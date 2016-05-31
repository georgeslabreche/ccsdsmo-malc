/*
 */

#ifndef __MAL_ULONG_LIST_H_INCLUDED__
#define __MAL_ULONG_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_ulong_list_t *mal_ulong_list_new(unsigned int element_count);

void mal_ulong_list_destroy(mal_ulong_list_t **self_p);

unsigned int mal_ulong_list_get_element_count(mal_ulong_list_t *self);

bool *mal_ulong_list_get_presence_flags(mal_ulong_list_t *self);

mal_ulong_t *mal_ulong_list_get_content(mal_ulong_list_t *self);

void mal_ulong_list_add_element(mal_ulong_list_t *self, int index, mal_ulong_t element);

int mal_ulong_list_add_encoding_length_malbinary(mal_ulong_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_ulong_list_encode_malbinary(mal_ulong_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_ulong_list_decode_malbinary(mal_ulong_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_ulong_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
