#include "pf.h"


// structure definition for composite pf_softwaredefinedradio_iqcomponents
struct _pf_softwaredefinedradio_iqcomponents_t {
  mal_float_list_t * f_inphase;
  mal_float_list_t * f_quadrature;
};

// fields accessors for composite pf_softwaredefinedradio_iqcomponents
mal_float_list_t * pf_softwaredefinedradio_iqcomponents_get_inphase(pf_softwaredefinedradio_iqcomponents_t * self)
{
  return self->f_inphase;
}
void pf_softwaredefinedradio_iqcomponents_set_inphase(pf_softwaredefinedradio_iqcomponents_t * self, mal_float_list_t * f_inphase)
{
  self->f_inphase = f_inphase;
}
mal_float_list_t * pf_softwaredefinedradio_iqcomponents_get_quadrature(pf_softwaredefinedradio_iqcomponents_t * self)
{
  return self->f_quadrature;
}
void pf_softwaredefinedradio_iqcomponents_set_quadrature(pf_softwaredefinedradio_iqcomponents_t * self, mal_float_list_t * f_quadrature)
{
  self->f_quadrature = f_quadrature;
}

// default constructor
pf_softwaredefinedradio_iqcomponents_t * pf_softwaredefinedradio_iqcomponents_new(void)
{
  pf_softwaredefinedradio_iqcomponents_t *self = (pf_softwaredefinedradio_iqcomponents_t *) calloc(1, sizeof(pf_softwaredefinedradio_iqcomponents_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_softwaredefinedradio_iqcomponents_add_encoding_length_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_inphase != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_inphase != NULL))
  {
    rc = mal_float_list_add_encoding_length_malbinary(self->f_inphase, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_quadrature != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_quadrature != NULL))
  {
    rc = mal_float_list_add_encoding_length_malbinary(self->f_quadrature, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_softwaredefinedradio_iqcomponents_encode_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_inphase != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_float_list_encode_malbinary(self->f_inphase, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_quadrature != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_float_list_encode_malbinary(self->f_quadrature, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_softwaredefinedradio_iqcomponents_decode_malbinary(pf_softwaredefinedradio_iqcomponents_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_inphase = mal_float_list_new(0);
    if (self->f_inphase == NULL) return -1;
    rc = mal_float_list_decode_malbinary(self->f_inphase, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_inphase = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_quadrature = mal_float_list_new(0);
    if (self->f_quadrature == NULL) return -1;
    rc = mal_float_list_decode_malbinary(self->f_quadrature, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_quadrature = NULL;
  }
  return rc;
}

// destructor
void pf_softwaredefinedradio_iqcomponents_destroy(pf_softwaredefinedradio_iqcomponents_t ** self_p)
{
  if ((*self_p)->f_inphase != NULL)
  {
    mal_float_list_destroy(& (*self_p)->f_inphase);
  }
  if ((*self_p)->f_quadrature != NULL)
  {
    mal_float_list_destroy(& (*self_p)->f_quadrature);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_softwaredefinedradio_iqcomponents_test(bool verbose)
{
  printf(" * PF:SoftwareDefinedRadio:IQComponents: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
