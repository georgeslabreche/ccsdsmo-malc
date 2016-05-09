#ifndef __TESTAREA_TESTSERVICE_TESTCOMPOSITE_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTCOMPOSITE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite testarea_testservice_testcomposite
mal_string_t * testarea_testservice_testcomposite_get_stringfield(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_set_stringfield(testarea_testservice_testcomposite_t * self, mal_string_t * stringfield);
bool testarea_testservice_testcomposite_intfield_is_present(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_intfield_set_present(testarea_testservice_testcomposite_t * self, bool is_present);
mal_integer_t testarea_testservice_testcomposite_get_intfield(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_set_intfield(testarea_testservice_testcomposite_t * self, mal_integer_t intfield);

bool testarea_testservice_testcomposite_floatfield_is_present(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_floatfield_set_present(testarea_testservice_testcomposite_t * self, bool is_present);
mal_float_t testarea_testservice_testcomposite_get_floatfield(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_set_floatfield(testarea_testservice_testcomposite_t * self, mal_float_t intfield);

bool testarea_testservice_testcomposite_doublefield_is_present(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_doublefield_set_present(testarea_testservice_testcomposite_t * self, bool is_present);
mal_double_t testarea_testservice_testcomposite_get_doublefield(testarea_testservice_testcomposite_t * self);
void testarea_testservice_testcomposite_set_doublefield(testarea_testservice_testcomposite_t * self, mal_double_t intfield);

// default constructor
testarea_testservice_testcomposite_t * testarea_testservice_testcomposite_new(void);

// encoding functions related to transport malbinary
int testarea_testservice_testcomposite_add_encoding_length_malbinary(testarea_testservice_testcomposite_t * self, malbinary_encoder_t * malbinary_encoder, unsigned int * encoding_length);
int testarea_testservice_testcomposite_encode_malbinary(testarea_testservice_testcomposite_t * self, malbinary_encoder_t * malbinary_encoder, char * bytes, unsigned int * offset);
int testarea_testservice_testcomposite_decode_malbinary(testarea_testservice_testcomposite_t * self, malbinary_decoder_t * malbinary_decoder, char * bytes, unsigned int * offset);

// destructor
void testarea_testservice_testcomposite_destroy(testarea_testservice_testcomposite_t ** self_p);

// test function
void testarea_testservice_testcomposite_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTSERVICE_TESTCOMPOSITE_H_INCLUDED__
