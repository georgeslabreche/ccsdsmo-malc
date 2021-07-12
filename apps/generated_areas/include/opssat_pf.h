#ifndef __OPSSAT_PF_H_INCLUDED__
#define __OPSSAT_PF_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int opssat_pf_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int opssat_pf_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int opssat_pf_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define OPSSAT_PF_AREA_NUMBER 75
#define OPSSAT_PF_AREA_VERSION 1

// generated code for enumeration opssat_pf_onboarddevice
typedef enum {
  OPSSAT_PF_ONBOARDDEVICE_NANOMIND1,
  OPSSAT_PF_ONBOARDDEVICE_NANOMIND2,
  OPSSAT_PF_ONBOARDDEVICE_UHFANTENNA,
  OPSSAT_PF_ONBOARDDEVICE_CCSDSENGINE,
  OPSSAT_PF_ONBOARDDEVICE_NANOCOM,
  OPSSAT_PF_ONBOARDDEVICE_GPS,
  OPSSAT_PF_ONBOARDDEVICE_SOLARPANEL1_1,
  OPSSAT_PF_ONBOARDDEVICE_SOLARPANEL1_2,
  OPSSAT_PF_ONBOARDDEVICE_SOLARPANEL2_1,
  OPSSAT_PF_ONBOARDDEVICE_SOLARPANEL2_2,
  OPSSAT_PF_ONBOARDDEVICE_NOTUSED,
  OPSSAT_PF_ONBOARDDEVICE_XBANDTRX,
  OPSSAT_PF_ONBOARDDEVICE_SBANDTRX,
  OPSSAT_PF_ONBOARDDEVICE_FINEADCS,
  OPSSAT_PF_ONBOARDDEVICE_SDR,
  OPSSAT_PF_ONBOARDDEVICE_SEPP1,
  OPSSAT_PF_ONBOARDDEVICE_SEPP2,
  OPSSAT_PF_ONBOARDDEVICE_HDCAMERA,
  OPSSAT_PF_ONBOARDDEVICE_OPTICALRX,
  OPSSAT_PF_ONBOARDDEVICE_EPS,
  OPSSAT_PF_ONBOARDDEVICE_ALLSOLARPANELS,
  OPSSAT_PF_ONBOARDDEVICE_SOLPANTEMP,
  OPSSAT_PF_ONBOARDDEVICE_NOTUSED2,
  OPSSAT_PF_ONBOARDDEVICE_FSS
} opssat_pf_onboarddevice_t;

// short form for enumeration type opssat_pf_onboarddevice
#define OPSSAT_PF_ONBOARDDEVICE_SHORT_FORM 0x4b000001000002L
#ifndef OPSSAT_PF_ONBOARDDEVICE_LIST_T_DEFINED
#define OPSSAT_PF_ONBOARDDEVICE_LIST_T_DEFINED

typedef struct _opssat_pf_onboarddevice_list_t opssat_pf_onboarddevice_list_t;

#endif // OPSSAT_PF_ONBOARDDEVICE_LIST_T_DEFINED

// short form for list of enumeration type opssat_pf_onboarddevice
#define OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM 0x4b000001fffffeL

// generated code for enumeration opssat_pf_devices
typedef enum {
  OPSSAT_PF_DEVICES_NANOMIND1,
  OPSSAT_PF_DEVICES_NANOMIND2,
  OPSSAT_PF_DEVICES_CCSDSENGINE,
  OPSSAT_PF_DEVICES_NANOCOM,
  OPSSAT_PF_DEVICES_GPS,
  OPSSAT_PF_DEVICES_SOLARPANEL1_1,
  OPSSAT_PF_DEVICES_SOLARPANEL1_2,
  OPSSAT_PF_DEVICES_SOLARPANEL2_1,
  OPSSAT_PF_DEVICES_SOLARPANEL2_2,
  OPSSAT_PF_DEVICES_XBANDTRX,
  OPSSAT_PF_DEVICES_SBANDTRX,
  OPSSAT_PF_DEVICES_SDR,
  OPSSAT_PF_DEVICES_SEPP1,
  OPSSAT_PF_DEVICES_SEPP2,
  OPSSAT_PF_DEVICES_OPTICALRX
} opssat_pf_devices_t;

