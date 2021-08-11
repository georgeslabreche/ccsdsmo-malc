#ifndef __COM_ARCHIVESYNC_DICTIONARY_H_INCLUDED__
#define __COM_ARCHIVESYNC_DICTIONARY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archivesync_dictionary
com_archivesync_dictionaryentry_list_t * com_archivesync_dictionary_get_entries(com_archivesync_dictionary_t * self);
void com_archivesync_dictionary_set_entries(com_archivesync_dictionary_t * self, com_archivesync_dictionaryentry_list_t * f_entries);

// default constructor
com_archivesync_dictionary_t * com_archivesync_dictionary_new(void);

// encoding functions related to transport malbinary
int com_archivesync_dictionary_add_encoding_length_malbinary(com_archivesync_dictionary_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_dictionary_encode_malbinary(com_archivesync_dictionary_t * self, mal_encoder_t * encoder, void * cursor);
int com_archivesync_dictionary_decode_malbinary(com_archivesync_dictionary_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archivesync_dictionary_destroy(com_archivesync_dictionary_t ** self_p);

// test function
void com_archivesync_dictionary_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVESYNC_DICTIONARY_H_INCLUDED__
