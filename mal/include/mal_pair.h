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

#ifndef __MAL_PAIR_H_INCLUDED__
#define __MAL_PAIR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_pair
bool mal_pair_first_is_present(mal_pair_t * self);
void mal_pair_first_set_present(mal_pair_t * self, bool is_present);
unsigned char mal_pair_first_get_attribute_tag(mal_pair_t * self);
void mal_pair_first_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag);
bool mal_pair_second_is_present(mal_pair_t * self);
void mal_pair_second_set_present(mal_pair_t * self, bool is_present);
unsigned char mal_pair_second_get_attribute_tag(mal_pair_t * self);
void mal_pair_second_set_attribute_tag(mal_pair_t * self, unsigned char attribute_tag);

// default constructor
mal_pair_t * mal_pair_new(void);

// encoding functions related to transport malbinary
int mal_pair_add_encoding_length_malbinary(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_encode_malbinary(mal_pair_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_pair_decode_malbinary(mal_pair_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_pair_destroy(mal_pair_t ** self_p);

// test function
void mal_pair_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_PAIR_H_INCLUDED__
