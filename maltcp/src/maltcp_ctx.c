/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
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
  int mal_socket;         // TCP server socket listening to remote mal contexts
  zhash_t *cnx_table;     // TCP client sockets connected to remote mal contexts, key = short URI
  void *endpoints_socket; // inproc connected to endpoints
  zloop_t *zloop;
  maltcp_header_t *maltcp_header;
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

mal_encoder_t *maltcp_get_encoder(maltcp_ctx_t *self) {
  return self->encoder;
}

mal_decoder_t *maltcp_get_decoder(maltcp_ctx_t *self) {
  return self->decoder;
}

//  --------------------------------------------------------------------------
//  The maltcp_endpoint_data_t structure holds the state for one end-point instance

// BE CAREFUL: This structure should be identical to the actor_endpoint_data_t
// structure used to create actor specific end-point (see mal_actor.c).
typedef struct {
  maltcp_ctx_t *maltcp_ctx;
  mal_endpoint_t *mal_endpoint;

  void *socket;
  zhash_t *remote_socket_table; // TCP client sockets connected to remote mal contexts, key = uri
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

char **get_protocol_host_port(mal_uri_t *uri) {
  char **split = (char **) calloc(3, sizeof(char *));
  split[0] = strtok(uri, "/:");
  split[1] = strtok(NULL, "/:");
  split[2] = strtok(NULL, "/:");
  return split;
}

mal_uri_t *get_short_uri(mal_uri_t *uri) {
  // Get the "/<consumer id>" part
  size_t uri_length = strlen(uri);
  int slashCounter = 0;
  int short_uri_length = 0;
  for (int i = 0; i < uri_length; i++) {
    if (uri[i] == '/') {
      slashCounter++;
      if (slashCounter == 3) {
        short_uri_length = i;
        break;
      }
    }
  }
  return uri+short_uri_length+1;
}

// TODO (AF): To remove.
// Point-to-Point protocol used, should be tcp.
//#define PTP_PROTOCOL         "tcp"
//#define PTP_PROTOCOL_LENGTH  3

// TODO (AF): To remove.
// Returns the URI for local listen ZMQ socket.
//mal_uri_t *get_uri_to(maltcp_ctx_t *self, mal_message_t *message) {
//  if (self->mapping_uri && self->mapping_uri->getzmquri_to_fn) {
//    return self->mapping_uri->getzmquri_to_fn(message);
//  } else {
//    mal_uri_t *uri_to = strdup(mal_message_get_uri_to(message));
//
//    mal_uri_t *socket_uri = NULL;
//
//    char **split = get_protocol_host_port(uri_to);
//    char *hostname = split[1];
//    char *port = split[2];
//
//    // This not the publish URI, ex: tcp://192.168.1.46:5555
//    socket_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 4 + strlen(hostname) + strlen(port) + 1);
//    // Need to set the final '\0' before using strcat
//    socket_uri[0] = '\0';
//    strcat(socket_uri, PTP_PROTOCOL "://");
//    strcat(socket_uri, hostname);
//    strcat(socket_uri, ":");
//    strcat(socket_uri, port);
//
//    free(uri_to);
//    return socket_uri;
//  }
//}

// TODO (AF): To remove.
// Returns the URI for remote ZMQ socket
//mal_uri_t *get_ptp_uri(maltcp_ctx_t *self, mal_uri_t *uri) {
//  if (self->mapping_uri && self->mapping_uri->get_p2p_zmquri_fn) {
//    return self->mapping_uri->get_p2p_zmquri_fn(uri);
//  } else {
//    char *dupuri = strdup(uri);
//
//    char **split = get_protocol_host_port(dupuri);
//    char *port = split[2];
//
//    mal_uri_t *ptp_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 5 + strlen(port) + 1);
//    // Need to set the final '\0' before using strcat
//    ptp_uri[0] = '\0';
//    strcat(ptp_uri, PTP_PROTOCOL "://*:");
//    strcat(ptp_uri, port);
//
//    free(dupuri);
//    return ptp_uri;
//  }
//}

mal_uinteger_t maltcp_decode_body_length(char *bytes, unsigned int length) {
  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_t cursor;

  // 'URI To' offset
  // +1 byte: version + sdu type
  // +2 bytes: service area
  // +2 bytes: service
  // +2 bytes: operation
  // +1 bytes: area version
  // +1 bytes: is error message + qos level + session
  // +8 bytes: transaction id
  // +1 bytes: flags
  // +1 bytes: encoding id
  // +4 bytes: body length

  malbinary_cursor_init(&cursor, bytes, length, 1 + 2 * 3 + 1 + 1 + 8 + 1 + 1);
  return malbinary_read32(&cursor);
}

// zloop_fn interface for standard socket
int maltcp_ctx_socket_receive(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;

  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket receive -> %d, %d.\n", poller->events, poller->revents);

  char header[FIXED_HEADER_LENGTH];
  int nb = 0;
  while (nb < FIXED_HEADER_LENGTH) {
    int nbread = recv(poller->fd, &header[nb], FIXED_HEADER_LENGTH-nb, 0);
    if (nbread == 0) {
      clog_warning(maltcp_logger, "maltcp_ctx_socket_receive: TCP connection closed\n");
      // TODO (AF): Need to clean.
      zloop_poller_end(loop, poller);
      close(poller->fd);
      return 0;
    }

    if (nbread <0) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_receive: Error reading header on TCP connection\n");
      // TODO (AF): Need to clean.
      zloop_poller_end(loop, poller);
      close(poller->fd);
      return -1;
    }
    nb += nbread;
  }

  // First read, get the message size in the header
  int msg_size = maltcp_decode_body_length(header, nb);
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: should read = %d bytes\n", msg_size);

  // Allocate the message and copy header
  char* msg = (char*) malloc(msg_size);
  memcpy(msg, header, FIXED_HEADER_LENGTH);

  // Read the whole message
  while (nb < msg_size) {
    int nbread = recv(poller->fd, &msg[nb], msg_size-nb, 0);
    if (nbread <=0) {
      clog_error(maltcp_logger, "maltcp_ctx_socket_receive: Error reading message on TCP connection\n");
      // TODO (AF): Need to clean.
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
  // TODO (AF): Register connection if needed

  // NOTE: Currently there is a TCP Connection from each EndPoint to each context.

  // TODO (AF): Complete Message URIs if needed

  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: uri_to=%s uri_from=%s\n", uri_to, uri_from);

  mal_uri_t *short_uri_to = get_short_uri(uri_to);
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: short_uri_to: %s\n", short_uri_to);

  // Re-send the message to the appropriate endpoint.
  // Note: Normally the message will be deleted by the appropriate endpoint.
  // What happens if no endpoint reads this message? It seems that Router socket
  // discard messages if there are no readers.
  int rc = zmq_send(self->endpoints_socket, short_uri_to, strlen(short_uri_to), ZMQ_SNDMORE);
  assert(rc == strlen(short_uri_to));
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: send identity (%d bytes) to endpoint %s\n", rc, short_uri_to);
  clog_debug(maltcp_logger, "maltcp_ctx_socket_receive: send message (%d bytes) to endpoint %s\n", msg_size, short_uri_to);

  // Send the message
  rc = zmq_send(self->endpoints_socket, msg, msg_size, ZMQ_DONTWAIT);
  assert(rc == msg_size);

  clog_debug(maltcp_logger, "maltcp_ctx: message handled.\n");

  // Destroy URIs: Be careful, short_uri_to is simply a pointer in short_uri_to.
  mal_uri_destroy(&uri_to);
  mal_uri_destroy(&uri_from);

  return 0;
}

int maltcp_ctx_socket_create(int port, int backlog) {
  clog_debug(maltcp_logger, "maltcp_ctx: creates TCP server socket.\n");

  int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == -1) {
    clog_error(maltcp_logger, "Failed to create listen socket: %s", strerror(errno));
    return -1;
  }
  //  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &one, sizeof(one));
  //  setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));

  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    clog_error(maltcp_logger, "Failed to bind server to port\n");
    return -1;
  }

  if (listen(listen_socket, backlog) == -1) {
    clog_error(maltcp_logger, "Failed to listen: %s", strerror(errno));
    return -1;
  }

  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket created.\n");

  return listen_socket;
}

