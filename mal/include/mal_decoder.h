/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
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
 * mal_decoding.h
 *
 *  Created on: 30 mai 2016
 *      Author: freyssin
 */

#ifndef MAL_INCLUDE_MAL_DECODER_H_
#define MAL_INCLUDE_MAL_DECODER_H_

#include "clog.h"
#include "mal.h"


/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding API
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

int mal_decoder_get_encoding_format_code(mal_decoder_t *self);

void mal_decoder_set_log_level(mal_decoder_t *self, int level);
clog_logger_t mal_decoder_get_logger(mal_decoder_t *self);

bool mal_decoder_is_varint(mal_decoder_t *decoder);

/*
 * Cursor manipulation.
 */

/** Creates a new decoding cursor */
void *mal_decoder_new_cursor(mal_decoder_t *self, char *bytes, unsigned int length, unsigned int offset);
/** Reset a decoding cursor for reuse */
void mal_decoder_cursor_reset(mal_decoder_t *self, void *cursor, char *bytes, unsigned int length, unsigned int offset);
/** Destroy an decoding cursor */
void mal_decoder_cursor_destroy(mal_decoder_t *self, void *cursor);

unsigned int mal_decoder_cursor_get_length(mal_decoder_t *self, void *cursor);
unsigned int mal_decoder_cursor_get_offset(mal_decoder_t *self, void *cursor);

void mal_decoder_cursor_assert(mal_decoder_t *self, void *cursor);

/* Decoding functions */

short mal_read16(mal_decoder_t *self, void *cursor);
int mal_read32(mal_decoder_t *self, void *cursor);
long mal_read64(mal_decoder_t *self, void *cursor);
int mal_decoder_decode_string(mal_decoder_t *self, void *cursor, mal_string_t **result);
int mal_decoder_decode_presence_flag(mal_decoder_t *self, void *cursor, bool *result);
int mal_decoder_decode_short_form(mal_decoder_t *self, void *cursor, long *result);
int mal_decoder_decode_small_enum(mal_decoder_t *self, void *cursor, int *result);
int mal_decoder_decode_medium_enum(mal_decoder_t *self, void *cursor, int *result);
int mal_decoder_decode_large_enum(mal_decoder_t *self, void *cursor, int *result);
int mal_decoder_decode_integer(mal_decoder_t *self, void *cursor, mal_integer_t *result);
int mal_decoder_decode_list_size(mal_decoder_t *self, void *cursor, unsigned int *result);
int mal_decoder_decode_uri(mal_decoder_t *self, void *cursor, mal_uri_t **result);
int mal_decoder_decode_blob(mal_decoder_t *self, void *cursor, mal_blob_t **result);
int mal_decoder_decode_time(mal_decoder_t *self, void *cursor, mal_time_t *result);
int mal_decoder_decode_uinteger(mal_decoder_t *self, void *cursor, mal_uinteger_t *result);
int mal_decoder_decode_identifier(mal_decoder_t *self, void *cursor, mal_identifier_t **result);
int mal_decoder_decode_uoctet(mal_decoder_t *self, void *cursor, mal_uoctet_t *result);
int mal_decoder_decode_long(mal_decoder_t *self, void *cursor, mal_long_t *result);
int mal_decoder_decode_ushort(mal_decoder_t *self, void *cursor, mal_ushort_t *result);
int mal_decoder_decode_boolean(mal_decoder_t *self, void *cursor, mal_boolean_t *result);
int mal_decoder_decode_duration(mal_decoder_t *self, void *cursor, mal_duration_t *result);
int mal_decoder_decode_float(mal_decoder_t *self, void *cursor, mal_float_t *result);
int mal_decoder_decode_double(mal_decoder_t *self, void *cursor, mal_double_t *result);
int mal_decoder_decode_octet(mal_decoder_t *self, void *cursor, mal_octet_t *result);
int mal_decoder_decode_short(mal_decoder_t *self, void *cursor, mal_short_t *result);
int mal_decoder_decode_ulong(mal_decoder_t *self, void *cursor, mal_ulong_t *result);
int mal_decoder_decode_finetime(mal_decoder_t *self, void *cursor, mal_finetime_t *result);
int mal_decoder_decode_attribute(mal_decoder_t *decoder, void *cursor,
    unsigned char attribute_tag, union mal_attribute_t *self);
