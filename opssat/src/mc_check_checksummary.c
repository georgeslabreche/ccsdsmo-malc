#include "mc.h"


// structure definition for composite mc_check_checksummary
struct _mc_check_checksummary_t {
  mal_long_t f_linkid;
  com_objectkey_t * f_parameterid;
  mal_time_t f_evaluationtime;
  mc_check_checkresult_t * f_result;
};

// fields accessors for composite mc_check_checksummary
mal_long_t mc_check_checksummary_get_linkid(mc_check_checksummary_t * self)
{
  return self->f_linkid;
}
void mc_check_checksummary_set_linkid(mc_check_checksummary_t * self, mal_long_t f_linkid)
{
  self->f_linkid = f_linkid;
}
com_objectkey_t * mc_check_checksummary_get_parameterid(mc_check_checksummary_t * self)
{
  return self->f_parameterid;
}
void mc_check_checksummary_set_parameterid(mc_check_checksummary_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}
mal_time_t mc_check_checksummary_get_evaluationtime(mc_check_checksummary_t * self)
{
  return self->f_evaluationtime;
}
void mc_check_checksummary_set_evaluationtime(mc_check_checksummary_t * self, mal_time_t f_evaluationtime)
{
  self->f_evaluationtime = f_evaluationtime;
}
mc_check_checkresult_t * mc_check_checksummary_get_result(mc_check_checksummary_t * self)
{
  return self->f_result;
}
void mc_check_checksummary_set_result(mc_check_checksummary_t * self, mc_check_checkresult_t * f_result)
{
  self->f_result = f_result;
}

// default constructor
mc_check_checksummary_t * mc_check_checksummary_new(void)
{
  mc_check_checksummary_t *self = (mc_check_checksummary_t *) calloc(1, sizeof(mc_check_checksummary_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checksummary_add_encoding_length_malbinary(mc_check_checksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkid, cursor);
  if (rc < 0)
    return rc;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_time_encoding_length(encoder, self->f_evaluationtime, cursor);
  if (rc < 0)
    return rc;
  rc = mc_check_checkresult_add_encoding_length_malbinary(self->f_result, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_checksummary_encode_malbinary(mc_check_checksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkid);
  if (rc < 0)
    return rc;
  rc = com_objectkey_encode_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_time(encoder, cursor, self->f_evaluationtime);
  if (rc < 0)
    return rc;
  rc = mc_check_checkresult_encode_malbinary(self->f_result, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_checksummary_decode_malbinary(mc_check_checksummary_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkid);
  if (rc < 0)
    return rc;
  self->f_parameterid = com_objectkey_new();
  if (self->f_parameterid == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_parameterid, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_time(decoder, cursor, &self->f_evaluationtime);
  if (rc < 0)
    return rc;
  self->f_result = mc_check_checkresult_new();
  if (self->f_result == NULL) return -1;
  rc = mc_check_checkresult_decode_malbinary(self->f_result, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_check_checksummary_destroy(mc_check_checksummary_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  if ((*self_p)->f_result != NULL)
  {
    mc_check_checkresult_destroy(& (*self_p)->f_result);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checksummary_test(bool verbose)
{
  printf(" * MC:Check:CheckSummary: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
