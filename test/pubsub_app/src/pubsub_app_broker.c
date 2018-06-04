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

#define MAX_SUBSCRIBER 10

// state
struct _pubsub_app_broker_t {
  mal_uri_t *provider_uri;
  mal_blob_t *authentication_id;
  mal_qoslevel_t qoslevel;
  mal_uinteger_t priority;
  mal_identifier_list_t *domain;
  mal_identifier_t *network_zone;
  mal_sessiontype_t session;
  mal_identifier_t *session_name;
  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  pubsub_subscriber_t **subscribers;
  //TODO: pubsub_publisher_t **publishers;
};

struct _pubsub_subscriber_t {
  mal_identifier_t *subscriptionid ;
  mal_subscription_t *mal_subscription;
  mal_uri_t *consumer_uri;
};

pubsub_app_broker_t *pubsub_app_broker_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name, mal_encoder_t *encoder, mal_decoder_t *decoder) {

  pubsub_app_broker_t *self = (pubsub_app_broker_t *) malloc(sizeof(pubsub_app_broker_t));
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
  self->encoder = encoder;
  self->decoder = decoder;
  //TODO: Implements an hashtable
  self->subscribers = (pubsub_subscriber_t **) calloc(MAX_SUBSCRIBER, sizeof(pubsub_subscriber_t *));
  return self;
}

/**
 * Getter / Setter
 */

mal_uri_t *pubsub_app_broker_get_provider_uri(
    pubsub_app_broker_t *self) {
  return self->provider_uri;
}

mal_blob_t *pubsub_app_broker_get_authentication_id(
    pubsub_app_broker_t *self) {
  return self->authentication_id;
}

mal_identifier_list_t *pubsub_app_broker_get_domain(
    pubsub_app_broker_t *self) {
  return self->domain;
}

mal_identifier_t *pubsub_app_broker_get_network_zone(
    pubsub_app_broker_t *self) {
  return self->network_zone;
}

mal_uinteger_t pubsub_app_broker_get_priority(
    pubsub_app_broker_t *self) {
  return self->priority;
}

mal_qoslevel_t pubsub_app_broker_get_qoslevel(
    pubsub_app_broker_t *self) {
  return self->qoslevel;
}

mal_sessiontype_t pubsub_app_broker_get_session(
    pubsub_app_broker_t *self) {
  return self->session;
}

mal_identifier_t *pubsub_app_broker_get_session_name(
    pubsub_app_broker_t *self) {
  return self->session_name;
}

/**
 * Initialization: register the broker handler.
 */
int pubsub_app_broker_initialize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;

  printf("### pubsub_app_broker_initialize\n");
  rc = mal_routing_register_broker_pubsub_handler(
      mal_actor_get_router(mal_actor),
      TESTAREA_AREA_NUMBER,
      TESTAREA_AREA_VERSION,
      TESTAREA_TESTSERVICE_SERVICE_NUMBER,
      TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER,
      pubsub_app_broker_on_notify_error,
      pubsub_app_broker_on_register,
      pubsub_app_broker_on_deregister,
      pubsub_app_broker_on_publish,
      pubsub_app_broker_on_publish_register,
      pubsub_app_broker_on_publish_deregister);
  assert(rc == 0);

  return rc;
}

int pubsub_app_broker_finalize(void *self, mal_actor_t *mal_actor) {
  int rc = 0;
  // TODO: unregister, ...
  printf("broker ended\n");
  return rc;
}

/**
 * This code below implements the handling of subscriptions.
 */

int get_subscriber_idx(pubsub_app_broker_t *broker, mal_uri_t * consumer_uri) {
  int i = 0;
  while (i < MAX_SUBSCRIBER) {
    if (broker->subscribers[i] &&
        strcmp(broker->subscribers[i]->consumer_uri, consumer_uri) == 0) {
      return i;
    }
    i++;
  }
  return 0;
}

