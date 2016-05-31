#include "mal.h"

struct _mal_file_list_t {
  unsigned int element_count;
  mal_file_t ** content;
};

// default constructor
mal_file_list_t * mal_file_list_new(unsigned int element_count)
{
  mal_file_list_t *self = (mal_file_list_t *) calloc(1, sizeof(mal_file_list_t));
  if (!self)
    return NULL;
  self->element_count = element_count;
  self->content = (mal_file_t **) calloc(element_count, sizeof(mal_file_t *));
  if (!self->content && (element_count > 0))
  {
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list, its content and its elements
void mal_file_list_destroy(mal_file_list_t ** self_p)
{
  if ((*self_p)->element_count > 0)
  {
    for (int i = 0; i < (*self_p)->element_count; i++)
    {
      if ((*self_p)->content[i] != NULL)
        mal_file_destroy(&(*self_p)->content[i]);
    }
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for composite list mal_file_list
unsigned int mal_file_list_get_element_count(mal_file_list_t * self)
{
  return self->element_count;
}
mal_file_t ** mal_file_list_get_content(mal_file_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int mal_file_list_add_encoding_length_malbinary(mal_file_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(malbinary_encoder, list_size, cursor);
  malbinary_add_length((malbinary_cursor_t *) cursor, list_size);
  mal_file_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    mal_file_t * list_element = content[i];
    if (list_element != NULL)
    {
      rc = mal_file_add_encoding_length_malbinary(list_element, malbinary_encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_file_list_encode_malbinary(mal_file_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = malbinary_encoder_encode_list_size(malbinary_encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  mal_file_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    mal_file_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_file_encode_malbinary(list_element, malbinary_encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_file_list_decode_malbinary(mal_file_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor)
{
  int rc = malbinary_decoder_decode_list_size(malbinary_decoder, cursor, &self->element_count);
  if (rc < 0)
    return rc;
  if (self->element_count == 0)
  {
    self->content = NULL;
    return 0;
  }
  self->content = (mal_file_t **) calloc(self->element_count, sizeof(mal_file_t *));
  if (self->content == NULL)
    return -1;
  for (int i = 0; i < self->element_count; i++)
  {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      self->content[i] = mal_file_new();
      if (self->content[i] == NULL) return -1;
      rc = mal_file_decode_malbinary(self->content[i], malbinary_decoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

// test function
void mal_file_list_test(bool verbose)
{
  printf(" * list of mal_file: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
