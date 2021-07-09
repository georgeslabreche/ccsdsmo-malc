#include "common.h"


// structure definition for composite common_directory_publishdetails
struct _common_directory_publishdetails_t {
  mal_identifier_t * f_providerid;
  mal_identifier_list_t * f_domain;
  mal_sessiontype_t f_sessiontype;
  mal_identifier_t * f_sourcesessionname;
  mal_identifier_t * f_network;
  common_directory_providerdetails_t * f_providerdetails;
  mal_file_list_t * f_servicexml;
};

// fields accessors for composite common_directory_publishdetails
mal_identifier_t * common_directory_publishdetails_get_providerid(common_directory_publishdetails_t * self)
{
  return self->f_providerid;
}
void common_directory_publishdetails_set_providerid(common_directory_publishdetails_t * self, mal_identifier_t * f_providerid)
{
  self->f_providerid = f_providerid;
}
mal_identifier_list_t * common_directory_publishdetails_get_domain(common_directory_publishdetails_t * self)
{
  return self->f_domain;
}
void common_directory_publishdetails_set_domain(common_directory_publishdetails_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_sessiontype_t common_directory_publishdetails_get_sessiontype(common_directory_publishdetails_t * self)
{
  return self->f_sessiontype;
}
void common_directory_publishdetails_set_sessiontype(common_directory_publishdetails_t * self, mal_sessiontype_t f_sessiontype)
{
  self->f_sessiontype = f_sessiontype;
}
mal_identifier_t * common_directory_publishdetails_get_sourcesessionname(common_directory_publishdetails_t * self)
{
  return self->f_sourcesessionname;
}
void common_directory_publishdetails_set_sourcesessionname(common_directory_publishdetails_t * self, mal_identifier_t * f_sourcesessionname)
{
  self->f_sourcesessionname = f_sourcesessionname;
}
mal_identifier_t * common_directory_publishdetails_get_network(common_directory_publishdetails_t * self)
{
  return self->f_network;
}
void common_directory_publishdetails_set_network(common_directory_publishdetails_t * self, mal_identifier_t * f_network)
{
  self->f_network = f_network;
}
common_directory_providerdetails_t * common_directory_publishdetails_get_providerdetails(common_directory_publishdetails_t * self)
{
  return self->f_providerdetails;
}
void common_directory_publishdetails_set_providerdetails(common_directory_publishdetails_t * self, common_directory_providerdetails_t * f_providerdetails)
{
  self->f_providerdetails = f_providerdetails;
}
mal_file_list_t * common_directory_publishdetails_get_servicexml(common_directory_publishdetails_t * self)
{
  return self->f_servicexml;
}
void common_directory_publishdetails_set_servicexml(common_directory_publishdetails_t * self, mal_file_list_t * f_servicexml)
{
  self->f_servicexml = f_servicexml;
}

// default constructor
common_directory_publishdetails_t * common_directory_publishdetails_new(void)
{
  common_directory_publishdetails_t *self = (common_directory_publishdetails_t *) calloc(1, sizeof(common_directory_publishdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_publishdetails_add_encoding_length_malbinary(common_directory_publishdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_providerid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_sessiontype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_sourcesessionname != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_sourcesessionname != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_sourcesessionname, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_network, cursor);
  if (rc < 0)
    return rc;
  rc = common_directory_providerdetails_add_encoding_length_malbinary(self->f_providerdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_servicexml != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_servicexml != NULL))
  {
    rc = mal_file_list_add_encoding_length_malbinary(self->f_servicexml, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_publishdetails_encode_malbinary(common_directory_publishdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_providerid);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_sessiontype);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_sourcesessionname != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_sourcesessionname);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_network);
  if (rc < 0)
    return rc;
  rc = common_directory_providerdetails_encode_malbinary(self->f_providerdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_servicexml != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_file_list_encode_malbinary(self->f_servicexml, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int common_directory_publishdetails_decode_malbinary(common_directory_publishdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_providerid);
  if (rc < 0)
    return rc;
  self->f_domain = mal_identifier_list_new(0);
  if (self->f_domain == NULL) return -1;
  rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_sessiontype = (mal_sessiontype_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_sourcesessionname);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_sourcesessionname = NULL;
  }
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_network);
  if (rc < 0)
    return rc;
  self->f_providerdetails = common_directory_providerdetails_new();
  if (self->f_providerdetails == NULL) return -1;
  rc = common_directory_providerdetails_decode_malbinary(self->f_providerdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_servicexml = mal_file_list_new(0);
    if (self->f_servicexml == NULL) return -1;
    rc = mal_file_list_decode_malbinary(self->f_servicexml, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_servicexml = NULL;
  }
  return rc;
}

// destructor
void common_directory_publishdetails_destroy(common_directory_publishdetails_t ** self_p)
{
  if ((*self_p)->f_providerid != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_providerid);
  }
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_sourcesessionname != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_sourcesessionname);
  }
  if ((*self_p)->f_network != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_network);
  }
  if ((*self_p)->f_providerdetails != NULL)
  {
    common_directory_providerdetails_destroy(& (*self_p)->f_providerdetails);
  }
  if ((*self_p)->f_servicexml != NULL)
  {
    mal_file_list_destroy(& (*self_p)->f_servicexml);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_publishdetails_test(bool verbose)
{
  printf(" * Common:Directory:PublishDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
