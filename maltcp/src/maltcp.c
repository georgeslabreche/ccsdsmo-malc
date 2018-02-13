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

/* */
#include "maltcp.h"

clog_logger_t maltcp_logger = CLOG_DEBUG_LEVEL;

void maltcp_set_log_level(int level) {
  maltcp_logger = level;
}

typedef enum {
  MAL_SDUTYPE_SEND=0,
  MAL_SDUTYPE_SUBMIT,
  MAL_SDUTYPE_SUBMIT_ACK,
  MAL_SDUTYPE_REQUEST,
  MAL_SDUTYPE_REQUEST_RESPONSE,
  MAL_SDUTYPE_INVOKE,
  MAL_SDUTYPE_INVOKE_ACK,
  MAL_SDUTYPE_INVOKE_RESPONSE,
  MAL_SDUTYPE_PROGRESS,
  MAL_SDUTYPE_PROGRESS_ACK,
  MAL_SDUTYPE_PROGRESS_UPDATE,
  MAL_SDUTYPE_PROGRESS_RESPONSE,
  MAL_SDUTYPE_PUBSUB_REGISTER,
  MAL_SDUTYPE_PUBSUB_REGISTER_ACK,
  MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER,
  MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER_ACK,
  MAL_SDUTYPE_PUBSUB_PUBLISH,
  MAL_SDUTYPE_PUBSUB_NOTIFY,
  MAL_SDUTYPE_PUBSUB_DEREGISTER,
  MAL_SDUTYPE_PUBSUB_DEREGISTER_ACK,
  MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER,
  MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER_ACK,
} mal_sdutype_t;

static int convert_to_sdu_type(mal_interactiontype_t type, mal_uoctet_t stage) {
  switch (type) {
  case MAL_INTERACTIONTYPE_SEND:
    return MAL_SDUTYPE_SEND;
  case MAL_INTERACTIONTYPE_SUBMIT:
    if (stage == MAL_IP_STAGE_SUBMIT) {
      return MAL_SDUTYPE_SUBMIT;
    } else {
      return MAL_SDUTYPE_SUBMIT_ACK;
    }
  case MAL_INTERACTIONTYPE_REQUEST:
    if (stage == MAL_IP_STAGE_REQUEST) {
      return MAL_SDUTYPE_REQUEST;
    } else {
      return MAL_SDUTYPE_REQUEST_RESPONSE;
    }
  case MAL_INTERACTIONTYPE_INVOKE:
    if (stage == MAL_IP_STAGE_INVOKE) {
      return MAL_SDUTYPE_INVOKE;
    } else if (stage == MAL_IP_STAGE_INVOKE_ACK) {
      return MAL_SDUTYPE_INVOKE_ACK;
    } else {
      return MAL_SDUTYPE_INVOKE_RESPONSE;
    }
  case MAL_INTERACTIONTYPE_PROGRESS:
    if (stage == MAL_IP_STAGE_PROGRESS) {
      return MAL_SDUTYPE_PROGRESS;
    } else if (stage == MAL_IP_STAGE_PROGRESS_ACK) {
      return MAL_SDUTYPE_PROGRESS_ACK;
    } else if (stage == MAL_IP_STAGE_PROGRESS_UPDATE) {
      return MAL_SDUTYPE_PROGRESS_UPDATE;
    } else {
      return MAL_SDUTYPE_PROGRESS_RESPONSE;
    }
  case MAL_INTERACTIONTYPE_PUBSUB:
    if (stage == MAL_IP_STAGE_PUBSUB_REGISTER) {
      return MAL_SDUTYPE_PUBSUB_REGISTER;
    } else if (stage == MAL_IP_STAGE_PUBSUB_REGISTER_ACK) {
      return MAL_SDUTYPE_PUBSUB_REGISTER_ACK;
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER) {
      return MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER;
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK) {
      return MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER_ACK;
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH) {
      return MAL_SDUTYPE_PUBSUB_PUBLISH;
    } else if (stage == MAL_IP_STAGE_PUBSUB_NOTIFY) {
      return MAL_SDUTYPE_PUBSUB_NOTIFY;
    } else if (stage == MAL_IP_STAGE_PUBSUB_DEREGISTER) {
      return MAL_SDUTYPE_PUBSUB_DEREGISTER;
    } else if (stage == MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK) {
      return MAL_SDUTYPE_PUBSUB_DEREGISTER_ACK;
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER) {
      return MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER;
    } else if (stage == MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK) {
      return MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER_ACK;
    } else {
      return -1;
    }
  default:
    return -1;
  }
}

