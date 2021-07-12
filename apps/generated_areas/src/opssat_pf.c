#include "opssat_pf.h"

int OPSSAT_PF_ONBOARDDEVICE_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24
};

int OPSSAT_PF_DEVICES_NUMERIC_VALUES[] =
{
  1,
  2,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  12,
  13,
  15,
  16,
  17,
  19
};

int OPSSAT_PF_I2CBUS_NUMERIC_VALUES[] =
{
  0,
  1,
  2
};

// generated code for operation opssat_pf_busswitches_setaccessmask

int opssat_pf_busswitches_setaccessmask_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_BUSSWITCHES_SERVICE_NUMBER, OPSSAT_PF_BUSSWITCHES_SETACCESSMASK_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_busswitches_setaccessmask_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_busswitches_setaccessmask_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_busswitches_setaccessmask_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_busswitches_setaccessmask_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_1(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor)
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
        rc = opssat_pf_onboarddevice_list_add_encoding_length_malbinary(element, encoder, cursor);
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

int opssat_pf_busswitches_setaccessmask_submit_encode_1(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element)
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
        rc = opssat_pf_onboarddevice_list_encode_malbinary(element, encoder, cursor);
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

int opssat_pf_busswitches_setaccessmask_submit_decode_1(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res)
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
        *element_res = opssat_pf_onboarddevice_list_new(0);
        if (*element_res == NULL) return -1;
        rc = opssat_pf_onboarddevice_list_decode_malbinary(*element_res, decoder, cursor);
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

int opssat_pf_busswitches_setaccessmask_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_busswitches_setaccessmask_submit_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_2(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
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

int opssat_pf_busswitches_setaccessmask_submit_encode_2(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
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

int opssat_pf_busswitches_setaccessmask_submit_decode_2(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
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

int opssat_pf_busswitches_setaccessmask_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_busswitches_setaccessmask_submit_decode_2(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_0(encoder,true,arg0->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_2(encoder,arg2->value.list_value,cursor);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_add_encoding_length_2(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_0(cursor,encoder,true,arg0->value.ushort_value);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_2(cursor,encoder,arg2->value.list_value);
  } else {
    rc = opssat_pf_busswitches_setaccessmask_submit_encode_2(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_busswitches_setaccessmask_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_BUSSWITCHES_SERVICE_NUMBER, OPSSAT_PF_BUSSWITCHES_SETACCESSMASK_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_busswitches_setaccessmask_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_busswitches_setaccessmask_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
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

int opssat_pf_busswitches_setaccessmask_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
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

int opssat_pf_busswitches_setaccessmask_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_poweroffsbandtx

int opssat_pf_power_poweroffsbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWEROFFSBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_poweroffsbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweroffsbandtx_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_poweroffsbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWEROFFSBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweroffsbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweroffsbandtx_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweroffsbandtx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_poweronsbandtx

int opssat_pf_power_poweronsbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONSBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_poweronsbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronsbandtx_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_poweronsbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONSBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweronsbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronsbandtx_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweronsbandtx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_poweroffsbandrx

int opssat_pf_power_poweroffsbandrx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWEROFFSBANDRX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_poweroffsbandrx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweroffsbandrx_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_poweroffsbandrx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWEROFFSBANDRX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweroffsbandrx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweroffsbandrx_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweroffsbandrx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_poweronsbandrx

int opssat_pf_power_poweronsbandrx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONSBANDRX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_poweronsbandrx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronsbandrx_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_poweronsbandrx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONSBANDRX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweronsbandrx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronsbandrx_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweronsbandrx_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_poweronxbandtx

int opssat_pf_power_poweronxbandtx_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONXBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_poweronxbandtx_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronxbandtx_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_poweronxbandtx_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERONXBANDTX_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_poweronxbandtx_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_poweronxbandtx_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_power_setpowerstate

int opssat_pf_power_setpowerstate_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_SETPOWERSTATE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_setpowerstate_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor)
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
        rc = opssat_pf_onboarddevice_list_add_encoding_length_malbinary(element, encoder, cursor);
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

int opssat_pf_power_setpowerstate_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element)
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
        rc = opssat_pf_onboarddevice_list_encode_malbinary(element, encoder, cursor);
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

int opssat_pf_power_setpowerstate_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res)
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
        *element_res = opssat_pf_onboarddevice_list_new(0);
        if (*element_res == NULL) return -1;
        rc = opssat_pf_onboarddevice_list_decode_malbinary(*element_res, decoder, cursor);
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

int opssat_pf_power_setpowerstate_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_power_setpowerstate_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_power_setpowerstate_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor)
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

int opssat_pf_power_setpowerstate_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element)
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

int opssat_pf_power_setpowerstate_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res)
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

int opssat_pf_power_setpowerstate_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_power_setpowerstate_submit_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_power_setpowerstate_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_setpowerstate_submit_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = opssat_pf_power_setpowerstate_submit_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_setpowerstate_submit_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = opssat_pf_power_setpowerstate_submit_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_setpowerstate_submit_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = opssat_pf_power_setpowerstate_submit_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_setpowerstate_submit_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = opssat_pf_power_setpowerstate_submit_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_setpowerstate_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_setpowerstate_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_SETPOWERSTATE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_setpowerstate_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_setpowerstate_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_setpowerstate_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
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

int opssat_pf_power_setpowerstate_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
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

int opssat_pf_power_setpowerstate_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_powercycle

int opssat_pf_power_powercycle_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERCYCLE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_powercycle_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element, void * cursor)
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
        rc = opssat_pf_onboarddevice_list_add_encoding_length_malbinary(element, encoder, cursor);
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

int opssat_pf_power_powercycle_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_onboarddevice_list_t * element)
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
        rc = opssat_pf_onboarddevice_list_encode_malbinary(element, encoder, cursor);
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

int opssat_pf_power_powercycle_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_onboarddevice_list_t ** element_res)
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
        *element_res = opssat_pf_onboarddevice_list_new(0);
        if (*element_res == NULL) return -1;
        rc = opssat_pf_onboarddevice_list_decode_malbinary(*element_res, decoder, cursor);
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

int opssat_pf_power_powercycle_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_power_powercycle_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_power_powercycle_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_uoctet_list_t * element, void * cursor)
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
        rc = mal_uoctet_list_add_encoding_length_malbinary(element, encoder, cursor);
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

