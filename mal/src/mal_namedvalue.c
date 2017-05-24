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

#include "mal.h"


// structure definition for composite mal_namedvalue
struct _mal_namedvalue_t {
  mal_identifier_t * name;
  bool value_is_present;
  unsigned char value_attribute_tag;
  union mal_attribute_t value;
};

// fields accessors for composite mal_namedvalue
mal_identifier_t * mal_namedvalue_get_name(mal_namedvalue_t * self)
{
  return self->name;
}
void mal_namedvalue_set_name(mal_namedvalue_t * self, mal_identifier_t * name)
{
  self->name = name;
}
bool mal_namedvalue_value_is_present(mal_namedvalue_t * self)
{
  return self->value_is_present;
}
void mal_namedvalue_value_set_present(mal_namedvalue_t * self, bool is_present)
{
  self->value_is_present = is_present;
}
unsigned char mal_namedvalue_value_get_attribute_tag(mal_namedvalue_t * self)
{
  return self->value_attribute_tag;
}
void mal_namedvalue_value_set_attribute_tag(mal_namedvalue_t * self, unsigned char attribute_tag)
{
  self->value_attribute_tag = attribute_tag;
}

// default constructor
mal_namedvalue_t * mal_namedvalue_new(void)
{
  mal_namedvalue_t *self = (mal_namedvalue_t *) calloc(1, sizeof(mal_namedvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_namedvalue_add_encoding_length_malbinary(mal_namedvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->name != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->name != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->name, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->value_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->value_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->value_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->value_attribute_tag, self->value, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_namedvalue_encode_malbinary(mal_namedvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->name != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->name);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->value_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->value_attribute_tag, self->value);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_namedvalue_decode_malbinary(mal_namedvalue_t * self, mal_decoder_t * decoder, void * cursor) {
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag) {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->name);
    if (rc < 0)
      return rc;
  } else {
    self->name = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag) {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->value_attribute_tag, &self->value);
    if (rc < 0)
      return rc;
  }
  self->value_is_present = presence_flag;
  return rc;
}

// destructor
void mal_namedvalue_destroy(mal_namedvalue_t ** self_p)
{
  if ((*self_p)->name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->name);
  }
  if ((*self_p)->value_is_present)
  {
    mal_attribute_destroy(&(*self_p)->value, (*self_p)->value_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_namedvalue_test(bool verbose)
{
  printf(" * MAL:NamedValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
