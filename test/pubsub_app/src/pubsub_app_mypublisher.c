/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
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
#include "pubsub_app.h"

// state
struct _pubsub_app_mypublisher_t {
  mal_uri_t *broker_uri;
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

pubsub_app_mypublisher_t *pubsub_app_mypublisher_new(mal_uri_t *broker_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  pubsub_app_mypublisher_t *self = (pubsub_app_mypublisher_t *) malloc(
      sizeof(pubsub_app_mypublisher_t));
  if (!self)
    return NULL;

  self->broker_uri = broker_uri;
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

mal_uri_t *pubsub_app_mypublisher_get_broker_uri(pubsub_app_mypublisher_t *self) {
  return self->broker_uri;
}

mal_blob_t *pubsub_app_mypublisher_get_authentication_id(
    pubsub_app_mypublisher_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *pubsub_app_mypublisher_get_domain(
    pubsub_app_mypublisher_t *self) {
  return self->domain;
}

mal_identifier_t *pubsub_app_mypublisher_get_network_zone(
    pubsub_app_mypublisher_t *self) {
  return self->network_zone;
}

mal_uinteger_t pubsub_app_mypublisher_get_priority(
    pubsub_app_mypublisher_t *self) {
  return self->priority;
}

mal_qoslevel_t pubsub_app_mypublisher_get_qoslevel(
    pubsub_app_mypublisher_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t pubsub_app_mypublisher_get_session(
    pubsub_app_mypublisher_t *self) {
  return self->session;
}

mal_identifier_t *pubsub_app_mypublisher_get_session_name(
    pubsub_app_mypublisher_t *self) {
  return self->session_name;
}

int pubsub_app_mypublisher_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;

  zclock_sleep (1000);

  printf("### pubsub_app_myprovider_initialize\n");
  rc = mal_routing_register_provider_pubsub_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER,
      pubsub_app_mypublisher_on_publish_error,
      pubsub_app_mypublisher_on_publish_register_ack,
      pubsub_app_mypublisher_on_publish_deregister_ack);

  pubsub_app_mypublisher_t *publisher = (pubsub_app_mypublisher_t *) self;

  mal_uri_t *broker_uri = publisher->broker_uri;

  // initiate a PUBLISH REGISTER interaction PUBLISH
  mal_entitykey_list_t *entitykey_list = mal_entitykey_list_new(1);
  mal_entitykey_t **entitykey_list_content = mal_entitykey_list_get_content(
      entitykey_list);
  // TODO: add missing parameters in EntityKey constructor
  entitykey_list_content[0] = mal_entitykey_new();
  mal_identifier_t *firstkey = mal_identifier_new("A.2.3");
  printf("--initialize firstkey = %p, %s\n", firstkey, firstkey);//NTA tmp
  mal_entitykey_set_firstsubkey(entitykey_list_content[0], firstkey);

  void *cursor_pubreg = mal_encoder_new_cursor(publisher->encoder);

  rc = mal_publish_register_add_encoding_length_entitykey_list(
      publisher->encoder, entitykey_list, cursor_pubreg);
  if (rc < 0)
    return rc;

  mal_message_t *publish_register_message = mal_message_new(
      publisher->authentication_id, publisher->qoslevel, publisher->priority,
      publisher->domain, publisher->network_zone, publisher->session,
      publisher->session_name, mal_encoder_cursor_get_length(publisher->encoder, cursor_pubreg));

  mal_encoder_cursor_init(
      publisher->encoder, cursor_pubreg,
      mal_message_get_body(publish_register_message),
      mal_encoder_cursor_get_length(publisher->encoder, cursor_pubreg),
      mal_message_get_body_offset(publish_register_message));

  rc = mal_publish_register_encode_entitykey_list(
      cursor_pubreg, publisher->encoder,
      entitykey_list);
  mal_encoder_cursor_assert(publisher->encoder, cursor_pubreg);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(publisher->encoder, cursor_pubreg);

  printf("\n\n-------------------- PUBLISH_REGISTER -----------------\n\n");//NTA tmp

  mal_endpoint_t *mal_endpoint = mal_actor_get_mal_endpoint(mal_actor);

  // send publish_register
  rc = testarea_testservice_testmonitor_publish_register(mal_endpoint, publish_register_message, broker_uri);
  if (rc < 0)
    return rc;

  // Keep the Publish Register transaction id
  long initial_publish_register_tid = mal_message_get_transaction_id(publish_register_message);
  printf("Keep the Publish Register transaction id %ld\n", initial_publish_register_tid);

  mal_entitykey_list_destroy(&entitykey_list);

  return rc;
}

int pubsub_app_mypublisher_deregister(void *self) {
  int rc = 0;
  mal_endpoint_t *mal_endpoint = mal_actor_get_mal_endpoint(publisher_actor);
  pubsub_app_mypublisher_t *publisher = (pubsub_app_mypublisher_t *) self;
  mal_uri_t *broker_uri = publisher->broker_uri;

  printf("\n\n-------------------- PUBLISH_DEREGISTER -----------------\n\n");//NTA tmp

  // initiate a PUBLISH DEREGISTER interaction PUBLISH
  mal_entitykey_list_t *entitykey_list = mal_entitykey_list_new(1);
  mal_entitykey_t **entitykey_list_content = mal_entitykey_list_get_content(
      entitykey_list);
  // TODO: add missing parameters in EntityKey constructor
  entitykey_list_content[0] = mal_entitykey_new();
  mal_identifier_t *firstkey = mal_identifier_new("A.2.3");
  printf("--deregister firstkey = %p, %s\n", firstkey, firstkey);//NTA tmp
  mal_entitykey_set_firstsubkey(entitykey_list_content[0], firstkey);

  void *cursor_pubdereg = mal_encoder_new_cursor(publisher->encoder);

  rc = mal_publish_deregister_add_encoding_length_entitykey_list(
      publisher->encoder, entitykey_list, cursor_pubdereg);
  if (rc < 0)
    return rc;

  mal_message_t *publish_deregister_message = mal_message_new(
      publisher->authentication_id, publisher->qoslevel, publisher->priority,
      publisher->domain, publisher->network_zone, publisher->session,
      publisher->session_name, mal_encoder_cursor_get_length(publisher->encoder, cursor_pubdereg));

  mal_encoder_cursor_init(
      publisher->encoder, cursor_pubdereg,
      mal_message_get_body(publish_deregister_message),
      mal_encoder_cursor_get_length(publisher->encoder, cursor_pubdereg),
      mal_message_get_body_offset(publish_deregister_message));

  rc = mal_publish_deregister_encode_entitykey_list(
      cursor_pubdereg, publisher->encoder,
      entitykey_list);
  mal_encoder_cursor_assert(publisher->encoder, cursor_pubdereg);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(publisher->encoder, cursor_pubdereg);

  // send publish_deregister
  rc = testarea_testservice_testmonitor_publish_deregister(mal_endpoint, publish_deregister_message, broker_uri);
  if (rc < 0)
    return rc;

  return rc;
}

int pubsub_app_mypublisher_publish(void *self) {
  int rc = 0;
  mal_endpoint_t *mal_endpoint = mal_actor_get_mal_endpoint(publisher_actor);
  pubsub_app_mypublisher_t *publisher = (pubsub_app_mypublisher_t *) self;
  mal_uri_t *broker_uri = publisher->broker_uri;

  printf("\n\n-------------------- PUBLISH MSG -----------------\n\n");//NTA tmp

  // initiate a PUBLISH interaction
  mal_updateheader_list_t *updateheader_list = mal_updateheader_list_new(1);
  // TODO: add missing parameters in UpdateHeader constructor
  mal_updateheader_t *updateheader0 = mal_updateheader_new();

  mal_uri_t *src_uri = mal_uri_new(mal_endpoint_get_uri(mal_endpoint));
  mal_updateheader_set_sourceuri(updateheader0, src_uri);
  printf("== updateheader0->source_uri = %s\n", mal_updateheader_get_sourceuri(updateheader0));
  mal_updateheader_set_updatetype(updateheader0, MAL_UPDATETYPE_CREATION);
  mal_updateheader_set_timestamp(updateheader0, 0L);
  mal_entitykey_t *entitykey = mal_entitykey_new();
  mal_entitykey_set_firstsubkey(entitykey, mal_identifier_new("MY FirstSubkey"));
  mal_updateheader_set_key(updateheader0, entitykey);

  mal_updateheader_t **updateheader_list_content =
      mal_updateheader_list_get_content(updateheader_list);
  updateheader_list_content[0] = updateheader0;


  testarea_testservice_testupdate_list_t *testupdate_list =
      testarea_testservice_testupdate_list_new(1);
  testarea_testservice_testupdate_t *update =
      testarea_testservice_testupdate_new();
  testarea_testservice_testupdate_set_stringfield(update,
      mal_string_new("hello world !!!!"));
  testarea_testservice_testupdate_t **update_list_content =
      testarea_testservice_testupdate_list_get_content(testupdate_list);
  update_list_content[0] = update;

  void *cursor_pub = mal_encoder_new_cursor(publisher->encoder);

  rc = mal_publish_add_encoding_length_updateheader_list(
      publisher->encoder, updateheader_list, cursor_pub);
  if (rc < 0)
    return rc;

  rc = testarea_testservice_testmonitor_update_add_encoding_length_0(
      publisher->encoder, testupdate_list, cursor_pub);
  if (rc < 0)
    return rc;

  mal_message_t *publish_message = mal_message_new(publisher->authentication_id,
      publisher->qoslevel, publisher->priority, publisher->domain,
      publisher->network_zone, publisher->session, publisher->session_name,
      mal_encoder_cursor_get_length(publisher->encoder, cursor_pub));

  mal_encoder_cursor_init(
      publisher->encoder, cursor_pub,
      mal_message_get_body(publish_message),
      mal_encoder_cursor_get_length(publisher->encoder, cursor_pub),
      mal_message_get_body_offset(publish_message));

  rc = mal_publish_encode_updateheader_list(
      cursor_pub, publisher->encoder, updateheader_list);
  mal_encoder_cursor_assert(publisher->encoder, cursor_pub);
  if (rc < 0)
    return rc;

  rc = testarea_testservice_testmonitor_update_encode_0(
      cursor_pub, publisher->encoder, testupdate_list);
  mal_encoder_cursor_assert(publisher->encoder, cursor_pub);
  if (rc < 0)
    return rc;

  mal_encoder_cursor_destroy(publisher->encoder, cursor_pub);

  // Keep the Publish Register transaction id
  long initial_publish_register_tid = mal_message_get_transaction_id(publish_message);

  //Publish
  rc = testarea_testservice_testmonitor_publish(mal_actor_get_mal_endpoint(publisher_actor),
      publish_message, broker_uri, initial_publish_register_tid);
  if (rc < 0)
    return rc;

  mal_updateheader_list_destroy(&updateheader_list);
  testarea_testservice_testupdate_list_destroy(&testupdate_list);

  // Deregister
  zclock_sleep (1000);
  pubsub_app_mypublisher_deregister(self);

  return rc;
}

int pubsub_app_mypublisher_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  // ...
  printf("publisher ended\n");
  return rc;
}

int pubsub_app_mypublisher_on_publish_error(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  printf("Provider testpublish_publish_error ERROR !!\n");
  return rc;
}

int pubsub_app_mypublisher_on_publish_register_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("Provider testpublish_register_ack done.\n");

  printf("\n\n-------------------- PUBLISH_REGISTER_ACK -----------------\n\n");//NTA tmp

  rc = pubsub_app_mypublisher_publish(self);

  return rc;
}

int pubsub_app_mypublisher_on_publish_deregister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  printf("\n\n-------------------- PUBLISH_DEREGISTER_ACK -----------------\n\n");//NTA tmp

  mal_actor_term(broker_actor);
  mal_actor_term(publisher_actor);

  return rc;
}

int pubsub_app_mypublisher_testarea_testservice_testpubsub(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  printf("Provider done.\n");
  return rc;
}

void pubsub_app_mypublisher_test(bool verbose) {
  printf(" * pubsub_app_mypublisher_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
