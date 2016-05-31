/*
 */

#include "mal.h"

mal_element_holder_t *mal_element_holder_new() {
  mal_element_holder_t *self = (mal_element_holder_t *) calloc(
      1, sizeof(mal_element_holder_t));
  if (!self)
    return NULL;

  return self;
}

void mal_element_holder_destroy(mal_element_holder_t **self_p) {
  if (*self_p) {
    mal_element_holder_t *self = *self_p;
    free(self);
    *self_p = NULL;
  }
}

bool mal_element_holder_get_presence_flag(mal_element_holder_t *self) {
  return self->presence_flag;
}

void mal_element_holder_set_presence_flag(mal_element_holder_t *self,
    bool presence_flag) {
  self->presence_flag = presence_flag;
}

long mal_element_holder_get_short_form(mal_element_holder_t *self) {
  return self->short_form;
}

void mal_element_holder_set_short_form(mal_element_holder_t *self,
    long short_form) {
  self->short_form = short_form;
}

union mal_element_t mal_element_holder_get_value(mal_element_holder_t *self) {
  return self->value;
}

void mal_element_holder_set_value(mal_element_holder_t *self,
    union mal_element_t value) {
  self->value = value;
}

void mal_element_holder_test(bool verbose) {
  printf(" * mal_element_holder: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