int opssat_pf_power_powercycle_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_uoctet_list_t * element)
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
        rc = mal_uoctet_list_encode_malbinary(element, encoder, cursor);
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

int opssat_pf_power_powercycle_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_uoctet_list_t ** element_res)
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
        *element_res = mal_uoctet_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_uoctet_list_decode_malbinary(*element_res, decoder, cursor);
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

int opssat_pf_power_powercycle_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_power_powercycle_submit_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_LIST_SHORT_FORM);
  return rc;
}

int opssat_pf_power_powercycle_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_powercycle_submit_add_encoding_length_0(encoder,arg0->value.list_value,cursor);
  } else {
    rc = opssat_pf_power_powercycle_submit_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_powercycle_submit_add_encoding_length_1(encoder,arg1->value.list_value,cursor);
  } else {
    rc = opssat_pf_power_powercycle_submit_add_encoding_length_1(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_powercycle_submit_encode_0(cursor,encoder,arg0->value.list_value);
  } else {
    rc = opssat_pf_power_powercycle_submit_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_powercycle_submit_encode_1(cursor,encoder,arg1->value.list_value);
  } else {
    rc = opssat_pf_power_powercycle_submit_encode_1(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_powercycle_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_powercycle_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_POWERCYCLE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_powercycle_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_powercycle_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_powercycle_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor)
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

int opssat_pf_power_powercycle_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element)
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

int opssat_pf_power_powercycle_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_devicepoweron

int opssat_pf_power_devicepoweron_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_DEVICEPOWERON_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_devicepoweron_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element, void * cursor)
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
        rc = mal_encoder_add_small_enum_encoding_length(encoder, element, cursor);
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

int opssat_pf_power_devicepoweron_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element)
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
        rc = mal_encoder_encode_small_enum(encoder, cursor, element);
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

int opssat_pf_power_devicepoweron_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_devices_t * element_res)
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
        int enumerated_value;
        rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
        if (rc < 0)
          return rc;
        *element_res = (opssat_pf_devices_t) enumerated_value;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int opssat_pf_power_devicepoweron_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_power_devicepoweron_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_DEVICES_SHORT_FORM);
  return rc;
}

int opssat_pf_power_devicepoweron_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_power_devicepoweron_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_power_devicepoweron_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_power_devicepoweron_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_power_devicepoweron_submit_decode_1(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_power_devicepoweron_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_devicepoweron_submit_add_encoding_length_0(encoder,true,arg0->value.enumerated_value,cursor);
  } else {
    rc = opssat_pf_power_devicepoweron_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_devicepoweron_submit_add_encoding_length_1(encoder,true,arg1->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_power_devicepoweron_submit_add_encoding_length_1(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_devicepoweron_submit_encode_0(cursor,encoder,true,arg0->value.enumerated_value);
  } else {
    rc = opssat_pf_power_devicepoweron_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_devicepoweron_submit_encode_1(cursor,encoder,true,arg1->value.ushort_value);
  } else {
    rc = opssat_pf_power_devicepoweron_submit_encode_1(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_devicepoweron_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_devicepoweron_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_DEVICEPOWERON_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_devicepoweron_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_devicepoweron_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_devicepoweron_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_power_devicepoweroff

int opssat_pf_power_devicepoweroff_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_DEVICEPOWEROFF_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element, void * cursor)
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
        rc = mal_encoder_add_small_enum_encoding_length(encoder, element, cursor);
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

int opssat_pf_power_devicepoweroff_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_devices_t element)
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
        rc = mal_encoder_encode_small_enum(encoder, cursor, element);
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

int opssat_pf_power_devicepoweroff_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_devices_t * element_res)
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
        int enumerated_value;
        rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
        if (rc < 0)
          return rc;
        *element_res = (opssat_pf_devices_t) enumerated_value;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_power_devicepoweroff_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_DEVICES_SHORT_FORM);
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_power_devicepoweroff_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_power_devicepoweroff_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_power_devicepoweroff_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_power_devicepoweroff_submit_decode_1(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_devicepoweroff_submit_add_encoding_length_0(encoder,true,arg0->value.enumerated_value,cursor);
  } else {
    rc = opssat_pf_power_devicepoweroff_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_devicepoweroff_submit_add_encoding_length_1(encoder,true,arg1->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_power_devicepoweroff_submit_add_encoding_length_1(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_power_devicepoweroff_submit_encode_0(cursor,encoder,true,arg0->value.enumerated_value);
  } else {
    rc = opssat_pf_power_devicepoweroff_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_power_devicepoweroff_submit_encode_1(cursor,encoder,true,arg1->value.ushort_value);
  } else {
    rc = opssat_pf_power_devicepoweroff_submit_encode_1(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_devicepoweroff_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_POWER_SERVICE_NUMBER, OPSSAT_PF_POWER_DEVICEPOWEROFF_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_devicepoweroff_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_power_devicepoweroff_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_power_devicepoweroff_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

int OPSSAT_PF_MODE_SYSTEMMODE_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8
};

// generated code for operation opssat_pf_mode_gotomode

int opssat_pf_mode_gotomode_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_MODE_SERVICE_NUMBER, OPSSAT_PF_MODE_GOTOMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SEND, MAL_IP_STAGE_SEND);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_mode_gotomode_send_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element, void * cursor)
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
        rc = mal_encoder_add_small_enum_encoding_length(encoder, element, cursor);
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

int opssat_pf_mode_gotomode_send_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_mode_systemmode_t element)
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
        rc = mal_encoder_encode_small_enum(encoder, cursor, element);
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

int opssat_pf_mode_gotomode_send_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_mode_systemmode_t * element_res)
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
        int enumerated_value;
        rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
        if (rc < 0)
          return rc;
        *element_res = (opssat_pf_mode_systemmode_t) enumerated_value;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int opssat_pf_mode_gotomode_send_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_mode_gotomode_send_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_MODE_SYSTEMMODE_SHORT_FORM);
  return rc;
}

int opssat_pf_mode_gotomode_send_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_mode_gotomode_send_add_encoding_length_0(encoder,true,arg0->value.enumerated_value,cursor);
  } else {
    rc = opssat_pf_mode_gotomode_send_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_mode_gotomode_send_encode_0(cursor,encoder,true,arg0->value.enumerated_value);
  } else {
    rc = opssat_pf_mode_gotomode_send_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_mode_gotomode_send(endpoint, message, provider_uri);
  return rc;
}

// generated code for operation opssat_pf_timemanagement_useautomatictime