int maltcp_ctx_socket_accept(zloop_t *zloop, zmq_pollitem_t *poller, void *arg) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;

  clog_debug(maltcp_logger, "maltcp_ctx: TCP server socket accept.\n");

  // Accept incoming connection and register it.
  struct sockaddr src_addr;
  int new_socket = -1;
  socklen_t len = sizeof(struct sockaddr_in);
  // Note: May be we could use poller->fd to replace self->mal_socket
  if ((new_socket = accept(self->mal_socket, &src_addr, &len)) == -1) {
    clog_error(maltcp_logger, "Failed to accept: %s", strerror(errno));
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
  // TODO (AF): use only one allocation.
  mal_uri_t mal_uri[strlen(src_ipstr) + 10 + 10 + 1];
  sprintf((char*) mal_uri, "%s://%s:%d", MALTCP_PROTOCOL, src_ipstr, src_port);
  clog_debug(maltcp_logger, "Source URI: %s\n", mal_uri);

  zmq_pollitem_t poller2 = { NULL, new_socket, ZMQ_POLLIN };
  int rc = zloop_poller(zloop, &poller2, maltcp_ctx_socket_receive, self);
  assert(rc == 0);

  clog_debug(maltcp_logger, "maltcp_ctx: TCP connection received\n");

  return 0;
}

