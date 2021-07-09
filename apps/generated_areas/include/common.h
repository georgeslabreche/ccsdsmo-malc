#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int common_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int common_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int common_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define COMMON_AREA_NUMBER 3
#define COMMON_AREA_VERSION 1

// generated code for composite Common:_:ServiceKey
#ifndef COMMON_SERVICEKEY_T_DEFINED
#define COMMON_SERVICEKEY_T_DEFINED

typedef struct _common_servicekey_t common_servicekey_t;

#endif // COMMON_SERVICEKEY_T_DEFINED

// short form for composite type Common:_:ServiceKey
#define COMMON_SERVICEKEY_SHORT_FORM 0x3000001000001L
#ifndef COMMON_SERVICEKEY_LIST_T_DEFINED
#define COMMON_SERVICEKEY_LIST_T_DEFINED

typedef struct _common_servicekey_list_t common_servicekey_list_t;

#endif // COMMON_SERVICEKEY_LIST_T_DEFINED

// short form for list of composite type Common:_:ServiceKey
#define COMMON_SERVICEKEY_LIST_SHORT_FORM 0x3000001ffffffL

// standard service identifiers
#define COMMON_DIRECTORY_SERVICE_NUMBER 1

// generated code for composite Common:Directory:ProviderDetails
#ifndef COMMON_DIRECTORY_PROVIDERDETAILS_T_DEFINED
#define COMMON_DIRECTORY_PROVIDERDETAILS_T_DEFINED

typedef struct _common_directory_providerdetails_t common_directory_providerdetails_t;

#endif // COMMON_DIRECTORY_PROVIDERDETAILS_T_DEFINED

// short form for composite type Common:Directory:ProviderDetails
#define COMMON_DIRECTORY_PROVIDERDETAILS_SHORT_FORM 0x3000101000001L
#ifndef COMMON_DIRECTORY_PROVIDERDETAILS_LIST_T_DEFINED
#define COMMON_DIRECTORY_PROVIDERDETAILS_LIST_T_DEFINED

typedef struct _common_directory_providerdetails_list_t common_directory_providerdetails_list_t;

#endif // COMMON_DIRECTORY_PROVIDERDETAILS_LIST_T_DEFINED

// short form for list of composite type Common:Directory:ProviderDetails
#define COMMON_DIRECTORY_PROVIDERDETAILS_LIST_SHORT_FORM 0x3000101ffffffL

// generated code for composite Common:Directory:ServiceCapability
#ifndef COMMON_DIRECTORY_SERVICECAPABILITY_T_DEFINED
#define COMMON_DIRECTORY_SERVICECAPABILITY_T_DEFINED

typedef struct _common_directory_servicecapability_t common_directory_servicecapability_t;

#endif // COMMON_DIRECTORY_SERVICECAPABILITY_T_DEFINED

// short form for composite type Common:Directory:ServiceCapability
#define COMMON_DIRECTORY_SERVICECAPABILITY_SHORT_FORM 0x3000101000002L
#ifndef COMMON_DIRECTORY_SERVICECAPABILITY_LIST_T_DEFINED
#define COMMON_DIRECTORY_SERVICECAPABILITY_LIST_T_DEFINED

typedef struct _common_directory_servicecapability_list_t common_directory_servicecapability_list_t;

#endif // COMMON_DIRECTORY_SERVICECAPABILITY_LIST_T_DEFINED

// short form for list of composite type Common:Directory:ServiceCapability
#define COMMON_DIRECTORY_SERVICECAPABILITY_LIST_SHORT_FORM 0x3000101fffffeL

// generated code for composite Common:Directory:AddressDetails
#ifndef COMMON_DIRECTORY_ADDRESSDETAILS_T_DEFINED
#define COMMON_DIRECTORY_ADDRESSDETAILS_T_DEFINED

typedef struct _common_directory_addressdetails_t common_directory_addressdetails_t;

#endif // COMMON_DIRECTORY_ADDRESSDETAILS_T_DEFINED

// short form for composite type Common:Directory:AddressDetails
#define COMMON_DIRECTORY_ADDRESSDETAILS_SHORT_FORM 0x3000101000004L
#ifndef COMMON_DIRECTORY_ADDRESSDETAILS_LIST_T_DEFINED
#define COMMON_DIRECTORY_ADDRESSDETAILS_LIST_T_DEFINED

