#ifndef __MAL_SUBSCRIPTION_H_INCLUDED__
#define __MAL_SUBSCRIPTION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_subscription
mal_identifier_t * mal_subscription_get_subscriptionid(mal_subscription_t * self);
void mal_subscription_set_subscriptionid(mal_subscription_t * self, mal_identifier_t * subscriptionid);
mal_entityrequest_list_t * mal_subscription_get_entities(mal_subscription_t * self);
void mal_subscription_set_entities(mal_subscription_t * self, mal_entityrequest_list_t * entities);

// default constructor
mal_subscription_t * mal_subscription_new(void);

// encoding functions related to transport malbinary
int mal_subscription_add_encoding_length_malbinary(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_subscription_encode_malbinary(mal_subscription_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_subscription_decode_malbinary(mal_subscription_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_subscription_destroy(mal_subscription_t ** self_p);

// test function
void mal_subscription_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_SUBSCRIPTION_H_INCLUDED__
