#ifndef __COM_H_INCLUDED__
#define __COM_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int com_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int com_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int com_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define COM_AREA_NUMBER 2
#define COM_AREA_VERSION 129

// generated code for composite COM:_:ObjectType
#ifndef COM_OBJECTTYPE_T_DEFINED
#define COM_OBJECTTYPE_T_DEFINED

typedef struct _com_objecttype_t com_objecttype_t;

#endif // COM_OBJECTTYPE_T_DEFINED

// short form for composite type COM:_:ObjectType
#define COM_OBJECTTYPE_SHORT_FORM 0xffffffff81000001L
#ifndef COM_OBJECTTYPE_LIST_T_DEFINED
#define COM_OBJECTTYPE_LIST_T_DEFINED

typedef struct _com_objecttype_list_t com_objecttype_list_t;

#endif // COM_OBJECTTYPE_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectType
#define COM_OBJECTTYPE_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite COM:_:ObjectKey
#ifndef COM_OBJECTKEY_T_DEFINED
#define COM_OBJECTKEY_T_DEFINED

typedef struct _com_objectkey_t com_objectkey_t;

#endif // COM_OBJECTKEY_T_DEFINED

// short form for composite type COM:_:ObjectKey
#define COM_OBJECTKEY_SHORT_FORM 0xffffffff81000002L
#ifndef COM_OBJECTKEY_LIST_T_DEFINED
#define COM_OBJECTKEY_LIST_T_DEFINED

typedef struct _com_objectkey_list_t com_objectkey_list_t;

#endif // COM_OBJECTKEY_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectKey
#define COM_OBJECTKEY_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite COM:_:ObjectId
#ifndef COM_OBJECTID_T_DEFINED
#define COM_OBJECTID_T_DEFINED

typedef struct _com_objectid_t com_objectid_t;

#endif // COM_OBJECTID_T_DEFINED

// short form for composite type COM:_:ObjectId
#define COM_OBJECTID_SHORT_FORM 0xffffffff81000003L
#ifndef COM_OBJECTID_LIST_T_DEFINED
#define COM_OBJECTID_LIST_T_DEFINED

typedef struct _com_objectid_list_t com_objectid_list_t;

#endif // COM_OBJECTID_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectId
#define COM_OBJECTID_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite COM:_:ObjectDetails
#ifndef COM_OBJECTDETAILS_T_DEFINED
#define COM_OBJECTDETAILS_T_DEFINED

typedef struct _com_objectdetails_t com_objectdetails_t;

#endif // COM_OBJECTDETAILS_T_DEFINED

// short form for composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_SHORT_FORM 0xffffffff81000004L
#ifndef COM_OBJECTDETAILS_LIST_T_DEFINED
#define COM_OBJECTDETAILS_LIST_T_DEFINED

typedef struct _com_objectdetails_list_t com_objectdetails_list_t;

#endif // COM_OBJECTDETAILS_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_LIST_SHORT_FORM 0xffffffff81fffffcL

// generated code for composite COM:_:InstanceBooleanPair
#ifndef COM_INSTANCEBOOLEANPAIR_T_DEFINED
#define COM_INSTANCEBOOLEANPAIR_T_DEFINED

typedef struct _com_instancebooleanpair_t com_instancebooleanpair_t;

#endif // COM_INSTANCEBOOLEANPAIR_T_DEFINED

// short form for composite type COM:_:InstanceBooleanPair
#define COM_INSTANCEBOOLEANPAIR_SHORT_FORM 0xffffffff81000005L
#ifndef COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED
#define COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED

typedef struct _com_instancebooleanpair_list_t com_instancebooleanpair_list_t;

#endif // COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED

// short form for list of composite type COM:_:InstanceBooleanPair
#define COM_INSTANCEBOOLEANPAIR_LIST_SHORT_FORM 0xffffffff81fffffbL

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
#define COM_ARCHIVE_EXPRESSIONOPERATOR_SHORT_FORM 0xffffffff81000005L
#ifndef COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED
#define COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED

typedef struct _com_archive_expressionoperator_list_t com_archive_expressionoperator_list_t;

#endif // COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED

// short form for list of enumeration type com_archive_expressionoperator
#define COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM 0xffffffff81fffffbL

// generated code for composite COM:Archive:ArchiveDetails
#ifndef COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED
#define COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED

typedef struct _com_archive_archivedetails_t com_archive_archivedetails_t;

#endif // COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED

// short form for composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM 0xffffffff81000001L
#ifndef COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED
#define COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED

typedef struct _com_archive_archivedetails_list_t com_archive_archivedetails_list_t;

#endif // COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED

// short form for list of composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite COM:Archive:ArchiveQuery
#ifndef COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED
#define COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED

