#include "malbinary.h"

struct _malbinary_decoder_t {
  // TODO: varint limited to the last parameter in the MAL body
  bool varint_supported;
  clog_logger_t logger;
};

malbinary_decoder_t *malbinary_decoder_new(bool varint_supported, bool verbose) {
  malbinary_decoder_t *self = (malbinary_decoder_t *) malloc(
      sizeof(malbinary_decoder_t));
  if (!self)
    return NULL;

  self->varint_supported = varint_supported;
  self->logger = CLOG_WARN_LEVEL;

  return self;
}

void malbinary_decoder_set_log_level(malbinary_decoder_t *decoder, int level) {
  clog_set_level(&decoder->logger, level);
}

clog_logger_t malbinary_decoder_get_logger(malbinary_decoder_t *decoder) {
  return decoder->logger;
}

short malbinary_read16(char *bytes, unsigned int *offset) {
  int index = (*offset);
  short res = (short) ((bytes[index++] & 0xFF) << 8);
  res = (short) (res | (bytes[index++] & 0xFF));
  (*offset) = index;
  return res;
}

int malbinary_read32(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  int res = (bytes[index++] & 0xFF) << 24;
  res = res | ((bytes[index++] & 0xFF) << 16);
  res = res | ((bytes[index++] & 0xFF) << 8);
  res = res | (bytes[index++] & 0xFF);
  (*offset) = index;
  return res;
}

long malbinary_read64(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  long res = ((bytes[index++] & 0xFFL) << 56);
  res = res | ((bytes[index++] & 0xFFL) << 48);
  res = res | ((bytes[index++] & 0xFFL) << 40);
  res = res | ((bytes[index++] & 0xFFL) << 32);
  res = res | ((bytes[index++] & 0xFFL) << 24);
  res = res | ((bytes[index++] & 0xFFL) << 16);
  res = res | ((bytes[index++] & 0xFFL) << 8);
  res = res | (bytes[index++] & 0xFFL);
  (*offset) = index;
  return res;
}

unsigned short malbinary_read_uvarshort(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  unsigned int value = 0;
  int i;
  int b;
  for (i = 0; ((b = bytes[index++]) & 0x80) != 0; i += 7) {
    value |= (b & 0x7f) << i;
  }
  (*offset) = index;
  return (value | b << i) & 0xFFFF;
}

unsigned int malbinary_read_uvarint(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  unsigned int value = 0;
  int i;
  int b;
  for (i = 0; ((b = bytes[index++]) & 0x80) != 0; i += 7) {
    value |= (b & 0x7f) << i;
  }
  (*offset) = index;
  return value | b << i;
}

unsigned long malbinary_read_uvarlong(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  unsigned long value = 0L;
  int i;
  long b;
  for (i = 0; ((b = bytes[index++]) & 0x80L) != 0L; i += 7) {
    value |= (b & 0x7fL) << i;
  }
  (*offset) = index;
  return value | b << i;
}

short malbinary_read_varshort(char *bytes, unsigned int *offset) {
  unsigned int i = malbinary_read_uvarint(bytes, offset);
  return ((i >> 1) ^ -(i & 1));
}

int malbinary_read_varint(char *bytes, unsigned int *offset) {
  unsigned int i = malbinary_read_uvarint(bytes, offset);
  return ((i >> 1) ^ -(i & 1));
}

long malbinary_read_varlong(char *bytes, unsigned int *offset) {
  unsigned long l = malbinary_read_uvarlong(bytes, offset);
  return ((l >> 1) ^ -(l & 1));
}

char *malbinary_read_str(malbinary_decoder_t *self, char *bytes, unsigned int *offset) {
  unsigned int length;
  if (self->varint_supported)
    length = malbinary_read_uvarint(bytes, offset);
  else
    length = malbinary_read32(bytes, offset);

  char *array = (char *) malloc(length + 1);
  if (array == NULL)
    return NULL;

  bcopy(& bytes[*offset], array, length);
  array[length] = '\0';

  (*offset) += length;

  return array;
}

void malbinary_read_array(char *array, unsigned int length, char *bytes,
    unsigned int *offset) {
  unsigned int index = (*offset);
  for (int i = 0; i < length; i++) {
    array[i] = bytes[index++];
  }
  (*offset) = index;
}

char malbinary_read(char *bytes, unsigned int *offset) {
  unsigned int index = (*offset);
  char res = bytes[index++];
  (*offset) = index;
  return res;
}

int malbinary_decoder_decode_string(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_string_t **result) {
  int rc = 0;
  (*result) = malbinary_read_str(self, bytes, offset);
  if (*result == NULL)
    return -1;
  return rc;
}

int malbinary_decoder_decode_presence_flag(malbinary_decoder_t *self,
    char *bytes, unsigned int *offset, bool *result) {
  int rc = 0;
  char flag = malbinary_read(bytes, offset);
  if (flag == 1) {
    (*result) = true;
  } else {
    (*result) = false;
  }
  return rc;
}

