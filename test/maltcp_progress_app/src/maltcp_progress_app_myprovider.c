/* */
#include "maltcp_progress_app.h"

// state
struct _maltcp_progress_app_myprovider_t {
  mal_uri_t *provider_uri;
  mal_blob_t *authentication_id;
  mal_qoslevel_t qoslevel;
  mal_uinteger_t priority;
  mal_identifier_list_t *domain;
  mal_identifier_t *network_zone;
  mal_sessiontype_t session;
  mal_identifier_t *session_name;
  int encoding_format_code;
  void *encoder;
  void *decoder;
};

maltcp_progress_app_myprovider_t *maltcp_progress_app_myprovider_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder) {
  maltcp_progress_app_myprovider_t *self = (maltcp_progress_app_myprovider_t *) malloc(
      sizeof(maltcp_progress_app_myprovider_t));
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
  self->encoding_format_code = encoding_format_code;
  self->encoder = encoder;
  self->decoder = decoder;
  return self;
}

int maltcp_progress_app_myprovider_get_encoding_format_code(
    maltcp_progress_app_myprovider_t *self) {
  return self->encoding_format_code;
}

void maltcp_progress_app_myprovider_set_decoder(maltcp_progress_app_myprovider_t *self,
    void *decoder) {
  self->decoder = decoder;
}

void *maltcp_progress_app_myprovider_get_decoder(maltcp_progress_app_myprovider_t *self) {
  return self->decoder;
}

void *maltcp_progress_app_myprovider_get_encoder(maltcp_progress_app_myprovider_t *self) {
  return self->encoder;
}

int maltcp_progress_app_myprovider_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_progress_app_myprovider_t *provider = (maltcp_progress_app_myprovider_t *) self;
  printf("### maltcp_progress_app_myprovider_initialize\n");

  rc = mal_routing_register_provider_progress_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER,
      maltcp_progress_app_myprovider_testarea_testservice_testprogress);

  return rc;
}

int maltcp_progress_app_myprovider_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  //maltcp_progress_app_myprovider_t *provider = (maltcp_progress_app_myprovider_t *) self;
  printf("### maltcp_progress_app_myprovider_finalize\n");

  return rc;
}

int maltcp_progress_app_myprovider_testarea_testservice_testprogress(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  maltcp_progress_app_myprovider_t *provider = (maltcp_progress_app_myprovider_t *) self;

  printf("maltcp_progress_app_myprovider: URI To=%s\n", mal_message_get_uri_to(message));

  // application code (may decode only a part of the message body)

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("maltcp_progress_app_myprovider: offset=%d\n", mal_message_get_body_offset(message));

  mal_string_list_t *parameter_0;
  printf("maltcp_progress_app_myprovider: decode first parameter\n");
  rc = testarea_testservice_testprogress_progress_decode_0(provider->encoding_format_code,
      &cursor, provider->decoder, &parameter_0);
  malbinary_cursor_assert(&cursor);
  if (rc < 0)
    return rc;
  printf("parameter_0=");
  mal_string_list_print(parameter_0);
  printf("\n");

  printf("maltcp_progress_app_myprovider: offset=%d\n", malbinary_cursor_get_body_offset(&cursor));

  // parameter_0 may be NULL
  if (parameter_0 == NULL) {
  } else {
  }

  // Send ack to consumer

  mal_message_t *ack_message = mal_message_new(
      provider->authentication_id,
      provider->qoslevel,
      provider->priority,
      provider->domain,
      provider->network_zone,
      provider->session,
      provider->session_name,
      0);

  mal_message_set_body(ack_message, NULL);
  mal_message_set_body_length(ack_message, 0);

  printf("AF: maltcp_progress_app_myprovider: handler send ACK\n");
  rc = testarea_testservice_testprogress_progress_ack(mal_endpoint, message, ack_message, (0 != 0));
  printf("AF: maltcp_progress_app_myprovider: handler ACK sent\n");

  printf("destroy MAL result message\n");
  mal_message_destroy(&ack_message, mal_ctx);

  // Send updates to consumer

  for (int i=0; i<10; i++) {
    printf("Before sleep\n");
    zclock_sleep (1000);
    printf("After sleep\n");

    mal_message_t *update_msg = mal_message_new(
        provider->authentication_id,
        provider->qoslevel,
        provider->priority,
        provider->domain,
        provider->network_zone,
        provider->session,
        provider->session_name,
        0);

    mal_message_set_body(update_msg, NULL);
    mal_message_set_body_length(update_msg, 0);

    printf("AF: maltcp_progress_app_myprovider: handler send UPDATE\n");
    rc = testarea_testservice_testprogress_progress_update(mal_endpoint, message, update_msg, (0 != 0));
    printf("AF: maltcp_progress_app_myprovider: handler UPDATE sent\n");

    printf("destroy MAL result message\n");
    mal_message_destroy(&update_msg, mal_ctx);
  }

  // Send response to consumer

  printf("maltcp_progress_app_myprovider: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(1);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("response-list-element-1");

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor_r;
  malbinary_cursor_reset(&cursor_r);

  printf("maltcp_progress_app_myprovider: encoding_length_0\n");
  rc = testarea_testservice_testprogress_progress_response_add_encoding_length_0(
		  maltcp_progress_app_myprovider_get_encoding_format_code(provider),
		  maltcp_progress_app_myprovider_get_encoder(provider), string_list, &cursor_r);
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

  printf("maltcp_progress_app_myprovider: encode 0\n");
  rc = testarea_testservice_testprogress_progress_response_encode_0(
		  maltcp_progress_app_myprovider_get_encoding_format_code(provider), &cursor_r,
		  maltcp_progress_app_myprovider_get_encoder(provider), string_list);
  if (rc < 0)
    return rc;


  printf("AF: maltcp_progress_app_myprovider: handler send RESPONSE\n");
  rc = testarea_testservice_testprogress_progress_response(mal_endpoint, message, result_message, (0 != 0));
  printf("AF: maltcp_progress_app_myprovider: handler RESPONSE sent\n");

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

void maltcp_progress_app_myprovider_test(bool verbose) {
  printf(" * maltcp_progress_app_myprovider_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
