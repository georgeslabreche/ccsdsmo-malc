#include "common.h"


// structure definition for composite common_configuration_serviceconfigurationidentifier
struct _common_configuration_serviceconfigurationidentifier_t {
  mal_identifier_t * f_configname;
  common_servicekey_t * f_servicekey;
};

// fields accessors for composite common_configuration_serviceconfigurationidentifier
mal_identifier_t * common_configuration_serviceconfigurationidentifier_get_configname(common_configuration_serviceconfigurationidentifier_t * self)
{
  return self->f_configname;
}
void common_configuration_serviceconfigurationidentifier_set_configname(common_configuration_serviceconfigurationidentifier_t * self, mal_identifier_t * f_configname)
{
  self->f_configname = f_configname;
}
common_servicekey_t * common_configuration_serviceconfigurationidentifier_get_servicekey(common_configuration_serviceconfigurationidentifier_t * self)
{
  return self->f_servicekey;
}
void common_configuration_serviceconfigurationidentifier_set_servicekey(common_configuration_serviceconfigurationidentifier_t * self, common_servicekey_t * f_servicekey)
{
  self->f_servicekey = f_servicekey;
}

// default constructor
common_configuration_serviceconfigurationidentifier_t * common_configuration_serviceconfigurationidentifier_new(void)
{
  common_configuration_serviceconfigurationidentifier_t *self = (common_configuration_serviceconfigurationidentifier_t *) calloc(1, sizeof(common_configuration_serviceconfigurationidentifier_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_configuration_serviceconfigurationidentifier_add_encoding_length_malbinary(common_configuration_serviceconfigurationidentifier_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_configname, cursor);
  if (rc < 0)
    return rc;
  rc = common_servicekey_add_encoding_length_malbinary(self->f_servicekey, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_serviceconfigurationidentifier_encode_malbinary(common_configuration_serviceconfigurationidentifier_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_configname);
  if (rc < 0)
    return rc;
  rc = common_servicekey_encode_malbinary(self->f_servicekey, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_serviceconfigurationidentifier_decode_malbinary(common_configuration_serviceconfigurationidentifier_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_configname);
  if (rc < 0)
    return rc;
  self->f_servicekey = common_servicekey_new();
  if (self->f_servicekey == NULL) return -1;
  rc = common_servicekey_decode_malbinary(self->f_servicekey, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_configuration_serviceconfigurationidentifier_destroy(common_configuration_serviceconfigurationidentifier_t ** self_p)
{
  if ((*self_p)->f_configname != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_configname);
  }
  if ((*self_p)->f_servicekey != NULL)
  {
    common_servicekey_destroy(& (*self_p)->f_servicekey);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_configuration_serviceconfigurationidentifier_test(bool verbose)
{
  printf(" * Common:Configuration:ServiceConfigurationIdentifier: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
