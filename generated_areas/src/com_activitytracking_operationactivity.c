#include "com.h"


// structure definition for composite com_activitytracking_operationactivity
struct _com_activitytracking_operationactivity_t {
  mal_interactiontype_t f_interactiontype;
};

// fields accessors for composite com_activitytracking_operationactivity
mal_interactiontype_t com_activitytracking_operationactivity_get_interactiontype(com_activitytracking_operationactivity_t * self)
{
  return self->f_interactiontype;
}
void com_activitytracking_operationactivity_set_interactiontype(com_activitytracking_operationactivity_t * self, mal_interactiontype_t f_interactiontype)
{
  self->f_interactiontype = f_interactiontype;
}

// default constructor
com_activitytracking_operationactivity_t * com_activitytracking_operationactivity_new(void)
{
  com_activitytracking_operationactivity_t *self = (com_activitytracking_operationactivity_t *) calloc(1, sizeof(com_activitytracking_operationactivity_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_activitytracking_operationactivity_add_encoding_length_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_interactiontype, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_operationactivity_encode_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_interactiontype);
  if (rc < 0)
    return rc;
  return rc;
}
int com_activitytracking_operationactivity_decode_malbinary(com_activitytracking_operationactivity_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_interactiontype = (mal_interactiontype_t) enumerated_value;
  return rc;
}

// destructor
void com_activitytracking_operationactivity_destroy(com_activitytracking_operationactivity_t ** self_p)
{
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_activitytracking_operationactivity_test(bool verbose)
{
  printf(" * COM:ActivityTracking:OperationActivity: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
