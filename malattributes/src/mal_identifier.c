/*
 */

#include "malattributes.h"

// MAL strings have to be allocated
mal_identifier_t *mal_identifier_new(char *char_content) {
  // Add final '\0'
  size_t bytes_count = strlen(char_content) + 1;
  char *self = (char *) malloc(sizeof(char) * bytes_count);
  strncpy(self, char_content, bytes_count);
  return self;
}

void mal_identifier_destroy(mal_identifier_t **self_p) {
  if (*self_p) {
    mal_identifier_t *self = *self_p;
    free(self);
    *self_p = NULL;
  }
}

size_t mal_identifier_get_char_count(mal_identifier_t *self) {
  return strlen(self);
}

void mal_identifier_test(bool verbose) {
  printf(" * mal_identifier: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