int opssat_pf_timemanagement_useautomatictime_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_USEAUTOMATICTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_timemanagement_useautomatictime_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor)
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
        rc = mal_encoder_add_boolean_encoding_length(encoder, element, cursor);
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

int opssat_pf_timemanagement_useautomatictime_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element)
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
        rc = mal_encoder_encode_boolean(encoder, cursor, element);
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

int opssat_pf_timemanagement_useautomatictime_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res)
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
        rc = mal_decoder_decode_boolean(decoder, cursor, element_res);
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

int opssat_pf_timemanagement_useautomatictime_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_timemanagement_useautomatictime_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_SHORT_FORM);
  return rc;
}

int opssat_pf_timemanagement_useautomatictime_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_useautomatictime_submit_add_encoding_length_0(encoder,true,arg0->value.boolean_value,cursor);
  } else {
    rc = opssat_pf_timemanagement_useautomatictime_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_useautomatictime_submit_encode_0(cursor,encoder,true,arg0->value.boolean_value);
  } else {
    rc = opssat_pf_timemanagement_useautomatictime_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_useautomatictime_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_timemanagement_useautomatictime_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_USEAUTOMATICTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_useautomatictime_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_useautomatictime_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_timemanagement_gettimemode

int opssat_pf_timemanagement_gettimemode_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_GETTIMEMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_timemanagement_gettimemode_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_gettimemode_request(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_timemanagement_gettimemode_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_GETTIMEMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_gettimemode_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor)
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
        rc = mal_encoder_add_boolean_encoding_length(encoder, element, cursor);
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

int opssat_pf_timemanagement_gettimemode_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element)
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
        rc = mal_encoder_encode_boolean(encoder, cursor, element);
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

int opssat_pf_timemanagement_gettimemode_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res)
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
        rc = mal_decoder_decode_boolean(decoder, cursor, element_res);
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

int opssat_pf_timemanagement_gettimemode_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_timemanagement_gettimemode_request_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_SHORT_FORM);
  return rc;
}

int opssat_pf_timemanagement_gettimemode_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_gettimemode_request_response_add_encoding_length_0(encoder,true,arg0->value.boolean_value,cursor);
  } else {
    rc = opssat_pf_timemanagement_gettimemode_request_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_gettimemode_request_response_encode_0(cursor,encoder,true,arg0->value.boolean_value);
  } else {
    rc = opssat_pf_timemanagement_gettimemode_request_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_gettimemode_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_timemanagement_applymanualtimeshift

int opssat_pf_timemanagement_applymanualtimeshift_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_APPLYMANUALTIMESHIFT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_timemanagement_applymanualtimeshift_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor)
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

int opssat_pf_timemanagement_applymanualtimeshift_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element)
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

int opssat_pf_timemanagement_applymanualtimeshift_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res)
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

int opssat_pf_timemanagement_applymanualtimeshift_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_timemanagement_applymanualtimeshift_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_DURATION_SHORT_FORM);
  return rc;
}

int opssat_pf_timemanagement_applymanualtimeshift_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_applymanualtimeshift_submit_add_encoding_length_0(encoder,true,arg0->value.duration_value,cursor);
  } else {
    rc = opssat_pf_timemanagement_applymanualtimeshift_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_applymanualtimeshift_submit_encode_0(cursor,encoder,true,arg0->value.duration_value);
  } else {
    rc = opssat_pf_timemanagement_applymanualtimeshift_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_applymanualtimeshift_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_timemanagement_applymanualtimeshift_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_APPLYMANUALTIMESHIFT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_applymanualtimeshift_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_applymanualtimeshift_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_applymanualtimeshift_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_timemanagement_setmanualtime

int opssat_pf_timemanagement_setmanualtime_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_SETMANUALTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_timemanagement_setmanualtime_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor)
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
        rc = mal_encoder_add_time_encoding_length(encoder, element, cursor);
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

int opssat_pf_timemanagement_setmanualtime_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element)
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
        rc = mal_encoder_encode_time(encoder, cursor, element);
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

int opssat_pf_timemanagement_setmanualtime_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_time_t * element_res)
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
        rc = mal_decoder_decode_time(decoder, cursor, element_res);
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

int opssat_pf_timemanagement_setmanualtime_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_timemanagement_setmanualtime_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_TIME_SHORT_FORM);
  return rc;
}

int opssat_pf_timemanagement_setmanualtime_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_setmanualtime_submit_add_encoding_length_0(encoder,true,arg0->value.time_value,cursor);
  } else {
    rc = opssat_pf_timemanagement_setmanualtime_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_setmanualtime_submit_encode_0(cursor,encoder,true,arg0->value.time_value);
  } else {
    rc = opssat_pf_timemanagement_setmanualtime_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_setmanualtime_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_timemanagement_setmanualtime_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_SETMANUALTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_setmanualtime_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_setmanualtime_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_setmanualtime_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_timemanagement_getcurrenttime

int opssat_pf_timemanagement_getcurrenttime_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_GETCURRENTTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_timemanagement_getcurrenttime_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_getcurrenttime_request(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_timemanagement_getcurrenttime_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_TIMEMANAGEMENT_SERVICE_NUMBER, OPSSAT_PF_TIMEMANAGEMENT_GETCURRENTTIME_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_timemanagement_getcurrenttime_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_time_t element, void * cursor)
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
        rc = mal_encoder_add_time_encoding_length(encoder, element, cursor);
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

int opssat_pf_timemanagement_getcurrenttime_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_time_t element)
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
        rc = mal_encoder_encode_time(encoder, cursor, element);
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

int opssat_pf_timemanagement_getcurrenttime_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_time_t * element_res)
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
        rc = mal_decoder_decode_time(decoder, cursor, element_res);
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

int opssat_pf_timemanagement_getcurrenttime_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_timemanagement_getcurrenttime_request_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_TIME_SHORT_FORM);
  return rc;
}

int opssat_pf_timemanagement_getcurrenttime_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_getcurrenttime_request_response_add_encoding_length_0(encoder,true,arg0->value.time_value,cursor);
  } else {
    rc = opssat_pf_timemanagement_getcurrenttime_request_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_timemanagement_getcurrenttime_request_response_encode_0(cursor,encoder,true,arg0->value.time_value);
  } else {
    rc = opssat_pf_timemanagement_getcurrenttime_request_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_timemanagement_getcurrenttime_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_experimentwd_alive

int opssat_pf_experimentwd_alive_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_EXPERIMENTWD_SERVICE_NUMBER, OPSSAT_PF_EXPERIMENTWD_ALIVE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SEND, MAL_IP_STAGE_SEND);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_experimentwd_alive_send_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_experimentwd_alive_send(endpoint, message, provider_uri);
  return rc;
}

