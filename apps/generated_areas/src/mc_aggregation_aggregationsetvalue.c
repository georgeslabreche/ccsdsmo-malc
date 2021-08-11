#include "mc.h"


// structure definition for composite mc_aggregation_aggregationsetvalue
struct _mc_aggregation_aggregationsetvalue_t {
  bool f_deltatime_is_present;
  mal_duration_t f_deltatime;
  bool f_intervaltime_is_present;
  mal_duration_t f_intervaltime;
  mc_aggregation_aggregationparametervalue_list_t * f_values;
};

// fields accessors for composite mc_aggregation_aggregationsetvalue
bool mc_aggregation_aggregationsetvalue_deltatime_is_present(mc_aggregation_aggregationsetvalue_t * self)
{
  return self->f_deltatime_is_present;
}
void mc_aggregation_aggregationsetvalue_deltatime_set_present(mc_aggregation_aggregationsetvalue_t * self, bool is_present)
{
  self->f_deltatime_is_present = is_present;
}
mal_duration_t mc_aggregation_aggregationsetvalue_get_deltatime(mc_aggregation_aggregationsetvalue_t * self)
{
  return self->f_deltatime;
}
void mc_aggregation_aggregationsetvalue_set_deltatime(mc_aggregation_aggregationsetvalue_t * self, mal_duration_t f_deltatime)
{
  self->f_deltatime = f_deltatime;
}
bool mc_aggregation_aggregationsetvalue_intervaltime_is_present(mc_aggregation_aggregationsetvalue_t * self)
{
  return self->f_intervaltime_is_present;
}
void mc_aggregation_aggregationsetvalue_intervaltime_set_present(mc_aggregation_aggregationsetvalue_t * self, bool is_present)
{
  self->f_intervaltime_is_present = is_present;
}
mal_duration_t mc_aggregation_aggregationsetvalue_get_intervaltime(mc_aggregation_aggregationsetvalue_t * self)
{
  return self->f_intervaltime;
}
void mc_aggregation_aggregationsetvalue_set_intervaltime(mc_aggregation_aggregationsetvalue_t * self, mal_duration_t f_intervaltime)
{
  self->f_intervaltime = f_intervaltime;
}
mc_aggregation_aggregationparametervalue_list_t * mc_aggregation_aggregationsetvalue_get_values(mc_aggregation_aggregationsetvalue_t * self)
{
  return self->f_values;
}
void mc_aggregation_aggregationsetvalue_set_values(mc_aggregation_aggregationsetvalue_t * self, mc_aggregation_aggregationparametervalue_list_t * f_values)
{
  self->f_values = f_values;
}

// default constructor
mc_aggregation_aggregationsetvalue_t * mc_aggregation_aggregationsetvalue_new(void)
{
  mc_aggregation_aggregationsetvalue_t *self = (mc_aggregation_aggregationsetvalue_t *) calloc(1, sizeof(mc_aggregation_aggregationsetvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationsetvalue_add_encoding_length_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_deltatime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_deltatime_is_present)
  {
    rc = mal_encoder_add_duration_encoding_length(encoder, self->f_deltatime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_intervaltime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_intervaltime_is_present)
  {
    rc = mal_encoder_add_duration_encoding_length(encoder, self->f_intervaltime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mc_aggregation_aggregationparametervalue_list_add_encoding_length_malbinary(self->f_values, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationsetvalue_encode_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_deltatime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_duration(encoder, cursor, self->f_deltatime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_intervaltime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_duration(encoder, cursor, self->f_intervaltime);
    if (rc < 0)
      return rc;
  }
  rc = mc_aggregation_aggregationparametervalue_list_encode_malbinary(self->f_values, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationsetvalue_decode_malbinary(mc_aggregation_aggregationsetvalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_duration(decoder, cursor, &self->f_deltatime);
    if (rc < 0)
      return rc;
  }
  self->f_deltatime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_duration(decoder, cursor, &self->f_intervaltime);
    if (rc < 0)
      return rc;
  }
  self->f_intervaltime_is_present = presence_flag;
  self->f_values = mc_aggregation_aggregationparametervalue_list_new(0);
  if (self->f_values == NULL) return -1;
  rc = mc_aggregation_aggregationparametervalue_list_decode_malbinary(self->f_values, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationsetvalue_destroy(mc_aggregation_aggregationsetvalue_t ** self_p)
{
  if ((*self_p)->f_values != NULL)
  {
    mc_aggregation_aggregationparametervalue_list_destroy(& (*self_p)->f_values);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationsetvalue_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationSetValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
