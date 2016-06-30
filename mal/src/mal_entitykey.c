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


// structure definition for composite mal_entitykey
struct _mal_entitykey_t {
  mal_identifier_t * firstsubkey;
  bool secondsubkey_is_present;
  mal_long_t secondsubkey;
  bool thirdsubkey_is_present;
  mal_long_t thirdsubkey;
  bool fourthsubkey_is_present;
  mal_long_t fourthsubkey;
};

// fields accessors for composite mal_entitykey
mal_identifier_t * mal_entitykey_get_firstsubkey(mal_entitykey_t * self)
{
  return self->firstsubkey;
}
void mal_entitykey_set_firstsubkey(mal_entitykey_t * self, mal_identifier_t * firstsubkey)
{
  self->firstsubkey = firstsubkey;
}
bool mal_entitykey_secondsubkey_is_present(mal_entitykey_t * self)
{
  return self->secondsubkey_is_present;
}
void mal_entitykey_secondsubkey_set_present(mal_entitykey_t * self, bool is_present)
{
  self->secondsubkey_is_present = is_present;
}
mal_long_t mal_entitykey_get_secondsubkey(mal_entitykey_t * self)
{
  return self->secondsubkey;
}
void mal_entitykey_set_secondsubkey(mal_entitykey_t * self, mal_long_t secondsubkey)
{
  self->secondsubkey = secondsubkey;
}
bool mal_entitykey_thirdsubkey_is_present(mal_entitykey_t * self)
{
  return self->thirdsubkey_is_present;
}
void mal_entitykey_thirdsubkey_set_present(mal_entitykey_t * self, bool is_present)
{
  self->thirdsubkey_is_present = is_present;
}
mal_long_t mal_entitykey_get_thirdsubkey(mal_entitykey_t * self)
{
  return self->thirdsubkey;
}
void mal_entitykey_set_thirdsubkey(mal_entitykey_t * self, mal_long_t thirdsubkey)
{
  self->thirdsubkey = thirdsubkey;
}
bool mal_entitykey_fourthsubkey_is_present(mal_entitykey_t * self)
{
  return self->fourthsubkey_is_present;
}
void mal_entitykey_fourthsubkey_set_present(mal_entitykey_t * self, bool is_present)
{
  self->fourthsubkey_is_present = is_present;
}
mal_long_t mal_entitykey_get_fourthsubkey(mal_entitykey_t * self)
{
  return self->fourthsubkey;
}
void mal_entitykey_set_fourthsubkey(mal_entitykey_t * self, mal_long_t fourthsubkey)
{
  self->fourthsubkey = fourthsubkey;
}

// default constructor
mal_entitykey_t * mal_entitykey_new(void)
{
  mal_entitykey_t *self = (mal_entitykey_t *) calloc(1, sizeof(mal_entitykey_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_entitykey_add_encoding_length_malbinary(mal_entitykey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->firstsubkey != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->firstsubkey != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->firstsubkey, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->secondsubkey_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->secondsubkey_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->secondsubkey, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->thirdsubkey_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->thirdsubkey_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->thirdsubkey, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->fourthsubkey_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->fourthsubkey_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->fourthsubkey, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_entitykey_encode_malbinary(mal_entitykey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->firstsubkey != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->firstsubkey);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->secondsubkey_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->secondsubkey);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->thirdsubkey_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->thirdsubkey);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->fourthsubkey_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->fourthsubkey);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_entitykey_decode_malbinary(mal_entitykey_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->firstsubkey);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->firstsubkey = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->secondsubkey);
    if (rc < 0)
      return rc;
  }
  self->secondsubkey_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->thirdsubkey);
    if (rc < 0)
      return rc;
  }
  self->thirdsubkey_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->fourthsubkey);
    if (rc < 0)
      return rc;
  }
  self->fourthsubkey_is_present = presence_flag;
  return rc;
}

// destructor
void mal_entitykey_destroy(mal_entitykey_t ** self_p)
{
  if ((*self_p)->firstsubkey != NULL)
  {
    mal_identifier_destroy(& (*self_p)->firstsubkey);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_entitykey_test(bool verbose)
{
  printf(" * MAL:EntityKey: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
