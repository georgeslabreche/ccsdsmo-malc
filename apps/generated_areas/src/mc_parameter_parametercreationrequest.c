#include "mc.h"


// structure definition for composite mc_parameter_parametercreationrequest
struct _mc_parameter_parametercreationrequest_t {
  mal_identifier_t * f_name;
  mc_parameter_parameterdefinitiondetails_t * f_paramdefdetails;
};

// fields accessors for composite mc_parameter_parametercreationrequest
mal_identifier_t * mc_parameter_parametercreationrequest_get_name(mc_parameter_parametercreationrequest_t * self)
{
  return self->f_name;
}
void mc_parameter_parametercreationrequest_set_name(mc_parameter_parametercreationrequest_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mc_parameter_parameterdefinitiondetails_t * mc_parameter_parametercreationrequest_get_paramdefdetails(mc_parameter_parametercreationrequest_t * self)
{
  return self->f_paramdefdetails;
}
void mc_parameter_parametercreationrequest_set_paramdefdetails(mc_parameter_parametercreationrequest_t * self, mc_parameter_parameterdefinitiondetails_t * f_paramdefdetails)
{
  self->f_paramdefdetails = f_paramdefdetails;
}

// default constructor
mc_parameter_parametercreationrequest_t * mc_parameter_parametercreationrequest_new(void)
{
  mc_parameter_parametercreationrequest_t *self = (mc_parameter_parametercreationrequest_t *) calloc(1, sizeof(mc_parameter_parametercreationrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_parameter_parametercreationrequest_add_encoding_length_malbinary(mc_parameter_parametercreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mc_parameter_parameterdefinitiondetails_add_encoding_length_malbinary(self->f_paramdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parametercreationrequest_encode_malbinary(mc_parameter_parametercreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mc_parameter_parameterdefinitiondetails_encode_malbinary(self->f_paramdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_parameter_parametercreationrequest_decode_malbinary(mc_parameter_parametercreationrequest_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  self->f_paramdefdetails = mc_parameter_parameterdefinitiondetails_new();
  if (self->f_paramdefdetails == NULL) return -1;
  rc = mc_parameter_parameterdefinitiondetails_decode_malbinary(self->f_paramdefdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_parameter_parametercreationrequest_destroy(mc_parameter_parametercreationrequest_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_paramdefdetails != NULL)
  {
    mc_parameter_parameterdefinitiondetails_destroy(& (*self_p)->f_paramdefdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_parameter_parametercreationrequest_test(bool verbose)
{
  printf(" * MC:Parameter:ParameterCreationRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
