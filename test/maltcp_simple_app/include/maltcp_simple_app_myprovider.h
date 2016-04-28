/*
 */

#ifndef __MALTCP_SIMPLE_APP_MYPROVIDER_H_INCLUDED__
#define __MALTCP_SIMPLE_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

maltcp_simple_app_myprovider_t *maltcp_simple_app_myprovider_new(
    mal_poller_t *poller,
    mal_endpoint_t *endpoint,
    int encoding_format_code,
    void *encoder, void *decoder);

void maltcp_simple_app_myprovider_set_decoder(maltcp_simple_app_myprovider_t *self, void *decoder);

int maltcp_simple_app_myprovider_get_encoding_format_code(maltcp_simple_app_myprovider_t *self);

void maltcp_simple_app_myprovider_run(zsock_t *pipe, void *args);

int maltcp_simple_app_myprovider_recv(maltcp_simple_app_myprovider_t *self);

int maltcp_simple_app_myprovider_testarea_testservice_testsend(
    void *self,
    mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

void maltcp_simple_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
