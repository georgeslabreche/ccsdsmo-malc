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

mal_encoder_t *malbinary_encoder_new(bool varint_supported) {
  mal_encoder_t *self = (mal_encoder_t *) malloc(sizeof(mal_encoder_t));
  if (!self)
    return NULL;

  self->encoding_format_code = MALBINARY_FORMAT_CODE;
  self->varint_supported = varint_supported;
  self->logger = CLOG_WARN_LEVEL;

  malbinary_init_encode_functions(self);

  return self;
}

void *malbinary_encoder_new_cursor() {
  malbinary_cursor_t *cursor = (malbinary_cursor_t *) malloc(sizeof(malbinary_cursor_t));
  if (! cursor) return NULL;

  malbinary_cursor_reset(cursor);

  return (void *) cursor;
}

void malbinary_write16(int int_value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 8);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 0);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

void malbinary_write32(int int_value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 24);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 16);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 8);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (int_value >> 0);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

void malbinary_write64(long long_value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 56);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 48);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 40);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 32);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 24);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 16);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 8);
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (long_value >> 0);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

int malbinary_var_ushort_encoding_length(unsigned short value) {
  if (value == 0) return 1;
  int ret = 0;
  for (int i = 0; i < 16; i += 7) {
    if ((value >> i) == 0) {
      break;
    }
    ret++;
  }
  return ret;
}

int malbinary_var_uinteger_encoding_length(unsigned int value) {
  if (value == 0) return 1;
  int ret = 0;
  for (int i = 0; i < 32; i += 7) {
    if ((value >> i) == 0) {
      break;
    }
    ret++;
  }
  return ret;
}

int malbinary_var_ulong_encoding_length(unsigned long value) {
  if (value == 0) return 1;
  int ret = 0;
  for (int i = 0; i < 64; i += 7) {
    if ((value >> i) == 0) {
      break;
    }
    ret++;
  }
  return ret;
}

int malbinary_var_short_encoding_length(short value) {
  return malbinary_var_ushort_encoding_length((value << 1) ^ (value >> 15));
}

int malbinary_var_integer_encoding_length(int value) {
  return malbinary_var_uinteger_encoding_length((value << 1) ^ (value >> 31));
}

int malbinary_var_long_encoding_length(long value) {
  return malbinary_var_ulong_encoding_length((value << 1) ^ (value >> 63));
}

void malbinary_write_uvarinteger(unsigned int value, char *bytes) {
  unsigned int index = 0;
  while ((value & -128) != 0)
  {
    bytes[index++] = (char) ((value & 127) | 128);
    value >>= 7;
  }
  bytes[index++] = (char) (value & 127);
}

void malbinary_write_uvarint(unsigned int value, void *cursor)
{
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  while ((value & -128) != 0)
  {
    ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) ((value & 127) | 128);
    ((malbinary_cursor_t *) cursor)->body_offset = index;
    value >>= 7;
  }
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (value & 127);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

void malbinary_write_uvarshort(unsigned short value, void *cursor) {
  malbinary_write_uvarint(value, cursor);
}


void malbinary_write_uvarlong(unsigned long value, void *cursor)
{
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  while ((value & -128L) != 0L)
  {
    ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) (((int) value & 127) | 128);
    ((malbinary_cursor_t *) cursor)->body_offset = index;
    value >>= 7;
  }
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) ((int) value & 127);
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

void malbinary_write_varshort(short value, void *cursor) {
  malbinary_write_uvarint((value << 1) ^ (value >> 15), cursor);
}

void malbinary_write_varint(int value, void *cursor) {
  malbinary_write_uvarint((value << 1) ^ (value >> 31), cursor);
}

void malbinary_write_varlong(long value, void *cursor) {
  malbinary_write_uvarlong((value << 1) ^ (value >> 63), cursor);
}

