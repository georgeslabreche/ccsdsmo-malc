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


// structure definition for composite com_archive_archivequery
struct _com_archive_archivequery_t {
  mal_identifier_list_t * f_domain;
  mal_identifier_t * f_network;
  mal_uri_t * f_provider;
  mal_long_t f_related;
  com_objectid_t * f_source;
  bool f_starttime_is_present;
  mal_finetime_t f_starttime;
  bool f_endtime_is_present;
  mal_finetime_t f_endtime;
  bool f_sortorder_is_present;
  mal_boolean_t f_sortorder;
  mal_string_t * f_sortfieldname;
};

// fields accessors for composite com_archive_archivequery
mal_identifier_list_t * com_archive_archivequery_get_domain(com_archive_archivequery_t * self)
{
  return self->f_domain;
}
void com_archive_archivequery_set_domain(com_archive_archivequery_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_identifier_t * com_archive_archivequery_get_network(com_archive_archivequery_t * self)
{
  return self->f_network;
}
void com_archive_archivequery_set_network(com_archive_archivequery_t * self, mal_identifier_t * f_network)
{
  self->f_network = f_network;
}
mal_uri_t * com_archive_archivequery_get_provider(com_archive_archivequery_t * self)
{
  return self->f_provider;
}
void com_archive_archivequery_set_provider(com_archive_archivequery_t * self, mal_uri_t * f_provider)
{
  self->f_provider = f_provider;
}
mal_long_t com_archive_archivequery_get_related(com_archive_archivequery_t * self)
{
  return self->f_related;
}
void com_archive_archivequery_set_related(com_archive_archivequery_t * self, mal_long_t f_related)
{
  self->f_related = f_related;
}
com_objectid_t * com_archive_archivequery_get_source(com_archive_archivequery_t * self)
{
  return self->f_source;
}
void com_archive_archivequery_set_source(com_archive_archivequery_t * self, com_objectid_t * f_source)
{
  self->f_source = f_source;
}
bool com_archive_archivequery_starttime_is_present(com_archive_archivequery_t * self)
{
  return self->f_starttime_is_present;
}
void com_archive_archivequery_starttime_set_present(com_archive_archivequery_t * self, bool is_present)
{
  self->f_starttime_is_present = is_present;
}
mal_finetime_t com_archive_archivequery_get_starttime(com_archive_archivequery_t * self)
{
  return self->f_starttime;
}
void com_archive_archivequery_set_starttime(com_archive_archivequery_t * self, mal_finetime_t f_starttime)
{
  self->f_starttime = f_starttime;
}
bool com_archive_archivequery_endtime_is_present(com_archive_archivequery_t * self)
{
  return self->f_endtime_is_present;
}
void com_archive_archivequery_endtime_set_present(com_archive_archivequery_t * self, bool is_present)
{
  self->f_endtime_is_present = is_present;
}
mal_finetime_t com_archive_archivequery_get_endtime(com_archive_archivequery_t * self)
{
  return self->f_endtime;
}
void com_archive_archivequery_set_endtime(com_archive_archivequery_t * self, mal_finetime_t f_endtime)
{
  self->f_endtime = f_endtime;
}
bool com_archive_archivequery_sortorder_is_present(com_archive_archivequery_t * self)
{
  return self->f_sortorder_is_present;
}
void com_archive_archivequery_sortorder_set_present(com_archive_archivequery_t * self, bool is_present)
{
  self->f_sortorder_is_present = is_present;
}
mal_boolean_t com_archive_archivequery_get_sortorder(com_archive_archivequery_t * self)
{
  return self->f_sortorder;
}
void com_archive_archivequery_set_sortorder(com_archive_archivequery_t * self, mal_boolean_t f_sortorder)
{
  self->f_sortorder = f_sortorder;
}
mal_string_t * com_archive_archivequery_get_sortfieldname(com_archive_archivequery_t * self)
{
  return self->f_sortfieldname;
}
void com_archive_archivequery_set_sortfieldname(com_archive_archivequery_t * self, mal_string_t * f_sortfieldname)
{
  self->f_sortfieldname = f_sortfieldname;
}

// default constructor
com_archive_archivequery_t * com_archive_archivequery_new(void)
{
  com_archive_archivequery_t *self = (com_archive_archivequery_t *) calloc(1, sizeof(com_archive_archivequery_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archive_archivequery_add_encoding_length_malbinary(com_archive_archivequery_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_domain != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_domain != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_network != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_network != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_network, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_provider != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_provider != NULL))
  {
    rc = mal_encoder_add_uri_encoding_length(encoder, self->f_provider, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_related, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_source != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_source != NULL))
  {
    rc = com_objectid_add_encoding_length_malbinary(self->f_source, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_starttime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_starttime_is_present)
  {
    rc = mal_encoder_add_finetime_encoding_length(encoder, self->f_starttime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_endtime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_endtime_is_present)
  {
    rc = mal_encoder_add_finetime_encoding_length(encoder, self->f_endtime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_sortorder_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_sortorder_is_present)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_sortorder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_sortfieldname != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_sortfieldname != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_sortfieldname, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archive_archivequery_encode_malbinary(com_archive_archivequery_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_domain != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_network != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_network);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_provider != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uri(encoder, cursor, self->f_provider);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_long(encoder, cursor, self->f_related);
  if (rc < 0)
    return rc;
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
  presence_flag = self->f_starttime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_finetime(encoder, cursor, self->f_starttime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_endtime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_finetime(encoder, cursor, self->f_endtime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_sortorder_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, self->f_sortorder);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_sortfieldname != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_sortfieldname);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archive_archivequery_decode_malbinary(com_archive_archivequery_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_domain = mal_identifier_list_new(0);
    if (self->f_domain == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_domain = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_network);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_network = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uri(decoder, cursor, &self->f_provider);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_provider = NULL;
  }
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_related);
  if (rc < 0)
    return rc;
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
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_finetime(decoder, cursor, &self->f_starttime);
    if (rc < 0)
      return rc;
  }
  self->f_starttime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_finetime(decoder, cursor, &self->f_endtime);
    if (rc < 0)
      return rc;
  }
  self->f_endtime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_sortorder);
    if (rc < 0)
      return rc;
  }
  self->f_sortorder_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_sortfieldname);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_sortfieldname = NULL;
  }
  return rc;
}

// destructor
void com_archive_archivequery_destroy(com_archive_archivequery_t ** self_p)
{
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_network != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_network);
  }
  if ((*self_p)->f_provider != NULL)
  {
    mal_uri_destroy(& (*self_p)->f_provider);
  }
  if ((*self_p)->f_source != NULL)
  {
    com_objectid_destroy(& (*self_p)->f_source);
  }
  if ((*self_p)->f_sortfieldname != NULL)
  {
    mal_string_destroy(& (*self_p)->f_sortfieldname);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archive_archivequery_test(bool verbose)
{
  printf(" * COM:Archive:ArchiveQuery: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