// generated code for operation opssat_pf_gps_getgpsdata

int opssat_pf_gps_getgpsdata_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_GPS_SERVICE_NUMBER, OPSSAT_PF_GPS_GETGPSDATA_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_gps_getgpsdata_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_gps_getgpsdata_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_gps_getgpsdata_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_gps_getgpsdata_invoke_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_gps_getgpsdata_invoke_add_encoding_length_0(encoder,arg0->value.blob_value,cursor);
  } else {
    rc = opssat_pf_gps_getgpsdata_invoke_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_gps_getgpsdata_invoke_encode_0(cursor,encoder,arg0->value.blob_value);
  } else {
    rc = opssat_pf_gps_getgpsdata_invoke_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_gps_getgpsdata_invoke(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_GPS_SERVICE_NUMBER, OPSSAT_PF_GPS_GETGPSDATA_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_gps_getgpsdata_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_GPS_SERVICE_NUMBER, OPSSAT_PF_GPS_GETGPSDATA_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_gps_getgpsdata_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_gps_getgpsdata_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_gps_getgpsdata_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_gps_getgpsdata_invoke_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_gps_getgpsdata_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_gps_getgpsdata_invoke_response_add_encoding_length_0(encoder,arg0->value.blob_value,cursor);
  } else {
    rc = opssat_pf_gps_getgpsdata_invoke_response_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_gps_getgpsdata_invoke_response_encode_0(cursor,encoder,arg0->value.blob_value);
  } else {
    rc = opssat_pf_gps_getgpsdata_invoke_response_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_gps_getgpsdata_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_gps_getgpsdata_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

int OPSSAT_PF_COARSEADCS_ADCSMODE_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4
};

// generated code for operation opssat_pf_coarseadcs_setadcsmode

int opssat_pf_coarseadcs_setadcsmode_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_SETADCSMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element, void * cursor)
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
        rc = mal_encoder_add_small_enum_encoding_length(encoder, element, cursor);
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

int opssat_pf_coarseadcs_setadcsmode_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_coarseadcs_adcsmode_t element)
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
        rc = mal_encoder_encode_small_enum(encoder, cursor, element);
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

int opssat_pf_coarseadcs_setadcsmode_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_coarseadcs_adcsmode_t * element_res)
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
        int enumerated_value;
        rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
        if (rc < 0)
          return rc;
        *element_res = (opssat_pf_coarseadcs_adcsmode_t) enumerated_value;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_coarseadcs_setadcsmode_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_COARSEADCS_ADCSMODE_SHORT_FORM);
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_setadcsmode_submit_add_encoding_length_0(encoder,true,arg0->value.enumerated_value,cursor);
  } else {
    rc = opssat_pf_coarseadcs_setadcsmode_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_setadcsmode_submit_encode_0(cursor,encoder,true,arg0->value.enumerated_value);
  } else {
    rc = opssat_pf_coarseadcs_setadcsmode_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_setadcsmode_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_SETADCSMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_setadcsmode_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_setadcsmode_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_coarseadcs_setnavtransmode

int opssat_pf_coarseadcs_setnavtransmode_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_SETNAVTRANSMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_coarseadcs_setnavtransmode_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor)
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
        rc = mal_encoder_add_boolean_encoding_length(encoder, element, cursor);
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

int opssat_pf_coarseadcs_setnavtransmode_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element)
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
        rc = mal_encoder_encode_boolean(encoder, cursor, element);
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

int opssat_pf_coarseadcs_setnavtransmode_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res)
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
        rc = mal_decoder_decode_boolean(decoder, cursor, element_res);
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

int opssat_pf_coarseadcs_setnavtransmode_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_coarseadcs_setnavtransmode_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_SHORT_FORM);
  return rc;
}

int opssat_pf_coarseadcs_setnavtransmode_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_setnavtransmode_submit_add_encoding_length_0(encoder,true,arg0->value.boolean_value,cursor);
  } else {
    rc = opssat_pf_coarseadcs_setnavtransmode_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_setnavtransmode_submit_encode_0(cursor,encoder,true,arg0->value.boolean_value);
  } else {
    rc = opssat_pf_coarseadcs_setnavtransmode_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_setnavtransmode_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_coarseadcs_setnavtransmode_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_SETNAVTRANSMODE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_setnavtransmode_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_setnavtransmode_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_coarseadcs_uploadorbittle

int opssat_pf_coarseadcs_uploadorbittle_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_UPLOADORBITTLE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_coarseadcs_uploadorbittle_submit_add_encoding_length_0(mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element, void * cursor)
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
        rc = opssat_pf_coarseadcs_orbittledata_add_encoding_length_malbinary(element, encoder, cursor);
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

int opssat_pf_coarseadcs_uploadorbittle_submit_encode_0(void * cursor, mal_encoder_t * encoder, opssat_pf_coarseadcs_orbittledata_t * element)
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
        rc = opssat_pf_coarseadcs_orbittledata_encode_malbinary(element, encoder, cursor);
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

int opssat_pf_coarseadcs_uploadorbittle_submit_decode_0(void * cursor, mal_decoder_t * decoder, opssat_pf_coarseadcs_orbittledata_t ** element_res)
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
        *element_res = opssat_pf_coarseadcs_orbittledata_new();
        if (*element_res == NULL) return -1;
        rc = opssat_pf_coarseadcs_orbittledata_decode_malbinary(*element_res, decoder, cursor);
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

int opssat_pf_coarseadcs_uploadorbittle_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_coarseadcs_uploadorbittle_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_COARSEADCS_ORBITTLEDATA_SHORT_FORM);
  return rc;
}

