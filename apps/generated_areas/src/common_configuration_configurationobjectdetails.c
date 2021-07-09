#include "common.h"


// structure definition for composite common_configuration_configurationobjectdetails
struct _common_configuration_configurationobjectdetails_t {
  common_configuration_configurationobjectset_list_t * f_configobjects;
};

// fields accessors for composite common_configuration_configurationobjectdetails
common_configuration_configurationobjectset_list_t * common_configuration_configurationobjectdetails_get_configobjects(common_configuration_configurationobjectdetails_t * self)
{
  return self->f_configobjects;
}
void common_configuration_configurationobjectdetails_set_configobjects(common_configuration_configurationobjectdetails_t * self, common_configuration_configurationobjectset_list_t * f_configobjects)
{
  self->f_configobjects = f_configobjects;
}

// default constructor
common_configuration_configurationobjectdetails_t * common_configuration_configurationobjectdetails_new(void)
{
  common_configuration_configurationobjectdetails_t *self = (common_configuration_configurationobjectdetails_t *) calloc(1, sizeof(common_configuration_configurationobjectdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_configuration_configurationobjectdetails_add_encoding_length_malbinary(common_configuration_configurationobjectdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = common_configuration_configurationobjectset_list_add_encoding_length_malbinary(self->f_configobjects, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_configurationobjectdetails_encode_malbinary(common_configuration_configurationobjectdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = common_configuration_configurationobjectset_list_encode_malbinary(self->f_configobjects, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_configurationobjectdetails_decode_malbinary(common_configuration_configurationobjectdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_configobjects = common_configuration_configurationobjectset_list_new(0);
  if (self->f_configobjects == NULL) return -1;
  rc = common_configuration_configurationobjectset_list_decode_malbinary(self->f_configobjects, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_configuration_configurationobjectdetails_destroy(common_configuration_configurationobjectdetails_t ** self_p)
{
  if ((*self_p)->f_configobjects != NULL)
  {
    common_configuration_configurationobjectset_list_destroy(& (*self_p)->f_configobjects);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_configuration_configurationobjectdetails_test(bool verbose)
{
  printf(" * Common:Configuration:ConfigurationObjectDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
