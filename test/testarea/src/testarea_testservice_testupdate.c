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


// structure definition for composite testarea_testservice_testupdate
struct _testarea_testservice_testupdate_t {
  mal_string_t * f_stringfield;
};

// fields accessors for composite testarea_testservice_testupdate
mal_string_t * testarea_testservice_testupdate_get_stringfield(testarea_testservice_testupdate_t * self)
{
  return self->f_stringfield;
}
void testarea_testservice_testupdate_set_stringfield(testarea_testservice_testupdate_t * self, mal_string_t * f_stringfield)
{
  self->f_stringfield = f_stringfield;
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
int testarea_testservice_testupdate_add_encoding_length_malbinary(testarea_testservice_testupdate_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_stringfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_stringfield != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_stringfield, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testupdate_encode_malbinary(testarea_testservice_testupdate_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_stringfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_stringfield);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int testarea_testservice_testupdate_decode_malbinary(testarea_testservice_testupdate_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_stringfield);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_stringfield = NULL;
  }
  return rc;
}

// destructor
void testarea_testservice_testupdate_destroy(testarea_testservice_testupdate_t ** self_p)
{
  if ((*self_p)->f_stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->f_stringfield);
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
