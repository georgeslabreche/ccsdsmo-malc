/*
 */

#include "malattributes.h"

// MAL strings have to be allocated
mal_string_t *mal_string_new(char *char_content) {
  // Add final '\0'
  size_t bytes_count = strlen(char_content) + 1;
  char *self = (char *) calloc(bytes_count, sizeof(char));
  if (!self)
    return NULL;
  strncpy(self, char_content, bytes_count);
  return self;
}

void mal_string_destroy(mal_string_t **self_p) {
  if (*self_p != NULL) {
    free((*self_p));
    (*self_p) = NULL;
  }
}

size_t mal_string_get_char_count(mal_string_t *self) {
  return strlen(self);
}

void mal_string_test(bool verbose) {
  printf(" * mal_string: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