typedef struct _common_directory_addressdetails_list_t common_directory_addressdetails_list_t;

#endif // COMMON_DIRECTORY_ADDRESSDETAILS_LIST_T_DEFINED

// short form for list of composite type Common:Directory:AddressDetails
#define COMMON_DIRECTORY_ADDRESSDETAILS_LIST_SHORT_FORM 0x3000101fffffcL

// generated code for composite Common:Directory:ProviderSummary
#ifndef COMMON_DIRECTORY_PROVIDERSUMMARY_T_DEFINED
#define COMMON_DIRECTORY_PROVIDERSUMMARY_T_DEFINED

typedef struct _common_directory_providersummary_t common_directory_providersummary_t;

#endif // COMMON_DIRECTORY_PROVIDERSUMMARY_T_DEFINED

// short form for composite type Common:Directory:ProviderSummary
#define COMMON_DIRECTORY_PROVIDERSUMMARY_SHORT_FORM 0x3000101000005L
#ifndef COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_T_DEFINED
#define COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_T_DEFINED

typedef struct _common_directory_providersummary_list_t common_directory_providersummary_list_t;

#endif // COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_T_DEFINED

// short form for list of composite type Common:Directory:ProviderSummary
#define COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_SHORT_FORM 0x3000101fffffbL

// generated code for composite Common:Directory:PublishDetails
#ifndef COMMON_DIRECTORY_PUBLISHDETAILS_T_DEFINED
#define COMMON_DIRECTORY_PUBLISHDETAILS_T_DEFINED

typedef struct _common_directory_publishdetails_t common_directory_publishdetails_t;

#endif // COMMON_DIRECTORY_PUBLISHDETAILS_T_DEFINED

// short form for composite type Common:Directory:PublishDetails
#define COMMON_DIRECTORY_PUBLISHDETAILS_SHORT_FORM 0x3000101000006L
#ifndef COMMON_DIRECTORY_PUBLISHDETAILS_LIST_T_DEFINED
#define COMMON_DIRECTORY_PUBLISHDETAILS_LIST_T_DEFINED

typedef struct _common_directory_publishdetails_list_t common_directory_publishdetails_list_t;

#endif // COMMON_DIRECTORY_PUBLISHDETAILS_LIST_T_DEFINED

// short form for list of composite type Common:Directory:PublishDetails
#define COMMON_DIRECTORY_PUBLISHDETAILS_LIST_SHORT_FORM 0x3000101fffffaL

// generated code for composite Common:Directory:ServiceFilter
#ifndef COMMON_DIRECTORY_SERVICEFILTER_T_DEFINED
#define COMMON_DIRECTORY_SERVICEFILTER_T_DEFINED

typedef struct _common_directory_servicefilter_t common_directory_servicefilter_t;

#endif // COMMON_DIRECTORY_SERVICEFILTER_T_DEFINED

// short form for composite type Common:Directory:ServiceFilter
#define COMMON_DIRECTORY_SERVICEFILTER_SHORT_FORM 0x3000101000007L
#ifndef COMMON_DIRECTORY_SERVICEFILTER_LIST_T_DEFINED
#define COMMON_DIRECTORY_SERVICEFILTER_LIST_T_DEFINED

typedef struct _common_directory_servicefilter_list_t common_directory_servicefilter_list_t;

#endif // COMMON_DIRECTORY_SERVICEFILTER_LIST_T_DEFINED

// short form for list of composite type Common:Directory:ServiceFilter
#define COMMON_DIRECTORY_SERVICEFILTER_LIST_SHORT_FORM 0x3000101fffff9L

// standard service identifiers
#define COMMON_LOGIN_SERVICE_NUMBER 2

// generated code for composite Common:Login:Profile
#ifndef COMMON_LOGIN_PROFILE_T_DEFINED
#define COMMON_LOGIN_PROFILE_T_DEFINED

typedef struct _common_login_profile_t common_login_profile_t;

#endif // COMMON_LOGIN_PROFILE_T_DEFINED

// short form for composite type Common:Login:Profile
#define COMMON_LOGIN_PROFILE_SHORT_FORM 0x3000201000001L
#ifndef COMMON_LOGIN_PROFILE_LIST_T_DEFINED
#define COMMON_LOGIN_PROFILE_LIST_T_DEFINED

typedef struct _common_login_profile_list_t common_login_profile_list_t;

