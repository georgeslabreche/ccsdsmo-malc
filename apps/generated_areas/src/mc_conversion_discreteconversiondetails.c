#include "mc.h"


// structure definition for composite mc_conversion_discreteconversiondetails
struct _mc_conversion_discreteconversiondetails_t {
  mal_pair_list_t * f_mapping;
};

// fields accessors for composite mc_conversion_discreteconversiondetails
mal_pair_list_t * mc_conversion_discreteconversiondetails_get_mapping(mc_conversion_discreteconversiondetails_t * self)
{
  return self->f_mapping;
}
void mc_conversion_discreteconversiondetails_set_mapping(mc_conversion_discreteconversiondetails_t * self, mal_pair_list_t * f_mapping)
{
  self->f_mapping = f_mapping;
}

// default constructor
mc_conversion_discreteconversiondetails_t * mc_conversion_discreteconversiondetails_new(void)
{
  mc_conversion_discreteconversiondetails_t *self = (mc_conversion_discreteconversiondetails_t *) calloc(1, sizeof(mc_conversion_discreteconversiondetails_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_conversion_discreteconversiondetails_add_encoding_length_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_pair_list_add_encoding_length_malbinary(self->f_mapping, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_discreteconversiondetails_encode_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_pair_list_encode_malbinary(self->f_mapping, encoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_conversion_discreteconversiondetails_decode_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  self->f_mapping = mal_pair_list_new(0);
  if (self->f_mapping == NULL) return -1;
  rc = mal_pair_list_decode_malbinary(self->f_mapping, decoder, cursor);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_conversion_discreteconversiondetails_destroy(mc_conversion_discreteconversiondetails_t ** self_p)
{
  if ((*self_p)->f_mapping != NULL)
  {
    mal_pair_list_destroy(& (*self_p)->f_mapping);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_conversion_discreteconversiondetails_test(bool verbose)
{
  printf(" * MC:Conversion:DiscreteConversionDetails: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
