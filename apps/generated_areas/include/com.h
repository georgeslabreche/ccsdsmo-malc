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
#define COM_AREA_VERSION 1

// generated code for composite COM:_:ObjectType
#ifndef COM_OBJECTTYPE_T_DEFINED
#define COM_OBJECTTYPE_T_DEFINED

typedef struct _com_objecttype_t com_objecttype_t;

#endif // COM_OBJECTTYPE_T_DEFINED

// short form for composite type COM:_:ObjectType
#define COM_OBJECTTYPE_SHORT_FORM 0x2000001000001L
#ifndef COM_OBJECTTYPE_LIST_T_DEFINED
#define COM_OBJECTTYPE_LIST_T_DEFINED

typedef struct _com_objecttype_list_t com_objecttype_list_t;

#endif // COM_OBJECTTYPE_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectType
#define COM_OBJECTTYPE_LIST_SHORT_FORM 0x2000001ffffffL

// generated code for composite COM:_:ObjectKey
#ifndef COM_OBJECTKEY_T_DEFINED
#define COM_OBJECTKEY_T_DEFINED

typedef struct _com_objectkey_t com_objectkey_t;

#endif // COM_OBJECTKEY_T_DEFINED

// short form for composite type COM:_:ObjectKey
#define COM_OBJECTKEY_SHORT_FORM 0x2000001000002L
#ifndef COM_OBJECTKEY_LIST_T_DEFINED
#define COM_OBJECTKEY_LIST_T_DEFINED

typedef struct _com_objectkey_list_t com_objectkey_list_t;

#endif // COM_OBJECTKEY_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectKey
#define COM_OBJECTKEY_LIST_SHORT_FORM 0x2000001fffffeL

// generated code for composite COM:_:ObjectId
#ifndef COM_OBJECTID_T_DEFINED
#define COM_OBJECTID_T_DEFINED

typedef struct _com_objectid_t com_objectid_t;

#endif // COM_OBJECTID_T_DEFINED

// short form for composite type COM:_:ObjectId
#define COM_OBJECTID_SHORT_FORM 0x2000001000003L
#ifndef COM_OBJECTID_LIST_T_DEFINED
#define COM_OBJECTID_LIST_T_DEFINED

typedef struct _com_objectid_list_t com_objectid_list_t;

#endif // COM_OBJECTID_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectId
#define COM_OBJECTID_LIST_SHORT_FORM 0x2000001fffffdL

// generated code for composite COM:_:ObjectDetails
#ifndef COM_OBJECTDETAILS_T_DEFINED
#define COM_OBJECTDETAILS_T_DEFINED

typedef struct _com_objectdetails_t com_objectdetails_t;

#endif // COM_OBJECTDETAILS_T_DEFINED

// short form for composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_SHORT_FORM 0x2000001000004L
#ifndef COM_OBJECTDETAILS_LIST_T_DEFINED
#define COM_OBJECTDETAILS_LIST_T_DEFINED

typedef struct _com_objectdetails_list_t com_objectdetails_list_t;

#endif // COM_OBJECTDETAILS_LIST_T_DEFINED

// short form for list of composite type COM:_:ObjectDetails
#define COM_OBJECTDETAILS_LIST_SHORT_FORM 0x2000001fffffcL

// generated code for composite COM:_:InstanceBooleanPair
#ifndef COM_INSTANCEBOOLEANPAIR_T_DEFINED
#define COM_INSTANCEBOOLEANPAIR_T_DEFINED

typedef struct _com_instancebooleanpair_t com_instancebooleanpair_t;

#endif // COM_INSTANCEBOOLEANPAIR_T_DEFINED

// short form for composite type COM:_:InstanceBooleanPair
#define COM_INSTANCEBOOLEANPAIR_SHORT_FORM 0x2000001000005L
#ifndef COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED
#define COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED

typedef struct _com_instancebooleanpair_list_t com_instancebooleanpair_list_t;

#endif // COM_INSTANCEBOOLEANPAIR_LIST_T_DEFINED

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
#ifndef COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED
#define COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED

typedef struct _com_archive_expressionoperator_list_t com_archive_expressionoperator_list_t;

#endif // COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_T_DEFINED

// short form for list of enumeration type com_archive_expressionoperator
#define COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM 0x2000201fffffbL

// generated code for composite COM:Archive:ArchiveDetails
#ifndef COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED
#define COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED

typedef struct _com_archive_archivedetails_t com_archive_archivedetails_t;

#endif // COM_ARCHIVE_ARCHIVEDETAILS_T_DEFINED

// short form for composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM 0x2000201000001L
#ifndef COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED
#define COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED

typedef struct _com_archive_archivedetails_list_t com_archive_archivedetails_list_t;

#endif // COM_ARCHIVE_ARCHIVEDETAILS_LIST_T_DEFINED

// short form for list of composite type COM:Archive:ArchiveDetails
#define COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM 0x2000201ffffffL

// generated code for composite COM:Archive:ArchiveQuery
#ifndef COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED
#define COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED

typedef struct _com_archive_archivequery_t com_archive_archivequery_t;

#endif // COM_ARCHIVE_ARCHIVEQUERY_T_DEFINED

// short form for composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM 0x2000201000002L
#ifndef COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED
#define COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED

typedef struct _com_archive_archivequery_list_t com_archive_archivequery_list_t;

#endif // COM_ARCHIVE_ARCHIVEQUERY_LIST_T_DEFINED

