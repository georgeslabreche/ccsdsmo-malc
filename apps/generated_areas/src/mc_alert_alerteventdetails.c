#include "mc.h"


// structure definition for composite mc_alert_alerteventdetails
struct _mc_alert_alerteventdetails_t {
  mc_attributevalue_list_t * f_argumentvalues;
  mal_identifier_list_t * f_argumentids;
};

// fields accessors for composite mc_alert_alerteventdetails
mc_attributevalue_list_t * mc_alert_alerteventdetails_get_argumentvalues(mc_alert_alerteventdetails_t * self)
{
  return self->f_argumentvalues;
}
void mc_alert_alerteventdetails_set_argumentvalues(mc_alert_alerteventdetails_t * self, mc_attributevalue_list_t * f_argumentvalues)
{
  self->f_argumentvalues = f_argumentvalues;
}
mal_identifier_list_t * mc_alert_alerteventdetails_get_argumentids(mc_alert_alerteventdetails_t * self)
{
  return self->f_argumentids;
}
void mc_alert_alerteventdetails_set_argumentids(mc_alert_alerteventdetails_t * self, mal_identifier_list_t * f_argumentids)
{
  self->f_argumentids = f_argumentids;
}

// default constructor
mc_alert_alerteventdetails_t * mc_alert_alerteventdetails_new(void)
{
  mc_alert_alerteventdetails_t *self = (mc_alert_alerteventdetails_t *) calloc(1, sizeof(mc_alert_alerteventdetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_alert_alerteventdetails_add_encoding_length_malbinary(mc_alert_alerteventdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
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
  return rc;
}
int mc_alert_alerteventdetails_encode_malbinary(mc_alert_alerteventdetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
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
  return rc;
}
int mc_alert_alerteventdetails_decode_malbinary(mc_alert_alerteventdetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
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
  return rc;
}

// destructor
void mc_alert_alerteventdetails_destroy(mc_alert_alerteventdetails_t ** self_p)
{
  if ((*self_p)->f_argumentvalues != NULL)
  {
    mc_attributevalue_list_destroy(& (*self_p)->f_argumentvalues);
  }
  if ((*self_p)->f_argumentids != NULL)
  {
    mal_identifier_list_destroy(& (*self_p)->f_argumentids);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_alert_alerteventdetails_test(bool verbose)
{
  printf(" * MC:Alert:AlertEventDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
