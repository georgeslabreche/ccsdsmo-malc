#ifndef __COM_ARCHIVE_ARCHIVEQUERY_H_INCLUDED__
#define __COM_ARCHIVE_ARCHIVEQUERY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_archivequery
mal_identifier_list_t * com_archive_archivequery_get_domain(com_archive_archivequery_t * self);
void com_archive_archivequery_set_domain(com_archive_archivequery_t * self, mal_identifier_list_t * f_domain);
mal_identifier_t * com_archive_archivequery_get_network(com_archive_archivequery_t * self);
void com_archive_archivequery_set_network(com_archive_archivequery_t * self, mal_identifier_t * f_network);
mal_uri_t * com_archive_archivequery_get_provider(com_archive_archivequery_t * self);
void com_archive_archivequery_set_provider(com_archive_archivequery_t * self, mal_uri_t * f_provider);
mal_long_t com_archive_archivequery_get_related(com_archive_archivequery_t * self);
void com_archive_archivequery_set_related(com_archive_archivequery_t * self, mal_long_t f_related);
com_objectid_t * com_archive_archivequery_get_source(com_archive_archivequery_t * self);
void com_archive_archivequery_set_source(com_archive_archivequery_t * self, com_objectid_t * f_source);
bool com_archive_archivequery_starttime_is_present(com_archive_archivequery_t * self);
void com_archive_archivequery_starttime_set_present(com_archive_archivequery_t * self, bool is_present);
mal_finetime_t com_archive_archivequery_get_starttime(com_archive_archivequery_t * self);
void com_archive_archivequery_set_starttime(com_archive_archivequery_t * self, mal_finetime_t f_starttime);
bool com_archive_archivequery_endtime_is_present(com_archive_archivequery_t * self);
void com_archive_archivequery_endtime_set_present(com_archive_archivequery_t * self, bool is_present);
mal_finetime_t com_archive_archivequery_get_endtime(com_archive_archivequery_t * self);
void com_archive_archivequery_set_endtime(com_archive_archivequery_t * self, mal_finetime_t f_endtime);
bool com_archive_archivequery_sortorder_is_present(com_archive_archivequery_t * self);
void com_archive_archivequery_sortorder_set_present(com_archive_archivequery_t * self, bool is_present);
mal_boolean_t com_archive_archivequery_get_sortorder(com_archive_archivequery_t * self);
void com_archive_archivequery_set_sortorder(com_archive_archivequery_t * self, mal_boolean_t f_sortorder);
mal_string_t * com_archive_archivequery_get_sortfieldname(com_archive_archivequery_t * self);
void com_archive_archivequery_set_sortfieldname(com_archive_archivequery_t * self, mal_string_t * f_sortfieldname);

// default constructor
com_archive_archivequery_t * com_archive_archivequery_new(void);

// encoding functions related to transport malbinary
int com_archive_archivequery_add_encoding_length_malbinary(com_archive_archivequery_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivequery_encode_malbinary(com_archive_archivequery_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivequery_decode_malbinary(com_archive_archivequery_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_archivequery_destroy(com_archive_archivequery_t ** self_p);

// test function
void com_archive_archivequery_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_ARCHIVEQUERY_H_INCLUDED__