//  --------------------------------------------------------------------------
//  Provide the Binding functions

maltcp_ctx_t *maltcp_ctx_new(mal_ctx_t *mal_ctx,
    char *hostname, char *port,
    maltcp_header_t *maltcp_header,
    bool verbose) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) malloc(sizeof(maltcp_ctx_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->hostname = hostname;
  self->port = port;
  self->maltcp_header = maltcp_header;

  self->encoder = malbinary_encoder_new(false);
  self->decoder = malbinary_decoder_new(false);

  if (verbose) {
    mal_uri_t mal_uri[strlen(hostname) + strlen(port) + 10 + 1];
    sprintf((char*) mal_uri, "%s://%s:%s", MALTCP_PROTOCOL, hostname, port);
    clog_debug(maltcp_logger, "maltcp_ctx_new: mal_uri=: %s\n", mal_uri);
  }

  zctx_t *zmq_ctx = zctx_new();
  self->zmq_ctx = zmq_ctx;

  self->cnx_table = zhash_new();

  // Creates the TCP listening socket
  int listen = maltcp_ctx_socket_create(atoi(port), BACKLOG);
  assert(listen >= 0);
  self->mal_socket = listen;
  if (verbose)
    clog_debug(maltcp_logger, "maltcp_ctx: ptp listening to: %s\n", port);

  //inproc
  void *endpoints_socket = zsocket_new(zmq_ctx, ZMQ_ROUTER);
  self->endpoints_socket = endpoints_socket;
  zsocket_bind(endpoints_socket, ZLOOP_ENDPOINTS_SOCKET_URI);

  zloop_t *zloop = zloop_new();
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
      maltcp_ctx_send_message, maltcp_ctx_recv_message, maltcp_ctx_endpoint_init_operation,
      maltcp_ctx_poller_wait,
      maltcp_ctx_destroy_message,
      maltcp_ctx_start,
      maltcp_ctx_stop,
      maltcp_ctx_destroy);

  return self;
}

int maltcp_ctx_start(void *self) {
  clog_debug(maltcp_logger, "maltcp_ctx: running...\n");
  return zloop_start(((maltcp_ctx_t *)self)->zloop);
}

