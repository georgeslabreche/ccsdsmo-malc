/* */
#include "maltcp.h"

clog_logger_t maltcp_logger = CLOG_WARN_LEVEL;

void maltcp_set_log_level(int level) {
  maltcp_logger = level;
}

typedef enum {
  MAL_SDUTYPE_SEND,
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
    if (stage == MAL_IP_STAGE_SEND) {
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
int maltcp_add_string_encoding_length(mal_string_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  int rc = 0;
  bool mdk_encode = false;
  unsigned int md_key;
  // find the string in the mapping directory
  if (mapping_directory != NULL) {
    rc = mapping_directory->get_key_fn(to_encode, &md_key);
    if ((rc == 0) && (md_key > 0))
      mdk_encode = true;
  }
  if (mdk_encode) {
    (*encoding_length) += 4;
  } else {
    rc = malbinary_encoder_add_string_encoding_length(encoder, to_encode, encoding_length);
  }
  return rc;
}

int maltcp_add_uri_encoding_length(mal_uri_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  return maltcp_add_string_encoding_length(to_encode, mapping_directory, encoder, encoding_length);
}

int maltcp_add_identifier_encoding_length(mal_identifier_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  return maltcp_add_string_encoding_length(to_encode, mapping_directory, encoder, encoding_length);
}

int maltcp_add_identifier_list_encoding_length(mal_identifier_list_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
  // Presence flags
  (*encoding_length) += list_size;
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    if (list_element != NULL) {
      rc = maltcp_add_identifier_encoding_length(list_element, mapping_directory, encoder, encoding_length);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int maltcp_add_message_encoding_length(maltcp_header_t *maltcp_header,
    mal_message_t *message, malbinary_encoder_t *encoder,
    unsigned int *encoding_length) {
  int rc = 0;

  clog_debug(malbinary_encoder_get_logger(encoder), "maltcp_add_message_encoding_length()\n");

  // +1 byte: version + sdu type
  // +2 bytes: service area
  // +2 bytes: service
  // +2 bytes: operation
  // +1 bytes: area version
  // +1 bytes: is error message + qos level + session
  // +8 bytes: transaction id
  // +1 byte: flags
  // +1 bytes: encoding id
  // +4 bytes: body length
  (*encoding_length) += 1 + 2 * 3 + 1 + 1 + 8 + 1 + 1 + 4;

  // always encode 'URI From' and 'URI To'
  rc = maltcp_add_uri_encoding_length(mal_message_get_uri_from(message),
      maltcp_header_get_mapping_directory(maltcp_header), encoder, encoding_length);
  if (rc < 0) return rc;
  rc = maltcp_add_uri_encoding_length(mal_message_get_uri_to(message),
      maltcp_header_get_mapping_directory(maltcp_header), encoder, encoding_length);
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
        mal_message_get_priority(message), encoding_length);
    if (rc < 0) return rc;
  }

  if (timestamp_flag > 0) {
    rc = malbinary_encoder_add_time_encoding_length(encoder,
        mal_message_get_timestamp(message), encoding_length);
    if (rc < 0) return rc;
  }

  if (network_zone_flag > 0) {
    rc = maltcp_add_identifier_encoding_length(mal_message_get_network_zone(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, encoding_length);
    if (rc < 0) return rc;
  }

  if (session_name_flag > 0) {
    rc = maltcp_add_identifier_encoding_length(mal_message_get_session_name(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, encoding_length);
    if (rc < 0) return rc;
  }

  if (domain_flag > 0) {
    rc = maltcp_add_identifier_list_encoding_length(mal_message_get_domain(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, encoding_length);
    if (rc < 0) return rc;
  }

  if (authentication_id_flag > 0) {
    rc = malbinary_encoder_add_blob_encoding_length(encoder,
        mal_message_get_authentication_id(message), encoding_length);
    if (rc < 0) return rc;
  }

  //encoding id
  rc = malbinary_encoder_add_octet_encoding_length(encoder,
      0, encoding_length);
  if (rc < 0) return rc;

  //body length
  rc = malbinary_encoder_add_uinteger_encoding_length(encoder,
      mal_message_get_body_length(message), encoding_length);
  if (rc < 0) return rc;

  (*encoding_length) += mal_message_get_body_length(message);

  return rc;
}

// internal functions, should not be visible from outside this module
int maltcp_encode_string(
    mal_string_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory,
    malbinary_encoder_t *encoder,
    char *bytes, unsigned int *offset) {
  int rc = 0;
  bool mdk_encode = false;
  unsigned int md_key;
  // find the string in the mapping directory
  if (mapping_directory != NULL) {
    rc = mapping_directory->get_key_fn(to_encode, &md_key);
    if ((rc == 0) && (md_key > 0))
      mdk_encode = true;
  }
  if (mdk_encode) {
    int opt_mdk = - md_key;
    // check opt_mdk is negative
    if (! (opt_mdk < 0)) {
      clog_error(maltcp_logger, "maltcp_encode_string, bad optional key: %d.", opt_mdk);
      return -1;
    }
    // TODO: varint
    malbinary_write32(opt_mdk, bytes, offset);
  } else {
    // check length is not too large
    int len = strlen(to_encode);
    if (! (len >= 0)) {
      clog_error(maltcp_logger, "maltcp_encode_string, length too large: %d.", len);
      return -1;
    }
    rc = malbinary_encoder_encode_string(encoder, bytes, offset, to_encode);
  }
  return rc;
}

int maltcp_encode_uri(mal_uri_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    char *bytes, unsigned int *offset) {
  return maltcp_encode_string(to_encode, mapping_directory, encoder, bytes, offset);
}

int maltcp_encode_identifier(mal_identifier_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    char *bytes, unsigned int *offset) {
  return maltcp_encode_string(to_encode, mapping_directory, encoder, bytes, offset);
}

int maltcp_encode_identifier_list(mal_identifier_list_t *to_encode,
    maltcp_mapping_directory_t *mapping_directory, malbinary_encoder_t *encoder,
    char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = mal_identifier_list_get_element_count(to_encode);
  // TODO varint ?
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  mal_identifier_t **content = mal_identifier_list_get_content(to_encode);
  for (int i = 0; i < list_size; i++) {
    mal_identifier_t *list_element = content[i];
    bool presence_flag = (list_element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, bytes, offset,
        presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = maltcp_encode_identifier(list_element, mapping_directory, encoder, bytes, offset);
      if (rc < 0)
        return rc;
    }
  }
  return rc;
}

int maltcp_encode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, malbinary_encoder_t *encoder, char *bytes,
    unsigned int *offset) {
  clog_debug(malbinary_encoder_get_logger(encoder), "maltcp_encode_message()\n");

  int sdu_type = convert_to_sdu_type(
      mal_message_get_interaction_type(message),
      mal_message_get_interaction_stage(message),
      mal_message_is_error_message(message));
  if (sdu_type == -1) {
    clog_error(maltcp_logger, MALZMQ_BAD_SDU_TYPE_MSG);
    return MALZMQ_BAD_SDU_TYPE;
  }

  bytes[(*offset)++] = (char) ((maltcp_header_get_version(maltcp_header) << 5)
      | sdu_type);

  malbinary_write16(mal_message_get_service_area(message), bytes, offset);
  malbinary_write16(mal_message_get_service(message), bytes, offset);
  malbinary_write16(mal_message_get_operation(message), bytes, offset);
  bytes[(*offset)++] = mal_message_get_area_version(message);

  bytes[(*offset)++] = (char) ((mal_message_is_error_message(message) << 7)
      | (mal_message_get_qoslevel(message) << 4)
      | (mal_message_get_session(message)));

  malbinary_write64(mal_message_get_transaction_id(message), bytes, offset);

  bool priority_flag = maltcp_header_get_priority_flag(maltcp_header);
  bool timestamp_flag = maltcp_header_get_timestamp_flag(maltcp_header);
  bool network_zone_flag = maltcp_header_get_network_zone_flag(maltcp_header);
  bool session_name_flag = maltcp_header_get_session_name_flag(maltcp_header);
  bool domain_flag = maltcp_header_get_domain_flag(maltcp_header);
  bool authentication_id_flag = maltcp_header_get_authentication_id_flag(
      maltcp_header);

  bytes[(*offset)++] = (char) (priority_flag << 5) | (timestamp_flag << 4)
              | (network_zone_flag << 3) | (session_name_flag << 2) | (domain_flag << 1)
              | (authentication_id_flag << 0);

  //encoding id
  malbinary_encoder_encode_octet(encoder, bytes, offset, 0);

  //body length (message length)
  unsigned int offset_bl = *offset;
  (*offset) += 4; // encode in end of this function

  // always encode 'URI From' and 'URI To'
  // this ordering is not consistent with the blue book proposal
  maltcp_encode_uri(mal_message_get_uri_from(message),
      maltcp_header_get_mapping_directory(maltcp_header), encoder, bytes, offset);
  maltcp_encode_uri(mal_message_get_uri_to(message),
      maltcp_header_get_mapping_directory(maltcp_header), encoder, bytes, offset);

  if (priority_flag > 0) {
    malbinary_encoder_encode_uinteger(encoder, bytes, offset,
        mal_message_get_priority(message));
  }

  if (timestamp_flag > 0) {
    malbinary_encoder_encode_time(encoder, bytes, offset,
        mal_message_get_timestamp(message));
  }

  if (network_zone_flag > 0) {
    maltcp_encode_identifier(mal_message_get_network_zone(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, bytes, offset);
  }

  if (session_name_flag > 0) {
    maltcp_encode_identifier(mal_message_get_session_name(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, bytes, offset);
  }

  if (domain_flag > 0) {
    maltcp_encode_identifier_list(mal_message_get_domain(message),
        maltcp_header_get_mapping_directory(maltcp_header), encoder, bytes, offset);
  }

  if (authentication_id_flag > 0) {
    malbinary_encoder_encode_blob(encoder, bytes, offset,
        mal_message_get_authentication_id(message));
  }

  char *body = mal_message_get_body(message);
  unsigned int body_offset = mal_message_get_body_offset(message);
  unsigned int body_length = mal_message_get_body_length(message);

  unsigned int index = *(offset);
  memcpy(bytes + index, body + body_offset, body_length);

  *(offset) += body_length;

  // encode the body length (message length)
  malbinary_encoder_encode_uinteger(encoder, bytes, &offset_bl, *(offset));
  printf("--- message_length = %u\n" , (*offset));//NTA tmp

  return 0;
}

// internal functions, should not be visible from outside this module
int maltcp_decode_string(maltcp_mapping_directory_t *mapping_directory,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset, mal_string_t **result) {
  int rc = 0;
  // TODO: varint
  int opt_mdk = malbinary_read32(bytes, offset);
  if (opt_mdk < 0) {
    unsigned int md_key = - opt_mdk;
    char *result_str;
    // find the string in the mapping directory
    if (mapping_directory == NULL)
      return -1;
    rc = mapping_directory->get_string_fn(md_key, &result_str);
    if (rc < 0)
      return rc;
    (*result) = mal_string_new(result_str);
  } else {
    unsigned int length = opt_mdk;
    (*result) = (char *) malloc(length + 1);
    if ((*result) == NULL) return -1;
    bcopy(& bytes[*offset], *result, length);
    (*result)[length] = '\0';
    (*offset) += length;
  }
  return rc;
}

int maltcp_decode_uri(maltcp_mapping_directory_t *mapping_directory,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset,
    mal_uri_t **result) {
  return maltcp_decode_string(mapping_directory, decoder, bytes, offset, result);
}

int maltcp_decode_uri_to(maltcp_header_t *maltcp_header,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset,
    mal_uri_t **uri_to) {
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
  (*offset) += 1 + 2 * 3 + 1 + 1 + 8 + 1 + 1 + 4;

  // this ordering is not consistent with the blue book proposal
  // Read the 'URI From' length
  int opt_mdk = malbinary_read32(bytes, offset);
  if (opt_mdk >= 0)
    (*offset) += opt_mdk;

  return maltcp_decode_uri(maltcp_header_get_mapping_directory(maltcp_header),
      decoder, bytes, offset, uri_to);
}

int maltcp_decode_identifier(maltcp_mapping_directory_t *mapping_directory,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset,
    mal_identifier_t **result) {
  return maltcp_decode_string(mapping_directory, decoder, bytes, offset, result);
}

int maltcp_decode_identifier_list(maltcp_mapping_directory_t *mapping_directory,
    malbinary_decoder_t *decoder, char *bytes, unsigned int *offset,
    mal_identifier_list_t **result) {
  int rc = 0;
  unsigned int list_size;
  mal_identifier_t **list_content;
  rc = malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  if (rc < 0)
    return rc;
  (*result) = mal_identifier_list_new(list_size);
  list_content = mal_identifier_list_get_content(*result);

  for (int i = 0; i < list_size; i++) {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset,
        &presence_flag);
    if (rc < 0)
      return rc;
    if (presence_flag) {
      rc = maltcp_decode_identifier(mapping_directory,
          decoder, bytes, offset, &list_content[i]);
      if (rc < 0)
        return rc;
    } else {
      list_content[i] = NULL;
    }
  }
  return rc;
}

int maltcp_decode_message(maltcp_header_t *maltcp_header,
    mal_message_t *message, malbinary_decoder_t *decoder, char *bytes,
    unsigned int *offset, unsigned int length,
    mal_uoctet_t *encoding_id, mal_uinteger_t *mal_message_length) {

  char b = bytes[(*offset)++];

  unsigned char version = (b >> 5) & 0x07;
  if (version != 1)
    return -1;

  int sduType = b & 0x1F;

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

  mal_ushort_t service_area = malbinary_read16(bytes, offset) & 0xFFFF;
  mal_message_set_service_area(message, service_area);

  mal_ushort_t service = malbinary_read16(bytes, offset) & 0xFFFF;
  mal_message_set_service(message, service);

  int operation = malbinary_read16(bytes, offset) & 0xFFFF;
  mal_message_set_operation(message, operation);

  byte area_version = bytes[(*offset)++];
  mal_message_set_area_version(message, area_version);

  b = bytes[(*offset)++];
  bool is_error_message = (b >> 7) & 0x01;
  mal_message_set_is_error_message(message, is_error_message);

  int qoslevel = (b >> 5) & 0x03;
  mal_message_set_qoslevel(message, (mal_qoslevel_t) qoslevel);

  int session = (b >> 3) & 0x03;
  mal_message_set_session(message, (mal_sessiontype_t) session);

  long transaction_id = malbinary_read64(bytes, offset);
  mal_message_set_transaction_id(message, transaction_id);

  b = bytes[(*offset)++];
  bool priority_flag = (b >> 5) & 0x01;
  bool timestamp_flag = (b >> 4) & 0x01;
  bool network_zone_flag = (b >> 3) & 0x01;
  bool session_name_flag = (b >> 2) & 0x01;
  bool domain_flag = (b >> 1) & 0x01;
  bool authentication_id_flag = b & 0x01;

  //encoding id
  malbinary_decoder_decode_uoctet(decoder, bytes, offset, encoding_id);
  //TODO: mal_message_set_encoding_id(message, encoding_id);

  //mal_message_length
  malbinary_decoder_decode_uinteger(decoder, bytes, offset, mal_message_length);

  // this ordering is not consistent with the blue book proposal
  mal_uri_t *uri_from;
  maltcp_decode_uri(maltcp_header_get_mapping_directory(maltcp_header),
      decoder, bytes, offset, &uri_from);
  mal_message_set_free_uri_from(message, true);
  mal_message_set_uri_from(message, uri_from);

  mal_uri_t *uri_to;
  maltcp_decode_uri(maltcp_header_get_mapping_directory(maltcp_header),
      decoder, bytes, offset, &uri_to);
  mal_message_set_free_uri_to(message, true);
  mal_message_set_uri_to(message, uri_to);

  mal_uinteger_t priority;
  if (priority_flag) {
    malbinary_decoder_decode_uinteger(decoder, bytes, offset, &priority);
  } else {
    priority = maltcp_header_get_priority(maltcp_header);
  }
  mal_message_set_priority(message, priority);

  mal_time_t timestamp;
  if (timestamp_flag) {
    malbinary_decoder_decode_time(decoder, bytes, offset, &timestamp);
  }
  mal_message_set_timestamp(message, timestamp);

  mal_identifier_t *network_zone;
  if (network_zone_flag) {
    maltcp_decode_identifier(maltcp_header_get_mapping_directory(maltcp_header),
        decoder, bytes, offset, &network_zone);
    mal_message_set_free_network_zone(message, true);
  } else {
    network_zone = maltcp_header_get_network_zone(maltcp_header);
    mal_message_set_free_network_zone(message, false);
  }
  mal_message_set_network_zone(message, network_zone);

  mal_identifier_t *session_name;
  if (session_name_flag) {
    maltcp_decode_identifier(maltcp_header_get_mapping_directory(maltcp_header),
        decoder, bytes, offset, &session_name);
    mal_message_set_free_session_name(message, true);
  } else {
    session_name = maltcp_header_get_session_name(maltcp_header);
    mal_message_set_free_session_name(message, false);
  }
  mal_message_set_session_name(message, session_name);

  mal_identifier_list_t *domain;
  if (domain_flag) {
    maltcp_decode_identifier_list(maltcp_header_get_mapping_directory(maltcp_header),
        decoder, bytes, offset, &domain);
    mal_message_set_free_domain(message, true);
  } else {
    domain = maltcp_header_get_domain(maltcp_header);
    mal_message_set_free_domain(message, false);
  }
  mal_message_set_domain(message, domain);

  mal_blob_t *authentication_id;
  if (authentication_id_flag) {
    malbinary_decoder_decode_blob(decoder, bytes, offset, &authentication_id);
    mal_message_set_free_authentication_id(message, true);
  } else {
    authentication_id = maltcp_header_get_authentication_id(maltcp_header);
    mal_message_set_free_authentication_id(message, false);
  }
  mal_message_set_authentication_id(message, authentication_id);

  unsigned int body_offset = (*offset);
  unsigned int body_length = length - body_offset;

  char *body = (char *) malloc(sizeof(char) * body_length);

  memcpy(body, bytes + body_offset, body_length);

  mal_message_set_body(message, body);
  mal_message_set_body_offset(message, 0);
  mal_message_set_body_length(message, body_length);

  return 0;
}

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
