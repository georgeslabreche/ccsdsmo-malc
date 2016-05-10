/*
 */

#ifndef __MAL_INTERACTIONTYPE_LIST_H_INCLUDED__
#define __MAL_INTERACTIONTYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_interactiontype_list_t *mal_interactiontype_list_new(
    unsigned int element_count);

void mal_interactiontype_list_destroy(mal_interactiontype_list_t **self_p);

unsigned int mal_interactiontype_list_get_element_count(
    mal_interactiontype_list_t *self);

mal_interactiontype_t *mal_interactiontype_list_get_content();

bool *mal_interactiontype_list_get_presence_flags(
    mal_interactiontype_list_t *self);

int mal_interactiontype_list_add_encoding_length_malbinary(
    mal_interactiontype_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_interactiontype_list_encode_malbinary(mal_interactiontype_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_interactiontype_list_decode_malbinary(mal_interactiontype_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_interactiontype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
