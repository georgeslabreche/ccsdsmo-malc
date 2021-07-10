#ifndef __MC_PARAMETER_PARAMETERDEFINITION_H_INCLUDED__
#define __MC_PARAMETER_PARAMETERDEFINITION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameter_parameterdefinition
mal_identifier_t * mc_parameter_parameterdefinition_get_name(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_name(mc_parameter_parameterdefinition_t * self, mal_identifier_t * f_name);
mal_string_t * mc_parameter_parameterdefinition_get_description(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_description(mc_parameter_parameterdefinition_t * self, mal_string_t * f_description);
mal_octet_t mc_parameter_parameterdefinition_get_rawtype(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_rawtype(mc_parameter_parameterdefinition_t * self, mal_octet_t f_rawtype);
mal_string_t * mc_parameter_parameterdefinition_get_rawunit(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_rawunit(mc_parameter_parameterdefinition_t * self, mal_string_t * f_rawunit);
mal_boolean_t mc_parameter_parameterdefinition_get_generationenabled(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_generationenabled(mc_parameter_parameterdefinition_t * self, mal_boolean_t f_generationenabled);
mal_duration_t mc_parameter_parameterdefinition_get_updateinterval(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_updateinterval(mc_parameter_parameterdefinition_t * self, mal_duration_t f_updateinterval);
mc_parameterexpression_t * mc_parameter_parameterdefinition_get_validityexpression(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_validityexpression(mc_parameter_parameterdefinition_t * self, mc_parameterexpression_t * f_validityexpression);
mc_parameter_parameterconversion_t * mc_parameter_parameterdefinition_get_conversion(mc_parameter_parameterdefinition_t * self);
void mc_parameter_parameterdefinition_set_conversion(mc_parameter_parameterdefinition_t * self, mc_parameter_parameterconversion_t * f_conversion);

// default constructor
mc_parameter_parameterdefinition_t * mc_parameter_parameterdefinition_new(void);

// encoding functions related to transport malbinary
int mc_parameter_parameterdefinition_add_encoding_length_malbinary(mc_parameter_parameterdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterdefinition_encode_malbinary(mc_parameter_parameterdefinition_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameter_parameterdefinition_decode_malbinary(mc_parameter_parameterdefinition_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameter_parameterdefinition_destroy(mc_parameter_parameterdefinition_t ** self_p);

// test function
void mc_parameter_parameterdefinition_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETER_PARAMETERDEFINITION_H_INCLUDED__
