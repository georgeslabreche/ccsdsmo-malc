#ifndef __OPSSAT_STD_H_INCLUDED__
#define __OPSSAT_STD_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int opssat_std_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int opssat_std_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int opssat_std_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define OPSSAT_STD_AREA_NUMBER 74
#define OPSSAT_STD_AREA_VERSION 1

// standard service identifiers
#define OPSSAT_STD_MEMORYMANAGEMENT_SERVICE_NUMBER 11

// generated code for enumeration opssat_std_memorymanagement_memorydevice
typedef enum {
  OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_NANOMIND,
  OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_EXTFLASH,
  OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_EXTFRAM,
  OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_EXTSDRAM
} opssat_std_memorymanagement_memorydevice_t;

// short form for enumeration type opssat_std_memorymanagement_memorydevice
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_SHORT_FORM 0x4a000b01000001L
#ifndef OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_T_DEFINED
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_T_DEFINED

typedef struct _opssat_std_memorymanagement_memorydevice_list_t opssat_std_memorymanagement_memorydevice_list_t;

#endif // OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_T_DEFINED

// short form for list of enumeration type opssat_std_memorymanagement_memorydevice
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_SHORT_FORM 0x4a000b01ffffffL

// generated code for composite OPSSAT_STD:MemoryManagement:MemoryBlock
#ifndef OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_T_DEFINED
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_T_DEFINED

typedef struct _opssat_std_memorymanagement_memoryblock_t opssat_std_memorymanagement_memoryblock_t;

#endif // OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_T_DEFINED

// short form for composite type OPSSAT_STD:MemoryManagement:MemoryBlock
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_SHORT_FORM 0x4a000b01000002L
#ifndef OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_T_DEFINED
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_T_DEFINED

typedef struct _opssat_std_memorymanagement_memoryblock_list_t opssat_std_memorymanagement_memoryblock_list_t;

#endif // OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_T_DEFINED

// short form for list of composite type OPSSAT_STD:MemoryManagement:MemoryBlock
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_SHORT_FORM 0x4a000b01fffffeL

// generated code for composite OPSSAT_STD:MemoryManagement:MemoryRange
#ifndef OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_T_DEFINED
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_T_DEFINED

typedef struct _opssat_std_memorymanagement_memoryrange_t opssat_std_memorymanagement_memoryrange_t;

#endif // OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_T_DEFINED

// short form for composite type OPSSAT_STD:MemoryManagement:MemoryRange
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_SHORT_FORM 0x4a000b01000003L
#ifndef OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_T_DEFINED
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_T_DEFINED

typedef struct _opssat_std_memorymanagement_memoryrange_list_t opssat_std_memorymanagement_memoryrange_list_t;

#endif // OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_T_DEFINED

// short form for list of composite type OPSSAT_STD:MemoryManagement:MemoryRange
#define OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_SHORT_FORM 0x4a000b01fffffdL

// standard service identifiers
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SERVICE_NUMBER 12

// generated code for enumeration opssat_std_schedulemanagement_schedule
typedef enum {
  OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_MISSION
} opssat_std_schedulemanagement_schedule_t;

// short form for enumeration type opssat_std_schedulemanagement_schedule
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_SHORT_FORM 0x4a000c01000001L
#ifndef OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_T_DEFINED
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_T_DEFINED

typedef struct _opssat_std_schedulemanagement_schedule_list_t opssat_std_schedulemanagement_schedule_list_t;

#endif // OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_T_DEFINED

// short form for list of enumeration type opssat_std_schedulemanagement_schedule
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_SHORT_FORM 0x4a000c01ffffffL

// generated code for composite OPSSAT_STD:ScheduleManagement:ScheduleEntry
#ifndef OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_T_DEFINED
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_T_DEFINED

typedef struct _opssat_std_schedulemanagement_scheduleentry_t opssat_std_schedulemanagement_scheduleentry_t;

#endif // OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_T_DEFINED

// short form for composite type OPSSAT_STD:ScheduleManagement:ScheduleEntry
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_SHORT_FORM 0x4a000c01000002L
#ifndef OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_T_DEFINED
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_T_DEFINED

typedef struct _opssat_std_schedulemanagement_scheduleentry_list_t opssat_std_schedulemanagement_scheduleentry_list_t;

#endif // OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_T_DEFINED

// short form for list of composite type OPSSAT_STD:ScheduleManagement:ScheduleEntry
#define OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_SHORT_FORM 0x4a000c01fffffeL

// generated code for composite OPSSAT_STD:ScheduleManagement:ListScheduleEntry
#ifndef OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_T_DEFINED
#define OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_T_DEFINED

