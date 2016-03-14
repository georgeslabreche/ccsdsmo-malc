#include "testarea.h"


// structure definition for composite testarea_testservice_testcomposite
struct _testarea_testservice_testcomposite_t {
  mal_string_t * stringfield;
  bool intfield_is_present;
  mal_integer_t intfield;
};

// fields accessors for composite testarea_testservice_testcomposite
mal_string_t * testarea_testservice_testcomposite_get_stringfield(testarea_testservice_testcomposite_t * self)
{
  return self->stringfield;
}
void testarea_testservice_testcomposite_set_stringfield(testarea_testservice_testcomposite_t * self, mal_string_t * stringfield)
{
  self->stringfield = stringfield;
}
bool testarea_testservice_testcomposite_intfield_is_present(testarea_testservice_testcomposite_t * self)
{
  return self->intfield_is_present;
}
void testarea_testservice_testcomposite_intfield_set_present(testarea_testservice_testcomposite_t * self, bool is_present)
{
  self->intfield_is_present = is_present;
}
mal_integer_t testarea_testservice_testcomposite_get_intfield(testarea_testservice_testcomposite_t * self)
{
  return self->intfield;
}
void testarea_testservice_testcomposite_set_intfield(testarea_testservice_testcomposite_t * self, mal_integer_t intfield)
{
  self->intfield = intfield;
}

// default constructor
testarea_testservice_testcomposite_t * testarea_testservice_testcomposite_new(void)
{
  testarea_testservice_testcomposite_t *self = (testarea_testservice_testcomposite_t *) calloc(1, sizeof(testarea_testservice_testcomposite_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testcomposite_add_encoding_length_malbinary(testarea_testservice_testcomposite_t * self, malbinary_encoder_t * malbinary_encoder, unsigned int * encoding_length)
{
  int rc = 0;
  (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->stringfield != NULL)
  {
    rc = malbinary_encoder_add_string_encoding_length(malbinary_encoder, self->stringfield, encoding_length);
    if (rc < 0)
      return rc;
  }
  (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
  if (self->intfield_is_present)
  {
    rc = malbinary_encoder_add_integer_encoding_length(malbinary_encoder, self->intfield, encoding_length);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testcomposite_encode_malbinary(testarea_testservice_testcomposite_t * self, malbinary_encoder_t * malbinary_encoder, char * bytes, unsigned int * offset)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->stringfield != NULL);
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_string(malbinary_encoder, bytes, offset, self->stringfield);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->intfield_is_present;
  rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_encoder_encode_integer(malbinary_encoder, bytes, offset, self->intfield);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testcomposite_decode_malbinary(testarea_testservice_testcomposite_t * self, malbinary_decoder_t * malbinary_decoder, char * bytes, unsigned int * offset)
{
  int rc = 0;
  bool presence_flag;
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_string(malbinary_decoder, bytes, offset, &self->stringfield);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->stringfield = NULL;
  }
  rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = malbinary_decoder_decode_integer(malbinary_decoder, bytes, offset, &self->intfield);
    if (rc < 0)
      return rc;
  }
  self->intfield_is_present = presence_flag;
  return rc;
}

// destructor
void testarea_testservice_testcomposite_destroy(testarea_testservice_testcomposite_t ** self_p)
{
  if ((*self_p)->stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->stringfield);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testcomposite_test(bool verbose)
{
  printf(" * TestArea:TestService:TestComposite: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
