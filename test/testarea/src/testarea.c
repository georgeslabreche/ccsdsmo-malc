#include "testarea.h"

// generated code for operation testarea_testservice_testsend

int testarea_testservice_testsend_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SEND, MAL_IP_STAGE_SEND);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testsend_send_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testsend_send_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_encode_1(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_decode_1(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(int encoding_format_code, void * encoder, testarea_testservice_testfinalcompositea_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testfinalcompositea_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfinalcompositea_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositeb(int encoding_format_code, void * encoder, testarea_testservice_testfinalcompositeb_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfinalcompositeb_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositeb(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testfinalcompositeb_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfinalcompositeb_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsend_send_decode_2(int encoding_format_code, void * cursor, void * decoder, mal_element_holder_t * element_holder)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_malbinary_decode_mal_element(malbinary_decoder, cursor, element_holder);
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

// generated code for operation testarea_testservice_testsubmit

int testarea_testservice_testsubmit_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testsubmit_submit_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsubmit_submit_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsubmit_submit_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testsubmit_submit_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsubmit_submit_encode_1(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testsubmit_submit_decode_1(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testsubmit_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

// generated code for operation testarea_testservice_testrequest

int testarea_testservice_testrequest_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTREQUEST_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testrequest_request_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testrequest_request_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_encode_1(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_decode_1(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testrequest_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTREQUEST_OPERATION_NUMBER, MAL_INTERACTIONTYPE_REQUEST, MAL_IP_STAGE_REQUEST_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testrequest_request_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_response_encode_0(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testrequest_request_response_decode_0(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

// generated code for operation testarea_testservice_testinvoke

int testarea_testservice_testinvoke_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testinvoke_invoke_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvoke_invoke_encode_0(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvoke_invoke_decode_0(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testinvoke_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testinvoke_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKE_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testinvoke_invoke_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvoke_invoke_response_encode_0(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvoke_invoke_response_decode_0(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

// generated code for operation testarea_testservice_testprogress

int testarea_testservice_testprogress_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testprogress_progress_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testprogress_progress_encode_0(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testprogress_progress_decode_0(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testprogress_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testprogress_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_UPDATE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testprogress_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTPROGRESS_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PROGRESS, MAL_IP_STAGE_PROGRESS_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testprogress_progress_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testprogress_progress_response_encode_0(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testprogress_progress_response_decode_0(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

// generated code for operation testarea_testservice_testmonitor

int testarea_testservice_testmonitor_update_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testupdate_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testupdate_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testmonitor_update_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testupdate_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testupdate_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testmonitor_update_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testupdate_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testupdate_list_new(0);
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testupdate_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testmonitor_update_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testmonitor_update_encode_1(int encoding_format_code, void * cursor, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testmonitor_update_decode_1(int encoding_format_code, void * cursor, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testmonitor_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int testarea_testservice_testmonitor_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int testarea_testservice_testmonitor_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid)
{
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH);
  mal_message_set_transaction_id(message, initial_publish_register_tid);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, false);
  return rc;
}

int testarea_testservice_testmonitor_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

int testarea_testservice_testmonitor_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri)
{
  int rc = 0;
  mal_message_init(message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTMONITOR_OPERATION_NUMBER, MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER);
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}

// generated code for operation testarea_testservice_testinvokealltypes

int testarea_testservice_testinvokealltypes_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKEALLTYPES_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testinvokealltypes_invoke_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfullcomposite_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvokealltypes_invoke_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testfullcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfullcomposite_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvokealltypes_invoke_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testfullcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testfullcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testfullcomposite_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_testservice_testinvokealltypes_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKEALLTYPES_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_ACK);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testinvokealltypes_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message)
{
  int rc = 0;
  mal_message_init(result_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTINVOKEALLTYPES_OPERATION_NUMBER, MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE_RESPONSE);
  rc = mal_endpoint_return_operation(endpoint, init_message, result_message, is_error_message);
  return rc;
}

int testarea_testservice_testinvokealltypes_invoke_response_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testfullcomposite_t * element, void * cursor)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      ((malbinary_cursor_t *) cursor)->body_length += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfullcomposite_add_encoding_length_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvokealltypes_invoke_response_encode_0(int encoding_format_code, void * cursor, void * encoder, testarea_testservice_testfullcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, cursor, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfullcomposite_encode_malbinary(element, malbinary_encoder, cursor);
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

int testarea_testservice_testinvokealltypes_invoke_response_decode_0(int encoding_format_code, void * cursor, void * decoder, testarea_testservice_testfullcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, cursor, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testfullcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testfullcomposite_decode_malbinary(*element_res, malbinary_decoder, cursor);
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

int testarea_malbinary_decode_mal_element(malbinary_decoder_t * malbinary_decoder, void * cursor, mal_element_holder_t * element_holder)
{
  int enumerated_value = 0;
  int rc = 0;
  rc = malbinary_decoder_decode_short_form(malbinary_decoder, cursor, &element_holder->short_form);
  if (rc < 0)
    return rc;
  if (element_holder->short_form == MAL_BLOB_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_blob(malbinary_decoder, cursor, &element_holder->value.blob_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_blob_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_blob_list_decode_malbinary((mal_blob_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_boolean(malbinary_decoder, cursor, &element_holder->value.boolean_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_boolean_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary((mal_boolean_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_double(malbinary_decoder, cursor, &element_holder->value.double_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_double_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_double_list_decode_malbinary((mal_double_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_duration(malbinary_decoder, cursor, &element_holder->value.duration_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_duration_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_duration_list_decode_malbinary((mal_duration_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entitykey_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entitykey_decode_malbinary((mal_entitykey_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entitykey_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entitykey_list_decode_malbinary((mal_entitykey_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entityrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entityrequest_decode_malbinary((mal_entityrequest_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entityrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entityrequest_list_decode_malbinary((mal_entityrequest_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_file_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_file_decode_malbinary((mal_file_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_file_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_file_list_decode_malbinary((mal_file_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_finetime(malbinary_decoder, cursor, &element_holder->value.finetime_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_finetime_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_finetime_list_decode_malbinary((mal_finetime_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_float(malbinary_decoder, cursor, &element_holder->value.float_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_float_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_float_list_decode_malbinary((mal_float_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_idbooleanpair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_idbooleanpair_decode_malbinary((mal_idbooleanpair_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_idbooleanpair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_idbooleanpair_list_decode_malbinary((mal_idbooleanpair_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_identifier(malbinary_decoder, cursor, &element_holder->value.identifier_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_identifier_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary((mal_identifier_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_integer(malbinary_decoder, cursor, &element_holder->value.integer_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_integer_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_integer_list_decode_malbinary((mal_integer_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_small_enum(malbinary_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_interactiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_interactiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_interactiontype_list_decode_malbinary((mal_interactiontype_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_long(malbinary_decoder, cursor, &element_holder->value.long_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_long_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_long_list_decode_malbinary((mal_long_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_namedvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_namedvalue_decode_malbinary((mal_namedvalue_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_namedvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary((mal_namedvalue_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_octet(malbinary_decoder, cursor, &element_holder->value.octet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_octet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_octet_list_decode_malbinary((mal_octet_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_pair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_pair_decode_malbinary((mal_pair_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_pair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_pair_list_decode_malbinary((mal_pair_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_small_enum(malbinary_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_qoslevel_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_qoslevel_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_qoslevel_list_decode_malbinary((mal_qoslevel_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_small_enum(malbinary_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_sessiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_sessiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_sessiontype_list_decode_malbinary((mal_sessiontype_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_short(malbinary_decoder, cursor, &element_holder->value.short_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_short_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_short_list_decode_malbinary((mal_short_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_string(malbinary_decoder, cursor, &element_holder->value.string_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_string_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_string_list_decode_malbinary((mal_string_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_subscription_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_subscription_decode_malbinary((mal_subscription_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_subscription_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_subscription_list_decode_malbinary((mal_subscription_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_time(malbinary_decoder, cursor, &element_holder->value.time_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_time_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_time_list_decode_malbinary((mal_time_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_uinteger(malbinary_decoder, cursor, &element_holder->value.uinteger_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uinteger_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uinteger_list_decode_malbinary((mal_uinteger_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_ulong(malbinary_decoder, cursor, &element_holder->value.ulong_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ulong_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ulong_list_decode_malbinary((mal_ulong_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_uoctet(malbinary_decoder, cursor, &element_holder->value.uoctet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uoctet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uoctet_list_decode_malbinary((mal_uoctet_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_uri(malbinary_decoder, cursor, &element_holder->value.uri_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uri_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uri_list_decode_malbinary((mal_uri_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_ushort(malbinary_decoder, cursor, &element_holder->value.ushort_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ushort_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ushort_list_decode_malbinary((mal_ushort_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_updateheader_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_updateheader_decode_malbinary((mal_updateheader_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updateheader_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updateheader_list_decode_malbinary((mal_updateheader_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_small_enum(malbinary_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_updatetype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updatetype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updatetype_list_decode_malbinary((mal_updatetype_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTCOMPOSITE_SHORT_FORM)
  {
    element_holder->value.composite_value = testarea_testservice_testcomposite_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = testarea_testservice_testcomposite_decode_malbinary((testarea_testservice_testcomposite_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTCOMPOSITE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testservice_testcomposite_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testservice_testcomposite_list_decode_malbinary((testarea_testservice_testcomposite_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM)
  {
    element_holder->value.composite_value = testarea_testservice_testfinalcompositea_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = testarea_testservice_testfinalcompositea_decode_malbinary((testarea_testservice_testfinalcompositea_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testservice_testfinalcompositea_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testservice_testfinalcompositea_list_decode_malbinary((testarea_testservice_testfinalcompositea_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_SHORT_FORM)
  {
    element_holder->value.composite_value = testarea_testservice_testfinalcompositeb_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = testarea_testservice_testfinalcompositeb_decode_malbinary((testarea_testservice_testfinalcompositeb_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEB_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testservice_testfinalcompositeb_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testservice_testfinalcompositeb_list_decode_malbinary((testarea_testservice_testfinalcompositeb_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_SHORT_FORM)
  {
    element_holder->value.composite_value = testarea_testservice_testfullcomposite_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = testarea_testservice_testfullcomposite_decode_malbinary((testarea_testservice_testfullcomposite_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTFULLCOMPOSITE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testservice_testfullcomposite_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testservice_testfullcomposite_list_decode_malbinary((testarea_testservice_testfullcomposite_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTUPDATE_SHORT_FORM)
  {
    element_holder->value.composite_value = testarea_testservice_testupdate_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = testarea_testservice_testupdate_decode_malbinary((testarea_testservice_testupdate_t *)element_holder->value.composite_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTSERVICE_TESTUPDATE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testservice_testupdate_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testservice_testupdate_list_decode_malbinary((testarea_testservice_testupdate_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == TESTAREA_TESTENUMERATION_SHORT_FORM)
  {
    rc = malbinary_decoder_decode_small_enum(malbinary_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (testarea_testenumeration_t) enumerated_value;
  }
  else if (element_holder->short_form == TESTAREA_TESTENUMERATION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = testarea_testenumeration_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = testarea_testenumeration_list_decode_malbinary((testarea_testenumeration_list_t *)element_holder->value.list_value, malbinary_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

// test function
void testarea_test(bool verbose)
{
  printf(" * testarea: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
