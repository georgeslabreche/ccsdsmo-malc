#ifndef __COM_ARCHIVESYNC_DICTIONARYENTRY_H_INCLUDED__
#define __COM_ARCHIVESYNC_DICTIONARYENTRY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archivesync_dictionaryentry
bool com_archivesync_dictionaryentry_id_is_present(com_archivesync_dictionaryentry_t * self);
void com_archivesync_dictionaryentry_id_set_present(com_archivesync_dictionaryentry_t * self, bool is_present);
mal_uinteger_t com_archivesync_dictionaryentry_get_id(com_archivesync_dictionaryentry_t * self);
void com_archivesync_dictionaryentry_set_id(com_archivesync_dictionaryentry_t * self, mal_uinteger_t f_id);
mal_string_t * com_archivesync_dictionaryentry_get_string(com_archivesync_dictionaryentry_t * self);
void com_archivesync_dictionaryentry_set_string(com_archivesync_dictionaryentry_t * self, mal_string_t * f_string);

// default constructor
com_archivesync_dictionaryentry_t * com_archivesync_dictionaryentry_new(void);

// encoding functions related to transport malbinary
int com_archivesync_dictionaryentry_add_encoding_length_malbinary(com_archivesync_dictionaryentry_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_dictionaryentry_encode_malbinary(com_archivesync_dictionaryentry_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_dictionaryentry_decode_malbinary(com_archivesync_dictionaryentry_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archivesync_dictionaryentry_destroy(com_archivesync_dictionaryentry_t ** self_p);

// test function
void com_archivesync_dictionaryentry_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVESYNC_DICTIONARYENTRY_H_INCLUDED__
