#include "mc.h"


// structure definition for composite mc_aggregation_aggregationparametervalue
struct _mc_aggregation_aggregationparametervalue_t {
  mc_parameter_parametervalue_t * f_value;
  bool f_paramdefinstid_is_present;
  mal_long_t f_paramdefinstid;
};

// fields accessors for composite mc_aggregation_aggregationparametervalue
mc_parameter_parametervalue_t * mc_aggregation_aggregationparametervalue_get_value(mc_aggregation_aggregationparametervalue_t * self)
{
  return self->f_value;
}
void mc_aggregation_aggregationparametervalue_set_value(mc_aggregation_aggregationparametervalue_t * self, mc_parameter_parametervalue_t * f_value)
{
  self->f_value = f_value;
}
bool mc_aggregation_aggregationparametervalue_paramdefinstid_is_present(mc_aggregation_aggregationparametervalue_t * self)
{
  return self->f_paramdefinstid_is_present;
}
void mc_aggregation_aggregationparametervalue_paramdefinstid_set_present(mc_aggregation_aggregationparametervalue_t * self, bool is_present)
{
  self->f_paramdefinstid_is_present = is_present;
}
mal_long_t mc_aggregation_aggregationparametervalue_get_paramdefinstid(mc_aggregation_aggregationparametervalue_t * self)
{
  return self->f_paramdefinstid;
}
void mc_aggregation_aggregationparametervalue_set_paramdefinstid(mc_aggregation_aggregationparametervalue_t * self, mal_long_t f_paramdefinstid)
{
  self->f_paramdefinstid = f_paramdefinstid;
}

// default constructor
mc_aggregation_aggregationparametervalue_t * mc_aggregation_aggregationparametervalue_new(void)
{
  mc_aggregation_aggregationparametervalue_t *self = (mc_aggregation_aggregationparametervalue_t *) calloc(1, sizeof(mc_aggregation_aggregationparametervalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationparametervalue_add_encoding_length_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mc_parameter_parametervalue_add_encoding_length_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_paramdefinstid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_paramdefinstid_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_paramdefinstid, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_aggregation_aggregationparametervalue_encode_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mc_parameter_parametervalue_encode_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = self->f_paramdefinstid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_paramdefinstid);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_aggregation_aggregationparametervalue_decode_malbinary(mc_aggregation_aggregationparametervalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  self->f_value = mc_parameter_parametervalue_new();
  if (self->f_value == NULL) return -1;
  rc = mc_parameter_parametervalue_decode_malbinary(self->f_value, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_paramdefinstid);
    if (rc < 0)
      return rc;
  }
  self->f_paramdefinstid_is_present = presence_flag;
  return rc;
}

// destructor
void mc_aggregation_aggregationparametervalue_destroy(mc_aggregation_aggregationparametervalue_t ** self_p)
{
  if ((*self_p)->f_value != NULL)
  {
    mc_parameter_parametervalue_destroy(& (*self_p)->f_value);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationparametervalue_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationParameterValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
