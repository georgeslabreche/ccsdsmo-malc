#include "com.h"

struct _com_archive_expressionoperator_list_t {
  unsigned int element_count;
  bool * presence_flags;
  com_archive_expressionoperator_t * content;
};

// default constructor
com_archive_expressionoperator_list_t * com_archive_expressionoperator_list_new(unsigned int element_count)
{
  com_archive_expressionoperator_list_t *self = (com_archive_expressionoperator_list_t *) calloc(1, sizeof(com_archive_expressionoperator_list_t));
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
  self->content = (com_archive_expressionoperator_t *) calloc(element_count, sizeof(com_archive_expressionoperator_t));
  if (!self->content)
  {
    free(self->presence_flags);
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list and its content
void com_archive_expressionoperator_list_destroy(com_archive_expressionoperator_list_t ** self_p)
{
  if ((*self_p)->element_count > 0)
  {
    free((*self_p)->presence_flags);
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for enumeration list com_archive_expressionoperator_list
unsigned int com_archive_expressionoperator_list_get_element_count(com_archive_expressionoperator_list_t * self)
{
  return self->element_count;
}
bool * com_archive_expressionoperator_list_get_presence_flags(com_archive_expressionoperator_list_t * self)
{
  return self->presence_flags;
}
com_archive_expressionoperator_t * com_archive_expressionoperator_list_get_content(com_archive_expressionoperator_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int com_archive_expressionoperator_list_add_encoding_length_malbinary(com_archive_expressionoperator_list_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  if (rc < 0)
    return rc;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag = self->presence_flags[i];
    rc = mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_encoder_add_small_enum_encoding_length(encoder, self->content[i], cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int com_archive_expressionoperator_list_encode_malbinary(com_archive_expressionoperator_list_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag = self->presence_flags[i];
    rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = mal_encoder_encode_small_enum(encoder, cursor, self->content[i]);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int com_archive_expressionoperator_list_decode_malbinary(com_archive_expressionoperator_list_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size;
  rc = mal_decoder_decode_list_size(decoder, cursor, &list_size);
  if (rc < 0)
    return rc;
  if (list_size == 0)
  {
    self->element_count = 0;
    self->presence_flags = NULL;
    self->content = NULL;
    return 0;
  }
  self->presence_flags = (bool *) calloc(list_size, sizeof(bool));
  if (self->presence_flags == NULL)
    return -1;
  self->content = (com_archive_expressionoperator_t *) calloc(list_size, sizeof(com_archive_expressionoperator_t));
  if (self->content == NULL)
  {
    free(self->presence_flags);
    self->presence_flags = NULL;
    return -1;
  }
  self->element_count = list_size;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag;
    int enumerated_value;
    rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    self->presence_flags[i] = presence_flag;
    if (presence_flag)
    {
      rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
      if (rc < 0)
        return rc;
      self->content[i] = (com_archive_expressionoperator_t) enumerated_value;
    }
  }
  return rc;
}

// test function
void com_archive_expressionoperator_list_test(bool verbose)
{
  printf(" * list of com_archive_expressionoperator: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
