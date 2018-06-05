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
#include "submit_app.h"

// state
struct _submit_app_myprovider_t {
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

submit_app_myprovider_t *submit_app_myprovider_new(
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  submit_app_myprovider_t *self = (submit_app_myprovider_t *) malloc(
      sizeof(submit_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int submit_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //submit_app_myprovider_t *provider = (submit_app_myprovider_t *) self;

  rc = mal_routing_register_provider_submit_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER,
      submit_app_myprovider_testarea_testservice_testsubmit);

  return rc;
}

int submit_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //submit_app_myprovider_t *provider = (submit_app_myprovider_t *) self;

  return rc;
}

void testarea_testservice_testcomposite_print(
    testarea_testservice_testcomposite_t *self) {
  printf("testarea_testservice_testcomposite_print(");
  printf("stringfield=%s", testarea_testservice_testcomposite_get_stringfield(self));
  printf(",intfield_is_present=%d", testarea_testservice_testcomposite_intfield_is_present(self));
  printf(",intfield=%d", testarea_testservice_testcomposite_get_intfield(self));
  printf(")");
}

void testarea_testservice_testfinalcompositea_print(
    testarea_testservice_testfinalcompositea_t *self) {
  printf("testarea_testservice_testfinalcompositea_print(");
  printf("intfield=%d", testarea_testservice_testfinalcompositea_get_intfield(self));
  printf(",intfield1=%d", testarea_testservice_testfinalcompositea_get_intfield2(self));
  printf(")");
}

int submit_app_myprovider_testarea_testservice_testsubmit(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  submit_app_myprovider_t *provider = (submit_app_myprovider_t *) self;

  printf("submit_app_myprovider: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  void *cursor = mal_decoder_new_cursor(
      provider->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("submit_app_myprovider: offset=%d\n", mal_message_get_body_offset(message));

  testarea_testservice_testcomposite_t *parameter_0;
  printf("submit_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testsend_send_decode_0(
      cursor, provider->decoder, &parameter_0);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("parameter_0=\n");
  testarea_testservice_testcomposite_print(parameter_0);
  printf("\n");

  printf("submit_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));

  mal_string_list_t *parameter_1;
  printf("submit_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testsend_send_decode_1(
      cursor, provider->decoder, &parameter_1);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("parameter_1=\n");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("submit_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));

  mal_element_holder_t parameter_2;
  printf("submit_app_myprovider: decode third parameter\n");
  rc = testarea_testservice_testsend_send_decode_2(
      cursor, provider->decoder, &parameter_2);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("submit_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));
  mal_decoder_cursor_destroy(provider->decoder, cursor);

  if (parameter_2.presence_flag)
    printf("submit_app_myprovider: decoding done, short form=%lu\n", parameter_2.short_form);
  else
    printf("submit_app_myprovider: decoding done, presence_flag false\n");

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {
  } else {
  }

  // parameter_1 may be NULL
  if (parameter_1 == NULL) {
  } else {
  }

  // parameter_2 may be NULL
  if (! parameter_2.presence_flag) {
  } else {
    if (parameter_2.short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
      testarea_testservice_testfinalcompositea_t *testfinalcompositea =
          (testarea_testservice_testfinalcompositea_t *) parameter_2.value.composite_value;
      mal_integer_t int_value =
          testarea_testservice_testfinalcompositea_get_intfield2(testfinalcompositea);
      printf("int_value=%d\n", int_value);

      printf("parameter_2=\n");
      testarea_testservice_testfinalcompositea_print(testfinalcompositea);
      printf("\n");

      printf("destroy parameter_2\n");
      testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
    } else {
      printf("parameter_2 unknown\n");
    }
  }

  // Send ack to consumer

  mal_message_t *result_message = mal_message_new_void();

  mal_message_set_uri_from(result_message, "");
  mal_message_set_uri_to(result_message, "");

  mal_message_set_authentication_id(result_message, mal_blob_new(0));
  mal_message_set_qoslevel(result_message, mal_message_get_qoslevel(message));
  mal_message_set_priority(result_message, mal_message_get_priority(message));
  mal_message_set_domain(result_message, mal_message_get_domain(message));
  mal_message_set_network_zone(result_message, mal_message_get_network_zone(message));
  mal_message_set_session(result_message, mal_message_get_session(message));
  mal_message_set_session_name(result_message, mal_message_get_session_name(message));
  mal_message_set_body(result_message, NULL);
  mal_message_set_body_length(result_message, 0);

  printf("AF: submit_app_myprovider: handler send ACK\n");
  rc = testarea_testservice_testsubmit_submit_ack(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: submit_app_myprovider: handler ACK sent: %d\n", rc);

  printf("destroy parameter_0\n");
  testarea_testservice_testcomposite_destroy(&parameter_0);
  printf("destroy parameter_1\n");
  mal_string_list_destroy(&parameter_1);

  printf("destroy MAL init message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("destroy MAL result message\n");
  mal_message_destroy(&result_message, mal_ctx);

  printf("Provider done.\n");
  return rc;
}

void submit_app_myprovider_test(bool verbose) {
  printf(" * submit_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
