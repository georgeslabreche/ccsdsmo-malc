#ifndef MAL_INCLUDE_MAL_ENDPOINT_H_
#define MAL_INCLUDE_MAL_ENDPOINT_H_

#ifdef __cplusplus
extern "C" {%
#endif

mal_endpoint_t *mal_endpoint_new(
    mal_ctx_t *mal_ctx,
    mal_uri_t *uri);

mal_endpoint_t *mal_endpoint_actor(
    mal_ctx_t *mal_ctx,
    void *endpoint_data);

void mal_endpoint_destroy(mal_endpoint_t **self_p);

mal_uri_t *mal_endpoint_get_uri(mal_endpoint_t *self);
mal_ctx_t *mal_endpoint_get_mal_ctx(mal_endpoint_t *self);

void *mal_endpoint_get_endpoint_data(mal_endpoint_t *self);
void mal_endpoint_set_endpoint_data(mal_endpoint_t *self, void *endpoint_data);

int mal_endpoint_init_operation(
    mal_endpoint_t *self,
    mal_message_t *message,
    mal_uri_t *uri_to,
    bool set_tid);

int mal_endpoint_return_operation(
    mal_endpoint_t *self,
    mal_message_t *init_message,
    mal_message_t *result_message,
    bool is_error_message);

int mal_endpoint_recv_message(
    mal_endpoint_t *self,
    mal_message_t **message);

//  Self test of this class
void mal_endpoint_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif /* MAL_INCLUDE_MAL_ENDPOINT_H_ */
