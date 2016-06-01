/*
 */

#include "mal.h"

clog_logger_t mal_logger = CLOG_WARN_LEVEL;

void mal_set_log_level(int level) {
  mal_logger = level;
}

int mal_register_add_encoding_length(mal_encoder_t *encoder,
    mal_subscription_t *element, void *cursor) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_subscription_add_encoding_length_malbinary(element, encoder, cursor);
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

int mal_register_encode(void *cursor, mal_encoder_t *encoder, mal_subscription_t *element) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag = (element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_subscription_encode_malbinary(element, encoder, cursor);
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

int mal_register_decode(void *cursor, mal_decoder_t *decoder, mal_subscription_t **res) {
  int rc = 0;
  switch (decoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    mal_subscription_t *element;
    if (presence_flag) {
      element = mal_subscription_new();
      rc = mal_subscription_decode_malbinary(element, decoder, cursor);
      if (rc < 0)
        return rc;
    } else {
      element = NULL;
    }
    (*res) = element;
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}

int mal_publish_register_add_encoding_length_entitykey_list(
    mal_encoder_t *encoder, mal_entitykey_list_t *element, void *cursor) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_entitykey_list_add_encoding_length_malbinary(element, encoder, cursor);
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

int mal_publish_register_encode_entitykey_list(
    void *cursor, mal_encoder_t *encoder,
    mal_entitykey_list_t *element) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag = (element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_entitykey_list_encode_malbinary(element, encoder, cursor);
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

int mal_publish_decode_entitykey_list( void *cursor, mal_decoder_t *decoder, mal_entitykey_list_t **res) {
  int rc = 0;
  switch (decoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    mal_entitykey_list_t *element;
    if (presence_flag) {
      element = mal_entitykey_list_new(1);
      rc = mal_entitykey_list_decode_malbinary(element, decoder, cursor);
      if (rc < 0)
        return rc;
    } else {
      element = NULL;
    }
    (*res) = element;
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}

int mal_publish_add_encoding_length_updateheader_list(
    mal_encoder_t *encoder, mal_updateheader_list_t *element,
    void *cursor) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    rc = malbinary_encoder_add_presence_flag_encoding_length(encoder,
        cursor);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_updateheader_list_add_encoding_length_malbinary(element,
          encoder, cursor);
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

int mal_publish_encode_updateheader_list(void *cursor, mal_encoder_t *encoder, mal_updateheader_list_t *element) {
  int rc = 0;
  switch (encoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag = (element != NULL);
    rc = malbinary_encoder_encode_presence_flag(encoder, cursor, presence_flag);
    if (rc < 0)
      return rc;
    if (element != NULL) {
      rc = mal_updateheader_list_encode_malbinary(element, encoder, cursor);
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

int mal_publish_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res) {
  int rc = 0;
  switch (decoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    mal_updateheader_list_t *element;
    if (presence_flag) {
      element = mal_updateheader_list_new(1);
      rc = mal_updateheader_list_decode_malbinary(element, decoder, cursor);
      if (rc < 0)
        return rc;
    } else {
      element = NULL;
    }
    (*res) = element;
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}

/*
int mal_notify_decode_subscriptionid(, void *cursor, mal_decoder_t *decoder, mal_identifier_t **res) {
  int rc = 0;
  switch (decoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, bytes, offset, &presence_flag);
    if (rc < 0)
      return rc;
    mal_identifier_t *element;
    if (presence_flag) {
      element = mal_updateheader_list_new();
      rc = malbinary_decoder_decode_identifier(decoder, bytes, offset, &element);
      if (rc < 0)
        return rc;
    } else {
      element = NULL;
    }
    (*res) = element;
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
*/

int mal_notify_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res) {
  int rc = 0;
  switch (decoder->encoding_format_code) {
  case MALBINARY_FORMAT_CODE: {
    bool presence_flag;
    rc = malbinary_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
    if (rc < 0)
      return rc;
    mal_updateheader_list_t *element;
    if (presence_flag) {
      element = mal_updateheader_list_new(1);
      rc = mal_updateheader_list_decode_malbinary(element, decoder, cursor);
      if (rc < 0)
        return rc;
    } else {
      element = NULL;
    }
    (*res) = element;
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}

void mal_test(bool verbose) {
  printf(" * mal_test: ");
  if (verbose)
    printf("\n");

//  @selftest
// ...
//  @end
  printf("OK\n");
}
