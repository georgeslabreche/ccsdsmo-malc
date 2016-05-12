/* */
#include "maltcp_simple_app.h"

// state
struct _maltcp_simple_app_myprovider_t {
  mal_poller_t *poller;
  mal_endpoint_t *endpoint;
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

maltcp_simple_app_myprovider_t *maltcp_simple_app_myprovider_new(
    mal_poller_t *poller,
    mal_endpoint_t *endpoint,
    int encoding_format_code,
    void *encoder, void *decoder) {
  maltcp_simple_app_myprovider_t *self = (maltcp_simple_app_myprovider_t *) malloc(
      sizeof(maltcp_simple_app_myprovider_t));
  if (!self)
    return NULL;

  self->poller = poller;
  self->endpoint = endpoint;
  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int maltcp_simple_app_myprovider_get_encoding_format_code(
    maltcp_simple_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void maltcp_simple_app_myprovider_set_decoder(maltcp_simple_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *maltcp_simple_app_myprovider_get_decoder(maltcp_simple_app_myprovider_t *self) {
  return self->decoder;
}

void maltcp_simple_app_myprovider_run(zsock_t *pipe, void *args) {
  int rc = 0;
  maltcp_simple_app_myprovider_t *self = (maltcp_simple_app_myprovider_t *) args;

  printf("maltcp_simple_app_myprovider_run:\n");

  //  Signal successful initialization
  zsock_signal(pipe, 0);

  mal_routing_t *router = mal_routing_new(self->endpoint, self);

  printf("maltcp_simple_app_myprovider_run: registers SEND handler\n");
  rc = mal_routing_register_provider_send_handler(
      router,
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER,
      maltcp_simple_app_myprovider_testarea_testservice_testsend);
  printf("maltcp_simple_app_myprovider_run, register SEND handler: %d\n", rc);
  if (rc != 0) return;

  mal_endpoint_t *endpoint;
  rc = mal_poller_wait(self->poller, &endpoint, -1);

  printf("maltcp_simple_app_myprovider_run, %p %p\n", (void *) endpoint, (void *) self->endpoint);

  mal_message_t *message = NULL;
  rc = mal_endpoint_recv_message(self->endpoint, &message);
  printf("maltcp_simple_app_myprovider_run, receive message: %d\n", rc);
  if (rc != 0) return;

  if (message != NULL) {
    rc = mal_routing_handle(router, message);
    if (rc != 0)
      mal_message_destroy(&message, mal_endpoint_get_mal_ctx(self->endpoint));
  }

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
  printf("intfield=%d", self->intfield);
  printf(",intfield1=%d", self->intfield2);
  printf(")");
}

int maltcp_simple_app_myprovider_testarea_testservice_testsend(
    void *self,
    mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message) {
  int rc = 0;
  maltcp_simple_app_myprovider_t *provider = (maltcp_simple_app_myprovider_t *) self;

  printf("maltcp_simple_app_myprovider_testarea_testservice_testsend: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("maltcp_simple_app_myprovider: offset=%d", mal_message_get_body_offset(message));

  testarea_testservice_testcomposite_t *parameter_0;
  printf("maltcp_simple_app_myprovider: decode first parameter\n");
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

  printf("maltcp_simple_app_myprovider: offset=%d", malbinary_cursor_get_body_offset(&cursor));

  mal_string_list_t *parameter_1;
  printf("maltcp_simple_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testsend_send_decode_1(provider->encoding_format_code,
      &cursor, provider->decoder, &parameter_1);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;
  printf("parameter_1=\n");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("maltcp_simple_app_myprovider: offset=%d\n", malbinary_cursor_get_body_offset(&cursor));

  long short_form;
  void *parameter_2;
  printf("maltcp_simple_app_myprovider: decode third parameter\n");
  rc = testarea_testservice_testsend_send_decode_2(provider->encoding_format_code,
      &cursor, provider->decoder, &short_form, &parameter_2);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;

  printf("maltcp_simple_app_myprovider: offset=%d\n", malbinary_cursor_get_body_offset(&cursor));
  printf("maltcp_simple_app_myprovider: decoding done, short form=%lu\n",
      short_form);

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {

  } else {

  }

  // parameter_1 may be NULL
  if (parameter_1 == NULL) {

  } else {

  }

  // parameter_2 may be NULL
  if (parameter_2 == NULL) {

  } else {
    if (short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
      testarea_testservice_testfinalcompositea_t *testfinalcompositea =
          (testarea_testservice_testfinalcompositea_t *) parameter_2;
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
  mal_message_destroy(&message, mal_endpoint_get_mal_ctx(provider->endpoint));

  printf("Provider done.\n");
  return rc;
}

void maltcp_simple_app_myprovider_test(bool verbose) {
  printf(" * maltcp_simple_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
