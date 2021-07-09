#include "mc.h"


// structure definition for composite mc_statistic_statisticevaluationreport
struct _mc_statistic_statisticevaluationreport_t {
  mal_long_t f_linkid;
  mc_statistic_statisticvalue_t * f_value;
};

// fields accessors for composite mc_statistic_statisticevaluationreport
mal_long_t mc_statistic_statisticevaluationreport_get_linkid(mc_statistic_statisticevaluationreport_t * self)
{
  return self->f_linkid;
}
void mc_statistic_statisticevaluationreport_set_linkid(mc_statistic_statisticevaluationreport_t * self, mal_long_t f_linkid)
{
  self->f_linkid = f_linkid;
}
mc_statistic_statisticvalue_t * mc_statistic_statisticevaluationreport_get_value(mc_statistic_statisticevaluationreport_t * self)
{
  return self->f_value;
}
void mc_statistic_statisticevaluationreport_set_value(mc_statistic_statisticevaluationreport_t * self, mc_statistic_statisticvalue_t * f_value)
{
  self->f_value = f_value;
}

// default constructor
mc_statistic_statisticevaluationreport_t * mc_statistic_statisticevaluationreport_new(void)
{
  mc_statistic_statisticevaluationreport_t *self = (mc_statistic_statisticevaluationreport_t *) calloc(1, sizeof(mc_statistic_statisticevaluationreport_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticevaluationreport_add_encoding_length_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkid, cursor);
  if (rc < 0)
    return rc;
  rc = mc_statistic_statisticvalue_add_encoding_length_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticevaluationreport_encode_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkid);
  if (rc < 0)
    return rc;
  rc = mc_statistic_statisticvalue_encode_malbinary(self->f_value, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticevaluationreport_decode_malbinary(mc_statistic_statisticevaluationreport_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkid);
  if (rc < 0)
    return rc;
  self->f_value = mc_statistic_statisticvalue_new();
  if (self->f_value == NULL) return -1;
  rc = mc_statistic_statisticvalue_decode_malbinary(self->f_value, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticevaluationreport_destroy(mc_statistic_statisticevaluationreport_t ** self_p)
{
  if ((*self_p)->f_value != NULL)
  {
    mc_statistic_statisticvalue_destroy(& (*self_p)->f_value);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticevaluationreport_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticEvaluationReport: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
