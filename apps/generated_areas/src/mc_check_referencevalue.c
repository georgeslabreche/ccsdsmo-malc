#include "mc.h"


// structure definition for composite mc_check_referencevalue
struct _mc_check_referencevalue_t {
  mal_ushort_t f_validcount;
  mal_duration_t f_deltatime;
  com_objectkey_t * f_parameterid;
};

// fields accessors for composite mc_check_referencevalue
mal_ushort_t mc_check_referencevalue_get_validcount(mc_check_referencevalue_t * self)
{
  return self->f_validcount;
}
void mc_check_referencevalue_set_validcount(mc_check_referencevalue_t * self, mal_ushort_t f_validcount)
{
  self->f_validcount = f_validcount;
}
mal_duration_t mc_check_referencevalue_get_deltatime(mc_check_referencevalue_t * self)
{
  return self->f_deltatime;
}
void mc_check_referencevalue_set_deltatime(mc_check_referencevalue_t * self, mal_duration_t f_deltatime)
{
  self->f_deltatime = f_deltatime;
}
com_objectkey_t * mc_check_referencevalue_get_parameterid(mc_check_referencevalue_t * self)
{
  return self->f_parameterid;
}
void mc_check_referencevalue_set_parameterid(mc_check_referencevalue_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}

// default constructor
mc_check_referencevalue_t * mc_check_referencevalue_new(void)
{
  mc_check_referencevalue_t *self = (mc_check_referencevalue_t *) calloc(1, sizeof(mc_check_referencevalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_referencevalue_add_encoding_length_malbinary(mc_check_referencevalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_ushort_encoding_length(encoder, self->f_validcount, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_deltatime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_parameterid != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_parameterid != NULL))
  {
    rc = com_objectkey_add_encoding_length_malbinary(self->f_parameterid, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_referencevalue_encode_malbinary(mc_check_referencevalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_ushort(encoder, cursor, self->f_validcount);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_deltatime);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_parameterid != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = com_objectkey_encode_malbinary(self->f_parameterid, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_referencevalue_decode_malbinary(mc_check_referencevalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_ushort(decoder, cursor, &self->f_validcount);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_deltatime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_parameterid = com_objectkey_new();
    if (self->f_parameterid == NULL) return -1;
    rc = com_objectkey_decode_malbinary(self->f_parameterid, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_parameterid = NULL;
  }
  return rc;
}

// destructor
void mc_check_referencevalue_destroy(mc_check_referencevalue_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_referencevalue_test(bool verbose)
{
  printf(" * MC:Check:ReferenceValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
