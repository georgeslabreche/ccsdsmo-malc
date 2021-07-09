#include "pf.h"


// structure definition for composite pf_camera_pixelresolution
struct _pf_camera_pixelresolution_t {
  mal_uinteger_t f_width;
  mal_uinteger_t f_height;
};

// fields accessors for composite pf_camera_pixelresolution
mal_uinteger_t pf_camera_pixelresolution_get_width(pf_camera_pixelresolution_t * self)
{
  return self->f_width;
}
void pf_camera_pixelresolution_set_width(pf_camera_pixelresolution_t * self, mal_uinteger_t f_width)
{
  self->f_width = f_width;
}
mal_uinteger_t pf_camera_pixelresolution_get_height(pf_camera_pixelresolution_t * self)
{
  return self->f_height;
}
void pf_camera_pixelresolution_set_height(pf_camera_pixelresolution_t * self, mal_uinteger_t f_height)
{
  self->f_height = f_height;
}

// default constructor
pf_camera_pixelresolution_t * pf_camera_pixelresolution_new(void)
{
  pf_camera_pixelresolution_t *self = (pf_camera_pixelresolution_t *) calloc(1, sizeof(pf_camera_pixelresolution_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_camera_pixelresolution_add_encoding_length_malbinary(pf_camera_pixelresolution_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_width, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_height, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_pixelresolution_encode_malbinary(pf_camera_pixelresolution_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_width);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_height);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_pixelresolution_decode_malbinary(pf_camera_pixelresolution_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_width);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_height);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_camera_pixelresolution_destroy(pf_camera_pixelresolution_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_camera_pixelresolution_test(bool verbose)
{
  printf(" * PF:Camera:PixelResolution: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
