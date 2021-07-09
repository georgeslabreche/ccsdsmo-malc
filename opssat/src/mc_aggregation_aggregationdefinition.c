#include "mc.h"


// structure definition for composite mc_aggregation_aggregationdefinition
struct _mc_aggregation_aggregationdefinition_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mc_aggregation_aggregationcategory_t f_category;
  mal_boolean_t f_generationenabled;
  mal_duration_t f_updateinterval;
  mal_boolean_t f_filterenabled;
  mal_duration_t f_filteredtimeout;
  mc_aggregation_aggregationreference_list_t * f_parametersets;
};

// fields accessors for composite mc_aggregation_aggregationdefinition
mal_identifier_t * mc_aggregation_aggregationdefinition_get_name(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_name;
}
void mc_aggregation_aggregationdefinition_set_name(mc_aggregation_aggregationdefinition_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * mc_aggregation_aggregationdefinition_get_description(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_description;
}
void mc_aggregation_aggregationdefinition_set_description(mc_aggregation_aggregationdefinition_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_aggregation_aggregationcategory_t mc_aggregation_aggregationdefinition_get_category(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_category;
}
void mc_aggregation_aggregationdefinition_set_category(mc_aggregation_aggregationdefinition_t * self, mc_aggregation_aggregationcategory_t f_category)
{
  self->f_category = f_category;
}
mal_boolean_t mc_aggregation_aggregationdefinition_get_generationenabled(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_generationenabled;
}
void mc_aggregation_aggregationdefinition_set_generationenabled(mc_aggregation_aggregationdefinition_t * self, mal_boolean_t f_generationenabled)
{
  self->f_generationenabled = f_generationenabled;
}
mal_duration_t mc_aggregation_aggregationdefinition_get_updateinterval(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_updateinterval;
}
void mc_aggregation_aggregationdefinition_set_updateinterval(mc_aggregation_aggregationdefinition_t * self, mal_duration_t f_updateinterval)
{
  self->f_updateinterval = f_updateinterval;
}
mal_boolean_t mc_aggregation_aggregationdefinition_get_filterenabled(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_filterenabled;
}
void mc_aggregation_aggregationdefinition_set_filterenabled(mc_aggregation_aggregationdefinition_t * self, mal_boolean_t f_filterenabled)
{
  self->f_filterenabled = f_filterenabled;
}
mal_duration_t mc_aggregation_aggregationdefinition_get_filteredtimeout(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_filteredtimeout;
}
void mc_aggregation_aggregationdefinition_set_filteredtimeout(mc_aggregation_aggregationdefinition_t * self, mal_duration_t f_filteredtimeout)
{
  self->f_filteredtimeout = f_filteredtimeout;
}
mc_aggregation_aggregationreference_list_t * mc_aggregation_aggregationdefinition_get_parametersets(mc_aggregation_aggregationdefinition_t * self)
{
  return self->f_parametersets;
}
void mc_aggregation_aggregationdefinition_set_parametersets(mc_aggregation_aggregationdefinition_t * self, mc_aggregation_aggregationreference_list_t * f_parametersets)
{
  self->f_parametersets = f_parametersets;
}

// default constructor
mc_aggregation_aggregationdefinition_t * mc_aggregation_aggregationdefinition_new(void)
{
  mc_aggregation_aggregationdefinition_t *self = (mc_aggregation_aggregationdefinition_t *) calloc(1, sizeof(mc_aggregation_aggregationdefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationdefinition_add_encoding_length_malbinary(mc_aggregation_aggregationdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_category, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_generationenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_updateinterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_filterenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_filteredtimeout, cursor);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationreference_list_add_encoding_length_malbinary(self->f_parametersets, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationdefinition_encode_malbinary(mc_aggregation_aggregationdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_updateinterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_filterenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_filteredtimeout);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationreference_list_encode_malbinary(self->f_parametersets, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationdefinition_decode_malbinary(mc_aggregation_aggregationdefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_category = (mc_aggregation_aggregationcategory_t) enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_updateinterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_filterenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_filteredtimeout);
  if (rc < 0)
    return rc;
  self->f_parametersets = mc_aggregation_aggregationreference_list_new(0);
  if (self->f_parametersets == NULL) return -1;
  rc = mc_aggregation_aggregationreference_list_decode_malbinary(self->f_parametersets, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationdefinition_destroy(mc_aggregation_aggregationdefinition_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_parametersets != NULL)
  {
    mc_aggregation_aggregationreference_list_destroy(& (*self_p)->f_parametersets);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationdefinition_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