typedef struct _com_archive_archivequery_t com_archive_archivequery_t;

#endif // COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED

// short form for composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM 0xffffffff81000002L
#ifndef COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED
#define COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED

typedef struct _com_archive_archivequery_list_t com_archive_archivequery_list_t;

#endif // COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED

// short form for list of composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite COM:Archive:CompositeFilter
#ifndef COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED

typedef struct _com_archive_compositefilter_t com_archive_compositefilter_t;

#endif // COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED

// short form for composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM 0xffffffff81000003L
#ifndef COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED

typedef struct _com_archive_compositefilter_list_t com_archive_compositefilter_list_t;

#endif // COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED

// short form for list of composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite COM:Archive:CompositeFilterSet
#ifndef COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED

typedef struct _com_archive_compositefilterset_t com_archive_compositefilterset_t;

#endif // COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED

// short form for composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM 0xffffffff81000004L
#ifndef COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED

typedef struct _com_archive_compositefilterset_list_t com_archive_compositefilterset_list_t;

#endif // COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED

// short form for list of composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM 0xffffffff81fffffcL

// standard service identifiers
#define COM_ACTIVITYTRACKING_SERVICE_NUMBER 3

// generated code for composite COM:ActivityTracking:ActivityTransfer
#ifndef COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED

typedef struct _com_activitytracking_activitytransfer_t com_activitytracking_activitytransfer_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM 0xffffffff81000001L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED

typedef struct _com_activitytracking_activitytransfer_list_t com_activitytracking_activitytransfer_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite COM:ActivityTracking:ActivityAcceptance
#ifndef COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED

typedef struct _com_activitytracking_activityacceptance_t com_activitytracking_activityacceptance_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM 0xffffffff81000002L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED

typedef struct _com_activitytracking_activityacceptance_list_t com_activitytracking_activityacceptance_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite COM:ActivityTracking:ActivityExecution
#ifndef COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED

typedef struct _com_activitytracking_activityexecution_t com_activitytracking_activityexecution_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM 0xffffffff81000003L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED

typedef struct _com_activitytracking_activityexecution_list_t com_activitytracking_activityexecution_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite COM:ActivityTracking:OperationActivity
#ifndef COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED

typedef struct _com_activitytracking_operationactivity_t com_activitytracking_operationactivity_t;

#endif // COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED

// short form for composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM 0xffffffff81000004L
#ifndef COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED

typedef struct _com_activitytracking_operationactivity_list_t com_activitytracking_operationactivity_list_t;

#endif // COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM 0xffffffff81fffffcL

