/*
 */

#ifndef __MAL_TIME_LIST_H_INCLUDED__
#define __MAL_TIME_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_time_list_t *mal_time_list_new(unsigned int element_count);

void mal_time_list_destroy(mal_time_list_t **self_p);

unsigned int mal_time_list_get_element_count(mal_time_list_t *self);

bool *mal_time_list_get_presence_flags(mal_time_list_t *self);

mal_time_t *mal_time_list_get_content(mal_time_list_t *self);

void mal_time_list_add_element(mal_time_list_t *self, int index, mal_time_t element);

int mal_time_list_add_encoding_length_malbinary(mal_time_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_time_list_encode_malbinary(mal_time_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_time_list_decode_malbinary(mal_time_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_time_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
