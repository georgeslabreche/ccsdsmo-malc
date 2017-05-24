/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
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


// structure definition for composite testarea_testservice_testfullcomposite
struct _testarea_testservice_testfullcomposite_t {
  mal_boolean_t f_boolfield;
  bool f_intfield_is_present;
  mal_integer_t f_intfield;
  mal_string_t * f_stringfield;
  mal_blob_t * f_blobfield;
  testarea_testenumeration_t f_enumfield;
  testarea_testservice_testcomposite_t * f_compfield;
  mal_boolean_list_t * f_boollistfield;
  mal_integer_list_t * f_intlistfield;
  mal_string_list_t * f_stringlistfield;
  mal_blob_list_t * f_bloblistfield;
  testarea_testenumeration_list_t * f_enumlistfield;
  testarea_testservice_testcomposite_list_t * f_complistfield;
  unsigned char f_attributefield_attribute_tag;
  union mal_attribute_t f_attributefield;
};

// fields accessors for composite testarea_testservice_testfullcomposite
mal_boolean_t testarea_testservice_testfullcomposite_get_boolfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_boolfield;
}
void testarea_testservice_testfullcomposite_set_boolfield(testarea_testservice_testfullcomposite_t * self, mal_boolean_t f_boolfield)
{
  self->f_boolfield = f_boolfield;
}
bool testarea_testservice_testfullcomposite_intfield_is_present(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_intfield_is_present;
}
void testarea_testservice_testfullcomposite_intfield_set_present(testarea_testservice_testfullcomposite_t * self, bool is_present)
{
  self->f_intfield_is_present = is_present;
}
mal_integer_t testarea_testservice_testfullcomposite_get_intfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_intfield;
}
void testarea_testservice_testfullcomposite_set_intfield(testarea_testservice_testfullcomposite_t * self, mal_integer_t f_intfield)
{
  self->f_intfield = f_intfield;
}
mal_string_t * testarea_testservice_testfullcomposite_get_stringfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_stringfield;
}
void testarea_testservice_testfullcomposite_set_stringfield(testarea_testservice_testfullcomposite_t * self, mal_string_t * f_stringfield)
{
  self->f_stringfield = f_stringfield;
}
mal_blob_t * testarea_testservice_testfullcomposite_get_blobfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_blobfield;
}
void testarea_testservice_testfullcomposite_set_blobfield(testarea_testservice_testfullcomposite_t * self, mal_blob_t * f_blobfield)
{
  self->f_blobfield = f_blobfield;
}
testarea_testenumeration_t testarea_testservice_testfullcomposite_get_enumfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_enumfield;
}
void testarea_testservice_testfullcomposite_set_enumfield(testarea_testservice_testfullcomposite_t * self, testarea_testenumeration_t f_enumfield)
{
  self->f_enumfield = f_enumfield;
}
testarea_testservice_testcomposite_t * testarea_testservice_testfullcomposite_get_compfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_compfield;
}
void testarea_testservice_testfullcomposite_set_compfield(testarea_testservice_testfullcomposite_t * self, testarea_testservice_testcomposite_t * f_compfield)
{
  self->f_compfield = f_compfield;
}
mal_boolean_list_t * testarea_testservice_testfullcomposite_get_boollistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_boollistfield;
}
void testarea_testservice_testfullcomposite_set_boollistfield(testarea_testservice_testfullcomposite_t * self, mal_boolean_list_t * f_boollistfield)
{
  self->f_boollistfield = f_boollistfield;
}
mal_integer_list_t * testarea_testservice_testfullcomposite_get_intlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_intlistfield;
}
void testarea_testservice_testfullcomposite_set_intlistfield(testarea_testservice_testfullcomposite_t * self, mal_integer_list_t * f_intlistfield)
{
  self->f_intlistfield = f_intlistfield;
}
mal_string_list_t * testarea_testservice_testfullcomposite_get_stringlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_stringlistfield;
}
void testarea_testservice_testfullcomposite_set_stringlistfield(testarea_testservice_testfullcomposite_t * self, mal_string_list_t * f_stringlistfield)
{
  self->f_stringlistfield = f_stringlistfield;
}
mal_blob_list_t * testarea_testservice_testfullcomposite_get_bloblistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_bloblistfield;
}
void testarea_testservice_testfullcomposite_set_bloblistfield(testarea_testservice_testfullcomposite_t * self, mal_blob_list_t * f_bloblistfield)
{
  self->f_bloblistfield = f_bloblistfield;
}
testarea_testenumeration_list_t * testarea_testservice_testfullcomposite_get_enumlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_enumlistfield;
}
void testarea_testservice_testfullcomposite_set_enumlistfield(testarea_testservice_testfullcomposite_t * self, testarea_testenumeration_list_t * f_enumlistfield)
{
  self->f_enumlistfield = f_enumlistfield;
}
testarea_testservice_testcomposite_list_t * testarea_testservice_testfullcomposite_get_complistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_complistfield;
}
void testarea_testservice_testfullcomposite_set_complistfield(testarea_testservice_testfullcomposite_t * self, testarea_testservice_testcomposite_list_t * f_complistfield)
{
  self->f_complistfield = f_complistfield;
}
unsigned char testarea_testservice_testfullcomposite_attributefield_get_attribute_tag(testarea_testservice_testfullcomposite_t * self)
{
  return self->f_attributefield_attribute_tag;
}
void testarea_testservice_testfullcomposite_attributefield_set_attribute_tag(testarea_testservice_testfullcomposite_t * self, unsigned char attribute_tag)
{
  self->f_attributefield_attribute_tag = attribute_tag;
}

