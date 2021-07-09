#include "opssat_pf.h"


// structure definition for composite opssat_pf_coarseadcs_orbittledata
struct _opssat_pf_coarseadcs_orbittledata_t {
  mal_string_t * f_firstline;
  mal_string_t * f_secondline;
};

// fields accessors for composite opssat_pf_coarseadcs_orbittledata
mal_string_t * opssat_pf_coarseadcs_orbittledata_get_firstline(opssat_pf_coarseadcs_orbittledata_t * self)
{
  return self->f_firstline;
}
void opssat_pf_coarseadcs_orbittledata_set_firstline(opssat_pf_coarseadcs_orbittledata_t * self, mal_string_t * f_firstline)
{
  self->f_firstline = f_firstline;
}
mal_string_t * opssat_pf_coarseadcs_orbittledata_get_secondline(opssat_pf_coarseadcs_orbittledata_t * self)
{
  return self->f_secondline;
}
void opssat_pf_coarseadcs_orbittledata_set_secondline(opssat_pf_coarseadcs_orbittledata_t * self, mal_string_t * f_secondline)
{
  self->f_secondline = f_secondline;
}

// default constructor
opssat_pf_coarseadcs_orbittledata_t * opssat_pf_coarseadcs_orbittledata_new(void)
{
  opssat_pf_coarseadcs_orbittledata_t *self = (opssat_pf_coarseadcs_orbittledata_t *) calloc(1, sizeof(opssat_pf_coarseadcs_orbittledata_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int opssat_pf_coarseadcs_orbittledata_add_encoding_length_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_firstline, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_secondline, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_pf_coarseadcs_orbittledata_encode_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_firstline);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_secondline);
  if (rc < 0)
    return rc;
  return rc;
}
int opssat_pf_coarseadcs_orbittledata_decode_malbinary(opssat_pf_coarseadcs_orbittledata_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_firstline);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_secondline);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void opssat_pf_coarseadcs_orbittledata_destroy(opssat_pf_coarseadcs_orbittledata_t ** self_p)
{
  if ((*self_p)->f_firstline != NULL)
  {
    mal_string_destroy(& (*self_p)->f_firstline);
  }
  if ((*self_p)->f_secondline != NULL)
  {
    mal_string_destroy(& (*self_p)->f_secondline);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void opssat_pf_coarseadcs_orbittledata_test(bool verbose)
{
  printf(" * OPSSAT_PF:CoarseADCS:OrbitTLEData: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
