#ifndef __MAL_NAMEDVALUE_LIST_H_INCLUDED__
#define __MAL_NAMEDVALUE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_namedvalue_list_t * mal_namedvalue_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mal_namedvalue_list_destroy(mal_namedvalue_list_t ** self_p);

// fields accessors for composite list mal_namedvalue_list
unsigned int mal_namedvalue_list_get_element_count(mal_namedvalue_list_t * self);
mal_namedvalue_t ** mal_namedvalue_list_get_content(mal_namedvalue_list_t * self);

// encoding functions related to transport malbinary
int mal_namedvalue_list_add_encoding_length_malbinary(mal_namedvalue_list_t * self, mal_encoder_t * encoder, void * cursor);
int mal_namedvalue_list_encode_malbinary(mal_namedvalue_list_t * self, mal_encoder_t * encoder, void * cursor);
int mal_namedvalue_list_decode_malbinary(mal_namedvalue_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void mal_namedvalue_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_NAMEDVALUE_LIST_H_INCLUDED__
