#ifndef __MC_ARGUMENTDEFINITION_LIST_H_INCLUDED__
#define __MC_ARGUMENTDEFINITION_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mc_argumentdefinition_list_t * mc_argumentdefinition_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mc_argumentdefinition_list_destroy(mc_argumentdefinition_list_t ** self_p);

// fields accessors for composite list mc_argumentdefinition_list
unsigned int mc_argumentdefinition_list_get_element_count(mc_argumentdefinition_list_t * self);
mc_argumentdefinition_t ** mc_argumentdefinition_list_get_content(mc_argumentdefinition_list_t * self);

// encoding functions related to transport malbinary
int mc_argumentdefinition_list_add_encoding_length_malbinary(mc_argumentdefinition_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinition_list_encode_malbinary(mc_argumentdefinition_list_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentdefinition_list_decode_malbinary(mc_argumentdefinition_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mc_argumentdefinition_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ARGUMENTDEFINITION_LIST_H_INCLUDED__
