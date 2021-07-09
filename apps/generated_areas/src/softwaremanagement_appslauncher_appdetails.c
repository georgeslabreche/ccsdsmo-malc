#include "softwaremanagement.h"


// structure definition for composite softwaremanagement_appslauncher_appdetails
struct _softwaremanagement_appslauncher_appdetails_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mal_string_t * f_version;
  mal_identifier_t * f_category;
  mal_boolean_t f_runatstartup;
  mal_boolean_t f_running;
  mal_string_t * f_extrainfo;
  mal_string_t * f_copyright;
  mal_string_t * f_runas;
};

// fields accessors for composite softwaremanagement_appslauncher_appdetails
mal_identifier_t * softwaremanagement_appslauncher_appdetails_get_name(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_name;
}
void softwaremanagement_appslauncher_appdetails_set_name(softwaremanagement_appslauncher_appdetails_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * softwaremanagement_appslauncher_appdetails_get_description(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_description;
}
void softwaremanagement_appslauncher_appdetails_set_description(softwaremanagement_appslauncher_appdetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mal_string_t * softwaremanagement_appslauncher_appdetails_get_version(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_version;
}
void softwaremanagement_appslauncher_appdetails_set_version(softwaremanagement_appslauncher_appdetails_t * self, mal_string_t * f_version)
{
  self->f_version = f_version;
}
mal_identifier_t * softwaremanagement_appslauncher_appdetails_get_category(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_category;
}
void softwaremanagement_appslauncher_appdetails_set_category(softwaremanagement_appslauncher_appdetails_t * self, mal_identifier_t * f_category)
{
  self->f_category = f_category;
}
mal_boolean_t softwaremanagement_appslauncher_appdetails_get_runatstartup(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_runatstartup;
}
void softwaremanagement_appslauncher_appdetails_set_runatstartup(softwaremanagement_appslauncher_appdetails_t * self, mal_boolean_t f_runatstartup)
{
  self->f_runatstartup = f_runatstartup;
}
mal_boolean_t softwaremanagement_appslauncher_appdetails_get_running(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_running;
}
void softwaremanagement_appslauncher_appdetails_set_running(softwaremanagement_appslauncher_appdetails_t * self, mal_boolean_t f_running)
{
  self->f_running = f_running;
}
mal_string_t * softwaremanagement_appslauncher_appdetails_get_extrainfo(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_extrainfo;
}
void softwaremanagement_appslauncher_appdetails_set_extrainfo(softwaremanagement_appslauncher_appdetails_t * self, mal_string_t * f_extrainfo)
{
  self->f_extrainfo = f_extrainfo;
}
mal_string_t * softwaremanagement_appslauncher_appdetails_get_copyright(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_copyright;
}
void softwaremanagement_appslauncher_appdetails_set_copyright(softwaremanagement_appslauncher_appdetails_t * self, mal_string_t * f_copyright)
{
  self->f_copyright = f_copyright;
}
mal_string_t * softwaremanagement_appslauncher_appdetails_get_runas(softwaremanagement_appslauncher_appdetails_t * self)
{
  return self->f_runas;
}
void softwaremanagement_appslauncher_appdetails_set_runas(softwaremanagement_appslauncher_appdetails_t * self, mal_string_t * f_runas)
{
  self->f_runas = f_runas;
}

// default constructor
softwaremanagement_appslauncher_appdetails_t * softwaremanagement_appslauncher_appdetails_new(void)
{
  softwaremanagement_appslauncher_appdetails_t *self = (softwaremanagement_appslauncher_appdetails_t *) calloc(1, sizeof(softwaremanagement_appslauncher_appdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int softwaremanagement_appslauncher_appdetails_add_encoding_length_malbinary(softwaremanagement_appslauncher_appdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_version, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_category, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_runatstartup, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_running, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_extrainfo != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_extrainfo != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_extrainfo, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_copyright != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_copyright != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_copyright, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_runas != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_runas != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_runas, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_appslauncher_appdetails_encode_malbinary(softwaremanagement_appslauncher_appdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_version);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_runatstartup);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_running);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_extrainfo != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_extrainfo);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_copyright != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_copyright);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_runas != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_runas);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int softwaremanagement_appslauncher_appdetails_decode_malbinary(softwaremanagement_appslauncher_appdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_version);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_category);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_runatstartup);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_running);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_extrainfo);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_extrainfo = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_copyright);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_copyright = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_runas);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_runas = NULL;
  }
  return rc;
}

// destructor
void softwaremanagement_appslauncher_appdetails_destroy(softwaremanagement_appslauncher_appdetails_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_version != NULL)
  {
    mal_string_destroy(& (*self_p)->f_version);
  }
  if ((*self_p)->f_category != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_category);
  }
  if ((*self_p)->f_extrainfo != NULL)
  {
    mal_string_destroy(& (*self_p)->f_extrainfo);
  }
  if ((*self_p)->f_copyright != NULL)
  {
    mal_string_destroy(& (*self_p)->f_copyright);
  }
  if ((*self_p)->f_runas != NULL)
  {
    mal_string_destroy(& (*self_p)->f_runas);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void softwaremanagement_appslauncher_appdetails_test(bool verbose)
{
  printf(" * SoftwareManagement:AppsLauncher:AppDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
