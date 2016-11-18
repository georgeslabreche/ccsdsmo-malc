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
#ifndef __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__
#define __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// fields accessors for composite com_activitytracking_operationactivity
mal_interactiontype_t com_activitytracking_operationactivity_get_interactiontype(com_activitytracking_operationactivity_t * self);
void com_activitytracking_operationactivity_set_interactiontype(com_activitytracking_operationactivity_t * self, mal_interactiontype_t f_interactiontype);

// default constructor
com_activitytracking_operationactivity_t * com_activitytracking_operationactivity_new(void);

// encoding functions related to transport malbinary
int com_activitytracking_operationactivity_add_encoding_length_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_operationactivity_encode_malbinary(com_activitytracking_operationactivity_t * self, mal_encoder_t * encoder, void * cursor);
int com_activitytracking_operationactivity_decode_malbinary(com_activitytracking_operationactivity_t * self, mal_decoder_t * decoder, void * cursor);

// destructor
void com_activitytracking_operationactivity_destroy(com_activitytracking_operationactivity_t ** self_p);

// test function
void com_activitytracking_operationactivity_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_ACTIVITYTRACKING_OPERATIONACTIVITY_H_INCLUDED__
