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

#define SUB_NAME "MAL"

typedef mal_uri_t *malzmq_get_p2p_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_ps_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_getzmquri_to_fn(mal_message_t *message);

typedef struct _malzmq_mapping_uri_t malzmq_mapping_uri_t;

struct _malzmq_mapping_uri_t {
  malzmq_get_p2p_zmquri_fn *get_p2p_zmquri_fn;
  malzmq_get_ps_zmquri_fn *get_ps_zmquri_fn;
  malzmq_getzmquri_to_fn *getzmquri_to_fn;
};

malzmq_ctx_t *malzmq_ctx_new(
    mal_ctx_t *mal_ctx,
    malzmq_mapping_uri_t *mapping_uri,
    char *hostname, char *port,
    malzmq_header_t *malzmq_header,
    bool verbose);

mal_encoder_t *malzmq_get_encoder(malzmq_ctx_t *self);
mal_decoder_t *malzmq_get_decoder(malzmq_ctx_t *self);

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

int malzmq_ctx_mal_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    malzmq_ctx_t *self, zmsg_t *zmsg, bool isPubsub);

int malzmq_ctx_mal_pubsub_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    void *arg);

int malzmq_ctx_mal_standard_socket_handle(zloop_t *loop, zmq_pollitem_t *poller,
    void *arg);

#ifdef __cplusplus
}
#endif

#endif
