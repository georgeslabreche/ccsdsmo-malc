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

#ifndef __MAL_FILE_H_INCLUDED__
#define __MAL_FILE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite mal_file
mal_identifier_t * mal_file_get_name(mal_file_t * self);
void mal_file_set_name(mal_file_t * self, mal_identifier_t * name);
mal_string_t * mal_file_get_mimetype(mal_file_t * self);
void mal_file_set_mimetype(mal_file_t * self, mal_string_t * mimetype);
bool mal_file_creationdate_is_present(mal_file_t * self);
void mal_file_creationdate_set_present(mal_file_t * self, bool is_present);
mal_time_t mal_file_get_creationdate(mal_file_t * self);
void mal_file_set_creationdate(mal_file_t * self, mal_time_t creationdate);
bool mal_file_modificationdate_is_present(mal_file_t * self);
void mal_file_modificationdate_set_present(mal_file_t * self, bool is_present);
mal_time_t mal_file_get_modificationdate(mal_file_t * self);
void mal_file_set_modificationdate(mal_file_t * self, mal_time_t modificationdate);
bool mal_file_size_is_present(mal_file_t * self);
void mal_file_size_set_present(mal_file_t * self, bool is_present);
mal_ulong_t mal_file_get_size(mal_file_t * self);
void mal_file_set_size(mal_file_t * self, mal_ulong_t size);
mal_blob_t * mal_file_get_content(mal_file_t * self);
void mal_file_set_content(mal_file_t * self, mal_blob_t * content);
mal_namedvalue_list_t * mal_file_get_metadata(mal_file_t * self);
void mal_file_set_metadata(mal_file_t * self, mal_namedvalue_list_t * metadata);

// default constructor
mal_file_t * mal_file_new(void);

// encoding functions related to transport malbinary
int mal_file_add_encoding_length_malbinary(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_file_encode_malbinary(mal_file_t * self, mal_encoder_t * mal_encoder, void * cursor);
int mal_file_decode_malbinary(mal_file_t * self, mal_decoder_t * mal_decoder, void * cursor);

// destructor
void mal_file_destroy(mal_file_t ** self_p);

// test function
void mal_file_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MAL_FILE_H_INCLUDED__
