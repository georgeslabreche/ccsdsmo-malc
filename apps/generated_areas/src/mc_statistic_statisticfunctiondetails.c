#include "mc.h"


// structure definition for composite mc_statistic_statisticfunctiondetails
struct _mc_statistic_statisticfunctiondetails_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
};

// fields accessors for composite mc_statistic_statisticfunctiondetails
mal_identifier_t * mc_statistic_statisticfunctiondetails_get_name(mc_statistic_statisticfunctiondetails_t * self)
{
  return self->f_name;
}
void mc_statistic_statisticfunctiondetails_set_name(mc_statistic_statisticfunctiondetails_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * mc_statistic_statisticfunctiondetails_get_description(mc_statistic_statisticfunctiondetails_t * self)
{
  return self->f_description;
}
void mc_statistic_statisticfunctiondetails_set_description(mc_statistic_statisticfunctiondetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}

// default constructor
mc_statistic_statisticfunctiondetails_t * mc_statistic_statisticfunctiondetails_new(void)
{
  mc_statistic_statisticfunctiondetails_t *self = (mc_statistic_statisticfunctiondetails_t *) calloc(1, sizeof(mc_statistic_statisticfunctiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticfunctiondetails_add_encoding_length_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticfunctiondetails_encode_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticfunctiondetails_decode_malbinary(mc_statistic_statisticfunctiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticfunctiondetails_destroy(mc_statistic_statisticfunctiondetails_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticfunctiondetails_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticFunctionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
