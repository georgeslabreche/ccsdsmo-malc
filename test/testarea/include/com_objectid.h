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
#ifndef __COM_OBJECTID_H_INCLUDED__
#define __COM_OBJECTID_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_objectid
com_objecttype_t * com_objectid_get_type(com_objectid_t * self);
void com_objectid_set_type(com_objectid_t * self, com_objecttype_t * f_type);
com_objectkey_t * com_objectid_get_key(com_objectid_t * self);
void com_objectid_set_key(com_objectid_t * self, com_objectkey_t * f_key);

// default constructor
com_objectid_t * com_objectid_new(void);

// encoding functions related to transport malbinary
int com_objectid_add_encoding_length_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectid_encode_malbinary(com_objectid_t * self, mal_encoder_t * encoder, void * cursor);
int com_objectid_decode_malbinary(com_objectid_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_objectid_destroy(com_objectid_t ** self_p);

// test function
void com_objectid_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_OBJECTID_H_INCLUDED__
