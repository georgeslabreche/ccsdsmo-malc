#ifndef __SOFTWAREMANAGEMENT_H_INCLUDED__
#define __SOFTWAREMANAGEMENT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int softwaremanagement_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int softwaremanagement_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int softwaremanagement_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define SOFTWAREMANAGEMENT_AREA_NUMBER 7
#define SOFTWAREMANAGEMENT_AREA_VERSION 1

// standard service identifiers
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER 1

// generated code for composite SoftwareManagement:PackageManagement:PackageDefinition
#ifndef SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_T_DEFINED
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_T_DEFINED

typedef struct _softwaremanagement_packagemanagement_packagedefinition_t softwaremanagement_packagemanagement_packagedefinition_t;

#endif // SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_T_DEFINED

// short form for composite type SoftwareManagement:PackageManagement:PackageDefinition
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_SHORT_FORM 0x7000101000007L
#ifndef SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_T_DEFINED
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_T_DEFINED

typedef struct _softwaremanagement_packagemanagement_packagedefinition_list_t softwaremanagement_packagemanagement_packagedefinition_list_t;

#endif // SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_T_DEFINED

// short form for list of composite type SoftwareManagement:PackageManagement:PackageDefinition
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_SHORT_FORM 0x7000101fffff9L

// generated code for composite SoftwareManagement:PackageManagement:InstallationDetails
#ifndef SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_T_DEFINED
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_T_DEFINED

typedef struct _softwaremanagement_packagemanagement_installationdetails_t softwaremanagement_packagemanagement_installationdetails_t;

#endif // SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_T_DEFINED

// short form for composite type SoftwareManagement:PackageManagement:InstallationDetails
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_SHORT_FORM 0x7000101000008L
#ifndef SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_T_DEFINED
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_T_DEFINED

typedef struct _softwaremanagement_packagemanagement_installationdetails_list_t softwaremanagement_packagemanagement_installationdetails_list_t;

#endif // SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_T_DEFINED

// short form for list of composite type SoftwareManagement:PackageManagement:InstallationDetails
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_SHORT_FORM 0x7000101fffff8L

// standard service identifiers
#define SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER 2

// standard service identifiers
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_SERVICE_NUMBER 3

// generated code for composite SoftwareManagement:CommandExecutor:CommandDetails
#ifndef SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_T_DEFINED
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_T_DEFINED

typedef struct _softwaremanagement_commandexecutor_commanddetails_t softwaremanagement_commandexecutor_commanddetails_t;

#endif // SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_T_DEFINED

// short form for composite type SoftwareManagement:CommandExecutor:CommandDetails
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_SHORT_FORM 0x7000301000001L
#ifndef SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_T_DEFINED
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_T_DEFINED

typedef struct _softwaremanagement_commandexecutor_commanddetails_list_t softwaremanagement_commandexecutor_commanddetails_list_t;

#endif // SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_T_DEFINED

// short form for list of composite type SoftwareManagement:CommandExecutor:CommandDetails
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_SHORT_FORM 0x7000301ffffffL

// standard service identifiers
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER 5

// generated code for composite SoftwareManagement:AppsLauncher:AppDetails
#ifndef SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_T_DEFINED
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_T_DEFINED

typedef struct _softwaremanagement_appslauncher_appdetails_t softwaremanagement_appslauncher_appdetails_t;

#endif // SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_T_DEFINED

// short form for composite type SoftwareManagement:AppsLauncher:AppDetails
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_SHORT_FORM 0x7000501000001L
#ifndef SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_T_DEFINED
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_T_DEFINED

typedef struct _softwaremanagement_appslauncher_appdetails_list_t softwaremanagement_appslauncher_appdetails_list_t;

#endif // SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_T_DEFINED

// short form for list of composite type SoftwareManagement:AppsLauncher:AppDetails
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_SHORT_FORM 0x7000501ffffffL

// include required areas definitions
#include "com.h"
#include "common.h"
#include "mc.h"
#include "pf.h"

// generated code for composite SoftwareManagement:PackageManagement:PackageDefinition

// generated code for composite SoftwareManagement:PackageManagement:InstallationDetails

