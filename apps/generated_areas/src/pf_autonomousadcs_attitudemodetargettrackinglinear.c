#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudemodetargettrackinglinear
struct _pf_autonomousadcs_attitudemodetargettrackinglinear_t {
  mal_float_t f_latitudestart;
  mal_float_t f_longitudestart;
  mal_float_t f_latitudeend;
  mal_float_t f_longitudeend;
  mal_long_t f_startepoch;
  mal_long_t f_endepoch;
};

// fields accessors for composite pf_autonomousadcs_attitudemodetargettrackinglinear
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_latitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_latitudestart;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_latitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_latitudestart)
{
  self->f_latitudestart = f_latitudestart;
}
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_longitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_longitudestart;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_longitudestart(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_longitudestart)
{
  self->f_longitudestart = f_longitudestart;
}
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_latitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_latitudeend;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_latitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_latitudeend)
{
  self->f_latitudeend = f_latitudeend;
}
mal_float_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_longitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_longitudeend;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_longitudeend(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_float_t f_longitudeend)
{
  self->f_longitudeend = f_longitudeend;
}
mal_long_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_startepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_startepoch;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_startepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_long_t f_startepoch)
{
  self->f_startepoch = f_startepoch;
}
mal_long_t pf_autonomousadcs_attitudemodetargettrackinglinear_get_endepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self)
{
  return self->f_endepoch;
}
void pf_autonomousadcs_attitudemodetargettrackinglinear_set_endepoch(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_long_t f_endepoch)
{
  self->f_endepoch = f_endepoch;
}

// default constructor
pf_autonomousadcs_attitudemodetargettrackinglinear_t * pf_autonomousadcs_attitudemodetargettrackinglinear_new(void)
{
  pf_autonomousadcs_attitudemodetargettrackinglinear_t *self = (pf_autonomousadcs_attitudemodetargettrackinglinear_t *) calloc(1, sizeof(pf_autonomousadcs_attitudemodetargettrackinglinear_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodetargettrackinglinear_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_latitudestart, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_longitudestart, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_latitudeend, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_longitudeend, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_startepoch, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_endepoch, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodetargettrackinglinear_encode_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_latitudestart);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_longitudestart);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_latitudeend);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_longitudeend);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_startepoch);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_endepoch);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodetargettrackinglinear_decode_malbinary(pf_autonomousadcs_attitudemodetargettrackinglinear_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_latitudestart);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_longitudestart);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_latitudeend);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_longitudeend);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_startepoch);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_endepoch);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudemodetargettrackinglinear_destroy(pf_autonomousadcs_attitudemodetargettrackinglinear_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudemodetargettrackinglinear_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeModeTargetTrackingLinear: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
