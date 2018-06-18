/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* */
#include "maltcp.h"

static const char ZLOOP_ENDPOINTS_SOCKET_URI[] = "inproc://zloop.endpoints";

static const int BACKLOG = 5;

struct _maltcp_ctx_t {
  mal_ctx_t *mal_ctx;
  zctx_t *zmq_ctx;
  char *hostname;
  char *port;
  char *root_uri;
  int mal_socket;         // TCP server socket listening to remote mal contexts
  zhash_t *cnx_table;     // TCP client sockets connected to remote mal contexts, key = short URI
  void *endpoints_socket; // inproc connected to endpoints
  zloop_t *zloop;
  maltcp_header_t *maltcp_header;
  // Private encoder / decoder used for PDU, always varint as the fixed part of the PDU
  // is handled directly through malbinary methods.
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

void maltcp_ctx_set_encoder_log_level(maltcp_ctx_t *self, int level) {
  if (self != NULL) {
    mal_encoder_set_log_level(self->encoder, level);
  }
}

void maltcp_ctx_set_decoder_log_level(maltcp_ctx_t *self, int level) {
  if (self != NULL) {
    mal_decoder_set_log_level(self->decoder, level);
  }
}

//  --------------------------------------------------------------------------
//  The maltcp_endpoint_data_t structure holds the state for one end-point instance

// BE CAREFUL: This structure should be identical to the actor_endpoint_data_t
// structure used to create actor specific end-point (see mal_actor.c).
typedef struct {
  maltcp_ctx_t *maltcp_ctx;
  mal_endpoint_t *mal_endpoint;
  void *socket;
  void *padding; // unused but defined in malzmq context
} maltcp_endpoint_data_t;

//  --------------------------------------------------------------------------
//  The maltcp_poller_data_t structure holds the state for multiples endpoint instances

typedef struct {
  maltcp_ctx_t *maltcp_ctx;
  mal_poller_t *mal_poller;

  zpoller_t *poller;          //  Socket poller

  int idx, max;
  maltcp_endpoint_data_t **endpoints;
} maltcp_poller_data_t;

// Default size for poller table
#define MAL_POLLER_LIST_DFLT_SIZE 20

maltcp_endpoint_data_t* maltcp_get_endpoint(maltcp_poller_data_t *poller_data, zsock_t *socket) {
  clog_info(maltcp_logger, " *** mal_routing_get_endpoint: \n");

  for (int i=0; i<poller_data->idx; i++) {
    if (poller_data->endpoints[i]->socket == socket) {
      clog_debug(maltcp_logger, " *** mal_routing_get_endpoint: OK\n");
      return poller_data->endpoints[i];
    }
  }
  return NULL;
}

int maltcp_add_endpoint(maltcp_poller_data_t *poller_data, mal_endpoint_t *endpoint) {
  clog_info(maltcp_logger, " *** maltcp_add_endpoint: %s\n", mal_endpoint_get_uri(endpoint));

  if (poller_data->idx < poller_data->max) {
    // Includes the structure in the table
    poller_data->endpoints[poller_data->idx++] =
        (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(endpoint);
    return 0;
  } else {
    clog_error(maltcp_logger, "Error :: Cannot add more than %d endpoints\n", poller_data->max);
    return -1;
  }
}

int maltcp_del_endpoint(maltcp_poller_data_t *poller_data, mal_endpoint_t *endpoint) {
  clog_info(maltcp_logger, " *** maltcp_del_endpoint: %s\n",  mal_endpoint_get_uri(endpoint));

  int found = -1;
  for (int i=0; i<poller_data->idx; i++) {
    if ((poller_data->endpoints[i] != NULL) &&
        (poller_data->endpoints[i] == mal_endpoint_get_endpoint_data(endpoint))) {
      found = i;
      break;
    }
  }

  if (found == -1) {
    clog_warning(maltcp_logger, " *** maltcp_del_endpoint: Not found\n");
    return -1;
  }

  poller_data->idx -= 1;
  for (int i=found; i<poller_data->idx; i++) {
    poller_data->endpoints[i] = poller_data->endpoints[i+1];
  }
  poller_data->endpoints[poller_data->idx] = NULL;

  clog_debug(maltcp_logger, " *** maltcp_del_endpoint: OK\n");
  return 0;
}

mal_uinteger_t maltcp_decode_variable_length(char *bytes, unsigned int length) {
  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_t cursor;

  malbinary_cursor_init(&cursor, bytes, length, VARIABLE_LENGTH_OFFSET);
  return malbinary_read32(&cursor);
}

// Functions needed to handle TCP connection hashtable.

typedef struct maltcp_ctx_connection {
  int socket;
  pthread_mutex_t lock;
} maltcp_ctx_connection_t;

maltcp_ctx_connection_t *maltcp_ctx_connection_create(int socket) {
  maltcp_ctx_connection_t *cnx_ptr = (maltcp_ctx_connection_t*) malloc(sizeof(maltcp_ctx_connection_t));
  // Initialize the mutex
  if (pthread_mutex_init(&cnx_ptr->lock, NULL) != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_connection_create: failed to initialize mutex.");
    free(cnx_ptr);
    return NULL;
  }
  cnx_ptr->socket = socket;
  return cnx_ptr;
}

int maltcp_ctx_connection_register_incoming(maltcp_ctx_t *self, int socket, char *peer_uri) {
  maltcp_ctx_connection_t *cnx_ptr = (maltcp_ctx_connection_t *) zhash_lookup(self->cnx_table, peer_uri);
  if (cnx_ptr != NULL) {
    clog_warning(maltcp_logger, "maltcp_ctx_register_incoming_cnx#1: %s already registered.\n", peer_uri);
    return 0;
  }

  cnx_ptr = maltcp_ctx_connection_create(socket);
  if (cnx_ptr == NULL) return -1;

  char *uri = (char *) malloc(strlen(peer_uri) +1);
  strcpy(uri, peer_uri);
  if (zhash_insert(self->cnx_table, uri, cnx_ptr) != 0) {
    // A connection is already registered for this URI.
    clog_warning(maltcp_logger, "maltcp_ctx_register_incoming_cnx#2: %s already registered.\n", uri);
    free(uri);
    free(cnx_ptr);
    return 0;
  }
  zhash_freefn(self->cnx_table, uri, free);

  return 0;
}

maltcp_ctx_connection_t *maltcp_ctx_connection_register_outgoing(maltcp_ctx_t *self, int socket, char *peer_uri) {
  maltcp_ctx_connection_t *cnx_ptr = maltcp_ctx_connection_create(socket);
  if (cnx_ptr != NULL) {
    char *uri = (char *) malloc(strlen(peer_uri) +1);
    strcpy(uri, peer_uri);
    zhash_update(self->cnx_table, uri, cnx_ptr);
    zhash_freefn(self->cnx_table, uri, free);
  }
  return cnx_ptr;
}

void maltcp_ctx_socket_destroy(maltcp_ctx_connection_t *cnx_ptr) {
  if (close(cnx_ptr->socket) != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_socket_destroy: Failed to close socket.\n");
  }
  if (pthread_mutex_destroy(&cnx_ptr->lock) != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_socket_destroy: Failed to destroy mutex.\n");
  }
}

int maltcp_ctx_connection_remove_socket(maltcp_ctx_t *self, int socket) {
  clog_debug(maltcp_logger, "maltcp_ctx_connection_remove_socket(%d).\n", socket);
  maltcp_ctx_connection_t *cnx_ptr =  (maltcp_ctx_connection_t*) zhash_first(self->cnx_table);
  while (cnx_ptr) {
    if (cnx_ptr->socket == socket) {
      // Close registered TCP connections
      clog_debug(maltcp_logger, "maltcp_ctx_connection_remove_socket: close and remove socket.\n");
      maltcp_ctx_socket_destroy(cnx_ptr);
      zhash_delete(self->cnx_table, zhash_cursor(self->cnx_table));
      // TODO: Should free the allocated string key and element structure.
      return 0;
    }
    cnx_ptr = (maltcp_ctx_connection_t*) zhash_next(self->cnx_table);
  }
  clog_debug(maltcp_logger, "maltcp_ctx_connection_remove_socket: socket (%d) not found.\n", socket);
  return 0;
}

// This function is called when a message is ready to be read on the specified
//connection. The connection is registered with the URI if needed.
int maltcp_ctx_socket_receive(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive\n");
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;

  struct sockaddr src_addr;
  socklen_t addr_size = sizeof(struct sockaddr_in);
  if (getpeername(poller->fd, (struct sockaddr *)&src_addr, &addr_size) != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_socket_receive: getpeername failed\n");
    return -1;
  }

  char src_ipstr[INET6_ADDRSTRLEN];
  int src_port;

  if (src_addr.sa_family == AF_INET) {
      struct sockaddr_in *s = (struct sockaddr_in *)&src_addr;
      src_port = ntohs(s->sin_port);
      inet_ntop(AF_INET, &s->sin_addr, src_ipstr, sizeof src_ipstr);
  } else { // AF_INET6
      struct sockaddr_in6 *s = (struct sockaddr_in6 *)&src_addr;
      src_port = ntohs(s->sin6_port);
      inet_ntop(AF_INET6, &s->sin6_addr, src_ipstr, sizeof src_ipstr);
  }
  mal_uri_t peer_uri[strlen(src_ipstr) + 10 + 10 + 1];
  sprintf((char*) peer_uri, "%s%s:%d", MALTCP_URI, src_ipstr, src_port);
  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket receive from URI: %s\n", peer_uri);

  char header[FIXED_HEADER_LENGTH];
  int nb = 0;
  while (nb < FIXED_HEADER_LENGTH) {
    int nbread = recv(poller->fd, &header[nb], FIXED_HEADER_LENGTH-nb, 0);
    if (nbread == 0) {
      clog_warning(maltcp_logger, "maltcp_ctx_socket_receive: TCP connection (%d) closed\n", poller->fd);
      maltcp_ctx_connection_remove_socket(self, poller->fd);
      zloop_poller_end(loop, poller);
      close(poller->fd);
      return 0;
    }

    if (nbread <0) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_receive: Error reading header on TCP connection\n");
      maltcp_ctx_connection_remove_socket(self, poller->fd);
      zloop_poller_end(loop, poller);
      close(poller->fd);
      return -1;
    }
    nb += nbread;
  }

  // First read, get the message size in the header
  int msg_size = maltcp_decode_variable_length(header, nb) + FIXED_HEADER_LENGTH;
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: should read = %d bytes\n", msg_size);

  // Allocate the message and copy header
  char* msg = (char*) malloc(msg_size);
  memcpy(msg, header, FIXED_HEADER_LENGTH);

  // Read the whole message
  while (nb < msg_size) {
    int nbread = recv(poller->fd, &msg[nb], msg_size-nb, 0);
    if (nbread <=0) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_receive: Error reading message on TCP connection\n");
      maltcp_ctx_connection_remove_socket(self, poller->fd);
      zloop_poller_end(loop, poller);
      close(poller->fd);
      free(msg);
      return -1;
    }
    nb += nbread;
  }

  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: message received, size = %d\n", msg_size);

