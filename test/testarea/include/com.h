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
#ifndef __COM_H_INCLUDED__
#define __COM_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int com_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define COM_AREA_NUMBER 2
#define COM_AREA_VERSION 1

// generated code for composite COM:_:ObjectType
typedef struct _com_objecttype_t com_objecttype_t;

// short form for composite type COM:_:ObjectType
#define COM_OBJECTTYPE_SHORT_FORM 0x2000001000001L
typedef struct _com_objecttype_list_t com_objecttype_list_t;

// short form for list of composite type COM:_:ObjectType
#define COM_OBJECTTYPE_LIST_SHORT_FORM 0x2000001ffffffL

// generated code for composite COM:_:ObjectKey
typedef struct _com_objectkey_t com_objectkey_t;

// short form for composite type COM:_:ObjectKey
#define COM_OBJECTKEY_SHORT_FORM 0x2000001000002L
typedef struct _com_objectkey_list_t com_objectkey_list_t;

// short form for list of composite type COM:_:ObjectKey
#define COM_OBJECTKEY_LIST_SHORT_FORM 0x2000001fffffeL

// generated code for composite COM:_:ObjectId
typedef struct _com_objectid_t com_objectid_t;

// short form for composite type COM:_:ObjectId
#define COM_OBJECTID_SHORT_FORM 0x2000001000003L
typedef struct _com_objectid_list_t com_objectid_list_t;

// short form for list of composite type COM:_:ObjectId
#define COM_OBJECTID_LIST_SHORT_FORM 0x2000001fffffdL

// generated code for composite COM:_:ObjectDetails
typedef struct _com_objectdetails_t com_objectdetails_t;

// short form for composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_SHORT_FORM 0x2000001000004L
typedef struct _com_objectdetails_list_t com_objectdetails_list_t;

// short form for list of composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_LIST_SHORT_FORM 0x2000001fffffcL

// generated code for composite COM:_:InstanceBooleanPair
typedef struct _com_instancebooleanpair_t com_instancebooleanpair_t;

// short form for composite type COM:_:InstanceBooleanPair
#define COM_INSTANCEBOOLEANPAIR_SHORT_FORM 0x2000001000005L
typedef struct _com_instancebooleanpair_list_t com_instancebooleanpair_list_t;

// short form for list of composite type COM:_:InstanceBooleanPair
#define COM_INSTANCEBOOLEANPAIR_LIST_SHORT_FORM 0x2000001fffffbL

// standard service identifiers
#define COM_EVENT_SERVICE_NUMBER 1

// standard service identifiers
#define COM_ARCHIVE_SERVICE_NUMBER 2

// generated code for enumeration com_archive_expressionoperator
typedef enum {
  COM_ARCHIVE_EXPRESSIONOPERATOR_EQUAL,
  COM_ARCHIVE_EXPRESSIONOPERATOR_DIFFER,
  COM_ARCHIVE_EXPRESSIONOPERATOR_GREATER,
  COM_ARCHIVE_EXPRESSIONOPERATOR_GREATER_OR_EQUAL,
  COM_ARCHIVE_EXPRESSIONOPERATOR_LESS,
  COM_ARCHIVE_EXPRESSIONOPERATOR_LESS_OR_EQUAL,
  COM_ARCHIVE_EXPRESSIONOPERATOR_CONTAINS,
  COM_ARCHIVE_EXPRESSIONOPERATOR_ICONTAINS
} com_archive_expressionoperator_t;

// short form for enumeration type com_archive_expressionoperator
#define COM_ARCHIVE_EXPRESSIONOPERATOR_SHORT_FORM 0x2000201000005L
typedef struct _com_archive_expressionoperator_list_t com_archive_expressionoperator_list_t;

// short form for list of enumeration type com_archive_expressionoperator
#define COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM 0x2000201fffffbL

// generated code for composite COM:Archive:ArchiveDetails
typedef struct _com_archive_archivedetails_t com_archive_archivedetails_t;

// short form for composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM 0x2000201000001L
typedef struct _com_archive_archivedetails_list_t com_archive_archivedetails_list_t;

// short form for list of composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM 0x2000201ffffffL

// generated code for composite COM:Archive:ArchiveQuery
typedef struct _com_archive_archivequery_t com_archive_archivequery_t;

// short form for composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM 0x2000201000002L
typedef struct _com_archive_archivequery_list_t com_archive_archivequery_list_t;

// short form for list of composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM 0x2000201fffffeL

