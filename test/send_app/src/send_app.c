/* */
#include "send_app.h"

mal_actor_t *consumer_actor = NULL;
mal_actor_t *provider_actor = NULL;

bool split = false;
bool tcp = true;

//  --------------------------------------------------------------------------
//  Selftest
int send_app_create_provider(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * send_app_create_provider: \n");

  send_app_myprovider_t *provider = send_app_myprovider_new(encoder, decoder);

//  mal_actor_t *provider_actor =
  provider_actor = mal_actor_new(
      mal_ctx,
      provider_uri, provider,
      send_app_myprovider_initialize, send_app_myprovider_finalize);

  return rc;
}

int send_app_create_consumer(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * send_app_create_consumer: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  send_app_myconsumer_t *consumer = send_app_myconsumer_new(provider_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "send_app/myconsumer");
  printf("send_app: consumer URI: %s\n", consumer_uri);

//  mal_actor_t *consumer_actor =
  consumer_actor = mal_actor_new(
      mal_ctx,
      consumer_uri, consumer,
      send_app_myconsumer_initialize, send_app_myconsumer_finalize);

  return rc;
}

void send_app_test(bool verbose) {
  printf(" * send_app: \n");

  // @selftest
  mal_ctx_t *mal_ctx = mal_ctx_new();
  void *ctx;

  if (tcp) {
    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // This test uses the same encoding configuration at the MAL/ZMQ transport
    // level (MAL header encoding) and at the application
    // level (MAL message body encoding)
    ctx = maltcp_ctx_new(
        mal_ctx,
        NULL,                 // Use default transformation of MAL URI to ZMQ URI
        "localhost", "6666",
        maltcp_header,
        true);
    // Change the logging level of maltcp encoding
    mal_encoder_set_log_level(maltcp_get_encoder((maltcp_ctx_t *) ctx), CLOG_WARN_LEVEL);
    mal_decoder_set_log_level(maltcp_get_decoder((maltcp_ctx_t *) ctx), CLOG_WARN_LEVEL);
  } else {
    // All the MAL header fields are passed
    malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL, NULL, NULL, NULL);

    // This test uses the same encoding configuration at the MAL/ZMQ transport
    // level (MAL header encoding) and at the application
    // level (MAL message body encoding)
    ctx = malzmq_ctx_new(
        mal_ctx,
        NULL,                 // Use default transformation of MAL URI to ZMQ URI
        "localhost", "6666",
        malzmq_header,
        true);
    // Change the logging level of malzmq encoding
    mal_encoder_set_log_level(malzmq_get_encoder((malzmq_ctx_t *) ctx), CLOG_WARN_LEVEL);
    mal_decoder_set_log_level(malzmq_get_decoder((malzmq_ctx_t *) ctx), CLOG_WARN_LEVEL);
  }

  mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "send_app/myprovider");
  printf("send_app: provider URI: %s\n", provider_uri);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  send_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
  send_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);

  //  @end
  printf("OK\n");

  mal_binding_ctx_start(mal_ctx);
  printf("Stopped.\n");
  mal_binding_ctx_destroy(mal_ctx);
  mal_ctx_destroy(&mal_ctx);
  printf("destroyed.\n");
}
