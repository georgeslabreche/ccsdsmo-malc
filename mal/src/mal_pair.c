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


// structure definition for composite mal_pair
struct _mal_pair_t {
  bool first_is_present;
  unsigned char first_attribute_tag;
  union mal_attribute_t first;
  bool second_is_present;
  unsigned char second_attribute_tag;
  union mal_attribute_t second;
};

// fields accessors for composite mal_pair
bool mal_pair_first_is_present(mal_pair_t * self)
{
  return self->first_is_present;
}
void mal_pair_first_set_present(mal_pair_t * self, bool is_present)
{
  self->first_is_present = is_present;
}
unsigned char mal_pair_first_get_attribute_tag(mal_pair_t * self)
{
  return self->first_attribute_tag;
}
void mal_pair_first_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag)
{
  self->first_attribute_tag = attribute_tag;
}
bool mal_pair_second_is_present(mal_pair_t * self)
{
  return self->second_is_present;
}
void mal_pair_second_set_present(mal_pair_t * self, bool is_present)
{
  self->second_is_present = is_present;
}
unsigned char mal_pair_second_get_attribute_tag(mal_pair_t * self)
{
  return self->second_attribute_tag;
}
void mal_pair_second_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag)
{
  self->second_attribute_tag = attribute_tag;
}

// default constructor
mal_pair_t * mal_pair_new(void)
{
  mal_pair_t *self = (mal_pair_t *) calloc(1, sizeof(mal_pair_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_pair_add_encoding_length_malbinary(mal_pair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->first_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->first_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->first_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->first_attribute_tag, self->first, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->second_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->second_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->second_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->second_attribute_tag, self->second, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_pair_encode_malbinary(mal_pair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->first_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->first_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->first_attribute_tag, self->first);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->second_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->second_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->second_attribute_tag, self->second);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_pair_decode_malbinary(mal_pair_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->first_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->first_attribute_tag, &self->first);
    if (rc < 0)
      return rc;
  }
  self->first_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->second_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->second_attribute_tag, &self->second);
    if (rc < 0)
      return rc;
  }
  self->second_is_present = presence_flag;
  return rc;
}

// destructor
void mal_pair_destroy(mal_pair_t ** self_p)
{
  if ((*self_p)->first_is_present)
  {
    mal_attribute_destroy(&(*self_p)->first, (*self_p)->first_attribute_tag);
  }
  if ((*self_p)->second_is_present)
  {
    mal_attribute_destroy(&(*self_p)->second, (*self_p)->second_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_pair_test(bool verbose)
{
  printf(" * MAL:Pair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
