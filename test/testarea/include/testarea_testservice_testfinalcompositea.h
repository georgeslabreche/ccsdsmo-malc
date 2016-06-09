#ifndef __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite testarea_testservice_testfinalcompositea
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(testarea_testservice_testfinalcompositea_t * self);
void testarea_testservice_testfinalcompositea_set_intfield(testarea_testservice_testfinalcompositea_t * self, mal_integer_t intfield);
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(testarea_testservice_testfinalcompositea_t * self);
void testarea_testservice_testfinalcompositea_set_intfield2(testarea_testservice_testfinalcompositea_t * self, mal_integer_t intfield2);

// default constructor
testarea_testservice_testfinalcompositea_t * testarea_testservice_testfinalcompositea_new(void);

// encoding functions related to transport malbinary
int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testservice_testfinalcompositea_encode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testservice_testfinalcompositea_decode_malbinary(testarea_testservice_testfinalcompositea_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void testarea_testservice_testfinalcompositea_destroy(testarea_testservice_testfinalcompositea_t ** self_p);

// test function
void testarea_testservice_testfinalcompositea_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__
