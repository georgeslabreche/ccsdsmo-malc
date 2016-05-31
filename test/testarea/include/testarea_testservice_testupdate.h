#ifndef __TESTAREA_TESTSERVICE_TESTUPDATE_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTUPDATE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite testarea_testservice_testupdate
mal_string_t * testarea_testservice_testupdate_get_stringfield(testarea_testservice_testupdate_t * self);
void testarea_testservice_testupdate_set_stringfield(testarea_testservice_testupdate_t * self, mal_string_t * stringfield);

// default constructor
testarea_testservice_testupdate_t * testarea_testservice_testupdate_new(void);

// encoding functions related to transport malbinary
int testarea_testservice_testupdate_add_encoding_length_malbinary(testarea_testservice_testupdate_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testservice_testupdate_encode_malbinary(testarea_testservice_testupdate_t * self, malbinary_encoder_t * malbinary_encoder, void * cursor);
int testarea_testservice_testupdate_decode_malbinary(testarea_testservice_testupdate_t * self, malbinary_decoder_t * malbinary_decoder, void * cursor);

// destructor
void testarea_testservice_testupdate_destroy(testarea_testservice_testupdate_t ** self_p);

// test function
void testarea_testservice_testupdate_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTUPDATE_H_INCLUDED__
