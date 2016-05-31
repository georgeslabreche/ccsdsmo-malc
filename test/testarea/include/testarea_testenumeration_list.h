#ifndef __TESTAREA_TESTENUMERATION_LIST_H_INCLUDED__
#define __TESTAREA_TESTENUMERATION_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
testarea_testenumeration_list_t * testarea_testenumeration_list_new(unsigned int element_count);

// destructor, free the list and its content
void testarea_testenumeration_list_destroy(testarea_testenumeration_list_t ** self_p);

// fields accessors for enumeration list testarea_testenumeration_list
unsigned int testarea_testenumeration_list_get_element_count(testarea_testenumeration_list_t * self);
bool * testarea_testenumeration_list_get_presence_flags(testarea_testenumeration_list_t * self);
testarea_testenumeration_t * testarea_testenumeration_list_get_content(testarea_testenumeration_list_t * self);

// encoding functions related to transport malbinary
int testarea_testenumeration_list_add_encoding_length_malbinary(testarea_testenumeration_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testenumeration_list_encode_malbinary(testarea_testenumeration_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testenumeration_list_decode_malbinary(testarea_testenumeration_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// test function
void testarea_testenumeration_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTENUMERATION_LIST_H_INCLUDED__
