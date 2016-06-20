#ifndef __PUBSUB_APP_MYSUBSCRIBER_H_INCLUDED__
#define __PUBSUB_APP_MYSUBSCRIBER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

pubsub_app_mysubscriber_t *pubsub_app_mysubscriber_new(mal_uri_t *broker_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain, mal_identifier_t *network_zone,
    mal_sessiontype_t session, mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int pubsub_app_mysubscriber_initialize(void *self, mal_actor_t *mal_actor);

int pubsub_app_mysubscriber_finalize(void *self, mal_actor_t *mal_actor);

int pubsub_app_mysubscriber_testregister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_mysubscriber_testderegister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_mysubscriber_testnotify(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *pubsub_app_mysubscriber_get_broker_uri(pubsub_app_mysubscriber_t *self);

mal_identifier_list_t *pubsub_app_mysubscriber_get_domain(pubsub_app_mysubscriber_t *self);

mal_blob_t *pubsub_app_mysubscriber_get_authentication_id(
    pubsub_app_mysubscriber_t *self);

void pubsub_app_mysubscriber_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
