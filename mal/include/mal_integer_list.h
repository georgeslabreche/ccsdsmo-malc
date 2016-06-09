/*
 */

#ifndef __MAL_INTEGER_LIST_H_INCLUDED__
#define __MAL_INTEGER_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_integer_list_t *mal_integer_list_new(unsigned int element_count);

void mal_integer_list_destroy(mal_integer_list_t **self_p);

unsigned int mal_integer_list_get_element_count(mal_integer_list_t *self);

bool *mal_integer_list_get_presence_flags(mal_integer_list_t *self);

mal_integer_t *mal_integer_list_get_content(mal_integer_list_t *self);

int mal_integer_list_add_encoding_length_malbinary(mal_integer_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_integer_list_encode_malbinary(mal_integer_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_integer_list_decode_malbinary(mal_integer_list_t *self,
    mal_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_integer_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
