/* */
#include "invoke_app.h"

// state
struct _invoke_app_myprovider_t {
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

invoke_app_myprovider_t *invoke_app_myprovider_new(int encoding_format_code,
    void *encoder, void *decoder) {
  invoke_app_myprovider_t *self = (invoke_app_myprovider_t *) malloc(
      sizeof(invoke_app_myprovider_t));
  if (!self)
    return NULL;

  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int invoke_app_myprovider_get_encoding_format_code(
    invoke_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void invoke_app_myprovider_set_decoder(invoke_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *invoke_app_myprovider_get_decoder(invoke_app_myprovider_t *self) {
  return self->decoder;
}

void *invoke_app_myprovider_get_encoder(invoke_app_myprovider_t *self) {
  return self->encoder;
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

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("invoke_app_myprovider: offset=%d\n", mal_message_get_body_offset(message));

  mal_string_list_t *parameter_0;
  printf("invoke_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testinvoke_invoke_decode_0(provider->encoding_format_code,
      &cursor, provider->decoder, &parameter_0);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;
  printf("parameter_0=");
  mal_string_list_print(parameter_0);
  printf("\n");

  printf("invoke_app_myprovider: offset=%d\n", malbinary_cursor_get_body_offset(&cursor));

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

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor_r;
  malbinary_cursor_reset(&cursor_r);

  printf("invoke_app_myprovider: encoding_length_0\n");
  rc = testarea_testservice_testinvoke_invoke_response_add_encoding_length_0(
		  invoke_app_myprovider_get_encoding_format_code(provider),
		  invoke_app_myprovider_get_encoder(provider), string_list, &cursor_r);
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
		  malbinary_cursor_get_body_length(&cursor_r));

  // TODO (AF): Use a virtual function
  malbinary_cursor_init(&cursor_r,
      mal_message_get_body(result_message),
      mal_message_get_body_offset(result_message) + mal_message_get_body_length(result_message),
      mal_message_get_body_offset(result_message));

  printf("invoke_app_myprovider: encode 0\n");
  rc = testarea_testservice_testinvoke_invoke_response_encode_0(
		  invoke_app_myprovider_get_encoding_format_code(provider), &cursor_r,
		  invoke_app_myprovider_get_encoder(provider), string_list);
  malbinary_cursor_assert(&cursor_r);
  if (rc < 0)
    return rc;


  printf("AF: invoke_app_myprovider: handler send RESPONSE\n");
  rc = testarea_testservice_testinvoke_invoke_response(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: invoke_app_myprovider: handler RESPONSE sent\n");

  printf("destroy parameter_0: \n");
  mal_string_list_destroy(&parameter_0);

  printf("destroy MAL init message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("destroy parameter_0\n");
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
