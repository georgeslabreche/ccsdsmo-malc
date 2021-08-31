#ifndef __MC_PARAMETER_PARAMETERRAWVALUE_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERRAWVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parameterrawvalue
mal_long_t mc_parameter_parameterrawvalue_get_paraminstid(mc_parameter_parameterrawvalue_t * self);
void mc_parameter_parameterrawvalue_set_paraminstid(mc_parameter_parameterrawvalue_t * self, mal_long_t f_paraminstid);
bool mc_parameter_parameterrawvalue_rawvalue_is_present(mc_parameter_parameterrawvalue_t * self);
void mc_parameter_parameterrawvalue_rawvalue_set_present(mc_parameter_parameterrawvalue_t * self, bool is_present);
unsigned char mc_parameter_parameterrawvalue_rawvalue_get_attribute_tag(mc_parameter_parameterrawvalue_t * self);
void mc_parameter_parameterrawvalue_rawvalue_set_attribute_tag(mc_parameter_parameterrawvalue_t * self, unsigned char attribute_tag);
union mal_attribute_t mc_parameter_parameterrawvalue_get_rawvalue(mc_parameter_parameterrawvalue_t * self);
void mc_parameter_parameterrawvalue_set_rawvalue(mc_parameter_parameterrawvalue_t * self, union mal_attribute_t f_rawvalue);

// default constructor
mc_parameter_parameterrawvalue_t * mc_parameter_parameterrawvalue_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parameterrawvalue_add_encoding_length_malbinary(mc_parameter_parameterrawvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterrawvalue_encode_malbinary(mc_parameter_parameterrawvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterrawvalue_decode_malbinary(mc_parameter_parameterrawvalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parameterrawvalue_destroy(mc_parameter_parameterrawvalue_t ** self_p);

// test function
void mc_parameter_parameterrawvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERRAWVALUE_H_INCLUDED__
