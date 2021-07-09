#ifndef __COM_OBJECTKEY_H_INCLUDED__
#define __COM_OBJECTKEY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_objectkey
mal_identifier_list_t * com_objectkey_get_domain(com_objectkey_t * self);
void com_objectkey_set_domain(com_objectkey_t * self, mal_identifier_list_t * f_domain);
mal_long_t com_objectkey_get_instid(com_objectkey_t * self);
void com_objectkey_set_instid(com_objectkey_t * self, mal_long_t f_instid);

// default constructor
com_objectkey_t * com_objectkey_new(void);

// encoding functions related to transport malbinary
int com_objectkey_add_encoding_length_malbinary(com_objectkey_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectkey_encode_malbinary(com_objectkey_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectkey_decode_malbinary(com_objectkey_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_objectkey_destroy(com_objectkey_t ** self_p);

// test function
void com_objectkey_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTKEY_H_INCLUDED__
