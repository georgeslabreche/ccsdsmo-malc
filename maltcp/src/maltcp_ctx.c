/* */
#include "maltcp.h"

static const char ZLOOP_ENDPOINTS_SOCKET_URI[] = "inproc://zloop.endpoints";

static const char MALZMQ_PROTOCOL[] = "maltcp";

static const int HEADER_LENGTH = 23;

struct _maltcp_ctx_t {
  mal_ctx_t *mal_ctx;
  zctx_t *zmq_ctx;
  maltcp_mapping_uri_t *mapping_uri;
  char *hostname;
  char *port;
  void *mal_socket;         // server socket listening to remote mal contexts
  //PUBSUB TODO: remove
  //void *mal_pubsub_socket;  // server socket listening to remote mal contexts
  void *endpoints_socket;   // inproc connected to endpoints
  zloop_t *zloop;
  maltcp_header_t *maltcp_header;
  malbinary_encoder_t *encoder;
  malbinary_decoder_t *decoder;
};

//  --------------------------------------------------------------------------
//  The maltcp_endpoint_data_t structure holds the state for one end-point instance

// BE CAREFUL: This structure should be identical to the actor_endpoint_data_t
// structure used to create actor specific end-point (see mal_actor.c).
typedef struct {
  maltcp_ctx_t *maltcp_ctx;
  mal_endpoint_t *mal_endpoint;

  void *socket;
  zhash_t *remote_socket_table; // client sockets connected to remote mal contexts, key = uri
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

// Point-to-Point protocol used, should be tcp.
#define PTP_PROTOCOL         "tcp"
#define PTP_PROTOCOL_LENGTH  3

//PUBSUB TODO: remove
// Publish/Subscribe protocol used, should be tcp, epgm or pgm
//#define PUBSUB_PROTOCOL         "tcp"
//#define PUBSUB_PROTOCOL_LENGTH  3

mal_uri_t *get_uri_to(maltcp_ctx_t *self, mal_message_t *message) {
  if (self->mapping_uri && self->mapping_uri->getzmquri_to_fn) {
    return self->mapping_uri->getzmquri_to_fn(message);
  } else {
    mal_uri_t *uri_to = strdup(mal_message_get_uri_to(message));

    mal_uri_t *socket_uri = NULL;

    char **split = get_protocol_host_port(uri_to);
    char *hostname = split[1];
    char *port = split[2];

    if (mal_message_get_interaction_stage(message) != MAL_IP_STAGE_PUBSUB_PUBLISH) {
      // This not the publish URI, ex: tcp://192.168.1.46:5555
      socket_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 4 + strlen(port) + 1);
      // Need to set the final '\0' before using strcat
      socket_uri[0] = '\0';
      strcat(socket_uri, PTP_PROTOCOL "://");
      strcat(socket_uri, hostname);
      strcat(socket_uri, ":");
      strcat(socket_uri, port);
    }
    /* PUBSUB TODO: remove
     else {
      char *mcast_addr = NULL; // ex: 224.0.0.251
      char *network_interface = NULL; // ex: eth0

      // This the publish URI, ex: epgm://eth0;224.0.0.251:5555
      char pubsub_port[6];
      sprintf(pubsub_port,"%d", atoi(port) + 1);

      if (strcmp(PUBSUB_PROTOCOL, PROTOCOL_PGM) == 0 || strcmp(PUBSUB_PROTOCOL, PROTOCOL_EPGM) == 0) {
        size_t uri_length = PUBSUB_PROTOCOL_LENGTH + strlen(network_interface) + 4 + strlen(pubsub_port);
        if (mcast_addr)
          uri_length += strlen(mcast_addr) + 1;
        socket_uri = (mal_uri_t *) malloc(uri_length * sizeof(mal_uri_t *) + 1);

        // Need to set the final '\0' before using strcat
        socket_uri[0] = '\0';
        strcat(socket_uri, PUBSUB_PROTOCOL);
        strcat(socket_uri, "://");
        strcat(socket_uri, network_interface);
        strcat(socket_uri, ";");
        strcat(socket_uri, mcast_addr);
        strcat(socket_uri, ":");
        strcat(socket_uri, pubsub_port);
      } else {
        size_t uri_length = PUBSUB_PROTOCOL_LENGTH + strlen(hostname) + 5 + strlen(pubsub_port);
        socket_uri = (mal_uri_t *) malloc(uri_length * sizeof(mal_uri_t *) + 1);
        // Need to set the final '\0' before using strcat
        socket_uri[0] = '\0';
        strcat(socket_uri, PUBSUB_PROTOCOL);
        strcat(socket_uri, ":// *:");
        strcat(socket_uri, pubsub_port);
      }
    }
    */

    free(uri_to);
    return socket_uri;
  }
}

