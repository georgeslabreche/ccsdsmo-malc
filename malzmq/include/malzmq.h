/*
 */

#ifndef __MALZMQ_H_INCLUDED__
#define __MALZMQ_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "czmq.h"
#include "zmq.h"

//  MALZMQ API version macros for compile-time API detection

#define MALZMQ_VERSION_MAJOR 1
#define MALZMQ_VERSION_MINOR 0
#define MALZMQ_VERSION_PATCH 0

#define MALZMQ_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALZMQ_VERSION \
		MALZMQ_MAKE_VERSION(MALZMQ_VERSION_MAJOR, MALZMQ_VERSION_MINOR, MALZMQ_VERSION_PATCH)

extern clog_logger_t malzmq_logger;

void malzmq_set_log_level(int level);

#define MALZMQ_PROTOCOL_VERSION 1

typedef struct _malzmq_ctx_t malzmq_ctx_t;
typedef struct _malzmq_header_t malzmq_header_t;

int malzmq_add_message_encoding_length(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_encoder_t *encoder,
    void *cursor);

int malzmq_encode_message(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_encoder_t *encoder, void *cursor);

int malzmq_decode_message(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_decoder_t *decoder, void *cursor);

int malzmq_decode_uri_to(malzmq_header_t *malzmq_header,
	mal_decoder_t *decoder, char *bytes, unsigned int length, mal_uri_t **uri_to);

void malzmq_test(bool verbose);

//  Public API classes
#include "malzmq_ctx.h"
#include "malzmq_header.h"

#ifdef __cplusplus
}
#endif

#endif