// generated code for composite COM:Archive:CompositeFilter
typedef struct _com_archive_compositefilter_t com_archive_compositefilter_t;

// short form for composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM 0x2000201000003L
typedef struct _com_archive_compositefilter_list_t com_archive_compositefilter_list_t;

// short form for list of composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM 0x2000201fffffdL

// generated code for composite COM:Archive:CompositeFilterSet
typedef struct _com_archive_compositefilterset_t com_archive_compositefilterset_t;

// short form for composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM 0x2000201000004L
typedef struct _com_archive_compositefilterset_list_t com_archive_compositefilterset_list_t;

// short form for list of composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM 0x2000201fffffcL

// standard service identifiers
#define COM_ACTIVITYTRACKING_SERVICE_NUMBER 3

// generated code for composite COM:ActivityTracking:ActivityTransfer
typedef struct _com_activitytracking_activitytransfer_t com_activitytracking_activitytransfer_t;

// short form for composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM 0x2000301000001L
typedef struct _com_activitytracking_activitytransfer_list_t com_activitytracking_activitytransfer_list_t;

// short form for list of composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM 0x2000301ffffffL

// generated code for composite COM:ActivityTracking:ActivityAcceptance
typedef struct _com_activitytracking_activityacceptance_t com_activitytracking_activityacceptance_t;

// short form for composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM 0x2000301000002L
typedef struct _com_activitytracking_activityacceptance_list_t com_activitytracking_activityacceptance_list_t;

// short form for list of composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM 0x2000301fffffeL

// generated code for composite COM:ActivityTracking:ActivityExecution
typedef struct _com_activitytracking_activityexecution_t com_activitytracking_activityexecution_t;

// short form for composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM 0x2000301000003L
typedef struct _com_activitytracking_activityexecution_list_t com_activitytracking_activityexecution_list_t;

// short form for list of composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM 0x2000301fffffdL

// generated code for composite COM:ActivityTracking:OperationActivity
typedef struct _com_activitytracking_operationactivity_t com_activitytracking_operationactivity_t;

// short form for composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM 0x2000301000004L
typedef struct _com_activitytracking_operationactivity_list_t com_activitytracking_operationactivity_list_t;

// short form for list of composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM 0x2000301fffffcL

// include required areas definitions
#include "testarea.h"

// generated code for composite COM:_:ObjectType

// generated code for composite COM:_:ObjectKey

// generated code for composite COM:_:ObjectId

// generated code for composite COM:_:ObjectDetails

// generated code for composite COM:_:InstanceBooleanPair

