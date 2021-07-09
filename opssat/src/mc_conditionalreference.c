#include "mc.h"


// structure definition for composite mc_conditionalreference
struct _mc_conditionalreference_t {
  mc_parameterexpression_t * f_condition;
  com_objectid_t * f_referenceid;
};

// fields accessors for composite mc_conditionalreference
mc_parameterexpression_t * mc_conditionalreference_get_condition(mc_conditionalreference_t * self)
{
  return self->f_condition;
}
void mc_conditionalreference_set_condition(mc_conditionalreference_t * self, mc_parameterexpression_t * f_condition)
{
  self->f_condition = f_condition;
}
com_objectid_t * mc_conditionalreference_get_referenceid(mc_conditionalreference_t * self)
{
  return self->f_referenceid;
}
void mc_conditionalreference_set_referenceid(mc_conditionalreference_t * self, com_objectid_t * f_referenceid)
{
  self->f_referenceid = f_referenceid;
}

// default constructor
mc_conditionalreference_t * mc_conditionalreference_new(void)
{
  mc_conditionalreference_t *self = (mc_conditionalreference_t *) calloc(1, sizeof(mc_conditionalreference_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_conditionalreference_add_encoding_length_malbinary(mc_conditionalreference_t * self, mal_encoder_t * encoder, void * cursor)
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
  rc = com_objectid_add_encoding_length_malbinary(self->f_referenceid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conditionalreference_encode_malbinary(mc_conditionalreference_t * self, mal_encoder_t * encoder, void * cursor)
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
  rc = com_objectid_encode_malbinary(self->f_referenceid, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conditionalreference_decode_malbinary(mc_conditionalreference_t * self, mal_decoder_t * decoder, void * cursor)
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
  self->f_referenceid = com_objectid_new();
  if (self->f_referenceid == NULL) return -1;
  rc = com_objectid_decode_malbinary(self->f_referenceid, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_conditionalreference_destroy(mc_conditionalreference_t ** self_p)
{
  if ((*self_p)->f_condition != NULL)
  {
    mc_parameterexpression_destroy(& (*self_p)->f_condition);
  }
  if ((*self_p)->f_referenceid != NULL)
  {
    com_objectid_destroy(& (*self_p)->f_referenceid);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_conditionalreference_test(bool verbose)
{
  printf(" * MC:ConditionalReference: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