  // Get URIs from message and register connection if needed
  mal_uri_t *uri_to;
  mal_uri_t *uri_from;
  if (maltcp_decode_uris(self->maltcp_header,
      self->decoder, msg, msg_size, &uri_to, &uri_from) != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_socket_receive, could not decode uri_to\n");
    return -1;
  }
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: uri_to=%s uri_from=%s\n", uri_to, uri_from);

  if ((uri_from != NULL) && (strncmp(uri_from, MALTCP_URI, sizeof MALTCP_URI -1) == 0)) {
    // The complete URI is registered in the message header, use it.
    int len = strlen(uri_from);
    char *ptr = strchr(uri_from +sizeof MALTCP_URI, '/');
    if (ptr != NULL)
      len = ptr-uri_from;
    char uri[len+1];
    strncpy(uri, uri_from, len);
    uri[len] = '\0';
    clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: register#1 %s\n", uri);
    // Register the connection if needed
    maltcp_ctx_connection_register_incoming(self, poller->fd, uri);
  } else {
    clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: register#2 %s\n", peer_uri);
    // Register the connection if needed
    maltcp_ctx_connection_register_incoming(self, poller->fd, peer_uri);
  }

  // Forward the message to the appropriate endpoint.

  // Note: Normally the message will be deleted by the appropriate endpoint.
  // What happens if no endpoint reads this message? It seems that Router socket
  // discard messages if there are no readers.

