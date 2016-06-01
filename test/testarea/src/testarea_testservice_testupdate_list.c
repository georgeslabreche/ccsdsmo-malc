#include "testarea.h"

struct _testarea_testservice_testupdate_list_t {
  unsigned int element_count;
  testarea_testservice_testupdate_t ** content;
};

// default constructor
testarea_testservice_testupdate_list_t * testarea_testservice_testupdate_list_new(unsigned int element_count)
{
  testarea_testservice_testupdate_list_t *self = (testarea_testservice_testupdate_list_t *) calloc(1, sizeof(testarea_testservice_testupdate_list_t));
  if (!self)
    return NULL;
  self->element_count = element_count;
  self->content = (testarea_testservice_testupdate_t **) calloc(element_count, sizeof(testarea_testservice_testupdate_t *));
  if (!self->content && (element_count > 0))
  {
    free(self);
    return NULL;
  }
  return self;
}

// destructor, free the list, its content and its elements
void testarea_testservice_testupdate_list_destroy(testarea_testservice_testupdate_list_t ** self_p)
{
  if ((*self_p)->element_count > 0)
  {
    for (int i = 0; i < (*self_p)->element_count; i++)
    {
      if ((*self_p)->content[i] != NULL)
        testarea_testservice_testupdate_destroy(&(*self_p)->content[i]);
    }
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}

// fields accessors for composite list testarea_testservice_testupdate_list
unsigned int testarea_testservice_testupdate_list_get_element_count(testarea_testservice_testupdate_list_t * self)
{
  return self->element_count;
}
testarea_testservice_testupdate_t ** testarea_testservice_testupdate_list_get_content(testarea_testservice_testupdate_list_t * self)
{
  return self->content;
}

// encoding functions related to transport malbinary
int testarea_testservice_testupdate_list_add_encoding_length_malbinary(testarea_testservice_testupdate_list_t * self, mal_encoder_t *encoder, void *cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  ((malbinary_cursor_t *) cursor)->body_length += list_size;
  testarea_testservice_testupdate_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    testarea_testservice_testupdate_t * list_element = content[i];
    if (list_element != NULL)
    {
      rc = testarea_testservice_testupdate_add_encoding_length_malbinary(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int testarea_testservice_testupdate_list_encode_malbinary(testarea_testservice_testupdate_list_t * self, mal_encoder_t *encoder, void *cursor)
{
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = malbinary_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0)
    return rc;
  testarea_testservice_testupdate_t ** content = self->content;
  for (int i = 0; i < list_size; i++)
  {
    testarea_testservice_testupdate_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      rc = testarea_testservice_testupdate_encode_malbinary(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}
int testarea_testservice_testupdate_list_decode_malbinary(testarea_testservice_testupdate_list_t * self, mal_decoder_t *decoder, void *cursor)
{
  int rc = malbinary_decoder_decode_list_size(decoder, cursor, &self->element_count);
  if (rc < 0)
    return rc;
  if (self->element_count == 0)
  {
    self->content = NULL;
    return 0;
  }
  self->content = (testarea_testservice_testupdate_t **) calloc(self->element_count, sizeof(testarea_testservice_testupdate_t *));
  if (self->content == NULL)
    return -1;
  for (int i = 0; i < self->element_count; i++)
  {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag)
    {
      self->content[i] = testarea_testservice_testupdate_new();
      if (self->content[i] == NULL) return -1;
      rc = testarea_testservice_testupdate_decode_malbinary(self->content[i], decoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

// test function
void testarea_testservice_testupdate_list_test(bool verbose)
{
  printf(" * list of testarea_testservice_testupdate: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
