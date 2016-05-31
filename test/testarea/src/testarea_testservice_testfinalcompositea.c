#include "testarea.h"


// structure definition for composite testarea_testservice_testfinalcompositea
struct _testarea_testservice_testfinalcompositea_t {
  mal_integer_t intfield;
  mal_integer_t intfield2;
};

// fields accessors for composite testarea_testservice_testfinalcompositea
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(testarea_testservice_testfinalcompositea_t * self)
{
  return self->intfield;
}
void testarea_testservice_testfinalcompositea_set_intfield(testarea_testservice_testfinalcompositea_t * self, mal_integer_t intfield)
{
  self->intfield = intfield;
}
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(testarea_testservice_testfinalcompositea_t * self)
{
  return self->intfield2;
}
void testarea_testservice_testfinalcompositea_set_intfield2(testarea_testservice_testfinalcompositea_t * self, mal_integer_t intfield2)
{
  self->intfield2 = intfield2;
}

// default constructor
testarea_testservice_testfinalcompositea_t * testarea_testservice_testfinalcompositea_new(void)
{
  testarea_testservice_testfinalcompositea_t *self = (testarea_testservice_testfinalcompositea_t *) calloc(1, sizeof(testarea_testservice_testfinalcompositea_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(testarea_testservice_testfinalcompositea_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  rc = malbinary_encoder_add_integer_encoding_length(malbinary_encoder, self->intfield, cursor);
  if (rc < 0)
    return rc;
  rc = malbinary_encoder_add_integer_encoding_length(malbinary_encoder, self->intfield2, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_encode_malbinary(testarea_testservice_testfinalcompositea_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor)
{
  int rc = 0;
  rc = malbinary_encoder_encode_integer(malbinary_encoder, cursor, self->intfield);
  if (rc < 0)
    return rc;
  rc = malbinary_encoder_encode_integer(malbinary_encoder, cursor, self->intfield2);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_decode_malbinary(testarea_testservice_testfinalcompositea_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor)
{
  int rc = 0;
  rc = malbinary_decoder_decode_integer(malbinary_decoder, cursor, &self->intfield);
  if (rc < 0)
    return rc;
  rc = malbinary_decoder_decode_integer(malbinary_decoder, cursor, &self->intfield2);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void testarea_testservice_testfinalcompositea_destroy(testarea_testservice_testfinalcompositea_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testfinalcompositea_test(bool verbose)
{
  printf(" * TestArea:TestService:TestFinalCompositeA: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
