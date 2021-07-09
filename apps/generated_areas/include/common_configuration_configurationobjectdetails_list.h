#ifndef __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_H_INCLUDED__
#define __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
common_configuration_configurationobjectdetails_list_t * common_configuration_configurationobjectdetails_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void common_configuration_configurationobjectdetails_list_destroy(common_configuration_configurationobjectdetails_list_t ** self_p);

// fields accessors for composite list common_configuration_configurationobjectdetails_list
unsigned int common_configuration_configurationobjectdetails_list_get_element_count(common_configuration_configurationobjectdetails_list_t * self);
common_configuration_configurationobjectdetails_t ** common_configuration_configurationobjectdetails_list_get_content(common_configuration_configurationobjectdetails_list_t * self);

// encoding functions related to transport malbinary
int common_configuration_configurationobjectdetails_list_add_encoding_length_malbinary(common_configuration_configurationobjectdetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectdetails_list_encode_malbinary(common_configuration_configurationobjectdetails_list_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectdetails_list_decode_malbinary(common_configuration_configurationobjectdetails_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void common_configuration_configurationobjectdetails_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_H_INCLUDED__
