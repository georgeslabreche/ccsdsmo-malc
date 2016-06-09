#include "mal.h"


// structure definition for composite mal_entityrequest
struct _mal_entityrequest_t {
  mal_identifier_list_t * subdomain;
  mal_boolean_t allareas;
  mal_boolean_t allservices;
  mal_boolean_t alloperations;
  mal_boolean_t onlyonchange;
  mal_entitykey_list_t * entitykeys;
};

// fields accessors for composite mal_entityrequest
mal_identifier_list_t * mal_entityrequest_get_subdomain(mal_entityrequest_t * self)
{
  return self->subdomain;
}
void mal_entityrequest_set_subdomain(mal_entityrequest_t * self, mal_identifier_list_t * subdomain)
{
  self->subdomain = subdomain;
}
mal_boolean_t mal_entityrequest_get_allareas(mal_entityrequest_t * self)
{
  return self->allareas;
}
void mal_entityrequest_set_allareas(mal_entityrequest_t * self, mal_boolean_t allareas)
{
  self->allareas = allareas;
}
mal_boolean_t mal_entityrequest_get_allservices(mal_entityrequest_t * self)
{
  return self->allservices;
}
void mal_entityrequest_set_allservices(mal_entityrequest_t * self, mal_boolean_t allservices)
{
  self->allservices = allservices;
}
mal_boolean_t mal_entityrequest_get_alloperations(mal_entityrequest_t * self)
{
  return self->alloperations;
}
void mal_entityrequest_set_alloperations(mal_entityrequest_t * self, mal_boolean_t alloperations)
{
  self->alloperations = alloperations;
}
mal_boolean_t mal_entityrequest_get_onlyonchange(mal_entityrequest_t * self)
{
  return self->onlyonchange;
}
void mal_entityrequest_set_onlyonchange(mal_entityrequest_t * self, mal_boolean_t onlyonchange)
{
  self->onlyonchange = onlyonchange;
}
mal_entitykey_list_t * mal_entityrequest_get_entitykeys(mal_entityrequest_t * self)
{
  return self->entitykeys;
}
void mal_entityrequest_set_entitykeys(mal_entityrequest_t * self, mal_entitykey_list_t * entitykeys)
{
  self->entitykeys = entitykeys;
}

// default constructor
mal_entityrequest_t * mal_entityrequest_new(void)
{
  mal_entityrequest_t *self = (mal_entityrequest_t *) calloc(1, sizeof(mal_entityrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mal_entityrequest_add_encoding_length_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(mal_encoder, cursor, (self->subdomain != NULL));
  if (rc < 0)
    return rc;
  if ((self->subdomain != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->subdomain, mal_encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_boolean_encoding_length(mal_encoder, self->allareas, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(mal_encoder, self->allservices, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(mal_encoder, self->alloperations, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(mal_encoder, self->onlyonchange, cursor);
  if (rc < 0)
    return rc;
  rc = mal_entitykey_list_add_encoding_length_malbinary(self->entitykeys, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_entityrequest_encode_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->subdomain != NULL);
  rc = mal_encoder_encode_presence_flag(mal_encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->subdomain, mal_encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_boolean(mal_encoder, cursor, self->allareas);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(mal_encoder, cursor, self->allservices);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(mal_encoder, cursor, self->alloperations);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(mal_encoder, cursor, self->onlyonchange);
  if (rc < 0)
    return rc;
  rc = mal_entitykey_list_encode_malbinary(self->entitykeys, mal_encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mal_entityrequest_decode_malbinary(mal_entityrequest_t * self, mal_decoder_t * mal_decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(mal_decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->subdomain = mal_identifier_list_new(0);
    if (self->subdomain == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->subdomain, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->subdomain = NULL;
  }
  rc = mal_decoder_decode_boolean(mal_decoder, cursor, &self->allareas);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(mal_decoder, cursor, &self->allservices);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(mal_decoder, cursor, &self->alloperations);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(mal_decoder, cursor, &self->onlyonchange);
  if (rc < 0)
    return rc;
  self->entitykeys = mal_entitykey_list_new(0);
  if (self->entitykeys == NULL) return -1;
  rc = mal_entitykey_list_decode_malbinary(self->entitykeys, mal_decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mal_entityrequest_destroy(mal_entityrequest_t ** self_p)
{
  if ((*self_p)->subdomain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->subdomain);
  }
  if ((*self_p)->entitykeys != NULL)
  {
    mal_entitykey_list_destroy(& (*self_p)->entitykeys);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mal_entityrequest_test(bool verbose)
{
  printf(" * MAL:EntityRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
