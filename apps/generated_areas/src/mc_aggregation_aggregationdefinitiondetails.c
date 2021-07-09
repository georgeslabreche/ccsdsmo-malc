#include "mc.h"


// structure definition for composite mc_aggregation_aggregationdefinitiondetails
struct _mc_aggregation_aggregationdefinitiondetails_t {
  mal_string_t * f_description;
  mal_uoctet_t f_category;
  mal_duration_t f_reportinterval;
  mal_boolean_t f_sendunchanged;
  mal_boolean_t f_senddefinitions;
  mal_boolean_t f_filterenabled;
  mal_duration_t f_filteredtimeout;
  mal_boolean_t f_generationenabled;
  mc_aggregation_aggregationparameterset_list_t * f_parametersets;
};

// fields accessors for composite mc_aggregation_aggregationdefinitiondetails
mal_string_t * mc_aggregation_aggregationdefinitiondetails_get_description(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_description;
}
void mc_aggregation_aggregationdefinitiondetails_set_description(mc_aggregation_aggregationdefinitiondetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mal_uoctet_t mc_aggregation_aggregationdefinitiondetails_get_category(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_category;
}
void mc_aggregation_aggregationdefinitiondetails_set_category(mc_aggregation_aggregationdefinitiondetails_t * self, mal_uoctet_t f_category)
{
  self->f_category = f_category;
}
mal_duration_t mc_aggregation_aggregationdefinitiondetails_get_reportinterval(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_reportinterval;
}
void mc_aggregation_aggregationdefinitiondetails_set_reportinterval(mc_aggregation_aggregationdefinitiondetails_t * self, mal_duration_t f_reportinterval)
{
  self->f_reportinterval = f_reportinterval;
}
mal_boolean_t mc_aggregation_aggregationdefinitiondetails_get_sendunchanged(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_sendunchanged;
}
void mc_aggregation_aggregationdefinitiondetails_set_sendunchanged(mc_aggregation_aggregationdefinitiondetails_t * self, mal_boolean_t f_sendunchanged)
{
  self->f_sendunchanged = f_sendunchanged;
}
mal_boolean_t mc_aggregation_aggregationdefinitiondetails_get_senddefinitions(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_senddefinitions;
}
void mc_aggregation_aggregationdefinitiondetails_set_senddefinitions(mc_aggregation_aggregationdefinitiondetails_t * self, mal_boolean_t f_senddefinitions)
{
  self->f_senddefinitions = f_senddefinitions;
}
mal_boolean_t mc_aggregation_aggregationdefinitiondetails_get_filterenabled(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_filterenabled;
}
void mc_aggregation_aggregationdefinitiondetails_set_filterenabled(mc_aggregation_aggregationdefinitiondetails_t * self, mal_boolean_t f_filterenabled)
{
  self->f_filterenabled = f_filterenabled;
}
mal_duration_t mc_aggregation_aggregationdefinitiondetails_get_filteredtimeout(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_filteredtimeout;
}
void mc_aggregation_aggregationdefinitiondetails_set_filteredtimeout(mc_aggregation_aggregationdefinitiondetails_t * self, mal_duration_t f_filteredtimeout)
{
  self->f_filteredtimeout = f_filteredtimeout;
}
mal_boolean_t mc_aggregation_aggregationdefinitiondetails_get_generationenabled(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_generationenabled;
}
void mc_aggregation_aggregationdefinitiondetails_set_generationenabled(mc_aggregation_aggregationdefinitiondetails_t * self, mal_boolean_t f_generationenabled)
{
  self->f_generationenabled = f_generationenabled;
}
mc_aggregation_aggregationparameterset_list_t * mc_aggregation_aggregationdefinitiondetails_get_parametersets(mc_aggregation_aggregationdefinitiondetails_t * self)
{
  return self->f_parametersets;
}
void mc_aggregation_aggregationdefinitiondetails_set_parametersets(mc_aggregation_aggregationdefinitiondetails_t * self, mc_aggregation_aggregationparameterset_list_t * f_parametersets)
{
  self->f_parametersets = f_parametersets;
}

// default constructor
mc_aggregation_aggregationdefinitiondetails_t * mc_aggregation_aggregationdefinitiondetails_new(void)
{
  mc_aggregation_aggregationdefinitiondetails_t *self = (mc_aggregation_aggregationdefinitiondetails_t *) calloc(1, sizeof(mc_aggregation_aggregationdefinitiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationdefinitiondetails_add_encoding_length_malbinary(mc_aggregation_aggregationdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uoctet_encoding_length(encoder, self->f_category, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_reportinterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_sendunchanged, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_senddefinitions, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_filterenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_filteredtimeout, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_generationenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationparameterset_list_add_encoding_length_malbinary(self->f_parametersets, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationdefinitiondetails_encode_malbinary(mc_aggregation_aggregationdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uoctet(encoder, cursor, self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_reportinterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_sendunchanged);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_senddefinitions);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_filterenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_filteredtimeout);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationparameterset_list_encode_malbinary(self->f_parametersets, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationdefinitiondetails_decode_malbinary(mc_aggregation_aggregationdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uoctet(decoder, cursor, &self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_reportinterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_sendunchanged);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_senddefinitions);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_filterenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_filteredtimeout);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_generationenabled);
  if (rc < 0)
    return rc;
  self->f_parametersets = mc_aggregation_aggregationparameterset_list_new(0);
  if (self->f_parametersets == NULL) return -1;
  rc = mc_aggregation_aggregationparameterset_list_decode_malbinary(self->f_parametersets, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationdefinitiondetails_destroy(mc_aggregation_aggregationdefinitiondetails_t ** self_p)
{
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_parametersets != NULL)
  {
    mc_aggregation_aggregationparameterset_list_destroy(& (*self_p)->f_parametersets);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationdefinitiondetails_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationDefinitionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
