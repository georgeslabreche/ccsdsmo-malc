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

#ifndef __PUBSUB_APP_BROKER_H_INCLUDED__
#define __PUBSUB_APP_BROKER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif


pubsub_app_broker_t *pubsub_app_broker_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain, mal_identifier_t *network_zone,
    mal_sessiontype_t session, mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int pubsub_app_broker_initialize(void *self, mal_actor_t *mal_actor);

int pubsub_app_broker_finalize(void *self, mal_actor_t *mal_actor);

int pubsub_app_broker_on_notify_error(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_broker_on_register(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_broker_on_deregister(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_broker_on_publish(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_broker_on_publish_register(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

int pubsub_app_broker_on_publish_deregister(void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

mal_uri_t *pubsub_app_broker_get_consumer_uri(pubsub_app_broker_t *self);

mal_uri_t *pubsub_app_broker_get_provider_uri(pubsub_app_broker_t *self);

mal_identifier_list_t *pubsub_app_broker_get_domain(pubsub_app_broker_t *self);

mal_blob_t *pubsub_app_broker_get_authentication_id(pubsub_app_broker_t *self);

void pubsub_app_broker_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
