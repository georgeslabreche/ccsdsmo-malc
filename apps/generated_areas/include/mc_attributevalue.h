#ifndef __MC_ATTRIBUTEVALUE_H_INCLUDED__
#define __MC_ATTRIBUTEVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_attributevalue
unsigned char mc_attributevalue_value_get_attribute_tag(mc_attributevalue_t * self);
void mc_attributevalue_value_set_attribute_tag(mc_attributevalue_t * self, unsigned char attribute_tag);

// default constructor
mc_attributevalue_t * mc_attributevalue_new(void);

// encoding functions related to transport malbinary
int mc_attributevalue_add_encoding_length_malbinary(mc_attributevalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_attributevalue_encode_malbinary(mc_attributevalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_attributevalue_decode_malbinary(mc_attributevalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_attributevalue_destroy(mc_attributevalue_t ** self_p);

// test function
void mc_attributevalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ATTRIBUTEVALUE_H_INCLUDED__
