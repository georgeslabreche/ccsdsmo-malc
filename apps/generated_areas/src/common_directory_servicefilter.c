#include "common.h"


// structure definition for composite common_directory_servicefilter
struct _common_directory_servicefilter_t {
  mal_identifier_t * f_serviceproviderid;
  mal_identifier_list_t * f_domain;
  mal_identifier_t * f_network;
  bool f_sessiontype_is_present;
  mal_sessiontype_t f_sessiontype;
  mal_identifier_t * f_sessionname;
  common_servicekey_t * f_servicekey;
  mal_ushort_list_t * f_requiredcapabilitysets;
};

// fields accessors for composite common_directory_servicefilter
mal_identifier_t * common_directory_servicefilter_get_serviceproviderid(common_directory_servicefilter_t * self)
{
  return self->f_serviceproviderid;
}
void common_directory_servicefilter_set_serviceproviderid(common_directory_servicefilter_t * self, mal_identifier_t * f_serviceproviderid)
{
  self->f_serviceproviderid = f_serviceproviderid;
}
mal_identifier_list_t * common_directory_servicefilter_get_domain(common_directory_servicefilter_t * self)
{
  return self->f_domain;
}
void common_directory_servicefilter_set_domain(common_directory_servicefilter_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_identifier_t * common_directory_servicefilter_get_network(common_directory_servicefilter_t * self)
{
  return self->f_network;
}
void common_directory_servicefilter_set_network(common_directory_servicefilter_t * self, mal_identifier_t * f_network)
{
  self->f_network = f_network;
}
bool common_directory_servicefilter_sessiontype_is_present(common_directory_servicefilter_t * self)
{
  return self->f_sessiontype_is_present;
}
void common_directory_servicefilter_sessiontype_set_present(common_directory_servicefilter_t * self, bool is_present)
{
  self->f_sessiontype_is_present = is_present;
}
mal_sessiontype_t common_directory_servicefilter_get_sessiontype(common_directory_servicefilter_t * self)
{
  return self->f_sessiontype;
}
void common_directory_servicefilter_set_sessiontype(common_directory_servicefilter_t * self, mal_sessiontype_t f_sessiontype)
{
  self->f_sessiontype = f_sessiontype;
}
mal_identifier_t * common_directory_servicefilter_get_sessionname(common_directory_servicefilter_t * self)
{
  return self->f_sessionname;
}
void common_directory_servicefilter_set_sessionname(common_directory_servicefilter_t * self, mal_identifier_t * f_sessionname)
{
  self->f_sessionname = f_sessionname;
}
common_servicekey_t * common_directory_servicefilter_get_servicekey(common_directory_servicefilter_t * self)
{
  return self->f_servicekey;
}
void common_directory_servicefilter_set_servicekey(common_directory_servicefilter_t * self, common_servicekey_t * f_servicekey)
{
  self->f_servicekey = f_servicekey;
}
mal_ushort_list_t * common_directory_servicefilter_get_requiredcapabilitysets(common_directory_servicefilter_t * self)
{
  return self->f_requiredcapabilitysets;
}
void common_directory_servicefilter_set_requiredcapabilitysets(common_directory_servicefilter_t * self, mal_ushort_list_t * f_requiredcapabilitysets)
{
  self->f_requiredcapabilitysets = f_requiredcapabilitysets;
}

// default constructor
common_directory_servicefilter_t * common_directory_servicefilter_new(void)
{
  common_directory_servicefilter_t *self = (common_directory_servicefilter_t *) calloc(1, sizeof(common_directory_servicefilter_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_servicefilter_add_encoding_length_malbinary(common_directory_servicefilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_serviceproviderid != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_serviceproviderid != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_serviceproviderid, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_domain != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_domain != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_network != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_network != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_network, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_sessiontype_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_sessiontype_is_present)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_sessiontype, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_sessionname != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_sessionname != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_sessionname, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_servicekey != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_servicekey != NULL))
  {
    rc = common_servicekey_add_encoding_length_malbinary(self->f_servicekey, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_requiredcapabilitysets != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_requiredcapabilitysets != NULL))
  {
    rc = mal_ushort_list_add_encoding_length_malbinary(self->f_requiredcapabilitysets, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_servicefilter_encode_malbinary(common_directory_servicefilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_serviceproviderid != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_serviceproviderid);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_domain != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_network != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_network);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_sessiontype_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_sessiontype);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_sessionname != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_sessionname);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_servicekey != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = common_servicekey_encode_malbinary(self->f_servicekey, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_requiredcapabilitysets != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_ushort_list_encode_malbinary(self->f_requiredcapabilitysets, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_servicefilter_decode_malbinary(common_directory_servicefilter_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_serviceproviderid);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_serviceproviderid = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_domain = mal_identifier_list_new(0);
    if (self->f_domain == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_domain = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_network);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_network = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    self->f_sessiontype = (mal_sessiontype_t) enumerated_value;
  }
  self->f_sessiontype_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_sessionname);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_sessionname = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_servicekey = common_servicekey_new();
    if (self->f_servicekey == NULL) return -1;
    rc = common_servicekey_decode_malbinary(self->f_servicekey, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_servicekey = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_requiredcapabilitysets = mal_ushort_list_new(0);
    if (self->f_requiredcapabilitysets == NULL) return -1;
    rc = mal_ushort_list_decode_malbinary(self->f_requiredcapabilitysets, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_requiredcapabilitysets = NULL;
  }
  return rc;
}

// destructor
void common_directory_servicefilter_destroy(common_directory_servicefilter_t ** self_p)
{
  if ((*self_p)->f_serviceproviderid != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_serviceproviderid);
  }
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_network != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_network);
  }
  if ((*self_p)->f_sessionname != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_sessionname);
  }
  if ((*self_p)->f_servicekey != NULL)
  {
    common_servicekey_destroy(& (*self_p)->f_servicekey);
  }
  if ((*self_p)->f_requiredcapabilitysets != NULL)
  {
    mal_ushort_list_destroy(& (*self_p)->f_requiredcapabilitysets);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_servicefilter_test(bool verbose)
{
  printf(" * Common:Directory:ServiceFilter: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
