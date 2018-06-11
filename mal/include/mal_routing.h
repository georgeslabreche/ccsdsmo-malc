/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
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

#ifndef MAL_INCLUDE_MAL_ROUTING_H_
#define MAL_INCLUDE_MAL_ROUTING_H_


#ifdef __cplusplus
extern "C" {
#endif

mal_routing_t *mal_routing_new(mal_endpoint_t *mal_endpoint, void *state);

void mal_routing_destroy(mal_routing_t **self_p);

void *mal_routing_get_state(mal_routing_t *self);

int mal_routing_handle(mal_routing_t *self, mal_message_t *message);

typedef int mal_routing_on_message_fn(void *self, mal_ctx_t *mal_ctx, mal_endpoint_t *mal_endpoint, mal_message_t *message);

//typedef struct _mal_routing_consumer_send_handler_t mal_routing_consumer_send_handler_t;
typedef struct _mal_routing_provider_send_handler_t mal_routing_provider_send_handler_t;
typedef struct _mal_routing_consumer_submit_handler_t mal_routing_consumer_submit_handler_t;
typedef struct _mal_routing_provider_submit_handler_t mal_routing_provider_submit_handler_t;
typedef struct _mal_routing_consumer_request_handler_t mal_routing_consumer_request_handler_t;
typedef struct _mal_routing_provider_request_handler_t mal_routing_provider_request_handler_t;
typedef struct _mal_routing_consumer_invoke_handler_t mal_routing_consumer_invoke_handler_t;
typedef struct _mal_routing_provider_invoke_handler_t mal_routing_provider_invoke_handler_t;
typedef struct _mal_routing_consumer_progress_handler_t mal_routing_consumer_progress_handler_t;
typedef struct _mal_routing_provider_progress_handler_t mal_routing_provider_progress_handler_t;
typedef struct _mal_routing_consumer_pubsub_handler_t mal_routing_consumer_pubsub_handler_t;
typedef struct _mal_routing_provider_pubsub_handler_t mal_routing_provider_pubsub_handler_t;
typedef struct _mal_routing_broker_pubsub_handler_t mal_routing_broker_pubsub_handler_t;

enum _handler_type_t {
  MAL_ACTOR_PROVIDER_SEND_HANDLER,
  MAL_ACTOR_PROVIDER_SUBMIT_HANDLER,
  MAL_ACTOR_PROVIDER_REQUEST_HANDLER,
  MAL_ACTOR_PROVIDER_INVOKE_HANDLER,
  MAL_ACTOR_PROVIDER_PROGRESS_HANDLER,
  MAL_ACTOR_PROVIDER_PUBSUB_HANDLER,
  MAL_ACTOR_CONSUMER_SEND_HANDLER,
  MAL_ACTOR_CONSUMER_SUBMIT_HANDLER,
  MAL_ACTOR_CONSUMER_REQUEST_HANDLER,
  MAL_ACTOR_CONSUMER_INVOKE_HANDLER,
  MAL_ACTOR_CONSUMER_PROGRESS_HANDLER,
  MAL_ACTOR_CONSUMER_PUBSUB_HANDLER,
  MAL_ACTOR_BROKER_PUBSUB_HANDLER
};

typedef enum _handler_type_t handler_type_t;

typedef struct _mal_routing_handler_t mal_routing_handler_t;

int mal_routing_register_provider_send_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_send);

int mal_routing_register_provider_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_submit);

int mal_routing_register_consumer_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack);

int mal_routing_register_provider_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_request);

int mal_routing_register_consumer_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_invoke);

int mal_routing_register_consumer_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_progress);

int mal_routing_register_consumer_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_update,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_publish_error,
    mal_routing_on_message_fn *on_publish_register_ack,
    mal_routing_on_message_fn *on_publish_deregister_ack);

int mal_routing_register_consumer_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_register_ack,
    mal_routing_on_message_fn *on_deregister_ack,
    mal_routing_on_message_fn *on_notify);

int mal_routing_register_broker_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_notify_error,
    mal_routing_on_message_fn *on_register,
    mal_routing_on_message_fn *on_deregister,
    mal_routing_on_message_fn *on_publish,
    mal_routing_on_message_fn *on_publish_register,
    mal_routing_on_message_fn *on_publish_deregister);

int mal_routing_remove_handler(
    mal_routing_t *mal_routing,
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation);

//  Self test of this class
void mal_routing_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif /* MAL_INCLUDE_MAL_ROUTING_H_ */