  assert(uri_to != NULL);

  // Get the service part of URI needed to route the message.
  mal_uri_t *short_uri_to = maltcp_get_service_from_uri(uri_to);
  int rc = zmq_send(self->endpoints_socket, short_uri_to, strlen(short_uri_to), ZMQ_SNDMORE);
  assert(rc == strlen(short_uri_to));
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: send identity (%d bytes) to endpoint %s\n", rc, short_uri_to);

  // Send the peer URI
  rc = zmq_send(self->endpoints_socket, peer_uri, strlen(peer_uri), ZMQ_SNDMORE);
  assert(rc == strlen(peer_uri));
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: send peer URI (%d bytes) to endpoint %s\n", rc, peer_uri);

  // Send the message
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: send message (%d bytes) to endpoint %s\n", msg_size, short_uri_to);
  rc = zmq_send(self->endpoints_socket, msg, msg_size, ZMQ_DONTWAIT);
  assert(rc == msg_size);

  clog_debug(maltcp_logger, "maltcp_ctx: message handled.\n");

  // Destroy URIs: Be careful, short_uri_to is simply a pointer in uri_to.
  mal_uri_destroy(&uri_to);
  mal_uri_destroy(&uri_from);

  return 0;
}

int maltcp_ctx_server_socket_create(int port, int backlog) {
  clog_debug(maltcp_logger, "maltcp_ctx: creates TCP server socket.\n");

  int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == -1) {
    clog_error(maltcp_logger, "Failed to create listen socket: %s", strerror(errno));
    return -1;
  }
  int one = 1;
  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
  //  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &one, sizeof(one));
  //  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));

  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    clog_error(maltcp_logger, "Failed to bind server to port %d: %s\n",
               port, strerror(errno));
    return -1;
  }

  if (listen(listen_socket, backlog) == -1) {
    clog_error(maltcp_logger, "Failed to listen: %s", strerror(errno));
    return -1;
  }

  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket created.\n");

  return listen_socket;
}

// This function is called when an incoming connection is detected on the
// listening socket. It accepts the connection and registers the appropriate
// poller to receive message.
int maltcp_ctx_socket_accept(zloop_t *zloop, zmq_pollitem_t *poller, void *arg) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;

  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket accept.\n");
  if (self->mal_socket == -1) {
    // The context is closed, return
    clog_debug(maltcp_logger, "maltcp_ctx_socket_accept: socket (%d) closed\n", poller->fd);
    return -1;
  }

  // Accept incoming connection and register it.
  struct sockaddr src_addr;
  int new_socket = -1;
  socklen_t len = sizeof(struct sockaddr_in);

  // Note: May be we could use poller->fd to replace self->mal_socket
  if ((new_socket = accept(self->mal_socket, &src_addr, &len)) == -1) {
    clog_error(maltcp_logger, "Failed to accept: %s\n", strerror(errno));
    return -1;
  }

  if (clog_is_loggable(maltcp_logger, CLOG_DEBUG_LEVEL)) {
    // Needed only for debug.
    char src_ipstr[INET6_ADDRSTRLEN];
    int src_port;

    if (src_addr.sa_family == AF_INET) {
      struct sockaddr_in *s = (struct sockaddr_in *)&src_addr;
      src_port = ntohs(s->sin_port);
      inet_ntop(AF_INET, &s->sin_addr, src_ipstr, sizeof src_ipstr);
    } else { // AF_INET6
      struct sockaddr_in6 *s = (struct sockaddr_in6 *)&src_addr;
      src_port = ntohs(s->sin6_port);
      inet_ntop(AF_INET6, &s->sin6_addr, src_ipstr, sizeof src_ipstr);
    }
    clog_debug(maltcp_logger, "maltcp_ctx_socket_accept: Source URI: %s%s:%d\n", MALTCP_URI, src_ipstr, src_port);
  }

  zmq_pollitem_t poller2 = { NULL, new_socket, ZMQ_POLLIN };
  int rc = zloop_poller(zloop, &poller2, maltcp_ctx_socket_receive, self);
  assert(rc == 0);

  // Note: do not register the connection since the uri is not yet precisely known.

  clog_debug(maltcp_logger, "maltcp_ctx: TCP connection established.\n");

  return 0;
}

