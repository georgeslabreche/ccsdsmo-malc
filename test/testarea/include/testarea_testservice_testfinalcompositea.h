/*
 */

#ifndef __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

struct _testarea_testservice_testfinalcompositea_t {
  mal_integer_t intfield;
  mal_integer_t intfield2;
};

testarea_testservice_testfinalcompositea_t *testarea_testservice_testfinalcompositea_new(
    void);

void testarea_testservice_testfinalcompositea_destroy(
    testarea_testservice_testfinalcompositea_t **self_p);

int testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_encoder_t *encoder, unsigned int *encoding_length);

int testarea_testservice_testfinalcompositea_encode_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_encoder_t *encoder, char *bytes, unsigned int *offset);

int testarea_testservice_testfinalcompositea_decode_malbinary(
    testarea_testservice_testfinalcompositea_t *self,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset);

mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(
    testarea_testservice_testfinalcompositea_t *self);

void testarea_testservice_testfinalcompositea_set_intfield();

mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(
    testarea_testservice_testfinalcompositea_t *self);

void testarea_testservice_testfinalcompositea_set_intfield2(
    testarea_testservice_testfinalcompositea_t *self, mal_integer_t intfield2);

void testarea_testservice_testfinalcompositea_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
