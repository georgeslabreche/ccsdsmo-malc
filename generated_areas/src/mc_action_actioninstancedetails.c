#include "mc.h"


// structure definition for composite mc_action_actioninstancedetails
struct _mc_action_actioninstancedetails_t {
  mal_long_t f_definstid;
  mal_boolean_t f_stagestartedrequired;
  mal_boolean_t f_stageprogressrequired;
  mal_boolean_t f_stagecompletedrequired;
  mc_attributevalue_list_t * f_argumentvalues;
  mal_identifier_list_t * f_argumentids;
  mal_boolean_list_t * f_israwvalue;
};

// fields accessors for composite mc_action_actioninstancedetails
mal_long_t mc_action_actioninstancedetails_get_definstid(mc_action_actioninstancedetails_t * self)
{
  return self->f_definstid;
}
void mc_action_actioninstancedetails_set_definstid(mc_action_actioninstancedetails_t * self, mal_long_t f_definstid)
{
  self->f_definstid = f_definstid;
}
mal_boolean_t mc_action_actioninstancedetails_get_stagestartedrequired(mc_action_actioninstancedetails_t * self)
{
  return self->f_stagestartedrequired;
}
void mc_action_actioninstancedetails_set_stagestartedrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stagestartedrequired)
{
  self->f_stagestartedrequired = f_stagestartedrequired;
}
mal_boolean_t mc_action_actioninstancedetails_get_stageprogressrequired(mc_action_actioninstancedetails_t * self)
{
  return self->f_stageprogressrequired;
}
void mc_action_actioninstancedetails_set_stageprogressrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stageprogressrequired)
{
  self->f_stageprogressrequired = f_stageprogressrequired;
}
mal_boolean_t mc_action_actioninstancedetails_get_stagecompletedrequired(mc_action_actioninstancedetails_t * self)
{
  return self->f_stagecompletedrequired;
}
void mc_action_actioninstancedetails_set_stagecompletedrequired(mc_action_actioninstancedetails_t * self, mal_boolean_t f_stagecompletedrequired)
{
  self->f_stagecompletedrequired = f_stagecompletedrequired;
}
mc_attributevalue_list_t * mc_action_actioninstancedetails_get_argumentvalues(mc_action_actioninstancedetails_t * self)
{
  return self->f_argumentvalues;
}
void mc_action_actioninstancedetails_set_argumentvalues(mc_action_actioninstancedetails_t * self, mc_attributevalue_list_t * f_argumentvalues)
{
  self->f_argumentvalues = f_argumentvalues;
}
mal_identifier_list_t * mc_action_actioninstancedetails_get_argumentids(mc_action_actioninstancedetails_t * self)
{
  return self->f_argumentids;
}
void mc_action_actioninstancedetails_set_argumentids(mc_action_actioninstancedetails_t * self, mal_identifier_list_t * f_argumentids)
{
  self->f_argumentids = f_argumentids;
}
mal_boolean_list_t * mc_action_actioninstancedetails_get_israwvalue(mc_action_actioninstancedetails_t * self)
{
  return self->f_israwvalue;
}
void mc_action_actioninstancedetails_set_israwvalue(mc_action_actioninstancedetails_t * self, mal_boolean_list_t * f_israwvalue)
{
  self->f_israwvalue = f_israwvalue;
}

// default constructor
mc_action_actioninstancedetails_t * mc_action_actioninstancedetails_new(void)
{
  mc_action_actioninstancedetails_t *self = (mc_action_actioninstancedetails_t *) calloc(1, sizeof(mc_action_actioninstancedetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_action_actioninstancedetails_add_encoding_length_malbinary(mc_action_actioninstancedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_definstid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_stagestartedrequired, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_stageprogressrequired, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_stagecompletedrequired, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_argumentvalues != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_argumentvalues != NULL))
  {
    rc = mc_attributevalue_list_add_encoding_length_malbinary(self->f_argumentvalues, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_argumentids != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_argumentids != NULL))
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(self->f_argumentids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_israwvalue != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_israwvalue != NULL))
  {
    rc = mal_boolean_list_add_encoding_length_malbinary(self->f_israwvalue, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_action_actioninstancedetails_encode_malbinary(mc_action_actioninstancedetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_definstid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_stagestartedrequired);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_stageprogressrequired);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_stagecompletedrequired);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_argumentvalues != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_attributevalue_list_encode_malbinary(self->f_argumentvalues, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_argumentids != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_identifier_list_encode_malbinary(self->f_argumentids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_israwvalue != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_boolean_list_encode_malbinary(self->f_israwvalue, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_action_actioninstancedetails_decode_malbinary(mc_action_actioninstancedetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_definstid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_stagestartedrequired);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_stageprogressrequired);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_stagecompletedrequired);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_argumentvalues = mc_attributevalue_list_new(0);
    if (self->f_argumentvalues == NULL) return -1;
    rc = mc_attributevalue_list_decode_malbinary(self->f_argumentvalues, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_argumentvalues = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_argumentids = mal_identifier_list_new(0);
    if (self->f_argumentids == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary(self->f_argumentids, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_argumentids = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_israwvalue = mal_boolean_list_new(0);
    if (self->f_israwvalue == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary(self->f_israwvalue, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_israwvalue = NULL;
  }
  return rc;
}

// destructor
void mc_action_actioninstancedetails_destroy(mc_action_actioninstancedetails_t ** self_p)
{
  if ((*self_p)->f_argumentvalues != NULL)
  {
    mc_attributevalue_list_destroy(& (*self_p)->f_argumentvalues);
  }
  if ((*self_p)->f_argumentids != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_argumentids);
  }
  if ((*self_p)->f_israwvalue != NULL)
  {
    mal_boolean_list_destroy(& (*self_p)->f_israwvalue);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_action_actioninstancedetails_test(bool verbose)
{
  printf(" * MC:Action:ActionInstanceDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
