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

#ifndef __MALTCP_H_INCLUDED__
#define __MALTCP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "czmq.h"
#include "zmq.h"

//  MALTCP API version macros for compile-time API detection

#define MALTCP_VERSION_MAJOR 1
#define MALTCP_VERSION_MINOR 0
#define MALTCP_VERSION_PATCH 0

#define MALTCP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALTCP_VERSION \
		MALTCP_MAKE_VERSION(MALTCP_VERSION_MAJOR, MALTCP_VERSION_MINOR, MALTCP_VERSION_PATCH)

typedef struct _mal_tcp_message_t mal_tcp_message_t;

extern clog_logger_t maltcp_logger;

void maltcp_set_log_level(int level);

#define MALTCP_PROTOCOL_VERSION 1

typedef struct _maltcp_ctx_t maltcp_ctx_t;
typedef struct _maltcp_header_t maltcp_header_t;

int maltcp_add_message_encoding_length(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_encoder_t *encoder,
    void *cursor);

int maltcp_encode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_encoder_t *encoder, void *cursor);

int maltcp_decode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_decoder_t *decoder, void *cursor,
    mal_uinteger_t *mal_message_length);

int maltcp_decode_uris(maltcp_header_t *maltcp_header,
	mal_decoder_t *decoder, char *bytes, unsigned int length,
	mal_uri_t **uri_to,
  mal_uri_t **uri_from);

void maltcp_test(bool verbose);

mal_tcp_message_t *maltcp_new_mal_tcp_message();
mal_tcp_message_t *maltcp_get_mal_tcp_message(maltcp_header_t *mal_header, mal_message_t *message);

static const char MALTCP_PROTOCOL[] = "maltcp";

static const int FIXED_HEADER_LENGTH = 23;

//  Public API classes
#include "maltcp_ctx.h"
#include "maltcp_header.h"

#ifdef __cplusplus
}
#endif

#endif
