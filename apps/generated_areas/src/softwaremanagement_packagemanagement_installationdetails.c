#include "softwaremanagement.h"


// structure definition for composite softwaremanagement_packagemanagement_installationdetails
struct _softwaremanagement_packagemanagement_installationdetails_t {
  bool f_installed_is_present;
  mal_boolean_t f_installed;
  mal_string_t * f_folderlocation;
};

// fields accessors for composite softwaremanagement_packagemanagement_installationdetails
bool softwaremanagement_packagemanagement_installationdetails_installed_is_present(softwaremanagement_packagemanagement_installationdetails_t * self)
{
  return self->f_installed_is_present;
}
void softwaremanagement_packagemanagement_installationdetails_installed_set_present(softwaremanagement_packagemanagement_installationdetails_t * self, bool is_present)
{
  self->f_installed_is_present = is_present;
}
mal_boolean_t softwaremanagement_packagemanagement_installationdetails_get_installed(softwaremanagement_packagemanagement_installationdetails_t * self)
{
  return self->f_installed;
}
void softwaremanagement_packagemanagement_installationdetails_set_installed(softwaremanagement_packagemanagement_installationdetails_t * self, mal_boolean_t f_installed)
{
  self->f_installed = f_installed;
}
mal_string_t * softwaremanagement_packagemanagement_installationdetails_get_folderlocation(softwaremanagement_packagemanagement_installationdetails_t * self)
{
  return self->f_folderlocation;
}
void softwaremanagement_packagemanagement_installationdetails_set_folderlocation(softwaremanagement_packagemanagement_installationdetails_t * self, mal_string_t * f_folderlocation)
{
  self->f_folderlocation = f_folderlocation;
}

// default constructor
softwaremanagement_packagemanagement_installationdetails_t * softwaremanagement_packagemanagement_installationdetails_new(void)
{
  softwaremanagement_packagemanagement_installationdetails_t *self = (softwaremanagement_packagemanagement_installationdetails_t *) calloc(1, sizeof(softwaremanagement_packagemanagement_installationdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int softwaremanagement_packagemanagement_installationdetails_add_encoding_length_malbinary(softwaremanagement_packagemanagement_installationdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_installed_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_installed_is_present)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_installed, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_folderlocation != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_folderlocation != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_folderlocation, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_packagemanagement_installationdetails_encode_malbinary(softwaremanagement_packagemanagement_installationdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_installed_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, self->f_installed);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_folderlocation != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_folderlocation);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_packagemanagement_installationdetails_decode_malbinary(softwaremanagement_packagemanagement_installationdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_installed);
    if (rc < 0)
      return rc;
  }
  self->f_installed_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_folderlocation);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_folderlocation = NULL;
  }
  return rc;
}

// destructor
void softwaremanagement_packagemanagement_installationdetails_destroy(softwaremanagement_packagemanagement_installationdetails_t ** self_p)
{
  if ((*self_p)->f_folderlocation != NULL)
  {
    mal_string_destroy(& (*self_p)->f_folderlocation);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void softwaremanagement_packagemanagement_installationdetails_test(bool verbose)
{
  printf(" * SoftwareManagement:PackageManagement:InstallationDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
