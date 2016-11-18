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


// structure definition for composite com_archive_archivedetails
struct _com_archive_archivedetails_t {
  mal_long_t f_instid;
  com_objectdetails_t * f_details;
  mal_identifier_t * f_network;
  bool f_timestamp_is_present;
  mal_finetime_t f_timestamp;
  mal_uri_t * f_provider;
};

// fields accessors for composite com_archive_archivedetails
mal_long_t com_archive_archivedetails_get_instid(com_archive_archivedetails_t * self)
{
  return self->f_instid;
}
void com_archive_archivedetails_set_instid(com_archive_archivedetails_t * self, mal_long_t f_instid)
{
  self->f_instid = f_instid;
}
com_objectdetails_t * com_archive_archivedetails_get_details(com_archive_archivedetails_t * self)
{
  return self->f_details;
}
void com_archive_archivedetails_set_details(com_archive_archivedetails_t * self, com_objectdetails_t * f_details)
{
  self->f_details = f_details;
}
mal_identifier_t * com_archive_archivedetails_get_network(com_archive_archivedetails_t * self)
{
  return self->f_network;
}
void com_archive_archivedetails_set_network(com_archive_archivedetails_t * self, mal_identifier_t * f_network)
{
  self->f_network = f_network;
}
bool com_archive_archivedetails_timestamp_is_present(com_archive_archivedetails_t * self)
{
  return self->f_timestamp_is_present;
}
void com_archive_archivedetails_timestamp_set_present(com_archive_archivedetails_t * self, bool is_present)
{
  self->f_timestamp_is_present = is_present;
}
mal_finetime_t com_archive_archivedetails_get_timestamp(com_archive_archivedetails_t * self)
{
  return self->f_timestamp;
}
void com_archive_archivedetails_set_timestamp(com_archive_archivedetails_t * self, mal_finetime_t f_timestamp)
{
  self->f_timestamp = f_timestamp;
}
mal_uri_t * com_archive_archivedetails_get_provider(com_archive_archivedetails_t * self)
{
  return self->f_provider;
}
void com_archive_archivedetails_set_provider(com_archive_archivedetails_t * self, mal_uri_t * f_provider)
{
  self->f_provider = f_provider;
}

// default constructor
com_archive_archivedetails_t * com_archive_archivedetails_new(void)
{
  com_archive_archivedetails_t *self = (com_archive_archivedetails_t *) calloc(1, sizeof(com_archive_archivedetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archive_archivedetails_add_encoding_length_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_instid, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectdetails_add_encoding_length_malbinary(self->f_details, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_network != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_network != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_network, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_timestamp_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_timestamp_is_present)
  {
    rc = mal_encoder_add_finetime_encoding_length(encoder, self->f_timestamp, cursor);
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
  return rc;
}
int com_archive_archivedetails_encode_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_instid);
  if (rc < 0)
    return rc;
  rc = com_objectdetails_encode_malbinary(self->f_details, encoder, cursor);
  if (rc < 0)
    return rc;
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
  presence_flag = self->f_timestamp_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_finetime(encoder, cursor, self->f_timestamp);
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
  return rc;
}
int com_archive_archivedetails_decode_malbinary(com_archive_archivedetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_instid);
  if (rc < 0)
    return rc;
  self->f_details = com_objectdetails_new();
  if (self->f_details == NULL) return -1;
  rc = com_objectdetails_decode_malbinary(self->f_details, decoder, cursor);
  if (rc < 0)
    return rc;
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
    rc = mal_decoder_decode_finetime(decoder, cursor, &self->f_timestamp);
    if (rc < 0)
      return rc;
  }
  self->f_timestamp_is_present = presence_flag;
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
  return rc;
}

// destructor
void com_archive_archivedetails_destroy(com_archive_archivedetails_t ** self_p)
{
  if ((*self_p)->f_details != NULL)
  {
    com_objectdetails_destroy(& (*self_p)->f_details);
  }
  if ((*self_p)->f_network != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_network);
  }
  if ((*self_p)->f_provider != NULL)
  {
    mal_uri_destroy(& (*self_p)->f_provider);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archive_archivedetails_test(bool verbose)
{
  printf(" * COM:Archive:ArchiveDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
