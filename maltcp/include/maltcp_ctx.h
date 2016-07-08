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

/*
 */

#ifndef __MALTCP_CTX_H_INCLUDED__
#define __MALTCP_CTX_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#define PROTOCOL_TCP "tcp"
#define PROTOCOL_EPGM "epgm"
#define PROTOCOL_PGM "pgm"

#define SUB_NAME "MAL"

typedef mal_uri_t *maltcp_get_p2p_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *maltcp_get_ps_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *maltcp_getzmquri_to_fn(mal_message_t *message);

typedef struct _maltcp_mapping_uri_t maltcp_mapping_uri_t;

struct _maltcp_mapping_uri_t {
  maltcp_get_p2p_zmquri_fn *get_p2p_zmquri_fn;
  maltcp_get_ps_zmquri_fn *get_ps_zmquri_fn;
  maltcp_getzmquri_to_fn *getzmquri_to_fn;
};

mal_encoder_t *maltcp_get_encoder(maltcp_ctx_t *self);
mal_decoder_t *maltcp_get_decoder(maltcp_ctx_t *self);

maltcp_ctx_t *maltcp_ctx_new(
    mal_ctx_t *mal_ctx,
    maltcp_mapping_uri_t *mapping_uri,
    char *hostname, char *port,
    maltcp_header_t *maltcp_header,
    bool verbose);

int maltcp_ctx_start(void *self);
int maltcp_ctx_stop(void *self);
int maltcp_ctx_destroy(void **self_p);

// Must be compliant with MAL virtual function: void *self
int maltcp_ctx_send_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_recv_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t **message);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_endpoint_init_operation(mal_endpoint_t *mal_endpoint,
    mal_message_t *message, mal_uri_t *uri_to, bool set_tid);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_destroy_message(void *self, mal_message_t *mal_message);

// Must be compliant with MAL virtual function: void *self
mal_uri_t *maltcp_ctx_create_uri(void *self, char *id);

// Must be compliant with corresponding MAL virtual function
void *maltcp_ctx_create_endpoint(void *self, mal_endpoint_t *endpoint);

// Must be compliant with corresponding MAL virtual function
void maltcp_ctx_destroy_endpoint(void *self, void **endpoint_p);

// Must be compliant with corresponding MAL virtual function
void *maltcp_ctx_create_poller(void *maltcp_ctx, mal_poller_t *mal_poller);

// Must be compliant with corresponding MAL virtual function
void maltcp_ctx_destroy_poller(void *self, void **poller_p);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Must be compliant with corresponding MAL virtual function
int maltcp_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller, mal_endpoint_t **mal_endpoint, int timeout);

//  Self test of this class
void maltcp_ctx_test(bool verbose);

//int maltcp_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
//    maltcp_ctx_t *self, zmq_msg_t *zmsg, mal_uinteger_t msg_size);

//int maltcp_ctx_mal_pubsub_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
//    void *arg);

int maltcp_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    void *arg);

#ifdef __cplusplus
}
#endif

#endif
