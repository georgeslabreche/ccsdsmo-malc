/*
 */

#ifndef __MAL_ENTITYREQUEST_H_INCLUDED__
#define __MAL_ENTITYREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_entityrequest_t *mal_entityrequest_new(void);

void mal_entityrequest_destroy(mal_entityrequest_t **self_p);

int mal_entityrequest_add_encoding_length_malbinary(mal_entityrequest_t *self,
    mal_encoder_t *encoder, void *cursor);

void mal_entityrequest_list_add_element(mal_entityrequest_list_t *self, int index, mal_entityrequest_t *element);

int mal_entityrequest_encode_malbinary(mal_entityrequest_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_entityrequest_decode_malbinary(mal_entityrequest_t *self,
    mal_decoder_t *decoder, void *cursor);

void mal_entityrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
