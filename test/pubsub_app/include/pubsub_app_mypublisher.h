#ifndef __PUBSUB_APP_MYPUBLISHER_H_INCLUDED__
#define __PUBSUB_APP_MYPUBLISHER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

pubsub_app_mypublisher_t *pubsub_app_mypublisher_new(mal_uri_t *broker_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain, mal_identifier_t *network_zone,
    mal_sessiontype_t session, mal_identifier_t *session_name,
    int encoding_format_code, void *encoder, void *decoder);

int pubsub_app_mypublisher_initialize(void *self, mal_actor_t *mal_actor);

int pubsub_app_mypublisher_finalize(void *self, mal_actor_t *mal_actor);

int pubsub_app_mypublisher_on_publish_error(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_mypublisher_on_publish_register_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_mypublisher_on_publish_deregister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_mypublisher_testarea_testservice_testpubsub(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *pubsub_app_mypublisher_get_broker_uri(pubsub_app_mypublisher_t *self);

int pubsub_app_mypublisher_get_encoding_format_code(
    pubsub_app_mypublisher_t *self);

mal_identifier_list_t *pubsub_app_mypublisher_get_domain(pubsub_app_mypublisher_t *self);

void *pubsub_app_mypublisher_get_encoder(pubsub_app_mypublisher_t *self);

void *pubsub_app_mypublisher_get_decoder(pubsub_app_mypublisher_t *self);

mal_blob_t *pubsub_app_mypublisher_get_authentication_id(
    pubsub_app_mypublisher_t *self);

void pubsub_app_mypublisher_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
