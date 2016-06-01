#ifndef __SEND_APP_MYCONSUMER_H_INCLUDED__
#define __SEND_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

send_app_myconsumer_t *send_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder);

int send_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor);

int send_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor);

mal_uri_t *send_app_myconsumer_get_provider_uri(send_app_myconsumer_t *self);
mal_identifier_list_t *send_app_myconsumer_get_domain(
    send_app_myconsumer_t *self);

mal_blob_t *send_app_myconsumer_get_authentication_id(
    send_app_myconsumer_t *self);

void send_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
