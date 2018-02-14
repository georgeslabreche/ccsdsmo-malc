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

/* */
#include <fcntl.h>
#include <unistd.h>
#include "../include/encoding.h"

mal_boolean_t BOOL1 = false;
mal_uoctet_t UOCTET1 = 0;
mal_uoctet_t UOCTET2 = 255;
mal_octet_t OCTET1 = -128;
mal_octet_t OCTET2 = 0;
mal_octet_t OCTET3 = 127;
mal_boolean_t BOOL2 = true;
mal_ushort_t USHORT1 = 0;
mal_ushort_t USHORT2 = 256;
mal_ushort_t USHORT3 = 65535;
mal_short_t SHORT1 = -32768;
mal_short_t SHORT2 = -256;
mal_short_t SHORT3 = 0;
mal_short_t SHORT4 = 256;
mal_short_t SHORT5 = 32767;
mal_boolean_t BOOL3 = false;
unsigned int UINT1 = 0;
unsigned int UINT2 = 256;
unsigned int UINT3 = 65536;
unsigned int UINT4 = 4294967295;
int INT1 = -2147483648;
int INT2 = -32768;
int INT3 = -256;
int INT4 = 0;
int INT5 = 256;
int INT6 = 32767;
int INT7 = 2147483647;
mal_boolean_t BOOL4 = false;
unsigned long ULONG1 = 0;
unsigned long ULONG2 = 65536;
unsigned long ULONG3 = 4294967295;
long LONG1 = -2147483648;
long LONG2 = 0;
long LONG3 = 2147483647;
mal_boolean_t BOOL5 = false;
float FLOAT1 = 1.25E6;
float FLOAT2 = -5.8E-2;
mal_boolean_t BOOL6 = false;
double DOUBLE1 = 1.25E6;
double DOUBLE2 = -5.8E-2;
mal_boolean_t BOOL7 = false;
char BLOB_C1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
mal_blob_t *BLOB1;
mal_boolean_t BOOL8 = false;
char* STRING1 = "Hello world";
mal_boolean_t BOOL9 = true;
// Encode 1234567.000000500 seconds from Unix epoch (in ms and ns)
mal_time_t TIME1 = 1234567000;
mal_boolean_t BOOL10 = true;
mal_finetime_t FINETIME1= 1234567000000500;
mal_boolean_t BOOL11 = false;

// Initializes data structures.
bool initialize() {
  BLOB1 = mal_blob_create(BLOB_C1, sizeof(BLOB_C1));
  return true;
}

void addBooleanEncodingLength(mal_encoder_t *encoder, void *cursor, mal_boolean_t value) {
  encoder->mal_encoder_add_boolean_encoding_length(encoder, value, cursor);
}

void writeBoolean(mal_encoder_t *encoder, void *cursor, mal_boolean_t value) {
  encoder->mal_encoder_encode_boolean(encoder, cursor, value);
}

bool testBoolean(mal_decoder_t *decoder, void *cursor, mal_boolean_t ref) {
  mal_boolean_t value;
  decoder->mal_decoder_decode_boolean(decoder, cursor, &value);
  if (value != ref) {
      printf("Test boolean %d != %d\n", value, ref);
      return false;
  }
  return true;
}

void addUOctetEncodingLength(mal_encoder_t *encoder, void *cursor, mal_uoctet_t value) {
  encoder->mal_encoder_add_uoctet_encoding_length(encoder, value, cursor);
}

void writeUOctet(mal_encoder_t *encoder, void *cursor, mal_uoctet_t value) {
  encoder->mal_encoder_encode_uoctet(encoder, cursor, value);
}

bool testUOctet(mal_decoder_t *decoder, void *cursor, mal_uoctet_t ref) {
  mal_uoctet_t value;
  decoder->mal_decoder_decode_uoctet(decoder, cursor, &value);
  if (value != ref) {
      printf("Test uint %hu != %hu\n", value, ref);
      return false;
  }
  return true;
}

