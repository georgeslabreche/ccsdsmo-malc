#include "common.h"


// structure definition for composite common_configuration_configurationobjectset
struct _common_configuration_configurationobjectset_t {
  com_objecttype_t * f_objtype;
  mal_identifier_list_t * f_domain;
  mal_long_list_t * f_objinstids;
};

// fields accessors for composite common_configuration_configurationobjectset
com_objecttype_t * common_configuration_configurationobjectset_get_objtype(common_configuration_configurationobjectset_t * self)
{
  return self->f_objtype;
}
void common_configuration_configurationobjectset_set_objtype(common_configuration_configurationobjectset_t * self, com_objecttype_t * f_objtype)
{
  self->f_objtype = f_objtype;
}
mal_identifier_list_t * common_configuration_configurationobjectset_get_domain(common_configuration_configurationobjectset_t * self)
{
  return self->f_domain;
}
void common_configuration_configurationobjectset_set_domain(common_configuration_configurationobjectset_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_long_list_t * common_configuration_configurationobjectset_get_objinstids(common_configuration_configurationobjectset_t * self)
{
  return self->f_objinstids;
}
void common_configuration_configurationobjectset_set_objinstids(common_configuration_configurationobjectset_t * self, mal_long_list_t * f_objinstids)
{
  self->f_objinstids = f_objinstids;
}

// default constructor
common_configuration_configurationobjectset_t * common_configuration_configurationobjectset_new(void)
{
  common_configuration_configurationobjectset_t *self = (common_configuration_configurationobjectset_t *) calloc(1, sizeof(common_configuration_configurationobjectset_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int common_configuration_configurationobjectset_add_encoding_length_malbinary(common_configuration_configurationobjectset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objecttype_add_encoding_length_malbinary(self->f_objtype, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_add_encoding_length_malbinary(self->f_objinstids, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_configurationobjectset_encode_malbinary(common_configuration_configurationobjectset_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objecttype_encode_malbinary(self->f_objtype, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_encode_malbinary(self->f_objinstids, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int common_configuration_configurationobjectset_decode_malbinary(common_configuration_configurationobjectset_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_objtype = com_objecttype_new();
  if (self->f_objtype == NULL) return -1;
  rc = com_objecttype_decode_malbinary(self->f_objtype, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_domain = mal_identifier_list_new(0);
  if (self->f_domain == NULL) return -1;
  rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_objinstids = mal_long_list_new(0);
  if (self->f_objinstids == NULL) return -1;
  rc = mal_long_list_decode_malbinary(self->f_objinstids, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void common_configuration_configurationobjectset_destroy(common_configuration_configurationobjectset_t ** self_p)
{
  if ((*self_p)->f_objtype != NULL)
  {
    com_objecttype_destroy(& (*self_p)->f_objtype);
  }
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_objinstids != NULL)
  {
    mal_long_list_destroy(& (*self_p)->f_objinstids);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void common_configuration_configurationobjectset_test(bool verbose)
{
  printf(" * Common:Configuration:ConfigurationObjectSet: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
