#include "pf.h"


// structure definition for composite pf_camera_picture
struct _pf_camera_picture_t {
  bool f_timestamp_is_present;
  mal_time_t f_timestamp;
  pf_camera_camerasettings_t * f_settings;
  mal_blob_t * f_content;
};

// fields accessors for composite pf_camera_picture
bool pf_camera_picture_timestamp_is_present(pf_camera_picture_t * self)
{
  return self->f_timestamp_is_present;
}
void pf_camera_picture_timestamp_set_present(pf_camera_picture_t * self, bool is_present)
{
  self->f_timestamp_is_present = is_present;
}
mal_time_t pf_camera_picture_get_timestamp(pf_camera_picture_t * self)
{
  return self->f_timestamp;
}
void pf_camera_picture_set_timestamp(pf_camera_picture_t * self, mal_time_t f_timestamp)
{
  self->f_timestamp = f_timestamp;
}
pf_camera_camerasettings_t * pf_camera_picture_get_settings(pf_camera_picture_t * self)
{
  return self->f_settings;
}
void pf_camera_picture_set_settings(pf_camera_picture_t * self, pf_camera_camerasettings_t * f_settings)
{
  self->f_settings = f_settings;
}
mal_blob_t * pf_camera_picture_get_content(pf_camera_picture_t * self)
{
  return self->f_content;
}
void pf_camera_picture_set_content(pf_camera_picture_t * self, mal_blob_t * f_content)
{
  self->f_content = f_content;
}

// default constructor
pf_camera_picture_t * pf_camera_picture_new(void)
{
  pf_camera_picture_t *self = (pf_camera_picture_t *) calloc(1, sizeof(pf_camera_picture_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_camera_picture_add_encoding_length_malbinary(pf_camera_picture_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_timestamp_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_timestamp_is_present)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, self->f_timestamp, cursor);
    if (rc < 0)
      return rc;
  }
  rc = pf_camera_camerasettings_add_encoding_length_malbinary(self->f_settings, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_blob_encoding_length(encoder, self->f_content, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_picture_encode_malbinary(pf_camera_picture_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_timestamp_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_time(encoder, cursor, self->f_timestamp);
    if (rc < 0)
      return rc;
  }
  rc = pf_camera_camerasettings_encode_malbinary(self->f_settings, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_blob(encoder, cursor, self->f_content);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_camera_picture_decode_malbinary(pf_camera_picture_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &self->f_timestamp);
    if (rc < 0)
      return rc;
  }
  self->f_timestamp_is_present = presence_flag;
  self->f_settings = pf_camera_camerasettings_new();
  if (self->f_settings == NULL) return -1;
  rc = pf_camera_camerasettings_decode_malbinary(self->f_settings, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_blob(decoder, cursor, &self->f_content);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void pf_camera_picture_destroy(pf_camera_picture_t ** self_p)
{
  if ((*self_p)->f_settings != NULL)
  {
    pf_camera_camerasettings_destroy(& (*self_p)->f_settings);
  }
  if ((*self_p)->f_content != NULL)
  {
    mal_blob_destroy(& (*self_p)->f_content);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_camera_picture_test(bool verbose)
{
  printf(" * PF:Camera:Picture: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