// include required areas definitions
#include "mc.h"
#include "opssat_pf.h"
#include "opssat_std.h"

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
int com_event_monitorevent_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationdefinition_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationdefinition_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationdefinition(mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationdefinition(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationreference_list(mal_encoder_t * encoder, mc_aggregation_aggregationreference_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationreference_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationreference_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationreference(mal_encoder_t * encoder, mc_aggregation_aggregationreference_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationreference(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationreference_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertdefinition_list(mal_encoder_t * encoder, mc_alert_alertdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertdefinition_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertdefinition(mal_encoder_t * encoder, mc_alert_alertdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertdefinition(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertevent_list(mal_encoder_t * encoder, mc_alert_alertevent_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertevent_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertevent_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertevent(mal_encoder_t * encoder, mc_alert_alertevent_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertevent(void * cursor, mal_encoder_t * encoder, mc_alert_alertevent_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklink_list(mal_encoder_t * encoder, mc_check_checklink_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklink_list(void * cursor, mal_encoder_t * encoder, mc_check_checklink_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklink(mal_encoder_t * encoder, mc_check_checklink_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklink(void * cursor, mal_encoder_t * encoder, mc_check_checklink_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checksummary_list(mal_encoder_t * encoder, mc_check_checksummary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checksummary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checksummary(mal_encoder_t * encoder, mc_check_checksummary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checksummary(void * cursor, mal_encoder_t * encoder, mc_check_checksummary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_constantcheck_list(mal_encoder_t * encoder, mc_check_constantcheck_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_constantcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheck_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_constantcheck(mal_encoder_t * encoder, mc_check_constantcheck_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_constantcheck(void * cursor, mal_encoder_t * encoder, mc_check_constantcheck_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_deltacheck_list(mal_encoder_t * encoder, mc_check_deltacheck_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_deltacheck_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheck_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_deltacheck(mal_encoder_t * encoder, mc_check_deltacheck_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_deltacheck(void * cursor, mal_encoder_t * encoder, mc_check_deltacheck_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_limitcheck_list(mal_encoder_t * encoder, mc_check_limitcheck_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_limitcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheck_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_limitcheck(mal_encoder_t * encoder, mc_check_limitcheck_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_limitcheck(void * cursor, mal_encoder_t * encoder, mc_check_limitcheck_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencecheck_list(mal_encoder_t * encoder, mc_check_referencecheck_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencecheck_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheck_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencecheck(mal_encoder_t * encoder, mc_check_referencecheck_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencecheck(void * cursor, mal_encoder_t * encoder, mc_check_referencecheck_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterdefinition_list(mal_encoder_t * encoder, mc_parameter_parameterdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterdefinition_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterdefinition(mal_encoder_t * encoder, mc_parameter_parameterdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterdefinition(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_validity_list(mal_encoder_t * encoder, mc_parameter_validity_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_validity_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validity_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_validity(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validity_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_validity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validity_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentdefinition_list(mal_encoder_t * encoder, mc_argumentdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentdefinition_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentdefinition(mal_encoder_t * encoder, mc_argumentdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentdefinition(void * cursor, mal_encoder_t * encoder, mc_argumentdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentvalue_list(mal_encoder_t * encoder, mc_argumentvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentvalue_list(void * cursor, mal_encoder_t * encoder, mc_argumentvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentvalue(mal_encoder_t * encoder, mc_argumentvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentvalue(void * cursor, mal_encoder_t * encoder, mc_argumentvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conditionalreference_list(mal_encoder_t * encoder, mc_conditionalreference_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conditionalreference_list(void * cursor, mal_encoder_t * encoder, mc_conditionalreference_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conditionalreference(mal_encoder_t * encoder, mc_conditionalreference_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conditionalreference(void * cursor, mal_encoder_t * encoder, mc_conditionalreference_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_coarseadcs_adcsmode_list(mal_encoder_t * encoder, opssat_pf_coarseadcs_adcsmode_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_coarseadcs_adcsmode_list(void * cursor, mal_encoder_t * encoder, opssat_pf_coarseadcs_adcsmode_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_coarseadcs_adcsmode(mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_coarseadcs_adcsmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_coarseadcs_orbittledata_list(mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_coarseadcs_orbittledata_list(void * cursor, mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_coarseadcs_orbittledata(mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_coarseadcs_orbittledata(void * cursor, mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_mode_systemmode_list(mal_encoder_t * encoder, opssat_pf_mode_systemmode_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_mode_systemmode_list(void * cursor, mal_encoder_t * encoder, opssat_pf_mode_systemmode_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_mode_systemmode(mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_mode_systemmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_devices_list(mal_encoder_t * encoder, opssat_pf_devices_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_devices_list(void * cursor, mal_encoder_t * encoder, opssat_pf_devices_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_devices(mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_devices(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_i2cbus_list(mal_encoder_t * encoder, opssat_pf_i2cbus_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_i2cbus_list(void * cursor, mal_encoder_t * encoder, opssat_pf_i2cbus_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_i2cbus(mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_i2cbus(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_onboarddevice_list(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_onboarddevice_list(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_pf_onboarddevice(mal_encoder_t * encoder, bool presence_flag, opssat_pf_onboarddevice_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_pf_onboarddevice(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_onboarddevice_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_filemanagement_fileaccessmode_list(mal_encoder_t * encoder, opssat_std_filemanagement_fileaccessmode_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_filemanagement_fileaccessmode_list(void * cursor, mal_encoder_t * encoder, opssat_std_filemanagement_fileaccessmode_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_filemanagement_fileaccessmode(mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_filemanagement_fileaccessmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memoryblock_list(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memoryblock_list(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memoryblock(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memoryblock(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memorydevice_list(mal_encoder_t * encoder, opssat_std_memorymanagement_memorydevice_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memorydevice_list(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memorydevice_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memorydevice(mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memorydevice(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memoryrange_list(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memoryrange_list(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_memorymanagement_memoryrange(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_memorymanagement_memoryrange(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_listscheduleentry_list(mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_listscheduleentry_list(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_listscheduleentry(mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_listscheduleentry(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_schedule_list(mal_encoder_t * encoder, opssat_std_schedulemanagement_schedule_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_schedule_list(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_schedule_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_schedule(mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_schedule(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_scheduleentry_list(mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_scheduleentry_list(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_opssat_std_schedulemanagement_scheduleentry(mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_opssat_std_schedulemanagement_scheduleentry(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_t * element);
int com_event_monitorevent_update_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_event_monitorevent_update_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_event_monitorevent_update_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_event_monitorevent_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int com_event_monitorevent_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int com_event_monitorevent_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int com_event_monitorevent_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int com_event_monitorevent_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for composite COM:Archive:ArchiveDetails

// generated code for composite COM:Archive:ArchiveQuery

// generated code for composite COM:Archive:CompositeFilter

// generated code for composite COM:Archive:CompositeFilterSet

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
