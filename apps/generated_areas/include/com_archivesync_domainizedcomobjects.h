#ifndef __COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_H_INCLUDED__
#define __COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archivesync_domainizedcomobjects
bool com_archivesync_domainizedcomobjects_domain_is_present(com_archivesync_domainizedcomobjects_t * self);
void com_archivesync_domainizedcomobjects_domain_set_present(com_archivesync_domainizedcomobjects_t * self, bool is_present);
mal_uinteger_t com_archivesync_domainizedcomobjects_get_domain(com_archivesync_domainizedcomobjects_t * self);
void com_archivesync_domainizedcomobjects_set_domain(com_archivesync_domainizedcomobjects_t * self, mal_uinteger_t f_domain);
com_archivesync_compactcomobject_list_t * com_archivesync_domainizedcomobjects_get_compactcomobjects(com_archivesync_domainizedcomobjects_t * self);
void com_archivesync_domainizedcomobjects_set_compactcomobjects(com_archivesync_domainizedcomobjects_t * self, com_archivesync_compactcomobject_list_t * f_compactcomobjects);

// default constructor
com_archivesync_domainizedcomobjects_t * com_archivesync_domainizedcomobjects_new(void);

// encoding functions related to transport malbinary
int com_archivesync_domainizedcomobjects_add_encoding_length_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_domainizedcomobjects_encode_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_domainizedcomobjects_decode_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archivesync_domainizedcomobjects_destroy(com_archivesync_domainizedcomobjects_t ** self_p);

// test function
void com_archivesync_domainizedcomobjects_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_H_INCLUDED__
