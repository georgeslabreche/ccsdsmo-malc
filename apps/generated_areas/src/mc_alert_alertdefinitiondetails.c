#include "mc.h"


// structure definition for composite mc_alert_alertdefinitiondetails
struct _mc_alert_alertdefinitiondetails_t {
  mal_string_t * f_description;
  mc_severity_t f_severity;
  mal_boolean_t f_generationenabled;
  mc_argumentdefinitiondetails_list_t * f_arguments;
};

// fields accessors for composite mc_alert_alertdefinitiondetails
mal_string_t * mc_alert_alertdefinitiondetails_get_description(mc_alert_alertdefinitiondetails_t * self)
{
  return self->f_description;
}
void mc_alert_alertdefinitiondetails_set_description(mc_alert_alertdefinitiondetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_severity_t mc_alert_alertdefinitiondetails_get_severity(mc_alert_alertdefinitiondetails_t * self)
{
  return self->f_severity;
}
void mc_alert_alertdefinitiondetails_set_severity(mc_alert_alertdefinitiondetails_t * self, mc_severity_t f_severity)
{
  self->f_severity = f_severity;
}
mal_boolean_t mc_alert_alertdefinitiondetails_get_generationenabled(mc_alert_alertdefinitiondetails_t * self)
{
  return self->f_generationenabled;
}
void mc_alert_alertdefinitiondetails_set_generationenabled(mc_alert_alertdefinitiondetails_t * self, mal_boolean_t f_generationenabled)
{
  self->f_generationenabled = f_generationenabled;
}
mc_argumentdefinitiondetails_list_t * mc_alert_alertdefinitiondetails_get_arguments(mc_alert_alertdefinitiondetails_t * self)
{
  return self->f_arguments;
}
void mc_alert_alertdefinitiondetails_set_arguments(mc_alert_alertdefinitiondetails_t * self, mc_argumentdefinitiondetails_list_t * f_arguments)
{
  self->f_arguments = f_arguments;
}

// default constructor
mc_alert_alertdefinitiondetails_t * mc_alert_alertdefinitiondetails_new(void)
{
  mc_alert_alertdefinitiondetails_t *self = (mc_alert_alertdefinitiondetails_t *) calloc(1, sizeof(mc_alert_alertdefinitiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_alert_alertdefinitiondetails_add_encoding_length_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_severity, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_generationenabled, cursor);
  if (rc < 0)
    return rc;
  rc = mc_argumentdefinitiondetails_list_add_encoding_length_malbinary(self->f_arguments, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_alert_alertdefinitiondetails_encode_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_severity);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_generationenabled);
  if (rc < 0)
    return rc;
  rc = mc_argumentdefinitiondetails_list_encode_malbinary(self->f_arguments, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_alert_alertdefinitiondetails_decode_malbinary(mc_alert_alertdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
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
  self->f_arguments = mc_argumentdefinitiondetails_list_new(0);
  if (self->f_arguments == NULL) return -1;
  rc = mc_argumentdefinitiondetails_list_decode_malbinary(self->f_arguments, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_alert_alertdefinitiondetails_destroy(mc_alert_alertdefinitiondetails_t ** self_p)
{
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_arguments != NULL)
  {
    mc_argumentdefinitiondetails_list_destroy(& (*self_p)->f_arguments);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_alert_alertdefinitiondetails_test(bool verbose)
{
  printf(" * MC:Alert:AlertDefinitionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
