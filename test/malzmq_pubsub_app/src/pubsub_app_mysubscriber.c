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
#include "../../malzmq_pubsub_app/include/pubsub_app.h"

// state
struct _pubsub_app_mysubscriber_t {
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

pubsub_app_mysubscriber_t *pubsub_app_mysubscriber_new(mal_uri_t *broker_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder) {
  pubsub_app_mysubscriber_t *self = (pubsub_app_mysubscriber_t *) malloc(
      sizeof(pubsub_app_mysubscriber_t));
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

mal_uri_t *pubsub_app_mysubscriber_get_broker_uri(
    pubsub_app_mysubscriber_t *self) {
  return self->broker_uri;
}

mal_blob_t *pubsub_app_mysubscriber_get_authentication_id(
    pubsub_app_mysubscriber_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *pubsub_app_mysubscriber_get_domain(
    pubsub_app_mysubscriber_t *self) {
  return self->domain;
}

mal_identifier_t *pubsub_app_mysubscriber_get_network_zone(
    pubsub_app_mysubscriber_t *self) {
  return self->network_zone;
}

mal_uinteger_t pubsub_app_mysubscriber_get_priority(
    pubsub_app_mysubscriber_t *self) {
  return self->priority;
}

mal_qoslevel_t pubsub_app_mysubscriber_get_qoslevel(
    pubsub_app_mysubscriber_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t pubsub_app_mysubscriber_get_session(
    pubsub_app_mysubscriber_t *self) {
  return self->session;
}

mal_identifier_t *pubsub_app_mysubscriber_get_session_name(
    pubsub_app_mysubscriber_t *self) {
  return self->session_name;
}

int pubsub_app_mysubscriber_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;

  printf("### pubsub_app_mysubscriber_initialize\n");
  rc = mal_routing_register_consumer_pubsub_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER,
      pubsub_app_mysubscriber_testregister_ack,
      pubsub_app_mysubscriber_testderegister_ack,
      pubsub_app_mysubscriber_testnotify);

  pubsub_app_mysubscriber_t *subscriber = (pubsub_app_mysubscriber_t *) self;

  // initiate a SUBSCRIBE interaction
  mal_uri_t *broker_uri = subscriber->broker_uri;

  mal_subscription_t *subscription = mal_subscription_new();
  mal_identifier_t *subscriptionid = mal_identifier_new("test-sub");
  mal_subscription_set_subscriptionid(subscription, subscriptionid);
  mal_entityrequest_list_t *entities = mal_entityrequest_list_new(0);
  // TODO: add some EntityRequests
  /* 
  mal_entityrequest_t *entityrequest = mal_entityrequest_new();
  mal_identifier_list_t *identifiers = mal_identifier_list_new(1);
  mal_identifier_t **identifiers_content = mal_identifier_list_get_content(identifiers);
  identifiers_content[0] = mal_identifier_new("A.B.C");
  entityrequest->subdomain = identifiers;
  mal_entityrequest_t **entityrequest_content = mal_entityrequest_list_get_content(entities);
  entityrequest_content[0] = entityrequest;
  mal_identifier_list_print(identifiers);
  */
  mal_subscription_set_entities(subscription, entities);

  void *register_cursor = mal_encoder_new_cursor(subscriber->encoder);

  rc = mal_register_add_encoding_length(
      subscriber->encoder, subscription, register_cursor);
  if (rc < 0)
    return rc;

  mal_message_t *register_message = mal_message_new(
      subscriber->authentication_id, subscriber->qoslevel, subscriber->priority,
      subscriber->domain, subscriber->network_zone, subscriber->session,
      subscriber->session_name, mal_encoder_cursor_get_length(subscriber->encoder, register_cursor));

  mal_encoder_cursor_init(
      subscriber->encoder, register_cursor,
      mal_message_get_body(register_message),
      mal_encoder_cursor_get_length(subscriber->encoder, register_cursor),
      mal_message_get_body_offset(register_message));

  rc = mal_register_encode(register_cursor, subscriber->encoder, subscription);
  assert(rc == 0);

  mal_encoder_cursor_destroy(subscriber->encoder, register_cursor);

  printf("=== register send... %s\n", broker_uri);
  rc = testarea_testservice_testmonitor_register(mal_actor_get_mal_endpoint(mal_actor),
      register_message, broker_uri);
  if (rc < 0)
    return rc;

  mal_subscription_destroy(&subscription);

  return rc;
}

int pubsub_app_mysubscriber_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  // ...
  mal_ctx_t *mal_ctx = mal_actor_get_mal_ctx(mal_actor);
  mal_ctx_stop(mal_ctx);
  return rc;
}

int pubsub_app_mysubscriber_testregister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("******** pubsub_app_mysubscriber_register_ack\n");
  return rc;
}

