#include "pf.h"


// structure definition for composite pf_autonomousadcs_wheelsspeed
struct _pf_autonomousadcs_wheelsspeed_t {
  mal_float_list_t * f_rotationalspeed;
};

// fields accessors for composite pf_autonomousadcs_wheelsspeed
mal_float_list_t * pf_autonomousadcs_wheelsspeed_get_rotationalspeed(pf_autonomousadcs_wheelsspeed_t * self)
{
  return self->f_rotationalspeed;
}
void pf_autonomousadcs_wheelsspeed_set_rotationalspeed(pf_autonomousadcs_wheelsspeed_t * self, mal_float_list_t * f_rotationalspeed)
{
  self->f_rotationalspeed = f_rotationalspeed;
}

// default constructor
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_wheelsspeed_new(void)
{
  pf_autonomousadcs_wheelsspeed_t *self = (pf_autonomousadcs_wheelsspeed_t *) calloc(1, sizeof(pf_autonomousadcs_wheelsspeed_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_wheelsspeed_add_encoding_length_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_float_list_add_encoding_length_malbinary(self->f_rotationalspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_wheelsspeed_encode_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_float_list_encode_malbinary(self->f_rotationalspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_wheelsspeed_decode_malbinary(pf_autonomousadcs_wheelsspeed_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_rotationalspeed = mal_float_list_new(0);
  if (self->f_rotationalspeed == NULL) return -1;
  rc = mal_float_list_decode_malbinary(self->f_rotationalspeed, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_wheelsspeed_destroy(pf_autonomousadcs_wheelsspeed_t ** self_p)
{
  if ((*self_p)->f_rotationalspeed != NULL)
  {
    mal_float_list_destroy(& (*self_p)->f_rotationalspeed);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_wheelsspeed_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:WheelsSpeed: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
