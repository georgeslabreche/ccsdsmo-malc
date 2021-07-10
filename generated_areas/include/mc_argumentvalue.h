#ifndef __MC_ARGUMENTVALUE_H_INCLUDED__
#define __MC_ARGUMENTVALUE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mc_argumentvalue
mal_boolean_t mc_argumentvalue_get_isconvertedvalue(mc_argumentvalue_t * self);
void mc_argumentvalue_set_isconvertedvalue(mc_argumentvalue_t * self, mal_boolean_t f_isconvertedvalue);
bool mc_argumentvalue_value_is_present(mc_argumentvalue_t * self);
void mc_argumentvalue_value_set_present(mc_argumentvalue_t * self, bool is_present);
unsigned char mc_argumentvalue_value_get_attribute_tag(mc_argumentvalue_t * self);
void mc_argumentvalue_value_set_attribute_tag(mc_argumentvalue_t * self, unsigned char attribute_tag);

// default constructor
mc_argumentvalue_t * mc_argumentvalue_new(void);

// encoding functions related to transport malbinary
int mc_argumentvalue_add_encoding_length_malbinary(mc_argumentvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentvalue_encode_malbinary(mc_argumentvalue_t * self, mal_encoder_t * encoder, void * cursor);
int mc_argumentvalue_decode_malbinary(mc_argumentvalue_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void mc_argumentvalue_destroy(mc_argumentvalue_t ** self_p);

// test function
void mc_argumentvalue_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_ARGUMENTVALUE_H_INCLUDED__
