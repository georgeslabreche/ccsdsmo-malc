/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->intfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->intfield2, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_encode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_integer(encoder, cursor, self->intfield);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_integer(encoder, cursor, self->intfield2);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfinalcompositea_decode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->intfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->intfield2);
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
