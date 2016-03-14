/*
 */

#include "malattributes.h"

struct _mal_blob_t {
  unsigned int length;
  char *content;
};

mal_blob_t *mal_blob_new(unsigned int length) {
  mal_blob_t *self = (mal_blob_t *) malloc(sizeof(mal_blob_t));
  if (!self)
    return NULL;

  self->length = length;
  self->content = (char *) malloc(sizeof(char) * length);

  return self;
}

void mal_blob_destroy(mal_blob_t **self_p) {
  if (*self_p) {
    mal_blob_t *self = *self_p;
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_blob_get_length(mal_blob_t *self) {
  return self->length;
}

char *mal_blob_get_content(mal_blob_t *self) {
  return self->content;
}

// TODO: Needs better integration with logging subsystem.
void mal_blob_print(mal_blob_t *self) {
  printf("mal_blob(");
  printf("length=%d", self->length);
  printf(",content=");
  for (int i = 0; i < self->length; i++) {
    printf("%#02x,", self->content[i]);
  }
  printf(")\n");
}

void mal_blob_test(bool verbose) {
  printf(" * mal_blob: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

