/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2018 CNES
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

/**/
#include "../include/progress_consumer.h"

mal_actor_t *consumer_actor = NULL;

bool split = false;
bool tcp = true;

//  --------------------------------------------------------------------------
//  Selftest

int progress_consumer_create_consumer(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder) {
  int rc = 0;

  printf(" * progress_consumer_create_consumer: \n");

  mal_blob_t *authentication_id = mal_blob_new(0);
  mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
  mal_uinteger_t priority = 4;
  mal_identifier_list_t *domain = mal_identifier_list_new(0);
  mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
  mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
  mal_identifier_t *session_name = mal_identifier_new("LIVE");

  progress_consumer_t *consumer = progress_consumer_new(provider_uri,
      authentication_id, qoslevel, priority, domain, network_zone, session,
      session_name, encoder, decoder);

  mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "progress_consumer/consumer");
  printf("progress_consumer: consumer URI: %s\n", consumer_uri);

  consumer_actor = mal_actor_new(
      mal_ctx,
      consumer_uri, consumer,
      progress_consumer_initialize, progress_consumer_finalize);

  return rc;
}

// state
struct _progress_consumer_t {
  mal_uri_t *provider_uri;
  mal_blob_t *authentication_id;
  mal_qoslevel_t qoslevel;
  mal_uinteger_t priority;
  mal_identifier_list_t *domain;
  mal_identifier_t *network_zone;
  mal_sessiontype_t session;
  mal_identifier_t *session_name;
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;

  int cpt;
};

progress_consumer_t *progress_consumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  progress_consumer_t *self = (progress_consumer_t *) malloc(
      sizeof(progress_consumer_t));
  if (!self)
    return NULL;

  self->provider_uri = provider_uri;
  self->authentication_id = authentication_id;
  self->qoslevel = qoslevel;
  self->priority = priority;
  self->domain = domain;
  self->network_zone = network_zone;
  self->session = session;
  self->session_name = session_name;
  self->encoder = encoder;
  self->decoder = decoder;

  self->cpt = 0;

  return self;
}

mal_uri_t *progress_consumer_get_provider_uri(progress_consumer_t *self) {
  return self->provider_uri;
}

