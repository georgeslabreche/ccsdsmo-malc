#ifndef __MC_CHECK_REFERENCECHECK_LIST_H_INCLUDED__
#define __MC_CHECK_REFERENCECHECK_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mc_check_referencecheck_list_t * mc_check_referencecheck_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mc_check_referencecheck_list_destroy(mc_check_referencecheck_list_t ** self_p);

// fields accessors for composite list mc_check_referencecheck_list
unsigned int mc_check_referencecheck_list_get_element_count(mc_check_referencecheck_list_t * self);
mc_check_referencecheck_t ** mc_check_referencecheck_list_get_content(mc_check_referencecheck_list_t * self);

// encoding functions related to transport malbinary
int mc_check_referencecheck_list_add_encoding_length_malbinary(mc_check_referencecheck_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_referencecheck_list_encode_malbinary(mc_check_referencecheck_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_check_referencecheck_list_decode_malbinary(mc_check_referencecheck_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mc_check_referencecheck_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_CHECK_REFERENCECHECK_LIST_H_INCLUDED__
