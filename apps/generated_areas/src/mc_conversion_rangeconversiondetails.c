#include "mc.h"


// structure definition for composite mc_conversion_rangeconversiondetails
struct _mc_conversion_rangeconversiondetails_t {
  mal_pair_list_t * f_points;
};

// fields accessors for composite mc_conversion_rangeconversiondetails
mal_pair_list_t * mc_conversion_rangeconversiondetails_get_points(mc_conversion_rangeconversiondetails_t * self)
{
  return self->f_points;
}
void mc_conversion_rangeconversiondetails_set_points(mc_conversion_rangeconversiondetails_t * self, mal_pair_list_t * f_points)
{
  self->f_points = f_points;
}

// default constructor
mc_conversion_rangeconversiondetails_t * mc_conversion_rangeconversiondetails_new(void)
{
  mc_conversion_rangeconversiondetails_t *self = (mc_conversion_rangeconversiondetails_t *) calloc(1, sizeof(mc_conversion_rangeconversiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_conversion_rangeconversiondetails_add_encoding_length_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_pair_list_add_encoding_length_malbinary(self->f_points, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_rangeconversiondetails_encode_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_pair_list_encode_malbinary(self->f_points, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_rangeconversiondetails_decode_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_points = mal_pair_list_new(0);
  if (self->f_points == NULL) return -1;
  rc = mal_pair_list_decode_malbinary(self->f_points, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_conversion_rangeconversiondetails_destroy(mc_conversion_rangeconversiondetails_t ** self_p)
{
  if ((*self_p)->f_points != NULL)
  {
    mal_pair_list_destroy(& (*self_p)->f_points);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_conversion_rangeconversiondetails_test(bool verbose)
{
  printf(" * MC:Conversion:RangeConversionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
