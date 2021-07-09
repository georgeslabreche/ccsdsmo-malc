#ifndef __COM_ARCHIVE_COMPOSITEFILTER_H_INCLUDED__
#define __COM_ARCHIVE_COMPOSITEFILTER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_compositefilter
mal_string_t * com_archive_compositefilter_get_fieldname(com_archive_compositefilter_t * self);
void com_archive_compositefilter_set_fieldname(com_archive_compositefilter_t * self, mal_string_t * f_fieldname);
com_archive_expressionoperator_t com_archive_compositefilter_get_type(com_archive_compositefilter_t * self);
void com_archive_compositefilter_set_type(com_archive_compositefilter_t * self, com_archive_expressionoperator_t f_type);
bool com_archive_compositefilter_fieldvalue_is_present(com_archive_compositefilter_t * self);
void com_archive_compositefilter_fieldvalue_set_present(com_archive_compositefilter_t * self, bool is_present);
unsigned char com_archive_compositefilter_fieldvalue_get_attribute_tag(com_archive_compositefilter_t * self);
void com_archive_compositefilter_fieldvalue_set_attribute_tag(com_archive_compositefilter_t * self, unsigned char attribute_tag);

// default constructor
com_archive_compositefilter_t * com_archive_compositefilter_new(void);

// encoding functions related to transport malbinary
int com_archive_compositefilter_add_encoding_length_malbinary(com_archive_compositefilter_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_compositefilter_encode_malbinary(com_archive_compositefilter_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_compositefilter_decode_malbinary(com_archive_compositefilter_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_compositefilter_destroy(com_archive_compositefilter_t ** self_p);

// test function
void com_archive_compositefilter_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_COMPOSITEFILTER_H_INCLUDED__