// generated code for operation softwaremanagement_packagemanagement_findpackage
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_FINDPACKAGE_OPERATION_NUMBER 1
int softwaremanagement_packagemanagement_findpackage_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_packagemanagement_findpackage_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_findpackage_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_findpackage_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_findpackage_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_findpackage_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_packagemanagement_findpackage_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_findpackage_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_findpackage_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_findpackage_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_findpackage_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int softwaremanagement_packagemanagement_findpackage_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int softwaremanagement_packagemanagement_findpackage_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_findpackage_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int softwaremanagement_packagemanagement_findpackage_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_findpackage_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int softwaremanagement_packagemanagement_findpackage_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_packagemanagement_install
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALL_OPERATION_NUMBER 2
int softwaremanagement_packagemanagement_install_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_packagemanagement_install_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_install_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_install_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_install_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_install_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_packagemanagement_install_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_install_invoke_ack_add_encoding_length_0(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_install_invoke_ack_encode_0(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int softwaremanagement_packagemanagement_install_invoke_ack_decode_0(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int softwaremanagement_packagemanagement_install_invoke_ack_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_install_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_packagemanagement_install_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_install_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_packagemanagement_install_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_install_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int softwaremanagement_packagemanagement_install_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_packagemanagement_uninstall
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UNINSTALL_OPERATION_NUMBER 3
int softwaremanagement_packagemanagement_uninstall_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_uninstall_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_uninstall_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_uninstall_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_uninstall_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int softwaremanagement_packagemanagement_uninstall_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int softwaremanagement_packagemanagement_uninstall_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_uninstall_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int softwaremanagement_packagemanagement_uninstall_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_uninstall_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_packagemanagement_uninstall_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_uninstall_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_packagemanagement_uninstall_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_uninstall_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int softwaremanagement_packagemanagement_uninstall_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_packagemanagement_upgrade
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UPGRADE_OPERATION_NUMBER 4
int softwaremanagement_packagemanagement_upgrade_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_packagemanagement_upgrade_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_upgrade_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_upgrade_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_upgrade_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_upgrade_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_packagemanagement_upgrade_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_upgrade_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_packagemanagement_upgrade_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_upgrade_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_packagemanagement_upgrade_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_upgrade_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int softwaremanagement_packagemanagement_upgrade_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_packagemanagement_checkpackageintegrity
#define SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_CHECKPACKAGEINTEGRITY_OPERATION_NUMBER 5
int softwaremanagement_packagemanagement_checkpackageintegrity_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int softwaremanagement_packagemanagement_checkpackageintegrity_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor);
int softwaremanagement_packagemanagement_checkpackageintegrity_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element);
int softwaremanagement_packagemanagement_checkpackageintegrity_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_heartbeat_beat
#define SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER 1
int softwaremanagement_heartbeat_beat_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_heartbeat_beat_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int softwaremanagement_heartbeat_beat_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_heartbeat_beat_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int softwaremanagement_heartbeat_beat_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_heartbeat_beat_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int softwaremanagement_heartbeat_beat_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation softwaremanagement_heartbeat_getperiod
#define SOFTWAREMANAGEMENT_HEARTBEAT_GETPERIOD_OPERATION_NUMBER 2
int softwaremanagement_heartbeat_getperiod_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_heartbeat_getperiod_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_heartbeat_getperiod_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_heartbeat_getperiod_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int softwaremanagement_heartbeat_getperiod_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int softwaremanagement_heartbeat_getperiod_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int softwaremanagement_heartbeat_getperiod_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_heartbeat_getperiod_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for composite SoftwareManagement:CommandExecutor:CommandDetails

// generated code for operation softwaremanagement_commandexecutor_runcommand
#define SOFTWAREMANAGEMENT_COMMANDEXECUTOR_RUNCOMMAND_OPERATION_NUMBER 1
int softwaremanagement_commandexecutor_runcommand_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_commandexecutor_runcommand_request_add_encoding_length_0(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor);
int softwaremanagement_commandexecutor_runcommand_request_encode_0(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element);
int softwaremanagement_commandexecutor_runcommand_request_decode_0(void * cursor, mal_decoder_t * decoder, softwaremanagement_commandexecutor_commanddetails_t ** element_res);
int softwaremanagement_commandexecutor_runcommand_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_commandexecutor_runcommand_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_commandexecutor_runcommand_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_commandexecutor_runcommand_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int softwaremanagement_commandexecutor_runcommand_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int softwaremanagement_commandexecutor_runcommand_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int softwaremanagement_commandexecutor_runcommand_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_commandexecutor_runcommand_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for composite SoftwareManagement:AppsLauncher:AppDetails

// generated code for operation softwaremanagement_appslauncher_monitorexecution
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER 1
int softwaremanagement_appslauncher_monitorexecution_update_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int softwaremanagement_appslauncher_monitorexecution_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int softwaremanagement_appslauncher_monitorexecution_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int softwaremanagement_appslauncher_monitorexecution_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_monitorexecution_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_appslauncher_monitorexecution_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int softwaremanagement_appslauncher_monitorexecution_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_appslauncher_monitorexecution_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int softwaremanagement_appslauncher_monitorexecution_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int softwaremanagement_appslauncher_monitorexecution_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int softwaremanagement_appslauncher_monitorexecution_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation softwaremanagement_appslauncher_runapp
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_RUNAPP_OPERATION_NUMBER 2
int softwaremanagement_appslauncher_runapp_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_appslauncher_runapp_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int softwaremanagement_appslauncher_runapp_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int softwaremanagement_appslauncher_runapp_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int softwaremanagement_appslauncher_runapp_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_runapp_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_appslauncher_runapp_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_runapp_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_appslauncher_runapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int softwaremanagement_appslauncher_runapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int softwaremanagement_appslauncher_runapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_appslauncher_killapp
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_KILLAPP_OPERATION_NUMBER 3
int softwaremanagement_appslauncher_killapp_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_appslauncher_killapp_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int softwaremanagement_appslauncher_killapp_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int softwaremanagement_appslauncher_killapp_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int softwaremanagement_appslauncher_killapp_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_killapp_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_appslauncher_killapp_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_killapp_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_appslauncher_killapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int softwaremanagement_appslauncher_killapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int softwaremanagement_appslauncher_killapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation softwaremanagement_appslauncher_stopapp
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_STOPAPP_OPERATION_NUMBER 4
int softwaremanagement_appslauncher_stopapp_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_appslauncher_stopapp_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int softwaremanagement_appslauncher_stopapp_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int softwaremanagement_appslauncher_stopapp_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int softwaremanagement_appslauncher_stopapp_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_stopapp_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_appslauncher_stopapp_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_stopapp_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int softwaremanagement_appslauncher_stopapp_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_stopapp_progress_update_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int softwaremanagement_appslauncher_stopapp_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int softwaremanagement_appslauncher_stopapp_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int softwaremanagement_appslauncher_stopapp_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_stopapp_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int softwaremanagement_appslauncher_stopapp_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_stopapp_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation softwaremanagement_appslauncher_listapp
#define SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER 5
int softwaremanagement_appslauncher_listapp_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int softwaremanagement_appslauncher_listapp_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int softwaremanagement_appslauncher_listapp_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int softwaremanagement_appslauncher_listapp_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int softwaremanagement_appslauncher_listapp_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int softwaremanagement_appslauncher_listapp_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_t ** element_res);
int softwaremanagement_appslauncher_listapp_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_listapp_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int softwaremanagement_appslauncher_listapp_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int softwaremanagement_appslauncher_listapp_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int softwaremanagement_appslauncher_listapp_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int softwaremanagement_appslauncher_listapp_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int softwaremanagement_appslauncher_listapp_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int softwaremanagement_appslauncher_listapp_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int softwaremanagement_appslauncher_listapp_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int softwaremanagement_appslauncher_listapp_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int softwaremanagement_appslauncher_listapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int softwaremanagement_appslauncher_listapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int softwaremanagement_appslauncher_listapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// test function
void softwaremanagement_test(bool verbose);

#include "softwaremanagement_packagemanagement_packagedefinition.h"
#include "softwaremanagement_packagemanagement_packagedefinition_list.h"
#include "softwaremanagement_packagemanagement_installationdetails.h"
#include "softwaremanagement_packagemanagement_installationdetails_list.h"
#include "softwaremanagement_commandexecutor_commanddetails.h"
#include "softwaremanagement_commandexecutor_commanddetails_list.h"
#include "softwaremanagement_appslauncher_appdetails.h"
#include "softwaremanagement_appslauncher_appdetails_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SOFTWAREMANAGEMENT_H_INCLUDED__
