#ifndef __MAL_ENTITYREQUEST_H_INCLUDED__
#define __MAL_ENTITYREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_entityrequest
mal_identifier_list_t * mal_entityrequest_get_subdomain(mal_entityrequest_t * self);
void mal_entityrequest_set_subdomain(mal_entityrequest_t * self, mal_identifier_list_t * subdomain);
mal_boolean_t mal_entityrequest_get_allareas(mal_entityrequest_t * self);
void mal_entityrequest_set_allareas(mal_entityrequest_t * self, mal_boolean_t allareas);
mal_boolean_t mal_entityrequest_get_allservices(mal_entityrequest_t * self);
void mal_entityrequest_set_allservices(mal_entityrequest_t * self, mal_boolean_t allservices);
mal_boolean_t mal_entityrequest_get_alloperations(mal_entityrequest_t * self);
void mal_entityrequest_set_alloperations(mal_entityrequest_t * self, mal_boolean_t alloperations);
mal_boolean_t mal_entityrequest_get_onlyonchange(mal_entityrequest_t * self);
void mal_entityrequest_set_onlyonchange(mal_entityrequest_t * self, mal_boolean_t onlyonchange);
mal_entitykey_list_t * mal_entityrequest_get_entitykeys(mal_entityrequest_t * self);
void mal_entityrequest_set_entitykeys(mal_entityrequest_t * self, mal_entitykey_list_t * entitykeys);

// default constructor
mal_entityrequest_t * mal_entityrequest_new(void);

// encoding functions related to transport malbinary
int mal_entityrequest_add_encoding_length_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entityrequest_encode_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entityrequest_decode_malbinary(mal_entityrequest_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_entityrequest_destroy(mal_entityrequest_t ** self_p);

// test function
void mal_entityrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_ENTITYREQUEST_H_INCLUDED__
