#ifndef __COM_INSTANCEBOOLEANPAIR_H_INCLUDED__
#define __COM_INSTANCEBOOLEANPAIR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_instancebooleanpair
mal_long_t com_instancebooleanpair_get_id(com_instancebooleanpair_t * self);
void com_instancebooleanpair_set_id(com_instancebooleanpair_t * self, mal_long_t f_id);
mal_boolean_t com_instancebooleanpair_get_value(com_instancebooleanpair_t * self);
void com_instancebooleanpair_set_value(com_instancebooleanpair_t * self, mal_boolean_t f_value);

// default constructor
com_instancebooleanpair_t * com_instancebooleanpair_new(void);

// encoding functions related to transport malbinary
int com_instancebooleanpair_add_encoding_length_malbinary(com_instancebooleanpair_t * self, mal_encoder_t * encoder, void * cursor);
int com_instancebooleanpair_encode_malbinary(com_instancebooleanpair_t * self, mal_encoder_t * encoder, void * cursor);
int com_instancebooleanpair_decode_malbinary(com_instancebooleanpair_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_instancebooleanpair_destroy(com_instancebooleanpair_t ** self_p);

// test function
void com_instancebooleanpair_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_INSTANCEBOOLEANPAIR_H_INCLUDED__
