#include "pf.h"

struct _pf_powercontrol_device_list_t {
  unsigned int element_count;
  pf_powercontrol_device_t ** content;
};

// default constructor
pf_powercontrol_device_list_t * pf_powercontrol_device_list_new(unsigned int element_count)
{
  pf_powercontrol_device_list_t *self = (pf_powercontrol_device_list_t *) calloc(1, sizeof(pf_powercontrol_device_list_t));
  if (!self)
    return NULL;
  self->element_count = element_count;
  self->content = (pf_powercontrol_device_t **) calloc(element_count, sizeof(pf_powercontrol_device_t *));
  if (!self->content && (element_count > 0))
  {
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list, its content and its elements
void pf_powercontrol_device_list_destroy(pf_powercontrol_device_list_t ** self_p)
{
  if (self_p && *self_p)
  {
    for (int i = 0; i < (*self_p)->element_count; i++)
    {
      if ((*self_p)->content[i] != NULL)
        pf_powercontrol_device_destroy(&(*self_p)->content[i]);
    }
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for composite list pf_powercontrol_device_list
unsigned int pf_powercontrol_device_list_get_element_count(pf_powercontrol_device_list_t * self)
{
  return self->element_count;
}
pf_powercontrol_device_t ** pf_powercontrol_device_list_get_content(pf_powercontrol_device_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int pf_powercontrol_device_list_add_encoding_length_malbinary(pf_powercontrol_device_list_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  if (rc < 0)
    return rc;
  for (int i = 0; i < list_size; i++)
  {
    pf_powercontrol_device_t * list_element = self->content[i];
    bool presence_flag = (list_element != NULL);
    rc = mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = pf_powercontrol_device_add_encoding_length_malbinary(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int pf_powercontrol_device_list_encode_malbinary(pf_powercontrol_device_list_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  pf_powercontrol_device_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    pf_powercontrol_device_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = pf_powercontrol_device_encode_malbinary(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int pf_powercontrol_device_list_decode_malbinary(pf_powercontrol_device_list_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  unsigned int list_size;
  rc = mal_decoder_decode_list_size(decoder, cursor, &list_size);
  if (rc < 0)
    return rc;
  if (list_size == 0)
  {
    self->element_count = 0;
    self->content = NULL;
    return 0;
  }
  self->content = (pf_powercontrol_device_t **) calloc(list_size, sizeof(pf_powercontrol_device_t *));
  if (self->content == NULL)
    return -1;
  self->element_count = list_size;
  for (int i = 0; i < list_size; i++)
  {
    bool presence_flag;
    rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      self->content[i] = pf_powercontrol_device_new();
      if (self->content[i] == NULL) return -1;
      rc = pf_powercontrol_device_decode_malbinary(self->content[i], decoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

// test function
void pf_powercontrol_device_list_test(bool verbose)
{
  printf(" * list of pf_powercontrol_device: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