// short form for list of composite type COM:Archive:ArchiveQuery
#define COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM 0x2000201fffffeL

// generated code for composite COM:Archive:CompositeFilter
#ifndef COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED

typedef struct _com_archive_compositefilter_t com_archive_compositefilter_t;

#endif // COM_ARCHIVE_COMPOSITEFILTER_T_DEFINED

// short form for composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM 0x2000201000003L
#ifndef COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED

typedef struct _com_archive_compositefilter_list_t com_archive_compositefilter_list_t;

#endif // COM_ARCHIVE_COMPOSITEFILTER_LIST_T_DEFINED

// short form for list of composite type COM:Archive:CompositeFilter
#define COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM 0x2000201fffffdL

// generated code for composite COM:Archive:CompositeFilterSet
#ifndef COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED

typedef struct _com_archive_compositefilterset_t com_archive_compositefilterset_t;

#endif // COM_ARCHIVE_COMPOSITEFILTERSET_T_DEFINED

// short form for composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM 0x2000201000004L
#ifndef COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED
#define COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED

typedef struct _com_archive_compositefilterset_list_t com_archive_compositefilterset_list_t;

#endif // COM_ARCHIVE_COMPOSITEFILTERSET_LIST_T_DEFINED

// short form for list of composite type COM:Archive:CompositeFilterSet
#define COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM 0x2000201fffffcL

// generated code for composite COM:Archive:PaginationFilter
#ifndef COM_ARCHIVE_PAGINATIONFILTER_T_DEFINED
#define COM_ARCHIVE_PAGINATIONFILTER_T_DEFINED

typedef struct _com_archive_paginationfilter_t com_archive_paginationfilter_t;

#endif // COM_ARCHIVE_PAGINATIONFILTER_T_DEFINED

// short form for composite type COM:Archive:PaginationFilter
#define COM_ARCHIVE_PAGINATIONFILTER_SHORT_FORM 0x2000201000006L
#ifndef COM_ARCHIVE_PAGINATIONFILTER_LIST_T_DEFINED
#define COM_ARCHIVE_PAGINATIONFILTER_LIST_T_DEFINED

typedef struct _com_archive_paginationfilter_list_t com_archive_paginationfilter_list_t;

#endif // COM_ARCHIVE_PAGINATIONFILTER_LIST_T_DEFINED

// short form for list of composite type COM:Archive:PaginationFilter
#define COM_ARCHIVE_PAGINATIONFILTER_LIST_SHORT_FORM 0x2000201fffffaL

// standard service identifiers
#define COM_ACTIVITYTRACKING_SERVICE_NUMBER 3

// generated code for composite COM:ActivityTracking:ActivityTransfer
#ifndef COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED

typedef struct _com_activitytracking_activitytransfer_t com_activitytracking_activitytransfer_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM 0x2000301000001L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED

typedef struct _com_activitytracking_activitytransfer_list_t com_activitytracking_activitytransfer_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityTransfer
#define COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM 0x2000301ffffffL

// generated code for composite COM:ActivityTracking:ActivityAcceptance
#ifndef COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED

typedef struct _com_activitytracking_activityacceptance_t com_activitytracking_activityacceptance_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM 0x2000301000002L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED

typedef struct _com_activitytracking_activityacceptance_list_t com_activitytracking_activityacceptance_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityAcceptance
#define COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM 0x2000301fffffeL

// generated code for composite COM:ActivityTracking:ActivityExecution
#ifndef COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED

typedef struct _com_activitytracking_activityexecution_t com_activitytracking_activityexecution_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_T_DEFINED

// short form for composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM 0x2000301000003L
#ifndef COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED

typedef struct _com_activitytracking_activityexecution_list_t com_activitytracking_activityexecution_list_t;

#endif // COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:ActivityExecution
#define COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM 0x2000301fffffdL

// generated code for composite COM:ActivityTracking:OperationActivity
#ifndef COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED

typedef struct _com_activitytracking_operationactivity_t com_activitytracking_operationactivity_t;

#endif // COM_ACTIVITYTRACKING_OPERATIONACTIVITY_T_DEFINED

// short form for composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM 0x2000301000004L
#ifndef COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED

typedef struct _com_activitytracking_operationactivity_list_t com_activitytracking_operationactivity_list_t;

#endif // COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_T_DEFINED

// short form for list of composite type COM:ActivityTracking:OperationActivity
#define COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM 0x2000301fffffcL

// standard service identifiers
#define COM_ARCHIVESYNC_SERVICE_NUMBER 4

// generated code for composite COM:ArchiveSync:DictionaryEntry
#ifndef COM_ARCHIVESYNC_DICTIONARYENTRY_T_DEFINED
#define COM_ARCHIVESYNC_DICTIONARYENTRY_T_DEFINED

typedef struct _com_archivesync_dictionaryentry_t com_archivesync_dictionaryentry_t;

#endif // COM_ARCHIVESYNC_DICTIONARYENTRY_T_DEFINED

// short form for composite type COM:ArchiveSync:DictionaryEntry
#define COM_ARCHIVESYNC_DICTIONARYENTRY_SHORT_FORM 0x2000401000007L
#ifndef COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_T_DEFINED
#define COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_T_DEFINED

typedef struct _com_archivesync_dictionaryentry_list_t com_archivesync_dictionaryentry_list_t;

#endif // COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_T_DEFINED

