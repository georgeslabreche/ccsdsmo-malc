#include "pf.h"


// structure definition for composite pf_autonomousadcs_attitudetelemetry
struct _pf_autonomousadcs_attitudetelemetry_t {
  pf_autonomousadcs_quaternion_t * f_attitude;
  pf_vectorf3d_t * f_angularvelocity;
  pf_vectorf3d_t * f_sunvector;
  pf_vectorf3d_t * f_magneticfield;
  mal_boolean_t f_statetarget;
};

// fields accessors for composite pf_autonomousadcs_attitudetelemetry
pf_autonomousadcs_quaternion_t * pf_autonomousadcs_attitudetelemetry_get_attitude(pf_autonomousadcs_attitudetelemetry_t * self)
{
  return self->f_attitude;
}
void pf_autonomousadcs_attitudetelemetry_set_attitude(pf_autonomousadcs_attitudetelemetry_t * self, pf_autonomousadcs_quaternion_t * f_attitude)
{
  self->f_attitude = f_attitude;
}
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_angularvelocity(pf_autonomousadcs_attitudetelemetry_t * self)
{
  return self->f_angularvelocity;
}
void pf_autonomousadcs_attitudetelemetry_set_angularvelocity(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_angularvelocity)
{
  self->f_angularvelocity = f_angularvelocity;
}
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_sunvector(pf_autonomousadcs_attitudetelemetry_t * self)
{
  return self->f_sunvector;
}
void pf_autonomousadcs_attitudetelemetry_set_sunvector(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_sunvector)
{
  self->f_sunvector = f_sunvector;
}
pf_vectorf3d_t * pf_autonomousadcs_attitudetelemetry_get_magneticfield(pf_autonomousadcs_attitudetelemetry_t * self)
{
  return self->f_magneticfield;
}
void pf_autonomousadcs_attitudetelemetry_set_magneticfield(pf_autonomousadcs_attitudetelemetry_t * self, pf_vectorf3d_t * f_magneticfield)
{
  self->f_magneticfield = f_magneticfield;
}
mal_boolean_t pf_autonomousadcs_attitudetelemetry_get_statetarget(pf_autonomousadcs_attitudetelemetry_t * self)
{
  return self->f_statetarget;
}
void pf_autonomousadcs_attitudetelemetry_set_statetarget(pf_autonomousadcs_attitudetelemetry_t * self, mal_boolean_t f_statetarget)
{
  self->f_statetarget = f_statetarget;
}

// default constructor
pf_autonomousadcs_attitudetelemetry_t * pf_autonomousadcs_attitudetelemetry_new(void)
{
  pf_autonomousadcs_attitudetelemetry_t *self = (pf_autonomousadcs_attitudetelemetry_t *) calloc(1, sizeof(pf_autonomousadcs_attitudetelemetry_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_attitudetelemetry_add_encoding_length_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_autonomousadcs_quaternion_add_encoding_length_malbinary(self->f_attitude, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_angularvelocity, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_sunvector, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_add_encoding_length_malbinary(self->f_magneticfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_statetarget, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudetelemetry_encode_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_autonomousadcs_quaternion_encode_malbinary(self->f_attitude, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_encode_malbinary(self->f_angularvelocity, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_encode_malbinary(self->f_sunvector, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = pf_vectorf3d_encode_malbinary(self->f_magneticfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_statetarget);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_attitudetelemetry_decode_malbinary(pf_autonomousadcs_attitudetelemetry_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_attitude = pf_autonomousadcs_quaternion_new();
  if (self->f_attitude == NULL) return -1;
  rc = pf_autonomousadcs_quaternion_decode_malbinary(self->f_attitude, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_angularvelocity = pf_vectorf3d_new();
  if (self->f_angularvelocity == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_angularvelocity, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_sunvector = pf_vectorf3d_new();
  if (self->f_sunvector == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_sunvector, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_magneticfield = pf_vectorf3d_new();
  if (self->f_magneticfield == NULL) return -1;
  rc = pf_vectorf3d_decode_malbinary(self->f_magneticfield, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_statetarget);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_attitudetelemetry_destroy(pf_autonomousadcs_attitudetelemetry_t ** self_p)
{
  if ((*self_p)->f_attitude != NULL)
  {
    pf_autonomousadcs_quaternion_destroy(& (*self_p)->f_attitude);
  }
  if ((*self_p)->f_angularvelocity != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_angularvelocity);
  }
  if ((*self_p)->f_sunvector != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_sunvector);
  }
  if ((*self_p)->f_magneticfield != NULL)
  {
    pf_vectorf3d_destroy(& (*self_p)->f_magneticfield);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_attitudetelemetry_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:AttitudeTelemetry: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
