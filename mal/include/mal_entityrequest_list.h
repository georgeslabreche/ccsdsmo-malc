/*
 */

#ifndef __MAL_ENTITYREQUEST_LIST_H_INCLUDED__
#define __MAL_ENTITYREQUEST_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_entityrequest_list_t *mal_entityrequest_list_new(unsigned int element_count);

void mal_entityrequest_list_destroy(mal_entityrequest_list_t **self_p);

unsigned int mal_entityrequest_list_get_element_count(mal_entityrequest_list_t *self);

mal_entityrequest_t **mal_entityrequest_list_get_content(mal_entityrequest_list_t *self);

int mal_entityrequest_list_add_encoding_length_malbinary(mal_entityrequest_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_entityrequest_list_encode_malbinary(mal_entityrequest_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_entityrequest_list_decode_malbinary(mal_entityrequest_list_t *self,
    mal_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_entityrequest_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
