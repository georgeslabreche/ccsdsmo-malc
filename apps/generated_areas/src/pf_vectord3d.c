#include "pf.h"


// structure definition for composite pf_vectord3d
struct _pf_vectord3d_t {
  bool f_x_is_present;
  mal_double_t f_x;
  bool f_y_is_present;
  mal_double_t f_y;
  bool f_z_is_present;
  mal_double_t f_z;
};

// fields accessors for composite pf_vectord3d
bool pf_vectord3d_x_is_present(pf_vectord3d_t * self)
{
  return self->f_x_is_present;
}
void pf_vectord3d_x_set_present(pf_vectord3d_t * self, bool is_present)
{
  self->f_x_is_present = is_present;
}
mal_double_t pf_vectord3d_get_x(pf_vectord3d_t * self)
{
  return self->f_x;
}
void pf_vectord3d_set_x(pf_vectord3d_t * self, mal_double_t f_x)
{
  self->f_x = f_x;
}
bool pf_vectord3d_y_is_present(pf_vectord3d_t * self)
{
  return self->f_y_is_present;
}
void pf_vectord3d_y_set_present(pf_vectord3d_t * self, bool is_present)
{
  self->f_y_is_present = is_present;
}
mal_double_t pf_vectord3d_get_y(pf_vectord3d_t * self)
{
  return self->f_y;
}
void pf_vectord3d_set_y(pf_vectord3d_t * self, mal_double_t f_y)
{
  self->f_y = f_y;
}
bool pf_vectord3d_z_is_present(pf_vectord3d_t * self)
{
  return self->f_z_is_present;
}
void pf_vectord3d_z_set_present(pf_vectord3d_t * self, bool is_present)
{
  self->f_z_is_present = is_present;
}
mal_double_t pf_vectord3d_get_z(pf_vectord3d_t * self)
{
  return self->f_z;
}
void pf_vectord3d_set_z(pf_vectord3d_t * self, mal_double_t f_z)
{
  self->f_z = f_z;
}

// default constructor
pf_vectord3d_t * pf_vectord3d_new(void)
{
  pf_vectord3d_t *self = (pf_vectord3d_t *) calloc(1, sizeof(pf_vectord3d_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_vectord3d_add_encoding_length_malbinary(pf_vectord3d_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_x_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_x_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_x, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_y_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_y_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_y, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_z_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_z_is_present)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, self->f_z, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_vectord3d_encode_malbinary(pf_vectord3d_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_x_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_x);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_y_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_y);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_z_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_double(encoder, cursor, self->f_z);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_vectord3d_decode_malbinary(pf_vectord3d_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_x);
    if (rc < 0)
      return rc;
  }
  self->f_x_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_y);
    if (rc < 0)
      return rc;
  }
  self->f_y_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &self->f_z);
    if (rc < 0)
      return rc;
  }
  self->f_z_is_present = presence_flag;
  return rc;
}

// destructor
void pf_vectord3d_destroy(pf_vectord3d_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_vectord3d_test(bool verbose)
{
  printf(" * PF:VectorD3D: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
