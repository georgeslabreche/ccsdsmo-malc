#include "mc.h"


// structure definition for composite mc_alert_alertcreationrequest
struct _mc_alert_alertcreationrequest_t {
  mal_identifier_t * f_name;
  mc_alert_alertdefinitiondetails_t * f_alertdefdetails;
};

// fields accessors for composite mc_alert_alertcreationrequest
mal_identifier_t * mc_alert_alertcreationrequest_get_name(mc_alert_alertcreationrequest_t * self)
{
  return self->f_name;
}
void mc_alert_alertcreationrequest_set_name(mc_alert_alertcreationrequest_t * self, mal_identifier_t * f_name)
{
  self->f_name = f_name;
}
mc_alert_alertdefinitiondetails_t * mc_alert_alertcreationrequest_get_alertdefdetails(mc_alert_alertcreationrequest_t * self)
{
  return self->f_alertdefdetails;
}
void mc_alert_alertcreationrequest_set_alertdefdetails(mc_alert_alertcreationrequest_t * self, mc_alert_alertdefinitiondetails_t * f_alertdefdetails)
{
  self->f_alertdefdetails = f_alertdefdetails;
}

// default constructor
mc_alert_alertcreationrequest_t * mc_alert_alertcreationrequest_new(void)
{
  mc_alert_alertcreationrequest_t *self = (mc_alert_alertcreationrequest_t *) calloc(1, sizeof(mc_alert_alertcreationrequest_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_alert_alertcreationrequest_add_encoding_length_malbinary(mc_alert_alertcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_name, cursor);
  if (rc < 0)
    return rc;
  rc = mc_alert_alertdefinitiondetails_add_encoding_length_malbinary(self->f_alertdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_alert_alertcreationrequest_encode_malbinary(mc_alert_alertcreationrequest_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_name);
  if (rc < 0)
    return rc;
  rc = mc_alert_alertdefinitiondetails_encode_malbinary(self->f_alertdefdetails, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_alert_alertcreationrequest_decode_malbinary(mc_alert_alertcreationrequest_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_name);
  if (rc < 0)
    return rc;
  self->f_alertdefdetails = mc_alert_alertdefinitiondetails_new();
  if (self->f_alertdefdetails == NULL) return -1;
  rc = mc_alert_alertdefinitiondetails_decode_malbinary(self->f_alertdefdetails, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_alert_alertcreationrequest_destroy(mc_alert_alertcreationrequest_t ** self_p)
{
  if ((*self_p)->f_name != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_name);
  }
  if ((*self_p)->f_alertdefdetails != NULL)
  {
    mc_alert_alertdefinitiondetails_destroy(& (*self_p)->f_alertdefdetails);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_alert_alertcreationrequest_test(bool verbose)
{
  printf(" * MC:Alert:AlertCreationRequest: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
