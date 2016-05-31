/*
 */

#ifndef __MAL_DOUBLE_LIST_H_INCLUDED__
#define __MAL_DOUBLE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_double_list_t *mal_double_list_new(unsigned int element_count);

void mal_double_list_destroy(mal_double_list_t **self_p);

unsigned int mal_double_list_get_element_count(mal_double_list_t *self);

bool *mal_double_list_get_presence_flags(mal_double_list_t *self);

mal_double_t *mal_double_list_get_content(mal_double_list_t *self);

void mal_double_list_add_element(mal_double_list_t *self, int index, mal_double_t element);

int mal_double_list_add_encoding_length_malbinary(mal_double_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_double_list_encode_malbinary(mal_double_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_double_list_decode_malbinary(mal_double_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_double_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
