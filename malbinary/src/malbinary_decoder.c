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

char *malbinary_read_str(char *bytes, unsigned int *offset) {
  // TODO: varint
  unsigned int length = malbinary_read32(bytes, offset);

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
  (*result) = malbinary_read_str(bytes, offset);
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
  // TODO: varint
  (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_short_form(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, long *result) {
  int rc = 0;
  (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_list_size(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, unsigned int *result) {
  int rc = 0;
  // TODO: varint
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
  (*result) = malbinary_read_str(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_blob(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_blob_t **result) {
  int rc = 0;
  // TODO: varint
  unsigned int length = malbinary_read32(bytes, offset);
  mal_blob_t *blob = mal_blob_new(length);
  char *blob_content = mal_blob_get_content(blob);
  malbinary_read_array(blob_content, length, bytes, offset);
  (*result) = blob;
  return rc;
}

int malbinary_decoder_decode_time(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_time_t *result) {
  int rc = 0;
  (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_uinteger(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_uinteger_t *result) {
  int rc = 0;
  (*result) = malbinary_read32(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_identifier(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_identifier_t **result) {
  int rc = 0;
  (*result) = malbinary_read_str(bytes, offset);
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
  (*result) = malbinary_read64(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_ushort(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ushort_t *result) {
  int rc = 0;
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

int malbinary_decoder_decode_float(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_float_t *result) {
  int rc = 0;
  //TODO: malbinary_decoder_decode_float
  return rc;
}

int malbinary_decoder_decode_double(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_double_t *result) {
  int rc = 0;
  //TODO: malbinary_decoder_decode_double
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
  (*result) = malbinary_read16(bytes, offset);
  return rc;
}

int malbinary_decoder_decode_ulong(malbinary_decoder_t *self, char *bytes,
    unsigned int *offset, mal_ulong_t *result) {
  int rc = 0;
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

