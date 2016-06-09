#include "mal.h"

struct _mal_updatetype_list_t {
  unsigned int element_count;
  bool * presence_flags;
  mal_updatetype_t * content;
};

// default constructor
mal_updatetype_list_t * mal_updatetype_list_new(unsigned int element_count)
{
  mal_updatetype_list_t *self = (mal_updatetype_list_t *) calloc(1, sizeof(mal_updatetype_list_t));
  if (!self)
    return NULL;
  self->element_count = element_count;
  if (element_count == 0)
    return self;
  self->presence_flags = (bool *) calloc(element_count, sizeof(bool));
  if (!self->presence_flags)
  {
    free(self);
    return NULL;
  }
  self->content = (mal_updatetype_t *) calloc(element_count, sizeof(mal_updatetype_t));
  if (!self->content)
  {
    free(self->presence_flags);
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list and its content
void mal_updatetype_list_destroy(mal_updatetype_list_t ** self_p)
{
  if ((*self_p)->element_count > 0)
  {
    free((*self_p)->presence_flags);
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for enumeration list mal_updatetype_list
unsigned int mal_updatetype_list_get_element_count(mal_updatetype_list_t * self)
{
  return self->element_count;
}
bool * mal_updatetype_list_get_presence_flags(mal_updatetype_list_t * self)
{
  return self->presence_flags;
}
mal_updatetype_t * mal_updatetype_list_get_content(mal_updatetype_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int mal_updatetype_list_add_encoding_length_malbinary(mal_updatetype_list_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  mal_encoder_add_list_size_encoding_length(mal_encoder, list_size, cursor);
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag = self->presence_flags[i];
    mal_encoder_add_presence_flag_encoding_length(mal_encoder, cursor, presence_flag);
    if (presence_flag)
    {
      rc = mal_encoder_add_small_enum_encoding_length(mal_encoder, self->content[i], cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_updatetype_list_encode_malbinary(mal_updatetype_list_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(mal_encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag = self->presence_flags[i];
    rc = mal_encoder_encode_presence_flag(mal_encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_encoder_encode_small_enum(mal_encoder, cursor, self->content[i]);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int mal_updatetype_list_decode_malbinary(mal_updatetype_list_t * self, mal_decoder_t * mal_decoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size;
  rc = mal_decoder_decode_list_size(mal_decoder, cursor, &list_size);
  if (rc < 0)
    return rc;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag;
    int enumerated_value;
    rc = mal_decoder_decode_presence_flag(mal_decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    self->presence_flags[i] = presence_flag;
    if (presence_flag)
    {
      rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
      if (rc < 0)
        return rc;
      self->content[i] = (mal_updatetype_t) enumerated_value;
    }
  }
  return rc;
}

// test function
void mal_updatetype_list_test(bool verbose)
{
  printf(" * list of mal_updatetype: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
