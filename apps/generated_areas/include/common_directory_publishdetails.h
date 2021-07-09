#ifndef __COMMON_DIRECTORY_PUBLISHDETAILS_H_INCLUDED__
#define __COMMON_DIRECTORY_PUBLISHDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_publishdetails
mal_identifier_t * common_directory_publishdetails_get_providerid(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_providerid(common_directory_publishdetails_t * self, mal_identifier_t * f_providerid);
mal_identifier_list_t * common_directory_publishdetails_get_domain(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_domain(common_directory_publishdetails_t * self, mal_identifier_list_t * f_domain);
mal_sessiontype_t common_directory_publishdetails_get_sessiontype(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_sessiontype(common_directory_publishdetails_t * self, mal_sessiontype_t f_sessiontype);
mal_identifier_t * common_directory_publishdetails_get_sourcesessionname(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_sourcesessionname(common_directory_publishdetails_t * self, mal_identifier_t * f_sourcesessionname);
mal_identifier_t * common_directory_publishdetails_get_network(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_network(common_directory_publishdetails_t * self, mal_identifier_t * f_network);
common_directory_providerdetails_t * common_directory_publishdetails_get_providerdetails(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_providerdetails(common_directory_publishdetails_t * self, common_directory_providerdetails_t * f_providerdetails);
mal_file_list_t * common_directory_publishdetails_get_servicexml(common_directory_publishdetails_t * self);
void common_directory_publishdetails_set_servicexml(common_directory_publishdetails_t * self, mal_file_list_t * f_servicexml);

// default constructor
common_directory_publishdetails_t * common_directory_publishdetails_new(void);

// encoding functions related to transport malbinary
int common_directory_publishdetails_add_encoding_length_malbinary(common_directory_publishdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_publishdetails_encode_malbinary(common_directory_publishdetails_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_publishdetails_decode_malbinary(common_directory_publishdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_publishdetails_destroy(common_directory_publishdetails_t ** self_p);

// test function
void common_directory_publishdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_PUBLISHDETAILS_H_INCLUDED__
