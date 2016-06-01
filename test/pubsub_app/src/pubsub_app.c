/* */
#include "pubsub_app.h"

#include "malbinary.h"
#include "malzmq.h"

//  --------------------------------------------------------------------------
//  Selftest
int pubsub_app_create_provider(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_uri_t *broker_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * pubsub_app_create_provider: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  pubsub_app_mypublisher_t *provider = pubsub_app_mypublisher_new(broker_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  mal_actor_t *provider_actor = mal_actor_new(
      mal_ctx,
      provider_uri, provider,
      pubsub_app_mypublisher_initialize, pubsub_app_mypublisher_finalize);

  printf(" * pubsub_app create provider actor: %s\n", mal_actor_get_uri(provider_actor));

  return rc;
}

int pubsub_app_create_consumer(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *consumer_uri,
    mal_uri_t *broker_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * pubsub_app_create_consumer: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  pubsub_app_mysubscriber_t *consumer = pubsub_app_mysubscriber_new(broker_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  mal_actor_t *consumer_actor = mal_actor_new(
      mal_ctx,
      consumer_uri, consumer,
      pubsub_app_mysubscriber_initialize, pubsub_app_mysubscriber_finalize);

  printf(" * pubsub_app create consumer actor: %s\n", mal_actor_get_uri(consumer_actor));

  return rc;
}

int pubsub_app_create_broker(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *consumer_uri,
    mal_uri_t *provider_uri,
    mal_uri_t *broker_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * pubsub_app_create_broker: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  pubsub_app_broker_t *broker = pubsub_app_broker_new(provider_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);
  assert(broker);

  mal_actor_t *broker_actor = mal_actor_new(
      mal_ctx,
      broker_uri, broker,
      pubsub_app_broker_initialize, pubsub_app_broker_finalize);

  printf(" * pubsub_app create broker actor: %s\n", mal_actor_get_uri(broker_actor));

  return rc;
}

void pubsub_app_test(bool verbose) {
  printf(" * pubsub_app: \n");

  //  @selftest
  mal_ctx_t *mal_ctx = mal_ctx_new();

  mal_encoder_t *encoder = malbinary_encoder_new(false);
  mal_decoder_t *decoder = malbinary_decoder_new(false);

  // All the MAL header fields are passed
  malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL, NULL,
      NULL, NULL);

  // This test uses the same encoding configuration at the MAL/ZMQ transport
  // level (MAL header encoding) and at the application
  // level (MAL message body encoding)
  malzmq_ctx_t *malzmq_ctx = malzmq_ctx_new(
      mal_ctx,
      NULL,                 // Use default transformation of MAL URI to ZMQ URI
      "localhost", "6666",
      malzmq_header,
      true);

  mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/myprovider");
  printf("pubsub_app: provider URI: %s\n", provider_uri);

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/mysubscriber");
  printf("pubsub_app: mysubscriber URI: %s\n", consumer_uri);

  mal_uri_t *broker_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/broker");
  printf("pubsub_app: broker URI: %s\n", broker_uri);

  pubsub_app_create_broker(verbose, mal_ctx, consumer_uri, provider_uri, broker_uri, encoder, decoder);
  pubsub_app_create_provider(verbose, mal_ctx, provider_uri, broker_uri, encoder, decoder);
  pubsub_app_create_consumer(verbose, mal_ctx, consumer_uri, broker_uri, encoder, decoder);

  //  @end
  printf("OK\n");

  // Start blocks until interrupted (see zloop).
  malzmq_ctx_start(malzmq_ctx);

  mal_ctx_destroy(&mal_ctx);
  malzmq_ctx_destroy(&malzmq_ctx);
}
