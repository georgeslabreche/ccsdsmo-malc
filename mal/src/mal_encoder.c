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

/** Creates a new encoding cursor, ready to calculate encoding size */
void *mal_encoder_new_cursor(mal_encoder_t *self) {
  return self->new_cursor();
}

/** Resets an encoding cursor for reuse, ready to calculate encoding size */
void mal_encoder_cursor_reset(mal_encoder_t *self, void *cursor) {
  self->cursor_reset(cursor);
}

/** Initializes the encoding cursor for encoding phase */
void mal_encoder_cursor_init(
    mal_encoder_t *self,
    void *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  self->cursor_init(cursor, bytes, length, offset);
}

/** Destroy an encoding cursor */
void mal_encoder_cursor_destroy(mal_encoder_t *self, void *cursor) {
  self->cursor_destroy(cursor);
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

int mal_encoder_add_presence_flag_encoding_length(mal_encoder_t *self, mal_boolean_t to_encode, void *cursor) {
  return self->mal_encoder_add_presence_flag_encoding_length(self, to_encode, cursor);
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

int mal_encoder_add_attribute_tag_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, void *cursor) {
  return encoder->mal_encoder_add_attribute_tag_encoding_length(encoder, attribute_tag, cursor);
}

int mal_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor) {
  return encoder->mal_encoder_add_attribute_encoding_length(encoder, attribute_tag, self, cursor);
}

