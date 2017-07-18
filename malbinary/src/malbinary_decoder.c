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

#include "malbinary.h"

mal_decoder_t *malbinary_decoder_new(bool varint_supported) {
  mal_decoder_t *self = (mal_decoder_t *) malloc(sizeof(mal_decoder_t));
  if (!self)
    return NULL;

  self->encoding_format_code = MALBINARY_FORMAT_CODE;
  self->varint_supported = varint_supported;
  self->logger = CLOG_WARN_LEVEL;

  malbinary_init_decode_functions(self);

  return self;
}

void *malbinary_decoder_new_cursor(char *bytes, unsigned int length, unsigned int offset) {
  malbinary_cursor_t *cursor = (malbinary_cursor_t *) malloc(sizeof(malbinary_cursor_t));
  if (! cursor) return NULL;

  malbinary_cursor_init(cursor, bytes, length, offset);

  return (void *) cursor;
}

void  malbinary_decoder_cursor_reset(void *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  malbinary_cursor_reset(cursor);
  malbinary_cursor_init(cursor, bytes, length, offset);
}

short malbinary_read16(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;;
  short res = (short) ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF) << 8);
  res = (short) (res | (((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF));
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return res;
}

int malbinary_read32(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  int res = (((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF) << 24;
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF) << 16);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF) << 8);
  res = res | (((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFF);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return res;
}

long malbinary_read64(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  long res = ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 56);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 48);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 40);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 32);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 24);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 16);
  res = res | ((((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL) << 8);
  res = res | (((malbinary_cursor_t *) cursor)->body_ptr[index++] & 0xFFL);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return res;
}

unsigned short malbinary_read_uvarshort(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  unsigned short value = 0;
  int i;
  short b;
  for (i = 0; ((b = ((malbinary_cursor_t *) cursor)->body_ptr[index++]) & 0x80) != 0; i += 7) {
    value |= (b & 0x7f) << i;
  }
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return value | b << i;
}

unsigned int malbinary_read_uvarint(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  unsigned int value = 0;
  int i;
  int b;
  for (i = 0; ((b = ((malbinary_cursor_t *) cursor)->body_ptr[index++]) & 0x80) != 0; i += 7) {
    value |= (b & 0x7f) << i;
  }
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return value | b << i;
}

unsigned long malbinary_read_uvarlong(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  unsigned long value = 0L;
  int i;
  long b;
  for (i = 0; ((b = ((malbinary_cursor_t *) cursor)->body_ptr[index++]) & 0x80L) != 0L; i += 7) {
    value |= (b & 0x7fL) << i;
  }
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return value | b << i;
}

short malbinary_read_varshort(void *cursor) {
  unsigned short i = malbinary_read_uvarshort(cursor);
  short s = 0;
  if ((i&0x1) != 0)
    s = -1;
  short temp = i >> 1;
  temp = temp ^ s;
  return temp;
}

int malbinary_read_varint(void *cursor) {
  unsigned int i = malbinary_read_uvarint(cursor);
  int s = 0;
  if ((i&0x1) != 0)
    s = 0xFFFFFFFF;
  int temp = i >> 1;
  temp = temp ^ s;
  return temp;
}

long malbinary_read_varlong(void *cursor) {
  unsigned long l = malbinary_read_uvarlong(cursor);
  long s = 0L;
  if ((l&0x1) != 0)
    s = 0xFFFFFFFFFFFFFFFFL;
  long temp = l >> 1;

  temp = temp ^ s;
  return temp;
}

char *malbinary_read_str(mal_decoder_t *self, void *cursor) {
  unsigned int length;
  if (self->varint_supported)
    length = malbinary_read_uvarint(cursor);
  else
    length = malbinary_read32(cursor);

  if (length < 0) {
    char *array = (char *) malloc(1);
    if (array == NULL)
      return NULL;
    array[0] = '\0';
    return array;
  }

  char *array = (char *) malloc(length + 1);
  if (array == NULL)
    return NULL;

  bcopy(& ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset], array, length);
  array[length] = '\0';

  ((malbinary_cursor_t *) cursor)->body_offset += length;
  return array;
}

