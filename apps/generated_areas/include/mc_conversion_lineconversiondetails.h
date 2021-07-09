#ifndef __MC_CONVERSION_LINECONVERSIONDETAILS_H_INCLUDED__
#define __MC_CONVERSION_LINECONVERSIONDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_conversion_lineconversiondetails
mal_boolean_t mc_conversion_lineconversiondetails_get_extrapolate(mc_conversion_lineconversiondetails_t * self);
void mc_conversion_lineconversiondetails_set_extrapolate(mc_conversion_lineconversiondetails_t * self, mal_boolean_t f_extrapolate);
mal_pair_list_t * mc_conversion_lineconversiondetails_get_points(mc_conversion_lineconversiondetails_t * self);
void mc_conversion_lineconversiondetails_set_points(mc_conversion_lineconversiondetails_t * self, mal_pair_list_t * f_points);

// default constructor
mc_conversion_lineconversiondetails_t * mc_conversion_lineconversiondetails_new(void);

// encoding functions related to transport malbinary
int mc_conversion_lineconversiondetails_add_encoding_length_malbinary(mc_conversion_lineconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_lineconversiondetails_encode_malbinary(mc_conversion_lineconversiondetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conversion_lineconversiondetails_decode_malbinary(mc_conversion_lineconversiondetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_conversion_lineconversiondetails_destroy(mc_conversion_lineconversiondetails_t ** self_p);

// test function
void mc_conversion_lineconversiondetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CONVERSION_LINECONVERSIONDETAILS_H_INCLUDED__
