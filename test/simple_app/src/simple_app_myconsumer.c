/* */
#include "simple_app.h"

// state
struct _simple_app_myconsumer_t {
  mal_endpoint_t *endpoint;
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

simple_app_myconsumer_t *simple_app_myconsumer_new(
    mal_endpoint_t *endpoint,
    mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, int encoding_format_code, void *encoder,
    void *decoder) {
  simple_app_myconsumer_t *self = (simple_app_myconsumer_t *) malloc(
      sizeof(simple_app_myconsumer_t));
  if (!self)
    return NULL;

  self->endpoint = endpoint;
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

int simple_app_myconsumer_get_encoding_format_code(
    simple_app_myconsumer_t *self) {
  return self->encoding_format_code;
}

void *simple_app_myconsumer_get_encoder(simple_app_myconsumer_t *self) {
  return self->encoder;
}

void *simple_app_myconsumer_get_decoder(simple_app_myconsumer_t *self) {
  return self->decoder;
}

mal_uri_t *simple_app_myconsumer_get_provider_uri(simple_app_myconsumer_t *self) {
  return self->provider_uri;
}

mal_blob_t *simple_app_myconsumer_get_authentication_id(
    simple_app_myconsumer_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *simple_app_myconsumer_get_domain(
    simple_app_myconsumer_t *self) {
  return self->domain;
}

mal_identifier_t *simple_app_myconsumer_get_network_zone(
    simple_app_myconsumer_t *self) {
  return self->network_zone;
}

mal_uinteger_t simple_app_myconsumer_get_priority(simple_app_myconsumer_t *self) {
  return self->priority;
}

mal_qoslevel_t simple_app_myconsumer_get_qoslevel(simple_app_myconsumer_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t simple_app_myconsumer_get_session(
    simple_app_myconsumer_t *self) {
  return self->session;
}

mal_identifier_t *simple_app_myconsumer_get_session_name(
    simple_app_myconsumer_t *self) {
  return self->session_name;
}

void simple_app_myconsumer_run(zsock_t *pipe, void *self) {
  simple_app_myconsumer_t *consumer = (simple_app_myconsumer_t *) self;

  //  Signal successful initialization
  zsock_signal(pipe, 0);

  printf("simple_app_myconsumer_run()\n");

  int rc = 0;

  // initiate a SEND interaction
  printf("simple_app_myconsumer: provider URI: %s\n", consumer->provider_uri);

  printf("simple_app_myconsumer: new test composite\n");
  testarea_testservice_testcomposite_t *testcomposite =
      testarea_testservice_testcomposite_new();
  mal_string_t *str = mal_string_new("hello world");
  testarea_testservice_testcomposite_set_stringfield(testcomposite, str);
  testarea_testservice_testcomposite_intfield_set_present(testcomposite, true);
  testarea_testservice_testcomposite_set_intfield(testcomposite, 10);

  printf("simple_app_myconsumer: new string list\n");
  mal_string_list_t *string_list = mal_string_list_new(2);
  mal_string_t **string_list_content = mal_string_list_get_content(string_list);
  string_list_content[0] = mal_string_new("list-element-1");
  string_list_content[1] = mal_string_new("list-element-2");

  printf("simple_app_myconsumer: new test final composite A\n");
  testarea_testservice_testfinalcompositea_t *testfinalcompositea =
      testarea_testservice_testfinalcompositea_new();
  testarea_testservice_testfinalcompositea_set_intfield(testfinalcompositea, 20);
  testarea_testservice_testfinalcompositea_set_intfield2(testfinalcompositea, 30);

  // TODO (AF): Use virtual allocation and initialization functions from encoder.
  malbinary_cursor_t cursor;
  malbinary_cursor_reset(&cursor);

  printf("simple_app_myconsumer: encoding_length_0\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_0(
      consumer->encoding_format_code, consumer->encoder, testcomposite, &cursor);
  if (rc < 0) {
    printf("ERROR during encoding_length\n");
    return;
  }

  printf("simple_app_myconsumer: encoding_length_1\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_1(
      consumer->encoding_format_code, consumer->encoder, string_list, &cursor);
  if (rc < 0) {
    printf("ERROR during encoding_length\n");
    return;
  }

  printf("simple_app_myconsumer: encoding_length_2\n");
  rc = testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(
          consumer->encoding_format_code, consumer->encoder,
          testfinalcompositea, &cursor);
  if (rc < 0) {
    printf("ERROR during encoding_length\n");
    return;
  }

  printf("simple_app_myconsumer: new MAL message\n");
  mal_message_t *message = mal_message_new(consumer->authentication_id,
      consumer->qoslevel, consumer->priority, consumer->domain,
      consumer->network_zone, consumer->session, consumer->session_name,
      malbinary_cursor_get_body_length(&cursor));

  // TODO (AF): Use a virtual function
  cursor.body_ptr = mal_message_get_body(message);
  cursor.body_offset = mal_message_get_body_offset(message);

  printf("simple_app_myconsumer: encode 0\n");
  rc = testarea_testservice_testsend_send_encode_0(
      consumer->encoding_format_code, &cursor,
      simple_app_myconsumer_get_encoder(consumer), testcomposite);
  malbinary_cursor_assert(&cursor);
  if (rc < 0) {
    printf("ERROR during encoding\n");
    return;
  }

  printf("simple_app_myconsumer: encode 1\n");
  rc = testarea_testservice_testsend_send_encode_1(
      consumer->encoding_format_code, &cursor,
      simple_app_myconsumer_get_encoder(consumer), string_list);
  malbinary_cursor_assert(&cursor);
  if (rc < 0) {
    printf("ERROR during encoding\n");
    return;
  }

  printf("simple_app_myconsumer: encode 2\n");
  rc = testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(
          consumer->encoding_format_code, &cursor,
          simple_app_myconsumer_get_encoder(consumer), testfinalcompositea);
  malbinary_cursor_assert(&cursor);
  if (rc < 0) {
    printf("ERROR during encoding\n");
    return;
  }

  printf("simple_app_myconsumer: send message\n");
  rc = testarea_testservice_testsend_send(consumer->endpoint, message, consumer->provider_uri);
  if (rc < 0) {
    printf("ERROR during sending\n");
    return;
  }

  testarea_testservice_testcomposite_destroy(&testcomposite);
  mal_string_list_destroy(&string_list);
  testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
}

void simple_app_myconsumer_test(bool verbose) {
  printf(" * simple_app_myconsumer_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
