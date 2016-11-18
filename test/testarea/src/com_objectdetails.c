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
#include "com.h"


// structure definition for composite com_objectdetails
struct _com_objectdetails_t {
  bool f_related_is_present;
  mal_long_t f_related;
  com_objectid_t * f_source;
};

// fields accessors for composite com_objectdetails
bool com_objectdetails_related_is_present(com_objectdetails_t * self)
{
  return self->f_related_is_present;
}
void com_objectdetails_related_set_present(com_objectdetails_t * self, bool is_present)
{
  self->f_related_is_present = is_present;
}
mal_long_t com_objectdetails_get_related(com_objectdetails_t * self)
{
  return self->f_related;
}
void com_objectdetails_set_related(com_objectdetails_t * self, mal_long_t f_related)
{
  self->f_related = f_related;
}
com_objectid_t * com_objectdetails_get_source(com_objectdetails_t * self)
{
  return self->f_source;
}
void com_objectdetails_set_source(com_objectdetails_t * self, com_objectid_t * f_source)
{
  self->f_source = f_source;
}

// default constructor
com_objectdetails_t * com_objectdetails_new(void)
{
  com_objectdetails_t *self = (com_objectdetails_t *) calloc(1, sizeof(com_objectdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_objectdetails_add_encoding_length_malbinary(com_objectdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_related_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_related_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_related, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_source != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_source != NULL))
  {
    rc = com_objectid_add_encoding_length_malbinary(self->f_source, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_objectdetails_encode_malbinary(com_objectdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_related_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_related);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_source != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = com_objectid_encode_malbinary(self->f_source, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_objectdetails_decode_malbinary(com_objectdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_related);
    if (rc < 0)
      return rc;
  }
  self->f_related_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_source = com_objectid_new();
    if (self->f_source == NULL) return -1;
    rc = com_objectid_decode_malbinary(self->f_source, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_source = NULL;
  }
  return rc;
}

// destructor
void com_objectdetails_destroy(com_objectdetails_t ** self_p)
{
  if ((*self_p)->f_source != NULL)
  {
    com_objectid_destroy(& (*self_p)->f_source);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_objectdetails_test(bool verbose)
{
  printf(" * COM:ObjectDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
