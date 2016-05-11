/*
 */

#include "testarea.h"

testarea_testservice_testfinalcompositea_t *testarea_testservice_testfinalcompositea_new(
    void) {
  testarea_testservice_testfinalcompositea_t *self =
      (testarea_testservice_testfinalcompositea_t *) malloc(
          sizeof(testarea_testservice_testfinalcompositea_t));
  if (!self)
    return NULL;
  return self;
}

void testarea_testservice_testfinalcompositea_destroy(
    testarea_testservice_testfinalcompositea_t **self_p) {
  if (*self_p) {
    testarea_testservice_testfinalcompositea_t *self = *self_p;
    free(self);
    *self_p = NULL;
  }
}

int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_encoder_t *encoder, void *cursor) {
  int rc = 0;
  if (self == NULL) {
    rc = -1;
    return rc;
  }

  rc = malbinary_encoder_add_integer_encoding_length(encoder, self->intfield, cursor);
  if (rc < 0)
    return rc;

  rc = malbinary_encoder_add_integer_encoding_length(encoder, self->intfield2, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

int testarea_testservice_testfinalcompositea_encode_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_encoder_t *encoder, void *cursor) {
  int rc = 0;
  rc = malbinary_encoder_encode_integer(encoder, cursor, self->intfield);
  if (rc < 0)
    return rc;
  rc = malbinary_encoder_encode_integer(encoder, cursor,
      self->intfield2);
  if (rc < 0)
    return rc;
  return rc;
}

int testarea_testservice_testfinalcompositea_decode_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_decoder_t *decoder, void *cursor) {
  int rc = 0;
  rc = malbinary_decoder_decode_integer(decoder, cursor,
      &(self->intfield));
  if (rc < 0)
    return rc;
  rc = malbinary_decoder_decode_integer(decoder, cursor,
      &(self->intfield2));
  if (rc < 0)
    return rc;
  return rc;
}

mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(
    testarea_testservice_testfinalcompositea_t *self) {
  return self->intfield;
}

void testarea_testservice_testfinalcompositea_set_intfield(
    testarea_testservice_testfinalcompositea_t *self, mal_integer_t intfield) {
  self->intfield = intfield;
}

mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(
    testarea_testservice_testfinalcompositea_t *self) {
  return self->intfield2;
}

void testarea_testservice_testfinalcompositea_set_intfield2(
    testarea_testservice_testfinalcompositea_t *self, mal_integer_t intfield2) {
  self->intfield2 = intfield2;
}

void testarea_testservice_testfinalcompositea_test(bool verbose) {
  printf(" * testarea_testservice_testfinalcompositea: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

