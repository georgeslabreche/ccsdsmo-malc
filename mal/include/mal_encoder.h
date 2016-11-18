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

#ifndef MAL_INCLUDE_MAL_ENCODER_H_
#define MAL_INCLUDE_MAL_ENCODER_H_

#include "clog.h"
#include "mal.h"

/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding API
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

int mal_encoder_get_encoding_format_code(mal_encoder_t *self);

void mal_encoder_set_log_level(mal_encoder_t *self, int level);
clog_logger_t mal_encoder_get_logger(mal_encoder_t *self);

bool mal_encoder_is_varint(mal_encoder_t *encoder);

/*
 * Cursor manipulation.
 */

/** Creates a new encoding cursor, ready to calculate encoding size */
void *mal_encoder_new_cursor(mal_encoder_t *self);
/** Resets an encoding cursor for reuse, ready to calculate encoding size */
void mal_encoder_cursor_reset(mal_encoder_t *self, void *cursor);
/** Initializes the encoding cursor for encoding phase */
void mal_encoder_cursor_init(mal_encoder_t *self, void *cursor, char *bytes, unsigned int length, unsigned int offset);
/** Destroy an encoding cursor */
void mal_encoder_cursor_destroy(mal_encoder_t *self, void *cursor);

unsigned int mal_encoder_cursor_get_length(mal_encoder_t *self, void *cursor);
unsigned int mal_encoder_cursor_get_offset(mal_encoder_t *self, void *cursor);

void mal_encoder_cursor_assert(mal_encoder_t *self, void *cursor);

/* Encoding length functions */

int mal_encoder_add_string_encoding_length(mal_encoder_t *self, mal_string_t *to_encode, void *cursor);
int mal_encoder_add_presence_flag_encoding_length( mal_encoder_t *self, mal_boolean_t to_encode, void *cursor);
int mal_encoder_add_short_form_encoding_length(mal_encoder_t *self, long to_encode, void *cursor);
int mal_encoder_add_integer_encoding_length(mal_encoder_t *self, mal_integer_t to_encode, void *cursor);
int mal_encoder_add_identifier_encoding_length(mal_encoder_t *self, mal_identifier_t *to_encode, void *cursor);
int mal_encoder_add_uinteger_encoding_length(mal_encoder_t *self, mal_uinteger_t to_encode, void *cursor);
int mal_encoder_add_uri_encoding_length(mal_encoder_t *self, mal_uri_t *to_encode, void *cursor);
int mal_encoder_add_time_encoding_length(mal_encoder_t *self, mal_time_t to_encode, void *cursor);
int mal_encoder_add_uoctet_encoding_length(mal_encoder_t *self, mal_uoctet_t to_encode, void *cursor);
int mal_encoder_add_long_encoding_length(mal_encoder_t *self, mal_long_t to_encode, void *cursor);
int mal_encoder_add_ushort_encoding_length(mal_encoder_t *self, mal_ushort_t to_encode, void *cursor);
int mal_encoder_add_boolean_encoding_length(mal_encoder_t *self, mal_boolean_t to_encode, void *cursor);
int mal_encoder_add_blob_encoding_length(mal_encoder_t *self, mal_blob_t *to_encode, void *cursor);
int mal_encoder_add_list_size_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor);
int mal_encoder_add_small_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor);
int mal_encoder_add_medium_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor);
int mal_encoder_add_large_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor);
int mal_encoder_add_duration_encoding_length(mal_encoder_t *self, mal_duration_t to_encode, void *cursor);
int mal_encoder_add_float_encoding_length(mal_encoder_t *self, mal_float_t to_encode, void *cursor);
int mal_encoder_add_double_encoding_length(mal_encoder_t *self, mal_double_t to_encode, void *cursor);
int mal_encoder_add_octet_encoding_length(mal_encoder_t *self, mal_octet_t to_encode, void *cursor);
int mal_encoder_add_short_encoding_length(mal_encoder_t *self, mal_short_t to_encode, void *cursor);
int mal_encoder_add_ulong_encoding_length(mal_encoder_t *self, mal_ulong_t to_encode, void *cursor);
int mal_encoder_add_finetime_encoding_length(mal_encoder_t *self, mal_finetime_t to_encode, void *cursor);
int mal_encoder_add_attribute_tag_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, void *cursor);
int mal_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor);

