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

#include "malbinary.h"

void malbinary_cursor_destroy(void *cursor) {
  if (! cursor) free(cursor);
}

void  malbinary_cursor_reset(void *cursor) {
  ((malbinary_cursor_t *) cursor)->body_ptr = (char *) 0;
  ((malbinary_cursor_t *) cursor)->body_length = 0;
  ((malbinary_cursor_t *) cursor)->body_offset = 0;
}

void malbinary_cursor_init(void *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  ((malbinary_cursor_t *) cursor)->body_ptr = &bytes[offset];
  ((malbinary_cursor_t *) cursor)->body_length = length;
  ((malbinary_cursor_t *) cursor)->body_offset = 0;
}

void malbinary_cursor_copy(malbinary_cursor_t *from, malbinary_cursor_t *to) {
  to->body_ptr = from->body_ptr;
  to->body_length = from->body_length;
  to->body_offset = from->body_offset;
}

void malbinary_cursor_assert(void *cursor) {
  // NOTE: Only used for debug
//  printf("-- body_offset = %d <= %d = body_length\n",
//      ((malbinary_cursor_t *) cursor)->body_offset, ((malbinary_cursor_t *) cursor)->body_length);
  assert(((malbinary_cursor_t *) cursor)->body_offset <= ((malbinary_cursor_t *) cursor)->body_length);
}

unsigned int malbinary_cursor_get_length(void *cursor){
  return ((malbinary_cursor_t *) cursor)->body_length;
}

unsigned int malbinary_cursor_get_offset(void *cursor){
  return ((malbinary_cursor_t *) cursor)->body_offset;
}

void malbinary_test(bool verbose) {
  printf(" * malbinary: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
