#ifndef __COMMON_SERVICEKEY_LIST_H_INCLUDED__
#define __COMMON_SERVICEKEY_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
common_servicekey_list_t * common_servicekey_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void common_servicekey_list_destroy(common_servicekey_list_t ** self_p);

// fields accessors for composite list common_servicekey_list
unsigned int common_servicekey_list_get_element_count(common_servicekey_list_t * self);
common_servicekey_t ** common_servicekey_list_get_content(common_servicekey_list_t * self);

// encoding functions related to transport malbinary
int common_servicekey_list_add_encoding_length_malbinary(common_servicekey_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_servicekey_list_encode_malbinary(common_servicekey_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_servicekey_list_decode_malbinary(common_servicekey_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void common_servicekey_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_SERVICEKEY_LIST_H_INCLUDED__
