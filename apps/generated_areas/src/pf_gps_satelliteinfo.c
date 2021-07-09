#include "pf.h"


// structure definition for composite pf_gps_satelliteinfo
struct _pf_gps_satelliteinfo_t {
  bool f_azimuth_is_present;
  mal_float_t f_azimuth;
  bool f_elevation_is_present;
  mal_float_t f_elevation;
  bool f_prn_is_present;
  mal_integer_t f_prn;
  bool f_almanac_is_present;
  mal_float_t f_almanac;
  bool f_ephemeris_is_present;
  mal_float_t f_ephemeris;
  bool f_recentfix_is_present;
  mal_time_t f_recentfix;
  bool f_svn_is_present;
  mal_uinteger_t f_svn;
};

// fields accessors for composite pf_gps_satelliteinfo
bool pf_gps_satelliteinfo_azimuth_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_azimuth_is_present;
}
void pf_gps_satelliteinfo_azimuth_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_azimuth_is_present = is_present;
}
mal_float_t pf_gps_satelliteinfo_get_azimuth(pf_gps_satelliteinfo_t * self)
{
  return self->f_azimuth;
}
void pf_gps_satelliteinfo_set_azimuth(pf_gps_satelliteinfo_t * self, mal_float_t f_azimuth)
{
  self->f_azimuth = f_azimuth;
}
bool pf_gps_satelliteinfo_elevation_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_elevation_is_present;
}
void pf_gps_satelliteinfo_elevation_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_elevation_is_present = is_present;
}
mal_float_t pf_gps_satelliteinfo_get_elevation(pf_gps_satelliteinfo_t * self)
{
  return self->f_elevation;
}
void pf_gps_satelliteinfo_set_elevation(pf_gps_satelliteinfo_t * self, mal_float_t f_elevation)
{
  self->f_elevation = f_elevation;
}
bool pf_gps_satelliteinfo_prn_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_prn_is_present;
}
void pf_gps_satelliteinfo_prn_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_prn_is_present = is_present;
}
mal_integer_t pf_gps_satelliteinfo_get_prn(pf_gps_satelliteinfo_t * self)
{
  return self->f_prn;
}
void pf_gps_satelliteinfo_set_prn(pf_gps_satelliteinfo_t * self, mal_integer_t f_prn)
{
  self->f_prn = f_prn;
}
bool pf_gps_satelliteinfo_almanac_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_almanac_is_present;
}
void pf_gps_satelliteinfo_almanac_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_almanac_is_present = is_present;
}
mal_float_t pf_gps_satelliteinfo_get_almanac(pf_gps_satelliteinfo_t * self)
{
  return self->f_almanac;
}
void pf_gps_satelliteinfo_set_almanac(pf_gps_satelliteinfo_t * self, mal_float_t f_almanac)
{
  self->f_almanac = f_almanac;
}
bool pf_gps_satelliteinfo_ephemeris_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_ephemeris_is_present;
}
void pf_gps_satelliteinfo_ephemeris_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_ephemeris_is_present = is_present;
}
mal_float_t pf_gps_satelliteinfo_get_ephemeris(pf_gps_satelliteinfo_t * self)
{
  return self->f_ephemeris;
}
void pf_gps_satelliteinfo_set_ephemeris(pf_gps_satelliteinfo_t * self, mal_float_t f_ephemeris)
{
  self->f_ephemeris = f_ephemeris;
}
bool pf_gps_satelliteinfo_recentfix_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_recentfix_is_present;
}
void pf_gps_satelliteinfo_recentfix_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_recentfix_is_present = is_present;
}
mal_time_t pf_gps_satelliteinfo_get_recentfix(pf_gps_satelliteinfo_t * self)
{
  return self->f_recentfix;
}
void pf_gps_satelliteinfo_set_recentfix(pf_gps_satelliteinfo_t * self, mal_time_t f_recentfix)
{
  self->f_recentfix = f_recentfix;
}
bool pf_gps_satelliteinfo_svn_is_present(pf_gps_satelliteinfo_t * self)
{
  return self->f_svn_is_present;
}
void pf_gps_satelliteinfo_svn_set_present(pf_gps_satelliteinfo_t * self, bool is_present)
{
  self->f_svn_is_present = is_present;
}
mal_uinteger_t pf_gps_satelliteinfo_get_svn(pf_gps_satelliteinfo_t * self)
{
  return self->f_svn;
}
void pf_gps_satelliteinfo_set_svn(pf_gps_satelliteinfo_t * self, mal_uinteger_t f_svn)
{
  self->f_svn = f_svn;
}

// default constructor
pf_gps_satelliteinfo_t * pf_gps_satelliteinfo_new(void)
{
  pf_gps_satelliteinfo_t *self = (pf_gps_satelliteinfo_t *) calloc(1, sizeof(pf_gps_satelliteinfo_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_gps_satelliteinfo_add_encoding_length_malbinary(pf_gps_satelliteinfo_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_azimuth_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_azimuth_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_azimuth, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_elevation_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_elevation_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_elevation, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_prn_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_prn_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_prn, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_almanac_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_almanac_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_almanac, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_ephemeris_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_ephemeris_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_ephemeris, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_recentfix_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_recentfix_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_recentfix, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_svn_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_svn_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_svn, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_satelliteinfo_encode_malbinary(pf_gps_satelliteinfo_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_azimuth_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_azimuth);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_elevation_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_elevation);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_prn_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_prn);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_almanac_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_almanac);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_ephemeris_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_ephemeris);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_recentfix_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_recentfix);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_svn_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_svn);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_satelliteinfo_decode_malbinary(pf_gps_satelliteinfo_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_azimuth);
    if (rc < 0)
      return rc;
  }
  self->f_azimuth_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_elevation);
    if (rc < 0)
      return rc;
  }
  self->f_elevation_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_prn);
    if (rc < 0)
      return rc;
  }
  self->f_prn_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_almanac);
    if (rc < 0)
      return rc;
  }
  self->f_almanac_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_ephemeris);
    if (rc < 0)
      return rc;
  }
  self->f_ephemeris_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_recentfix);
    if (rc < 0)
      return rc;
  }
  self->f_recentfix_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_svn);
    if (rc < 0)
      return rc;
  }
  self->f_svn_is_present = presence_flag;
  return rc;
}

// destructor
void pf_gps_satelliteinfo_destroy(pf_gps_satelliteinfo_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_gps_satelliteinfo_test(bool verbose)
{
  printf(" * PF:GPS:SatelliteInfo: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
