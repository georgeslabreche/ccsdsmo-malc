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

#ifndef __MAL_UPDATEHEADER_H_INCLUDED__
#define __MAL_UPDATEHEADER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_updateheader
mal_time_t mal_updateheader_get_timestamp(mal_updateheader_t * self);
void mal_updateheader_set_timestamp(mal_updateheader_t * self, mal_time_t timestamp);
mal_uri_t * mal_updateheader_get_sourceuri(mal_updateheader_t * self);
void mal_updateheader_set_sourceuri(mal_updateheader_t * self, mal_uri_t * sourceuri);
mal_updatetype_t mal_updateheader_get_updatetype(mal_updateheader_t * self);
void mal_updateheader_set_updatetype(mal_updateheader_t * self, mal_updatetype_t updatetype);
mal_entitykey_t * mal_updateheader_get_key(mal_updateheader_t * self);
void mal_updateheader_set_key(mal_updateheader_t * self, mal_entitykey_t * key);

// default constructor
mal_updateheader_t * mal_updateheader_new(void);

// encoding functions related to transport malbinary
int mal_updateheader_add_encoding_length_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_updateheader_encode_malbinary(mal_updateheader_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_updateheader_decode_malbinary(mal_updateheader_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_updateheader_destroy(mal_updateheader_t ** self_p);

// test function
void mal_updateheader_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_UPDATEHEADER_H_INCLUDED__
