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

int mal_actor_active_count();

mal_actor_t *mal_actor_new(
    mal_ctx_t *mal_ctx,
    mal_uri_t *uri,
    void *state,
    mal_actor_initialize_fn *initialize,
    mal_actor_finalize_fn *finalize);

void mal_actor_term(mal_actor_t *actor);
void mal_actor_destroy(mal_ctx_t *mal_ctx, mal_actor_t **self_p);

mal_uri_t *mal_actor_get_uri(mal_actor_t *self);
mal_ctx_t *mal_actor_get_mal_ctx(mal_actor_t *self);
mal_endpoint_t *mal_actor_get_mal_endpoint(mal_actor_t *self);
mal_routing_t *mal_actor_get_router(mal_actor_t *self);
void *mal_actor_get_state(mal_actor_t *self);
bool mal_actor_alive(mal_actor_t *self);
void mal_actor_join(mal_actor_t *self);

int mal_actor_send_command(mal_actor_t *to, char *cmd);

//  Self test of this class
void mal_actor_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif

