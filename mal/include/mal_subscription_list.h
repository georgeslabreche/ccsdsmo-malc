/*
 */

#ifndef __MAL_SUBSCRIPTION_LIST_H_INCLUDED__
#define __MAL_SUBSCRIPTION_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_subscription_list_t *mal_subscription_list_new(unsigned int element_count);

void mal_subscription_list_destroy(mal_subscription_list_t **self_p);

unsigned int mal_subscription_list_get_element_count(mal_subscription_list_t *self);

mal_subscription_t **mal_subscription_list_get_content(mal_subscription_list_t *self);

void mal_subscription_list_add_element(mal_subscription_list_t *self, int index, mal_subscription_t *element);

int mal_subscription_list_add_encoding_length_malbinary(mal_subscription_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_subscription_list_encode_malbinary(mal_subscription_list_t *self,
    malbinary_encoder_t *encoder, void *cursor);

int mal_subscription_list_decode_malbinary(mal_subscription_list_t *self,
    malbinary_decoder_t *decoder, void *cursor);

//  Self test of this class
void mal_subscription_list_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