int opssat_pf_coarseadcs_uploadorbittle_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_uploadorbittle_submit_add_encoding_length_0(encoder,arg0->value.composite_value,cursor);
  } else {
    rc = opssat_pf_coarseadcs_uploadorbittle_submit_add_encoding_length_0(encoder,NULL,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_coarseadcs_uploadorbittle_submit_encode_0(cursor,encoder,arg0->value.composite_value);
  } else {
    rc = opssat_pf_coarseadcs_uploadorbittle_submit_encode_0(cursor,encoder,NULL);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_uploadorbittle_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_coarseadcs_uploadorbittle_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_UPLOADORBITTLE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_uploadorbittle_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_uploadorbittle_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_uploadorbittle_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_coarseadcs_resetadcs

int opssat_pf_coarseadcs_resetadcs_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_RESETADCS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_coarseadcs_resetadcs_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_resetadcs_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_coarseadcs_resetadcs_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_RESETADCS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_resetadcs_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_resetadcs_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_coarseadcs_loadadcsparams

int opssat_pf_coarseadcs_loadadcsparams_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_LOADADCSPARAMS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_coarseadcs_loadadcsparams_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_loadadcsparams_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_coarseadcs_loadadcsparams_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_COARSEADCS_SERVICE_NUMBER, OPSSAT_PF_COARSEADCS_LOADADCSPARAMS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_coarseadcs_loadadcsparams_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_coarseadcs_loadadcsparams_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_performhealthcheck

int opssat_pf_advancedobc_performhealthcheck_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_PERFORMHEALTHCHECK_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_integer_t element, void * cursor)
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
        rc = mal_encoder_add_integer_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_performhealthcheck_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_integer_t element)
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
        rc = mal_encoder_encode_integer(encoder, cursor, element);
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

