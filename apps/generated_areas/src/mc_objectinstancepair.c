#include "mc.h"


// structure definition for composite mc_objectinstancepair
struct _mc_objectinstancepair_t {
  mal_long_t f_objidentityinstanceid;
  mal_long_t f_objdefinstanceid;
};

// fields accessors for composite mc_objectinstancepair
mal_long_t mc_objectinstancepair_get_objidentityinstanceid(mc_objectinstancepair_t * self)
{
  return self->f_objidentityinstanceid;
}
void mc_objectinstancepair_set_objidentityinstanceid(mc_objectinstancepair_t * self, mal_long_t f_objidentityinstanceid)
{
  self->f_objidentityinstanceid = f_objidentityinstanceid;
}
mal_long_t mc_objectinstancepair_get_objdefinstanceid(mc_objectinstancepair_t * self)
{
  return self->f_objdefinstanceid;
}
void mc_objectinstancepair_set_objdefinstanceid(mc_objectinstancepair_t * self, mal_long_t f_objdefinstanceid)
{
  self->f_objdefinstanceid = f_objdefinstanceid;
}

// default constructor
mc_objectinstancepair_t * mc_objectinstancepair_new(void)
{
  mc_objectinstancepair_t *self = (mc_objectinstancepair_t *) calloc(1, sizeof(mc_objectinstancepair_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_objectinstancepair_add_encoding_length_malbinary(mc_objectinstancepair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_objidentityinstanceid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_objdefinstanceid, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_objectinstancepair_encode_malbinary(mc_objectinstancepair_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_objidentityinstanceid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_long(encoder, cursor, self->f_objdefinstanceid);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_objectinstancepair_decode_malbinary(mc_objectinstancepair_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_objidentityinstanceid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_objdefinstanceid);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_objectinstancepair_destroy(mc_objectinstancepair_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_objectinstancepair_test(bool verbose)
{
  printf(" * MC:ObjectInstancePair: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