int add_subscriber(pubsub_app_broker_t *broker,
    mal_identifier_t *subscriptionid,
    mal_uri_t *consumer_uri,
    mal_subscription_t *mal_subscription) {
  printf("add_subscriber: consumer_uri = %s, subId = %s\n", consumer_uri, subscriptionid);
  int i = get_subscriber_idx(broker, consumer_uri);
  if (i > 0) {
    // update
    broker->subscribers[i]->consumer_uri = consumer_uri;
    broker->subscribers[i]->subscriptionid = subscriptionid;
    broker->subscribers[i]->mal_subscription = mal_subscription;
    return 0;
  }
  while (i < MAX_SUBSCRIBER && broker->subscribers[i]) {
    i++;
  }
  if (i < MAX_SUBSCRIBER) {
    pubsub_subscriber_t *self = (pubsub_subscriber_t *) malloc(sizeof(pubsub_subscriber_t));
    self->consumer_uri = consumer_uri;
    self->subscriptionid = subscriptionid;
    self->mal_subscription = mal_subscription;
    broker->subscribers[i] = self;
    printf("add_subscriber: uri = %s, subId = %s\n", broker->subscribers[i]->consumer_uri, broker->subscribers[i]->subscriptionid);
  } else {
    return -1;
  }
  return 0;
}

int remove_subscriber(pubsub_app_broker_t *broker, mal_identifier_t *subscriptionid, mal_uri_t *consumer_uri) {
  printf("remove_subscriber: subId = %s\n", subscriptionid);
  int i = 0;
  while (i < MAX_SUBSCRIBER) {
    if (broker->subscribers[i] &&
        strcmp(broker->subscribers[i]->consumer_uri, consumer_uri) == 0 &&
        strcmp(broker->subscribers[i]->subscriptionid, subscriptionid) ==0) {
      // remove
      printf("remove_subscriber: uri = %s, subId = %s\n", broker->subscribers[i]->consumer_uri, broker->subscribers[i]->subscriptionid);
      free(broker->subscribers[i]);
      broker->subscribers[i] = NULL;
    }
    i++;
  }
  return 0;
}

/**
 * This code implements the reaction to a NOTIFY_ERROR message.
 */
int pubsub_app_broker_on_notify_error(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("Provider broker_notify_error ERROR !!\n");
  return rc;
}

/**
 * This code below allows to send a REGISTER_ACK message to the subscriber.
 * It should be shared between all broker implementations.
 */
int pubsub_app_register_ack(mal_endpoint_t *mal_endpoint,
    mal_message_t *init_message, mal_message_t *result_message, bool is_error_message) {
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_REGISTER_ACK);
  rc = mal_endpoint_return_operation(mal_endpoint, init_message, result_message, is_error_message);
  return rc;
}

/**
 * This code below allows to send a DEREGISTER_ACK message to the subscriber.
 * It should be shared between all broker implementations.
 */
int pubsub_app_deregister_ack(mal_endpoint_t *mal_endpoint,
    mal_message_t *init_message, mal_message_t *result_message, bool is_error_message) {
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK);
  rc = mal_endpoint_return_operation(mal_endpoint, init_message, result_message, is_error_message);
  return rc;
}

/**
 * This code below allows to send a PUBLISH_REGISTER_ACK message to the publisher.
 * It should be shared between all broker implementations.
 */
int pubsub_app_publish_register_ack(mal_endpoint_t *mal_endpoint,
    mal_message_t *init_message, mal_message_t *result_message, bool is_error_message) {
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK);
  rc = mal_endpoint_return_operation(mal_endpoint, init_message, result_message, is_error_message);
  return rc;
}

/**
 * This code below allows to send a PUBLISH_DEREGISTER_ACK message to the publisher.
 * It should be shared between all broker implementations.
 */
int pubsub_app_publish_deregister_ack(mal_endpoint_t *mal_endpoint,
    mal_message_t *init_message, mal_message_t *result_message, bool is_error_message) {
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK);
  rc = mal_endpoint_return_operation(mal_endpoint, init_message, result_message, is_error_message);
  return rc;
}

/**
 * This code below allows to send a NOTIFY message to a subscriber.
 * It should be shared between all broker implementations.
 */
int pubsub_app_notify(mal_endpoint_t *mal_endpoint, mal_message_t * message,
    mal_uri_t * consumer_uri, long initial_publish_register_tid) {
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_NOTIFY);
  mal_message_set_transaction_id(message, initial_publish_register_tid);
  rc = mal_endpoint_init_operation(mal_endpoint, message, consumer_uri, false);
  return rc;
}

/**
 * This code below allows to notify each subscriber.
 * It should be shared between all broker implementations.
 */
