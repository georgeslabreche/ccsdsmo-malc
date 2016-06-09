#ifndef __MAL_INTERACTIONTYPE_LIST_H_INCLUDED__
#define __MAL_INTERACTIONTYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_interactiontype_list_t * mal_interactiontype_list_new(unsigned int element_count);

// destructor, free the list and its content
void mal_interactiontype_list_destroy(mal_interactiontype_list_t ** self_p);

// fields accessors for enumeration list mal_interactiontype_list
unsigned int mal_interactiontype_list_get_element_count(mal_interactiontype_list_t * self);
bool * mal_interactiontype_list_get_presence_flags(mal_interactiontype_list_t * self);
mal_interactiontype_t * mal_interactiontype_list_get_content(mal_interactiontype_list_t * self);

// encoding functions related to transport malbinary
int mal_interactiontype_list_add_encoding_length_malbinary(mal_interactiontype_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_interactiontype_list_encode_malbinary(mal_interactiontype_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_interactiontype_list_decode_malbinary(mal_interactiontype_list_t * self, mal_decoder_t * mal_decoder, void * cursor);

// test function
void mal_interactiontype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_INTERACTIONTYPE_LIST_H_INCLUDED__
