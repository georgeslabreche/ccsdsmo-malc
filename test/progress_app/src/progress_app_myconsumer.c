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
#include "progress_app.h"

// state
struct _progress_app_myconsumer_t {
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

progress_app_myconsumer_t *progress_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  progress_app_myconsumer_t *self = (progress_app_myconsumer_t *) malloc(
      sizeof(progress_app_myconsumer_t));
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

mal_uri_t *progress_app_myconsumer_get_provider_uri(progress_app_myconsumer_t *self) {
  return self->provider_uri;
}

mal_blob_t *progress_app_myconsumer_get_authentication_id(progress_app_myconsumer_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *progress_app_myconsumer_get_domain(progress_app_myconsumer_t *self) {
  return self->domain;
}

mal_identifier_t *progress_app_myconsumer_get_network_zone(progress_app_myconsumer_t *self) {
  return self->network_zone;
}

mal_uinteger_t progress_app_myconsumer_get_priority(progress_app_myconsumer_t *self) {
  return self->priority;
}

mal_qoslevel_t progress_app_myconsumer_get_qoslevel(progress_app_myconsumer_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t progress_app_myconsumer_get_session(progress_app_myconsumer_t *self) {
  return self->session;
}

mal_identifier_t *progress_app_myconsumer_get_session_name(progress_app_myconsumer_t *self) {
  return self->session_name;
}

int progress_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor) {
  printf("progress_app_myconsumer_initialize()\n");

  int rc = 0;

  rc = mal_routing_register_consumer_progress_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER,
      progress_app_myconsumer_testarea_testservice_testprogress_ack,
      progress_app_myconsumer_testarea_testservice_testprogress_update,
      progress_app_myconsumer_testarea_testservice_testprogress_response);


  progress_app_myconsumer_t *consumer = (progress_app_myconsumer_t *) self;

  // initiate an progress interaction
  mal_uri_t *provider_uri = consumer->provider_uri;

  printf("progress_app_myconsumer: provider URI: %s\n", provider_uri);

  printf("progress_app_myconsumer: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(4);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("list-element-0");
  string_list_content[1] = mal_string_new("list-element-1");
  string_list_content[2] = mal_string_new("list-element-2");
  string_list_content[3] = mal_string_new("list-element-3");

  void *cursor = mal_encoder_new_cursor(consumer->encoder);

  printf("progress_app_myconsumer: encoding_length_0\n");
  rc = testarea_testservice_testprogress_progress_add_encoding_length_0(
      consumer->encoder, string_list, cursor);
  if (rc < 0)
    return rc;

  printf("progress_app_myconsumer: new MAL message\n");
  mal_message_t *message = mal_message_new(consumer->authentication_id,
      consumer->qoslevel, consumer->priority, consumer->domain,
      consumer->network_zone, consumer->session, consumer->session_name,
      mal_encoder_cursor_get_length(consumer->encoder, cursor));

  mal_encoder_cursor_init(
      consumer->encoder, cursor,
      mal_message_get_body(message),
      mal_encoder_cursor_get_length(consumer->encoder, cursor),
      mal_message_get_body_offset(message));

  printf("progress_app_myconsumer: encode 0\n");
  rc = testarea_testservice_testprogress_progress_encode_0(
      cursor, consumer->encoder, string_list);
  mal_encoder_cursor_assert(consumer->encoder, cursor);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(consumer->encoder, cursor);

  printf("progress_app_myconsumer: progress message\n");
  rc = testarea_testservice_testprogress_progress(mal_actor_get_mal_endpoint(mal_actor), message, provider_uri);
  if (rc < 0)
    return rc;

  mal_string_list_destroy(&string_list);

  return rc;
}

int progress_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //progress_app_myprovider_t *provider = (progress_app_myprovider_t *) self;
  printf("### progress_app_myconsumer_finalize\n");

  return rc;
}

int progress_app_myconsumer_testarea_testservice_testprogress_ack(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)  {
  int rc = 0;

//  progress_app_myconsumer_t *consumer = (progress_app_myconsumer_t *) self;

  printf("#### progress_app_myconsumer, testprogressack: %d, %d\n",
      mal_message_get_interaction_stage(message), mal_message_is_error_message(message));

  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer ACK'ed.\n");

  return rc;
}

int progress_app_myconsumer_testarea_testservice_testprogress_update(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  progress_app_myconsumer_t *consumer = (progress_app_myconsumer_t *) self;

  consumer->cpt += 1;

  printf("#### progress_app_myconsumer, testprogress_update: %d, %d -> %d\n",
      mal_message_get_interaction_stage(message), mal_message_is_error_message(message),
      consumer->cpt);

  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer UPDATED.\n");

  return rc;
}

int progress_app_myconsumer_testarea_testservice_testprogress_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)  {
	int rc = 0;

	progress_app_myconsumer_t *consumer = (progress_app_myconsumer_t *) self;

	printf("#### progress_app_myconsumer, testprogress: %d, %d\n",
			mal_message_get_interaction_stage(message),
			mal_message_is_error_message(message));

  // Get response parameter.

	void *cursor = mal_decoder_new_cursor(
	    consumer->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

	printf("progress_app_myprovider: offset=%d\n", mal_message_get_body_offset(message));

	mal_string_list_t *parameter_0;
	printf("progress_app_myprovider: decode first parameter\n");
	rc = testarea_testservice_testprogress_progress_response_decode_0(
			cursor, consumer->decoder, &parameter_0);
	mal_decoder_cursor_assert(consumer->decoder, cursor);
	if (rc < 0)
		return rc;

  mal_decoder_cursor_destroy(consumer->decoder, cursor);

	printf("progress_app_myprovider: parameter_0=");
	mal_string_list_print(parameter_0);
	printf("\n");

  printf("progress_app_myprovider: destroy parameter_0\n");
  mal_string_list_destroy(&parameter_0);

  printf("progress_app_myprovider: destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer done.\n");

  mal_actor_term(provider_actor);
  mal_actor_join(provider_actor);

  mal_actor_term(consumer_actor);

  printf("Stop context.\n");
  mal_ctx_stop(mal_ctx);

	return 0;
}

void progress_app_myconsumer_test(bool verbose) {
  printf(" * progress_app_myconsumer_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
