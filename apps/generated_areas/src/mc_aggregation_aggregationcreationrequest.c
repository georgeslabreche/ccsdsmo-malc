#include "mc.h"


// structure definition for composite mc_aggregation_aggregationcreationrequest
struct _mc_aggregation_aggregationcreationrequest_t {
  mal_identifier_t * f_name;
  mc_aggregation_aggregationdefinitiondetails_t * f_aggdefdetails;
};

// fields accessors for composite mc_aggregation_aggregationcreationrequest
mal_identifier_t * mc_aggregation_aggregationcreationrequest_get_name(mc_aggregation_aggregationcreationrequest_t * self)
{
  return self->f_name;
}
void mc_aggregation_aggregationcreationrequest_set_name(mc_aggregation_aggregationcreationrequest_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mc_aggregation_aggregationdefinitiondetails_t * mc_aggregation_aggregationcreationrequest_get_aggdefdetails(mc_aggregation_aggregationcreationrequest_t * self)
{
  return self->f_aggdefdetails;
}
void mc_aggregation_aggregationcreationrequest_set_aggdefdetails(mc_aggregation_aggregationcreationrequest_t * self, mc_aggregation_aggregationdefinitiondetails_t * f_aggdefdetails)
{
  self->f_aggdefdetails = f_aggdefdetails;
}

// default constructor
mc_aggregation_aggregationcreationrequest_t * mc_aggregation_aggregationcreationrequest_new(void)
{
  mc_aggregation_aggregationcreationrequest_t *self = (mc_aggregation_aggregationcreationrequest_t *) calloc(1, sizeof(mc_aggregation_aggregationcreationrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_aggregationcreationrequest_add_encoding_length_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationdefinitiondetails_add_encoding_length_malbinary(self->f_aggdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationcreationrequest_encode_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mc_aggregation_aggregationdefinitiondetails_encode_malbinary(self->f_aggdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_aggregationcreationrequest_decode_malbinary(mc_aggregation_aggregationcreationrequest_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  self->f_aggdefdetails = mc_aggregation_aggregationdefinitiondetails_new();
  if (self->f_aggdefdetails == NULL) return -1;
  rc = mc_aggregation_aggregationdefinitiondetails_decode_malbinary(self->f_aggdefdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_aggregationcreationrequest_destroy(mc_aggregation_aggregationcreationrequest_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_aggdefdetails != NULL)
  {
    mc_aggregation_aggregationdefinitiondetails_destroy(& (*self_p)->f_aggdefdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_aggregationcreationrequest_test(bool verbose)
{
  printf(" * MC:Aggregation:AggregationCreationRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
