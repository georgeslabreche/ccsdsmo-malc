/*
 */

#ifndef __MAL_ENTITYKEY_LIST_H_INCLUDED__
#define __MAL_ENTITYKEY_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_entitykey_list_t *mal_entitykey_list_new(unsigned int element_count);

void mal_entitykey_list_destroy(mal_entitykey_list_t **self_p);

unsigned int mal_entitykey_list_get_element_count(mal_entitykey_list_t *self);

mal_entitykey_t **mal_entitykey_list_get_content(mal_entitykey_list_t *self);

int mal_entitykey_list_add_encoding_length_malbinary(mal_entitykey_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_entitykey_list_encode_malbinary(mal_entitykey_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_entitykey_list_decode_malbinary(mal_entitykey_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_entitykey_list_test(bool verbose);

struct _mal_entitykey_list_t {
  unsigned int element_count;
  mal_entitykey_t **content;
};

#ifdef __cplusplus
}
#endif

#endif
