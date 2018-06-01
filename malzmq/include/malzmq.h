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

#ifndef __MALZMQ_H_INCLUDED__
#define __MALZMQ_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "malzmq_library.h"

extern clog_logger_t malzmq_logger;

void malzmq_set_log_level(int level);

#define MALZMQ_PROTOCOL_VERSION 1

void malzmq_test(bool verbose);

// BEGIN -- URI manipulation functions:

static const char MALZMTP_PROTOCOL[] = "malzmtp";  // unused
static const char MALZMTP_URI[] = "malzmtp://";

// Default value for Point-to-Point protocol, should be tcp.
#define PTP_PROTOCOL         "tcp"
#define PTP_PROTOCOL_LENGTH  3

// Default value for Publish/Subscribe protocol, should be tcp, epgm or pgm
#define PUBSUB_PROTOCOL         "tcp"
#define PUBSUB_PROTOCOL_LENGTH  3

// Returns a newly allocated string containing the IP address from the URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "ipaddress"
extern char *malzmq_get_host_from_uri(char *uri);

// Returns the port number from the URI specified in parameter:
// "maltcp://ipaddress:port/service" -> port
extern int malzmq_get_port_from_uri(char *uri);

// Returns a pointer to the substring that specify the requested service in the URI
// specified in parameter: "maltcp://ipaddress:port/service" -> "service"
extern char *malzmq_get_service_from_uri(char *full_uri);

// END -- URI manipulation functions

int malzmq_add_message_encoding_length(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_encoder_t *encoder,
    void *cursor);

int malzmq_encode_message(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_encoder_t *encoder, void *cursor);

int malzmq_decode_message(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_decoder_t *decoder, void *cursor);

int malzmq_decode_uri_to(malzmq_header_t *malzmq_header,
	mal_decoder_t *decoder, char *bytes, unsigned int length, mal_uri_t **uri_to);

#ifdef __cplusplus
}
#endif

#endif