int maltcp_ctx_stop(void *self) {
  clog_debug(maltcp_logger, "maltcp_ctx: stop...\n");
  // Note: this method is not symmetric with maltcp_ctx_start, may be we have to
  // create and bind the socket in maltcp_ctx_start rather than in maltcp_ctx_new.
  close(((maltcp_ctx_t *)self)->mal_socket);
  zsocket_destroy(((maltcp_ctx_t *)self)->zmq_ctx, ((maltcp_ctx_t *)self)->endpoints_socket);
  // TODO (AF): Close all pollers?
  zloop_destroy(&((maltcp_ctx_t *)self)->zloop);
  clog_debug(maltcp_logger, "maltcp_ctx: stopped.\n");
  return 0;
}

int maltcp_ctx_destroy(void **self_p) {
  if (*self_p) {
    maltcp_ctx_t *self = (maltcp_ctx_t *) *self_p;
    free(self->maltcp_header);
    free(self);
    *self_p = NULL;
  }
  return 0;
}

#define URIOFFSET (3 + sizeof MALTCP_PROTOCOL -1)

// Returns hostname from a string like "maltcp://hostname:port/service"
char *gethostfromuri(char *uri) {
  char* ptr1 = strchr(uri +URIOFFSET, ':');
  if (ptr1 == NULL)
    return NULL;

  size_t len = (size_t) (ptr1 - uri -URIOFFSET);
  char* host = (char*) malloc(len +1);
  strncpy(host, uri +URIOFFSET, len);
  host[len] = '\0';

  clog_debug(maltcp_logger, "gethostfromuri(%s) -> %s ** %s **\n", uri, ptr1, host);

  return host;
}

// Returns port from a string like "maltcp://hostname:port/service"
int getportfromuri(char *uri) {
  char port[10];
  char* ptr1 = strchr(uri +URIOFFSET, ':');
  if (ptr1 == NULL)
    return -1;
  char* ptr2 = strchr(ptr1+1, '/');
  if (ptr2 == NULL)
    ptr2 = ptr1 + strlen(ptr1);

  size_t len = (size_t) (ptr2 - ptr1 -1);
  strncpy(port, ptr1+1, len);
  port[len] = '\0';

  clog_debug(maltcp_logger, "getportfromuri(%s) -> %s %s  ** %s **\n", uri, ptr1, ptr2, port);

  return atoi(port);
}

typedef struct maltcp_ctx_connection {
  int socket;
} maltcp_ctx_connection_t;

