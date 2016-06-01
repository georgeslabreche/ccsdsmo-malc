/*
 */

#ifndef __MAL_DURATION_LIST_H_INCLUDED__
#define __MAL_DURATION_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_duration_list_t *mal_duration_list_new(unsigned int element_count);

void mal_duration_list_destroy(mal_duration_list_t **self_p);

unsigned int mal_duration_list_get_element_count(mal_duration_list_t *self);

bool *mal_duration_list_get_presence_flags(mal_duration_list_t *self);

mal_duration_t *mal_duration_list_get_content(mal_duration_list_t *self);

void mal_duration_list_add_element(mal_duration_list_t *self, int index, mal_duration_t element);

int mal_duration_list_add_encoding_length_malbinary(mal_duration_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_duration_list_encode_malbinary(mal_duration_list_t *self,
    mal_encoder_t *encoder, void *cursor);

int mal_duration_list_decode_malbinary(mal_duration_list_t *self,
    mal_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_duration_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
