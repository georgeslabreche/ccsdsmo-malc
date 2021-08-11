#ifndef __COMMON_DIRECTORY_SERVICECAPABILITY_H_INCLUDED__
#define __COMMON_DIRECTORY_SERVICECAPABILITY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_servicecapability
common_servicekey_t * common_directory_servicecapability_get_servicekey(common_directory_servicecapability_t * self);
void common_directory_servicecapability_set_servicekey(common_directory_servicecapability_t * self, common_servicekey_t * f_servicekey);
mal_ushort_list_t * common_directory_servicecapability_get_supportedcapabilitysets(common_directory_servicecapability_t * self);
void common_directory_servicecapability_set_supportedcapabilitysets(common_directory_servicecapability_t * self, mal_ushort_list_t * f_supportedcapabilitysets);
mal_namedvalue_list_t * common_directory_servicecapability_get_serviceproperties(common_directory_servicecapability_t * self);
void common_directory_servicecapability_set_serviceproperties(common_directory_servicecapability_t * self, mal_namedvalue_list_t * f_serviceproperties);
common_directory_addressdetails_list_t * common_directory_servicecapability_get_serviceaddresses(common_directory_servicecapability_t * self);
void common_directory_servicecapability_set_serviceaddresses(common_directory_servicecapability_t * self, common_directory_addressdetails_list_t * f_serviceaddresses);

// default constructor
common_directory_servicecapability_t * common_directory_servicecapability_new(void);

// encoding functions related to transport malbinary
int common_directory_servicecapability_add_encoding_length_malbinary(common_directory_servicecapability_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicecapability_encode_malbinary(common_directory_servicecapability_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicecapability_decode_malbinary(common_directory_servicecapability_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_servicecapability_destroy(common_directory_servicecapability_t ** self_p);

// test function
void common_directory_servicecapability_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_SERVICECAPABILITY_H_INCLUDED__