//  --------------------------------------------------------------------------
//  Provide the Binding functions

int zloop_timer_handle(zloop_t *loop, int timer_id, void *arg) {
  return 0;
}

maltcp_ctx_t *maltcp_ctx_new(mal_ctx_t *mal_ctx,
    char *hostname, char *port,
    maltcp_header_t *maltcp_header,
    // TODO: no longer used
    bool verbose) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) malloc(sizeof(maltcp_ctx_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->hostname = hostname;
  self->port = port;
  self->maltcp_header = maltcp_header;

  self->encoder = malbinary_encoder_new(true);
  self->decoder = malbinary_decoder_new(true);

  self->root_uri = (char *) malloc(strlen(hostname) + strlen(port) + 10 + 1);
  sprintf((char*) self->root_uri, "%s%s:%s", MALTCP_URI, hostname, port);
  clog_debug(maltcp_logger, "maltcp_ctx_new: root_uri=%s\n", self->root_uri);

  zctx_t *zmq_ctx = zctx_new();
  self->zmq_ctx = zmq_ctx;

  self->cnx_table = zhash_new();

  // Creates the TCP listening socket
  int listen = maltcp_ctx_server_socket_create(atoi(port), BACKLOG);
  //assert(listen >= 0);
  if (listen < 0) {
    clog_error(maltcp_logger, "EXCEPTION:: maltcp_ctx_new: listen = %d\n", listen);
    return NULL;
  }

  self->mal_socket = listen;
  clog_debug(maltcp_logger, "maltcp_ctx: ptp listening to: %s\n", port);

  //inproc
  void *endpoints_socket = zsocket_new(zmq_ctx, ZMQ_ROUTER);
  self->endpoints_socket = endpoints_socket;
  zsocket_bind(endpoints_socket, ZLOOP_ENDPOINTS_SOCKET_URI);

  zloop_t *zloop = zloop_new();
  // TODO (AF): It seems that adding poller from outside of handler is not correctly
  // supported by ZMQ. We should provide an inproc socket allowing to add the needed
  // poller. However it seems that a timer regularly awaking the zloop corrects this
  // issue.
  zloop_timer(zloop, 100, 0, zloop_timer_handle, self);
//  zloop_set_verbose(zloop, true);
  self->zloop = zloop;

  zmq_pollitem_t poller = { NULL, listen, ZMQ_POLLIN };
  int rc = zloop_poller(zloop, &poller, maltcp_ctx_socket_accept, self);
  assert(rc == 0);

  mal_ctx_set_binding(
      mal_ctx, self,
      maltcp_ctx_create_uri,
      maltcp_ctx_create_endpoint, maltcp_ctx_destroy_endpoint,
      maltcp_ctx_create_poller, maltcp_ctx_destroy_poller,
      maltcp_ctx_poller_add_endpoint, maltcp_ctx_poller_del_endpoint,
      maltcp_ctx_send_message, maltcp_ctx_recv_message,
      maltcp_ctx_poller_wait,
      maltcp_ctx_destroy_message,
      maltcp_ctx_start,
      maltcp_ctx_stop,
      maltcp_ctx_destroy);

  return self;
}

int maltcp_ctx_start(void *self) {
  clog_debug(maltcp_logger, "maltcp_ctx: running...\n");
  int rc = zloop_start(((maltcp_ctx_t *)self)->zloop);
  clog_debug(maltcp_logger, "maltcp_ctx: stopped: %d.\n", rc);
  return rc;
}

int maltcp_ctx_stop(void *self) {
  maltcp_ctx_t *mal_ctx = (maltcp_ctx_t *) self;

  clog_debug(maltcp_logger, "maltcp_ctx_stop...\n");
  if (mal_ctx->mal_socket != -1) {
    // Note: this method is not symmetric with maltcp_ctx_start, may be we have to
    // create and bind the socket in maltcp_ctx_start rather than in maltcp_ctx_new.
    int socket = mal_ctx->mal_socket;
    mal_ctx->mal_socket = -1;
    close(socket);
  }
  clog_debug(maltcp_logger, "maltcp_ctx_stop: stopped.\n");

  return 0;
}

int maltcp_ctx_destroy(void **self_p) {
  clog_debug(maltcp_logger, "maltcp_ctx_destroy...\n");
  if (self_p && *self_p) {
    maltcp_ctx_t *self = (maltcp_ctx_t *) *self_p;


    // TODO(AF): zmq_close versus zsocket_destroy
    zsocket_set_linger(self->endpoints_socket, 0);
    clog_debug(maltcp_logger, "maltcp_ctx_destroy: linger=%d\n", zsocket_linger(self->endpoints_socket));
    zsocket_destroy(self->zmq_ctx, self->endpoints_socket);
  //  zmq_close(mal_ctx->endpoints_socket);

    // Free all structures in hash-table, close socket and destroy mutex.
    if (self->cnx_table) {
      maltcp_ctx_connection_t *cnx_ptr =  (maltcp_ctx_connection_t*) zhash_first(self->cnx_table);
      while (cnx_ptr) {
        // Close registered TCP connections
        clog_debug(maltcp_logger, "maltcp_ctx_destroy: close socket %d.\n", cnx_ptr->socket);
        maltcp_ctx_socket_destroy(cnx_ptr);
        // destroy all registered sockets
        cnx_ptr = (maltcp_ctx_connection_t*) zhash_next(self->cnx_table);
      }
    }

    // TODO (AF): Close all pollers?
    clog_debug(maltcp_logger, "maltcp_ctx_destroy: stopped.\n");

    free(self->maltcp_header);
    // Free all structures in hash-table, close socket and destroy mutex.
    if (self->cnx_table)
      zhash_destroy(&self->cnx_table);
    zloop_destroy(&self->zloop);
//    zsocket_destroy(self->zmq_ctx, self->endpoints_socket);
//    zmq_close(self->endpoints_socket);
    zctx_destroy(&self->zmq_ctx);

    free(self);
    *self_p = NULL;
  }
  clog_debug(maltcp_logger, "maltcp_ctx_destroy: destroyed.\n");
  return 0;
}

int maltcp_ctx_socket_send(maltcp_ctx_connection_t *cnx, malbinary_cursor_t *cursor) {
  // Lock TCP connection.
  pthread_mutex_lock(&cnx->lock);
  clog_debug(maltcp_logger, "maltcp_ctx_socket_send: send TCP message, size=%d\n", malbinary_cursor_get_length(cursor));
  int rc = send(cnx->socket, cursor->body_ptr, malbinary_cursor_get_length(cursor), 0);
  if (rc < 0)
    clog_error(maltcp_logger, "maltcp_ctx_socket_send: error sending message.\n");
  else
    clog_debug(maltcp_logger, "maltcp_ctx_socket_send: message sent.\n");
  // Unock TCP connection.
  pthread_mutex_unlock(&cnx->lock);
  return rc;
}

maltcp_ctx_connection_t *maltcp_ctx_socket_connect(maltcp_ctx_t *self, mal_uri_t *socket_uri) {
  maltcp_ctx_connection_t *cnx_ptr = (maltcp_ctx_connection_t *) zhash_lookup(self->cnx_table, socket_uri);

  if (cnx_ptr == NULL) {
    clog_debug(maltcp_logger, "maltcp_ctx_socket_connect: open a new PTP socket\n");

    // Create a new connection
    struct hostent *server;
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_connect: failed to create client socket: %s\n", strerror(errno));
      return NULL;
    }

    char *ipaddr = maltcp_get_host_from_uri(socket_uri);
    int port = maltcp_get_port_from_uri(socket_uri);
    clog_debug(maltcp_logger, "maltcp_ctx_socket_connect: %s %d\n", ipaddr, port);
    if ((server = gethostbyname(ipaddr)) == NULL) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_connect: failed to to get address: %s\n", strerror(errno));
      free(ipaddr);
      return NULL;
    }
    free(ipaddr);

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_connect: failed to connect: %s\n", strerror(errno));
      return NULL;
    }
    clog_debug(maltcp_logger, "maltcp_ctx_socket_connect: connected to %s\n", socket_uri);

    clog_debug(maltcp_logger, "maltcp_ctx_socket_connect: update TCP connections table\n");
    cnx_ptr = maltcp_ctx_connection_register_outgoing(self, client_socket, socket_uri);

    // Register a zloop poller for this connection.
    zmq_pollitem_t poller = { NULL, client_socket, ZMQ_POLLIN };
    int rc = zloop_poller(self->zloop, &poller, maltcp_ctx_socket_receive, self);
    assert(rc == 0);
  } else {
    clog_debug(maltcp_logger, "maltcp_ctx_socket_connect: use existing connection (%d) for %s\n", cnx_ptr->socket, socket_uri);
  }

  return cnx_ptr;
}