static mal_interactiontype_t convert_to_interaction_type(int sduType) {
  switch (sduType) {
  case MAL_SDUTYPE_SEND:
    return MAL_INTERACTIONTYPE_SEND;
  case MAL_SDUTYPE_SUBMIT:
  case MAL_SDUTYPE_SUBMIT_ACK:
    return MAL_INTERACTIONTYPE_SUBMIT;
  case MAL_SDUTYPE_REQUEST:
  case MAL_SDUTYPE_REQUEST_RESPONSE:
    return MAL_INTERACTIONTYPE_REQUEST;
  case MAL_SDUTYPE_INVOKE:
  case MAL_SDUTYPE_INVOKE_ACK:
  case MAL_SDUTYPE_INVOKE_RESPONSE:
    return MAL_INTERACTIONTYPE_INVOKE;
  case MAL_SDUTYPE_PROGRESS:
  case MAL_SDUTYPE_PROGRESS_ACK:
  case MAL_SDUTYPE_PROGRESS_UPDATE:
  case MAL_SDUTYPE_PROGRESS_RESPONSE:
    return MAL_INTERACTIONTYPE_PROGRESS;
  case MAL_SDUTYPE_PUBSUB_REGISTER:
  case MAL_SDUTYPE_PUBSUB_DEREGISTER:
  case MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER:
  case MAL_SDUTYPE_PUBSUB_PUBLISH:
  case MAL_SDUTYPE_PUBSUB_NOTIFY:
  case MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER:
  case MAL_SDUTYPE_PUBSUB_REGISTER_ACK:
  case MAL_SDUTYPE_PUBSUB_DEREGISTER_ACK:
  case MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER_ACK:
  case MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER_ACK:
    return MAL_INTERACTIONTYPE_PUBSUB;
  default:
    return (mal_interactiontype_t) -1;
  }
}

static mal_uoctet_t convert_to_interaction_stage(int sduType) {
  switch (sduType) {
  case MAL_SDUTYPE_SEND:
    return MAL_IP_STAGE_SEND;
  case MAL_SDUTYPE_SUBMIT:
    return MAL_IP_STAGE_SUBMIT;
  case MAL_SDUTYPE_REQUEST:
    return MAL_IP_STAGE_REQUEST;
  case MAL_SDUTYPE_INVOKE:
    return MAL_IP_STAGE_INVOKE;
  case MAL_SDUTYPE_PROGRESS:
    return MAL_IP_STAGE_PROGRESS;
  case MAL_SDUTYPE_PUBSUB_REGISTER:
    return MAL_IP_STAGE_PUBSUB_REGISTER;
  case MAL_SDUTYPE_PUBSUB_DEREGISTER:
    return MAL_IP_STAGE_PUBSUB_DEREGISTER;
  case MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER:
    return MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER;
  case MAL_SDUTYPE_PUBSUB_PUBLISH:
    return MAL_IP_STAGE_PUBSUB_PUBLISH;
  case MAL_SDUTYPE_PUBSUB_NOTIFY:
    return MAL_IP_STAGE_PUBSUB_NOTIFY;
  case MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER:
    return MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER;
  case MAL_SDUTYPE_SUBMIT_ACK:
    return MAL_IP_STAGE_SUBMIT_ACK;
  case MAL_SDUTYPE_REQUEST_RESPONSE:
    return MAL_IP_STAGE_REQUEST_RESPONSE;
  case MAL_SDUTYPE_INVOKE_ACK:
    return MAL_IP_STAGE_INVOKE_ACK;
  case MAL_SDUTYPE_INVOKE_RESPONSE:
    return MAL_IP_STAGE_INVOKE_RESPONSE;
  case MAL_SDUTYPE_PROGRESS_ACK:
    return MAL_IP_STAGE_PROGRESS_ACK;
  case MAL_SDUTYPE_PROGRESS_UPDATE:
    return MAL_IP_STAGE_PROGRESS_UPDATE;
  case MAL_SDUTYPE_PROGRESS_RESPONSE:
    return MAL_IP_STAGE_PROGRESS_RESPONSE;
  case MAL_SDUTYPE_PUBSUB_REGISTER_ACK:
    return MAL_IP_STAGE_PUBSUB_REGISTER_ACK;
  case MAL_SDUTYPE_PUBSUB_DEREGISTER_ACK:
    return MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK;
  case MAL_SDUTYPE_PUBSUB_PUBLISH_REGISTER_ACK:
    return MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK;
  case MAL_SDUTYPE_PUBSUB_PUBLISH_DEREGISTER_ACK:
    return MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK;
  default:
    return -1;
  }
}

