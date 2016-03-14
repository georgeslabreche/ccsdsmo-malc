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
    malbinary_encoder_t *encoder, unsigned int *encoding_length);

int mal_entityrequest_encode_malbinary(mal_entityrequest_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset);

int mal_entityrequest_decode_malbinary(mal_entityrequest_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset);

void mal_entityrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