// Must be compliant with MAL virtual function: void *self
int maltcp_ctx_send_message(void *self, mal_endpoint_t *mal_endpoint, mal_message_t *mal_message) {
  maltcp_ctx_t *maltcp_ctx = (maltcp_ctx_t *) self;

  if (clog_is_loggable(maltcp_logger, CLOG_INFO_LEVEL)) {
    clog_info(maltcp_logger, "maltcp_ctx_send_message:\n");
    mal_message_print(mal_message);
    clog_info(maltcp_logger, "\n");
  }

  int rc = 0;

  mal_uri_t *uri_to = mal_message_get_uri_to(mal_message);
  clog_debug(maltcp_logger, "maltcp_ctx_send_message: uri_to=%s\n", uri_to);

  char *peer_uri = maltcp_get_base_uri(uri_to);
  clog_debug(maltcp_logger, "maltcp_ctx_send_message: peer_uri=%s\n", peer_uri);

  maltcp_ctx_connection_t *cnx_ptr = maltcp_ctx_socket_connect(maltcp_ctx, peer_uri);
  if (cnx_ptr == NULL) {
    clog_error(maltcp_logger, "maltcp_ctx_send_message: cannot create connection for %s.\n", peer_uri);
    free(peer_uri);
    return -1;
  }
  free(peer_uri);

  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_t cursor;
  malbinary_cursor_reset(&cursor);

  // TODO: In a first time we should separate the header and body size in order to send them
  // in separate frames. In a second time we should cut the message in multiples frames.

  // maltcp_add_message_encoding_length should not add body_length to encoding length
  // bytes should content uniquely the header
  // maltcp_encode_message should not copy the body to the bytes array
  // we should creates and send 2 frames

  // 'maltcp' encoding format of the MAL header
  rc = maltcp_add_message_encoding_length(maltcp_ctx->maltcp_header, mal_message, maltcp_ctx->encoder, &cursor);
  if (rc < 0)
    return rc;

  clog_debug(maltcp_logger, "maltcp_ctx: encoding_length=%d\n", malbinary_cursor_get_length(&cursor));

  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_init(&cursor,
      (char *) malloc(malbinary_cursor_get_length(&cursor)),
      malbinary_cursor_get_length(&cursor),
      0);

  clog_debug(maltcp_logger, "maltcp_ctx: mal_message_encode_malbinary\n");

  // 'maltcp' encoding format of the MAL header
  rc = maltcp_encode_message(maltcp_ctx->maltcp_header, mal_message, maltcp_ctx->encoder, &cursor);
  if (rc < 0)
    return rc;
  assert(cursor.body_length == cursor.body_offset);

  clog_debug(maltcp_logger, "maltcp_ctx: message is encoded: %d bytes\n", malbinary_cursor_get_offset(&cursor));

  // send the message
  if (maltcp_ctx_socket_send(cnx_ptr, &cursor) < 0)
    return -1;

  return 0;
}

