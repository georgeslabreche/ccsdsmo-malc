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


// structure definition for composite mal_file
struct _mal_file_t {
  mal_identifier_t * name;
  mal_string_t * mimetype;
  bool creationdate_is_present;
  mal_time_t creationdate;
  bool modificationdate_is_present;
  mal_time_t modificationdate;
  bool size_is_present;
  mal_ulong_t size;
  mal_blob_t * content;
  mal_namedvalue_list_t * metadata;
};

// fields accessors for composite mal_file
mal_identifier_t * mal_file_get_name(mal_file_t * self)
{
  return self->name;
}
void mal_file_set_name(mal_file_t * self, mal_identifier_t * name)
{
  self->name = name;
}
mal_string_t * mal_file_get_mimetype(mal_file_t * self)
{
  return self->mimetype;
}
void mal_file_set_mimetype(mal_file_t * self, mal_string_t * mimetype)
{
  self->mimetype = mimetype;
}
bool mal_file_creationdate_is_present(mal_file_t * self)
{
  return self->creationdate_is_present;
}
void mal_file_creationdate_set_present(mal_file_t * self, bool is_present)
{
  self->creationdate_is_present = is_present;
}
mal_time_t mal_file_get_creationdate(mal_file_t * self)
{
  return self->creationdate;
}
void mal_file_set_creationdate(mal_file_t * self, mal_time_t creationdate)
{
  self->creationdate = creationdate;
}
bool mal_file_modificationdate_is_present(mal_file_t * self)
{
  return self->modificationdate_is_present;
}
void mal_file_modificationdate_set_present(mal_file_t * self, bool is_present)
{
  self->modificationdate_is_present = is_present;
}
mal_time_t mal_file_get_modificationdate(mal_file_t * self)
{
  return self->modificationdate;
}
void mal_file_set_modificationdate(mal_file_t * self, mal_time_t modificationdate)
{
  self->modificationdate = modificationdate;
}
bool mal_file_size_is_present(mal_file_t * self)
{
  return self->size_is_present;
}
void mal_file_size_set_present(mal_file_t * self, bool is_present)
{
  self->size_is_present = is_present;
}
mal_ulong_t mal_file_get_size(mal_file_t * self)
{
  return self->size;
}
void mal_file_set_size(mal_file_t * self, mal_ulong_t size)
{
  self->size = size;
}
mal_blob_t * mal_file_get_content(mal_file_t * self)
{
  return self->content;
}
void mal_file_set_content(mal_file_t * self, mal_blob_t * content)
{
  self->content = content;
}
mal_namedvalue_list_t * mal_file_get_metadata(mal_file_t * self)
{
  return self->metadata;
}
void mal_file_set_metadata(mal_file_t * self, mal_namedvalue_list_t * metadata)
{
  self->metadata = metadata;
}

// default constructor
mal_file_t * mal_file_new(void)
{
  mal_file_t *self = (mal_file_t *) calloc(1, sizeof(mal_file_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_file_add_encoding_length_malbinary(mal_file_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->mimetype != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->mimetype != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->mimetype, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->creationdate_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->creationdate_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->creationdate, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->modificationdate_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->modificationdate_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->modificationdate, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->size_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->size_is_present)
  {
    rc = mal_encoder_add_ulong_encoding_length(encoder, self->size, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->content != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->content != NULL))
  {
    rc = mal_encoder_add_blob_encoding_length(encoder, self->content, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->metadata != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->metadata != NULL))
  {
    rc = mal_namedvalue_list_add_encoding_length_malbinary(self->metadata, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_file_encode_malbinary(mal_file_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->name);
  if (rc < 0)
    return rc;
  presence_flag = (self->mimetype != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->mimetype);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->creationdate_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->creationdate);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->modificationdate_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->modificationdate);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->size_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_ulong(encoder, cursor, self->size);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->content != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_blob(encoder, cursor, self->content);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->metadata != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_namedvalue_list_encode_malbinary(self->metadata, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mal_file_decode_malbinary(mal_file_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->mimetype);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->mimetype = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->creationdate);
    if (rc < 0)
      return rc;
  }
  self->creationdate_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->modificationdate);
    if (rc < 0)
      return rc;
  }
  self->modificationdate_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_ulong(decoder, cursor, &self->size);
    if (rc < 0)
      return rc;
  }
  self->size_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_blob(decoder, cursor, &self->content);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->content = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->metadata = mal_namedvalue_list_new(0);
    if (self->metadata == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary(self->metadata, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->metadata = NULL;
  }
  return rc;
}

// destructor
void mal_file_destroy(mal_file_t ** self_p)
{
  if ((*self_p)->name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->name);
  }
  if ((*self_p)->mimetype != NULL)
  {
    mal_string_destroy(& (*self_p)->mimetype);
  }
  if ((*self_p)->content != NULL)
  {
    mal_blob_destroy(& (*self_p)->content);
  }
  if ((*self_p)->metadata != NULL)
  {
    mal_namedvalue_list_destroy(& (*self_p)->metadata);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_file_test(bool verbose)
{
  printf(" * MAL:File: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
