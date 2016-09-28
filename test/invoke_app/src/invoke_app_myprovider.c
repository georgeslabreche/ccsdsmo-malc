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
#include "invoke_app.h"

// state
struct _invoke_app_myprovider_t {
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

invoke_app_myprovider_t *invoke_app_myprovider_new(
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  invoke_app_myprovider_t *self = (invoke_app_myprovider_t *) malloc(sizeof(invoke_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int invoke_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //invoke_app_myprovider_t *provider = (invoke_app_myprovider_t *) self;
  printf("### invoke_app_myprovider_initialize:\n");

  rc = mal_routing_register_provider_invoke_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTINVOKE_OPERATION_NUMBER,
      invoke_app_myprovider_testarea_testservice_testinvoke);

  return rc;
}

int invoke_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //invoke_app_myprovider_t *provider = (invoke_app_myprovider_t *) self;
  printf("### invoke_app_myprovider_finalize:\n");

  return rc;
}

int invoke_app_myprovider_testarea_testservice_testinvoke(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  printf("### invoke_app_myconsumer, testinvoke: URI To=%s\n", mal_message_get_uri_to(message));

  invoke_app_myprovider_t *provider = (invoke_app_myprovider_t *) self;

  // application code (may decode only a part of the message body)

  void *cursor = mal_decoder_new_cursor(
      provider->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("invoke_app_myprovider: offset=%d\n", mal_message_get_body_offset(message));

  mal_string_list_t *parameter_0;
  printf("invoke_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testinvoke_invoke_decode_0(
      cursor, provider->decoder, &parameter_0);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;
  printf("parameter_0=");
  mal_string_list_print(parameter_0);
  printf("\n");

  printf("invoke_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));
  mal_decoder_cursor_destroy(provider->decoder, cursor);

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {
  } else {
  }

  // Send ack to consumer

  mal_message_t *ack_message = mal_message_new(
      mal_blob_new(0),
      mal_message_get_qoslevel(message),
      mal_message_get_priority(message),
      mal_message_get_domain(message),
      mal_message_get_network_zone(message),
      mal_message_get_session(message),
      mal_message_get_session_name(message),
      0);

  mal_message_set_body(ack_message, NULL);
  mal_message_set_body_length(ack_message, 0);

  printf("AF: invoke_app_myprovider: handler send ACK\n");
  rc = testarea_testservice_testinvoke_invoke_ack(mal_endpoint, message, ack_message, (0 != 0));
  printf("AF: invoke_app_myprovider: handler ACK sent\n");

  printf("destroy MAL result message\n");
  mal_message_destroy(&ack_message, mal_ctx);

//  printf("Before sleep\n");
//  zclock_sleep (10000);
//  printf("After sleep\n");

  // Send response to consumer

  printf("invoke_app_myprovider: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(1);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("response-list-element-1");

  void *cursor_r = mal_encoder_new_cursor(provider->encoder);

  printf("invoke_app_myprovider: encoding_length_0\n");
  rc = testarea_testservice_testinvoke_invoke_response_add_encoding_length_0(
		  provider->encoder, string_list, cursor_r);
  if (rc < 0)
    return rc;

  mal_message_t *result_message = mal_message_new(
		  mal_blob_new(0),
		  mal_message_get_qoslevel(message),
		  mal_message_get_priority(message),
		  mal_message_get_domain(message),
		  mal_message_get_network_zone(message),
		  mal_message_get_session(message),
		  mal_message_get_session_name(message),
		  mal_encoder_cursor_get_length(provider->encoder, cursor_r));

  mal_encoder_cursor_init(
      provider->encoder, cursor_r,
      mal_message_get_body(result_message),
      mal_message_get_body_offset(result_message) + mal_message_get_body_length(result_message),
      mal_message_get_body_offset(result_message));

  printf("invoke_app_myprovider: encode 0\n");
  rc = testarea_testservice_testinvoke_invoke_response_encode_0(
      cursor_r, provider->encoder, string_list);
  mal_encoder_cursor_assert(provider->encoder, cursor_r);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(provider->encoder, cursor_r);

  printf("AF: invoke_app_myprovider: handler send RESPONSE\n");
  rc = testarea_testservice_testinvoke_invoke_response(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: invoke_app_myprovider: handler RESPONSE sent\n");

  printf("destroy parameter_0: \n");
  mal_string_list_destroy(&parameter_0);

  printf("destroy MAL init message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("destroy string_list\n");
  mal_string_list_destroy(&string_list);

  printf("destroy MAL result message\n");
  mal_message_destroy(&result_message, mal_ctx);

  printf("Provider done.\n");

  return rc;
}

void invoke_app_myprovider_test(bool verbose) {
  printf(" * invoke_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
