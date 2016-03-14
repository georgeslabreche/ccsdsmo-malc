/*
 */

#include "mal.h"

struct _mal_list_t {
  unsigned int element_count;
  void **content;
};

mal_list_t *mal_list_new(unsigned int element_count) {
  mal_list_t *self = (mal_list_t *) malloc(sizeof(mal_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->content = (void **) malloc(sizeof(void *) * element_count);

  return self;
}

void mal_list_destroy(mal_list_t **self_p) {
  if (*self_p) {
    mal_list_t *self = *self_p;
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_list_get_element_count(mal_list_t *self) {
  return self->element_count;
}

void **mal_list_get_content(mal_list_t *self) {
  return self->content;
}

void mal_list_test(bool verbose) {
  printf(" * mal_list: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

