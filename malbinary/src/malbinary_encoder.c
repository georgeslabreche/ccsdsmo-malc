#include "malbinary.h"

struct _malbinary_encoder_t {
  // TODO: varint limited to the last parameter in the MAL body
  bool varint_supported;
  clog_logger_t logger;
};

malbinary_encoder_t *malbinary_encoder_new(bool varint_supported, bool verbose) {
  malbinary_encoder_t *self = (malbinary_encoder_t *) malloc(
      sizeof(malbinary_encoder_t));
  if (!self)
    return NULL;

  self->varint_supported = varint_supported;
  self->logger = CLOG_WARN_LEVEL;

  return self;
}

void malbinary_encoder_set_log_level(malbinary_encoder_t *encoder, int level) {
  clog_set_level(&encoder->logger, level);
}

clog_logger_t malbinary_encoder_get_logger(malbinary_encoder_t *encoder) {
  return encoder->logger;
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
  for (int i = 0; i < 14; i += 7) {
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
  for (int i = 0; i < 28; i += 7) {
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
  for (int i = 0; i < 63; i += 7) {
    if ((value >> i) == 0) {
      break;
    }
    ret++;
  }
  return ret;
}

int malbinary_var_short_encoding_length(short value) {
  if (value > 0)
    return malbinary_var_ushort_encoding_length(2 * value);
  else
    return malbinary_var_ushort_encoding_length(-2 * value - 1);
}

int malbinary_var_integer_encoding_length(int value) {
  if (value > 0)
    return malbinary_var_uinteger_encoding_length(2 * value);
  else
    return malbinary_var_uinteger_encoding_length(-2 * value - 1);
}

int malbinary_var_long_encoding_length(long value) {
  if (value > 0)
    return malbinary_var_ulong_encoding_length(2 * value);
  else
    return malbinary_var_ulong_encoding_length(-2 * value - 1);
}

void malbinary_write_uvarshort(unsigned short value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  while (true) {
    if ((value & ~0x7F) == 0) {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) value;
      ((malbinary_cursor_t *) cursor)->body_offset = index;
      return;
    } else {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
  }
}

void malbinary_write_uvarint(unsigned int value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  while (true) {
    if ((value & ~0x7F) == 0) {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) value;
      ((malbinary_cursor_t *) cursor)->body_offset = index;
      return;
    } else {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char)((value & 0x7F) | 0x80);
      value >>= 7;
    }
  }
}

void malbinary_write_uvarlong(unsigned long value, void *cursor) {
  unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;
  while (true) {
    if ((value & ~0x7FL) == 0) {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char) value;
      ((malbinary_cursor_t *) cursor)->body_offset = index;
      return;
    } else {
      ((malbinary_cursor_t *) cursor)->body_ptr[index++] = (char)(((int) value & 0x7F) | 0x80);
      value >>= 7;
    }
  }
}

void malbinary_write_varshort(short value, void *cursor) {
  malbinary_write_uvarshort(value << 1 ^ value >> 15, cursor);
}

void malbinary_write_varint(int value, void *cursor) {
  malbinary_write_uvarint(value << 1 ^ value >> 31, cursor);
}

void malbinary_write_varlong(long value, void *cursor) {
  malbinary_write_uvarlong(value << 1 ^ value >> 63, cursor);
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

int malbinary_encoder_add_string_encoding_length(malbinary_encoder_t *self, mal_string_t *to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported) {
    size_t length = mal_string_get_char_count(to_encode);
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(length) + length;
  } else {
    ((malbinary_cursor_t *) cursor)->body_length += 4 + mal_string_get_char_count(to_encode);
  }
  return rc;
}

int malbinary_encoder_add_presence_flag_encoding_length(malbinary_encoder_t *self, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  return rc;
}

int malbinary_encoder_add_short_form_encoding_length(malbinary_encoder_t *self, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_SHORT_FORM_SIZE;
  return rc;
}

