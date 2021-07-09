#include "mc.h"


// structure definition for composite mc_check_deltacheck
struct _mc_check_deltacheck_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mc_severity_t f_checkseverity;
  mal_duration_t f_maxreportinginterval;
  mal_uinteger_t f_nominalcount;
  mal_uinteger_t f_violationcount;
  mc_check_referencevalue_t * f_checkreference;
  mal_boolean_t f_violateinrange;
  mal_boolean_t f_samplebased;
  mal_boolean_t f_valuedelta;
  bool f_lowerthreshold_is_present;
  unsigned char f_lowerthreshold_attribute_tag;
  union mal_attribute_t f_lowerthreshold;
  bool f_upperthreshold_is_present;
  unsigned char f_upperthreshold_attribute_tag;
  union mal_attribute_t f_upperthreshold;
};

// fields accessors for composite mc_check_deltacheck
mal_identifier_t * mc_check_deltacheck_get_name(mc_check_deltacheck_t * self)
{
  return self->f_name;
}
void mc_check_deltacheck_set_name(mc_check_deltacheck_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * mc_check_deltacheck_get_description(mc_check_deltacheck_t * self)
{
  return self->f_description;
}
void mc_check_deltacheck_set_description(mc_check_deltacheck_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_severity_t mc_check_deltacheck_get_checkseverity(mc_check_deltacheck_t * self)
{
  return self->f_checkseverity;
}
void mc_check_deltacheck_set_checkseverity(mc_check_deltacheck_t * self, mc_severity_t f_checkseverity)
{
  self->f_checkseverity = f_checkseverity;
}
mal_duration_t mc_check_deltacheck_get_maxreportinginterval(mc_check_deltacheck_t * self)
{
  return self->f_maxreportinginterval;
}
void mc_check_deltacheck_set_maxreportinginterval(mc_check_deltacheck_t * self, mal_duration_t f_maxreportinginterval)
{
  self->f_maxreportinginterval = f_maxreportinginterval;
}
mal_uinteger_t mc_check_deltacheck_get_nominalcount(mc_check_deltacheck_t * self)
{
  return self->f_nominalcount;
}
void mc_check_deltacheck_set_nominalcount(mc_check_deltacheck_t * self, mal_uinteger_t f_nominalcount)
{
  self->f_nominalcount = f_nominalcount;
}
mal_uinteger_t mc_check_deltacheck_get_violationcount(mc_check_deltacheck_t * self)
{
  return self->f_violationcount;
}
void mc_check_deltacheck_set_violationcount(mc_check_deltacheck_t * self, mal_uinteger_t f_violationcount)
{
  self->f_violationcount = f_violationcount;
}
mc_check_referencevalue_t * mc_check_deltacheck_get_checkreference(mc_check_deltacheck_t * self)
{
  return self->f_checkreference;
}
void mc_check_deltacheck_set_checkreference(mc_check_deltacheck_t * self, mc_check_referencevalue_t * f_checkreference)
{
  self->f_checkreference = f_checkreference;
}
mal_boolean_t mc_check_deltacheck_get_violateinrange(mc_check_deltacheck_t * self)
{
  return self->f_violateinrange;
}
void mc_check_deltacheck_set_violateinrange(mc_check_deltacheck_t * self, mal_boolean_t f_violateinrange)
{
  self->f_violateinrange = f_violateinrange;
}
mal_boolean_t mc_check_deltacheck_get_samplebased(mc_check_deltacheck_t * self)
{
  return self->f_samplebased;
}
void mc_check_deltacheck_set_samplebased(mc_check_deltacheck_t * self, mal_boolean_t f_samplebased)
{
  self->f_samplebased = f_samplebased;
}
mal_boolean_t mc_check_deltacheck_get_valuedelta(mc_check_deltacheck_t * self)
{
  return self->f_valuedelta;
}
void mc_check_deltacheck_set_valuedelta(mc_check_deltacheck_t * self, mal_boolean_t f_valuedelta)
{
  self->f_valuedelta = f_valuedelta;
}
bool mc_check_deltacheck_lowerthreshold_is_present(mc_check_deltacheck_t * self)
{
  return self->f_lowerthreshold_is_present;
}
void mc_check_deltacheck_lowerthreshold_set_present(mc_check_deltacheck_t * self, bool is_present)
{
  self->f_lowerthreshold_is_present = is_present;
}
unsigned char mc_check_deltacheck_lowerthreshold_get_attribute_tag(mc_check_deltacheck_t * self)
{
  return self->f_lowerthreshold_attribute_tag;
}
void mc_check_deltacheck_lowerthreshold_set_attribute_tag(mc_check_deltacheck_t * self, unsigned char attribute_tag)
{
  self->f_lowerthreshold_attribute_tag = attribute_tag;
}
bool mc_check_deltacheck_upperthreshold_is_present(mc_check_deltacheck_t * self)
{
  return self->f_upperthreshold_is_present;
}
void mc_check_deltacheck_upperthreshold_set_present(mc_check_deltacheck_t * self, bool is_present)
{
  self->f_upperthreshold_is_present = is_present;
}
unsigned char mc_check_deltacheck_upperthreshold_get_attribute_tag(mc_check_deltacheck_t * self)
{
  return self->f_upperthreshold_attribute_tag;
}
void mc_check_deltacheck_upperthreshold_set_attribute_tag(mc_check_deltacheck_t * self, unsigned char attribute_tag)
{
  self->f_upperthreshold_attribute_tag = attribute_tag;
}

// default constructor
mc_check_deltacheck_t * mc_check_deltacheck_new(void)
{
  mc_check_deltacheck_t *self = (mc_check_deltacheck_t *) calloc(1, sizeof(mc_check_deltacheck_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_deltacheck_add_encoding_length_malbinary(mc_check_deltacheck_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_checkseverity, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_maxreportinginterval, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_nominalcount, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_violationcount, cursor);
  if (rc < 0)
    return rc;
  rc = mc_check_referencevalue_add_encoding_length_malbinary(self->f_checkreference, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_violateinrange, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_samplebased, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_valuedelta, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_lowerthreshold_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_lowerthreshold_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_lowerthreshold_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_lowerthreshold_attribute_tag, self->f_lowerthreshold, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_upperthreshold_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_upperthreshold_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_upperthreshold_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_upperthreshold_attribute_tag, self->f_upperthreshold, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_deltacheck_encode_malbinary(mc_check_deltacheck_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_checkseverity);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_maxreportinginterval);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_nominalcount);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_violationcount);
  if (rc < 0)
    return rc;
  rc = mc_check_referencevalue_encode_malbinary(self->f_checkreference, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_violateinrange);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_samplebased);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_valuedelta);
  if (rc < 0)
    return rc;
  presence_flag = self->f_lowerthreshold_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_lowerthreshold_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_lowerthreshold_attribute_tag, self->f_lowerthreshold);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_upperthreshold_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_upperthreshold_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_upperthreshold_attribute_tag, self->f_upperthreshold);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_deltacheck_decode_malbinary(mc_check_deltacheck_t * self, mal_decoder_t * decoder, void * cursor)
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
  self->f_checkseverity = (mc_severity_t) enumerated_value;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_maxreportinginterval);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_nominalcount);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_violationcount);
  if (rc < 0)
    return rc;
  self->f_checkreference = mc_check_referencevalue_new();
  if (self->f_checkreference == NULL) return -1;
  rc = mc_check_referencevalue_decode_malbinary(self->f_checkreference, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_violateinrange);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_samplebased);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_valuedelta);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_lowerthreshold_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_lowerthreshold_attribute_tag, &self->f_lowerthreshold);
    if (rc < 0)
      return rc;
  }
  self->f_lowerthreshold_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_upperthreshold_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_upperthreshold_attribute_tag, &self->f_upperthreshold);
    if (rc < 0)
      return rc;
  }
  self->f_upperthreshold_is_present = presence_flag;
  return rc;
}

// destructor
void mc_check_deltacheck_destroy(mc_check_deltacheck_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_checkreference != NULL)
  {
    mc_check_referencevalue_destroy(& (*self_p)->f_checkreference);
  }
  if ((*self_p)->f_lowerthreshold_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_lowerthreshold, (*self_p)->f_lowerthreshold_attribute_tag);
  }
  if ((*self_p)->f_upperthreshold_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_upperthreshold, (*self_p)->f_upperthreshold_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_deltacheck_test(bool verbose)
{
  printf(" * MC:Check:DeltaCheck: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
