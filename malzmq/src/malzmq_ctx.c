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
#include "malzmq.h"

static const char ZLOOP_ENDPOINTS_SOCKET_URI[] = "inproc://zloop.endpoints";

struct _malzmq_ctx_t {
  mal_ctx_t *mal_ctx;
  zctx_t *zmq_ctx;
  malzmq_mapping_uri_t *mapping_uri;
  char *hostname;
  char *port;
  void *mal_socket;         // server socket listening to remote mal contexts
  void *mal_pubsub_socket;  // server socket listening to remote mal contexts
  void *endpoints_socket;   // inproc connected to endpoints
  zloop_t *zloop;
  malzmq_header_t *malzmq_header;
  // Private encoder / decoder used for PDU, always varint as the fixed part of the PDU
  // is handled directly through malbinary methods.
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

void malzmq_ctx_set_encoder_log_level(malzmq_ctx_t *self, int level) {
  if (self != NULL)
    mal_encoder_set_log_level(self->encoder, level);
}

void malzmq_ctx_set_decoder_log_level(malzmq_ctx_t *self, int level) {
  if (self != NULL)
    mal_decoder_set_log_level(self->decoder, level);
}

//  --------------------------------------------------------------------------
//  The malzmq_endpoint_data_t structure holds the state for one end-point instance

// BE CAREFUL: This structure should be identical to the actor_endpoint_data_t
// structure used to create actor specific end-point (see mal_actor.c).
typedef struct {
  malzmq_ctx_t *malzmq_ctx;
  mal_endpoint_t *mal_endpoint;
  void *socket;
  zhash_t *remote_socket_table; // client sockets connected to remote mal contexts, key = uri
} malzmq_endpoint_data_t;

//  --------------------------------------------------------------------------
//  The malzmq_poller_data_t structure holds the state for multiples endpoint instances

typedef struct {
  malzmq_ctx_t *malzmq_ctx;
  mal_poller_t *mal_poller;

  zpoller_t *poller;          //  Socket poller

  int idx, max;
  malzmq_endpoint_data_t **endpoints;
} malzmq_poller_data_t;

// Default size for poller table
#define MAL_POLLER_LIST_DFLT_SIZE 20

malzmq_endpoint_data_t* malzmq_get_endpoint(malzmq_poller_data_t *poller_data, zsock_t *socket) {
  clog_info(malzmq_logger, " *** mal_routing_get_endpoint: \n");

  for (int i=0; i<poller_data->idx; i++) {
    if (poller_data->endpoints[i]->socket == socket) {
      clog_debug(malzmq_logger, " *** mal_routing_get_endpoint: OK\n");
      return poller_data->endpoints[i];
    }
  }
  return NULL;
}

int malzmq_add_endpoint(malzmq_poller_data_t *poller_data, mal_endpoint_t *endpoint) {
  clog_info(malzmq_logger, " *** malzmq_add_endpoint: %s\n", mal_endpoint_get_uri(endpoint));

  if (poller_data->idx < poller_data->max) {
    // Includes the structure in the table
    poller_data->endpoints[poller_data->idx++] =
        (malzmq_endpoint_data_t *) mal_endpoint_get_endpoint_data(endpoint);
    return 0;
  } else {
    clog_error(malzmq_logger, "Error :: Cannot add more than %d endpoints\n", poller_data->max);
    return -1;
  }
}

int malzmq_del_endpoint(malzmq_poller_data_t *poller_data, mal_endpoint_t *endpoint) {
  clog_info(malzmq_logger, " *** malzmq_del_endpoint: %s\n",  mal_endpoint_get_uri(endpoint));

  int found = -1;
  for (int i=0; i<poller_data->idx; i++) {
    if ((poller_data->endpoints[i] != NULL) &&
        (poller_data->endpoints[i] == mal_endpoint_get_endpoint_data(endpoint))) {
      found = i;
      break;
    }
  }

  if (found == -1) {
    clog_warning(malzmq_logger, " *** malzmq_del_endpoint: Not found\n");
    return -1;
  }

  poller_data->idx -= 1;
  for (int i=found; i<poller_data->idx; i++) {
    poller_data->endpoints[i] = poller_data->endpoints[i+1];
  }
  poller_data->endpoints[poller_data->idx] = NULL;

  clog_debug(malzmq_logger, " *** malzmq_del_endpoint: OK\n");
  return 0;
}

// ************************************************************
// Default URI mapping
// ************************************************************

mal_uri_t *get_remote_ptp_zmtp_uri(malzmq_ctx_t *self, mal_uri_t *uri_to) {
  if (self->mapping_uri && self->mapping_uri->get_remote_ptp_zmtp_uri) {
    return self->mapping_uri->get_remote_ptp_zmtp_uri(uri_to);
  } else {
    // Default handling of URI using TCP for all interactions
    mal_uri_t *socket_uri = NULL;

    char *hostname = malzmq_get_host_from_uri(uri_to);
    int port = malzmq_get_port_from_uri(uri_to);

    socket_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 3 + strlen(hostname) + 1 + 5 + 1);
    sprintf(socket_uri, "%s://%s:%d", PTP_PROTOCOL, hostname, port);
    free(hostname);
    clog_debug(malzmq_logger, "##### get_remote_ptp_zmtp_uri: %s\n", socket_uri);
    return socket_uri;
  }
}

