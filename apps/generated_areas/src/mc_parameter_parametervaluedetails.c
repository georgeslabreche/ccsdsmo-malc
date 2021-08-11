#include "mc.h"


// structure definition for composite mc_parameter_parametervaluedetails
struct _mc_parameter_parametervaluedetails_t {
  mal_long_t f_paramid;
  mal_long_t f_defid;
  mal_time_t f_timestamp;
  mc_parameter_parametervalue_t * f_value;
};

// fields accessors for composite mc_parameter_parametervaluedetails
mal_long_t mc_parameter_parametervaluedetails_get_paramid(mc_parameter_parametervaluedetails_t * self)
{
  return self->f_paramid;
}
void mc_parameter_parametervaluedetails_set_paramid(mc_parameter_parametervaluedetails_t * self, mal_long_t f_paramid)
{
  self->f_paramid = f_paramid;
}
mal_long_t mc_parameter_parametervaluedetails_get_defid(mc_parameter_parametervaluedetails_t * self)
{
  return self->f_defid;
}
void mc_parameter_parametervaluedetails_set_defid(mc_parameter_parametervaluedetails_t * self, mal_long_t f_defid)
{
  self->f_defid = f_defid;
}
mal_time_t mc_parameter_parametervaluedetails_get_timestamp(mc_parameter_parametervaluedetails_t * self)
{
  return self->f_timestamp;
}
void mc_parameter_parametervaluedetails_set_timestamp(mc_parameter_parametervaluedetails_t * self, mal_time_t f_timestamp)
{
  self->f_timestamp = f_timestamp;
}
mc_parameter_parametervalue_t * mc_parameter_parametervaluedetails_get_value(mc_parameter_parametervaluedetails_t * self)
{
  return self->f_value;
}
void mc_parameter_parametervaluedetails_set_value(mc_parameter_parametervaluedetails_t * self, mc_parameter_parametervalue_t * f_value)
{
  self->f_value = f_value;
}

// default constructor
mc_parameter_parametervaluedetails_t * mc_parameter_parametervaluedetails_new(void)
{
  mc_parameter_parametervaluedetails_t *self = (mc_parameter_parametervaluedetails_t *) calloc(1, sizeof(mc_parameter_parametervaluedetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parametervaluedetails_add_encoding_length_malbinary(mc_parameter_parametervaluedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_paramid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_defid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_time_encoding_length(encoder, self->f_timestamp, cursor);
  if (rc < 0)
    return rc;
  rc = mc_parameter_parametervalue_add_encoding_length_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parametervaluedetails_encode_malbinary(mc_parameter_parametervaluedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_paramid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_defid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_time(encoder, cursor, self->f_timestamp);
  if (rc < 0)
    return rc;
  rc = mc_parameter_parametervalue_encode_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parametervaluedetails_decode_malbinary(mc_parameter_parametervaluedetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_paramid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_defid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_time(decoder, cursor, &self->f_timestamp);
  if (rc < 0)
    return rc;
  self->f_value = mc_parameter_parametervalue_new();
  if (self->f_value == NULL) return -1;
  rc = mc_parameter_parametervalue_decode_malbinary(self->f_value, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_parameter_parametervaluedetails_destroy(mc_parameter_parametervaluedetails_t ** self_p)
{
  if ((*self_p)->f_value != NULL)
  {
    mc_parameter_parametervalue_destroy(& (*self_p)->f_value);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parametervaluedetails_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterValueDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
