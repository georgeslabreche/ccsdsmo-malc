#ifndef __MAL_FILE_LIST_H_INCLUDED__
#define __MAL_FILE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_file_list_t * mal_file_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mal_file_list_destroy(mal_file_list_t ** self_p);

// fields accessors for composite list mal_file_list
unsigned int mal_file_list_get_element_count(mal_file_list_t * self);
mal_file_t ** mal_file_list_get_content(mal_file_list_t * self);

// encoding functions related to transport malbinary
int mal_file_list_add_encoding_length_malbinary(mal_file_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_file_list_encode_malbinary(mal_file_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int mal_file_list_decode_malbinary(mal_file_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// test function
void mal_file_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_FILE_LIST_H_INCLUDED__
