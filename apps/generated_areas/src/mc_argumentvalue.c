#include "mc.h"


// structure definition for composite mc_argumentvalue
struct _mc_argumentvalue_t {
  mal_boolean_t f_isconvertedvalue;
  bool f_value_is_present;
  unsigned char f_value_attribute_tag;
  union mal_attribute_t f_value;
};

// fields accessors for composite mc_argumentvalue
mal_boolean_t mc_argumentvalue_get_isconvertedvalue(mc_argumentvalue_t * self)
{
  return self->f_isconvertedvalue;
}
void mc_argumentvalue_set_isconvertedvalue(mc_argumentvalue_t * self, mal_boolean_t f_isconvertedvalue)
{
  self->f_isconvertedvalue = f_isconvertedvalue;
}
bool mc_argumentvalue_value_is_present(mc_argumentvalue_t * self)
{
  return self->f_value_is_present;
}
void mc_argumentvalue_value_set_present(mc_argumentvalue_t * self, bool is_present)
{
  self->f_value_is_present = is_present;
}
unsigned char mc_argumentvalue_value_get_attribute_tag(mc_argumentvalue_t * self)
{
  return self->f_value_attribute_tag;
}
void mc_argumentvalue_value_set_attribute_tag(mc_argumentvalue_t * self, unsigned char attribute_tag)
{
  self->f_value_attribute_tag = attribute_tag;
}

// default constructor
mc_argumentvalue_t * mc_argumentvalue_new(void)
{
  mc_argumentvalue_t *self = (mc_argumentvalue_t *) calloc(1, sizeof(mc_argumentvalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_argumentvalue_add_encoding_length_malbinary(mc_argumentvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_isconvertedvalue, cursor);
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
int mc_argumentvalue_encode_malbinary(mc_argumentvalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_isconvertedvalue);
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
int mc_argumentvalue_decode_malbinary(mc_argumentvalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_isconvertedvalue);
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
void mc_argumentvalue_destroy(mc_argumentvalue_t ** self_p)
{
  if ((*self_p)->f_value_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_value, (*self_p)->f_value_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_argumentvalue_test(bool verbose)
{
  printf(" * MC:ArgumentValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
