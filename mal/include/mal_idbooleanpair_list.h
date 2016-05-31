#ifndef __MAL_IDBOOLEANPAIR_LIST_H_INCLUDED__
#define __MAL_IDBOOLEANPAIR_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_idbooleanpair_list_t * mal_idbooleanpair_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mal_idbooleanpair_list_destroy(mal_idbooleanpair_list_t ** self_p);

// fields accessors for composite list mal_idbooleanpair_list
unsigned int mal_idbooleanpair_list_get_element_count(mal_idbooleanpair_list_t * self);
mal_idbooleanpair_t ** mal_idbooleanpair_list_get_content(mal_idbooleanpair_list_t * self);

// encoding functions related to transport malbinary
int mal_idbooleanpair_list_add_encoding_length_malbinary(mal_idbooleanpair_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_idbooleanpair_list_encode_malbinary(mal_idbooleanpair_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_idbooleanpair_list_decode_malbinary(mal_idbooleanpair_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// test function
void mal_idbooleanpair_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_IDBOOLEANPAIR_LIST_H_INCLUDED__