mal_uri_t *get_remote_mcast_zmtp_uri(malzmq_ctx_t *self, mal_uri_t *uri_to) {
  if (self->mapping_uri && self->mapping_uri->get_remote_mcast_zmtp_uri) {
    return self->mapping_uri->get_remote_mcast_zmtp_uri(uri_to);
  } else {
    // Default handling of URI using TCP for all interactions
    mal_uri_t *socket_uri = NULL;

    char *hostname = malzmq_get_host_from_uri(uri_to);
    int port = malzmq_get_port_from_uri(uri_to);

    // This the publish URI, ex: epgm://eth0;224.0.0.251:5555
    if (strcmp(PUBSUB_PROTOCOL, PROTOCOL_PGM) == 0 || strcmp(PUBSUB_PROTOCOL, PROTOCOL_EPGM) == 0) {
      // TODO (AF): We should fix these parameters below
      char *mcast_addr = NULL; // ex: 224.0.0.251
      char *network_interface = NULL; // ex: eth0

      size_t uri_length = PUBSUB_PROTOCOL_LENGTH + 3 + strlen(network_interface) + 1 + 1 + 5 + 1;
      if (mcast_addr)
        uri_length += strlen(mcast_addr);
      socket_uri = (mal_uri_t *) malloc(uri_length);
      sprintf(socket_uri, "%s://%s;%s:%d", PUBSUB_PROTOCOL, network_interface, mcast_addr?mcast_addr:"", (port +1));
    } else {
      //ex: "tcp://*:5555"
      socket_uri = (mal_uri_t *) malloc(PUBSUB_PROTOCOL_LENGTH + 3 + strlen(hostname) + 1 + 5 + 1);
      sprintf(socket_uri, "%s://%s:%d", PUBSUB_PROTOCOL, hostname, (port +1));
    }

    free(hostname);
    clog_debug(malzmq_logger, "##### get_remote_mcast_zmtp_uri: %s\n", socket_uri);
    return socket_uri;
  }
}

mal_uri_t *get_local_ptp_zmtp_uri(malzmq_ctx_t *self, mal_uri_t *uri) {
  if (self->mapping_uri && self->mapping_uri->get_local_ptp_zmtp_uri) {
    return self->mapping_uri->get_local_ptp_zmtp_uri(uri);
  } else {
    int port = malzmq_get_port_from_uri(uri);
    mal_uri_t *ptp_uri = (mal_uri_t *) malloc(PTP_PROTOCOL_LENGTH + 5 + 5 + 1);
    sprintf(ptp_uri, "%s://*:%d", PTP_PROTOCOL, port);
    clog_debug(malzmq_logger, "##### get_local_ptp_zmtp_uri: %s\n", ptp_uri);
    return ptp_uri;
  }
}

mal_uri_t *get_local_mcast_zmtp_uri(malzmq_ctx_t *self, mal_uri_t *uri) {
  if (self->mapping_uri && self->mapping_uri->get_local_mcast_zmtp_uri) {
    return self->mapping_uri->get_local_mcast_zmtp_uri(uri);
  } else {
    char *hostname = malzmq_get_host_from_uri(uri);
    int port = malzmq_get_port_from_uri(uri);

    // TODO (AF): We should fix this parameter below
    char *mcast_addr = NULL; // ex: 224.0.0.251

    mal_uri_t *mcast_uri = NULL;
    if (strcmp(PUBSUB_PROTOCOL, PROTOCOL_PGM) == 0 || strcmp(PUBSUB_PROTOCOL, PROTOCOL_EPGM) == 0) {
      size_t uri_length = PUBSUB_PROTOCOL_LENGTH + 3 + strlen(hostname) + 1 + 1 + 5 + 1;
      if (mcast_addr)
        uri_length += strlen(mcast_addr);

      mcast_uri = (mal_uri_t *) malloc(uri_length);
      sprintf(mcast_uri, "%s://%s;%s:%d", PUBSUB_PROTOCOL, hostname, mcast_addr?mcast_addr:"", (port +1));
    } else {
//      size_t uri_length = PUBSUB_PROTOCOL_LENGTH + 3 + strlen(hostname) + 1 + 5 + 1;
      size_t uri_length = PUBSUB_PROTOCOL_LENGTH + 3 + 1 + 1 + 5 + 1;
      mcast_uri = (mal_uri_t *) malloc(uri_length);
//      sprintf(mcast_uri, "%s://%s:%d", PUBSUB_PROTOCOL, hostname, (port +1));
      sprintf(mcast_uri, "%s://*:%d", PUBSUB_PROTOCOL, (port +1));
    }

    clog_debug(malzmq_logger, "##### get_local_mcast_zmtp_uri: %s\n", mcast_uri);

    free(hostname);
    return mcast_uri;
  }
}

int malzmq_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    malzmq_ctx_t *self, zmsg_t *zmsg, bool isPubsub);

