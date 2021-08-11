#ifndef __MC_CONVERSION_DISCRETECONVERSIONDETAILS_H_INCLUDED__
#define __MC_CONVERSION_DISCRETECONVERSIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_conversion_discreteconversiondetails
mal_pair_list_t * mc_conversion_discreteconversiondetails_get_mapping(mc_conversion_discreteconversiondetails_t * self);
void mc_conversion_discreteconversiondetails_set_mapping(mc_conversion_discreteconversiondetails_t * self, mal_pair_list_t * f_mapping);

// default constructor
mc_conversion_discreteconversiondetails_t * mc_conversion_discreteconversiondetails_new(void);

// encoding functions related to transport malbinary
int mc_conversion_discreteconversiondetails_add_encoding_length_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_discreteconversiondetails_encode_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_discreteconversiondetails_decode_malbinary(mc_conversion_discreteconversiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_conversion_discreteconversiondetails_destroy(mc_conversion_discreteconversiondetails_t ** self_p);

// test function
void mc_conversion_discreteconversiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CONVERSION_DISCRETECONVERSIONDETAILS_H_INCLUDED__