// short form for list of composite type COM:ArchiveSync:DictionaryEntry
#define COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_SHORT_FORM 0x2000401fffff9L

// generated code for composite COM:ArchiveSync:Dictionary
#ifndef COM_ARCHIVESYNC_DICTIONARY_T_DEFINED
#define COM_ARCHIVESYNC_DICTIONARY_T_DEFINED

typedef struct _com_archivesync_dictionary_t com_archivesync_dictionary_t;

#endif // COM_ARCHIVESYNC_DICTIONARY_T_DEFINED

// short form for composite type COM:ArchiveSync:Dictionary
#define COM_ARCHIVESYNC_DICTIONARY_SHORT_FORM 0x2000401000008L
#ifndef COM_ARCHIVESYNC_DICTIONARY_LIST_T_DEFINED
#define COM_ARCHIVESYNC_DICTIONARY_LIST_T_DEFINED

typedef struct _com_archivesync_dictionary_list_t com_archivesync_dictionary_list_t;

#endif // COM_ARCHIVESYNC_DICTIONARY_LIST_T_DEFINED

// short form for list of composite type COM:ArchiveSync:Dictionary
#define COM_ARCHIVESYNC_DICTIONARY_LIST_SHORT_FORM 0x2000401fffff8L

// generated code for composite COM:ArchiveSync:CompactCOMObject
#ifndef COM_ARCHIVESYNC_COMPACTCOMOBJECT_T_DEFINED
#define COM_ARCHIVESYNC_COMPACTCOMOBJECT_T_DEFINED

typedef struct _com_archivesync_compactcomobject_t com_archivesync_compactcomobject_t;

#endif // COM_ARCHIVESYNC_COMPACTCOMOBJECT_T_DEFINED

// short form for composite type COM:ArchiveSync:CompactCOMObject
#define COM_ARCHIVESYNC_COMPACTCOMOBJECT_SHORT_FORM 0x2000401000009L
#ifndef COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_T_DEFINED
#define COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_T_DEFINED

typedef struct _com_archivesync_compactcomobject_list_t com_archivesync_compactcomobject_list_t;

#endif // COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_T_DEFINED

// short form for list of composite type COM:ArchiveSync:CompactCOMObject
#define COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_SHORT_FORM 0x2000401fffff7L

// generated code for composite COM:ArchiveSync:DomainizedCOMObjects
#ifndef COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_T_DEFINED
#define COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_T_DEFINED

typedef struct _com_archivesync_domainizedcomobjects_t com_archivesync_domainizedcomobjects_t;

#endif // COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_T_DEFINED

// short form for composite type COM:ArchiveSync:DomainizedCOMObjects
#define COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_SHORT_FORM 0x200040100000aL
#ifndef COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_T_DEFINED
#define COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_T_DEFINED

typedef struct _com_archivesync_domainizedcomobjects_list_t com_archivesync_domainizedcomobjects_list_t;

#endif // COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_T_DEFINED

// short form for list of composite type COM:ArchiveSync:DomainizedCOMObjects
#define COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_SHORT_FORM 0x2000401fffff6L

// include required areas definitions
#include "common.h"
#include "mc.h"
#include "pf.h"
#include "softwaremanagement.h"

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
int com_event_monitorevent_update_add_encoding_length_1_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
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
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_event_monitorevent_update_encode_1_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_event_monitorevent_update_add_encoding_length_1_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_event_monitorevent_update_add_encoding_length_1_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_event_monitorevent_update_encode_1_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
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

// generated code for composite COM:Archive:PaginationFilter