// internal functions, should not be visible from outside this module
int maltcp_add_string_encoding_length(mal_string_t *to_encode, mal_encoder_t *encoder,
    void *cursor) {
  return malbinary_encoder_add_string_encoding_length(encoder, to_encode, cursor);
}

int maltcp_add_uri_encoding_length(mal_uri_t *to_encode, mal_encoder_t *encoder,
    void *cursor) {
  return maltcp_add_string_encoding_length(to_encode, encoder, cursor);
}

int maltcp_add_identifier_encoding_length(mal_identifier_t *to_encode, mal_encoder_t *encoder,
    void *cursor) {
  return maltcp_add_string_encoding_length(to_encode, encoder, cursor);
}

int maltcp_add_identifier_list_encoding_length(mal_identifier_list_t *to_encode,
     mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  // Presence flags
  ((malbinary_cursor_t *) cursor)->body_length += list_size;
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    if (list_element != NULL) {
      rc = maltcp_add_identifier_encoding_length(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int maltcp_add_message_encoding_length(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_encoder_t *encoder,
    void *cursor) {
  int rc = 0;

  clog_debug(mal_encoder_get_logger(encoder), "maltcp_add_message_encoding_length()\n");

  ((malbinary_cursor_t *) cursor)->body_length += FIXED_HEADER_LENGTH;

  // always encode 'URI From' and 'URI To'
  rc = maltcp_add_uri_encoding_length(maltcp_get_service_from_uri(mal_message_get_uri_from(message)), encoder, cursor);
  if (rc < 0) return rc;
  char *uri_to = maltcp_get_service_from_uri(mal_message_get_uri_to(message));
  if (strlen(uri_to) > 0)
    rc = maltcp_add_uri_encoding_length(uri_to, encoder, cursor);
  if (rc < 0) return rc;

  bool priority_flag = maltcp_header_get_priority_flag(maltcp_header);
  bool timestamp_flag = maltcp_header_get_timestamp_flag(maltcp_header);
  bool network_zone_flag = maltcp_header_get_network_zone_flag(maltcp_header);
  bool session_name_flag = maltcp_header_get_session_name_flag(maltcp_header);
  bool domain_flag = maltcp_header_get_domain_flag(maltcp_header);
  bool authentication_id_flag = maltcp_header_get_authentication_id_flag(
      maltcp_header);

  if (priority_flag > 0) {
    rc = malbinary_encoder_add_uinteger_encoding_length(encoder,
        mal_message_get_priority(message), cursor);
    if (rc < 0) return rc;
  }

  if (timestamp_flag > 0) {
    rc = malbinary_encoder_add_time_encoding_length(encoder,
        mal_message_get_timestamp(message), cursor);
    if (rc < 0) return rc;
  }

  if (network_zone_flag > 0) {
    rc = maltcp_add_identifier_encoding_length(mal_message_get_network_zone(message),
        encoder, cursor);
    if (rc < 0) return rc;
  }

  if (session_name_flag > 0) {
    rc = maltcp_add_identifier_encoding_length(mal_message_get_session_name(message),
        encoder, cursor);
    if (rc < 0) return rc;
  }

  if (domain_flag > 0) {
    rc = maltcp_add_identifier_list_encoding_length(mal_message_get_domain(message),
        encoder, cursor);
    if (rc < 0) return rc;
  }

  if (authentication_id_flag > 0) {
    rc = malbinary_encoder_add_blob_encoding_length(encoder,
        mal_message_get_authentication_id(message), cursor);
    if (rc < 0) return rc;
  }

  ((malbinary_cursor_t *) cursor)->body_length += mal_message_get_body_length(message);

  return rc;
}

int maltcp_encode_uri(mal_uri_t *to_encode, mal_encoder_t *encoder, void *cursor) {
  return malbinary_encoder_encode_string(encoder, cursor, to_encode);
}

int maltcp_encode_identifier(mal_identifier_t *to_encode, mal_encoder_t *encoder, void *cursor) {
  return malbinary_encoder_encode_string(encoder, cursor, to_encode);
}

int maltcp_encode_identifier_list(mal_identifier_list_t *to_encode, mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  malbinary_encoder_encode_list_size(encoder, cursor, list_size);
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
        presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = maltcp_encode_identifier(list_element, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int maltcp_encode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_encoder_t *encoder, void *cursor) {
  clog_debug(mal_encoder_get_logger(encoder), "maltcp_encode_message()\n");

  int sdu_type = convert_to_sdu_type(
      mal_message_get_interaction_type(message),
      mal_message_get_interaction_stage(message));

  if ((sdu_type & 0xFFFFFFE0) != 0) {
    clog_error(maltcp_logger, MALZMQ_BAD_SDU_TYPE_MSG);
    return MALZMQ_BAD_SDU_TYPE;
  }

  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = (char) ((maltcp_header_get_version(maltcp_header) << 5)
      | sdu_type);

  malbinary_write16(mal_message_get_service_area(message), cursor);
  malbinary_write16(mal_message_get_service(message), cursor);
  malbinary_write16(mal_message_get_operation(message), cursor);
  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = mal_message_get_area_version(message);

  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = (char) ((mal_message_is_error_message(message) << 7)
      | (mal_message_get_qoslevel(message) << 4)
      | (mal_message_get_session(message)));

  malbinary_write64(mal_message_get_transaction_id(message), cursor);

  bool source_flag = true;

  char *uri_to = maltcp_get_service_from_uri(mal_message_get_uri_to(message));
  bool destination_flag = (strlen(uri_to) > 0);

  // TODO (AF): We could use a static byte field for all flags rather than separate
  // boolean fields for each flags.
  bool priority_flag = maltcp_header_get_priority_flag(maltcp_header);
  bool timestamp_flag = maltcp_header_get_timestamp_flag(maltcp_header);
  bool network_zone_flag = maltcp_header_get_network_zone_flag(maltcp_header);
  if (mal_message_get_network_zone(message) == NULL)
    network_zone_flag = false;
  bool session_name_flag = maltcp_header_get_session_name_flag(maltcp_header);
  if (mal_message_get_session_name(message) == NULL)
    session_name_flag = false;
  bool domain_flag = maltcp_header_get_domain_flag(maltcp_header);
  if (mal_message_get_domain(message) == NULL)
    domain_flag = false;
  bool authentication_id_flag = maltcp_header_get_authentication_id_flag(maltcp_header);
  if (mal_message_get_authentication_id(message) == NULL)
    authentication_id_flag = false;
  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] =
      (char) (source_flag << 7) | (destination_flag << 6) |
             (priority_flag << 5) |
             (timestamp_flag << 4) |
             (network_zone_flag << 3) |
             (session_name_flag << 2) |
             (domain_flag << 1) |
             (authentication_id_flag << 0);

  malbinary_write(mal_message_get_encoding_id((message)), cursor);

  // This field will be fixed later with the variable length of the message.
  malbinary_cursor_t cursor_bl;
  malbinary_cursor_copy((malbinary_cursor_t *) cursor, &cursor_bl);
  ((malbinary_cursor_t *) cursor)->body_offset += 4;

  // Always encode 'URI From'
  maltcp_encode_uri(maltcp_get_service_from_uri(mal_message_get_uri_from(message)), encoder, cursor);
  // Only encode the end part of the URI if it exist.
  if (destination_flag != false)
    maltcp_encode_uri(uri_to, encoder, cursor);

  if (priority_flag != false) {
    malbinary_encoder_encode_uinteger(encoder, cursor,
        mal_message_get_priority(message));
  }

  if (timestamp_flag != false) {
    malbinary_encoder_encode_time(encoder, cursor,
        mal_message_get_timestamp(message));
  }

  if (network_zone_flag != false) {
    maltcp_encode_identifier(mal_message_get_network_zone(message), encoder, cursor);
  }

  if (session_name_flag != false) {
    maltcp_encode_identifier(mal_message_get_session_name(message), encoder, cursor);
  }

  if (domain_flag != false) {
    maltcp_encode_identifier_list(mal_message_get_domain(message), encoder, cursor);
  }

  if (authentication_id_flag != false) {
    malbinary_encoder_encode_blob(encoder, cursor, mal_message_get_authentication_id(message));
  }

  // Copy the body in the frame.
  unsigned int body_length = mal_message_get_body_length(message);
  if (body_length > 0) {
    char *body = mal_message_get_body(message);
    unsigned int body_offset = mal_message_get_body_offset(message);

    char *bytes = ((malbinary_cursor_t *) cursor)->body_ptr;
    unsigned int index = ((malbinary_cursor_t *) cursor)->body_offset;

    memcpy(bytes + index, body + body_offset, body_length);
    ((malbinary_cursor_t *) cursor)->body_offset += body_length;
  }

  // According to the specification this field contains the variable length of the PDU.
  int msg_len = malbinary_cursor_get_offset((malbinary_cursor_t *) cursor);
  malbinary_write32(msg_len - FIXED_HEADER_LENGTH, &cursor_bl);
  clog_debug(maltcp_logger, "--- message_length = %u\n" , msg_len);

  return 0;
}

int maltcp_decode_uri(mal_decoder_t *decoder, void *cursor, mal_uri_t **result) {
  return malbinary_decoder_decode_string(decoder, cursor, result);
}

int maltcp_decode_uris(maltcp_header_t *maltcp_header,
    mal_decoder_t *decoder, char *bytes, unsigned int length,
    mal_uri_t **uri_to,
    mal_uri_t **uri_from) {
  // Note: We could use virtual allocation and initialization functions from encoder
  // rather than malbinary interface.
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor, bytes, length, 0);

  // 'URI To' offset
  // +1 byte: version + sdu type
  // +2 bytes: service area
  // +2 bytes: service
  // +2 bytes: operation
  // +1 bytes: area version
  // +1 bytes: is error message + qos level + session
  // +8 bytes: transaction id
  // +1 bytes: flags
  // +1 bytes: encoding id
  // +4 bytes: body length

  // Verify if 'URI To' and 'URI From' fields are present.
  char b = cursor.body_ptr[cursor.body_offset +17];
  bool source_flag = (b >> 7) & 0x01;
  bool destination_flag = (b >> 6) & 0x01;

  cursor.body_offset += FIXED_HEADER_LENGTH;

  if (source_flag) {
    int rc = maltcp_decode_uri(decoder, &cursor, uri_from);
    if (rc < 0) return rc;
  } else {
    *uri_from = NULL;
  }

  if (destination_flag) {
    int rc = maltcp_decode_uri(decoder, &cursor, uri_to);
    if (rc < 0) return rc;
  } else {
    *uri_to = NULL;
  }

  return 0;
}

int maltcp_decode_identifier(mal_decoder_t *decoder, void *cursor,
    mal_identifier_t **result) {
  int rc = malbinary_decoder_decode_string(decoder, cursor, result);
  return rc;
}

int maltcp_decode_identifier_list(mal_decoder_t *decoder, void *cursor,
    mal_identifier_list_t **result) {
  int rc = 0;
  unsigned int list_size;
  mal_identifier_t **list_content;
  rc = malbinary_decoder_decode_list_size(decoder, cursor, &list_size);
  if (rc < 0)
    return rc;
  (*result) = mal_identifier_list_new(list_size);
  list_content = mal_identifier_list_get_content(*result);

  for (int i = 0; i < list_size; i++) {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
        &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = maltcp_decode_identifier(decoder, cursor, &list_content[i]);
      if (rc < 0)
        return rc;
    } else {
      list_content[i] = NULL;
    }
  }
  return rc;
}

int maltcp_decode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, mal_decoder_t *decoder, void *cursor,
    mal_uinteger_t *variable_length) {
  char b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];

  unsigned char version = (b >> 5) & 0x07;
  clog_debug(maltcp_logger, "maltcp_decode_message: version=%d\n", version);
  if (version != 1)
    return -1;

  int sduType = b & 0x1F;

  clog_debug(maltcp_logger, "maltcp_decode_message: sduType=%d\n", sduType);

  mal_interactiontype_t interaction_type = convert_to_interaction_type(sduType);
  if (interaction_type == -1) {
    clog_error(maltcp_logger, MALZMQ_BAD_INTERACTION_TYPE_MSG);
    return MALZMQ_BAD_INTERACTION_TYPE;
  }
  mal_message_set_interaction_type(message, interaction_type);

  mal_uoctet_t interaction_stage = convert_to_interaction_stage(sduType);
  if (interaction_stage == -1) {
    clog_error(maltcp_logger, MALZMQ_BAD_INTERACTION_STAGE_MSG);
    return MALZMQ_BAD_INTERACTION_STAGE;
  }
  mal_message_set_interaction_stage(message, interaction_stage);

  clog_debug(maltcp_logger, "maltcp_decode_message: %d, %d\n", interaction_type, interaction_stage);

  mal_ushort_t service_area = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_service_area(message, service_area);

  mal_ushort_t service = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_service(message, service);

  int operation = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_operation(message, operation);

  byte area_version = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  mal_message_set_area_version(message, area_version);

  clog_debug(maltcp_logger, "maltcp_decode_message: %d, %d, %d, %d\n", service_area, service, operation, area_version);

  b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  bool is_error_message = (b >> 7) & 0x01;
  mal_message_set_is_error_message(message, is_error_message);

  int qoslevel = (b >> 4) & 0x07;
  mal_message_set_qoslevel(message, (mal_qoslevel_t) qoslevel);

  int session = (b >> 0) & 0xF;
  mal_message_set_session(message, (mal_sessiontype_t) session);

  long transaction_id = malbinary_read64(cursor);
  mal_message_set_transaction_id(message, transaction_id);

  b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  bool source_flag = (b >> 7) & 0x01;
  bool destination_flag = (b >> 6) & 0x01;
  bool priority_flag = (b >> 5) & 0x01;
  bool timestamp_flag = (b >> 4) & 0x01;
  bool network_zone_flag = (b >> 3) & 0x01;
  bool session_name_flag = (b >> 2) & 0x01;
  bool domain_flag = (b >> 1) & 0x01;
  bool authentication_id_flag = b & 0x01;

  //encoding id
  mal_uoctet_t encoding_id = malbinary_read(cursor);
  mal_message_set_encoding_id(message, encoding_id);

  //mal_message_length
  (*variable_length) = malbinary_read32(cursor);

  mal_uri_t *uri_from;
  if (source_flag) {
    maltcp_decode_uri(decoder, cursor, &uri_from);
    mal_message_set_free_uri_from(message, true);
    mal_message_set_uri_from(message, uri_from);
  }
  // TODO (AF): Optimized mapping

  mal_uri_t *uri_to;
  if (destination_flag) {
    maltcp_decode_uri(decoder, cursor, &uri_to);
    mal_message_set_free_uri_to(message, true);
    mal_message_set_uri_to(message, uri_to);
  }
  // TODO (AF): Optimized mapping

  mal_uinteger_t priority;
  if (priority_flag) {
    malbinary_decoder_decode_uinteger(decoder, cursor, &priority);
  } else {
    priority = maltcp_header_get_priority(maltcp_header);
  }
  mal_message_set_priority(message, priority);

  mal_time_t timestamp;
  if (timestamp_flag) {
    malbinary_decoder_decode_time(decoder, cursor, &timestamp);
  }
  mal_message_set_timestamp(message, timestamp);

  mal_identifier_t *network_zone;
  if (network_zone_flag) {
    maltcp_decode_identifier(decoder, cursor, &network_zone);
    mal_message_set_free_network_zone(message, true);
  } else {
    network_zone = maltcp_header_get_network_zone(maltcp_header);
    mal_message_set_free_network_zone(message, false);
  }
  mal_message_set_network_zone(message, network_zone);

  mal_identifier_t *session_name;
  if (session_name_flag) {
    maltcp_decode_identifier(decoder, cursor, &session_name);
    mal_message_set_free_session_name(message, true);
  } else {
    session_name = maltcp_header_get_session_name(maltcp_header);
    mal_message_set_free_session_name(message, false);
  }
  mal_message_set_session_name(message, session_name);

  mal_identifier_list_t *domain;
  if (domain_flag) {
    maltcp_decode_identifier_list(decoder, cursor, &domain);
    mal_message_set_free_domain(message, true);
  } else {
    domain = maltcp_header_get_domain(maltcp_header);
    mal_message_set_free_domain(message, false);
  }
  mal_message_set_domain(message, domain);

  mal_blob_t *authentication_id;
  if (authentication_id_flag) {
    malbinary_decoder_decode_blob(decoder, cursor, &authentication_id);
    mal_message_set_free_authentication_id(message, true);
  } else {
    authentication_id = maltcp_header_get_authentication_id(maltcp_header);
    mal_message_set_free_authentication_id(message, false);
  }
  mal_message_set_authentication_id(message, authentication_id);

  unsigned int body_offset = ((malbinary_cursor_t *) cursor)->body_offset;
  unsigned int body_length = ((malbinary_cursor_t *) cursor)->body_length - body_offset;

  char *bytes = ((malbinary_cursor_t *) cursor)->body_ptr;
  char *body = NULL;
  if (body_length > 0) {
    // Copy the message in a newly allocated memory array.
    body = (char *) malloc(sizeof(char) * body_length);
    memcpy(body, bytes + body_offset, body_length);
  }

  // TODO (AF): Normally we should keep the body in the frame!!
  mal_message_set_body(message, body);
  mal_message_set_body_offset(message, 0);
  mal_message_set_body_length(message, body_length);

  return 0;
}

