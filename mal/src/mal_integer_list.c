/*
 */

#include "mal.h"

struct _mal_integer_list_t {
  unsigned int element_count;
  bool *presence_flags;
  mal_integer_t *content;
};

mal_integer_list_t *mal_integer_list_new(unsigned int element_count) {
  mal_integer_list_t *self = (mal_integer_list_t *) malloc(
      sizeof(mal_integer_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->presence_flags = (bool *) malloc(
      sizeof(bool) * element_count);
  self->content = (mal_integer_t *) malloc(
      sizeof(mal_integer_t) * element_count);

  return self;
}

void mal_integer_list_destroy(mal_integer_list_t **self_p) {
  if (*self_p) {
    mal_integer_list_t *self = *self_p;
    free(self->presence_flags);
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_integer_list_get_element_count(mal_integer_list_t *self) {
  return self->element_count;
}

bool *mal_integer_list_get_presence_flags(mal_integer_list_t *self) {
  return self->presence_flags;
}

mal_integer_t *mal_integer_list_get_content(mal_integer_list_t *self) {
  return self->content;
}

int mal_integer_list_add_encoding_length_malbinary(mal_integer_list_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
  bool *presence_flags = self->presence_flags;
  mal_integer_t *content = self->content;
  // Presence flags
  (*encoding_length) += list_size;
  for (int i = 0; i < list_size; i++) {
    if (presence_flags[i]) {
      mal_integer_t list_element = content[i];
      rc = malbinary_encoder_add_integer_encoding_length(encoder, list_element,
          encoding_length);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_integer_list_encode_malbinary(mal_integer_list_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  bool *presence_flags = self->presence_flags;
  mal_integer_t *content = self->content;
  for (int i = 0; i < list_size; i++) {
    bool present = presence_flags[i];
    rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
        present);
    if (rc < 0)
      return rc;
    if (present) {
      mal_integer_t list_element = content[i];
      rc = malbinary_encoder_encode_integer(encoder, bytes, offset,
          list_element);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_integer_list_decode_malbinary(mal_integer_list_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  bool *presence_flags = (bool *) malloc(sizeof(bool) * list_size);
  mal_integer_t *list_content = (mal_integer_t *) malloc(
      sizeof(mal_integer_t) * list_size);
  for (int i = 0; i < list_size; i++) {
    mal_integer_t list_element;
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
        &presence_flag);
    if (rc < 0)
      return rc;
    presence_flags[i] = presence_flag;
    if (presence_flag) {
      rc = malbinary_decoder_decode_integer(decoder, bytes, offset,
          &list_element);
      if (rc < 0)
        return rc;
      list_content[i] = list_element;
    }
  }
  self->presence_flags = presence_flags;
  self->content = list_content;
  return rc;
}

void mal_integer_list_test(bool verbose) {
  printf(" * mal_integer_list: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

