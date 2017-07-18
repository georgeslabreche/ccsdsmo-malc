/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
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
#include "malzmq.h"

clog_logger_t malzmq_logger = CLOG_WARN_LEVEL;

void malzmq_set_log_level(int level) {
  malzmq_logger = level;
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

static int convert_to_sdu_type(mal_interactiontype_t type, mal_uoctet_t stage,
    mal_boolean_t isError) {
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

/*
 static char *uri_seek_id(mal_uri_t *uri) {
 size_t uri_length = strlen(uri);
 int slashCounter = 0;
 for (int i = 0; i < uri_length; i++) {
 if (uri[i] == '/') {
 slashCounter++;
 if (slashCounter == 3) {
 return uri + i + 1;
 }
 }
 }
 // No id found
 return "";
 }*/

// internal functions, should not be visible from outside this module
int malzmq_add_string_encoding_length(mal_string_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  bool mdk_encode = false;
  unsigned int md_key;
  // find the string in the mapping directory
  if (mapping_directory != NULL) {
    int rc = mapping_directory->get_key_fn(to_encode, &md_key);
    if ((rc == 0) && (md_key > 0))
      mdk_encode = true;
  }
  if (mdk_encode) {
    malbinary_encoder_add_integer_encoding_length(encoder, (-md_key), cursor);
  } else {
    size_t length = mal_string_get_char_count(to_encode);
    if (encoder->varint_supported) {
      malbinary_encoder_add_integer_encoding_length(encoder, length, cursor);
      ((malbinary_cursor_t *) cursor)->body_length += length;
    } else {
      ((malbinary_cursor_t *) cursor)->body_length += 4 + length;
    }
  }
  return 0;
}

int malzmq_add_uri_encoding_length(mal_uri_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  return malzmq_add_string_encoding_length(to_encode, mapping_directory, encoder, cursor);
}

int malzmq_add_identifier_encoding_length(mal_identifier_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  return malzmq_add_string_encoding_length(to_encode, mapping_directory, encoder, cursor);
}

int malzmq_add_identifier_list_encoding_length(mal_identifier_list_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
  // Presence flags
  ((malbinary_cursor_t *) cursor)->body_length += list_size;
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    if (list_element != NULL) {
      rc = malzmq_add_identifier_encoding_length(list_element, mapping_directory, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int malzmq_add_message_encoding_length(malzmq_header_t *malzmq_header,
    mal_message_t *message, mal_encoder_t *encoder,
    void *cursor) {
  int rc = 0;

  clog_debug(mal_encoder_get_logger(encoder), "malzmq_add_message_encoding_length()\n");

  // +1 byte: version + sdu type
  // +2 bytes: service area
  // +2 bytes: service
  // +2 bytes: operation
  // +1 bytes: area version
  // +1 bytes: is error message + qos level + session
  // +8 bytes: transaction id
  // +1 byte: flags
  ((malbinary_cursor_t *) cursor)->body_length += 18;

  // always encode 'URI From' and 'URI To'
  rc = malzmq_add_uri_encoding_length(mal_message_get_uri_from(message),
      malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  if (rc < 0) return rc;
  rc = malzmq_add_uri_encoding_length(mal_message_get_uri_to(message),
      malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  if (rc < 0) return rc;

  char encoding_id_flag;
  mal_uoctet_t encoding_id = mal_message_get_encoding_id(message);
  if (encoding_id < 3)
    encoding_id_flag = encoding_id;
  else
    encoding_id_flag = 3;
  bool priority_flag = malzmq_header_get_priority_flag(malzmq_header);
  bool timestamp_flag = malzmq_header_get_timestamp_flag(malzmq_header);
  bool network_zone_flag = malzmq_header_get_network_zone_flag(malzmq_header);
  bool session_name_flag = malzmq_header_get_session_name_flag(malzmq_header);
  bool domain_flag = malzmq_header_get_domain_flag(malzmq_header);
  bool authentication_id_flag = malzmq_header_get_authentication_id_flag(
      malzmq_header);

  if (encoding_id_flag == 3) {
    rc = malbinary_encoder_add_uoctet_encoding_length(encoder, encoding_id, cursor);
    if (rc < 0) return rc;
  }

  if (priority_flag > 0) {
    rc = malbinary_encoder_add_uinteger_encoding_length(encoder, mal_message_get_priority(message), cursor);
    if (rc < 0) return rc;
  }

  if (timestamp_flag > 0) {
    ((malbinary_cursor_t *) cursor)->body_length += 6;
  }

  if (network_zone_flag > 0) {
    rc = malzmq_add_identifier_encoding_length(mal_message_get_network_zone(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
    if (rc < 0) return rc;
  }

  if (session_name_flag > 0) {
    rc = malzmq_add_identifier_encoding_length(mal_message_get_session_name(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
    if (rc < 0) return rc;
  }

  if (domain_flag > 0) {
    rc = malzmq_add_identifier_list_encoding_length(mal_message_get_domain(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
    if (rc < 0) return rc;
  }

  if (authentication_id_flag > 0) {
    rc = malbinary_encoder_add_blob_encoding_length(encoder, mal_message_get_authentication_id(message), cursor);
    if (rc < 0) return rc;
  }

  ((malbinary_cursor_t *) cursor)->body_length += mal_message_get_body_length(message);

  return rc;
}

// internal functions, should not be visible from outside this module
int malzmq_encode_string(
    mal_string_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory,
    mal_encoder_t *encoder,
    void *cursor) {
  bool mdk_encode = false;
  unsigned int md_key;
  // find the string in the mapping directory
  if (mapping_directory != NULL) {
    int rc = mapping_directory->get_key_fn(to_encode, &md_key);
    if ((rc == 0) && (md_key > 0))
      mdk_encode = true;
  }
  if (mdk_encode) {
    int opt_mdk = (-md_key);
    // check opt_mdk is negative
    if (! (opt_mdk < 0)) {
      clog_error(malzmq_logger, "malzmq_encode_string, bad optional key: %d.", opt_mdk);
      return -1;
    }
    malbinary_encoder_encode_integer(encoder, cursor, opt_mdk);
  } else {
    // check length is not too large
    int len = strlen(to_encode);
    if (! (len >= 0)) {
      clog_error(malzmq_logger, "malzmq_encode_string, length too large: %d.", len);
      return -1;
    }
    malbinary_encoder_encode_integer(encoder, cursor, len);
    malbinary_write_array(to_encode, len, cursor);
  }
  return 0;
}

int malzmq_encode_uri(mal_uri_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  return malzmq_encode_string(to_encode, mapping_directory, encoder, cursor);
}

int malzmq_encode_identifier(mal_identifier_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  return malzmq_encode_string(to_encode, mapping_directory, encoder, cursor);
}

int malzmq_encode_identifier_list(mal_identifier_list_t *to_encode,
    malzmq_mapping_directory_t *mapping_directory, mal_encoder_t *encoder,
    void *cursor) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  malbinary_encoder_encode_list_size(encoder, cursor, list_size);
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = malzmq_encode_identifier(list_element, mapping_directory, encoder, cursor);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int malzmq_encode_time(mal_encoder_t *encoder, void *cursor, mal_time_t to_encode) {
  int rc = 0;

  clog_debug(malzmq_logger, "malzmq_encode_time: to_encode = %lu\n", to_encode);

  long timestamp = to_encode;
  timestamp += MILLISECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  long days = timestamp / MILLISECONDS_IN_DAY;
  long millisecondsInDay = (timestamp % MILLISECONDS_IN_DAY);

  if (days > 65535)
  {
    clog_debug(malzmq_logger, "malzmq_encode_time: days > 65535\n");
    return 1;
  }
  malbinary_write16(days, cursor);
  malbinary_write32(millisecondsInDay, cursor);
  return rc;
}

int malzmq_encode_message(malzmq_header_t *malzmq_header, mal_message_t *message, mal_encoder_t *encoder, void *cursor) {
  clog_debug(mal_encoder_get_logger(encoder), "malzmq_encode_message()\n");

  int sdu_type = convert_to_sdu_type(
      mal_message_get_interaction_type(message),
      mal_message_get_interaction_stage(message),
      mal_message_is_error_message(message));
  if (sdu_type == -1) {
    clog_error(malzmq_logger, MALZMQ_BAD_SDU_TYPE_MSG);
    return MALZMQ_BAD_SDU_TYPE;
  }

  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = (char) ((malzmq_header_get_version(malzmq_header) << 5)
      | sdu_type);

  malbinary_write16(mal_message_get_service_area(message), cursor);
  malbinary_write16(mal_message_get_service(message), cursor);
  malbinary_write16(mal_message_get_operation(message), cursor);
  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = mal_message_get_area_version(message);

  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] = (char) ((mal_message_is_error_message(message) << 7)
      | (mal_message_get_qoslevel(message) << 4)
      | (mal_message_get_session(message)));

  malbinary_write64(mal_message_get_transaction_id(message), cursor);

  char encoding_id_flag;
  mal_uoctet_t encoding_id = mal_message_get_encoding_id(message);
  if (encoding_id < 3)
    encoding_id_flag = encoding_id;
  else
    encoding_id_flag = 3;
  bool priority_flag = malzmq_header_get_priority_flag(malzmq_header);
  bool timestamp_flag = malzmq_header_get_timestamp_flag(malzmq_header);
  bool network_zone_flag = malzmq_header_get_network_zone_flag(malzmq_header);
  bool session_name_flag = malzmq_header_get_session_name_flag(malzmq_header);
  bool domain_flag = malzmq_header_get_domain_flag(malzmq_header);
  bool authentication_id_flag = malzmq_header_get_authentication_id_flag(malzmq_header);

  ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++] =
      (char) (encoding_id_flag << 6) |
             (priority_flag << 5) |
             (timestamp_flag << 4) |
             (network_zone_flag << 3) |
             (session_name_flag << 2) |
             (domain_flag << 1) |
             (authentication_id_flag << 0);

  // always encode 'URI From' and 'URI To'
  malzmq_encode_uri(mal_message_get_uri_from(message),
      malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  malzmq_encode_uri(mal_message_get_uri_to(message),
      malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);

   if (encoding_id_flag == 3) {
     malbinary_encoder_encode_uoctet(encoder, cursor, encoding_id);
   }

   if (priority_flag > 0) {
     malbinary_encoder_encode_uinteger(encoder, cursor, mal_message_get_priority(message));
   }

  if (timestamp_flag != false) {
    malzmq_encode_time(encoder, cursor, mal_message_get_timestamp(message));
  }

  if (network_zone_flag > 0) {
    malzmq_encode_identifier(mal_message_get_network_zone(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  }

  if (session_name_flag > 0) {
    malzmq_encode_identifier(mal_message_get_session_name(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  }

  if (domain_flag > 0) {
    malzmq_encode_identifier_list(mal_message_get_domain(message),
        malzmq_header_get_mapping_directory(malzmq_header), encoder, cursor);
  }

  if (authentication_id_flag > 0) {
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

  return 0;
}

// internal functions, should not be visible from outside this module
int malzmq_decode_string(malzmq_mapping_directory_t *mapping_directory,
    mal_decoder_t *decoder, void *cursor, mal_string_t **result) {
  mal_integer_t opt_mdk;

  malbinary_decoder_decode_integer(decoder, cursor, &opt_mdk);
  if (opt_mdk < 0) {
    unsigned int md_key = - opt_mdk;
    char *result_str;
    // find the string in the mapping directory
    if (mapping_directory == NULL)
      return -1;
    int rc = mapping_directory->get_string_fn(md_key, &result_str);
    if (rc < 0)
      return rc;
    (*result) = mal_string_new(result_str);
  } else {
    unsigned int length = opt_mdk;
    (*result) = (char *) malloc(length + 1);
    if ((*result) == NULL) return -1;
    bcopy(& ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset], *result, length);
    (*result)[length] = '\0';
    ((malbinary_cursor_t *) cursor)->body_offset += length;
  }
  return 0;
}

int malzmq_decode_uri(malzmq_mapping_directory_t *mapping_directory,
    mal_decoder_t *decoder, void *cursor,
    mal_uri_t **result) {
  return malzmq_decode_string(mapping_directory, decoder, cursor, result);
}

int malzmq_decode_uri_to(malzmq_header_t *malzmq_header,
    mal_decoder_t *decoder, char *bytes, unsigned int length,
    mal_uri_t **uri_to) {
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
  cursor.body_offset += 18;

  // Go beyond the 'URI From'
  mal_uri_t *uri_from;
  int rc = malzmq_decode_uri(malzmq_header_get_mapping_directory(malzmq_header),
        decoder, &cursor, &uri_from);
  if (rc != 0)
    return rc;
  rc = malzmq_decode_uri(malzmq_header_get_mapping_directory(malzmq_header),
      decoder, &cursor, uri_to);
  return rc;
}

int malzmq_decode_identifier(malzmq_mapping_directory_t *mapping_directory,
    mal_decoder_t *decoder, void *cursor,
    mal_identifier_t **result) {
  return malzmq_decode_string(mapping_directory, decoder, cursor, result);
}

int malzmq_decode_identifier_list(malzmq_mapping_directory_t *mapping_directory,
    mal_decoder_t *decoder, void *cursor,
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
      rc = malzmq_decode_identifier(mapping_directory,
          decoder, cursor, &list_content[i]);
      if (rc < 0)
        return rc;
    } else {
      list_content[i] = NULL;
    }
  }
  return rc;
}

int malzmq_decode_time(mal_decoder_t *decoder, void *cursor, mal_time_t *result) {
  int rc = 0;
  long days = malbinary_read16(cursor) & 0xFFFFL;
  long millisecondsInDay = malbinary_read32(cursor) & 0xFFFFFFFFL;
  long timestamp = days * MILLISECONDS_IN_DAY;
  timestamp += millisecondsInDay;
  timestamp -= MILLISECONDS_FROM_CCSDS_TO_UNIX_EPOCH;
  *result = timestamp;
  return rc;
}

int malzmq_decode_message(malzmq_header_t *malzmq_header, mal_message_t *message, mal_decoder_t *decoder, void *cursor) {
  char b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];

  unsigned char version = (b >> 5) & 0x07;
  if (version != 1)
    return -1;

  int sduType = b & 0x1F;

  mal_interactiontype_t interaction_type = convert_to_interaction_type(sduType);
  if (interaction_type == -1) {
    clog_error(malzmq_logger, MALZMQ_BAD_INTERACTION_TYPE_MSG);
    return MALZMQ_BAD_INTERACTION_TYPE;
  }
  mal_message_set_interaction_type(message, interaction_type);

  mal_uoctet_t interaction_stage = convert_to_interaction_stage(sduType);
  if (interaction_stage == -1) {
    clog_error(malzmq_logger, MALZMQ_BAD_INTERACTION_STAGE_MSG);
    return MALZMQ_BAD_INTERACTION_STAGE;
  }
  mal_message_set_interaction_stage(message, interaction_stage);

  mal_ushort_t service_area = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_service_area(message, service_area);

  mal_ushort_t service = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_service(message, service);

  int operation = malbinary_read16(cursor) & 0xFFFF;
  mal_message_set_operation(message, operation);

  byte area_version = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  mal_message_set_area_version(message, area_version);

  b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  bool is_error_message = (b >> 7) & 0x01;
  mal_message_set_is_error_message(message, is_error_message);

  int qoslevel = (b >> 4) & 0x07;
  mal_message_set_qoslevel(message, (mal_qoslevel_t) qoslevel);

  int session = (b >> 0) & 0x0F;
  mal_message_set_session(message, (mal_sessiontype_t) session);

  long transaction_id = malbinary_read64(cursor);
  mal_message_set_transaction_id(message, transaction_id);

  b = ((malbinary_cursor_t *) cursor)->body_ptr[((malbinary_cursor_t *) cursor)->body_offset++];
  char encoding_id_flag = (b >> 6) & 0x03;
  bool priority_flag = (b >> 5) & 0x01;
  bool timestamp_flag = (b >> 4) & 0x01;
  bool network_zone_flag = (b >> 3) & 0x01;
  bool session_name_flag = (b >> 2) & 0x01;
  bool domain_flag = (b >> 1) & 0x01;
  bool authentication_id_flag = b & 0x01;

  mal_uri_t *uri_from;
  malzmq_decode_uri(malzmq_header_get_mapping_directory(malzmq_header),
      decoder, cursor, &uri_from);
  mal_message_set_free_uri_from(message, true);
  mal_message_set_uri_from(message, uri_from);

  mal_uri_t *uri_to;
  malzmq_decode_uri(malzmq_header_get_mapping_directory(malzmq_header),
      decoder, cursor, &uri_to);
  mal_message_set_free_uri_to(message, true);
  mal_message_set_uri_to(message, uri_to);

  mal_uoctet_t encoding_id;
  if (encoding_id_flag == 3) {
    malbinary_decoder_decode_uoctet(decoder, cursor, &encoding_id);
    mal_message_set_encoding_id(message, encoding_id);
  } else {
    mal_message_set_encoding_id(message, encoding_id_flag);
  }

   mal_uinteger_t priority;
   if (priority_flag) {
     malbinary_decoder_decode_uinteger(decoder, cursor, &priority);
   } else {
     priority = malzmq_header_get_priority(malzmq_header);
   }
   mal_message_set_priority(message, priority);

  mal_time_t timestamp;
  if (timestamp_flag) {
    malzmq_decode_time(decoder, cursor, &timestamp);
  }
  mal_message_set_timestamp(message, timestamp);

  mal_identifier_t *network_zone;
  if (network_zone_flag) {
    malzmq_decode_identifier(malzmq_header_get_mapping_directory(malzmq_header),
        decoder, cursor, &network_zone);
    mal_message_set_free_network_zone(message, true);
  } else {
    network_zone = malzmq_header_get_network_zone(malzmq_header);
    mal_message_set_free_network_zone(message, false);
  }
  mal_message_set_network_zone(message, network_zone);

  mal_identifier_t *session_name;
  if (session_name_flag) {
    malzmq_decode_identifier(malzmq_header_get_mapping_directory(malzmq_header),
        decoder, cursor, &session_name);
    mal_message_set_free_session_name(message, true);
  } else {
    session_name = malzmq_header_get_session_name(malzmq_header);
    mal_message_set_free_session_name(message, false);
  }
  mal_message_set_session_name(message, session_name);

  mal_identifier_list_t *domain;
  if (domain_flag) {
    malzmq_decode_identifier_list(malzmq_header_get_mapping_directory(malzmq_header),
        decoder, cursor, &domain);
    mal_message_set_free_domain(message, true);
  } else {
    domain = malzmq_header_get_domain(malzmq_header);
    mal_message_set_free_domain(message, false);
  }
  mal_message_set_domain(message, domain);

  mal_blob_t *authentication_id;
  if (authentication_id_flag) {
    malbinary_decoder_decode_blob(decoder, cursor, &authentication_id);
    mal_message_set_free_authentication_id(message, true);
  } else {
    authentication_id = malzmq_header_get_authentication_id(malzmq_header);
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

// BEGIN -- URI manipulation functions:
// - malzmtp://192.168.0.1:2534/Service
// - malzmtp://[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:972/Service

// Returns a newly allocated string containing the IP address from the URI specified
// in parameter: "maltcp://ipaddress:port/service" -> "ipaddress"
char *malzmq_get_host_from_uri(char *uri) {
  // TODO (AF): IPv6
  char* ptr1 = strchr(uri +sizeof MALZMTP_URI -1, ':');
  if (ptr1 == NULL)
    return NULL;

  size_t len = (size_t) (ptr1 - uri -sizeof MALZMTP_URI +1);
  char* host = (char*) malloc(len +1);
  strncpy(host, uri +sizeof MALZMTP_URI -1, len);
  host[len] = '\0';
  clog_debug(malzmq_logger, "get_host_from_uri(%s) /%d -> %s\n", uri, len, host);

  return host;
}

// Returns the port number from the URI specified in parameter:
// "maltcp://ipaddress:port/service" -> port
int malzmq_get_port_from_uri(char *uri) {
  // TODO (AF): IPv6
  char port[10];
  char* ptr1 = strchr(uri +sizeof MALZMTP_URI -1, ':');
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

// Returns a pointer to the substring that specify the requested service in the URI
// specified in parameter: "maltcp://ipaddress:port/service" -> "service"
char *malzmq_get_service_from_uri(char *full_uri) {
  if (strncmp(MALZMTP_URI, full_uri, sizeof MALZMTP_URI -1) == 0) {
    char *ptr = strchr(full_uri +sizeof MALZMTP_URI, '/');
    return ptr+1;
  } else {
    return full_uri;
  }
}

// END -- URI manipulation functions

//  --------------------------------------------------------------------------
//  Selftest

void malzmq_test(bool verbose) {
  printf(" * malzmq: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
