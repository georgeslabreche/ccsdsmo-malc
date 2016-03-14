#include "testarea.h"

// generated code for operation testarea_testservice_testsend

int testarea_testservice_testsend_send(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SEND, MAL_IP_STAGE_SEND);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testsend_send_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testsend_send_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testsend_send_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testsend_send_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testsend_send_encode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testsend_send_decode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

// generated code for operation testarea_testservice_testsubmit

int testarea_testservice_testsubmit_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri)
{
  int rc = 0;
  mal_message_init(init_message, TESTAREA_AREA_NUMBER, TESTAREA_AREA_VERSION, TESTAREA_TESTSERVICE_SERVICE_NUMBER, TESTAREA_TESTSERVICE_TESTSUBMIT_OPERATION_NUMBER, MAL_INTERACTIONTYPE_SUBMIT, MAL_IP_STAGE_SUBMIT);
  rc = mal_endpoint_init_operation(endpoint, init_message, provider_uri, true);
  return rc;
}

int testarea_testservice_testsubmit_submit_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testsubmit_submit_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testsubmit_submit_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testsubmit_submit_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testsubmit_submit_encode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testsubmit_submit_decode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testrequest_request_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testcomposite_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testrequest_request_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testcomposite_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testrequest_request_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testcomposite_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testrequest_request_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testrequest_request_encode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testrequest_request_decode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testrequest_request_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testrequest_request_response_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testrequest_request_response_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testinvoke_invoke_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testinvoke_invoke_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testinvoke_invoke_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testinvoke_invoke_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testinvoke_invoke_response_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testinvoke_invoke_response_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testprogress_progress_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testprogress_progress_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testprogress_progress_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testprogress_progress_response_add_encoding_length_0(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testprogress_progress_response_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testprogress_progress_response_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testmonitor_update_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testupdate_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testupdate_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testmonitor_update_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testupdate_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testupdate_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testmonitor_update_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testupdate_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testupdate_list_new(0);
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testupdate_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testmonitor_update_add_encoding_length_1(int encoding_format_code, void * encoder, mal_string_list_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = mal_string_list_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testmonitor_update_encode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, mal_string_list_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = mal_string_list_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testmonitor_update_decode_1(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, mal_string_list_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = mal_string_list_new(0);
        if (*element_res == NULL) return -1;
        rc = mal_string_list_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testinvokealltypes_invoke_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testfullcomposite_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfullcomposite_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testinvokealltypes_invoke_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testfullcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfullcomposite_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testinvokealltypes_invoke_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testfullcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testfullcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testfullcomposite_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testinvokealltypes_invoke_response_add_encoding_length_0(int encoding_format_code, void * encoder, testarea_testservice_testfullcomposite_t * element, unsigned int * encoding_length)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      (*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
      if (element != NULL)
      {
        rc = testarea_testservice_testfullcomposite_add_encoding_length_malbinary(element, malbinary_encoder, encoding_length);
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

int testarea_testservice_testinvokealltypes_invoke_response_encode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * encoder, testarea_testservice_testfullcomposite_t * element)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_encoder_t * malbinary_encoder = (malbinary_encoder_t *) encoder;
      bool presence_flag = (element != NULL);
      rc = malbinary_encoder_encode_presence_flag(malbinary_encoder, bytes, offset, presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        rc = testarea_testservice_testfullcomposite_encode_malbinary(element, malbinary_encoder, bytes, offset);
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

int testarea_testservice_testinvokealltypes_invoke_response_decode_0(int encoding_format_code, char * bytes, unsigned int * offset, void * decoder, testarea_testservice_testfullcomposite_t ** element_res)
{
  int rc = 0;
  switch (encoding_format_code)
  {
    case MALBINARY_FORMAT_CODE:
    {
      malbinary_decoder_t * malbinary_decoder = (malbinary_decoder_t *) decoder;
      bool presence_flag;
      rc = malbinary_decoder_decode_presence_flag(malbinary_decoder, bytes, offset, &presence_flag);
      if (rc < 0)
        return rc;
      if (presence_flag)
      {
        *element_res = testarea_testservice_testfullcomposite_new();
        if (*element_res == NULL) return -1;
        rc = testarea_testservice_testfullcomposite_decode_malbinary(*element_res, malbinary_decoder, bytes, offset);
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

int testarea_testservice_testsend_send_add_encoding_length_2_testarea_testservice_testfinalcompositea(
    int encoding_format_code, void * encoder,
    testarea_testservice_testfinalcompositea_t *element,
    unsigned int *encoding_length) {
  int rc = 0;
  switch (encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    malbinary_encoder_t *binary_encoder = (malbinary_encoder_t *) encoder;
    rc = malbinary_encoder_add_presence_flag_encoding_length(binary_encoder,
        encoding_length);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = malbinary_encoder_add_short_form_encoding_length(binary_encoder,
          encoding_length);
      if (rc < 0)
        return rc;
      rc =
          testarea_testservice_testfinalcompositea_add_encoding_length_malbinary(
              element, binary_encoder, encoding_length);
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

int testarea_testservice_testsend_send_encode_2_testarea_testservice_testfinalcompositea(
    int encoding_format_code, char *bytes, unsigned int *offset, void *encoder,
    testarea_testservice_testfinalcompositea_t *element) {
  int rc = 0;
  switch (encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    malbinary_encoder_t *binary_encoder = (malbinary_encoder_t *) encoder;
    bool presence_flag = (element != NULL);
    rc = malbinary_encoder_encode_presence_flag(binary_encoder, bytes, offset,
        presence_flag);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = malbinary_encoder_encode_short_form(binary_encoder, bytes, offset,
      TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM);
      if (rc < 0)
        return rc;
      rc = testarea_testservice_testfinalcompositea_encode_malbinary(element,
          binary_encoder, bytes, offset);
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

int testarea_testservice_testsend_send_decode_2(int encoding_format_code,
    char *bytes, unsigned int *offset, void *decoder, long *short_form_res,
    void **res) {
  int rc = 0;
  switch (encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    malbinary_decoder_t *binary_decoder = (malbinary_decoder_t *) decoder;
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(binary_decoder, bytes, offset,
        &presence_flag);
    if (rc < 0)
      return rc;
    void *element;
    long short_form;
    if (presence_flag) {
      malbinary_decoder_decode_short_form(binary_decoder, bytes, offset,
          &short_form);
      if (short_form == TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
        testarea_testservice_testfinalcompositea_t *composite =
            testarea_testservice_testfinalcompositea_new();
        rc = testarea_testservice_testfinalcompositea_decode_malbinary(
            composite, binary_decoder, bytes, offset);
        element = composite;
      } else {
        rc = -1;
      }
      if (rc < 0)
        return rc;
    } else {
      short_form = 0;
      element = NULL;
    }
    (*res) = element;
    (*short_form_res) = short_form;
    break;
  }
  default:
    rc = -1;
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
