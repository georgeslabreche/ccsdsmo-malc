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


// structure definition for composite com_objectkey
struct _com_objectkey_t {
  mal_identifier_list_t * f_domain;
  mal_long_t f_instid;
};

// fields accessors for composite com_objectkey
mal_identifier_list_t * com_objectkey_get_domain(com_objectkey_t * self)
{
  return self->f_domain;
}
void com_objectkey_set_domain(com_objectkey_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_long_t com_objectkey_get_instid(com_objectkey_t * self)
{
  return self->f_instid;
}
void com_objectkey_set_instid(com_objectkey_t * self, mal_long_t f_instid)
{
  self->f_instid = f_instid;
}

// default constructor
com_objectkey_t * com_objectkey_new(void)
{
  com_objectkey_t *self = (com_objectkey_t *) calloc(1, sizeof(com_objectkey_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_objectkey_add_encoding_length_malbinary(com_objectkey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_instid, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objectkey_encode_malbinary(com_objectkey_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_instid);
  if (rc < 0)
    return rc;
  return rc;
}
int com_objectkey_decode_malbinary(com_objectkey_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_domain = mal_identifier_list_new(0);
  if (self->f_domain == NULL) return -1;
  rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_instid);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_objectkey_destroy(com_objectkey_t ** self_p)
{
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_objectkey_test(bool verbose)
{
  printf(" * COM:ObjectKey: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
