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

#include "mal.h"


// structure definition for composite mal_idbooleanpair
struct _mal_idbooleanpair_t {
  mal_identifier_t * id;
  bool value_is_present;
  mal_boolean_t value;
};

// fields accessors for composite mal_idbooleanpair
mal_identifier_t * mal_idbooleanpair_get_id(mal_idbooleanpair_t * self)
{
  return self->id;
}
void mal_idbooleanpair_set_id(mal_idbooleanpair_t * self, mal_identifier_t * id)
{
  self->id = id;
}
bool mal_idbooleanpair_value_is_present(mal_idbooleanpair_t * self)
{
  return self->value_is_present;
}
void mal_idbooleanpair_value_set_present(mal_idbooleanpair_t * self, bool is_present)
{
  self->value_is_present = is_present;
}
mal_boolean_t mal_idbooleanpair_get_value(mal_idbooleanpair_t * self)
{
  return self->value;
}
void mal_idbooleanpair_set_value(mal_idbooleanpair_t * self, mal_boolean_t value)
{
  self->value = value;
}

// default constructor
mal_idbooleanpair_t * mal_idbooleanpair_new(void)
{
  mal_idbooleanpair_t *self = (mal_idbooleanpair_t *) calloc(1, sizeof(mal_idbooleanpair_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_idbooleanpair_add_encoding_length_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->id != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->id != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->id, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->value_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->value_is_present)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, self->value, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_idbooleanpair_encode_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->id != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->id);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->value_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, self->value);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_idbooleanpair_decode_malbinary(mal_idbooleanpair_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->id);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->id = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &self->value);
    if (rc < 0)
      return rc;
  }
  self->value_is_present = presence_flag;
  return rc;
}

// destructor
void mal_idbooleanpair_destroy(mal_idbooleanpair_t ** self_p)
{
  if ((*self_p)->id != NULL)
  {
    mal_identifier_destroy(& (*self_p)->id);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_idbooleanpair_test(bool verbose)
{
  printf(" * MAL:IdBooleanPair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
