/*
 */

#ifndef __MAL_UPDATEHEADER_LIST_H_INCLUDED__
#define __MAL_UPDATEHEADER_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_updateheader_list_t *mal_updateheader_list_new(unsigned int element_count);

void mal_updateheader_list_destroy(mal_updateheader_list_t **self_p);

unsigned int mal_updateheader_list_get_element_count(mal_updateheader_list_t *self);

mal_updateheader_t **mal_updateheader_list_get_content(mal_updateheader_list_t *self);

int mal_updateheader_list_add_encoding_length_malbinary(mal_updateheader_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_updateheader_list_encode_malbinary(mal_updateheader_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_updateheader_list_decode_malbinary(mal_updateheader_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_updateheader_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
