/*
 */

#include "mal.h"

struct _mal_entityrequest_t {
  mal_identifier_list_t *subdomain;
  //TODO: definition of the mal_entityrequest_t structure
};

mal_entityrequest_t *mal_entityrequest_new(void) {
  mal_entityrequest_t *self = (mal_entityrequest_t *) malloc(sizeof(mal_entityrequest_t));
  if (!self)
    return NULL;
  //TODO: initialization of the mal_entityrequest_t structure
  return self;
}

void mal_entityrequest_destroy(mal_entityrequest_t **self_p) {
  if (*self_p) {
    mal_entityrequest_t *self = *self_p;
    // TODO: garbage of the mal_entityrequest_t structure
    free(self);
    *self_p = NULL;
  }
}

int mal_entityrequest_add_encoding_length_malbinary(mal_entityrequest_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length) {
  int rc = 0;
  if (self == NULL) {
    rc = -1;
    return rc;
  }
  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entityrequest_encode_malbinary(mal_entityrequest_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entityrequest_decode_malbinary(mal_entityrequest_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  return rc;
}

void mal_entityrequest_test(bool verbose) {
  printf(" * mal_entityrequest: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

