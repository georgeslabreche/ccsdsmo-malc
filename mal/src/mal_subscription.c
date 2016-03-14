#include "mal.h"

struct _mal_subscription_t {
  mal_identifier_t *subscriptionid;
  mal_entityrequest_list_t *entities;
};

mal_subscription_t *mal_subscription_new(void) {
  mal_subscription_t *self = (mal_subscription_t *) malloc(
      sizeof(mal_subscription_t));
  if (!self)
    return NULL;
  return self;
}

void mal_subscription_destroy(mal_subscription_t **self_p) {
  if (*self_p) {
    mal_subscription_t *self = *self_p;
    mal_identifier_destroy(&(self->subscriptionid));
    mal_entityrequest_list_destroy(&(self->entities));
    free(self);
    *self_p = NULL;
  }
}

int mal_subscription_add_encoding_length_malbinary(mal_subscription_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length) {
  int rc = 0;
  if (self == NULL) {
    rc = -1;
    return rc;
  }

  // Field 'subscriptionid' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder,
      encoding_length);
  if (self->subscriptionid != NULL) {
    rc = malbinary_encoder_add_identifier_encoding_length(encoder,
        self->subscriptionid, encoding_length);
    if (rc < 0)
      return rc;
  }

  // Field 'entities' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder,
      encoding_length);
  if (rc < 0)
    return rc;
  if (self->entities != NULL) {
    rc = mal_entityrequest_list_add_encoding_length_malbinary(self->entities,
        encoder, encoding_length);
    if (rc < 0)
      return rc;
  }
  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_subscription_encode_malbinary(mal_subscription_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;

  bool is_present = (self->subscriptionid != NULL);
  rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
      is_present);
  if (is_present) {
    rc = malbinary_encoder_encode_identifier(encoder, bytes, offset,
        self->subscriptionid);
    if (rc < 0)
      return rc;
  }

  is_present = (self->entities != NULL);
  rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
      is_present);
  if (is_present) {
    rc = mal_entityrequest_list_encode_malbinary(self->entities, encoder, bytes,
        offset);
    if (rc < 0)
      return rc;
  }

  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_subscription_decode_malbinary(mal_subscription_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  bool is_present;
  rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
      &is_present);
  if (rc < 0)
    return rc;
  if (is_present) {
    rc = malbinary_decoder_decode_identifier(decoder, bytes, offset,
        &(self->subscriptionid));
  }

  rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
      &is_present);
  if (rc < 0)
    return rc;
  if (is_present) {
    self->entities = mal_entityrequest_list_new(0);
    rc = mal_entityrequest_list_decode_malbinary(self->entities, decoder, bytes,
        offset);
  }

  return rc;
}

mal_identifier_t *mal_subscription_get_subscriptionid(mal_subscription_t *self) {
  return self->subscriptionid;
}

void mal_subscription_set_subscriptionid(mal_subscription_t *self,
    mal_identifier_t *subscriptionid) {
  self->subscriptionid = subscriptionid;
}

mal_entityrequest_list_t *mal_subscription_get_entities(
    mal_subscription_t *self) {
  return self->entities;
}

void mal_subscription_set_entities(mal_subscription_t *self,
    mal_entityrequest_list_t * entities) {
  self->entities = entities;
}

void mal_subscription_test(bool verbose) {
  printf(" * mal_subscription: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