#endif // COMMON_LOGIN_PROFILE_LIST_T_DEFINED

// short form for list of composite type Common:Login:Profile
#define COMMON_LOGIN_PROFILE_LIST_SHORT_FORM 0x3000201ffffffL

// standard service identifiers
#define COMMON_CONFIGURATION_SERVICE_NUMBER 5

// generated code for enumeration common_configuration_configurationtype
typedef enum {
  COMMON_CONFIGURATION_CONFIGURATIONTYPE_PROVIDER,
  COMMON_CONFIGURATION_CONFIGURATIONTYPE_SERVICE
} common_configuration_configurationtype_t;

// short form for enumeration type common_configuration_configurationtype
#define COMMON_CONFIGURATION_CONFIGURATIONTYPE_SHORT_FORM 0x3000501000004L
#ifndef COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_T_DEFINED
#define COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_T_DEFINED

typedef struct _common_configuration_configurationtype_list_t common_configuration_configurationtype_list_t;

#endif // COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_T_DEFINED

// short form for list of enumeration type common_configuration_configurationtype
#define COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_SHORT_FORM 0x3000501fffffcL

// generated code for composite Common:Configuration:ConfigurationObjectSet
#ifndef COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_T_DEFINED
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_T_DEFINED

typedef struct _common_configuration_configurationobjectset_t common_configuration_configurationobjectset_t;

#endif // COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_T_DEFINED

// short form for composite type Common:Configuration:ConfigurationObjectSet
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_SHORT_FORM 0x3000501000001L
#ifndef COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_T_DEFINED
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_T_DEFINED

typedef struct _common_configuration_configurationobjectset_list_t common_configuration_configurationobjectset_list_t;

#endif // COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_T_DEFINED

// short form for list of composite type Common:Configuration:ConfigurationObjectSet
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_SHORT_FORM 0x3000501ffffffL

// generated code for composite Common:Configuration:ConfigurationObjectDetails
#ifndef COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_T_DEFINED
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_T_DEFINED

typedef struct _common_configuration_configurationobjectdetails_t common_configuration_configurationobjectdetails_t;

#endif // COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_T_DEFINED

// short form for composite type Common:Configuration:ConfigurationObjectDetails
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_SHORT_FORM 0x3000501000002L
#ifndef COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_T_DEFINED
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_T_DEFINED

typedef struct _common_configuration_configurationobjectdetails_list_t common_configuration_configurationobjectdetails_list_t;

#endif // COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_T_DEFINED

// short form for list of composite type Common:Configuration:ConfigurationObjectDetails
#define COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_SHORT_FORM 0x3000501fffffeL

// generated code for composite Common:Configuration:ServiceConfigurationIdentifier
#ifndef COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_T_DEFINED
#define COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_T_DEFINED

typedef struct _common_configuration_serviceconfigurationidentifier_t common_configuration_serviceconfigurationidentifier_t;

#endif // COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_T_DEFINED

// short form for composite type Common:Configuration:ServiceConfigurationIdentifier
#define COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_SHORT_FORM 0x3000501000003L
#ifndef COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_T_DEFINED
#define COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_T_DEFINED

typedef struct _common_configuration_serviceconfigurationidentifier_list_t common_configuration_serviceconfigurationidentifier_list_t;

#endif // COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_T_DEFINED

// short form for list of composite type Common:Configuration:ServiceConfigurationIdentifier
#define COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_SHORT_FORM 0x3000501fffffdL

// include required areas definitions
#include "com.h"
#include "mc.h"
#include "pf.h"
#include "softwaremanagement.h"

// generated code for composite Common:_:ServiceKey

// generated code for composite Common:Directory:ProviderDetails

// generated code for composite Common:Directory:ServiceCapability

// generated code for composite Common:Directory:AddressDetails

// generated code for composite Common:Directory:ProviderSummary

// generated code for composite Common:Directory:PublishDetails

// generated code for composite Common:Directory:ServiceFilter

