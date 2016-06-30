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

#ifndef __MAL_ENTITYREQUEST_H_INCLUDED__
#define __MAL_ENTITYREQUEST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_entityrequest
mal_identifier_list_t * mal_entityrequest_get_subdomain(mal_entityrequest_t * self);
void mal_entityrequest_set_subdomain(mal_entityrequest_t * self, mal_identifier_list_t * subdomain);
mal_boolean_t mal_entityrequest_get_allareas(mal_entityrequest_t * self);
void mal_entityrequest_set_allareas(mal_entityrequest_t * self, mal_boolean_t allareas);
mal_boolean_t mal_entityrequest_get_allservices(mal_entityrequest_t * self);
void mal_entityrequest_set_allservices(mal_entityrequest_t * self, mal_boolean_t allservices);
mal_boolean_t mal_entityrequest_get_alloperations(mal_entityrequest_t * self);
void mal_entityrequest_set_alloperations(mal_entityrequest_t * self, mal_boolean_t alloperations);
mal_boolean_t mal_entityrequest_get_onlyonchange(mal_entityrequest_t * self);
void mal_entityrequest_set_onlyonchange(mal_entityrequest_t * self, mal_boolean_t onlyonchange);
mal_entitykey_list_t * mal_entityrequest_get_entitykeys(mal_entityrequest_t * self);
void mal_entityrequest_set_entitykeys(mal_entityrequest_t * self, mal_entitykey_list_t * entitykeys);

// default constructor
mal_entityrequest_t * mal_entityrequest_new(void);

// encoding functions related to transport malbinary
int mal_entityrequest_add_encoding_length_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entityrequest_encode_malbinary(mal_entityrequest_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_entityrequest_decode_malbinary(mal_entityrequest_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_entityrequest_destroy(mal_entityrequest_t ** self_p);

// test function
void mal_entityrequest_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_ENTITYREQUEST_H_INCLUDED__
