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


// structure definition for composite com_objectid
struct _com_objectid_t {
  com_objecttype_t * f_type;
  com_objectkey_t * f_key;
};

// fields accessors for composite com_objectid
com_objecttype_t * com_objectid_get_type(com_objectid_t * self)
{
  return self->f_type;
}
void com_objectid_set_type(com_objectid_t * self, com_objecttype_t * f_type)
{
  self->f_type = f_type;
}
com_objectkey_t * com_objectid_get_key(com_objectid_t * self)
{
  return self->f_key;
}
void com_objectid_set_key(com_objectid_t * self, com_objectkey_t * f_key)
{
  self->f_key = f_key;
}

// default constructor
com_objectid_t * com_objectid_new(void)
{
  com_objectid_t *self = (com_objectid_t *) calloc(1, sizeof(com_objectid_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_objectid_add_encoding_length_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objecttype_add_encoding_length_malbinary(self->f_type, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_key, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objectid_encode_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objecttype_encode_malbinary(self->f_type, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectkey_encode_malbinary(self->f_key, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objectid_decode_malbinary(com_objectid_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_type = com_objecttype_new();
  if (self->f_type == NULL) return -1;
  rc = com_objecttype_decode_malbinary(self->f_type, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_key = com_objectkey_new();
  if (self->f_key == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_key, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_objectid_destroy(com_objectid_t ** self_p)
{
  if ((*self_p)->f_type != NULL)
  {
    com_objecttype_destroy(& (*self_p)->f_type);
  }
  if ((*self_p)->f_key != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_key);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_objectid_test(bool verbose)
{
  printf(" * COM:ObjectId: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
