#include "mc.h"


// structure definition for composite mc_alert_alertdefinition
struct _mc_alert_alertdefinition_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mc_severity_t f_severity;
  mal_boolean_t f_generationenabled;
  mc_argumentdefinition_list_t * f_arguments;
  mal_identifier_list_t * f_argumentids;
};

// fields accessors for composite mc_alert_alertdefinition
mal_identifier_t * mc_alert_alertdefinition_get_name(mc_alert_alertdefinition_t * self)
{
  return self->f_name;
}
void mc_alert_alertdefinition_set_name(mc_alert_alertdefinition_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * mc_alert_alertdefinition_get_description(mc_alert_alertdefinition_t * self)
{
  return self->f_description;
}
void mc_alert_alertdefinition_set_description(mc_alert_alertdefinition_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_severity_t mc_alert_alertdefinition_get_severity(mc_alert_alertdefinition_t * self)
{
  return self->f_severity;
}
void mc_alert_alertdefinition_set_severity(mc_alert_alertdefinition_t * self, mc_severity_t f_severity)
{
  self->f_severity = f_severity;
}
mal_boolean_t mc_alert_alertdefinition_get_generationenabled(mc_alert_alertdefinition_t * self)
{
  return self->f_generationenabled;
}
void mc_alert_alertdefinition_set_generationenabled(mc_alert_alertdefinition_t * self, mal_boolean_t f_generationenabled)
{
  self->f_generationenabled = f_generationenabled;
}
mc_argumentdefinition_list_t * mc_alert_alertdefinition_get_arguments(mc_alert_alertdefinition_t * self)
{
  return self->f_arguments;
}
void mc_alert_alertdefinition_set_arguments(mc_alert_alertdefinition_t * self, mc_argumentdefinition_list_t * f_arguments)
{
  self->f_arguments = f_arguments;
}
mal_identifier_list_t * mc_alert_alertdefinition_get_argumentids(mc_alert_alertdefinition_t * self)
{
  return self->f_argumentids;
}
void mc_alert_alertdefinition_set_argumentids(mc_alert_alertdefinition_t * self, mal_identifier_list_t * f_argumentids)
{
  self->f_argumentids = f_argumentids;
}

// default constructor
mc_alert_alertdefinition_t * mc_alert_alertdefinition_new(void)
{
  mc_alert_alertdefinition_t *self = (mc_alert_alertdefinition_t *) calloc(1, sizeof(mc_alert_alertdefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_alert_alertdefinition_add_encoding_length_malbinary(mc_alert_alertdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_severity, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_generationenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mc_argumentdefinition_list_add_encoding_length_malbinary(self->f_arguments, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_argumentids != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_argumentids != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->f_argumentids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_alert_alertdefinition_encode_malbinary(mc_alert_alertdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_severity);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mc_argumentdefinition_list_encode_malbinary(self->f_arguments, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_argumentids != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->f_argumentids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_alert_alertdefinition_decode_malbinary(mc_alert_alertdefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_severity = (mc_severity_t) enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_generationenabled);
  if (rc < 0)
    return rc;
  self->f_arguments = mc_argumentdefinition_list_new(0);
  if (self->f_arguments == NULL) return -1;
  rc = mc_argumentdefinition_list_decode_malbinary(self->f_arguments, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_argumentids = mal_identifier_list_new(0);
    if (self->f_argumentids == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->f_argumentids, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_argumentids = NULL;
  }
  return rc;
}

// destructor
void mc_alert_alertdefinition_destroy(mc_alert_alertdefinition_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_arguments != NULL)
  {
    mc_argumentdefinition_list_destroy(& (*self_p)->f_arguments);
  }
  if ((*self_p)->f_argumentids != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_argumentids);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_alert_alertdefinition_test(bool verbose)
{
  printf(" * MC:Alert:AlertDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
