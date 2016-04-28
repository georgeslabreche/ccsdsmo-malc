/* */
#include "maltcp_submit_app.h"

// state
struct _maltcp_submit_app_myconsumer_t {
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

maltcp_submit_app_myconsumer_t *maltcp_submit_app_myconsumer_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder) {
  maltcp_submit_app_myconsumer_t *self = (maltcp_submit_app_myconsumer_t *) malloc(
      sizeof(maltcp_submit_app_myconsumer_t));
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

int maltcp_submit_app_myconsumer_get_encoding_format_code(
    maltcp_submit_app_myconsumer_t *self) {
  return self->encoding_format_code;
}

void *maltcp_submit_app_myconsumer_get_encoder(maltcp_submit_app_myconsumer_t *self) {
  return self->encoder;
}

void *maltcp_submit_app_myconsumer_get_decoder(maltcp_submit_app_myconsumer_t *self) {
  return self->decoder;
}

mal_uri_t *maltcp_submit_app_myconsumer_get_provider_uri(maltcp_submit_app_myconsumer_t *self) {
  return self->provider_uri;
}

mal_blob_t *maltcp_submit_app_myconsumer_get_authentication_id(
    maltcp_submit_app_myconsumer_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *maltcp_submit_app_myconsumer_get_domain(
    maltcp_submit_app_myconsumer_t *self) {
  return self->domain;
}

mal_identifier_t *maltcp_submit_app_myconsumer_get_network_zone(
    maltcp_submit_app_myconsumer_t *self) {
  return self->network_zone;
}

mal_uinteger_t maltcp_submit_app_myconsumer_get_priority(maltcp_submit_app_myconsumer_t *self) {
  return self->priority;
}

mal_qoslevel_t maltcp_submit_app_myconsumer_get_qoslevel(maltcp_submit_app_myconsumer_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t maltcp_submit_app_myconsumer_get_session(
    maltcp_submit_app_myconsumer_t *self) {
  return self->session;
}

mal_identifier_t *maltcp_submit_app_myconsumer_get_session_name(
    maltcp_submit_app_myconsumer_t *self) {
  return self->session_name;
}

int maltcp_submit_app_myconsumer_initialize(void *self, mal_actor_t *mal_actor) {
  printf("maltcp_submit_app_myconsumer_initialize()\n");

  int rc = 0;

  rc = mal_routing_register_consumer_submit_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER,
      maltcp_submit_app_myconsumer_testarea_testservice_testsubmitack);

  maltcp_submit_app_myconsumer_t *consumer = (maltcp_submit_app_myconsumer_t *) self;

  // initiate a SEND interaction
  mal_uri_t *provider_uri = consumer->provider_uri;

  printf("maltcp_submit_app_myconsumer: provider URI: %s\n", provider_uri);

  printf("maltcp_submit_app_myconsumer: new test composite\n");
  testarea_testservice_testcomposite_t *testcomposite =
      testarea_testservice_testcomposite_new();
  mal_string_t *str = mal_string_new("hello world");
  testarea_testservice_testcomposite_set_stringfield(testcomposite, str);
  testarea_testservice_testcomposite_intfield_set_present(testcomposite, true);
  testarea_testservice_testcomposite_set_intfield(testcomposite, 10);

  printf("maltcp_submit_app_myconsumer: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(2);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("list-element-1");
  string_list_content[1] = mal_string_new("list-element-2");

  printf("maltcp_submit_app_myconsumer: new test final composite A\n");
  testarea_testservice_testfinalcompositea_t *testfinalcompositea =
      testarea_testservice_testfinalcompositea_new();
  testarea_testservice_testfinalcompositea_set_intfield(testfinalcompositea,
      20);
  testarea_testservice_testfinalcompositea_set_intfield2(testfinalcompositea,
      30);

  unsigned int body_length = 0;
  printf("maltcp_submit_app_myconsumer: encoding_length_0\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_0(
      consumer->encoding_format_code, consumer->encoder, testcomposite,
      &body_length);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: encoding_length_1\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_1(
      consumer->encoding_format_code, consumer->encoder, string_list,
      &body_length);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: encoding_length_2\n");
  rc =
      testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(
          consumer->encoding_format_code, consumer->encoder,
          testfinalcompositea, &body_length);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: new MAL message\n");
  mal_message_t *message = mal_message_new(consumer->authentication_id,
      consumer->qoslevel, consumer->priority, consumer->domain,
      consumer->network_zone, consumer->session, consumer->session_name,
      body_length);

  unsigned int offset = mal_message_get_body_offset(message);
  char *bytes = mal_message_get_body(message);

  printf("maltcp_submit_app_myconsumer: encode 0\n");
  rc = testarea_testservice_testsend_send_encode_0(
      consumer->encoding_format_code, bytes, &offset,
      maltcp_submit_app_myconsumer_get_encoder(consumer), testcomposite);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: encode 1\n");
  rc = testarea_testservice_testsend_send_encode_1(
      consumer->encoding_format_code, bytes, &offset,
      maltcp_submit_app_myconsumer_get_encoder(consumer), string_list);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: encode 2\n");
  rc =
      testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(
          consumer->encoding_format_code, bytes, &offset,
          maltcp_submit_app_myconsumer_get_encoder(consumer), testfinalcompositea);
  if (rc < 0)
    return rc;

  printf("maltcp_submit_app_myconsumer: submit message\n");
  rc = testarea_testservice_testsubmit_submit(mal_actor_get_mal_endpoint(mal_actor), message,
      provider_uri);
  if (rc < 0)
    return rc;

  testarea_testservice_testcomposite_destroy(&testcomposite);
  mal_string_list_destroy(&string_list);
  testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);

  return rc;
}

int maltcp_submit_app_myconsumer_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  // ...
  return rc;
}

int maltcp_submit_app_myconsumer_testarea_testservice_testsubmitack(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

//  maltcp_submit_app_myconsumer_t *consumer = (maltcp_submit_app_myconsumer_t *) self;

  printf("#### maltcp_submit_app_myconsumer_testarea_testservice_testsubmitack: URI To=%s\n",
      mal_message_get_uri_to(message));

  printf("#### maltcp_submit_app_myconsumer, testsubmitack: %d, %d\n",
      mal_message_get_interaction_stage(message), mal_message_is_error_message(message));

  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Consumer done.\n");

  return rc;
}


int maltcp_submit_app_myconsumer_testarea_testservice_testsubmit(mal_uoctet_t interaction, bool iserror)  {
  printf("#### maltcp_submit_app_myconsumer, testsubmit: %d, %d\n", interaction, iserror);
  return 0;
}



void maltcp_submit_app_myconsumer_test(bool verbose) {
  printf(" * maltcp_submit_app_myconsumer_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
