#ifndef __MC_PARAMETER_PARAMETERCREATIONREQUEST_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERCREATIONREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parametercreationrequest
mal_identifier_t * mc_parameter_parametercreationrequest_get_name(mc_parameter_parametercreationrequest_t * self);
void mc_parameter_parametercreationrequest_set_name(mc_parameter_parametercreationrequest_t * self, mal_identifier_t * f_name);
mc_parameter_parameterdefinitiondetails_t * mc_parameter_parametercreationrequest_get_paramdefdetails(mc_parameter_parametercreationrequest_t * self);
void mc_parameter_parametercreationrequest_set_paramdefdetails(mc_parameter_parametercreationrequest_t * self, mc_parameter_parameterdefinitiondetails_t * f_paramdefdetails);

// default constructor
mc_parameter_parametercreationrequest_t * mc_parameter_parametercreationrequest_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parametercreationrequest_add_encoding_length_malbinary(mc_parameter_parametercreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametercreationrequest_encode_malbinary(mc_parameter_parametercreationrequest_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parametercreationrequest_decode_malbinary(mc_parameter_parametercreationrequest_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parametercreationrequest_destroy(mc_parameter_parametercreationrequest_t ** self_p);

// test function
void mc_parameter_parametercreationrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERCREATIONREQUEST_H_INCLUDED__