int mal_encoder_add_entitykey_encoding_length(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_entityrequest_encoding_length(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_file_encoding_length(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_idbooleanpair_encoding_length(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_namedvalue_encoding_length(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_pair_encoding_length(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_subscription_encoding_length(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_add_updateheader_encoding_length(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);

int mal_encoder_blob_list_add_encoding_length(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_boolean_list_add_encoding_length(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_double_list_add_encoding_length(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_duration_list_add_encoding_length(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_entitykey_list_add_encoding_length(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_entityrequest_list_add_encoding_length(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_file_list_add_encoding_length(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_finetime_list_add_encoding_length(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_float_list_add_encoding_length(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_idbooleanpair_list_add_encoding_length(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_identifier_list_add_encoding_length(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_integer_list_add_encoding_length(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_interactiontype_list_add_encoding_length(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_long_list_add_encoding_length(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_namedvalue_list_add_encoding_length(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_octet_list_add_encoding_length(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_pair_list_add_encoding_length(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_qoslevel_list_add_encoding_length(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_sessiontype_list_add_encoding_length(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_short_list_add_encoding_length(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_string_list_add_encoding_length(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_subscription_list_add_encoding_length(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_time_list_add_encoding_length(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_uinteger_list_add_encoding_length(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_ulong_list_add_encoding_length(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_uoctet_list_add_encoding_length(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_updateheader_list_add_encoding_length(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_updatetype_list_add_encoding_length(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_uri_list_add_encoding_length(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_ushort_list_add_encoding_length(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor);


/* Encoding functions */

int mal_encoder_encode_string(mal_encoder_t *self, void *cursor, mal_string_t *to_encode);
int mal_encoder_encode_presence_flag(mal_encoder_t *self, void *cursor, bool to_encode);
int mal_encoder_encode_short_form(mal_encoder_t *self, void *cursor, long to_encode);
int mal_encoder_encode_small_enum(mal_encoder_t *self, void *cursor, int to_encode);
int mal_encoder_encode_medium_enum(mal_encoder_t *self, void *cursor, int to_encode);
int mal_encoder_encode_large_enum(mal_encoder_t *self, void *cursor, int to_encode);
int mal_encoder_encode_integer(mal_encoder_t *self, void *cursor, mal_integer_t to_encode);
int mal_encoder_encode_list_size(mal_encoder_t *self, void *cursor, unsigned int to_encode);
int mal_encoder_encode_uri(mal_encoder_t *self, void *cursor, mal_uri_t *to_encode);
int mal_encoder_encode_blob(mal_encoder_t *self, void *cursor, mal_blob_t *to_encode);
int mal_encoder_encode_time(mal_encoder_t *self, void *cursor, mal_time_t to_encode);
int mal_encoder_encode_uinteger(mal_encoder_t *self, void *cursor, mal_uinteger_t to_encode);
int mal_encoder_encode_identifier(mal_encoder_t *self, void *cursor, mal_identifier_t *to_encode);
int mal_encoder_encode_uoctet(mal_encoder_t *self, void *cursor, mal_uoctet_t to_encode);
int mal_encoder_encode_long(mal_encoder_t *self, void *cursor, mal_long_t to_encode);
int mal_encoder_encode_ushort(mal_encoder_t *self, void *cursor, mal_ushort_t to_encode);
int mal_encoder_encode_boolean(mal_encoder_t *self, void *cursor, mal_boolean_t to_encode);
void mal_write16(mal_encoder_t *self, int int_value, void *cursor);
void mal_write32(mal_encoder_t *self, int int_value, void *cursor);
void mal_write64(mal_encoder_t *self, long long_value, void *cursor);
int mal_encoder_encode_duration(mal_encoder_t *self, void *cursor, mal_duration_t to_encode);
int mal_encoder_encode_float(mal_encoder_t *self, void *cursor, mal_float_t to_encode);
int mal_encoder_encode_double(mal_encoder_t *self, void *cursor, mal_double_t to_encode);
int mal_encoder_encode_octet(mal_encoder_t *self, void *cursor, mal_octet_t to_encode);
int mal_encoder_encode_short(mal_encoder_t *self, void *cursor, mal_short_t to_encode);
int mal_encoder_encode_ulong(mal_encoder_t *self, void *cursor, mal_ulong_t to_encode);
int mal_encoder_encode_finetime(mal_encoder_t *self, void *cursor, mal_finetime_t to_encode);
int mal_encoder_encode_attribute(mal_encoder_t *encoder,
    void *cursor, unsigned char attribute_tag, union mal_attribute_t self);
int mal_encoder_encode_attribute_tag(mal_encoder_t *encoder, void *cursor, unsigned char to_encode);

int mal_encoder_encode_entitykey(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_entityrequest(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_file(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_idbooleanpair(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_namedvalue(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_pair(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_subscription(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_encoder_encode_updateheader(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);

int mal_encoder_encode_blob_list(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_boolean_list(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_double_list(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_duration_list(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_entitykey_list(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_entityrequest_list(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_file_list(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_finetime_list(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_float_list(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_idbooleanpair_list(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_identifier_list(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_integer_list(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_interactiontype_list(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_long_list(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_namedvalue_list(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_octet_list(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_pair_list(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_qoslevel_list(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_sessiontype_list(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_short_list(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_string_list(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_subscription_list(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_time_list(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_uinteger_list(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_ulong_list(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_uoctet_list(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_updateheader_list(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_updatetype_list(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_uri_list(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor);
int mal_encoder_encode_ushort_list(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor);

/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding SPI
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

/* Cursor manipulation */

/** Creates a new encoding cursor, ready to calculate encoding size */
typedef void *mal_encoder_new_cursor_fn();
/** Resets an encoding cursor for reuse, ready to calculate encoding size */
typedef void mal_encoder_cursor_reset_fn(void *cursor);
/** Initializes the encoding cursor for encoding phase */
typedef void mal_encoder_cursor_init_fn(void *cursor, char *bytes, unsigned int length, unsigned int offset);
/** Destroy an encoding cursor */
typedef void mal_encoder_cursor_destroy_fn(void *cursor);
typedef unsigned int mal_encoder_cursor_get_length_fn(void *cursor);
typedef unsigned int mal_encoder_cursor_get_offset_fn(void *cursor);
typedef void mal_encoder_cursor_assert_fn(void *cursor);

/* Encoding length functions */

typedef int mal_encoder_add_string_encoding_length_fn(mal_encoder_t *self, mal_string_t *to_encode, void *cursor);
typedef int mal_encoder_add_presence_flag_encoding_length_fn( mal_encoder_t *self, mal_boolean_t to_encode, void *cursor);
typedef int mal_encoder_add_short_form_encoding_length_fn(mal_encoder_t *self, long to_encode, void *cursor);
typedef int mal_encoder_add_integer_encoding_length_fn(mal_encoder_t *self, mal_integer_t to_encode, void *cursor);
typedef int mal_encoder_add_identifier_encoding_length_fn(mal_encoder_t *self, mal_identifier_t *to_encode, void *cursor);
typedef int mal_encoder_add_uinteger_encoding_length_fn(mal_encoder_t *self, mal_uinteger_t to_encode, void *cursor);
typedef int mal_encoder_add_uri_encoding_length_fn(mal_encoder_t *self, mal_uri_t *to_encode, void *cursor);
typedef int mal_encoder_add_time_encoding_length_fn(mal_encoder_t *self, mal_time_t to_encode, void *cursor);
typedef int mal_encoder_add_uoctet_encoding_length_fn(mal_encoder_t *self, mal_uoctet_t to_encode, void *cursor);
typedef int mal_encoder_add_long_encoding_length_fn(mal_encoder_t *self, mal_long_t to_encode, void *cursor);
typedef int mal_encoder_add_ushort_encoding_length_fn(mal_encoder_t *self, mal_ushort_t to_encode, void *cursor);
typedef int mal_encoder_add_boolean_encoding_length_fn(mal_encoder_t *self, mal_boolean_t to_encode, void *cursor);
typedef int mal_encoder_add_blob_encoding_length_fn(mal_encoder_t *self, mal_blob_t *to_encode, void *cursor);
typedef int mal_encoder_add_list_size_encoding_length_fn(mal_encoder_t *self, unsigned int to_encode, void *cursor);
typedef int mal_encoder_add_small_enum_encoding_length_fn(mal_encoder_t *self, unsigned int to_encode, void *cursor);
typedef int mal_encoder_add_medium_enum_encoding_length_fn(mal_encoder_t *self, unsigned int to_encode, void *cursor);
typedef int mal_encoder_add_large_enum_encoding_length_fn(mal_encoder_t *self, unsigned int to_encode, void *cursor);
typedef int mal_encoder_add_duration_encoding_length_fn(mal_encoder_t *self, mal_duration_t to_encode, void *cursor);
typedef int mal_encoder_add_float_encoding_length_fn(mal_encoder_t *self, mal_float_t to_encode, void *cursor);
typedef int mal_encoder_add_double_encoding_length_fn(mal_encoder_t *self, mal_double_t to_encode, void *cursor);
typedef int mal_encoder_add_octet_encoding_length_fn(mal_encoder_t *self, mal_octet_t to_encode, void *cursor);
typedef int mal_encoder_add_short_encoding_length_fn(mal_encoder_t *self, mal_short_t to_encode, void *cursor);
typedef int mal_encoder_add_ulong_encoding_length_fn(mal_encoder_t *self, mal_ulong_t to_encode, void *cursor);
typedef int mal_encoder_add_finetime_encoding_length_fn(mal_encoder_t *self, mal_finetime_t to_encode, void *cursor);
typedef int mal_encoder_add_attribute_tag_encoding_length_fn(mal_encoder_t *encoder,
    unsigned char attribute_tag, void *cursor);
typedef int mal_encoder_add_attribute_encoding_length_fn(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor);

typedef int mal_encoder_add_entitykey_encoding_length_fn(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_entityrequest_encoding_length_fn(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_file_encoding_length_fn(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_idbooleanpair_encoding_length_fn(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_namedvalue_encoding_length_fn(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_pair_encoding_length_fn(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_subscription_encoding_length_fn(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_add_updateheader_encoding_length_fn(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);

typedef int mal_encoder_blob_list_add_encoding_length_fn(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_boolean_list_add_encoding_length_fn(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_double_list_add_encoding_length_fn(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_duration_list_add_encoding_length_fn(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_entitykey_list_add_encoding_length_fn(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_entityrequest_list_add_encoding_length_fn(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_file_list_add_encoding_length_fn(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_finetime_list_add_encoding_length_fn(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_float_list_add_encoding_length_fn(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_idbooleanpair_list_add_encoding_length_fn(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_identifier_list_add_encoding_length_fn(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_integer_list_add_encoding_length_fn(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_interactiontype_list_add_encoding_length_fn(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_long_list_add_encoding_length_fn(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_namedvalue_list_add_encoding_length_fn(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_octet_list_add_encoding_length_fn(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_pair_list_add_encoding_length_fn(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_qoslevel_list_add_encoding_length_fn(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_sessiontype_list_add_encoding_length_fn(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_short_list_add_encoding_length_fn(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_string_list_add_encoding_length_fn(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_subscription_list_add_encoding_length_fn(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_time_list_add_encoding_length_fn(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_uinteger_list_add_encoding_length_fn(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_ulong_list_add_encoding_length_fn(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_uoctet_list_add_encoding_length_fn(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_updateheader_list_add_encoding_length_fn(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_updatetype_list_add_encoding_length_fn(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_uri_list_add_encoding_length_fn(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_ushort_list_add_encoding_length_fn(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor);


/* Encoding functions */

typedef int mal_encoder_encode_string_fn(mal_encoder_t *self, void *cursor, mal_string_t *to_encode);
typedef int mal_encoder_encode_presence_flag_fn(mal_encoder_t *self, void *cursor, bool to_encode);
typedef int mal_encoder_encode_short_form_fn(mal_encoder_t *self, void *cursor, long to_encode);
typedef int mal_encoder_encode_small_enum_fn(mal_encoder_t *self, void *cursor, int to_encode);
typedef int mal_encoder_encode_medium_enum_fn(mal_encoder_t *self, void *cursor, int to_encode);
typedef int mal_encoder_encode_large_enum_fn(mal_encoder_t *self, void *cursor, int to_encode);
typedef int mal_encoder_encode_integer_fn(mal_encoder_t *self, void *cursor, mal_integer_t to_encode);
typedef int mal_encoder_encode_list_size_fn(mal_encoder_t *self, void *cursor, unsigned int to_encode);
typedef int mal_encoder_encode_uri_fn(mal_encoder_t *self, void *cursor, mal_uri_t *to_encode);
typedef int mal_encoder_encode_blob_fn(mal_encoder_t *self, void *cursor, mal_blob_t *to_encode);
typedef int mal_encoder_encode_time_fn(mal_encoder_t *self, void *cursor, mal_time_t to_encode);
typedef int mal_encoder_encode_uinteger_fn(mal_encoder_t *self, void *cursor, mal_uinteger_t to_encode);
typedef int mal_encoder_encode_identifier_fn(mal_encoder_t *self, void *cursor, mal_identifier_t *to_encode);
typedef int mal_encoder_encode_uoctet_fn(mal_encoder_t *self, void *cursor, mal_uoctet_t to_encode);
typedef int mal_encoder_encode_long_fn(mal_encoder_t *self, void *cursor, mal_long_t to_encode);
typedef int mal_encoder_encode_ushort_fn(mal_encoder_t *self, void *cursor, mal_ushort_t to_encode);
typedef int mal_encoder_encode_boolean_fn(mal_encoder_t *self, void *cursor, mal_boolean_t to_encode);
typedef void mal_write16_fn(int int_value, void *cursor);
typedef void mal_write32_fn(int int_value, void *cursor);
typedef void mal_write64_fn(long long_value, void *cursor);
typedef int mal_encoder_encode_duration_fn(mal_encoder_t *self, void *cursor, mal_duration_t to_encode);
typedef int mal_encoder_encode_float_fn(mal_encoder_t *self, void *cursor, mal_float_t to_encode);
typedef int mal_encoder_encode_double_fn(mal_encoder_t *self, void *cursor, mal_double_t to_encode);
typedef int mal_encoder_encode_octet_fn(mal_encoder_t *self, void *cursor, mal_octet_t to_encode);
typedef int mal_encoder_encode_short_fn(mal_encoder_t *self, void *cursor, mal_short_t to_encode);
typedef int mal_encoder_encode_ulong_fn(mal_encoder_t *self, void *cursor, mal_ulong_t to_encode);
typedef int mal_encoder_encode_finetime_fn(mal_encoder_t *self, void *cursor, mal_finetime_t to_encode);
typedef int mal_encoder_encode_attribute_fn(mal_encoder_t *encoder,
    void *cursor, unsigned char attribute_tag, union mal_attribute_t self);
typedef int mal_encoder_encode_attribute_tag_fn(mal_encoder_t *encoder, void *cursor, unsigned char to_encode);

typedef int mal_encoder_encode_entitykey_fn(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_entityrequest_fn(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_file_fn(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_idbooleanpair_fn(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_namedvalue_fn(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_pair_fn(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_subscription_fn(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
typedef int mal_encoder_encode_updateheader_fn(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);

typedef int mal_encoder_encode_blob_list_fn(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_boolean_list_fn(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_double_list_fn(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_duration_list_fn(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_entitykey_list_fn(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_entityrequest_list_fn(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_file_list_fn(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_finetime_list_fn(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_float_list_fn(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_idbooleanpair_list_fn(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_identifier_list_fn(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_integer_list_fn(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_interactiontype_list_fn(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_long_list_fn(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_namedvalue_list_fn(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_octet_list_fn(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_pair_list_fn(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_qoslevel_list_fn(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_sessiontype_list_fn(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_short_list_fn(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_string_list_fn(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_subscription_list_fn(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_time_list_fn(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_uinteger_list_fn(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_ulong_list_fn(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_uoctet_list_fn(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_updateheader_list_fn(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_updatetype_list_fn(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_uri_list_fn(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor);
typedef int mal_encoder_encode_ushort_list_fn(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor);

/*
 * Prototype of initialization function for encoding handles structure.
 */
typedef void mal_encoder_initialize_functions_fn(
    mal_encoder_t *self,
    mal_encoder_new_cursor_fn *new_cursor,
    mal_encoder_cursor_reset_fn *cursor_reset,
    mal_encoder_cursor_init_fn *cursor_init,
    mal_encoder_cursor_destroy_fn *cursor_destroy,
    mal_encoder_cursor_get_length_fn *cursor_get_length,
    mal_encoder_cursor_get_offset_fn *cursor_get_offset,
    mal_encoder_cursor_assert_fn *cursor_assert,
    mal_encoder_add_string_encoding_length_fn *mal_encoder_add_string_encoding_length,
    mal_encoder_add_presence_flag_encoding_length_fn *mal_encoder_add_presence_flag_encoding_length,
    mal_encoder_add_short_form_encoding_length_fn *mal_encoder_add_short_form_encoding_length,
    mal_encoder_add_integer_encoding_length_fn *mal_encoder_add_integer_encoding_length,
    mal_encoder_add_identifier_encoding_length_fn *mal_encoder_add_identifier_encoding_length,
    mal_encoder_add_uinteger_encoding_length_fn *mal_encoder_add_uinteger_encoding_length,
    mal_encoder_add_uri_encoding_length_fn *mal_encoder_add_uri_encoding_length,
    mal_encoder_add_time_encoding_length_fn *mal_encoder_add_time_encoding_length,
    mal_encoder_add_uoctet_encoding_length_fn *mal_encoder_add_uoctet_encoding_length,
    mal_encoder_add_long_encoding_length_fn *mal_encoder_add_long_encoding_length,
    mal_encoder_add_ushort_encoding_length_fn *mal_encoder_add_ushort_encoding_length,
    mal_encoder_add_boolean_encoding_length_fn *mal_encoder_add_boolean_encoding_length,
    mal_encoder_add_blob_encoding_length_fn *mal_encoder_add_blob_encoding_length,
    mal_encoder_add_list_size_encoding_length_fn *mal_encoder_add_list_size_encoding_length,
    mal_encoder_add_small_enum_encoding_length_fn *mal_encoder_add_small_enum_encoding_length,
    mal_encoder_add_medium_enum_encoding_length_fn *mal_encoder_add_medium_enum_encoding_length,
    mal_encoder_add_large_enum_encoding_length_fn *mal_encoder_add_large_enum_encoding_length,
    mal_encoder_add_duration_encoding_length_fn *mal_encoder_add_duration_encoding_length,
    mal_encoder_add_float_encoding_length_fn *mal_encoder_add_float_encoding_length,
    mal_encoder_add_double_encoding_length_fn *mal_encoder_add_double_encoding_length,
    mal_encoder_add_octet_encoding_length_fn *mal_encoder_add_octet_encoding_length,
    mal_encoder_add_short_encoding_length_fn *mal_encoder_add_short_encoding_length,
    mal_encoder_add_ulong_encoding_length_fn *mal_encoder_add_ulong_encoding_length,
    mal_encoder_add_finetime_encoding_length_fn *mal_encoder_add_finetime_encoding_length,
    mal_encoder_add_attribute_tag_encoding_length_fn *mal_encoder_add_attribute_tag_encoding_length,
    mal_encoder_add_attribute_encoding_length_fn *mal_encoder_add_attribute_encoding_length,

    mal_encoder_add_entitykey_encoding_length_fn *mal_encoder_add_entitykey_encoding_length,
    mal_encoder_add_entityrequest_encoding_length_fn *mal_encoder_add_entityrequest_encoding_length,
    mal_encoder_add_file_encoding_length_fn *mal_encoder_add_file_encoding_length,
    mal_encoder_add_idbooleanpair_encoding_length_fn *mal_encoder_add_idbooleanpair_encoding_length,
    mal_encoder_add_namedvalue_encoding_length_fn *mal_encoder_add_namedvalue_encoding_length,
    mal_encoder_add_pair_encoding_length_fn *mal_encoder_add_pair_encoding_length,
    mal_encoder_add_subscription_encoding_length_fn *mal_encoder_add_subscription_encoding_length,
    mal_encoder_add_updateheader_encoding_length_fn *mal_encoder_add_updateheader_encoding_length,

    mal_encoder_blob_list_add_encoding_length_fn *mal_encoder_blob_list_add_encoding_length,
    mal_encoder_boolean_list_add_encoding_length_fn *mal_encoder_boolean_list_add_encoding_length,
    mal_encoder_double_list_add_encoding_length_fn *mal_encoder_double_list_add_encoding_length,
    mal_encoder_duration_list_add_encoding_length_fn *mal_encoder_duration_list_add_encoding_length,
    mal_encoder_entitykey_list_add_encoding_length_fn *mal_encoder_entitykey_list_add_encoding_length,
    mal_encoder_entityrequest_list_add_encoding_length_fn *mal_encoder_entityrequest_list_add_encoding_length,
    mal_encoder_file_list_add_encoding_length_fn *mal_encoder_file_list_add_encoding_length,
    mal_encoder_finetime_list_add_encoding_length_fn *mal_encoder_finetime_list_add_encoding_length,
    mal_encoder_float_list_add_encoding_length_fn *mal_encoder_float_list_add_encoding_length,
    mal_encoder_idbooleanpair_list_add_encoding_length_fn * mal_encoder_idbooleanpair_list_add_encoding_length,
    mal_encoder_identifier_list_add_encoding_length_fn *mal_encoder_identifier_list_add_encoding_length,
    mal_encoder_integer_list_add_encoding_length_fn *mal_encoder_integer_list_add_encoding_length,
    mal_encoder_interactiontype_list_add_encoding_length_fn * mal_encoder_interactiontype_list_add_encoding_length,
    mal_encoder_long_list_add_encoding_length_fn *mal_encoder_long_list_add_encoding_length,
    mal_encoder_namedvalue_list_add_encoding_length_fn *mal_encoder_namedvalue_list_add_encoding_length,
    mal_encoder_octet_list_add_encoding_length_fn *mal_encoder_octet_list_add_encoding_length,
    mal_encoder_pair_list_add_encoding_length_fn *mal_encoder_pair_list_add_encoding_length,
    mal_encoder_qoslevel_list_add_encoding_length_fn *mal_encoder_qoslevel_list_add_encoding_length,
    mal_encoder_sessiontype_list_add_encoding_length_fn *mal_encoder_sessiontype_list_add_encoding_length,
    mal_encoder_short_list_add_encoding_length_fn *mal_encoder_short_list_add_encoding_length,
    mal_encoder_string_list_add_encoding_length_fn *mal_encoder_string_list_add_encoding_length,
    mal_encoder_subscription_list_add_encoding_length_fn *mal_encoder_subscription_list_add_encoding_length,
    mal_encoder_time_list_add_encoding_length_fn *mal_encoder_time_list_add_encoding_length,
    mal_encoder_uinteger_list_add_encoding_length_fn *mal_encoder_uinteger_list_add_encoding_length,
    mal_encoder_ulong_list_add_encoding_length_fn *mal_encoder_ulong_list_add_encoding_length,
    mal_encoder_uoctet_list_add_encoding_length_fn *mal_encoder_uoctet_list_add_encoding_length,
    mal_encoder_updateheader_list_add_encoding_length_fn *mal_encoder_updateheader_list_add_encoding_length,
    mal_encoder_updatetype_list_add_encoding_length_fn *mal_encoder_updatetype_list_add_encoding_length,
    mal_encoder_uri_list_add_encoding_length_fn *mal_encoder_uri_list_add_encoding_length,
    mal_encoder_ushort_list_add_encoding_length_fn *mal_encoder_ushort_list_add_encoding_length,

    mal_encoder_encode_string_fn *mal_encoder_encode_string,
    mal_encoder_encode_presence_flag_fn *mal_encoder_encode_presence_flag,
    mal_encoder_encode_short_form_fn *mal_encoder_encode_short_form,
    mal_encoder_encode_small_enum_fn *mal_encoder_encode_small_enum,
    mal_encoder_encode_medium_enum_fn *mal_encoder_encode_medium_enum,
    mal_encoder_encode_large_enum_fn *mal_encoder_encode_large_enum,
    mal_encoder_encode_integer_fn *mal_encoder_encode_integer,
    mal_encoder_encode_list_size_fn *mal_encoder_encode_list_size,
    mal_encoder_encode_uri_fn *mal_encoder_encode_uri,
    mal_encoder_encode_blob_fn *mal_encoder_encode_blob,
    mal_encoder_encode_time_fn *mal_encoder_encode_time,
    mal_encoder_encode_uinteger_fn *mal_encoder_encode_uinteger,
    mal_encoder_encode_identifier_fn *mal_encoder_encode_identifier,
    mal_encoder_encode_uoctet_fn *mal_encoder_encode_uoctet,
    mal_encoder_encode_long_fn *mal_encoder_encode_long,
    mal_encoder_encode_ushort_fn *mal_encoder_encode_ushort,
    mal_encoder_encode_boolean_fn *mal_encoder_encode_boolean,
    mal_write16_fn *mal_write16,
    mal_write32_fn *mal_write32,
    mal_write64_fn *mal_write64,
    mal_encoder_encode_duration_fn *mal_encoder_encode_duration,
    mal_encoder_encode_float_fn *mal_encoder_encode_float,
    mal_encoder_encode_double_fn *mal_encoder_encode_double,
    mal_encoder_encode_octet_fn *mal_encoder_encode_octet,
    mal_encoder_encode_short_fn *mal_encoder_encode_short,
    mal_encoder_encode_ulong_fn *mal_encoder_encode_ulong,
    mal_encoder_encode_finetime_fn *mal_encoder_encode_finetime,
    mal_encoder_encode_attribute_fn *mal_encoder_encode_attribute,
    mal_encoder_encode_attribute_tag_fn *mal_encoder_encode_attribute_tag,

    mal_encoder_encode_entitykey_fn *mal_encoder_encode_entitykey,
    mal_encoder_encode_entityrequest_fn *mal_encoder_encode_entityrequest,
    mal_encoder_encode_file_fn *mal_encoder_encode_file,
    mal_encoder_encode_idbooleanpair_fn *mal_encoder_encode_idbooleanpair,
    mal_encoder_encode_namedvalue_fn *mal_encoder_encode_namedvalue,
    mal_encoder_encode_pair_fn *mal_encoder_encode_pair,
    mal_encoder_encode_subscription_fn *mal_encoder_encode_subscription,
    mal_encoder_encode_updateheader_fn *mal_encoder_encode_updateheader,

    mal_encoder_encode_blob_list_fn *mal_encoder_encode_blob_list,
    mal_encoder_encode_boolean_list_fn *mal_encoder_encode_boolean_list,
    mal_encoder_encode_double_list_fn *mal_encoder_encode_double_list,
    mal_encoder_encode_duration_list_fn *mal_encoder_encode_duration_list,
    mal_encoder_encode_entitykey_list_fn *mal_encoder_encode_entitykey_list,
    mal_encoder_encode_entityrequest_list_fn *mal_encoder_encode_entityrequest_list,
    mal_encoder_encode_file_list_fn *mal_encoder_encode_file_list,
    mal_encoder_encode_finetime_list_fn *mal_encoder_encode_finetime_list,
    mal_encoder_encode_float_list_fn *mal_encoder_encode_float_list,
    mal_encoder_encode_idbooleanpair_list_fn *mal_encoder_encode_idbooleanpair_list,
    mal_encoder_encode_identifier_list_fn *mal_encoder_encode_identifier_list,
    mal_encoder_encode_integer_list_fn *mal_encoder_encode_integer_list,
    mal_encoder_encode_interactiontype_list_fn *mal_encoder_encode_interactiontype_list,
    mal_encoder_encode_long_list_fn *mal_encoder_encode_long_list,
    mal_encoder_encode_namedvalue_list_fn *mal_encoder_encode_namedvalue_list,
    mal_encoder_encode_octet_list_fn *mal_encoder_encode_octet_list,
    mal_encoder_encode_pair_list_fn *mal_encoder_encode_pair_list,
    mal_encoder_encode_qoslevel_list_fn *mal_encoder_encode_qoslevel_list,
    mal_encoder_encode_sessiontype_list_fn *mal_encoder_encode_sessiontype_list,
    mal_encoder_encode_short_list_fn *mal_encoder_encode_short_list,
    mal_encoder_encode_string_list_fn *mal_encoder_encode_string_list,
    mal_encoder_encode_subscription_list_fn *mal_encoder_encode_subscription_list,
    mal_encoder_encode_time_list_fn *mal_encoder_encode_time_list,
    mal_encoder_encode_uinteger_list_fn *mal_encoder_encode_uinteger_list,
    mal_encoder_encode_ulong_list_fn *mal_encoder_encode_ulong_list,
    mal_encoder_encode_uoctet_list_fn *mal_encoder_encode_uoctet_list,
    mal_encoder_encode_updateheader_list_fn *mal_encoder_encode_updateheader_list,
    mal_encoder_encode_updatetype_list_fn *mal_encoder_encode_updatetype_list,
    mal_encoder_encode_uri_list_fn *mal_encoder_encode_uri_list,
    mal_encoder_encode_ushort_list_fn *mal_encoder_encode_ushort_list);

/*
 * Currently this function can not be used by the encoding modules as it causes
 * a circular dependency. Encoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
mal_encoder_initialize_functions_fn mal_encoder_initialize_functions;

// NOTE: This structure should be private to the MAL:
//  -1- The encoding module initializes it through the mal_encoder_initialize_fn.
//  -2- The users (consumer, provider, stubs) uses it through the mal_encoder functions.

struct _mal_encoder_t {
  int encoding_format_code;
  bool varint_supported;
  clog_logger_t logger;

  /* Cursor manipulation */

  mal_encoder_new_cursor_fn *new_cursor;
  mal_encoder_cursor_reset_fn *cursor_reset;
  mal_encoder_cursor_init_fn *cursor_init;
  mal_encoder_cursor_destroy_fn *cursor_destroy;
  mal_encoder_cursor_get_length_fn *cursor_get_length;
  mal_encoder_cursor_get_offset_fn *cursor_get_offset;
  mal_encoder_cursor_assert_fn *cursor_assert;

  /* Encoding length functions */

  mal_encoder_add_string_encoding_length_fn *mal_encoder_add_string_encoding_length;
  mal_encoder_add_presence_flag_encoding_length_fn *mal_encoder_add_presence_flag_encoding_length;
  mal_encoder_add_short_form_encoding_length_fn *mal_encoder_add_short_form_encoding_length;
  mal_encoder_add_integer_encoding_length_fn *mal_encoder_add_integer_encoding_length;
  mal_encoder_add_identifier_encoding_length_fn *mal_encoder_add_identifier_encoding_length;
  mal_encoder_add_uinteger_encoding_length_fn *mal_encoder_add_uinteger_encoding_length;
  mal_encoder_add_uri_encoding_length_fn *mal_encoder_add_uri_encoding_length;
  mal_encoder_add_time_encoding_length_fn *mal_encoder_add_time_encoding_length;
  mal_encoder_add_uoctet_encoding_length_fn *mal_encoder_add_uoctet_encoding_length;
  mal_encoder_add_long_encoding_length_fn *mal_encoder_add_long_encoding_length;
  mal_encoder_add_ushort_encoding_length_fn *mal_encoder_add_ushort_encoding_length;
  mal_encoder_add_boolean_encoding_length_fn *mal_encoder_add_boolean_encoding_length;
  mal_encoder_add_blob_encoding_length_fn *mal_encoder_add_blob_encoding_length;
  mal_encoder_add_list_size_encoding_length_fn *mal_encoder_add_list_size_encoding_length;
  mal_encoder_add_small_enum_encoding_length_fn *mal_encoder_add_small_enum_encoding_length;
  mal_encoder_add_medium_enum_encoding_length_fn *mal_encoder_add_medium_enum_encoding_length;
  mal_encoder_add_large_enum_encoding_length_fn *mal_encoder_add_large_enum_encoding_length;
  mal_encoder_add_duration_encoding_length_fn *mal_encoder_add_duration_encoding_length;
  mal_encoder_add_float_encoding_length_fn *mal_encoder_add_float_encoding_length;
  mal_encoder_add_double_encoding_length_fn *mal_encoder_add_double_encoding_length;
  mal_encoder_add_octet_encoding_length_fn *mal_encoder_add_octet_encoding_length;
  mal_encoder_add_short_encoding_length_fn *mal_encoder_add_short_encoding_length;
  mal_encoder_add_ulong_encoding_length_fn *mal_encoder_add_ulong_encoding_length;
  mal_encoder_add_finetime_encoding_length_fn *mal_encoder_add_finetime_encoding_length;
  mal_encoder_add_attribute_tag_encoding_length_fn *mal_encoder_add_attribute_tag_encoding_length;
  mal_encoder_add_attribute_encoding_length_fn *mal_encoder_add_attribute_encoding_length;

  mal_encoder_add_entitykey_encoding_length_fn *mal_encoder_add_entitykey_encoding_length;
  mal_encoder_add_entityrequest_encoding_length_fn *mal_encoder_add_entityrequest_encoding_length;
  mal_encoder_add_file_encoding_length_fn *mal_encoder_add_file_encoding_length;
  mal_encoder_add_idbooleanpair_encoding_length_fn *mal_encoder_add_idbooleanpair_encoding_length;
  mal_encoder_add_namedvalue_encoding_length_fn *mal_encoder_add_namedvalue_encoding_length;
  mal_encoder_add_pair_encoding_length_fn *mal_encoder_add_pair_encoding_length;
  mal_encoder_add_subscription_encoding_length_fn *mal_encoder_add_subscription_encoding_length;
  mal_encoder_add_updateheader_encoding_length_fn *mal_encoder_add_updateheader_encoding_length;

  mal_encoder_blob_list_add_encoding_length_fn *mal_encoder_blob_list_add_encoding_length;
  mal_encoder_boolean_list_add_encoding_length_fn *mal_encoder_boolean_list_add_encoding_length;
  mal_encoder_double_list_add_encoding_length_fn *mal_encoder_double_list_add_encoding_length;
  mal_encoder_duration_list_add_encoding_length_fn *mal_encoder_duration_list_add_encoding_length;
  mal_encoder_entitykey_list_add_encoding_length_fn *mal_encoder_entitykey_list_add_encoding_length;
  mal_encoder_entityrequest_list_add_encoding_length_fn *mal_encoder_entityrequest_list_add_encoding_length;
  mal_encoder_file_list_add_encoding_length_fn *mal_encoder_file_list_add_encoding_length;
  mal_encoder_finetime_list_add_encoding_length_fn *mal_encoder_finetime_list_add_encoding_length;
  mal_encoder_float_list_add_encoding_length_fn *mal_encoder_float_list_add_encoding_length;
  mal_encoder_idbooleanpair_list_add_encoding_length_fn * mal_encoder_idbooleanpair_list_add_encoding_length;
  mal_encoder_identifier_list_add_encoding_length_fn *mal_encoder_identifier_list_add_encoding_length;
  mal_encoder_integer_list_add_encoding_length_fn *mal_encoder_integer_list_add_encoding_length;
  mal_encoder_interactiontype_list_add_encoding_length_fn * mal_encoder_interactiontype_list_add_encoding_length;
  mal_encoder_long_list_add_encoding_length_fn *mal_encoder_long_list_add_encoding_length;
  mal_encoder_namedvalue_list_add_encoding_length_fn *mal_encoder_namedvalue_list_add_encoding_length;
  mal_encoder_octet_list_add_encoding_length_fn *mal_encoder_octet_list_add_encoding_length;
  mal_encoder_pair_list_add_encoding_length_fn *mal_encoder_pair_list_add_encoding_length;
  mal_encoder_qoslevel_list_add_encoding_length_fn *mal_encoder_qoslevel_list_add_encoding_length;
  mal_encoder_sessiontype_list_add_encoding_length_fn *mal_encoder_sessiontype_list_add_encoding_length;
  mal_encoder_short_list_add_encoding_length_fn *mal_encoder_short_list_add_encoding_length;
  mal_encoder_string_list_add_encoding_length_fn *mal_encoder_string_list_add_encoding_length;
  mal_encoder_subscription_list_add_encoding_length_fn *mal_encoder_subscription_list_add_encoding_length;
  mal_encoder_time_list_add_encoding_length_fn *mal_encoder_time_list_add_encoding_length;
  mal_encoder_uinteger_list_add_encoding_length_fn *mal_encoder_uinteger_list_add_encoding_length;
  mal_encoder_ulong_list_add_encoding_length_fn *mal_encoder_ulong_list_add_encoding_length;
  mal_encoder_uoctet_list_add_encoding_length_fn *mal_encoder_uoctet_list_add_encoding_length;
  mal_encoder_updateheader_list_add_encoding_length_fn *mal_encoder_updateheader_list_add_encoding_length;
  mal_encoder_updatetype_list_add_encoding_length_fn *mal_encoder_updatetype_list_add_encoding_length;
  mal_encoder_uri_list_add_encoding_length_fn *mal_encoder_uri_list_add_encoding_length;
  mal_encoder_ushort_list_add_encoding_length_fn *mal_encoder_ushort_list_add_encoding_length;

  /* Encoding functions */

  mal_encoder_encode_string_fn *mal_encoder_encode_string;
  mal_encoder_encode_presence_flag_fn *mal_encoder_encode_presence_flag;
  mal_encoder_encode_short_form_fn *mal_encoder_encode_short_form;
  mal_encoder_encode_small_enum_fn *mal_encoder_encode_small_enum;
  mal_encoder_encode_medium_enum_fn *mal_encoder_encode_medium_enum;
  mal_encoder_encode_large_enum_fn *mal_encoder_encode_large_enum;
  mal_encoder_encode_integer_fn *mal_encoder_encode_integer;
  mal_encoder_encode_list_size_fn *mal_encoder_encode_list_size;
  mal_encoder_encode_uri_fn *mal_encoder_encode_uri;
  mal_encoder_encode_blob_fn *mal_encoder_encode_blob;
  mal_encoder_encode_time_fn *mal_encoder_encode_time;
  mal_encoder_encode_uinteger_fn *mal_encoder_encode_uinteger;
  mal_encoder_encode_identifier_fn *mal_encoder_encode_identifier;
  mal_encoder_encode_uoctet_fn *mal_encoder_encode_uoctet;
  mal_encoder_encode_long_fn *mal_encoder_encode_long;
  mal_encoder_encode_ushort_fn *mal_encoder_encode_ushort;
  mal_encoder_encode_boolean_fn *mal_encoder_encode_boolean;
  mal_write16_fn *mal_write16;
  mal_write32_fn *mal_write32;
  mal_write64_fn *mal_write64;
  mal_encoder_encode_duration_fn *mal_encoder_encode_duration;
  mal_encoder_encode_float_fn *mal_encoder_encode_float;
  mal_encoder_encode_double_fn *mal_encoder_encode_double;
  mal_encoder_encode_octet_fn *mal_encoder_encode_octet;
  mal_encoder_encode_short_fn *mal_encoder_encode_short;
  mal_encoder_encode_ulong_fn *mal_encoder_encode_ulong;
  mal_encoder_encode_finetime_fn *mal_encoder_encode_finetime;
  mal_encoder_encode_attribute_fn *mal_encoder_encode_attribute;
  mal_encoder_encode_attribute_tag_fn *mal_encoder_encode_attribute_tag;

  mal_encoder_encode_entitykey_fn *mal_encoder_encode_entitykey;
  mal_encoder_encode_entityrequest_fn *mal_encoder_encode_entityrequest;
  mal_encoder_encode_file_fn *mal_encoder_encode_file;
  mal_encoder_encode_idbooleanpair_fn *mal_encoder_encode_idbooleanpair;
  mal_encoder_encode_namedvalue_fn *mal_encoder_encode_namedvalue;
  mal_encoder_encode_pair_fn *mal_encoder_encode_pair;
  mal_encoder_encode_subscription_fn *mal_encoder_encode_subscription;
  mal_encoder_encode_updateheader_fn *mal_encoder_encode_updateheader;

  mal_encoder_encode_blob_list_fn *mal_encoder_encode_blob_list;
  mal_encoder_encode_boolean_list_fn *mal_encoder_encode_boolean_list;
  mal_encoder_encode_double_list_fn *mal_encoder_encode_double_list;
  mal_encoder_encode_duration_list_fn *mal_encoder_encode_duration_list;
  mal_encoder_encode_entitykey_list_fn *mal_encoder_encode_entitykey_list;
  mal_encoder_encode_entityrequest_list_fn *mal_encoder_encode_entityrequest_list;
  mal_encoder_encode_file_list_fn *mal_encoder_encode_file_list;
  mal_encoder_encode_finetime_list_fn *mal_encoder_encode_finetime_list;
  mal_encoder_encode_float_list_fn *mal_encoder_encode_float_list;
  mal_encoder_encode_idbooleanpair_list_fn *mal_encoder_encode_idbooleanpair_list;
  mal_encoder_encode_identifier_list_fn *mal_encoder_encode_identifier_list;
  mal_encoder_encode_integer_list_fn *mal_encoder_encode_integer_list;
  mal_encoder_encode_interactiontype_list_fn *mal_encoder_encode_interactiontype_list;
  mal_encoder_encode_long_list_fn *mal_encoder_encode_long_list;
  mal_encoder_encode_namedvalue_list_fn *mal_encoder_encode_namedvalue_list;
  mal_encoder_encode_octet_list_fn *mal_encoder_encode_octet_list;
  mal_encoder_encode_pair_list_fn *mal_encoder_encode_pair_list;
  mal_encoder_encode_qoslevel_list_fn *mal_encoder_encode_qoslevel_list;
  mal_encoder_encode_sessiontype_list_fn *mal_encoder_encode_sessiontype_list;
  mal_encoder_encode_short_list_fn *mal_encoder_encode_short_list;
  mal_encoder_encode_string_list_fn *mal_encoder_encode_string_list;
  mal_encoder_encode_subscription_list_fn *mal_encoder_encode_subscription_list;
  mal_encoder_encode_time_list_fn *mal_encoder_encode_time_list;
  mal_encoder_encode_uinteger_list_fn *mal_encoder_encode_uinteger_list;
  mal_encoder_encode_ulong_list_fn *mal_encoder_encode_ulong_list;
  mal_encoder_encode_uoctet_list_fn *mal_encoder_encode_uoctet_list;
  mal_encoder_encode_updateheader_list_fn *mal_encoder_encode_updateheader_list;
  mal_encoder_encode_updatetype_list_fn *mal_encoder_encode_updatetype_list;
  mal_encoder_encode_uri_list_fn *mal_encoder_encode_uri_list;
  mal_encoder_encode_ushort_list_fn *mal_encoder_encode_ushort_list;
};

void mal_encoder_test(bool verbose);

#endif /* MAL_INCLUDE_MAL_ENCODER_H_ */