// short form for enumeration type opssat_pf_devices
#define OPSSAT_PF_DEVICES_SHORT_FORM 0x4b000001000003L
#ifndef OPSSAT_PF_DEVICES_LIST_T_DEFINED
#define OPSSAT_PF_DEVICES_LIST_T_DEFINED

typedef struct _opssat_pf_devices_list_t opssat_pf_devices_list_t;

#endif // OPSSAT_PF_DEVICES_LIST_T_DEFINED

// short form for list of enumeration type opssat_pf_devices
#define OPSSAT_PF_DEVICES_LIST_SHORT_FORM 0x4b000001fffffdL

// generated code for enumeration opssat_pf_i2cbus
typedef enum {
  OPSSAT_PF_I2CBUS_CSP,
  OPSSAT_PF_I2CBUS_BUSCONTROL,
  OPSSAT_PF_I2CBUS_PAYLOAD
} opssat_pf_i2cbus_t;

// short form for enumeration type opssat_pf_i2cbus
#define OPSSAT_PF_I2CBUS_SHORT_FORM 0x4b000001000004L
#ifndef OPSSAT_PF_I2CBUS_LIST_T_DEFINED
#define OPSSAT_PF_I2CBUS_LIST_T_DEFINED

typedef struct _opssat_pf_i2cbus_list_t opssat_pf_i2cbus_list_t;

#endif // OPSSAT_PF_I2CBUS_LIST_T_DEFINED

// short form for list of enumeration type opssat_pf_i2cbus
#define OPSSAT_PF_I2CBUS_LIST_SHORT_FORM 0x4b000001fffffcL

// standard service identifiers
#define OPSSAT_PF_BUSSWITCHES_SERVICE_NUMBER 16

// standard service identifiers
#define OPSSAT_PF_POWER_SERVICE_NUMBER 17

// standard service identifiers
#define OPSSAT_PF_MODE_SERVICE_NUMBER 18

// generated code for enumeration opssat_pf_mode_systemmode
typedef enum {
  OPSSAT_PF_MODE_SYSTEMMODE_SAFE,
  OPSSAT_PF_MODE_SYSTEMMODE_OPERATIONAL,
  OPSSAT_PF_MODE_SYSTEMMODE_EXPERIMENTAL,
  OPSSAT_PF_MODE_SYSTEMMODE_SET_FIRSTBOOTVALUE,
  OPSSAT_PF_MODE_SYSTEMMODE_RESET_FIRSTBOOTVALUE,
  OPSSAT_PF_MODE_SYSTEMMODE_OBSW_UPLOAD_SBAND,
  OPSSAT_PF_MODE_SYSTEMMODE_OBSW_UPLOAD_UHF,
  OPSSAT_PF_MODE_SYSTEMMODE_OBSW_START
} opssat_pf_mode_systemmode_t;

// short form for enumeration type opssat_pf_mode_systemmode
#define OPSSAT_PF_MODE_SYSTEMMODE_SHORT_FORM 0x4b001201000001L
#ifndef OPSSAT_PF_MODE_SYSTEMMODE_LIST_T_DEFINED
#define OPSSAT_PF_MODE_SYSTEMMODE_LIST_T_DEFINED

typedef struct _opssat_pf_mode_systemmode_list_t opssat_pf_mode_systemmode_list_t;

#endif // OPSSAT_PF_MODE_SYSTEMMODE_LIST_T_DEFINED

// short form for list of enumeration type opssat_pf_mode_systemmode
#define OPSSAT_PF_MODE_SYSTEMMODE_LIST_SHORT_FORM 0x4b001201ffffffL

// standard service identifiers
#define OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER 19

// standard service identifiers
#define OPSSAT_PF_EXPERIMENTWD_SERVICE_NUMBER 20

// standard service identifiers
#define OPSSAT_PF_GPS_SERVICE_NUMBER 21

// standard service identifiers
#define OPSSAT_PF_COARSEADCS_SERVICE_NUMBER 22