void malbinary_read_array(char *array, unsigned int length, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  for (int i = 0; i < length; i++) {
    array[i] = ((malbinary_cursor_t *) cursor)->body_ptr[index++];
  }
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

char malbinary_read(void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  char res = ((malbinary_cursor_t *) cursor)->body_ptr[index++];
  ((malbinary_cursor_t *) cursor)->body_offset = index;
  return res;
}

int malbinary_decoder_decode_string(mal_decoder_t *self, void *cursor, mal_string_t **result) {
  (*result) = malbinary_read_str(self, cursor);
  if (*result == NULL)
    return -1;
  return 0;
}

int malbinary_decoder_decode_presence_flag(mal_decoder_t *self, void *cursor, bool *result) {
  char flag = malbinary_read(cursor);
  if (flag == 1) {
    (*result) = true;
  } else {
    (*result) = false;
  }
  return 0;
}

int malbinary_decoder_decode_integer(mal_decoder_t *self, void *cursor, mal_integer_t *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_varint(cursor);
  else
    (*result) = malbinary_read32(cursor);
  return 0;
}

int malbinary_decoder_decode_short_form(mal_decoder_t *self, void *cursor, long *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_varlong(cursor);
  else
    (*result) = malbinary_read64(cursor);
  return 0;
}

int malbinary_decoder_decode_list_size(mal_decoder_t *self, void *cursor, unsigned int *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_uvarint(cursor);
  else
    (*result) = malbinary_read32(cursor);
  return 0;
}

int malbinary_decoder_decode_small_enum(mal_decoder_t *self, void *cursor, int *result) {
  (*result) = malbinary_read(cursor);
  return 0;
}

int malbinary_decoder_decode_medium_enum(mal_decoder_t *self, void *cursor, int *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_uvarshort(cursor);
  else
    (*result) = malbinary_read16(cursor);
  return 0;
}

int malbinary_decoder_decode_large_enum(mal_decoder_t *self, void *cursor, int *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_uvarint(cursor);
  else
    (*result) = malbinary_read32(cursor);
  return 0;
}

int malbinary_decoder_decode_uri(mal_decoder_t *self, void *cursor, mal_uri_t **result) {
  int rc = 0;
  (*result) = malbinary_read_str(self, cursor);
  return rc;
}

int malbinary_decoder_decode_blob(mal_decoder_t *self, void *cursor, mal_blob_t **result) {
  int rc = 0;
  unsigned int length;
  if (self->varint_supported)
    length = malbinary_read_uvarint(cursor);
  else
    length = malbinary_read32(cursor);

  if (length < 0) {
    (*result) = NULL;
  } else if (length == 0) {
    (*result) = mal_blob_new(0);
  } else {
    mal_blob_t *blob = mal_blob_new(length);
    char *blob_content = mal_blob_get_content(blob);
    malbinary_read_array(blob_content, length, cursor);
    (*result) = blob;
  }
  return rc;
}

int malbinary_decoder_decode_time(mal_decoder_t *self, void *cursor, mal_time_t *result) {
  long days = malbinary_read16(cursor) & 0xFFFFL;
  long millisecondsInDay = malbinary_read32(cursor) & 0xFFFFFFFFL;
  long timestamp = days * MILLISECONDS_IN_DAY;
  timestamp += millisecondsInDay;
  timestamp -= MILLISECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  (*result) = timestamp;
  return 0;
}

int malbinary_decoder_decode_uinteger(mal_decoder_t *self, void *cursor, mal_uinteger_t *result) {
  if (self->varint_supported)
    (*result) = malbinary_read_uvarint(cursor);
  else
    (*result) = malbinary_read32(cursor);
  return 0;
}

int malbinary_decoder_decode_identifier(mal_decoder_t *self, void *cursor, mal_identifier_t **result) {
  (*result) = malbinary_read_str(self, cursor);
  return 0;
}

int malbinary_decoder_decode_uoctet(mal_decoder_t *self, void *cursor, mal_uoctet_t *result) {
  (*result) = malbinary_read(cursor);
  return 0;
}

int malbinary_decoder_decode_long(mal_decoder_t *self, void *cursor, mal_long_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varlong(cursor);
  else
    (*result) = malbinary_read64(cursor);
  return rc;
}

int malbinary_decoder_decode_ushort(mal_decoder_t *self, void *cursor, mal_ushort_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarshort(cursor);
  else
    (*result) = malbinary_read16(cursor);
  return rc;
}

int malbinary_decoder_decode_boolean(mal_decoder_t *self, void *cursor, mal_boolean_t *result) {
  int rc = 0;
  char flag = malbinary_read(cursor);
  if (flag == 1) {
    (*result) = true;
  } else {
    (*result) = false;
  }
  return rc;
}

int malbinary_decoder_decode_attribute_tag(mal_decoder_t *self, void *cursor, unsigned char *result) {
  return malbinary_decoder_decode_uoctet(self, cursor, result);
}

int malbinary_decoder_decode_duration(mal_decoder_t *self, void *cursor, mal_duration_t *result) {
// TODO: Be careful, during MAL/ZMTP interop duration was defined as a float (fixed by Guilhem).
//  return malbinary_decoder_decode_float(self, cursor, result);
  return malbinary_decoder_decode_double(self, cursor, result);
}

float intBitsToFloat(int x) {
  union {
    float f;  // assuming 32-bit IEEE 754 single-precision
    int i;    // assuming 32-bit 2's complement int
  } u;
  u.i = x;
  return u.f;
}

int malbinary_decoder_decode_float(mal_decoder_t *self, void *cursor, mal_float_t *result) {
  int rc = 0;
  mal_integer_t i;
  malbinary_decoder_decode_integer(self, cursor, &i);
  (*result) = intBitsToFloat(i);
  return rc;
}

double longBitsToDouble(long x) {
  union {
    double d;
    long l;
  } u;
  u.l = x;
  return u.d;
}

int malbinary_decoder_decode_double(mal_decoder_t *self, void *cursor, mal_double_t *result) {
  int rc = 0;
  mal_long_t l;
  malbinary_decoder_decode_long(self, cursor, &l);
  (*result) = longBitsToDouble(l);
  return rc;
}

int malbinary_decoder_decode_octet(mal_decoder_t *self, void *cursor, mal_octet_t *result) {
  int rc = 0;
  (*result) = malbinary_read(cursor);
  return rc;
}

int malbinary_decoder_decode_short(mal_decoder_t *self, void *cursor, mal_short_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varshort(cursor);
  else
    (*result) = malbinary_read16(cursor);
  return rc;
}

int malbinary_decoder_decode_ulong(mal_decoder_t *self, void *cursor, mal_ulong_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarlong(cursor);
  else
    (*result) = malbinary_read64(cursor);
  return rc;
}

int malbinary_decoder_decode_finetime(mal_decoder_t *self, void *cursor, mal_finetime_t *result) {
  long days = malbinary_read16(cursor) & 0xFFFFL;
  long millisecondsInDay = malbinary_read32(cursor) & 0xFFFFFFFFL;
  long picosecondsInMillisecond = malbinary_read32(cursor) & 0xFFFFFFFFL;
  unsigned long timestamp = days * NANOSECONDS_IN_DAY;
  timestamp += millisecondsInDay * ONE_MILLION;
  timestamp += picosecondsInMillisecond / 1000;
  timestamp -= NANOSECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  (*result) = timestamp;
  return 0;
}

int malbinary_decoder_decode_attribute(mal_decoder_t *decoder, void *cursor,
    unsigned char attribute_tag, union mal_attribute_t *self) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_blob(decoder, cursor, &self->blob_value);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_boolean(decoder, cursor, &self->boolean_value);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_duration(decoder, cursor, &self->duration_value);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_float(decoder, cursor, &self->float_value);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_double(decoder, cursor, &self->double_value);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_identifier(decoder, cursor, &self->identifier_value);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_octet(decoder, cursor, &self->octet_value);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uoctet(decoder, cursor, &self->uoctet_value);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_short(decoder, cursor, &self->short_value);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_ushort(decoder, cursor, &self->ushort_value);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_integer(decoder, cursor, &self->integer_value);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uinteger(decoder, cursor, &self->uinteger_value);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_long(decoder, cursor, &self->long_value);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_ulong(decoder, cursor, &self->ulong_value);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_string(decoder, cursor, &self->string_value);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_time(decoder, cursor, &self->time_value);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_finetime(decoder, cursor, &self->finetime_value);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uri(decoder, cursor, &self->uri_value);
    break;
  default:
    clog_error(decoder->logger, "Unexpected attribute tag value: %d\n", attribute_tag);
    return -1;
  }
  return rc;
}

