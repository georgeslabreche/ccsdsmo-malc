#ifndef __MAL_ENTITYKEY_LIST_H_INCLUDED__
#define __MAL_ENTITYKEY_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_entitykey_list_t * mal_entitykey_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mal_entitykey_list_destroy(mal_entitykey_list_t ** self_p);

// fields accessors for composite list mal_entitykey_list
unsigned int mal_entitykey_list_get_element_count(mal_entitykey_list_t * self);
mal_entitykey_t ** mal_entitykey_list_get_content(mal_entitykey_list_t * self);

// encoding functions related to transport malbinary
int mal_entitykey_list_add_encoding_length_malbinary(mal_entitykey_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entitykey_list_encode_malbinary(mal_entitykey_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entitykey_list_decode_malbinary(mal_entitykey_list_t * self, mal_decoder_t * mal_decoder, void * cursor);

// test function
void mal_entitykey_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_ENTITYKEY_LIST_H_INCLUDED__