// This function is used by endpoint to receive message from zloop.
int maltcp_ctx_recv_message(void *self, mal_endpoint_t *mal_endpoint, mal_message_t **message) {
  maltcp_ctx_t *maltcp_ctx = (maltcp_ctx_t *) self;
  maltcp_endpoint_data_t *endpoint_data = (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  int rc = 0;

  clog_debug(maltcp_logger, "maltcp_ctx_recv_message()\n");

  zmsg_t *zmsg = zmsg_recv(endpoint_data->socket);
  if (zmsg) {
    size_t frames_count = zmsg_size(zmsg);

    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: received zmsg (%d frames)\n", frames_count);

    // The first frame contains the peer URI.
    zframe_t *from = zmsg_pop(zmsg);
    char *peer_uri = NULL;
    if (from != NULL) {
      int len = zframe_size(from);
      peer_uri = (char *) malloc(len +1);
      strncpy(peer_uri, (char *)zframe_data(from), len);
      peer_uri[len] = '\0';
      zframe_destroy(&from);
    }
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: peer_uri = %s\n", peer_uri);

    // The MAL message is in the second frame.
    // Now the frame is owned by us.
    zframe_t *frame = zmsg_pop(zmsg);

    size_t mal_msg_bytes_length = zframe_size(frame);
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: mal_msg_bytes_length=%d\n", mal_msg_bytes_length);

    // Does not copy the frame bytes in another array.
    byte *mal_msg_bytes = zframe_data(frame);

    *message = mal_message_new_void();

    // MALTCP always uses the 'malbinary' encoding format for the messages header encoding (another
    // format may be used at the application layer for the message body).

    // Note: We could use virtual allocation and initialization functions from encoder
    // rather than malbinary interface.
    malbinary_cursor_t cursor;
    malbinary_cursor_init(&cursor, (char *) mal_msg_bytes, mal_msg_bytes_length, 0);

    mal_uinteger_t variable_length;

    // 'maltcp' encoding format of the MAL header
    if (maltcp_decode_message(maltcp_ctx->maltcp_header, *message, maltcp_ctx->decoder, &cursor, &variable_length) != 0) {
      clog_error(maltcp_logger, "maltcp_ctx_recv_message, cannot decode message\n");
      return -1;
    }
    // Note: Currently the message length is always equal to the frame size.
    assert(mal_msg_bytes_length == (variable_length + FIXED_HEADER_LENGTH));

    // TODO (AF) : Normally the frame should be kept to avoid copying the body of the message.
    // currently the body is always copied in a newly allocated memory.
    // Destroy must free the tcp frame
//    mal_message_set_body_owner(*message, frame);

    // If the From URI field is not completely filled, we have to complete it with
    // the information from TCP/IP protocol.
    mal_uri_t *uri_from = mal_message_get_uri_from(*message);
    if (uri_from == NULL) {
      mal_message_set_uri_from(*message, peer_uri);
      mal_message_set_free_uri_from(*message, (1==1));
    } else if (strncmp(uri_from, MALTCP_URI, sizeof MALTCP_URI -1) != 0) {
      if (uri_from[0] == '/')
        uri_from += 1;
      mal_uri_t *uri = (mal_uri_t *) malloc(strlen(peer_uri) + strlen(uri_from) +2);
      strcpy(uri, peer_uri);
      // Ensures presence of path separator (not added in maltcp_ctx_socket_receive).
      strcat(uri, "/");
      strcat(uri, uri_from);
      mal_message_set_uri_from(*message, uri);
      mal_message_set_free_uri_from(*message, (1==1));
      free(peer_uri);
    } else {
      // The complete URI is registered in the message header, use it.
      free(peer_uri);
    }

    // If the To URI field is not completely filled, we have to complete it.
    // TODO (AF): The To URI should never be completely filled!!
    mal_uri_t *uri_to = mal_message_get_uri_to(*message);
    if ((uri_to == NULL) || (strncmp(uri_to, MALTCP_URI, sizeof MALTCP_URI -1) != 0)) {
      mal_message_set_uri_to(*message, mal_endpoint_get_uri(endpoint_data->mal_endpoint));
      mal_message_set_free_uri_to(*message, (1!=1));
    }

    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: ");
    if (clog_is_loggable(maltcp_logger, CLOG_DEBUG_LEVEL))
      mal_message_print(*message);
    clog_debug(maltcp_logger, "\n");

    // Verify if the message could be delivered and destroy it otherwise.
    if (endpoint_data->mal_endpoint) {
      bool message_delivered = false;
      mal_uri_t *endpoint_uri = mal_endpoint_get_uri(endpoint_data->mal_endpoint);
      if (strcmp(maltcp_get_service_from_uri(endpoint_uri), maltcp_get_service_from_uri(uri_to)) == 0)
        message_delivered = true;

      clog_debug(maltcp_logger, "maltcp_ctx_recv_message: message_delivered=%d\n", message_delivered);

      if (!message_delivered) {
        clog_debug(maltcp_logger, "maltcp_ctx_recv_message: destroy MAL message\n", uri_to);

        mal_message_destroy(message, maltcp_ctx->mal_ctx);
      }
    }

    // TODO (AF) : Normally the frame should be kept to avoid copying the body of the message.
    // currently the body is always copied in a newly allocated memory.
    zframe_destroy(&frame);
  } else {
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message(): NULL\n");
  }

  return rc;
}

// Must be compliant with MAL virtual function.
int maltcp_ctx_destroy_message(void *self, mal_message_t *mal_message) {
  zframe_t *frame = (zframe_t *) mal_message_get_body_owner(mal_message);
  if (frame != NULL) {
    zframe_destroy(&frame);
  }
  return 0;
}

// Must be compliant with MAL virtual function: void *self
mal_uri_t *maltcp_ctx_create_uri(void *self, char *id) {
  maltcp_ctx_t *maltcp_ctx = (maltcp_ctx_t *) self;

  clog_debug(maltcp_logger, "maltcp_ctx_create_uri()\n");

  size_t uri_length = strlen(MALTCP_URI);
  if (maltcp_ctx->hostname) {
    uri_length += strlen(maltcp_ctx->hostname);
  }
  if (maltcp_ctx->port) {
    uri_length += strlen(maltcp_ctx->port) + 1;
  }
  if (id) {
    uri_length += strlen(id) + 1;
  }

  clog_debug(maltcp_logger, "maltcp_ctx: uri_length=%d\n", uri_length);

  char *uri = (char *) malloc(uri_length + 1);
  // Need to set the final '\0' before using strcat
  uri[0] = '\0';
  if (uri) {
    strcat(uri, MALTCP_URI);
    if (maltcp_ctx->hostname) {
      strcat(uri, maltcp_ctx->hostname);
    }
    if (maltcp_ctx->port) {
      strcat(uri, ":");
      strcat(uri, maltcp_ctx->port);
    }
    if (id) {
      strcat(uri, "/");
      strcat(uri, id);
    }
  }

  clog_debug(maltcp_logger, "maltcp_ctx: created URI: %s\n", uri);

  return uri;
}

void *maltcp_ctx_create_endpoint(void *maltcp_ctx, mal_endpoint_t *mal_endpoint) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) maltcp_ctx;
  maltcp_endpoint_data_t *endpoint_data = NULL;

  clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint()\n");

  if (mal_endpoint) {
    endpoint_data = (maltcp_endpoint_data_t *) zmalloc(sizeof(maltcp_endpoint_data_t));
    assert(endpoint_data);

    //  Initialize the endpoint ZMQ specific state
    endpoint_data->maltcp_ctx = self;
    endpoint_data->mal_endpoint = mal_endpoint;

    mal_endpoint_set_endpoint_data(mal_endpoint, endpoint_data);

    clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint: initialize endpoint\n");

    // Initialize the endpoint
    mal_uri_t *handler_uri = maltcp_get_service_from_uri(mal_endpoint_get_uri(endpoint_data->mal_endpoint));

    clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint: initialize endpoint -> %s\n", handler_uri);

    // Create a socket connected to the zloop to receive
    // MAL messages to be handled by this actor
    void *zloop_socket = zsocket_new(self->zmq_ctx, ZMQ_DEALER);

    // Keep the socket
    endpoint_data->socket = zloop_socket;

    // The identity of the handler is its URI
    zmq_setsockopt(zloop_socket, ZMQ_IDENTITY, handler_uri, strlen(handler_uri));

    // Connect to the zloop
    clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint: connect to the zloop\n");
    zmq_connect(zloop_socket, ZLOOP_ENDPOINTS_SOCKET_URI);

    clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint: initialized.\n");
  } else {
    clog_error(maltcp_logger, "maltcp_ctx_create_endpoint, cannot create end-point: %s\n", mal_endpoint_get_uri(endpoint_data->mal_endpoint));
  }

  return endpoint_data;
}

