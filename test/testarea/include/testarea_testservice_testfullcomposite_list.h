#ifndef __TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_LIST_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
testarea_testservice_testfullcomposite_list_t * testarea_testservice_testfullcomposite_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void testarea_testservice_testfullcomposite_list_destroy(testarea_testservice_testfullcomposite_list_t ** self_p);

// fields accessors for composite list testarea_testservice_testfullcomposite_list
unsigned int testarea_testservice_testfullcomposite_list_get_element_count(testarea_testservice_testfullcomposite_list_t * self);
testarea_testservice_testfullcomposite_t ** testarea_testservice_testfullcomposite_list_get_content(testarea_testservice_testfullcomposite_list_t * self);

// encoding functions related to transport malbinary
int testarea_testservice_testfullcomposite_list_add_encoding_length_malbinary(testarea_testservice_testfullcomposite_list_t * self, malbinary_encoder_t * malbinary_encoder, unsigned int * encoding_length);
int testarea_testservice_testfullcomposite_list_encode_malbinary(testarea_testservice_testfullcomposite_list_t * self, malbinary_encoder_t * malbinary_encoder, char * bytes, unsigned int * offset);
int testarea_testservice_testfullcomposite_list_decode_malbinary(testarea_testservice_testfullcomposite_list_t * self, malbinary_decoder_t * malbinary_decoder, char * bytes, unsigned int * offset);

// test function
void testarea_testservice_testfullcomposite_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_LIST_H_INCLUDED__
