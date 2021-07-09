#include "pf.h"


// structure definition for composite pf_autonomousadcs_actuatorstelemetry
struct _pf_autonomousadcs_actuatorstelemetry_t {
  pf_autonomousadcs_wheelsspeed_t * f_targetwheelspeed;
  pf_autonomousadcs_wheelsspeed_t * f_currentwheelspeed;
  pf_vectorf3d_t * f_mtqdipolemoment;
  pf_autonomousadcs_magnetorquersstate_t f_mtqstate;
};

// fields accessors for composite pf_autonomousadcs_actuatorstelemetry
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_actuatorstelemetry_get_targetwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self)
{
  return self->f_targetwheelspeed;
}
void pf_autonomousadcs_actuatorstelemetry_set_targetwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_wheelsspeed_t * f_targetwheelspeed)
{
  self->f_targetwheelspeed = f_targetwheelspeed;
}
pf_autonomousadcs_wheelsspeed_t * pf_autonomousadcs_actuatorstelemetry_get_currentwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self)
{
  return self->f_currentwheelspeed;
}
void pf_autonomousadcs_actuatorstelemetry_set_currentwheelspeed(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_wheelsspeed_t * f_currentwheelspeed)
{
  self->f_currentwheelspeed = f_currentwheelspeed;
}
pf_vectorf3d_t * pf_autonomousadcs_actuatorstelemetry_get_mtqdipolemoment(pf_autonomousadcs_actuatorstelemetry_t * self)
{
  return self->f_mtqdipolemoment;
}
void pf_autonomousadcs_actuatorstelemetry_set_mtqdipolemoment(pf_autonomousadcs_actuatorstelemetry_t * self, pf_vectorf3d_t * f_mtqdipolemoment)
{
  self->f_mtqdipolemoment = f_mtqdipolemoment;
}
pf_autonomousadcs_magnetorquersstate_t pf_autonomousadcs_actuatorstelemetry_get_mtqstate(pf_autonomousadcs_actuatorstelemetry_t * self)
{
  return self->f_mtqstate;
}
void pf_autonomousadcs_actuatorstelemetry_set_mtqstate(pf_autonomousadcs_actuatorstelemetry_t * self, pf_autonomousadcs_magnetorquersstate_t f_mtqstate)
{
  self->f_mtqstate = f_mtqstate;
}

// default constructor
pf_autonomousadcs_actuatorstelemetry_t * pf_autonomousadcs_actuatorstelemetry_new(void)
{
  pf_autonomousadcs_actuatorstelemetry_t *self = (pf_autonomousadcs_actuatorstelemetry_t *) calloc(1, sizeof(pf_autonomousadcs_actuatorstelemetry_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_actuatorstelemetry_add_encoding_length_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_autonomousadcs_wheelsspeed_add_encoding_length_malbinary(self->f_targetwheelspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_autonomousadcs_wheelsspeed_add_encoding_length_malbinary(self->f_currentwheelspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_mtqdipolemoment, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_mtqstate, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_actuatorstelemetry_encode_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_autonomousadcs_wheelsspeed_encode_malbinary(self->f_targetwheelspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_autonomousadcs_wheelsspeed_encode_malbinary(self->f_currentwheelspeed, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_encode_malbinary(self->f_mtqdipolemoment, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_mtqstate);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_actuatorstelemetry_decode_malbinary(pf_autonomousadcs_actuatorstelemetry_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  self->f_targetwheelspeed = pf_autonomousadcs_wheelsspeed_new();
  if (self->f_targetwheelspeed == NULL) return -1;
  rc = pf_autonomousadcs_wheelsspeed_decode_malbinary(self->f_targetwheelspeed, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_currentwheelspeed = pf_autonomousadcs_wheelsspeed_new();
  if (self->f_currentwheelspeed == NULL) return -1;
  rc = pf_autonomousadcs_wheelsspeed_decode_malbinary(self->f_currentwheelspeed, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_mtqdipolemoment = pf_vectorf3d_new();
  if (self->f_mtqdipolemoment == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_mtqdipolemoment, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_mtqstate = (pf_autonomousadcs_magnetorquersstate_t) enumerated_value;
  return rc;
}

// destructor
void pf_autonomousadcs_actuatorstelemetry_destroy(pf_autonomousadcs_actuatorstelemetry_t ** self_p)
{
  if ((*self_p)->f_targetwheelspeed != NULL)
  {
    pf_autonomousadcs_wheelsspeed_destroy(& (*self_p)->f_targetwheelspeed);
  }
  if ((*self_p)->f_currentwheelspeed != NULL)
  {
    pf_autonomousadcs_wheelsspeed_destroy(& (*self_p)->f_currentwheelspeed);
  }
  if ((*self_p)->f_mtqdipolemoment != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_mtqdipolemoment);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_actuatorstelemetry_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:ActuatorsTelemetry: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