// TODO (AF): The 2 functions below should be merged in a unique one (malzmq_ctx_mal_socket_handle, see above)
// using the poller parameter to determine which socket to read the message.

// zloop_fn interface for standard socket
int malzmq_ctx_mal_standard_socket_handle(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  malzmq_ctx_t *self = (malzmq_ctx_t *) arg;
  if (self->mal_socket == NULL) {
    // The context is closed, return
    clog_debug(malzmq_logger, "malzmq_ctx_mal_standard_socket_handle: socket (%d) closed\n", poller->fd);
    return -1;
  }

  zmsg_t *zmsg = zmsg_recv(self->mal_socket);
  if (zmsg) {
    clog_debug(malzmq_logger, "malzmq_ctx_mal_standard_socket_handle: received zmsg size = %d\n", zmsg_size(zmsg));
    return malzmq_ctx_mal_socket_handle(loop, poller, self, zmsg, false);
  }
  return 0;
}

// zloop_fn interface for pubsub socket
int malzmq_ctx_mal_pubsub_socket_handle(zloop_t *loop, zmq_pollitem_t *poller, void *arg) {
  malzmq_ctx_t *self = (malzmq_ctx_t *) arg;
  if (self->mal_pubsub_socket == NULL) {
    // The context is closed, return
    clog_debug(malzmq_logger, "malzmq_ctx_mal_pubsub_socket_handle: socket (%d) closed\n", poller->fd);
    return -1;
  }

  zmsg_t *zmsg = zmsg_recv(self->mal_pubsub_socket);
  if (zmsg) {
    clog_debug(malzmq_logger, "malzmq_ctx_mal_pubsub_socket_handle: received zmsg size = %d\n", zmsg_size(zmsg));
    return malzmq_ctx_mal_socket_handle(loop, poller, self, zmsg, true);
  }
  return 0;
}

// This method handles messages received from standard or pubsub sockets.
int malzmq_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    malzmq_ctx_t *self, zmsg_t *zmsg, bool isPubsub) {

  clog_debug(malzmq_logger, "malzmq_ctx: malzmq_ctx_mal_socket_handle\n");

  if (zmsg) {
    clog_debug(malzmq_logger, "malzmq_ctx: received zmsg, decoding...\n");

    // Remove the first frame: this frame contains the identity of the sender and it is
    // currently unused.
    zframe_t *frame = zmsg_pop(zmsg);
    zframe_destroy(&frame);

    clog_debug(malzmq_logger, "malzmq_ctx: zmsg size: %d\n", zmsg_size(zmsg));

    // The MAL message is in the next frames, leave the frames in the zmsg (don't pop the frame)
    // as the zmsg is sent again to the endpoint. This frame should contains at least the header.
    frame = zmsg_next(zmsg);

    clog_debug(malzmq_logger, "malzmq_ctx: frame size: %d\n", zframe_size(frame));

    mal_uri_t *uri_to;
    if (malzmq_decode_uri_to(self->malzmq_header,
        self->decoder, (char *) zframe_data(frame), zframe_size(frame), &uri_to) != 0) {
      clog_error(malzmq_logger, "malzmq_ctx_mal_socket_handle, could not decode uri_to\n");
      return -1;
    }

    clog_debug(malzmq_logger, "malzmq_ctx: zmsg decoded.\n");

    clog_debug(malzmq_logger, "malzmq_ctx: uri_to: %s\n", uri_to);

    mal_uri_t *short_uri_to = malzmq_get_service_from_uri(uri_to);
    clog_debug(malzmq_logger, "malzmq_ctx: short_uri_to: %s\n", short_uri_to);

    // Re-send the message to the appropriate endpoint.
    // Normally the message will be deleted by the appropriate endpoint.
    // What happens if no endpoint reads this message? It seems that Router socket
    // discard messages if there are no readers.
    zframe_t *identity_frame = zframe_new(short_uri_to, strlen(short_uri_to));
    zmsg_push(zmsg, identity_frame);

    clog_debug(malzmq_logger, "malzmq_ctx: send message (%d frames) to endpoint %s\n",
        zmsg_size(zmsg), short_uri_to);

    // Destroy URI To
    mal_uri_destroy(&uri_to);

    int rc = zmsg_send(&zmsg, self->endpoints_socket);
    assert(rc == 0);
  }

  clog_debug(malzmq_logger, "malzmq_ctx: zmsg handled.\n");
  return 0;
}

//  --------------------------------------------------------------------------
//  Provide the Binding functions

