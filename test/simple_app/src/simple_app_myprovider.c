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

// state
struct _simple_app_myprovider_t {
  mal_poller_t *poller;
  mal_endpoint_t *endpoint;
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
};

simple_app_myprovider_t *simple_app_myprovider_new(
    mal_poller_t *poller,
    mal_endpoint_t *endpoint,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  simple_app_myprovider_t *self = (simple_app_myprovider_t *) malloc(
      sizeof(simple_app_myprovider_t));
  if (!self)
    return NULL;

  self->poller = poller;
  self->endpoint = endpoint;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

void simple_app_myprovider_run(zsock_t *pipe, void *args) {
  int rc = 0;
  simple_app_myprovider_t *self = (simple_app_myprovider_t *) args;

  printf("simple_app_myprovider_run:\n");

  //  Signal successful initialization
  zsock_signal(pipe, 0);

  mal_routing_t *router = mal_routing_new(self->endpoint, self);

  printf("simple_app_myprovider_run: registers SEND handler\n");
  rc = mal_routing_register_provider_send_handler(
      router,
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER,
      simple_app_myprovider_testarea_testservice_testsend);
  printf("simple_app_myprovider_run, register SEND handler: %d\n", rc);
  if (rc != 0) return;

  mal_endpoint_t *endpoint;
  rc = mal_poller_wait(self->poller, &endpoint, -1);

  printf("simple_app_myprovider_run\n");

  mal_message_t *message = NULL;
  rc = mal_endpoint_recv_message(endpoint, &message);
  printf("simple_app_myprovider_run, receive message: %d\n", rc);
  if (rc != 0) return;

  if (message != NULL) {
    rc = mal_routing_handle(router, message);
    if (rc != 0)
      mal_message_destroy(&message, mal_endpoint_get_mal_ctx(self->endpoint));
  }

  mal_poller_destroy(&self->poller);
  mal_endpoint_destroy(&self->endpoint);
  mal_routing_destroy(&router);

  printf("simple_app_myprovider_run, end.\n");

  zactor_destroy(&provider_actor);

  return;
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

int simple_app_myprovider_testarea_testservice_testsend(
    void *self,
    mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message) {
  int rc = 0;
  simple_app_myprovider_t *provider = (simple_app_myprovider_t *) self;

  printf("simple_app_myprovider_testarea_testservice_testsend: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  void *cursor = mal_decoder_new_cursor(
      provider->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("simple_app_myprovider: offset=%d", mal_message_get_body_offset(message));

  testarea_testservice_testcomposite_t *parameter_0;
  printf("simple_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testsend_send_decode_0(
      cursor,
      provider->decoder,
      &parameter_0);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("parameter_0=\n");
  testarea_testservice_testcomposite_print(parameter_0);
  printf("\n");

  printf("simple_app_myprovider: offset=%d", mal_decoder_cursor_get_offset(provider->decoder, cursor));

  mal_string_list_t *parameter_1;
  printf("simple_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testsend_send_decode_1(
      cursor, provider->decoder, &parameter_1);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("parameter_1=\n");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("simple_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));

  mal_element_holder_t element_holder;
  printf("simple_app_myprovider: decode third parameter\n");
  rc = testarea_testservice_testsend_send_decode_2(
      cursor, provider->decoder, &element_holder);
  mal_decoder_cursor_assert(provider->decoder, cursor);
  if (rc < 0)
    return rc;

  printf("simple_app_myprovider: offset=%d\n", mal_decoder_cursor_get_offset(provider->decoder, cursor));
  mal_decoder_cursor_destroy(provider->decoder, cursor);

  printf("simple_app_myprovider: decoding done, short form=%lu\n", element_holder.short_form);

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {
  } else {
  }

  // parameter_1 may be NULL
  if (parameter_1 == NULL) {
  } else {
  }

  // parameter_2 may be NULL
  if (element_holder.value.composite_value == NULL) {
  } else {
    if (element_holder.short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
      testarea_testservice_testfinalcompositea_t *testfinalcompositea =
          (testarea_testservice_testfinalcompositea_t *) element_holder.value.composite_value;
      mal_integer_t int_value =
          testarea_testservice_testfinalcompositea_get_intfield2(testfinalcompositea);
      printf("int_value=%d\n", int_value);

      printf("parameter_2=\n");
      testarea_testservice_testfinalcompositea_print(testfinalcompositea);
      printf("\n");

      printf("destroy parameter_2\n");
      testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
    }
  }

  printf("destroy parameter_0\n");
  testarea_testservice_testcomposite_destroy(&parameter_0);
  printf("destroy parameter_1\n");
  mal_string_list_destroy(&parameter_1);

  printf("destroy MAL message\n");
  mal_message_destroy(&message, mal_endpoint_get_mal_ctx(provider->endpoint));

  printf("Provider done.\n");

  mal_ctx_stop(mal_ctx);

  return rc;
}

void simple_app_myprovider_test(bool verbose) {
  printf(" * simple_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
