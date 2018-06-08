/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* */
#include "pubsub_app.h"

bool split = TEST_SPLIT;
bool tcp = TEST_TCP;

mal_actor_t *publisher_actor = NULL;
mal_actor_t *subscriber_actor = NULL;
mal_actor_t *broker_actor = NULL;

//  --------------------------------------------------------------------------
//  Selftest
int pubsub_app_create_publisher(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *publisher_uri,
    mal_uri_t *broker_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * pubsub_app_create_publisher: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  pubsub_app_mypublisher_t *publisher = pubsub_app_mypublisher_new(broker_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  publisher_actor = mal_actor_new(
      mal_ctx,
      publisher_uri, publisher,
      pubsub_app_mypublisher_initialize, pubsub_app_mypublisher_finalize);

  printf(" * pubsub_app create publisher actor: %s\n", mal_actor_get_uri(publisher_actor));

  return rc;
}

int pubsub_app_create_subscriber(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *subscriber_uri,
    mal_uri_t *broker_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * pubsub_app_create_subscriber: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  pubsub_app_mysubscriber_t *subscriber = pubsub_app_mysubscriber_new(broker_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  subscriber_actor = mal_actor_new(
      mal_ctx,
      subscriber_uri, subscriber,
      pubsub_app_mysubscriber_initialize, pubsub_app_mysubscriber_finalize);

  printf(" * pubsub_app create subscriber actor: %s\n", mal_actor_get_uri(subscriber_actor));

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

  broker_actor = mal_actor_new(
      mal_ctx,
      broker_uri, broker,
      pubsub_app_broker_initialize, pubsub_app_broker_finalize);

  printf(" * pubsub_app create broker actor: %s\n", mal_actor_get_uri(broker_actor));

  return rc;
}

mal_uri_t *getNull(mal_uri_t *maluri) {
  return NULL;
}

void pubsub_app_test(bool verbose) {
  printf(" * pubsub_app: \n");

  //  @selftest
  mal_ctx_t *mal_ctx = mal_ctx_new();
  void *ctx;

  if (tcp) {
    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Change the logging level of maltcp transport
    maltcp_set_log_level(CLOG_DEBUG_LEVEL);

    // This test uses the same encoding configuration at the MAL/ZMQ
    // transport level (MAL header encoding) and at the application
    // level (MAL message body encoding)
    ctx = maltcp_ctx_new(
        mal_ctx,
        "127.0.0.1", "6666",
        maltcp_header,
        true);
    // Change the logging level of encoding
    maltcp_ctx_set_encoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
    maltcp_ctx_set_decoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
  } else {
    // All the MAL header fields are passed
    malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL, NULL, NULL, NULL);

    malzmq_mapping_uri_t *mapping_uri = NULL;
    // Uncomment the code below to disable the mcast channel
//    mapping_uri = (malzmq_mapping_uri_t *) malloc(sizeof(malzmq_mapping_uri_t));
//    mapping_uri->get_local_mcast_zmtp_uri = getNull;
//    mapping_uri->get_local_ptp_zmtp_uri = NULL;
//    mapping_uri->get_remote_mcast_zmtp_uri = getNull;
//    mapping_uri->get_remote_ptp_zmtp_uri = NULL;

    // Change the logging level of maltcp transport
    malzmq_set_log_level(CLOG_DEBUG_LEVEL);

    // This test uses the same encoding configuration at the MAL/ZMQ transport
    // level (MAL header encoding) and at the application
    // level (MAL message body encoding)
    ctx = malzmq_ctx_new(
        mal_ctx,
        mapping_uri,                 // Use default transformation of MAL URI to ZMQ URI
        "localhost", "6666",
        malzmq_header,
        true);

    // Change the logging level of encoding
    malzmq_ctx_set_encoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
    malzmq_ctx_set_decoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
  }

  if (!ctx) exit(EXIT_FAILURE);

  mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/myprovider");
  printf("pubsub_app: provider URI: %s\n", provider_uri);

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/mysubscriber");
  printf("pubsub_app: mysubscriber URI: %s\n", consumer_uri);

  mal_uri_t *broker_uri = mal_ctx_create_uri(mal_ctx, "pubsub_app/broker");
  printf("pubsub_app: broker URI: %s\n", broker_uri);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  pubsub_app_create_broker(verbose, mal_ctx, consumer_uri, provider_uri, broker_uri, encoder, decoder);
  pubsub_app_create_publisher(verbose, mal_ctx, provider_uri, broker_uri, encoder, decoder);
  pubsub_app_create_subscriber(verbose, mal_ctx, consumer_uri, broker_uri, encoder, decoder);

  //  @end
  printf("OK\n");

  // Start blocks until interrupted (see zloop).
  mal_ctx_start(mal_ctx);
  printf("Stopped.\n");

  mal_actor_join(publisher_actor);
  mal_actor_destroy(mal_ctx, &publisher_actor);
  mal_actor_join(subscriber_actor);
  mal_actor_destroy(mal_ctx, &subscriber_actor);
  mal_actor_join(broker_actor);
  mal_actor_destroy(mal_ctx, &broker_actor);

  mal_ctx_destroy(&mal_ctx);
  printf("destroyed.\n");
}