mal_uri_t *get_ptp_uri(maltcp_ctx_t *self, mal_uri_t *uri) {
  if (self->mapping_uri && self->mapping_uri->get_p2p_zmquri_fn) {
    return self->mapping_uri->get_p2p_zmquri_fn(uri);
  } else {
    char *dupuri = strdup(uri);

    char **split = get_protocol_host_port(dupuri);
    char *port = split[2];

    mal_uri_t *ptp_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 5 + strlen(port) + 1);
    // Need to set the final '\0' before using strcat
    ptp_uri[0] = '\0';
    strcat(ptp_uri, PTP_PROTOCOL "://*:");
    strcat(ptp_uri, port);

    free(dupuri);
    return ptp_uri;
  }
}

//PUBSUB TODO: remove
/*
mal_uri_t *get_ps_uri(maltcp_ctx_t *self, mal_uri_t *uri) {
  if (self->mapping_uri && self->mapping_uri->get_ps_zmquri_fn) {
    return self->mapping_uri->get_ps_zmquri_fn(uri);
  } else {
    char *dupuri = strdup(uri);

    char *mcast_addr = NULL; // ex: 224.0.0.251
    char **split = get_protocol_host_port(dupuri);
    char *hostname = split[1];
    char *port = split[2];
    char pubsub_port[6];
    sprintf(pubsub_port,"%d", atoi(port) + 1);

    mal_uri_t *ps_uri = NULL;
    if (strcmp(PUBSUB_PROTOCOL, PROTOCOL_PGM) == 0 || strcmp(PUBSUB_PROTOCOL, PROTOCOL_EPGM) == 0) {
      size_t uri_length = strlen(PUBSUB_PROTOCOL) + strlen(hostname) + 4 + strlen(pubsub_port);
      if (mcast_addr) {
        uri_length += strlen(mcast_addr) + 1;
      }
      ps_uri = (mal_uri_t *) malloc(uri_length * sizeof(mal_uri_t *) + 1);
      // Need to set the final '\0' before using strcat
      ps_uri[0] = '\0';
      //epgm://192.168.1.46;224.0.0.251:5555
      strcat(ps_uri, PUBSUB_PROTOCOL "://");
      strcat(ps_uri, hostname);
      strcat(ps_uri, ";");
      strcat(ps_uri, mcast_addr);
      strcat(ps_uri, ":");
      strcat(ps_uri, pubsub_port);
    } else {
      size_t uri_length = strlen(PUBSUB_PROTOCOL) + strlen(hostname) + 4 + strlen(pubsub_port);
      ps_uri = (mal_uri_t *) malloc(uri_length * sizeof(mal_uri_t *) + 1);
      // Need to set the final '\0' before using strcat
      ps_uri[0] = '\0';
      // tcp://192.168.1.46:5555
      strcat(ps_uri, PUBSUB_PROTOCOL "://");
      strcat(ps_uri, hostname);
      strcat(ps_uri, ":");
      strcat(ps_uri, pubsub_port);
    }

    free(dupuri);
    return ps_uri;
  }
}
*/