int pubsub_app_consumer_notify(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("pubsub_app_consumer_notify\n");

  pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

  long initial_publish_register_tid = mal_message_get_transaction_id(message);

  if (broker->subscribers) {
    for (int i = 0; i < MAX_SUBSCRIBER; i++) {
      if (broker->subscribers[i]) {
        mal_uri_t *consumer_uri = broker->subscribers[i]->consumer_uri;
        rc = pubsub_app_notify(mal_endpoint, message, consumer_uri, initial_publish_register_tid);
      }
    }
  }
  assert(rc == 0);
  return rc;
}

/**
 * This code implements the reaction to a PUBLISH message.
 */
int pubsub_app_broker_on_publish(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;

  printf("\n### on_publish callback \n");

  //pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

  //unsigned int offset = mal_message_get_body_offset(message);
  //char *bytes = mal_message_get_body(message);

  mal_uri_t *from = mal_message_get_uri_from(message);
  printf("\tfrom = %s\n", from);
  mal_uri_t *to = mal_message_get_uri_to(message);
    printf("\tto = %s\n", to);

  mal_uoctet_t stage = mal_message_get_interaction_stage(message);
  printf("\tstage = %d\n", stage);

  pubsub_app_consumer_notify(self, mal_ctx, mal_endpoint, message);

  /*
  mal_identifier_t *subscriptionid;
  rc = mal_notify_decode_subscriptionid(subscriber->encoding_format_code, bytes,
      &offset, subscriber->decoder, &subscriptionid);
  if (rc < 0)
    return rc;

  mal_updateheader_list_t *updateheader_list;
  rc = mal_publish_decode_updateheader_list(subscriber->encoding_format_code,
      bytes, &offset, subscriber->decoder, &updateheader_list);
  if (rc < 0)
    return rc;

  testarea_testservice_testupdate_list_t *update_list_0;
  rc = testarea_testservice_testmonitor_update_decode_0(
      subscriber->encoding_format_code, bytes, &offset, subscriber->decoder,
      &update_list_0);
  if (rc < 0)
    return rc;

  // process the update list
  // ...

  mal_identifier_destroy(&subscriptionid);
  mal_updateheader_list_destroy(&updateheader_list);
  testarea_testservice_testupdate_list_destroy(&update_list_0);
*/
  return rc;
}

/**
 * This code implements the reaction to a REGISTER message.
 */
