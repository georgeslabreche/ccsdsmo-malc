#ifndef __MAL_SUBSCRIPTION_LIST_H_INCLUDED__
#define __MAL_SUBSCRIPTION_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_subscription_list_t * mal_subscription_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void mal_subscription_list_destroy(mal_subscription_list_t ** self_p);

// fields accessors for composite list mal_subscription_list
unsigned int mal_subscription_list_get_element_count(mal_subscription_list_t * self);
mal_subscription_t ** mal_subscription_list_get_content(mal_subscription_list_t * self);

// encoding functions related to transport malbinary
int mal_subscription_list_add_encoding_length_malbinary(mal_subscription_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_subscription_list_encode_malbinary(mal_subscription_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_subscription_list_decode_malbinary(mal_subscription_list_t * self, mal_decoder_t * mal_decoder, void * cursor);

// test function
void mal_subscription_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_SUBSCRIPTION_LIST_H_INCLUDED__
