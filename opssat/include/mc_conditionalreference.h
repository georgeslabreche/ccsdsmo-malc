#ifndef __MC_CONDITIONALREFERENCE_H_INCLUDED__
#define __MC_CONDITIONALREFERENCE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_conditionalreference
mc_parameterexpression_t * mc_conditionalreference_get_condition(mc_conditionalreference_t * self);
void mc_conditionalreference_set_condition(mc_conditionalreference_t * self, mc_parameterexpression_t * f_condition);
com_objectid_t * mc_conditionalreference_get_referenceid(mc_conditionalreference_t * self);
void mc_conditionalreference_set_referenceid(mc_conditionalreference_t * self, com_objectid_t * f_referenceid);

// default constructor
mc_conditionalreference_t * mc_conditionalreference_new(void);

// encoding functions related to transport malbinary
int mc_conditionalreference_add_encoding_length_malbinary(mc_conditionalreference_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conditionalreference_encode_malbinary(mc_conditionalreference_t * self, mal_encoder_t * encoder, void * cursor);
int mc_conditionalreference_decode_malbinary(mc_conditionalreference_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_conditionalreference_destroy(mc_conditionalreference_t ** self_p);

// test function
void mc_conditionalreference_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CONDITIONALREFERENCE_H_INCLUDED__
