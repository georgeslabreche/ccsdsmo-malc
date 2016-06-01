/*
 */

#include "mal.h"

struct _mal_uri_list_t {
  unsigned int element_count;
  mal_uri_t **content;
};

mal_uri_list_t *mal_uri_list_new(unsigned int element_count) {
  mal_uri_list_t *self = (mal_uri_list_t *) malloc(
      sizeof(mal_uri_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->content = (mal_uri_t **) malloc(
      sizeof(mal_uri_t *) * element_count);

  return self;
}

void mal_uri_list_destroy(mal_uri_list_t **self_p) {
  if (*self_p) {
    mal_uri_list_t *self = *self_p;
    unsigned int list_size = self->element_count;
    mal_uri_t **content = self->content;
    for (int i = 0; i < list_size; i++) {
      mal_uri_destroy(&content[i]);
    }
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_uri_list_get_element_count(mal_uri_list_t *self) {
  return self->element_count;
}

mal_uri_t **mal_uri_list_get_content(mal_uri_list_t *self) {
  return self->content;
}

void mal_uri_list_add_element(mal_uri_list_t *self, int index, mal_uri_t *element) {
  self->content[index] = element;
}

int mal_uri_list_add_encoding_length_malbinary(mal_uri_list_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  // Presence flags
  malbinary_add_length((malbinary_cursor_t *) cursor, list_size);
  mal_uri_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    mal_uri_t *list_element = content[i];
    if (list_element != NULL) {
      rc = malbinary_encoder_add_uri_encoding_length(encoder, list_element, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_uri_list_encode_malbinary(mal_uri_list_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, cursor, list_size);
  mal_uri_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    mal_uri_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
        presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malbinary_encoder_encode_uri(encoder, cursor,
          list_element);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_uri_list_decode_malbinary(mal_uri_list_t *self,
    mal_decoder_t *decoder, void *cursor) {
  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, cursor, &list_size);
  mal_uri_t **list_content = (mal_uri_t **) malloc(
      sizeof(mal_uri_t *) * list_size);
  for (int i = 0; i < list_size; i++) {
    mal_uri_t *list_element;
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
        &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malbinary_decoder_decode_uri(decoder, cursor,
          &list_element);
      if (rc < 0)
        return rc;
    } else {
      list_element = NULL;
    }
    list_content[i] = list_element;
  }
  self->element_count = list_size;
  self->content = list_content;
  return rc;
}

// TODO: Needs better integration with logging subsystem.
void mal_uri_list_print(mal_uri_list_t *self) {
  printf("mal_uri_list(");
  printf("element_count=%d", self->element_count);
  printf(",content=");
  for (int i = 0; i < self->element_count; i++) {
    printf("%s,", self->content[i]);
  }
  printf(")");
}

void mal_uri_list_test(bool verbose) {
  printf(" * mal_uri_list: ");
  if (verbose)
    printf("\n");

//  @selftest
// ...
//  @end
  printf("OK\n");
}