// default constructor
testarea_testservice_testfullcomposite_t * testarea_testservice_testfullcomposite_new(void)
{
  testarea_testservice_testfullcomposite_t *self = (testarea_testservice_testfullcomposite_t *) calloc(1, sizeof(testarea_testservice_testfullcomposite_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testfullcomposite_add_encoding_length_malbinary(testarea_testservice_testfullcomposite_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_boolfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_intfield_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_intfield_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_intfield, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_stringfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_stringfield != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_stringfield, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_blob_encoding_length(encoder, self->f_blobfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_enumfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_compfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_compfield != NULL))
  {
    rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(self->f_compfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_boollistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_boollistfield != NULL))
  {
    rc = mal_boolean_list_add_encoding_length_malbinary(self->f_boollistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_integer_list_add_encoding_length_malbinary(self->f_intlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_string_list_add_encoding_length_malbinary(self->f_stringlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_bloblistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_bloblistfield != NULL))
  {
    rc = mal_blob_list_add_encoding_length_malbinary(self->f_bloblistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_enumlistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_enumlistfield != NULL))
  {
    rc = testarea_testenumeration_list_add_encoding_length_malbinary(self->f_enumlistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = testarea_testservice_testcomposite_list_add_encoding_length_malbinary(self->f_complistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_attributefield_attribute_tag, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_attributefield_attribute_tag, self->f_attributefield, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfullcomposite_encode_malbinary(testarea_testservice_testfullcomposite_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_boolfield);
  if (rc < 0)
    return rc;
  presence_flag = self->f_intfield_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_intfield);
    if (rc < 0)
      return rc;
  }
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
  rc = mal_encoder_encode_blob(encoder, cursor, self->f_blobfield);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_enumfield);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_compfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = testarea_testservice_testcomposite_encode_malbinary(self->f_compfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_boollistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_boolean_list_encode_malbinary(self->f_boollistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_integer_list_encode_malbinary(self->f_intlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_string_list_encode_malbinary(self->f_stringlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_bloblistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_blob_list_encode_malbinary(self->f_bloblistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_enumlistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = testarea_testenumeration_list_encode_malbinary(self->f_enumlistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = testarea_testservice_testcomposite_list_encode_malbinary(self->f_complistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_attributefield_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute(encoder, cursor, self->f_attributefield_attribute_tag, self->f_attributefield);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfullcomposite_decode_malbinary(testarea_testservice_testfullcomposite_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_boolfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_intfield);
    if (rc < 0)
      return rc;
  }
  self->f_intfield_is_present = presence_flag;
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
  rc = mal_decoder_decode_blob(decoder, cursor, &self->f_blobfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_enumfield = (testarea_testenumeration_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_compfield = testarea_testservice_testcomposite_new();
    if (self->f_compfield == NULL) return -1;
    rc = testarea_testservice_testcomposite_decode_malbinary(self->f_compfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_compfield = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_boollistfield = mal_boolean_list_new(0);
    if (self->f_boollistfield == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary(self->f_boollistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_boollistfield = NULL;
  }
  self->f_intlistfield = mal_integer_list_new(0);
  if (self->f_intlistfield == NULL) return -1;
  rc = mal_integer_list_decode_malbinary(self->f_intlistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_stringlistfield = mal_string_list_new(0);
  if (self->f_stringlistfield == NULL) return -1;
  rc = mal_string_list_decode_malbinary(self->f_stringlistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_bloblistfield = mal_blob_list_new(0);
    if (self->f_bloblistfield == NULL) return -1;
    rc = mal_blob_list_decode_malbinary(self->f_bloblistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_bloblistfield = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_enumlistfield = testarea_testenumeration_list_new(0);
    if (self->f_enumlistfield == NULL) return -1;
    rc = testarea_testenumeration_list_decode_malbinary(self->f_enumlistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_enumlistfield = NULL;
  }
  self->f_complistfield = testarea_testservice_testcomposite_list_new(0);
  if (self->f_complistfield == NULL) return -1;
  rc = testarea_testservice_testcomposite_list_decode_malbinary(self->f_complistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_attributefield_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute(decoder, cursor, self->f_attributefield_attribute_tag, &self->f_attributefield);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void testarea_testservice_testfullcomposite_destroy(testarea_testservice_testfullcomposite_t ** self_p)
{
  if ((*self_p)->f_stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->f_stringfield);
  }
  if ((*self_p)->f_blobfield != NULL)
  {
    mal_blob_destroy(& (*self_p)->f_blobfield);
  }
  if ((*self_p)->f_compfield != NULL)
  {
    testarea_testservice_testcomposite_destroy(& (*self_p)->f_compfield);
  }
  if ((*self_p)->f_boollistfield != NULL)
  {
    mal_boolean_list_destroy(& (*self_p)->f_boollistfield);
  }
  if ((*self_p)->f_intlistfield != NULL)
  {
    mal_integer_list_destroy(& (*self_p)->f_intlistfield);
  }
  if ((*self_p)->f_stringlistfield != NULL)
  {
    mal_string_list_destroy(& (*self_p)->f_stringlistfield);
  }
  if ((*self_p)->f_bloblistfield != NULL)
  {
    mal_blob_list_destroy(& (*self_p)->f_bloblistfield);
  }
  if ((*self_p)->f_enumlistfield != NULL)
  {
    testarea_testenumeration_list_destroy(& (*self_p)->f_enumlistfield);
  }
  if ((*self_p)->f_complistfield != NULL)
  {
    testarea_testservice_testcomposite_list_destroy(& (*self_p)->f_complistfield);
  }
  mal_attribute_destroy(&(*self_p)->f_attributefield, (*self_p)->f_attributefield_attribute_tag);
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testfullcomposite_test(bool verbose)
{
  printf(" * TestArea:TestService:TestFullComposite: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
