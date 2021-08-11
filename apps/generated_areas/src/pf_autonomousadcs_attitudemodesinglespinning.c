#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudemodesinglespinning
struct _pf_autonomousadcs_attitudemodesinglespinning_t {
  pf_vectorf3d_t * f_bodyaxis;
  mal_float_t f_angularvelocity;
};

// fields accessors for composite pf_autonomousadcs_attitudemodesinglespinning
pf_vectorf3d_t * pf_autonomousadcs_attitudemodesinglespinning_get_bodyaxis(pf_autonomousadcs_attitudemodesinglespinning_t * self)
{
  return self->f_bodyaxis;
}
void pf_autonomousadcs_attitudemodesinglespinning_set_bodyaxis(pf_autonomousadcs_attitudemodesinglespinning_t * self, pf_vectorf3d_t * f_bodyaxis)
{
  self->f_bodyaxis = f_bodyaxis;
}
mal_float_t pf_autonomousadcs_attitudemodesinglespinning_get_angularvelocity(pf_autonomousadcs_attitudemodesinglespinning_t * self)
{
  return self->f_angularvelocity;
}
void pf_autonomousadcs_attitudemodesinglespinning_set_angularvelocity(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_float_t f_angularvelocity)
{
  self->f_angularvelocity = f_angularvelocity;
}

// default constructor
pf_autonomousadcs_attitudemodesinglespinning_t * pf_autonomousadcs_attitudemodesinglespinning_new(void)
{
  pf_autonomousadcs_attitudemodesinglespinning_t *self = (pf_autonomousadcs_attitudemodesinglespinning_t *) calloc(1, sizeof(pf_autonomousadcs_attitudemodesinglespinning_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodesinglespinning_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_bodyaxis, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_angularvelocity, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodesinglespinning_encode_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_vectorf3d_encode_malbinary(self->f_bodyaxis, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_angularvelocity);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodesinglespinning_decode_malbinary(pf_autonomousadcs_attitudemodesinglespinning_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_bodyaxis = pf_vectorf3d_new();
  if (self->f_bodyaxis == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_bodyaxis, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_angularvelocity);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudemodesinglespinning_destroy(pf_autonomousadcs_attitudemodesinglespinning_t ** self_p)
{
  if ((*self_p)->f_bodyaxis != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_bodyaxis);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudemodesinglespinning_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeModeSingleSpinning: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
