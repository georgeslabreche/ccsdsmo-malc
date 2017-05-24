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
#include "com.h"


// structure definition for composite com_archive_compositefilter
struct _com_archive_compositefilter_t {
  mal_string_t * f_fieldname;
  com_archive_expressionoperator_t f_type;
  bool f_fieldvalue_is_present;
  unsigned char f_fieldvalue_attribute_tag;
  union mal_attribute_t f_fieldvalue;
};

// fields accessors for composite com_archive_compositefilter
mal_string_t * com_archive_compositefilter_get_fieldname(com_archive_compositefilter_t * self)
{
  return self->f_fieldname;
}
void com_archive_compositefilter_set_fieldname(com_archive_compositefilter_t * self, mal_string_t * f_fieldname)
{
  self->f_fieldname = f_fieldname;
}
com_archive_expressionoperator_t com_archive_compositefilter_get_type(com_archive_compositefilter_t * self)
{
  return self->f_type;
}
void com_archive_compositefilter_set_type(com_archive_compositefilter_t * self, com_archive_expressionoperator_t f_type)
{
  self->f_type = f_type;
}
bool com_archive_compositefilter_fieldvalue_is_present(com_archive_compositefilter_t * self)
{
  return self->f_fieldvalue_is_present;
}
void com_archive_compositefilter_fieldvalue_set_present(com_archive_compositefilter_t * self, bool is_present)
{
  self->f_fieldvalue_is_present = is_present;
}
unsigned char com_archive_compositefilter_fieldvalue_get_attribute_tag(com_archive_compositefilter_t * self)
{
  return self->f_fieldvalue_attribute_tag;
}
void com_archive_compositefilter_fieldvalue_set_attribute_tag(com_archive_compositefilter_t * self, unsigned char attribute_tag)
{
  self->f_fieldvalue_attribute_tag = attribute_tag;
}

// default constructor
com_archive_compositefilter_t * com_archive_compositefilter_new(void)
{
  com_archive_compositefilter_t *self = (com_archive_compositefilter_t *) calloc(1, sizeof(com_archive_compositefilter_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archive_compositefilter_add_encoding_length_malbinary(com_archive_compositefilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_fieldname, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_type, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_fieldvalue_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_fieldvalue_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_fieldvalue_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_fieldvalue_attribute_tag, self->f_fieldvalue, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archive_compositefilter_encode_malbinary(com_archive_compositefilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_fieldname);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_type);
  if (rc < 0)
    return rc;
  presence_flag = self->f_fieldvalue_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_fieldvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_fieldvalue_attribute_tag, self->f_fieldvalue);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archive_compositefilter_decode_malbinary(com_archive_compositefilter_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_fieldname);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_type = (com_archive_expressionoperator_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_fieldvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_fieldvalue_attribute_tag, &self->f_fieldvalue);
    if (rc < 0)
      return rc;
  }
  self->f_fieldvalue_is_present = presence_flag;
  return rc;
}

// destructor
void com_archive_compositefilter_destroy(com_archive_compositefilter_t ** self_p)
{
  if ((*self_p)->f_fieldname != NULL)
  {
    mal_string_destroy(& (*self_p)->f_fieldname);
  }
  if ((*self_p)->f_fieldvalue_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_fieldvalue, (*self_p)->f_fieldvalue_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archive_compositefilter_test(bool verbose)
{
  printf(" * COM:Archive:CompositeFilter: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
