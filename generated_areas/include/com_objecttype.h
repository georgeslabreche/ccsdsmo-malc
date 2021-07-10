#ifndef __COM_OBJECTTYPE_H_INCLUDED__
#define __COM_OBJECTTYPE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_objecttype
mal_ushort_t com_objecttype_get_area(com_objecttype_t * self);
void com_objecttype_set_area(com_objecttype_t * self, mal_ushort_t f_area);
mal_ushort_t com_objecttype_get_service(com_objecttype_t * self);
void com_objecttype_set_service(com_objecttype_t * self, mal_ushort_t f_service);
mal_uoctet_t com_objecttype_get_version(com_objecttype_t * self);
void com_objecttype_set_version(com_objecttype_t * self, mal_uoctet_t f_version);
mal_ushort_t com_objecttype_get_number(com_objecttype_t * self);
void com_objecttype_set_number(com_objecttype_t * self, mal_ushort_t f_number);

// default constructor
com_objecttype_t * com_objecttype_new(void);

// encoding functions related to transport malbinary
int com_objecttype_add_encoding_length_malbinary(com_objecttype_t * self, mal_encoder_t * encoder, void * cursor);
int com_objecttype_encode_malbinary(com_objecttype_t * self, mal_encoder_t * encoder, void * cursor);
int com_objecttype_decode_malbinary(com_objecttype_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_objecttype_destroy(com_objecttype_t ** self_p);

// test function
void com_objecttype_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTTYPE_H_INCLUDED__
