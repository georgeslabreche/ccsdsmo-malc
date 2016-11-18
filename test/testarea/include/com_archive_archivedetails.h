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
#ifndef __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__
#define __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_archive_archivedetails
mal_long_t com_archive_archivedetails_get_instid(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_instid(com_archive_archivedetails_t * self, mal_long_t f_instid);
com_objectdetails_t * com_archive_archivedetails_get_details(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_details(com_archive_archivedetails_t * self, com_objectdetails_t * f_details);
mal_identifier_t * com_archive_archivedetails_get_network(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_network(com_archive_archivedetails_t * self, mal_identifier_t * f_network);
bool com_archive_archivedetails_timestamp_is_present(com_archive_archivedetails_t * self);
void com_archive_archivedetails_timestamp_set_present(com_archive_archivedetails_t * self, bool is_present);
mal_finetime_t com_archive_archivedetails_get_timestamp(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_timestamp(com_archive_archivedetails_t * self, mal_finetime_t f_timestamp);
mal_uri_t * com_archive_archivedetails_get_provider(com_archive_archivedetails_t * self);
void com_archive_archivedetails_set_provider(com_archive_archivedetails_t * self, mal_uri_t * f_provider);

// default constructor
com_archive_archivedetails_t * com_archive_archivedetails_new(void);

// encoding functions related to transport malbinary
int com_archive_archivedetails_add_encoding_length_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivedetails_encode_malbinary(com_archive_archivedetails_t * self, mal_encoder_t * encoder, void * cursor);
int com_archive_archivedetails_decode_malbinary(com_archive_archivedetails_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_archive_archivedetails_destroy(com_archive_archivedetails_t ** self_p);

// test function
void com_archive_archivedetails_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ARCHIVE_ARCHIVEDETAILS_H_INCLUDED__
