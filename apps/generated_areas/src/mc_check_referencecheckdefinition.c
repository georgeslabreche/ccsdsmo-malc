#include "mc.h"


// structure definition for composite mc_check_referencecheckdefinition
struct _mc_check_referencecheckdefinition_t {
  mal_string_t * f_description;
  mc_severity_t f_checkseverity;
  mal_duration_t f_maxreportinginterval;
  mal_uinteger_t f_nominalcount;
  mal_duration_t f_nominaltime;
  mal_uinteger_t f_violationcount;
  mal_duration_t f_violationtime;
  com_archive_expressionoperator_t f_operator;
  mc_check_referencevalue_t * f_checkreference;
};

// fields accessors for composite mc_check_referencecheckdefinition
mal_string_t * mc_check_referencecheckdefinition_get_description(mc_check_referencecheckdefinition_t * self)
{
  return self->f_description;
}
void mc_check_referencecheckdefinition_set_description(mc_check_referencecheckdefinition_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mc_severity_t mc_check_referencecheckdefinition_get_checkseverity(mc_check_referencecheckdefinition_t * self)
{
  return self->f_checkseverity;
}
void mc_check_referencecheckdefinition_set_checkseverity(mc_check_referencecheckdefinition_t * self, mc_severity_t f_checkseverity)
{
  self->f_checkseverity = f_checkseverity;
}
mal_duration_t mc_check_referencecheckdefinition_get_maxreportinginterval(mc_check_referencecheckdefinition_t * self)
{
  return self->f_maxreportinginterval;
}
void mc_check_referencecheckdefinition_set_maxreportinginterval(mc_check_referencecheckdefinition_t * self, mal_duration_t f_maxreportinginterval)
{
  self->f_maxreportinginterval = f_maxreportinginterval;
}
mal_uinteger_t mc_check_referencecheckdefinition_get_nominalcount(mc_check_referencecheckdefinition_t * self)
{
  return self->f_nominalcount;
}
void mc_check_referencecheckdefinition_set_nominalcount(mc_check_referencecheckdefinition_t * self, mal_uinteger_t f_nominalcount)
{
  self->f_nominalcount = f_nominalcount;
}
mal_duration_t mc_check_referencecheckdefinition_get_nominaltime(mc_check_referencecheckdefinition_t * self)
{
  return self->f_nominaltime;
}
void mc_check_referencecheckdefinition_set_nominaltime(mc_check_referencecheckdefinition_t * self, mal_duration_t f_nominaltime)
{
  self->f_nominaltime = f_nominaltime;
}
mal_uinteger_t mc_check_referencecheckdefinition_get_violationcount(mc_check_referencecheckdefinition_t * self)
{
  return self->f_violationcount;
}
void mc_check_referencecheckdefinition_set_violationcount(mc_check_referencecheckdefinition_t * self, mal_uinteger_t f_violationcount)
{
  self->f_violationcount = f_violationcount;
}
mal_duration_t mc_check_referencecheckdefinition_get_violationtime(mc_check_referencecheckdefinition_t * self)
{
  return self->f_violationtime;
}
void mc_check_referencecheckdefinition_set_violationtime(mc_check_referencecheckdefinition_t * self, mal_duration_t f_violationtime)
{
  self->f_violationtime = f_violationtime;
}
com_archive_expressionoperator_t mc_check_referencecheckdefinition_get_operator(mc_check_referencecheckdefinition_t * self)
{
  return self->f_operator;
}
void mc_check_referencecheckdefinition_set_operator(mc_check_referencecheckdefinition_t * self, com_archive_expressionoperator_t f_operator)
{
  self->f_operator = f_operator;
}
mc_check_referencevalue_t * mc_check_referencecheckdefinition_get_checkreference(mc_check_referencecheckdefinition_t * self)
{
  return self->f_checkreference;
}
void mc_check_referencecheckdefinition_set_checkreference(mc_check_referencecheckdefinition_t * self, mc_check_referencevalue_t * f_checkreference)
{
  self->f_checkreference = f_checkreference;
}

// default constructor
mc_check_referencecheckdefinition_t * mc_check_referencecheckdefinition_new(void)
{
  mc_check_referencecheckdefinition_t *self = (mc_check_referencecheckdefinition_t *) calloc(1, sizeof(mc_check_referencecheckdefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_referencecheckdefinition_add_encoding_length_malbinary(mc_check_referencecheckdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
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
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_nominaltime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_violationcount, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_duration_encoding_length(encoder, self->f_violationtime, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_operator, cursor);
  if (rc < 0)
    return rc;
  rc = mc_check_referencevalue_add_encoding_length_malbinary(self->f_checkreference, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_referencecheckdefinition_encode_malbinary(mc_check_referencecheckdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
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
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_nominaltime);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_violationcount);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_duration(encoder, cursor, self->f_violationtime);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_operator);
  if (rc < 0)
    return rc;
  rc = mc_check_referencevalue_encode_malbinary(self->f_checkreference, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_check_referencecheckdefinition_decode_malbinary(mc_check_referencecheckdefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
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
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_nominaltime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_violationcount);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_duration(decoder, cursor, &self->f_violationtime);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_operator = (com_archive_expressionoperator_t) enumerated_value;
  self->f_checkreference = mc_check_referencevalue_new();
  if (self->f_checkreference == NULL) return -1;
  rc = mc_check_referencevalue_decode_malbinary(self->f_checkreference, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_check_referencecheckdefinition_destroy(mc_check_referencecheckdefinition_t ** self_p)
{
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_checkreference != NULL)
  {
    mc_check_referencevalue_destroy(& (*self_p)->f_checkreference);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_referencecheckdefinition_test(bool verbose)
{
  printf(" * MC:Check:ReferenceCheckDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
