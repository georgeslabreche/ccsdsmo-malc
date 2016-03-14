#ifndef MAL_INCLUDE_MAL_POLLER_H_
#define MAL_INCLUDE_MAL_POLLER_H_

#ifdef __cplusplus
extern "C" {%
#endif

mal_poller_t *mal_poller_new(mal_ctx_t *mal_ctx);

void mal_poller_destroy(mal_poller_t **self_p);

mal_ctx_t *mal_poller_get_mal_ctx(mal_poller_t *self);

void *mal_poller_get_poller_data(mal_poller_t *self);
void mal_poller_set_poller_data(mal_poller_t *self, void *poller_data);

int mal_poller_add_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint);

int mal_poller_del_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint);

int mal_poller_wait(
    mal_poller_t *self,
    mal_endpoint_t **message,
    int timeout);

//  Self test of this class
void mal_poller_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif /* MAL_INCLUDE_MAL_POLLER_H_ */
