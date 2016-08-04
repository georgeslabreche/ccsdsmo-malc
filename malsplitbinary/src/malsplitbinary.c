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

#include "malsplitbinary.h"

//decode bitfield most significant
unsigned int malbinary_read_uvarinteger(char *bytes) {
  unsigned int index = 0;
  unsigned int value = 0;
  int i;
  int b;
  for (i = 0; ((b = bytes[index++]) & 0x80) != 0; i += 7) {
    value |= (b & 0x7f) << i;
  }
  return value | b << i;
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

void malbinary_write_uvarinteger(unsigned int value, char *bytes)
{
  unsigned int index = 0;
  while ((value & -128) != 0L)
  {
    bytes[index++] = (char) ((value & 127) | 128);
    value >>= 7;
  }
  bytes[index++] = (char) (value & 127);
}

unsigned int malsplitbinary_cursor_get_bitfield_nb_bytes(unsigned int most_significant) {
  if (most_significant%8 == 0)
    return most_significant/8;
  else
    return most_significant/8+1;
}

void malsplitbinary_cursor_destroy(void *cursor) {
  if (! cursor) free(cursor);
}

void  malsplitbinary_cursor_reset(void *cursor) {
  malbinary_cursor_reset(&((malsplitbinary_cursor_t *)cursor)->malbinary_cursor);
  ((malsplitbinary_cursor_t *)cursor)->bitfield_ptr = (char *)0;
  ((malsplitbinary_cursor_t *)cursor)->bitfield_idx = 0;
  ((malsplitbinary_cursor_t *)cursor)->most_significant = 0;
  ((malsplitbinary_cursor_t *)cursor)->bitfield_length = 0;
}


void  malsplitbinary_decoder_cursor_reset(void *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  malsplitbinary_cursor_reset(cursor);
  malsplitbinary_decoder_cursor_init(cursor, bytes, length, offset);
}

void  malsplitbinary_encoder_cursor_init(void *cursor,
    char *bytes, //message
    unsigned int length, //message length
    unsigned int offset) { //message_offset

  unsigned int bf_nb_bytes = malsplitbinary_cursor_get_bitfield_nb_bytes(((malsplitbinary_cursor_t *) cursor)->bitfield_length);
  // set most_significant bytes length
  malbinary_write_uvarinteger(bf_nb_bytes, bytes+offset);
  //printf("--- bf_nb_bytes = %d\n", bf_nb_bytes);//NTA tmp

  unsigned int bf_offset = offset + malbinary_var_uinteger_encoding_length(bf_nb_bytes);
  //printf("malsplitbinary_encoder_cursor_init bf_offset = %d\n", bf_offset);//NTA tmp
  ((malsplitbinary_cursor_t *) cursor)->bitfield_ptr = &bytes[bf_offset];
  //body_offset
  int body_offset = bf_offset + bf_nb_bytes;
  //printf("malsplitbinary_encoder_cursor_init body_offset = %d\n", body_offset);//NTA tmp
  //body_length
  int body_length = length - body_offset;
  //printf("malsplitbinary_encoder_cursor_init body_length = %d\n", body_length);//NTA tmp
  malbinary_cursor_init(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor, bytes, body_length, body_offset);

  ((malsplitbinary_cursor_t *) cursor)->bitfield_idx = 0;
  ((malsplitbinary_cursor_t *) cursor)->most_significant = ((malsplitbinary_cursor_t *) cursor)->bitfield_length;

  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor);
}

void  malsplitbinary_decoder_cursor_init(void *cursor,
    char *bytes, //message
    unsigned int length, //message length
    unsigned int offset) { //message_offset

  unsigned int bf_nb_bytes = malbinary_read_uvarinteger(bytes);
  //printf("-- malsplitbinary_decoder_cursor_init read bf_nb_bytes = %d\n", bf_nb_bytes);//NTA tmp
  ((malsplitbinary_cursor_t *) cursor)->bitfield_length = bf_nb_bytes * 8;// max bitfield length

  unsigned int bf_offset = offset + malbinary_var_uinteger_encoding_length(bf_nb_bytes);
  //printf("-- malsplitbinary_decoder_cursor_init bf_offset = %d\n", bf_offset);//NTA tmp
  ((malsplitbinary_cursor_t *) cursor)->bitfield_ptr = &bytes[bf_offset];
  //body_offset
  int body_offset = bf_offset + bf_nb_bytes;
  //printf("-- malsplitbinary_decoder_cursor_init body_offset = %d\n", body_offset);//NTA tmp
  //body_length
  int body_length = length - body_offset;
  //printf("-- malsplitbinary_decoder_cursor_init body_length = %d\n", body_length);//NTA tmp
  malbinary_cursor_init(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor, bytes, body_length, body_offset);

  ((malsplitbinary_cursor_t *) cursor)->bitfield_idx = 0;
  //((malsplitbinary_cursor_t *) cursor)->most_significant = most_significant;
  ((malsplitbinary_cursor_t *) cursor)->most_significant = 0;
  malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor);
}

