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
#ifndef __COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_H_INCLUDED__
#define __COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// default constructor
com_archive_expressionoperator_list_t * com_archive_expressionoperator_list_new(unsigned int element_count);

// destructor, free the list and its content
void com_archive_expressionoperator_list_destroy(com_archive_expressionoperator_list_t ** self_p);

// fields accessors for enumeration list com_archive_expressionoperator_list
unsigned int com_archive_expressionoperator_list_get_element_count(com_archive_expressionoperator_list_t * self);
bool * com_archive_expressionoperator_list_get_presence_flags(com_archive_expressionoperator_list_t * self);
com_archive_expressionoperator_t * com_archive_expressionoperator_list_get_content(com_archive_expressionoperator_list_t * self);

// encoding functions related to transport malbinary
int com_archive_expressionoperator_list_add_encoding_length_malbinary(com_archive_expressionoperator_list_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_expressionoperator_list_encode_malbinary(com_archive_expressionoperator_list_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_expressionoperator_list_decode_malbinary(com_archive_expressionoperator_list_t * self, mal_decoder_t * decoder, void * cursor);

// test function
void com_archive_expressionoperator_list_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_H_INCLUDED__