// generated code for operation com_archive_retrieve
#define COM_ARCHIVE_RETRIEVE_OPERATION_NUMBER 1
int com_archive_retrieve_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_retrieve_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_retrieve_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_retrieve_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_retrieve_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_retrieve_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_retrieve_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_retrieve_invoke_add_encoding_length_2(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_retrieve_invoke_encode_2(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_retrieve_invoke_decode_2(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_retrieve_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_retrieve_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int com_archive_retrieve_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_retrieve_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archive_retrieve_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_retrieve_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_retrieve_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_retrieve_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
int com_archive_retrieve_invoke_response_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_retrieve_invoke_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_retrieve_invoke_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_retrieve_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int com_archive_retrieve_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_retrieve_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_retrieve_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_query
#define COM_ARCHIVE_QUERY_OPERATION_NUMBER 2
int com_archive_query_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_query_progress_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_query_progress_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_query_progress_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int com_archive_query_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_add_encoding_length_1(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_encode_1(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_decode_1(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_query_progress_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_query_progress_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivequery_list_t ** element_res);
int com_archive_query_progress_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_add_encoding_length_3_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_query_progress_encode_3_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_query_progress_add_encoding_length_3_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_query_progress_encode_3_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_query_progress_add_encoding_length_3(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_query_progress_encode_3(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_query_progress_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int com_archive_query_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archive_query_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_update_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_update_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_query_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_update_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_update_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_query_progress_update_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_archive_query_progress_update_add_encoding_length_3_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_archive_query_progress_update_encode_3_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_archive_query_progress_update_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_archive_query_progress_update_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_archive_query_progress_update_encode_3_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
int com_archive_query_progress_update_add_encoding_length_3(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_query_progress_update_encode_3(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_query_progress_update_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int com_archive_query_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_query_progress_response_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_query_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_query_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_query_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_response_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_query_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_query_progress_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_response_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_query_progress_response_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_query_progress_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_archive_query_progress_response_add_encoding_length_3_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_archive_query_progress_response_encode_3_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_archive_query_progress_response_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_archive_query_progress_response_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_archive_query_progress_response_encode_3_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
int com_archive_query_progress_response_add_encoding_length_3(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_query_progress_response_encode_3(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_query_progress_response_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_query_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int com_archive_query_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_query_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_query_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_count
#define COM_ARCHIVE_COUNT_OPERATION_NUMBER 3
int com_archive_count_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_count_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_count_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_count_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_count_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_count_invoke_add_encoding_length_1(mal_encoder_t * encoder, com_archive_archivequery_list_t * element, void * cursor);
int com_archive_count_invoke_encode_1(void * cursor, mal_encoder_t * encoder, com_archive_archivequery_list_t * element);
int com_archive_count_invoke_decode_1(void * cursor, mal_decoder_t * decoder, com_archive_archivequery_list_t ** element_res);
int com_archive_count_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_count_invoke_add_encoding_length_2_com_archive_compositefilterset_list(mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element, void * cursor);
int com_archive_count_invoke_encode_2_com_archive_compositefilterset_list(void * cursor, mal_encoder_t * encoder, com_archive_compositefilterset_list_t * element);
int com_archive_count_invoke_add_encoding_length_2_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_count_invoke_encode_2_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_count_invoke_add_encoding_length_2(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_count_invoke_encode_2(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_count_invoke_decode_2(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_count_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int com_archive_count_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_count_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archive_count_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_count_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_count_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_count_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_count_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_count_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archive_count_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_count_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_count_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_store
#define COM_ARCHIVE_STORE_OPERATION_NUMBER 4
int com_archive_store_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_store_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int com_archive_store_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int com_archive_store_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int com_archive_store_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_add_encoding_length_1(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_store_request_encode_1(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_store_request_decode_1(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_store_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_add_encoding_length_2(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_store_request_encode_2(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_store_request_decode_2(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_store_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_add_encoding_length_3(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_3(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_store_request_decode_3(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_store_request_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_archive_store_request_add_encoding_length_4_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_archive_store_request_add_encoding_length_4_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_archive_store_request_encode_4_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_archive_store_request_add_encoding_length_4_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_archive_store_request_encode_4_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_archive_store_request_encode_4_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_archive_store_request_add_encoding_length_4_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_archive_store_request_encode_4_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_archive_store_request_add_encoding_length_4_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_archive_store_request_encode_4_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_archive_store_request_add_encoding_length_4_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_archive_store_request_encode_4_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_archive_store_request_add_encoding_length_4_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_archive_store_request_add_encoding_length_4_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_archive_store_request_encode_4_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_archive_store_request_add_encoding_length_4_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_archive_store_request_encode_4_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_archive_store_request_add_encoding_length_4_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_archive_store_request_add_encoding_length_4_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_archive_store_request_add_encoding_length_4_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_archive_store_request_encode_4_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_archive_store_request_add_encoding_length_4_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_archive_store_request_encode_4_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_archive_store_request_add_encoding_length_4_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_archive_store_request_add_encoding_length_4_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_archive_store_request_add_encoding_length_4_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_archive_store_request_encode_4_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_archive_store_request_add_encoding_length_4_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_archive_store_request_add_encoding_length_4_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_archive_store_request_add_encoding_length_4_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_archive_store_request_add_encoding_length_4_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_archive_store_request_add_encoding_length_4_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_archive_store_request_encode_4_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_archive_store_request_add_encoding_length_4_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_archive_store_request_encode_4_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
int com_archive_store_request_add_encoding_length_4(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_store_request_encode_4(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_store_request_decode_4(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3, mal_element_holder_t * arg4);
int com_archive_store_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_store_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_store_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_store_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_store_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_store_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archive_store_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_store_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_store_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_update
#define COM_ARCHIVE_UPDATE_OPERATION_NUMBER 5
int com_archive_update_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_update_submit_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_update_submit_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_update_submit_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_update_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_update_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_update_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_update_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_update_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_update_submit_add_encoding_length_2(mal_encoder_t * encoder, com_archive_archivedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_2(void * cursor, mal_encoder_t * encoder, com_archive_archivedetails_list_t * element);
int com_archive_update_submit_decode_2(void * cursor, mal_decoder_t * decoder, com_archive_archivedetails_list_t ** element_res);
int com_archive_update_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
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
int com_archive_update_submit_add_encoding_length_3_com_archive_paginationfilter_list(mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_paginationfilter_list(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archive_paginationfilter(mal_encoder_t * encoder, com_archive_paginationfilter_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archive_paginationfilter(void * cursor, mal_encoder_t * encoder, com_archive_paginationfilter_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_compactcomobject_list(mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_compactcomobject_list(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_compactcomobject(mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_compactcomobject(void * cursor, mal_encoder_t * encoder, com_archivesync_compactcomobject_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_dictionary_list(mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_dictionary_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_dictionary(mal_encoder_t * encoder, com_archivesync_dictionary_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_dictionary(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionary_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_dictionaryentry_list(mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_dictionaryentry_list(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_dictionaryentry(mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_dictionaryentry(void * cursor, mal_encoder_t * encoder, com_archivesync_dictionaryentry_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_domainizedcomobjects_list(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_domainizedcomobjects_list(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_list_t * element);
int com_archive_update_submit_add_encoding_length_3_com_archivesync_domainizedcomobjects(mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element, void * cursor);
int com_archive_update_submit_encode_3_com_archivesync_domainizedcomobjects(void * cursor, mal_encoder_t * encoder, com_archivesync_domainizedcomobjects_t * element);
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
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationobjectdetails_list(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationobjectdetails_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationobjectdetails(mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationobjectdetails(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationobjectset_list(mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationobjectset_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationobjectset(mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationobjectset(void * cursor, mal_encoder_t * encoder, common_configuration_configurationobjectset_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationtype_list(mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationtype_list(void * cursor, mal_encoder_t * encoder, common_configuration_configurationtype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_configurationtype(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_configurationtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_serviceconfigurationidentifier_list(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_serviceconfigurationidentifier_list(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_configuration_serviceconfigurationidentifier(mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_configuration_serviceconfigurationidentifier(void * cursor, mal_encoder_t * encoder, common_configuration_serviceconfigurationidentifier_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_addressdetails_list(mal_encoder_t * encoder, common_directory_addressdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_addressdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_addressdetails(mal_encoder_t * encoder, common_directory_addressdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_addressdetails(void * cursor, mal_encoder_t * encoder, common_directory_addressdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_providerdetails_list(mal_encoder_t * encoder, common_directory_providerdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_providerdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_providerdetails(mal_encoder_t * encoder, common_directory_providerdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_providerdetails(void * cursor, mal_encoder_t * encoder, common_directory_providerdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_providersummary_list(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_providersummary_list(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_providersummary(mal_encoder_t * encoder, common_directory_providersummary_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_providersummary(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_publishdetails_list(mal_encoder_t * encoder, common_directory_publishdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_publishdetails_list(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_publishdetails(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_publishdetails(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_servicecapability_list(mal_encoder_t * encoder, common_directory_servicecapability_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_servicecapability_list(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_servicecapability(mal_encoder_t * encoder, common_directory_servicecapability_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_servicecapability(void * cursor, mal_encoder_t * encoder, common_directory_servicecapability_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_servicefilter_list(mal_encoder_t * encoder, common_directory_servicefilter_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_servicefilter_list(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_directory_servicefilter(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_directory_servicefilter(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int com_archive_update_submit_add_encoding_length_3_common_login_profile_list(mal_encoder_t * encoder, common_login_profile_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_login_profile_list(void * cursor, mal_encoder_t * encoder, common_login_profile_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_login_profile(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_login_profile(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int com_archive_update_submit_add_encoding_length_3_common_servicekey_list(mal_encoder_t * encoder, common_servicekey_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_servicekey_list(void * cursor, mal_encoder_t * encoder, common_servicekey_list_t * element);
int com_archive_update_submit_add_encoding_length_3_common_servicekey(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int com_archive_update_submit_encode_3_common_servicekey(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
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
int com_archive_update_submit_add_encoding_length_3_mc_action_actioncategory_list(mal_encoder_t * encoder, mc_action_actioncategory_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioncategory_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncategory_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actioncategory(mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioncategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_action_actioncategory_t element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actioncreationrequest_list(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioncreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actioncreationrequest(mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioncreationrequest(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actiondefinitiondetails_list(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actiondefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actiondefinitiondetails(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actiondefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actioninstancedetails_list(mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioninstancedetails_list(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_action_actioninstancedetails(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_action_actioninstancedetails(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationcategory_list(mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationcategory_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcategory_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationcategory(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationcategory(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_aggregationcategory_t element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationcreationrequest_list(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationcreationrequest(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationcreationrequest(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationdefinitiondetails(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationparameterset_list(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationparameterset_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationparameterset(mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationparameterset(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparameterset_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationparametervalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationparametervalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationparametervalue(mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationparametervalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationparametervalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationsetvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationsetvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationsetvalue(mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationsetvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationsetvalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationvalue_list(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationvalue_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationvalue(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationvalue(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationvaluedetails_list(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationvaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_aggregationvaluedetails(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_aggregationvaluedetails(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_generationmode_list(mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_generationmode_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_generationmode_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_generationmode(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_generationmode(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_generationmode_t element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_thresholdfilter_list(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_thresholdfilter_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_thresholdfilter(mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_thresholdfilter(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdfilter_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_thresholdtype_list(mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_thresholdtype_list(void * cursor, mal_encoder_t * encoder, mc_aggregation_thresholdtype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_aggregation_thresholdtype(mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_aggregation_thresholdtype(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_aggregation_thresholdtype_t element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alertcreationrequest_list(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alertcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alertcreationrequest(mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alertcreationrequest(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alertdefinitiondetails_list(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alertdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alertdefinitiondetails(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alertdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alerteventdetails_list(mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alerteventdetails_list(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_alert_alerteventdetails(mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_alert_alerteventdetails(void * cursor, mal_encoder_t * encoder, mc_alert_alerteventdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checklinkdetails_list(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checklinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checklinkdetails(mal_encoder_t * encoder, mc_check_checklinkdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checklinkdetails(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checklinksummary_list(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checklinksummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checklinksummary(mal_encoder_t * encoder, mc_check_checklinksummary_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checklinksummary(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresult_list(mal_encoder_t * encoder, mc_check_checkresult_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresult_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresult(mal_encoder_t * encoder, mc_check_checkresult_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresult(void * cursor, mal_encoder_t * encoder, mc_check_checkresult_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresultfilter_list(mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresultfilter_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresultfilter(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresultfilter(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresultsummary_list(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresultsummary_list(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkresultsummary(mal_encoder_t * encoder, mc_check_checkresultsummary_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkresultsummary(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkstate_list(mal_encoder_t * encoder, mc_check_checkstate_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkstate_list(void * cursor, mal_encoder_t * encoder, mc_check_checkstate_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checkstate(mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checkstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_check_checkstate_t element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checktypedinstance_list(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checktypedinstance_list(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_checktypedinstance(mal_encoder_t * encoder, mc_check_checktypedinstance_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_checktypedinstance(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_compoundcheckdefinition(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_compoundcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_constantcheckdefinition(mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_constantcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_deltacheckdefinition(mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_deltacheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_limitcheckdefinition(mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_limitcheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_referencecheckdefinition(mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_referencecheckdefinition(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_referencevalue_list(mal_encoder_t * encoder, mc_check_referencevalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_referencevalue_list(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_check_referencevalue(mal_encoder_t * encoder, mc_check_referencevalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_check_referencevalue(void * cursor, mal_encoder_t * encoder, mc_check_referencevalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_discreteconversiondetails_list(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_discreteconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_discreteconversiondetails(mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_discreteconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_discreteconversiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_lineconversiondetails_list(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_lineconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_lineconversiondetails(mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_lineconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_lineconversiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_polyconversiondetails_list(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_polyconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_polyconversiondetails(mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_polyconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_polyconversiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_rangeconversiondetails_list(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_rangeconversiondetails_list(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conversion_rangeconversiondetails(mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conversion_rangeconversiondetails(void * cursor, mal_encoder_t * encoder, mc_conversion_rangeconversiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_group_groupdetails_list(mal_encoder_t * encoder, mc_group_groupdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_group_groupdetails_list(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_group_groupdetails(mal_encoder_t * encoder, mc_group_groupdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_group_groupdetails(void * cursor, mal_encoder_t * encoder, mc_group_groupdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterconversion_list(mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterconversion_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterconversion(mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterconversion(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterconversion_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametercreationrequest_list(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametercreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametercreationrequest(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametercreationrequest(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterdefinitiondetails_list(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterdefinitiondetails(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterrawvalue_list(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterrawvalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parameterrawvalue(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parameterrawvalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametervalue_list(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametervalue_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametervalue(mal_encoder_t * encoder, mc_parameter_parametervalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametervalue(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametervaluedetails_list(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametervaluedetails_list(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_parametervaluedetails(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_parametervaluedetails(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_validitystate_list(mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_validitystate_list(void * cursor, mal_encoder_t * encoder, mc_parameter_validitystate_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameter_validitystate(mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameter_validitystate(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_parameter_validitystate_t element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticcreationrequest_list(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticcreationrequest_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticcreationrequest(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticcreationrequest(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticevaluationreport_list(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticevaluationreport_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticevaluationreport(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticevaluationreport(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticfunctiondetails_list(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticfunctiondetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticfunctiondetails(mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticfunctiondetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticfunctiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticlinkdetails_list(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticlinkdetails_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticlinkdetails(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticlinkdetails(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticlinksummary_list(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticlinksummary_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticlinksummary(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticlinksummary(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticvalue_list(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticvalue_list(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_statistic_statisticvalue(mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_statistic_statisticvalue(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_argumentdefinitiondetails_list(mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_argumentdefinitiondetails_list(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_argumentdefinitiondetails(mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_argumentdefinitiondetails(void * cursor, mal_encoder_t * encoder, mc_argumentdefinitiondetails_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_attributevalue_list(mal_encoder_t * encoder, mc_attributevalue_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_attributevalue_list(void * cursor, mal_encoder_t * encoder, mc_attributevalue_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_attributevalue(mal_encoder_t * encoder, mc_attributevalue_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_attributevalue(void * cursor, mal_encoder_t * encoder, mc_attributevalue_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conditionalconversion_list(mal_encoder_t * encoder, mc_conditionalconversion_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conditionalconversion_list(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_conditionalconversion(mal_encoder_t * encoder, mc_conditionalconversion_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_conditionalconversion(void * cursor, mal_encoder_t * encoder, mc_conditionalconversion_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_objectinstancepair_list(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_objectinstancepair_list(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_objectinstancepair(mal_encoder_t * encoder, mc_objectinstancepair_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_objectinstancepair(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameterexpression_list(mal_encoder_t * encoder, mc_parameterexpression_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameterexpression_list(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_parameterexpression(mal_encoder_t * encoder, mc_parameterexpression_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_parameterexpression(void * cursor, mal_encoder_t * encoder, mc_parameterexpression_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_severity_list(mal_encoder_t * encoder, mc_severity_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_mc_severity_list(void * cursor, mal_encoder_t * encoder, mc_severity_list_t * element);
int com_archive_update_submit_add_encoding_length_3_mc_severity(mal_encoder_t * encoder, bool presence_flag, mc_severity_t element, void * cursor);
int com_archive_update_submit_encode_3_mc_severity(void * cursor, mal_encoder_t * encoder, bool presence_flag, mc_severity_t element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_actuatorstelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_actuatorstelemetry(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_actuatorstelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudetelemetry_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_attitudetelemetry(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_attitudetelemetry(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate_list(mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_magnetorquersstate_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_magnetorquersstate_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_magnetorquersstate(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_magnetorquersstate(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_magnetorquersstate_t element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_quaternion_list(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_quaternion_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_quaternion(mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_quaternion(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_quaternion_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_reactionwheelidentifier_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelidentifier_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_reactionwheelidentifier(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_reactionwheelidentifier(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters_list(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_reactionwheelparameters_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_reactionwheelparameters(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_reactionwheelparameters(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_wheelsspeed_list(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_wheelsspeed_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_autonomousadcs_wheelsspeed(mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_autonomousadcs_wheelsspeed(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_wheelsspeed_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_camerasettings_list(mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_camerasettings_list(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_camerasettings(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_camerasettings(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_picture_list(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_picture_list(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_picture(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_picture(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_pictureformat(mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_pictureformat(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_camera_pictureformat_t element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_camera_pixelresolution(mal_encoder_t * encoder, pf_camera_pixelresolution_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_camera_pixelresolution(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_nearbypositiondefinition_list(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_nearbypositiondefinition_list(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_nearbypositiondefinition(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_nearbypositiondefinition(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_position_list(mal_encoder_t * encoder, pf_gps_position_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_position_list(void * cursor, mal_encoder_t * encoder, pf_gps_position_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_position(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_position(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_positionextradetails_list(mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_positionextradetails_list(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_positionextradetails(mal_encoder_t * encoder, pf_gps_positionextradetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_positionextradetails(void * cursor, mal_encoder_t * encoder, pf_gps_positionextradetails_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_satelliteinfo_list(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_satelliteinfo_list(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_satelliteinfo(mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_satelliteinfo(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_twolineelementset_list(mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_twolineelementset_list(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_gps_twolineelementset(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_gps_twolineelementset(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_powercontrol_device_list(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_powercontrol_device_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_powercontrol_device(mal_encoder_t * encoder, pf_powercontrol_device_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_powercontrol_device(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_powercontrol_devicetype_list(mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_powercontrol_devicetype_list(void * cursor, mal_encoder_t * encoder, pf_powercontrol_devicetype_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_powercontrol_devicetype(mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element, void * cursor);
int com_archive_update_submit_encode_3_pf_powercontrol_devicetype(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_powercontrol_devicetype_t element);
int com_archive_update_submit_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents_list(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_softwaredefinedradio_iqcomponents_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_softwaredefinedradio_iqcomponents(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_softwaredefinedradio_iqcomponents(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration_list(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_softwaredefinedradio_sdrconfiguration_list(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_softwaredefinedradio_sdrconfiguration(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_softwaredefinedradio_sdrconfiguration(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_vectord3d_list(mal_encoder_t * encoder, pf_vectord3d_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_vectord3d_list(void * cursor, mal_encoder_t * encoder, pf_vectord3d_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_vectord3d(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_vectord3d(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_vectorf3d_list(mal_encoder_t * encoder, pf_vectorf3d_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_vectorf3d_list(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_list_t * element);
int com_archive_update_submit_add_encoding_length_3_pf_vectorf3d(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int com_archive_update_submit_encode_3_pf_vectorf3d(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_appslauncher_appdetails_list(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_appslauncher_appdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_appslauncher_appdetails(mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_appslauncher_appdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_appslauncher_appdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails_list(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_commandexecutor_commanddetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_commandexecutor_commanddetails(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_commandexecutor_commanddetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_packagemanagement_installationdetails_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_list_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_packagemanagement_installationdetails(mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_packagemanagement_installationdetails(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_installationdetails_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition_list(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_packagemanagement_packagedefinition_list(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_list_t * element);
int com_archive_update_submit_add_encoding_length_3_softwaremanagement_packagemanagement_packagedefinition(mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element, void * cursor);
int com_archive_update_submit_encode_3_softwaremanagement_packagemanagement_packagedefinition(void * cursor, mal_encoder_t * encoder, softwaremanagement_packagemanagement_packagedefinition_t * element);
int com_archive_update_submit_add_encoding_length_3(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int com_archive_update_submit_encode_3(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int com_archive_update_submit_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_update_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int com_archive_update_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_update_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archive_update_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_update_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_update_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation com_archive_delete
#define COM_ARCHIVE_DELETE_OPERATION_NUMBER 6
int com_archive_delete_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archive_delete_request_add_encoding_length_0(mal_encoder_t * encoder, com_objecttype_t * element, void * cursor);
int com_archive_delete_request_encode_0(void * cursor, mal_encoder_t * encoder, com_objecttype_t * element);
int com_archive_delete_request_decode_0(void * cursor, mal_decoder_t * decoder, com_objecttype_t ** element_res);
int com_archive_delete_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_delete_request_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int com_archive_delete_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int com_archive_delete_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int com_archive_delete_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_delete_request_add_encoding_length_2(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_delete_request_encode_2(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_delete_request_decode_2(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_delete_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_delete_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int com_archive_delete_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archive_delete_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int com_archive_delete_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int com_archive_delete_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int com_archive_delete_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archive_delete_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archive_delete_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archive_delete_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archive_delete_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite COM:ActivityTracking:ActivityTransfer

// generated code for composite COM:ActivityTracking:ActivityAcceptance

// generated code for composite COM:ActivityTracking:ActivityExecution

// generated code for composite COM:ActivityTracking:OperationActivity

// generated code for composite COM:ArchiveSync:DictionaryEntry

// generated code for composite COM:ArchiveSync:Dictionary

// generated code for composite COM:ArchiveSync:CompactCOMObject

// generated code for composite COM:ArchiveSync:DomainizedCOMObjects

// generated code for operation com_archivesync_gettime
#define COM_ARCHIVESYNC_GETTIME_OPERATION_NUMBER 1
int com_archivesync_gettime_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archivesync_gettime_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archivesync_gettime_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_gettime_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archivesync_gettime_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archivesync_gettime_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_finetime_t * element_res);
int com_archivesync_gettime_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_gettime_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archivesync_gettime_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archivesync_gettime_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_finetime_t * element_res);
int com_archivesync_gettime_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_gettime_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);

// generated code for operation com_archivesync_retrieverange
#define COM_ARCHIVESYNC_RETRIEVERANGE_OPERATION_NUMBER 2
int com_archivesync_retrieverange_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archivesync_retrieverange_progress_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archivesync_retrieverange_progress_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archivesync_retrieverange_progress_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_finetime_t * element_res);
int com_archivesync_retrieverange_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element, void * cursor);
int com_archivesync_retrieverange_progress_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_finetime_t element);
int com_archivesync_retrieverange_progress_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_finetime_t * element_res);
int com_archivesync_retrieverange_progress_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_add_encoding_length_2(mal_encoder_t * encoder, com_objecttype_list_t * element, void * cursor);
int com_archivesync_retrieverange_progress_encode_2(void * cursor, mal_encoder_t * encoder, com_objecttype_list_t * element);
int com_archivesync_retrieverange_progress_decode_2(void * cursor, mal_decoder_t * decoder, com_objecttype_list_t ** element_res);
int com_archivesync_retrieverange_progress_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_add_encoding_length_3(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int com_archivesync_retrieverange_progress_encode_3(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int com_archivesync_retrieverange_progress_decode_3(void * cursor, mal_decoder_t * decoder, mal_identifier_t ** element_res);
int com_archivesync_retrieverange_progress_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int com_archivesync_retrieverange_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverange_progress_ack_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archivesync_retrieverange_progress_ack_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archivesync_retrieverange_progress_ack_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int com_archivesync_retrieverange_progress_ack_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archivesync_retrieverange_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverange_progress_update_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archivesync_retrieverange_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archivesync_retrieverange_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int com_archivesync_retrieverange_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_update_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archivesync_retrieverange_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archivesync_retrieverange_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int com_archivesync_retrieverange_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int com_archivesync_retrieverange_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverange_progress_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archivesync_retrieverange_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archivesync_retrieverange_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int com_archivesync_retrieverange_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverange_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation com_archivesync_retrieverangeagain
#define COM_ARCHIVESYNC_RETRIEVERANGEAGAIN_OPERATION_NUMBER 3
int com_archivesync_retrieverangeagain_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archivesync_retrieverangeagain_progress_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archivesync_retrieverangeagain_progress_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archivesync_retrieverangeagain_progress_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int com_archivesync_retrieverangeagain_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverangeagain_progress_add_encoding_length_1(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int com_archivesync_retrieverangeagain_progress_encode_1(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int com_archivesync_retrieverangeagain_progress_decode_1(void * cursor, mal_decoder_t * decoder, mal_uinteger_list_t ** element_res);
int com_archivesync_retrieverangeagain_progress_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverangeagain_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int com_archivesync_retrieverangeagain_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverangeagain_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archivesync_retrieverangeagain_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverangeagain_progress_update_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int com_archivesync_retrieverangeagain_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int com_archivesync_retrieverangeagain_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int com_archivesync_retrieverangeagain_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverangeagain_progress_update_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int com_archivesync_retrieverangeagain_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int com_archivesync_retrieverangeagain_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int com_archivesync_retrieverangeagain_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_retrieverangeagain_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int com_archivesync_retrieverangeagain_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_retrieverangeagain_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation com_archivesync_getdictionary
#define COM_ARCHIVESYNC_GETDICTIONARY_OPERATION_NUMBER 4
int com_archivesync_getdictionary_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archivesync_getdictionary_request_add_encoding_length_0(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int com_archivesync_getdictionary_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int com_archivesync_getdictionary_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_integer_list_t ** element_res);
int com_archivesync_getdictionary_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_getdictionary_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archivesync_getdictionary_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_getdictionary_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int com_archivesync_getdictionary_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int com_archivesync_getdictionary_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int com_archivesync_getdictionary_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_getdictionary_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation com_archivesync_free
#define COM_ARCHIVESYNC_FREE_OPERATION_NUMBER 5
int com_archivesync_free_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int com_archivesync_free_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int com_archivesync_free_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int com_archivesync_free_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int com_archivesync_free_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int com_archivesync_free_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int com_archivesync_free_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int com_archivesync_free_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int com_archivesync_free_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

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
#include "com_archive_paginationfilter.h"
#include "com_archive_paginationfilter_list.h"
#include "com_activitytracking_activitytransfer.h"
#include "com_activitytracking_activitytransfer_list.h"
#include "com_activitytracking_activityacceptance.h"
#include "com_activitytracking_activityacceptance_list.h"
#include "com_activitytracking_activityexecution.h"
#include "com_activitytracking_activityexecution_list.h"
#include "com_activitytracking_operationactivity.h"
#include "com_activitytracking_operationactivity_list.h"
#include "com_archivesync_dictionaryentry.h"
#include "com_archivesync_dictionaryentry_list.h"
#include "com_archivesync_dictionary.h"
#include "com_archivesync_dictionary_list.h"
#include "com_archivesync_compactcomobject.h"
#include "com_archivesync_compactcomobject_list.h"
#include "com_archivesync_domainizedcomobjects.h"
#include "com_archivesync_domainizedcomobjects_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COM_H_INCLUDED__
