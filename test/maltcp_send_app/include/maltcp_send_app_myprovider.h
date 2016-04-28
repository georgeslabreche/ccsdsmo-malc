/*
 */

#ifndef __MALTCP_SEND_APP_MYPROVIDER_H_INCLUDED__
#define __MALTCP_SEND_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

maltcp_send_app_myprovider_t *maltcp_send_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder);

void maltcp_send_app_myprovider_set_decoder(maltcp_send_app_myprovider_t *self,
    void *decoder);

int maltcp_send_app_myprovider_get_encoding_format_code(
    maltcp_send_app_myprovider_t *self);

int maltcp_send_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int maltcp_send_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int maltcp_send_app_myprovider_testarea_testservice_testsend(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void maltcp_send_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