int malbinary_decoder_decode_integer(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_integer_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varint(bytes, offset);
  else
    (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_short_form(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, long *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varlong(bytes, offset);
  else
    (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_list_size(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, unsigned int *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarint(bytes, offset);
  else
    (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_small_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result) {
  int rc = 0;
  (*result) = malbinary_read(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_medium_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result) {
  int rc = 0;
  (*result) = malbinary_read16(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_large_enum(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, int *result) {
  int rc = 0;
  (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_uri(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uri_t **result) {
  int rc = 0;
  (*result) = malbinary_read_str(self, bytes, offset);
  return rc;
}

int malbinary_decoder_decode_blob(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_blob_t **result) {
  int rc = 0;
  unsigned int length;
  if (self->varint_supported)
    length = malbinary_read_uvarint(bytes, offset);
  else
    length = malbinary_read32(bytes, offset);
  mal_blob_t *blob = mal_blob_new(length);
  char *blob_content = mal_blob_get_content(blob);
  malbinary_read_array(blob_content, length, bytes, offset);
  (*result) = blob;
  return rc;
}

int malbinary_decoder_decode_time(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_time_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarlong(bytes, offset);
  else
    (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_uinteger(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uinteger_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarint(bytes, offset);
  else
    (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_identifier(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_identifier_t **result) {
  int rc = 0;
  (*result) = malbinary_read_str(self, bytes, offset);
  return rc;
}

int malbinary_decoder_decode_uoctet(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uoctet_t *result) {
  int rc = 0;
  (*result) = malbinary_read(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_long(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_long_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varlong(bytes, offset);
  else
    (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_ushort(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ushort_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarshort(bytes, offset);
  else
    (*result) = malbinary_read16(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_boolean(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_boolean_t *result) {
  int rc = 0;
  char flag = malbinary_read(bytes, offset);
  if (flag == 1) {
    (*result) = true;
  } else {
    (*result) = false;
  }
  return rc;
}

int malbinary_decoder_decode_attribute_tag(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, unsigned char *result) {
  int rc = 0;
  (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_duration(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_duration_t *result) {
  int rc = 0;
  //TODO: malbinary_decoder_decode_duration
  return rc;
}

float intBitsToFloat(int x) {
  union {
    float f;  // assuming 32-bit IEEE 754 single-precision
    int i;    // assuming 32-bit 2's complement int
  } u;
  u.i = x;
  return u.f;
}

int malbinary_decoder_decode_float(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_float_t *result) {
  int rc = 0;
  mal_integer_t i;
  malbinary_decoder_decode_integer(self, bytes, offset, &i);
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

int malbinary_decoder_decode_double(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_double_t *result) {
  int rc = 0;
  mal_long_t l;
  malbinary_decoder_decode_long(self, bytes, offset, &l);
  (*result) = longBitsToDouble(l);
  return rc;
}

int malbinary_decoder_decode_octet(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_octet_t *result) {
  int rc = 0;
  (*result) = malbinary_read(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_short(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_short_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_varshort(bytes, offset);
  else
    (*result) = malbinary_read16(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_ulong(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ulong_t *result) {
  int rc = 0;
  if (self->varint_supported)
    (*result) = malbinary_read_uvarlong(bytes, offset);
  else
    (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_finetime(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_finetime_t *result) {
  int rc = 0;
  //TODO: malbinary_decoder_decode_finetime
  return rc;
}

int malbinary_decoder_decode_attribute(malbinary_decoder_t *malbinary_decoder, char *bytes,
    unsigned int *offset, unsigned char attribute_tag, union mal_attribute_t self) {
  int rc = 0;
  switch (attribute_tag) {
  case MAL_BLOB_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_blob(malbinary_decoder, bytes, offset, &self.blob_value);
    break;
  case MAL_BOOLEAN_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_boolean(malbinary_decoder, bytes, offset, &self.boolean_value);
    break;
  case MAL_DURATION_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_duration(malbinary_decoder, bytes, offset, &self.duration_value);
    break;
  case MAL_FLOAT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_float(malbinary_decoder, bytes, offset, &self.float_value);
    break;
  case MAL_DOUBLE_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_double(malbinary_decoder, bytes, offset, &self.double_value);
    break;
  case MAL_IDENTIFIER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_identifier(malbinary_decoder, bytes, offset, &self.identifier_value);
    break;
  case MAL_OCTET_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_octet(malbinary_decoder, bytes, offset, &self.octet_value);
    break;
  case MAL_UOCTET_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uoctet(malbinary_decoder, bytes, offset, &self.uoctet_value);
    break;
  case MAL_SHORT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_short(malbinary_decoder, bytes, offset, &self.short_value);
    break;
  case MAL_USHORT_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_ushort(malbinary_decoder, bytes, offset, &self.ushort_value);
    break;
  case MAL_INTEGER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_integer(malbinary_decoder, bytes, offset, &self.integer_value);
    break;
  case MAL_UINTEGER_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uinteger(malbinary_decoder, bytes, offset, &self.uinteger_value);
    break;
  case MAL_LONG_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_long(malbinary_decoder, bytes, offset, &self.long_value);
    break;
  case MAL_ULONG_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_ulong(malbinary_decoder, bytes, offset, &self.ulong_value);
    break;
  case MAL_STRING_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_string(malbinary_decoder, bytes, offset, &self.string_value);
    break;
  case MAL_TIME_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_time(malbinary_decoder, bytes, offset, &self.time_value);
    break;
  case MAL_FINETIME_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_finetime(malbinary_decoder, bytes, offset, &self.finetime_value);
    break;
  case MAL_URI_ATTRIBUTE_TAG:
    rc = malbinary_decoder_decode_uri(malbinary_decoder, bytes, offset, &self.uri_value);
    break;
  default:
    //nothing to do
    break;
  }
  return rc;
}

void malbinary_decoder_test(bool verbose) {
  printf(" * malbinary_decoder: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

