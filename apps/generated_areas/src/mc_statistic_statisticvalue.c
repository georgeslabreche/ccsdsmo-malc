#include "mc.h"


// structure definition for composite mc_statistic_statisticvalue
struct _mc_statistic_statisticvalue_t {
  mal_long_t f_paramdefinstid;
  bool f_starttime_is_present;
  mal_time_t f_starttime;
  bool f_endtime_is_present;
  mal_time_t f_endtime;
  bool f_valuetime_is_present;
  mal_time_t f_valuetime;
  bool f_value_is_present;
  unsigned char f_value_attribute_tag;
  union mal_attribute_t f_value;
  mal_uinteger_t f_samplecount;
};

// fields accessors for composite mc_statistic_statisticvalue
mal_long_t mc_statistic_statisticvalue_get_paramdefinstid(mc_statistic_statisticvalue_t * self)
{
  return self->f_paramdefinstid;
}
void mc_statistic_statisticvalue_set_paramdefinstid(mc_statistic_statisticvalue_t * self, mal_long_t f_paramdefinstid)
{
  self->f_paramdefinstid = f_paramdefinstid;
}
bool mc_statistic_statisticvalue_starttime_is_present(mc_statistic_statisticvalue_t * self)
{
  return self->f_starttime_is_present;
}
void mc_statistic_statisticvalue_starttime_set_present(mc_statistic_statisticvalue_t * self, bool is_present)
{
  self->f_starttime_is_present = is_present;
}
mal_time_t mc_statistic_statisticvalue_get_starttime(mc_statistic_statisticvalue_t * self)
{
  return self->f_starttime;
}
void mc_statistic_statisticvalue_set_starttime(mc_statistic_statisticvalue_t * self, mal_time_t f_starttime)
{
  self->f_starttime = f_starttime;
}
bool mc_statistic_statisticvalue_endtime_is_present(mc_statistic_statisticvalue_t * self)
{
  return self->f_endtime_is_present;
}
void mc_statistic_statisticvalue_endtime_set_present(mc_statistic_statisticvalue_t * self, bool is_present)
{
  self->f_endtime_is_present = is_present;
}
mal_time_t mc_statistic_statisticvalue_get_endtime(mc_statistic_statisticvalue_t * self)
{
  return self->f_endtime;
}
void mc_statistic_statisticvalue_set_endtime(mc_statistic_statisticvalue_t * self, mal_time_t f_endtime)
{
  self->f_endtime = f_endtime;
}
bool mc_statistic_statisticvalue_valuetime_is_present(mc_statistic_statisticvalue_t * self)
{
  return self->f_valuetime_is_present;
}
void mc_statistic_statisticvalue_valuetime_set_present(mc_statistic_statisticvalue_t * self, bool is_present)
{
  self->f_valuetime_is_present = is_present;
}
mal_time_t mc_statistic_statisticvalue_get_valuetime(mc_statistic_statisticvalue_t * self)
{
  return self->f_valuetime;
}
void mc_statistic_statisticvalue_set_valuetime(mc_statistic_statisticvalue_t * self, mal_time_t f_valuetime)
{
  self->f_valuetime = f_valuetime;
}
bool mc_statistic_statisticvalue_value_is_present(mc_statistic_statisticvalue_t * self)
{
  return self->f_value_is_present;
}
void mc_statistic_statisticvalue_value_set_present(mc_statistic_statisticvalue_t * self, bool is_present)
{
  self->f_value_is_present = is_present;
}
unsigned char mc_statistic_statisticvalue_value_get_attribute_tag(mc_statistic_statisticvalue_t * self)
{
  return self->f_value_attribute_tag;
}
void mc_statistic_statisticvalue_value_set_attribute_tag(mc_statistic_statisticvalue_t * self, unsigned char attribute_tag)
{
  self->f_value_attribute_tag = attribute_tag;
}
union mal_attribute_t mc_statistic_statisticvalue_get_value(mc_statistic_statisticvalue_t * self)
{
  return self->f_value;
}
void mc_statistic_statisticvalue_set_value(mc_statistic_statisticvalue_t * self, union mal_attribute_t f_value)
{
  self->f_value = f_value;
}
mal_uinteger_t mc_statistic_statisticvalue_get_samplecount(mc_statistic_statisticvalue_t * self)
{
  return self->f_samplecount;
}
void mc_statistic_statisticvalue_set_samplecount(mc_statistic_statisticvalue_t * self, mal_uinteger_t f_samplecount)
{
  self->f_samplecount = f_samplecount;
}

// default constructor
mc_statistic_statisticvalue_t * mc_statistic_statisticvalue_new(void)
{
  mc_statistic_statisticvalue_t *self = (mc_statistic_statisticvalue_t *) calloc(1, sizeof(mc_statistic_statisticvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticvalue_add_encoding_length_malbinary(mc_statistic_statisticvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_paramdefinstid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_starttime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_starttime_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_starttime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_endtime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_endtime_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_endtime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_valuetime_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_valuetime_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_valuetime, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_value_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_value_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_value_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_value_attribute_tag, self->f_value, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_samplecount, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticvalue_encode_malbinary(mc_statistic_statisticvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_paramdefinstid);
  if (rc < 0)
    return rc;
  presence_flag = self->f_starttime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_starttime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_endtime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_endtime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_valuetime_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_valuetime);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_value_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_value_attribute_tag, self->f_value);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_samplecount);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticvalue_decode_malbinary(mc_statistic_statisticvalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_paramdefinstid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_starttime);
    if (rc < 0)
      return rc;
  }
  self->f_starttime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_endtime);
    if (rc < 0)
      return rc;
  }
  self->f_endtime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_valuetime);
    if (rc < 0)
      return rc;
  }
  self->f_valuetime_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_value_attribute_tag, &self->f_value);
    if (rc < 0)
      return rc;
  }
  self->f_value_is_present = presence_flag;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_samplecount);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticvalue_destroy(mc_statistic_statisticvalue_t ** self_p)
{
  if ((*self_p)->f_value_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_value, (*self_p)->f_value_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticvalue_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
