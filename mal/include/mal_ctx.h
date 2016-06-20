/*
 */

#ifndef __MALCTX_H_INCLUDED__
#define __MALCTX_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_ctx_t *mal_ctx_new();

void mal_ctx_destroy(mal_ctx_t **self_p);

void mal_ctx_set_binding(
    mal_ctx_t *self, void *mal_binding_ctx,
    mal_binding_ctx_create_uri_fn *create_uri,
    mal_binding_ctx_create_endpoint_fn *create_endpoint,
    mal_binding_ctx_destroy_endpoint_fn *destroy_endpoint,
    mal_binding_ctx_create_poller_fn *create_poller,
    mal_binding_ctx_destroy_poller_fn *destroy_poller,
    mal_binding_ctx_poller_add_endpoint_fn *poller_add_endpoint,
    mal_binding_ctx_poller_del_endpoint_fn *poller_del_endpoint,
    mal_binding_ctx_send_message_fn *send_message,
    mal_binding_ctx_recv_message_fn *recv_message,
    mal_binding_ctx_init_operation_fn *init_operation,
    mal_binding_ctx_poller_wait_fn *poller_wait,
    mal_binding_ctx_destroy_message_fn *destroy_message,
    mal_binding_ctx_start_fn *mal_ctx_start,
    mal_binding_ctx_stop_fn *mal_ctx_stop,
    mal_binding_ctx_destroy_fn *mal_ctx_destroy);

void *mal_ctx_get_binding(mal_ctx_t *self);

mal_uri_t *mal_ctx_create_uri(mal_ctx_t *self, char *id);

void *mal_ctx_create_endpoint(mal_ctx_t *self, mal_endpoint_t *mal_endpoint);

void mal_ctx_destroy_endpoint(mal_ctx_t *self, void **endpoint_p);

void *mal_ctx_create_poller(mal_ctx_t *self, mal_poller_t *mal_poller);

void mal_ctx_destroy_poller(mal_ctx_t *self, void **poller_p);

int mal_ctx_poller_add_endpoint(
    mal_ctx_t *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

int mal_ctx_poller_del_endpoint(
    mal_ctx_t *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

int mal_ctx_send_message(mal_ctx_t *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

int mal_ctx_recv_message(
    mal_ctx_t *self, mal_endpoint_t *mal_endpoint,
    mal_message_t **message);

int mal_ctx_init_operation(mal_ctx_t *self, mal_endpoint_t *mal_endpoint,
    mal_message_t *message, mal_uri_t *uri_to, bool set_tid);

int mal_ctx_poller_wait(
    mal_ctx_t *self, mal_poller_t *mal_poller,
    mal_endpoint_t **endpoint,
    int timeout);

int mal_ctx_destroy_message(mal_ctx_t *self, mal_message_t *message);

int mal_ctx_start(mal_ctx_t *self);
int mal_ctx_stop(mal_ctx_t *self);

//  Self test of this class
void mal_ctx_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
