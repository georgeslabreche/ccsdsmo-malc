/*
 */

#ifndef __MAL_BOOLEAN_LIST_H_INCLUDED__
#define __MAL_BOOLEAN_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_boolean_list_t *mal_boolean_list_new(unsigned int element_count);

void mal_boolean_list_destroy(mal_boolean_list_t **self_p);

unsigned int mal_boolean_list_get_element_count(mal_boolean_list_t *self);

bool *mal_boolean_list_get_presence_flags(mal_boolean_list_t *self);

mal_boolean_t *mal_boolean_list_get_content(mal_boolean_list_t *self);

int mal_boolean_list_add_encoding_length_malbinary(mal_boolean_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_boolean_list_encode_malbinary(mal_boolean_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_boolean_list_decode_malbinary(mal_boolean_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_boolean_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
