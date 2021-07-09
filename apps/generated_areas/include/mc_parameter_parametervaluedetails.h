#ifndef __MC_PARAMETER_PARAMETERVALUEDETAILS_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERVALUEDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parametervaluedetails
mal_long_t mc_parameter_parametervaluedetails_get_paramid(mc_parameter_parametervaluedetails_t * self);
void mc_parameter_parametervaluedetails_set_paramid(mc_parameter_parametervaluedetails_t * self, mal_long_t f_paramid);
mal_long_t mc_parameter_parametervaluedetails_get_defid(mc_parameter_parametervaluedetails_t * self);
void mc_parameter_parametervaluedetails_set_defid(mc_parameter_parametervaluedetails_t * self, mal_long_t f_defid);
mal_time_t mc_parameter_parametervaluedetails_get_timestamp(mc_parameter_parametervaluedetails_t * self);
void mc_parameter_parametervaluedetails_set_timestamp(mc_parameter_parametervaluedetails_t * self, mal_time_t f_timestamp);
mc_parameter_parametervalue_t * mc_parameter_parametervaluedetails_get_value(mc_parameter_parametervaluedetails_t * self);
void mc_parameter_parametervaluedetails_set_value(mc_parameter_parametervaluedetails_t * self, mc_parameter_parametervalue_t * f_value);

// default constructor
mc_parameter_parametervaluedetails_t * mc_parameter_parametervaluedetails_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parametervaluedetails_add_encoding_length_malbinary(mc_parameter_parametervaluedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametervaluedetails_encode_malbinary(mc_parameter_parametervaluedetails_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametervaluedetails_decode_malbinary(mc_parameter_parametervaluedetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parametervaluedetails_destroy(mc_parameter_parametervaluedetails_t ** self_p);

// test function
void mc_parameter_parametervaluedetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERVALUEDETAILS_H_INCLUDED__
