#include "mc.h"


// structure definition for composite mc_check_constantcheck
struct _mc_check_constantcheck_t {
  mal_identifier_t * f_name;
  mal_string_t * f_description;
  mc_severity_t f_checkseverity;
  mal_duration_t f_maxreportinginterval;
  mal_uinteger_t f_nominalcount;
  mal_uinteger_t f_violationcount;
  com_archive_expressionoperator_t f_operator;
  mc_attributevalue_list_t * f_values;
};

// fields accessors for composite mc_check_constantcheck
mal_identifier_t * mc_check_constantcheck_get_name(mc_check_constantcheck_t * self)
{
  return self->f_name;
}
void mc_check_constantcheck_set_name(mc_check_constantcheck_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mal_string_t * mc_check_constantcheck_get_description(mc_check_constantcheck_t * self)
{
  return self->f_description;
}
void mc_check_constantcheck_set_description(mc_check_constantcheck_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_severity_t mc_check_constantcheck_get_checkseverity(mc_check_constantcheck_t * self)
{
  return self->f_checkseverity;
}
void mc_check_constantcheck_set_checkseverity(mc_check_constantcheck_t * self, mc_severity_t f_checkseverity)
{
  self->f_checkseverity = f_checkseverity;
}
mal_duration_t mc_check_constantcheck_get_maxreportinginterval(mc_check_constantcheck_t * self)
{
  return self->f_maxreportinginterval;
}
void mc_check_constantcheck_set_maxreportinginterval(mc_check_constantcheck_t * self, mal_duration_t f_maxreportinginterval)
{
  self->f_maxreportinginterval = f_maxreportinginterval;
}
mal_uinteger_t mc_check_constantcheck_get_nominalcount(mc_check_constantcheck_t * self)
{
  return self->f_nominalcount;
}
void mc_check_constantcheck_set_nominalcount(mc_check_constantcheck_t * self, mal_uinteger_t f_nominalcount)
{
  self->f_nominalcount = f_nominalcount;
}
mal_uinteger_t mc_check_constantcheck_get_violationcount(mc_check_constantcheck_t * self)
{
  return self->f_violationcount;
}
void mc_check_constantcheck_set_violationcount(mc_check_constantcheck_t * self, mal_uinteger_t f_violationcount)
{
  self->f_violationcount = f_violationcount;
}
com_archive_expressionoperator_t mc_check_constantcheck_get_operator(mc_check_constantcheck_t * self)
{
  return self->f_operator;
}
void mc_check_constantcheck_set_operator(mc_check_constantcheck_t * self, com_archive_expressionoperator_t f_operator)
{
  self->f_operator = f_operator;
}
mc_attributevalue_list_t * mc_check_constantcheck_get_values(mc_check_constantcheck_t * self)
{
  return self->f_values;
}
void mc_check_constantcheck_set_values(mc_check_constantcheck_t * self, mc_attributevalue_list_t * f_values)
{
  self->f_values = f_values;
}

// default constructor
mc_check_constantcheck_t * mc_check_constantcheck_new(void)
{
  mc_check_constantcheck_t *self = (mc_check_constantcheck_t *) calloc(1, sizeof(mc_check_constantcheck_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_constantcheck_add_encoding_length_malbinary(mc_check_constantcheck_t * self, mal_encoder_t * encoder, void * cursor)
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
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_operator, cursor);
  if (rc < 0)
    return rc;
  rc = mc_attributevalue_list_add_encoding_length_malbinary(self->f_values, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_constantcheck_encode_malbinary(mc_check_constantcheck_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
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
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_operator);
  if (rc < 0)
    return rc;
  rc = mc_attributevalue_list_encode_malbinary(self->f_values, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_constantcheck_decode_malbinary(mc_check_constantcheck_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
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
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_operator = (com_archive_expressionoperator_t) enumerated_value;
  self->f_values = mc_attributevalue_list_new(0);
  if (self->f_values == NULL) return -1;
  rc = mc_attributevalue_list_decode_malbinary(self->f_values, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_check_constantcheck_destroy(mc_check_constantcheck_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_values != NULL)
  {
    mc_attributevalue_list_destroy(& (*self_p)->f_values);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_constantcheck_test(bool verbose)
{
  printf(" * MC:Check:ConstantCheck: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
