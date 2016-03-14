/*
 */

#include "mal.h"

struct _mal_enum_list_t {
  unsigned int element_count;
  bool *presence_flags;
  int *content;
};

mal_enum_list_t *mal_enum_list_new(unsigned int element_count,
    bool *presence_flags, int *content) {
  mal_enum_list_t *self = (mal_enum_list_t *) malloc(
      sizeof(mal_enum_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->presence_flags = presence_flags;
  self->content = content;

  return self;
}

unsigned int mal_enum_list_get_element_count(mal_enum_list_t *self) {
  return self->element_count;
}

bool *mal_enum_list_get_presence_flags(mal_enum_list_t *self) {
  return self->presence_flags;
}

int *mal_enum_list_get_content(mal_enum_list_t *self) {
  return self->content;
}

void mal_enum_list_test(bool verbose) {
  printf(" * mal_enum_list: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

