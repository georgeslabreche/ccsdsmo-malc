#include "com.h"


// structure definition for composite com_activitytracking_activityexecution
struct _com_activitytracking_activityexecution_t {
  mal_boolean_t f_success;
  mal_uinteger_t f_executionstage;
  mal_uinteger_t f_stagecount;
};

// fields accessors for composite com_activitytracking_activityexecution
mal_boolean_t com_activitytracking_activityexecution_get_success(com_activitytracking_activityexecution_t * self)
{
  return self->f_success;
}
void com_activitytracking_activityexecution_set_success(com_activitytracking_activityexecution_t * self, mal_boolean_t f_success)
{
  self->f_success = f_success;
}
mal_uinteger_t com_activitytracking_activityexecution_get_executionstage(com_activitytracking_activityexecution_t * self)
{
  return self->f_executionstage;
}
void com_activitytracking_activityexecution_set_executionstage(com_activitytracking_activityexecution_t * self, mal_uinteger_t f_executionstage)
{
  self->f_executionstage = f_executionstage;
}
mal_uinteger_t com_activitytracking_activityexecution_get_stagecount(com_activitytracking_activityexecution_t * self)
{
  return self->f_stagecount;
}
void com_activitytracking_activityexecution_set_stagecount(com_activitytracking_activityexecution_t * self, mal_uinteger_t f_stagecount)
{
  self->f_stagecount = f_stagecount;
}

// default constructor
com_activitytracking_activityexecution_t * com_activitytracking_activityexecution_new(void)
{
  com_activitytracking_activityexecution_t *self = (com_activitytracking_activityexecution_t *) calloc(1, sizeof(com_activitytracking_activityexecution_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_activitytracking_activityexecution_add_encoding_length_malbinary(com_activitytracking_activityexecution_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_success, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_executionstage, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_stagecount, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_activityexecution_encode_malbinary(com_activitytracking_activityexecution_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_success);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_executionstage);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_stagecount);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_activityexecution_decode_malbinary(com_activitytracking_activityexecution_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_success);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_executionstage);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_stagecount);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_activitytracking_activityexecution_destroy(com_activitytracking_activityexecution_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_activitytracking_activityexecution_test(bool verbose)
{
  printf(" * COM:ActivityTracking:ActivityExecution: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
