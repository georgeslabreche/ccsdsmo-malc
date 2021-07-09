#include "mc.h"


// structure definition for composite mc_check_checklinksummary
struct _mc_check_checklinksummary_t {
  mal_long_t f_checkid;
  mal_long_t f_linkid;
  mal_long_t f_linkdefinitionid;
  mal_boolean_t f_checkenabled;
  com_objectkey_t * f_parameterid;
};

// fields accessors for composite mc_check_checklinksummary
mal_long_t mc_check_checklinksummary_get_checkid(mc_check_checklinksummary_t * self)
{
  return self->f_checkid;
}
void mc_check_checklinksummary_set_checkid(mc_check_checklinksummary_t * self, mal_long_t f_checkid)
{
  self->f_checkid = f_checkid;
}
mal_long_t mc_check_checklinksummary_get_linkid(mc_check_checklinksummary_t * self)
{
  return self->f_linkid;
}
void mc_check_checklinksummary_set_linkid(mc_check_checklinksummary_t * self, mal_long_t f_linkid)
{
  self->f_linkid = f_linkid;
}
mal_long_t mc_check_checklinksummary_get_linkdefinitionid(mc_check_checklinksummary_t * self)
{
  return self->f_linkdefinitionid;
}
void mc_check_checklinksummary_set_linkdefinitionid(mc_check_checklinksummary_t * self, mal_long_t f_linkdefinitionid)
{
  self->f_linkdefinitionid = f_linkdefinitionid;
}
mal_boolean_t mc_check_checklinksummary_get_checkenabled(mc_check_checklinksummary_t * self)
{
  return self->f_checkenabled;
}
void mc_check_checklinksummary_set_checkenabled(mc_check_checklinksummary_t * self, mal_boolean_t f_checkenabled)
{
  self->f_checkenabled = f_checkenabled;
}
com_objectkey_t * mc_check_checklinksummary_get_parameterid(mc_check_checklinksummary_t * self)
{
  return self->f_parameterid;
}
void mc_check_checklinksummary_set_parameterid(mc_check_checklinksummary_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}

// default constructor
mc_check_checklinksummary_t * mc_check_checklinksummary_new(void)
{
  mc_check_checklinksummary_t *self = (mc_check_checklinksummary_t *) calloc(1, sizeof(mc_check_checklinksummary_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checklinksummary_add_encoding_length_malbinary(mc_check_checklinksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_checkid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_linkdefinitionid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_checkenabled, cursor);
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
int mc_check_checklinksummary_encode_malbinary(mc_check_checklinksummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_checkid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_linkdefinitionid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_checkenabled);
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
int mc_check_checklinksummary_decode_malbinary(mc_check_checklinksummary_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_checkid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_linkdefinitionid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_checkenabled);
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
void mc_check_checklinksummary_destroy(mc_check_checklinksummary_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checklinksummary_test(bool verbose)
{
  printf(" * MC:Check:CheckLinkSummary: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