// zloop_fn interface for standard socket
int maltcp_ctx_mal_standard_socket_handle(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;

  mal_uoctet_t id [256];
  mal_uinteger_t id_size = 0;

  mal_uinteger_t mal_msg_bytes_length;
  zmq_msg_t zmsg;
  mal_uinteger_t offset =0;
  while (true) {
    id_size = zmq_recv (self->mal_socket, id, 256, 0);
    assert (id_size > 0);

    zmq_msg_t msg;
    //  Create an empty ØMQ message to hold the message part
    int rc = zmq_msg_init(&msg);
    assert (rc == 0);

    //  Block until a message is available to be received from socket
    rc = zmq_recvmsg(self->mal_socket, &msg, 0);
    assert (rc != -1);

    if (rc == 0)
      return 0;

    if (rc >= HEADER_LENGTH && offset == 0) {
      mal_uinteger_t offset_body_length = 19;
      int r = malbinary_decoder_decode_uinteger(self->decoder, (char *)zmq_msg_data(&msg), &offset_body_length, &mal_msg_bytes_length);
      assert(r==0);
      clog_debug(maltcp_logger, "maltcp_ctx_mal_standard_socket_handle: message size = %d\n", mal_msg_bytes_length);
      if (rc == mal_msg_bytes_length) {
        clog_debug(maltcp_logger, "maltcp_ctx_mal_standard_socket_handle: read size = %d, end.\n", rc);
        zmsg = msg;
        break;
      }
    }

    if ((offset+rc) < mal_msg_bytes_length) {
      clog_debug(maltcp_logger, "maltcp_ctx_mal_standard_socket_handle: read size = %d, more (continue)\n", rc);
      zmq_msg_init_size(&zmsg, mal_msg_bytes_length);
      char *data = (char*)zmq_msg_data(&zmsg);
      memcpy(data+offset, zmq_msg_data(&msg), rc);
    } else {
      //last read
      clog_debug(maltcp_logger, "maltcp_ctx_mal_standard_socket_handle: read size = %d, last.\n", rc);
      char *data = (char*)zmq_msg_data(&zmsg);
      memcpy(data+offset, zmq_msg_data(&msg), rc);
      break;
    }
    offset += rc;
    zmq_msg_close(&msg);
  }

  if (zmq_msg_size(&zmsg) > 0) {
    clog_debug(maltcp_logger, "maltcp_ctx_mal_standard_socket_handle: received size = %d\n", zmq_msg_size(&zmsg));
    return maltcp_ctx_mal_socket_handle(loop, poller, self, &zmsg, mal_msg_bytes_length, false);
  }
  return 0;
}

/*
 * //PUBSUB TODO: remove ?
// zloop_fn interface for pubsub socket
int maltcp_ctx_mal_pubsub_socket_handle(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) arg;
  zmsg_t *zmsg = zmsg_recv(self->mal_pubsub_socket);
  if (zmsg) {
    clog_debug(maltcp_logger, "maltcp_ctx_mal_pubsub_socket_handle: received zmsg size = %d\n", zmsg_size(zmsg));
    maltcp_ctx_mal_socket_handle(loop, poller, self, zmsg, true);
  }
  return 0;
}
*/

// This method handles messages received from standard or pubsub sockets.
int maltcp_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    maltcp_ctx_t *self, zmq_msg_t *zmsg, mal_uinteger_t msg_size, bool isPubsub) {

  clog_debug(maltcp_logger, "maltcp_ctx: maltcp_ctx_mal_socket_handle\n");
  if (zmsg != NULL) {
    clog_debug(maltcp_logger, "maltcp_ctx: received msg, decoding...\n");

    unsigned int offset = 0;
    mal_uri_t *uri_to;
    if (maltcp_decode_uri_to(self->maltcp_header,
        self->decoder, (char *)zmq_msg_data(zmsg), &offset, &uri_to) != 0) {
      clog_error(maltcp_logger, "maltcp_ctx_mal_socket_handle, could not decode uri_to\n");
      return -1;
    }

    clog_debug(maltcp_logger, "maltcp_ctx: msg decoded.\n");

    clog_debug(maltcp_logger, "maltcp_ctx: uri_to: %s\n", uri_to);

    mal_uri_t *short_uri_to = get_short_uri(uri_to);
    clog_debug(maltcp_logger, "maltcp_ctx: short_uri_to: %s\n", short_uri_to);

    // Re-send the message to the appropriate endpoint.
    // Normally the message will be deleted by the appropriate endpoint.
    // What happens if no endpoint reads this message? It seems that Router socket
    // discard messages if there are no readers.
    //zframe_t *identity_frame = zframe_new(short_uri_to, strlen(short_uri_to));
    zmq_msg_t identity;
    int rc = zmq_msg_init_data (&identity, short_uri_to, strlen(short_uri_to), NULL, NULL); assert (rc == 0);
    rc = zmq_msg_send(&identity, self->endpoints_socket, ZMQ_SNDMORE);
    assert(rc == strlen(short_uri_to));
    clog_debug(maltcp_logger, "maltcp_ctx: send identity (%d bytes) to endpoint %s\n", rc, short_uri_to);

    size_t msg_size = zmq_msg_size(zmsg);
    clog_debug(maltcp_logger, "maltcp_ctx: send message (%d frames) to endpoint %s\n", msg_size, short_uri_to);

    // Destroy URI To
    mal_uri_destroy(&uri_to);

    //int rc = zmsg_send(&zmsg, self->endpoints_socket);
    rc = zmq_msg_send(zmsg, self->endpoints_socket, ZMQ_DONTWAIT);
    assert(rc == msg_size);
  }

  clog_debug(maltcp_logger, "maltcp_ctx: zmsg handled.\n");
  return 0;
}

