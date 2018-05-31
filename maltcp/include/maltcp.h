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

#include "maltcp_library.h"

typedef struct _mal_tcp_message_t mal_tcp_message_t;

extern clog_logger_t maltcp_logger;

void maltcp_set_log_level(int level);

#define MALTCP_PROTOCOL_VERSION 1


// 'Variable length' offset
// +1 byte: version + sdu type
// +2 bytes: service area
// +2 bytes: service
// +2 bytes: operation
// +1 bytes: area version
// +1 bytes: is error message + qos level + session
// +8 bytes: transaction id
// +1 bytes: flags
// +1 bytes: encoding id

static const int VARIABLE_LENGTH_OFFSET = 19;

// Fixed header length
// 'Variable length' offset (see above)
// +4 bytes: variable length
static const int FIXED_HEADER_LENGTH = 23;

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

// BEGIN -- URI manipulation functions maltcp:

static const char MALTCP_PROTOCOL[] = "maltcp"; // unused
static const char MALTCP_URI[] = "maltcp://";

// Returns a newly allocated string containing the base URI of the full URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "maltcp://ipaddress:port"
extern char *maltcp_get_base_uri(char *full_uri);

// Returns a pointer to the substring that specify the requested service in the URI
// specified in parameter: "maltcp://ipaddress:port/service" -> "service"
extern char *maltcp_get_service_from_uri(char *full_uri);

// Returns a newly allocated string containing the IP address from the URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "ipaddress"
extern char *maltcp_get_host_from_uri(char *uri);

// Returns the port number from the URI specified in parameter:
// "maltcp://ipaddress:port/service" -> port
extern int maltcp_get_port_from_uri(char *uri);

// END -- URI manipulation functions

#ifdef __cplusplus
}
#endif

#endif