void malbinary_write_array(char *array, unsigned int length, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  for (int i = 0; i < length; i++) {
    ((malbinary_cursor_t *) cursor)->body_ptr[index++] = array[i];
  }
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

void malbinary_write(char b, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  ((malbinary_cursor_t *) cursor)->body_ptr[index++] = b;
  ((malbinary_cursor_t *) cursor)->body_offset = index;
}

int malbinary_encoder_add_string_encoding_length(mal_encoder_t *self, mal_string_t *to_encode, void *cursor) {
  int rc = 0;
  size_t length = mal_string_get_char_count(to_encode);
  if (self->varint_supported) {
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(length) + length;
  } else {
    ((malbinary_cursor_t *) cursor)->body_length += 4 + length;
  }
  return rc;
}

int malbinary_encoder_add_presence_flag_encoding_length(mal_encoder_t *self, mal_boolean_t to_encode, void *cursor) {
  return malbinary_encoder_add_boolean_encoding_length(self, to_encode, cursor);
}

int malbinary_encoder_add_short_form_encoding_length(mal_encoder_t *self, long to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_long_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_SHORT_FORM_SIZE;
  return rc;
}

int malbinary_encoder_add_integer_encoding_length(mal_encoder_t *self, mal_integer_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_integer_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_list_size_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_small_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_SMALL_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_medium_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_ushort_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_MEDIUM_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_large_enum_encoding_length(mal_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_LARGE_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_identifier_encoding_length(mal_encoder_t *self,
    mal_identifier_t *to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported) {
    size_t length = mal_identifier_get_char_count(to_encode);
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(length) + length;
  } else {
    ((malbinary_cursor_t *) cursor)->body_length += 4 + mal_identifier_get_char_count(to_encode);
  }
  return rc;
}

int malbinary_encoder_add_uinteger_encoding_length(mal_encoder_t *self,
    mal_uinteger_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_uri_encoding_length(mal_encoder_t *self,
    mal_uri_t *to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported) {
    size_t length = mal_uri_get_char_count(to_encode);
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(length) + length;
  } else {
    ((malbinary_cursor_t *) cursor)->body_length += 4 + mal_uri_get_char_count(to_encode);
  }
  return rc;
}

int malbinary_encoder_add_time_encoding_length(mal_encoder_t *self,
    mal_time_t to_encode, void *cursor) {
  ((malbinary_cursor_t *) cursor)->body_length += 6;
  return 0;
}

int malbinary_encoder_add_uoctet_encoding_length(mal_encoder_t *self, mal_uoctet_t to_encode, void *cursor) {
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return 0;
}

int malbinary_encoder_add_long_encoding_length(mal_encoder_t *self,
    mal_long_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
      ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_long_encoding_length(to_encode);
    else
      ((malbinary_cursor_t *) cursor)->body_length += 8;
  return rc;
}

int malbinary_encoder_add_ushort_encoding_length(mal_encoder_t *self,
    mal_ushort_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_ushort_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 2;
  return rc;
}

int malbinary_encoder_add_boolean_encoding_length(mal_encoder_t *self,
    mal_boolean_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return rc;
}

int malbinary_encoder_add_blob_encoding_length(mal_encoder_t *self,
    mal_blob_t *to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported) {
    unsigned int length = mal_blob_get_length(to_encode);
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(length) + length;
  } else {
    ((malbinary_cursor_t *) cursor)->body_length += 4 + mal_blob_get_length(to_encode);
  }
  return rc;
}

int malbinary_encoder_encode_string(mal_encoder_t *self, void *cursor, mal_string_t *to_encode) {
  int rc = 0;
  size_t length = mal_string_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_presence_flag(mal_encoder_t *self,
    void *cursor, bool present) {
  int rc = 0;
  if (present) {
    malbinary_write(1, cursor);
  } else {
    malbinary_write(0, cursor);
  }
  return rc;
}

int malbinary_encoder_encode_short_form(mal_encoder_t *self, void *cursor, long to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_integer(mal_encoder_t *self, void *cursor, mal_integer_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varint(to_encode, cursor);
  else
    malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_list_size(mal_encoder_t *self, void *cursor, unsigned int list_size) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarint(list_size, cursor);
  else
    malbinary_write32(list_size, cursor);
  return rc;
}

int malbinary_encoder_encode_small_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_medium_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarshort(to_encode, cursor);
  else
    malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_large_enum(mal_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarint(to_encode, cursor);
  else
    malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_uri(mal_encoder_t *self, void *cursor, mal_uri_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_uri_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_blob(mal_encoder_t *self, void *cursor, mal_blob_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_blob_get_length(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(mal_blob_get_content(to_encode), length, cursor);
  return rc;
}

int malbinary_encoder_encode_time(mal_encoder_t *self, void *cursor, mal_time_t to_encode) {
  unsigned long timestamp = to_encode;
  timestamp += MILLISECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  long days = timestamp / MILLISECONDS_IN_DAY;
  long millisecondsInDay = (timestamp % MILLISECONDS_IN_DAY);

  if (days > 65535) {
    clog_debug(mal_encoder_get_logger(self), "malbinary_encoder_encode_time: days > 65535\n");
    return 1;
  }
  malbinary_write16(days, cursor);
  malbinary_write32(millisecondsInDay, cursor);
  return 0;
}

int malbinary_encoder_encode_uinteger(mal_encoder_t *self, void *cursor, mal_uinteger_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
      malbinary_write_uvarint(to_encode, cursor);
    else
      malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_identifier(mal_encoder_t *self, void *cursor, mal_identifier_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_identifier_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_uoctet(mal_encoder_t *self, void *cursor, mal_uoctet_t to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_long(mal_encoder_t *self, void *cursor, mal_long_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_ushort(mal_encoder_t *self, void *cursor, mal_ushort_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarshort(to_encode, cursor);
  else
    malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_boolean(mal_encoder_t *self, void *cursor, mal_boolean_t to_encode) {
  int rc = 0;
  if (to_encode) {
    malbinary_write(1, cursor);
  } else {
    malbinary_write(0, cursor);
  }
  return rc;
}

int malbinary_encoder_encode_attribute_tag(mal_encoder_t *self, void *cursor, unsigned char to_encode) {
  return malbinary_encoder_encode_uoctet(self, cursor, to_encode);
}

int malbinary_encoder_add_duration_encoding_length(mal_encoder_t *self,
    mal_duration_t to_encode, void *cursor) {
// TODO: Be careful, during MAL/ZMTP interop duration was defined as a float (fixed by Guilhem).
//  return malbinary_encoder_add_float_encoding_length(self, (mal_float_t) to_encode, cursor);
  return malbinary_encoder_add_double_encoding_length(self, (mal_float_t) to_encode, cursor);
}

int floatToIntBits(float x) {
  union {
    float f;  // assuming 32-bit IEEE 754 single-precision
    int i;    // assuming 32-bit 2's complement int
  } u;
  u.f = x;
  return u.i;
}

int malbinary_encoder_add_float_encoding_length(mal_encoder_t *self,
    mal_float_t to_encode, void *cursor) {
  int rc = 0;
  mal_integer_t i = floatToIntBits(to_encode);
  rc = malbinary_encoder_add_integer_encoding_length(self, i, cursor);
  return rc;
}

long doubleToLongBits(double x) {
  union {
    double d;
    long l;
  } u;
  u.d = x;
  return u.l;
}

int malbinary_encoder_add_double_encoding_length(mal_encoder_t *self,
    mal_double_t to_encode, void *cursor) {
  int rc = 0;
  mal_long_t l = doubleToLongBits(to_encode);
  rc = malbinary_encoder_add_long_encoding_length(self, l, cursor);
  return rc;
}

int malbinary_encoder_add_octet_encoding_length(mal_encoder_t *self,
    mal_octet_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return rc;
}

int malbinary_encoder_add_short_encoding_length(mal_encoder_t *self,
    mal_short_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_short_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 2;
  return rc;
}

int malbinary_encoder_add_ulong_encoding_length(mal_encoder_t *self,
    mal_ulong_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_ulong_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 8;
  return rc;
}

int malbinary_encoder_add_finetime_encoding_length(mal_encoder_t *self,
    mal_finetime_t to_encode, void *cursor) {
  ((malbinary_cursor_t *) cursor)->body_length += 10;
  return 0;
}

int malbinary_encoder_encode_duration(mal_encoder_t *self, void *cursor, mal_duration_t to_encode) {
// TODO: Be careful, during MAL/ZMTP interop duration was defined as a float (fixed by Guilhem).
// return  malbinary_encoder_encode_float(self, cursor, (mal_float_t) to_encode);
 return  malbinary_encoder_encode_double(self, cursor, (mal_float_t) to_encode);
}

int malbinary_encoder_encode_float(mal_encoder_t *self, void *cursor, mal_float_t to_encode) {
  int rc = 0;
  int i = floatToIntBits(to_encode);
  if (self->varint_supported)
    malbinary_write_varint(i, cursor);
  else
    malbinary_write32(i, cursor);
  return rc;
}

int malbinary_encoder_encode_double(mal_encoder_t *self, void *cursor, mal_double_t to_encode) {
  int rc = 0;
  long l = doubleToLongBits(to_encode);
  if (self->varint_supported)
    malbinary_write_varlong(l, cursor);
  else
    malbinary_write64(l, cursor);
  return rc;
}

int malbinary_encoder_encode_octet(mal_encoder_t *self, void *cursor, mal_octet_t to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_short(mal_encoder_t *self, void *cursor, mal_short_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varshort(to_encode, cursor);
  else
    malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_ulong(mal_encoder_t *self, void *cursor, mal_ulong_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_finetime(mal_encoder_t *self, void *cursor, mal_finetime_t to_encode) {
  unsigned long timestamp = to_encode;
  timestamp += NANOSECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  unsigned long days = timestamp / NANOSECONDS_IN_DAY;
  unsigned long nanosecondsInDay = (timestamp % NANOSECONDS_IN_DAY);
  unsigned long millisecondsInDay = nanosecondsInDay / ONE_MILLION;
  unsigned long picosecondsInMillisecond = (nanosecondsInDay % ONE_MILLION) * 1000;

  if (days > 65535)
  {
    clog_debug(mal_encoder_get_logger(self), "malbinary_encoder_encode_finetime: days > 65535\n");
    return 1;
  }
  malbinary_write16(days, cursor);
  malbinary_write32(millisecondsInDay, cursor);
  malbinary_write32(picosecondsInMillisecond, cursor);

  return 0;
}

int malbinary_encoder_add_attribute_tag_encoding_length(mal_encoder_t *encoder, unsigned char attribute_tag, void *cursor) {
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_ATTRIBUTE_TAG_SIZE;
  return 0;
}

int malbinary_encoder_add_attribute_encoding_length(mal_encoder_t *encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_blob_encoding_length(encoder, self.blob_value, cursor);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_boolean_encoding_length(encoder, self.boolean_value, cursor);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_duration_encoding_length(encoder, self.duration_value, cursor);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_float_encoding_length(encoder, self.float_value, cursor);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_double_encoding_length(encoder, self.double_value, cursor);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_identifier_encoding_length(encoder, self.identifier_value, cursor);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_octet_encoding_length(encoder, self.octet_value, cursor);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uoctet_encoding_length(encoder, self.uoctet_value, cursor);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_short_encoding_length(encoder, self.short_value, cursor);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_ushort_encoding_length(encoder, self.ushort_value, cursor);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_integer_encoding_length(encoder, self.integer_value, cursor);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uinteger_encoding_length(encoder, self.uinteger_value, cursor);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_long_encoding_length(encoder, self.long_value, cursor);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_ulong_encoding_length(encoder, self.ulong_value, cursor);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_string_encoding_length(encoder, self.string_value, cursor);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_time_encoding_length(encoder, self.time_value, cursor);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_finetime_encoding_length(encoder, self.finetime_value, cursor);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uri_encoding_length(encoder, self.uri_value, cursor);
    break;
  default:
    clog_error(encoder->logger, "Unexpected attribute tag value: %d\n", attribute_tag);
    return -1;
  }
  return rc;
}

int malbinary_encoder_encode_attribute(mal_encoder_t *encoder, void *cursor, unsigned char attribute_tag, union mal_attribute_t self) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_blob(encoder, cursor, self.blob_value);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_boolean(encoder, cursor, self.boolean_value);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_duration(encoder, cursor, self.duration_value);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_float(encoder, cursor, self.float_value);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_double(encoder, cursor, self.double_value);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_identifier(encoder, cursor, self.identifier_value);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_octet(encoder, cursor, self.octet_value);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uoctet(encoder, cursor, self.uoctet_value);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_short(encoder, cursor, self.short_value);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_ushort(encoder, cursor, self.ushort_value);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_integer(encoder, cursor, self.integer_value);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uinteger(encoder, cursor, self.uinteger_value);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_long(encoder, cursor, self.long_value);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_ulong(encoder, cursor, self.ulong_value);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_string(encoder, cursor, self.string_value);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_time(encoder, cursor, self.time_value);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_finetime(encoder, cursor, self.finetime_value);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uri(encoder, cursor, self.uri_value);
    break;
  default:
    clog_error(encoder->logger, "Unexpected attribute tag value: %d\n", attribute_tag);
    return -1;
  }
  return rc;
}

// NOTE: The malbinary encoding functions should be private and only used through
// the mal_encoder_t structure.

void malbinary_init_encode_functions(mal_encoder_t *self) {
  mal_encoder_initialize_functions(self,
      malbinary_encoder_new_cursor,
      malbinary_cursor_reset,
      malbinary_cursor_init,
      malbinary_cursor_destroy,
      malbinary_cursor_get_length,
      malbinary_cursor_get_offset,
      malbinary_cursor_assert,
      malbinary_encoder_add_string_encoding_length,
      malbinary_encoder_add_presence_flag_encoding_length,
      malbinary_encoder_add_short_form_encoding_length,
      malbinary_encoder_add_integer_encoding_length,
      malbinary_encoder_add_identifier_encoding_length,
      malbinary_encoder_add_uinteger_encoding_length,
      malbinary_encoder_add_uri_encoding_length,
      malbinary_encoder_add_time_encoding_length,
      malbinary_encoder_add_uoctet_encoding_length,
      malbinary_encoder_add_long_encoding_length,
      malbinary_encoder_add_ushort_encoding_length,
      malbinary_encoder_add_boolean_encoding_length,
      malbinary_encoder_add_blob_encoding_length,
      malbinary_encoder_add_list_size_encoding_length,
      malbinary_encoder_add_small_enum_encoding_length,
      malbinary_encoder_add_medium_enum_encoding_length,
      malbinary_encoder_add_large_enum_encoding_length,
      malbinary_encoder_add_duration_encoding_length,
      malbinary_encoder_add_float_encoding_length,
      malbinary_encoder_add_double_encoding_length,
      malbinary_encoder_add_octet_encoding_length,
      malbinary_encoder_add_short_encoding_length,
      malbinary_encoder_add_ulong_encoding_length,
      malbinary_encoder_add_finetime_encoding_length,
      malbinary_encoder_add_attribute_tag_encoding_length,
      malbinary_encoder_add_attribute_encoding_length,

      mal_entitykey_add_encoding_length_malbinary,
      mal_entityrequest_add_encoding_length_malbinary,
      mal_file_add_encoding_length_malbinary,
      mal_idbooleanpair_add_encoding_length_malbinary,
      mal_namedvalue_add_encoding_length_malbinary,
      mal_pair_add_encoding_length_malbinary,
      mal_subscription_add_encoding_length_malbinary,
      mal_updateheader_add_encoding_length_malbinary,

      mal_blob_list_add_encoding_length_malbinary,
      mal_boolean_list_add_encoding_length_malbinary,
      mal_double_list_add_encoding_length_malbinary,
      mal_duration_list_add_encoding_length_malbinary,
      mal_entitykey_list_add_encoding_length_malbinary,
      mal_entityrequest_list_add_encoding_length_malbinary,
      mal_file_list_add_encoding_length_malbinary,
      mal_finetime_list_add_encoding_length_malbinary,
      mal_float_list_add_encoding_length_malbinary,
      mal_idbooleanpair_list_add_encoding_length_malbinary,
      mal_identifier_list_add_encoding_length_malbinary,
      mal_integer_list_add_encoding_length_malbinary,
      mal_interactiontype_list_add_encoding_length_malbinary,
      mal_long_list_add_encoding_length_malbinary,
      mal_namedvalue_list_add_encoding_length_malbinary,
      mal_octet_list_add_encoding_length_malbinary,
      mal_pair_list_add_encoding_length_malbinary,
      mal_qoslevel_list_add_encoding_length_malbinary,
      mal_sessiontype_list_add_encoding_length_malbinary,
      mal_short_list_add_encoding_length_malbinary,
      mal_string_list_add_encoding_length_malbinary,
      mal_subscription_list_add_encoding_length_malbinary,
      mal_time_list_add_encoding_length_malbinary,
      mal_uinteger_list_add_encoding_length_malbinary,
      mal_ulong_list_add_encoding_length_malbinary,
      mal_uoctet_list_add_encoding_length_malbinary,
      mal_updateheader_list_add_encoding_length_malbinary,
      mal_updatetype_list_add_encoding_length_malbinary,
      mal_uri_list_add_encoding_length_malbinary,
      mal_ushort_list_add_encoding_length_malbinary,

      malbinary_encoder_encode_string,
      malbinary_encoder_encode_presence_flag,
      malbinary_encoder_encode_short_form,
      malbinary_encoder_encode_small_enum,
      malbinary_encoder_encode_medium_enum,
      malbinary_encoder_encode_large_enum,
      malbinary_encoder_encode_integer,
      malbinary_encoder_encode_list_size,
      malbinary_encoder_encode_uri,
      malbinary_encoder_encode_blob,
      malbinary_encoder_encode_time,
      malbinary_encoder_encode_uinteger,
      malbinary_encoder_encode_identifier,
      malbinary_encoder_encode_uoctet,
      malbinary_encoder_encode_long,
      malbinary_encoder_encode_ushort,
      malbinary_encoder_encode_boolean,
      malbinary_write16,
      malbinary_write32,
      malbinary_write64,
      malbinary_encoder_encode_duration,
      malbinary_encoder_encode_float,
      malbinary_encoder_encode_double,
      malbinary_encoder_encode_octet,
      malbinary_encoder_encode_short,
      malbinary_encoder_encode_ulong,
      malbinary_encoder_encode_finetime,
      malbinary_encoder_encode_attribute,
      malbinary_encoder_encode_attribute_tag,

      mal_entitykey_encode_malbinary,
      mal_entityrequest_encode_malbinary,
      mal_file_encode_malbinary,
      mal_idbooleanpair_encode_malbinary,
      mal_namedvalue_encode_malbinary,
      mal_pair_encode_malbinary,
      mal_subscription_encode_malbinary,
      mal_updateheader_encode_malbinary,

      mal_blob_list_encode_malbinary,
      mal_boolean_list_encode_malbinary,
      mal_double_list_encode_malbinary,
      mal_duration_list_encode_malbinary,
      mal_entitykey_list_encode_malbinary,
      mal_entityrequest_list_encode_malbinary,
      mal_file_list_encode_malbinary,
      mal_finetime_list_encode_malbinary,
      mal_float_list_encode_malbinary,
      mal_idbooleanpair_list_encode_malbinary,
      mal_identifier_list_encode_malbinary,
      mal_integer_list_encode_malbinary,
      mal_interactiontype_list_encode_malbinary,
      mal_long_list_encode_malbinary,
      mal_namedvalue_list_encode_malbinary,
      mal_octet_list_encode_malbinary,
      mal_pair_list_encode_malbinary,
      mal_qoslevel_list_encode_malbinary,
      mal_sessiontype_list_encode_malbinary,
      mal_short_list_encode_malbinary,
      mal_string_list_encode_malbinary,
      mal_subscription_list_encode_malbinary,
      mal_time_list_encode_malbinary,
      mal_uinteger_list_encode_malbinary,
      mal_ulong_list_encode_malbinary,
      mal_uoctet_list_encode_malbinary,
      mal_updateheader_list_encode_malbinary,
      mal_updatetype_list_encode_malbinary,
      mal_uri_list_encode_malbinary,
      mal_ushort_list_encode_malbinary);
}

// Test

void malbinary_encoder_test(bool verbose) {
  verbose = true;
  int errors = 0;

  printf(" * malbinary_encoder: ");
  if (verbose)
    printf("\n");

  unsigned short ushort_value = 0;
  if (malbinary_var_ushort_encoding_length(ushort_value) != 1) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_ushort_encoding_length(%hu) -> %d ERROR\n", ushort_value, malbinary_var_ushort_encoding_length(ushort_value));
  }
  ushort_value = 127;
  if (malbinary_var_ushort_encoding_length(ushort_value) != 1) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_ushort_encoding_length(%hu) -> %d ERROR\n", ushort_value, malbinary_var_ushort_encoding_length(ushort_value));
  }
  ushort_value = 128;
  if (malbinary_var_ushort_encoding_length(ushort_value) != 2) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_ushort_encoding_length(%hu) -> %d ERROR\n", ushort_value, malbinary_var_ushort_encoding_length(ushort_value));
  }
  ushort_value = 65535;
  if (malbinary_var_ushort_encoding_length(ushort_value) != 3) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_ushort_encoding_length(%hu) -> %d ERROR\n", ushort_value, malbinary_var_ushort_encoding_length(ushort_value));
  }

  short short_value = 0;
  if (malbinary_var_short_encoding_length(short_value) != 1) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = 1;
  if (malbinary_var_short_encoding_length(short_value) != 1) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = -1;
  if (malbinary_var_short_encoding_length(short_value) != 1) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = 127;
  if (malbinary_var_short_encoding_length(short_value) != 2) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = -127;
  if (malbinary_var_short_encoding_length(short_value) != 2) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = 128;
  if (malbinary_var_short_encoding_length(short_value) != 2) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = -128;
  if (malbinary_var_short_encoding_length(short_value) != 2) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = 32767;
  if (malbinary_var_short_encoding_length(short_value) != 3) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }
  short_value = -32768;
  if (malbinary_var_short_encoding_length(short_value) != 3) {
    errors += 1;
    if (verbose)
      printf("malbinary_var_short_encoding_length(%hd) -> %d ERROR\n", short_value, malbinary_var_short_encoding_length(short_value));
  }

  //  @selftest
// ...
//  @end
  printf((errors == 0)?"OK\n":"ERROR\n");
}

