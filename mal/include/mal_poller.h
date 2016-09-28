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
