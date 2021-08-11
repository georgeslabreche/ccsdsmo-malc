#include "pf.h"


// structure definition for composite pf_autonomousadcs_reactionwheelparameters
struct _pf_autonomousadcs_reactionwheelparameters_t {
  mal_integer_t f_controlmode;
  mal_float_t f_maxspeed;
  mal_float_t f_maxtorque;
  mal_float_t f_inertia;
  bool f_motorconst_is_present;
  mal_float_t f_motorconst;
};

// fields accessors for composite pf_autonomousadcs_reactionwheelparameters
mal_integer_t pf_autonomousadcs_reactionwheelparameters_get_controlmode(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_controlmode;
}
void pf_autonomousadcs_reactionwheelparameters_set_controlmode(pf_autonomousadcs_reactionwheelparameters_t * self, mal_integer_t f_controlmode)
{
  self->f_controlmode = f_controlmode;
}
mal_float_t pf_autonomousadcs_reactionwheelparameters_get_maxspeed(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_maxspeed;
}
void pf_autonomousadcs_reactionwheelparameters_set_maxspeed(pf_autonomousadcs_reactionwheelparameters_t * self, mal_float_t f_maxspeed)
{
  self->f_maxspeed = f_maxspeed;
}
mal_float_t pf_autonomousadcs_reactionwheelparameters_get_maxtorque(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_maxtorque;
}
void pf_autonomousadcs_reactionwheelparameters_set_maxtorque(pf_autonomousadcs_reactionwheelparameters_t * self, mal_float_t f_maxtorque)
{
  self->f_maxtorque = f_maxtorque;
}
mal_float_t pf_autonomousadcs_reactionwheelparameters_get_inertia(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_inertia;
}
void pf_autonomousadcs_reactionwheelparameters_set_inertia(pf_autonomousadcs_reactionwheelparameters_t * self, mal_float_t f_inertia)
{
  self->f_inertia = f_inertia;
}
bool pf_autonomousadcs_reactionwheelparameters_motorconst_is_present(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_motorconst_is_present;
}
void pf_autonomousadcs_reactionwheelparameters_motorconst_set_present(pf_autonomousadcs_reactionwheelparameters_t * self, bool is_present)
{
  self->f_motorconst_is_present = is_present;
}
mal_float_t pf_autonomousadcs_reactionwheelparameters_get_motorconst(pf_autonomousadcs_reactionwheelparameters_t * self)
{
  return self->f_motorconst;
}
void pf_autonomousadcs_reactionwheelparameters_set_motorconst(pf_autonomousadcs_reactionwheelparameters_t * self, mal_float_t f_motorconst)
{
  self->f_motorconst = f_motorconst;
}

// default constructor
pf_autonomousadcs_reactionwheelparameters_t * pf_autonomousadcs_reactionwheelparameters_new(void)
{
  pf_autonomousadcs_reactionwheelparameters_t *self = (pf_autonomousadcs_reactionwheelparameters_t *) calloc(1, sizeof(pf_autonomousadcs_reactionwheelparameters_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_autonomousadcs_reactionwheelparameters_add_encoding_length_malbinary(pf_autonomousadcs_reactionwheelparameters_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_integer_encoding_length(encoder, self->f_controlmode, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_maxspeed, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_maxtorque, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_inertia, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_motorconst_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_motorconst_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_motorconst, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_autonomousadcs_reactionwheelparameters_encode_malbinary(pf_autonomousadcs_reactionwheelparameters_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_integer(encoder, cursor, self->f_controlmode);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_maxspeed);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_maxtorque);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_inertia);
  if (rc < 0)
    return rc;
  presence_flag = self->f_motorconst_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_motorconst);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_autonomousadcs_reactionwheelparameters_decode_malbinary(pf_autonomousadcs_reactionwheelparameters_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_integer(decoder, cursor, &self->f_controlmode);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_maxspeed);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_maxtorque);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_inertia);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_motorconst);
    if (rc < 0)
      return rc;
  }
  self->f_motorconst_is_present = presence_flag;
  return rc;
}

// destructor
void pf_autonomousadcs_reactionwheelparameters_destroy(pf_autonomousadcs_reactionwheelparameters_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_autonomousadcs_reactionwheelparameters_test(bool verbose)
{
  printf(" * PF:AutonomousADCS:ReactionWheelParameters: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
