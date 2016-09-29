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

#ifndef __PROGRESS_PROVIDER_H_INCLUDED__
#define __PROGRESS_PROVIDER_H_INCLUDED__

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

#define PROGRESS_PROVIDER_VERSION_MAJOR 1
#define PROGRESS_PROVIDER_VERSION_MINOR 0
#define PROGRESS_PROVIDER_VERSION_PATCH 0

#define PROGRESS_PROVIDER_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define PROGRESS_PROVIDER_VERSION \
    PROGRESS_PROVIDER_MAKE_VERSION(PROGRESS_PROVIDER_VERSION_MAJOR, PROGRESS_PROVIDER_VERSION_MINOR, PROGRESS_PROVIDER_VERSION_PATCH)

typedef struct _progress_provider_t progress_provider_t;

progress_provider_t *progress_provider_new(mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder);

int progress_provider_initialize(void *self, mal_actor_t *mal_actor);

int progress_provider_finalize(void *self, mal_actor_t *mal_actor);

int progress_provider_testarea_testservice_testprogress(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);

void progress_provider_test(bool verbose);

extern mal_actor_t *provider_actor;

#ifdef __cplusplus
}
#endif

#endif