int pubsub_app_broker_on_register(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("==== pubsub_app_broker_on_register\n");
  pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

  // Get response parameter.

  void *cursor = mal_decoder_new_cursor(
      broker->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("pubsub_app_broker_on_register: offset=%d\n", mal_message_get_body_offset(message));

  mal_subscription_t *mal_subscription = mal_subscription_new();
  rc = mal_register_decode(cursor, broker->decoder, &mal_subscription);
  mal_decoder_cursor_assert(broker->decoder, cursor);
  assert(rc == 0);

  mal_decoder_cursor_destroy(broker->decoder, cursor);

  mal_identifier_t *subscriptionid = mal_subscription_get_subscriptionid(mal_subscription);
  assert(subscriptionid);

  mal_uri_t *consumer_uri = mal_message_get_uri_from(message);
  rc = add_subscriber(broker, subscriptionid, consumer_uri, mal_subscription);
  assert(rc == 0);

  printf("pubsub_app_broker_on_register: subscriptionid=%s\n", subscriptionid);

  // Send ack to consumer
   mal_message_t *ack_message = mal_message_new(
       broker->authentication_id,
       broker->qoslevel,
       broker->priority,
       broker->domain,
       broker->network_zone,
       broker->session,
       broker->session_name,
       0);
   mal_message_set_body(ack_message, NULL);
   mal_message_set_body_length(ack_message, 0);
   rc = pubsub_app_register_ack(mal_endpoint, message, ack_message, false);
   printf("destroy MAL result message\n");
   mal_message_destroy(&ack_message, mal_ctx);

  return rc;
}

/**
 * This code implements the reaction to a DEREGISTER message.
 */
int pubsub_app_broker_on_deregister(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("pubsub_app_broker_on_deregister\n");
   pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

   // Get response parameter.

   void *cursor = mal_decoder_new_cursor(
       broker->decoder,
       mal_message_get_body(message),
       mal_message_get_body_offset(message) + mal_message_get_body_length(message),
       mal_message_get_body_offset(message));

   printf("pubsub_app_broker_on_deregister: offset=%d\n", mal_message_get_body_offset(message));

   mal_identifier_list_t *subscription_list;
   rc = mal_deregister_decode(cursor, broker->decoder, &subscription_list);
   mal_decoder_cursor_assert(broker->decoder, cursor);
   assert(rc == 0);
   mal_decoder_cursor_destroy(broker->decoder, cursor);

   mal_identifier_t *subscriptionid = *mal_identifier_list_get_content(subscription_list);
   assert(subscriptionid);

   mal_uri_t *consumer_uri = mal_message_get_uri_from(message);
   rc = remove_subscriber(broker, subscriptionid, consumer_uri);
   assert(rc == 0);

   // Send ack to consumer
   mal_message_t *ack_message = mal_message_new(
       broker->authentication_id,
       broker->qoslevel,
       broker->priority,
       broker->domain,
       broker->network_zone,
       broker->session,
       broker->session_name,
       0);
   mal_message_set_body(ack_message, NULL);
   mal_message_set_body_length(ack_message, 0);
   rc = pubsub_app_deregister_ack(mal_endpoint, message, ack_message, false);
   printf("destroy MAL result message\n");
   mal_message_destroy(&ack_message, mal_ctx);

   return rc;
}

/**
 * This code implements the reaction to a PUBLISH_REGISTER message.
 */
int pubsub_app_broker_on_publish_register(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("==== pubsub_app_broker_on_publish_register\n");
  pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

  // Get response parameter.
  void *cursor = mal_decoder_new_cursor(
      broker->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("pubsub_app_broker_on_publish_register: offset=%d\n", mal_message_get_body_offset(message));

  mal_entitykey_list_t *entitykey_list = mal_entitykey_list_new(1);
  mal_publish_decode_entitykey_list(cursor, broker->decoder, &entitykey_list);

  mal_entitykey_t **entitykey_list_content = mal_entitykey_list_get_content(entitykey_list);
  printf("mal_entitykey_get_firstsubkey = %s\n", mal_entitykey_get_firstsubkey(entitykey_list_content[0]));
  mal_decoder_cursor_assert(broker->decoder, cursor);
  assert(rc == 0);

  mal_decoder_cursor_destroy(broker->decoder, cursor);

  //TODO add entitykey to the publishers table

  // Send ack to publisher
  mal_message_t *ack_message = mal_message_new(
      broker->authentication_id,
      broker->qoslevel,
      broker->priority,
      broker->domain,
      broker->network_zone,
      broker->session,
      broker->session_name,
      0);
  mal_message_set_body(ack_message, NULL);
  mal_message_set_body_length(ack_message, 0);
  rc = pubsub_app_publish_register_ack(mal_endpoint, message, ack_message, false);
  printf("destroy MAL result message\n");
  mal_message_destroy(&ack_message, mal_ctx);

  return rc;
}

/**
 * This code implements the reaction to a PUBLISH_DEREGISTER message.
 */
int pubsub_app_broker_on_publish_deregister(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message) {
  int rc = 0;
  printf("==== pubsub_app_broker_on_publish_deregister\n");
  pubsub_app_broker_t *broker = (pubsub_app_broker_t *) self;

  // Get response parameter.
  void *cursor = mal_decoder_new_cursor(
      broker->decoder,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));

  printf("pubsub_app_broker_on_publish_deregister: offset=%d\n", mal_message_get_body_offset(message));

  mal_entitykey_list_t *entitykey_list = mal_entitykey_list_new(1);
  mal_publish_decode_entitykey_list(cursor, broker->decoder, &entitykey_list);

  mal_entitykey_t **entitykey_list_content = mal_entitykey_list_get_content(entitykey_list);
  printf("mal_entitykey_get_firstsubkey = %s\n", mal_entitykey_get_firstsubkey(entitykey_list_content[0]));
  mal_decoder_cursor_assert(broker->decoder, cursor);
  assert(rc == 0);

  //TODO remove publishers

  mal_decoder_cursor_destroy(broker->decoder, cursor);

  // Send ack to publisher
  mal_message_t *ack_message = mal_message_new(
      broker->authentication_id,
      broker->qoslevel,
      broker->priority,
      broker->domain,
      broker->network_zone,
      broker->session,
      broker->session_name,
      0);
  mal_message_set_body(ack_message, NULL);
  mal_message_set_body_length(ack_message, 0);
  rc = pubsub_app_publish_deregister_ack(mal_endpoint, message, ack_message, false);
  printf("destroy MAL result message\n");
  mal_message_destroy(&ack_message, mal_ctx);

  return rc;
}

void pubsub_app_broker_test(bool verbose) {
  printf(" * pubsub_app_broker_test: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
