/*
 */

#ifndef __MAL_H_INCLUDED__
#define __MAL_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "clog.h"

#include "malattributes.h"
#include "malbinary.h"

//  MAL API version macros for compile-time API detection

#define MAL_VERSION_MAJOR 1
#define MAL_VERSION_MINOR 0
#define MAL_VERSION_PATCH 0

#define MAL_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MAL_VERSION \
    MAL_MAKE_VERSION(MAL_VERSION_MAJOR, MAL_VERSION_MINOR, MAL_VERSION_PATCH)

extern clog_logger_t mal_logger;

void mal_set_log_level(int level);

#define MAL_AREA_NUMBER 1
#define MAL_AREA_VERSION 1

#define MAL_IP_STAGE_SEND 1
#define MAL_IP_STAGE_SUBMIT 1
#define MAL_IP_STAGE_SUBMIT_ACK 2
#define MAL_IP_STAGE_REQUEST 1
#define MAL_IP_STAGE_REQUEST_RESPONSE 2
#define MAL_IP_STAGE_INVOKE 1
#define MAL_IP_STAGE_INVOKE_ACK 2
#define MAL_IP_STAGE_INVOKE_RESPONSE 3
#define MAL_IP_STAGE_PROGRESS 1
#define MAL_IP_STAGE_PROGRESS_ACK 2
#define MAL_IP_STAGE_PROGRESS_UPDATE 3
#define MAL_IP_STAGE_PROGRESS_RESPONSE 4
#define MAL_IP_STAGE_PUBSUB_REGISTER 1
#define MAL_IP_STAGE_PUBSUB_REGISTER_ACK 2
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER 3
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK 4
#define MAL_IP_STAGE_PUBSUB_PUBLISH 5
#define MAL_IP_STAGE_PUBSUB_NOTIFY 6
#define MAL_IP_STAGE_PUBSUB_DEREGISTER 7
#define MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK 8
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER 9
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK 10

typedef struct _mal_ctx_t mal_ctx_t;
typedef struct _mal_message_t mal_message_t;
typedef struct _mal_poller_t mal_poller_t;
typedef struct _mal_endpoint_t mal_endpoint_t;
typedef struct _mal_list_t mal_list_t;
typedef struct _mal_enum_list_t mal_enum_list_t;
typedef struct _mal_subscription_t mal_subscription_t;
typedef struct _mal_entitykey_t mal_entitykey_t;
typedef struct _mal_entityrequest_t mal_entityrequest_t;
typedef struct _mal_element_holder_t mal_element_holder_t;
typedef struct _mal_updateheader_t mal_updateheader_t;

typedef struct _mal_integer_list_t mal_integer_list_t;
typedef struct _mal_interactiontype_list_t mal_interactiontype_list_t;
typedef struct _mal_identifier_list_t mal_identifier_list_t;
typedef struct _mal_string_list_t mal_string_list_t;
typedef struct _mal_blob_list_t mal_blob_list_t;
typedef struct _mal_entityrequest_list_t mal_entityrequest_list_t;
typedef struct _mal_entitykey_list_t mal_entitykey_list_t;
typedef struct _mal_updateheader_list_t mal_updateheader_list_t;
typedef struct _mal_boolean_list_t mal_boolean_list_t;

typedef enum {
  MAL_INTERACTIONTYPE_SEND,
  MAL_INTERACTIONTYPE_SUBMIT,
  MAL_INTERACTIONTYPE_REQUEST,
  MAL_INTERACTIONTYPE_INVOKE,
  MAL_INTERACTIONTYPE_PROGRESS,
  MAL_INTERACTIONTYPE_PUBSUB,
} mal_interactiontype_t;

typedef enum {
  MAL_SESSIONTYPE_LIVE, MAL_SESSIONTYPE_SIMULATION, MAL_SESSIONTYPE_REPLAY
} mal_sessiontype_t;

typedef enum {
  MAL_QOSLEVEL_BESTEFFORT,
  MAL_QOSLEVEL_ASSURED,
  MAL_QOSLEVEL_QUEUED,
  MAL_QOSLEVEL_TIMELY
} mal_qoslevel_t;

