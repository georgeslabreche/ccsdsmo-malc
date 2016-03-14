/*
 */

#include "mal.h"

struct _mal_identifier_list_t {
  unsigned int element_count;
  mal_identifier_t **content;
};

mal_identifier_list_t *mal_identifier_list_new(unsigned int element_count) {
  mal_identifier_list_t *self = (mal_identifier_list_t *) malloc(
      sizeof(mal_identifier_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->content = (mal_identifier_t **) malloc(
      sizeof(mal_identifier_t *) * element_count);

  return self;
}

void mal_identifier_list_destroy(mal_identifier_list_t **self_p) {
  if (*self_p) {
    mal_identifier_list_t *self = *self_p;
    free(self->content);
    free(self);
    *self_p = NULL;
  }
}

unsigned int mal_identifier_list_get_element_count(mal_identifier_list_t *self) {
  return self->element_count;
}

mal_identifier_t **mal_identifier_list_get_content(mal_identifier_list_t *self) {
  return self->content;
}

int mal_identifier_list_add_encoding_length_malbinary(
    mal_identifier_list_t *self, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
  // Presence flags
  (*encoding_length) += list_size;
  mal_identifier_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    if (list_element != NULL) {
      rc = malbinary_encoder_add_identifier_encoding_length(encoder,
          list_element, encoding_length);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_identifier_list_encode_malbinary(mal_identifier_list_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  mal_identifier_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
        presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malbinary_encoder_encode_identifier(encoder, bytes, offset,
          list_element);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_identifier_list_decode_malbinary(mal_identifier_list_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  clog_debug(malbinary_decoder_get_logger(decoder), "mal_identifier_list_decode_malbinary()\n");

  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  mal_identifier_t **list_content = (mal_identifier_t **) malloc(
      sizeof(mal_identifier_t *) * list_size);

  clog_debug(malbinary_decoder_get_logger(decoder), "mal_identifier_list: %d\n", list_size);

  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element;
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
        &presence_flag);

    clog_debug(malbinary_decoder_get_logger(decoder), "mal_identifier_list: presence_flag=%d\n", presence_flag);

    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malbinary_decoder_decode_identifier(decoder, bytes, offset,
          &list_element);

      clog_debug(malbinary_decoder_get_logger(decoder), "mal_identifier_list: list_element=%s\n", list_element);

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
void mal_identifier_list_print(mal_identifier_list_t *self) {
  printf("mal_identifier_list(element_count=%d, content=", self->element_count);
  for (int i = 0; i < self->element_count; i++) {
    printf("%s,", self->content[i]);
  }
  printf(")");
}

void mal_identifier_list_test(bool verbose) {
  printf(" * mal_identifier_list: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

