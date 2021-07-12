#include "mc.h"


// structure definition for composite mc_action_actioncreationrequest
struct _mc_action_actioncreationrequest_t {
  mal_identifier_t * f_name;
  mc_action_actiondefinitiondetails_t * f_actiondefdetails;
};

// fields accessors for composite mc_action_actioncreationrequest
mal_identifier_t * mc_action_actioncreationrequest_get_name(mc_action_actioncreationrequest_t * self)
{
  return self->f_name;
}
void mc_action_actioncreationrequest_set_name(mc_action_actioncreationrequest_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mc_action_actiondefinitiondetails_t * mc_action_actioncreationrequest_get_actiondefdetails(mc_action_actioncreationrequest_t * self)
{
  return self->f_actiondefdetails;
}
void mc_action_actioncreationrequest_set_actiondefdetails(mc_action_actioncreationrequest_t * self, mc_action_actiondefinitiondetails_t * f_actiondefdetails)
{
  self->f_actiondefdetails = f_actiondefdetails;
}

// default constructor
mc_action_actioncreationrequest_t * mc_action_actioncreationrequest_new(void)
{
  mc_action_actioncreationrequest_t *self = (mc_action_actioncreationrequest_t *) calloc(1, sizeof(mc_action_actioncreationrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_action_actioncreationrequest_add_encoding_length_malbinary(mc_action_actioncreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mc_action_actiondefinitiondetails_add_encoding_length_malbinary(self->f_actiondefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_action_actioncreationrequest_encode_malbinary(mc_action_actioncreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mc_action_actiondefinitiondetails_encode_malbinary(self->f_actiondefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_action_actioncreationrequest_decode_malbinary(mc_action_actioncreationrequest_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  self->f_actiondefdetails = mc_action_actiondefinitiondetails_new();
  if (self->f_actiondefdetails == NULL) return -1;
  rc = mc_action_actiondefinitiondetails_decode_malbinary(self->f_actiondefdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_action_actioncreationrequest_destroy(mc_action_actioncreationrequest_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_actiondefdetails != NULL)
  {
    mc_action_actiondefinitiondetails_destroy(& (*self_p)->f_actiondefdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_action_actioncreationrequest_test(bool verbose)
{
  printf(" * MC:Action:ActionCreationRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
