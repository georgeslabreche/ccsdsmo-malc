#include "malbinary.h"

void  malbinary_cursor_reset(malbinary_cursor_t *cursor) {
  cursor->body_ptr = (char *) 0;
  cursor->body_length = 0;
  cursor->body_offset = 0;
}

void malbinary_cursor_init(malbinary_cursor_t *cursor,
    char *bytes, unsigned int length, unsigned int offset) {
  cursor->body_ptr = &bytes[offset];
  cursor->body_length = length;
  cursor->body_offset = 0;
}

void malbinary_cursor_copy(malbinary_cursor_t *from, malbinary_cursor_t *to) {
  to->body_ptr = from->body_ptr;
  to->body_length = from->body_length;
  to->body_offset = from->body_offset;
}

void malbinary_cursor_assert(malbinary_cursor_t *cursor) {
  assert(cursor->body_offset <= cursor->body_length);
}

unsigned int malbinary_cursor_get_body_length(malbinary_cursor_t *cursor){
  return cursor->body_length;
}

unsigned int malbinary_cursor_get_body_offset(malbinary_cursor_t *cursor){
  return cursor->body_offset;
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
