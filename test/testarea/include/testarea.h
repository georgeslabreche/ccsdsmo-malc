/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 - 2017 CNES
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

#ifndef __TESTAREA_H_INCLUDED__
#define __TESTAREA_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define TEST_SPLIT (false)
#define TEST_TCP (false)

// standard area identifiers
#define TESTAREA_AREA_NUMBER 200
#define TESTAREA_AREA_VERSION 1

// generated code for enumeration testarea_testenumeration
typedef enum {
  TESTAREA_TESTENUMERATION_FIRST,
  TESTAREA_TESTENUMERATION_SECOND,
  TESTAREA_TESTENUMERATION_LAST
} testarea_testenumeration_t;

// short form for enumeration type testarea_testenumeration
#define TESTAREA_TESTENUMERATION_SHORT_FORM 0xc8000001000002L

// short form for list of enumeration type testarea_testenumeration
#define TESTAREA_TESTENUMERATION_LIST_SHORT_FORM 0xc8000001fffffeL

// standard service identifiers
#define TESTAREA_TESTSERVICE_SERVICE_NUMBER 1

// generated code for composite TestArea:TestService:TestComposite
// short form for composite type TestArea:TestService:TestComposite
#define TESTAREA_TESTSERVICE_TESTCOMPOSITE_SHORT_FORM 0xc8000101000001L

// short form for list of composite type TestArea:TestService:TestComposite
#define TESTAREA_TESTSERVICE_TESTCOMPOSITE_LIST_SHORT_FORM 0xc8000101ffffffL

// generated code for composite TestArea:TestService:TestFullComposite
// short form for composite type TestArea:TestService:TestFullComposite
#define TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_SHORT_FORM 0xc8000101000002L

// short form for list of composite type TestArea:TestService:TestFullComposite
#define TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_LIST_SHORT_FORM 0xc8000101fffffeL

// generated code for composite TestArea:TestService:TestUpdate
// short form for composite type TestArea:TestService:TestUpdate
#define TESTAREA_TESTSERVICE_TESTUPDATE_SHORT_FORM 0xc8000101000003L

// short form for list of composite type TestArea:TestService:TestUpdate
#define TESTAREA_TESTSERVICE_TESTUPDATE_LIST_SHORT_FORM 0xc8000101fffffdL

// generated code for composite TestArea:TestService:TestFinalCompositeA
// short form for composite type TestArea:TestService:TestFinalCompositeA
#define TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM 0xc8000101000004L

// short form for list of composite type TestArea:TestService:TestFinalCompositeA
#define TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_LIST_SHORT_FORM 0xc8000101fffffcL

// generated code for composite TestArea:TestService:TestFinalCompositeB
// short form for composite type TestArea:TestService:TestFinalCompositeB
#define TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_SHORT_FORM 0xc8000101000005L

// short form for list of composite type TestArea:TestService:TestFinalCompositeB
#define TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_LIST_SHORT_FORM 0xc8000101fffffbL

#include "testarea_library.h"

int testarea_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// include required areas definitions
#include "com.h"

// generated code for composite TestArea:TestService:TestComposite

// generated code for composite TestArea:TestService:TestFullComposite

// generated code for composite TestArea:TestService:TestUpdate

// generated code for composite TestArea:TestService:TestFinalCompositeA

// generated code for composite TestArea:TestService:TestFinalCompositeB

// generated code for operation testarea_testservice_testsend
#define TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER 1
int testarea_testservice_testsend_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testsend_send_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int testarea_testservice_testsend_send_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int testarea_testservice_testsend_send_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testcomposite_t ** element_res);
int testarea_testservice_testsend_send_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testsend_send_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testsend_send_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int testarea_testservice_testsend_send_decode_2(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation testarea_testservice_testsubmit
#define TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER 2
int testarea_testservice_testsubmit_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testsubmit_submit_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int testarea_testservice_testsubmit_submit_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int testarea_testservice_testsubmit_submit_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testcomposite_t ** element_res);
int testarea_testservice_testsubmit_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testsubmit_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testsubmit_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testsubmit_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);

// generated code for operation testarea_testservice_testrequest
#define TESTAREA_TESTSERVICE_TESTREQUEST_OPERATION_NUMBER 3
int testarea_testservice_testrequest_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testrequest_request_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int testarea_testservice_testrequest_request_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int testarea_testservice_testrequest_request_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testcomposite_t ** element_res);
int testarea_testservice_testrequest_request_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testrequest_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testrequest_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testrequest_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testrequest_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testrequest_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testrequest_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);

// generated code for operation testarea_testservice_testinvoke
#define TESTAREA_TESTSERVICE_TESTINVOKE_OPERATION_NUMBER 4
int testarea_testservice_testinvoke_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testinvoke_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testinvoke_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testinvoke_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testinvoke_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testinvoke_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testinvoke_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testinvoke_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testinvoke_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);

// generated code for operation testarea_testservice_testprogress
#define TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER 5
int testarea_testservice_testprogress_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testprogress_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testprogress_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testprogress_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testprogress_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testprogress_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testprogress_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testprogress_progress_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testprogress_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testprogress_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);

// generated code for operation testarea_testservice_testmonitor
#define TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER 6
int testarea_testservice_testmonitor_update_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int testarea_testservice_testmonitor_update_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int testarea_testservice_testmonitor_update_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testupdate_list_t ** element_res);
int testarea_testservice_testmonitor_update_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int testarea_testservice_testmonitor_update_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int testarea_testservice_testmonitor_update_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int testarea_testservice_testmonitor_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int testarea_testservice_testmonitor_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int testarea_testservice_testmonitor_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int testarea_testservice_testmonitor_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int testarea_testservice_testmonitor_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation testarea_testservice_testinvokealltypes
#define TESTAREA_TESTSERVICE_TESTINVOKEALLTYPES_OPERATION_NUMBER 7
int testarea_testservice_testinvokealltypes_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testinvokealltypes_invoke_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int testarea_testservice_testinvokealltypes_invoke_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int testarea_testservice_testinvokealltypes_invoke_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testfullcomposite_t ** element_res);
int testarea_testservice_testinvokealltypes_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testinvokealltypes_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int testarea_testservice_testinvokealltypes_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int testarea_testservice_testinvokealltypes_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int testarea_testservice_testinvokealltypes_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, testarea_testservice_testfullcomposite_t ** element_res);

// generated code for operation testarea_testservice_testcrossref
#define TESTAREA_TESTSERVICE_TESTCROSSREF_OPERATION_NUMBER 8
int testarea_testservice_testcrossref_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int testarea_testservice_testcrossref_send_add_encoding_length_0(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int testarea_testservice_testcrossref_send_encode_0(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int testarea_testservice_testcrossref_send_decode_0(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_t ** element_res);

// test function
void testarea_test(bool verbose);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TESTAREA_H_INCLUDED__
