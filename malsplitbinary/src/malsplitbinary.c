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

clog_logger_t malsplitbinary_logger = CLOG_WARN_LEVEL;

void malsplitbinary_set_log_level(int level) {
  malsplitbinary_logger = level;
}

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
  while ((value & -128) != 0)
  {
    bytes[index++] = (char) ((value & 127) | 128);
    value >>= 7;
  }
  bytes[index++] = (char) (value & 127);
}

unsigned int malsplitbinary_cursor_get_bitfield_nb_bytes(unsigned int most_significant) {
  // The result should be zero if most_significant is zero.
  if (most_significant <= 0) return 0;
  return ((most_significant -1) /8) +1;
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

/**
 * This function is called after evaluation of the size of encoded message.
 * It initializes the cursor before the encoding phase.
 */
void  malsplitbinary_encoder_cursor_init(void *cursor,
    char *bytes,              //message
    unsigned int length,      //message length
    unsigned int offset) {    //message_offset
  ((malsplitbinary_cursor_t *) cursor)->bitfield_length = ((malsplitbinary_cursor_t *) cursor)->most_significant;
  unsigned int bf_nb_bytes = malsplitbinary_cursor_get_bitfield_nb_bytes(((malsplitbinary_cursor_t *) cursor)->most_significant);
  // set most_significant bytes length
  malbinary_write_uvarinteger(bf_nb_bytes, bytes+offset);
  // Calculates the bitfield offset
  unsigned int bf_offset = offset + malbinary_var_uinteger_encoding_length(bf_nb_bytes);
  // Cleans the bitfield area
  if (bf_nb_bytes > 0) memset(&bytes[bf_offset], 0, bf_nb_bytes);
  ((malsplitbinary_cursor_t *) cursor)->bitfield_ptr = &bytes[bf_offset];
  //body_offset
  int body_offset = bf_offset + bf_nb_bytes;
  //body_length
  int body_length = length - body_offset;
  malbinary_cursor_init(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor, bytes, body_length, body_offset);
  // Reset bitfield index in order to encode bits.
  ((malsplitbinary_cursor_t *) cursor)->bitfield_idx = 0;

  // NOTE: Only used for debug
  // malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor);
}

/**
 * This function initializes the cursor before the decoding phase.
 */
void  malsplitbinary_decoder_cursor_init(void *cursor,
    char *bytes,            //message
    unsigned int length,    //message length
    unsigned int offset) {  //message_offset

  unsigned int bf_nb_bytes = malbinary_read_uvarinteger(bytes+offset);
  ((malsplitbinary_cursor_t *) cursor)->bitfield_length = bf_nb_bytes *8;

  unsigned int bf_offset = offset + malbinary_var_uinteger_encoding_length(bf_nb_bytes);
  ((malsplitbinary_cursor_t *) cursor)->bitfield_ptr = &bytes[bf_offset];
  //body_offset
  int body_offset = bf_offset + bf_nb_bytes;
  //body_length
  int body_length = length - body_offset;
  // Initializes malbinary part of cursor
  malbinary_cursor_init(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor, bytes, body_length, body_offset);
  // Set next bit to decode index
  ((malsplitbinary_cursor_t *) cursor)->bitfield_idx = 0;
  // Unused during decoding but avoids leaving an uninitialized field
  ((malsplitbinary_cursor_t *) cursor)->most_significant = 0;

  // NOTE: Only used for debug
  // malsplitbinary_cursor_print((malsplitbinary_cursor_t *) cursor);
}

void malsplitbinary_cursor_assert(void *cursor) {
  // NOTE: Only used for debug
//  printf("-- malsplitbinary_cursor_assert: body_offset %d <= %d length\n",
//      (((malsplitbinary_cursor_t *) cursor)->malbinary_cursor.body_offset + malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor)),
//      malsplitbinary_cursor_get_length(cursor));
//  printf("-- malsplitbinary_cursor_assert: bitfield_idx %d, %d bitfield_length\n",
//      ((malsplitbinary_cursor_t *) cursor)->bitfield_idx,
//      ((malsplitbinary_cursor_t *) cursor)->bitfield_length);
  assert(((malsplitbinary_cursor_t *) cursor)->malbinary_cursor.body_offset + malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor) <= malsplitbinary_cursor_get_length(cursor));
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

/**
 * Returns the size in bytes of the bitfield including the encoding of its size.
 */
unsigned int malsplitbinary_cursor_get_bitfield_length(malsplitbinary_cursor_t *cursor) {
  unsigned int bf_nb_bytes = malsplitbinary_cursor_get_bitfield_nb_bytes(cursor->most_significant);
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
  // NOTE: Only used for debug
//  printf("message len = %d (body %d + bitfield %d)\n",
//      (malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor) +
//          malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor)),
//          malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor),
//          malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor));//NTA tmp
  return malbinary_cursor_get_length(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor) +
      malsplitbinary_cursor_get_bitfield_length((malsplitbinary_cursor_t *) cursor);
}

unsigned int malsplitbinary_cursor_get_offset(void *cursor) {
  return malbinary_cursor_get_offset(&((malsplitbinary_cursor_t *) cursor)->malbinary_cursor);
}


void malsplitbinary_cursor_print(malsplitbinary_cursor_t *cursor) {
  clog_debug(malsplitbinary_logger, "malsplitbinary_cursor(");
  if (cursor) {
    clog_debug_no_header(malsplitbinary_logger, "bitfield_idx=%d, ", malsplitbinary_cursor_get_bitfield_idx(cursor));
    clog_debug_no_header(malsplitbinary_logger, "bitfield_length=%d (%d),",
        ((malsplitbinary_cursor_t *) cursor)->bitfield_length, malsplitbinary_cursor_get_bitfield_length(cursor));
    clog_debug_no_header(malsplitbinary_logger, "most_significant=%d, ", malsplitbinary_cursor_get_most_significant(cursor));
    clog_debug_no_header(malsplitbinary_logger, "body_offset=%d, ", malsplitbinary_cursor_get_body_offset(cursor));
    clog_debug_no_header(malsplitbinary_logger, "body_length=%d", malsplitbinary_cursor_get_body_length(cursor));
  } else {
    clog_debug_no_header(malsplitbinary_logger, "NULL");
  }
  clog_debug_no_header(malsplitbinary_logger, ")\n");
}

void malsplitbinary_cursor_dump(malsplitbinary_cursor_t *cursor) {
  char *bitfield = malsplitbinary_cursor_get_bitfield_ptr(cursor);
  int bitfield_idx = malsplitbinary_cursor_get_bitfield_idx(cursor);
  clog_debug(malsplitbinary_logger, "malsplitbinary_cursor(bitfield_length=%d:[", cursor->bitfield_length);
  if ((bitfield != NULL) && (cursor->bitfield_length > 0)) {
    for (int i = 0 ; i < (cursor->bitfield_length/8 + 1) ; i++) {
      for (int j = 0 ; j < 8 && (i*8+j) < cursor->bitfield_length ; j++) {
        if ((i*8+j) == bitfield_idx) {
          // Add a marker for the current position
          clog_debug_no_header(malsplitbinary_logger, ">");
        }
        clog_debug_no_header(malsplitbinary_logger, "%d", (bitfield[i] & (1 << j)) >> j);
      }
    }
  }
  clog_debug_no_header(malsplitbinary_logger, "]");
  char *body = malsplitbinary_cursor_get_body_ptr(cursor);
  unsigned int body_len = malsplitbinary_cursor_get_body_length(cursor);
  int body_offset = malsplitbinary_cursor_get_body_offset(cursor);
  clog_debug_no_header(malsplitbinary_logger, ",body_length=%d:[", body_len);
  if (body != NULL)
  for (int j = 0 ; j < body_len ; j++) {
    if (j == body_offset) {
      // Add a marker for the current position
      clog_debug_no_header(malsplitbinary_logger, ">");
    }
    clog_debug_no_header(malsplitbinary_logger, "%02X ", (unsigned char)body[j]);
  }
  clog_debug_no_header(malsplitbinary_logger,"])\n");
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