void addOctetEncodingLength(mal_encoder_t *encoder, void *cursor, mal_octet_t value) {
  encoder->mal_encoder_add_octet_encoding_length(encoder, value, cursor);
}

void writeOctet(mal_encoder_t *encoder, void *cursor, mal_octet_t value) {
  encoder->mal_encoder_encode_octet(encoder, cursor, value);
}

bool testOctet(mal_decoder_t *decoder, void *cursor, mal_octet_t ref) {
  mal_octet_t value;
  decoder->mal_decoder_decode_octet(decoder, cursor, &value);
  if (value != ref) {
      printf("Test int %hu != %hu\n", value, ref);
      return false;
  }
  return true;
}

void addUShortEncodingLength(mal_encoder_t *encoder, void *cursor, mal_ushort_t value) {
  encoder->mal_encoder_add_ushort_encoding_length(encoder, value, cursor);
}

void writeUShort(mal_encoder_t *encoder, void *cursor, mal_ushort_t value) {
  encoder->mal_encoder_encode_ushort(encoder, cursor, value);
}

bool testUShort(mal_decoder_t *decoder, void *cursor, mal_ushort_t ref) {
  mal_ushort_t value;
  decoder->mal_decoder_decode_ushort(decoder, cursor, &value);
  if (value != ref) {
      printf("Test ushort %hu != %hu\n", value, ref);
      return false;
  }
  return true;
}

void addShortEncodingLength(mal_encoder_t *encoder, void *cursor, mal_short_t value) {
  encoder->mal_encoder_add_short_encoding_length(encoder, value, cursor);
}

void writeShort(mal_encoder_t *encoder, void *cursor, mal_short_t value) {
  encoder->mal_encoder_encode_short(encoder, cursor, value);
}

bool testShort(mal_decoder_t *decoder, void *cursor, mal_short_t ref) {
  mal_short_t value;
  decoder->mal_decoder_decode_short(decoder, cursor, &value);
  if (value != ref) {
      printf("Test short %hu != %hu\n", value, ref);
      return false;
  }
  return true;
}

void addUIntEncodingLength(mal_encoder_t *encoder, void *cursor, unsigned int value) {
  encoder->mal_encoder_add_uinteger_encoding_length(encoder, value, cursor);
}

void writeUInt(mal_encoder_t *encoder, void *cursor, unsigned int value) {
  encoder->mal_encoder_encode_uinteger(encoder, cursor, value);
}

bool testUInt(mal_decoder_t *decoder, void *cursor, unsigned int ref) {
  unsigned int value;
  decoder->mal_decoder_decode_uinteger(decoder, cursor, &value);
  if (value != ref) {
      printf("Test uint %u != %u\n", value, ref);
      return false;
  }
  return true;
}

void addIntEncodingLength(mal_encoder_t *encoder, void *cursor, int value) {
  encoder->mal_encoder_add_integer_encoding_length(encoder, value, cursor);
}

void writeInt(mal_encoder_t *encoder, void *cursor, int value) {
  encoder->mal_encoder_encode_integer(encoder, cursor, value);
}

bool testInt(mal_decoder_t *decoder, void *cursor, int ref) {
  int value;
  decoder->mal_decoder_decode_integer(decoder, cursor, &value);
  if (value != ref) {
      printf("Test int %d != %d\n", value, ref);
      return false;
  }
  return true;
}

void addULongEncodingLength(mal_encoder_t *encoder, void *cursor, unsigned long value) {
  encoder->mal_encoder_add_ulong_encoding_length(encoder, value, cursor);
}

void writeULong(mal_encoder_t *encoder, void *cursor, unsigned long value) {
  encoder->mal_encoder_encode_ulong(encoder, cursor, value);
}

bool testULong(mal_decoder_t *decoder, void *cursor, unsigned long ref) {
  unsigned long value;
  decoder->mal_decoder_decode_ulong(decoder, cursor, &value);
  if (value != ref) {
      printf("Test ulong %lud != %lud\n", value, ref);
      return false;
  }
  return true;
}

