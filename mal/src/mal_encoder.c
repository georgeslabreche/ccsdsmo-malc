/*
 */

#include "malattributes.h"
#include "mal_encoder.h"

/** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding API
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

int mal_encoder_get_encoding_format_code(mal_encoder_t *self) {
  return self->encoding_format_code;
}

void mal_encoder_set_log_level(mal_encoder_t *self, int level) {
  clog_set_level(&self->logger, level);
}

clog_logger_t mal_encoder_get_logger(mal_encoder_t *self) {
  return self->logger;
}

bool mal_encoder_is_varint(mal_encoder_t *encoder) {
  return encoder->varint_supported;
}

/*
 * Cursor manipulation.
 */

void *mal_encoder_new_cursor(mal_encoder_t *self) {
  return self->new_cursor();
}

void mal_encoder_cursor_destroy(mal_encoder_t *self, void *cursor) {
  self->cursor_destroy(cursor);
}

void mal_encoder_cursor_init(
    mal_encoder_t *self,
    void *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  self->cursor_init(cursor, bytes, length, offset);
}

void mal_encoder_cursor_reset(mal_encoder_t *self, void *cursor) {
  self->cursor_reset(cursor);
}

unsigned int mal_encoder_cursor_get_length(mal_encoder_t *self, void *cursor) {
  return self->cursor_get_length(cursor);
}

unsigned int mal_encoder_cursor_get_offset(mal_encoder_t *self, void *cursor) {
  return self->cursor_get_offset(cursor);
}

void mal_encoder_cursor_assert(mal_encoder_t *self, void *cursor) {
  self->cursor_assert(cursor);
}

/* Encoding length functions */

