#include "pf.h"


// structure definition for composite pf_gps_position
struct _pf_gps_position_t {
  mal_float_t f_latitude;
  mal_float_t f_longitude;
  mal_float_t f_altitude;
  pf_gps_positionextradetails_t * f_extradetails;
};

// fields accessors for composite pf_gps_position
mal_float_t pf_gps_position_get_latitude(pf_gps_position_t * self)
{
  return self->f_latitude;
}
void pf_gps_position_set_latitude(pf_gps_position_t * self, mal_float_t f_latitude)
{
  self->f_latitude = f_latitude;
}
mal_float_t pf_gps_position_get_longitude(pf_gps_position_t * self)
{
  return self->f_longitude;
}
void pf_gps_position_set_longitude(pf_gps_position_t * self, mal_float_t f_longitude)
{
  self->f_longitude = f_longitude;
}
mal_float_t pf_gps_position_get_altitude(pf_gps_position_t * self)
{
  return self->f_altitude;
}
void pf_gps_position_set_altitude(pf_gps_position_t * self, mal_float_t f_altitude)
{
  self->f_altitude = f_altitude;
}
pf_gps_positionextradetails_t * pf_gps_position_get_extradetails(pf_gps_position_t * self)
{
  return self->f_extradetails;
}
void pf_gps_position_set_extradetails(pf_gps_position_t * self, pf_gps_positionextradetails_t * f_extradetails)
{
  self->f_extradetails = f_extradetails;
}

// default constructor
pf_gps_position_t * pf_gps_position_new(void)
{
  pf_gps_position_t *self = (pf_gps_position_t *) calloc(1, sizeof(pf_gps_position_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_gps_position_add_encoding_length_malbinary(pf_gps_position_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_latitude, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_longitude, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_altitude, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_extradetails != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_extradetails != NULL))
  {
    rc = pf_gps_positionextradetails_add_encoding_length_malbinary(self->f_extradetails, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_position_encode_malbinary(pf_gps_position_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_latitude);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_longitude);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_altitude);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_extradetails != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = pf_gps_positionextradetails_encode_malbinary(self->f_extradetails, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_position_decode_malbinary(pf_gps_position_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_latitude);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_longitude);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_altitude);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_extradetails = pf_gps_positionextradetails_new();
    if (self->f_extradetails == NULL) return -1;
    rc = pf_gps_positionextradetails_decode_malbinary(self->f_extradetails, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_extradetails = NULL;
  }
  return rc;
}

// destructor
void pf_gps_position_destroy(pf_gps_position_t ** self_p)
{
  if ((*self_p)->f_extradetails != NULL)
  {
    pf_gps_positionextradetails_destroy(& (*self_p)->f_extradetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_gps_position_test(bool verbose)
{
  printf(" * PF:GPS:Position: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
