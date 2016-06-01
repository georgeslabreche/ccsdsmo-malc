/*
 */

#ifndef __PROGRESS_APP_MYPROVIDER_H_INCLUDED__
#define __PROGRESS_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

progress_app_myprovider_t *progress_app_myprovider_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int progress_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int progress_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int progress_app_myprovider_testarea_testservice_testprogress(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void progress_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
