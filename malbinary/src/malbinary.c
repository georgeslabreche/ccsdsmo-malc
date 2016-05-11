#include "malbinary.h"

void  malbinary_cursor_initialize(malbinary_cursor_t *cursor) {
  cursor->body_ptr = (char *) 0;
  cursor->body_length = 0;
  cursor->body_offset = 0;
}

//void malbinary_cursor_map_message(malbinary_cursor_t *cursor, mal_message_t *message) {
//  cursor->body_ptr = mal_message_get_body(message);
//  cursor->body_offset = mal_message_get_body_offset(message);
//}

unsigned int malbinary_cursor_get_body_length(malbinary_cursor_t *cursor){
  return cursor->body_length;
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
