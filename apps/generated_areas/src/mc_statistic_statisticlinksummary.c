#include "mc.h"


// structure definition for composite mc_statistic_statisticlinksummary
struct _mc_statistic_statisticlinksummary_t {
  mal_long_t f_funcid;
  mal_long_t f_linkid;
  mal_long_t f_linkdefid;
  mal_boolean_t f_reportingenabled;
  com_objectkey_t * f_parameterid;
};

// fields accessors for composite mc_statistic_statisticlinksummary
mal_long_t mc_statistic_statisticlinksummary_get_funcid(mc_statistic_statisticlinksummary_t * self)
{
  return self->f_funcid;
}
void mc_statistic_statisticlinksummary_set_funcid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_funcid)
{
  self->f_funcid = f_funcid;
}
mal_long_t mc_statistic_statisticlinksummary_get_linkid(mc_statistic_statisticlinksummary_t * self)
{
  return self->f_linkid;
}
void mc_statistic_statisticlinksummary_set_linkid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_linkid)
{
  self->f_linkid = f_linkid;
}
mal_long_t mc_statistic_statisticlinksummary_get_linkdefid(mc_statistic_statisticlinksummary_t * self)
{
  return self->f_linkdefid;
}
void mc_statistic_statisticlinksummary_set_linkdefid(mc_statistic_statisticlinksummary_t * self, mal_long_t f_linkdefid)
{
  self->f_linkdefid = f_linkdefid;
}
mal_boolean_t mc_statistic_statisticlinksummary_get_reportingenabled(mc_statistic_statisticlinksummary_t * self)
{
  return self->f_reportingenabled;
}
void mc_statistic_statisticlinksummary_set_reportingenabled(mc_statistic_statisticlinksummary_t * self, mal_boolean_t f_reportingenabled)
{
  self->f_reportingenabled = f_reportingenabled;
}
com_objectkey_t * mc_statistic_statisticlinksummary_get_parameterid(mc_statistic_statisticlinksummary_t * self)
{
  return self->f_parameterid;
}
void mc_statistic_statisticlinksummary_set_parameterid(mc_statistic_statisticlinksummary_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}

// default constructor
mc_statistic_statisticlinksummary_t * mc_statistic_statisticlinksummary_new(void)
{
  mc_statistic_statisticlinksummary_t *self = (mc_statistic_statisticlinksummary_t *) calloc(1, sizeof(mc_statistic_statisticlinksummary_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticlinksummary_add_encoding_length_malbinary(mc_statistic_statisticlinksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_funcid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkdefid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_reportingenabled, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticlinksummary_encode_malbinary(mc_statistic_statisticlinksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_funcid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkdefid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_reportingenabled);
  if (rc < 0)
    return rc;
  rc = com_objectkey_encode_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticlinksummary_decode_malbinary(mc_statistic_statisticlinksummary_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_funcid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkdefid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_reportingenabled);
  if (rc < 0)
    return rc;
  self->f_parameterid = com_objectkey_new();
  if (self->f_parameterid == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_parameterid, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticlinksummary_destroy(mc_statistic_statisticlinksummary_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticlinksummary_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticLinkSummary: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
