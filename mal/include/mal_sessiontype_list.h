#ifndef __MAL_SESSIONTYPE_LIST_H_INCLUDED__
#define __MAL_SESSIONTYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_sessiontype_list_t * mal_sessiontype_list_new(unsigned int element_count);

// destructor, free the list and its content
void mal_sessiontype_list_destroy(mal_sessiontype_list_t ** self_p);

// fields accessors for enumeration list mal_sessiontype_list
unsigned int mal_sessiontype_list_get_element_count(mal_sessiontype_list_t * self);
bool * mal_sessiontype_list_get_presence_flags(mal_sessiontype_list_t * self);
mal_sessiontype_t * mal_sessiontype_list_get_content(mal_sessiontype_list_t * self);

// encoding functions related to transport malbinary
int mal_sessiontype_list_add_encoding_length_malbinary(mal_sessiontype_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_sessiontype_list_encode_malbinary(mal_sessiontype_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_sessiontype_list_decode_malbinary(mal_sessiontype_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// test function
void mal_sessiontype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_SESSIONTYPE_LIST_H_INCLUDED__
