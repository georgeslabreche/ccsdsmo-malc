#ifndef __COM_OBJECTID_H_INCLUDED__
#define __COM_OBJECTID_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_objectid
com_objecttype_t * com_objectid_get_type(com_objectid_t * self);
void com_objectid_set_type(com_objectid_t * self, com_objecttype_t * f_type);
com_objectkey_t * com_objectid_get_key(com_objectid_t * self);
void com_objectid_set_key(com_objectid_t * self, com_objectkey_t * f_key);

// default constructor
com_objectid_t * com_objectid_new(void);

// encoding functions related to transport malbinary
int com_objectid_add_encoding_length_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectid_encode_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectid_decode_malbinary(com_objectid_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_objectid_destroy(com_objectid_t ** self_p);

// test function
void com_objectid_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTID_H_INCLUDED__