typedef enum {
  MAL_UPDATETYPE_CREATION,
  MAL_UPDATETYPE_UPDATE,
  MAL_UPDATETYPE_MODIFICATION,
  MAL_UPDATETYPE_DELETION
} mal_updatetype_t;

union mal_element_t {
  mal_blob_t *blob_value;
  mal_boolean_t boolean_value;
  mal_double_t double_value;
  mal_float_t float_value;
  mal_octet_t octet_value;
  mal_uoctet_t uoctet_value;
  mal_short_t short_value;
  mal_ushort_t ushort_value;
  mal_integer_t integer_value;
  mal_uinteger_t uinteger_value;
  mal_long_t long_value;
  mal_ulong_t ulong_value;
  mal_string_t *string_value;
  mal_identifier_t *identifier_value;
  mal_uri_t *uri_value;
  mal_time_t time_value;
  mal_finetime_t finetime_value;
  mal_duration_t duration_value;
  int enumerated_value;
  void *composite_value;
  void *list_value;
};

// TODO: We should create specific list for each type (as for boolean, integer or string for
// example). So mal_list_t and mal_enum_list_t should be deleted as they are not useful.
typedef mal_list_t mal_octet_list_t;
typedef mal_list_t mal_uoctet_list_t;
typedef mal_list_t mal_short_list_t;
typedef mal_list_t mal_ushort_list_t;
typedef mal_list_t mal_uinteger_list_t;
typedef mal_list_t mal_long_list_t;
typedef mal_list_t mal_ulong_list_t;
typedef mal_list_t mal_time_list_t;
typedef mal_list_t mal_fine_time_list_t;
typedef mal_list_t mal_duration_list_t;
typedef mal_list_t mal_uri_list_t;
typedef mal_enum_list_t mal_sessiontype_list_t;
typedef mal_enum_list_t mal_qoslevel_list_t;
typedef mal_enum_list_t mal_updatetype_list_t;

// Function to be provided by a MAL binding to create a URI
typedef mal_uri_t *mal_binding_ctx_create_uri_fn(void *mal_binding_ctx, char *id);

// Function to be provided by a MAL binding to create an MAL end-point
typedef void *mal_binding_ctx_create_endpoint_fn(void *mal_binding_ctx, mal_endpoint_t *mal_endpoint);

// Function to be provided by a MAL binding to destroy an MAL end-point
typedef void mal_binding_ctx_destroy_endpoint_fn(void *mal_binding_ctx, void **endpoint_p);

// Function to be provided by a MAL binding to create a MAL poller
typedef void *mal_binding_ctx_create_poller_fn(void *mal_binding_ctx, mal_poller_t *mal_poller);

// Function to be provided by a MAL binding to destroy a MAL poller
typedef void mal_binding_ctx_destroy_poller_fn(void *mal_binding_ctx, void **poller_p);

// Function to be provided by a MAL binding to add an end-point to a MAL poller
typedef int mal_binding_ctx_poller_add_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Function to be provided by a MAL binding to remove an end-point to a MAL poller
typedef int mal_binding_ctx_poller_del_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

// Function to be provided by a MAL binding to send a message
typedef int mal_binding_ctx_send_message_fn(
    void *mal_binding_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message);

// Function to be provided by a MAL binding to receive a message
typedef int mal_binding_ctx_recv_message_fn(
    void *mal_binding_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t **message);

// Function to be provided by a MAL binding to wait on a MAL poller
typedef int mal_binding_ctx_poller_wait_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller, mal_endpoint_t **mal_endpoint, int timeout);

// Function to be provided by a MAL binding to destroy a message
typedef int mal_binding_ctx_destroy_message_fn(void *mal_binding_ctx, mal_message_t *message);

int mal_register_add_encoding_length(int encoding_format_code, void *encoder,
    mal_subscription_t *element, unsigned int *encoding_length);

int mal_register_encode(int encoding_format_code, char *bytes,
    unsigned int *offset, void *encoder, mal_subscription_t *element);

