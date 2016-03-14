/*
 */
#include "mal.h"

struct _mal_endpoint_t {
  mal_ctx_t *mal_ctx;
  mal_uri_t *uri;
  long transaction_id_counter;

  void *endpoint_data;
};

mal_endpoint_t *mal_endpoint_new(
    mal_ctx_t *mal_ctx,
    mal_uri_t *uri) {
  mal_endpoint_t *self = (mal_endpoint_t *) malloc(sizeof(mal_endpoint_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->uri = strdup(uri);
  self->transaction_id_counter = 0L;

  mal_ctx_create_endpoint(mal_ctx, self);

  return self;
}

mal_endpoint_t *mal_endpoint_actor(
    mal_ctx_t *mal_ctx,
    void *endpoint_data) {
  mal_endpoint_t *self = (mal_endpoint_t *) malloc(sizeof(mal_endpoint_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  self->uri = strdup("actor");
  self->transaction_id_counter = 0L;

  self->endpoint_data = endpoint_data;

  return self;
}

void mal_endpoint_destroy(mal_endpoint_t **self_p) {
  if (*self_p) {
    mal_endpoint_t *self = *self_p;
    free(self->uri);

    mal_ctx_destroy_endpoint(self->mal_ctx, &self->endpoint_data);

    free(self);
    *self_p = NULL;
  }
}

/**
 * Get the reference to the MAL context of the end-point.
 */
mal_ctx_t *mal_endpoint_get_mal_ctx(mal_endpoint_t *self) {
  return self->mal_ctx;
}

/**
 * Get the EndPoint URI.
 */
mal_uri_t *mal_endpoint_get_uri(mal_endpoint_t *self) {
  return self->uri;
}

// Used by the transport implementation to retrieve specific datas associated to the EndPoint.
void *mal_endpoint_get_endpoint_data(mal_endpoint_t *self) {
  return self->endpoint_data;
}

//  Used by the transport implementation to set specific datas associated to the EndPoint.
void mal_endpoint_set_endpoint_data(mal_endpoint_t *self, void *endpoint_data) {
  self->endpoint_data = endpoint_data;
}

// TODO: Currently catch the PUBLISH_(DE)REGISTER message in order to automatically send the
// corresponding ack. This code corresponds to the ZMQ implementation of the Pub/Sub interaction,
// it should be in the ZMQ transport package.
int trap_publish_register(mal_endpoint_t *self, mal_message_t *init_message, mal_uoctet_t stage) {
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
  mal_message_set_uri_from(result_message, self->uri);
  mal_message_set_free_uri_from(result_message, false);
  mal_message_set_transaction_id(result_message,
      mal_message_get_transaction_id(init_message));
  mal_message_set_is_error_message(result_message, false);

  // The current implementation of the publish/subscribe sends automatically the
  // acknowledge messages for PUBLISH_[DE]REGISTER.

  return mal_ctx_send_message(self->mal_ctx, self, result_message);
}

int mal_endpoint_init_operation(mal_endpoint_t *self,
    mal_message_t *message, mal_uri_t *uri_to, bool set_tid) {
  mal_message_set_uri_to(message, uri_to);
  mal_message_set_uri_from(message, self->uri);
  mal_message_set_free_uri_from(message, false);
  if (set_tid) {
    mal_message_set_transaction_id(message, self->transaction_id_counter++);
  }

  // TODO: Currently catch the PUBLISH_(DE)REGISTER message in order to automatically send the
  // corresponding ack. This code corresponds to the ZMQ implementation of the Pub/Sub interaction,
  // it should be in the ZMQ transport package.
  mal_uoctet_t stage = mal_message_get_interaction_stage(message);
  if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER) {
    return trap_publish_register((mal_endpoint_t *)self, message, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK);
  } else if(stage == MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER) {
    return trap_publish_register((mal_endpoint_t *)self, message, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK);
  }

  return mal_ctx_send_message(self->mal_ctx, self, message);
}

int mal_endpoint_return_operation(mal_endpoint_t *self,
    mal_message_t *init_message, mal_message_t *result_message,
    bool is_error_message) {
  mal_message_set_uri_to(result_message,
      mal_message_get_uri_from(init_message));
  mal_message_set_free_uri_to(result_message, false);
  mal_message_set_uri_from(result_message, self->uri);
  mal_message_set_free_uri_from(result_message, false);
  mal_message_set_transaction_id(result_message,
      mal_message_get_transaction_id(init_message));
  mal_message_set_is_error_message(result_message, is_error_message);

  return mal_ctx_send_message(self->mal_ctx, self, result_message);
}

int mal_endpoint_recv_message(
    mal_endpoint_t *self,
    mal_message_t **message) {
  return mal_ctx_recv_message(self->mal_ctx, self, message);
}

void mal_endpoint_test(bool verbose) {
  printf(" * mal_endpoint: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
