#ifndef __COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_H_INCLUDED__
#define __COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_configuration_configurationobjectset
com_objecttype_t * common_configuration_configurationobjectset_get_objtype(common_configuration_configurationobjectset_t * self);
void common_configuration_configurationobjectset_set_objtype(common_configuration_configurationobjectset_t * self, com_objecttype_t * f_objtype);
mal_identifier_list_t * common_configuration_configurationobjectset_get_domain(common_configuration_configurationobjectset_t * self);
void common_configuration_configurationobjectset_set_domain(common_configuration_configurationobjectset_t * self, mal_identifier_list_t * f_domain);
mal_long_list_t * common_configuration_configurationobjectset_get_objinstids(common_configuration_configurationobjectset_t * self);
void common_configuration_configurationobjectset_set_objinstids(common_configuration_configurationobjectset_t * self, mal_long_list_t * f_objinstids);

// default constructor
common_configuration_configurationobjectset_t * common_configuration_configurationobjectset_new(void);

// encoding functions related to transport malbinary
int common_configuration_configurationobjectset_add_encoding_length_malbinary(common_configuration_configurationobjectset_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectset_encode_malbinary(common_configuration_configurationobjectset_t * self, mal_encoder_t * encoder, void * cursor);
int common_configuration_configurationobjectset_decode_malbinary(common_configuration_configurationobjectset_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_configuration_configurationobjectset_destroy(common_configuration_configurationobjectset_t ** self_p);

// test function
void common_configuration_configurationobjectset_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_H_INCLUDED__
