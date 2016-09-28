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

#ifndef __REQUEST_APP_MYPROVIDER_H_INCLUDED__
#define __REQUEST_APP_MYPROVIDER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

request_app_myprovider_t *request_app_myprovider_new(
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int request_app_myprovider_initialize(void *self, mal_actor_t *mal_actor);

int request_app_myprovider_finalize(void *self, mal_actor_t *mal_actor);

int request_app_myprovider_testarea_testservice_testrequest(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void request_app_myprovider_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