mal_blob_t *progress_consumer_get_authentication_id(progress_consumer_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *progress_consumer_get_domain(progress_consumer_t *self) {
  return self->domain;
}

mal_identifier_t *progress_consumer_get_network_zone(progress_consumer_t *self) {
  return self->network_zone;
}

mal_uinteger_t progress_consumer_get_priority(progress_consumer_t *self) {
  return self->priority;
}

mal_qoslevel_t progress_consumer_get_qoslevel(progress_consumer_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t progress_consumer_get_session(progress_consumer_t *self) {
  return self->session;
}

mal_identifier_t *progress_consumer_get_session_name(progress_consumer_t *self) {
  return self->session_name;
}

int progress_consumer_initialize(void *self, mal_actor_t *mal_actor) {
  printf("progress_consumer_initialize()\n");

  int rc = 0;

  rc = mal_routing_register_consumer_progress_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER,
      progress_consumer_testarea_testservice_testprogress_ack,
      progress_consumer_testarea_testservice_testprogress_update,
      progress_consumer_testarea_testservice_testprogress_response);


  progress_consumer_t *consumer = (progress_consumer_t *) self;

  // initiate an progress interaction
  mal_uri_t *provider_uri = consumer->provider_uri;

  printf("progress_consumer: provider URI: %s\n", provider_uri);

  printf("progress_consumer: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(4);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("list-element-0");
  string_list_content[1] = mal_string_new("list-element-1");
  string_list_content[2] = mal_string_new("list-element-2");
  string_list_content[3] = mal_string_new("list-element-3");

  void *cursor = mal_encoder_new_cursor(consumer->encoder);

  printf("progress_consumer: encoding_length_0\n");
  rc = testarea_testservice_testprogress_progress_add_encoding_length_0(
      consumer->encoder, string_list, cursor);
  if (rc < 0)
    return rc;

  printf("progress_consumer: new MAL message\n");
  mal_message_t *message = mal_message_new(consumer->authentication_id,
      consumer->qoslevel, consumer->priority, consumer->domain,
      consumer->network_zone, consumer->session, consumer->session_name,
      mal_encoder_cursor_get_length(consumer->encoder, cursor));

  mal_encoder_cursor_init(
      consumer->encoder, cursor,
      mal_message_get_body(message),
      mal_encoder_cursor_get_length(consumer->encoder, cursor),
      mal_message_get_body_offset(message));

  printf("progress_consumer: encode 0\n");
  rc = testarea_testservice_testprogress_progress_encode_0(
      cursor, consumer->encoder, string_list);
  mal_encoder_cursor_assert(consumer->encoder, cursor);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(consumer->encoder, cursor);

  printf("progress_consumer: progress message\n");
  rc = testarea_testservice_testprogress_progress(mal_actor_get_mal_endpoint(mal_actor), message, provider_uri);
  if (rc < 0)
    return rc;

  mal_string_list_destroy(&string_list);

  return rc;
}

int progress_consumer_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //progress_provider_t *provider = (progress_provider_t *) self;
  printf("### progress_consumer_finalize\n");

  mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
  mal_ctx_stop(mal_ctx);

  return rc;
}

int progress_consumer_testarea_testservice_testprogress_ack(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)  {
  int rc = 0;

//  progress_consumer_t *consumer = (progress_consumer_t *) self;

  printf("#### progress_consumer, testprogressack: %d, %d\n",
      mal_message_get_interaction_stage(message), mal_message_is_error_message(message));

  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer ACK'ed.\n");

  return rc;
}

int progress_consumer_testarea_testservice_testprogress_update(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  progress_consumer_t *consumer = (progress_consumer_t *) self;

  consumer->cpt += 1;

  printf("#### progress_consumer, testprogress_update: %d, %d -> %d\n",
      mal_message_get_interaction_stage(message), mal_message_is_error_message(message),
      consumer->cpt);

  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer UPDATED.\n");

  return rc;
}

int progress_consumer_testarea_testservice_testprogress_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)  {
  int rc = 0;

  progress_consumer_t *consumer = (progress_consumer_t *) self;

  printf("#### progress_consumer, testprogress: %d, %d\n",
      mal_message_get_interaction_stage(message),
      mal_message_is_error_message(message));

  // Get response parameter.

  void *cursor = mal_decoder_new_cursor(
      consumer->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("progress_provider: offset=%d\n", mal_message_get_body_offset(message));

  mal_string_list_t *parameter_0;
  printf("progress_provider: decode first parameter\n");
  rc = testarea_testservice_testprogress_progress_response_decode_0(
      cursor, consumer->decoder, &parameter_0);
  mal_decoder_cursor_assert(consumer->decoder, cursor);
  if (rc < 0)
    return rc;

  mal_decoder_cursor_destroy(consumer->decoder, cursor);

  printf("progress_provider: parameter_0=");
  mal_string_list_print(parameter_0);
  printf("\n");

  printf("progress_provider: destroy parameter_0\n");
  mal_string_list_destroy(&parameter_0);

  printf("progress_provider: destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer done.\n");

  mal_actor_term(consumer_actor);

  return 0;
}

void progress_consumer_test(bool verbose) {
  mal_set_log_level(CLOG_DEBUG_LEVEL);
  malzmq_set_log_level(CLOG_DEBUG_LEVEL);

  printf(" * progress_consumer: \n");

  //  @selftest
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
        "127.0.0.1", "7777",
        maltcp_header,
        true);
    // Change the logging level of maltcp encoding
    maltcp_ctx_set_encoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
    maltcp_ctx_set_decoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
  } else {
    // All the MAL header fields are passed
    malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL, NULL, NULL, NULL);

    // This test uses the same encoding configuration at the MAL/ZMQ transport
    // level (MAL header encoding) and at the application
    // level (MAL message body encoding)
    ctx = malzmq_ctx_new(
        mal_ctx,
        NULL,                 // Use default transformation of MAL URI to ZMQ URI
        "localhost", "7777",
        malzmq_header,
        true);
    // Change the logging level of malzmq encoding
    malzmq_ctx_set_encoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
    malzmq_ctx_set_decoder_log_level((malzmq_ctx_t *) ctx, CLOG_WARN_LEVEL);
  }

  if (!ctx) exit(EXIT_FAILURE);

  mal_uri_t *provider_uri = "maltcp://192.168.1.80:6666/progress_provider/provider";
  printf("progress_consumer: provider URI: %s\n", provider_uri);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }
  progress_consumer_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);

  //  @end
  printf("OK\n");

  // Start blocks until interrupted (see zloop).
  mal_ctx_start(mal_ctx);
  
  printf("Stopped.\n");
  
  mal_actor_destroy(mal_ctx, &consumer_actor);

  mal_ctx_destroy(&mal_ctx);
  printf("destroyed.\n");
}
