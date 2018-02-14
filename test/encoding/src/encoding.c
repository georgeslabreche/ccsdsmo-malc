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

/* */
#include "../include/encoding.h"

//  --------------------------------------------------------------------------
//  Selftest

bool encoding_test_ushort(bool split, unsigned short value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_ushort(%s, %hu)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_ushort_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_ushort(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_ushort(%s, %hu) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  unsigned short decoded = 0;
  decoder->mal_decoder_decode_ushort(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_ushort(%s, %hu) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_ushort(%s, %hu) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_ushort -> %d/%d/%d, %hu ? %hu %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_uint(bool split, unsigned int value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_uint(%s, %u)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_uinteger_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_uinteger(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_uint(%s, %u) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  unsigned int decoded = 0;
  decoder->mal_decoder_decode_uinteger(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_uint(%s, %u) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_uint(%s, %u) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_uinteger -> %d/%d/%d, %u ? %u %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_ulong(bool split, unsigned long value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_ulong(%s, %lu)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_ulong_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_ulong(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_ulong(%s, %lu) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  unsigned long decoded = 0;
  decoder->mal_decoder_decode_ulong(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_ulong(%s, %lu) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_ulong(%s, %lu) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_ulong -> %d/%d/%d, %lu ? %lu %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}


bool encoding_test_short(bool split, short value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_short(%s, %hd)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_short_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_short(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_short(%s, %hd) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  short decoded = 0;
  decoder->mal_decoder_decode_short(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_short(%s, %hd) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_short(%s, %hd) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_short -> %d/%d/%d, %hd ? %hd %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_int(bool split, int value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_int(%s, %d)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_integer_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_integer(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_int(%s, %d) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  int decoded = 0;
  decoder->mal_decoder_decode_integer(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_int(%s, %d) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_int(%s, %d) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_integer -> %d/%d/%d, %d ? %d %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_long(bool split, long value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_long(%s, %ld)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_long_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_long(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_long(%s, %ld) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  long decoded = 0;
  decoder->mal_decoder_decode_long(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_long(%s, %ld) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_long(%s, %ld) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_long -> %d/%d/%d, %ld ? %ld %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_duration(bool split, mal_duration_t value, bool verbose) {
  int err = 0;
  if (verbose)
    printf("Test encode_duration(%s, %lf)\n", split?"true":"false", value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }

  void *cursor1 = mal_encoder_new_cursor(encoder);
  int size = mal_encoder_cursor_get_length(encoder, cursor1);
  encoder->mal_encoder_add_duration_encoding_length(encoder, value, cursor1);
  size = (mal_encoder_cursor_get_length(encoder, cursor1) - size);
  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
  encoder->mal_encoder_encode_duration(encoder, cursor1, value);
  int offset1 = mal_encoder_cursor_get_offset(encoder, cursor1);
  if (size != offset1) {
    if (verbose)
      printf("Test encode_duration(%s, %lf) Bad encoding offset\n", split?"true":"false", value);
    err +=1;
  }

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
  mal_duration_t decoded = 0.;
  decoder->mal_decoder_decode_duration(decoder, cursor2, &decoded);
  int offset2 = mal_encoder_cursor_get_offset(encoder, cursor2);
  if (size != offset2) {
    if (verbose)
      printf("Test encode_duration(%s, %lf) Bad decoding offset\n", split?"true":"false", value);
    err +=1;
  }
  if (decoded != value) {
    if (verbose)
      printf("Test encode_duration(%s, %lf) Bad decoding value\n", split?"true":"false", value);
    err +=1;
  }

  if ((verbose) || (err > 0))
    printf("Test encode_duration -> %d/%d/%d, %lf ? %lf %s\n",
        size, offset1, offset2, value, decoded, (err == 0)?"OK":"ERROR");

  return (err == 0);
}

bool encoding_test_bools(bool split, unsigned int nb, unsigned long value, bool verbose) {
  if (verbose)
    printf("Test encode_bools(%s, %d, %0lx)\n", split?"true":"false", nb, value);

  mal_encoder_t *encoder;
  mal_decoder_t *decoder;
  if (split) {
    encoder = malsplitbinary_encoder_new();
    decoder = malsplitbinary_decoder_new();
  } else {
    encoder = malbinary_encoder_new(false);
    decoder = malbinary_decoder_new(false);
  }
    malsplitbinary_set_log_level(CLOG_DEBUG_LEVEL);

  void *cursor1 = mal_encoder_new_cursor(encoder);
  for (int i = 0 ; i<nb ; i++) {
    encoder->mal_encoder_add_boolean_encoding_length(encoder, (value >> i) & 0x01, cursor1);
  }
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor1);

  unsigned int length = mal_encoder_cursor_get_length(encoder, cursor1);
  char* buf = (char *) calloc(1, length);
  mal_encoder_cursor_init(
        encoder, cursor1,
        buf,
        length,
        0);
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor1);
  for (int i = 0 ; i<nb ; i++) {
    encoder->mal_encoder_encode_boolean(encoder, cursor1, (value >> i) & 0x01);
  }
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor1);

  void *cursor2 = mal_decoder_new_cursor(
      decoder,
      buf,
      length,
      0);
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor2);
  unsigned long decoded = 0;
  for (int i = 0 ; i<nb ; i++) {
    mal_boolean_t current;
    decoder->mal_decoder_decode_boolean(decoder, cursor2, &current);
    decoded = decoded | (((long) current) << i);
  }
//  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor2);

  printf("Test encode_bools -> %0lx %s\n", decoded, (decoded == value)?"OK":"ERROR");
  return (decoded == value);
}

bool encoding_test1(bool split, bool verbose) {
  bool ok = true;

  ok &= encoding_test_ushort(split, 0, true);
  ok &= encoding_test_ushort(split, 1, true);
  ok &= encoding_test_ushort(split, 127, true);
  ok &= encoding_test_ushort(split, 128, true);
  ok &= encoding_test_ushort(split, 65535, true);

  ok &= encoding_test_uint(split, 0, true);
  ok &= encoding_test_uint(split, 127, true);
  ok &= encoding_test_uint(split, 128, true);
  ok &= encoding_test_uint(split, 65535, true);
  ok &= encoding_test_uint(split, 65536, true);

  ok &= encoding_test_ulong(split, 0L, true);
  ok &= encoding_test_ulong(split, 127L, true);
  ok &= encoding_test_ulong(split, 1L<<16, true);
  ok &= encoding_test_ulong(split, 1L<<32, true);
  ok &= encoding_test_ulong(split, 1L<<63, true);

  ok &= encoding_test_short(split, 0, true);
  ok &= encoding_test_short(split, 1, true);
  ok &= encoding_test_short(split, -1, true);
  ok &= encoding_test_short(split, 127, true);
  ok &= encoding_test_short(split, 128, true);
  ok &= encoding_test_short(split, 32267, true);
  ok &= encoding_test_short(split, -32768, true);

  ok &= encoding_test_int(split, 0, true);
  ok &= encoding_test_int(split, 1, true);
  ok &= encoding_test_int(split, -1, true);
  ok &= encoding_test_int(split, 127, true);
  ok &= encoding_test_int(split, 128, true);
  ok &= encoding_test_int(split, 32267, true);
  ok &= encoding_test_int(split, -32768, true);

  ok &= encoding_test_long(split, 0L, true);
  ok &= encoding_test_long(split, 127L, true);
  ok &= encoding_test_long(split, 1L<<16, true);
  ok &= encoding_test_long(split, 1L<<32, true);
  ok &= encoding_test_long(split, 1L<<62, true);
  ok &= encoding_test_long(split, -(1L<<62), true);

  ok &= encoding_test_duration(split, 1.0, true);

  ok &= encoding_test_bools(split, 1, 0, true);
  ok &= encoding_test_bools(split, 1, 1, true);
  ok &= encoding_test_bools(split, 2, 0, true);
  ok &= encoding_test_bools(split, 2, 0x1, true);
  ok &= encoding_test_bools(split, 2, 0x2, true);
  ok &= encoding_test_bools(split, 3, 0x2, true);
  ok &= encoding_test_bools(split, 4, 0x2, true);
  ok &= encoding_test_bools(split, 8, 0x55, true);
  ok &= encoding_test_bools(split, 16, 0x5555, true);
  ok &= encoding_test_bools(split, 24, 0x555555, true);
  ok &= encoding_test_bools(split, 32, 0x55555555, true);
  ok &= encoding_test_bools(split, 55, 0x1010101010100, true);

  return ok;
}

void encoding_test(bool verbose) {
  bool ok = true;

  // @selftest
  printf(" * encoding: ");
  if (verbose)
    printf("\n");

  ok &= encoding_test1(false, verbose);
  ok &= encoding_test1(true, verbose);
  //  @end

  printf("%s\n", ok?"OK":"ERROR");
}
