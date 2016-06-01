/*
 */

// TODO (AF): To remove
//#include "mal.h"
#include "malattributes.h"
#include "mal_decoder.h"

int mal_decoder_get_encoding_format_code(mal_decoder_t *self) {
  return self->encoding_format_code;
}

void mal_decoder_set_log_level(mal_decoder_t *self, int level) {
  clog_set_level(&self->logger, level);
}

clog_logger_t mal_decoder_get_logger(mal_decoder_t *self) {
  return self->logger;
}

/*
 * Cursor manipulation.
 */

void *mal_decoder_new_cursor(mal_decoder_t *self, char *bytes, unsigned int length, unsigned int offset) {
  return self->new_cursor(bytes, length, offset);
}

void mal_decoder_cursor_destroy(mal_decoder_t *self, void *cursor) {
  self->cursor_destroy(cursor);
}

void mal_decoder_cursor_init(mal_decoder_t *self, void *cursor, char *bytes, unsigned int length, unsigned int offset) {
  self->cursor_init(cursor, bytes, length, offset);
}


void mal_decoder_cursor_reset(mal_decoder_t *self, void *cursor) {
  self->cursor_reset(cursor);
}


unsigned int mal_decoder_cursor_get_length(mal_decoder_t *self, void *cursor) {
  return self->cursor_get_length(cursor);
}


unsigned int mal_decoder_cursor_get_offset(mal_decoder_t *self, void *cursor) {
  return self->cursor_get_offset(cursor);
}


void mal_decoder_cursor_assert(mal_decoder_t *self, void *cursor) {
  self->cursor_assert(cursor);
}

/*
 * Handles structure initialization.
 *
 * TODO (AF): The use of this function in malbinary causes a circular
 * dependency !!
 */
void mal_decoder_initialize_functions(
    mal_decoder_t *self,
    mal_decoder_new_cursor_fn *new_cursor,
    mal_decoder_cursor_destroy_fn *cursor_destroy,
    mal_decoder_cursor_init_fn *cursor_init,
    mal_decoder_cursor_reset_fn *cursor_reset,
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
    mal_decoder_decode_attribute_tag_fn *mal_decoder_decode_attribute_tag) {
  /*
   * Cursor manipulation.
   */

  self->new_cursor = new_cursor;
  self->cursor_destroy = cursor_destroy;
  self->cursor_init = cursor_init;
  self->cursor_reset = cursor_reset;
  self->cursor_get_length = cursor_get_length;
  self->cursor_get_offset = cursor_get_offset;
  self->cursor_assert = cursor_assert;

  /*
   * Decoding functions.
   */

  self->mal_read16 = mal_read16;
  self->mal_read32 = mal_read32;
  self->mal_read64 = mal_read64;
  self->mal_decoder_decode_string = mal_decoder_decode_string;
  self->mal_decoder_decode_presence_flag = mal_decoder_decode_presence_flag;
  self->mal_decoder_decode_short_form = mal_decoder_decode_short_form;
  self->mal_decoder_decode_small_enum = mal_decoder_decode_small_enum;
  self->mal_decoder_decode_medium_enum = mal_decoder_decode_medium_enum;
  self->mal_decoder_decode_large_enum = mal_decoder_decode_large_enum;
  self->mal_decoder_decode_integer = mal_decoder_decode_integer;
  self->mal_decoder_decode_list_size = mal_decoder_decode_list_size;
  self->mal_decoder_decode_uri = mal_decoder_decode_uri;
  self->mal_decoder_decode_blob = mal_decoder_decode_blob;
  self->mal_decoder_decode_time = mal_decoder_decode_time;
  self->mal_decoder_decode_uinteger = mal_decoder_decode_uinteger;
  self->mal_decoder_decode_identifier = mal_decoder_decode_identifier;
  self->mal_decoder_decode_uoctet = mal_decoder_decode_uoctet;
  self->mal_decoder_decode_long = mal_decoder_decode_long;
  self->mal_decoder_decode_ushort = mal_decoder_decode_ushort;
  self->mal_decoder_decode_boolean = mal_decoder_decode_boolean;
  self->mal_decoder_decode_duration = mal_decoder_decode_duration;
  self->mal_decoder_decode_float = mal_decoder_decode_float;
  self->mal_decoder_decode_double = mal_decoder_decode_double;
  self->mal_decoder_decode_octet = mal_decoder_decode_octet;
  self->mal_decoder_decode_short = mal_decoder_decode_short;
  self->mal_decoder_decode_ulong = mal_decoder_decode_ulong;
  self->mal_decoder_decode_finetime = mal_decoder_decode_finetime;
  self->mal_decoder_decode_attribute = mal_decoder_decode_attribute;
  self->mal_decoder_decode_attribute_tag = mal_decoder_decode_attribute_tag;
}

/*
 * Test
 */

void mal_decoder_test(bool verbose) {
  printf(" * mal_encoding: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