// generated code for enumeration opssat_pf_coarseadcs_adcsmode
typedef enum {
  OPSSAT_PF_COARSEADCS_ADCSMODE_IDLE,
  OPSSAT_PF_COARSEADCS_ADCSMODE_DETUMBLING,
  OPSSAT_PF_COARSEADCS_ADCSMODE_NADIRPOINTING,
  OPSSAT_PF_COARSEADCS_ADCSMODE_EXPERIMENTAL
} opssat_pf_coarseadcs_adcsmode_t;

// short form for enumeration type opssat_pf_coarseadcs_adcsmode
#define OPSSAT_PF_COARSEADCS_ADCSMODE_SHORT_FORM 0x4b001601000001L
#ifndef OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_T_DEFINED
#define OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_T_DEFINED

typedef struct _opssat_pf_coarseadcs_adcsmode_list_t opssat_pf_coarseadcs_adcsmode_list_t;

#endif // OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_T_DEFINED

// short form for list of enumeration type opssat_pf_coarseadcs_adcsmode
#define OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_SHORT_FORM 0x4b001601ffffffL

// generated code for composite OPSSAT_PF:CoarseADCS:OrbitTLEData
#ifndef OPSSAT_PF_COARSEADCS_ORBITTLEDATA_T_DEFINED
#define OPSSAT_PF_COARSEADCS_ORBITTLEDATA_T_DEFINED

typedef struct _opssat_pf_coarseadcs_orbittledata_t opssat_pf_coarseadcs_orbittledata_t;

#endif // OPSSAT_PF_COARSEADCS_ORBITTLEDATA_T_DEFINED

// short form for composite type OPSSAT_PF:CoarseADCS:OrbitTLEData
#define OPSSAT_PF_COARSEADCS_ORBITTLEDATA_SHORT_FORM 0x4b001601000003L
#ifndef OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_T_DEFINED
#define OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_T_DEFINED

typedef struct _opssat_pf_coarseadcs_orbittledata_list_t opssat_pf_coarseadcs_orbittledata_list_t;

#endif // OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_T_DEFINED

// short form for list of composite type OPSSAT_PF:CoarseADCS:OrbitTLEData
#define OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_SHORT_FORM 0x4b001601fffffdL

// standard service identifiers
#define OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER 23

// include required areas definitions
#include "com.h"
#include "mc.h"
#include "opssat_std.h"

