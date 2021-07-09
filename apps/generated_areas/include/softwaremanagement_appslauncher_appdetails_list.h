#ifndef __SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_H_INCLUDED__
#define __SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
softwaremanagement_appslauncher_appdetails_list_t * softwaremanagement_appslauncher_appdetails_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void softwaremanagement_appslauncher_appdetails_list_destroy(softwaremanagement_appslauncher_appdetails_list_t ** self_p);

// fields accessors for composite list softwaremanagement_appslauncher_appdetails_list
unsigned int softwaremanagement_appslauncher_appdetails_list_get_element_count(softwaremanagement_appslauncher_appdetails_list_t * self);
softwaremanagement_appslauncher_appdetails_t ** softwaremanagement_appslauncher_appdetails_list_get_content(softwaremanagement_appslauncher_appdetails_list_t * self);

// encoding functions related to transport malbinary
int softwaremanagement_appslauncher_appdetails_list_add_encoding_length_malbinary(softwaremanagement_appslauncher_appdetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int softwaremanagement_appslauncher_appdetails_list_encode_malbinary(softwaremanagement_appslauncher_appdetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int softwaremanagement_appslauncher_appdetails_list_decode_malbinary(softwaremanagement_appslauncher_appdetails_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void softwaremanagement_appslauncher_appdetails_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_H_INCLUDED__