typedef struct _opssat_std_schedulemanagement_listscheduleentry_t opssat_std_schedulemanagement_listscheduleentry_t;

#endif // OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_T_DEFINED

// short form for composite type OPSSAT_STD:ScheduleManagement:ListScheduleEntry
#define OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_SHORT_FORM 0x4a000c01000003L
#ifndef OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_T_DEFINED
#define OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_T_DEFINED

typedef struct _opssat_std_schedulemanagement_listscheduleentry_list_t opssat_std_schedulemanagement_listscheduleentry_list_t;

#endif // OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_T_DEFINED

// short form for list of composite type OPSSAT_STD:ScheduleManagement:ListScheduleEntry
#define OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_SHORT_FORM 0x4a000c01fffffdL

// standard service identifiers
#define OPSSAT_STD_PACKETSTORE_SERVICE_NUMBER 14

// standard service identifiers
#define OPSSAT_STD_FILEMANAGEMENT_SERVICE_NUMBER 15

// generated code for enumeration opssat_std_filemanagement_fileaccessmode
typedef enum {
  OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_APPEND,
  OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_OVERWRITE,
  OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_READ_ONLY
} opssat_std_filemanagement_fileaccessmode_t;

// short form for enumeration type opssat_std_filemanagement_fileaccessmode
#define OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_SHORT_FORM 0x4a000f01000001L
#ifndef OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_T_DEFINED
#define OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_T_DEFINED

typedef struct _opssat_std_filemanagement_fileaccessmode_list_t opssat_std_filemanagement_fileaccessmode_list_t;

#endif // OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_T_DEFINED

// short form for list of enumeration type opssat_std_filemanagement_fileaccessmode
#define OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_SHORT_FORM 0x4a000f01ffffffL

// include required areas definitions
#include "com.h"
#include "mc.h"
#include "opssat_pf.h"

// generated code for composite OPSSAT_STD:MemoryManagement:MemoryBlock

// generated code for composite OPSSAT_STD:MemoryManagement:MemoryRange

// generated code for operation opssat_std_memorymanagement_loadmemory
#define OPSSAT_STD_MEMORYMANAGEMENT_LOADMEMORY_OPERATION_NUMBER 1
int opssat_std_memorymanagement_loadmemory_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_memorymanagement_loadmemory_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element, void * cursor);
int opssat_std_memorymanagement_loadmemory_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element);
int opssat_std_memorymanagement_loadmemory_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_memorymanagement_memorydevice_t * element_res);
int opssat_std_memorymanagement_loadmemory_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_loadmemory_submit_add_encoding_length_1(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element, void * cursor);
int opssat_std_memorymanagement_loadmemory_submit_encode_1(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element);
int opssat_std_memorymanagement_loadmemory_submit_decode_1(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryblock_t ** element_res);
int opssat_std_memorymanagement_loadmemory_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_loadmemory_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_memorymanagement_loadmemory_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_loadmemory_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_memorymanagement_loadmemory_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_memorymanagement_dumpmemory
#define OPSSAT_STD_MEMORYMANAGEMENT_DUMPMEMORY_OPERATION_NUMBER 2
int opssat_std_memorymanagement_dumpmemory_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_memorymanagement_dumpmemory_progress_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element, void * cursor);
int opssat_std_memorymanagement_dumpmemory_progress_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element);
int opssat_std_memorymanagement_dumpmemory_progress_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_memorymanagement_memorydevice_t * element_res);
int opssat_std_memorymanagement_dumpmemory_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_dumpmemory_progress_add_encoding_length_1(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element, void * cursor);
int opssat_std_memorymanagement_dumpmemory_progress_encode_1(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element);
int opssat_std_memorymanagement_dumpmemory_progress_decode_1(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryrange_t ** element_res);
int opssat_std_memorymanagement_dumpmemory_progress_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_dumpmemory_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_memorymanagement_dumpmemory_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_dumpmemory_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_memorymanagement_dumpmemory_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_dumpmemory_progress_update_add_encoding_length_0(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element, void * cursor);
int opssat_std_memorymanagement_dumpmemory_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element);
int opssat_std_memorymanagement_dumpmemory_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryblock_t ** element_res);
int opssat_std_memorymanagement_dumpmemory_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_dumpmemory_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_memorymanagement_dumpmemory_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_dumpmemory_progress_response_add_encoding_length_0(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element, void * cursor);
int opssat_std_memorymanagement_dumpmemory_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryblock_t * element);
int opssat_std_memorymanagement_dumpmemory_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryblock_t ** element_res);
int opssat_std_memorymanagement_dumpmemory_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_dumpmemory_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_memorymanagement_dumpmemory_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_memorymanagement_checkmemory
#define OPSSAT_STD_MEMORYMANAGEMENT_CHECKMEMORY_OPERATION_NUMBER 3
int opssat_std_memorymanagement_checkmemory_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_memorymanagement_checkmemory_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element, void * cursor);
int opssat_std_memorymanagement_checkmemory_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element);
int opssat_std_memorymanagement_checkmemory_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_memorymanagement_memorydevice_t * element_res);
int opssat_std_memorymanagement_checkmemory_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_checkmemory_request_add_encoding_length_1(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element, void * cursor);
int opssat_std_memorymanagement_checkmemory_request_encode_1(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element);
int opssat_std_memorymanagement_checkmemory_request_decode_1(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryrange_t ** element_res);
int opssat_std_memorymanagement_checkmemory_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_checkmemory_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_memorymanagement_checkmemory_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_checkmemory_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_memorymanagement_checkmemory_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_memorymanagement_checkmemory_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_memorymanagement_checkmemory_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_checkmemory_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_memorymanagement_checkmemory_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_memorymanagement_clearmemory
#define OPSSAT_STD_MEMORYMANAGEMENT_CLEARMEMORY_OPERATION_NUMBER 4
int opssat_std_memorymanagement_clearmemory_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_memorymanagement_clearmemory_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element, void * cursor);
int opssat_std_memorymanagement_clearmemory_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_memorymanagement_memorydevice_t element);
int opssat_std_memorymanagement_clearmemory_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_memorymanagement_memorydevice_t * element_res);
int opssat_std_memorymanagement_clearmemory_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_clearmemory_submit_add_encoding_length_1(mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element, void * cursor);
int opssat_std_memorymanagement_clearmemory_submit_encode_1(void * cursor, mal_encoder_t * encoder, opssat_std_memorymanagement_memoryrange_t * element);
int opssat_std_memorymanagement_clearmemory_submit_decode_1(void * cursor, mal_decoder_t * decoder, opssat_std_memorymanagement_memoryrange_t ** element_res);
int opssat_std_memorymanagement_clearmemory_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_memorymanagement_clearmemory_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_memorymanagement_clearmemory_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_memorymanagement_clearmemory_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_memorymanagement_clearmemory_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite OPSSAT_STD:ScheduleManagement:ScheduleEntry

