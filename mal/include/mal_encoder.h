/*
 */

#ifndef MAL_INCLUDE_MAL_ENCODER_H_
#define MAL_INCLUDE_MAL_ENCODER_H_

#include "clog.h"

typedef struct _mal_encoder_t mal_encoder_t;

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

void *mal_encoder_new_cursor(mal_encoder_t *self);
void mal_encoder_cursor_destroy(mal_encoder_t *self, void *cursor);
void mal_encoder_cursor_init(mal_encoder_t *self, void *cursor, char *bytes, unsigned int length, unsigned int offset);
void mal_encoder_cursor_reset(mal_encoder_t *self, void *cursor);
unsigned int mal_encoder_cursor_get_length(mal_encoder_t *self, void *cursor);
unsigned int mal_encoder_cursor_get_offset(mal_encoder_t *self, void *cursor);
void mal_encoder_cursor_assert(mal_encoder_t *self, void *cursor);

/* Encoding length functions */

int mal_encoder_add_string_encoding_length(mal_encoder_t *self, mal_string_t *to_encode, void *cursor);
int mal_encoder_add_presence_flag_encoding_length( mal_encoder_t *self, void *cursor);
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
int mal_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor);

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

/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding SPI
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

/* Cursor manipulation */

typedef void *mal_encoder_new_cursor_fn();
typedef void mal_encoder_cursor_destroy_fn(void *cursor);
typedef void mal_encoder_cursor_init_fn(void *cursor, char *bytes, unsigned int length, unsigned int offset);
typedef void mal_encoder_cursor_reset_fn(void *cursor);
typedef unsigned int mal_encoder_cursor_get_length_fn(void *cursor);
typedef unsigned int mal_encoder_cursor_get_offset_fn(void *cursor);
typedef void mal_encoder_cursor_assert_fn(void *cursor);

/* Encoding length functions */

typedef int mal_encoder_add_string_encoding_length_fn(mal_encoder_t *self, mal_string_t *to_encode, void *cursor);
typedef int mal_encoder_add_presence_flag_encoding_length_fn( mal_encoder_t *self, void *cursor);
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
typedef int mal_encoder_add_attribute_encoding_length_fn(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor);

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

/*
 * Prototype of initialization function for encoding handles structure.
 */
typedef void mal_encoder_initialize_functions_fn(
    mal_encoder_t *self,
    mal_encoder_new_cursor_fn *new_cursor,
    mal_encoder_cursor_destroy_fn *cursor_destroy,
    mal_encoder_cursor_init_fn *cursor_init,
    mal_encoder_cursor_reset_fn *cursor_reset,
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
    mal_encoder_add_attribute_encoding_length_fn *mal_encoder_add_attribute_encoding_length,
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
    mal_encoder_encode_attribute_tag_fn *mal_encoder_encode_attribute_tag);

/*
 * Currently this function can not be used by the encoding modules as it causes
 * a circular dependency. Encoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
mal_encoder_initialize_functions_fn mal_encoder_initialize_functions;

// TODO (AF): This structure should be private to the MAL:
//  -1- The encoding module initializes it through the mal_encoder_initialize_fn.
//  -2- The users (consumer, provider, stubs) uses it through the mal_encoder functions.

struct _mal_encoder_t {
  int encoding_format_code;
  // TODO: varint limited to the last parameter in the MAL body
  bool varint_supported;
  clog_logger_t logger;

  /* Cursor manipulation */

  mal_encoder_new_cursor_fn *new_cursor;
  mal_encoder_cursor_destroy_fn *cursor_destroy;
  mal_encoder_cursor_init_fn *cursor_init;
  mal_encoder_cursor_reset_fn *cursor_reset;
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
  mal_encoder_add_attribute_encoding_length_fn *mal_encoder_add_attribute_encoding_length;

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
};

void mal_encoder_test(bool verbose);

#endif /* MAL_INCLUDE_MAL_ENCODER_H_ */
