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

/*
 */

#ifndef __MAL_H_INCLUDED__
#define __MAL_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include <malattributes.h>

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

// generated code for enumeration mal_interactiontype
typedef enum {
  MAL_INTERACTIONTYPE_SEND,
  MAL_INTERACTIONTYPE_SUBMIT,
  MAL_INTERACTIONTYPE_REQUEST,
  MAL_INTERACTIONTYPE_INVOKE,
  MAL_INTERACTIONTYPE_PROGRESS,
  MAL_INTERACTIONTYPE_PUBSUB
} mal_interactiontype_t;

// short form for enumeration type mal_interactiontype
#define MAL_INTERACTIONTYPE_SHORT_FORM 0x1000001000013L

// short form for list of enumeration type mal_interactiontype
#define MAL_INTERACTIONTYPE_LIST_SHORT_FORM 0x1000001ffffedL

// generated code for enumeration mal_sessiontype
typedef enum {
  MAL_SESSIONTYPE_LIVE,
  MAL_SESSIONTYPE_SIMULATION,
  MAL_SESSIONTYPE_REPLAY
} mal_sessiontype_t;

// short form for enumeration type mal_sessiontype
#define MAL_SESSIONTYPE_SHORT_FORM 0x1000001000014L

// short form for list of enumeration type mal_sessiontype
#define MAL_SESSIONTYPE_LIST_SHORT_FORM 0x1000001ffffecL

// generated code for enumeration mal_qoslevel
typedef enum {
  MAL_QOSLEVEL_BESTEFFORT,
  MAL_QOSLEVEL_ASSURED,
  MAL_QOSLEVEL_QUEUED,
  MAL_QOSLEVEL_TIMELY
} mal_qoslevel_t;

// short form for enumeration type mal_qoslevel
#define MAL_QOSLEVEL_SHORT_FORM 0x1000001000015L

// short form for list of enumeration type mal_qoslevel
#define MAL_QOSLEVEL_LIST_SHORT_FORM 0x1000001ffffebL

// generated code for enumeration mal_updatetype
typedef enum {
  MAL_UPDATETYPE_CREATION,
  MAL_UPDATETYPE_UPDATE,
  MAL_UPDATETYPE_MODIFICATION,
  MAL_UPDATETYPE_DELETION
} mal_updatetype_t;

// short form for enumeration type mal_updatetype
#define MAL_UPDATETYPE_SHORT_FORM 0x1000001000016L

// short form for list of enumeration type mal_updatetype
#define MAL_UPDATETYPE_LIST_SHORT_FORM 0x1000001ffffeaL

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

#include "mal_library.h"

extern clog_logger_t mal_logger;

void mal_set_log_level(int level);

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding API
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ******/

int mal_register_add_encoding_length(mal_encoder_t *encoder,
    mal_subscription_t *element, void *cursor);

int mal_register_encode(void *cursor, mal_encoder_t *encoder, mal_subscription_t *element);

int mal_register_decode(void *cursor, mal_decoder_t *decoder, mal_subscription_t **res);

int mal_deregister_add_encoding_length(mal_encoder_t *encoder,
    mal_identifier_list_t *element, void *cursor);

int mal_deregister_encode(void *cursor, mal_encoder_t *encoder, mal_identifier_list_t *element);

int mal_deregister_decode(void *cursor, mal_decoder_t *decoder, mal_identifier_list_t **res);

int mal_publish_register_add_encoding_length_entitykey_list(
    mal_encoder_t *encoder, mal_entitykey_list_t *element,
    void *cursor);

int mal_publish_deregister_add_encoding_length_entitykey_list(
    mal_encoder_t *encoder, mal_entitykey_list_t *element,
    void *cursor);

int mal_publish_register_encode_entitykey_list(
    void *cursor, mal_encoder_t *encoder,
    mal_entitykey_list_t *element);

int mal_publish_deregister_encode_entitykey_list(
    void *cursor, mal_encoder_t *encoder,
    mal_entitykey_list_t *element);

int mal_publish_decode_entitykey_list(void *cursor, mal_decoder_t *decoder, mal_entitykey_list_t **res);

int mal_publish_add_encoding_length_updateheader_list(mal_encoder_t *encoder, mal_updateheader_list_t *element,
    void *cursor);

int mal_publish_encode_updateheader_list(void *cursor, mal_encoder_t *encoder, mal_updateheader_list_t *element);

int mal_publish_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res);