int maltcp_ctx_socket_connect(maltcp_ctx_t *self, mal_uri_t *socket_uri) {
  maltcp_ctx_connection_t *cnx_ptr = (maltcp_ctx_connection_t *) zhash_lookup(self->cnx_table, socket_uri);

  if (cnx_ptr == NULL) {
    clog_debug(maltcp_logger, "maltcp_ctx: open a new PTP socket\n");

    // Create a new connection
    struct hostent *server;
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
      clog_error(maltcp_logger, "Failed to create client socket: %s", strerror(errno));
      return -1;
    }

    // TODO (AF): host should be IP address
    if ((server = gethostbyname(gethostfromuri(socket_uri))) == NULL) {
      clog_error(maltcp_logger, "Failed to to get address: %s", strerror(errno));
      return -1;
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(getportfromuri(socket_uri));

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
      clog_error(maltcp_logger, "Failed to connect: %s", strerror(errno));
      return -1;
    }
    clog_debug(maltcp_logger, "client connected\n");

    clog_debug(maltcp_logger, "maltcp_ctx: connect to %s\n", socket_uri);

    cnx_ptr = (maltcp_ctx_connection_t*) malloc(sizeof(maltcp_ctx_connection_t));
    cnx_ptr->socket = client_socket;

    // TODO (AF):
    clog_debug(maltcp_logger, "maltcp_ctx: update TCP connections hashtable\n");
    zhash_update(self->cnx_table, socket_uri, cnx_ptr);
  }

  return cnx_ptr->socket;
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

  mal_uri_t *socket_uri = mal_message_get_uri_to(mal_message);
  clog_debug(maltcp_logger, "maltcp_ctx_send_message: socket_uri=%s\n", socket_uri);

  maltcp_endpoint_data_t *endpoint_data =
      (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  maltcp_ctx_connection_t *cnx_ptr = (maltcp_ctx_connection_t *) zhash_lookup(endpoint_data->remote_socket_table, socket_uri);

  int client_socket = -1;
  if (cnx_ptr == NULL) {
    clog_debug(maltcp_logger, "maltcp_ctx: open a new PTP socket\n");

    // Create a new connection
    struct hostent *server;
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
      clog_error(maltcp_logger, "Failed to create client socket: %s", strerror(errno));
      return -1;
    }

    // TODO (AF): host should be IP address
    if ((server = gethostbyname(gethostfromuri(socket_uri))) == NULL) {
      clog_error(maltcp_logger, "Failed to get address: %s", strerror(errno));
      exit(1);
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(getportfromuri(socket_uri));

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
      clog_error(maltcp_logger, "Failed to connect: %s", strerror(errno));
      exit(1);
    }
    clog_debug(maltcp_logger, "client connected\n");

    clog_debug(maltcp_logger, "maltcp_ctx: connect to %s\n", socket_uri);

    cnx_ptr = (maltcp_ctx_connection_t*) malloc(sizeof(maltcp_ctx_connection_t));
    cnx_ptr->socket = client_socket;

    // TODO (AF):
    clog_debug(maltcp_logger, "maltcp_ctx: update TCP connections hashtable\n");
    zhash_update(endpoint_data->remote_socket_table, socket_uri, cnx_ptr);
  } else {
    client_socket = cnx_ptr->socket;
  }

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

  //zframe_t *frame = zframe_new(bytes, encoding_length);
  clog_debug(maltcp_logger, "maltcp_ctx: send zmq message\n");

  // send the message
  send(client_socket, cursor.body_ptr, malbinary_cursor_get_length(&cursor), 0);

  clog_debug(maltcp_logger, "maltcp_ctx: message sent.\n");

  return rc;
}

