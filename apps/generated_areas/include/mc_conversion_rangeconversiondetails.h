#ifndef __MC_CONVERSION_RANGECONVERSIONDETAILS_H_INCLUDED__
#define __MC_CONVERSION_RANGECONVERSIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_conversion_rangeconversiondetails
mal_pair_list_t * mc_conversion_rangeconversiondetails_get_points(mc_conversion_rangeconversiondetails_t * self);
void mc_conversion_rangeconversiondetails_set_points(mc_conversion_rangeconversiondetails_t * self, mal_pair_list_t * f_points);

// default constructor
mc_conversion_rangeconversiondetails_t * mc_conversion_rangeconversiondetails_new(void);

// encoding functions related to transport malbinary
int mc_conversion_rangeconversiondetails_add_encoding_length_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_rangeconversiondetails_encode_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_rangeconversiondetails_decode_malbinary(mc_conversion_rangeconversiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_conversion_rangeconversiondetails_destroy(mc_conversion_rangeconversiondetails_t ** self_p);

// test function
void mc_conversion_rangeconversiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CONVERSION_RANGECONVERSIONDETAILS_H_INCLUDED__
