#include "common.h"


// structure definition for composite common_directory_providerdetails
struct _common_directory_providerdetails_t {
  common_directory_servicecapability_list_t * f_servicecapabilities;
  common_directory_addressdetails_list_t * f_provideraddresses;
};

// fields accessors for composite common_directory_providerdetails
common_directory_servicecapability_list_t * common_directory_providerdetails_get_servicecapabilities(common_directory_providerdetails_t * self)
{
  return self->f_servicecapabilities;
}
void common_directory_providerdetails_set_servicecapabilities(common_directory_providerdetails_t * self, common_directory_servicecapability_list_t * f_servicecapabilities)
{
  self->f_servicecapabilities = f_servicecapabilities;
}
common_directory_addressdetails_list_t * common_directory_providerdetails_get_provideraddresses(common_directory_providerdetails_t * self)
{
  return self->f_provideraddresses;
}
void common_directory_providerdetails_set_provideraddresses(common_directory_providerdetails_t * self, common_directory_addressdetails_list_t * f_provideraddresses)
{
  self->f_provideraddresses = f_provideraddresses;
}

// default constructor
common_directory_providerdetails_t * common_directory_providerdetails_new(void)
{
  common_directory_providerdetails_t *self = (common_directory_providerdetails_t *) calloc(1, sizeof(common_directory_providerdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_directory_providerdetails_add_encoding_length_malbinary(common_directory_providerdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = common_directory_servicecapability_list_add_encoding_length_malbinary(self->f_servicecapabilities, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = common_directory_addressdetails_list_add_encoding_length_malbinary(self->f_provideraddresses, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_directory_providerdetails_encode_malbinary(common_directory_providerdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = common_directory_servicecapability_list_encode_malbinary(self->f_servicecapabilities, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = common_directory_addressdetails_list_encode_malbinary(self->f_provideraddresses, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_directory_providerdetails_decode_malbinary(common_directory_providerdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_servicecapabilities = common_directory_servicecapability_list_new(0);
  if (self->f_servicecapabilities == NULL) return -1;
  rc = common_directory_servicecapability_list_decode_malbinary(self->f_servicecapabilities, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_provideraddresses = common_directory_addressdetails_list_new(0);
  if (self->f_provideraddresses == NULL) return -1;
  rc = common_directory_addressdetails_list_decode_malbinary(self->f_provideraddresses, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_directory_providerdetails_destroy(common_directory_providerdetails_t ** self_p)
{
  if ((*self_p)->f_servicecapabilities != NULL)
  {
    common_directory_servicecapability_list_destroy(& (*self_p)->f_servicecapabilities);
  }
  if ((*self_p)->f_provideraddresses != NULL)
  {
    common_directory_addressdetails_list_destroy(& (*self_p)->f_provideraddresses);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_directory_providerdetails_test(bool verbose)
{
  printf(" * Common:Directory:ProviderDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
