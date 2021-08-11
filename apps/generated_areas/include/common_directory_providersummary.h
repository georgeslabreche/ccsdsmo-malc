#ifndef __COMMON_DIRECTORY_PROVIDERSUMMARY_H_INCLUDED__
#define __COMMON_DIRECTORY_PROVIDERSUMMARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_providersummary
com_objectkey_t * common_directory_providersummary_get_providerkey(common_directory_providersummary_t * self);
void common_directory_providersummary_set_providerkey(common_directory_providersummary_t * self, com_objectkey_t * f_providerkey);
mal_identifier_t * common_directory_providersummary_get_providerid(common_directory_providersummary_t * self);
void common_directory_providersummary_set_providerid(common_directory_providersummary_t * self, mal_identifier_t * f_providerid);
common_directory_providerdetails_t * common_directory_providersummary_get_providerdetails(common_directory_providersummary_t * self);
void common_directory_providersummary_set_providerdetails(common_directory_providersummary_t * self, common_directory_providerdetails_t * f_providerdetails);

// default constructor
common_directory_providersummary_t * common_directory_providersummary_new(void);

// encoding functions related to transport malbinary
int common_directory_providersummary_add_encoding_length_malbinary(common_directory_providersummary_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_providersummary_encode_malbinary(common_directory_providersummary_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_providersummary_decode_malbinary(common_directory_providersummary_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_providersummary_destroy(common_directory_providersummary_t ** self_p);

// test function
void common_directory_providersummary_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_PROVIDERSUMMARY_H_INCLUDED__
