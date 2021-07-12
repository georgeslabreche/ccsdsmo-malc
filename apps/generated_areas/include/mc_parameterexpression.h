#ifndef __MC_PARAMETEREXPRESSION_H_INCLUDED__
#define __MC_PARAMETEREXPRESSION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_parameterexpression
com_objectkey_t * mc_parameterexpression_get_parameterid(mc_parameterexpression_t * self);
void mc_parameterexpression_set_parameterid(mc_parameterexpression_t * self, com_objectkey_t * f_parameterid);
com_archive_expressionoperator_t mc_parameterexpression_get_operator(mc_parameterexpression_t * self);
void mc_parameterexpression_set_operator(mc_parameterexpression_t * self, com_archive_expressionoperator_t f_operator);
mal_boolean_t mc_parameterexpression_get_useconverted(mc_parameterexpression_t * self);
void mc_parameterexpression_set_useconverted(mc_parameterexpression_t * self, mal_boolean_t f_useconverted);
bool mc_parameterexpression_value_is_present(mc_parameterexpression_t * self);
void mc_parameterexpression_value_set_present(mc_parameterexpression_t * self, bool is_present);
unsigned char mc_parameterexpression_value_get_attribute_tag(mc_parameterexpression_t * self);
void mc_parameterexpression_value_set_attribute_tag(mc_parameterexpression_t * self, unsigned char attribute_tag);

// default constructor
mc_parameterexpression_t * mc_parameterexpression_new(void);

// encoding functions related to transport malbinary
int mc_parameterexpression_add_encoding_length_malbinary(mc_parameterexpression_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameterexpression_encode_malbinary(mc_parameterexpression_t * self, mal_encoder_t * encoder, void * cursor);
int mc_parameterexpression_decode_malbinary(mc_parameterexpression_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_parameterexpression_destroy(mc_parameterexpression_t ** self_p);

// test function
void mc_parameterexpression_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_PARAMETEREXPRESSION_H_INCLUDED__
