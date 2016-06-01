#include "testarea.h"


// structure definition for composite testarea_testservice_testupdate
struct _testarea_testservice_testupdate_t {
  mal_string_t * stringfield;
};

// fields accessors for composite testarea_testservice_testupdate
mal_string_t * testarea_testservice_testupdate_get_stringfield(testarea_testservice_testupdate_t * self)
{
  return self->stringfield;
}
void testarea_testservice_testupdate_set_stringfield(testarea_testservice_testupdate_t * self, mal_string_t * stringfield)
{
  self->stringfield = stringfield;
}

// default constructor
testarea_testservice_testupdate_t * testarea_testservice_testupdate_new(void)
{
  testarea_testservice_testupdate_t *self = (testarea_testservice_testupdate_t *) calloc(1, sizeof(testarea_testservice_testupdate_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testupdate_add_encoding_length_malbinary(testarea_testservice_testupdate_t * self, mal_encoder_t *encoder, void *cursor)
{
  int rc = 0;
  ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->stringfield != NULL)
  {
    rc = malbinary_encoder_add_string_encoding_length(encoder, self->stringfield, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testupdate_encode_malbinary(testarea_testservice_testupdate_t * self, mal_encoder_t *encoder, void *cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->stringfield != NULL);
  rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_string(encoder, cursor, self->stringfield);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testupdate_decode_malbinary(testarea_testservice_testupdate_t * self, mal_decoder_t *decoder, void *cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_string(decoder, cursor, &self->stringfield);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->stringfield = NULL;
  }
  return rc;
}

// destructor
void testarea_testservice_testupdate_destroy(testarea_testservice_testupdate_t ** self_p)
{
  if ((*self_p)->stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->stringfield);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testupdate_test(bool verbose)
{
  printf(" * TestArea:TestService:TestUpdate: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