//  --------------------------------------------------------------------------
//  Provide the Binding functions

maltcp_ctx_t *maltcp_ctx_new(mal_ctx_t *mal_ctx,
    maltcp_mapping_uri_t *mapping_uri,
    char *hostname, char *port,
    maltcp_header_t *maltcp_header,
    malbinary_encoder_t *encoder, malbinary_decoder_t *decoder,
    bool verbose) {
  maltcp_ctx_t *self = (maltcp_ctx_t *) malloc(sizeof(maltcp_ctx_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->mapping_uri = mapping_uri;
  self->hostname = hostname;
  self->port = port;
  self->maltcp_header = maltcp_header;
  self->encoder = encoder;
  self->decoder = decoder;

  int mal_uri_len = strlen(hostname) + strlen(port) + 10;
  mal_uri_t mal_uri[mal_uri_len + 1];
  mal_uri[0] = '\0';
  strcat(mal_uri, "maltcp://");
  strcat(mal_uri, hostname);
  strcat(mal_uri, ":");
  strcat(mal_uri, port);

  if (verbose)
    clog_debug(maltcp_logger, "maltcp_ctx_new: mal_uri=: %s\n", mal_uri);

  zctx_t *zmq_ctx = zctx_new();
  self->zmq_ctx = zmq_ctx;

  // PTP : bind socket
  void *mal_socket = zsocket_new(zmq_ctx, ZMQ_STREAM);
  self->mal_socket = mal_socket;
  mal_uri_t *ptp_uri = get_ptp_uri(self, mal_uri);
  zsocket_bind(self->mal_socket, ptp_uri);
  if (verbose)
    clog_debug(maltcp_logger, "maltcp_ctx: ptp listening to: %s\n", ptp_uri);

  /*
   * //PUBSUB TODO: remove
  // PS : connect socket
  void *pub = zsocket_new(zmq_ctx, ZMQ_SUB);
  assert (pub);
  self->mal_pubsub_socket = pub;
  mal_uri_t *ps_uri = get_ps_uri(self, mal_uri);
  int rc = zsocket_connect(self->mal_pubsub_socket, ps_uri);
  assert(rc == 0);
  if (verbose)
    clog_debug(maltcp_logger, "maltcp_ctx: pubsub connect to: %s\n", ps_uri);
  zsocket_set_subscribe(self->mal_pubsub_socket, SUB_NAME);
 */

  //inproc
  void *endpoints_socket = zsocket_new(zmq_ctx, ZMQ_ROUTER);
  self->endpoints_socket = endpoints_socket;
  zsocket_bind(endpoints_socket, ZLOOP_ENDPOINTS_SOCKET_URI);

  zloop_t *zloop = zloop_new();
  self->zloop = zloop;

  // The poll item is a 0MQ socket, not a fd
  // therefore, 0 is passed as a second parameter for the fd value.
  // zmq_pollitem_t is a libzmq structure (not a czmq) that is
  // not kept by the poller. It is only used as a set of parameters.
  zmq_pollitem_t poller = { self->mal_socket, 0, ZMQ_POLLIN };
  int rc = zloop_poller(zloop, &poller, maltcp_ctx_mal_standard_socket_handle, self);
  assert(rc == 0);

  /*
   * //PUBSUB TODO: remove
  poller.socket = self->mal_pubsub_socket;
  rc = zloop_poller(zloop, &poller, maltcp_ctx_mal_pubsub_socket_handle, self);
  assert(rc == 0);
  */

  mal_ctx_set_binding(
      mal_ctx, self,
      maltcp_ctx_create_uri,
      maltcp_ctx_create_endpoint, maltcp_ctx_destroy_endpoint,
      maltcp_ctx_create_poller, maltcp_ctx_destroy_poller,
      maltcp_ctx_poller_add_endpoint, maltcp_ctx_poller_del_endpoint,
      maltcp_ctx_send_message, maltcp_ctx_recv_message,
      maltcp_ctx_poller_wait,
      maltcp_ctx_destroy_message);

  return self;
}

int maltcp_ctx_start(maltcp_ctx_t *self) {
  clog_debug(maltcp_logger, "maltcp_ctx: running...\n");
  return zloop_start(self->zloop);
}

void maltcp_ctx_destroy(maltcp_ctx_t **self_p) {
  if (*self_p) {
    maltcp_ctx_t *self = *self_p;
    free(self->maltcp_header);
    free(self);
    *self_p = NULL;
  }
}

// Must be compliant with MAL virtual function: void *self
int maltcp_ctx_send_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *mal_message) {
  maltcp_ctx_t *maltcp_ctx = (maltcp_ctx_t *) self;

  if (clog_is_loggable(maltcp_logger, CLOG_INFO_LEVEL)) {
    clog_info(maltcp_logger, "maltcp_ctx_send_message()\n");
    mal_message_print(mal_message);
    clog_info(maltcp_logger, "\n");
  }

  int rc = 0;

  mal_uri_t *socket_uri = get_uri_to(maltcp_ctx, mal_message);

  clog_debug(maltcp_logger, "maltcp_ctx_send_message: socket_uri=%s\n", socket_uri);

  maltcp_endpoint_data_t *endpoint_data =
      (maltcp_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  void *socket = zhash_lookup(endpoint_data->remote_socket_table, socket_uri);

  if (socket == NULL) {
    // Open a new socket

    if (mal_message_get_interaction_stage(mal_message) != MAL_IP_STAGE_PUBSUB_PUBLISH) {
      clog_debug(maltcp_logger, "maltcp_ctx: open a new PTP socket\n");
      socket = zsocket_new(maltcp_ctx->zmq_ctx, ZMQ_STREAM);
      clog_debug(maltcp_logger, "maltcp_ctx: connect to %s\n", socket_uri);
      zmq_connect(socket, socket_uri);
    }
    /*
     * //PUBSUB TODO: remove
    else {
      clog_debug(maltcp_logger, "maltcp_ctx: open a new PUBSUB socket\n");
      socket = zsocket_new(maltcp_ctx->zmq_ctx, ZMQ_PUB);

      int val = 0;
      rc = zmq_setsockopt(socket, ZMQ_LINGER, &val, sizeof(val));
      assert (rc == 0);

      clog_debug(maltcp_logger, "maltcp_ctx: bind to %s\n", socket_uri);

      rc = zsocket_bind(socket, socket_uri);
      assert(rc);
      // Avoid to lost the first message
      zclock_sleep (500);
    }
    */

    clog_debug(maltcp_logger, "maltcp_ctx: update table\n");
    zhash_update(endpoint_data->remote_socket_table, socket_uri, socket);
  }

  clog_debug(maltcp_logger, "maltcp_ctx: mal_message_add_encoding_length_malbinary\n");

  unsigned int encoding_length = 0;

  // TODO: In a first time we should separate the header and body size in order to send them
  // in separate frames. In a second time we should cut the message in multiples frames.

  // maltcp_add_message_encoding_length should not add body_length to encoding length
  // bytes should content uniquely the header
  // maltcp_encode_message should not copy the body to the bytes array
  // we should creates and send 2 frames

  // 'maltcp' encoding format of the MAL header
  rc = maltcp_add_message_encoding_length(maltcp_ctx->maltcp_header, mal_message, maltcp_ctx->encoder, &encoding_length);
  if (rc < 0)
    return rc;

  clog_debug(maltcp_logger, "maltcp_ctx: encoding_length=%d\n", encoding_length);

  char *bytes = (char *) malloc(encoding_length);

  clog_debug(maltcp_logger, "maltcp_ctx: mal_message_encode_malbinary\n");

  unsigned int offset = 0;

  // 'maltcp' encoding format of the MAL header
  rc = maltcp_encode_message(maltcp_ctx->maltcp_header, mal_message,
      maltcp_ctx->encoder, bytes, &offset);
  if (rc < 0)
    return rc;

  clog_debug(maltcp_logger, "maltcp_ctx: message is encoded: %d bytes\n", offset);

  //zframe_t *frame = zframe_new(bytes, encoding_length);
  clog_debug(maltcp_logger, "maltcp_ctx: send zmq message\n");

  if (mal_message_get_interaction_stage(mal_message) != MAL_IP_STAGE_PUBSUB_PUBLISH) {
    // send one frame on send stage
    //rc = zframe_send(&frame, socket, 0);

    unsigned char id [256];
    size_t id_size = 256;
    // Must currently resort to the libzmq low-level lib to obtain
    // raw identity information because CZMQ is returning the binary
    // identity data as a char* and often there is 0 in the data which
    // prematurely terminates the char* data.
    rc = zmq_getsockopt(socket, ZMQ_IDENTITY, id, &id_size);
    assert (rc == 0);

    /* Sends the ID frame followed by the response */
    zmq_send (socket, id, id_size, ZMQ_SNDMORE);
    zmq_send (socket, (char *) bytes, offset, 0);
    clog_debug(maltcp_logger, "maltcp_ctx: zmq message (%d) sended.\n", offset);

    /* TODO: use zmq_msg_* ?
    zmq_msg_t msg;
    int rc = zmq_msg_init_data (&msg, (char *) bytes, encoding_length, NULL, NULL); assert (rc == 0);
    rc = zmq_msg_send(&msg, socket, 0);
    assert(rc == encoding_length);
     */

    /* Closes the connection by sending the ID frame followed by a zero response */
    //zmq_send (socket, id, id_size, ZMQ_SNDMORE);
    //zmq_send (socket, 0, 0, ZMQ_SNDMORE);
    /* NOTE: If we don't use ZMQ_SNDMORE, then we won't be able to send more */
    /* message to any client */
  }
  /*
   * //PUBSUB TODO: remove
  else {
    // send two frames on publish stage
    rc = zstr_sendm(socket, SUB_NAME);
    clog_debug(maltcp_logger, "maltcp_ctx: send the SUB_NAME, rc = %d\n", rc);
    rc = zframe_send(&frame, socket, 0);
    clog_debug(maltcp_logger, "maltcp_ctx: zframe_send the message,  rc = %d\n", rc);
    assert(rc == 0);
  }
  */
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

    // MALTCP always uses the 'malbinary' encoding format for the messages encoding (another format
    // may be used at the application layer for the message body).
    unsigned int offset = 0;

    mal_uoctet_t encoding_id;
    mal_uinteger_t mal_message_length;

    // 'maltcp' encoding format of the MAL header
    if (maltcp_decode_message(maltcp_ctx->maltcp_header, *message,
        maltcp_ctx->decoder, (char *) mal_msg_bytes, &offset,
        mal_msg_bytes_length, &encoding_id, &mal_message_length) != 0) {
      clog_error(maltcp_logger, "maltcp_ctx_recv_message, cannot decode message\n");
      return -1;
    }

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

  size_t uri_length = strlen(MALZMQ_PROTOCOL) + 3;
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
    strcat(uri, MALZMQ_PROTOCOL);
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
      void *socket = zhash_first(self->remote_socket_table);
      while (socket) {
        // destroy all registered sockets
        zsocket_destroy(self->maltcp_ctx->zmq_ctx, socket);
        socket = zhash_next(self->remote_socket_table);
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

  clog_debug(maltcp_logger, "maltcp_ctx_poller_wait()\n");

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

