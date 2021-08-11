#include "mc.h"


// structure definition for composite mc_aggregation_aggregationparameterset
struct _mc_aggregation_aggregationparameterset_t {
  mal_identifier_list_t * f_domain;
  mal_long_list_t * f_parameters;
  mal_duration_t f_sampleinterval;
  mc_aggregation_thresholdfilter_t * f_reportfilter;
};

// fields accessors for composite mc_aggregation_aggregationparameterset
mal_identifier_list_t * mc_aggregation_aggregationparameterset_get_domain(mc_aggregation_aggregationparameterset_t * self)
{
  return self->f_domain;
}
void mc_aggregation_aggregationparameterset_set_domain(mc_aggregation_aggregationparameterset_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_long_list_t * mc_aggregation_aggregationparameterset_get_parameters(mc_aggregation_aggregationparameterset_t * self)
{
  return self->f_parameters;
}
void mc_aggregation_aggregationparameterset_set_parameters(mc_aggregation_aggregationparameterset_t * self, mal_long_list_t * f_parameters)
{
  self->f_parameters = f_parameters;
}
mal_duration_t mc_aggregation_aggregationparameterset_get_sampleinterval(mc_aggregation_aggregationparameterset_t * self)
{
  return self->f_sampleinterval;
}
void mc_aggregation_aggregationparameterset_set_sampleinterval(mc_aggregation_aggregationparameterset_t * self, mal_duration_t f_sampleinterval)
{
  self->f_sampleinterval = f_sampleinterval;
}
mc_aggregation_thresholdfilter_t * mc_aggregation_aggregationparameterset_get_reportfilter(mc_aggregation_aggregationparameterset_t * self)
{
  return self->f_reportfilter;
}
void mc_aggregation_aggregationparameterset_set_reportfilter(mc_aggregation_aggregationparameterset_t * self, mc_aggregation_thresholdfilter_t * f_reportfilter)
{
  self->f_reportfilter = f_reportfilter;
}

// default constructor
mc_aggregation_aggregationparameterset_t * mc_aggregation_aggregationparameterset_new(void)
{
  mc_aggregation_aggregationparameterset_t *self = (mc_aggregation_aggregationparameterset_t *) calloc(1, sizeof(mc_aggregation_aggregationparameterset_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationparameterset_add_encoding_length_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_domain != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_domain != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_long_list_add_encoding_length_malbinary(self->f_parameters, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_sampleinterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_reportfilter != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_reportfilter != NULL))
  {
    rc = mc_aggregation_thresholdfilter_add_encoding_length_malbinary(self->f_reportfilter, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_aggregation_aggregationparameterset_encode_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_domain != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_long_list_encode_malbinary(self->f_parameters, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_sampleinterval);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_reportfilter != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_aggregation_thresholdfilter_encode_malbinary(self->f_reportfilter, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_aggregation_aggregationparameterset_decode_malbinary(mc_aggregation_aggregationparameterset_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_domain = mal_identifier_list_new(0);
    if (self->f_domain == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_domain = NULL;
  }
  self->f_parameters = mal_long_list_new(0);
  if (self->f_parameters == NULL) return -1;
  rc = mal_long_list_decode_malbinary(self->f_parameters, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_sampleinterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_reportfilter = mc_aggregation_thresholdfilter_new();
    if (self->f_reportfilter == NULL) return -1;
    rc = mc_aggregation_thresholdfilter_decode_malbinary(self->f_reportfilter, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_reportfilter = NULL;
  }
  return rc;
}

// destructor
void mc_aggregation_aggregationparameterset_destroy(mc_aggregation_aggregationparameterset_t ** self_p)
{
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_parameters != NULL)
  {
    mal_long_list_destroy(& (*self_p)->f_parameters);
  }
  if ((*self_p)->f_reportfilter != NULL)
  {
    mc_aggregation_thresholdfilter_destroy(& (*self_p)->f_reportfilter);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationparameterset_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationParameterSet: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
