#include "common.h"


// structure definition for composite common_directory_addressdetails
struct _common_directory_addressdetails_t {
  mal_qoslevel_list_t * f_supportedlevels;
  mal_namedvalue_list_t * f_qosproperties;
  mal_uinteger_t f_prioritylevels;
  mal_uri_t * f_serviceuri;
  mal_uri_t * f_brokeruri;
  bool f_brokerproviderobjinstid_is_present;
  mal_long_t f_brokerproviderobjinstid;
};

// fields accessors for composite common_directory_addressdetails
mal_qoslevel_list_t * common_directory_addressdetails_get_supportedlevels(common_directory_addressdetails_t * self)
{
  return self->f_supportedlevels;
}
void common_directory_addressdetails_set_supportedlevels(common_directory_addressdetails_t * self, mal_qoslevel_list_t * f_supportedlevels)
{
  self->f_supportedlevels = f_supportedlevels;
}
mal_namedvalue_list_t * common_directory_addressdetails_get_qosproperties(common_directory_addressdetails_t * self)
{
  return self->f_qosproperties;
}
void common_directory_addressdetails_set_qosproperties(common_directory_addressdetails_t * self, mal_namedvalue_list_t * f_qosproperties)
{
  self->f_qosproperties = f_qosproperties;
}
mal_uinteger_t common_directory_addressdetails_get_prioritylevels(common_directory_addressdetails_t * self)
{
  return self->f_prioritylevels;
}
void common_directory_addressdetails_set_prioritylevels(common_directory_addressdetails_t * self, mal_uinteger_t f_prioritylevels)
{
  self->f_prioritylevels = f_prioritylevels;
}
mal_uri_t * common_directory_addressdetails_get_serviceuri(common_directory_addressdetails_t * self)
{
  return self->f_serviceuri;
}
void common_directory_addressdetails_set_serviceuri(common_directory_addressdetails_t * self, mal_uri_t * f_serviceuri)
{
  self->f_serviceuri = f_serviceuri;
}
mal_uri_t * common_directory_addressdetails_get_brokeruri(common_directory_addressdetails_t * self)
{
  return self->f_brokeruri;
}
void common_directory_addressdetails_set_brokeruri(common_directory_addressdetails_t * self, mal_uri_t * f_brokeruri)
{
  self->f_brokeruri = f_brokeruri;
}
bool common_directory_addressdetails_brokerproviderobjinstid_is_present(common_directory_addressdetails_t * self)
{
  return self->f_brokerproviderobjinstid_is_present;
}
void common_directory_addressdetails_brokerproviderobjinstid_set_present(common_directory_addressdetails_t * self, bool is_present)
{
  self->f_brokerproviderobjinstid_is_present = is_present;
}
mal_long_t common_directory_addressdetails_get_brokerproviderobjinstid(common_directory_addressdetails_t * self)
{
  return self->f_brokerproviderobjinstid;
}
void common_directory_addressdetails_set_brokerproviderobjinstid(common_directory_addressdetails_t * self, mal_long_t f_brokerproviderobjinstid)
{
  self->f_brokerproviderobjinstid = f_brokerproviderobjinstid;
}

// default constructor
common_directory_addressdetails_t * common_directory_addressdetails_new(void)
{
  common_directory_addressdetails_t *self = (common_directory_addressdetails_t *) calloc(1, sizeof(common_directory_addressdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_addressdetails_add_encoding_length_malbinary(common_directory_addressdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_qoslevel_list_add_encoding_length_malbinary(self->f_supportedlevels, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_namedvalue_list_add_encoding_length_malbinary(self->f_qosproperties, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_prioritylevels, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_serviceuri != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_serviceuri != NULL))
  {
    rc = mal_encoder_add_uri_encoding_length(encoder, self->f_serviceuri, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_brokeruri != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_brokeruri != NULL))
  {
    rc = mal_encoder_add_uri_encoding_length(encoder, self->f_brokeruri, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_brokerproviderobjinstid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_brokerproviderobjinstid_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_brokerproviderobjinstid, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_addressdetails_encode_malbinary(common_directory_addressdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_qoslevel_list_encode_malbinary(self->f_supportedlevels, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_namedvalue_list_encode_malbinary(self->f_qosproperties, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_prioritylevels);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_serviceuri != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uri(encoder, cursor, self->f_serviceuri);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_brokeruri != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uri(encoder, cursor, self->f_brokeruri);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_brokerproviderobjinstid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_brokerproviderobjinstid);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_addressdetails_decode_malbinary(common_directory_addressdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  self->f_supportedlevels = mal_qoslevel_list_new(0);
  if (self->f_supportedlevels == NULL) return -1;
  rc = mal_qoslevel_list_decode_malbinary(self->f_supportedlevels, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_qosproperties = mal_namedvalue_list_new(0);
  if (self->f_qosproperties == NULL) return -1;
  rc = mal_namedvalue_list_decode_malbinary(self->f_qosproperties, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_prioritylevels);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uri(decoder, cursor, &self->f_serviceuri);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_serviceuri = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uri(decoder, cursor, &self->f_brokeruri);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_brokeruri = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_brokerproviderobjinstid);
    if (rc < 0)
      return rc;
  }
  self->f_brokerproviderobjinstid_is_present = presence_flag;
  return rc;
}

// destructor
void common_directory_addressdetails_destroy(common_directory_addressdetails_t ** self_p)
{
  if ((*self_p)->f_supportedlevels != NULL)
  {
    mal_qoslevel_list_destroy(& (*self_p)->f_supportedlevels);
  }
  if ((*self_p)->f_qosproperties != NULL)
  {
    mal_namedvalue_list_destroy(& (*self_p)->f_qosproperties);
  }
  if ((*self_p)->f_serviceuri != NULL)
  {
    mal_uri_destroy(& (*self_p)->f_serviceuri);
  }
  if ((*self_p)->f_brokeruri != NULL)
  {
    mal_uri_destroy(& (*self_p)->f_brokeruri);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_addressdetails_test(bool verbose)
{
  printf(" * Common:Directory:AddressDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
