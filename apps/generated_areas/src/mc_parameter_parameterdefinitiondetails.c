#include "mc.h"


// structure definition for composite mc_parameter_parameterdefinitiondetails
struct _mc_parameter_parameterdefinitiondetails_t {
  mal_string_t * f_description;
  mal_octet_t f_rawtype;
  mal_string_t * f_rawunit;
  mal_boolean_t f_generationenabled;
  mal_duration_t f_reportinterval;
  mc_parameterexpression_t * f_validityexpression;
  mc_parameter_parameterconversion_t * f_conversion;
};

// fields accessors for composite mc_parameter_parameterdefinitiondetails
mal_string_t * mc_parameter_parameterdefinitiondetails_get_description(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_description;
}
void mc_parameter_parameterdefinitiondetails_set_description(mc_parameter_parameterdefinitiondetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mal_octet_t mc_parameter_parameterdefinitiondetails_get_rawtype(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_rawtype;
}
void mc_parameter_parameterdefinitiondetails_set_rawtype(mc_parameter_parameterdefinitiondetails_t * self, mal_octet_t f_rawtype)
{
  self->f_rawtype = f_rawtype;
}
mal_string_t * mc_parameter_parameterdefinitiondetails_get_rawunit(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_rawunit;
}
void mc_parameter_parameterdefinitiondetails_set_rawunit(mc_parameter_parameterdefinitiondetails_t * self, mal_string_t * f_rawunit)
{
  self->f_rawunit = f_rawunit;
}
mal_boolean_t mc_parameter_parameterdefinitiondetails_get_generationenabled(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_generationenabled;
}
void mc_parameter_parameterdefinitiondetails_set_generationenabled(mc_parameter_parameterdefinitiondetails_t * self, mal_boolean_t f_generationenabled)
{
  self->f_generationenabled = f_generationenabled;
}
mal_duration_t mc_parameter_parameterdefinitiondetails_get_reportinterval(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_reportinterval;
}
void mc_parameter_parameterdefinitiondetails_set_reportinterval(mc_parameter_parameterdefinitiondetails_t * self, mal_duration_t f_reportinterval)
{
  self->f_reportinterval = f_reportinterval;
}
mc_parameterexpression_t * mc_parameter_parameterdefinitiondetails_get_validityexpression(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_validityexpression;
}
void mc_parameter_parameterdefinitiondetails_set_validityexpression(mc_parameter_parameterdefinitiondetails_t * self, mc_parameterexpression_t * f_validityexpression)
{
  self->f_validityexpression = f_validityexpression;
}
mc_parameter_parameterconversion_t * mc_parameter_parameterdefinitiondetails_get_conversion(mc_parameter_parameterdefinitiondetails_t * self)
{
  return self->f_conversion;
}
void mc_parameter_parameterdefinitiondetails_set_conversion(mc_parameter_parameterdefinitiondetails_t * self, mc_parameter_parameterconversion_t * f_conversion)
{
  self->f_conversion = f_conversion;
}

// default constructor
mc_parameter_parameterdefinitiondetails_t * mc_parameter_parameterdefinitiondetails_new(void)
{
  mc_parameter_parameterdefinitiondetails_t *self = (mc_parameter_parameterdefinitiondetails_t *) calloc(1, sizeof(mc_parameter_parameterdefinitiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parameterdefinitiondetails_add_encoding_length_malbinary(mc_parameter_parameterdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_octet_encoding_length(encoder, self->f_rawtype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_rawunit != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_rawunit != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_rawunit, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_generationenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_reportinterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_validityexpression != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_validityexpression != NULL))
  {
    rc = mc_parameterexpression_add_encoding_length_malbinary(self->f_validityexpression, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_conversion != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_conversion != NULL))
  {
    rc = mc_parameter_parameterconversion_add_encoding_length_malbinary(self->f_conversion, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parameterdefinitiondetails_encode_malbinary(mc_parameter_parameterdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_octet(encoder, cursor, self->f_rawtype);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_rawunit != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_rawunit);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_reportinterval);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_validityexpression != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_parameterexpression_encode_malbinary(self->f_validityexpression, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_conversion != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_parameter_parameterconversion_encode_malbinary(self->f_conversion, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parameterdefinitiondetails_decode_malbinary(mc_parameter_parameterdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_octet(decoder, cursor, &self->f_rawtype);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_rawunit);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_rawunit = NULL;
  }
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_reportinterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_validityexpression = mc_parameterexpression_new();
    if (self->f_validityexpression == NULL) return -1;
    rc = mc_parameterexpression_decode_malbinary(self->f_validityexpression, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_validityexpression = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_conversion = mc_parameter_parameterconversion_new();
    if (self->f_conversion == NULL) return -1;
    rc = mc_parameter_parameterconversion_decode_malbinary(self->f_conversion, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_conversion = NULL;
  }
  return rc;
}

// destructor
void mc_parameter_parameterdefinitiondetails_destroy(mc_parameter_parameterdefinitiondetails_t ** self_p)
{
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_rawunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_rawunit);
  }
  if ((*self_p)->f_validityexpression != NULL)
  {
    mc_parameterexpression_destroy(& (*self_p)->f_validityexpression);
  }
  if ((*self_p)->f_conversion != NULL)
  {
    mc_parameter_parameterconversion_destroy(& (*self_p)->f_conversion);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parameterdefinitiondetails_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterDefinitionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
