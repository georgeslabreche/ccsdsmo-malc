#include "pf.h"


// structure definition for composite pf_autonomousadcs_quaternion
struct _pf_autonomousadcs_quaternion_t {
  mal_float_t f_a;
  mal_float_t f_b;
  mal_float_t f_c;
  mal_float_t f_d;
};

// fields accessors for composite pf_autonomousadcs_quaternion
mal_float_t pf_autonomousadcs_quaternion_get_a(pf_autonomousadcs_quaternion_t * self)
{
  return self->f_a;
}
void pf_autonomousadcs_quaternion_set_a(pf_autonomousadcs_quaternion_t * self, mal_float_t f_a)
{
  self->f_a = f_a;
}
mal_float_t pf_autonomousadcs_quaternion_get_b(pf_autonomousadcs_quaternion_t * self)
{
  return self->f_b;
}
void pf_autonomousadcs_quaternion_set_b(pf_autonomousadcs_quaternion_t * self, mal_float_t f_b)
{
  self->f_b = f_b;
}
mal_float_t pf_autonomousadcs_quaternion_get_c(pf_autonomousadcs_quaternion_t * self)
{
  return self->f_c;
}
void pf_autonomousadcs_quaternion_set_c(pf_autonomousadcs_quaternion_t * self, mal_float_t f_c)
{
  self->f_c = f_c;
}
mal_float_t pf_autonomousadcs_quaternion_get_d(pf_autonomousadcs_quaternion_t * self)
{
  return self->f_d;
}
void pf_autonomousadcs_quaternion_set_d(pf_autonomousadcs_quaternion_t * self, mal_float_t f_d)
{
  self->f_d = f_d;
}

// default constructor
pf_autonomousadcs_quaternion_t * pf_autonomousadcs_quaternion_new(void)
{
  pf_autonomousadcs_quaternion_t *self = (pf_autonomousadcs_quaternion_t *) calloc(1, sizeof(pf_autonomousadcs_quaternion_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_quaternion_add_encoding_length_malbinary(pf_autonomousadcs_quaternion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_a, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_b, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_c, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_d, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_quaternion_encode_malbinary(pf_autonomousadcs_quaternion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_a);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_b);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_c);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_d);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_autonomousadcs_quaternion_decode_malbinary(pf_autonomousadcs_quaternion_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_a);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_b);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_c);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_d);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_autonomousadcs_quaternion_destroy(pf_autonomousadcs_quaternion_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_quaternion_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:Quaternion: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
