#ifndef __MAL_UPDATEHEADER_H_INCLUDED__
#define __MAL_UPDATEHEADER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_updateheader
mal_time_t mal_updateheader_get_timestamp(mal_updateheader_t * self);
void mal_updateheader_set_timestamp(mal_updateheader_t * self, mal_time_t timestamp);
mal_uri_t * mal_updateheader_get_sourceuri(mal_updateheader_t * self);
void mal_updateheader_set_sourceuri(mal_updateheader_t * self, mal_uri_t * sourceuri);
mal_updatetype_t mal_updateheader_get_updatetype(mal_updateheader_t * self);
void mal_updateheader_set_updatetype(mal_updateheader_t * self, mal_updatetype_t updatetype);
mal_entitykey_t * mal_updateheader_get_key(mal_updateheader_t * self);
void mal_updateheader_set_key(mal_updateheader_t * self, mal_entitykey_t * key);

// default constructor
mal_updateheader_t * mal_updateheader_new(void);

// encoding functions related to transport malbinary
int mal_updateheader_add_encoding_length_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_updateheader_encode_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_updateheader_decode_malbinary(mal_updateheader_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_updateheader_destroy(mal_updateheader_t ** self_p);

// test function
void mal_updateheader_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_UPDATEHEADER_H_INCLUDED__
