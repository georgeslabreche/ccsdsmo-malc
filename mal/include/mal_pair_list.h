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

#ifndef __MAL_PAIR_LIST_H_INCLUDED__
#define __MAL_PAIR_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
mal_pair_list_t * mal_pair_list_new(unsigned int element_count);

void mal_pair_list_clear(mal_pair_list_t * self);

// destructor, free the list, its content and its elements
void mal_pair_list_destroy(mal_pair_list_t ** self_p);

// fields accessors for composite list mal_pair_list
unsigned int mal_pair_list_get_element_count(mal_pair_list_t * self);
mal_pair_t ** mal_pair_list_get_content(mal_pair_list_t * self);

// encoding functions related to transport malbinary
int mal_pair_list_add_encoding_length_malbinary(mal_pair_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_list_encode_malbinary(mal_pair_list_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_list_decode_malbinary(mal_pair_list_t * self, mal_decoder_t * mal_decoder, void * cursor);

// test function
void mal_pair_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_PAIR_LIST_H_INCLUDED__