void addLongEncodingLength(mal_encoder_t *encoder, void *cursor, long value) {
  encoder->mal_encoder_add_long_encoding_length(encoder, value, cursor);
}

void writeLong(mal_encoder_t *encoder, void *cursor, long value) {
  encoder->mal_encoder_encode_long(encoder, cursor, value);
}

bool testLong(mal_decoder_t *decoder, void *cursor, long ref) {
  long value;
  decoder->mal_decoder_decode_long(decoder, cursor, &value);
  if (value != ref) {
      printf("Test long %ld != %ld\n", value, ref);
      return false;
  }
  return true;
}

void addFloatEncodingLength(mal_encoder_t *encoder, void *cursor, mal_float_t value) {
  encoder->mal_encoder_add_float_encoding_length(encoder, value, cursor);
}

int floatToIntBits(float x) {
  union {
    float f;  // assuming 32-bit IEEE 754 single-precision
    int i;    // assuming 32-bit 2's complement int
  } u;
  u.f = x;
  return u.i;
}

void writeFloat(mal_encoder_t *encoder, void *cursor, mal_float_t value) {
  encoder->mal_encoder_encode_float(encoder, cursor, value);
}

bool testFloat(mal_decoder_t *decoder, void *cursor, mal_float_t ref) {
  mal_float_t value;
  decoder->mal_decoder_decode_float(decoder, cursor, &value);
  if (value != ref) {
      printf("Test float %f != %f\n", value, ref);
      return false;
  }
  return true;
}

void addDoubleEncodingLength(mal_encoder_t *encoder, void *cursor, mal_double_t value) {
  encoder->mal_encoder_add_double_encoding_length(encoder, value, cursor);
}

long doubleToLongBits(double x) {
  union {
    double d;
    long l;
  } u;
  u.d = x;
  return u.l;
}

void writeDouble(mal_encoder_t *encoder, void *cursor, mal_double_t value) {
  encoder->mal_encoder_encode_double(encoder, cursor, value);
}

bool testDouble(mal_decoder_t *decoder, void *cursor, mal_double_t ref) {
  mal_double_t value;
  decoder->mal_decoder_decode_double(decoder, cursor, &value);
  if (value != ref) {
      printf("Test double %f != %f\n", value, ref);
      return false;
  }
  return true;
}

void addBlobEncodingLength(mal_encoder_t *encoder, void *cursor, mal_blob_t *value) {
  encoder->mal_encoder_add_blob_encoding_length(encoder, value, cursor);
}

void writeBlob(mal_encoder_t *encoder, void *cursor, mal_blob_t *value) {
  encoder->mal_encoder_encode_blob(encoder, cursor, value);
}

bool testBlob(mal_decoder_t *decoder, void *cursor, mal_blob_t *ref) {
  mal_blob_t *value;
  decoder->mal_decoder_decode_blob(decoder, cursor, &value);
  if ((mal_blob_get_length(value) != mal_blob_get_length(ref)) ||
      memcmp(mal_blob_get_content(value), mal_blob_get_content(ref), mal_blob_get_length(value)) != 0) {
      printf("Test blob: ERROR\n");
      return false;
  }
  return true;
}

void addStringEncodingLength(mal_encoder_t *encoder, void *cursor, char *value) {
  encoder->mal_encoder_add_string_encoding_length(encoder, value, cursor);
}

void writeString(mal_encoder_t *encoder, void *cursor, char *value) {
  encoder->mal_encoder_encode_string(encoder, cursor, value);
}

bool testString(mal_decoder_t *decoder, void *cursor, char *ref) {
  char *value;
  decoder->mal_decoder_decode_string(decoder, cursor, &value);
  if (strcmp(value, ref) != 0) {
      printf("Test string %s != %s\n", value, ref);
      return false;
  }
  return true;
}

void addTimeEncodingLength(mal_encoder_t *encoder, void *cursor, mal_time_t value) {
  encoder->mal_encoder_add_time_encoding_length(encoder, value, cursor);
}

void writeTime(mal_encoder_t *encoder, void *cursor, mal_time_t value) {
  encoder->mal_encoder_encode_time(encoder, cursor, value);
}