// NOTE: The malbinary decoding functions should be private and only used through
// the mal_decoder_t structure.

void malbinary_init_decode_functions(mal_decoder_t *self) {
  mal_decoder_initialize_functions(self,
      malbinary_decoder_new_cursor,
      malbinary_decoder_cursor_reset,
      malbinary_cursor_destroy,
      malbinary_cursor_get_length,
      malbinary_cursor_get_offset,
      malbinary_cursor_assert,
      malbinary_read16,
      malbinary_read32,
      malbinary_read64,
      malbinary_decoder_decode_string,
      malbinary_decoder_decode_presence_flag,
      malbinary_decoder_decode_short_form,
      malbinary_decoder_decode_small_enum,
      malbinary_decoder_decode_medium_enum,
      malbinary_decoder_decode_large_enum,
      malbinary_decoder_decode_integer,
      malbinary_decoder_decode_list_size,
      malbinary_decoder_decode_uri,
      malbinary_decoder_decode_blob,
      malbinary_decoder_decode_time,
      malbinary_decoder_decode_uinteger,
      malbinary_decoder_decode_identifier,
      malbinary_decoder_decode_uoctet,
      malbinary_decoder_decode_long,
      malbinary_decoder_decode_ushort,
      malbinary_decoder_decode_boolean,
      malbinary_decoder_decode_duration,
      malbinary_decoder_decode_float,
      malbinary_decoder_decode_double,
      malbinary_decoder_decode_octet,
      malbinary_decoder_decode_short,
      malbinary_decoder_decode_ulong,
      malbinary_decoder_decode_finetime,
      malbinary_decoder_decode_attribute,
      malbinary_decoder_decode_attribute_tag,

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

// Test

void malbinary_decoder_test(bool verbose) {
  printf(" * malbinary_decoder: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

