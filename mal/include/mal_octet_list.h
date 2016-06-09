/*
 */

#ifndef __MAL_OCTET_LIST_H_INCLUDED__
#define __MAL_OCTET_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_octet_list_t *mal_octet_list_new(unsigned int element_count);

void mal_octet_list_destroy(mal_octet_list_t **self_p);

unsigned int mal_octet_list_get_element_count(mal_octet_list_t *self);

bool *mal_octet_list_get_presence_flags(mal_octet_list_t *self);

mal_octet_t *mal_octet_list_get_content(mal_octet_list_t *self);

int mal_octet_list_add_encoding_length_malbinary(mal_octet_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_octet_list_encode_malbinary(mal_octet_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_octet_list_decode_malbinary(mal_octet_list_t *self,
    mal_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_octet_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
