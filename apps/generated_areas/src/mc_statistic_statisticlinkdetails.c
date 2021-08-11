#include "mc.h"


// structure definition for composite mc_statistic_statisticlinkdetails
struct _mc_statistic_statisticlinkdetails_t {
  mal_duration_t f_samplinginterval;
  mal_duration_t f_reportinginterval;
  mal_duration_t f_collectioninterval;
  mal_boolean_t f_reseteverycollection;
  mal_boolean_t f_reportingenabled;
  mal_boolean_t f_useconverted;
};

// fields accessors for composite mc_statistic_statisticlinkdetails
mal_duration_t mc_statistic_statisticlinkdetails_get_samplinginterval(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_samplinginterval;
}
void mc_statistic_statisticlinkdetails_set_samplinginterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_samplinginterval)
{
  self->f_samplinginterval = f_samplinginterval;
}
mal_duration_t mc_statistic_statisticlinkdetails_get_reportinginterval(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_reportinginterval;
}
void mc_statistic_statisticlinkdetails_set_reportinginterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_reportinginterval)
{
  self->f_reportinginterval = f_reportinginterval;
}
mal_duration_t mc_statistic_statisticlinkdetails_get_collectioninterval(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_collectioninterval;
}
void mc_statistic_statisticlinkdetails_set_collectioninterval(mc_statistic_statisticlinkdetails_t * self, mal_duration_t f_collectioninterval)
{
  self->f_collectioninterval = f_collectioninterval;
}
mal_boolean_t mc_statistic_statisticlinkdetails_get_reseteverycollection(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_reseteverycollection;
}
void mc_statistic_statisticlinkdetails_set_reseteverycollection(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_reseteverycollection)
{
  self->f_reseteverycollection = f_reseteverycollection;
}
mal_boolean_t mc_statistic_statisticlinkdetails_get_reportingenabled(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_reportingenabled;
}
void mc_statistic_statisticlinkdetails_set_reportingenabled(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_reportingenabled)
{
  self->f_reportingenabled = f_reportingenabled;
}
mal_boolean_t mc_statistic_statisticlinkdetails_get_useconverted(mc_statistic_statisticlinkdetails_t * self)
{
  return self->f_useconverted;
}
void mc_statistic_statisticlinkdetails_set_useconverted(mc_statistic_statisticlinkdetails_t * self, mal_boolean_t f_useconverted)
{
  self->f_useconverted = f_useconverted;
}

// default constructor
mc_statistic_statisticlinkdetails_t * mc_statistic_statisticlinkdetails_new(void)
{
  mc_statistic_statisticlinkdetails_t *self = (mc_statistic_statisticlinkdetails_t *) calloc(1, sizeof(mc_statistic_statisticlinkdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticlinkdetails_add_encoding_length_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_samplinginterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_reportinginterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_collectioninterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_reseteverycollection, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_reportingenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_useconverted, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticlinkdetails_encode_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_samplinginterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_reportinginterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_collectioninterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_reseteverycollection);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_reportingenabled);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_useconverted);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticlinkdetails_decode_malbinary(mc_statistic_statisticlinkdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_samplinginterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_reportinginterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_collectioninterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_reseteverycollection);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_reportingenabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_useconverted);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticlinkdetails_destroy(mc_statistic_statisticlinkdetails_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticlinkdetails_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticLinkDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