int malbinary_encoder_add_integer_encoding_length(malbinary_encoder_t *self, mal_integer_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_integer_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_list_size_encoding_length(malbinary_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_small_enum_encoding_length(malbinary_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_SMALL_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_medium_enum_encoding_length(malbinary_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_MEDIUM_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_large_enum_encoding_length(malbinary_encoder_t *self,
    unsigned int to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_LARGE_ENUM_SIZE;
  return rc;
}

int malbinary_encoder_add_identifier_encoding_length(malbinary_encoder_t *self,
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

int malbinary_encoder_add_uinteger_encoding_length(malbinary_encoder_t *self,
    mal_uinteger_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_uinteger_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 4;
  return rc;
}

int malbinary_encoder_add_uri_encoding_length(malbinary_encoder_t *self,
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

int malbinary_encoder_add_time_encoding_length(malbinary_encoder_t *self,
    mal_time_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 8;
  return rc;
}

int malbinary_encoder_add_uoctet_encoding_length(malbinary_encoder_t *self,
    mal_uoctet_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return rc;
}

int malbinary_encoder_add_long_encoding_length(malbinary_encoder_t *self,
    mal_long_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
      ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_long_encoding_length(to_encode);
    else
      ((malbinary_cursor_t *) cursor)->body_length += 8;
  return rc;
}

int malbinary_encoder_add_ushort_encoding_length(malbinary_encoder_t *self,
    mal_ushort_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_ushort_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 2;
  return rc;
}

int malbinary_encoder_add_boolean_encoding_length(malbinary_encoder_t *self,
    mal_boolean_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return rc;
}

int malbinary_encoder_add_blob_encoding_length(malbinary_encoder_t *self,
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

int malbinary_encoder_encode_string(malbinary_encoder_t *self, void *cursor, mal_string_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_string_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_presence_flag(malbinary_encoder_t *self,
    void *cursor, bool present) {
  int rc = 0;
  if (present) {
    malbinary_write(1, cursor);
  } else {
    malbinary_write(0, cursor);
  }
  return rc;
}

int malbinary_encoder_encode_short_form(malbinary_encoder_t *self, void *cursor, long to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_integer(malbinary_encoder_t *self, void *cursor, mal_integer_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varint(to_encode, cursor);
  else
    malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_list_size(malbinary_encoder_t *self, void *cursor, unsigned int list_size) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarint(list_size, cursor);
  else
    malbinary_write32(list_size, cursor);
  return rc;
}

int malbinary_encoder_encode_small_enum(malbinary_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_medium_enum(malbinary_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_large_enum(malbinary_encoder_t *self, void *cursor, int to_encode) {
  int rc = 0;
  malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_uri(malbinary_encoder_t *self, void *cursor, mal_uri_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_uri_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_blob(malbinary_encoder_t *self, void *cursor, mal_blob_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_blob_get_length(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(mal_blob_get_content(to_encode), length, cursor);
  return rc;
}

int malbinary_encoder_encode_time(malbinary_encoder_t *self, void *cursor, mal_time_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_uinteger(malbinary_encoder_t *self, void *cursor, mal_uinteger_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
      malbinary_write_uvarint(to_encode, cursor);
    else
      malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_identifier(malbinary_encoder_t *self, void *cursor, mal_identifier_t *to_encode) {
  int rc = 0;
  unsigned int length = mal_identifier_get_char_count(to_encode);
  if (self->varint_supported)
    malbinary_write_uvarint(length, cursor);
  else
    malbinary_write32(length, cursor);
  malbinary_write_array(to_encode, length, cursor);
  return rc;
}

int malbinary_encoder_encode_uoctet(malbinary_encoder_t *self, void *cursor, mal_uoctet_t to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_long(malbinary_encoder_t *self, void *cursor, mal_long_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_ushort(malbinary_encoder_t *self, void *cursor, mal_ushort_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varshort(to_encode, cursor);
  else
    malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_boolean(malbinary_encoder_t *self, void *cursor, mal_boolean_t to_encode) {
  int rc = 0;
  if (to_encode) {
    malbinary_write(1, cursor);
  } else {
    malbinary_write(0, cursor);
  }
  return rc;
}

int malbinary_encoder_encode_attribute_tag(malbinary_encoder_t *malbinary_encoder, void *cursor, unsigned char to_encode) {
  int rc = 0;
  malbinary_write32(to_encode, cursor);
  return rc;
}

int malbinary_encoder_add_duration_encoding_length(malbinary_encoder_t *self,
    mal_duration_t to_encode, void *cursor) {
  int rc = 0;
  //TODO: malbinary_encoder_add_duration_encoding_length
  return rc;
}

int floatToIntBits(float x) {
  union {
    float f;  // assuming 32-bit IEEE 754 single-precision
    int i;    // assuming 32-bit 2's complement int
  } u;
  u.f = x;
  return u.i;
}

int malbinary_encoder_add_float_encoding_length(malbinary_encoder_t *self,
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

int malbinary_encoder_add_double_encoding_length(malbinary_encoder_t *self,
    mal_double_t to_encode, void *cursor) {
  int rc = 0;
  mal_long_t l = doubleToLongBits(to_encode);
  rc = malbinary_encoder_add_long_encoding_length(self, l, cursor);
  return rc;
}

int malbinary_encoder_add_octet_encoding_length(malbinary_encoder_t *self,
    mal_octet_t to_encode, void *cursor) {
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += 1;
  return rc;
}

int malbinary_encoder_add_short_encoding_length(malbinary_encoder_t *self,
    mal_short_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_short_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 2;
  return rc;
}

int malbinary_encoder_add_ulong_encoding_length(malbinary_encoder_t *self,
    mal_ulong_t to_encode, void *cursor) {
  int rc = 0;
  if (self->varint_supported)
    ((malbinary_cursor_t *) cursor)->body_length += malbinary_var_ulong_encoding_length(to_encode);
  else
    ((malbinary_cursor_t *) cursor)->body_length += 8;
  return rc;
}

int malbinary_encoder_add_finetime_encoding_length(malbinary_encoder_t *self,
    mal_finetime_t to_encode, void *cursor) {
  int rc = 0;
  //TODO: malbinary_encoder_add_finetime_encoding_length
  return rc;
}

int malbinary_encoder_encode_duration(malbinary_encoder_t *self, void *cursor, mal_duration_t to_encode) {
  int rc = 0;
  //TODO: malbinary_encoder_encode_duration
  return rc;
}

int malbinary_encoder_encode_float(malbinary_encoder_t *self, void *cursor, mal_float_t to_encode) {
  int rc = 0;
  int i = floatToIntBits(to_encode);
  if (self->varint_supported)
    malbinary_write_varint(i, cursor);
  else
    malbinary_write32(i, cursor);
  return rc;
}

int malbinary_encoder_encode_double(malbinary_encoder_t *self, void *cursor, mal_double_t to_encode) {
  int rc = 0;
  long l = doubleToLongBits(to_encode);
  if (self->varint_supported)
    malbinary_write_varlong(l, cursor);
  else
    malbinary_write64(l, cursor);
  return rc;
}

int malbinary_encoder_encode_octet(malbinary_encoder_t *self, void *cursor, mal_octet_t to_encode) {
  int rc = 0;
  malbinary_write(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_short(malbinary_encoder_t *self, void *cursor, mal_short_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_varshort(to_encode, cursor);
  else
    malbinary_write16(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_ulong(malbinary_encoder_t *self, void *cursor, mal_ulong_t to_encode) {
  int rc = 0;
  if (self->varint_supported)
    malbinary_write_uvarlong(to_encode, cursor);
  else
    malbinary_write64(to_encode, cursor);
  return rc;
}

int malbinary_encoder_encode_finetime(malbinary_encoder_t *self, void *cursor, mal_finetime_t to_encode) {
  int rc = 0;
  //TODO: malbinary_encoder_encode_finetime
  return rc;
}

int malbinary_encoder_add_attribute_encoding_length(malbinary_encoder_t *malbinary_encoder,
    unsigned char attribute_tag, union mal_attribute_t self, void *cursor) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_blob_encoding_length(malbinary_encoder, self.blob_value, cursor);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_boolean_encoding_length(malbinary_encoder, self.boolean_value, cursor);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_duration_encoding_length(malbinary_encoder, self.duration_value, cursor);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_float_encoding_length(malbinary_encoder, self.float_value, cursor);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_double_encoding_length(malbinary_encoder, self.double_value, cursor);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_identifier_encoding_length(malbinary_encoder, self.identifier_value, cursor);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_octet_encoding_length(malbinary_encoder, self.octet_value, cursor);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uoctet_encoding_length(malbinary_encoder, self.uoctet_value, cursor);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_short_encoding_length(malbinary_encoder, self.short_value, cursor);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_ushort_encoding_length(malbinary_encoder, self.ushort_value, cursor);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_integer_encoding_length(malbinary_encoder, self.integer_value, cursor);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uinteger_encoding_length(malbinary_encoder, self.uinteger_value, cursor);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_long_encoding_length(malbinary_encoder, self.long_value, cursor);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_ulong_encoding_length(malbinary_encoder, self.ulong_value, cursor);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_string_encoding_length(malbinary_encoder, self.string_value, cursor);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_time_encoding_length(malbinary_encoder, self.time_value, cursor);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_finetime_encoding_length(malbinary_encoder, self.finetime_value, cursor);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_encoder_add_uri_encoding_length(malbinary_encoder, self.uri_value, cursor);
    break;
  default:
    //nothing to do
    break;
  }
  return rc;
}

int malbinary_encoder_encode_attribute(malbinary_encoder_t *malbinary_encoder, void *cursor, unsigned char attribute_tag, union mal_attribute_t self) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_blob(malbinary_encoder, cursor, self.blob_value);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_boolean(malbinary_encoder, cursor, self.boolean_value);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_duration(malbinary_encoder, cursor, self.duration_value);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_float(malbinary_encoder, cursor, self.float_value);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_double(malbinary_encoder, cursor, self.double_value);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_identifier(malbinary_encoder, cursor, self.identifier_value);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_octet(malbinary_encoder, cursor, self.octet_value);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uoctet(malbinary_encoder, cursor, self.uoctet_value);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_short(malbinary_encoder, cursor, self.short_value);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_ushort(malbinary_encoder, cursor, self.ushort_value);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_integer(malbinary_encoder, cursor, self.integer_value);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uinteger(malbinary_encoder, cursor, self.uinteger_value);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_long(malbinary_encoder, cursor, self.long_value);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_ulong(malbinary_encoder, cursor, self.ulong_value);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_string(malbinary_encoder, cursor, self.string_value);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_time(malbinary_encoder, cursor, self.time_value);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_finetime(malbinary_encoder, cursor, self.finetime_value);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_encoder_encode_uri(malbinary_encoder, cursor, self.uri_value);
    break;
  default:
    //nothing to do
    break;
  }
  return rc;
}

void malbinary_encoder_test(bool verbose) {
  printf(" * malbinary_encoder: ");
  if (verbose)
    printf("\n");

//  @selftest
// ...
//  @end
  printf("OK\n");
}

