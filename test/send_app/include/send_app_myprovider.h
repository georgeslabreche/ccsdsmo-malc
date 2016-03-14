/*
 */

#ifndef __SEND_APP_MYPROVIDER_H_INCLUDED__
#define __SEND_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

send_app_myprovider_t *send_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder);

void send_app_myprovider_set_decoder(send_app_myprovider_t *self,
    void *decoder);

int send_app_myprovider_get_encoding_format_code(
    send_app_myprovider_t *self);

int send_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int send_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int send_app_myprovider_testarea_testservice_testsend(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void send_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
