/* */
#include "../include/send_app.h"

// state
struct _send_app_myprovider_t {
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

send_app_myprovider_t *send_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder) {
  send_app_myprovider_t *self = (send_app_myprovider_t *) malloc(
      sizeof(send_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int send_app_myprovider_get_encoding_format_code(
    send_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void send_app_myprovider_set_decoder(send_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *send_app_myprovider_get_decoder(send_app_myprovider_t *self) {
  return self->decoder;
}

int send_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //send_app_myprovider_t *provider = (send_app_myprovider_t *) self;

  rc = mal_routing_register_provider_send_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER,
      send_app_myprovider_testarea_testservice_testsend);

  return rc;
}

int send_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //send_app_myprovider_t *provider = (send_app_myprovider_t *) self;

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

int send_app_myprovider_testarea_testservice_testsend(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  send_app_myprovider_t *provider = (send_app_myprovider_t *) self;

  printf("send_app_myprovider_testarea_testservice_testsend: URI To=%s\n",
      mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("send_app_myprovider: offset=%d", mal_message_get_body_offset(message));

  testarea_testservice_testcomposite_t *parameter_0;
  printf("send_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testsend_send_decode_0(
      provider->encoding_format_code,
      &cursor,
      provider->decoder,
      &parameter_0);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;
  printf("parameter_0=\n");
  testarea_testservice_testcomposite_print(parameter_0);
  printf("\n");

  printf("send_app_myprovider: offset=%d", malbinary_cursor_get_body_offset(&cursor));

  mal_string_list_t *parameter_1;
  printf("send_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testsend_send_decode_1(provider->encoding_format_code,
      &cursor, provider->decoder, &parameter_1);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;
  printf("parameter_1=\n");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("send_app_myprovider: offset=%d", malbinary_cursor_get_body_offset(&cursor));

  mal_element_holder_t element_holder;
  printf("send_app_myprovider: decode third parameter\n");
  rc = testarea_testservice_testsend_send_decode_2(provider->encoding_format_code,
      &cursor, provider->decoder, &element_holder);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;

  printf("send_app_myprovider: offset=%d", malbinary_cursor_get_body_offset(&cursor));
  printf("send_app_myprovider: decoding done, short form=%lu\n", element_holder.short_form);

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
          testarea_testservice_testfinalcompositea_get_intfield2(
              testfinalcompositea);
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
  mal_message_destroy(&message, mal_ctx);

  printf("Provider done.\n");
  return rc;
}

void send_app_myprovider_test(bool verbose) {
  printf(" * send_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
