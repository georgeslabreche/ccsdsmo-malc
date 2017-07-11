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

#ifndef __MALZMQ_CTX_H_INCLUDED__
#define __MALZMQ_CTX_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#define PROTOCOL_TCP "tcp"
#define PROTOCOL_EPGM "epgm"
#define PROTOCOL_PGM "pgm"

// TODO (AF): fix SUB_NAME?
// #define SUB_NAME "MAL"
#define SUB_NAME ""

typedef mal_uri_t *malzmq_get_local_ptp_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_local_mcast_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_remote_ptp_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_remote_mcast_zmtp_uri_fn(mal_uri_t *maluri);

typedef struct _malzmq_mapping_uri_t malzmq_mapping_uri_t;

struct _malzmq_mapping_uri_t {
  malzmq_get_local_ptp_zmtp_uri_fn *get_local_ptp_zmtp_uri;
  malzmq_get_local_mcast_zmtp_uri_fn *get_local_mcast_zmtp_uri;
  malzmq_get_remote_ptp_zmtp_uri_fn *get_remote_ptp_zmtp_uri;
  malzmq_get_remote_mcast_zmtp_uri_fn *get_remote_mcast_zmtp_uri;
};

malzmq_ctx_t *malzmq_ctx_new(
    mal_ctx_t *mal_ctx,
    malzmq_mapping_uri_t *mapping_uri,
    char *hostname, char *port,
    malzmq_header_t *malzmq_header,
    bool verbose);

void malzmq_ctx_set_encoder_log_level(malzmq_ctx_t *self, int level);
void malzmq_ctx_set_decoder_log_level(malzmq_ctx_t *self, int level);

int malzmq_ctx_start(void *self);
int malzmq_ctx_stop(void *self);
int malzmq_ctx_destroy(void **self);

// Must be compliant with MAL virtual function: void *self
int malzmq_ctx_send_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_recv_message(void *self, mal_endpoint_t *mal_endpoint,
    mal_message_t **message);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_endpoint_init_operation(mal_endpoint_t *mal_endpoint,
    mal_message_t *message, mal_uri_t *uri_to, bool set_tid);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_destroy_message(void *self, mal_message_t *mal_message);

// Must be compliant with MAL virtual function: void *self
mal_uri_t *malzmq_ctx_create_uri(void *self, char *id);

// Must be compliant with corresponding MAL virtual function
void *malzmq_ctx_create_endpoint(void *self, mal_endpoint_t *endpoint);

// Must be compliant with corresponding MAL virtual function
void malzmq_ctx_destroy_endpoint(void *self, void **endpoint_p);

// Must be compliant with corresponding MAL virtual function
void *malzmq_ctx_create_poller(void *malzmq_ctx, mal_poller_t *mal_poller);

// Must be compliant with corresponding MAL virtual function
void malzmq_ctx_destroy_poller(void *self, void **poller_p);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Must be compliant with corresponding MAL virtual function
int malzmq_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller, mal_endpoint_t **mal_endpoint, int timeout);

//  Self test of this class
void malzmq_ctx_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
