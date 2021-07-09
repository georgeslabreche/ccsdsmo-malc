#include "mc.h"


// structure definition for composite mc_check_checkresultfilter
struct _mc_check_checkresultfilter_t {
  mal_long_list_t * f_checkfilter;
  mal_long_list_t * f_parameterfilter;
  mc_check_checkstate_list_t * f_statefilter;
};

// fields accessors for composite mc_check_checkresultfilter
mal_long_list_t * mc_check_checkresultfilter_get_checkfilter(mc_check_checkresultfilter_t * self)
{
  return self->f_checkfilter;
}
void mc_check_checkresultfilter_set_checkfilter(mc_check_checkresultfilter_t * self, mal_long_list_t * f_checkfilter)
{
  self->f_checkfilter = f_checkfilter;
}
mal_long_list_t * mc_check_checkresultfilter_get_parameterfilter(mc_check_checkresultfilter_t * self)
{
  return self->f_parameterfilter;
}
void mc_check_checkresultfilter_set_parameterfilter(mc_check_checkresultfilter_t * self, mal_long_list_t * f_parameterfilter)
{
  self->f_parameterfilter = f_parameterfilter;
}
mc_check_checkstate_list_t * mc_check_checkresultfilter_get_statefilter(mc_check_checkresultfilter_t * self)
{
  return self->f_statefilter;
}
void mc_check_checkresultfilter_set_statefilter(mc_check_checkresultfilter_t * self, mc_check_checkstate_list_t * f_statefilter)
{
  self->f_statefilter = f_statefilter;
}

// default constructor
mc_check_checkresultfilter_t * mc_check_checkresultfilter_new(void)
{
  mc_check_checkresultfilter_t *self = (mc_check_checkresultfilter_t *) calloc(1, sizeof(mc_check_checkresultfilter_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checkresultfilter_add_encoding_length_malbinary(mc_check_checkresultfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_long_list_add_encoding_length_malbinary(self->f_checkfilter, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_add_encoding_length_malbinary(self->f_parameterfilter, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mc_check_checkstate_list_add_encoding_length_malbinary(self->f_statefilter, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_checkresultfilter_encode_malbinary(mc_check_checkresultfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_long_list_encode_malbinary(self->f_checkfilter, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_encode_malbinary(self->f_parameterfilter, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mc_check_checkstate_list_encode_malbinary(self->f_statefilter, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_checkresultfilter_decode_malbinary(mc_check_checkresultfilter_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_checkfilter = mal_long_list_new(0);
  if (self->f_checkfilter == NULL) return -1;
  rc = mal_long_list_decode_malbinary(self->f_checkfilter, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_parameterfilter = mal_long_list_new(0);
  if (self->f_parameterfilter == NULL) return -1;
  rc = mal_long_list_decode_malbinary(self->f_parameterfilter, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_statefilter = mc_check_checkstate_list_new(0);
  if (self->f_statefilter == NULL) return -1;
  rc = mc_check_checkstate_list_decode_malbinary(self->f_statefilter, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_check_checkresultfilter_destroy(mc_check_checkresultfilter_t ** self_p)
{
  if ((*self_p)->f_checkfilter != NULL)
  {
    mal_long_list_destroy(& (*self_p)->f_checkfilter);
  }
  if ((*self_p)->f_parameterfilter != NULL)
  {
    mal_long_list_destroy(& (*self_p)->f_parameterfilter);
  }
  if ((*self_p)->f_statefilter != NULL)
  {
    mc_check_checkstate_list_destroy(& (*self_p)->f_statefilter);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checkresultfilter_test(bool verbose)
{
  printf(" * MC:Check:CheckResultFilter: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
