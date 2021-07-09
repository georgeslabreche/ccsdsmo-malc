#ifndef __MC_CONDITIONALCONVERSION_H_INCLUDED__
#define __MC_CONDITIONALCONVERSION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_conditionalconversion
mc_parameterexpression_t * mc_conditionalconversion_get_condition(mc_conditionalconversion_t * self);
void mc_conditionalconversion_set_condition(mc_conditionalconversion_t * self, mc_parameterexpression_t * f_condition);
com_objectkey_t * mc_conditionalconversion_get_conversionid(mc_conditionalconversion_t * self);
void mc_conditionalconversion_set_conversionid(mc_conditionalconversion_t * self, com_objectkey_t * f_conversionid);

// default constructor
mc_conditionalconversion_t * mc_conditionalconversion_new(void);

// encoding functions related to transport malbinary
int mc_conditionalconversion_add_encoding_length_malbinary(mc_conditionalconversion_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conditionalconversion_encode_malbinary(mc_conditionalconversion_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conditionalconversion_decode_malbinary(mc_conditionalconversion_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_conditionalconversion_destroy(mc_conditionalconversion_t ** self_p);

// test function
void mc_conditionalconversion_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CONDITIONALCONVERSION_H_INCLUDED__