int mal_encoder_add_string_encoding_length(mal_encoder_t *self, mal_string_t *to_encode, void *cursor) {
  return self->mal_encoder_add_string_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_presence_flag_encoding_length(mal_encoder_t *self, void *cursor) {
  return self->mal_encoder_add_presence_flag_encoding_length(self, cursor);
}

int mal_encoder_add_short_form_encoding_length(mal_encoder_t *self, long to_encode, void *cursor) {
  return self->mal_encoder_add_short_form_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_integer_encoding_length(mal_encoder_t *self, mal_integer_t to_encode, void *cursor) {
  return self->mal_encoder_add_integer_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_identifier_encoding_length(mal_encoder_t *self, mal_identifier_t *to_encode, void *cursor) {
  return self->mal_encoder_add_identifier_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_uinteger_encoding_length(mal_encoder_t *self, mal_uinteger_t to_encode, void *cursor) {
  return self->mal_encoder_add_uinteger_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_uri_encoding_length(mal_encoder_t *self, mal_uri_t *to_encode, void *cursor) {
  return self->mal_encoder_add_uri_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_time_encoding_length(mal_encoder_t *self, mal_time_t to_encode, void *cursor) {
  return self->mal_encoder_add_time_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_uoctet_encoding_length(mal_encoder_t *self, mal_uoctet_t to_encode, void *cursor) {
  return self->mal_encoder_add_uoctet_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_long_encoding_length(mal_encoder_t *self, mal_long_t to_encode, void *cursor) {
  return self->mal_encoder_add_long_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_ushort_encoding_length(mal_encoder_t *self, mal_ushort_t to_encode, void *cursor) {
  return self->mal_encoder_add_ushort_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_boolean_encoding_length(mal_encoder_t *self, mal_boolean_t to_encode, void *cursor) {
  return self->mal_encoder_add_boolean_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_blob_encoding_length(mal_encoder_t *self, mal_blob_t *to_encode, void *cursor) {
  return self->mal_encoder_add_blob_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_list_size_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor) {
  return self->mal_encoder_add_list_size_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_small_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor) {
  return self->mal_encoder_add_small_enum_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_medium_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor) {
  return self->mal_encoder_add_medium_enum_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_large_enum_encoding_length(mal_encoder_t *self, unsigned int to_encode, void *cursor) {
  return self->mal_encoder_add_large_enum_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_duration_encoding_length(mal_encoder_t *self, mal_duration_t to_encode, void *cursor) {
  return self->mal_encoder_add_duration_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_float_encoding_length(mal_encoder_t *self, mal_float_t to_encode, void *cursor) {
  return self->mal_encoder_add_float_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_double_encoding_length(mal_encoder_t *self, mal_double_t to_encode, void *cursor) {
  return self->mal_encoder_add_double_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_octet_encoding_length(mal_encoder_t *self, mal_octet_t to_encode, void *cursor) {
  return self->mal_encoder_add_octet_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_short_encoding_length(mal_encoder_t *self, mal_short_t to_encode, void *cursor) {
  return self->mal_encoder_add_short_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_ulong_encoding_length(mal_encoder_t *self, mal_ulong_t to_encode, void *cursor) {
  return self->mal_encoder_add_ulong_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_finetime_encoding_length(mal_encoder_t *self, mal_finetime_t to_encode, void *cursor) {
  return self->mal_encoder_add_finetime_encoding_length(self, to_encode, cursor);
}

int mal_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor) {
  return encoder->mal_encoder_add_attribute_encoding_length(encoder, attribute_tag, self, cursor);
}


/* Encoding functions */

int mal_encoder_encode_string(mal_encoder_t *self, void *cursor, mal_string_t *to_encode) {
  return self->mal_encoder_encode_string(self, cursor, to_encode);
}

int mal_encoder_encode_presence_flag(mal_encoder_t *self, void *cursor, bool to_encode) {
  return self->mal_encoder_encode_presence_flag(self, cursor, to_encode);
}

int mal_encoder_encode_short_form(mal_encoder_t *self, void *cursor, long to_encode) {
  return self->mal_encoder_encode_short_form(self, cursor, to_encode);
}

int mal_encoder_encode_small_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  return self->mal_encoder_encode_small_enum(self, cursor, to_encode);
}

int mal_encoder_encode_medium_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  return self->mal_encoder_encode_medium_enum(self, cursor, to_encode);
}

int mal_encoder_encode_large_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  return self->mal_encoder_encode_large_enum(self, cursor, to_encode);
}

int mal_encoder_encode_integer(mal_encoder_t *self, void *cursor, mal_integer_t to_encode) {
  return self->mal_encoder_encode_integer(self, cursor, to_encode);
}

int mal_encoder_encode_list_size(mal_encoder_t *self, void *cursor, unsigned int to_encode) {
  return self->mal_encoder_encode_list_size(self, cursor, to_encode);
}

int mal_encoder_encode_uri(mal_encoder_t *self, void *cursor, mal_uri_t *to_encode) {
  return self->mal_encoder_encode_uri(self, cursor, to_encode);
}

int mal_encoder_encode_blob(mal_encoder_t *self, void *cursor, mal_blob_t *to_encode) {
  return self->mal_encoder_encode_blob(self, cursor, to_encode);
}

int mal_encoder_encode_time(mal_encoder_t *self, void *cursor, mal_time_t to_encode) {
  return self->mal_encoder_encode_time(self, cursor, to_encode);
}

int mal_encoder_encode_uinteger(mal_encoder_t *self, void *cursor, mal_uinteger_t to_encode) {
  return self->mal_encoder_encode_uinteger(self,cursor, to_encode);
}

int mal_encoder_encode_identifier(mal_encoder_t *self, void *cursor, mal_identifier_t *to_encode) {
  return self->mal_encoder_encode_identifier(self, cursor, to_encode);
}

int mal_encoder_encode_uoctet(mal_encoder_t *self, void *cursor, mal_uoctet_t to_encode) {
  return self->mal_encoder_encode_uoctet(self, cursor, to_encode);
}

int mal_encoder_encode_long(mal_encoder_t *self, void *cursor, mal_long_t to_encode) {
  return self->mal_encoder_encode_long(self, cursor, to_encode);
}

int mal_encoder_encode_ushort(mal_encoder_t *self, void *cursor, mal_ushort_t to_encode) {
  return self->mal_encoder_encode_ushort(self, cursor, to_encode);
}

int mal_encoder_encode_boolean(mal_encoder_t *self, void *cursor, mal_boolean_t to_encode) {
  return self->mal_encoder_encode_boolean(self, cursor, to_encode);
}

void mal_write16(mal_encoder_t *self, int int_value, void *cursor) {
  self->mal_write16(int_value, cursor);
}

void mal_write32(mal_encoder_t *self, int int_value, void *cursor) {
  self->mal_write32(int_value, cursor);
}

void mal_write64(mal_encoder_t *self, long long_value, void *cursor) {
  self->mal_write64(long_value,  cursor);
}

int mal_encoder_encode_duration(mal_encoder_t *self, void *cursor, mal_duration_t to_encode) {
  return self->mal_encoder_encode_duration(self, cursor, to_encode);
}

int mal_encoder_encode_float(mal_encoder_t *self, void *cursor, mal_float_t to_encode) {
  return self->mal_encoder_encode_float(self, cursor, to_encode);
}

int mal_encoder_encode_double(mal_encoder_t *self, void *cursor, mal_double_t to_encode) {
  return self->mal_encoder_encode_double(self, cursor, to_encode);
}

int mal_encoder_encode_octet(mal_encoder_t *self, void *cursor, mal_octet_t to_encode) {
  return self->mal_encoder_encode_octet(self, cursor, to_encode);
}

int mal_encoder_encode_short(mal_encoder_t *self, void *cursor, mal_short_t to_encode) {
  return self->mal_encoder_encode_short(self, cursor, to_encode);
}

int mal_encoder_encode_ulong(mal_encoder_t *self, void *cursor, mal_ulong_t to_encode) {
  return self->mal_encoder_encode_ulong(self, cursor, to_encode);
}

int mal_encoder_encode_finetime(mal_encoder_t *self, void *cursor, mal_finetime_t to_encode) {
  return self->mal_encoder_encode_finetime(self, cursor, to_encode);
}

int mal_encoder_encode_attribute(mal_encoder_t *encoder,
    void *cursor, unsigned char attribute_tag, union mal_attribute_t self) {
  return encoder->mal_encoder_encode_attribute(encoder, cursor, attribute_tag, self);
}

int mal_encoder_encode_attribute_tag(mal_encoder_t *self, void *cursor, unsigned char to_encode) {
  return self->mal_encoder_encode_attribute_tag(self, cursor, to_encode);
}

/*
 * Currently this function can not be used by the encoding modules as it causes
 * a circular dependency. Encoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
void mal_encoder_initialize_functions(
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
    mal_encoder_encode_attribute_tag_fn *mal_encoder_encode_attribute_tag) {
  /* Cursor manipulation */

  self->new_cursor = new_cursor;
  self->cursor_destroy = cursor_destroy;
  self->cursor_init = cursor_init;
  self->cursor_reset = cursor_reset;
  self->cursor_get_length = cursor_get_length;
  self->cursor_get_offset = cursor_get_offset;
  self->cursor_assert = cursor_assert;

  /* Encoding length functions */

  self->mal_encoder_add_string_encoding_length = mal_encoder_add_string_encoding_length;
  self->mal_encoder_add_presence_flag_encoding_length = mal_encoder_add_presence_flag_encoding_length;
  self->mal_encoder_add_short_form_encoding_length = mal_encoder_add_short_form_encoding_length;
  self->mal_encoder_add_integer_encoding_length = mal_encoder_add_integer_encoding_length;
  self->mal_encoder_add_identifier_encoding_length = mal_encoder_add_identifier_encoding_length;
  self->mal_encoder_add_uinteger_encoding_length = mal_encoder_add_uinteger_encoding_length;
  self->mal_encoder_add_uri_encoding_length = mal_encoder_add_uri_encoding_length;
  self->mal_encoder_add_time_encoding_length = mal_encoder_add_time_encoding_length;
  self->mal_encoder_add_uoctet_encoding_length = mal_encoder_add_uoctet_encoding_length;
  self->mal_encoder_add_long_encoding_length = mal_encoder_add_long_encoding_length;
  self->mal_encoder_add_ushort_encoding_length = mal_encoder_add_ushort_encoding_length;
  self->mal_encoder_add_boolean_encoding_length = mal_encoder_add_boolean_encoding_length;
  self->mal_encoder_add_blob_encoding_length = mal_encoder_add_blob_encoding_length;
  self->mal_encoder_add_list_size_encoding_length = mal_encoder_add_list_size_encoding_length;
  self->mal_encoder_add_small_enum_encoding_length = mal_encoder_add_small_enum_encoding_length;
  self->mal_encoder_add_medium_enum_encoding_length = mal_encoder_add_medium_enum_encoding_length;
  self->mal_encoder_add_large_enum_encoding_length = mal_encoder_add_large_enum_encoding_length;
  self->mal_encoder_add_duration_encoding_length = mal_encoder_add_duration_encoding_length;
  self->mal_encoder_add_float_encoding_length = mal_encoder_add_float_encoding_length;
  self->mal_encoder_add_double_encoding_length = mal_encoder_add_double_encoding_length;
  self->mal_encoder_add_octet_encoding_length = mal_encoder_add_octet_encoding_length;
  self->mal_encoder_add_short_encoding_length = mal_encoder_add_short_encoding_length;
  self->mal_encoder_add_ulong_encoding_length = mal_encoder_add_ulong_encoding_length;
  self->mal_encoder_add_finetime_encoding_length = mal_encoder_add_finetime_encoding_length;
  self->mal_encoder_add_attribute_encoding_length = mal_encoder_add_attribute_encoding_length;

  /* Encoding functions */

  self->mal_encoder_encode_string = mal_encoder_encode_string;
  self->mal_encoder_encode_presence_flag = mal_encoder_encode_presence_flag;
  self->mal_encoder_encode_short_form = mal_encoder_encode_short_form;
  self->mal_encoder_encode_small_enum = mal_encoder_encode_small_enum;
  self->mal_encoder_encode_medium_enum = mal_encoder_encode_medium_enum;
  self->mal_encoder_encode_large_enum = mal_encoder_encode_large_enum;
  self->mal_encoder_encode_integer = mal_encoder_encode_integer;
  self->mal_encoder_encode_list_size = mal_encoder_encode_list_size;
  self->mal_encoder_encode_uri = mal_encoder_encode_uri;
  self->mal_encoder_encode_blob = mal_encoder_encode_blob;
  self->mal_encoder_encode_time = mal_encoder_encode_time;
  self->mal_encoder_encode_uinteger = mal_encoder_encode_uinteger;
  self->mal_encoder_encode_identifier = mal_encoder_encode_identifier;
  self->mal_encoder_encode_uoctet = mal_encoder_encode_uoctet;
  self->mal_encoder_encode_long = mal_encoder_encode_long;
  self->mal_encoder_encode_ushort = mal_encoder_encode_ushort;
  self->mal_encoder_encode_boolean = mal_encoder_encode_boolean;
  self->mal_write16 = mal_write16;
  self->mal_write32 = mal_write32;
  self->mal_write64 = mal_write64;
  self->mal_encoder_encode_duration = mal_encoder_encode_duration;
  self->mal_encoder_encode_float = mal_encoder_encode_float;
  self->mal_encoder_encode_double = mal_encoder_encode_double;
  self->mal_encoder_encode_octet = mal_encoder_encode_octet;
  self->mal_encoder_encode_short = mal_encoder_encode_short;
  self->mal_encoder_encode_ulong = mal_encoder_encode_ulong;
  self->mal_encoder_encode_finetime = mal_encoder_encode_finetime;
  self->mal_encoder_encode_attribute = mal_encoder_encode_attribute;
  self->mal_encoder_encode_attribute_tag = mal_encoder_encode_attribute_tag;
}

/*
 * Test
 */

void mal_encoder_test(bool verbose) {
  printf(" * mal_encoding: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

