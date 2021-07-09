/*  =========================================================================
    demo_app_consumer - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef DEMO_APP_CONSUMER_H_INCLUDED
#define DEMO_APP_CONSUMER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new demo_app_consumer
DEMO_EXPORT demo_app_consumer_t *
    demo_app_consumer_new (mal_uri_t *provider_uri,
        mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
        mal_uinteger_t priority, mal_identifier_list_t *domain,
        mal_identifier_t *network_zone, mal_sessiontype_t session,
        mal_identifier_t *session_name,
        mal_encoder_t *encoder, mal_decoder_t *decoder);


DEMO_EXPORT int
    demo_app_consumer_actor_create(
        bool verbose,
        mal_ctx_t *mal_ctx,
        mal_uri_t *provider_uri,
        mal_encoder_t *encoder,
        mal_decoder_t *decoder);

DEMO_EXPORT int
    demo_app_consumer_initialize(void *self, mal_actor_t *mal_actor);

DEMO_EXPORT int
    demo_app_consumer_finalize(void *self, mal_actor_t *mal_actor);

DEMO_EXPORT int
    demo_app_consumer_request_response(
        void *self, mal_ctx_t *mal_ctx,
        mal_endpoint_t *mal_endpoint, mal_message_t *message);

//  Destroy the demo_app_consumer
DEMO_EXPORT void
    demo_app_consumer_destroy (demo_app_consumer_t **self_p, mal_ctx_t *mal_ctx);

//  @end

#ifdef __cplusplus
}
#endif

#endif
