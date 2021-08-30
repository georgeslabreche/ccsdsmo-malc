#include "mc.h"


// structure definition for composite mc_parameterexpression
struct _mc_parameterexpression_t {
  com_objectkey_t * f_parameterid;
  com_archive_expressionoperator_t f_operator;
  mal_boolean_t f_useconverted;
  bool f_value_is_present;
  unsigned char f_value_attribute_tag;
  union mal_attribute_t f_value;
};

// fields accessors for composite mc_parameterexpression
com_objectkey_t * mc_parameterexpression_get_parameterid(mc_parameterexpression_t * self)
{
  return self->f_parameterid;
}
void mc_parameterexpression_set_parameterid(mc_parameterexpression_t * self, com_objectkey_t * f_parameterid)
{
  self->f_parameterid = f_parameterid;
}
com_archive_expressionoperator_t mc_parameterexpression_get_operator(mc_parameterexpression_t * self)
{
  return self->f_operator;
}
void mc_parameterexpression_set_operator(mc_parameterexpression_t * self, com_archive_expressionoperator_t f_operator)
{
  self->f_operator = f_operator;
}
mal_boolean_t mc_parameterexpression_get_useconverted(mc_parameterexpression_t * self)
{
  return self->f_useconverted;
}
void mc_parameterexpression_set_useconverted(mc_parameterexpression_t * self, mal_boolean_t f_useconverted)
{
  self->f_useconverted = f_useconverted;
}
bool mc_parameterexpression_value_is_present(mc_parameterexpression_t * self)
{
  return self->f_value_is_present;
}
void mc_parameterexpression_value_set_present(mc_parameterexpression_t * self, bool is_present)
{
  self->f_value_is_present = is_present;
}
unsigned char mc_parameterexpression_value_get_attribute_tag(mc_parameterexpression_t * self)
{
  return self->f_value_attribute_tag;
}
void mc_parameterexpression_value_set_attribute_tag(mc_parameterexpression_t * self, unsigned char attribute_tag)
{
  self->f_value_attribute_tag = attribute_tag;
}
union mal_attribute_t mc_parameterexpression_get_value(mc_parameterexpression_t * self)
{
  return self->f_value;
}
void mc_parameterexpression_set_value(mc_parameterexpression_t * self, union mal_attribute_t f_value)
{
  self->f_value = f_value;
}

// default constructor
mc_parameterexpression_t * mc_parameterexpression_new(void)
{
  mc_parameterexpression_t *self = (mc_parameterexpression_t *) calloc(1, sizeof(mc_parameterexpression_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameterexpression_add_encoding_length_malbinary(mc_parameterexpression_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objectkey_add_encoding_length_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_operator, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_useconverted, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_value_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_value_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_value_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_value_attribute_tag, self->f_value, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameterexpression_encode_malbinary(mc_parameterexpression_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = com_objectkey_encode_malbinary(self->f_parameterid, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_operator);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_useconverted);
  if (rc < 0)
    return rc;
  presence_flag = self->f_value_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_value_attribute_tag, self->f_value);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_parameterexpression_decode_malbinary(mc_parameterexpression_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  self->f_parameterid = com_objectkey_new();
  if (self->f_parameterid == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_parameterid, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_operator = (com_archive_expressionoperator_t) enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_useconverted);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_value_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_value_attribute_tag, &self->f_value);
    if (rc < 0)
      return rc;
  }
  self->f_value_is_present = presence_flag;
  return rc;
}

// destructor
void mc_parameterexpression_destroy(mc_parameterexpression_t ** self_p)
{
  if ((*self_p)->f_parameterid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_parameterid);
  }
  if ((*self_p)->f_value_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_value, (*self_p)->f_value_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameterexpression_test(bool verbose)
{
  printf(" * MC:ParameterExpression: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
