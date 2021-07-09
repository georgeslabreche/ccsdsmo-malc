#include "mc.h"


// structure definition for composite mc_conversion_lineconversiondetails
struct _mc_conversion_lineconversiondetails_t {
  mal_boolean_t f_extrapolate;
  mal_pair_list_t * f_points;
};

// fields accessors for composite mc_conversion_lineconversiondetails
mal_boolean_t mc_conversion_lineconversiondetails_get_extrapolate(mc_conversion_lineconversiondetails_t * self)
{
  return self->f_extrapolate;
}
void mc_conversion_lineconversiondetails_set_extrapolate(mc_conversion_lineconversiondetails_t * self, mal_boolean_t f_extrapolate)
{
  self->f_extrapolate = f_extrapolate;
}
mal_pair_list_t * mc_conversion_lineconversiondetails_get_points(mc_conversion_lineconversiondetails_t * self)
{
  return self->f_points;
}
void mc_conversion_lineconversiondetails_set_points(mc_conversion_lineconversiondetails_t * self, mal_pair_list_t * f_points)
{
  self->f_points = f_points;
}

// default constructor
mc_conversion_lineconversiondetails_t * mc_conversion_lineconversiondetails_new(void)
{
  mc_conversion_lineconversiondetails_t *self = (mc_conversion_lineconversiondetails_t *) calloc(1, sizeof(mc_conversion_lineconversiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_conversion_lineconversiondetails_add_encoding_length_malbinary(mc_conversion_lineconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_extrapolate, cursor);
  if (rc < 0)
    return rc;
  rc = mal_pair_list_add_encoding_length_malbinary(self->f_points, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_lineconversiondetails_encode_malbinary(mc_conversion_lineconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_extrapolate);
  if (rc < 0)
    return rc;
  rc = mal_pair_list_encode_malbinary(self->f_points, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_lineconversiondetails_decode_malbinary(mc_conversion_lineconversiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_extrapolate);
  if (rc < 0)
    return rc;
  self->f_points = mal_pair_list_new(0);
  if (self->f_points == NULL) return -1;
  rc = mal_pair_list_decode_malbinary(self->f_points, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_conversion_lineconversiondetails_destroy(mc_conversion_lineconversiondetails_t ** self_p)
{
  if ((*self_p)->f_points != NULL)
  {
    mal_pair_list_destroy(& (*self_p)->f_points);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_conversion_lineconversiondetails_test(bool verbose)
{
  printf(" * MC:Conversion:LineConversionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
