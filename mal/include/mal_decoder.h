/*
 * mal_decoding.h
 *
 *  Created on: 30 mai 2016
 *      Author: freyssin
 */

#ifndef MAL_INCLUDE_MAL_DECODER_H_
#define MAL_INCLUDE_MAL_DECODER_H_

#include "clog.h"

typedef struct _mal_decoder_t mal_decoder_t;

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
    unsigned char attribute_tag, union mal_attribute_t self);
int mal_decoder_decode_attribute_tag(mal_decoder_t *self, void *cursor, unsigned char *result);

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
    unsigned char attribute_tag, union mal_attribute_t self);
typedef int mal_decoder_decode_attribute_tag_fn(mal_decoder_t *self, void *cursor, unsigned char *result);

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
    mal_decoder_decode_attribute_tag_fn *mal_decoder_decode_attribute_tag);

/*
 * Currently this function can not be used by the decoding modules as it causes
 * a circular dependency. Decoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
mal_decoder_initialize_functions_fn mal_decoder_initialize_functions;

// TODO (AF): This structure should be private to the MAL:
//  -1- The encoding module initializes it through the mal_decoder_initialize_fn.
//  -2- The users (consumer, provider, stubs) uses it through the mal_decoder functions.

struct _mal_decoder_t {
  int encoding_format_code;
  // TODO: varint limited to the last parameter in the MAL body
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
};

void mal_decoder_test(bool verbose);

#endif /* MAL_INCLUDE_MAL_DECODER_H_ */
