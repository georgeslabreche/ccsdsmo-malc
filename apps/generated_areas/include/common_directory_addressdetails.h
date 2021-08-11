#ifndef __COMMON_DIRECTORY_ADDRESSDETAILS_H_INCLUDED__
#define __COMMON_DIRECTORY_ADDRESSDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_addressdetails
mal_qoslevel_list_t * common_directory_addressdetails_get_supportedlevels(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_supportedlevels(common_directory_addressdetails_t * self, mal_qoslevel_list_t * f_supportedlevels);
mal_namedvalue_list_t * common_directory_addressdetails_get_qosproperties(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_qosproperties(common_directory_addressdetails_t * self, mal_namedvalue_list_t * f_qosproperties);
mal_uinteger_t common_directory_addressdetails_get_prioritylevels(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_prioritylevels(common_directory_addressdetails_t * self, mal_uinteger_t f_prioritylevels);
mal_uri_t * common_directory_addressdetails_get_serviceuri(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_serviceuri(common_directory_addressdetails_t * self, mal_uri_t * f_serviceuri);
mal_uri_t * common_directory_addressdetails_get_brokeruri(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_brokeruri(common_directory_addressdetails_t * self, mal_uri_t * f_brokeruri);
bool common_directory_addressdetails_brokerproviderobjinstid_is_present(common_directory_addressdetails_t * self);
void common_directory_addressdetails_brokerproviderobjinstid_set_present(common_directory_addressdetails_t * self, bool is_present);
mal_long_t common_directory_addressdetails_get_brokerproviderobjinstid(common_directory_addressdetails_t * self);
void common_directory_addressdetails_set_brokerproviderobjinstid(common_directory_addressdetails_t * self, mal_long_t f_brokerproviderobjinstid);

// default constructor
common_directory_addressdetails_t * common_directory_addressdetails_new(void);

// encoding functions related to transport malbinary
int common_directory_addressdetails_add_encoding_length_malbinary(common_directory_addressdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_addressdetails_encode_malbinary(common_directory_addressdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_addressdetails_decode_malbinary(common_directory_addressdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_addressdetails_destroy(common_directory_addressdetails_t ** self_p);

// test function
void common_directory_addressdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_ADDRESSDETAILS_H_INCLUDED__
