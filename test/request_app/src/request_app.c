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
#include "request_app.h"

bool split = TEST_SPLIT;
bool tcp = TEST_TCP;

mal_actor_t *provider_actor = NULL;
mal_actor_t *consumer_actor = NULL;

//  --------------------------------------------------------------------------
// test also the mapping directory in this test
#define MD_SIZE 4
char **md_content = NULL;
int md_size = 0;

int md_get_key(char *string, unsigned int *key) {
  if (string == NULL) return -1;
  if (md_size == 0) return -1;
  for (int i = 0; i < md_size; i++) {
    if (strcmp(string, md_content[i]) == 0) {
      (*key) = (i+1);
      printf("#DEBUG md_get_key(%s) -> %d\n", string, *key);
      return 0;
    }
  }
  printf("#DEBUG md_get_key(%s) -> NOT FOUND\n", string);
  return -1;
}

int md_get_string(unsigned int key, char **string) {
  int i = key - 1;
  if ((i < 0) || (i >= md_size)) {
    printf("#DEBUG md_get_string(%d) -> NOT FOUND\n", key);
    return -1;
  }
  (*string) = md_content[i];
  printf("#DEBUG md_get_key(%d) -> %s\n", key, *string);
  return 0;
}

int md_put_string(char *string, unsigned int *key) {
  if (md_size >= MD_SIZE)
	return -1;
  if (md_size == 0) {
	md_content = (char **) calloc(MD_SIZE, sizeof(char *));
  }
  md_content[md_size++] = strdup(string);
  (*key) = md_size;
  printf("#DEBUG md_put_string(%s) -> %d\n", string, *key);
  return 0;
}

malzmq_mapping_directory_t mapping_directory = {
  &md_get_key, &md_get_string, &md_put_string
};

//  --------------------------------------------------------------------------
//  Selftest
int request_app_create_provider(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * request_app_create_provider: \n");

  request_app_myprovider_t *provider = request_app_myprovider_new(encoder, decoder);

  provider_actor = mal_actor_new(
      mal_ctx,
      provider_uri, provider,
      request_app_myprovider_initialize, request_app_myprovider_finalize);

  return rc;
}

int request_app_create_consumer(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * request_app_create_consumer: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  request_app_myconsumer_t *consumer = request_app_myconsumer_new(provider_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "request_app/myconsumer");
  printf("request_app: consumer URI: %s\n", consumer_uri);

 consumer_actor = mal_actor_new(
      mal_ctx,
      consumer_uri, consumer,
      request_app_myconsumer_initialize, request_app_myconsumer_finalize);

  return rc;
}

void request_app_test(bool verbose) {
  printf(" * request_app: \n");

  //  @selftest
  mal_ctx_t *mal_ctx = mal_ctx_new();
  void *ctx;

  if (tcp) {
    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);
    ctx = maltcp_ctx_new(
        mal_ctx,
        "127.0.0.1", "6666",
        maltcp_header,
        true);
    // Change the logging level of maltcp encoding
    maltcp_ctx_set_encoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
    maltcp_ctx_set_decoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
  } else {
    // All the MAL header fields are passed
    malzmq_header_t *malzmq_header = malzmq_header_new(&mapping_directory, true, 0, true, NULL, NULL, NULL, NULL);
    ctx = malzmq_ctx_new(
        mal_ctx,
        NULL,                 // Use default transformation of MAL URI to ZMQ URI
        "localhost", "6666",
        malzmq_header,
        true);
    // Change the logging level of malzmq encoding
    malzmq_ctx_set_encoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
    malzmq_ctx_set_decoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
  }

  if (!ctx) exit(EXIT_FAILURE);

  mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "request_app/myprovider");
  printf("request_app: provider URI: %s\n", provider_uri);
//  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "request_app/myconsumer");
//  printf("request_app: consumer URI: %s\n", consumer_uri);

  if (!tcp) {
    unsigned int md_key;
    mapping_directory.put_string_fn(provider_uri, &md_key);
//    mapping_directory.put_string_fn(consumer_uri, &md_key);
  }

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  request_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
  request_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);

  //  @end
  printf("OK\n");

  // Start blocks until interrupted (see zloop).
  mal_ctx_start(mal_ctx);
  
  printf("Stopped.\n");

  mal_actor_join(provider_actor);
  mal_actor_destroy(mal_ctx, &provider_actor);

  mal_actor_join(consumer_actor);
  mal_actor_destroy(mal_ctx, &consumer_actor);
  
  mal_ctx_destroy(&mal_ctx);
  printf("destroyed.\n");
}