bool testTime(mal_decoder_t *decoder, void *cursor, mal_time_t ref) {
  mal_time_t value;
  decoder->mal_decoder_decode_time(decoder, cursor, &value);
  if (value != ref) {
      printf("Test time %ld != %ld\n", value, ref);
      return false;
  }
  return true;
}

void addFineTimeEncodingLength(mal_encoder_t *encoder, void *cursor, mal_finetime_t value) {
  encoder->mal_encoder_add_finetime_encoding_length(encoder, value, cursor);
}

void writeFineTime(mal_encoder_t *encoder, void *cursor, mal_finetime_t value) {
  encoder->mal_encoder_encode_finetime(encoder, cursor, value);
}

bool testFineTime(mal_decoder_t *decoder, void *cursor, mal_finetime_t ref) {
  mal_finetime_t value;
  decoder->mal_decoder_decode_finetime(decoder, cursor, &value);
  if (value != ref) {
      printf("Test finetime %ld != %ld\n", value, ref);
      return false;
  }
  return true;
}

char *testEncoding(mal_encoder_t *encoder, void *cursor) {
  addBooleanEncodingLength(encoder, cursor, BOOL1);
  addUOctetEncodingLength(encoder, cursor, UOCTET1);
  addUOctetEncodingLength(encoder, cursor, UOCTET2);
  addOctetEncodingLength(encoder, cursor, OCTET1);
  addOctetEncodingLength(encoder, cursor, OCTET2);
  addOctetEncodingLength(encoder, cursor, OCTET3);
  addBooleanEncodingLength(encoder, cursor, BOOL2);
  addUShortEncodingLength(encoder, cursor, USHORT1);
  addUShortEncodingLength(encoder, cursor, USHORT2);
  addUShortEncodingLength(encoder, cursor, USHORT3);
  addShortEncodingLength(encoder, cursor, SHORT1);
  addShortEncodingLength(encoder, cursor, SHORT2);
  addShortEncodingLength(encoder, cursor, SHORT3);
  addShortEncodingLength(encoder, cursor, SHORT4);
  addShortEncodingLength(encoder, cursor, SHORT5);
  addBooleanEncodingLength(encoder, cursor, BOOL3);
  addUIntEncodingLength(encoder, cursor, UINT1);
  addUIntEncodingLength(encoder, cursor, UINT2);
  addUIntEncodingLength(encoder, cursor, UINT3);
  addUIntEncodingLength(encoder, cursor, UINT4);
  addIntEncodingLength(encoder, cursor, INT1);
  addIntEncodingLength(encoder, cursor, INT2);
  addIntEncodingLength(encoder, cursor, INT3);
  addIntEncodingLength(encoder, cursor, INT4);
  addIntEncodingLength(encoder, cursor, INT5);
  addIntEncodingLength(encoder, cursor, INT6);
  addIntEncodingLength(encoder, cursor, INT7);
  addBooleanEncodingLength(encoder, cursor, BOOL4);
  addULongEncodingLength(encoder, cursor, ULONG1);
  addULongEncodingLength(encoder, cursor, ULONG2);
  addULongEncodingLength(encoder, cursor, ULONG3);
  addLongEncodingLength(encoder, cursor, LONG1);
  addLongEncodingLength(encoder, cursor, LONG2);
  addLongEncodingLength(encoder, cursor, LONG3);
  addBooleanEncodingLength(encoder, cursor, BOOL5);
  addFloatEncodingLength(encoder, cursor, FLOAT1);
  addFloatEncodingLength(encoder, cursor, FLOAT2);
  addBooleanEncodingLength(encoder, cursor, BOOL6);
  addDoubleEncodingLength(encoder, cursor, DOUBLE1);
  addDoubleEncodingLength(encoder, cursor, DOUBLE2);
  addBooleanEncodingLength(encoder, cursor, BOOL7);
  addBlobEncodingLength(encoder, cursor, BLOB1);
  addBooleanEncodingLength(encoder, cursor, BOOL8);
  addStringEncodingLength(encoder, cursor, STRING1);
  addBooleanEncodingLength(encoder, cursor, BOOL9);
  addTimeEncodingLength(encoder, cursor, TIME1);
  addBooleanEncodingLength(encoder, cursor, BOOL10);
  addFineTimeEncodingLength(encoder, cursor, FINETIME1);
  addBooleanEncodingLength(encoder, cursor, BOOL11);

  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor);
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(encoder, cursor, buf, length, 0);

  writeBoolean(encoder, cursor, BOOL1);
  writeUOctet(encoder, cursor, UOCTET1);
  writeUOctet(encoder, cursor, UOCTET2);
  writeOctet(encoder, cursor, OCTET1);
  writeOctet(encoder, cursor, OCTET2);
  writeOctet(encoder, cursor, OCTET3);
  writeBoolean(encoder, cursor, BOOL2);
  writeUShort(encoder, cursor, USHORT1);
  writeUShort(encoder, cursor, USHORT2);
  writeUShort(encoder, cursor, USHORT3);
  writeShort(encoder, cursor, SHORT1);
  writeShort(encoder, cursor, SHORT2);
  writeShort(encoder, cursor, SHORT3);
  writeShort(encoder, cursor, SHORT4);
  writeShort(encoder, cursor, SHORT5);
  writeBoolean(encoder, cursor, BOOL3);
  writeUInt(encoder, cursor, UINT1);
  writeUInt(encoder, cursor, UINT2);
  writeUInt(encoder, cursor, UINT3);
  writeUInt(encoder, cursor, UINT4);
  writeInt(encoder, cursor, INT1);
  writeInt(encoder, cursor, INT2);
  writeInt(encoder, cursor, INT3);
  writeInt(encoder, cursor, INT4);
  writeInt(encoder, cursor, INT5);
  writeInt(encoder, cursor, INT6);
  writeInt(encoder, cursor, INT7);
  writeBoolean(encoder, cursor, BOOL4);
  writeULong(encoder, cursor, ULONG1);
  writeULong(encoder, cursor, ULONG2);
  writeULong(encoder, cursor, ULONG3);
  writeLong(encoder, cursor, LONG1);
  writeLong(encoder, cursor, LONG2);
  writeLong(encoder, cursor, LONG3);
  writeBoolean(encoder, cursor, BOOL5);
  writeFloat(encoder, cursor, FLOAT1);
  writeFloat(encoder, cursor, FLOAT2);
  writeBoolean(encoder, cursor, BOOL6);
  writeDouble(encoder, cursor, DOUBLE1);
  writeDouble(encoder, cursor, DOUBLE2);
  writeBoolean(encoder, cursor, BOOL7);
  writeBlob(encoder, cursor, BLOB1);
  writeBoolean(encoder, cursor, BOOL8);
  writeString(encoder, cursor, STRING1);
  writeBoolean(encoder, cursor, BOOL9);
  writeTime(encoder, cursor, TIME1);
  writeBoolean(encoder, cursor, BOOL10);
  writeFineTime(encoder, cursor, FINETIME1);
  writeBoolean(encoder, cursor, BOOL11);

  return buf;
}

