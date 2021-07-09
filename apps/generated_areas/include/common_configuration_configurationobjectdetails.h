#ifndef __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_H_INCLUDED__
#define __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_configuration_configurationobjectdetails
common_configuration_configurationobjectset_list_t * common_configuration_configurationobjectdetails_get_configobjects(common_configuration_configurationobjectdetails_t * self);
void common_configuration_configurationobjectdetails_set_configobjects(common_configuration_configurationobjectdetails_t * self, common_configuration_configurationobjectset_list_t * f_configobjects);

// default constructor
common_configuration_configurationobjectdetails_t * common_configuration_configurationobjectdetails_new(void);

// encoding functions related to transport malbinary
int common_configuration_configurationobjectdetails_add_encoding_length_malbinary(common_configuration_configurationobjectdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectdetails_encode_malbinary(common_configuration_configurationobjectdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectdetails_decode_malbinary(common_configuration_configurationobjectdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_configuration_configurationobjectdetails_destroy(common_configuration_configurationobjectdetails_t ** self_p);

// test function
void common_configuration_configurationobjectdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_H_INCLUDED__
