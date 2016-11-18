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


// structure definition for composite com_instancebooleanpair
struct _com_instancebooleanpair_t {
  mal_long_t f_id;
  mal_boolean_t f_value;
};

// fields accessors for composite com_instancebooleanpair
mal_long_t com_instancebooleanpair_get_id(com_instancebooleanpair_t * self)
{
  return self->f_id;
}
void com_instancebooleanpair_set_id(com_instancebooleanpair_t * self, mal_long_t f_id)
{
  self->f_id = f_id;
}
mal_boolean_t com_instancebooleanpair_get_value(com_instancebooleanpair_t * self)
{
  return self->f_value;
}
void com_instancebooleanpair_set_value(com_instancebooleanpair_t * self, mal_boolean_t f_value)
{
  self->f_value = f_value;
}

// default constructor
com_instancebooleanpair_t * com_instancebooleanpair_new(void)
{
  com_instancebooleanpair_t *self = (com_instancebooleanpair_t *) calloc(1, sizeof(com_instancebooleanpair_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_instancebooleanpair_add_encoding_length_malbinary(com_instancebooleanpair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_id, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_value, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_instancebooleanpair_encode_malbinary(com_instancebooleanpair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_id);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_value);
  if (rc < 0)
    return rc;
  return rc;
}
int com_instancebooleanpair_decode_malbinary(com_instancebooleanpair_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_id);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_value);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_instancebooleanpair_destroy(com_instancebooleanpair_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_instancebooleanpair_test(bool verbose)
{
  printf(" * COM:InstanceBooleanPair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
