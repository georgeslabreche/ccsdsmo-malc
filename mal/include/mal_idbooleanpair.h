#ifndef __MAL_IDBOOLEANPAIR_H_INCLUDED__
#define __MAL_IDBOOLEANPAIR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_idbooleanpair
mal_identifier_t * mal_idbooleanpair_get_id(mal_idbooleanpair_t * self);
void mal_idbooleanpair_set_id(mal_idbooleanpair_t * self, mal_identifier_t * id);
bool mal_idbooleanpair_value_is_present(mal_idbooleanpair_t * self);
void mal_idbooleanpair_value_set_present(mal_idbooleanpair_t * self, bool is_present);
mal_boolean_t mal_idbooleanpair_get_value(mal_idbooleanpair_t * self);
void mal_idbooleanpair_set_value(mal_idbooleanpair_t * self, mal_boolean_t value);

// default constructor
mal_idbooleanpair_t * mal_idbooleanpair_new(void);

// encoding functions related to transport malbinary
int mal_idbooleanpair_add_encoding_length_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_idbooleanpair_encode_malbinary(mal_idbooleanpair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_idbooleanpair_decode_malbinary(mal_idbooleanpair_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_idbooleanpair_destroy(mal_idbooleanpair_t ** self_p);

// test function
void mal_idbooleanpair_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_IDBOOLEANPAIR_H_INCLUDED__
