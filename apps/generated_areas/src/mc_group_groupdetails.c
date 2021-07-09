#include "mc.h"


// structure definition for composite mc_group_groupdetails
struct _mc_group_groupdetails_t {
  mal_string_t * f_description;
  com_objecttype_t * f_objecttype;
  mal_identifier_list_t * f_domain;
  mal_long_list_t * f_instanceids;
};

// fields accessors for composite mc_group_groupdetails
mal_string_t * mc_group_groupdetails_get_description(mc_group_groupdetails_t * self)
{
  return self->f_description;
}
void mc_group_groupdetails_set_description(mc_group_groupdetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
com_objecttype_t * mc_group_groupdetails_get_objecttype(mc_group_groupdetails_t * self)
{
  return self->f_objecttype;
}
void mc_group_groupdetails_set_objecttype(mc_group_groupdetails_t * self, com_objecttype_t * f_objecttype)
{
  self->f_objecttype = f_objecttype;
}
mal_identifier_list_t * mc_group_groupdetails_get_domain(mc_group_groupdetails_t * self)
{
  return self->f_domain;
}
void mc_group_groupdetails_set_domain(mc_group_groupdetails_t * self, mal_identifier_list_t * f_domain)
{
  self->f_domain = f_domain;
}
mal_long_list_t * mc_group_groupdetails_get_instanceids(mc_group_groupdetails_t * self)
{
  return self->f_instanceids;
}
void mc_group_groupdetails_set_instanceids(mc_group_groupdetails_t * self, mal_long_list_t * f_instanceids)
{
  self->f_instanceids = f_instanceids;
}

// default constructor
mc_group_groupdetails_t * mc_group_groupdetails_new(void)
{
  mc_group_groupdetails_t *self = (mc_group_groupdetails_t *) calloc(1, sizeof(mc_group_groupdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_group_groupdetails_add_encoding_length_malbinary(mc_group_groupdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = com_objecttype_add_encoding_length_malbinary(self->f_objecttype, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_add_encoding_length_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_add_encoding_length_malbinary(self->f_instanceids, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_group_groupdetails_encode_malbinary(mc_group_groupdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = com_objecttype_encode_malbinary(self->f_objecttype, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_identifier_list_encode_malbinary(self->f_domain, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_long_list_encode_malbinary(self->f_instanceids, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_group_groupdetails_decode_malbinary(mc_group_groupdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  self->f_objecttype = com_objecttype_new();
  if (self->f_objecttype == NULL) return -1;
  rc = com_objecttype_decode_malbinary(self->f_objecttype, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_domain = mal_identifier_list_new(0);
  if (self->f_domain == NULL) return -1;
  rc = mal_identifier_list_decode_malbinary(self->f_domain, decoder, cursor);
  if (rc < 0)
    return rc;
  self->f_instanceids = mal_long_list_new(0);
  if (self->f_instanceids == NULL) return -1;
  rc = mal_long_list_decode_malbinary(self->f_instanceids, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_group_groupdetails_destroy(mc_group_groupdetails_t ** self_p)
{
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_objecttype != NULL)
  {
    com_objecttype_destroy(& (*self_p)->f_objecttype);
  }
  if ((*self_p)->f_domain != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_domain);
  }
  if ((*self_p)->f_instanceids != NULL)
  {
    mal_long_list_destroy(& (*self_p)->f_instanceids);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_group_groupdetails_test(bool verbose)
{
  printf(" * MC:Group:GroupDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
