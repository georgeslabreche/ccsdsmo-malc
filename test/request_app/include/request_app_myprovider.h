/*
 */

#ifndef __REQUEST_APP_MYPROVIDER_H_INCLUDED__
#define __REQUEST_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

request_app_myprovider_t *request_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder);

void request_app_myprovider_set_decoder(request_app_myprovider_t *self,
    void *decoder);

int request_app_myprovider_get_encoding_format_code(
    request_app_myprovider_t *self);

int request_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int request_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int request_app_myprovider_testarea_testservice_testrequest(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void request_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
