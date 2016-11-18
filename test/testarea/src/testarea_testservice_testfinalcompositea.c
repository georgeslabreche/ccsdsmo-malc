#include "testarea.h"


// structure definition for composite testarea_testservice_testfinalcompositea
struct _testarea_testservice_testfinalcompositea_t {
  mal_integer_t f_intfield;
  mal_integer_t f_intfield2;
};

// fields accessors for composite testarea_testservice_testfinalcompositea
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(testarea_testservice_testfinalcompositea_t * self)
{
  return self->f_intfield;
}
void testarea_testservice_testfinalcompositea_set_intfield(testarea_testservice_testfinalcompositea_t * self, mal_integer_t f_intfield)
{
  self->f_intfield = f_intfield;
}
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(testarea_testservice_testfinalcompositea_t * self)
{
  return self->f_intfield2;
}
void testarea_testservice_testfinalcompositea_set_intfield2(testarea_testservice_testfinalcompositea_t * self, mal_integer_t f_intfield2)
{
  self->f_intfield2 = f_intfield2;
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
int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->f_intfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->f_intfield2, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_encode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_integer(encoder, cursor, self->f_intfield);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_integer(encoder, cursor, self->f_intfield2);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_decode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->f_intfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->f_intfield2);
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
