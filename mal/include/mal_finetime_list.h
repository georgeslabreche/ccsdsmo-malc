/*
 */

#ifndef __MAL_FINETIME_LIST_H_INCLUDED__
#define __MAL_FINETIME_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_finetime_list_t *mal_finetime_list_new(unsigned int element_count);

void mal_finetime_list_destroy(mal_finetime_list_t **self_p);

unsigned int mal_finetime_list_get_element_count(mal_finetime_list_t *self);

bool *mal_finetime_list_get_presence_flags(mal_finetime_list_t *self);

mal_finetime_t *mal_finetime_list_get_content(mal_finetime_list_t *self);

void mal_finetime_list_add_element(mal_finetime_list_t *self, int index, mal_finetime_t element);

int mal_finetime_list_add_encoding_length_malbinary(mal_finetime_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_finetime_list_encode_malbinary(mal_finetime_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_finetime_list_decode_malbinary(mal_finetime_list_t *self,
    mal_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_finetime_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