int maltcp_ctx_recv_message(void *self, mal_endpoint_t *mal_endpoint, mal_message_t **message) {
  maltcp_ctx_t *maltcp_ctx = (maltcp_ctx_t *) self;
  maltcp_endpoint_data_t *endpoint_data = (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  int rc = 0;

  clog_debug(maltcp_logger, "maltcp_ctx_recv_message()\n");

  zmsg_t *zmsg = zmsg_recv(endpoint_data->socket);
  if (zmsg) {
    size_t frames_count = zmsg_size(zmsg);

    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: received zmsg (%d frames)\n", frames_count);

    // The MAL message is in the first frame.
    // Now the frame is owned by us.
    zframe_t *frame = zmsg_pop(zmsg);

    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: frame size = %d\n", zframe_size(frame));

    size_t mal_msg_bytes_length = zframe_size(frame);
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: mal_msg_bytes_length=%d\n", mal_msg_bytes_length);

    // Does not copy the frame bytes in another array.
    byte *mal_msg_bytes = zframe_data(frame);

    *message = mal_message_new_void();

    // MALTCP always uses the 'malbinary' encoding format for the messages encoding (another
    // format may be used at the application layer for the message body).

    // Note: We could use virtual allocation and initialization functions from encoder
    // rather than malbinary interface.
    malbinary_cursor_t cursor;
    malbinary_cursor_init(&cursor, (char *) mal_msg_bytes, mal_msg_bytes_length, 0);

    mal_uinteger_t mal_message_length;

    // 'maltcp' encoding format of the MAL header
    if (maltcp_decode_message(maltcp_ctx->maltcp_header, *message,
        maltcp_ctx->decoder, &cursor, &mal_message_length) != 0) {
      clog_error(maltcp_logger, "maltcp_ctx_recv_message, cannot decode message\n");
      return -1;
    }
    // Note: Currently the message length is always equal to the frame size.
    assert(mal_msg_bytes_length == mal_message_length);

    // Destroy must free the tcp frame
    mal_message_set_body_owner(*message, frame);

    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: ");
    if (clog_is_loggable(maltcp_logger, CLOG_DEBUG_LEVEL))
      mal_message_print(*message);
    clog_debug(maltcp_logger, "\n");

    // Verify that the message is for the current endpoint
    mal_uri_t *uri_to = mal_message_get_uri_to(*message);
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message: uri_to=%s\n", uri_to);

    // Verify if the message could be delivered and destroy it otherwise.
    if (endpoint_data->mal_endpoint) {
      bool message_delivered = false;
      mal_uri_t *endpoint_uri = mal_endpoint_get_uri(endpoint_data->mal_endpoint);
      if (strcmp(get_short_uri(endpoint_uri), get_short_uri(uri_to)) == 0)
        message_delivered = true;

      clog_debug(maltcp_logger, "maltcp_ctx_recv_message: message_delivered=%d\n", message_delivered);

      if (!message_delivered) {
        clog_debug(maltcp_logger, "maltcp_ctx_recv_message: destroy MAL message\n", uri_to);

        mal_message_destroy(message, maltcp_ctx->mal_ctx);
      }
    }
  } else {
    clog_debug(maltcp_logger, "maltcp_ctx_recv_message(): NULL\n");
  }

  return rc;
}

int maltcp_ctx_endpoint_init_operation(mal_endpoint_t *mal_endpoint,
    mal_message_t *message, mal_uri_t *uri_to, bool set_tid) {

  mal_message_set_uri_to(message, uri_to);
  mal_message_set_uri_from(message,  mal_endpoint_get_uri(mal_endpoint));
  mal_message_set_free_uri_from(message, false);
  if (set_tid) {
    mal_message_set_transaction_id(message, mal_endpoint_get_next_transaction_id_counter(mal_endpoint));
  }

  return mal_ctx_send_message(mal_endpoint_get_mal_ctx(mal_endpoint), mal_endpoint, message);
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

  size_t uri_length = strlen(MALTCP_PROTOCOL) + 3;
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
    strcat(uri, MALTCP_PROTOCOL);
    strcat(uri, "://");
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
    endpoint_data->remote_socket_table = zhash_new();

    mal_endpoint_set_endpoint_data(mal_endpoint, endpoint_data);

    clog_debug(maltcp_logger, "maltcp_ctx_create_endpoint: initialize endpoint\n");

    // Initialize the endpoint
    mal_uri_t *handler_uri = get_short_uri(mal_endpoint_get_uri(endpoint_data->mal_endpoint));

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
  maltcp_endpoint_data_t **self_p = (maltcp_endpoint_data_t **) endpoint_p;
  assert(self_p);
  if (*self_p) {
    maltcp_endpoint_data_t *self = *self_p;

    //  ... destroy your own state here
    if (self->remote_socket_table) {
      maltcp_ctx_connection_t *cnx_ptr =  (maltcp_ctx_connection_t*) zhash_first(self->remote_socket_table);
      while (cnx_ptr) {
        // TODO (AF): close registered TCP connections
        clog_debug(maltcp_logger, "maltcp_ctx_destroy_endpoint: close socket.\n");
        close(cnx_ptr->socket);
        // destroy all registered sockets
        cnx_ptr = (maltcp_ctx_connection_t*) zhash_next(self->remote_socket_table);
      }
      zhash_destroy(&self->remote_socket_table);
    }

    // mal_ctx and mal_endpoint must not be destroyed here
    // but where they have been created.

    free(self);
    *self_p = NULL;
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

  if (*self_p) {
    maltcp_poller_data_t *self = *self_p;
    zpoller_destroy(&self->poller);

    free(self->endpoints);

    // mal_ctx and mal_poller must not be destroyed here
    // but where they have been created.

    free(self);
    *self_p = NULL;
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

