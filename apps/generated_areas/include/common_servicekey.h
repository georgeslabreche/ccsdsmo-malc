#ifndef __COMMON_SERVICEKEY_H_INCLUDED__
#define __COMMON_SERVICEKEY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite common_servicekey
mal_ushort_t common_servicekey_get_keyarea(common_servicekey_t * self);
void common_servicekey_set_keyarea(common_servicekey_t * self, mal_ushort_t f_keyarea);
mal_ushort_t common_servicekey_get_keyservice(common_servicekey_t * self);
void common_servicekey_set_keyservice(common_servicekey_t * self, mal_ushort_t f_keyservice);
mal_uoctet_t common_servicekey_get_keyareaversion(common_servicekey_t * self);
void common_servicekey_set_keyareaversion(common_servicekey_t * self, mal_uoctet_t f_keyareaversion);

// default constructor
common_servicekey_t * common_servicekey_new(void);

// encoding functions related to transport malbinary
int common_servicekey_add_encoding_length_malbinary(common_servicekey_t * self, mal_encoder_t * encoder, void * cursor);
int common_servicekey_encode_malbinary(common_servicekey_t * self, mal_encoder_t * encoder, void * cursor);
int common_servicekey_decode_malbinary(common_servicekey_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void common_servicekey_destroy(common_servicekey_t ** self_p);

// test function
void common_servicekey_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_SERVICEKEY_H_INCLUDED__
