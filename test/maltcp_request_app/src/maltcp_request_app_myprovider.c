/* */
#include "maltcp_request_app.h"

// state
struct _maltcp_request_app_myprovider_t {
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

maltcp_request_app_myprovider_t *maltcp_request_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder) {
  maltcp_request_app_myprovider_t *self = (maltcp_request_app_myprovider_t *) malloc(
      sizeof(maltcp_request_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int maltcp_request_app_myprovider_get_encoding_format_code(
    maltcp_request_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void maltcp_request_app_myprovider_set_decoder(maltcp_request_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *maltcp_request_app_myprovider_get_decoder(maltcp_request_app_myprovider_t *self) {
  return self->decoder;
}

void *maltcp_request_app_myprovider_get_encoder(maltcp_request_app_myprovider_t *self) {
  return self->encoder;
}

int maltcp_request_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_request_app_myprovider_t *provider = (maltcp_request_app_myprovider_t *) self;

  rc = mal_routing_register_provider_request_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTREQUEST_OPERATION_NUMBER,
      maltcp_request_app_myprovider_testarea_testservice_testrequest);

  return rc;
}

int maltcp_request_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_request_app_myprovider_t *provider = (maltcp_request_app_myprovider_t *) self;

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

int maltcp_request_app_myprovider_testarea_testservice_testrequest(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  maltcp_request_app_myprovider_t *provider = (maltcp_request_app_myprovider_t *) self;

  printf("maltcp_request_app_myprovider: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  unsigned int offset = mal_message_get_body_offset(message);
  char *bytes = mal_message_get_body(message);

  printf("maltcp_request_app_myprovider: offset=%d\n", offset);

  testarea_testservice_testcomposite_t *parameter_0;
  printf("maltcp_request_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testrequest_request_decode_0(provider->encoding_format_code,
      bytes, &offset, provider->decoder, &parameter_0);
  if (rc < 0)
    return rc;
  printf("parameter_0=");
  testarea_testservice_testcomposite_print(parameter_0);
  printf("\n");

  printf("maltcp_request_app_myprovider: offset=%d\n", offset);

  mal_string_list_t *parameter_1;
  printf("maltcp_request_app_myprovider: decode second parameter\n");
  rc = testarea_testservice_testrequest_request_decode_1(provider->encoding_format_code,
      bytes, &offset, provider->decoder, &parameter_1);
  if (rc < 0)
    return rc;
  printf("parameter_1=");
  mal_string_list_print(parameter_1);
  printf("\n");

  printf("maltcp_request_app_myprovider: offset=%d\n", offset);

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {
  } else {
  }

  // parameter_1 may be NULL
  if (parameter_1 == NULL) {
  } else {
  }

  // Send response to consumer

  printf("maltcp_request_app_myprovider: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(3);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("response-list-element-1");
  string_list_content[1] = mal_string_new("response-list-element-2");
  string_list_content[2] = mal_string_new("response-list-element-3");

  unsigned int body_length = 0;
  printf("maltcp_request_app_myprovider: encoding_length_0\n");
  rc = testarea_testservice_testrequest_request_response_add_encoding_length_0(
		  maltcp_request_app_myprovider_get_encoding_format_code(provider),
		  maltcp_request_app_myprovider_get_encoder(provider), string_list, &body_length);
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
		  body_length);

  unsigned int offset_r = mal_message_get_body_offset(result_message);
  char *bytes_r = mal_message_get_body(result_message);

  printf("maltcp_request_app_myprovider: encode 0\n");
  rc = testarea_testservice_testrequest_request_response_encode_0(
		  maltcp_request_app_myprovider_get_encoding_format_code(provider), bytes_r, &offset_r,
		  maltcp_request_app_myprovider_get_encoder(provider), string_list);
  if (rc < 0)
    return rc;

  printf("AF: maltcp_request_app_myprovider: handler send RESPONSE\n");
  rc = testarea_testservice_testrequest_request_response(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: maltcp_request_app_myprovider: handler RESPONSE sent\n");

  printf("destroy parameter_0: \n");
  testarea_testservice_testcomposite_destroy(&parameter_0);
  printf("destroy parameter_1\n");
  mal_string_list_destroy(&parameter_1);

  printf("destroy MAL init message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("destroy parameter_0\n");
  mal_string_list_destroy(&string_list);

  printf("destroy MAL result message\n");
  mal_message_destroy(&result_message, mal_ctx);

  printf("Provider done.\n");
  return rc;
}

void maltcp_request_app_myprovider_test(bool verbose) {
  printf(" * maltcp_request_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
