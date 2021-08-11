#include "mc.h"


// structure definition for composite mc_argumentdefinitiondetails
struct _mc_argumentdefinitiondetails_t {
  mal_identifier_t * f_argid;
  mal_string_t * f_description;
  mal_octet_t f_rawtype;
  mal_string_t * f_rawunit;
  mc_conditionalconversion_list_t * f_conditionalconversions;
  bool f_convertedtype_is_present;
  mal_octet_t f_convertedtype;
  mal_string_t * f_convertedunit;
};

// fields accessors for composite mc_argumentdefinitiondetails
mal_identifier_t * mc_argumentdefinitiondetails_get_argid(mc_argumentdefinitiondetails_t * self)
{
  return self->f_argid;
}
void mc_argumentdefinitiondetails_set_argid(mc_argumentdefinitiondetails_t * self, mal_identifier_t * f_argid)
{
  self->f_argid = f_argid;
}
mal_string_t * mc_argumentdefinitiondetails_get_description(mc_argumentdefinitiondetails_t * self)
{
  return self->f_description;
}
void mc_argumentdefinitiondetails_set_description(mc_argumentdefinitiondetails_t * self, mal_string_t * f_description)
{
  self->f_description = f_description;
}
mal_octet_t mc_argumentdefinitiondetails_get_rawtype(mc_argumentdefinitiondetails_t * self)
{
  return self->f_rawtype;
}
void mc_argumentdefinitiondetails_set_rawtype(mc_argumentdefinitiondetails_t * self, mal_octet_t f_rawtype)
{
  self->f_rawtype = f_rawtype;
}
mal_string_t * mc_argumentdefinitiondetails_get_rawunit(mc_argumentdefinitiondetails_t * self)
{
  return self->f_rawunit;
}
void mc_argumentdefinitiondetails_set_rawunit(mc_argumentdefinitiondetails_t * self, mal_string_t * f_rawunit)
{
  self->f_rawunit = f_rawunit;
}
mc_conditionalconversion_list_t * mc_argumentdefinitiondetails_get_conditionalconversions(mc_argumentdefinitiondetails_t * self)
{
  return self->f_conditionalconversions;
}
void mc_argumentdefinitiondetails_set_conditionalconversions(mc_argumentdefinitiondetails_t * self, mc_conditionalconversion_list_t * f_conditionalconversions)
{
  self->f_conditionalconversions = f_conditionalconversions;
}
bool mc_argumentdefinitiondetails_convertedtype_is_present(mc_argumentdefinitiondetails_t * self)
{
  return self->f_convertedtype_is_present;
}
void mc_argumentdefinitiondetails_convertedtype_set_present(mc_argumentdefinitiondetails_t * self, bool is_present)
{
  self->f_convertedtype_is_present = is_present;
}
mal_octet_t mc_argumentdefinitiondetails_get_convertedtype(mc_argumentdefinitiondetails_t * self)
{
  return self->f_convertedtype;
}
void mc_argumentdefinitiondetails_set_convertedtype(mc_argumentdefinitiondetails_t * self, mal_octet_t f_convertedtype)
{
  self->f_convertedtype = f_convertedtype;
}
mal_string_t * mc_argumentdefinitiondetails_get_convertedunit(mc_argumentdefinitiondetails_t * self)
{
  return self->f_convertedunit;
}
void mc_argumentdefinitiondetails_set_convertedunit(mc_argumentdefinitiondetails_t * self, mal_string_t * f_convertedunit)
{
  self->f_convertedunit = f_convertedunit;
}

// default constructor
mc_argumentdefinitiondetails_t * mc_argumentdefinitiondetails_new(void)
{
  mc_argumentdefinitiondetails_t *self = (mc_argumentdefinitiondetails_t *) calloc(1, sizeof(mc_argumentdefinitiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_argumentdefinitiondetails_add_encoding_length_malbinary(mc_argumentdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_identifier_encoding_length(encoder, self->f_argid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_description != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_description != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->f_description, cursor);
    if (rc < 0)
      return rc;
  }
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
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_conditionalconversions != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_conditionalconversions != NULL))
  {
    rc = mc_conditionalconversion_list_add_encoding_length_malbinary(self->f_conditionalconversions, encoder, cursor);
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
int mc_argumentdefinitiondetails_encode_malbinary(mc_argumentdefinitiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_identifier(encoder, cursor, self->f_argid);
  if (rc < 0)
    return rc;
  presence_flag = (self->f_description != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->f_description);
    if (rc < 0)
      return rc;
  }
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
  presence_flag = (self->f_conditionalconversions != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mc_conditionalconversion_list_encode_malbinary(self->f_conditionalconversions, encoder, cursor);
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
int mc_argumentdefinitiondetails_decode_malbinary(mc_argumentdefinitiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_identifier(decoder, cursor, &self->f_argid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->f_description);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_description = NULL;
  }
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
    self->f_conditionalconversions = mc_conditionalconversion_list_new(0);
    if (self->f_conditionalconversions == NULL) return -1;
    rc = mc_conditionalconversion_list_decode_malbinary(self->f_conditionalconversions, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_conditionalconversions = NULL;
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
void mc_argumentdefinitiondetails_destroy(mc_argumentdefinitiondetails_t ** self_p)
{
  if ((*self_p)->f_argid != NULL)
  {
    mal_identifier_destroy(& (*self_p)->f_argid);
  }
  if ((*self_p)->f_description != NULL)
  {
    mal_string_destroy(& (*self_p)->f_description);
  }
  if ((*self_p)->f_rawunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_rawunit);
  }
  if ((*self_p)->f_conditionalconversions != NULL)
  {
    mc_conditionalconversion_list_destroy(& (*self_p)->f_conditionalconversions);
  }
  if ((*self_p)->f_convertedunit != NULL)
  {
    mal_string_destroy(& (*self_p)->f_convertedunit);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_argumentdefinitiondetails_test(bool verbose)
{
  printf(" * MC:ArgumentDefinitionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
