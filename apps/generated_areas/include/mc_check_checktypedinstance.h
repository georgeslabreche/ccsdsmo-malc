#ifndef __MC_CHECK_CHECKTYPEDINSTANCE_H_INCLUDED__
#define __MC_CHECK_CHECKTYPEDINSTANCE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_check_checktypedinstance
com_objecttype_t * mc_check_checktypedinstance_get_objdefchecktype(mc_check_checktypedinstance_t * self);
void mc_check_checktypedinstance_set_objdefchecktype(mc_check_checktypedinstance_t * self, com_objecttype_t * f_objdefchecktype);
mc_objectinstancepair_t * mc_check_checktypedinstance_get_objinstids(mc_check_checktypedinstance_t * self);
void mc_check_checktypedinstance_set_objinstids(mc_check_checktypedinstance_t * self, mc_objectinstancepair_t * f_objinstids);

// default constructor
mc_check_checktypedinstance_t * mc_check_checktypedinstance_new(void);

// encoding functions related to transport malbinary
int mc_check_checktypedinstance_add_encoding_length_malbinary(mc_check_checktypedinstance_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checktypedinstance_encode_malbinary(mc_check_checktypedinstance_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_checktypedinstance_decode_malbinary(mc_check_checktypedinstance_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_check_checktypedinstance_destroy(mc_check_checktypedinstance_t ** self_p);

// test function
void mc_check_checktypedinstance_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_CHECKTYPEDINSTANCE_H_INCLUDED__
