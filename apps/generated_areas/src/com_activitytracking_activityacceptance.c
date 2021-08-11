#include "com.h"


// structure definition for composite com_activitytracking_activityacceptance
struct _com_activitytracking_activityacceptance_t {
  mal_boolean_t f_success;
};

// fields accessors for composite com_activitytracking_activityacceptance
mal_boolean_t com_activitytracking_activityacceptance_get_success(com_activitytracking_activityacceptance_t * self)
{
  return self->f_success;
}
void com_activitytracking_activityacceptance_set_success(com_activitytracking_activityacceptance_t * self, mal_boolean_t f_success)
{
  self->f_success = f_success;
}

// default constructor
com_activitytracking_activityacceptance_t * com_activitytracking_activityacceptance_new(void)
{
  com_activitytracking_activityacceptance_t *self = (com_activitytracking_activityacceptance_t *) calloc(1, sizeof(com_activitytracking_activityacceptance_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_activitytracking_activityacceptance_add_encoding_length_malbinary(com_activitytracking_activityacceptance_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_success, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_activityacceptance_encode_malbinary(com_activitytracking_activityacceptance_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_success);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_activityacceptance_decode_malbinary(com_activitytracking_activityacceptance_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_success);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_activitytracking_activityacceptance_destroy(com_activitytracking_activityacceptance_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_activitytracking_activityacceptance_test(bool verbose)
{
  printf(" * COM:ActivityTracking:ActivityAcceptance: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