void maltcp_ctx_destroy_endpoint(void *self, void **endpoint_p) {
  assert(endpoint_p);
  if (*endpoint_p) {
    maltcp_endpoint_data_t *endpoint = *(maltcp_endpoint_data_t **) endpoint_p;
    *endpoint_p = NULL;

    clog_debug(maltcp_logger, "maltcp_ctx_destroy_endpoint(): %d ..\n", endpoint->socket);
    // NOTE: Closing this socket makes a core dump during maltcp_ctx_destroy !!
    zsock_set_linger(endpoint->socket, 0);
//    zsocket_destroy(endpoint->maltcp_ctx->zmq_ctx, endpoint->socket);
//    zmq_close(endpoint->socket);

    //  ... destroy your own state here

    // mal_ctx and mal_endpoint must not be destroyed here
    // but where they have been created.

    free(endpoint);
    clog_debug(maltcp_logger, "maltcp_ctx_destroy_endpoint().\n");
  }
}

void *maltcp_ctx_create_poller(void *maltcp_ctx, mal_poller_t *mal_poller)  {
  maltcp_ctx_t *self = (maltcp_ctx_t *) maltcp_ctx;
  clog_debug(maltcp_logger, "maltcp_ctx_create_poller()\n");

  maltcp_poller_data_t *poller_data = (maltcp_poller_data_t *) zmalloc(sizeof(maltcp_poller_data_t));
  assert(poller_data);

  //  Initialize the poller ZMQ specific state
  poller_data->maltcp_ctx = self;
  poller_data->mal_poller = mal_poller;

  poller_data->max = MAL_POLLER_LIST_DFLT_SIZE;
  poller_data->idx = 0;
  poller_data->endpoints =  (maltcp_endpoint_data_t **) calloc(MAL_POLLER_LIST_DFLT_SIZE, sizeof(maltcp_endpoint_data_t *));
  if (poller_data->endpoints == NULL) {
    free(self);
    return NULL;
  }

  poller_data->poller = NULL;

  mal_poller_set_poller_data(mal_poller, poller_data);

  return poller_data;
}

