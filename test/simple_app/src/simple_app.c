/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
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
#include "simple_app.h"

zactor_t *provider_actor = NULL;
zactor_t *consumer_actor = NULL;

bool split = TEST_SPLIT;
bool tcp = TEST_TCP;

//  --------------------------------------------------------------------------
//  Selftest

simple_app_myprovider_t *simple_app_create_provider(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  printf(" * simple_app_create_provider: \n");

  mal_endpoint_t *provider_endpoint = mal_endpoint_new(mal_ctx, provider_uri);
  printf(" * simple_app_create_consumer: Create provider endpoint, URI: %s\n", provider_uri);
  mal_poller_t *provider_poller = mal_poller_new(mal_ctx);
  mal_poller_add_endpoint(provider_poller, provider_endpoint);

  simple_app_myprovider_t *provider = simple_app_myprovider_new(provider_poller, provider_endpoint, encoder, decoder);

  return provider;
}

simple_app_myconsumer_t *simple_app_create_consumer(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  printf(" * simple_app_create_consumer: \n");

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "simple_app/myconsumer");
  mal_endpoint_t *consumer_endpoint = mal_endpoint_new(mal_ctx, consumer_uri);
  printf(" * simple_app_create_consumer: Create consumer endpoint, URI: %s\n", consumer_uri);

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  simple_app_myconsumer_t *consumer = simple_app_myconsumer_new(
      consumer_endpoint,
      provider_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  return consumer;
}

void simple_app_test(bool verbose) {
  simple_app_myconsumer_t *consumer;
  simple_app_myprovider_t *provider;

  mal_set_log_level(CLOG_DEBUG_LEVEL);
  malzmq_set_log_level(CLOG_DEBUG_LEVEL);

  printf(" * simple_app: \n");

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
        "127.0.0.1", "6666",
        maltcp_header,
        true);
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
  }

  if (!ctx) exit(EXIT_FAILURE);

  mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "simple_app/myprovider");
  printf("simple_app: provider URI: %s\n", provider_uri);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  provider = simple_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
  consumer = simple_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);

  provider_actor = zactor_new(simple_app_myprovider_run, provider);
  consumer_actor = zactor_new(simple_app_myconsumer_run, consumer);

  //  @end
  printf("OK\n");

  // Start blocks until interrupted (see zloop).
  mal_ctx_start(mal_ctx);

  printf("Stopped.\n");

  mal_ctx_destroy(&mal_ctx);
  printf("destroyed.\n");
}