// BEGIN -- URI manipulation functions maltcp:
// - maltcp://192.168.0.1:2534/Service
// - maltcp://[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:972/Service’

// Returns a newly allocated string containing the base URI of the full URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "maltcp://ipaddress:port"
char *maltcp_get_base_uri(char *full_uri) {
  int len = strlen(full_uri);
  char *ptr = strchr(full_uri +sizeof MALTCP_URI, '/');
  if (ptr != NULL)
    len = ptr-full_uri;
  char *base_uri = (char*) malloc(len+1);
  strncpy(base_uri, full_uri, len);
  base_uri[len] = '\0';

  return base_uri;
}

// Returns a pointer to the substring that specify the requested service in the URI
// specified in parameter: "maltcp://ipaddress:port/service" -> "service"
char *maltcp_get_service_from_uri(char *full_uri) {
  if (strncmp(MALTCP_URI, full_uri, sizeof MALTCP_URI -1) == 0) {
    char *ptr = strchr(full_uri +sizeof MALTCP_URI, '/');
    return ptr+1;
  } else {
    return full_uri;
  }
}

// Returns a newly allocated string containing the IP address from the URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "ipaddress"
char *maltcp_get_host_from_uri(char *uri) {
  // TODO (AF): IPv6
  char* ptr1 = strchr(uri +sizeof MALTCP_URI -1, ':');
  if (ptr1 == NULL)
    return NULL;

  size_t len = (size_t) (ptr1 - uri -sizeof MALTCP_URI +1);
  clog_debug(maltcp_logger, "get_host_from_uri: %s %d\n", ptr1, len);
  char* host = (char*) malloc(len +1);
  strncpy(host, uri +sizeof MALTCP_URI -1, len);
  host[len] = '\0';

  return host;
}

// Returns the port number from the URI specified in parameter:
// "maltcp://ipaddress:port/service" -> port
int maltcp_get_port_from_uri(char *uri) {
  // TODO (AF): IPv6
  char port[10];
  char* ptr1 = strchr(uri +sizeof MALTCP_URI -1, ':');
  if (ptr1 == NULL)
    return -1;
  char* ptr2 = strchr(ptr1+1, '/');
  if (ptr2 == NULL)
    ptr2 = ptr1 + strlen(ptr1);

  size_t len = (size_t) (ptr2 - ptr1 -1);
  strncpy(port, ptr1+1, len);
  port[len] = '\0';

  return atoi(port);
}

// END -- URI manipulation functions

//  --------------------------------------------------------------------------
//  Selftest

void maltcp_test(bool verbose) {
  printf(" * maltcp: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
