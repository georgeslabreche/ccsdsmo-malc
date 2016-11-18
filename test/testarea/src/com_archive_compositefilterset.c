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


// structure definition for composite com_archive_compositefilterset
struct _com_archive_compositefilterset_t {
  com_archive_compositefilter_list_t * f_filters;
};

// fields accessors for composite com_archive_compositefilterset
com_archive_compositefilter_list_t * com_archive_compositefilterset_get_filters(com_archive_compositefilterset_t * self)
{
  return self->f_filters;
}
void com_archive_compositefilterset_set_filters(com_archive_compositefilterset_t * self, com_archive_compositefilter_list_t * f_filters)
{
  self->f_filters = f_filters;
}

// default constructor
com_archive_compositefilterset_t * com_archive_compositefilterset_new(void)
{
  com_archive_compositefilterset_t *self = (com_archive_compositefilterset_t *) calloc(1, sizeof(com_archive_compositefilterset_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archive_compositefilterset_add_encoding_length_malbinary(com_archive_compositefilterset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_archive_compositefilter_list_add_encoding_length_malbinary(self->f_filters, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archive_compositefilterset_encode_malbinary(com_archive_compositefilterset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_archive_compositefilter_list_encode_malbinary(self->f_filters, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archive_compositefilterset_decode_malbinary(com_archive_compositefilterset_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_filters = com_archive_compositefilter_list_new(0);
  if (self->f_filters == NULL) return -1;
  rc = com_archive_compositefilter_list_decode_malbinary(self->f_filters, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_archive_compositefilterset_destroy(com_archive_compositefilterset_t ** self_p)
{
  if ((*self_p)->f_filters != NULL)
  {
    com_archive_compositefilter_list_destroy(& (*self_p)->f_filters);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archive_compositefilterset_test(bool verbose)
{
  printf(" * COM:Archive:CompositeFilterSet: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
