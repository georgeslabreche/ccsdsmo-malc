/*
 */

#ifndef __MAL_URI_LIST_H_INCLUDED__
#define __MAL_URI_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_uri_list_t *mal_uri_list_new(unsigned int element_count);

void mal_uri_list_destroy(mal_uri_list_t **self_p);

unsigned int mal_uri_list_get_element_count(mal_uri_list_t *self);

mal_uri_t **mal_uri_list_get_content(mal_uri_list_t *self);

void mal_uri_list_add_element(mal_uri_list_t *self, int index, mal_uri_t *element);

int mal_uri_list_add_encoding_length_malbinary(mal_uri_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_uri_list_encode_malbinary(mal_uri_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_uri_list_decode_malbinary(mal_uri_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

void mal_uri_list_print(mal_uri_list_t *self);

//  Self test of this class
void mal_uri_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
