/*
 */
#include "mal.h"

struct _mal_poller_t {
  mal_ctx_t *mal_ctx;

  void *poller_data;
};

mal_poller_t *mal_poller_new(mal_ctx_t *mal_ctx) {
  mal_poller_t *self = (mal_poller_t *) malloc(sizeof(mal_poller_t));
  if (!self)
    return NULL;

  self->mal_ctx = mal_ctx;
  mal_ctx_create_poller(mal_ctx, self);

  return self;
}

void mal_poller_destroy(mal_poller_t **self_p) {
  if (*self_p) {
    mal_poller_t *self = *self_p;

    mal_ctx_destroy_poller(self->mal_ctx, &self->poller_data);

    free(self);
    *self_p = NULL;
  }
}

/**
 * Get the reference to the MAL context of this poller.
 */
mal_ctx_t *mal_poller_get_mal_ctx(mal_poller_t *self) {
  return self->mal_ctx;
}

// Used by the transport implementation to retrieve specific datas associated to the poller.
void *mal_poller_get_poller_data(mal_poller_t *self) {
  return self->poller_data;
}

//  Used by the transport implementation to set specific datas associated to the poller.
void mal_poller_set_poller_data(mal_poller_t *self, void *poller_data) {
  self->poller_data = poller_data;
}

int mal_poller_add_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint) {
  return mal_ctx_poller_add_endpoint(self->mal_ctx, self, mal_endpoint);
}

int mal_poller_del_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint) {
  return mal_ctx_poller_del_endpoint(self->mal_ctx, self, mal_endpoint);
}

int mal_poller_wait(
    mal_poller_t *self,
    mal_endpoint_t **endpoint,
    int timeout) {
  return mal_ctx_poller_wait(self->mal_ctx, self, endpoint, timeout);
}

//  Self test of this class
void mal_poller_test(bool verbose) {
  printf(" * mal_poller: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
