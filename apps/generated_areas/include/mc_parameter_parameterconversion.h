#ifndef __MC_PARAMETER_PARAMETERCONVERSION_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERCONVERSION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parameterconversion
mal_octet_t mc_parameter_parameterconversion_get_convertedtype(mc_parameter_parameterconversion_t * self);
void mc_parameter_parameterconversion_set_convertedtype(mc_parameter_parameterconversion_t * self, mal_octet_t f_convertedtype);
mal_string_t * mc_parameter_parameterconversion_get_convertedunit(mc_parameter_parameterconversion_t * self);
void mc_parameter_parameterconversion_set_convertedunit(mc_parameter_parameterconversion_t * self, mal_string_t * f_convertedunit);
mc_conditionalconversion_list_t * mc_parameter_parameterconversion_get_conditionalconversions(mc_parameter_parameterconversion_t * self);
void mc_parameter_parameterconversion_set_conditionalconversions(mc_parameter_parameterconversion_t * self, mc_conditionalconversion_list_t * f_conditionalconversions);

// default constructor
mc_parameter_parameterconversion_t * mc_parameter_parameterconversion_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parameterconversion_add_encoding_length_malbinary(mc_parameter_parameterconversion_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterconversion_encode_malbinary(mc_parameter_parameterconversion_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterconversion_decode_malbinary(mc_parameter_parameterconversion_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parameterconversion_destroy(mc_parameter_parameterconversion_t ** self_p);

// test function
void mc_parameter_parameterconversion_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERCONVERSION_H_INCLUDED__
