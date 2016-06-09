#ifndef __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite testarea_testservice_testfinalcompositeb
mal_integer_t testarea_testservice_testfinalcompositeb_get_intfield(testarea_testservice_testfinalcompositeb_t * self);
void testarea_testservice_testfinalcompositeb_set_intfield(testarea_testservice_testfinalcompositeb_t * self, mal_integer_t intfield);
mal_string_t * testarea_testservice_testfinalcompositeb_get_stringfield(testarea_testservice_testfinalcompositeb_t * self);
void testarea_testservice_testfinalcompositeb_set_stringfield(testarea_testservice_testfinalcompositeb_t * self, mal_string_t * stringfield);

// default constructor
testarea_testservice_testfinalcompositeb_t * testarea_testservice_testfinalcompositeb_new(void);

// encoding functions related to transport malbinary
int testarea_testservice_testfinalcompositeb_add_encoding_length_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testservice_testfinalcompositeb_encode_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testservice_testfinalcompositeb_decode_malbinary(testarea_testservice_testfinalcompositeb_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void testarea_testservice_testfinalcompositeb_destroy(testarea_testservice_testfinalcompositeb_t ** self_p);

// test function
void testarea_testservice_testfinalcompositeb_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_H_INCLUDED__
