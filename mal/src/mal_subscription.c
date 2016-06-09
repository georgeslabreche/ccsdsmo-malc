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
int mal_subscription_add_encoding_length_malbinary(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(mal_encoder, self->subscriptionid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_entityrequest_list_add_encoding_length_malbinary(self->entities, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_subscription_encode_malbinary(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(mal_encoder, cursor, self->subscriptionid);
  if (rc < 0)
    return rc;
  rc = mal_entityrequest_list_encode_malbinary(self->entities, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_subscription_decode_malbinary(mal_subscription_t * self, mal_decoder_t * mal_decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(mal_decoder, cursor, &self->subscriptionid);
  if (rc < 0)
    return rc;
  self->entities = mal_entityrequest_list_new(0);
  if (self->entities == NULL) return -1;
  rc = mal_entityrequest_list_decode_malbinary(self->entities, mal_decoder, cursor);
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