void writeFile(char *path, char *buf, int len) {
  int ret = 0;

  int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC);
  if (fd < 0) {
    printf("open ERROR: %d\n", errno);
    return;
  }
  ret = write(fd, buf, len);
  if (ret != len) {
    printf("write ERROR %d %d\n", ret, errno);
    return;
  }
  ret = close(fd);
  if (ret != 0) {
    printf("close ERROR %d %d\n", ret, errno);
    return;
  }
}

void readFile(char *path, char **buf, int *len) {
  int fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror(path);
    printf("open ERROR: %d\n", errno);
    return;
  }
  int size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  *buf = (char *) calloc(1, size);
  *len = read(fd, *buf, size);
  if (*len != size) {
    printf("read ERROR %d %d\n", *len, errno);
  }
  return;
}

bool testDecoding(mal_decoder_t *decoder, void *cursor) {
  bool ok = true;

  ok &= testBoolean(decoder, cursor, BOOL1);
  ok &= testUOctet(decoder, cursor, UOCTET1);
  ok &= testUOctet(decoder, cursor, UOCTET2);
  ok &= testOctet(decoder, cursor, OCTET1);
  ok &= testOctet(decoder, cursor, OCTET2);
  ok &= testOctet(decoder, cursor, OCTET3);
  ok &= testBoolean(decoder, cursor, BOOL2);
  ok &= testUShort(decoder, cursor, USHORT1);
  ok &= testUShort(decoder, cursor, USHORT2);
  ok &= testUShort(decoder, cursor, USHORT3);
  ok &= testShort(decoder, cursor, SHORT1);
  ok &= testShort(decoder, cursor, SHORT2);
  ok &= testShort(decoder, cursor, SHORT3);
  ok &= testShort(decoder, cursor, SHORT4);
  ok &= testShort(decoder, cursor, SHORT5);
  ok &= testBoolean(decoder, cursor, BOOL3);
  ok &= testUInt(decoder, cursor, UINT1);
  ok &= testUInt(decoder, cursor, UINT2);
  ok &= testUInt(decoder, cursor, UINT3);
  ok &= testUInt(decoder, cursor, UINT4);
  ok &= testInt(decoder, cursor, INT1);
  ok &= testInt(decoder, cursor, INT2);
  ok &= testInt(decoder, cursor, INT3);
  ok &= testInt(decoder, cursor, INT4);
  ok &= testInt(decoder, cursor, INT5);
  ok &= testInt(decoder, cursor, INT6);
  ok &= testInt(decoder, cursor, INT7);
  ok &= testBoolean(decoder, cursor, BOOL4);
  ok &= testULong(decoder, cursor, ULONG1);
  ok &= testULong(decoder, cursor, ULONG2);
  ok &= testULong(decoder, cursor, ULONG3);
  ok &= testLong(decoder, cursor, LONG1);
  ok &= testLong(decoder, cursor, LONG2);
  ok &= testLong(decoder, cursor, LONG3);
  ok &= testBoolean(decoder, cursor, BOOL5);
  ok &= testFloat(decoder, cursor, FLOAT1);
  ok &= testFloat(decoder, cursor, FLOAT2);
  ok &= testBoolean(decoder, cursor, BOOL6);
  ok &= testDouble(decoder, cursor, DOUBLE1);
  ok &= testDouble(decoder, cursor, DOUBLE2);
  ok &= testBoolean(decoder, cursor, BOOL7);
  ok &= testBlob(decoder, cursor, BLOB1);
  ok &= testBoolean(decoder, cursor, BOOL8);
  ok &= testString(decoder, cursor, STRING1);
  ok &= testBoolean(decoder, cursor, BOOL9);
  ok &= testTime(decoder, cursor, TIME1);
  ok &= testBoolean(decoder, cursor, BOOL10);
  ok &= testFineTime(decoder, cursor, FINETIME1);
  ok &= testBoolean(decoder, cursor, BOOL11);

  return ok;
}

