#ifndef __COM_OBJECTTYPE_LIST_H_INCLUDED__
#define __COM_OBJECTTYPE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
com_objecttype_list_t * com_objecttype_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void com_objecttype_list_destroy(com_objecttype_list_t ** self_p);

// fields accessors for composite list com_objecttype_list
unsigned int com_objecttype_list_get_element_count(com_objecttype_list_t * self);
com_objecttype_t ** com_objecttype_list_get_content(com_objecttype_list_t * self);

// encoding functions related to transport malbinary
int com_objecttype_list_add_encoding_length_malbinary(com_objecttype_list_t * self, mal_encoder_t * encoder, void * cursor);
int com_objecttype_list_encode_malbinary(com_objecttype_list_t * self, mal_encoder_t * encoder, void * cursor);
int com_objecttype_list_decode_malbinary(com_objecttype_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void com_objecttype_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTTYPE_LIST_H_INCLUDED__
