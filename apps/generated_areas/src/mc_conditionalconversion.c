#include "mc.h"


// structure definition for composite mc_conditionalconversion
struct _mc_conditionalconversion_t {
  mc_parameterexpression_t * f_condition;
  com_objectkey_t * f_conversionid;
};

// fields accessors for composite mc_conditionalconversion
mc_parameterexpression_t * mc_conditionalconversion_get_condition(mc_conditionalconversion_t * self)
{
  return self->f_condition;
}
void mc_conditionalconversion_set_condition(mc_conditionalconversion_t * self, mc_parameterexpression_t * f_condition)
{
  self->f_condition = f_condition;
}
com_objectkey_t * mc_conditionalconversion_get_conversionid(mc_conditionalconversion_t * self)
{
  return self->f_conversionid;
}
void mc_conditionalconversion_set_conversionid(mc_conditionalconversion_t * self, com_objectkey_t * f_conversionid)
{
  self->f_conversionid = f_conversionid;
}

// default constructor
mc_conditionalconversion_t * mc_conditionalconversion_new(void)
{
  mc_conditionalconversion_t *self = (mc_conditionalconversion_t *) calloc(1, sizeof(mc_conditionalconversion_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_conditionalconversion_add_encoding_length_malbinary(mc_conditionalconversion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_condition != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_condition != NULL))
  {
    rc = mc_parameterexpression_add_encoding_length_malbinary(self->f_condition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = com_objectkey_add_encoding_length_malbinary(self->f_conversionid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conditionalconversion_encode_malbinary(mc_conditionalconversion_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = (self->f_condition != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_parameterexpression_encode_malbinary(self->f_condition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = com_objectkey_encode_malbinary(self->f_conversionid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conditionalconversion_decode_malbinary(mc_conditionalconversion_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_condition = mc_parameterexpression_new();
    if (self->f_condition == NULL) return -1;
    rc = mc_parameterexpression_decode_malbinary(self->f_condition, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_condition = NULL;
  }
  self->f_conversionid = com_objectkey_new();
  if (self->f_conversionid == NULL) return -1;
  rc = com_objectkey_decode_malbinary(self->f_conversionid, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_conditionalconversion_destroy(mc_conditionalconversion_t ** self_p)
{
  if ((*self_p)->f_condition != NULL)
  {
    mc_parameterexpression_destroy(& (*self_p)->f_condition);
  }
  if ((*self_p)->f_conversionid != NULL)
  {
    com_objectkey_destroy(& (*self_p)->f_conversionid);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_conditionalconversion_test(bool verbose)
{
  printf(" * MC:ConditionalConversion: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