void maltcp_ctx_destroy_poller(void *self, void **poller_p) {
  maltcp_poller_data_t **self_p = (maltcp_poller_data_t **) poller_p;
  assert(self_p);

  if (self_p && *self_p) {
    maltcp_poller_data_t *self = *self_p;
    *self_p = NULL;
    zpoller_destroy(&self->poller);

    free(self->endpoints);

    // mal_ctx and mal_poller must not be destroyed here
    // but where they have been created.

    free(self);
  }
}

int maltcp_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  maltcp_poller_data_t *poller_data = (maltcp_poller_data_t *) mal_poller_get_poller_data(mal_poller);
  maltcp_endpoint_data_t *endpoint_data = (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);
  int rc = 0;

  clog_debug(maltcp_logger, "maltcp_ctx_poller_add_endpoint(): %s\n", mal_endpoint_get_uri(mal_endpoint));

  maltcp_add_endpoint(poller_data, mal_endpoint);
  if (poller_data->poller == NULL)
    poller_data->poller = zpoller_new(endpoint_data->socket, NULL);
  else
    rc = zpoller_add(poller_data->poller, endpoint_data->socket);

  return rc;
}

int maltcp_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  maltcp_poller_data_t *poller_data = (maltcp_poller_data_t *) mal_poller_get_poller_data(mal_poller);
  maltcp_endpoint_data_t *endpoint_data = (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  int rc = 0;

  clog_debug(maltcp_logger, "maltcp_ctx_poller_del_endpoint(): %s\n", mal_endpoint_get_uri(mal_endpoint));

  if (poller_data->poller == NULL) {
    clog_error(maltcp_logger, "");
    return -1;
  }

  rc = zpoller_remove(poller_data->poller, endpoint_data->socket);
  if (rc != 0) {
    clog_error(maltcp_logger, "maltcp_ctx_poller_del_endpoint(): zpoller null\n");
    return rc;
  }

  rc = maltcp_del_endpoint(poller_data, mal_endpoint);
  clog_debug(maltcp_logger, "maltcp_ctx_poller_del_endpoint: return %d\n",rc);

  return rc;
}

int maltcp_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller, mal_endpoint_t **mal_endpoint, int timeout) {
  maltcp_poller_data_t *poller_data = (maltcp_poller_data_t *) mal_poller_get_poller_data(mal_poller);

  int rc = 0;

  clog_debug(maltcp_logger, "maltcp_ctx_poller_wait(%d)\n", timeout);

  zsock_t *which = (zsock_t *) zpoller_wait(poller_data->poller, timeout);
  if (zpoller_terminated(poller_data->poller)) {
    clog_debug(maltcp_logger, "maltcp_ctx_poller_wait: zpoller_terminated.\n");
    return -1;
  }

  if (which) {
    maltcp_endpoint_data_t *endpoint_data = maltcp_get_endpoint(poller_data, which);
    if (endpoint_data != NULL) {
      *mal_endpoint = endpoint_data->mal_endpoint;

      clog_debug(maltcp_logger, "maltcp_ctx_poller_wait: data available for end-point %s\n", mal_endpoint_get_uri(*mal_endpoint));
    } else {
      clog_error(maltcp_logger, "maltcp_ctx_poller_wait: cannot find corresponding end-point\n");
      return -1;
    }
  } else {
    *mal_endpoint = NULL;
  }

  return rc;
}

//  --------------------------------------------------------------------------
//  Selftest

void maltcp_ctx_test(bool verbose) {
  printf(" * maltcp ctx: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