// generated code for operation com_event_monitorevent
#define COM_EVENT_MONITOREVENT_OPERATION_NUMBER 1
int com_event_monitorevent_update_add_encoding_length_0(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_0(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_event_monitorevent_update_decode_0(void * cursor, mal_decoder_t * decoder, com_objectdetails_list_t ** element_res);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_event_monitorevent_update_add_encoding_length_1_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_event_monitorevent_update_add_encoding_length_1_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_event_monitorevent_update_encode_1_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_event_monitorevent_update_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_event_monitorevent_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int com_event_monitorevent_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for composite COM:Archive:ArchiveDetails

// generated code for composite COM:Archive:ArchiveQuery

// generated code for composite COM:Archive:CompositeFilter

// generated code for composite COM:Archive:CompositeFilterSet

// generated code for operation com_archive_retrieve
#define COM_ARCHIVE_RETRIEVE_OPERATION_NUMBER 1
int com_archive_retrieve_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_retrieve_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_retrieve_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_retrieve_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_retrieve_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_retrieve_invoke_add_encoding_length_2(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_2(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_retrieve_invoke_decode_2(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_retrieve_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_retrieve_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_retrieve_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_retrieve_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_retrieve_invoke_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_retrieve_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_retrieve_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_retrieve_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_query
#define COM_ARCHIVE_QUERY_OPERATION_NUMBER 2
int com_archive_query_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_query_progress_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_query_progress_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_query_progress_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int com_archive_query_progress_add_encoding_length_1(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_encode_1(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_decode_1(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_query_progress_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_query_progress_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivequery_list_t ** element_res);
int com_archive_query_progress_add_encoding_length_3_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_query_progress_encode_3_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_query_progress_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_update_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_update_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_query_progress_update_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_update_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_query_progress_update_add_encoding_length_3_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_query_progress_update_add_encoding_length_3_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_query_progress_update_encode_3_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_query_progress_update_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_response_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_response_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_query_progress_response_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_response_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_query_progress_response_add_encoding_length_3_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_query_progress_response_add_encoding_length_3_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_query_progress_response_encode_3_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_query_progress_response_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_query_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_query_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_count
#define COM_ARCHIVE_COUNT_OPERATION_NUMBER 3
int com_archive_count_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_count_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_count_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_count_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_count_invoke_add_encoding_length_1(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_count_invoke_encode_1(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_count_invoke_decode_1(void * cursor, mal_decoder_t * decoder, com_archive_archivequery_list_t ** element_res);
int com_archive_count_invoke_add_encoding_length_2_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_count_invoke_encode_2_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_count_invoke_decode_2(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_count_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_count_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_count_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_count_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_count_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_count_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_count_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_count_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_store
#define COM_ARCHIVE_STORE_OPERATION_NUMBER 4
int com_archive_store_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_store_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_store_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_store_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int com_archive_store_request_add_encoding_length_1(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_store_request_encode_1(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_store_request_decode_1(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_store_request_add_encoding_length_2(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_store_request_encode_2(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_store_request_decode_2(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_store_request_add_encoding_length_3(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_3(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_store_request_decode_3(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_store_request_encode_4_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_store_request_encode_4_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_store_request_add_encoding_length_4_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_store_request_encode_4_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_store_request_add_encoding_length_4_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_store_request_encode_4_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_store_request_add_encoding_length_4_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_store_request_add_encoding_length_4_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_store_request_encode_4_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_store_request_add_encoding_length_4_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_store_request_encode_4_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_store_request_add_encoding_length_4_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_store_request_encode_4_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_store_request_add_encoding_length_4_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_store_request_add_encoding_length_4_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_store_request_add_encoding_length_4_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_store_request_encode_4_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_store_request_add_encoding_length_4_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_store_request_encode_4_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_store_request_add_encoding_length_4_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_store_request_add_encoding_length_4_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_store_request_add_encoding_length_4_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_store_request_encode_4_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_store_request_add_encoding_length_4_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_store_request_encode_4_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_store_request_add_encoding_length_4_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_store_request_encode_4_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_store_request_add_encoding_length_4_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_store_request_add_encoding_length_4_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_store_request_encode_4_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_store_request_add_encoding_length_4_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_store_request_add_encoding_length_4_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_store_request_encode_4_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_store_request_add_encoding_length_4_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_store_request_encode_4_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_store_request_add_encoding_length_4_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_store_request_encode_4_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_store_request_add_encoding_length_4_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_store_request_add_encoding_length_4_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_store_request_add_encoding_length_4_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_store_request_encode_4_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_store_request_add_encoding_length_4_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_store_request_encode_4_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_store_request_add_encoding_length_4_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_store_request_encode_4_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_store_request_add_encoding_length_4_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_store_request_encode_4_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_store_request_add_encoding_length_4_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_store_request_add_encoding_length_4_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_store_request_encode_4_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_store_request_add_encoding_length_4_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_store_request_add_encoding_length_4_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_store_request_add_encoding_length_4_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_store_request_encode_4_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_store_request_encode_4_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_store_request_add_encoding_length_4_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_store_request_encode_4_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_store_request_decode_4(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_store_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_store_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_store_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_store_error_add_encoding_length_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_store_error_add_encoding_length_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_store_error_encode_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_store_error_add_encoding_length_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_store_error_add_encoding_length_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_store_error_add_encoding_length_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_store_error_add_encoding_length_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_store_error_add_encoding_length_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_store_error_add_encoding_length_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_store_error_add_encoding_length_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_store_error_add_encoding_length_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_store_error_add_encoding_length_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_store_error_encode_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_store_error_add_encoding_length_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_store_error_encode_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_store_error_add_encoding_length_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_store_error_encode_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_store_error_add_encoding_length_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_store_error_encode_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_store_error_add_encoding_length_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_store_error_encode_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_store_error_add_encoding_length_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_store_error_encode_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_store_error_add_encoding_length_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_store_error_encode_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_store_error_add_encoding_length_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_store_error_encode_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_store_error_add_encoding_length_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_store_error_encode_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_store_error_add_encoding_length_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_store_error_encode_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_store_error_add_encoding_length_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_store_error_encode_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_store_error_add_encoding_length_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_store_error_encode_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_store_error_add_encoding_length_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_store_error_add_encoding_length_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_store_error_encode_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_store_error_add_encoding_length_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_store_error_add_encoding_length_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_store_error_encode_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_store_error_add_encoding_length_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_store_error_add_encoding_length_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_store_error_encode_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_store_error_add_encoding_length_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_store_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_store_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_store_error_add_encoding_length_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_store_error_add_encoding_length_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_store_error_encode_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_store_error_add_encoding_length_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_store_error_add_encoding_length_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_store_error_encode_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_store_error_add_encoding_length_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_store_error_add_encoding_length_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_store_error_encode_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_store_error_add_encoding_length_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_store_error_add_encoding_length_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_store_error_encode_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_store_error_add_encoding_length_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_store_error_add_encoding_length_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_store_error_encode_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_store_error_add_encoding_length_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_store_error_add_encoding_length_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_store_error_encode_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_store_error_add_encoding_length_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_store_error_add_encoding_length_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_store_error_encode_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_store_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_store_error_add_encoding_length_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_store_error_encode_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_store_error_add_encoding_length_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_store_error_add_encoding_length_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_store_error_encode_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_store_error_add_encoding_length_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_store_error_add_encoding_length_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_store_error_encode_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_store_error_add_encoding_length_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_store_error_add_encoding_length_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_store_error_encode_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_store_error_add_encoding_length_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_store_error_add_encoding_length_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_store_error_encode_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_store_error_add_encoding_length_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_store_error_add_encoding_length_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_store_error_encode_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_store_error_add_encoding_length_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_store_error_add_encoding_length_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_store_error_encode_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_store_error_add_encoding_length_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_store_error_add_encoding_length_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_store_error_encode_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_store_error_add_encoding_length_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_store_error_add_encoding_length_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_store_error_encode_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_store_error_add_encoding_length_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_store_error_add_encoding_length_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_store_error_encode_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_store_error_add_encoding_length_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_store_error_add_encoding_length_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_store_error_encode_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_store_error_add_encoding_length_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_store_error_add_encoding_length_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_store_error_encode_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_store_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_store_error_add_encoding_length_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_store_error_encode_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_store_error_add_encoding_length_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_store_error_add_encoding_length_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_store_error_encode_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_store_error_add_encoding_length_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_store_error_add_encoding_length_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_store_error_encode_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_store_error_add_encoding_length_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_store_error_add_encoding_length_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_store_error_encode_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_store_error_add_encoding_length_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_store_error_add_encoding_length_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_store_error_encode_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_store_error_add_encoding_length_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_store_error_add_encoding_length_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_store_error_encode_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_store_error_add_encoding_length_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_store_error_add_encoding_length_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_store_error_encode_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_store_error_add_encoding_length_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_store_error_encode_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_store_error_add_encoding_length_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_store_error_encode_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_store_error_add_encoding_length_mal_attribute(mal_encoder_t * encoder, bool presence_flag, unsigned char attribute_tag, union mal_attribute_t element, void * cursor);
int com_archive_store_error_encode_mal_attribute(void * cursor, mal_encoder_t * encoder, bool presence_flag, unsigned char attribute_tag, union mal_attribute_t element);
int com_archive_store_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_update
#define COM_ARCHIVE_UPDATE_OPERATION_NUMBER 5
int com_archive_update_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_update_submit_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_update_submit_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_update_submit_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_update_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_update_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_update_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_update_submit_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_update_submit_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_update_submit_add_encoding_length_3_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_update_submit_add_encoding_length_3_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_update_submit_add_encoding_length_3_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_update_submit_add_encoding_length_3_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_update_submit_add_encoding_length_3_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_update_submit_add_encoding_length_3_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_update_submit_add_encoding_length_3_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_update_submit_add_encoding_length_3_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_update_submit_add_encoding_length_3_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_update_submit_add_encoding_length_3_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_update_submit_add_encoding_length_3_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_update_submit_add_encoding_length_3_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_update_submit_add_encoding_length_3_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_update_submit_add_encoding_length_3_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_update_submit_add_encoding_length_3_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_update_submit_add_encoding_length_3_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_update_submit_add_encoding_length_3_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_update_submit_add_encoding_length_3_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_update_submit_encode_3_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_update_submit_add_encoding_length_3_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_update_submit_encode_3_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_update_submit_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_update_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_update_error_add_encoding_length_com_activitytracking_activityacceptance_list(mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activityacceptance_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_list_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_activityacceptance(mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activityacceptance(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityacceptance_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_activityexecution_list(mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activityexecution_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_list_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_activityexecution(mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activityexecution(void * cursor, mal_encoder_t * encoder, com_activitytracking_activityexecution_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_activitytransfer_list(mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activitytransfer_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_list_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_activitytransfer(mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_activitytransfer(void * cursor, mal_encoder_t * encoder, com_activitytracking_activitytransfer_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_operationactivity_list(mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_operationactivity_list(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_list_t * element);
int com_archive_update_error_add_encoding_length_com_activitytracking_operationactivity(mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element, void * cursor);
int com_archive_update_error_encode_com_activitytracking_operationactivity(void * cursor, mal_encoder_t * encoder, com_activitytracking_operationactivity_t * element);
int com_archive_update_error_add_encoding_length_com_archive_archivedetails_list(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_archivedetails_list(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_update_error_add_encoding_length_com_archive_archivedetails(mal_encoder_t * encoder, com_archive_archivedetails_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_archivedetails(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_t * element);
int com_archive_update_error_add_encoding_length_com_archive_archivequery_list(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_archivequery_list(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_update_error_add_encoding_length_com_archive_archivequery(mal_encoder_t * encoder, com_archive_archivequery_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_archivequery(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_t * element);
int com_archive_update_error_add_encoding_length_com_archive_compositefilter_list(mal_encoder_t * encoder, com_archive_compositefilter_list_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_compositefilter_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_list_t * element);
int com_archive_update_error_add_encoding_length_com_archive_compositefilter(mal_encoder_t * encoder, com_archive_compositefilter_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_compositefilter(void * cursor, mal_encoder_t * encoder, com_archive_compositefilter_t * element);
int com_archive_update_error_add_encoding_length_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_update_error_add_encoding_length_com_archive_compositefilterset(mal_encoder_t * encoder, com_archive_compositefilterset_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_compositefilterset(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_t * element);
int com_archive_update_error_add_encoding_length_com_archive_expressionoperator_list(mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element, void * cursor);
int com_archive_update_error_encode_com_archive_expressionoperator_list(void * cursor, mal_encoder_t * encoder, com_archive_expressionoperator_list_t * element);
int com_archive_update_error_add_encoding_length_com_archive_expressionoperator(mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element, void * cursor);
int com_archive_update_error_encode_com_archive_expressionoperator(void * cursor, mal_encoder_t * encoder, bool presence_flag, com_archive_expressionoperator_t element);
int com_archive_update_error_add_encoding_length_com_instancebooleanpair_list(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int com_archive_update_error_encode_com_instancebooleanpair_list(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int com_archive_update_error_add_encoding_length_com_instancebooleanpair(mal_encoder_t * encoder, com_instancebooleanpair_t * element, void * cursor);
int com_archive_update_error_encode_com_instancebooleanpair(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_t * element);
int com_archive_update_error_add_encoding_length_com_objectdetails_list(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int com_archive_update_error_encode_com_objectdetails_list(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int com_archive_update_error_add_encoding_length_com_objectdetails(mal_encoder_t * encoder, com_objectdetails_t * element, void * cursor);
int com_archive_update_error_encode_com_objectdetails(void * cursor, mal_encoder_t * encoder, com_objectdetails_t * element);
int com_archive_update_error_add_encoding_length_com_objectid_list(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int com_archive_update_error_encode_com_objectid_list(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int com_archive_update_error_add_encoding_length_com_objectid(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int com_archive_update_error_encode_com_objectid(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int com_archive_update_error_add_encoding_length_com_objectkey_list(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int com_archive_update_error_encode_com_objectkey_list(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int com_archive_update_error_add_encoding_length_com_objectkey(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int com_archive_update_error_encode_com_objectkey(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int com_archive_update_error_add_encoding_length_com_objecttype_list(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archive_update_error_encode_com_objecttype_list(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archive_update_error_add_encoding_length_com_objecttype(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_update_error_encode_com_objecttype(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_update_error_add_encoding_length_mal_blob_list(mal_encoder_t * encoder, mal_blob_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_blob_list(void * cursor, mal_encoder_t * encoder, mal_blob_list_t * element);
int com_archive_update_error_add_encoding_length_mal_blob(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archive_update_error_encode_mal_blob(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archive_update_error_add_encoding_length_mal_boolean_list(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_boolean_list(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int com_archive_update_error_add_encoding_length_mal_boolean(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_update_error_encode_mal_boolean(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_update_error_add_encoding_length_mal_double_list(mal_encoder_t * encoder, mal_double_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_double_list(void * cursor, mal_encoder_t * encoder, mal_double_list_t * element);
int com_archive_update_error_add_encoding_length_mal_double(mal_encoder_t * encoder, bool presence_flag, mal_double_t element, void * cursor);
int com_archive_update_error_encode_mal_double(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_double_t element);
int com_archive_update_error_add_encoding_length_mal_duration_list(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_duration_list(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int com_archive_update_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int com_archive_update_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int com_archive_update_error_add_encoding_length_mal_entitykey_list(mal_encoder_t * encoder, mal_entitykey_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_entitykey_list(void * cursor, mal_encoder_t * encoder, mal_entitykey_list_t * element);
int com_archive_update_error_add_encoding_length_mal_entitykey(mal_encoder_t * encoder, mal_entitykey_t * element, void * cursor);
int com_archive_update_error_encode_mal_entitykey(void * cursor, mal_encoder_t * encoder, mal_entitykey_t * element);
int com_archive_update_error_add_encoding_length_mal_entityrequest_list(mal_encoder_t * encoder, mal_entityrequest_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_entityrequest_list(void * cursor, mal_encoder_t * encoder, mal_entityrequest_list_t * element);
int com_archive_update_error_add_encoding_length_mal_entityrequest(mal_encoder_t * encoder, mal_entityrequest_t * element, void * cursor);
int com_archive_update_error_encode_mal_entityrequest(void * cursor, mal_encoder_t * encoder, mal_entityrequest_t * element);
int com_archive_update_error_add_encoding_length_mal_file_list(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_file_list(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int com_archive_update_error_add_encoding_length_mal_file(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int com_archive_update_error_encode_mal_file(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int com_archive_update_error_add_encoding_length_mal_finetime_list(mal_encoder_t * encoder, mal_finetime_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_finetime_list(void * cursor, mal_encoder_t * encoder, mal_finetime_list_t * element);
int com_archive_update_error_add_encoding_length_mal_finetime(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archive_update_error_encode_mal_finetime(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archive_update_error_add_encoding_length_mal_float_list(mal_encoder_t * encoder, mal_float_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_float_list(void * cursor, mal_encoder_t * encoder, mal_float_list_t * element);
int com_archive_update_error_add_encoding_length_mal_float(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int com_archive_update_error_encode_mal_float(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int com_archive_update_error_add_encoding_length_mal_idbooleanpair_list(mal_encoder_t * encoder, mal_idbooleanpair_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_idbooleanpair_list(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_list_t * element);
int com_archive_update_error_add_encoding_length_mal_idbooleanpair(mal_encoder_t * encoder, mal_idbooleanpair_t * element, void * cursor);
int com_archive_update_error_encode_mal_idbooleanpair(void * cursor, mal_encoder_t * encoder, mal_idbooleanpair_t * element);
int com_archive_update_error_add_encoding_length_mal_identifier_list(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_identifier_list(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_update_error_add_encoding_length_mal_identifier(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archive_update_error_encode_mal_identifier(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archive_update_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archive_update_error_add_encoding_length_mal_integer(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int com_archive_update_error_encode_mal_integer(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int com_archive_update_error_add_encoding_length_mal_interactiontype_list(mal_encoder_t * encoder, mal_interactiontype_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_interactiontype_list(void * cursor, mal_encoder_t * encoder, mal_interactiontype_list_t * element);
int com_archive_update_error_add_encoding_length_mal_interactiontype(mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element, void * cursor);
int com_archive_update_error_encode_mal_interactiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_interactiontype_t element);
int com_archive_update_error_add_encoding_length_mal_long_list(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_long_list(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_update_error_add_encoding_length_mal_long(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archive_update_error_encode_mal_long(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archive_update_error_add_encoding_length_mal_namedvalue_list(mal_encoder_t * encoder, mal_namedvalue_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_namedvalue_list(void * cursor, mal_encoder_t * encoder, mal_namedvalue_list_t * element);
int com_archive_update_error_add_encoding_length_mal_namedvalue(mal_encoder_t * encoder, mal_namedvalue_t * element, void * cursor);
int com_archive_update_error_encode_mal_namedvalue(void * cursor, mal_encoder_t * encoder, mal_namedvalue_t * element);
int com_archive_update_error_add_encoding_length_mal_octet_list(mal_encoder_t * encoder, mal_octet_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_octet_list(void * cursor, mal_encoder_t * encoder, mal_octet_list_t * element);
int com_archive_update_error_add_encoding_length_mal_octet(mal_encoder_t * encoder, bool presence_flag, mal_octet_t element, void * cursor);
int com_archive_update_error_encode_mal_octet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_octet_t element);
int com_archive_update_error_add_encoding_length_mal_pair_list(mal_encoder_t * encoder, mal_pair_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_pair_list(void * cursor, mal_encoder_t * encoder, mal_pair_list_t * element);
int com_archive_update_error_add_encoding_length_mal_pair(mal_encoder_t * encoder, mal_pair_t * element, void * cursor);
int com_archive_update_error_encode_mal_pair(void * cursor, mal_encoder_t * encoder, mal_pair_t * element);
int com_archive_update_error_add_encoding_length_mal_qoslevel_list(mal_encoder_t * encoder, mal_qoslevel_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_qoslevel_list(void * cursor, mal_encoder_t * encoder, mal_qoslevel_list_t * element);
int com_archive_update_error_add_encoding_length_mal_qoslevel(mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element, void * cursor);
int com_archive_update_error_encode_mal_qoslevel(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_qoslevel_t element);
int com_archive_update_error_add_encoding_length_mal_sessiontype_list(mal_encoder_t * encoder, mal_sessiontype_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_sessiontype_list(void * cursor, mal_encoder_t * encoder, mal_sessiontype_list_t * element);
int com_archive_update_error_add_encoding_length_mal_sessiontype(mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element, void * cursor);
int com_archive_update_error_encode_mal_sessiontype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_sessiontype_t element);
int com_archive_update_error_add_encoding_length_mal_short_list(mal_encoder_t * encoder, mal_short_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_short_list(void * cursor, mal_encoder_t * encoder, mal_short_list_t * element);
int com_archive_update_error_add_encoding_length_mal_short(mal_encoder_t * encoder, bool presence_flag, mal_short_t element, void * cursor);
int com_archive_update_error_encode_mal_short(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_short_t element);
int com_archive_update_error_add_encoding_length_mal_string_list(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_string_list(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archive_update_error_add_encoding_length_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int com_archive_update_error_encode_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int com_archive_update_error_add_encoding_length_mal_subscription_list(mal_encoder_t * encoder, mal_subscription_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_subscription_list(void * cursor, mal_encoder_t * encoder, mal_subscription_list_t * element);
int com_archive_update_error_add_encoding_length_mal_subscription(mal_encoder_t * encoder, mal_subscription_t * element, void * cursor);
int com_archive_update_error_encode_mal_subscription(void * cursor, mal_encoder_t * encoder, mal_subscription_t * element);
int com_archive_update_error_add_encoding_length_mal_time_list(mal_encoder_t * encoder, mal_time_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_time_list(void * cursor, mal_encoder_t * encoder, mal_time_list_t * element);
int com_archive_update_error_add_encoding_length_mal_time(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int com_archive_update_error_encode_mal_time(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int com_archive_update_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_update_error_add_encoding_length_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archive_update_error_encode_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archive_update_error_add_encoding_length_mal_ulong_list(mal_encoder_t * encoder, mal_ulong_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_ulong_list(void * cursor, mal_encoder_t * encoder, mal_ulong_list_t * element);
int com_archive_update_error_add_encoding_length_mal_ulong(mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element, void * cursor);
int com_archive_update_error_encode_mal_ulong(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ulong_t element);
int com_archive_update_error_add_encoding_length_mal_uoctet_list(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_uoctet_list(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int com_archive_update_error_add_encoding_length_mal_uoctet(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int com_archive_update_error_encode_mal_uoctet(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int com_archive_update_error_add_encoding_length_mal_uri_list(mal_encoder_t * encoder, mal_uri_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_uri_list(void * cursor, mal_encoder_t * encoder, mal_uri_list_t * element);
int com_archive_update_error_add_encoding_length_mal_uri(mal_encoder_t * encoder, mal_uri_t * element, void * cursor);
int com_archive_update_error_encode_mal_uri(void * cursor, mal_encoder_t * encoder, mal_uri_t * element);
int com_archive_update_error_add_encoding_length_mal_ushort_list(mal_encoder_t * encoder, mal_ushort_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_ushort_list(void * cursor, mal_encoder_t * encoder, mal_ushort_list_t * element);
int com_archive_update_error_add_encoding_length_mal_ushort(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int com_archive_update_error_encode_mal_ushort(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int com_archive_update_error_add_encoding_length_mal_updateheader_list(mal_encoder_t * encoder, mal_updateheader_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_updateheader_list(void * cursor, mal_encoder_t * encoder, mal_updateheader_list_t * element);
int com_archive_update_error_add_encoding_length_mal_updateheader(mal_encoder_t * encoder, mal_updateheader_t * element, void * cursor);
int com_archive_update_error_encode_mal_updateheader(void * cursor, mal_encoder_t * encoder, mal_updateheader_t * element);
int com_archive_update_error_add_encoding_length_mal_updatetype_list(mal_encoder_t * encoder, mal_updatetype_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_updatetype_list(void * cursor, mal_encoder_t * encoder, mal_updatetype_list_t * element);
int com_archive_update_error_add_encoding_length_mal_updatetype(mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element, void * cursor);
int com_archive_update_error_encode_mal_updatetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_updatetype_t element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testcomposite_list(mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testcomposite(mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testcomposite_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfinalcompositea_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfinalcompositea_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfinalcompositea(mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfinalcompositea(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositea_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfinalcompositeb_list(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfinalcompositeb_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfinalcompositeb(mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfinalcompositeb(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfinalcompositeb_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfullcomposite_list(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfullcomposite_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testfullcomposite(mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testfullcomposite(void * cursor, mal_encoder_t * encoder, testarea_testservice_testfullcomposite_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testupdate_list(mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testupdate_list(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testservice_testupdate(mal_encoder_t * encoder, testarea_testservice_testupdate_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testservice_testupdate(void * cursor, mal_encoder_t * encoder, testarea_testservice_testupdate_t * element);
int com_archive_update_error_add_encoding_length_testarea_testenumeration_list(mal_encoder_t * encoder, testarea_testenumeration_list_t * element, void * cursor);
int com_archive_update_error_encode_testarea_testenumeration_list(void * cursor, mal_encoder_t * encoder, testarea_testenumeration_list_t * element);
int com_archive_update_error_add_encoding_length_testarea_testenumeration(mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element, void * cursor);
int com_archive_update_error_encode_testarea_testenumeration(void * cursor, mal_encoder_t * encoder, bool presence_flag, testarea_testenumeration_t element);
int com_archive_update_error_add_encoding_length_mal_attribute(mal_encoder_t * encoder, bool presence_flag, unsigned char attribute_tag, union mal_attribute_t element, void * cursor);
int com_archive_update_error_encode_mal_attribute(void * cursor, mal_encoder_t * encoder, bool presence_flag, unsigned char attribute_tag, union mal_attribute_t element);
int com_archive_update_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_delete
#define COM_ARCHIVE_DELETE_OPERATION_NUMBER 6
int com_archive_delete_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_delete_request_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_delete_request_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_delete_request_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_delete_request_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_delete_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_delete_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_delete_request_add_encoding_length_2(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_delete_request_encode_2(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_delete_request_decode_2(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_delete_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_delete_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_delete_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_delete_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_delete_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_delete_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_delete_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite COM:ActivityTracking:ActivityTransfer

// generated code for composite COM:ActivityTracking:ActivityAcceptance

// generated code for composite COM:ActivityTracking:ActivityExecution

// generated code for composite COM:ActivityTracking:OperationActivity

// test function
void com_test(bool verbose);

#include "com_objecttype.h"
#include "com_objecttype_list.h"
#include "com_objectkey.h"
#include "com_objectkey_list.h"
#include "com_objectid.h"
#include "com_objectid_list.h"
#include "com_objectdetails.h"
#include "com_objectdetails_list.h"
#include "com_instancebooleanpair.h"
#include "com_instancebooleanpair_list.h"
#include "com_archive_expressionoperator_list.h"
#include "com_archive_archivedetails.h"
#include "com_archive_archivedetails_list.h"
#include "com_archive_archivequery.h"
#include "com_archive_archivequery_list.h"
#include "com_archive_compositefilter.h"
#include "com_archive_compositefilter_list.h"
#include "com_archive_compositefilterset.h"
#include "com_archive_compositefilterset_list.h"
#include "com_activitytracking_activitytransfer.h"
#include "com_activitytracking_activitytransfer_list.h"
#include "com_activitytracking_activityacceptance.h"
#include "com_activitytracking_activityacceptance_list.h"
#include "com_activitytracking_activityexecution.h"
#include "com_activitytracking_activityexecution_list.h"
#include "com_activitytracking_operationactivity.h"
#include "com_activitytracking_operationactivity_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_H_INCLUDED__
