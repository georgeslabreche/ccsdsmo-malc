#include "mc.h"


// structure definition for composite mc_aggregation_aggregationvaluedetails
struct _mc_aggregation_aggregationvaluedetails_t {
  mal_long_t f_aggid;
  mal_long_t f_defid;
  mal_time_t f_timestamp;
  mc_aggregation_aggregationvalue_t * f_value;
};

// fields accessors for composite mc_aggregation_aggregationvaluedetails
mal_long_t mc_aggregation_aggregationvaluedetails_get_aggid(mc_aggregation_aggregationvaluedetails_t * self)
{
  return self->f_aggid;
}
void mc_aggregation_aggregationvaluedetails_set_aggid(mc_aggregation_aggregationvaluedetails_t * self, mal_long_t f_aggid)
{
  self->f_aggid = f_aggid;
}
mal_long_t mc_aggregation_aggregationvaluedetails_get_defid(mc_aggregation_aggregationvaluedetails_t * self)
{
  return self->f_defid;
}
void mc_aggregation_aggregationvaluedetails_set_defid(mc_aggregation_aggregationvaluedetails_t * self, mal_long_t f_defid)
{
  self->f_defid = f_defid;
}
mal_time_t mc_aggregation_aggregationvaluedetails_get_timestamp(mc_aggregation_aggregationvaluedetails_t * self)
{
  return self->f_timestamp;
}
void mc_aggregation_aggregationvaluedetails_set_timestamp(mc_aggregation_aggregationvaluedetails_t * self, mal_time_t f_timestamp)
{
  self->f_timestamp = f_timestamp;
}
mc_aggregation_aggregationvalue_t * mc_aggregation_aggregationvaluedetails_get_value(mc_aggregation_aggregationvaluedetails_t * self)
{
  return self->f_value;
}
void mc_aggregation_aggregationvaluedetails_set_value(mc_aggregation_aggregationvaluedetails_t * self, mc_aggregation_aggregationvalue_t * f_value)
{
  self->f_value = f_value;
}

// default constructor
mc_aggregation_aggregationvaluedetails_t * mc_aggregation_aggregationvaluedetails_new(void)
{
  mc_aggregation_aggregationvaluedetails_t *self = (mc_aggregation_aggregationvaluedetails_t *) calloc(1, sizeof(mc_aggregation_aggregationvaluedetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationvaluedetails_add_encoding_length_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_aggid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_defid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_time_encoding_length(encoder, self->f_timestamp, cursor);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationvalue_add_encoding_length_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationvaluedetails_encode_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_aggid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_defid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_time(encoder, cursor, self->f_timestamp);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationvalue_encode_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationvaluedetails_decode_malbinary(mc_aggregation_aggregationvaluedetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_aggid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_defid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_time(decoder, cursor, &self->f_timestamp);
  if (rc < 0)
    return rc;
  self->f_value = mc_aggregation_aggregationvalue_new();
  if (self->f_value == NULL) return -1;
  rc = mc_aggregation_aggregationvalue_decode_malbinary(self->f_value, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationvaluedetails_destroy(mc_aggregation_aggregationvaluedetails_t ** self_p)
{
  if ((*self_p)->f_value != NULL)
  {
    mc_aggregation_aggregationvalue_destroy(& (*self_p)->f_value);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationvaluedetails_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationValueDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
