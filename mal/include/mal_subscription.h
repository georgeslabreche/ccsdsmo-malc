/*
 */

#ifndef __MAL_SUBSCRIPTION_H_INCLUDED__
#define __MAL_SUBSCRIPTION_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

mal_subscription_t *mal_subscription_new(void);

void mal_subscription_destroy(mal_subscription_t **self_p);

int mal_subscription_add_encoding_length_malbinary(mal_subscription_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length);

int mal_subscription_encode_malbinary(mal_subscription_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset);

int mal_subscription_decode_malbinary(mal_subscription_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset);

mal_identifier_t *mal_subscription_get_subscriptionid(mal_subscription_t *self);

void mal_subscription_set_subscriptionid(mal_subscription_t *self,
    mal_identifier_t *subscriptionid);

mal_entityrequest_list_t *mal_subscription_get_entities(
    mal_subscription_t *self);

void mal_subscription_set_entities(mal_subscription_t *self,
    mal_entityrequest_list_t * entities);

void mal_subscription_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
