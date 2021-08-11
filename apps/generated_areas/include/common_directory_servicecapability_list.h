#ifndef __COMMON_DIRECTORY_SERVICECAPABILITY_LIST_H_INCLUDED__
#define __COMMON_DIRECTORY_SERVICECAPABILITY_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
common_directory_servicecapability_list_t * common_directory_servicecapability_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void common_directory_servicecapability_list_destroy(common_directory_servicecapability_list_t ** self_p);

// fields accessors for composite list common_directory_servicecapability_list
unsigned int common_directory_servicecapability_list_get_element_count(common_directory_servicecapability_list_t * self);
common_directory_servicecapability_t ** common_directory_servicecapability_list_get_content(common_directory_servicecapability_list_t * self);

// encoding functions related to transport malbinary
int common_directory_servicecapability_list_add_encoding_length_malbinary(common_directory_servicecapability_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicecapability_list_encode_malbinary(common_directory_servicecapability_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicecapability_list_decode_malbinary(common_directory_servicecapability_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void common_directory_servicecapability_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_SERVICECAPABILITY_LIST_H_INCLUDED__
