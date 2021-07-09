#ifndef __COM_OBJECTDETAILS_H_INCLUDED__
#define __COM_OBJECTDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_objectdetails
bool com_objectdetails_related_is_present(com_objectdetails_t * self);
void com_objectdetails_related_set_present(com_objectdetails_t * self, bool is_present);
mal_long_t com_objectdetails_get_related(com_objectdetails_t * self);
void com_objectdetails_set_related(com_objectdetails_t * self, mal_long_t f_related);
com_objectid_t * com_objectdetails_get_source(com_objectdetails_t * self);
void com_objectdetails_set_source(com_objectdetails_t * self, com_objectid_t * f_source);

// default constructor
com_objectdetails_t * com_objectdetails_new(void);

// encoding functions related to transport malbinary
int com_objectdetails_add_encoding_length_malbinary(com_objectdetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectdetails_encode_malbinary(com_objectdetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectdetails_decode_malbinary(com_objectdetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_objectdetails_destroy(com_objectdetails_t ** self_p);

// test function
void com_objectdetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTDETAILS_H_INCLUDED__
