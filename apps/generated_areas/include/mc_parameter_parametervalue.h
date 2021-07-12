#ifndef __MC_PARAMETER_PARAMETERVALUE_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parametervalue
mc_parameter_validity_t mc_parameter_parametervalue_get_validitystate(mc_parameter_parametervalue_t * self);
void mc_parameter_parametervalue_set_validitystate(mc_parameter_parametervalue_t * self, mc_parameter_validity_t f_validitystate);
bool mc_parameter_parametervalue_rawvalue_is_present(mc_parameter_parametervalue_t * self);
void mc_parameter_parametervalue_rawvalue_set_present(mc_parameter_parametervalue_t * self, bool is_present);
unsigned char mc_parameter_parametervalue_rawvalue_get_attribute_tag(mc_parameter_parametervalue_t * self);
void mc_parameter_parametervalue_rawvalue_set_attribute_tag(mc_parameter_parametervalue_t * self, unsigned char attribute_tag);
bool mc_parameter_parametervalue_convertedvalue_is_present(mc_parameter_parametervalue_t * self);
void mc_parameter_parametervalue_convertedvalue_set_present(mc_parameter_parametervalue_t * self, bool is_present);
unsigned char mc_parameter_parametervalue_convertedvalue_get_attribute_tag(mc_parameter_parametervalue_t * self);
void mc_parameter_parametervalue_convertedvalue_set_attribute_tag(mc_parameter_parametervalue_t * self, unsigned char attribute_tag);

// default constructor
mc_parameter_parametervalue_t * mc_parameter_parametervalue_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parametervalue_add_encoding_length_malbinary(mc_parameter_parametervalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametervalue_encode_malbinary(mc_parameter_parametervalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametervalue_decode_malbinary(mc_parameter_parametervalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parametervalue_destroy(mc_parameter_parametervalue_t ** self_p);

// test function
void mc_parameter_parametervalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERVALUE_H_INCLUDED__