malzmq_ctx_t *malzmq_ctx_new(mal_ctx_t *mal_ctx,
    malzmq_mapping_uri_t *mapping_uri,
    char *hostname, char *port,
    malzmq_header_t *malzmq_header,
    // TODO: no longer used
    bool verbose) {
  malzmq_ctx_t *self = (malzmq_ctx_t *) malloc(sizeof(malzmq_ctx_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->mapping_uri = mapping_uri;
  self->hostname = hostname;
  self->port = port;
  self->malzmq_header = malzmq_header;

  self->encoder = malbinary_encoder_new(true);
  self->decoder = malbinary_decoder_new(true);

  int mal_uri_len = strlen(hostname) + strlen(port) + 10;
  mal_uri_t mal_uri[mal_uri_len + 1];
  sprintf(mal_uri, "%s%s:%s", MALZMTP_URI, hostname, port);

  clog_debug(malzmq_logger, "malzmq_ctx_new: mal_uri=: %s\n", mal_uri);

  zctx_t *zmq_ctx = zctx_new();
  self->zmq_ctx = zmq_ctx;

  // PTP : bind socket
  mal_uri_t *ptp_uri = get_local_ptp_zmtp_uri(self, mal_uri);
  void *mal_socket = zsocket_new(zmq_ctx, ZMQ_ROUTER);
  self->mal_socket = mal_socket;
  zsocket_bind(self->mal_socket, ptp_uri);
  clog_debug(malzmq_logger, "malzmq_ctx: ptp listening to: %s\n", ptp_uri);

  // PS : bind socket
  mal_uri_t *mcast_uri = get_local_mcast_zmtp_uri(self, mal_uri);
  if (mcast_uri != NULL) {
    void *sub = zsocket_new(zmq_ctx, ZMQ_SUB);
    assert(sub);
    self->mal_pubsub_socket = sub;
    zsocket_bind(self->mal_pubsub_socket, mcast_uri);
    clog_debug(malzmq_logger, "malzmq_ctx: mcast bound to: %s / \"%s\"\n", mcast_uri, SUB_NAME);
    zsocket_set_subscribe(self->mal_pubsub_socket, SUB_NAME);
  } else {
    self->mal_pubsub_socket = NULL;
    clog_debug(malzmq_logger, "malzmq_ctx: mcast channel disable\n");
  }

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
  int rc = zloop_poller(zloop, &poller, malzmq_ctx_mal_standard_socket_handle, self);
  assert(rc == 0);

  if (self->mal_pubsub_socket != NULL) {
    poller.socket = self->mal_pubsub_socket;
    rc = zloop_poller(zloop, &poller, malzmq_ctx_mal_pubsub_socket_handle, self);
    assert(rc == 0);
  }

  mal_ctx_set_binding(
      mal_ctx, self,
      malzmq_ctx_create_uri,
      malzmq_ctx_create_endpoint, malzmq_ctx_destroy_endpoint,
      malzmq_ctx_create_poller, malzmq_ctx_destroy_poller,
      malzmq_ctx_poller_add_endpoint, malzmq_ctx_poller_del_endpoint,
      malzmq_ctx_send_message, malzmq_ctx_recv_message,
      malzmq_ctx_poller_wait,
      malzmq_ctx_destroy_message,
      malzmq_ctx_start,
      malzmq_ctx_stop,
      malzmq_ctx_destroy);

  return self;
}

int malzmq_ctx_start(void *self) {
  clog_debug(malzmq_logger, "malzmq_ctx: running...\n");
  return zloop_start(((malzmq_ctx_t *)self)->zloop);
}

int malzmq_ctx_stop(void *self) {
  malzmq_ctx_t *mal_ctx = (malzmq_ctx_t *) self;

  clog_debug(malzmq_logger, "malzmq_ctx: stop...\n");

  if (mal_ctx->mal_socket != NULL) {
    void* socket = mal_ctx->mal_socket;
    mal_ctx->mal_socket = NULL;
    zsocket_signal(socket);
    zmq_close(socket);

    clog_debug(malzmq_logger, "malzmq_ctx_stop: close socket.\n");
  }

  if (mal_ctx->mal_pubsub_socket != NULL) {
    void* socket = mal_ctx->mal_pubsub_socket;
    mal_ctx->mal_pubsub_socket = NULL;
    zsocket_signal(socket);
    zmq_close(socket);

    clog_debug(malzmq_logger, "malzmq_ctx_stop: close pubsub.\n");
  }

  return 0;
}

int malzmq_ctx_destroy(void **self_p) {
  if (self_p && *self_p) {
    malzmq_ctx_t *self = (malzmq_ctx_t *) *self_p;
    free(self->malzmq_header);
    free(self);
    *self_p = NULL;
  }
  return 0;
}

int trap_publish_register(mal_endpoint_t *mal_endpoint, mal_message_t *init_message, mal_uoctet_t stage);

// Must be compliant with MAL virtual function: void *self
int malzmq_ctx_send_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *mal_message) {
  malzmq_ctx_t *malzmq_ctx = (malzmq_ctx_t *) self;

  mal_interactiontype_t interaction = mal_message_get_interaction_type(mal_message);
  mal_uoctet_t stage = mal_message_get_interaction_stage(mal_message);
  if ((interaction == MAL_INTERACTIONTYPE_PUBSUB) &&
      malzmq_header_is_internal_broker(malzmq_ctx->malzmq_header)) {
    // Note: Currently catch the PUBLISH_(DE)REGISTER message in order to automatically send
    // the corresponding ack. This code corresponds to the current ZMQ implementation of the
    // Pub/Sub interaction.
    if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER) {
      return trap_publish_register(mal_endpoint, mal_message, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK);
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER) {
      return trap_publish_register(mal_endpoint, mal_message, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK);
    }
  }

  mal_uri_t *uri_to = mal_message_get_uri_to(mal_message);
  mal_uri_t *ptp_uri = get_remote_ptp_zmtp_uri(malzmq_ctx, uri_to);
  mal_uri_t *mcast_uri = NULL;
  if ((interaction == MAL_INTERACTIONTYPE_PUBSUB) &&
      (stage == MAL_IP_STAGE_PUBSUB_PUBLISH)) {
    // In the current implementation only PUBLISH message are sent through
    // the multicast channel if defined.
    mcast_uri = get_remote_mcast_zmtp_uri(malzmq_ctx, uri_to);
  }

  clog_debug(malzmq_logger, "malzmq_ctx_send_message: socket_uri=%s, %s\n", ptp_uri, mcast_uri);

  if (clog_is_loggable(malzmq_logger, CLOG_INFO_LEVEL)) {
    clog_info(malzmq_logger, "malzmq_ctx_send_message()\n");
    mal_message_print(mal_message);
    clog_info(malzmq_logger, "\n");
  }

  int rc = 0;

  malzmq_endpoint_data_t *endpoint_data =
      (malzmq_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  void *socket = NULL;
  if (mcast_uri != NULL) {
    // Needs to use the multicast channel, get the corresponding socket
    socket = zhash_lookup(endpoint_data->remote_socket_table, mcast_uri);
  } else {
    // Gets the corresponding PTP socket
    socket = zhash_lookup(endpoint_data->remote_socket_table, ptp_uri);
  }

  if (socket == NULL) {
    // Open a new socket
    mal_uri_t *socket_uri = NULL;

    if (mcast_uri == NULL) {
      socket_uri = ptp_uri;
      clog_debug(malzmq_logger, "malzmq_ctx: open a new PTP socket\n");
      socket = zsocket_new(malzmq_ctx->zmq_ctx, ZMQ_DEALER);

      clog_debug(malzmq_logger, "malzmq_ctx: connect to %s\n", socket_uri);
      zmq_connect(socket, socket_uri);
    } else {
      socket_uri = mcast_uri;
      clog_debug(malzmq_logger, "malzmq_ctx: open a new PUBSUB socket\n");
      socket = zsocket_new(malzmq_ctx->zmq_ctx, ZMQ_PUB);

      int val = 0;
      rc = zmq_setsockopt(socket, ZMQ_LINGER, &val, sizeof(val));
      assert (rc == 0);

      clog_debug(malzmq_logger, "malzmq_ctx: connect to %s\n", socket_uri);
      zmq_connect(socket, socket_uri);

      // Avoid to lost the first message
      zclock_sleep (500);
    }
    clog_debug(malzmq_logger, "malzmq_ctx: update table\n");
    zhash_update(endpoint_data->remote_socket_table, socket_uri, socket);
  }

  clog_debug(malzmq_logger, "malzmq_ctx: mal_message_add_encoding_length_malbinary\n");

  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_t cursor;
  malbinary_cursor_reset(&cursor);

  // TODO: In a first time we should separate the header and body size in order to send them
  // in separate frames. In a second time we should cut the message in multiples frames.

  // malzmq_add_message_encoding_length should not add body_length to encoding length
  // bytes should content uniquely the header
  // malzmq_encode_message should not copy the body to the bytes array
  // we should creates and send 2 frames

  // 'malzmq' encoding format of the MAL header
  rc = malzmq_add_message_encoding_length(malzmq_ctx->malzmq_header, mal_message, malzmq_ctx->encoder, &cursor);
  if (rc < 0)
    return rc;

  clog_debug(malzmq_logger, "malzmq_ctx: encoding_length=%d\n", malbinary_cursor_get_length(&cursor));

  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_init(&cursor,
      (char *) malloc(malbinary_cursor_get_length(&cursor)),
      malbinary_cursor_get_length(&cursor),
      0);

  clog_debug(malzmq_logger, "malzmq_ctx: mal_message_encode_malbinary\n");

  // 'malzmq' encoding format of the MAL header
  rc = malzmq_encode_message(malzmq_ctx->malzmq_header, mal_message, malzmq_ctx->encoder, &cursor);
  if (rc < 0)
    return rc;

  clog_debug(malzmq_logger, "malzmq_ctx: message is encoded: %d bytes\n", malbinary_cursor_get_offset(&cursor));

  zframe_t *frame = zframe_new(cursor.body_ptr, malbinary_cursor_get_length(&cursor));

  clog_debug(malzmq_logger, "malzmq_ctx: send zmq message\n");

  if (mcast_uri == NULL) {
    // send one frame on send stage
    rc = zframe_send(&frame, socket, 0);
    assert(rc == 0);
  } else {
    // send two frames on publish stage
    rc = zstr_sendm(socket, SUB_NAME);
    clog_debug(malzmq_logger, "malzmq_ctx: send the SUB_NAME \"%s\", rc = %d\n", SUB_NAME, rc);
    rc = zframe_send(&frame, socket, 0);
    clog_debug(malzmq_logger, "malzmq_ctx: zframe_send the message,  rc = %d\n", rc);
    assert(rc == 0);
  }

  clog_debug(malzmq_logger, "malzmq_ctx: message sent.\n");

  return rc;
}

int malzmq_ctx_recv_message(void *self, mal_endpoint_t *mal_endpoint, mal_message_t **message) {
  malzmq_ctx_t *malzmq_ctx = (malzmq_ctx_t *) self;
  malzmq_endpoint_data_t *endpoint_data = (malzmq_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  int rc = 0;

  clog_debug(malzmq_logger, "malzmq_ctx_recv_message()\n");

  zmsg_t *zmsg = zmsg_recv(endpoint_data->socket);
  if (zmsg) {
    size_t frames_count = zmsg_size(zmsg);

    clog_debug(malzmq_logger, "malzmq_ctx_recv_message: received zmsg (%d frames)\n", frames_count);

    // The MAL message is in the first frame.
    // Now the frame is owned by us.
    zframe_t *frame = zmsg_pop(zmsg);

    clog_debug(malzmq_logger, "malzmq_ctx_recv_message: frame size = %d\n", zframe_size(frame));

    size_t mal_msg_bytes_length = zframe_size(frame);
    clog_debug(malzmq_logger, "malzmq_ctx_recv_message: mal_msg_bytes_length=%d\n", mal_msg_bytes_length);

    // Does not copy the frame bytes in another array.
    byte *mal_msg_bytes = zframe_data(frame);

    *message = mal_message_new_void();

    // MALZMQ always uses the 'malbinary' encoding format for the messages encoding (another format
    // may be used at the application layer for the message body).

    // Note: We could use virtual allocation and initialization functions from encoder
    // rather than malbinary interface.
    malbinary_cursor_t cursor;
	  malbinary_cursor_init(&cursor, (char *) mal_msg_bytes, mal_msg_bytes_length, 0);

    // 'malzmq' encoding format of the MAL header
    if (malzmq_decode_message(malzmq_ctx->malzmq_header, *message, malzmq_ctx->decoder, &cursor) != 0) {
      clog_error(malzmq_logger, "malzmq_ctx_recv_message, cannot decode message\n");
      return -1;
    }

    // TODO (AF) : Normally the frame should be kept to avoid copying the body of the message.
    // currently the body is always copied in a newly allocated memory.
    // Destroy must free the zmq frame
//    mal_message_set_body_owner(*message, frame);

    clog_debug(malzmq_logger, "malzmq_ctx_recv_message: ");
    if (clog_is_loggable(malzmq_logger, CLOG_DEBUG_LEVEL))
      mal_message_print(*message);
    clog_debug(malzmq_logger, "\n");

    // Verify that the message is for the current endpoint
    mal_uri_t *uri_to = mal_message_get_uri_to(*message);
    clog_debug(malzmq_logger, "malzmq_ctx_recv_message: uri_to=%s\n", uri_to);

    // Verify if the message could be delivered and destroy it otherwise.
    if (endpoint_data->mal_endpoint) {
      bool message_delivered = false;
      mal_uri_t *endpoint_uri = mal_endpoint_get_uri(endpoint_data->mal_endpoint);
      if (strcmp(malzmq_get_service_from_uri(endpoint_uri), malzmq_get_service_from_uri(uri_to)) == 0)
        message_delivered = true;

      clog_debug(malzmq_logger, "malzmq_ctx_recv_message: message_delivered=%d\n", message_delivered);

      if (!message_delivered) {
        clog_debug(malzmq_logger, "malzmq_ctx_recv_message: destroy MAL message\n", uri_to);

        mal_message_destroy(message, malzmq_ctx->mal_ctx);
      }
    }

    // TODO (AF) : Normally the frame should be kept to avoid copying the body of the message.
    // currently the body is always copied in a newly allocated memory.
    zframe_destroy(&frame);
  } else {
    clog_debug(malzmq_logger, "malzmq_ctx_recv_message(): NULL\n");
  }

  return rc;
}

// NOTE: Currently catch the PUBLISH_(DE)REGISTER message in order to automatically send
// the corresponding ack. This code corresponds to the current ZMQ implementation of the
// Pub/Sub interaction.
int trap_publish_register(mal_endpoint_t *mal_endpoint, mal_message_t *init_message, mal_uoctet_t stage) {
  mal_message_t *result_message = mal_message_new(
      mal_message_get_authentication_id(init_message),
      mal_message_get_qoslevel(init_message),
      mal_message_get_priority(init_message),
      mal_message_get_domain(init_message),
      mal_message_get_network_zone(init_message),
      mal_message_get_session(init_message),
      mal_message_get_session_name(init_message),
      0);
  mal_message_set_body(result_message, NULL);
  mal_message_set_body_length(result_message, 0);
  mal_message_init(result_message,
      mal_message_get_service_area(init_message), mal_message_get_area_version(init_message),
      mal_message_get_service(init_message), mal_message_get_operation(init_message),
      MAL_INTERACTIONTYPE_PUBSUB, stage);

  mal_message_set_uri_to(result_message,
      mal_message_get_uri_from(init_message));
  mal_message_set_free_uri_to(result_message, false);
  mal_message_set_uri_from(result_message, mal_endpoint_get_uri(mal_endpoint));
  mal_message_set_free_uri_from(result_message, false);
  mal_message_set_transaction_id(result_message,
      mal_message_get_transaction_id(init_message));
  mal_message_set_is_error_message(result_message, false);

  // The current implementation of the publish/subscribe sends automatically the
  // acknowledge messages for PUBLISH_[DE]REGISTER.

  return mal_ctx_send_message(mal_endpoint_get_mal_ctx(mal_endpoint), mal_endpoint, result_message);
}

// Must be compliant with MAL virtual function.
int malzmq_ctx_destroy_message(void *self, mal_message_t *mal_message) {
  zframe_t *frame = (zframe_t *) mal_message_get_body_owner(mal_message);
  if (frame != NULL) {
    zframe_destroy(&frame);
  }
  return 0;
}

// Must be compliant with MAL virtual function: void *self
mal_uri_t *malzmq_ctx_create_uri(void *self, char *id) {
  malzmq_ctx_t *malzmq_ctx = (malzmq_ctx_t *) self;

  clog_debug(malzmq_logger, "malzmq_ctx_create_uri()\n");

  size_t uri_length = strlen(MALZMTP_URI);
  if (malzmq_ctx->hostname) {
    uri_length += strlen(malzmq_ctx->hostname);
  }
  if (malzmq_ctx->port) {
    uri_length += strlen(malzmq_ctx->port) + 1;
  }
  if (id) {
    uri_length += strlen(id) + 1;
  }

  clog_debug(malzmq_logger, "malzmq_ctx: uri_length=%d\n", uri_length);

  char *uri = (char *) malloc(uri_length + 1);
  // Need to set the final '\0' before using strcat
  uri[0] = '\0';
  if (uri) {
    strcat(uri, MALZMTP_URI);
    if (malzmq_ctx->hostname) {
      strcat(uri, malzmq_ctx->hostname);
    }
    if (malzmq_ctx->port) {
      strcat(uri, ":");
      strcat(uri, malzmq_ctx->port);
    }
    if (id) {
      strcat(uri, "/");
      strcat(uri, id);
    }
  }

  clog_debug(malzmq_logger, "malzmq_ctx: created URI: %s\n", uri);

  return uri;
}

void *malzmq_ctx_create_endpoint(void *malzmq_ctx, mal_endpoint_t *mal_endpoint) {
  malzmq_ctx_t *self = (malzmq_ctx_t *) malzmq_ctx;
  malzmq_endpoint_data_t *endpoint_data = NULL;

  clog_debug(malzmq_logger, "malzmq_ctx_create_endpoint()\n");

  if (mal_endpoint) {
    endpoint_data = (malzmq_endpoint_data_t *) zmalloc(sizeof(malzmq_endpoint_data_t));
    assert(endpoint_data);

    //  Initialize the endpoint ZMQ specific state
    endpoint_data->malzmq_ctx = self;
    endpoint_data->mal_endpoint = mal_endpoint;
    endpoint_data->remote_socket_table = zhash_new();

    mal_endpoint_set_endpoint_data(mal_endpoint, endpoint_data);

    clog_debug(malzmq_logger, "malzmq_ctx_create_endpoint: initialize endpoint\n");

    // Initialize the endpoint
    mal_uri_t *handler_uri = malzmq_get_service_from_uri(mal_endpoint_get_uri(endpoint_data->mal_endpoint));

    clog_debug(malzmq_logger, "malzmq_ctx_create_endpoint: initialize endpoint -> %s\n", handler_uri);

    // Create a socket connected to the zloop to receive
    // MAL messages to be handled by this actor
    void *zloop_socket = zsocket_new(self->zmq_ctx, ZMQ_DEALER);

    // Keep the socket
    endpoint_data->socket = zloop_socket;

    // The identity of the handler is its URI
    zmq_setsockopt(zloop_socket, ZMQ_IDENTITY, handler_uri, strlen(handler_uri));

    // Connect to the zloop
    clog_debug(malzmq_logger, "malzmq_ctx_create_endpoint: connect to the zloop\n");
    zmq_connect(zloop_socket, ZLOOP_ENDPOINTS_SOCKET_URI);

    clog_debug(malzmq_logger, "malzmq_ctx_create_endpoint: initialized.\n");
  } else {
    clog_error(malzmq_logger, "malzmq_ctx_create_endpoint, cannot create end-point: %s\n", mal_endpoint_get_uri(endpoint_data->mal_endpoint));
  }

  return endpoint_data;
}

void malzmq_ctx_destroy_endpoint(void *self, void **endpoint_p) {
  assert(endpoint_p);
  if (*endpoint_p) {
    malzmq_endpoint_data_t *endpoint = *(malzmq_endpoint_data_t **) endpoint_p;
    *endpoint_p = NULL;

    //  ... destroy your own state here
    if (endpoint->remote_socket_table) {
      void *socket = zhash_first(endpoint->remote_socket_table);
      while (socket) {
        // destroy all registered sockets
        zsocket_destroy(endpoint->malzmq_ctx->zmq_ctx, socket);
        socket = zhash_next(endpoint->remote_socket_table);
      }
      zhash_destroy(&endpoint->remote_socket_table);
    }

    // mal_ctx and mal_endpoint must not be destroyed here
    // but where they have been created.

    free(endpoint);
  }
}

void *malzmq_ctx_create_poller(void *malzmq_ctx, mal_poller_t *mal_poller)  {
  malzmq_ctx_t *self = (malzmq_ctx_t *) malzmq_ctx;
  clog_debug(malzmq_logger, "malzmq_ctx_create_poller()\n");

  malzmq_poller_data_t *poller_data = (malzmq_poller_data_t *) zmalloc(sizeof(malzmq_poller_data_t));
  assert(poller_data);

  //  Initialize the poller ZMQ specific state
  poller_data->malzmq_ctx = self;
  poller_data->mal_poller = mal_poller;

  poller_data->max = MAL_POLLER_LIST_DFLT_SIZE;
  poller_data->idx = 0;
  poller_data->endpoints =  (malzmq_endpoint_data_t **) calloc(MAL_POLLER_LIST_DFLT_SIZE, sizeof(malzmq_endpoint_data_t *));
  if (poller_data->endpoints == NULL) {
    free(self);
    return NULL;
  }

  poller_data->poller = NULL;

  mal_poller_set_poller_data(mal_poller, poller_data);

  return poller_data;
}

void malzmq_ctx_destroy_poller(void *self, void **poller_p) {
  assert(poller_p);

  if (*poller_p) {
    malzmq_poller_data_t *poller = *(malzmq_poller_data_t **) poller_p;
    *poller_p = NULL;
    zpoller_destroy(&poller->poller);

    free(poller->endpoints);

    // mal_ctx and mal_poller must not be destroyed here
    // but where they have been created.

    free(poller);
  }
}

int malzmq_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  malzmq_poller_data_t *poller_data = (malzmq_poller_data_t *) mal_poller_get_poller_data(mal_poller);
  malzmq_endpoint_data_t *endpoint_data = (malzmq_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);
  int rc = 0;

  clog_debug(malzmq_logger, "malzmq_ctx_poller_add_endpoint(): %s\n", mal_endpoint_get_uri(mal_endpoint));

  malzmq_add_endpoint(poller_data, mal_endpoint);
  if (poller_data->poller == NULL)
    poller_data->poller = zpoller_new(endpoint_data->socket, NULL);
  else
    rc = zpoller_add(poller_data->poller, endpoint_data->socket);

  return rc;
}

int malzmq_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  malzmq_poller_data_t *poller_data = (malzmq_poller_data_t *) mal_poller_get_poller_data(mal_poller);
  malzmq_endpoint_data_t *endpoint_data = (malzmq_endpoint_data_t *) mal_endpoint_get_endpoint_data(mal_endpoint);

  int rc = 0;

  clog_debug(malzmq_logger, "malzmq_ctx_poller_del_endpoint(): %s\n", mal_endpoint_get_uri(mal_endpoint));

  if (poller_data->poller == NULL) {
    clog_error(malzmq_logger, "");
    return -1;
  }

  rc = zpoller_remove(poller_data->poller, endpoint_data->socket);
  if (rc != 0) {
    clog_error(malzmq_logger, "malzmq_ctx_poller_del_endpoint(): zpoller null\n");
    return rc;
  }

  rc = malzmq_del_endpoint(poller_data, mal_endpoint);
  clog_debug(malzmq_logger, "malzmq_ctx_poller_del_endpoint: return %d\n",rc);

  return rc;
}