int mal_encoder_add_entitykey_encoding_length(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_entitykey_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_entityrequest_encoding_length(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_entityrequest_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_file_encoding_length(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_file_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_idbooleanpair_encoding_length(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_idbooleanpair_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_namedvalue_encoding_length(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_namedvalue_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_pair_encoding_length(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_pair_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_subscription_encoding_length(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_subscription_encoding_length(self, mal_encoder, cursor);
}
int mal_encoder_add_updateheader_encoding_length(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_add_updateheader_encoding_length(self, mal_encoder, cursor);
}

int mal_encoder_blob_list_add_encoding_length(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_blob_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_boolean_list_add_encoding_length(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_boolean_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_double_list_add_encoding_length(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_double_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_duration_list_add_encoding_length(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_duration_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_entitykey_list_add_encoding_length(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_entitykey_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_entityrequest_list_add_encoding_length(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_entityrequest_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_file_list_add_encoding_length(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_file_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_finetime_list_add_encoding_length(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_finetime_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_float_list_add_encoding_length(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_float_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_idbooleanpair_list_add_encoding_length(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_idbooleanpair_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_identifier_list_add_encoding_length(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_identifier_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_integer_list_add_encoding_length(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_integer_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_interactiontype_list_add_encoding_length(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_interactiontype_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_long_list_add_encoding_length(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_long_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_namedvalue_list_add_encoding_length(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_namedvalue_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_octet_list_add_encoding_length(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_octet_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_pair_list_add_encoding_length(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_pair_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_qoslevel_list_add_encoding_length(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_qoslevel_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_sessiontype_list_add_encoding_length(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_sessiontype_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_short_list_add_encoding_length(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_short_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_string_list_add_encoding_length(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_string_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_subscription_list_add_encoding_length(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_subscription_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_time_list_add_encoding_length(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_time_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_uinteger_list_add_encoding_length(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_uinteger_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_ulong_list_add_encoding_length(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_ulong_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_uoctet_list_add_encoding_length(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_uoctet_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_updateheader_list_add_encoding_length(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_updateheader_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_updatetype_list_add_encoding_length(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_updatetype_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_uri_list_add_encoding_length(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_uri_list_add_encoding_length(self, encoder,cursor);
}
int mal_encoder_ushort_list_add_encoding_length(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_ushort_list_add_encoding_length(self, encoder,cursor);
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

int mal_encoder_encode_entitykey(mal_entitykey_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_entitykey(self, mal_encoder, cursor);
}
int mal_encoder_encode_entityrequest(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_entityrequest(self, mal_encoder, cursor);
}
int mal_encoder_encode_file(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_file(self, mal_encoder, cursor);
}
int mal_encoder_encode_idbooleanpair(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_idbooleanpair(self, mal_encoder, cursor);
}
int mal_encoder_encode_namedvalue(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_namedvalue(self, mal_encoder, cursor);
}
int mal_encoder_encode_pair(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_pair(self, mal_encoder, cursor);
}
int mal_encoder_encode_subscription(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_subscription(self, mal_encoder, cursor);
}
int mal_encoder_encode_updateheader(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor) {
  return mal_encoder->mal_encoder_encode_updateheader(self, mal_encoder, cursor);
}

int mal_encoder_encode_blob_list(mal_blob_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_blob_list(self, encoder, cursor);
}
int mal_encoder_encode_boolean_list(mal_boolean_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_boolean_list(self, encoder, cursor);
}
int mal_encoder_encode_double_list(mal_double_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_double_list(self, encoder, cursor);
}
int mal_encoder_encode_duration_list(mal_duration_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_duration_list(self, encoder, cursor);
}
int mal_encoder_encode_entitykey_list(mal_entitykey_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_entitykey_list(self, encoder, cursor);
}
int mal_encoder_encode_entityrequest_list(mal_entityrequest_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_entityrequest_list(self, encoder, cursor);
}
int mal_encoder_encode_file_list(mal_file_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_file_list(self, encoder, cursor);
}
int mal_encoder_encode_finetime_list(mal_finetime_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_finetime_list(self, encoder, cursor);
}
int mal_encoder_encode_float_list(mal_float_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_float_list(self, encoder, cursor);
}
int mal_encoder_encode_idbooleanpair_list(mal_idbooleanpair_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_idbooleanpair_list(self, encoder, cursor);
}
int mal_encoder_encode_identifier_list(mal_identifier_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_identifier_list(self, encoder, cursor);
}
int mal_encoder_encode_integer_list(mal_integer_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_integer_list(self, encoder, cursor);
}
int mal_encoder_encode_interactiontype_list(mal_interactiontype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_interactiontype_list(self, encoder, cursor);
}
int mal_encoder_encode_long_list(mal_long_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_long_list(self, encoder, cursor);
}
int mal_encoder_encode_namedvalue_list(mal_namedvalue_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_namedvalue_list(self, encoder, cursor);
}
int mal_encoder_encode_octet_list(mal_octet_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_octet_list(self, encoder, cursor);
}
int mal_encoder_encode_pair_list(mal_pair_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_pair_list(self, encoder, cursor);
}
int mal_encoder_encode_qoslevel_list(mal_qoslevel_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_qoslevel_list(self, encoder, cursor);
}
int mal_encoder_encode_sessiontype_list(mal_sessiontype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_sessiontype_list(self, encoder, cursor);
}
int mal_encoder_encode_short_list(mal_short_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_short_list(self, encoder, cursor);
}
int mal_encoder_encode_string_list(mal_string_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_string_list(self, encoder, cursor);
}
int mal_encoder_encode_subscription_list(mal_subscription_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_subscription_list(self, encoder, cursor);
}
int mal_encoder_encode_time_list(mal_time_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_time_list(self, encoder, cursor);
}
int mal_encoder_encode_uinteger_list(mal_uinteger_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_uinteger_list(self, encoder, cursor);
}
int mal_encoder_encode_ulong_list(mal_ulong_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_ulong_list(self, encoder, cursor);
}
int mal_encoder_encode_uoctet_list(mal_uoctet_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_uoctet_list(self, encoder, cursor);
}
int mal_encoder_encode_updateheader_list(mal_updateheader_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_updateheader_list(self, encoder, cursor);
}
int mal_encoder_encode_updatetype_list(mal_updatetype_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_updatetype_list(self, encoder, cursor);
}
int mal_encoder_encode_uri_list(mal_uri_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_uri_list(self, encoder, cursor);
}
int mal_encoder_encode_ushort_list(mal_ushort_list_t *self, mal_encoder_t *encoder, void *cursor) {
  return encoder->mal_encoder_encode_ushort_list(self, encoder, cursor);
}

/*
 * Currently this function can not be used by the encoding modules as it causes
 * a circular dependency. Encoding modules must declare an initialization function
 * with exactly the same signature and code.
 */
void mal_encoder_initialize_functions(
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
    mal_encoder_encode_ushort_list_fn *mal_encoder_encode_ushort_list) {
  /* Cursor manipulation */

  self->new_cursor = new_cursor;
  self->cursor_reset = cursor_reset;
  self->cursor_init = cursor_init;
  self->cursor_destroy = cursor_destroy;
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
  self->mal_encoder_add_attribute_tag_encoding_length = mal_encoder_add_attribute_tag_encoding_length;
  self->mal_encoder_add_attribute_encoding_length = mal_encoder_add_attribute_encoding_length;

  self->mal_encoder_add_entitykey_encoding_length = mal_encoder_add_entitykey_encoding_length;
  self->mal_encoder_add_entityrequest_encoding_length = mal_encoder_add_entityrequest_encoding_length;
  self->mal_encoder_add_file_encoding_length = mal_encoder_add_file_encoding_length;
  self->mal_encoder_add_idbooleanpair_encoding_length = mal_encoder_add_idbooleanpair_encoding_length;
  self->mal_encoder_add_namedvalue_encoding_length = mal_encoder_add_namedvalue_encoding_length;
  self->mal_encoder_add_pair_encoding_length = mal_encoder_add_pair_encoding_length;
  self->mal_encoder_add_subscription_encoding_length = mal_encoder_add_subscription_encoding_length;
  self->mal_encoder_add_updateheader_encoding_length = mal_encoder_add_updateheader_encoding_length;

  self->mal_encoder_blob_list_add_encoding_length = mal_encoder_blob_list_add_encoding_length;
  self->mal_encoder_boolean_list_add_encoding_length = mal_encoder_boolean_list_add_encoding_length;
  self->mal_encoder_double_list_add_encoding_length = mal_encoder_double_list_add_encoding_length;
  self->mal_encoder_duration_list_add_encoding_length = mal_encoder_duration_list_add_encoding_length;
  self->mal_encoder_entitykey_list_add_encoding_length = mal_encoder_entitykey_list_add_encoding_length;
  self->mal_encoder_entityrequest_list_add_encoding_length = mal_encoder_entityrequest_list_add_encoding_length;
  self->mal_encoder_file_list_add_encoding_length = mal_encoder_file_list_add_encoding_length;
  self->mal_encoder_finetime_list_add_encoding_length = mal_encoder_finetime_list_add_encoding_length;
  self->mal_encoder_float_list_add_encoding_length = mal_encoder_float_list_add_encoding_length;
  self->mal_encoder_idbooleanpair_list_add_encoding_length =  mal_encoder_idbooleanpair_list_add_encoding_length;
  self->mal_encoder_identifier_list_add_encoding_length = mal_encoder_identifier_list_add_encoding_length;
  self->mal_encoder_integer_list_add_encoding_length = mal_encoder_integer_list_add_encoding_length;
  self->mal_encoder_interactiontype_list_add_encoding_length =  mal_encoder_interactiontype_list_add_encoding_length;
  self->mal_encoder_long_list_add_encoding_length = mal_encoder_long_list_add_encoding_length;
  self->mal_encoder_namedvalue_list_add_encoding_length = mal_encoder_namedvalue_list_add_encoding_length;
  self->mal_encoder_octet_list_add_encoding_length = mal_encoder_octet_list_add_encoding_length;
  self->mal_encoder_pair_list_add_encoding_length = mal_encoder_pair_list_add_encoding_length;
  self->mal_encoder_qoslevel_list_add_encoding_length = mal_encoder_qoslevel_list_add_encoding_length;
  self->mal_encoder_sessiontype_list_add_encoding_length = mal_encoder_sessiontype_list_add_encoding_length;
  self->mal_encoder_short_list_add_encoding_length = mal_encoder_short_list_add_encoding_length;
  self->mal_encoder_string_list_add_encoding_length = mal_encoder_string_list_add_encoding_length;
  self->mal_encoder_subscription_list_add_encoding_length = mal_encoder_subscription_list_add_encoding_length;
  self->mal_encoder_time_list_add_encoding_length = mal_encoder_time_list_add_encoding_length;
  self->mal_encoder_uinteger_list_add_encoding_length = mal_encoder_uinteger_list_add_encoding_length;
  self->mal_encoder_ulong_list_add_encoding_length = mal_encoder_ulong_list_add_encoding_length;
  self->mal_encoder_uoctet_list_add_encoding_length = mal_encoder_uoctet_list_add_encoding_length;
  self->mal_encoder_updateheader_list_add_encoding_length = mal_encoder_updateheader_list_add_encoding_length;
  self->mal_encoder_updatetype_list_add_encoding_length = mal_encoder_updatetype_list_add_encoding_length;
  self->mal_encoder_uri_list_add_encoding_length = mal_encoder_uri_list_add_encoding_length;
  self->mal_encoder_ushort_list_add_encoding_length = mal_encoder_ushort_list_add_encoding_length;

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

  self->mal_encoder_encode_entitykey = mal_encoder_encode_entitykey;
  self->mal_encoder_encode_entityrequest = mal_encoder_encode_entityrequest;
  self->mal_encoder_encode_file = mal_encoder_encode_file;
  self->mal_encoder_encode_idbooleanpair = mal_encoder_encode_idbooleanpair;
  self->mal_encoder_encode_namedvalue = mal_encoder_encode_namedvalue;
  self->mal_encoder_encode_pair = mal_encoder_encode_pair;
  self->mal_encoder_encode_subscription = mal_encoder_encode_subscription;
  self->mal_encoder_encode_updateheader = mal_encoder_encode_updateheader;

  self->mal_encoder_encode_blob_list = mal_encoder_encode_blob_list;
  self->mal_encoder_encode_boolean_list = mal_encoder_encode_boolean_list;
  self->mal_encoder_encode_double_list = mal_encoder_encode_double_list;
  self->mal_encoder_encode_duration_list = mal_encoder_encode_duration_list;
  self->mal_encoder_encode_entitykey_list = mal_encoder_encode_entitykey_list;
  self->mal_encoder_encode_entityrequest_list = mal_encoder_encode_entityrequest_list;
  self->mal_encoder_encode_file_list = mal_encoder_encode_file_list;
  self->mal_encoder_encode_finetime_list = mal_encoder_encode_finetime_list;
  self->mal_encoder_encode_float_list = mal_encoder_encode_float_list;
  self->mal_encoder_encode_idbooleanpair_list = mal_encoder_encode_idbooleanpair_list;
  self->mal_encoder_encode_identifier_list = mal_encoder_encode_identifier_list;
  self->mal_encoder_encode_integer_list = mal_encoder_encode_integer_list;
  self->mal_encoder_encode_interactiontype_list = mal_encoder_encode_interactiontype_list;
  self->mal_encoder_encode_long_list = mal_encoder_encode_long_list;
  self->mal_encoder_encode_namedvalue_list = mal_encoder_encode_namedvalue_list;
  self->mal_encoder_encode_octet_list = mal_encoder_encode_octet_list;
  self->mal_encoder_encode_pair_list = mal_encoder_encode_pair_list;
  self->mal_encoder_encode_qoslevel_list = mal_encoder_encode_qoslevel_list;
  self->mal_encoder_encode_sessiontype_list = mal_encoder_encode_sessiontype_list;
  self->mal_encoder_encode_short_list = mal_encoder_encode_short_list;
  self->mal_encoder_encode_string_list = mal_encoder_encode_string_list;
  self->mal_encoder_encode_subscription_list = mal_encoder_encode_subscription_list;
  self->mal_encoder_encode_time_list = mal_encoder_encode_time_list;
  self->mal_encoder_encode_uinteger_list = mal_encoder_encode_uinteger_list;
  self->mal_encoder_encode_ulong_list = mal_encoder_encode_ulong_list;
  self->mal_encoder_encode_uoctet_list = mal_encoder_encode_uoctet_list;
  self->mal_encoder_encode_updateheader_list = mal_encoder_encode_updateheader_list;
  self->mal_encoder_encode_updatetype_list = mal_encoder_encode_updatetype_list;
  self->mal_encoder_encode_uri_list = mal_encoder_encode_uri_list;
  self->mal_encoder_encode_ushort_list = mal_encoder_encode_ushort_list;
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