void malsplitbinary_cursor_assert(void *cursor) {
  printf("-- malsplitbinary_cursor_assert: body_offset %d <= %d length\n",
      (((malsplitbinary_cursor_t *) cursor)->malbinary_cursor.body_offset + malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor)),
      malsplitbinary_cursor_get_length(cursor));//NTA tmp
  printf("-- malsplitbinary_cursor_assert: bitfield_idx %d <= %d bitfield_length\n",
      ((malsplitbinary_cursor_t *) cursor)->bitfield_idx,
      ((malsplitbinary_cursor_t *) cursor)->bitfield_length);//NTA tmp
  assert(((malsplitbinary_cursor_t *) cursor)->malbinary_cursor.body_offset + malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor) <= malsplitbinary_cursor_get_length(cursor));
  assert(((malsplitbinary_cursor_t *) cursor)->bitfield_idx <= ((malsplitbinary_cursor_t *) cursor)->bitfield_length);
}

char *malsplitbinary_cursor_get_bitfield_ptr(malsplitbinary_cursor_t *cursor) {
  return cursor->bitfield_ptr;
}

unsigned int malsplitbinary_cursor_get_bitfield_idx(malsplitbinary_cursor_t *cursor) {
  return cursor->bitfield_idx;
}

unsigned int malsplitbinary_cursor_get_most_significant(malsplitbinary_cursor_t *cursor) {
  return cursor->most_significant;
}

unsigned int malsplitbinary_cursor_get_bitfield_length(malsplitbinary_cursor_t *cursor) {
  unsigned int bf_nb_bytes = malsplitbinary_cursor_get_bitfield_nb_bytes(cursor->bitfield_length);
  return malbinary_var_uinteger_encoding_length(bf_nb_bytes) + bf_nb_bytes;
}

char *malsplitbinary_cursor_get_body_ptr(malsplitbinary_cursor_t *cursor) {
  return cursor->malbinary_cursor.body_ptr;
}

unsigned int malsplitbinary_cursor_get_body_offset(malsplitbinary_cursor_t *cursor) {
  return malbinary_cursor_get_offset(&cursor->malbinary_cursor);
}

unsigned int malsplitbinary_cursor_get_body_length(malsplitbinary_cursor_t *cursor) {
  return malbinary_cursor_get_length(&cursor->malbinary_cursor);
}

unsigned int malsplitbinary_cursor_get_length(void *cursor) {
  /*
  printf("message len = %d (body %d + bitfield %d)\n",
      (malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor) +
          malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor)),
      malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor),
      malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor));//NTA tmp
      */
  return malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor) +
      malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor);
}

unsigned int malsplitbinary_cursor_get_offset(void *cursor) {
  return malbinary_cursor_get_offset(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor);
}


void malsplitbinary_cursor_print(malsplitbinary_cursor_t *cursor) {
  printf("malsplitbinary_cursor(");
  if (cursor) {
    printf("bitfield_idx=%d, ", malsplitbinary_cursor_get_bitfield_idx(cursor));
    printf("bitfield_length=%d, ", malsplitbinary_cursor_get_bitfield_length(cursor));
    printf("most_significant=%d, ", malsplitbinary_cursor_get_most_significant(cursor));
    printf("body_offset=%d, ", malsplitbinary_cursor_get_body_offset(cursor));
    printf("body_length=%d", malsplitbinary_cursor_get_body_length(cursor));
  } else {
    printf("NULL");
  }
  printf(")\n");
}

void malsplitbinary_test(bool verbose) {
  printf(" * malsplitbinary: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
