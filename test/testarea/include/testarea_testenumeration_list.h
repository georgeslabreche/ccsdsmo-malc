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
int testarea_testenumeration_list_add_encoding_length_malbinary(testarea_testenumeration_list_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testenumeration_list_encode_malbinary(testarea_testenumeration_list_t * self, mal_encoder_t * encoder, void * cursor);
int testarea_testenumeration_list_decode_malbinary(testarea_testenumeration_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void testarea_testenumeration_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_TESTENUMERATION_LIST_H_INCLUDED__
