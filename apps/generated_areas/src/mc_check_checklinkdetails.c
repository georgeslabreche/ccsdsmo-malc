#include "mc.h"


// structure definition for composite mc_check_checklinkdetails
struct _mc_check_checklinkdetails_t {
  mal_boolean_t f_checkenabled;
  mal_boolean_t f_checkonchange;
  mal_boolean_t f_useconverted;
  mal_duration_t f_checkinterval;
  mc_parameterexpression_t * f_condition;
};

// fields accessors for composite mc_check_checklinkdetails
mal_boolean_t mc_check_checklinkdetails_get_checkenabled(mc_check_checklinkdetails_t * self)
{
  return self->f_checkenabled;
}
void mc_check_checklinkdetails_set_checkenabled(mc_check_checklinkdetails_t * self, mal_boolean_t f_checkenabled)
{
  self->f_checkenabled = f_checkenabled;
}
mal_boolean_t mc_check_checklinkdetails_get_checkonchange(mc_check_checklinkdetails_t * self)
{
  return self->f_checkonchange;
}
void mc_check_checklinkdetails_set_checkonchange(mc_check_checklinkdetails_t * self, mal_boolean_t f_checkonchange)
{
  self->f_checkonchange = f_checkonchange;
}
mal_boolean_t mc_check_checklinkdetails_get_useconverted(mc_check_checklinkdetails_t * self)
{
  return self->f_useconverted;
}
void mc_check_checklinkdetails_set_useconverted(mc_check_checklinkdetails_t * self, mal_boolean_t f_useconverted)
{
  self->f_useconverted = f_useconverted;
}
mal_duration_t mc_check_checklinkdetails_get_checkinterval(mc_check_checklinkdetails_t * self)
{
  return self->f_checkinterval;
}
void mc_check_checklinkdetails_set_checkinterval(mc_check_checklinkdetails_t * self, mal_duration_t f_checkinterval)
{
  self->f_checkinterval = f_checkinterval;
}
mc_parameterexpression_t * mc_check_checklinkdetails_get_condition(mc_check_checklinkdetails_t * self)
{
  return self->f_condition;
}
void mc_check_checklinkdetails_set_condition(mc_check_checklinkdetails_t * self, mc_parameterexpression_t * f_condition)
{
  self->f_condition = f_condition;
}

// default constructor
mc_check_checklinkdetails_t * mc_check_checklinkdetails_new(void)
{
  mc_check_checklinkdetails_t *self = (mc_check_checklinkdetails_t *) calloc(1, sizeof(mc_check_checklinkdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checklinkdetails_add_encoding_length_malbinary(mc_check_checklinkdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_checkenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_checkonchange, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_useconverted, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_checkinterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_condition != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_condition != NULL))
  {
    rc = mc_parameterexpression_add_encoding_length_malbinary(self->f_condition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checklinkdetails_encode_malbinary(mc_check_checklinkdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_checkenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_checkonchange);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_useconverted);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_checkinterval);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_condition != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_parameterexpression_encode_malbinary(self->f_condition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checklinkdetails_decode_malbinary(mc_check_checklinkdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_checkenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_checkonchange);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_useconverted);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_checkinterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_condition = mc_parameterexpression_new();
    if (self->f_condition == NULL) return -1;
    rc = mc_parameterexpression_decode_malbinary(self->f_condition, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_condition = NULL;
  }
  return rc;
}

// destructor
void mc_check_checklinkdetails_destroy(mc_check_checklinkdetails_t ** self_p)
{
  if ((*self_p)->f_condition != NULL)
  {
    mc_parameterexpression_destroy(& (*self_p)->f_condition);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checklinkdetails_test(bool verbose)
{
  printf(" * MC:Check:CheckLinkDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
