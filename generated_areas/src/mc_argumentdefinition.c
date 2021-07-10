#include "mc.h"


// structure definition for composite mc_argumentdefinition
struct _mc_argumentdefinition_t {
  mal_octet_t f_rawtype;
  mal_string_t * f_rawunit;
  mc_conditionalreference_list_t * f_conversioncondition;
  bool f_convertedtype_is_present;
  mal_octet_t f_convertedtype;
  mal_string_t * f_convertedunit;
};

// fields accessors for composite mc_argumentdefinition
mal_octet_t mc_argumentdefinition_get_rawtype(mc_argumentdefinition_t * self)
{
  return self->f_rawtype;
}
void mc_argumentdefinition_set_rawtype(mc_argumentdefinition_t * self, mal_octet_t f_rawtype)
{
  self->f_rawtype = f_rawtype;
}
mal_string_t * mc_argumentdefinition_get_rawunit(mc_argumentdefinition_t * self)
{
  return self->f_rawunit;
}
void mc_argumentdefinition_set_rawunit(mc_argumentdefinition_t * self, mal_string_t * f_rawunit)
{
  self->f_rawunit = f_rawunit;
}
mc_conditionalreference_list_t * mc_argumentdefinition_get_conversioncondition(mc_argumentdefinition_t * self)
{
  return self->f_conversioncondition;
}
void mc_argumentdefinition_set_conversioncondition(mc_argumentdefinition_t * self, mc_conditionalreference_list_t * f_conversioncondition)
{
  self->f_conversioncondition = f_conversioncondition;
}
bool mc_argumentdefinition_convertedtype_is_present(mc_argumentdefinition_t * self)
{
  return self->f_convertedtype_is_present;
}
void mc_argumentdefinition_convertedtype_set_present(mc_argumentdefinition_t * self, bool is_present)
{
  self->f_convertedtype_is_present = is_present;
}
mal_octet_t mc_argumentdefinition_get_convertedtype(mc_argumentdefinition_t * self)
{
  return self->f_convertedtype;
}
void mc_argumentdefinition_set_convertedtype(mc_argumentdefinition_t * self, mal_octet_t f_convertedtype)
{
  self->f_convertedtype = f_convertedtype;
}
mal_string_t * mc_argumentdefinition_get_convertedunit(mc_argumentdefinition_t * self)
{
  return self->f_convertedunit;
}
void mc_argumentdefinition_set_convertedunit(mc_argumentdefinition_t * self, mal_string_t * f_convertedunit)
{
  self->f_convertedunit = f_convertedunit;
}

// default constructor
mc_argumentdefinition_t * mc_argumentdefinition_new(void)
{
  mc_argumentdefinition_t *self = (mc_argumentdefinition_t *) calloc(1, sizeof(mc_argumentdefinition_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_argumentdefinition_add_encoding_length_malbinary(mc_argumentdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_octet_encoding_length(encoder, self->f_rawtype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_rawunit != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_rawunit != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_rawunit, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_conversioncondition != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_conversioncondition != NULL))
  {
    rc = mc_conditionalreference_list_add_encoding_length_malbinary(self->f_conversioncondition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_convertedtype_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_convertedtype_is_present)
  {
    rc = mal_encoder_add_octet_encoding_length(encoder, self->f_convertedtype, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_convertedunit != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_convertedunit != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_convertedunit, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_argumentdefinition_encode_malbinary(mc_argumentdefinition_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_octet(encoder, cursor, self->f_rawtype);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_rawunit != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_rawunit);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_conversioncondition != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_conditionalreference_list_encode_malbinary(self->f_conversioncondition, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_convertedtype_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_octet(encoder, cursor, self->f_convertedtype);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_convertedunit != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_convertedunit);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int mc_argumentdefinition_decode_malbinary(mc_argumentdefinition_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_octet(decoder, cursor, &self->f_rawtype);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_rawunit);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_rawunit = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_conversioncondition = mc_conditionalreference_list_new(0);
    if (self->f_conversioncondition == NULL) return -1;
    rc = mc_conditionalreference_list_decode_malbinary(self->f_conversioncondition, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_conversioncondition = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_octet(decoder, cursor, &self->f_convertedtype);
    if (rc < 0)
      return rc;
  }
  self->f_convertedtype_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_convertedunit);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_convertedunit = NULL;
  }
  return rc;
}

// destructor
void mc_argumentdefinition_destroy(mc_argumentdefinition_t ** self_p)
{
  if ((*self_p)->f_rawunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_rawunit);
  }
  if ((*self_p)->f_conversioncondition != NULL)
  {
    mc_conditionalreference_list_destroy(& (*self_p)->f_conversioncondition);
  }
  if ((*self_p)->f_convertedunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_convertedunit);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_argumentdefinition_test(bool verbose)
{
  printf(" * MC:ArgumentDefinition: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
