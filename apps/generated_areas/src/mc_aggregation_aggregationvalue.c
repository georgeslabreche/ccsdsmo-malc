#include "mc.h"


// structure definition for composite mc_aggregation_aggregationvalue
struct _mc_aggregation_aggregationvalue_t {
  mc_aggregation_generationmode_t f_generationmode;
  mal_boolean_t f_filtered;
  mc_aggregation_aggregationsetvalue_list_t * f_parametersetvalues;
};

// fields accessors for composite mc_aggregation_aggregationvalue
mc_aggregation_generationmode_t mc_aggregation_aggregationvalue_get_generationmode(mc_aggregation_aggregationvalue_t * self)
{
  return self->f_generationmode;
}
void mc_aggregation_aggregationvalue_set_generationmode(mc_aggregation_aggregationvalue_t * self, mc_aggregation_generationmode_t f_generationmode)
{
  self->f_generationmode = f_generationmode;
}
mal_boolean_t mc_aggregation_aggregationvalue_get_filtered(mc_aggregation_aggregationvalue_t * self)
{
  return self->f_filtered;
}
void mc_aggregation_aggregationvalue_set_filtered(mc_aggregation_aggregationvalue_t * self, mal_boolean_t f_filtered)
{
  self->f_filtered = f_filtered;
}
mc_aggregation_aggregationsetvalue_list_t * mc_aggregation_aggregationvalue_get_parametersetvalues(mc_aggregation_aggregationvalue_t * self)
{
  return self->f_parametersetvalues;
}
void mc_aggregation_aggregationvalue_set_parametersetvalues(mc_aggregation_aggregationvalue_t * self, mc_aggregation_aggregationsetvalue_list_t * f_parametersetvalues)
{
  self->f_parametersetvalues = f_parametersetvalues;
}

// default constructor
mc_aggregation_aggregationvalue_t * mc_aggregation_aggregationvalue_new(void)
{
  mc_aggregation_aggregationvalue_t *self = (mc_aggregation_aggregationvalue_t *) calloc(1, sizeof(mc_aggregation_aggregationvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationvalue_add_encoding_length_malbinary(mc_aggregation_aggregationvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_generationmode, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_filtered, cursor);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationsetvalue_list_add_encoding_length_malbinary(self->f_parametersetvalues, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationvalue_encode_malbinary(mc_aggregation_aggregationvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_generationmode);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_filtered);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationsetvalue_list_encode_malbinary(self->f_parametersetvalues, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationvalue_decode_malbinary(mc_aggregation_aggregationvalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_generationmode = (mc_aggregation_generationmode_t) enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_filtered);
  if (rc < 0)
    return rc;
  self->f_parametersetvalues = mc_aggregation_aggregationsetvalue_list_new(0);
  if (self->f_parametersetvalues == NULL) return -1;
  rc = mc_aggregation_aggregationsetvalue_list_decode_malbinary(self->f_parametersetvalues, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationvalue_destroy(mc_aggregation_aggregationvalue_t ** self_p)
{
  if ((*self_p)->f_parametersetvalues != NULL)
  {
    mc_aggregation_aggregationsetvalue_list_destroy(& (*self_p)->f_parametersetvalues);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationvalue_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
