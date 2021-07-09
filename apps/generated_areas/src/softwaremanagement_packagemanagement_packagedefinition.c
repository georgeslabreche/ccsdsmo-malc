#include "softwaremanagement.h"


// structure definition for composite softwaremanagement_packagemanagement_packagedefinition
struct _softwaremanagement_packagemanagement_packagedefinition_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mal_identifier_t * f_category;
  mal_file_t * f_path;
  mal_string_t * f_publisher;
};

// fields accessors for composite softwaremanagement_packagemanagement_packagedefinition
mal_identifier_t * softwaremanagement_packagemanagement_packagedefinition_get_name(softwaremanagement_packagemanagement_packagedefinition_t * self)
{
  return self->f_name;
}
void softwaremanagement_packagemanagement_packagedefinition_set_name(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * softwaremanagement_packagemanagement_packagedefinition_get_description(softwaremanagement_packagemanagement_packagedefinition_t * self)
{
  return self->f_description;
}
void softwaremanagement_packagemanagement_packagedefinition_set_description(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mal_identifier_t * softwaremanagement_packagemanagement_packagedefinition_get_category(softwaremanagement_packagemanagement_packagedefinition_t * self)
{
  return self->f_category;
}
void softwaremanagement_packagemanagement_packagedefinition_set_category(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_identifier_t * f_category)
{
  self->f_category = f_category;
}
mal_file_t * softwaremanagement_packagemanagement_packagedefinition_get_path(softwaremanagement_packagemanagement_packagedefinition_t * self)
{
  return self->f_path;
}
void softwaremanagement_packagemanagement_packagedefinition_set_path(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_file_t * f_path)
{
  self->f_path = f_path;
}
mal_string_t * softwaremanagement_packagemanagement_packagedefinition_get_publisher(softwaremanagement_packagemanagement_packagedefinition_t * self)
{
  return self->f_publisher;
}
void softwaremanagement_packagemanagement_packagedefinition_set_publisher(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_string_t * f_publisher)
{
  self->f_publisher = f_publisher;
}

// default constructor
softwaremanagement_packagemanagement_packagedefinition_t * softwaremanagement_packagemanagement_packagedefinition_new(void)
{
  softwaremanagement_packagemanagement_packagedefinition_t *self = (softwaremanagement_packagemanagement_packagedefinition_t *) calloc(1, sizeof(softwaremanagement_packagemanagement_packagedefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int softwaremanagement_packagemanagement_packagedefinition_add_encoding_length_malbinary(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_description != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_description != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_category, cursor);
  if (rc < 0)
    return rc;
  rc = mal_file_add_encoding_length_malbinary(self->f_path, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_publisher != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_publisher != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_publisher, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_packagemanagement_packagedefinition_encode_malbinary(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_description != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_file_encode_malbinary(self->f_path, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_publisher != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_publisher);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_packagemanagement_packagedefinition_decode_malbinary(softwaremanagement_packagemanagement_packagedefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_description = NULL;
  }
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_category);
  if (rc < 0)
    return rc;
  self->f_path = mal_file_new();
  if (self->f_path == NULL) return -1;
  rc = mal_file_decode_malbinary(self->f_path, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_publisher);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_publisher = NULL;
  }
  return rc;
}

// destructor
void softwaremanagement_packagemanagement_packagedefinition_destroy(softwaremanagement_packagemanagement_packagedefinition_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_category != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_category);
  }
  if ((*self_p)->f_path != NULL)
  {
    mal_file_destroy(& (*self_p)->f_path);
  }
  if ((*self_p)->f_publisher != NULL)
  {
    mal_string_destroy(& (*self_p)->f_publisher);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void softwaremanagement_packagemanagement_packagedefinition_test(bool verbose)
{
  printf(" * SoftwareManagement:PackageManagement:PackageDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
