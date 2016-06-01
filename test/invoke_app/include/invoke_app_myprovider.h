/*
 */

#ifndef __INVOKE_APP_MYPROVIDER_H_INCLUDED__
#define __INVOKE_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

invoke_app_myprovider_t *invoke_app_myprovider_new(
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int invoke_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int invoke_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int invoke_app_myprovider_testarea_testservice_testinvoke(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void invoke_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
