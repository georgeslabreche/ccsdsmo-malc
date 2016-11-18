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


// structure definition for composite com_activitytracking_activitytransfer
struct _com_activitytracking_activitytransfer_t {
  mal_boolean_t f_success;
  bool f_estimateduration_is_present;
  mal_duration_t f_estimateduration;
  mal_uri_t * f_nextdestination;
};

// fields accessors for composite com_activitytracking_activitytransfer
mal_boolean_t com_activitytracking_activitytransfer_get_success(com_activitytracking_activitytransfer_t * self)
{
  return self->f_success;
}
void com_activitytracking_activitytransfer_set_success(com_activitytracking_activitytransfer_t * self, mal_boolean_t f_success)
{
  self->f_success = f_success;
}
bool com_activitytracking_activitytransfer_estimateduration_is_present(com_activitytracking_activitytransfer_t * self)
{
  return self->f_estimateduration_is_present;
}
void com_activitytracking_activitytransfer_estimateduration_set_present(com_activitytracking_activitytransfer_t * self, bool is_present)
{
  self->f_estimateduration_is_present = is_present;
}
mal_duration_t com_activitytracking_activitytransfer_get_estimateduration(com_activitytracking_activitytransfer_t * self)
{
  return self->f_estimateduration;
}
void com_activitytracking_activitytransfer_set_estimateduration(com_activitytracking_activitytransfer_t * self, mal_duration_t f_estimateduration)
{
  self->f_estimateduration = f_estimateduration;
}
mal_uri_t * com_activitytracking_activitytransfer_get_nextdestination(com_activitytracking_activitytransfer_t * self)
{
  return self->f_nextdestination;
}
void com_activitytracking_activitytransfer_set_nextdestination(com_activitytracking_activitytransfer_t * self, mal_uri_t * f_nextdestination)
{
  self->f_nextdestination = f_nextdestination;
}

// default constructor
com_activitytracking_activitytransfer_t * com_activitytracking_activitytransfer_new(void)
{
  com_activitytracking_activitytransfer_t *self = (com_activitytracking_activitytransfer_t *) calloc(1, sizeof(com_activitytracking_activitytransfer_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_activitytracking_activitytransfer_add_encoding_length_malbinary(com_activitytracking_activitytransfer_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_success, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_estimateduration_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_estimateduration_is_present)
  {
    rc = mal_encoder_add_duration_encoding_length(encoder, self->f_estimateduration, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_nextdestination != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_nextdestination != NULL))
  {
    rc = mal_encoder_add_uri_encoding_length(encoder, self->f_nextdestination, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_activitytracking_activitytransfer_encode_malbinary(com_activitytracking_activitytransfer_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_success);
  if (rc < 0)
    return rc;
  presence_flag = self->f_estimateduration_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_duration(encoder, cursor, self->f_estimateduration);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_nextdestination != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uri(encoder, cursor, self->f_nextdestination);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_activitytracking_activitytransfer_decode_malbinary(com_activitytracking_activitytransfer_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_success);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_duration(decoder, cursor, &self->f_estimateduration);
    if (rc < 0)
      return rc;
  }
  self->f_estimateduration_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uri(decoder, cursor, &self->f_nextdestination);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_nextdestination = NULL;
  }
  return rc;
}

// destructor
void com_activitytracking_activitytransfer_destroy(com_activitytracking_activitytransfer_t ** self_p)
{
  if ((*self_p)->f_nextdestination != NULL)
  {
    mal_uri_destroy(& (*self_p)->f_nextdestination);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_activitytracking_activitytransfer_test(bool verbose)
{
  printf(" * COM:ActivityTracking:ActivityTransfer: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
