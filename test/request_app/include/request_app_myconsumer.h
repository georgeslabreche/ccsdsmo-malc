#ifndef __REQUEST_APP_MYCONSUMER_H_INCLUDED__
#define __REQUEST_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

request_app_myconsumer_t *request_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int request_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor);

int request_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor);

int request_app_myconsumer_testarea_testservice_testrequest_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *request_app_myconsumer_get_provider_uri(request_app_myconsumer_t *self);

mal_identifier_list_t *request_app_myconsumer_get_domain(
		request_app_myconsumer_t *self);

mal_blob_t *request_app_myconsumer_get_authentication_id(
		request_app_myconsumer_t *self);

void request_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
