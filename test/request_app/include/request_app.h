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

#ifndef __REQUEST_APP_H_INCLUDED__
#define __REQUEST_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"
#include "malzmq.h"
#include "maltcp.h"
#include "testarea.h"
#include "malactor.h"

#define REQUEST_APP_VERSION_MAJOR 1
#define REQUEST_APP_VERSION_MINOR 0
#define REQUEST_APP_VERSION_PATCH 0

#define REQUEST_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define REQUEST_APP_VERSION \
		REQUEST_APP_MAKE_VERSION(REQUEST_APP_VERSION_MAJOR, REQUEST_APP_VERSION_MINOR, REQUEST_APP_VERSION_PATCH)

typedef struct _request_app_myprovider_t request_app_myprovider_t;
typedef struct _request_app_myconsumer_t request_app_myconsumer_t;

void request_app_test(bool verbose);

// Public API classes
#include "request_app_myconsumer.h"
#include "request_app_myprovider.h"

extern mal_actor_t *provider_actor;
extern mal_actor_t *consumer_actor;

// Fixes somes compilation issues with recent releases of Zproject.
void request_app_private_selftest(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