int pubsub_app_mysubscriber_testderegister_ack(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  // Note: Never called!!
  int rc = 0;
  printf("******** pubsub_app_mysubscriber_deregister_ack\n");
  return rc;
}

int pubsub_app_mysubscriber_testnotify(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  pubsub_app_mysubscriber_t *subscriber = (pubsub_app_mysubscriber_t *) self;

  printf("#### pubsub_app_mysubscriber_testnotify: %d, %d\n",
      mal_message_get_interaction_stage(message),
      mal_message_is_error_message(message));

  void *cursor = mal_decoder_new_cursor(
      subscriber->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  /*
  mal_identifier_t *subscriptionid;
  rc = mal_notify_decode_subscriptionid(subscriber->encoding_format_code, bytes,
      &offset, subscriber->decoder, &subscriptionid);
  if (rc < 0)
    return rc;
  */

  mal_updateheader_list_t *updateheader_list;
  rc = mal_publish_decode_updateheader_list(
      cursor, subscriber->decoder, &updateheader_list);
  mal_decoder_cursor_assert(subscriber->decoder, cursor);
  if (rc < 0)
    return rc;

  unsigned int uh_count = mal_updateheader_list_get_element_count(updateheader_list);
  printf("== updateheader_list \n\tcount = %d\n", uh_count);
  assert(uh_count > 0);
  mal_updateheader_t **updateheaders = mal_updateheader_list_get_content(updateheader_list);
  printf("\tsrc_uri = %s\n", mal_updateheader_get_sourceuri(updateheaders[uh_count-1]));
  printf("\tfirstsubkey = %s\n\n", mal_entitykey_get_firstsubkey(mal_updateheader_get_key(updateheaders[uh_count-1])));

  printf("== testupdate_list\n");
  testarea_testservice_testupdate_list_t *parameter_0;
  rc = testarea_testservice_testmonitor_update_decode_0(
      cursor, subscriber->decoder, &parameter_0);
  mal_decoder_cursor_assert(subscriber->decoder, cursor);
  assert(rc == 0);

  mal_decoder_cursor_destroy(subscriber->decoder, cursor);

  // process the update list
  unsigned int count = testarea_testservice_testupdate_list_get_element_count(parameter_0);
  printf("\tcount = %d\n", count);

  testarea_testservice_testupdate_t ** content_list = testarea_testservice_testupdate_list_get_content(parameter_0);
  mal_string_t *string = testarea_testservice_testupdate_get_stringfield(content_list[0]);
  printf("\tcontent_0 = %s\n\n", string);

  /*
  mal_identifier_destroy(&subscriptionid);
  */
  mal_updateheader_list_destroy(&updateheader_list);
  printf("destroy parameter_0\n");
  testarea_testservice_testupdate_list_destroy(&parameter_0);
  printf("destroy MAL result message\n");
  mal_message_destroy(&message, mal_ctx);

  printf("Subscriber done.\n");

  // Wait for actor's completion
  zclock_sleep(1000);

  mal_actor_term(broker_actor);
  mal_actor_join(broker_actor);
  mal_actor_term(publisher_actor);
  mal_actor_join(publisher_actor);
  mal_actor_term(subscriber_actor);

  return rc;
}

void pubsub_app_mysubscriber_test(bool verbose) {
  printf(" * pubsub_app_mysubscriber_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
