#ifndef __MC_CHECK_REFERENCEVALUE_H_INCLUDED__
#define __MC_CHECK_REFERENCEVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_referencevalue
mal_ushort_t mc_check_referencevalue_get_validcount(mc_check_referencevalue_t * self);
void mc_check_referencevalue_set_validcount(mc_check_referencevalue_t * self, mal_ushort_t f_validcount);
mal_duration_t mc_check_referencevalue_get_deltatime(mc_check_referencevalue_t * self);
void mc_check_referencevalue_set_deltatime(mc_check_referencevalue_t * self, mal_duration_t f_deltatime);
com_objectkey_t * mc_check_referencevalue_get_parameterid(mc_check_referencevalue_t * self);
void mc_check_referencevalue_set_parameterid(mc_check_referencevalue_t * self, com_objectkey_t * f_parameterid);

// default constructor
mc_check_referencevalue_t * mc_check_referencevalue_new(void);

// encoding functions related to transport malbinary
int mc_check_referencevalue_add_encoding_length_malbinary(mc_check_referencevalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_referencevalue_encode_malbinary(mc_check_referencevalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_referencevalue_decode_malbinary(mc_check_referencevalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_referencevalue_destroy(mc_check_referencevalue_t ** self_p);

// test function
void mc_check_referencevalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_REFERENCEVALUE_H_INCLUDED__
