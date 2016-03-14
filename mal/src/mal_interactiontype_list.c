/*
 */

#include "mal.h"

struct _mal_interactiontype_list_t {
  unsigned int element_count;
  bool *presence_flags;
  mal_interactiontype_t *content;
};

mal_interactiontype_list_t *mal_interactiontype_list_new(
    unsigned int element_count) {
  mal_interactiontype_list_t *self = (mal_interactiontype_list_t *) malloc(
      sizeof(mal_interactiontype_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->presence_flags = (bool *) malloc(sizeof(bool) * element_count);
  self->content = (mal_interactiontype_t *) malloc(
      sizeof(mal_interactiontype_t) * element_count);

  return self;
}

void mal_interactiontype_list_destroy(mal_interactiontype_list_t **self_p) {
  if (*self_p) {
    mal_interactiontype_list_t *self = *self_p;
    free(self->presence_flags);
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_interactiontype_list_get_element_count(
    mal_interactiontype_list_t *self) {
  return self->element_count;
}

bool *mal_interactiontype_list_get_presence_flags(
    mal_interactiontype_list_t *self) {
  return self->presence_flags;
}

mal_interactiontype_t *mal_interactiontype_list_get_content(
    mal_interactiontype_list_t *self) {
  return self->content;
}

int mal_interactiontype_list_add_encoding_length_malbinary(
    mal_interactiontype_list_t *self, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
  bool *presence_flags = self->presence_flags;
  // Presence flags
  (*encoding_length) += list_size;
  for (int i = 0; i < list_size; i++) {
    bool presence_flag = presence_flags[i];
    if (presence_flag) {
      // Small enum
      (*encoding_length) += 1;
    }
  }
  return rc;
}

int mal_interactiontype_list_encode_malbinary(mal_interactiontype_list_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  bool *presence_flags = self->presence_flags;
  mal_interactiontype_t *content = self->content;
  for (int i = 0; i < list_size; i++) {
    bool presence_flag = presence_flags[i];
    rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
        presence_flag);
    if (rc < 0)
      return rc;
    mal_interactiontype_t enumerated = content[i];
    if (presence_flag) {
      rc = malbinary_encoder_encode_small_enum(encoder, bytes, offset,
          enumerated);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_interactiontype_list_decode_malbinary(mal_interactiontype_list_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  bool *presence_flags = (bool *) malloc(sizeof(bool) * list_size);
  mal_interactiontype_t *list_content = (mal_interactiontype_t *) malloc(
      sizeof(mal_interactiontype_t) * list_size);
  for (int i = 0; i < list_size; i++) {
    int list_element;
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
        &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malbinary_decoder_decode_small_enum(decoder, bytes, offset,
          &list_element);
      if (rc < 0)
        return rc;
      presence_flags[i] = true;
      list_content[i] = (mal_interactiontype_t) list_element;
    } else {
      presence_flags[i] = false;
    }
  }
  self->presence_flags = presence_flags;
  self->content = list_content;
  return rc;
}

void mal_interactiontype_list_test(bool verbose) {
  printf(" * mal_interactiontype_list: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

