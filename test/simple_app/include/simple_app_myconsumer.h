#ifndef __SIMPLE_APP_MYCONSUMER_H_INCLUDED__
#define __SIMPLE_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

simple_app_myconsumer_t *simple_app_myconsumer_new(
    mal_endpoint_t *endpoint,
    mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder);

void simple_app_myconsumer_run(zsock_t *pipe, void *args);

int simple_app_myconsumer_send(simple_app_myconsumer_t *self);

mal_uri_t *simple_app_myconsumer_get_provider_uri(simple_app_myconsumer_t *self);

int simple_app_myconsumer_get_encoding_format_code(
    simple_app_myconsumer_t *self);

mal_identifier_list_t *simple_app_myconsumer_get_domain(
    simple_app_myconsumer_t *self);

void *simple_app_myconsumer_get_encoder(simple_app_myconsumer_t *self);

void *simple_app_myconsumer_get_decoder(simple_app_myconsumer_t *self);

mal_blob_t *simple_app_myconsumer_get_authentication_id(
    simple_app_myconsumer_t *self);

void simple_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
