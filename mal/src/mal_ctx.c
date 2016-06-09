/*
 */

#include "mal.h"

struct _mal_ctx_t {
  void *mal_binding_ctx;
  mal_binding_ctx_create_uri_fn *create_uri;
  mal_binding_ctx_create_endpoint_fn *create_endpoint;
  mal_binding_ctx_destroy_endpoint_fn *destroy_endpoint;
  mal_binding_ctx_create_poller_fn *create_poller;
  mal_binding_ctx_destroy_poller_fn *destroy_poller;
  mal_binding_ctx_poller_add_endpoint_fn *poller_add_endpoint;
  mal_binding_ctx_poller_del_endpoint_fn *poller_del_endpoint;
  mal_binding_ctx_send_message_fn *send_message;
  mal_binding_ctx_recv_message_fn *recv_message;
  mal_binding_ctx_poller_wait_fn *poller_wait;
  mal_binding_ctx_destroy_message_fn *destroy_message;
  mal_binding_ctx_start_fn *mal_binding_ctx_start;
  mal_binding_ctx_stop_fn *mal_binding_ctx_stop;
  mal_binding_ctx_destroy_fn *mal_binding_ctx_destroy;
};

mal_ctx_t *mal_ctx_new() {
  mal_ctx_t *self = (mal_ctx_t *) malloc(sizeof(mal_ctx_t));
  if (!self)
    return NULL;

  self->mal_binding_ctx = NULL;
  self->create_uri = NULL;
  self->create_endpoint = NULL;
  self->destroy_endpoint = NULL;
  self->create_poller = NULL;
  self->destroy_poller = NULL;
  self->poller_add_endpoint = NULL;
  self->poller_del_endpoint = NULL;
  self->send_message = NULL;
  self->recv_message = NULL;
  self->poller_wait = NULL;
  self->destroy_message = NULL;
  self->mal_binding_ctx_start = NULL;
  self->mal_binding_ctx_stop = NULL;
  self->mal_binding_ctx_destroy = NULL;

  return self;
}


void mal_ctx_destroy(mal_ctx_t **self_p) {
  if (*self_p) {
    mal_ctx_t *self = *self_p;
    free(self);
    *self_p = NULL;
  }
}

void mal_ctx_set_binding(
    mal_ctx_t *self, void *mal_binding_ctx,
    mal_binding_ctx_create_uri_fn *create_uri,
    mal_binding_ctx_create_endpoint_fn *create_endpoint,
    mal_binding_ctx_destroy_endpoint_fn *destroy_endpoint,
    mal_binding_ctx_create_poller_fn *create_poller,
    mal_binding_ctx_destroy_poller_fn *destroy_poller,
    mal_binding_ctx_poller_add_endpoint_fn *poller_add_endpoint,
    mal_binding_ctx_poller_del_endpoint_fn *poller_del_endpoint,
    mal_binding_ctx_send_message_fn *send_message,
    mal_binding_ctx_recv_message_fn *recv_message,
    mal_binding_ctx_poller_wait_fn *poller_wait,
    mal_binding_ctx_destroy_message_fn *destroy_message,
    mal_binding_ctx_start_fn *mal_binding_ctx_start,
    mal_binding_ctx_stop_fn *mal_binding_ctx_stop,
    mal_binding_ctx_destroy_fn *mal_binding_ctx_destroy) {
  self->mal_binding_ctx = mal_binding_ctx;
  self->create_uri = create_uri;
  self->create_endpoint = create_endpoint;
  self->destroy_endpoint = destroy_endpoint;
  self->create_poller = create_poller;
  self->destroy_poller = destroy_poller;
  self->poller_add_endpoint = poller_add_endpoint;
  self->poller_del_endpoint = poller_del_endpoint;
  self->send_message = send_message;
  self->recv_message = recv_message;
  self->poller_wait = poller_wait;
  self->destroy_message = destroy_message;
  self->mal_binding_ctx_start = mal_binding_ctx_start;
  self->mal_binding_ctx_stop = mal_binding_ctx_stop;
  self->mal_binding_ctx_destroy = mal_binding_ctx_destroy;
}

void *mal_ctx_get_binding(mal_ctx_t *self) {
  return self->mal_binding_ctx;
}

mal_uri_t *mal_ctx_create_uri(mal_ctx_t *self, char *id) {
  return self->create_uri(self->mal_binding_ctx, id);
}

void *mal_ctx_create_endpoint(mal_ctx_t *self, mal_endpoint_t *mal_endpoint) {
  return self->create_endpoint(self->mal_binding_ctx, mal_endpoint);
}

void mal_ctx_destroy_endpoint(mal_ctx_t *self, void **endpoint_p) {
  self->destroy_endpoint(self->mal_binding_ctx, endpoint_p);
}

void *mal_ctx_create_poller(mal_ctx_t *self, mal_poller_t *mal_poller) {
  return self->create_poller(self->mal_binding_ctx, mal_poller);
}

void mal_ctx_destroy_poller(mal_ctx_t *self, void **poller_p) {
  self->destroy_poller(self->mal_binding_ctx, poller_p);
}

int mal_ctx_poller_add_endpoint(
    mal_ctx_t *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  return self->poller_add_endpoint(self->mal_binding_ctx, mal_poller, mal_endpoint);
}

int mal_ctx_poller_del_endpoint(
    mal_ctx_t *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint) {
  return self->poller_del_endpoint(self->mal_binding_ctx, mal_poller, mal_endpoint);
}

int mal_ctx_send_message(mal_ctx_t *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *message) {
  return self->send_message(self->mal_binding_ctx, mal_endpoint, message);
}

int mal_ctx_recv_message(
    mal_ctx_t *self, mal_endpoint_t *mal_endpoint,
    mal_message_t **message) {
  return self->recv_message(self->mal_binding_ctx, mal_endpoint, message);
}

int mal_ctx_poller_wait(
    mal_ctx_t *self, mal_poller_t *mal_poller,
    mal_endpoint_t **endpoint,
    int timeout) {
  return self->poller_wait(self->mal_binding_ctx, mal_poller, endpoint, timeout);
}

int mal_ctx_destroy_message(mal_ctx_t *self, mal_message_t *message) {
  return self->destroy_message(self->mal_binding_ctx, message);
}

int mal_binding_ctx_start(mal_ctx_t *self) {
  return self->mal_binding_ctx_start(self->mal_binding_ctx);
}
int mal_binding_ctx_stop(mal_ctx_t *self) {
  return self->mal_binding_ctx_stop(self->mal_binding_ctx);
}
int mal_binding_ctx_destroy(mal_ctx_t *self) {
  return self->mal_binding_ctx_destroy(&self->mal_binding_ctx);
}

void mal_ctx_test(bool verbose) {
  printf(" * mal_ctx: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

