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
#include "send_app.h"

// state
struct _send_app_myconsumer_t {
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
};

send_app_myconsumer_t *send_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  send_app_myconsumer_t *self = (send_app_myconsumer_t *) malloc(
      sizeof(send_app_myconsumer_t));
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
  return self;
}

mal_uri_t *send_app_myconsumer_get_provider_uri(send_app_myconsumer_t *self) {
  return self->provider_uri;
}

mal_blob_t *send_app_myconsumer_get_authentication_id(
    send_app_myconsumer_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *send_app_myconsumer_get_domain(
    send_app_myconsumer_t *self) {
  return self->domain;
}

mal_identifier_t *send_app_myconsumer_get_network_zone(
    send_app_myconsumer_t *self) {
  return self->network_zone;
}

mal_uinteger_t send_app_myconsumer_get_priority(send_app_myconsumer_t *self) {
  return self->priority;
}

mal_qoslevel_t send_app_myconsumer_get_qoslevel(send_app_myconsumer_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t send_app_myconsumer_get_session(
    send_app_myconsumer_t *self) {
  return self->session;
}

mal_identifier_t *send_app_myconsumer_get_session_name(
    send_app_myconsumer_t *self) {
  return self->session_name;
}

int send_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor) {
  printf("send_app_myconsumer_initialize()\n");

  int rc = 0;

  send_app_myconsumer_t *consumer = (send_app_myconsumer_t *) self;

  // initiate a SEND interaction
  mal_uri_t *provider_uri = consumer->provider_uri;

  printf("send_app_myconsumer: provider URI: %s\n", provider_uri);

  printf("send_app_myconsumer: new test composite\n");
  testarea_testservice_testcomposite_t *testcomposite =
      testarea_testservice_testcomposite_new();
  mal_string_t *str = mal_string_new("hello world");
  testarea_testservice_testcomposite_set_stringfield(testcomposite, str);
  testarea_testservice_testcomposite_intfield_set_present(testcomposite, true);
  testarea_testservice_testcomposite_set_intfield(testcomposite, 10);

  printf("send_app_myconsumer: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(2);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("list-element-1");
  string_list_content[1] = mal_string_new("list-element-2");

  printf("send_app_myconsumer: new test final composite A\n");
  testarea_testservice_testfinalcompositea_t *testfinalcompositea =
      testarea_testservice_testfinalcompositea_new();
  testarea_testservice_testfinalcompositea_set_intfield(testfinalcompositea,
      20);
  testarea_testservice_testfinalcompositea_set_intfield2(testfinalcompositea,
      30);

  void *cursor = mal_encoder_new_cursor(consumer->encoder);

  printf("send_app_myconsumer: encoding_length_0\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_0(
      consumer->encoder, testcomposite, cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myconsumer: encoding_length_1\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_1(
      consumer->encoder, string_list, cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myconsumer: encoding_length_2\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(
          consumer->encoder, testfinalcompositea, cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myconsumer: new MAL message\n");
  mal_message_t *message = mal_message_new(consumer->authentication_id,
      consumer->qoslevel, consumer->priority, consumer->domain,
      consumer->network_zone, consumer->session, consumer->session_name,
      mal_encoder_cursor_get_length(consumer->encoder, cursor));

  mal_encoder_cursor_init(
      consumer->encoder, cursor,
      mal_message_get_body(message),
      mal_encoder_cursor_get_length(consumer->encoder, cursor),
      mal_message_get_body_offset(message));

  printf("send_app_myconsumer: encode 0\n");
  rc = testarea_testservice_testsend_send_encode_0(
      cursor, consumer->encoder, testcomposite);
  mal_encoder_cursor_assert(consumer->encoder, cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myconsumer: encode 1\n");
  rc = testarea_testservice_testsend_send_encode_1(
      cursor, consumer->encoder, string_list);
  mal_encoder_cursor_assert(consumer->encoder, cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myconsumer: encode 2\n");
  rc =
      testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(
          cursor, consumer->encoder, testfinalcompositea);
  mal_encoder_cursor_assert(consumer->encoder, cursor);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(consumer->encoder, cursor);

  printf("send_app_myconsumer: send message\n");
  rc = testarea_testservice_testsend_send(mal_actor_get_mal_endpoint(mal_actor), message, provider_uri);
  if (rc < 0)
    return rc;

  testarea_testservice_testcomposite_destroy(&testcomposite);
  mal_string_list_destroy(&string_list);
  testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);

  return rc;
}

int send_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  // ...
  return rc;
}

void send_app_myconsumer_test(bool verbose) {
  printf(" * send_app_myconsumer_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
