#include "mc.h"


// structure definition for composite mc_check_checktypedinstance
struct _mc_check_checktypedinstance_t {
  com_objecttype_t * f_objdefchecktype;
  mc_objectinstancepair_t * f_objinstids;
};

// fields accessors for composite mc_check_checktypedinstance
com_objecttype_t * mc_check_checktypedinstance_get_objdefchecktype(mc_check_checktypedinstance_t * self)
{
  return self->f_objdefchecktype;
}
void mc_check_checktypedinstance_set_objdefchecktype(mc_check_checktypedinstance_t * self, com_objecttype_t * f_objdefchecktype)
{
  self->f_objdefchecktype = f_objdefchecktype;
}
mc_objectinstancepair_t * mc_check_checktypedinstance_get_objinstids(mc_check_checktypedinstance_t * self)
{
  return self->f_objinstids;
}
void mc_check_checktypedinstance_set_objinstids(mc_check_checktypedinstance_t * self, mc_objectinstancepair_t * f_objinstids)
{
  self->f_objinstids = f_objinstids;
}

// default constructor
mc_check_checktypedinstance_t * mc_check_checktypedinstance_new(void)
{
  mc_check_checktypedinstance_t *self = (mc_check_checktypedinstance_t *) calloc(1, sizeof(mc_check_checktypedinstance_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_check_checktypedinstance_add_encoding_length_malbinary(mc_check_checktypedinstance_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = com_objecttype_add_encoding_length_malbinary(self->f_objdefchecktype, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_objinstids != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_objinstids != NULL))
  {
    rc = mc_objectinstancepair_add_encoding_length_malbinary(self->f_objinstids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checktypedinstance_encode_malbinary(mc_check_checktypedinstance_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = com_objecttype_encode_malbinary(self->f_objdefchecktype, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_objinstids != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_objectinstancepair_encode_malbinary(self->f_objinstids, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_check_checktypedinstance_decode_malbinary(mc_check_checktypedinstance_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  self->f_objdefchecktype = com_objecttype_new();
  if (self->f_objdefchecktype == NULL) return -1;
  rc = com_objecttype_decode_malbinary(self->f_objdefchecktype, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_objinstids = mc_objectinstancepair_new();
    if (self->f_objinstids == NULL) return -1;
    rc = mc_objectinstancepair_decode_malbinary(self->f_objinstids, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_objinstids = NULL;
  }
  return rc;
}

// destructor
void mc_check_checktypedinstance_destroy(mc_check_checktypedinstance_t ** self_p)
{
  if ((*self_p)->f_objdefchecktype != NULL)
  {
    com_objecttype_destroy(& (*self_p)->f_objdefchecktype);
  }
  if ((*self_p)->f_objinstids != NULL)
  {
    mc_objectinstancepair_destroy(& (*self_p)->f_objinstids);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_check_checktypedinstance_test(bool verbose)
{
  printf(" * MC:Check:CheckTypedInstance: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
