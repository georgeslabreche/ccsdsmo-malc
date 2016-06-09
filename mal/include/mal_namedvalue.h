#ifndef __MAL_NAMEDVALUE_H_INCLUDED__
#define __MAL_NAMEDVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_namedvalue
mal_identifier_t * mal_namedvalue_get_name(mal_namedvalue_t * self);
void mal_namedvalue_set_name(mal_namedvalue_t * self, mal_identifier_t * name);
bool mal_namedvalue_value_is_present(mal_namedvalue_t * self);
void mal_namedvalue_value_set_present(mal_namedvalue_t * self, bool is_present);
unsigned char mal_namedvalue_value_get_attribute_tag(mal_namedvalue_t * self);
void mal_namedvalue_value_set_attribute_tag(mal_namedvalue_t * self, unsigned char attribute_tag);

// default constructor
mal_namedvalue_t * mal_namedvalue_new(void);

// encoding functions related to transport malbinary
int mal_namedvalue_add_encoding_length_malbinary(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_namedvalue_encode_malbinary(mal_namedvalue_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_namedvalue_decode_malbinary(mal_namedvalue_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_namedvalue_destroy(mal_namedvalue_t ** self_p);

// test function
void mal_namedvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_NAMEDVALUE_H_INCLUDED__
