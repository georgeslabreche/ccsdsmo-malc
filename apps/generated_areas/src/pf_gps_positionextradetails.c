#include "pf.h"


// structure definition for composite pf_gps_positionextradetails
struct _pf_gps_positionextradetails_t {
  bool f_utc_is_present;
  mal_time_t f_utc;
  bool f_fixquality_is_present;
  mal_integer_t f_fixquality;
  bool f_numberofsatellites_is_present;
  mal_integer_t f_numberofsatellites;
  bool f_hdop_is_present;
  mal_float_t f_hdop;
  bool f_undulation_is_present;
  mal_float_t f_undulation;
};

// fields accessors for composite pf_gps_positionextradetails
bool pf_gps_positionextradetails_utc_is_present(pf_gps_positionextradetails_t * self)
{
  return self->f_utc_is_present;
}
void pf_gps_positionextradetails_utc_set_present(pf_gps_positionextradetails_t * self, bool is_present)
{
  self->f_utc_is_present = is_present;
}
mal_time_t pf_gps_positionextradetails_get_utc(pf_gps_positionextradetails_t * self)
{
  return self->f_utc;
}
void pf_gps_positionextradetails_set_utc(pf_gps_positionextradetails_t * self, mal_time_t f_utc)
{
  self->f_utc = f_utc;
}
bool pf_gps_positionextradetails_fixquality_is_present(pf_gps_positionextradetails_t * self)
{
  return self->f_fixquality_is_present;
}
void pf_gps_positionextradetails_fixquality_set_present(pf_gps_positionextradetails_t * self, bool is_present)
{
  self->f_fixquality_is_present = is_present;
}
mal_integer_t pf_gps_positionextradetails_get_fixquality(pf_gps_positionextradetails_t * self)
{
  return self->f_fixquality;
}
void pf_gps_positionextradetails_set_fixquality(pf_gps_positionextradetails_t * self, mal_integer_t f_fixquality)
{
  self->f_fixquality = f_fixquality;
}
bool pf_gps_positionextradetails_numberofsatellites_is_present(pf_gps_positionextradetails_t * self)
{
  return self->f_numberofsatellites_is_present;
}
void pf_gps_positionextradetails_numberofsatellites_set_present(pf_gps_positionextradetails_t * self, bool is_present)
{
  self->f_numberofsatellites_is_present = is_present;
}
mal_integer_t pf_gps_positionextradetails_get_numberofsatellites(pf_gps_positionextradetails_t * self)
{
  return self->f_numberofsatellites;
}
void pf_gps_positionextradetails_set_numberofsatellites(pf_gps_positionextradetails_t * self, mal_integer_t f_numberofsatellites)
{
  self->f_numberofsatellites = f_numberofsatellites;
}
bool pf_gps_positionextradetails_hdop_is_present(pf_gps_positionextradetails_t * self)
{
  return self->f_hdop_is_present;
}
void pf_gps_positionextradetails_hdop_set_present(pf_gps_positionextradetails_t * self, bool is_present)
{
  self->f_hdop_is_present = is_present;
}
mal_float_t pf_gps_positionextradetails_get_hdop(pf_gps_positionextradetails_t * self)
{
  return self->f_hdop;
}
void pf_gps_positionextradetails_set_hdop(pf_gps_positionextradetails_t * self, mal_float_t f_hdop)
{
  self->f_hdop = f_hdop;
}
bool pf_gps_positionextradetails_undulation_is_present(pf_gps_positionextradetails_t * self)
{
  return self->f_undulation_is_present;
}
void pf_gps_positionextradetails_undulation_set_present(pf_gps_positionextradetails_t * self, bool is_present)
{
  self->f_undulation_is_present = is_present;
}
mal_float_t pf_gps_positionextradetails_get_undulation(pf_gps_positionextradetails_t * self)
{
  return self->f_undulation;
}
void pf_gps_positionextradetails_set_undulation(pf_gps_positionextradetails_t * self, mal_float_t f_undulation)
{
  self->f_undulation = f_undulation;
}

// default constructor
pf_gps_positionextradetails_t * pf_gps_positionextradetails_new(void)
{
  pf_gps_positionextradetails_t *self = (pf_gps_positionextradetails_t *) calloc(1, sizeof(pf_gps_positionextradetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_gps_positionextradetails_add_encoding_length_malbinary(pf_gps_positionextradetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_utc_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_utc_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_utc, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_fixquality_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_fixquality_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_fixquality, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_numberofsatellites_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_numberofsatellites_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_numberofsatellites, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_hdop_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_hdop_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_hdop, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_undulation_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_undulation_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_undulation, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_positionextradetails_encode_malbinary(pf_gps_positionextradetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_utc_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_utc);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_fixquality_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_fixquality);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_numberofsatellites_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_numberofsatellites);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_hdop_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_hdop);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_undulation_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_undulation);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_positionextradetails_decode_malbinary(pf_gps_positionextradetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_utc);
    if (rc < 0)
      return rc;
  }
  self->f_utc_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_fixquality);
    if (rc < 0)
      return rc;
  }
  self->f_fixquality_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_numberofsatellites);
    if (rc < 0)
      return rc;
  }
  self->f_numberofsatellites_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_hdop);
    if (rc < 0)
      return rc;
  }
  self->f_hdop_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_undulation);
    if (rc < 0)
      return rc;
  }
  self->f_undulation_is_present = presence_flag;
  return rc;
}

// destructor
void pf_gps_positionextradetails_destroy(pf_gps_positionextradetails_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_gps_positionextradetails_test(bool verbose)
{
  printf(" * PF:GPS:PositionExtraDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
