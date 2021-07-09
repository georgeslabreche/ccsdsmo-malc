#include "pf.h"


// structure definition for composite pf_softwaredefinedradio_sdrconfiguration
struct _pf_softwaredefinedradio_sdrconfiguration_t {
  bool f_rxcarrierfrequency_is_present;
  mal_float_t f_rxcarrierfrequency;
  bool f_rxgain_is_present;
  mal_integer_t f_rxgain;
  bool f_rxlowpassbw_is_present;
  mal_float_t f_rxlowpassbw;
  bool f_rxsamplingfrequency_is_present;
  mal_float_t f_rxsamplingfrequency;
};

// fields accessors for composite pf_softwaredefinedradio_sdrconfiguration
bool pf_softwaredefinedradio_sdrconfiguration_rxcarrierfrequency_is_present(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxcarrierfrequency_is_present;
}
void pf_softwaredefinedradio_sdrconfiguration_rxcarrierfrequency_set_present(pf_softwaredefinedradio_sdrconfiguration_t * self, bool is_present)
{
  self->f_rxcarrierfrequency_is_present = is_present;
}
mal_float_t pf_softwaredefinedradio_sdrconfiguration_get_rxcarrierfrequency(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxcarrierfrequency;
}
void pf_softwaredefinedradio_sdrconfiguration_set_rxcarrierfrequency(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_float_t f_rxcarrierfrequency)
{
  self->f_rxcarrierfrequency = f_rxcarrierfrequency;
}
bool pf_softwaredefinedradio_sdrconfiguration_rxgain_is_present(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxgain_is_present;
}
void pf_softwaredefinedradio_sdrconfiguration_rxgain_set_present(pf_softwaredefinedradio_sdrconfiguration_t * self, bool is_present)
{
  self->f_rxgain_is_present = is_present;
}
mal_integer_t pf_softwaredefinedradio_sdrconfiguration_get_rxgain(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxgain;
}
void pf_softwaredefinedradio_sdrconfiguration_set_rxgain(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_integer_t f_rxgain)
{
  self->f_rxgain = f_rxgain;
}
bool pf_softwaredefinedradio_sdrconfiguration_rxlowpassbw_is_present(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxlowpassbw_is_present;
}
void pf_softwaredefinedradio_sdrconfiguration_rxlowpassbw_set_present(pf_softwaredefinedradio_sdrconfiguration_t * self, bool is_present)
{
  self->f_rxlowpassbw_is_present = is_present;
}
mal_float_t pf_softwaredefinedradio_sdrconfiguration_get_rxlowpassbw(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxlowpassbw;
}
void pf_softwaredefinedradio_sdrconfiguration_set_rxlowpassbw(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_float_t f_rxlowpassbw)
{
  self->f_rxlowpassbw = f_rxlowpassbw;
}
bool pf_softwaredefinedradio_sdrconfiguration_rxsamplingfrequency_is_present(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxsamplingfrequency_is_present;
}
void pf_softwaredefinedradio_sdrconfiguration_rxsamplingfrequency_set_present(pf_softwaredefinedradio_sdrconfiguration_t * self, bool is_present)
{
  self->f_rxsamplingfrequency_is_present = is_present;
}
mal_float_t pf_softwaredefinedradio_sdrconfiguration_get_rxsamplingfrequency(pf_softwaredefinedradio_sdrconfiguration_t * self)
{
  return self->f_rxsamplingfrequency;
}
void pf_softwaredefinedradio_sdrconfiguration_set_rxsamplingfrequency(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_float_t f_rxsamplingfrequency)
{
  self->f_rxsamplingfrequency = f_rxsamplingfrequency;
}

// default constructor
pf_softwaredefinedradio_sdrconfiguration_t * pf_softwaredefinedradio_sdrconfiguration_new(void)
{
  pf_softwaredefinedradio_sdrconfiguration_t *self = (pf_softwaredefinedradio_sdrconfiguration_t *) calloc(1, sizeof(pf_softwaredefinedradio_sdrconfiguration_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_softwaredefinedradio_sdrconfiguration_add_encoding_length_malbinary(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rxcarrierfrequency_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rxcarrierfrequency_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_rxcarrierfrequency, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rxgain_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rxgain_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->f_rxgain, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rxlowpassbw_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rxlowpassbw_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_rxlowpassbw, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rxsamplingfrequency_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rxsamplingfrequency_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_rxsamplingfrequency, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_softwaredefinedradio_sdrconfiguration_encode_malbinary(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_rxcarrierfrequency_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_rxcarrierfrequency);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_rxgain_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->f_rxgain);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_rxlowpassbw_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_rxlowpassbw);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_rxsamplingfrequency_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_rxsamplingfrequency);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_softwaredefinedradio_sdrconfiguration_decode_malbinary(pf_softwaredefinedradio_sdrconfiguration_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_rxcarrierfrequency);
    if (rc < 0)
      return rc;
  }
  self->f_rxcarrierfrequency_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->f_rxgain);
    if (rc < 0)
      return rc;
  }
  self->f_rxgain_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_rxlowpassbw);
    if (rc < 0)
      return rc;
  }
  self->f_rxlowpassbw_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_rxsamplingfrequency);
    if (rc < 0)
      return rc;
  }
  self->f_rxsamplingfrequency_is_present = presence_flag;
  return rc;
}

// destructor
void pf_softwaredefinedradio_sdrconfiguration_destroy(pf_softwaredefinedradio_sdrconfiguration_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_softwaredefinedradio_sdrconfiguration_test(bool verbose)
{
  printf(" * PF:SoftwareDefinedRadio:SDRConfiguration: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
