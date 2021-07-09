#ifndef __COM_ARCHIVE_PAGINATIONFILTER_H_INCLUDED__
#define __COM_ARCHIVE_PAGINATIONFILTER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_paginationfilter
mal_uinteger_t com_archive_paginationfilter_get_limit(com_archive_paginationfilter_t * self);
void com_archive_paginationfilter_set_limit(com_archive_paginationfilter_t * self, mal_uinteger_t f_limit);
mal_uinteger_t com_archive_paginationfilter_get_offset(com_archive_paginationfilter_t * self);
void com_archive_paginationfilter_set_offset(com_archive_paginationfilter_t * self, mal_uinteger_t f_offset);

// default constructor
com_archive_paginationfilter_t * com_archive_paginationfilter_new(void);

// encoding functions related to transport malbinary
int com_archive_paginationfilter_add_encoding_length_malbinary(com_archive_paginationfilter_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_paginationfilter_encode_malbinary(com_archive_paginationfilter_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_paginationfilter_decode_malbinary(com_archive_paginationfilter_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_paginationfilter_destroy(com_archive_paginationfilter_t ** self_p);

// test function
void com_archive_paginationfilter_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_PAGINATIONFILTER_H_INCLUDED__