int malzmq_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller, mal_endpoint_t **mal_endpoint, int timeout) {
  malzmq_poller_data_t *poller_data = (malzmq_poller_data_t *) mal_poller_get_poller_data(mal_poller);

  int rc = 0;

  clog_debug(malzmq_logger, "malzmq_ctx_poller_wait()\n");

  zsock_t *which = (zsock_t *) zpoller_wait(poller_data->poller, timeout);
  if (zpoller_terminated(poller_data->poller)) {
    clog_debug(malzmq_logger, "malzmq_ctx_poller_wait: zpoller_terminated.\n");
    return -1;
  }

  if (which) {
    malzmq_endpoint_data_t *endpoint_data = malzmq_get_endpoint(poller_data, which);
    if (endpoint_data != NULL) {
      *mal_endpoint = endpoint_data->mal_endpoint;

      clog_debug(malzmq_logger, "malzmq_ctx_poller_wait: data available for end-point %s\n", mal_endpoint_get_uri(*mal_endpoint));
    } else {
      clog_error(malzmq_logger, "malzmq_ctx_poller_wait: cannot find corresponding end-point\n");
      return -1;
    }
  } else {
    *mal_endpoint = NULL;
  }

  return rc;
}

//  --------------------------------------------------------------------------
//  Selftest

void malzmq_ctx_test(bool verbose) {
  printf(" * malzmq ctx: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

