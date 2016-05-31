#ifndef __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_LIST_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
testarea_testservice_testfinalcompositea_list_t * testarea_testservice_testfinalcompositea_list_new(unsigned int element_count);

// destructor, free the list, its content and its elements
void testarea_testservice_testfinalcompositea_list_destroy(testarea_testservice_testfinalcompositea_list_t ** self_p);

// fields accessors for composite list testarea_testservice_testfinalcompositea_list
unsigned int testarea_testservice_testfinalcompositea_list_get_element_count(testarea_testservice_testfinalcompositea_list_t * self);
testarea_testservice_testfinalcompositea_t ** testarea_testservice_testfinalcompositea_list_get_content(testarea_testservice_testfinalcompositea_list_t * self);

// encoding functions related to transport malbinary
int testarea_testservice_testfinalcompositea_list_add_encoding_length_malbinary(testarea_testservice_testfinalcompositea_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testservice_testfinalcompositea_list_encode_malbinary(testarea_testservice_testfinalcompositea_list_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testservice_testfinalcompositea_list_decode_malbinary(testarea_testservice_testfinalcompositea_list_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// test function
void testarea_testservice_testfinalcompositea_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_LIST_H_INCLUDED__
