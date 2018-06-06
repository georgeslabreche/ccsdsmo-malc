/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2018 CNES
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

#include "malsplitbinary.h"

mal_decoder_t *malsplitbinary_decoder_new() {
  mal_decoder_t *self = (mal_decoder_t *) malloc(sizeof(mal_decoder_t));
  if (!self)
    return NULL;

  self->encoding_format_code = MALSPLITBINARY_FORMAT_CODE;
  self->varint_supported = true;
  self->logger = CLOG_WARN_LEVEL;

  malsplitbinary_init_decode_functions(self);

  return self;
}

void *malsplitbinary_decoder_new_cursor(
    char *bytes,
    unsigned int length,
    unsigned int offset) {
  malsplitbinary_cursor_t *cursor = (malsplitbinary_cursor_t *) malloc(sizeof(malsplitbinary_cursor_t));
  if (! cursor) return NULL;
  malsplitbinary_decoder_cursor_init(cursor, bytes, length, offset);

  return (void *) cursor;
}

int malsplitbinary_decoder_decode_string(mal_decoder_t *self,
    void *cursor, mal_string_t **result) {
  return malbinary_decoder_decode_string(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_presence_flag(mal_decoder_t *self,
    void *cursor, bool *result) {
  return malsplitbinary_decoder_decode_boolean(self, cursor, result);
}

int malsplitbinary_decoder_decode_integer(mal_decoder_t *self,
    void *cursor, mal_integer_t *result) {
  return malbinary_decoder_decode_integer(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_short_form(mal_decoder_t *self,
    void *cursor, long *result) {
  return malbinary_decoder_decode_short_form(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_list_size(mal_decoder_t *self,
    void *cursor, unsigned int *result) {
  return malbinary_decoder_decode_list_size(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_small_enum(mal_decoder_t *self,
    void *cursor, int *result) {
  return malbinary_decoder_decode_small_enum(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_medium_enum(mal_decoder_t *self,
    void *cursor, int *result) {
  return malbinary_decoder_decode_medium_enum(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_large_enum(mal_decoder_t *self,
    void *cursor, int *result) {
  return malbinary_decoder_decode_large_enum(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_uri(mal_decoder_t *self,
    void *cursor, mal_uri_t **result) {
  return malbinary_decoder_decode_uri(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_blob(mal_decoder_t *self,
    void *cursor, mal_blob_t **result) {
  return malbinary_decoder_decode_blob(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_time(mal_decoder_t *self,
    void *cursor, mal_time_t *result) {
  return malbinary_decoder_decode_time(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_uinteger(mal_decoder_t *self,
    void *cursor, mal_uinteger_t *result) {
  return malbinary_decoder_decode_uinteger(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_identifier(mal_decoder_t *self,
    void *cursor, mal_identifier_t **result) {
  return malbinary_decoder_decode_identifier(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_uoctet(mal_decoder_t *self,
    void *cursor, mal_uoctet_t *result) {
  return malbinary_decoder_decode_uoctet(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_long(mal_decoder_t *self,
    void *cursor, mal_long_t *result) {
  return malbinary_decoder_decode_long(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_ushort(mal_decoder_t *self,
    void *cursor, mal_ushort_t *result) {
  return malbinary_decoder_decode_ushort(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_boolean(mal_decoder_t *self,
    void *cursor, mal_boolean_t *result) {
  if (((malsplitbinary_cursor_t *) cursor)->bitfield_idx < ((malsplitbinary_cursor_t *) cursor)->bitfield_length) {
    char *bitfield = malsplitbinary_cursor_get_bitfield_ptr((malsplitbinary_cursor_t *) cursor);
    unsigned int v = bitfield[(((malsplitbinary_cursor_t *) cursor)->bitfield_idx) >> 3];
    (*result) = (v >> ((malsplitbinary_cursor_t *) cursor)->bitfield_idx % 8) & 1;
  } else {
    (*result) = false;
  }
  ((malsplitbinary_cursor_t *) cursor)->bitfield_idx++;
  return 0;
}

int malsplitbinary_decoder_decode_attribute_tag(mal_decoder_t *self,
    void *cursor, unsigned char *result) {
  return malbinary_decoder_decode_attribute_tag(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_duration(mal_decoder_t *self,
    void *cursor, mal_duration_t *result) {
  return malbinary_decoder_decode_duration(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_float(mal_decoder_t *self,
    void *cursor, mal_float_t *result) {
  return malbinary_decoder_decode_float(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_double(mal_decoder_t *self,
    void *cursor, mal_double_t *result) {
  return malbinary_decoder_decode_double(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_octet(mal_decoder_t *self,
    void *cursor, mal_octet_t *result) {
  return malbinary_decoder_decode_octet(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_short(mal_decoder_t *self,
    void *cursor, mal_short_t *result) {
  return malbinary_decoder_decode_short(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_ulong(mal_decoder_t *self,
    void *cursor, mal_ulong_t *result) {
  return malbinary_decoder_decode_ulong(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_finetime(mal_decoder_t *self,
    void *cursor, mal_finetime_t *result) {
  return malbinary_decoder_decode_finetime(self, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, result);
}

int malsplitbinary_decoder_decode_attribute(mal_decoder_t *malsplitbinary_decoder,
    void *cursor, unsigned char attribute_tag, union mal_attribute_t *self) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_blob(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->blob_value);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_boolean(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->boolean_value);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_duration(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->duration_value);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_float(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->float_value);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_double(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->double_value);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_identifier(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->identifier_value);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_octet(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->octet_value);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_uoctet(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->uoctet_value);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_short(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->short_value);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_ushort(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->ushort_value);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_integer(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->integer_value);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_uinteger(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->uinteger_value);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_long(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->long_value);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_ulong(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->ulong_value);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_string(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->string_value);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_time(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->time_value);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_finetime(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->finetime_value);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malsplitbinary_decoder_decode_uri(malsplitbinary_decoder, &((malsplitbinary_cursor_t *)cursor)->malbinary_cursor, &self->uri_value);
    break;
  default:
    clog_error(malsplitbinary_decoder->logger, "Unexpected attribute tag value: %d\n", attribute_tag);
    return -1;
  }
  return rc;
}

// NOTE: The malsplitbinary decoding functions should be private and only used through
// the mal_decoder_t structure.

void malsplitbinary_init_decode_functions(mal_decoder_t *self) {
  mal_decoder_initialize_functions(self,
      malsplitbinary_decoder_new_cursor,
      malsplitbinary_decoder_cursor_reset,
      malsplitbinary_cursor_destroy,
      malsplitbinary_cursor_get_length,
      malsplitbinary_cursor_get_offset,
      malsplitbinary_cursor_assert,
      malbinary_read16,//TODO ?
      malbinary_read32,//TODO ?
      malbinary_read64,//TODO ?
      malsplitbinary_decoder_decode_string,
      malsplitbinary_decoder_decode_presence_flag,
      malsplitbinary_decoder_decode_short_form,
      malsplitbinary_decoder_decode_small_enum,
      malsplitbinary_decoder_decode_medium_enum,
      malsplitbinary_decoder_decode_large_enum,
      malsplitbinary_decoder_decode_integer,
      malsplitbinary_decoder_decode_list_size,
      malsplitbinary_decoder_decode_uri,
      malsplitbinary_decoder_decode_blob,
      malsplitbinary_decoder_decode_time,
      malsplitbinary_decoder_decode_uinteger,
      malsplitbinary_decoder_decode_identifier,
      malsplitbinary_decoder_decode_uoctet,
      malsplitbinary_decoder_decode_long,
      malsplitbinary_decoder_decode_ushort,
      malsplitbinary_decoder_decode_boolean,
      malsplitbinary_decoder_decode_duration,
      malsplitbinary_decoder_decode_float,
      malsplitbinary_decoder_decode_double,
      malsplitbinary_decoder_decode_octet,
      malsplitbinary_decoder_decode_short,
      malsplitbinary_decoder_decode_ulong,
      malsplitbinary_decoder_decode_finetime,
      malsplitbinary_decoder_decode_attribute,
      malsplitbinary_decoder_decode_attribute_tag,

      mal_entitykey_decode_malbinary,
      mal_entityrequest_decode_malbinary,
      mal_file_decode_malbinary,
      mal_idbooleanpair_decode_malbinary,
      mal_namedvalue_decode_malbinary,
      mal_pair_decode_malbinary,
      mal_subscription_decode_malbinary,
      mal_updateheader_decode_malbinary,

      mal_blob_list_decode_malbinary,
      mal_boolean_list_decode_malbinary,
      mal_double_list_decode_malbinary,
      mal_duration_list_decode_malbinary,
      mal_entitykey_list_decode_malbinary,
      mal_entityrequest_list_decode_malbinary,
      mal_file_list_decode_malbinary,
      mal_finetime_list_decode_malbinary,
      mal_float_list_decode_malbinary,
      mal_idbooleanpair_list_decode_malbinary,
      mal_identifier_list_decode_malbinary,
      mal_integer_list_decode_malbinary,
      mal_interactiontype_list_decode_malbinary,
      mal_long_list_decode_malbinary,
      mal_namedvalue_list_decode_malbinary,
      mal_octet_list_decode_malbinary,
      mal_pair_list_decode_malbinary,
      mal_qoslevel_list_decode_malbinary,
      mal_sessiontype_list_decode_malbinary,
      mal_short_list_decode_malbinary,
      mal_string_list_decode_malbinary,
      mal_subscription_list_decode_malbinary,
      mal_time_list_decode_malbinary,
      mal_uinteger_list_decode_malbinary,
      mal_ulong_list_decode_malbinary,
      mal_uoctet_list_decode_malbinary,
      mal_updateheader_list_decode_malbinary,
      mal_updatetype_list_decode_malbinary,
      mal_uri_list_decode_malbinary,
      mal_ushort_list_decode_malbinary);
}

void malsplitbinary_decoder_test(bool verbose) {
  printf(" * malsplitbinary_decoder: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

