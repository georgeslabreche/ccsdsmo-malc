#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudemodevectorpointing
struct _pf_autonomousadcs_attitudemodevectorpointing_t {
  pf_vectorf3d_t * f_target;
  mal_float_t f_margin;
};

// fields accessors for composite pf_autonomousadcs_attitudemodevectorpointing
pf_vectorf3d_t * pf_autonomousadcs_attitudemodevectorpointing_get_target(pf_autonomousadcs_attitudemodevectorpointing_t * self)
{
  return self->f_target;
}
void pf_autonomousadcs_attitudemodevectorpointing_set_target(pf_autonomousadcs_attitudemodevectorpointing_t * self, pf_vectorf3d_t * f_target)
{
  self->f_target = f_target;
}
mal_float_t pf_autonomousadcs_attitudemodevectorpointing_get_margin(pf_autonomousadcs_attitudemodevectorpointing_t * self)
{
  return self->f_margin;
}
void pf_autonomousadcs_attitudemodevectorpointing_set_margin(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_float_t f_margin)
{
  self->f_margin = f_margin;
}

// default constructor
pf_autonomousadcs_attitudemodevectorpointing_t * pf_autonomousadcs_attitudemodevectorpointing_new(void)
{
  pf_autonomousadcs_attitudemodevectorpointing_t *self = (pf_autonomousadcs_attitudemodevectorpointing_t *) calloc(1, sizeof(pf_autonomousadcs_attitudemodevectorpointing_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudemodevectorpointing_add_encoding_length_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_target, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_margin, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodevectorpointing_encode_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_vectorf3d_encode_malbinary(self->f_target, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_margin);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudemodevectorpointing_decode_malbinary(pf_autonomousadcs_attitudemodevectorpointing_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_target = pf_vectorf3d_new();
  if (self->f_target == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_target, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_margin);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudemodevectorpointing_destroy(pf_autonomousadcs_attitudemodevectorpointing_t ** self_p)
{
  if ((*self_p)->f_target != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_target);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudemodevectorpointing_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeModeVectorPointing: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
