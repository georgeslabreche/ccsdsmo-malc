/*
 */

#ifndef __MAL_UPDATEHEADER_H_INCLUDED__
#define __MAL_UPDATEHEADER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_updateheader_t *mal_updateheader_new(void);

void mal_updateheader_destroy(mal_updateheader_t **self_p);

int mal_updateheader_add_encoding_length_malbinary(mal_updateheader_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_updateheader_encode_malbinary(mal_updateheader_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_updateheader_decode_malbinary(mal_updateheader_t *self,
    mal_decoder_t *decoder, void *cursor);

void mal_updateheader_set_source_uri(mal_updateheader_t *self, mal_uri_t *source_uri);
mal_uri_t *mal_updateheader_get_source_uri(mal_updateheader_t *self);
void mal_updateheader_set_entitykey(mal_updateheader_t *self, mal_entitykey_t *entitykey);
mal_entitykey_t *mal_updateheader_get_entitykey(mal_updateheader_t *self);
void mal_updateheader_set_timestamp(mal_updateheader_t *self, mal_time_t timestamp);
mal_time_t mal_updateheader_get_timestamp(mal_updateheader_t *self);
void mal_updateheader_set_updatetype(mal_updateheader_t *self, mal_updatetype_t updatetype);
mal_updatetype_t mal_updateheader_get_updatetype(mal_updateheader_t *self);

void mal_updateheader_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
