#include "mal.h"

struct _mal_idbooleanpair_list_t {
  unsigned int element_count;
  mal_idbooleanpair_t ** content;
};

// default constructor
mal_idbooleanpair_list_t * mal_idbooleanpair_list_new(unsigned int element_count)
{
  mal_idbooleanpair_list_t *self = (mal_idbooleanpair_list_t *) calloc(1, sizeof(mal_idbooleanpair_list_t));
  if (!self)
    return NULL;
  self->element_count = element_count;
  self->content = (mal_idbooleanpair_t **) calloc(element_count, sizeof(mal_idbooleanpair_t *));
  if (!self->content && (element_count > 0))
  {
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list, its content and its elements
void mal_idbooleanpair_list_destroy(mal_idbooleanpair_list_t ** self_p)
{
  if ((*self_p)->element_count > 0)
  {
    for (int i = 0; i < (*self_p)->element_count; i++)
    {
      if ((*self_p)->content[i] != NULL)
        mal_idbooleanpair_destroy(&(*self_p)->content[i]);
    }
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for composite list mal_idbooleanpair_list
unsigned int mal_idbooleanpair_list_get_element_count(mal_idbooleanpair_list_t * self)
{
  return self->element_count;
}
mal_idbooleanpair_t ** mal_idbooleanpair_list_get_content(mal_idbooleanpair_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int mal_idbooleanpair_list_add_encoding_length_malbinary(mal_idbooleanpair_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(malbinary_encoder, list_size, cursor);
  malbinary_add_length((malbinary_cursor_t *) cursor, list_size);
  mal_idbooleanpair_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    mal_idbooleanpair_t * list_element = content[i];
    if (list_element != NULL)
    {
      rc = mal_idbooleanpair_add_encoding_length_malbinary(list_element, malbinary_encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_idbooleanpair_list_encode_malbinary(mal_idbooleanpair_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = malbinary_encoder_encode_list_size(malbinary_encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  mal_idbooleanpair_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    mal_idbooleanpair_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_idbooleanpair_encode_malbinary(list_element, malbinary_encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_idbooleanpair_list_decode_malbinary(mal_idbooleanpair_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor)
{
  int rc = malbinary_decoder_decode_list_size(malbinary_decoder, cursor, &self->element_count);
  if (rc < 0)
    return rc;
  if (self->element_count == 0)
  {
    self->content = NULL;
    return 0;
  }
  self->content = (mal_idbooleanpair_t **) calloc(self->element_count, sizeof(mal_idbooleanpair_t *));
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
      self->content[i] = mal_idbooleanpair_new();
      if (self->content[i] == NULL) return -1;
      rc = mal_idbooleanpair_decode_malbinary(self->content[i], malbinary_decoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

// test function
void mal_idbooleanpair_list_test(bool verbose)
{
  printf(" * list of mal_idbooleanpair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
