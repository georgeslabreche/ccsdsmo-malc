#include "mc.h"


// structure definition for composite mc_aggregation_thresholdfilter
struct _mc_aggregation_thresholdfilter_t {
  mc_aggregation_thresholdtype_t f_thresholdtype;
  unsigned char f_thresholdvalue_attribute_tag;
  union mal_attribute_t f_thresholdvalue;
  mal_boolean_t f_useconverted;
};

// fields accessors for composite mc_aggregation_thresholdfilter
mc_aggregation_thresholdtype_t mc_aggregation_thresholdfilter_get_thresholdtype(mc_aggregation_thresholdfilter_t * self)
{
  return self->f_thresholdtype;
}
void mc_aggregation_thresholdfilter_set_thresholdtype(mc_aggregation_thresholdfilter_t * self, mc_aggregation_thresholdtype_t f_thresholdtype)
{
  self->f_thresholdtype = f_thresholdtype;
}
unsigned char mc_aggregation_thresholdfilter_thresholdvalue_get_attribute_tag(mc_aggregation_thresholdfilter_t * self)
{
  return self->f_thresholdvalue_attribute_tag;
}
void mc_aggregation_thresholdfilter_thresholdvalue_set_attribute_tag(mc_aggregation_thresholdfilter_t * self, unsigned char attribute_tag)
{
  self->f_thresholdvalue_attribute_tag = attribute_tag;
}
union mal_attribute_t mc_aggregation_thresholdfilter_get_thresholdvalue(mc_aggregation_thresholdfilter_t * self)
{
  return self->f_thresholdvalue;
}
void mc_aggregation_thresholdfilter_set_thresholdvalue(mc_aggregation_thresholdfilter_t * self, union mal_attribute_t f_thresholdvalue)
{
  self->f_thresholdvalue = f_thresholdvalue;
}
mal_boolean_t mc_aggregation_thresholdfilter_get_useconverted(mc_aggregation_thresholdfilter_t * self)
{
  return self->f_useconverted;
}
void mc_aggregation_thresholdfilter_set_useconverted(mc_aggregation_thresholdfilter_t * self, mal_boolean_t f_useconverted)
{
  self->f_useconverted = f_useconverted;
}

// default constructor
mc_aggregation_thresholdfilter_t * mc_aggregation_thresholdfilter_new(void)
{
  mc_aggregation_thresholdfilter_t *self = (mc_aggregation_thresholdfilter_t *) calloc(1, sizeof(mc_aggregation_thresholdfilter_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_aggregation_thresholdfilter_add_encoding_length_malbinary(mc_aggregation_thresholdfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->f_thresholdtype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_thresholdvalue_attribute_tag, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_thresholdvalue_attribute_tag, self->f_thresholdvalue, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->f_useconverted, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_thresholdfilter_encode_malbinary(mc_aggregation_thresholdfilter_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->f_thresholdtype);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_thresholdvalue_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute(encoder, cursor, self->f_thresholdvalue_attribute_tag, self->f_thresholdvalue);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->f_useconverted);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_aggregation_thresholdfilter_decode_malbinary(mc_aggregation_thresholdfilter_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  int enumerated_value;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->f_thresholdtype = (mc_aggregation_thresholdtype_t) enumerated_value;
  rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_thresholdvalue_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute(decoder, cursor, self->f_thresholdvalue_attribute_tag, &self->f_thresholdvalue);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->f_useconverted);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_aggregation_thresholdfilter_destroy(mc_aggregation_thresholdfilter_t ** self_p)
{
  mal_attribute_destroy(&(*self_p)->f_thresholdvalue, (*self_p)->f_thresholdvalue_attribute_tag);
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_aggregation_thresholdfilter_test(bool verbose)
{
  printf(" * MC:Aggregation:ThresholdFilter: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