int opssat_pf_advancedobc_performhealthcheck_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_integer_t * element_res)
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
        rc = mal_decoder_decode_integer(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_performhealthcheck_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_performhealthcheck_request_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_INTEGER_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_performhealthcheck_request_add_encoding_length_0(encoder,true,arg0->value.integer_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_performhealthcheck_request_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_performhealthcheck_request_encode_0(cursor,encoder,true,arg0->value.integer_value);
  } else {
    rc = opssat_pf_advancedobc_performhealthcheck_request_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_performhealthcheck_request(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_PERFORMHEALTHCHECK_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_performhealthcheck_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_performhealthcheck_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_performhealthcheck_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_performhealthcheck_request_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_performhealthcheck_request_response_add_encoding_length_0(encoder,arg0->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_performhealthcheck_request_response_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_performhealthcheck_request_response_encode_0(cursor,encoder,arg0->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_performhealthcheck_request_response_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_performhealthcheck_request_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_performhealthcheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_advancedobc_resetnanomindwdg

int opssat_pf_advancedobc_resetnanomindwdg_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETNANOMINDWDG_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_resetnanomindwdg_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetnanomindwdg_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_resetnanomindwdg_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETNANOMINDWDG_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_resetnanomindwdg_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetnanomindwdg_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_resetobsw

int opssat_pf_advancedobc_resetobsw_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETOBSW_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_resetobsw_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetobsw_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_resetobsw_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETOBSW_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_resetobsw_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetobsw_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_readi2cpayload

int opssat_pf_advancedobc_readi2cpayload_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_decode_2(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_decode_3(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_1(encoder,arg1->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_1(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_2(encoder,true,arg2->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_2(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg3
  if (arg3 != NULL && arg3->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_3(encoder,true,arg3->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_add_encoding_length_3(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_1(cursor,encoder,arg1->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_1(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_2(cursor,encoder,true,arg2->value.ushort_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_2(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg3
  if (arg3 != NULL && arg3->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_3(cursor,encoder,true,arg3->value.ushort_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_encode_3(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cpayload_invoke(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cpayload_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_response_add_encoding_length_0(encoder,arg0->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_response_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_response_encode_0(cursor,encoder,arg0->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cpayload_invoke_response_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cpayload_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cpayload_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_advancedobc_writei2cpayload

int opssat_pf_advancedobc_writei2cpayload_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_writei2cpayload_invoke_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_writei2cpayload_invoke_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_1(encoder,arg1->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_add_encoding_length_1(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_encode_1(cursor,encoder,arg1->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_encode_1(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cpayload_invoke(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cpayload_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CPAYLOAD_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cpayload_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_writei2cpayload_invoke_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_response_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_response_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cpayload_invoke_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cpayload_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cpayload_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_advancedobc_resetepswatchdog

int opssat_pf_advancedobc_resetepswatchdog_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETEPSWATCHDOG_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_resetepswatchdog_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetepswatchdog_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_resetepswatchdog_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETEPSWATCHDOG_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_resetepswatchdog_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_resetepswatchdog_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_enablecriticalcommands

int opssat_pf_advancedobc_enablecriticalcommands_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_ENABLECRITICALCOMMANDS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_enablecriticalcommands_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor)
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
        rc = mal_encoder_add_boolean_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_enablecriticalcommands_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element)
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
        rc = mal_encoder_encode_boolean(encoder, cursor, element);
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

int opssat_pf_advancedobc_enablecriticalcommands_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res)
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
        rc = mal_decoder_decode_boolean(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_enablecriticalcommands_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_enablecriticalcommands_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BOOLEAN_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_enablecriticalcommands_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_enablecriticalcommands_submit_add_encoding_length_0(encoder,true,arg0->value.boolean_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_enablecriticalcommands_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_enablecriticalcommands_submit_encode_0(cursor,encoder,true,arg0->value.boolean_value);
  } else {
    rc = opssat_pf_advancedobc_enablecriticalcommands_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_enablecriticalcommands_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_enablecriticalcommands_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_ENABLECRITICALCOMMANDS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_enablecriticalcommands_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_enablecriticalcommands_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_setbootimage

int opssat_pf_advancedobc_setbootimage_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_SETBOOTIMAGE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor)
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
        rc = mal_encoder_add_string_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_setbootimage_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element)
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
        rc = mal_encoder_encode_string(encoder, cursor, element);
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

int opssat_pf_advancedobc_setbootimage_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res)
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
        rc = mal_decoder_decode_string(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_setbootimage_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_setbootimage_submit_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_STRING_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor)
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
        rc = mal_encoder_add_uinteger_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_setbootimage_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element)
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
        rc = mal_encoder_encode_uinteger(encoder, cursor, element);
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

int opssat_pf_advancedobc_setbootimage_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uinteger_t * element_res)
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
        rc = mal_decoder_decode_uinteger(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_setbootimage_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_setbootimage_submit_decode_1(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UINTEGER_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_setbootimage_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_0(encoder,arg0->value.string_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_1(encoder,true,arg1->value.uinteger_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_setbootimage_submit_add_encoding_length_1(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_setbootimage_submit_encode_0(cursor,encoder,arg0->value.string_value);
  } else {
    rc = opssat_pf_advancedobc_setbootimage_submit_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_setbootimage_submit_encode_1(cursor,encoder,true,arg1->value.uinteger_value);
  } else {
    rc = opssat_pf_advancedobc_setbootimage_submit_encode_1(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_setbootimage_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_setbootimage_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_SETBOOTIMAGE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_setbootimage_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_setbootimage_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

// generated code for operation opssat_pf_advancedobc_readi2cbus

int opssat_pf_advancedobc_readi2cbus_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cbus_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_readi2cbus_invoke_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cbus_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_readi2cbus_invoke_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element, void * cursor)
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
        rc = mal_encoder_add_ushort_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cbus_invoke_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_ushort_t element)
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
        rc = mal_encoder_encode_ushort(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_ushort_t * element_res)
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
        rc = mal_decoder_decode_ushort(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cbus_invoke_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_readi2cbus_invoke_decode_2(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_USHORT_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_1(encoder,arg1->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_1(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_2(encoder,true,arg2->value.ushort_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_add_encoding_length_2(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_1(cursor,encoder,arg1->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_1(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg2
  if (arg2 != NULL && arg2->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_2(cursor,encoder,true,arg2->value.ushort_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_encode_2(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cbus_invoke(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cbus_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_READI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_readi2cbus_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_readi2cbus_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_readi2cbus_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_readi2cbus_invoke_response_decode_0(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_response_add_encoding_length_0(encoder,arg0->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_response_add_encoding_length_0(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_response_encode_0(cursor,encoder,arg0->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_readi2cbus_invoke_response_encode_0(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_readi2cbus_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_readi2cbus_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_advancedobc_writei2cbus

int opssat_pf_advancedobc_writei2cbus_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cbus_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cbus_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cbus_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_writei2cbus_invoke_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_1(mal_encoder_t * encoder, mal_blob_t * element, void * cursor)
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
        rc = mal_encoder_add_blob_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cbus_invoke_encode_1(void * cursor, mal_encoder_t * encoder, mal_blob_t * element)
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
        rc = mal_encoder_encode_blob(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cbus_invoke_decode_1(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res)
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
        rc = mal_decoder_decode_blob(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cbus_invoke_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  rc = opssat_pf_advancedobc_writei2cbus_invoke_decode_1(cursor, decoder, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, ((void*)value.composite_value != NULL));
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_BLOB_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  // Length of arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_1(encoder,arg1->value.blob_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_add_encoding_length_1(encoder,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Encoding arg1
  if (arg1 != NULL && arg1->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_encode_1(cursor,encoder,arg1->value.blob_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_encode_1(cursor,encoder,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cbus_invoke(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cbus_invoke_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_WRITEI2CBUS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element, void * cursor)
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
        rc = mal_encoder_add_uoctet_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_writei2cbus_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uoctet_t element)
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
        rc = mal_encoder_encode_uoctet(encoder, cursor, element);
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

int opssat_pf_advancedobc_writei2cbus_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_uoctet_t * element_res)
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
        rc = mal_decoder_decode_uoctet(decoder, cursor, element_res);
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

int opssat_pf_advancedobc_writei2cbus_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_writei2cbus_invoke_response_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, MAL_UOCTET_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_response_add_encoding_length_0(encoder,true,arg0->value.uoctet_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_response_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_response_encode_0(cursor,encoder,true,arg0->value.uoctet_value);
  } else {
    rc = opssat_pf_advancedobc_writei2cbus_invoke_response_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_writei2cbus_invoke_response(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_writei2cbus_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
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
        rc = opssat_pf_malbinary_decode_mal_element(decoder, cursor, element_holder);
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

// generated code for operation opssat_pf_advancedobc_reseti2ccontroller

int opssat_pf_advancedobc_reseti2ccontroller_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETI2CCONTROLLER_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int opssat_pf_advancedobc_reseti2ccontroller_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element, void * cursor)
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
        rc = mal_encoder_add_small_enum_encoding_length(encoder, element, cursor);
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

int opssat_pf_advancedobc_reseti2ccontroller_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, opssat_pf_i2cbus_t element)
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
        rc = mal_encoder_encode_small_enum(encoder, cursor, element);
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

int opssat_pf_advancedobc_reseti2ccontroller_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, opssat_pf_i2cbus_t * element_res)
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
        int enumerated_value;
        rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
        if (rc < 0)
          return rc;
        *element_res = (opssat_pf_i2cbus_t) enumerated_value;
        (*presence_flag_res) = presence_flag;
      }
      break;
    }
    default:
    rc = -1;
  }
  return rc;
}

int opssat_pf_advancedobc_reseti2ccontroller_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  union mal_element_t value;
  bool presence_flag;
  rc = opssat_pf_advancedobc_reseti2ccontroller_submit_decode_0(cursor, decoder, &presence_flag, (void*)&value.composite_value);
  mal_element_holder_set_presence_flag(element_holder, presence_flag);
  mal_element_holder_set_value(element_holder, value);
  mal_element_holder_set_short_form(element_holder, OPSSAT_PF_I2CBUS_SHORT_FORM);
  return rc;
}

int opssat_pf_advancedobc_reseti2ccontroller_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  // Length of arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_reseti2ccontroller_submit_add_encoding_length_0(encoder,true,arg0->value.enumerated_value,cursor);
  } else {
    rc = opssat_pf_advancedobc_reseti2ccontroller_submit_add_encoding_length_0(encoder,false,0,cursor);
  }
  if (rc < 0)
    return rc;
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Encoding arg0
  if (arg0 != NULL && arg0->presence_flag) {
    rc = opssat_pf_advancedobc_reseti2ccontroller_submit_encode_0(cursor,encoder,true,arg0->value.enumerated_value);
  } else {
    rc = opssat_pf_advancedobc_reseti2ccontroller_submit_encode_0(cursor,encoder,false,0);
  }
  if (rc < 0)
    return rc;
  mal_encoder_cursor_assert(encoder, cursor);
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_reseti2ccontroller_submit(endpoint, message, provider_uri);
  return rc;
}

int opssat_pf_advancedobc_reseti2ccontroller_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, OPSSAT_PF_AREA_NUMBER, OPSSAT_PF_AREA_VERSION, OPSSAT_PF_ADVANCEDOBC_SERVICE_NUMBER, OPSSAT_PF_ADVANCEDOBC_RESETI2CCONTROLLER_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int opssat_pf_advancedobc_reseti2ccontroller_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name)
{
  int rc = 0;
  void *cursor = mal_encoder_new_cursor(encoder);
  // Length
  mal_message_t *message = mal_message_new(authentication_id, qoslevel, priority, domain, network_zone, session, session_name, mal_encoder_cursor_get_length(encoder, cursor));
  mal_encoder_cursor_init(encoder, cursor, mal_message_get_body(message), mal_encoder_cursor_get_length(encoder, cursor), mal_message_get_body_offset(message));
  // Encoding
  // Clean
  mal_encoder_cursor_destroy(encoder, cursor);
  rc = opssat_pf_advancedobc_reseti2ccontroller_submit_ack(endpoint, message, result_message, is_error_message);
  return rc;
}

int opssat_pf_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor)
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
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationreference_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationreference_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_SHORT_FORM)
  {
    rc = mc_alert_alertdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_SHORT_FORM)
  {
    rc = mc_alert_alertevent_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertevent_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_SHORT_FORM)
  {
    rc = mc_check_checklink_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_LIST_SHORT_FORM)
  {
    rc = mc_check_checklink_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checksummary_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checksummary_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_SHORT_FORM)
  {
    rc = mc_check_constantcheck_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_constantcheck_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_SHORT_FORM)
  {
    rc = mc_check_deltacheck_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_deltacheck_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_SHORT_FORM)
  {
    rc = mc_check_limitcheck_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_limitcheck_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_SHORT_FORM)
  {
    rc = mc_check_referencecheck_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_referencecheck_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_LIST_SHORT_FORM)
  {
    rc = mc_parameter_validity_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_SHORT_FORM)
  {
    rc = mc_argumentdefinition_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_argumentdefinition_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_SHORT_FORM)
  {
    rc = mc_argumentvalue_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_LIST_SHORT_FORM)
  {
    rc = mc_argumentvalue_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_SHORT_FORM)
  {
    rc = mc_conditionalreference_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_LIST_SHORT_FORM)
  {
    rc = mc_conditionalreference_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_adcsmode_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_orbittledata_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_orbittledata_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_mode_systemmode_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_LIST_SHORT_FORM)
  {
    rc = opssat_pf_devices_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_LIST_SHORT_FORM)
  {
    rc = opssat_pf_i2cbus_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_onboarddevice_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_SHORT_FORM)
  {
    rc = opssat_std_filemanagement_fileaccessmode_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryblock_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryblock_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memorydevice_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryrange_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryrange_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_listscheduleentry_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_listscheduleentry_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_SHORT_FORM)
  {
    rc = mal_encoder_add_small_enum_encoding_length(encoder, element_holder->value.enumerated_value, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_schedule_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_scheduleentry_add_encoding_length_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_scheduleentry_list_add_encoding_length_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

int opssat_pf_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder)
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
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationreference_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_SHORT_FORM)
  {
    rc = mc_aggregation_aggregationreference_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_SHORT_FORM)
  {
    rc = mc_alert_alertdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_SHORT_FORM)
  {
    rc = mc_alert_alertevent_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_LIST_SHORT_FORM)
  {
    rc = mc_alert_alertevent_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_SHORT_FORM)
  {
    rc = mc_check_checklink_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_LIST_SHORT_FORM)
  {
    rc = mc_check_checklink_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_SHORT_FORM)
  {
    rc = mc_check_checksummary_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_LIST_SHORT_FORM)
  {
    rc = mc_check_checksummary_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_SHORT_FORM)
  {
    rc = mc_check_constantcheck_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_constantcheck_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_SHORT_FORM)
  {
    rc = mc_check_deltacheck_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_deltacheck_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_SHORT_FORM)
  {
    rc = mc_check_limitcheck_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_limitcheck_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_SHORT_FORM)
  {
    rc = mc_check_referencecheck_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_LIST_SHORT_FORM)
  {
    rc = mc_check_referencecheck_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_parameter_parameterdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_LIST_SHORT_FORM)
  {
    rc = mc_parameter_validity_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_SHORT_FORM)
  {
    rc = mc_argumentdefinition_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_LIST_SHORT_FORM)
  {
    rc = mc_argumentdefinition_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_SHORT_FORM)
  {
    rc = mc_argumentvalue_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_LIST_SHORT_FORM)
  {
    rc = mc_argumentvalue_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_SHORT_FORM)
  {
    rc = mc_conditionalreference_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_LIST_SHORT_FORM)
  {
    rc = mc_conditionalreference_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
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
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_adcsmode_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_orbittledata_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_SHORT_FORM)
  {
    rc = opssat_pf_coarseadcs_orbittledata_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_mode_systemmode_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_LIST_SHORT_FORM)
  {
    rc = opssat_pf_devices_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_LIST_SHORT_FORM)
  {
    rc = opssat_pf_i2cbus_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM)
  {
    rc = opssat_pf_onboarddevice_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_SHORT_FORM)
  {
    rc = opssat_std_filemanagement_fileaccessmode_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryblock_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryblock_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memorydevice_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryrange_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_SHORT_FORM)
  {
    rc = opssat_std_memorymanagement_memoryrange_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_listscheduleentry_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_listscheduleentry_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_SHORT_FORM)
  {
    rc = mal_encoder_encode_small_enum(encoder, cursor, element_holder->value.enumerated_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_schedule_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_scheduleentry_encode_malbinary(element_holder->value.composite_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_SHORT_FORM)
  {
    rc = opssat_std_schedulemanagement_scheduleentry_list_encode_malbinary(element_holder->value.list_value, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

int opssat_pf_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder)
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
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationdefinition_decode_malbinary((mc_aggregation_aggregationdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationdefinition_list_decode_malbinary((mc_aggregation_aggregationdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_aggregation_aggregationreference_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_aggregation_aggregationreference_decode_malbinary((mc_aggregation_aggregationreference_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_aggregation_aggregationreference_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_aggregation_aggregationreference_list_decode_malbinary((mc_aggregation_aggregationreference_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_alert_alertdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_alert_alertdefinition_decode_malbinary((mc_alert_alertdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_alert_alertdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_alert_alertdefinition_list_decode_malbinary((mc_alert_alertdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_alert_alertevent_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_alert_alertevent_decode_malbinary((mc_alert_alertevent_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ALERT_ALERTEVENT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_alert_alertevent_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_alert_alertevent_list_decode_malbinary((mc_alert_alertevent_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checklink_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checklink_decode_malbinary((mc_check_checklink_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKLINK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checklink_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checklink_list_decode_malbinary((mc_check_checklink_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_checksummary_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_checksummary_decode_malbinary((mc_check_checksummary_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CHECKSUMMARY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_checksummary_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_checksummary_list_decode_malbinary((mc_check_checksummary_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_constantcheck_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_constantcheck_decode_malbinary((mc_check_constantcheck_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_CONSTANTCHECK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_constantcheck_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_constantcheck_list_decode_malbinary((mc_check_constantcheck_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_deltacheck_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_deltacheck_decode_malbinary((mc_check_deltacheck_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_DELTACHECK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_deltacheck_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_deltacheck_list_decode_malbinary((mc_check_deltacheck_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_limitcheck_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_limitcheck_decode_malbinary((mc_check_limitcheck_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_LIMITCHECK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_limitcheck_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_limitcheck_list_decode_malbinary((mc_check_limitcheck_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_check_referencecheck_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_check_referencecheck_decode_malbinary((mc_check_referencecheck_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CHECK_REFERENCECHECK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_check_referencecheck_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_check_referencecheck_list_decode_malbinary((mc_check_referencecheck_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_parameter_parameterdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_parameter_parameterdefinition_decode_malbinary((mc_parameter_parameterdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_PARAMETER_PARAMETERDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_parameterdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_parameterdefinition_list_decode_malbinary((mc_parameter_parameterdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mc_parameter_validity_t) enumerated_value;
  }
  else if (element_holder->short_form == MC_PARAMETER_VALIDITY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_parameter_validity_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_parameter_validity_list_decode_malbinary((mc_parameter_validity_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_argumentdefinition_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_argumentdefinition_decode_malbinary((mc_argumentdefinition_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTDEFINITION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_argumentdefinition_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_argumentdefinition_list_decode_malbinary((mc_argumentdefinition_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_argumentvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_argumentvalue_decode_malbinary((mc_argumentvalue_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_ARGUMENTVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_argumentvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_argumentvalue_list_decode_malbinary((mc_argumentvalue_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_SHORT_FORM)
  {
    element_holder->value.composite_value = mc_conditionalreference_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mc_conditionalreference_decode_malbinary((mc_conditionalreference_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MC_CONDITIONALREFERENCE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mc_conditionalreference_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mc_conditionalreference_list_decode_malbinary((mc_conditionalreference_list_t *)element_holder->value.list_value, decoder, cursor);
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
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_pf_coarseadcs_adcsmode_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ADCSMODE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_coarseadcs_adcsmode_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_coarseadcs_adcsmode_list_decode_malbinary((opssat_pf_coarseadcs_adcsmode_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_SHORT_FORM)
  {
    element_holder->value.composite_value = opssat_pf_coarseadcs_orbittledata_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = opssat_pf_coarseadcs_orbittledata_decode_malbinary((opssat_pf_coarseadcs_orbittledata_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_COARSEADCS_ORBITTLEDATA_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_coarseadcs_orbittledata_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_coarseadcs_orbittledata_list_decode_malbinary((opssat_pf_coarseadcs_orbittledata_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_pf_mode_systemmode_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_PF_MODE_SYSTEMMODE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_mode_systemmode_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_mode_systemmode_list_decode_malbinary((opssat_pf_mode_systemmode_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_pf_devices_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_PF_DEVICES_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_devices_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_devices_list_decode_malbinary((opssat_pf_devices_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_pf_i2cbus_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_PF_I2CBUS_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_i2cbus_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_i2cbus_list_decode_malbinary((opssat_pf_i2cbus_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_pf_onboarddevice_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_PF_ONBOARDDEVICE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_pf_onboarddevice_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_pf_onboarddevice_list_decode_malbinary((opssat_pf_onboarddevice_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_std_filemanagement_fileaccessmode_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_STD_FILEMANAGEMENT_FILEACCESSMODE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_filemanagement_fileaccessmode_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_filemanagement_fileaccessmode_list_decode_malbinary((opssat_std_filemanagement_fileaccessmode_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_SHORT_FORM)
  {
    element_holder->value.composite_value = opssat_std_memorymanagement_memoryblock_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = opssat_std_memorymanagement_memoryblock_decode_malbinary((opssat_std_memorymanagement_memoryblock_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYBLOCK_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_memorymanagement_memoryblock_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_memorymanagement_memoryblock_list_decode_malbinary((opssat_std_memorymanagement_memoryblock_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_std_memorymanagement_memorydevice_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYDEVICE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_memorymanagement_memorydevice_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_memorymanagement_memorydevice_list_decode_malbinary((opssat_std_memorymanagement_memorydevice_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_SHORT_FORM)
  {
    element_holder->value.composite_value = opssat_std_memorymanagement_memoryrange_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = opssat_std_memorymanagement_memoryrange_decode_malbinary((opssat_std_memorymanagement_memoryrange_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_MEMORYMANAGEMENT_MEMORYRANGE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_memorymanagement_memoryrange_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_memorymanagement_memoryrange_list_decode_malbinary((opssat_std_memorymanagement_memoryrange_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_SHORT_FORM)
  {
    element_holder->value.composite_value = opssat_std_schedulemanagement_listscheduleentry_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = opssat_std_schedulemanagement_listscheduleentry_decode_malbinary((opssat_std_schedulemanagement_listscheduleentry_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_LISTSCHEDULEENTRY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_schedulemanagement_listscheduleentry_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_schedulemanagement_listscheduleentry_list_decode_malbinary((opssat_std_schedulemanagement_listscheduleentry_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (opssat_std_schedulemanagement_schedule_t) enumerated_value;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_schedulemanagement_schedule_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_schedulemanagement_schedule_list_decode_malbinary((opssat_std_schedulemanagement_schedule_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_SHORT_FORM)
  {
    element_holder->value.composite_value = opssat_std_schedulemanagement_scheduleentry_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = opssat_std_schedulemanagement_scheduleentry_decode_malbinary((opssat_std_schedulemanagement_scheduleentry_t *)element_holder->value.composite_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == OPSSAT_STD_SCHEDULEMANAGEMENT_SCHEDULEENTRY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = opssat_std_schedulemanagement_scheduleentry_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = opssat_std_schedulemanagement_scheduleentry_list_decode_malbinary((opssat_std_schedulemanagement_scheduleentry_list_t *)element_holder->value.list_value, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
  return rc;
}

// test function
void opssat_pf_test(bool verbose)
{
  printf(" * opssat_pf: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
