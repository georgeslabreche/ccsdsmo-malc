#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudemodetargettracking
struct _pf_autonomousadcs_attitudemodetargettracking_t {
  mal_float_t f_latitude;
  mal_float_t f_longitude;
};

// fields accessors for composite pf_autonomousadcs_attitudemodetargettracking
mal_float_t pf_autonomousadcs_attitudemodetargettracking_get_latitude(pf_autonomousadcs_attitudemodetargettracking_t * self)
{
  return self->f_latitude;
}
void pf_autonomousadcs_attitudemodetargettracking_set_latitude(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_float_t f_latitude)
{
  self->f_latitude = f_latitude;
}
mal_float_t pf_autonomousadcs_attitudemodetargettracking_get_longitude(pf_autonomousadcs_attitudemodetargettracking_t * self)
{
  return self->f_longitude;
}
void pf_autonomousadcs_attitudemodetargettracking_set_longitude(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_float_t f_longitude)
{
  self->f_longitude = f_longitude;
}

// default constructor
pf_autonomousadcs_attitudemodetargettracking_t * pf_autonomousadcs_attitudemodetargettracking_new(void)
{
  pf_autonomousadcs_attitudemodetargettracking_t *self = (pf_autonomousadcs_attitudemodetargettracking_t *) calloc(1, sizeof(pf_autonomousadcs_attitudemodetargettracking_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodetargettracking_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_latitude, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_longitude, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodetargettracking_encode_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_latitude);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_longitude);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodetargettracking_decode_malbinary(pf_autonomousadcs_attitudemodetargettracking_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_latitude);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_longitude);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudemodetargettracking_destroy(pf_autonomousadcs_attitudemodetargettracking_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudemodetargettracking_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeModeTargetTracking: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
