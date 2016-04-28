/* */
#include "maltcp_submit_app.h"

// state
struct _maltcp_submit_app_myprovider_t {
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

maltcp_submit_app_myprovider_t *maltcp_submit_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder) {
  maltcp_submit_app_myprovider_t *self = (maltcp_submit_app_myprovider_t *) malloc(
      sizeof(maltcp_submit_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int maltcp_submit_app_myprovider_get_encoding_format_code(
    maltcp_submit_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void maltcp_submit_app_myprovider_set_decoder(maltcp_submit_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *maltcp_submit_app_myprovider_get_decoder(maltcp_submit_app_myprovider_t *self) {
  return self->decoder;
}

int maltcp_submit_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_submit_app_myprovider_t *provider = (maltcp_submit_app_myprovider_t *) self;

  rc = mal_routing_register_provider_submit_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER,
      maltcp_submit_app_myprovider_testarea_testservice_testsubmit);

  return rc;
}

int maltcp_submit_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_submit_app_myprovider_t *provider = (maltcp_submit_app_myprovider_t *) self;

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
  printf("intfield=%d", self->intfield);
  printf(",intfield1=%d", self->intfield2);
  printf(")");
}

int maltcp_submit_app_myprovider_testarea_testservice_testsubmit(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  maltcp_submit_app_myprovider_t *provider = (maltcp_submit_app_myprovider_t *) self;

  printf("maltcp_submit_app_myprovider: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  unsigned int offset = mal_message_get_body_offset(message);
  char *bytes = mal_message_get_body(message);

  printf("maltcp_submit_app_myprovider: offset=%d", offset);

  testarea_testservice_testcomposite_t *parameter_0;
  printf("maltcp_submit_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testsend_send_decode_0(provider->encoding_format_code,
      bytes, &offset, provider->decoder, &parameter_0);
  if (rc < 0)
    return rc;
  printf("parameter_0=\n");
  testarea_testservice_testcomposite_print(parameter_0);
  printf("\n");

  printf("maltcp_submit_app_myprovider: offset=%d", offset);

  mal_string_list_t *parameter_1;
  printf("maltcp_submit_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testsend_send_decode_1(provider->encoding_format_code,
      bytes, &offset, provider->decoder, &parameter_1);
  if (rc < 0)
    return rc;
  printf("parameter_1=\n");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("maltcp_submit_app_myprovider: offset=%d", offset);

  long short_form;
  void *parameter_2;
  printf("maltcp_submit_app_myprovider: decode third parameter\n");
  rc = testarea_testservice_testsend_send_decode_2(provider->encoding_format_code,
      bytes, &offset, provider->decoder, &short_form, &parameter_2);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myprovider: offset=%d", offset);
  printf("maltcp_submit_app_myprovider: decoding done, short form=%lu\n", short_form);

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

  printf("AF: maltcp_submit_app_myprovider: handler send ACK\n");
  rc = testarea_testservice_testsubmit_submit_ack(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: maltcp_submit_app_myprovider: handler ACK sent\n");

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

void maltcp_submit_app_myprovider_test(bool verbose) {
  printf(" * maltcp_submit_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
