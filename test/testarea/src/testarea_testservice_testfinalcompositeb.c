#include "testarea.h"


// structure definition for composite testarea_testservice_testfinalcompositeb
struct _testarea_testservice_testfinalcompositeb_t {
  mal_integer_t intfield;
  mal_string_t * stringfield;
};

// fields accessors for composite testarea_testservice_testfinalcompositeb
mal_integer_t testarea_testservice_testfinalcompositeb_get_intfield(testarea_testservice_testfinalcompositeb_t * self)
{
  return self->intfield;
}
void testarea_testservice_testfinalcompositeb_set_intfield(testarea_testservice_testfinalcompositeb_t * self, mal_integer_t intfield)
{
  self->intfield = intfield;
}
mal_string_t * testarea_testservice_testfinalcompositeb_get_stringfield(testarea_testservice_testfinalcompositeb_t * self)
{
  return self->stringfield;
}
void testarea_testservice_testfinalcompositeb_set_stringfield(testarea_testservice_testfinalcompositeb_t * self, mal_string_t * stringfield)
{
  self->stringfield = stringfield;
}

// default constructor
testarea_testservice_testfinalcompositeb_t * testarea_testservice_testfinalcompositeb_new(void)
{
  testarea_testservice_testfinalcompositeb_t *self = (testarea_testservice_testfinalcompositeb_t *) calloc(1, sizeof(testarea_testservice_testfinalcompositeb_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testfinalcompositeb_add_encoding_length_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->intfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->stringfield, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositeb_encode_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_integer(encoder, cursor, self->intfield);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->stringfield);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositeb_decode_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->intfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->stringfield);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void testarea_testservice_testfinalcompositeb_destroy(testarea_testservice_testfinalcompositeb_t ** self_p)
{
  if ((*self_p)->stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->stringfield);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testfinalcompositeb_test(bool verbose)
{
  printf(" * TestArea:TestService:TestFinalCompositeB: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
