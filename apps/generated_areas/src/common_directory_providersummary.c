#include "common.h"


// structure definition for composite common_directory_providersummary
struct _common_directory_providersummary_t {
  com_objectkey_t * f_providerkey;
  mal_identifier_t * f_providerid;
  common_directory_providerdetails_t * f_providerdetails;
};

// fields accessors for composite common_directory_providersummary
com_objectkey_t * common_directory_providersummary_get_providerkey(common_directory_providersummary_t * self)
{
  return self->f_providerkey;
}
void common_directory_providersummary_set_providerkey(common_directory_providersummary_t * self, com_objectkey_t * f_providerkey)
{
  self->f_providerkey = f_providerkey;
}
mal_identifier_t * common_directory_providersummary_get_providerid(common_directory_providersummary_t * self)
{
  return self->f_providerid;
}
void common_directory_providersummary_set_providerid(common_directory_providersummary_t * self, mal_identifier_t * f_providerid)
{
  self->f_providerid = f_providerid;
}
common_directory_providerdetails_t * common_directory_providersummary_get_providerdetails(common_directory_providersummary_t * self)
{
  return self->f_providerdetails;
}
void common_directory_providersummary_set_providerdetails(common_directory_providersummary_t * self, common_directory_providerdetails_t * f_providerdetails)
{
  self->f_providerdetails = f_providerdetails;
}

// default constructor
common_directory_providersummary_t * common_directory_providersummary_new(void)
{
  common_directory_providersummary_t *self = (common_directory_providersummary_t *) calloc(1, sizeof(common_directory_providersummary_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_providersummary_add_encoding_length_malbinary(common_directory_providersummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_providerkey, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_providerid, cursor);
  if (rc < 0)
    return rc;
  rc = common_directory_providerdetails_add_encoding_length_malbinary(self->f_providerdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_directory_providersummary_encode_malbinary(common_directory_providersummary_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objectkey_encode_malbinary(self->f_providerkey, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_providerid);
  if (rc < 0)
    return rc;
  rc = common_directory_providerdetails_encode_malbinary(self->f_providerdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_directory_providersummary_decode_malbinary(common_directory_providersummary_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_providerkey = com_objectkey_new();
  if (self->f_providerkey == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_providerkey, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_providerid);
  if (rc < 0)
    return rc;
  self->f_providerdetails = common_directory_providerdetails_new();
  if (self->f_providerdetails == NULL) return -1;
  rc = common_directory_providerdetails_decode_malbinary(self->f_providerdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_directory_providersummary_destroy(common_directory_providersummary_t ** self_p)
{
  if ((*self_p)->f_providerkey != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_providerkey);
  }
  if ((*self_p)->f_providerid != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_providerid);
  }
  if ((*self_p)->f_providerdetails != NULL)
  {
    common_directory_providerdetails_destroy(& (*self_p)->f_providerdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_providersummary_test(bool verbose)
{
  printf(" * Common:Directory:ProviderSummary: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
