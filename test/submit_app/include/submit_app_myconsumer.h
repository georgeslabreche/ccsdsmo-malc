#ifndef __SUBMIT_APP_MYCONSUMER_H_INCLUDED__
#define __SUBMIT_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

submit_app_myconsumer_t *submit_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int submit_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor);

int submit_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor);

int submit_app_myconsumer_testarea_testservice_testsubmitack(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *submit_app_myconsumer_get_provider_uri(submit_app_myconsumer_t *self);

mal_identifier_list_t *submit_app_myconsumer_get_domain(
    submit_app_myconsumer_t *self);

mal_blob_t *submit_app_myconsumer_get_authentication_id(
    submit_app_myconsumer_t *self);

void submit_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