/*
int mal_notify_decode_subscriptionid(char *bytes,
    unsigned int *offset, mal_decoder_t *decoder, mal_identifier_t **res);
*/

int mal_notify_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res);

#define MAL_ERROR       0x01000000
#define MALZMQ_ERROR    0x02000000

#define MAL_ROUTING_NO_HANDLER                  -(MAL_ERROR|0x00000001)
#define MAL_ROUTING_BAD_IP_STAGE                -(MAL_ERROR|0x00000002)
#define MAL_ROUTING_UNKNOW_INTERACTION_TYPE     -(MAL_ERROR|0x00000003)

#define MAL_ROUTING_NO_HANDLER_MSG              " *** mal_routing_handle: Error NO HANDLER CORRESPONDING TO THIS MESSAGE"
#define MAL_ROUTING_BAD_IP_STAGE_MSG            " *** mal_routing_handle: Error BAD IP STAGE"
#define MAL_ROUTING_UNKNOW_INTERACTION_TYPE_MSG " *** mal_routing_handle: Error UNKNOW INTERACTION TYPE"

// TODO (AF): Be careful these constants are also used in MALTCP!
#define MALZMQ_BAD_INTERACTION_STAGE            -(MALZMQ_ERROR|0x00000001)
#define MALZMQ_BAD_INTERACTION_TYPE             -(MALZMQ_ERROR|0x00000002)
#define MALZMQ_BAD_SDU_TYPE                     -(MALZMQ_ERROR|0x00000003)

#define MALZMQ_BAD_INTERACTION_STAGE_MSG        " *** malzmq_decode_message: Error BAD IP STAGE"
#define MALZMQ_BAD_INTERACTION_TYPE_MSG         " *** malzmq_decode_message: Error BAD INTERACTION TYPE"
#define MALZMQ_BAD_SDU_TYPE_MSG                 " *** malzmq_encode_message: Error BAD SDU TYPE"


// short form for composite type MAL:_:Subscription
#define MAL_SUBSCRIPTION_SHORT_FORM 0x1000001000017L

// short form for list of composite type MAL:_:Subscription
#define MAL_SUBSCRIPTION_LIST_SHORT_FORM 0x1000001ffffe9L

// short form for composite type MAL:_:EntityRequest
#define MAL_ENTITYREQUEST_SHORT_FORM 0x1000001000018L

// short form for list of composite type MAL:_:EntityRequest
#define MAL_ENTITYREQUEST_LIST_SHORT_FORM 0x1000001ffffe8L

// short form for composite type MAL:_:EntityKey
#define MAL_ENTITYKEY_SHORT_FORM 0x1000001000019L

// short form for list of composite type MAL:_:EntityKey
#define MAL_ENTITYKEY_LIST_SHORT_FORM 0x1000001ffffe7L

// short form for composite type MAL:_:UpdateHeader
#define MAL_UPDATEHEADER_SHORT_FORM 0x100000100001aL

// short form for list of composite type MAL:_:UpdateHeader
#define MAL_UPDATEHEADER_LIST_SHORT_FORM 0x1000001ffffe6L

// generated code for composite MAL:_:IdBooleanPair
// short form for composite type MAL:_:IdBooleanPair
#define MAL_IDBOOLEANPAIR_SHORT_FORM 0x100000100001bL

// short form for list of composite type MAL:_:IdBooleanPair
#define MAL_IDBOOLEANPAIR_LIST_SHORT_FORM 0x1000001ffffe5L

// generated code for composite MAL:_:Pair
// short form for composite type MAL:_:Pair
#define MAL_PAIR_SHORT_FORM 0x100000100001cL

// short form for list of composite type MAL:_:Pair
#define MAL_PAIR_LIST_SHORT_FORM 0x1000001ffffe4L

// generated code for composite MAL:_:NamedValue
// short form for composite type MAL:_:NamedValue
#define MAL_NAMEDVALUE_SHORT_FORM 0x100000100001dL

// short form for list of composite type MAL:_:NamedValue
#define MAL_NAMEDVALUE_LIST_SHORT_FORM 0x1000001ffffe3L

// generated code for composite MAL:_:File
// short form for composite type MAL:_:File
#define MAL_FILE_SHORT_FORM 0x100000100001eL

// short form for list of composite type MAL:_:File
#define MAL_FILE_LIST_SHORT_FORM 0x1000001ffffe2L

void mal_message_set_log_level(int level);

void mal_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