// generated code for operation common_directory_lookupprovider
#define COMMON_DIRECTORY_LOOKUPPROVIDER_OPERATION_NUMBER 1
int common_directory_lookupprovider_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_directory_lookupprovider_request_add_encoding_length_0(mal_encoder_t * encoder, common_directory_servicefilter_t * element, void * cursor);
int common_directory_lookupprovider_request_encode_0(void * cursor, mal_encoder_t * encoder, common_directory_servicefilter_t * element);
int common_directory_lookupprovider_request_decode_0(void * cursor, mal_decoder_t * decoder, common_directory_servicefilter_t ** element_res);
int common_directory_lookupprovider_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_lookupprovider_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_lookupprovider_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_directory_lookupprovider_request_response_add_encoding_length_0(mal_encoder_t * encoder, common_directory_providersummary_list_t * element, void * cursor);
int common_directory_lookupprovider_request_response_encode_0(void * cursor, mal_encoder_t * encoder, common_directory_providersummary_list_t * element);
int common_directory_lookupprovider_request_response_decode_0(void * cursor, mal_decoder_t * decoder, common_directory_providersummary_list_t ** element_res);
int common_directory_lookupprovider_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_lookupprovider_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_lookupprovider_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_directory_publishprovider
#define COMMON_DIRECTORY_PUBLISHPROVIDER_OPERATION_NUMBER 2
int common_directory_publishprovider_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_directory_publishprovider_request_add_encoding_length_0(mal_encoder_t * encoder, common_directory_publishdetails_t * element, void * cursor);
int common_directory_publishprovider_request_encode_0(void * cursor, mal_encoder_t * encoder, common_directory_publishdetails_t * element);
int common_directory_publishprovider_request_decode_0(void * cursor, mal_decoder_t * decoder, common_directory_publishdetails_t ** element_res);
int common_directory_publishprovider_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_publishprovider_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_publishprovider_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_directory_publishprovider_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_directory_publishprovider_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_directory_publishprovider_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_directory_publishprovider_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_publishprovider_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_directory_publishprovider_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_directory_publishprovider_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_directory_publishprovider_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_publishprovider_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_directory_publishprovider_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_directory_withdrawprovider
#define COMMON_DIRECTORY_WITHDRAWPROVIDER_OPERATION_NUMBER 3
int common_directory_withdrawprovider_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_directory_withdrawprovider_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_directory_withdrawprovider_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_directory_withdrawprovider_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_directory_withdrawprovider_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_withdrawprovider_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_withdrawprovider_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_directory_withdrawprovider_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_directory_withdrawprovider_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_directory_getservicexml
#define COMMON_DIRECTORY_GETSERVICEXML_OPERATION_NUMBER 4
int common_directory_getservicexml_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_directory_getservicexml_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_directory_getservicexml_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_directory_getservicexml_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_directory_getservicexml_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_getservicexml_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_getservicexml_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_directory_getservicexml_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_file_list_t * element, void * cursor);
int common_directory_getservicexml_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_file_list_t * element);
int common_directory_getservicexml_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_file_list_t ** element_res);
int common_directory_getservicexml_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_directory_getservicexml_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_directory_getservicexml_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite Common:Login:Profile