bool compareFiles(char *msg, char *file1, char *file2);

bool testFixedBinaryEncoding() {
  // Creates the encoder
  mal_encoder_t *encoder = malbinary_encoder_new(false);
  void *cursor = mal_encoder_new_cursor(encoder);
  // Runs the test
  char* buf = testEncoding(encoder, cursor);
  int length = mal_encoder_cursor_get_length(encoder, cursor);
  // Writes encoding datas in file
  writeFile("./cfixedbinary.data", buf, length);
  return compareFiles("testFixedBinaryEncoding: %s\n", "./cfixedbinary.ref", "./cfixedbinary.data");
}

bool testFixedBinaryDecoding() {
  int length = 0;
  char *buf = NULL;
  // Reads file
  readFile("./cfixedbinary.ref", &buf, &length);
  // Creates the decoder
  mal_decoder_t *decoder = malbinary_decoder_new(false);
  void *cursor = mal_decoder_new_cursor(decoder, buf, length, 0);

  return testDecoding(decoder, cursor);
}

bool testVarintBinaryEncoding() {
  // Creates the encoder
  mal_encoder_t *encoder = malbinary_encoder_new(true);
  void *cursor1 = mal_encoder_new_cursor(encoder);
  // Runs the test
  char* buf = testEncoding(encoder, cursor1);
  int length = mal_encoder_cursor_get_length(encoder, cursor1);
  // Writes encoding datas in file
  writeFile("./cvarintbinary.data", buf, length);
  return compareFiles("testVarintBinaryEncoding: %s\n", "./cfixedbinary.ref", "./cfixedbinary.data");
}