int mal_decoder_decode_attribute_tag(mal_decoder_t *self, void *cursor, unsigned char *result);

int mal_decoder_decode_entitykey(mal_entitykey_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_entityrequest(mal_entityrequest_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_file(mal_file_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_idbooleanpair(mal_idbooleanpair_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_namedvalue(mal_namedvalue_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_pair(mal_pair_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_subscription(mal_subscription_t * self, mal_decoder_t * mal_decoder, void * cursor);
int mal_decoder_decode_updateheader(mal_updateheader_t * self, mal_decoder_t * mal_decoder, void * cursor);

int mal_decoder_decode_blob_list(mal_blob_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_boolean_list(mal_boolean_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_double_list(mal_double_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_duration_list(mal_duration_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_entitykey_list(mal_entitykey_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_entityrequest_list(mal_entityrequest_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_file_list(mal_file_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_finetime_list(mal_finetime_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_float_list(mal_float_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_idbooleanpair_list(mal_idbooleanpair_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_identifier_list(mal_identifier_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_integer_list(mal_integer_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_interactiontype_list(mal_interactiontype_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_long_list(mal_long_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_namedvalue_list(mal_namedvalue_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_octet_list(mal_octet_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_pair_list(mal_pair_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_qoslevel_list(mal_qoslevel_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_sessiontype_list(mal_sessiontype_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_short_list(mal_short_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_string_list(mal_string_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_subscription_list(mal_subscription_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_time_list(mal_time_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_uinteger_list(mal_uinteger_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_ulong_list(mal_ulong_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_uoctet_list(mal_uoctet_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_updateheader_list(mal_updateheader_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_updatetype_list(mal_updatetype_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_uri_list(mal_uri_list_t *self, mal_decoder_t *decoder, void *cursor);
int mal_decoder_decode_ushort_list(mal_ushort_list_t *self, mal_decoder_t *decoder, void *cursor);

/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding SPI
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

/* Cursor manipulation */

/** Creates a new decoding cursor */
typedef void *mal_decoder_new_cursor_fn(char *bytes, unsigned int length, unsigned int offset);
/** Reset a decoding cursor for reuse */
typedef void mal_decoder_cursor_reset_fn(void *cursor, char *bytes, unsigned int length, unsigned int offset);
/** Destroy an decoding cursor */
typedef void mal_decoder_cursor_destroy_fn(void *cursor);
typedef unsigned int mal_decoder_cursor_get_length_fn(void *cursor);
typedef unsigned int mal_decoder_cursor_get_offset_fn(void *cursor);
typedef void mal_decoder_cursor_assert_fn(void *cursor);

/* Decoding functions */

typedef short mal_read16_fn(void *cursor);
typedef int mal_read32_fn(void *cursor);
typedef long mal_read64_fn(void *cursor);
typedef int mal_decoder_decode_string_fn(mal_decoder_t *self, void *cursor, mal_string_t **result);
typedef int mal_decoder_decode_presence_flag_fn(mal_decoder_t *self, void *cursor, bool *result);
typedef int mal_decoder_decode_short_form_fn(mal_decoder_t *self, void *cursor, long *result);
typedef int mal_decoder_decode_small_enum_fn(mal_decoder_t *self, void *cursor, int *result);
typedef int mal_decoder_decode_medium_enum_fn(mal_decoder_t *self, void *cursor, int *result);
typedef int mal_decoder_decode_large_enum_fn(mal_decoder_t *self, void *cursor, int *result);
typedef int mal_decoder_decode_integer_fn(mal_decoder_t *self, void *cursor, mal_integer_t *result);
typedef int mal_decoder_decode_list_size_fn(mal_decoder_t *self, void *cursor, unsigned int *result);
typedef int mal_decoder_decode_uri_fn(mal_decoder_t *self, void *cursor, mal_uri_t **result);
typedef int mal_decoder_decode_blob_fn(mal_decoder_t *self, void *cursor, mal_blob_t **result);
typedef int mal_decoder_decode_time_fn(mal_decoder_t *self, void *cursor, mal_time_t *result);
typedef int mal_decoder_decode_uinteger_fn(mal_decoder_t *self, void *cursor, mal_uinteger_t *result);
typedef int mal_decoder_decode_identifier_fn(mal_decoder_t *self, void *cursor, mal_identifier_t **result);
typedef int mal_decoder_decode_uoctet_fn(mal_decoder_t *self, void *cursor, mal_uoctet_t *result);
typedef int mal_decoder_decode_long_fn(mal_decoder_t *self, void *cursor, mal_long_t *result);
typedef int mal_decoder_decode_ushort_fn(mal_decoder_t *self, void *cursor, mal_ushort_t *result);
typedef int mal_decoder_decode_boolean_fn(mal_decoder_t *self, void *cursor, mal_boolean_t *result);
typedef int mal_decoder_decode_duration_fn(mal_decoder_t *self, void *cursor, mal_duration_t *result);
typedef int mal_decoder_decode_float_fn(mal_decoder_t *self, void *cursor, mal_float_t *result);
typedef int mal_decoder_decode_double_fn(mal_decoder_t *self, void *cursor, mal_double_t *result);
typedef int mal_decoder_decode_octet_fn(mal_decoder_t *self, void *cursor, mal_octet_t *result);
typedef int mal_decoder_decode_short_fn(mal_decoder_t *self, void *cursor, mal_short_t *result);
typedef int mal_decoder_decode_ulong_fn(mal_decoder_t *self, void *cursor, mal_ulong_t *result);
typedef int mal_decoder_decode_finetime_fn(mal_decoder_t *self, void *cursor, mal_finetime_t *result);
typedef int mal_decoder_decode_attribute_fn(mal_decoder_t *decoder, void *cursor,
    unsigned char attribute_tag, union mal_attribute_t *self);
typedef int mal_decoder_decode_attribute_tag_fn(mal_decoder_t *self, void *cursor, unsigned char *result);

typedef int mal_decoder_decode_entitykey_fn(mal_entitykey_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_entityrequest_fn(mal_entityrequest_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_file_fn(mal_file_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_idbooleanpair_fn(mal_idbooleanpair_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_namedvalue_fn(mal_namedvalue_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_pair_fn(mal_pair_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_subscription_fn(mal_subscription_t * self, mal_decoder_t * mal_decoder, void * cursor);
typedef int mal_decoder_decode_updateheader_fn(mal_updateheader_t * self, mal_decoder_t * mal_decoder, void * cursor);

typedef int mal_decoder_decode_blob_list_fn(mal_blob_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_boolean_list_fn(mal_boolean_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_double_list_fn(mal_double_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_duration_list_fn(mal_duration_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_entitykey_list_fn(mal_entitykey_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_entityrequest_list_fn(mal_entityrequest_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_file_list_fn(mal_file_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_finetime_list_fn(mal_finetime_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_float_list_fn(mal_float_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_idbooleanpair_list_fn(mal_idbooleanpair_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_identifier_list_fn(mal_identifier_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_integer_list_fn(mal_integer_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_interactiontype_list_fn(mal_interactiontype_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_long_list_fn(mal_long_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_namedvalue_list_fn(mal_namedvalue_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_octet_list_fn(mal_octet_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_pair_list_fn(mal_pair_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_qoslevel_list_fn(mal_qoslevel_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_sessiontype_list_fn(mal_sessiontype_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_short_list_fn(mal_short_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_string_list_fn(mal_string_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_subscription_list_fn(mal_subscription_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_time_list_fn(mal_time_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_uinteger_list_fn(mal_uinteger_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_ulong_list_fn(mal_ulong_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_uoctet_list_fn(mal_uoctet_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_updateheader_list_fn(mal_updateheader_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_updatetype_list_fn(mal_updatetype_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_uri_list_fn(mal_uri_list_t *self, mal_decoder_t *decoder, void *cursor);
typedef int mal_decoder_decode_ushort_list_fn(mal_ushort_list_t *self, mal_decoder_t *decoder, void *cursor);

/*
 * Prototype of initialization function for decoding handles structure.
 */
typedef void mal_decoder_initialize_functions_fn(
    mal_decoder_t *self,
    mal_decoder_new_cursor_fn *new_cursor,
    mal_decoder_cursor_reset_fn *cursor_reset,
    mal_decoder_cursor_destroy_fn *cursor_destroy,
    mal_decoder_cursor_get_length_fn *cursor_get_length,
    mal_decoder_cursor_get_offset_fn *cursor_get_offset,
    mal_decoder_cursor_assert_fn *cursor_assert,
    mal_read16_fn *mal_read16,
    mal_read32_fn *mal_read32,
    mal_read64_fn *mal_read64,
    mal_decoder_decode_string_fn *mal_decoder_decode_string,
    mal_decoder_decode_presence_flag_fn *mal_decoder_decode_presence_flag,
    mal_decoder_decode_short_form_fn *mal_decoder_decode_short_form,
    mal_decoder_decode_small_enum_fn *mal_decoder_decode_small_enum,
    mal_decoder_decode_medium_enum_fn *mal_decoder_decode_medium_enum,
    mal_decoder_decode_large_enum_fn *mal_decoder_decode_large_enum,
    mal_decoder_decode_integer_fn *mal_decoder_decode_integer,
    mal_decoder_decode_list_size_fn *mal_decoder_decode_list_size,
    mal_decoder_decode_uri_fn *mal_decoder_decode_uri,
    mal_decoder_decode_blob_fn *mal_decoder_decode_blob,
    mal_decoder_decode_time_fn *mal_decoder_decode_time,
    mal_decoder_decode_uinteger_fn *mal_decoder_decode_uinteger,
    mal_decoder_decode_identifier_fn *mal_decoder_decode_identifier,
    mal_decoder_decode_uoctet_fn *mal_decoder_decode_uoctet,
    mal_decoder_decode_long_fn *mal_decoder_decode_long,
    mal_decoder_decode_ushort_fn *mal_decoder_decode_ushort,
    mal_decoder_decode_boolean_fn *mal_decoder_decode_boolean,
    mal_decoder_decode_duration_fn *mal_decoder_decode_duration,
    mal_decoder_decode_float_fn *mal_decoder_decode_float,
    mal_decoder_decode_double_fn *mal_decoder_decode_double,
    mal_decoder_decode_octet_fn *mal_decoder_decode_octet,
    mal_decoder_decode_short_fn *mal_decoder_decode_short,
    mal_decoder_decode_ulong_fn *mal_decoder_decode_ulong,
    mal_decoder_decode_finetime_fn *mal_decoder_decode_finetime,
    mal_decoder_decode_attribute_fn *mal_decoder_decode_attribute,
    mal_decoder_decode_attribute_tag_fn *mal_decoder_decode_attribute_tag,

    mal_decoder_decode_entitykey_fn *mal_decoder_decode_entitykey,
    mal_decoder_decode_entityrequest_fn *mal_decoder_decode_entityrequest,
    mal_decoder_decode_file_fn *mal_decoder_decode_file,
    mal_decoder_decode_idbooleanpair_fn *mal_decoder_decode_idbooleanpair,
    mal_decoder_decode_namedvalue_fn *mal_decoder_decode_namedvalue,
    mal_decoder_decode_pair_fn *mal_decoder_decode_pair,
    mal_decoder_decode_subscription_fn *mal_decoder_decode_subscription,
    mal_decoder_decode_updateheader_fn *mal_decoder_decode_updateheader,

    mal_decoder_decode_blob_list_fn *mal_decoder_decode_blob_list,
    mal_decoder_decode_boolean_list_fn *mal_decoder_decode_boolean_list,
    mal_decoder_decode_double_list_fn *mal_decoder_decode_double_list,
    mal_decoder_decode_duration_list_fn *mal_decoder_decode_duration_list,
    mal_decoder_decode_entitykey_list_fn *mal_decoder_decode_entitykey_list,
    mal_decoder_decode_entityrequest_list_fn *mal_decoder_decode_entityrequest_list,
    mal_decoder_decode_file_list_fn *mal_decoder_decode_file_list,
    mal_decoder_decode_finetime_list_fn *mal_decoder_decode_finetime_list,
    mal_decoder_decode_float_list_fn *mal_decoder_decode_float_list,
    mal_decoder_decode_idbooleanpair_list_fn *mal_decoder_decode_idbooleanpair_list,
    mal_decoder_decode_identifier_list_fn *mal_decoder_decode_identifier_list,
    mal_decoder_decode_integer_list_fn *mal_decoder_decode_integer_list,
    mal_decoder_decode_interactiontype_list_fn *mal_decoder_decode_interactiontype_list,
    mal_decoder_decode_long_list_fn *mal_decoder_decode_long_list,
    mal_decoder_decode_namedvalue_list_fn *mal_decoder_decode_namedvalue_list,
    mal_decoder_decode_octet_list_fn *mal_decoder_decode_octet_list,
    mal_decoder_decode_pair_list_fn *mal_decoder_decode_pair_list,
    mal_decoder_decode_qoslevel_list_fn *mal_decoder_decode_qoslevel_list,
    mal_decoder_decode_sessiontype_list_fn *mal_decoder_decode_sessiontype_list,
    mal_decoder_decode_short_list_fn *mal_decoder_decode_short_list,
    mal_decoder_decode_string_list_fn *mal_decoder_decode_string_list,
    mal_decoder_decode_subscription_list_fn *mal_decoder_decode_subscription_list,
    mal_decoder_decode_time_list_fn *mal_decoder_decode_time_list,
    mal_decoder_decode_uinteger_list_fn *mal_decoder_decode_uinteger_list,
    mal_decoder_decode_ulong_list_fn *mal_decoder_decode_ulong_list,
    mal_decoder_decode_uoctet_list_fn *mal_decoder_decode_uoctet_list,
    mal_decoder_decode_updateheader_list_fn *mal_decoder_decode_updateheader_list,
    mal_decoder_decode_updatetype_list_fn *mal_decoder_decode_updatetype_list,
    mal_decoder_decode_uri_list_fn *mal_decoder_decode_uri_list,
    mal_decoder_decode_ushort_list_fn *mal_decoder_decode_ushort_list);

/*
 * Currently this function can not be used by the decoding modules as it causes
 * a circular dependency. Decoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
mal_decoder_initialize_functions_fn mal_decoder_initialize_functions;

// NOTE: This structure should be private to the MAL:
//  -1- The encoding module initializes it through the mal_decoder_initialize_fn.
//  -2- The users (consumer, provider, stubs) uses it through the mal_decoder functions.

struct _mal_decoder_t {
  int encoding_format_code;
  bool varint_supported;
  clog_logger_t logger;

  /* Cursor manipulation */

  mal_decoder_new_cursor_fn *new_cursor;
  mal_decoder_cursor_reset_fn *cursor_reset;
  mal_decoder_cursor_destroy_fn *cursor_destroy;
  mal_decoder_cursor_get_length_fn *cursor_get_length;
  mal_decoder_cursor_get_offset_fn *cursor_get_offset;
  mal_decoder_cursor_assert_fn *cursor_assert;

  /* Decoding functions */

  mal_read16_fn *mal_read16;
  mal_read32_fn *mal_read32;
  mal_read64_fn *mal_read64;
  mal_decoder_decode_string_fn *mal_decoder_decode_string;
  mal_decoder_decode_presence_flag_fn *mal_decoder_decode_presence_flag;
  mal_decoder_decode_short_form_fn *mal_decoder_decode_short_form;
  mal_decoder_decode_small_enum_fn *mal_decoder_decode_small_enum;
  mal_decoder_decode_medium_enum_fn *mal_decoder_decode_medium_enum;
  mal_decoder_decode_large_enum_fn *mal_decoder_decode_large_enum;
  mal_decoder_decode_integer_fn *mal_decoder_decode_integer;
  mal_decoder_decode_list_size_fn *mal_decoder_decode_list_size;
  mal_decoder_decode_uri_fn *mal_decoder_decode_uri;
  mal_decoder_decode_blob_fn *mal_decoder_decode_blob;
  mal_decoder_decode_time_fn *mal_decoder_decode_time;
  mal_decoder_decode_uinteger_fn *mal_decoder_decode_uinteger;
  mal_decoder_decode_identifier_fn *mal_decoder_decode_identifier;
  mal_decoder_decode_uoctet_fn *mal_decoder_decode_uoctet;
  mal_decoder_decode_long_fn *mal_decoder_decode_long;
  mal_decoder_decode_ushort_fn *mal_decoder_decode_ushort;
  mal_decoder_decode_boolean_fn *mal_decoder_decode_boolean;
  mal_decoder_decode_duration_fn *mal_decoder_decode_duration;
  mal_decoder_decode_float_fn *mal_decoder_decode_float;
  mal_decoder_decode_double_fn *mal_decoder_decode_double;
  mal_decoder_decode_octet_fn *mal_decoder_decode_octet;
  mal_decoder_decode_short_fn *mal_decoder_decode_short;
  mal_decoder_decode_ulong_fn *mal_decoder_decode_ulong;
  mal_decoder_decode_finetime_fn *mal_decoder_decode_finetime;
  mal_decoder_decode_attribute_fn *mal_decoder_decode_attribute;
  mal_decoder_decode_attribute_tag_fn *mal_decoder_decode_attribute_tag;

  mal_decoder_decode_entitykey_fn *mal_decoder_decode_entitykey;
  mal_decoder_decode_entityrequest_fn *mal_decoder_decode_entityrequest;
  mal_decoder_decode_file_fn *mal_decoder_decode_file;
  mal_decoder_decode_idbooleanpair_fn *mal_decoder_decode_idbooleanpair;
  mal_decoder_decode_namedvalue_fn *mal_decoder_decode_namedvalue;
  mal_decoder_decode_pair_fn *mal_decoder_decode_pair;
  mal_decoder_decode_subscription_fn *mal_decoder_decode_subscription;
  mal_decoder_decode_updateheader_fn *mal_decoder_decode_updateheader;

  mal_decoder_decode_blob_list_fn *mal_decoder_decode_blob_list;
  mal_decoder_decode_boolean_list_fn *mal_decoder_decode_boolean_list;
  mal_decoder_decode_double_list_fn *mal_decoder_decode_double_list;
  mal_decoder_decode_duration_list_fn *mal_decoder_decode_duration_list;
  mal_decoder_decode_entitykey_list_fn *mal_decoder_decode_entitykey_list;
  mal_decoder_decode_entityrequest_list_fn *mal_decoder_decode_entityrequest_list;
  mal_decoder_decode_file_list_fn *mal_decoder_decode_file_list;
  mal_decoder_decode_finetime_list_fn *mal_decoder_decode_finetime_list;
  mal_decoder_decode_float_list_fn *mal_decoder_decode_float_list;
  mal_decoder_decode_idbooleanpair_list_fn *mal_decoder_decode_idbooleanpair_list;
  mal_decoder_decode_identifier_list_fn *mal_decoder_decode_identifier_list;
  mal_decoder_decode_integer_list_fn *mal_decoder_decode_integer_list;
  mal_decoder_decode_interactiontype_list_fn *mal_decoder_decode_interactiontype_list;
  mal_decoder_decode_long_list_fn *mal_decoder_decode_long_list;
  mal_decoder_decode_namedvalue_list_fn *mal_decoder_decode_namedvalue_list;
  mal_decoder_decode_octet_list_fn *mal_decoder_decode_octet_list;
  mal_decoder_decode_pair_list_fn *mal_decoder_decode_pair_list;
  mal_decoder_decode_qoslevel_list_fn *mal_decoder_decode_qoslevel_list;
  mal_decoder_decode_sessiontype_list_fn *mal_decoder_decode_sessiontype_list;
  mal_decoder_decode_short_list_fn *mal_decoder_decode_short_list;
  mal_decoder_decode_string_list_fn *mal_decoder_decode_string_list;
  mal_decoder_decode_subscription_list_fn *mal_decoder_decode_subscription_list;
  mal_decoder_decode_time_list_fn *mal_decoder_decode_time_list;
  mal_decoder_decode_uinteger_list_fn *mal_decoder_decode_uinteger_list;
  mal_decoder_decode_ulong_list_fn *mal_decoder_decode_ulong_list;
  mal_decoder_decode_uoctet_list_fn *mal_decoder_decode_uoctet_list;
  mal_decoder_decode_updateheader_list_fn *mal_decoder_decode_updateheader_list;
  mal_decoder_decode_updatetype_list_fn *mal_decoder_decode_updatetype_list;
  mal_decoder_decode_uri_list_fn *mal_decoder_decode_uri_list;
  mal_decoder_decode_ushort_list_fn *mal_decoder_decode_ushort_list;
};

void mal_decoder_test(bool verbose);

#endif /* MAL_INCLUDE_MAL_DECODER_H_ */
