#ifndef __PROGRESS_APP_MYCONSUMER_H_INCLUDED__
#define __PROGRESS_APP_MYCONSUMER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

progress_app_myconsumer_t *progress_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder);

int progress_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor);

int progress_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor);

int progress_app_myconsumer_testarea_testservice_testprogress_ack(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int progress_app_myconsumer_testarea_testservice_testprogress_update(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int progress_app_myconsumer_testarea_testservice_testprogress_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *progress_app_myconsumer_get_provider_uri(progress_app_myconsumer_t *self);

int progress_app_myconsumer_get_encoding_format_code(
		progress_app_myconsumer_t *self);

mal_identifier_list_t *progress_app_myconsumer_get_domain(
		progress_app_myconsumer_t *self);

void *progress_app_myconsumer_get_encoder(progress_app_myconsumer_t *self);

void *progress_app_myconsumer_get_decoder(progress_app_myconsumer_t *self);

mal_blob_t *progress_app_myconsumer_get_authentication_id(
		progress_app_myconsumer_t *self);

void progress_app_myconsumer_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
