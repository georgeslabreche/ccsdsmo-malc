#ifndef __MALTCP_REQUEST_APP_MYCONSUMER_H_INCLUDED__
#define __MALTCP_REQUEST_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

maltcp_request_app_myconsumer_t *maltcp_request_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder);

int maltcp_request_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor);

int maltcp_request_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor);

int maltcp_request_app_myconsumer_testarea_testservice_testrequest_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *maltcp_request_app_myconsumer_get_provider_uri(maltcp_request_app_myconsumer_t *self);

int maltcp_request_app_myconsumer_get_encoding_format_code(
		maltcp_request_app_myconsumer_t *self);

mal_identifier_list_t *maltcp_request_app_myconsumer_get_domain(
		maltcp_request_app_myconsumer_t *self);

void *maltcp_request_app_myconsumer_get_encoder(maltcp_request_app_myconsumer_t *self);

void *maltcp_request_app_myconsumer_get_decoder(maltcp_request_app_myconsumer_t *self);

mal_blob_t *maltcp_request_app_myconsumer_get_authentication_id(
		maltcp_request_app_myconsumer_t *self);

void maltcp_request_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