int mal_register_decode(int encoding_format_code, char *bytes,
    unsigned int *offset, void *decoder, mal_subscription_t **res);

int mal_publish_register_add_encoding_length_entitykey_list(
    int encoding_format_code, void *encoder, mal_entitykey_list_t *element,
    unsigned int *encoding_length);

int mal_publish_register_encode_entitykey_list(int encoding_format_code,
    char *bytes, unsigned int *offset, void *encoder,
    mal_entitykey_list_t *element);

int mal_publish_decode_entitykey_list(int encoding_format_code, char *bytes,
    unsigned int *offset, void *decoder, mal_entitykey_list_t **res);

int mal_publish_add_encoding_length_updateheader_list(int encoding_format_code,
    void *encoder, mal_updateheader_list_t *element,
    unsigned int *encoding_length);

int mal_publish_encode_updateheader_list(int encoding_format_code, char *bytes,
    unsigned int *offset, void *encoder, mal_updateheader_list_t *element);

int mal_publish_decode_updateheader_list(int encoding_format_code, char *bytes,
    unsigned int *offset, void *decoder, mal_updateheader_list_t **res);

/*
int mal_notify_decode_subscriptionid(int encoding_format_code, char *bytes,
    unsigned int *offset, void *decoder, mal_identifier_t **res);
*/

int mal_notify_decode_updateheader_list(int encoding_format_code, char *bytes,
    unsigned int *offset, void *decoder, mal_updateheader_list_t **res);

#define MAL_ERROR       0x01000000
#define MALZMQ_ERROR    0x02000000

#define MAL_ROUTING_NO_HANDLER                  -(MAL_ERROR|0x00000001)
#define MAL_ROUTING_BAD_IP_STAGE                -(MAL_ERROR|0x00000002)
#define MAL_ROUTING_UNKNOW_INTERACTION_TYPE     -(MAL_ERROR|0x00000003)

#define MAL_ROUTING_NO_HANDLER_MSG              " *** mal_routing_handle: Error NO HANDLER CORRESPONDING TO THIS MESSAGE"
#define MAL_ROUTING_BAD_IP_STAGE_MSG            " *** mal_routing_handle: Error BAD IP STAGE"
#define MAL_ROUTING_UNKNOW_INTERACTION_TYPE_MSG " *** mal_routing_handle: Error UNKNOW INTERACTION TYPE"

#define MALZMQ_BAD_INTERACTION_STAGE            -(MALZMQ_ERROR|0x00000001)
#define MALZMQ_BAD_INTERACTION_TYPE             -(MALZMQ_ERROR|0x00000002)
#define MALZMQ_BAD_SDU_TYPE                     -(MALZMQ_ERROR|0x00000003)

#define MALZMQ_BAD_INTERACTION_STAGE_MSG        " *** malzmq_decode_message: Error BAD IP STAGE"
#define MALZMQ_BAD_INTERACTION_TYPE_MSG         " *** malzmq_decode_message: Error BAD INTERACTION TYPE"
#define MALZMQ_BAD_SDU_TYPE_MSG                 " *** malzmq_encode_message: Error BAD SDU TYPE"

void mal_test(bool verbose);

//  Public API classes
#include "mal_ctx.h"
#include "mal_endpoint.h"
#include "mal_poller.h"
#include "mal_list.h"
#include "mal_enum_list.h"
#include "mal_integer_list.h"
#include "mal_identifier_list.h"
#include "mal_blob_list.h"
#include "mal_entitykey.h"
#include "mal_string_list.h"
#include "mal_interactiontype_list.h"
#include "mal_entityrequest_list.h"
#include "mal_entitykey_list.h"
#include "mal_updateheader_list.h"
#include "mal_subscription.h"
#include "mal_entityrequest.h"
#include "mal_message.h"
#include "mal_updateheader.h"
#include "mal_element_holder.h"
#include "mal_boolean_list.h"
#include "mal_routing.h"

#ifdef __cplusplus
}
#endif

#endif
