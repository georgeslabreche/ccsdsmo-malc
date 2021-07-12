#include "mc.h"


// structure definition for composite mc_attributevalue
struct _mc_attributevalue_t {
  unsigned char f_value_attribute_tag;
  union mal_attribute_t f_value;
};

// fields accessors for composite mc_attributevalue
unsigned char mc_attributevalue_value_get_attribute_tag(mc_attributevalue_t * self)
{
  return self->f_value_attribute_tag;
}
void mc_attributevalue_value_set_attribute_tag(mc_attributevalue_t * self, unsigned char attribute_tag)
{
  self->f_value_attribute_tag = attribute_tag;
}

// default constructor
mc_attributevalue_t * mc_attributevalue_new(void)
{
  mc_attributevalue_t *self = (mc_attributevalue_t *) calloc(1, sizeof(mc_attributevalue_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int mc_attributevalue_add_encoding_length_malbinary(mc_attributevalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->f_value_attribute_tag, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_encoding_length(encoder, self->f_value_attribute_tag, self->f_value, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_attributevalue_encode_malbinary(mc_attributevalue_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->f_value_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute(encoder, cursor, self->f_value_attribute_tag, self->f_value);
  if (rc < 0)
    return rc;
  return rc;
}
int mc_attributevalue_decode_malbinary(mc_attributevalue_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->f_value_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute(decoder, cursor, self->f_value_attribute_tag, &self->f_value);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void mc_attributevalue_destroy(mc_attributevalue_t ** self_p)
{
  mal_attribute_destroy(&(*self_p)->f_value, (*self_p)->f_value_attribute_tag);
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void mc_attributevalue_test(bool verbose)
{
  printf(" * MC:AttributeValue: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