// generated code for operation opssat_pf_busswitches_setaccessmask
#define OPSSAT_PF_BUSSWITCHES_SETACCESSMASK_OPERATION_NUMBER 1
int opssat_pf_busswitches_setaccessmask_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_busswitches_setaccessmask_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_busswitches_setaccessmask_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_busswitches_setaccessmask_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_1(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor);
int opssat_pf_busswitches_setaccessmask_submit_encode_1(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element);
int opssat_pf_busswitches_setaccessmask_submit_decode_1(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res);
int opssat_pf_busswitches_setaccessmask_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_2(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int opssat_pf_busswitches_setaccessmask_submit_encode_2(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int opssat_pf_busswitches_setaccessmask_submit_decode_2(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int opssat_pf_busswitches_setaccessmask_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_busswitches_setaccessmask_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int opssat_pf_busswitches_setaccessmask_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_busswitches_setaccessmask_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_busswitches_setaccessmask_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int opssat_pf_busswitches_setaccessmask_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int opssat_pf_busswitches_setaccessmask_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_poweroffsbandtx
#define OPSSAT_PF_POWER_POWEROFFSBANDTX_OPERATION_NUMBER 1
int opssat_pf_power_poweroffsbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_poweroffsbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweroffsbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_poweroffsbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweroffsbandtx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_poweronsbandtx
#define OPSSAT_PF_POWER_POWERONSBANDTX_OPERATION_NUMBER 2
int opssat_pf_power_poweronsbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_poweronsbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweronsbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_poweronsbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweronsbandtx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_poweroffsbandrx
#define OPSSAT_PF_POWER_POWEROFFSBANDRX_OPERATION_NUMBER 3
int opssat_pf_power_poweroffsbandrx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_poweroffsbandrx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweroffsbandrx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_poweroffsbandrx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweroffsbandrx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_poweronsbandrx
#define OPSSAT_PF_POWER_POWERONSBANDRX_OPERATION_NUMBER 4
int opssat_pf_power_poweronsbandrx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_poweronsbandrx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweronsbandrx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_poweronsbandrx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweronsbandrx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_poweronxbandtx
#define OPSSAT_PF_POWER_POWERONXBANDTX_OPERATION_NUMBER 7
int opssat_pf_power_poweronxbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_poweronxbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_poweronxbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_poweronxbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_power_setpowerstate
#define OPSSAT_PF_POWER_SETPOWERSTATE_OPERATION_NUMBER 5
int opssat_pf_power_setpowerstate_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_setpowerstate_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor);
int opssat_pf_power_setpowerstate_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element);
int opssat_pf_power_setpowerstate_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res);
int opssat_pf_power_setpowerstate_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_setpowerstate_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int opssat_pf_power_setpowerstate_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int opssat_pf_power_setpowerstate_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int opssat_pf_power_setpowerstate_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_setpowerstate_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_power_setpowerstate_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_setpowerstate_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_setpowerstate_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int opssat_pf_power_setpowerstate_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int opssat_pf_power_setpowerstate_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_powercycle
#define OPSSAT_PF_POWER_POWERCYCLE_OPERATION_NUMBER 6
int opssat_pf_power_powercycle_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_powercycle_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor);
int opssat_pf_power_powercycle_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element);
int opssat_pf_power_powercycle_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res);
int opssat_pf_power_powercycle_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_powercycle_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor);
int opssat_pf_power_powercycle_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element);
int opssat_pf_power_powercycle_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_uoctet_list_t ** element_res);
int opssat_pf_power_powercycle_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_powercycle_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_power_powercycle_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_powercycle_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_powercycle_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int opssat_pf_power_powercycle_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int opssat_pf_power_powercycle_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_devicepoweron
#define OPSSAT_PF_POWER_DEVICEPOWERON_OPERATION_NUMBER 8
int opssat_pf_power_devicepoweron_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_devicepoweron_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element, void * cursor);
int opssat_pf_power_devicepoweron_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element);
int opssat_pf_power_devicepoweron_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_devices_t * element_res);
int opssat_pf_power_devicepoweron_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_devicepoweron_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_power_devicepoweron_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_power_devicepoweron_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_power_devicepoweron_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_devicepoweron_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_power_devicepoweron_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_devicepoweron_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_devicepoweron_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_power_devicepoweroff
#define OPSSAT_PF_POWER_DEVICEPOWEROFF_OPERATION_NUMBER 9
int opssat_pf_power_devicepoweroff_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_power_devicepoweroff_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element, void * cursor);
int opssat_pf_power_devicepoweroff_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element);
int opssat_pf_power_devicepoweroff_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_devices_t * element_res);
int opssat_pf_power_devicepoweroff_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_devicepoweroff_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_power_devicepoweroff_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_power_devicepoweroff_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_power_devicepoweroff_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_power_devicepoweroff_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_power_devicepoweroff_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_power_devicepoweroff_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_power_devicepoweroff_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_mode_gotomode
#define OPSSAT_PF_MODE_GOTOMODE_OPERATION_NUMBER 1
int opssat_pf_mode_gotomode_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_mode_gotomode_send_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element, void * cursor);
int opssat_pf_mode_gotomode_send_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element);
int opssat_pf_mode_gotomode_send_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_mode_systemmode_t * element_res);
int opssat_pf_mode_gotomode_send_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_mode_gotomode_send_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation opssat_pf_timemanagement_useautomatictime
#define OPSSAT_PF_TIMEMANAGEMENT_USEAUTOMATICTIME_OPERATION_NUMBER 1
int opssat_pf_timemanagement_useautomatictime_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_timemanagement_useautomatictime_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int opssat_pf_timemanagement_useautomatictime_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int opssat_pf_timemanagement_useautomatictime_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int opssat_pf_timemanagement_useautomatictime_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_timemanagement_useautomatictime_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_timemanagement_useautomatictime_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_timemanagement_useautomatictime_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_timemanagement_gettimemode
#define OPSSAT_PF_TIMEMANAGEMENT_GETTIMEMODE_OPERATION_NUMBER 2
int opssat_pf_timemanagement_gettimemode_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_timemanagement_gettimemode_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_timemanagement_gettimemode_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_timemanagement_gettimemode_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int opssat_pf_timemanagement_gettimemode_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int opssat_pf_timemanagement_gettimemode_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int opssat_pf_timemanagement_gettimemode_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_timemanagement_gettimemode_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation opssat_pf_timemanagement_applymanualtimeshift
#define OPSSAT_PF_TIMEMANAGEMENT_APPLYMANUALTIMESHIFT_OPERATION_NUMBER 3
int opssat_pf_timemanagement_applymanualtimeshift_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_timemanagement_applymanualtimeshift_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int opssat_pf_timemanagement_applymanualtimeshift_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int opssat_pf_timemanagement_applymanualtimeshift_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int opssat_pf_timemanagement_applymanualtimeshift_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_timemanagement_applymanualtimeshift_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_timemanagement_applymanualtimeshift_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_timemanagement_applymanualtimeshift_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_timemanagement_applymanualtimeshift_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_timemanagement_setmanualtime
#define OPSSAT_PF_TIMEMANAGEMENT_SETMANUALTIME_OPERATION_NUMBER 4
int opssat_pf_timemanagement_setmanualtime_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_timemanagement_setmanualtime_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int opssat_pf_timemanagement_setmanualtime_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int opssat_pf_timemanagement_setmanualtime_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_time_t * element_res);
int opssat_pf_timemanagement_setmanualtime_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_timemanagement_setmanualtime_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_timemanagement_setmanualtime_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_timemanagement_setmanualtime_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_timemanagement_setmanualtime_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_timemanagement_getcurrenttime
#define OPSSAT_PF_TIMEMANAGEMENT_GETCURRENTTIME_OPERATION_NUMBER 5
int opssat_pf_timemanagement_getcurrenttime_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_timemanagement_getcurrenttime_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_timemanagement_getcurrenttime_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_timemanagement_getcurrenttime_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor);
int opssat_pf_timemanagement_getcurrenttime_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element);
int opssat_pf_timemanagement_getcurrenttime_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_time_t * element_res);
int opssat_pf_timemanagement_getcurrenttime_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_timemanagement_getcurrenttime_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation opssat_pf_experimentwd_alive
#define OPSSAT_PF_EXPERIMENTWD_ALIVE_OPERATION_NUMBER 1
int opssat_pf_experimentwd_alive_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_experimentwd_alive_send_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_gps_getgpsdata
#define OPSSAT_PF_GPS_GETGPSDATA_OPERATION_NUMBER 1
int opssat_pf_gps_getgpsdata_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_gps_getgpsdata_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_gps_getgpsdata_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_gps_getgpsdata_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_gps_getgpsdata_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_gps_getgpsdata_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_gps_getgpsdata_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_gps_getgpsdata_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_gps_getgpsdata_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_gps_getgpsdata_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_gps_getgpsdata_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_gps_getgpsdata_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_gps_getgpsdata_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_gps_getgpsdata_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_gps_getgpsdata_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite OPSSAT_PF:CoarseADCS:OrbitTLEData

