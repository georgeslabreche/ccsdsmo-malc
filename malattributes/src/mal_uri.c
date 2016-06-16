/*
 */

#include "malattributes.h"

// MAL strings have to be allocated
mal_uri_t *mal_uri_new(char *char_content) {
  // Add final '\0'
  size_t bytes_count = strlen(char_content) + 1;
  char *self = (char *) calloc(bytes_count, sizeof(char));
  strncpy(self, char_content, bytes_count);
  return self;
}

void mal_uri_destroy(mal_uri_t **self_p) {
  if (*self_p) {
    free((*self_p));
    *self_p = NULL;
  }
}

size_t mal_uri_get_char_count(mal_uri_t *self) {
  return strlen(self);
}

void mal_uri_test(bool verbose) {
  printf(" * mal_uri: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
