#include "mc.h"


// structure definition for composite mc_parameter_parametervalue
struct _mc_parameter_parametervalue_t {
  mc_parameter_validity_t f_validitystate;
  bool f_rawvalue_is_present;
  unsigned char f_rawvalue_attribute_tag;
  union mal_attribute_t f_rawvalue;
  bool f_convertedvalue_is_present;
  unsigned char f_convertedvalue_attribute_tag;
  union mal_attribute_t f_convertedvalue;
};

// fields accessors for composite mc_parameter_parametervalue
mc_parameter_validity_t mc_parameter_parametervalue_get_validitystate(mc_parameter_parametervalue_t * self)
{
  return self->f_validitystate;
}
void mc_parameter_parametervalue_set_validitystate(mc_parameter_parametervalue_t * self, mc_parameter_validity_t f_validitystate)
{
  self->f_validitystate = f_validitystate;
}
bool mc_parameter_parametervalue_rawvalue_is_present(mc_parameter_parametervalue_t * self)
{
  return self->f_rawvalue_is_present;
}
void mc_parameter_parametervalue_rawvalue_set_present(mc_parameter_parametervalue_t * self, bool is_present)
{
  self->f_rawvalue_is_present = is_present;
}
unsigned char mc_parameter_parametervalue_rawvalue_get_attribute_tag(mc_parameter_parametervalue_t * self)
{
  return self->f_rawvalue_attribute_tag;
}
void mc_parameter_parametervalue_rawvalue_set_attribute_tag(mc_parameter_parametervalue_t * self, unsigned char attribute_tag)
{
  self->f_rawvalue_attribute_tag = attribute_tag;
}
bool mc_parameter_parametervalue_convertedvalue_is_present(mc_parameter_parametervalue_t * self)
{
  return self->f_convertedvalue_is_present;
}
void mc_parameter_parametervalue_convertedvalue_set_present(mc_parameter_parametervalue_t * self, bool is_present)
{
  self->f_convertedvalue_is_present = is_present;
}
unsigned char mc_parameter_parametervalue_convertedvalue_get_attribute_tag(mc_parameter_parametervalue_t * self)
{
  return self->f_convertedvalue_attribute_tag;
}
void mc_parameter_parametervalue_convertedvalue_set_attribute_tag(mc_parameter_parametervalue_t * self, unsigned char attribute_tag)
{
  self->f_convertedvalue_attribute_tag = attribute_tag;
}

// default constructor
mc_parameter_parametervalue_t * mc_parameter_parametervalue_new(void)
{
  mc_parameter_parametervalue_t *self = (mc_parameter_parametervalue_t *) calloc(1, sizeof(mc_parameter_parametervalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parametervalue_add_encoding_length_malbinary(mc_parameter_parametervalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_validitystate, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_rawvalue_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_rawvalue_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_rawvalue_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_rawvalue_attribute_tag, self->f_rawvalue, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_convertedvalue_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_convertedvalue_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_convertedvalue_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_convertedvalue_attribute_tag, self->f_convertedvalue, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parametervalue_encode_malbinary(mc_parameter_parametervalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_validitystate);
  if (rc < 0)
    return rc;
  presence_flag = self->f_rawvalue_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_rawvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_rawvalue_attribute_tag, self->f_rawvalue);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_convertedvalue_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_convertedvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_convertedvalue_attribute_tag, self->f_convertedvalue);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameter_parametervalue_decode_malbinary(mc_parameter_parametervalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_validitystate = (mc_parameter_validity_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_rawvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_rawvalue_attribute_tag, &self->f_rawvalue);
    if (rc < 0)
      return rc;
  }
  self->f_rawvalue_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_convertedvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_convertedvalue_attribute_tag, &self->f_convertedvalue);
    if (rc < 0)
      return rc;
  }
  self->f_convertedvalue_is_present = presence_flag;
  return rc;
}

// destructor
void mc_parameter_parametervalue_destroy(mc_parameter_parametervalue_t ** self_p)
{
  if ((*self_p)->f_rawvalue_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_rawvalue, (*self_p)->f_rawvalue_attribute_tag);
  }
  if ((*self_p)->f_convertedvalue_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_convertedvalue, (*self_p)->f_convertedvalue_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parametervalue_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
