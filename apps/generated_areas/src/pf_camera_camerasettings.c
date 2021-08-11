#include "pf.h"


// structure definition for composite pf_camera_camerasettings
struct _pf_camera_camerasettings_t {
  pf_camera_pixelresolution_t * f_resolution;
  pf_camera_pictureformat_t f_format;
  mal_duration_t f_exposuretime;
  mal_float_t f_gainred;
  mal_float_t f_gaingreen;
  mal_float_t f_gainblue;
};

// fields accessors for composite pf_camera_camerasettings
pf_camera_pixelresolution_t * pf_camera_camerasettings_get_resolution(pf_camera_camerasettings_t * self)
{
  return self->f_resolution;
}
void pf_camera_camerasettings_set_resolution(pf_camera_camerasettings_t * self, pf_camera_pixelresolution_t * f_resolution)
{
  self->f_resolution = f_resolution;
}
pf_camera_pictureformat_t pf_camera_camerasettings_get_format(pf_camera_camerasettings_t * self)
{
  return self->f_format;
}
void pf_camera_camerasettings_set_format(pf_camera_camerasettings_t * self, pf_camera_pictureformat_t f_format)
{
  self->f_format = f_format;
}
mal_duration_t pf_camera_camerasettings_get_exposuretime(pf_camera_camerasettings_t * self)
{
  return self->f_exposuretime;
}
void pf_camera_camerasettings_set_exposuretime(pf_camera_camerasettings_t * self, mal_duration_t f_exposuretime)
{
  self->f_exposuretime = f_exposuretime;
}
mal_float_t pf_camera_camerasettings_get_gainred(pf_camera_camerasettings_t * self)
{
  return self->f_gainred;
}
void pf_camera_camerasettings_set_gainred(pf_camera_camerasettings_t * self, mal_float_t f_gainred)
{
  self->f_gainred = f_gainred;
}
mal_float_t pf_camera_camerasettings_get_gaingreen(pf_camera_camerasettings_t * self)
{
  return self->f_gaingreen;
}
void pf_camera_camerasettings_set_gaingreen(pf_camera_camerasettings_t * self, mal_float_t f_gaingreen)
{
  self->f_gaingreen = f_gaingreen;
}
mal_float_t pf_camera_camerasettings_get_gainblue(pf_camera_camerasettings_t * self)
{
  return self->f_gainblue;
}
void pf_camera_camerasettings_set_gainblue(pf_camera_camerasettings_t * self, mal_float_t f_gainblue)
{
  self->f_gainblue = f_gainblue;
}

// default constructor
pf_camera_camerasettings_t * pf_camera_camerasettings_new(void)
{
  pf_camera_camerasettings_t *self = (pf_camera_camerasettings_t *) calloc(1, sizeof(pf_camera_camerasettings_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_camera_camerasettings_add_encoding_length_malbinary(pf_camera_camerasettings_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_camera_pixelresolution_add_encoding_length_malbinary(self->f_resolution, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_format, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_exposuretime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_gainred, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_gaingreen, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_float_encoding_length(encoder, self->f_gainblue, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_camerasettings_encode_malbinary(pf_camera_camerasettings_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = pf_camera_pixelresolution_encode_malbinary(self->f_resolution, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_format);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_exposuretime);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_gainred);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_gaingreen);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_float(encoder, cursor, self->f_gainblue);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_camerasettings_decode_malbinary(pf_camera_camerasettings_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  self->f_resolution = pf_camera_pixelresolution_new();
  if (self->f_resolution == NULL) return -1;
  rc = pf_camera_pixelresolution_decode_malbinary(self->f_resolution, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_format = (pf_camera_pictureformat_t) enumerated_value;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_exposuretime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_gainred);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_gaingreen);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_float(decoder, cursor, &self->f_gainblue);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_camera_camerasettings_destroy(pf_camera_camerasettings_t ** self_p)
{
  if ((*self_p)->f_resolution != NULL)
  {
    pf_camera_pixelresolution_destroy(& (*self_p)->f_resolution);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_camera_camerasettings_test(bool verbose)
{
  printf(" * PF:Camera:CameraSettings: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
