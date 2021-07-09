#ifndef __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__
#define __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_archivedetails
mal_long_t com_archive_archivedetails_get_instid(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_instid(com_archive_archivedetails_t * self, mal_long_t f_instid);
com_objectdetails_t * com_archive_archivedetails_get_details(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_details(com_archive_archivedetails_t * self, com_objectdetails_t * f_details);
mal_identifier_t * com_archive_archivedetails_get_network(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_network(com_archive_archivedetails_t * self, mal_identifier_t * f_network);
bool com_archive_archivedetails_timestamp_is_present(com_archive_archivedetails_t * self);
void com_archive_archivedetails_timestamp_set_present(com_archive_archivedetails_t * self, bool is_present);
mal_finetime_t com_archive_archivedetails_get_timestamp(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_timestamp(com_archive_archivedetails_t * self, mal_finetime_t f_timestamp);
mal_uri_t * com_archive_archivedetails_get_provider(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_provider(com_archive_archivedetails_t * self, mal_uri_t * f_provider);

// default constructor
com_archive_archivedetails_t * com_archive_archivedetails_new(void);

// encoding functions related to transport malbinary
int com_archive_archivedetails_add_encoding_length_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivedetails_encode_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivedetails_decode_malbinary(com_archive_archivedetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_archivedetails_destroy(com_archive_archivedetails_t ** self_p);

// test function
void com_archive_archivedetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__
