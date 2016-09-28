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
long mal_endpoint_get_next_transaction_id_counter(mal_endpoint_t *self);
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
