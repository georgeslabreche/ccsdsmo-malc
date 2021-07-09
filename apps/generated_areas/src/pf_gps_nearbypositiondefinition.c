#include "pf.h"


// structure definition for composite pf_gps_nearbypositiondefinition
struct _pf_gps_nearbypositiondefinition_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  bool f_distanceboundary_is_present;
  mal_float_t f_distanceboundary;
  pf_gps_position_t * f_position;
};

// fields accessors for composite pf_gps_nearbypositiondefinition
mal_identifier_t * pf_gps_nearbypositiondefinition_get_name(pf_gps_nearbypositiondefinition_t * self)
{
  return self->f_name;
}
void pf_gps_nearbypositiondefinition_set_name(pf_gps_nearbypositiondefinition_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * pf_gps_nearbypositiondefinition_get_description(pf_gps_nearbypositiondefinition_t * self)
{
  return self->f_description;
}
void pf_gps_nearbypositiondefinition_set_description(pf_gps_nearbypositiondefinition_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
bool pf_gps_nearbypositiondefinition_distanceboundary_is_present(pf_gps_nearbypositiondefinition_t * self)
{
  return self->f_distanceboundary_is_present;
}
void pf_gps_nearbypositiondefinition_distanceboundary_set_present(pf_gps_nearbypositiondefinition_t * self, bool is_present)
{
  self->f_distanceboundary_is_present = is_present;
}
mal_float_t pf_gps_nearbypositiondefinition_get_distanceboundary(pf_gps_nearbypositiondefinition_t * self)
{
  return self->f_distanceboundary;
}
void pf_gps_nearbypositiondefinition_set_distanceboundary(pf_gps_nearbypositiondefinition_t * self, mal_float_t f_distanceboundary)
{
  self->f_distanceboundary = f_distanceboundary;
}
pf_gps_position_t * pf_gps_nearbypositiondefinition_get_position(pf_gps_nearbypositiondefinition_t * self)
{
  return self->f_position;
}
void pf_gps_nearbypositiondefinition_set_position(pf_gps_nearbypositiondefinition_t * self, pf_gps_position_t * f_position)
{
  self->f_position = f_position;
}

// default constructor
pf_gps_nearbypositiondefinition_t * pf_gps_nearbypositiondefinition_new(void)
{
  pf_gps_nearbypositiondefinition_t *self = (pf_gps_nearbypositiondefinition_t *) calloc(1, sizeof(pf_gps_nearbypositiondefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int pf_gps_nearbypositiondefinition_add_encoding_length_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_name != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_name != NULL))
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_description != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_description != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_distanceboundary_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_distanceboundary_is_present)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, self->f_distanceboundary, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_position != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_position != NULL))
  {
    rc = pf_gps_position_add_encoding_length_malbinary(self->f_position, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_nearbypositiondefinition_encode_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_name != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
    if (rc < 0)
      return rc;
  }
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
  presence_flag = self->f_distanceboundary_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_float(encoder, cursor, self->f_distanceboundary);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_position != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = pf_gps_position_encode_malbinary(self->f_position, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int pf_gps_nearbypositiondefinition_decode_malbinary(pf_gps_nearbypositiondefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_name = NULL;
  }
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
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &self->f_distanceboundary);
    if (rc < 0)
      return rc;
  }
  self->f_distanceboundary_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_position = pf_gps_position_new();
    if (self->f_position == NULL) return -1;
    rc = pf_gps_position_decode_malbinary(self->f_position, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_position = NULL;
  }
  return rc;
}

// destructor
void pf_gps_nearbypositiondefinition_destroy(pf_gps_nearbypositiondefinition_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_position != NULL)
  {
    pf_gps_position_destroy(& (*self_p)->f_position);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void pf_gps_nearbypositiondefinition_test(bool verbose)
{
  printf(" * PF:GPS:NearbyPositionDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
