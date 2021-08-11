#ifndef __COMMON_DIRECTORY_SERVICEFILTER_H_INCLUDED__
#define __COMMON_DIRECTORY_SERVICEFILTER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_directory_servicefilter
mal_identifier_t * common_directory_servicefilter_get_serviceproviderid(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_serviceproviderid(common_directory_servicefilter_t * self, mal_identifier_t * f_serviceproviderid);
mal_identifier_list_t * common_directory_servicefilter_get_domain(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_domain(common_directory_servicefilter_t * self, mal_identifier_list_t * f_domain);
mal_identifier_t * common_directory_servicefilter_get_network(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_network(common_directory_servicefilter_t * self, mal_identifier_t * f_network);
bool common_directory_servicefilter_sessiontype_is_present(common_directory_servicefilter_t * self);
void common_directory_servicefilter_sessiontype_set_present(common_directory_servicefilter_t * self, bool is_present);
mal_sessiontype_t common_directory_servicefilter_get_sessiontype(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_sessiontype(common_directory_servicefilter_t * self, mal_sessiontype_t f_sessiontype);
mal_identifier_t * common_directory_servicefilter_get_sessionname(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_sessionname(common_directory_servicefilter_t * self, mal_identifier_t * f_sessionname);
common_servicekey_t * common_directory_servicefilter_get_servicekey(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_servicekey(common_directory_servicefilter_t * self, common_servicekey_t * f_servicekey);
mal_ushort_list_t * common_directory_servicefilter_get_requiredcapabilitysets(common_directory_servicefilter_t * self);
void common_directory_servicefilter_set_requiredcapabilitysets(common_directory_servicefilter_t * self, mal_ushort_list_t * f_requiredcapabilitysets);

// default constructor
common_directory_servicefilter_t * common_directory_servicefilter_new(void);

// encoding functions related to transport malbinary
int common_directory_servicefilter_add_encoding_length_malbinary(common_directory_servicefilter_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicefilter_encode_malbinary(common_directory_servicefilter_t * self, mal_encoder_t * encoder, void * cursor);
int common_directory_servicefilter_decode_malbinary(common_directory_servicefilter_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_directory_servicefilter_destroy(common_directory_servicefilter_t ** self_p);

// test function
void common_directory_servicefilter_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_DIRECTORY_SERVICEFILTER_H_INCLUDED__
