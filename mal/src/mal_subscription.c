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


// structure definition for composite mal_subscription
struct _mal_subscription_t {
  mal_identifier_t * subscriptionid;
  mal_entityrequest_list_t * entities;
};

// fields accessors for composite mal_subscription
mal_identifier_t * mal_subscription_get_subscriptionid(mal_subscription_t * self)
{
  return self->subscriptionid;
}
void mal_subscription_set_subscriptionid(mal_subscription_t * self, mal_identifier_t * subscriptionid)
{
  self->subscriptionid = subscriptionid;
}
mal_entityrequest_list_t * mal_subscription_get_entities(mal_subscription_t * self)
{
  return self->entities;
}
void mal_subscription_set_entities(mal_subscription_t * self, mal_entityrequest_list_t * entities)
{
  self->entities = entities;
}

// default constructor
mal_subscription_t * mal_subscription_new(void)
{
  mal_subscription_t *self = (mal_subscription_t *) calloc(1, sizeof(mal_subscription_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_subscription_add_encoding_length_malbinary(mal_subscription_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->subscriptionid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_entityrequest_list_add_encoding_length_malbinary(self->entities, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_subscription_encode_malbinary(mal_subscription_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->subscriptionid);
  if (rc < 0)
    return rc;
  rc = mal_entityrequest_list_encode_malbinary(self->entities, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_subscription_decode_malbinary(mal_subscription_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->subscriptionid);
  if (rc < 0)
    return rc;
  self->entities = mal_entityrequest_list_new(0);
  if (self->entities == NULL) return -1;
  rc = mal_entityrequest_list_decode_malbinary(self->entities, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mal_subscription_destroy(mal_subscription_t ** self_p)
{
  if ((*self_p)->subscriptionid != NULL)
  {
    mal_identifier_destroy(& (*self_p)->subscriptionid);
  }
  if ((*self_p)->entities != NULL)
  {
    mal_entityrequest_list_destroy(& (*self_p)->entities);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_subscription_test(bool verbose)
{
  printf(" * MAL:Subscription: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
