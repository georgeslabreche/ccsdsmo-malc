#include "mc.h"


// structure definition for composite mc_statistic_statisticcreationrequest
struct _mc_statistic_statisticcreationrequest_t {
  mal_long_t f_statfuncinstid;
  com_objectkey_t * f_parameterid;
  mc_statistic_statisticlinkdetails_t * f_linkdetails;
};

// fields accessors for composite mc_statistic_statisticcreationrequest
mal_long_t mc_statistic_statisticcreationrequest_get_statfuncinstid(mc_statistic_statisticcreationrequest_t * self)
{
  return self->f_statfuncinstid;
}
void mc_statistic_statisticcreationrequest_set_statfuncinstid(mc_statistic_statisticcreationrequest_t * self, mal_long_t f_statfuncinstid)
{
  self->f_statfuncinstid = f_statfuncinstid;
}
com_objectkey_t * mc_statistic_statisticcreationrequest_get_parameterid(mc_statistic_statisticcreationrequest_t * self)
{
  return self->f_parameterid;
}
void mc_statistic_statisticcreationrequest_set_parameterid(mc_statistic_statisticcreationrequest_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}
mc_statistic_statisticlinkdetails_t * mc_statistic_statisticcreationrequest_get_linkdetails(mc_statistic_statisticcreationrequest_t * self)
{
  return self->f_linkdetails;
}
void mc_statistic_statisticcreationrequest_set_linkdetails(mc_statistic_statisticcreationrequest_t * self, mc_statistic_statisticlinkdetails_t * f_linkdetails)
{
  self->f_linkdetails = f_linkdetails;
}

// default constructor
mc_statistic_statisticcreationrequest_t * mc_statistic_statisticcreationrequest_new(void)
{
  mc_statistic_statisticcreationrequest_t *self = (mc_statistic_statisticcreationrequest_t *) calloc(1, sizeof(mc_statistic_statisticcreationrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_statistic_statisticcreationrequest_add_encoding_length_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_statfuncinstid, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mc_statistic_statisticlinkdetails_add_encoding_length_malbinary(self->f_linkdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticcreationrequest_encode_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_statfuncinstid);
  if (rc < 0)
    return rc;
  rc = com_objectkey_encode_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mc_statistic_statisticlinkdetails_encode_malbinary(self->f_linkdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_statistic_statisticcreationrequest_decode_malbinary(mc_statistic_statisticcreationrequest_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_statfuncinstid);
  if (rc < 0)
    return rc;
  self->f_parameterid = com_objectkey_new();
  if (self->f_parameterid == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_parameterid, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_linkdetails = mc_statistic_statisticlinkdetails_new();
  if (self->f_linkdetails == NULL) return -1;
  rc = mc_statistic_statisticlinkdetails_decode_malbinary(self->f_linkdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_statistic_statisticcreationrequest_destroy(mc_statistic_statisticcreationrequest_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  if ((*self_p)->f_linkdetails != NULL)
  {
    mc_statistic_statisticlinkdetails_destroy(& (*self_p)->f_linkdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_statistic_statisticcreationrequest_test(bool verbose)
{
  printf(" * MC:Statistic:StatisticCreationRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