bool testVarintBinaryDecoding() {
  int length = 0;
  char *buf = NULL;
  // Reads file
  readFile("./cvarintbinary.ref", &buf, &length);
  // Creates the decoder
  mal_decoder_t *decoder = malbinary_decoder_new(true);
  void *cursor2 = mal_decoder_new_cursor(decoder, buf, length, 0);

  return testDecoding(decoder, cursor2);
}

bool testSplitBinaryEncoding() {
  // Creates the encoder
  mal_encoder_t *encoder = malsplitbinary_encoder_new();
  void *cursor1 = mal_encoder_new_cursor(encoder);
  // Runs the test
  char* buf = testEncoding(encoder, cursor1);
  int length = mal_encoder_cursor_get_length(encoder, cursor1);
  // Writes encoding datas in file
  writeFile("./csplitbinary.data", buf, length);
  return compareFiles("testSplitBinaryEncoding: %s\n", "./cfixedbinary.ref", "./cfixedbinary.data");
}

bool testSplitBinaryDecoding() {
  int length = 0;
  char *buf = NULL;
  // Reads file
  readFile("./csplitbinary.ref", &buf, &length);
  // Creates the decoder
  mal_decoder_t *decoder = malsplitbinary_decoder_new();
  void *cursor2 = mal_decoder_new_cursor(decoder, buf, length, 0);

  return testDecoding(decoder, cursor2);
}

void file_encoding_test(bool verbose) {
  bool ok = true;

  // @selftest
  printf(" * encoding: ");
  if (verbose) printf("\n");

  ok &= initialize();

  ok &= testFixedBinaryEncoding();
  if (verbose) printf("testFixedBinaryEncoding\n");
  ok &= testVarintBinaryEncoding();
  if (verbose) printf("testVarintBinaryEncoding\n");
  ok &= testSplitBinaryEncoding();
  if (verbose) printf("testSplitBinaryEncoding\n");
  ok &= testFixedBinaryDecoding();
  if (verbose) printf("testFixedBinaryDecoding\n");
  ok &= testVarintBinaryDecoding();
  if (verbose) printf("testFixedBinaryDecoding\n");
  ok &= testSplitBinaryDecoding();
  if (verbose) printf("testFixedBinaryDecoding\n");
  //  @end

  printf("%s\n", ok?"OK":"ERROR");
}

bool compareFiles(char *msg, char *file1, char *file2) {
  FILE *fp1, *fp2;
  char ch1, ch2, same;
  unsigned long l;

  /* open first file */
  if((fp1 = fopen(file1, "rb"))==NULL) {
    printf(msg, "Cannot open first file.\n");
    return false;
  }

  /* open second file */
  if((fp2 = fopen(file2, "rb"))==NULL) {
    printf(msg, "Cannot open second file.\n");
    return false;
  }

  l = 0;
  same = true;
  /* compare the files */
  while(!feof(fp1)) {
    ch1 = fgetc(fp1);
    if(ferror(fp1)) {
      printf(msg, "Error reading first file.\n");
      same = false;
      break;
    }
    ch2 = fgetc(fp2);
    if(ferror(fp2)) {
      printf(msg, "Error reading second file.\n");
      same = false;
      break;
    }
    if(ch1 != ch2) {
      printf(msg, "Files differ");
      same = false;
      break;
    }
    l++;
  }

  fclose(fp1);
  fclose(fp2);

  return same;
}
