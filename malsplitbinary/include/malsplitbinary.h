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

/*
 */

#ifndef __MALSPLITBINARY_H_INCLUDED__
#define __MALSPLITBINARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "malsplitbinary_library.h"

struct _malsplitbinary_cursor_t {
  malbinary_cursor_t malbinary_cursor;
  // Pointer to the bitfield.
  char *bitfield_ptr;
  // Index of next bit to use during encode or decode.
  unsigned int bitfield_idx;
  // Number of useful bits in bitfield, this counter is only used during the
  // evaluation of bitfield size.
  unsigned int most_significant;
  // Number of bits in bitfield, this counter has several semantics depending of
  // the encoding phase: during the size evaluation it contains the number of encoded
  // bits, during encoding or decoding phases it contains the maximum number of bits
  // in the bitfield area (depending of the most significant bit of this area)
  unsigned int bitfield_length;
  // Note: Normally only 2 counters are needed: bitfield_idx is not used during the
  // size evaluation, most_significant is not used during encoding or decoding.
};
typedef struct _malsplitbinary_cursor_t malsplitbinary_cursor_t;

extern clog_logger_t malsplitbinary_logger;

void malsplitbinary_set_log_level(int level);

void malsplitbinary_cursor_destroy(void *cursor);
void  malsplitbinary_cursor_reset(void *cursor);
void  malsplitbinary_decoder_cursor_init(void *cursor,
    char *bytes, //message
    unsigned int length, //message length
    unsigned int offset); //message_offset
void  malsplitbinary_encoder_cursor_init(void *cursor,
    char *bytes, //message
    unsigned int length, //message length
    unsigned int offset); //message_offset
void  malsplitbinary_decoder_cursor_reset(void *cursor,
    char *bytes, unsigned int length, unsigned int offset);
void malsplitbinary_cursor_assert(void *cursor);
char *malsplitbinary_cursor_get_bitfield_ptr(malsplitbinary_cursor_t *cursor);
unsigned int malsplitbinary_cursor_get_bitfield_idx(malsplitbinary_cursor_t *cursor);
unsigned int malsplitbinary_cursor_get_most_significant(malsplitbinary_cursor_t *cursor);
unsigned int malsplitbinary_cursor_get_bitfield_length(malsplitbinary_cursor_t *cursor);

char *malsplitbinary_cursor_get_body_ptr(malsplitbinary_cursor_t *cursor);
unsigned int malsplitbinary_cursor_get_body_offset(malsplitbinary_cursor_t *cursor);
void malsplitbinary_cursor_print(malsplitbinary_cursor_t *cursor);
void malsplitbinary_cursor_dump(malsplitbinary_cursor_t *cursor);

unsigned int malsplitbinary_cursor_get_length(void *cursor);
unsigned int malsplitbinary_cursor_get_offset(void *cursor);

// The format code must be unique among all the available encoding formats
#define MALSPLITBINARY_FORMAT_CODE 1

#define MALSPLITBINARY_PRESENCE_FLAG_SIZE 1
#define MALSPLITBINARY_ATTRIBUTE_TAG_SIZE 1
#define MALSPLITBINARY_SHORT_FORM_SIZE 8
#define MALSPLITBINARY_SMALL_ENUM_SIZE 1
#define MALSPLITBINARY_MEDIUM_ENUM_SIZE 2
#define MALSPLITBINARY_LARGE_ENUM_SIZE 4

void malsplitbinary_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
