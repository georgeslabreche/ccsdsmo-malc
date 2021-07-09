#include "common.h"


// structure definition for composite common_directory_servicecapability
struct _common_directory_servicecapability_t {
  common_servicekey_t * f_servicekey;
  mal_ushort_list_t * f_supportedcapabilitysets;
  mal_namedvalue_list_t * f_serviceproperties;
  common_directory_addressdetails_list_t * f_serviceaddresses;
};

// fields accessors for composite common_directory_servicecapability
common_servicekey_t * common_directory_servicecapability_get_servicekey(common_directory_servicecapability_t * self)
{
  return self->f_servicekey;
}
void common_directory_servicecapability_set_servicekey(common_directory_servicecapability_t * self, common_servicekey_t * f_servicekey)
{
  self->f_servicekey = f_servicekey;
}
mal_ushort_list_t * common_directory_servicecapability_get_supportedcapabilitysets(common_directory_servicecapability_t * self)
{
  return self->f_supportedcapabilitysets;
}
void common_directory_servicecapability_set_supportedcapabilitysets(common_directory_servicecapability_t * self, mal_ushort_list_t * f_supportedcapabilitysets)
{
  self->f_supportedcapabilitysets = f_supportedcapabilitysets;
}
mal_namedvalue_list_t * common_directory_servicecapability_get_serviceproperties(common_directory_servicecapability_t * self)
{
  return self->f_serviceproperties;
}
void common_directory_servicecapability_set_serviceproperties(common_directory_servicecapability_t * self, mal_namedvalue_list_t * f_serviceproperties)
{
  self->f_serviceproperties = f_serviceproperties;
}
common_directory_addressdetails_list_t * common_directory_servicecapability_get_serviceaddresses(common_directory_servicecapability_t * self)
{
  return self->f_serviceaddresses;
}
void common_directory_servicecapability_set_serviceaddresses(common_directory_servicecapability_t * self, common_directory_addressdetails_list_t * f_serviceaddresses)
{
  self->f_serviceaddresses = f_serviceaddresses;
}

// default constructor
common_directory_servicecapability_t * common_directory_servicecapability_new(void)
{
  common_directory_servicecapability_t *self = (common_directory_servicecapability_t *) calloc(1, sizeof(common_directory_servicecapability_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_servicecapability_add_encoding_length_malbinary(common_directory_servicecapability_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = common_servicekey_add_encoding_length_malbinary(self->f_servicekey, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_supportedcapabilitysets != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_supportedcapabilitysets != NULL))
  {
    rc = mal_ushort_list_add_encoding_length_malbinary(self->f_supportedcapabilitysets, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_serviceproperties != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_serviceproperties != NULL))
  {
    rc = mal_namedvalue_list_add_encoding_length_malbinary(self->f_serviceproperties, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_serviceaddresses != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_serviceaddresses != NULL))
  {
    rc = common_directory_addressdetails_list_add_encoding_length_malbinary(self->f_serviceaddresses, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_servicecapability_encode_malbinary(common_directory_servicecapability_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = common_servicekey_encode_malbinary(self->f_servicekey, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_supportedcapabilitysets != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_ushort_list_encode_malbinary(self->f_supportedcapabilitysets, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_serviceproperties != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_namedvalue_list_encode_malbinary(self->f_serviceproperties, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_serviceaddresses != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = common_directory_addressdetails_list_encode_malbinary(self->f_serviceaddresses, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_servicecapability_decode_malbinary(common_directory_servicecapability_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  self->f_servicekey = common_servicekey_new();
  if (self->f_servicekey == NULL) return -1;
  rc = common_servicekey_decode_malbinary(self->f_servicekey, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_supportedcapabilitysets = mal_ushort_list_new(0);
    if (self->f_supportedcapabilitysets == NULL) return -1;
    rc = mal_ushort_list_decode_malbinary(self->f_supportedcapabilitysets, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_supportedcapabilitysets = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_serviceproperties = mal_namedvalue_list_new(0);
    if (self->f_serviceproperties == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary(self->f_serviceproperties, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_serviceproperties = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_serviceaddresses = common_directory_addressdetails_list_new(0);
    if (self->f_serviceaddresses == NULL) return -1;
    rc = common_directory_addressdetails_list_decode_malbinary(self->f_serviceaddresses, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_serviceaddresses = NULL;
  }
  return rc;
}

// destructor
void common_directory_servicecapability_destroy(common_directory_servicecapability_t ** self_p)
{
  if ((*self_p)->f_servicekey != NULL)
  {
    common_servicekey_destroy(& (*self_p)->f_servicekey);
  }
  if ((*self_p)->f_supportedcapabilitysets != NULL)
  {
    mal_ushort_list_destroy(& (*self_p)->f_supportedcapabilitysets);
  }
  if ((*self_p)->f_serviceproperties != NULL)
  {
    mal_namedvalue_list_destroy(& (*self_p)->f_serviceproperties);
  }
  if ((*self_p)->f_serviceaddresses != NULL)
  {
    common_directory_addressdetails_list_destroy(& (*self_p)->f_serviceaddresses);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_servicecapability_test(bool verbose)
{
  printf(" * Common:Directory:ServiceCapability: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
