#include "pf.h"


// structure definition for composite pf_powercontrol_device
struct _pf_powercontrol_device_t {
  mal_boolean_t f_enabled;
  bool f_unitobjinstid_is_present;
  mal_long_t f_unitobjinstid;
  mal_identifier_t * f_name;
  pf_powercontrol_devicetype_t f_devicetype;
};

// fields accessors for composite pf_powercontrol_device
mal_boolean_t pf_powercontrol_device_get_enabled(pf_powercontrol_device_t * self)
{
  return self->f_enabled;
}
void pf_powercontrol_device_set_enabled(pf_powercontrol_device_t * self, mal_boolean_t f_enabled)
{
  self->f_enabled = f_enabled;
}
bool pf_powercontrol_device_unitobjinstid_is_present(pf_powercontrol_device_t * self)
{
  return self->f_unitobjinstid_is_present;
}
void pf_powercontrol_device_unitobjinstid_set_present(pf_powercontrol_device_t * self, bool is_present)
{
  self->f_unitobjinstid_is_present = is_present;
}
mal_long_t pf_powercontrol_device_get_unitobjinstid(pf_powercontrol_device_t * self)
{
  return self->f_unitobjinstid;
}
void pf_powercontrol_device_set_unitobjinstid(pf_powercontrol_device_t * self, mal_long_t f_unitobjinstid)
{
  self->f_unitobjinstid = f_unitobjinstid;
}
mal_identifier_t * pf_powercontrol_device_get_name(pf_powercontrol_device_t * self)
{
  return self->f_name;
}
void pf_powercontrol_device_set_name(pf_powercontrol_device_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
pf_powercontrol_devicetype_t pf_powercontrol_device_get_devicetype(pf_powercontrol_device_t * self)
{
  return self->f_devicetype;
}
void pf_powercontrol_device_set_devicetype(pf_powercontrol_device_t * self, pf_powercontrol_devicetype_t f_devicetype)
{
  self->f_devicetype = f_devicetype;
}

// default constructor
pf_powercontrol_device_t * pf_powercontrol_device_new(void)
{
  pf_powercontrol_device_t *self = (pf_powercontrol_device_t *) calloc(1, sizeof(pf_powercontrol_device_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_powercontrol_device_add_encoding_length_malbinary(pf_powercontrol_device_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_enabled, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_unitobjinstid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_unitobjinstid_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_unitobjinstid, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_name != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_name != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_devicetype, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_powercontrol_device_encode_malbinary(pf_powercontrol_device_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_enabled);
  if (rc < 0)
    return rc;
  presence_flag = self->f_unitobjinstid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_unitobjinstid);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_name != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_devicetype);
  if (rc < 0)
    return rc;
  return rc;
}
int pf_powercontrol_device_decode_malbinary(pf_powercontrol_device_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_enabled);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_unitobjinstid);
    if (rc < 0)
      return rc;
  }
  self->f_unitobjinstid_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_name = NULL;
  }
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_devicetype = (pf_powercontrol_devicetype_t) enumerated_value;
  return rc;
}

// destructor
void pf_powercontrol_device_destroy(pf_powercontrol_device_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_powercontrol_device_test(bool verbose)
{
  printf(" * PF:PowerControl:Device: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
