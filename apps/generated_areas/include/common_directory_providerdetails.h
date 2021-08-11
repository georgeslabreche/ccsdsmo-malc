#ifndef __COMMON_DIRECTORY_PROVIDERDETAILS_H_INCLUDED__
#define __COMMON_DIRECTORY_PROVIDERDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_providerdetails
common_directory_servicecapability_list_t * common_directory_providerdetails_get_servicecapabilities(common_directory_providerdetails_t * self);
void common_directory_providerdetails_set_servicecapabilities(common_directory_providerdetails_t * self, common_directory_servicecapability_list_t * f_servicecapabilities);
common_directory_addressdetails_list_t * common_directory_providerdetails_get_provideraddresses(common_directory_providerdetails_t * self);
void common_directory_providerdetails_set_provideraddresses(common_directory_providerdetails_t * self, common_directory_addressdetails_list_t * f_provideraddresses);

// default constructor
common_directory_providerdetails_t * common_directory_providerdetails_new(void);

// encoding functions related to transport malbinary
int common_directory_providerdetails_add_encoding_length_malbinary(common_directory_providerdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_providerdetails_encode_malbinary(common_directory_providerdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_providerdetails_decode_malbinary(common_directory_providerdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_providerdetails_destroy(common_directory_providerdetails_t ** self_p);

// test function
void common_directory_providerdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_PROVIDERDETAILS_H_INCLUDED__
