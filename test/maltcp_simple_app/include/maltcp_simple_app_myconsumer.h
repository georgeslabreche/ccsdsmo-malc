#ifndef __MALTCP_SIMPLE_APP_MYCONSUMER_H_INCLUDED__
#define __MALTCP_SIMPLE_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

maltcp_simple_app_myconsumer_t *maltcp_simple_app_myconsumer_new(
    mal_endpoint_t *endpoint,
    mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder);

void maltcp_simple_app_myconsumer_run(zsock_t *pipe, void *args);

int maltcp_simple_app_myconsumer_send(maltcp_simple_app_myconsumer_t *self);

mal_uri_t *maltcp_simple_app_myconsumer_get_provider_uri(maltcp_simple_app_myconsumer_t *self);

int maltcp_simple_app_myconsumer_get_encoding_format_code(
    maltcp_simple_app_myconsumer_t *self);

mal_identifier_list_t *maltcp_simple_app_myconsumer_get_domain(
    maltcp_simple_app_myconsumer_t *self);

void *maltcp_simple_app_myconsumer_get_encoder(maltcp_simple_app_myconsumer_t *self);

void *maltcp_simple_app_myconsumer_get_decoder(maltcp_simple_app_myconsumer_t *self);

mal_blob_t *maltcp_simple_app_myconsumer_get_authentication_id(
    maltcp_simple_app_myconsumer_t *self);

void maltcp_simple_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
