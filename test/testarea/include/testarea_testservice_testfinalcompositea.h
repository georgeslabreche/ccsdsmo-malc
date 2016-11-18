/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__
#define __TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite testarea_testservice_testfinalcompositea
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield(testarea_testservice_testfinalcompositea_t * self);
void testarea_testservice_testfinalcompositea_set_intfield(testarea_testservice_testfinalcompositea_t * self, mal_integer_t f_intfield);
mal_integer_t testarea_testservice_testfinalcompositea_get_intfield2(testarea_testservice_testfinalcompositea_t * self);
void testarea_testservice_testfinalcompositea_set_intfield2(testarea_testservice_testfinalcompositea_t * self, mal_integer_t f_intfield2);

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
