/*
 */

#ifndef __MAL_FLOAT_LIST_H_INCLUDED__
#define __MAL_FLOAT_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_float_list_t *mal_float_list_new(unsigned int element_count);

void mal_float_list_destroy(mal_float_list_t **self_p);

unsigned int mal_float_list_get_element_count(mal_float_list_t *self);

bool *mal_float_list_get_presence_flags(mal_float_list_t *self);

mal_float_t *mal_float_list_get_content(mal_float_list_t *self);

void mal_float_list_add_element(mal_float_list_t *self, int index, mal_float_t element);

int mal_float_list_add_encoding_length_malbinary(mal_float_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_float_list_encode_malbinary(mal_float_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_float_list_decode_malbinary(mal_float_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_float_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