// generated code for composite OPSSAT_STD:ScheduleManagement:ListScheduleEntry

// generated code for operation opssat_std_schedulemanagement_insertoperation
#define OPSSAT_STD_SCHEDULEMANAGEMENT_INSERTOPERATION_OPERATION_NUMBER 1
int opssat_std_schedulemanagement_insertoperation_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_schedulemanagement_insertoperation_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_t * element, void * cursor);
int opssat_std_schedulemanagement_insertoperation_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_scheduleentry_t * element);
int opssat_std_schedulemanagement_insertoperation_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_std_schedulemanagement_scheduleentry_t ** element_res);
int opssat_std_schedulemanagement_insertoperation_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_schedulemanagement_insertoperation_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_schedulemanagement_insertoperation_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_schedulemanagement_insertoperation_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_schedulemanagement_insertoperation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_schedulemanagement_clearfromtime
#define OPSSAT_STD_SCHEDULEMANAGEMENT_CLEARFROMTIME_OPERATION_NUMBER 2
int opssat_std_schedulemanagement_clearfromtime_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_schedulemanagement_clearfromtime_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element, void * cursor);
int opssat_std_schedulemanagement_clearfromtime_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element);
int opssat_std_schedulemanagement_clearfromtime_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_schedulemanagement_schedule_t * element_res);
int opssat_std_schedulemanagement_clearfromtime_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_schedulemanagement_clearfromtime_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int opssat_std_schedulemanagement_clearfromtime_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int opssat_std_schedulemanagement_clearfromtime_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_time_t * element_res);
int opssat_std_schedulemanagement_clearfromtime_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_schedulemanagement_clearfromtime_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_schedulemanagement_clearfromtime_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_schedulemanagement_clearfromtime_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_schedulemanagement_clearfromtime_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_schedulemanagement_listoperation
#define OPSSAT_STD_SCHEDULEMANAGEMENT_LISTOPERATION_OPERATION_NUMBER 3
int opssat_std_schedulemanagement_listoperation_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_schedulemanagement_listoperation_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element, void * cursor);
int opssat_std_schedulemanagement_listoperation_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_schedulemanagement_schedule_t element);
int opssat_std_schedulemanagement_listoperation_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_schedulemanagement_schedule_t * element_res);
int opssat_std_schedulemanagement_listoperation_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_schedulemanagement_listoperation_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_schedulemanagement_listoperation_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_schedulemanagement_listoperation_request_response_add_encoding_length_0(mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_list_t * element, void * cursor);
int opssat_std_schedulemanagement_listoperation_request_response_encode_0(void * cursor, mal_encoder_t * encoder, opssat_std_schedulemanagement_listscheduleentry_list_t * element);
int opssat_std_schedulemanagement_listoperation_request_response_decode_0(void * cursor, mal_decoder_t * decoder, opssat_std_schedulemanagement_listscheduleentry_list_t ** element_res);
int opssat_std_schedulemanagement_listoperation_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_schedulemanagement_listoperation_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_schedulemanagement_listoperation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_packetstore_downlinkpacketstorecontent
#define OPSSAT_STD_PACKETSTORE_DOWNLINKPACKETSTORECONTENT_OPERATION_NUMBER 1
int opssat_std_packetstore_downlinkpacketstorecontent_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_packetstore_downlinkpacketstorecontent_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_packetstore_downlinkpacketstorecontent_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_packetstore_downlinkpacketstorecontent_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_std_packetstore_stoppacketstoredownlink
#define OPSSAT_STD_PACKETSTORE_STOPPACKETSTOREDOWNLINK_OPERATION_NUMBER 2
int opssat_std_packetstore_stoppacketstoredownlink_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_packetstore_stoppacketstoredownlink_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_packetstore_stoppacketstoredownlink_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_packetstore_stoppacketstoredownlink_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_std_packetstore_deletepacketstorefiles
#define OPSSAT_STD_PACKETSTORE_DELETEPACKETSTOREFILES_OPERATION_NUMBER 3
int opssat_std_packetstore_deletepacketstorefiles_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_packetstore_deletepacketstorefiles_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_packetstore_deletepacketstorefiles_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_packetstore_deletepacketstorefiles_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_std_filemanagement_createfile
#define OPSSAT_STD_FILEMANAGEMENT_CREATEFILE_OPERATION_NUMBER 1
int opssat_std_filemanagement_createfile_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_createfile_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_createfile_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_createfile_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_createfile_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_createfile_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_filemanagement_createfile_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_createfile_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_createfile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_removefile
#define OPSSAT_STD_FILEMANAGEMENT_REMOVEFILE_OPERATION_NUMBER 2
int opssat_std_filemanagement_removefile_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_removefile_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_removefile_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_removefile_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_removefile_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_removefile_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_filemanagement_removefile_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_removefile_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_removefile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_writefile
#define OPSSAT_STD_FILEMANAGEMENT_WRITEFILE_OPERATION_NUMBER 3
int opssat_std_filemanagement_writefile_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_writefile_request_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_writefile_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_writefile_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element);
int opssat_std_filemanagement_writefile_request_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_filemanagement_fileaccessmode_t * element_res);
int opssat_std_filemanagement_writefile_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_writefile_request_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_writefile_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_writefile_request_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_writefile_request_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_add_encoding_length_4(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_4(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_writefile_request_decode_4(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_writefile_request_decode_4_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_add_encoding_length_5(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_std_filemanagement_writefile_request_encode_5(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_std_filemanagement_writefile_request_decode_5(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_std_filemanagement_writefile_request_decode_5_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3, mal_element_holder_t * arg4, mal_element_holder_t * arg5);
int opssat_std_filemanagement_writefile_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_writefile_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_std_filemanagement_writefile_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_std_filemanagement_writefile_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_std_filemanagement_writefile_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_writefile_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_filemanagement_writefile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_checkmissingdatasets
#define OPSSAT_STD_FILEMANAGEMENT_CHECKMISSINGDATASETS_OPERATION_NUMBER 4
int opssat_std_filemanagement_checkmissingdatasets_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_checkmissingdatasets_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_checkmissingdatasets_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_checkmissingdatasets_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_checkmissingdatasets_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_checkmissingdatasets_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_checkmissingdatasets_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_checkmissingdatasets_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int opssat_std_filemanagement_checkmissingdatasets_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int opssat_std_filemanagement_checkmissingdatasets_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_uinteger_list_t ** element_res);
int opssat_std_filemanagement_checkmissingdatasets_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_checkmissingdatasets_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);

// generated code for operation opssat_std_filemanagement_readfile
#define OPSSAT_STD_FILEMANAGEMENT_READFILE_OPERATION_NUMBER 5
int opssat_std_filemanagement_readfile_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_readfile_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_readfile_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_readfile_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_readfile_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_std_filemanagement_fileaccessmode_t element);
int opssat_std_filemanagement_readfile_progress_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_std_filemanagement_fileaccessmode_t * element_res);
int opssat_std_filemanagement_readfile_progress_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_filemanagement_readfile_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_readfile_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_readfile_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_readfile_progress_update_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_readfile_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_readfile_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_update_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_readfile_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_readfile_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_update_add_encoding_length_2(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_std_filemanagement_readfile_progress_update_encode_2(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_std_filemanagement_readfile_progress_update_decode_2(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_std_filemanagement_readfile_progress_update_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_update_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_update_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_std_filemanagement_readfile_progress_update_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_std_filemanagement_readfile_progress_update_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int opssat_std_filemanagement_readfile_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_readfile_progress_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_readfile_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_readfile_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_readfile_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_readfile_progress_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_response_add_encoding_length_2(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_std_filemanagement_readfile_progress_response_encode_2(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_std_filemanagement_readfile_progress_response_decode_2(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_std_filemanagement_readfile_progress_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_response_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_std_filemanagement_readfile_progress_response_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_std_filemanagement_readfile_progress_response_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_std_filemanagement_readfile_progress_response_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_readfile_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int opssat_std_filemanagement_readfile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_testfile
#define OPSSAT_STD_FILEMANAGEMENT_TESTFILE_OPERATION_NUMBER 6
int opssat_std_filemanagement_testfile_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_testfile_request_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_testfile_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_testfile_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_testfile_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_testfile_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_filemanagement_testfile_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_testfile_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_std_filemanagement_testfile_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_std_filemanagement_testfile_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_std_filemanagement_testfile_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_testfile_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_std_filemanagement_testfile_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_std_filemanagement_testfile_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_std_filemanagement_testfile_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_testfile_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_std_filemanagement_testfile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_patchfile
#define OPSSAT_STD_FILEMANAGEMENT_PATCHFILE_OPERATION_NUMBER 7
int opssat_std_filemanagement_patchfile_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_patchfile_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_patchfile_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_patchfile_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_patchfile_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_patchfile_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_patchfile_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_patchfile_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_patchfile_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_patchfile_submit_add_encoding_length_2(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_patchfile_submit_encode_2(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_patchfile_submit_decode_2(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_patchfile_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_patchfile_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int opssat_std_filemanagement_patchfile_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_patchfile_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_patchfile_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_std_filemanagement_listfiles
#define OPSSAT_STD_FILEMANAGEMENT_LISTFILES_OPERATION_NUMBER 8
int opssat_std_filemanagement_listfiles_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_std_filemanagement_listfiles_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_listfiles_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_listfiles_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_std_filemanagement_listfiles_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_listfiles_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_std_filemanagement_listfiles_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_listfiles_progress_update_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_std_filemanagement_listfiles_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_std_filemanagement_listfiles_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_update_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_std_filemanagement_listfiles_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_std_filemanagement_listfiles_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_update_add_encoding_length_2(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_update_encode_2(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_listfiles_progress_update_decode_2(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_listfiles_progress_update_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int opssat_std_filemanagement_listfiles_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_std_filemanagement_listfiles_progress_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_std_filemanagement_listfiles_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_std_filemanagement_listfiles_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_std_filemanagement_listfiles_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_std_filemanagement_listfiles_progress_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_response_add_encoding_length_2(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_std_filemanagement_listfiles_progress_response_encode_2(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_std_filemanagement_listfiles_progress_response_decode_2(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_std_filemanagement_listfiles_progress_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_std_filemanagement_listfiles_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int opssat_std_filemanagement_listfiles_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// test function
void opssat_std_test(bool verbose);

#include "opssat_std_memorymanagement_memorydevice_list.h"
#include "opssat_std_memorymanagement_memoryblock.h"
#include "opssat_std_memorymanagement_memoryblock_list.h"
#include "opssat_std_memorymanagement_memoryrange.h"
#include "opssat_std_memorymanagement_memoryrange_list.h"
#include "opssat_std_schedulemanagement_schedule_list.h"
#include "opssat_std_schedulemanagement_scheduleentry.h"
#include "opssat_std_schedulemanagement_scheduleentry_list.h"
#include "opssat_std_schedulemanagement_listscheduleentry.h"
#include "opssat_std_schedulemanagement_listscheduleentry_list.h"
#include "opssat_std_filemanagement_fileaccessmode_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_STD_H_INCLUDED__
