/*
 */

#include "mal.h"

struct _mal_blob_list_t {
  unsigned int element_count;
  mal_blob_t **content;
};

mal_blob_list_t *mal_blob_list_new(unsigned int element_count) {
  mal_blob_list_t *self = (mal_blob_list_t *) calloc(1, sizeof(mal_blob_list_t));
  if (!self)
    return NULL;

  self->element_count = element_count;
  self->content = (mal_blob_t **) calloc(element_count, sizeof(mal_blob_t *));
  if (!self->content && (element_count > 0))
  {
    free(self);
    return NULL;
  }
  return self;
}

void mal_blob_list_destroy(mal_blob_list_t **self_p) {
  if (*self_p) {
    if ((*self_p)->element_count > 0)
    {
      for (int i = 0; i < (*self_p)->element_count; i++)
      {
        if ((*self_p)->content[i] != NULL)
          mal_blob_destroy(&(*self_p)->content[i]);
      }
      free((*self_p)->content);
    }
    free (*self_p);
    (*self_p) = NULL;
  }
}

unsigned int mal_blob_list_get_element_count(mal_blob_list_t *self) {
  return self->element_count;
}

mal_blob_t **mal_blob_list_get_content(mal_blob_list_t *self) {
  return self->content;
}

int mal_blob_list_add_encoding_length_malbinary(mal_blob_list_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  mal_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  for (int i = 0; i < list_size; i++)
  {
    mal_blob_t *list_element = self->content[i];
    bool presence_flag = (list_element != NULL);
    mal_encoder_add_presence_flag_encoding_length(encoder, cursor, presence_flag);
    if (presence_flag)
    {
      rc = mal_encoder_add_blob_encoding_length(encoder, list_element, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_blob_list_encode_malbinary(mal_blob_list_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  mal_blob_t **content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    mal_blob_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_encoder_encode_blob(encoder, cursor, list_element);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int mal_blob_list_decode_malbinary(mal_blob_list_t *self,
    mal_decoder_t *decoder, void *cursor) {
  int rc = mal_decoder_decode_list_size(decoder, cursor, &self->element_count);
  if (rc < 0)
    return rc;
  if (self->element_count == 0)
  {
    self->content = NULL;
    return 0;
  }
  self->content = (mal_blob_t **) calloc(self->element_count, sizeof(mal_blob_t *));
  if (self->content == NULL)
    return -1;
  for (int i = 0; i < self->element_count; i++)
  {
    bool presence_flag;
    rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_decoder_decode_blob(decoder, cursor, &self->content[i]);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

void mal_blob_list_test(bool verbose) {
  printf(" * mal_blob_list: ");
  if (verbose)
    printf("\n");

//  @selftest
// ...
//  @end
  printf("OK\n");
}