// generated code for operation common_login_login
#define COMMON_LOGIN_LOGIN_OPERATION_NUMBER 1
int common_login_login_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_login_login_request_add_encoding_length_0(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int common_login_login_request_encode_0(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int common_login_login_request_decode_0(void * cursor, mal_decoder_t * decoder, common_login_profile_t ** element_res);
int common_login_login_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_login_request_add_encoding_length_1(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int common_login_login_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int common_login_login_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int common_login_login_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_login_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_login_login_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_login_login_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int common_login_login_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int common_login_login_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int common_login_login_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_login_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_login_login_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_login_login_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_login_login_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_login_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_login_login_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_login_logout
#define COMMON_LOGIN_LOGOUT_OPERATION_NUMBER 2
int common_login_logout_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_login_logout_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_login_logout_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_login_logout_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation common_login_listroles
#define COMMON_LOGIN_LISTROLES_OPERATION_NUMBER 3
int common_login_listroles_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_login_listroles_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int common_login_listroles_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int common_login_listroles_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_t ** element_res);
int common_login_listroles_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_listroles_request_add_encoding_length_1(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int common_login_listroles_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int common_login_listroles_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int common_login_listroles_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_listroles_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_login_listroles_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_login_listroles_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int common_login_listroles_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int common_login_listroles_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int common_login_listroles_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_listroles_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_login_listroles_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_login_handover
#define COMMON_LOGIN_HANDOVER_OPERATION_NUMBER 4
int common_login_handover_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_login_handover_request_add_encoding_length_0(mal_encoder_t * encoder, common_login_profile_t * element, void * cursor);
int common_login_handover_request_encode_0(void * cursor, mal_encoder_t * encoder, common_login_profile_t * element);
int common_login_handover_request_decode_0(void * cursor, mal_decoder_t * decoder, common_login_profile_t ** element_res);
int common_login_handover_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_handover_request_add_encoding_length_1(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int common_login_handover_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int common_login_handover_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int common_login_handover_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_handover_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_login_handover_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_login_handover_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int common_login_handover_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int common_login_handover_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int common_login_handover_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_handover_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int common_login_handover_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int common_login_handover_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int common_login_handover_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_login_handover_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_login_handover_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite Common:Configuration:ConfigurationObjectSet

// generated code for composite Common:Configuration:ConfigurationObjectDetails

// generated code for composite Common:Configuration:ServiceConfigurationIdentifier

// generated code for operation common_configuration_activate
#define COMMON_CONFIGURATION_ACTIVATE_OPERATION_NUMBER 1
int common_configuration_activate_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_activate_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int common_configuration_activate_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int common_configuration_activate_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objectkey_t ** element_res);
int common_configuration_activate_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_activate_invoke_add_encoding_length_1(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int common_configuration_activate_invoke_encode_1(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int common_configuration_activate_invoke_decode_1(void * cursor, mal_decoder_t * decoder, com_objectid_t ** element_res);
int common_configuration_activate_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_activate_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_activate_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_activate_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_configuration_activate_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_activate_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int common_configuration_activate_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int common_configuration_activate_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int common_configuration_activate_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_activate_invoke_response_add_encoding_length_1(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int common_configuration_activate_invoke_response_encode_1(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int common_configuration_activate_invoke_response_decode_1(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int common_configuration_activate_invoke_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_activate_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_activate_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_list
#define COMMON_CONFIGURATION_LIST_OPERATION_NUMBER 2
int common_configuration_list_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_list_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element, void * cursor);
int common_configuration_list_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, common_configuration_configurationtype_t element);
int common_configuration_list_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, common_configuration_configurationtype_t * element_res);
int common_configuration_list_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_list_request_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int common_configuration_list_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int common_configuration_list_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int common_configuration_list_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_list_request_add_encoding_length_2(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int common_configuration_list_request_encode_2(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
int common_configuration_list_request_decode_2(void * cursor, mal_decoder_t * decoder, common_servicekey_t ** element_res);
int common_configuration_list_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_list_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int common_configuration_list_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_list_request_response_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int common_configuration_list_request_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int common_configuration_list_request_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int common_configuration_list_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_list_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_list_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_getcurrent
#define COMMON_CONFIGURATION_GETCURRENT_OPERATION_NUMBER 3
int common_configuration_getcurrent_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_getcurrent_request_add_encoding_length_0(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int common_configuration_getcurrent_request_encode_0(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int common_configuration_getcurrent_request_decode_0(void * cursor, mal_decoder_t * decoder, com_objectkey_t ** element_res);
int common_configuration_getcurrent_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_getcurrent_request_add_encoding_length_1(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int common_configuration_getcurrent_request_encode_1(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
int common_configuration_getcurrent_request_decode_1(void * cursor, mal_decoder_t * decoder, common_servicekey_t ** element_res);
int common_configuration_getcurrent_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_getcurrent_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_getcurrent_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_getcurrent_request_response_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int common_configuration_getcurrent_request_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int common_configuration_getcurrent_request_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int common_configuration_getcurrent_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_getcurrent_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_getcurrent_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_exportxml
#define COMMON_CONFIGURATION_EXPORTXML_OPERATION_NUMBER 4
int common_configuration_exportxml_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_exportxml_request_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int common_configuration_exportxml_request_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int common_configuration_exportxml_request_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_t ** element_res);
int common_configuration_exportxml_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_exportxml_request_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int common_configuration_exportxml_request_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int common_configuration_exportxml_request_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int common_configuration_exportxml_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_exportxml_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_exportxml_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_exportxml_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int common_configuration_exportxml_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int common_configuration_exportxml_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_file_t ** element_res);
int common_configuration_exportxml_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_exportxml_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_exportxml_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_add
#define COMMON_CONFIGURATION_ADD_OPERATION_NUMBER 5
int common_configuration_add_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_add_submit_add_encoding_length_0(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int common_configuration_add_submit_encode_0(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int common_configuration_add_submit_decode_0(void * cursor, mal_decoder_t * decoder, com_objectkey_t ** element_res);
int common_configuration_add_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_add_submit_add_encoding_length_1(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int common_configuration_add_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int common_configuration_add_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int common_configuration_add_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_add_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_add_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_add_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_configuration_add_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int common_configuration_add_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int common_configuration_add_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_remove
#define COMMON_CONFIGURATION_REMOVE_OPERATION_NUMBER 6
int common_configuration_remove_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_remove_submit_add_encoding_length_0(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int common_configuration_remove_submit_encode_0(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int common_configuration_remove_submit_decode_0(void * cursor, mal_decoder_t * decoder, com_objectkey_t ** element_res);
int common_configuration_remove_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_remove_submit_add_encoding_length_1(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int common_configuration_remove_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int common_configuration_remove_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int common_configuration_remove_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_remove_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int common_configuration_remove_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_remove_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_configuration_remove_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int common_configuration_remove_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int common_configuration_remove_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_storecurrent
#define COMMON_CONFIGURATION_STORECURRENT_OPERATION_NUMBER 7
int common_configuration_storecurrent_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_storecurrent_invoke_add_encoding_length_0(mal_encoder_t * encoder, com_objectkey_t * element, void * cursor);
int common_configuration_storecurrent_invoke_encode_0(void * cursor, mal_encoder_t * encoder, com_objectkey_t * element);
int common_configuration_storecurrent_invoke_decode_0(void * cursor, mal_decoder_t * decoder, com_objectkey_t ** element_res);
int common_configuration_storecurrent_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_storecurrent_invoke_add_encoding_length_1(mal_encoder_t * encoder, common_servicekey_t * element, void * cursor);
int common_configuration_storecurrent_invoke_encode_1(void * cursor, mal_encoder_t * encoder, common_servicekey_t * element);
int common_configuration_storecurrent_invoke_decode_1(void * cursor, mal_decoder_t * decoder, common_servicekey_t ** element_res);
int common_configuration_storecurrent_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_storecurrent_invoke_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int common_configuration_storecurrent_invoke_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int common_configuration_storecurrent_invoke_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int common_configuration_storecurrent_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_storecurrent_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int common_configuration_storecurrent_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_storecurrent_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int common_configuration_storecurrent_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_storecurrent_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int common_configuration_storecurrent_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int common_configuration_storecurrent_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_t ** element_res);
int common_configuration_storecurrent_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_storecurrent_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_storecurrent_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation common_configuration_importxml
#define COMMON_CONFIGURATION_IMPORTXML_OPERATION_NUMBER 8
int common_configuration_importxml_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int common_configuration_importxml_request_add_encoding_length_0(mal_encoder_t * encoder, mal_file_t * element, void * cursor);
int common_configuration_importxml_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_file_t * element);
int common_configuration_importxml_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_file_t ** element_res);
int common_configuration_importxml_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_importxml_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_importxml_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int common_configuration_importxml_request_response_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_t * element, void * cursor);
int common_configuration_importxml_request_response_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_t * element);
int common_configuration_importxml_request_response_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_t ** element_res);
int common_configuration_importxml_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int common_configuration_importxml_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int common_configuration_importxml_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// test function
void common_test(bool verbose);

#include "common_servicekey.h"
#include "common_servicekey_list.h"
#include "common_directory_providerdetails.h"
#include "common_directory_providerdetails_list.h"
#include "common_directory_servicecapability.h"
#include "common_directory_servicecapability_list.h"
#include "common_directory_addressdetails.h"
#include "common_directory_addressdetails_list.h"
#include "common_directory_providersummary.h"
#include "common_directory_providersummary_list.h"
#include "common_directory_publishdetails.h"
#include "common_directory_publishdetails_list.h"
#include "common_directory_servicefilter.h"
#include "common_directory_servicefilter_list.h"
#include "common_login_profile.h"
#include "common_login_profile_list.h"
#include "common_configuration_configurationtype_list.h"
#include "common_configuration_configurationobjectset.h"
#include "common_configuration_configurationobjectset_list.h"
#include "common_configuration_configurationobjectdetails.h"
#include "common_configuration_configurationobjectdetails_list.h"
#include "common_configuration_serviceconfigurationidentifier.h"
#include "common_configuration_serviceconfigurationidentifier_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __COMMON_H_INCLUDED__
