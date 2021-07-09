#ifndef __COM_ARCHIVE_COMPOSITEFILTERSET_H_INCLUDED__
#define __COM_ARCHIVE_COMPOSITEFILTERSET_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_compositefilterset
com_archive_compositefilter_list_t * com_archive_compositefilterset_get_filters(com_archive_compositefilterset_t * self);
void com_archive_compositefilterset_set_filters(com_archive_compositefilterset_t * self, com_archive_compositefilter_list_t * f_filters);

// default constructor
com_archive_compositefilterset_t * com_archive_compositefilterset_new(void);

// encoding functions related to transport malbinary
int com_archive_compositefilterset_add_encoding_length_malbinary(com_archive_compositefilterset_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_compositefilterset_encode_malbinary(com_archive_compositefilterset_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_compositefilterset_decode_malbinary(com_archive_compositefilterset_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_compositefilterset_destroy(com_archive_compositefilterset_t ** self_p);

// test function
void com_archive_compositefilterset_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_COMPOSITEFILTERSET_H_INCLUDED__
