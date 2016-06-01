/*
 */

#ifndef __SIMPLE_APP_MYPROVIDER_H_INCLUDED__
#define __SIMPLE_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

simple_app_myprovider_t *simple_app_myprovider_new(
    mal_poller_t *poller,
    mal_endpoint_t *endpoint,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder);

void simple_app_myprovider_run(zsock_t *pipe, void *args);

int simple_app_myprovider_recv(simple_app_myprovider_t *self);

int simple_app_myprovider_testarea_testservice_testsend(
    void *self,
    mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

void simple_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
