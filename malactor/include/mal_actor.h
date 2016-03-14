#ifndef __MAL_ACTOR_H_INCLUDED__
#define __MAL_ACTOR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "malactor.h"

// Callback function for initializing an actor
typedef int mal_actor_initialize_fn(void *self, mal_actor_t *mal_actor);

// Callback function for finalizing an actor
typedef int mal_actor_finalize_fn(void *self, mal_actor_t *mal_actor);

mal_actor_t *mal_actor_new(
    mal_ctx_t *mal_ctx,
    mal_uri_t *uri,
    void *state,
    mal_actor_initialize_fn *initialize,
    mal_actor_finalize_fn *finalize);

void mal_actor_destroy(mal_ctx_t *mal_ctx, mal_actor_t **self_p);

mal_uri_t *mal_actor_get_uri(mal_actor_t *self);
mal_ctx_t *mal_actor_get_mal_ctx(mal_actor_t *self);
mal_endpoint_t *mal_actor_get_mal_endpoint(mal_actor_t *self);
mal_routing_t *mal_actor_get_router(mal_actor_t *self);

int mal_actor_send_command(mal_actor_t *to, char *cmd);

//  Self test of this class
void mal_actor_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif

