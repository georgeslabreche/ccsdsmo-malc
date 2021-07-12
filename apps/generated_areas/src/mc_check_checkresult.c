#include "mc.h"


// structure definition for composite mc_check_checkresult
struct _mc_check_checkresult_t {
  mc_check_checkstate_t f_previouscheckstate;
  mc_check_checkstate_t f_currentcheckstate;
  bool f_checkedvalue_is_present;
  unsigned char f_checkedvalue_attribute_tag;
  union mal_attribute_t f_checkedvalue;
  bool f_previousevaluationresult_is_present;
  mal_boolean_t f_previousevaluationresult;
  bool f_currentevaluationresult_is_present;
  mal_boolean_t f_currentevaluationresult;
};

// fields accessors for composite mc_check_checkresult
mc_check_checkstate_t mc_check_checkresult_get_previouscheckstate(mc_check_checkresult_t * self)
{
  return self->f_previouscheckstate;
}
void mc_check_checkresult_set_previouscheckstate(mc_check_checkresult_t * self, mc_check_checkstate_t f_previouscheckstate)
{
  self->f_previouscheckstate = f_previouscheckstate;
}
mc_check_checkstate_t mc_check_checkresult_get_currentcheckstate(mc_check_checkresult_t * self)
{
  return self->f_currentcheckstate;
}
void mc_check_checkresult_set_currentcheckstate(mc_check_checkresult_t * self, mc_check_checkstate_t f_currentcheckstate)
{
  self->f_currentcheckstate = f_currentcheckstate;
}
bool mc_check_checkresult_checkedvalue_is_present(mc_check_checkresult_t * self)
{
  return self->f_checkedvalue_is_present;
}
void mc_check_checkresult_checkedvalue_set_present(mc_check_checkresult_t * self, bool is_present)
{
  self->f_checkedvalue_is_present = is_present;
}
unsigned char mc_check_checkresult_checkedvalue_get_attribute_tag(mc_check_checkresult_t * self)
{
  return self->f_checkedvalue_attribute_tag;
}
void mc_check_checkresult_checkedvalue_set_attribute_tag(mc_check_checkresult_t * self, unsigned char attribute_tag)
{
  self->f_checkedvalue_attribute_tag = attribute_tag;
}
bool mc_check_checkresult_previousevaluationresult_is_present(mc_check_checkresult_t * self)
{
  return self->f_previousevaluationresult_is_present;
}
void mc_check_checkresult_previousevaluationresult_set_present(mc_check_checkresult_t * self, bool is_present)
{
  self->f_previousevaluationresult_is_present = is_present;
}
mal_boolean_t mc_check_checkresult_get_previousevaluationresult(mc_check_checkresult_t * self)
{
  return self->f_previousevaluationresult;
}
void mc_check_checkresult_set_previousevaluationresult(mc_check_checkresult_t * self, mal_boolean_t f_previousevaluationresult)
{
  self->f_previousevaluationresult = f_previousevaluationresult;
}
bool mc_check_checkresult_currentevaluationresult_is_present(mc_check_checkresult_t * self)
{
  return self->f_currentevaluationresult_is_present;
}
void mc_check_checkresult_currentevaluationresult_set_present(mc_check_checkresult_t * self, bool is_present)
{
  self->f_currentevaluationresult_is_present = is_present;
}
mal_boolean_t mc_check_checkresult_get_currentevaluationresult(mc_check_checkresult_t * self)
{
  return self->f_currentevaluationresult;
}
void mc_check_checkresult_set_currentevaluationresult(mc_check_checkresult_t * self, mal_boolean_t f_currentevaluationresult)
{
  self->f_currentevaluationresult = f_currentevaluationresult;
}

// default constructor
mc_check_checkresult_t * mc_check_checkresult_new(void)
{
  mc_check_checkresult_t *self = (mc_check_checkresult_t *) calloc(1, sizeof(mc_check_checkresult_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checkresult_add_encoding_length_malbinary(mc_check_checkresult_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_previouscheckstate, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_currentcheckstate, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_checkedvalue_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_checkedvalue_is_present)
  {
    rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_checkedvalue_attribute_tag, cursor);
    if (rc < 0)
      return rc;
    rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_checkedvalue_attribute_tag, self->f_checkedvalue, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_previousevaluationresult_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_previousevaluationresult_is_present)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_previousevaluationresult, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_currentevaluationresult_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_currentevaluationresult_is_present)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_currentevaluationresult, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checkresult_encode_malbinary(mc_check_checkresult_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_previouscheckstate);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_currentcheckstate);
  if (rc < 0)
    return rc;
  presence_flag = self->f_checkedvalue_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_checkedvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_encoder_encode_attribute(encoder, cursor, self->f_checkedvalue_attribute_tag, self->f_checkedvalue);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_previousevaluationresult_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, self->f_previousevaluationresult);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_currentevaluationresult_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, self->f_currentevaluationresult);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checkresult_decode_malbinary(mc_check_checkresult_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_previouscheckstate = (mc_check_checkstate_t) enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_currentcheckstate = (mc_check_checkstate_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_checkedvalue_attribute_tag);
    if (rc < 0)
      return rc;
    rc = mal_decoder_decode_attribute(decoder, cursor, self->f_checkedvalue_attribute_tag, &self->f_checkedvalue);
    if (rc < 0)
      return rc;
  }
  self->f_checkedvalue_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_previousevaluationresult);
    if (rc < 0)
      return rc;
  }
  self->f_previousevaluationresult_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_currentevaluationresult);
    if (rc < 0)
      return rc;
  }
  self->f_currentevaluationresult_is_present = presence_flag;
  return rc;
}

// destructor
void mc_check_checkresult_destroy(mc_check_checkresult_t ** self_p)
{
  if ((*self_p)->f_checkedvalue_is_present)
  {
    mal_attribute_destroy(&(*self_p)->f_checkedvalue, (*self_p)->f_checkedvalue_attribute_tag);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checkresult_test(bool verbose)
{
  printf(" * MC:Check:CheckResult: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