// generated code for operation opssat_pf_coarseadcs_setadcsmode
#define OPSSAT_PF_COARSEADCS_SETADCSMODE_OPERATION_NUMBER 1
int opssat_pf_coarseadcs_setadcsmode_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_coarseadcs_setadcsmode_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element, void * cursor);
int opssat_pf_coarseadcs_setadcsmode_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element);
int opssat_pf_coarseadcs_setadcsmode_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_coarseadcs_adcsmode_t * element_res);
int opssat_pf_coarseadcs_setadcsmode_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_coarseadcs_setadcsmode_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_coarseadcs_setadcsmode_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_coarseadcs_setadcsmode_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_coarseadcs_setadcsmode_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_coarseadcs_setnavtransmode
#define OPSSAT_PF_COARSEADCS_SETNAVTRANSMODE_OPERATION_NUMBER 2
int opssat_pf_coarseadcs_setnavtransmode_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_coarseadcs_setnavtransmode_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int opssat_pf_coarseadcs_setnavtransmode_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int opssat_pf_coarseadcs_setnavtransmode_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int opssat_pf_coarseadcs_setnavtransmode_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_coarseadcs_setnavtransmode_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_coarseadcs_setnavtransmode_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_coarseadcs_setnavtransmode_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_coarseadcs_uploadorbittle
#define OPSSAT_PF_COARSEADCS_UPLOADORBITTLE_OPERATION_NUMBER 4
int opssat_pf_coarseadcs_uploadorbittle_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_coarseadcs_uploadorbittle_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element, void * cursor);
int opssat_pf_coarseadcs_uploadorbittle_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element);
int opssat_pf_coarseadcs_uploadorbittle_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_coarseadcs_orbittledata_t ** element_res);
int opssat_pf_coarseadcs_uploadorbittle_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_coarseadcs_uploadorbittle_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_coarseadcs_uploadorbittle_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_coarseadcs_uploadorbittle_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_coarseadcs_uploadorbittle_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_coarseadcs_resetadcs
#define OPSSAT_PF_COARSEADCS_RESETADCS_OPERATION_NUMBER 5
int opssat_pf_coarseadcs_resetadcs_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_coarseadcs_resetadcs_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_coarseadcs_resetadcs_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_coarseadcs_resetadcs_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_coarseadcs_loadadcsparams
#define OPSSAT_PF_COARSEADCS_LOADADCSPARAMS_OPERATION_NUMBER 3
int opssat_pf_coarseadcs_loadadcsparams_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_coarseadcs_loadadcsparams_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_coarseadcs_loadadcsparams_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_coarseadcs_loadadcsparams_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_performhealthcheck
#define OPSSAT_PF_ADVANCEDOBC_PERFORMHEALTHCHECK_OPERATION_NUMBER 1
int opssat_pf_advancedobc_performhealthcheck_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_performhealthcheck_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor);
int opssat_pf_advancedobc_performhealthcheck_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element);
int opssat_pf_advancedobc_performhealthcheck_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_integer_t * element_res);
int opssat_pf_advancedobc_performhealthcheck_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_performhealthcheck_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_performhealthcheck_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_performhealthcheck_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_performhealthcheck_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_performhealthcheck_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_performhealthcheck_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_performhealthcheck_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_performhealthcheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_advancedobc_resetnanomindwdg
#define OPSSAT_PF_ADVANCEDOBC_RESETNANOMINDWDG_OPERATION_NUMBER 2
int opssat_pf_advancedobc_resetnanomindwdg_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_resetnanomindwdg_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_resetnanomindwdg_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_resetnanomindwdg_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_resetobsw
#define OPSSAT_PF_ADVANCEDOBC_RESETOBSW_OPERATION_NUMBER 3
int opssat_pf_advancedobc_resetobsw_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_resetobsw_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_resetobsw_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_resetobsw_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_readi2cpayload
#define OPSSAT_PF_ADVANCEDOBC_READI2CPAYLOAD_OPERATION_NUMBER 4
int opssat_pf_advancedobc_readi2cpayload_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_readi2cpayload_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_readi2cpayload_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_advancedobc_readi2cpayload_invoke_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_advancedobc_readi2cpayload_invoke_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_advancedobc_readi2cpayload_invoke_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cpayload_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int opssat_pf_advancedobc_readi2cpayload_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_readi2cpayload_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_readi2cpayload_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_readi2cpayload_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_readi2cpayload_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_readi2cpayload_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_readi2cpayload_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cpayload_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_readi2cpayload_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_advancedobc_writei2cpayload
#define OPSSAT_PF_ADVANCEDOBC_WRITEI2CPAYLOAD_OPERATION_NUMBER 5
int opssat_pf_advancedobc_writei2cpayload_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_writei2cpayload_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_writei2cpayload_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_writei2cpayload_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_writei2cpayload_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_writei2cpayload_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_writei2cpayload_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cpayload_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_advancedobc_writei2cpayload_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_writei2cpayload_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_writei2cpayload_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_writei2cpayload_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_writei2cpayload_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_writei2cpayload_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_writei2cpayload_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cpayload_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_writei2cpayload_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_advancedobc_resetepswatchdog
#define OPSSAT_PF_ADVANCEDOBC_RESETEPSWATCHDOG_OPERATION_NUMBER 6
int opssat_pf_advancedobc_resetepswatchdog_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_resetepswatchdog_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_resetepswatchdog_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_resetepswatchdog_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_enablecriticalcommands
#define OPSSAT_PF_ADVANCEDOBC_ENABLECRITICALCOMMANDS_OPERATION_NUMBER 7
int opssat_pf_advancedobc_enablecriticalcommands_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_enablecriticalcommands_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int opssat_pf_advancedobc_enablecriticalcommands_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int opssat_pf_advancedobc_enablecriticalcommands_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int opssat_pf_advancedobc_enablecriticalcommands_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_enablecriticalcommands_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_enablecriticalcommands_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_enablecriticalcommands_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_setbootimage
#define OPSSAT_PF_ADVANCEDOBC_SETBOOTIMAGE_OPERATION_NUMBER 8
int opssat_pf_advancedobc_setbootimage_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int opssat_pf_advancedobc_setbootimage_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int opssat_pf_advancedobc_setbootimage_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int opssat_pf_advancedobc_setbootimage_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int opssat_pf_advancedobc_setbootimage_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int opssat_pf_advancedobc_setbootimage_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res);
int opssat_pf_advancedobc_setbootimage_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_setbootimage_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_advancedobc_setbootimage_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_setbootimage_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation opssat_pf_advancedobc_readi2cbus
#define OPSSAT_PF_ADVANCEDOBC_READI2CBUS_OPERATION_NUMBER 9
int opssat_pf_advancedobc_readi2cbus_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_readi2cbus_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_readi2cbus_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor);
int opssat_pf_advancedobc_readi2cbus_invoke_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res);
int opssat_pf_advancedobc_readi2cbus_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cbus_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int opssat_pf_advancedobc_readi2cbus_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_readi2cbus_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_readi2cbus_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_readi2cbus_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_readi2cbus_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_readi2cbus_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_readi2cbus_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_readi2cbus_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_readi2cbus_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_advancedobc_writei2cbus
#define OPSSAT_PF_ADVANCEDOBC_WRITEI2CBUS_OPERATION_NUMBER 10
int opssat_pf_advancedobc_writei2cbus_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_writei2cbus_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_writei2cbus_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_writei2cbus_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int opssat_pf_advancedobc_writei2cbus_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int opssat_pf_advancedobc_writei2cbus_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int opssat_pf_advancedobc_writei2cbus_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cbus_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int opssat_pf_advancedobc_writei2cbus_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_writei2cbus_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int opssat_pf_advancedobc_writei2cbus_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_writei2cbus_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor);
int opssat_pf_advancedobc_writei2cbus_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element);
int opssat_pf_advancedobc_writei2cbus_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res);
int opssat_pf_advancedobc_writei2cbus_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_writei2cbus_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_writei2cbus_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation opssat_pf_advancedobc_reseti2ccontroller
#define OPSSAT_PF_ADVANCEDOBC_RESETI2CCONTROLLER_OPERATION_NUMBER 11
int opssat_pf_advancedobc_reseti2ccontroller_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int opssat_pf_advancedobc_reseti2ccontroller_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element, void * cursor);
int opssat_pf_advancedobc_reseti2ccontroller_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element);
int opssat_pf_advancedobc_reseti2ccontroller_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_i2cbus_t * element_res);
int opssat_pf_advancedobc_reseti2ccontroller_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int opssat_pf_advancedobc_reseti2ccontroller_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int opssat_pf_advancedobc_reseti2ccontroller_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int opssat_pf_advancedobc_reseti2ccontroller_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// test function
void opssat_pf_test(bool verbose);

#include "opssat_pf_onboarddevice_list.h"
#include "opssat_pf_devices_list.h"
#include "opssat_pf_i2cbus_list.h"
#include "opssat_pf_mode_systemmode_list.h"
#include "opssat_pf_coarseadcs_adcsmode_list.h"
#include "opssat_pf_coarseadcs_orbittledata.h"
#include "opssat_pf_coarseadcs_orbittledata_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __OPSSAT_PF_H_INCLUDED__
