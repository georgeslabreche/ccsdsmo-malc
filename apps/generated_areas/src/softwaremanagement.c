#include "softwaremanagement.h"

// generated code for operation softwaremanagement_packagemanagement_findpackage

int softwaremanagement_packagemanagement_findpackage_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_FINDPACKAGE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_findpackage_request_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_findpackage_request(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_FINDPACKAGE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_findpackage_request_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_boolean_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_boolean_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_boolean_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_boolean_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_findpackage_request_response_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_findpackage_request_response_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_findpackage_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_integer_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_integer_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_findpackage_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_packagemanagement_install

int softwaremanagement_packagemanagement_install_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_install_invoke_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_install_invoke_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_install_invoke_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_install_invoke_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_install_invoke_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_install_invoke(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack_add_encoding_length_0(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_boolean_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack_encode_0(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_boolean_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack_decode_0(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_boolean_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_boolean_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_install_invoke_ack_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_install_invoke_ack_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_install_invoke_ack_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_install_invoke_ack_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_install_invoke_ack_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_install_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_install_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_install_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_install_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_integer_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_integer_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_install_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_packagemanagement_uninstall

int softwaremanagement_packagemanagement_uninstall_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UNINSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_uninstall_invoke_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_boolean_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_boolean_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_boolean_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_boolean_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_uninstall_invoke_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_uninstall_invoke_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_uninstall_invoke(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UNINSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_uninstall_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UNINSTALL_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_uninstall_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_integer_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_integer_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_uninstall_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_packagemanagement_upgrade

int softwaremanagement_packagemanagement_upgrade_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UPGRADE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_upgrade_invoke_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_upgrade_invoke_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_upgrade_invoke_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_upgrade_invoke_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_upgrade_invoke_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_upgrade_invoke(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UPGRADE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_upgrade_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_UPGRADE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_upgrade_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_integer_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_integer_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_upgrade_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_packagemanagement_checkpackageintegrity

int softwaremanagement_packagemanagement_checkpackageintegrity_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_CHECKPACKAGEINTEGRITY_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_checkpackageintegrity_request(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_CHECKPACKAGEINTEGRITY_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_boolean_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_boolean_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_boolean_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_boolean_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_STRING_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_packagemanagement_checkpackageintegrity_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_error_add_encoding_length_mal_integer_list(mal_encoder_t * encoder, mal_integer_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_integer_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_error_encode_mal_integer_list(void * cursor, mal_encoder_t * encoder, mal_integer_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_integer_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_packagemanagement_checkpackageintegrity_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_heartbeat_beat

int softwaremanagement_heartbeat_beat_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_heartbeat_beat_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg)
{
  int rc = 0;
  mal_subscription_t *subscription = (mal_subscription_t *)arg->value.composite_value;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  rc = mal_register_add_encoding_length(encoder, subscription, cursor);
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  rc = mal_register_encode(cursor, encoder, subscription);
  if (rc < 0)
    return rc;
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_heartbeat_beat_register(endpoint, message, broker_uri);
  return rc;
}

int softwaremanagement_heartbeat_beat_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_heartbeat_beat_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH);
  mal_message_set_transaction_id(message, initial_publish_register_tid);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, false);
  return rc;
}

int softwaremanagement_heartbeat_beat_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_heartbeat_beat_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg)
{
  int rc = 0;
  mal_identifier_list_t *subscription = (mal_identifier_list_t *)arg->value.list_value;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  rc = mal_deregister_add_encoding_length(encoder, subscription, cursor);
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  rc = mal_deregister_encode(cursor, encoder, subscription);
  if (rc < 0)
    return rc;
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_heartbeat_beat_deregister(endpoint, message, broker_uri);
  return rc;
}

int softwaremanagement_heartbeat_beat_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_BEAT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

// generated code for operation softwaremanagement_heartbeat_getperiod

int softwaremanagement_heartbeat_getperiod_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_GETPERIOD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_heartbeat_getperiod_request(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_HEARTBEAT_SERVICE_NUMBER, SOFTWAREMANAGEMENT_HEARTBEAT_GETPERIOD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_add_duration_encoding_length(encoder, element, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_encode_duration(encoder, cursor, element);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_decoder_decode_duration(decoder, cursor, element_res);
        if (rc < 0)
          return rc;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = softwaremanagement_heartbeat_getperiod_request_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_DURATION_SHORT_FORM);
  return rc;
}

int softwaremanagement_heartbeat_getperiod_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_heartbeat_getperiod_request_response_add_encoding_length_0(encoder,true,arg0->value.duration_value,cursor);
  } else {
    rc = softwaremanagement_heartbeat_getperiod_request_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_heartbeat_getperiod_request_response_encode_0(cursor,encoder,true,arg0->value.duration_value);
  } else {
    rc = softwaremanagement_heartbeat_getperiod_request_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_heartbeat_getperiod_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation softwaremanagement_commandexecutor_runcommand

int softwaremanagement_commandexecutor_runcommand_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_COMMANDEXECUTOR_SERVICE_NUMBER, SOFTWAREMANAGEMENT_COMMANDEXECUTOR_RUNCOMMAND_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_add_encoding_length_0(mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = softwaremanagement_commandexecutor_commanddetails_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_encode_0(void * cursor, mal_encoder_t * encoder, softwaremanagement_commandexecutor_commanddetails_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_commandexecutor_commanddetails_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_decode_0(void * cursor, mal_decoder_t * decoder, softwaremanagement_commandexecutor_commanddetails_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = softwaremanagement_commandexecutor_commanddetails_new();
        if (*element_res == NULL) return -1;
        rc = softwaremanagement_commandexecutor_commanddetails_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_commandexecutor_runcommand_request_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_SHORT_FORM);
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_commandexecutor_runcommand_request_add_encoding_length_0(encoder,arg0->value.composite_value,cursor);
  } else {
    rc = softwaremanagement_commandexecutor_runcommand_request_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_commandexecutor_runcommand_request_encode_0(cursor,encoder,arg0->value.composite_value);
  } else {
    rc = softwaremanagement_commandexecutor_runcommand_request_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_commandexecutor_runcommand_request(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_COMMANDEXECUTOR_SERVICE_NUMBER, SOFTWAREMANAGEMENT_COMMANDEXECUTOR_RUNCOMMAND_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_add_long_encoding_length(encoder, element, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_encode_long(encoder, cursor, element);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_decoder_decode_long(decoder, cursor, element_res);
        if (rc < 0)
          return rc;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = softwaremanagement_commandexecutor_runcommand_request_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_SHORT_FORM);
  return rc;
}

int softwaremanagement_commandexecutor_runcommand_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_commandexecutor_runcommand_request_response_add_encoding_length_0(encoder,true,arg0->value.long_value,cursor);
  } else {
    rc = softwaremanagement_commandexecutor_runcommand_request_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_commandexecutor_runcommand_request_response_encode_0(cursor,encoder,true,arg0->value.long_value);
  } else {
    rc = softwaremanagement_commandexecutor_runcommand_request_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_commandexecutor_runcommand_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation softwaremanagement_appslauncher_monitorexecution

int softwaremanagement_appslauncher_monitorexecution_update_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      if ((element != NULL))
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      presence_flag = true;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_monitorexecution_update_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_STRING_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg)
{
  int rc = 0;
  mal_subscription_t *subscription = (mal_subscription_t *)arg->value.composite_value;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  rc = mal_register_add_encoding_length(encoder, subscription, cursor);
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  rc = mal_register_encode(cursor, encoder, subscription);
  if (rc < 0)
    return rc;
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_monitorexecution_register(endpoint, message, broker_uri);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH);
  mal_message_set_transaction_id(message, initial_publish_register_tid);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, false);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg)
{
  int rc = 0;
  mal_identifier_list_t *subscription = (mal_identifier_list_t *)arg->value.list_value;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  rc = mal_deregister_add_encoding_length(encoder, subscription, cursor);
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  rc = mal_deregister_encode(cursor, encoder, subscription);
  if (rc < 0)
    return rc;
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_monitorexecution_deregister(endpoint, message, broker_uri);
  return rc;
}

int softwaremanagement_appslauncher_monitorexecution_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_MONITOREXECUTION_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

// generated code for operation softwaremanagement_appslauncher_runapp

int softwaremanagement_appslauncher_runapp_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_RUNAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_long_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_long_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_long_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_long_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_runapp_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_runapp_submit_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_runapp_submit_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_runapp_submit_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_runapp_submit_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_runapp_submit(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_RUNAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_runapp_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_runapp_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_runapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_uinteger_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_runapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_uinteger_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_runapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_appslauncher_killapp

int softwaremanagement_appslauncher_killapp_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_KILLAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_long_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_long_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_long_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_long_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_killapp_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_killapp_submit_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_killapp_submit_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_killapp_submit_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_killapp_submit_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_killapp_submit(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_KILLAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_killapp_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_killapp_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_killapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_uinteger_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_killapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_uinteger_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_killapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

// generated code for operation softwaremanagement_appslauncher_stopapp

int softwaremanagement_appslauncher_stopapp_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_STOPAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_long_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_long_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_long_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_long_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_stopapp_progress_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_stopapp_progress_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_stopapp_progress_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_stopapp_progress_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_stopapp_progress_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_stopapp_progress(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_STOPAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_stopapp_progress_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_STOPAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_UPDATE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_add_long_encoding_length(encoder, element, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_encode_long(encoder, cursor, element);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_decoder_decode_long(decoder, cursor, element_res);
        if (rc < 0)
          return rc;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = softwaremanagement_appslauncher_stopapp_progress_update_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_stopapp_progress_update_add_encoding_length_0(encoder,true,arg0->value.long_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_stopapp_progress_update_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_stopapp_progress_update_encode_0(cursor,encoder,true,arg0->value.long_value);
  } else {
    rc = softwaremanagement_appslauncher_stopapp_progress_update_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_stopapp_progress_update(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_STOPAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_stopapp_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_stopapp_progress_response(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation softwaremanagement_appslauncher_listapp

int softwaremanagement_appslauncher_listapp_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_identifier_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_identifier_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_listapp_request_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_encoder_add_identifier_encoding_length(encoder, element, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_encoder_encode_identifier(encoder, cursor, element);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_identifier_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_decoder_decode_identifier(decoder, cursor, element_res);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_listapp_request_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_IDENTIFIER_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(encoder,arg1->value.identifier_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_encode_1(cursor,encoder,arg1->value.identifier_value);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_encode_1(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_listapp_request(endpoint, message, provider_uri);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, SOFTWAREMANAGEMENT_AREA_NUMBER, SOFTWAREMANAGEMENT_AREA_VERSION, SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER, SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_long_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_long_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_long_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_long_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_listapp_request_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_LONG_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_boolean_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_boolean_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_boolean_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_boolean_list_decode_malbinary(*element_res, decoder, cursor);
        if (rc < 0)
          return rc;
      }
      else
      {
        *element_res = NULL;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = softwaremanagement_appslauncher_listapp_request_response_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int softwaremanagement_appslauncher_listapp_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_response_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_response_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_response_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = softwaremanagement_appslauncher_listapp_request_response_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = softwaremanagement_appslauncher_listapp_request_response_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = softwaremanagement_appslauncher_listapp_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int softwaremanagement_appslauncher_listapp_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
      if (rc < 0)
        return rc;
      if ((element != NULL))
      {
        rc = mal_uinteger_list_add_encoding_length_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
{
  int rc = 0;
  switch (encoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag = (element != NULL);
      rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_uinteger_list_encode_malbinary(element, encoder, cursor);
        if (rc < 0)
          return rc;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_appslauncher_listapp_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (decoder->encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    case MALSPLITBINARY_FORMAT_CODE:
    {
      bool presence_flag;
      rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = softwaremanagement_malbinary_decode_mal_element(decoder, cursor, element_holder);
        if (rc < 0)
          return rc;
      }
      mal_element_holder_set_presence_flag(element_holder, presence_flag);
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int softwaremanagement_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor)
{
  int rc = 0;
  // Encoding abstract mal_element require encoding short form
  rc = mal_encoder_add_short_form_encoding_length(encoder, element_holder->short_form, cursor);
  if (rc < 0)
    return rc;
  if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM)
  {
    rc = com_activitytracking_activityacceptance_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activityacceptance_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM)
  {
    rc = com_activitytracking_activityexecution_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activityexecution_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM)
  {
    rc = com_activitytracking_activitytransfer_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activitytransfer_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM)
  {
    rc = com_activitytracking_operationactivity_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_operationactivity_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM)
  {
    rc = com_archive_archivedetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM)
  {
    rc = com_archive_archivedetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM)
  {
    rc = com_archive_archivequery_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM)
  {
    rc = com_archive_archivequery_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM)
  {
    rc = com_archive_compositefilter_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM)
  {
    rc = com_archive_compositefilter_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM)
  {
    rc = com_archive_compositefilterset_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM)
  {
    rc = com_archive_compositefilterset_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM)
  {
    rc = com_archive_expressionoperator_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_SHORT_FORM)
  {
    rc = com_archive_paginationfilter_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_LIST_SHORT_FORM)
  {
    rc = com_archive_paginationfilter_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_SHORT_FORM)
  {
    rc = com_archivesync_compactcomobject_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_SHORT_FORM)
  {
    rc = com_archivesync_compactcomobject_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_SHORT_FORM)
  {
    rc = com_archivesync_dictionary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_LIST_SHORT_FORM)
  {
    rc = com_archivesync_dictionary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_SHORT_FORM)
  {
    rc = com_archivesync_dictionaryentry_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_SHORT_FORM)
  {
    rc = com_archivesync_dictionaryentry_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_SHORT_FORM)
  {
    rc = com_archivesync_domainizedcomobjects_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_SHORT_FORM)
  {
    rc = com_archivesync_domainizedcomobjects_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_SHORT_FORM)
  {
    rc = com_instancebooleanpair_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_LIST_SHORT_FORM)
  {
    rc = com_instancebooleanpair_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_SHORT_FORM)
  {
    rc = com_objectdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_LIST_SHORT_FORM)
  {
    rc = com_objectdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_SHORT_FORM)
  {
    rc = com_objectid_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_LIST_SHORT_FORM)
  {
    rc = com_objectid_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_SHORT_FORM)
  {
    rc = com_objectkey_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_LIST_SHORT_FORM)
  {
    rc = com_objectkey_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_SHORT_FORM)
  {
    rc = com_objecttype_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_LIST_SHORT_FORM)
  {
    rc = com_objecttype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectset_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectset_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationtype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_SHORT_FORM)
  {
    rc = common_configuration_serviceconfigurationidentifier_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_SHORT_FORM)
  {
    rc = common_configuration_serviceconfigurationidentifier_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_SHORT_FORM)
  {
    rc = common_directory_addressdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_addressdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_SHORT_FORM)
  {
    rc = common_directory_providerdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_providerdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_SHORT_FORM)
  {
    rc = common_directory_providersummary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_SHORT_FORM)
  {
    rc = common_directory_providersummary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_SHORT_FORM)
  {
    rc = common_directory_publishdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_publishdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_SHORT_FORM)
  {
    rc = common_directory_servicecapability_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_LIST_SHORT_FORM)
  {
    rc = common_directory_servicecapability_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_SHORT_FORM)
  {
    rc = common_directory_servicefilter_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_LIST_SHORT_FORM)
  {
    rc = common_directory_servicefilter_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_SHORT_FORM)
  {
    rc = common_login_profile_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_LIST_SHORT_FORM)
  {
    rc = common_login_profile_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_SHORT_FORM)
  {
    rc = common_servicekey_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_LIST_SHORT_FORM)
  {
    rc = common_servicekey_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_SHORT_FORM)
  {
    rc = mal_encoder_add_blob_encoding_length(encoder, element_holder->value.blob_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_LIST_SHORT_FORM)
  {
    rc = mal_blob_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_SHORT_FORM)
  {
    rc = mal_encoder_add_boolean_encoding_length(encoder, element_holder->value.boolean_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_LIST_SHORT_FORM)
  {
    rc = mal_boolean_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_SHORT_FORM)
  {
    rc = mal_encoder_add_double_encoding_length(encoder, element_holder->value.double_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_LIST_SHORT_FORM)
  {
    rc = mal_double_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_SHORT_FORM)
  {
    rc = mal_encoder_add_duration_encoding_length(encoder, element_holder->value.duration_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_LIST_SHORT_FORM)
  {
    rc = mal_duration_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_SHORT_FORM)
  {
    rc = mal_entitykey_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_LIST_SHORT_FORM)
  {
    rc = mal_entitykey_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_SHORT_FORM)
  {
    rc = mal_entityrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_LIST_SHORT_FORM)
  {
    rc = mal_entityrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_SHORT_FORM)
  {
    rc = mal_file_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_LIST_SHORT_FORM)
  {
    rc = mal_file_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_SHORT_FORM)
  {
    rc = mal_encoder_add_finetime_encoding_length(encoder, element_holder->value.finetime_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_LIST_SHORT_FORM)
  {
    rc = mal_finetime_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_SHORT_FORM)
  {
    rc = mal_encoder_add_float_encoding_length(encoder, element_holder->value.float_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_LIST_SHORT_FORM)
  {
    rc = mal_float_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_SHORT_FORM)
  {
    rc = mal_idbooleanpair_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_LIST_SHORT_FORM)
  {
    rc = mal_idbooleanpair_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_SHORT_FORM)
  {
    rc = mal_encoder_add_identifier_encoding_length(encoder, element_holder->value.identifier_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_LIST_SHORT_FORM)
  {
    rc = mal_identifier_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_SHORT_FORM)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, element_holder->value.integer_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_LIST_SHORT_FORM)
  {
    rc = mal_integer_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_LIST_SHORT_FORM)
  {
    rc = mal_interactiontype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_SHORT_FORM)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, element_holder->value.long_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_LIST_SHORT_FORM)
  {
    rc = mal_long_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_SHORT_FORM)
  {
    rc = mal_namedvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_LIST_SHORT_FORM)
  {
    rc = mal_namedvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_SHORT_FORM)
  {
    rc = mal_encoder_add_octet_encoding_length(encoder, element_holder->value.octet_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_LIST_SHORT_FORM)
  {
    rc = mal_octet_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_SHORT_FORM)
  {
    rc = mal_pair_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_LIST_SHORT_FORM)
  {
    rc = mal_pair_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_LIST_SHORT_FORM)
  {
    rc = mal_qoslevel_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_LIST_SHORT_FORM)
  {
    rc = mal_sessiontype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_SHORT_FORM)
  {
    rc = mal_encoder_add_short_encoding_length(encoder, element_holder->value.short_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_LIST_SHORT_FORM)
  {
    rc = mal_short_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_SHORT_FORM)
  {
    rc = mal_encoder_add_string_encoding_length(encoder, element_holder->value.string_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_LIST_SHORT_FORM)
  {
    rc = mal_string_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_SHORT_FORM)
  {
    rc = mal_subscription_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_LIST_SHORT_FORM)
  {
    rc = mal_subscription_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_SHORT_FORM)
  {
    rc = mal_encoder_add_time_encoding_length(encoder, element_holder->value.time_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_LIST_SHORT_FORM)
  {
    rc = mal_time_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_SHORT_FORM)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, element_holder->value.uinteger_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_LIST_SHORT_FORM)
  {
    rc = mal_uinteger_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_SHORT_FORM)
  {
    rc = mal_encoder_add_ulong_encoding_length(encoder, element_holder->value.ulong_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_LIST_SHORT_FORM)
  {
    rc = mal_ulong_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_SHORT_FORM)
  {
    rc = mal_encoder_add_uoctet_encoding_length(encoder, element_holder->value.uoctet_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_LIST_SHORT_FORM)
  {
    rc = mal_uoctet_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_SHORT_FORM)
  {
    rc = mal_encoder_add_uri_encoding_length(encoder, element_holder->value.uri_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_LIST_SHORT_FORM)
  {
    rc = mal_uri_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_SHORT_FORM)
  {
    rc = mal_encoder_add_ushort_encoding_length(encoder, element_holder->value.ushort_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_LIST_SHORT_FORM)
  {
    rc = mal_ushort_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_SHORT_FORM)
  {
    rc = mal_updateheader_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_LIST_SHORT_FORM)
  {
    rc = mal_updateheader_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_LIST_SHORT_FORM)
  {
    rc = mal_updatetype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_LIST_SHORT_FORM)
  {
    rc = mc_action_actioncategory_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_action_actioncreationrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_action_actioncreationrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_action_actiondefinitiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_action_actiondefinitiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_SHORT_FORM)
  {
    rc = mc_action_actioninstancedetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_action_actioninstancedetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcategory_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcreationrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcreationrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinitiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinitiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparameterset_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparameterset_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparametervalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparametervalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationsetvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationsetvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvaluedetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvaluedetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_generationmode_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdfilter_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdfilter_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdtype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_alert_alertcreationrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertcreationrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_alert_alertdefinitiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertdefinitiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_SHORT_FORM)
  {
    rc = mc_alert_alerteventdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_alert_alerteventdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_SHORT_FORM)
  {
    rc = mc_check_checklinkdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_check_checklinkdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checklinksummary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checklinksummary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_SHORT_FORM)
  {
    rc = mc_check_checkresult_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresult_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_SHORT_FORM)
  {
    rc = mc_check_checkresultfilter_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresultfilter_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checkresultsummary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresultsummary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_LIST_SHORT_FORM)
  {
    rc = mc_check_checkstate_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_SHORT_FORM)
  {
    rc = mc_check_checktypedinstance_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_LIST_SHORT_FORM)
  {
    rc = mc_check_checktypedinstance_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_compoundcheckdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_compoundcheckdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_constantcheckdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_constantcheckdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_deltacheckdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_deltacheckdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_limitcheckdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_limitcheckdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_referencecheckdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_referencecheckdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_SHORT_FORM)
  {
    rc = mc_check_referencevalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_LIST_SHORT_FORM)
  {
    rc = mc_check_referencevalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_discreteconversiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_discreteconversiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_lineconversiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_lineconversiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_polyconversiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_polyconversiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_rangeconversiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_rangeconversiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_SHORT_FORM)
  {
    rc = mc_group_groupdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_group_groupdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_SHORT_FORM)
  {
    rc = mc_parameter_parameterconversion_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterconversion_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_parameter_parametercreationrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametercreationrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinitiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinitiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_SHORT_FORM)
  {
    rc = mc_parameter_parameterrawvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterrawvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_SHORT_FORM)
  {
    rc = mc_parameter_parametervalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametervalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_SHORT_FORM)
  {
    rc = mc_parameter_parametervaluedetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametervaluedetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_validitystate_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_statistic_statisticcreationrequest_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticcreationrequest_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_SHORT_FORM)
  {
    rc = mc_statistic_statisticevaluationreport_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticevaluationreport_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_SHORT_FORM)
  {
    rc = mc_statistic_statisticfunctiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticfunctiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinkdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinkdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinksummary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinksummary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_SHORT_FORM)
  {
    rc = mc_statistic_statisticvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_argumentdefinitiondetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_argumentdefinitiondetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_SHORT_FORM)
  {
    rc = mc_attributevalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_LIST_SHORT_FORM)
  {
    rc = mc_attributevalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_SHORT_FORM)
  {
    rc = mc_conditionalconversion_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_LIST_SHORT_FORM)
  {
    rc = mc_conditionalconversion_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_SHORT_FORM)
  {
    rc = mc_objectinstancepair_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_LIST_SHORT_FORM)
  {
    rc = mc_objectinstancepair_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_SHORT_FORM)
  {
    rc = mc_parameterexpression_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_LIST_SHORT_FORM)
  {
    rc = mc_parameterexpression_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_SEVERITY_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_SEVERITY_LIST_SHORT_FORM)
  {
    rc = mc_severity_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_SHORT_FORM)
  {
    rc = pf_autonomousadcs_actuatorstelemetry_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_actuatorstelemetry_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodebdot_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodebdot_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodenadirpointing_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodenadirpointing_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesinglespinning_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesinglespinning_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesunpointing_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesunpointing_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettracking_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettracking_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodevectorpointing_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodevectorpointing_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudetelemetry_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudetelemetry_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_magnetorquersstate_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_SHORT_FORM)
  {
    rc = pf_autonomousadcs_quaternion_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_quaternion_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelidentifier_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelparameters_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelparameters_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_SHORT_FORM)
  {
    rc = pf_autonomousadcs_wheelsspeed_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_wheelsspeed_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_SHORT_FORM)
  {
    rc = pf_camera_camerasettings_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_LIST_SHORT_FORM)
  {
    rc = pf_camera_camerasettings_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_SHORT_FORM)
  {
    rc = pf_camera_picture_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_LIST_SHORT_FORM)
  {
    rc = pf_camera_picture_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_LIST_SHORT_FORM)
  {
    rc = pf_camera_pictureformat_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_SHORT_FORM)
  {
    rc = pf_camera_pixelresolution_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_LIST_SHORT_FORM)
  {
    rc = pf_camera_pixelresolution_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_SHORT_FORM)
  {
    rc = pf_gps_nearbypositiondefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_LIST_SHORT_FORM)
  {
    rc = pf_gps_nearbypositiondefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_SHORT_FORM)
  {
    rc = pf_gps_position_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_LIST_SHORT_FORM)
  {
    rc = pf_gps_position_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_SHORT_FORM)
  {
    rc = pf_gps_positionextradetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_LIST_SHORT_FORM)
  {
    rc = pf_gps_positionextradetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_SHORT_FORM)
  {
    rc = pf_gps_satelliteinfo_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_LIST_SHORT_FORM)
  {
    rc = pf_gps_satelliteinfo_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_SHORT_FORM)
  {
    rc = pf_gps_twolineelementset_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_LIST_SHORT_FORM)
  {
    rc = pf_gps_twolineelementset_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_SHORT_FORM)
  {
    rc = pf_powercontrol_device_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_LIST_SHORT_FORM)
  {
    rc = pf_powercontrol_device_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_LIST_SHORT_FORM)
  {
    rc = pf_powercontrol_devicetype_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_iqcomponents_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_iqcomponents_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_sdrconfiguration_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_sdrconfiguration_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_SHORT_FORM)
  {
    rc = pf_vectord3d_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_LIST_SHORT_FORM)
  {
    rc = pf_vectord3d_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_SHORT_FORM)
  {
    rc = pf_vectorf3d_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_LIST_SHORT_FORM)
  {
    rc = pf_vectorf3d_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_appslauncher_appdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_appslauncher_appdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_commandexecutor_commanddetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_commandexecutor_commanddetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_installationdetails_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_installationdetails_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_packagedefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_packagedefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

int softwaremanagement_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder)
{
  int rc = 0;
  // Encoding abstract mal_element require encoding short form
  rc = mal_encoder_encode_short_form(encoder, cursor, element_holder->short_form);
  if (rc < 0)
    return rc;
  if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM)
  {
    rc = com_activitytracking_activityacceptance_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activityacceptance_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM)
  {
    rc = com_activitytracking_activityexecution_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activityexecution_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM)
  {
    rc = com_activitytracking_activitytransfer_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_activitytransfer_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM)
  {
    rc = com_activitytracking_operationactivity_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM)
  {
    rc = com_activitytracking_operationactivity_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM)
  {
    rc = com_archive_archivedetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM)
  {
    rc = com_archive_archivedetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM)
  {
    rc = com_archive_archivequery_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM)
  {
    rc = com_archive_archivequery_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM)
  {
    rc = com_archive_compositefilter_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM)
  {
    rc = com_archive_compositefilter_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM)
  {
    rc = com_archive_compositefilterset_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM)
  {
    rc = com_archive_compositefilterset_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM)
  {
    rc = com_archive_expressionoperator_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_SHORT_FORM)
  {
    rc = com_archive_paginationfilter_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_LIST_SHORT_FORM)
  {
    rc = com_archive_paginationfilter_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_SHORT_FORM)
  {
    rc = com_archivesync_compactcomobject_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_SHORT_FORM)
  {
    rc = com_archivesync_compactcomobject_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_SHORT_FORM)
  {
    rc = com_archivesync_dictionary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_LIST_SHORT_FORM)
  {
    rc = com_archivesync_dictionary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_SHORT_FORM)
  {
    rc = com_archivesync_dictionaryentry_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_SHORT_FORM)
  {
    rc = com_archivesync_dictionaryentry_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_SHORT_FORM)
  {
    rc = com_archivesync_domainizedcomobjects_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_SHORT_FORM)
  {
    rc = com_archivesync_domainizedcomobjects_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_SHORT_FORM)
  {
    rc = com_instancebooleanpair_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_LIST_SHORT_FORM)
  {
    rc = com_instancebooleanpair_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_SHORT_FORM)
  {
    rc = com_objectdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_LIST_SHORT_FORM)
  {
    rc = com_objectdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_SHORT_FORM)
  {
    rc = com_objectid_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_LIST_SHORT_FORM)
  {
    rc = com_objectid_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_SHORT_FORM)
  {
    rc = com_objectkey_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_LIST_SHORT_FORM)
  {
    rc = com_objectkey_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_SHORT_FORM)
  {
    rc = com_objecttype_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_LIST_SHORT_FORM)
  {
    rc = com_objecttype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectset_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationobjectset_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_SHORT_FORM)
  {
    rc = common_configuration_configurationtype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_SHORT_FORM)
  {
    rc = common_configuration_serviceconfigurationidentifier_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_SHORT_FORM)
  {
    rc = common_configuration_serviceconfigurationidentifier_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_SHORT_FORM)
  {
    rc = common_directory_addressdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_addressdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_SHORT_FORM)
  {
    rc = common_directory_providerdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_providerdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_SHORT_FORM)
  {
    rc = common_directory_providersummary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_SHORT_FORM)
  {
    rc = common_directory_providersummary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_SHORT_FORM)
  {
    rc = common_directory_publishdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_LIST_SHORT_FORM)
  {
    rc = common_directory_publishdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_SHORT_FORM)
  {
    rc = common_directory_servicecapability_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_LIST_SHORT_FORM)
  {
    rc = common_directory_servicecapability_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_SHORT_FORM)
  {
    rc = common_directory_servicefilter_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_LIST_SHORT_FORM)
  {
    rc = common_directory_servicefilter_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_SHORT_FORM)
  {
    rc = common_login_profile_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_LIST_SHORT_FORM)
  {
    rc = common_login_profile_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_SHORT_FORM)
  {
    rc = common_servicekey_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_LIST_SHORT_FORM)
  {
    rc = common_servicekey_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_SHORT_FORM)
  {
    rc = mal_encoder_encode_blob(encoder, cursor, element_holder->value.blob_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_LIST_SHORT_FORM)
  {
    rc = mal_blob_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_SHORT_FORM)
  {
    rc = mal_encoder_encode_boolean(encoder, cursor, element_holder->value.boolean_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_LIST_SHORT_FORM)
  {
    rc = mal_boolean_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_SHORT_FORM)
  {
    rc = mal_encoder_encode_double(encoder, cursor, element_holder->value.double_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_LIST_SHORT_FORM)
  {
    rc = mal_double_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_SHORT_FORM)
  {
    rc = mal_encoder_encode_duration(encoder, cursor, element_holder->value.duration_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_LIST_SHORT_FORM)
  {
    rc = mal_duration_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_SHORT_FORM)
  {
    rc = mal_entitykey_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_LIST_SHORT_FORM)
  {
    rc = mal_entitykey_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_SHORT_FORM)
  {
    rc = mal_entityrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_LIST_SHORT_FORM)
  {
    rc = mal_entityrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_SHORT_FORM)
  {
    rc = mal_file_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_LIST_SHORT_FORM)
  {
    rc = mal_file_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_SHORT_FORM)
  {
    rc = mal_encoder_encode_finetime(encoder, cursor, element_holder->value.finetime_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_LIST_SHORT_FORM)
  {
    rc = mal_finetime_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_SHORT_FORM)
  {
    rc = mal_encoder_encode_float(encoder, cursor, element_holder->value.float_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_LIST_SHORT_FORM)
  {
    rc = mal_float_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_SHORT_FORM)
  {
    rc = mal_idbooleanpair_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_LIST_SHORT_FORM)
  {
    rc = mal_idbooleanpair_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_SHORT_FORM)
  {
    rc = mal_encoder_encode_identifier(encoder, cursor, element_holder->value.identifier_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_LIST_SHORT_FORM)
  {
    rc = mal_identifier_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_SHORT_FORM)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, element_holder->value.integer_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_LIST_SHORT_FORM)
  {
    rc = mal_integer_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_LIST_SHORT_FORM)
  {
    rc = mal_interactiontype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_SHORT_FORM)
  {
    rc = mal_encoder_encode_long(encoder, cursor, element_holder->value.long_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_LIST_SHORT_FORM)
  {
    rc = mal_long_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_SHORT_FORM)
  {
    rc = mal_namedvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_LIST_SHORT_FORM)
  {
    rc = mal_namedvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_SHORT_FORM)
  {
    rc = mal_encoder_encode_octet(encoder, cursor, element_holder->value.octet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_LIST_SHORT_FORM)
  {
    rc = mal_octet_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_SHORT_FORM)
  {
    rc = mal_pair_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_LIST_SHORT_FORM)
  {
    rc = mal_pair_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_LIST_SHORT_FORM)
  {
    rc = mal_qoslevel_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_LIST_SHORT_FORM)
  {
    rc = mal_sessiontype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_SHORT_FORM)
  {
    rc = mal_encoder_encode_short(encoder, cursor, element_holder->value.short_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_LIST_SHORT_FORM)
  {
    rc = mal_short_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_SHORT_FORM)
  {
    rc = mal_encoder_encode_string(encoder, cursor, element_holder->value.string_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_LIST_SHORT_FORM)
  {
    rc = mal_string_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_SHORT_FORM)
  {
    rc = mal_subscription_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_LIST_SHORT_FORM)
  {
    rc = mal_subscription_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_SHORT_FORM)
  {
    rc = mal_encoder_encode_time(encoder, cursor, element_holder->value.time_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_LIST_SHORT_FORM)
  {
    rc = mal_time_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_SHORT_FORM)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, element_holder->value.uinteger_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_LIST_SHORT_FORM)
  {
    rc = mal_uinteger_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_SHORT_FORM)
  {
    rc = mal_encoder_encode_ulong(encoder, cursor, element_holder->value.ulong_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_LIST_SHORT_FORM)
  {
    rc = mal_ulong_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_SHORT_FORM)
  {
    rc = mal_encoder_encode_uoctet(encoder, cursor, element_holder->value.uoctet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_LIST_SHORT_FORM)
  {
    rc = mal_uoctet_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_SHORT_FORM)
  {
    rc = mal_encoder_encode_uri(encoder, cursor, element_holder->value.uri_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_LIST_SHORT_FORM)
  {
    rc = mal_uri_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_SHORT_FORM)
  {
    rc = mal_encoder_encode_ushort(encoder, cursor, element_holder->value.ushort_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_LIST_SHORT_FORM)
  {
    rc = mal_ushort_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_SHORT_FORM)
  {
    rc = mal_updateheader_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_LIST_SHORT_FORM)
  {
    rc = mal_updateheader_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_LIST_SHORT_FORM)
  {
    rc = mal_updatetype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_LIST_SHORT_FORM)
  {
    rc = mc_action_actioncategory_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_action_actioncreationrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_action_actioncreationrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_action_actiondefinitiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_action_actiondefinitiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_SHORT_FORM)
  {
    rc = mc_action_actioninstancedetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_action_actioninstancedetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcategory_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcreationrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationcreationrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinitiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinitiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparameterset_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparameterset_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparametervalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationparametervalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationsetvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationsetvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvaluedetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationvaluedetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_generationmode_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdfilter_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdfilter_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_thresholdtype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_alert_alertcreationrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertcreationrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_alert_alertdefinitiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertdefinitiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_SHORT_FORM)
  {
    rc = mc_alert_alerteventdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_alert_alerteventdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_SHORT_FORM)
  {
    rc = mc_check_checklinkdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_check_checklinkdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checklinksummary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checklinksummary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_SHORT_FORM)
  {
    rc = mc_check_checkresult_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresult_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_SHORT_FORM)
  {
    rc = mc_check_checkresultfilter_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresultfilter_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checkresultsummary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checkresultsummary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_LIST_SHORT_FORM)
  {
    rc = mc_check_checkstate_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_SHORT_FORM)
  {
    rc = mc_check_checktypedinstance_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_LIST_SHORT_FORM)
  {
    rc = mc_check_checktypedinstance_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_compoundcheckdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_compoundcheckdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_constantcheckdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_constantcheckdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_deltacheckdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_deltacheckdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_limitcheckdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_limitcheckdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_SHORT_FORM)
  {
    rc = mc_check_referencecheckdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_check_referencecheckdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_SHORT_FORM)
  {
    rc = mc_check_referencevalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_LIST_SHORT_FORM)
  {
    rc = mc_check_referencevalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_discreteconversiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_discreteconversiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_lineconversiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_lineconversiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_polyconversiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_polyconversiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_SHORT_FORM)
  {
    rc = mc_conversion_rangeconversiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_conversion_rangeconversiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_SHORT_FORM)
  {
    rc = mc_group_groupdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_group_groupdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_SHORT_FORM)
  {
    rc = mc_parameter_parameterconversion_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterconversion_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_parameter_parametercreationrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametercreationrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinitiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinitiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_SHORT_FORM)
  {
    rc = mc_parameter_parameterrawvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterrawvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_SHORT_FORM)
  {
    rc = mc_parameter_parametervalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametervalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_SHORT_FORM)
  {
    rc = mc_parameter_parametervaluedetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parametervaluedetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_LIST_SHORT_FORM)
  {
    rc = mc_parameter_validitystate_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_SHORT_FORM)
  {
    rc = mc_statistic_statisticcreationrequest_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticcreationrequest_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_SHORT_FORM)
  {
    rc = mc_statistic_statisticevaluationreport_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticevaluationreport_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_SHORT_FORM)
  {
    rc = mc_statistic_statisticfunctiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticfunctiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinkdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinkdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinksummary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticlinksummary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_SHORT_FORM)
  {
    rc = mc_statistic_statisticvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_LIST_SHORT_FORM)
  {
    rc = mc_statistic_statisticvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_SHORT_FORM)
  {
    rc = mc_argumentdefinitiondetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    rc = mc_argumentdefinitiondetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_SHORT_FORM)
  {
    rc = mc_attributevalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_LIST_SHORT_FORM)
  {
    rc = mc_attributevalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_SHORT_FORM)
  {
    rc = mc_conditionalconversion_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_LIST_SHORT_FORM)
  {
    rc = mc_conditionalconversion_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_SHORT_FORM)
  {
    rc = mc_objectinstancepair_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_LIST_SHORT_FORM)
  {
    rc = mc_objectinstancepair_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_SHORT_FORM)
  {
    rc = mc_parameterexpression_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_LIST_SHORT_FORM)
  {
    rc = mc_parameterexpression_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_SEVERITY_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_SEVERITY_LIST_SHORT_FORM)
  {
    rc = mc_severity_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_SHORT_FORM)
  {
    rc = pf_autonomousadcs_actuatorstelemetry_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_actuatorstelemetry_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodebdot_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodebdot_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodenadirpointing_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodenadirpointing_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesinglespinning_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesinglespinning_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesunpointing_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodesunpointing_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettracking_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettracking_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodevectorpointing_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudemodevectorpointing_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudetelemetry_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_attitudetelemetry_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_magnetorquersstate_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_SHORT_FORM)
  {
    rc = pf_autonomousadcs_quaternion_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_quaternion_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelidentifier_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelparameters_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_reactionwheelparameters_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_SHORT_FORM)
  {
    rc = pf_autonomousadcs_wheelsspeed_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_SHORT_FORM)
  {
    rc = pf_autonomousadcs_wheelsspeed_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_SHORT_FORM)
  {
    rc = pf_camera_camerasettings_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_LIST_SHORT_FORM)
  {
    rc = pf_camera_camerasettings_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_SHORT_FORM)
  {
    rc = pf_camera_picture_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_LIST_SHORT_FORM)
  {
    rc = pf_camera_picture_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_LIST_SHORT_FORM)
  {
    rc = pf_camera_pictureformat_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_SHORT_FORM)
  {
    rc = pf_camera_pixelresolution_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_LIST_SHORT_FORM)
  {
    rc = pf_camera_pixelresolution_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_SHORT_FORM)
  {
    rc = pf_gps_nearbypositiondefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_LIST_SHORT_FORM)
  {
    rc = pf_gps_nearbypositiondefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_SHORT_FORM)
  {
    rc = pf_gps_position_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_LIST_SHORT_FORM)
  {
    rc = pf_gps_position_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_SHORT_FORM)
  {
    rc = pf_gps_positionextradetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_LIST_SHORT_FORM)
  {
    rc = pf_gps_positionextradetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_SHORT_FORM)
  {
    rc = pf_gps_satelliteinfo_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_LIST_SHORT_FORM)
  {
    rc = pf_gps_satelliteinfo_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_SHORT_FORM)
  {
    rc = pf_gps_twolineelementset_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_LIST_SHORT_FORM)
  {
    rc = pf_gps_twolineelementset_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_SHORT_FORM)
  {
    rc = pf_powercontrol_device_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_LIST_SHORT_FORM)
  {
    rc = pf_powercontrol_device_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_LIST_SHORT_FORM)
  {
    rc = pf_powercontrol_devicetype_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_iqcomponents_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_iqcomponents_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_sdrconfiguration_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_SHORT_FORM)
  {
    rc = pf_softwaredefinedradio_sdrconfiguration_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_SHORT_FORM)
  {
    rc = pf_vectord3d_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_LIST_SHORT_FORM)
  {
    rc = pf_vectord3d_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_SHORT_FORM)
  {
    rc = pf_vectorf3d_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_LIST_SHORT_FORM)
  {
    rc = pf_vectorf3d_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_appslauncher_appdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_appslauncher_appdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_commandexecutor_commanddetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_commandexecutor_commanddetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_installationdetails_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_installationdetails_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_packagedefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_SHORT_FORM)
  {
    rc = softwaremanagement_packagemanagement_packagedefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

int softwaremanagement_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder)
{
  int enumerated_value = 0;
  int rc = 0;
  rc = mal_decoder_decode_short_form(decoder, cursor, &element_holder->short_form);
  if (rc < 0)
    return rc;
  if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_SHORT_FORM)
  {
    element_holder->value.composite_value = com_activitytracking_activityacceptance_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_activitytracking_activityacceptance_decode_malbinary((com_activitytracking_activityacceptance_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYACCEPTANCE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_activitytracking_activityacceptance_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_activitytracking_activityacceptance_list_decode_malbinary((com_activitytracking_activityacceptance_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_SHORT_FORM)
  {
    element_holder->value.composite_value = com_activitytracking_activityexecution_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_activitytracking_activityexecution_decode_malbinary((com_activitytracking_activityexecution_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYEXECUTION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_activitytracking_activityexecution_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_activitytracking_activityexecution_list_decode_malbinary((com_activitytracking_activityexecution_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_SHORT_FORM)
  {
    element_holder->value.composite_value = com_activitytracking_activitytransfer_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_activitytracking_activitytransfer_decode_malbinary((com_activitytracking_activitytransfer_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_ACTIVITYTRANSFER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_activitytracking_activitytransfer_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_activitytracking_activitytransfer_list_decode_malbinary((com_activitytracking_activitytransfer_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_SHORT_FORM)
  {
    element_holder->value.composite_value = com_activitytracking_operationactivity_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_activitytracking_operationactivity_decode_malbinary((com_activitytracking_operationactivity_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ACTIVITYTRACKING_OPERATIONACTIVITY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_activitytracking_operationactivity_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_activitytracking_operationactivity_list_decode_malbinary((com_activitytracking_operationactivity_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archive_archivedetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archive_archivedetails_decode_malbinary((com_archive_archivedetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_archivedetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_archivedetails_list_decode_malbinary((com_archive_archivedetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archive_archivequery_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archive_archivequery_decode_malbinary((com_archive_archivequery_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_ARCHIVEQUERY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_archivequery_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_archivequery_list_decode_malbinary((com_archive_archivequery_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archive_compositefilter_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archive_compositefilter_decode_malbinary((com_archive_compositefilter_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_compositefilter_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_compositefilter_list_decode_malbinary((com_archive_compositefilter_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archive_compositefilterset_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archive_compositefilterset_decode_malbinary((com_archive_compositefilterset_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_COMPOSITEFILTERSET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_compositefilterset_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_compositefilterset_list_decode_malbinary((com_archive_compositefilterset_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (com_archive_expressionoperator_t) enumerated_value;
  }
  else if (element_holder->short_form == COM_ARCHIVE_EXPRESSIONOPERATOR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_expressionoperator_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_expressionoperator_list_decode_malbinary((com_archive_expressionoperator_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archive_paginationfilter_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archive_paginationfilter_decode_malbinary((com_archive_paginationfilter_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVE_PAGINATIONFILTER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archive_paginationfilter_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archive_paginationfilter_list_decode_malbinary((com_archive_paginationfilter_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archivesync_compactcomobject_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archivesync_compactcomobject_decode_malbinary((com_archivesync_compactcomobject_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_COMPACTCOMOBJECT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archivesync_compactcomobject_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archivesync_compactcomobject_list_decode_malbinary((com_archivesync_compactcomobject_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archivesync_dictionary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archivesync_dictionary_decode_malbinary((com_archivesync_dictionary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archivesync_dictionary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archivesync_dictionary_list_decode_malbinary((com_archivesync_dictionary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archivesync_dictionaryentry_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archivesync_dictionaryentry_decode_malbinary((com_archivesync_dictionaryentry_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DICTIONARYENTRY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archivesync_dictionaryentry_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archivesync_dictionaryentry_list_decode_malbinary((com_archivesync_dictionaryentry_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_SHORT_FORM)
  {
    element_holder->value.composite_value = com_archivesync_domainizedcomobjects_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_archivesync_domainizedcomobjects_decode_malbinary((com_archivesync_domainizedcomobjects_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_ARCHIVESYNC_DOMAINIZEDCOMOBJECTS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_archivesync_domainizedcomobjects_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_archivesync_domainizedcomobjects_list_decode_malbinary((com_archivesync_domainizedcomobjects_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = com_instancebooleanpair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_instancebooleanpair_decode_malbinary((com_instancebooleanpair_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_INSTANCEBOOLEANPAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_instancebooleanpair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_instancebooleanpair_list_decode_malbinary((com_instancebooleanpair_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = com_objectdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_objectdetails_decode_malbinary((com_objectdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_objectdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_objectdetails_list_decode_malbinary((com_objectdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_SHORT_FORM)
  {
    element_holder->value.composite_value = com_objectid_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_objectid_decode_malbinary((com_objectid_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTID_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_objectid_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_objectid_list_decode_malbinary((com_objectid_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_SHORT_FORM)
  {
    element_holder->value.composite_value = com_objectkey_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_objectkey_decode_malbinary((com_objectkey_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTKEY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_objectkey_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_objectkey_list_decode_malbinary((com_objectkey_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_SHORT_FORM)
  {
    element_holder->value.composite_value = com_objecttype_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = com_objecttype_decode_malbinary((com_objecttype_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COM_OBJECTTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = com_objecttype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = com_objecttype_list_decode_malbinary((com_objecttype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = common_configuration_configurationobjectdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_configuration_configurationobjectdetails_decode_malbinary((common_configuration_configurationobjectdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_configuration_configurationobjectdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_configuration_configurationobjectdetails_list_decode_malbinary((common_configuration_configurationobjectdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_SHORT_FORM)
  {
    element_holder->value.composite_value = common_configuration_configurationobjectset_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_configuration_configurationobjectset_decode_malbinary((common_configuration_configurationobjectset_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONOBJECTSET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_configuration_configurationobjectset_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_configuration_configurationobjectset_list_decode_malbinary((common_configuration_configurationobjectset_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (common_configuration_configurationtype_t) enumerated_value;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_CONFIGURATIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_configuration_configurationtype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_configuration_configurationtype_list_decode_malbinary((common_configuration_configurationtype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_SHORT_FORM)
  {
    element_holder->value.composite_value = common_configuration_serviceconfigurationidentifier_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_configuration_serviceconfigurationidentifier_decode_malbinary((common_configuration_serviceconfigurationidentifier_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_CONFIGURATION_SERVICECONFIGURATIONIDENTIFIER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_configuration_serviceconfigurationidentifier_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_configuration_serviceconfigurationidentifier_list_decode_malbinary((common_configuration_serviceconfigurationidentifier_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_addressdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_addressdetails_decode_malbinary((common_directory_addressdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_ADDRESSDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_addressdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_addressdetails_list_decode_malbinary((common_directory_addressdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_providerdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_providerdetails_decode_malbinary((common_directory_providerdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_providerdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_providerdetails_list_decode_malbinary((common_directory_providerdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_providersummary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_providersummary_decode_malbinary((common_directory_providersummary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PROVIDERSUMMARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_providersummary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_providersummary_list_decode_malbinary((common_directory_providersummary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_publishdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_publishdetails_decode_malbinary((common_directory_publishdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_PUBLISHDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_publishdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_publishdetails_list_decode_malbinary((common_directory_publishdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_servicecapability_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_servicecapability_decode_malbinary((common_directory_servicecapability_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICECAPABILITY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_servicecapability_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_servicecapability_list_decode_malbinary((common_directory_servicecapability_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_SHORT_FORM)
  {
    element_holder->value.composite_value = common_directory_servicefilter_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_directory_servicefilter_decode_malbinary((common_directory_servicefilter_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_DIRECTORY_SERVICEFILTER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_directory_servicefilter_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_directory_servicefilter_list_decode_malbinary((common_directory_servicefilter_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_SHORT_FORM)
  {
    element_holder->value.composite_value = common_login_profile_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_login_profile_decode_malbinary((common_login_profile_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_LOGIN_PROFILE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_login_profile_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_login_profile_list_decode_malbinary((common_login_profile_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_SHORT_FORM)
  {
    element_holder->value.composite_value = common_servicekey_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = common_servicekey_decode_malbinary((common_servicekey_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == COMMON_SERVICEKEY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = common_servicekey_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = common_servicekey_list_decode_malbinary((common_servicekey_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_SHORT_FORM)
  {
    rc = mal_decoder_decode_blob(decoder, cursor, &element_holder->value.blob_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_blob_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_blob_list_decode_malbinary((mal_blob_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_SHORT_FORM)
  {
    rc = mal_decoder_decode_boolean(decoder, cursor, &element_holder->value.boolean_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_boolean_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary((mal_boolean_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_SHORT_FORM)
  {
    rc = mal_decoder_decode_double(decoder, cursor, &element_holder->value.double_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_double_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_double_list_decode_malbinary((mal_double_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_SHORT_FORM)
  {
    rc = mal_decoder_decode_duration(decoder, cursor, &element_holder->value.duration_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_duration_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_duration_list_decode_malbinary((mal_duration_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entitykey_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entitykey_decode_malbinary((mal_entitykey_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entitykey_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entitykey_list_decode_malbinary((mal_entitykey_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entityrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entityrequest_decode_malbinary((mal_entityrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entityrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entityrequest_list_decode_malbinary((mal_entityrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_file_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_file_decode_malbinary((mal_file_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_file_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_file_list_decode_malbinary((mal_file_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_SHORT_FORM)
  {
    rc = mal_decoder_decode_finetime(decoder, cursor, &element_holder->value.finetime_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_finetime_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_finetime_list_decode_malbinary((mal_finetime_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_SHORT_FORM)
  {
    rc = mal_decoder_decode_float(decoder, cursor, &element_holder->value.float_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_float_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_float_list_decode_malbinary((mal_float_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_idbooleanpair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_idbooleanpair_decode_malbinary((mal_idbooleanpair_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_idbooleanpair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_idbooleanpair_list_decode_malbinary((mal_idbooleanpair_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_SHORT_FORM)
  {
    rc = mal_decoder_decode_identifier(decoder, cursor, &element_holder->value.identifier_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_identifier_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary((mal_identifier_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_SHORT_FORM)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &element_holder->value.integer_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_integer_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_integer_list_decode_malbinary((mal_integer_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_interactiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_interactiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_interactiontype_list_decode_malbinary((mal_interactiontype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_SHORT_FORM)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &element_holder->value.long_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_long_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_long_list_decode_malbinary((mal_long_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_namedvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_namedvalue_decode_malbinary((mal_namedvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_namedvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary((mal_namedvalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_SHORT_FORM)
  {
    rc = mal_decoder_decode_octet(decoder, cursor, &element_holder->value.octet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_octet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_octet_list_decode_malbinary((mal_octet_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_pair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_pair_decode_malbinary((mal_pair_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_pair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_pair_list_decode_malbinary((mal_pair_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_qoslevel_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_qoslevel_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_qoslevel_list_decode_malbinary((mal_qoslevel_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_sessiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_sessiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_sessiontype_list_decode_malbinary((mal_sessiontype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_SHORT_FORM)
  {
    rc = mal_decoder_decode_short(decoder, cursor, &element_holder->value.short_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_short_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_short_list_decode_malbinary((mal_short_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_SHORT_FORM)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &element_holder->value.string_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_string_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_string_list_decode_malbinary((mal_string_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_subscription_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_subscription_decode_malbinary((mal_subscription_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_subscription_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_subscription_list_decode_malbinary((mal_subscription_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_SHORT_FORM)
  {
    rc = mal_decoder_decode_time(decoder, cursor, &element_holder->value.time_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_time_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_time_list_decode_malbinary((mal_time_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_SHORT_FORM)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &element_holder->value.uinteger_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uinteger_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uinteger_list_decode_malbinary((mal_uinteger_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_SHORT_FORM)
  {
    rc = mal_decoder_decode_ulong(decoder, cursor, &element_holder->value.ulong_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ulong_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ulong_list_decode_malbinary((mal_ulong_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_SHORT_FORM)
  {
    rc = mal_decoder_decode_uoctet(decoder, cursor, &element_holder->value.uoctet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uoctet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uoctet_list_decode_malbinary((mal_uoctet_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_SHORT_FORM)
  {
    rc = mal_decoder_decode_uri(decoder, cursor, &element_holder->value.uri_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uri_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uri_list_decode_malbinary((mal_uri_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_SHORT_FORM)
  {
    rc = mal_decoder_decode_ushort(decoder, cursor, &element_holder->value.ushort_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ushort_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ushort_list_decode_malbinary((mal_ushort_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_updateheader_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_updateheader_decode_malbinary((mal_updateheader_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updateheader_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updateheader_list_decode_malbinary((mal_updateheader_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_updatetype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updatetype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updatetype_list_decode_malbinary((mal_updatetype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_action_actioncategory_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCATEGORY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_action_actioncategory_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_action_actioncategory_list_decode_malbinary((mc_action_actioncategory_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_action_actioncreationrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_action_actioncreationrequest_decode_malbinary((mc_action_actioncreationrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_action_actioncreationrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_action_actioncreationrequest_list_decode_malbinary((mc_action_actioncreationrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_action_actiondefinitiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_action_actiondefinitiondetails_decode_malbinary((mc_action_actiondefinitiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_action_actiondefinitiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_action_actiondefinitiondetails_list_decode_malbinary((mc_action_actiondefinitiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_action_actioninstancedetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_action_actioninstancedetails_decode_malbinary((mc_action_actioninstancedetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ACTION_ACTIONINSTANCEDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_action_actioninstancedetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_action_actioninstancedetails_list_decode_malbinary((mc_action_actioninstancedetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_aggregation_aggregationcategory_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationcategory_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationcategory_list_decode_malbinary((mc_aggregation_aggregationcategory_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationcreationrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationcreationrequest_decode_malbinary((mc_aggregation_aggregationcreationrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationcreationrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationcreationrequest_list_decode_malbinary((mc_aggregation_aggregationcreationrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationdefinitiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationdefinitiondetails_decode_malbinary((mc_aggregation_aggregationdefinitiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationdefinitiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationdefinitiondetails_list_decode_malbinary((mc_aggregation_aggregationdefinitiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationparameterset_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationparameterset_decode_malbinary((mc_aggregation_aggregationparameterset_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationparameterset_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationparameterset_list_decode_malbinary((mc_aggregation_aggregationparameterset_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationparametervalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationparametervalue_decode_malbinary((mc_aggregation_aggregationparametervalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationparametervalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationparametervalue_list_decode_malbinary((mc_aggregation_aggregationparametervalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationsetvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationsetvalue_decode_malbinary((mc_aggregation_aggregationsetvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationsetvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationsetvalue_list_decode_malbinary((mc_aggregation_aggregationsetvalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationvalue_decode_malbinary((mc_aggregation_aggregationvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationvalue_list_decode_malbinary((mc_aggregation_aggregationvalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationvaluedetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationvaluedetails_decode_malbinary((mc_aggregation_aggregationvaluedetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationvaluedetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationvaluedetails_list_decode_malbinary((mc_aggregation_aggregationvaluedetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_aggregation_generationmode_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_AGGREGATION_GENERATIONMODE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_generationmode_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_generationmode_list_decode_malbinary((mc_aggregation_generationmode_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_thresholdfilter_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_thresholdfilter_decode_malbinary((mc_aggregation_thresholdfilter_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDFILTER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_thresholdfilter_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_thresholdfilter_list_decode_malbinary((mc_aggregation_thresholdfilter_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_aggregation_thresholdtype_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_AGGREGATION_THRESHOLDTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_thresholdtype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_thresholdtype_list_decode_malbinary((mc_aggregation_thresholdtype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_alert_alertcreationrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_alert_alertcreationrequest_decode_malbinary((mc_alert_alertcreationrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTCREATIONREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_alert_alertcreationrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_alert_alertcreationrequest_list_decode_malbinary((mc_alert_alertcreationrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_alert_alertdefinitiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_alert_alertdefinitiondetails_decode_malbinary((mc_alert_alertdefinitiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_alert_alertdefinitiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_alert_alertdefinitiondetails_list_decode_malbinary((mc_alert_alertdefinitiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_alert_alerteventdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_alert_alerteventdetails_decode_malbinary((mc_alert_alerteventdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENTDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_alert_alerteventdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_alert_alerteventdetails_list_decode_malbinary((mc_alert_alerteventdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checklinkdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checklinkdetails_decode_malbinary((mc_check_checklinkdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checklinkdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checklinkdetails_list_decode_malbinary((mc_check_checklinkdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checklinksummary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checklinksummary_decode_malbinary((mc_check_checklinksummary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINKSUMMARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checklinksummary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checklinksummary_list_decode_malbinary((mc_check_checklinksummary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checkresult_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checkresult_decode_malbinary((mc_check_checkresult_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checkresult_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checkresult_list_decode_malbinary((mc_check_checkresult_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checkresultfilter_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checkresultfilter_decode_malbinary((mc_check_checkresultfilter_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTFILTER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checkresultfilter_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checkresultfilter_list_decode_malbinary((mc_check_checkresultfilter_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checkresultsummary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checkresultsummary_decode_malbinary((mc_check_checkresultsummary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKRESULTSUMMARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checkresultsummary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checkresultsummary_list_decode_malbinary((mc_check_checkresultsummary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_check_checkstate_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSTATE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checkstate_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checkstate_list_decode_malbinary((mc_check_checkstate_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checktypedinstance_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checktypedinstance_decode_malbinary((mc_check_checktypedinstance_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKTYPEDINSTANCE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checktypedinstance_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checktypedinstance_list_decode_malbinary((mc_check_checktypedinstance_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_compoundcheckdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_compoundcheckdefinition_decode_malbinary((mc_check_compoundcheckdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_compoundcheckdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_compoundcheckdefinition_list_decode_malbinary((mc_check_compoundcheckdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_constantcheckdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_constantcheckdefinition_decode_malbinary((mc_check_constantcheckdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECKDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_constantcheckdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_constantcheckdefinition_list_decode_malbinary((mc_check_constantcheckdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_deltacheckdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_deltacheckdefinition_decode_malbinary((mc_check_deltacheckdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECKDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_deltacheckdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_deltacheckdefinition_list_decode_malbinary((mc_check_deltacheckdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_limitcheckdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_limitcheckdefinition_decode_malbinary((mc_check_limitcheckdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECKDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_limitcheckdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_limitcheckdefinition_list_decode_malbinary((mc_check_limitcheckdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_referencecheckdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_referencecheckdefinition_decode_malbinary((mc_check_referencecheckdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECKDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_referencecheckdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_referencecheckdefinition_list_decode_malbinary((mc_check_referencecheckdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_referencevalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_referencevalue_decode_malbinary((mc_check_referencevalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCEVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_referencevalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_referencevalue_list_decode_malbinary((mc_check_referencevalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conversion_discreteconversiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conversion_discreteconversiondetails_decode_malbinary((mc_conversion_discreteconversiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conversion_discreteconversiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conversion_discreteconversiondetails_list_decode_malbinary((mc_conversion_discreteconversiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conversion_lineconversiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conversion_lineconversiondetails_decode_malbinary((mc_conversion_lineconversiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_LINECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conversion_lineconversiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conversion_lineconversiondetails_list_decode_malbinary((mc_conversion_lineconversiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conversion_polyconversiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conversion_polyconversiondetails_decode_malbinary((mc_conversion_polyconversiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conversion_polyconversiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conversion_polyconversiondetails_list_decode_malbinary((mc_conversion_polyconversiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conversion_rangeconversiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conversion_rangeconversiondetails_decode_malbinary((mc_conversion_rangeconversiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conversion_rangeconversiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conversion_rangeconversiondetails_list_decode_malbinary((mc_conversion_rangeconversiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_group_groupdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_group_groupdetails_decode_malbinary((mc_group_groupdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_GROUP_GROUPDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_group_groupdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_group_groupdetails_list_decode_malbinary((mc_group_groupdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parameterconversion_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parameterconversion_decode_malbinary((mc_parameter_parameterconversion_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCONVERSION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parameterconversion_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parameterconversion_list_decode_malbinary((mc_parameter_parameterconversion_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parametercreationrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parametercreationrequest_decode_malbinary((mc_parameter_parametercreationrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parametercreationrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parametercreationrequest_list_decode_malbinary((mc_parameter_parametercreationrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parameterdefinitiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parameterdefinitiondetails_decode_malbinary((mc_parameter_parameterdefinitiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parameterdefinitiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parameterdefinitiondetails_list_decode_malbinary((mc_parameter_parameterdefinitiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parameterrawvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parameterrawvalue_decode_malbinary((mc_parameter_parameterrawvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERRAWVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parameterrawvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parameterrawvalue_list_decode_malbinary((mc_parameter_parameterrawvalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parametervalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parametervalue_decode_malbinary((mc_parameter_parametervalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parametervalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parametervalue_list_decode_malbinary((mc_parameter_parametervalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parametervaluedetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parametervaluedetails_decode_malbinary((mc_parameter_parametervaluedetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parametervaluedetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parametervaluedetails_list_decode_malbinary((mc_parameter_parametervaluedetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_parameter_validitystate_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITYSTATE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_validitystate_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_validitystate_list_decode_malbinary((mc_parameter_validitystate_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticcreationrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticcreationrequest_decode_malbinary((mc_statistic_statisticcreationrequest_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticcreationrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticcreationrequest_list_decode_malbinary((mc_statistic_statisticcreationrequest_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticevaluationreport_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticevaluationreport_decode_malbinary((mc_statistic_statisticevaluationreport_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticevaluationreport_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticevaluationreport_list_decode_malbinary((mc_statistic_statisticevaluationreport_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticfunctiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticfunctiondetails_decode_malbinary((mc_statistic_statisticfunctiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticfunctiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticfunctiondetails_list_decode_malbinary((mc_statistic_statisticfunctiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticlinkdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticlinkdetails_decode_malbinary((mc_statistic_statisticlinkdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticlinkdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticlinkdetails_list_decode_malbinary((mc_statistic_statisticlinkdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticlinksummary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticlinksummary_decode_malbinary((mc_statistic_statisticlinksummary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICLINKSUMMARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticlinksummary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticlinksummary_list_decode_malbinary((mc_statistic_statisticlinksummary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_statistic_statisticvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_statistic_statisticvalue_decode_malbinary((mc_statistic_statisticvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_STATISTIC_STATISTICVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_statistic_statisticvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_statistic_statisticvalue_list_decode_malbinary((mc_statistic_statisticvalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_argumentdefinitiondetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_argumentdefinitiondetails_decode_malbinary((mc_argumentdefinitiondetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_argumentdefinitiondetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_argumentdefinitiondetails_list_decode_malbinary((mc_argumentdefinitiondetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_attributevalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_attributevalue_decode_malbinary((mc_attributevalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ATTRIBUTEVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_attributevalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_attributevalue_list_decode_malbinary((mc_attributevalue_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conditionalconversion_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conditionalconversion_decode_malbinary((mc_conditionalconversion_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALCONVERSION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conditionalconversion_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conditionalconversion_list_decode_malbinary((mc_conditionalconversion_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_objectinstancepair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_objectinstancepair_decode_malbinary((mc_objectinstancepair_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_OBJECTINSTANCEPAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_objectinstancepair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_objectinstancepair_list_decode_malbinary((mc_objectinstancepair_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameterexpression_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameterexpression_decode_malbinary((mc_parameterexpression_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETEREXPRESSION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameterexpression_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameterexpression_list_decode_malbinary((mc_parameterexpression_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_SEVERITY_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_severity_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_SEVERITY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_severity_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_severity_list_decode_malbinary((mc_severity_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_actuatorstelemetry_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_actuatorstelemetry_decode_malbinary((pf_autonomousadcs_actuatorstelemetry_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_actuatorstelemetry_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_actuatorstelemetry_list_decode_malbinary((pf_autonomousadcs_actuatorstelemetry_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodebdot_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodebdot_decode_malbinary((pf_autonomousadcs_attitudemodebdot_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodebdot_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodebdot_list_decode_malbinary((pf_autonomousadcs_attitudemodebdot_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodenadirpointing_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodenadirpointing_decode_malbinary((pf_autonomousadcs_attitudemodenadirpointing_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodenadirpointing_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodenadirpointing_list_decode_malbinary((pf_autonomousadcs_attitudemodenadirpointing_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodesinglespinning_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodesinglespinning_decode_malbinary((pf_autonomousadcs_attitudemodesinglespinning_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodesinglespinning_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodesinglespinning_list_decode_malbinary((pf_autonomousadcs_attitudemodesinglespinning_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodesunpointing_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodesunpointing_decode_malbinary((pf_autonomousadcs_attitudemodesunpointing_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodesunpointing_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodesunpointing_list_decode_malbinary((pf_autonomousadcs_attitudemodesunpointing_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodetargettracking_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodetargettracking_decode_malbinary((pf_autonomousadcs_attitudemodetargettracking_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodetargettracking_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodetargettracking_list_decode_malbinary((pf_autonomousadcs_attitudemodetargettracking_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodetargettrackinglinear_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_decode_malbinary((pf_autonomousadcs_attitudemodetargettrackinglinear_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodetargettrackinglinear_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodetargettrackinglinear_list_decode_malbinary((pf_autonomousadcs_attitudemodetargettrackinglinear_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudemodevectorpointing_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodevectorpointing_decode_malbinary((pf_autonomousadcs_attitudemodevectorpointing_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudemodevectorpointing_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudemodevectorpointing_list_decode_malbinary((pf_autonomousadcs_attitudemodevectorpointing_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_attitudetelemetry_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudetelemetry_decode_malbinary((pf_autonomousadcs_attitudetelemetry_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_attitudetelemetry_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_attitudetelemetry_list_decode_malbinary((pf_autonomousadcs_attitudetelemetry_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (pf_autonomousadcs_magnetorquersstate_t) enumerated_value;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_magnetorquersstate_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_magnetorquersstate_list_decode_malbinary((pf_autonomousadcs_magnetorquersstate_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_quaternion_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_quaternion_decode_malbinary((pf_autonomousadcs_quaternion_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_QUATERNION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_quaternion_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_quaternion_list_decode_malbinary((pf_autonomousadcs_quaternion_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (pf_autonomousadcs_reactionwheelidentifier_t) enumerated_value;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_reactionwheelidentifier_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_reactionwheelidentifier_list_decode_malbinary((pf_autonomousadcs_reactionwheelidentifier_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_reactionwheelparameters_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_reactionwheelparameters_decode_malbinary((pf_autonomousadcs_reactionwheelparameters_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_reactionwheelparameters_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_reactionwheelparameters_list_decode_malbinary((pf_autonomousadcs_reactionwheelparameters_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_autonomousadcs_wheelsspeed_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_autonomousadcs_wheelsspeed_decode_malbinary((pf_autonomousadcs_wheelsspeed_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_autonomousadcs_wheelsspeed_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_autonomousadcs_wheelsspeed_list_decode_malbinary((pf_autonomousadcs_wheelsspeed_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_camera_camerasettings_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_camera_camerasettings_decode_malbinary((pf_camera_camerasettings_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_CAMERASETTINGS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_camera_camerasettings_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_camera_camerasettings_list_decode_malbinary((pf_camera_camerasettings_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_camera_picture_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_camera_picture_decode_malbinary((pf_camera_picture_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTURE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_camera_picture_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_camera_picture_list_decode_malbinary((pf_camera_picture_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (pf_camera_pictureformat_t) enumerated_value;
  }
  else if (element_holder->short_form == PF_CAMERA_PICTUREFORMAT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_camera_pictureformat_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_camera_pictureformat_list_decode_malbinary((pf_camera_pictureformat_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_camera_pixelresolution_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_camera_pixelresolution_decode_malbinary((pf_camera_pixelresolution_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_CAMERA_PIXELRESOLUTION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_camera_pixelresolution_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_camera_pixelresolution_list_decode_malbinary((pf_camera_pixelresolution_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_gps_nearbypositiondefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_gps_nearbypositiondefinition_decode_malbinary((pf_gps_nearbypositiondefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_NEARBYPOSITIONDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_gps_nearbypositiondefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_gps_nearbypositiondefinition_list_decode_malbinary((pf_gps_nearbypositiondefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_gps_position_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_gps_position_decode_malbinary((pf_gps_position_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_gps_position_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_gps_position_list_decode_malbinary((pf_gps_position_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_gps_positionextradetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_gps_positionextradetails_decode_malbinary((pf_gps_positionextradetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_POSITIONEXTRADETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_gps_positionextradetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_gps_positionextradetails_list_decode_malbinary((pf_gps_positionextradetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_gps_satelliteinfo_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_gps_satelliteinfo_decode_malbinary((pf_gps_satelliteinfo_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_SATELLITEINFO_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_gps_satelliteinfo_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_gps_satelliteinfo_list_decode_malbinary((pf_gps_satelliteinfo_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_gps_twolineelementset_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_gps_twolineelementset_decode_malbinary((pf_gps_twolineelementset_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_GPS_TWOLINEELEMENTSET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_gps_twolineelementset_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_gps_twolineelementset_list_decode_malbinary((pf_gps_twolineelementset_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_powercontrol_device_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_powercontrol_device_decode_malbinary((pf_powercontrol_device_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_powercontrol_device_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_powercontrol_device_list_decode_malbinary((pf_powercontrol_device_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (pf_powercontrol_devicetype_t) enumerated_value;
  }
  else if (element_holder->short_form == PF_POWERCONTROL_DEVICETYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_powercontrol_devicetype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_powercontrol_devicetype_list_decode_malbinary((pf_powercontrol_devicetype_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_softwaredefinedradio_iqcomponents_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_softwaredefinedradio_iqcomponents_decode_malbinary((pf_softwaredefinedradio_iqcomponents_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_softwaredefinedradio_iqcomponents_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_softwaredefinedradio_iqcomponents_list_decode_malbinary((pf_softwaredefinedradio_iqcomponents_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_softwaredefinedradio_sdrconfiguration_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_softwaredefinedradio_sdrconfiguration_decode_malbinary((pf_softwaredefinedradio_sdrconfiguration_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_softwaredefinedradio_sdrconfiguration_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_softwaredefinedradio_sdrconfiguration_list_decode_malbinary((pf_softwaredefinedradio_sdrconfiguration_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_vectord3d_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_vectord3d_decode_malbinary((pf_vectord3d_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORD3D_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_vectord3d_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_vectord3d_list_decode_malbinary((pf_vectord3d_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_SHORT_FORM)
  {
    element_holder->value.composite_value = pf_vectorf3d_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = pf_vectorf3d_decode_malbinary((pf_vectorf3d_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == PF_VECTORF3D_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = pf_vectorf3d_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = pf_vectorf3d_list_decode_malbinary((pf_vectorf3d_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = softwaremanagement_appslauncher_appdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = softwaremanagement_appslauncher_appdetails_decode_malbinary((softwaremanagement_appslauncher_appdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_APPSLAUNCHER_APPDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = softwaremanagement_appslauncher_appdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = softwaremanagement_appslauncher_appdetails_list_decode_malbinary((softwaremanagement_appslauncher_appdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = softwaremanagement_commandexecutor_commanddetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = softwaremanagement_commandexecutor_commanddetails_decode_malbinary((softwaremanagement_commandexecutor_commanddetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_COMMANDEXECUTOR_COMMANDDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = softwaremanagement_commandexecutor_commanddetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = softwaremanagement_commandexecutor_commanddetails_list_decode_malbinary((softwaremanagement_commandexecutor_commanddetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_SHORT_FORM)
  {
    element_holder->value.composite_value = softwaremanagement_packagemanagement_installationdetails_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = softwaremanagement_packagemanagement_installationdetails_decode_malbinary((softwaremanagement_packagemanagement_installationdetails_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_INSTALLATIONDETAILS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = softwaremanagement_packagemanagement_installationdetails_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = softwaremanagement_packagemanagement_installationdetails_list_decode_malbinary((softwaremanagement_packagemanagement_installationdetails_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = softwaremanagement_packagemanagement_packagedefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = softwaremanagement_packagemanagement_packagedefinition_decode_malbinary((softwaremanagement_packagemanagement_packagedefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == SOFTWAREMANAGEMENT_PACKAGEMANAGEMENT_PACKAGEDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = softwaremanagement_packagemanagement_packagedefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = softwaremanagement_packagemanagement_packagedefinition_list_decode_malbinary((softwaremanagement_packagemanagement_packagedefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

// test function
void softwaremanagement_test(bool verbose)
{
  printf(" * softwaremanagement: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
