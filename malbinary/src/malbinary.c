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

void malbinary_add_length(void *cursor, unsigned int length) {
  ((malbinary_cursor_t *) cursor)->body_length += length;
}

void malbinary_cursor_assert(void *cursor) {
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
