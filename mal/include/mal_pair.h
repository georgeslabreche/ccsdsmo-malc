#ifndef __MAL_PAIR_H_INCLUDED__
#define __MAL_PAIR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_pair
bool mal_pair_first_is_present(mal_pair_t * self);
void mal_pair_first_set_present(mal_pair_t * self, bool is_present);
unsigned char mal_pair_first_get_attribute_tag(mal_pair_t * self);
void mal_pair_first_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag);
bool mal_pair_second_is_present(mal_pair_t * self);
void mal_pair_second_set_present(mal_pair_t * self, bool is_present);
unsigned char mal_pair_second_get_attribute_tag(mal_pair_t * self);
void mal_pair_second_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag);

// default constructor
mal_pair_t * mal_pair_new(void);

// encoding functions related to transport malbinary
int mal_pair_add_encoding_length_malbinary(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_encode_malbinary(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_decode_malbinary(mal_pair_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_pair_destroy(mal_pair_t ** self_p);

// test function
void mal_pair_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_PAIR_H_INCLUDED__
