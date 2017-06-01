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

#include "mal.h"

// TODO: These values seem unused, verify and remove if needed.
int MAL_INTERACTIONTYPE_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4,
  5,
  6
};

// TODO: These values seem unused, verify and remove if needed.
int MAL_SESSIONTYPE_NUMERIC_VALUES[] =
{
  1,
  2,
  3
};

// TODO: These values seem unused, verify and remove if needed.
int MAL_QOSLEVEL_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4
};

// TODO: These values seem unused, verify and remove if needed.
int MAL_UPDATETYPE_NUMERIC_VALUES[] =
{
  1,
  2,
  3,
  4
};

clog_logger_t mal_logger = CLOG_WARN_LEVEL;

void mal_set_log_level(int level) {
  mal_logger = level;
}

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
 * Encoding API
 * ***** ***** ***** ***** ***** ***** ***** ***** ***** ******/

int mal_register_add_encoding_length(mal_encoder_t *encoder,
    mal_subscription_t *element, void *cursor) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_subscription_add_encoding_length_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_register_encode(void *cursor, mal_encoder_t *encoder, mal_subscription_t *element) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_subscription_encode_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_register_decode(void *cursor, mal_decoder_t *decoder, mal_subscription_t **res) {
  bool presence_flag = true;
  int rc = 0;
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
  return rc;
}

int mal_deregister_add_encoding_length(mal_encoder_t *encoder,
    mal_identifier_list_t *element, void *cursor) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_identifier_list_add_encoding_length_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_deregister_encode(void *cursor, mal_encoder_t *encoder, mal_identifier_list_t *element) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_identifier_list_encode_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_deregister_decode(void *cursor, mal_decoder_t *decoder, mal_identifier_list_t **res) {
  bool presence_flag = true;
  int rc = 0;
  mal_identifier_list_t *element;
  if (presence_flag) {
    element = mal_identifier_list_new(0);
    rc = mal_identifier_list_decode_malbinary(element, decoder, cursor);
    if (rc < 0)
      return rc;
  } else {
    element = NULL;
  }
  (*res) = element;
  return rc;
}

int mal_publish_register_add_encoding_length_entitykey_list(
    mal_encoder_t *encoder, mal_entitykey_list_t *element, void *cursor) {
  int rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
  if (rc < 0)
    return rc;
  if (element != NULL) {
    rc = mal_entitykey_list_add_encoding_length_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_register_encode_entitykey_list(
    void *cursor, mal_encoder_t *encoder,
    mal_entitykey_list_t *element) {
  int rc = mal_encoder_encode_presence_flag(encoder, cursor, (element != NULL));
  if (rc < 0)
    return rc;
  if (element != NULL) {
    rc = mal_entitykey_list_encode_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_decode_entitykey_list( void *cursor, mal_decoder_t *decoder, mal_entitykey_list_t **res) {
  bool presence_flag;
  int rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
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
  return rc;
}

int mal_publish_deregister_add_encoding_length_entitykey_list(
    mal_encoder_t *encoder, mal_entitykey_list_t *element, void *cursor) {
  int rc = mal_encoder_add_presence_flag_encoding_length(encoder, (element != NULL), cursor);
  if (rc < 0)
    return rc;
  if (element != NULL) {
    rc = mal_entitykey_list_add_encoding_length_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_deregister_encode_entitykey_list(
    void *cursor, mal_encoder_t *encoder,
    mal_entitykey_list_t *element) {
  int rc = mal_encoder_encode_presence_flag(encoder, cursor, (element != NULL));
  if (rc < 0)
    return rc;
  if (element != NULL) {
    rc = mal_entitykey_list_encode_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_add_encoding_length_updateheader_list(
    mal_encoder_t *encoder, mal_updateheader_list_t *element,
    void *cursor) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_updateheader_list_add_encoding_length_malbinary(element,
        encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_encode_updateheader_list(void *cursor, mal_encoder_t *encoder, mal_updateheader_list_t *element) {
  int rc = 0;
  if (element != NULL) {
    rc = mal_updateheader_list_encode_malbinary(element, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}

int mal_publish_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res) {
  bool presence_flag = true;
  int rc = 0;
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
  return rc;
}

int mal_notify_decode_updateheader_list(void *cursor, mal_decoder_t *decoder, mal_updateheader_list_t **res) {
  bool presence_flag = true;
  int rc = 0;
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
  return rc;
}

int mal_malbinary_decode_mal_element(mal_decoder_t * mal_decoder, void * cursor, mal_element_holder_t * element_holder)
{
  int enumerated_value = 0;
  int rc = 0;
  rc = mal_decoder_decode_short_form(mal_decoder, cursor, &element_holder->short_form);
  if (rc < 0)
    return rc;
  if (element_holder->short_form == MAL_BLOB_SHORT_FORM)
  {
    rc = mal_decoder_decode_blob(mal_decoder, cursor, &element_holder->value.blob_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BLOB_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_blob_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_blob_list_decode_malbinary((mal_blob_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_SHORT_FORM)
  {
    rc = mal_decoder_decode_boolean(mal_decoder, cursor, &element_holder->value.boolean_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_BOOLEAN_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_boolean_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary((mal_boolean_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_SHORT_FORM)
  {
    rc = mal_decoder_decode_double(mal_decoder, cursor, &element_holder->value.double_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DOUBLE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_double_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_double_list_decode_malbinary((mal_double_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_SHORT_FORM)
  {
    rc = mal_decoder_decode_duration(mal_decoder, cursor, &element_holder->value.duration_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_DURATION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_duration_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_duration_list_decode_malbinary((mal_duration_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entitykey_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entitykey_decode_malbinary((mal_entitykey_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYKEY_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entitykey_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entitykey_list_decode_malbinary((mal_entitykey_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_entityrequest_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_entityrequest_decode_malbinary((mal_entityrequest_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ENTITYREQUEST_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_entityrequest_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_entityrequest_list_decode_malbinary((mal_entityrequest_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_file_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_file_decode_malbinary((mal_file_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FILE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_file_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_file_list_decode_malbinary((mal_file_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_SHORT_FORM)
  {
    rc = mal_decoder_decode_finetime(mal_decoder, cursor, &element_holder->value.finetime_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FINETIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_finetime_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_finetime_list_decode_malbinary((mal_finetime_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_SHORT_FORM)
  {
    rc = mal_decoder_decode_float(mal_decoder, cursor, &element_holder->value.float_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_FLOAT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_float_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_float_list_decode_malbinary((mal_float_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_idbooleanpair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_idbooleanpair_decode_malbinary((mal_idbooleanpair_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDBOOLEANPAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_idbooleanpair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_idbooleanpair_list_decode_malbinary((mal_idbooleanpair_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_SHORT_FORM)
  {
    rc = mal_decoder_decode_identifier(mal_decoder, cursor, &element_holder->value.identifier_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_IDENTIFIER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_identifier_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_identifier_list_decode_malbinary((mal_identifier_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_SHORT_FORM)
  {
    rc = mal_decoder_decode_integer(mal_decoder, cursor, &element_holder->value.integer_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_integer_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_integer_list_decode_malbinary((mal_integer_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_interactiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_INTERACTIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_interactiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_interactiontype_list_decode_malbinary((mal_interactiontype_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_SHORT_FORM)
  {
    rc = mal_decoder_decode_long(mal_decoder, cursor, &element_holder->value.long_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_LONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_long_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_long_list_decode_malbinary((mal_long_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_namedvalue_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_namedvalue_decode_malbinary((mal_namedvalue_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_NAMEDVALUE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_namedvalue_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_namedvalue_list_decode_malbinary((mal_namedvalue_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_SHORT_FORM)
  {
    rc = mal_decoder_decode_octet(mal_decoder, cursor, &element_holder->value.octet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_OCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_octet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_octet_list_decode_malbinary((mal_octet_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_pair_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_pair_decode_malbinary((mal_pair_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_PAIR_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_pair_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_pair_list_decode_malbinary((mal_pair_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_qoslevel_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_QOSLEVEL_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_qoslevel_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_qoslevel_list_decode_malbinary((mal_qoslevel_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_sessiontype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_SESSIONTYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_sessiontype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_sessiontype_list_decode_malbinary((mal_sessiontype_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_SHORT_FORM)
  {
    rc = mal_decoder_decode_short(mal_decoder, cursor, &element_holder->value.short_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_short_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_short_list_decode_malbinary((mal_short_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_SHORT_FORM)
  {
    rc = mal_decoder_decode_string(mal_decoder, cursor, &element_holder->value.string_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_STRING_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_string_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_string_list_decode_malbinary((mal_string_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_subscription_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_subscription_decode_malbinary((mal_subscription_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_SUBSCRIPTION_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_subscription_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_subscription_list_decode_malbinary((mal_subscription_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_SHORT_FORM)
  {
    rc = mal_decoder_decode_time(mal_decoder, cursor, &element_holder->value.time_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_TIME_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_time_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_time_list_decode_malbinary((mal_time_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_SHORT_FORM)
  {
    rc = mal_decoder_decode_uinteger(mal_decoder, cursor, &element_holder->value.uinteger_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UINTEGER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uinteger_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uinteger_list_decode_malbinary((mal_uinteger_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_SHORT_FORM)
  {
    rc = mal_decoder_decode_ulong(mal_decoder, cursor, &element_holder->value.ulong_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_ULONG_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ulong_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ulong_list_decode_malbinary((mal_ulong_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_SHORT_FORM)
  {
    rc = mal_decoder_decode_uoctet(mal_decoder, cursor, &element_holder->value.uoctet_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UOCTET_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uoctet_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uoctet_list_decode_malbinary((mal_uoctet_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_SHORT_FORM)
  {
    rc = mal_decoder_decode_uri(mal_decoder, cursor, &element_holder->value.uri_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_URI_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_uri_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_uri_list_decode_malbinary((mal_uri_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_SHORT_FORM)
  {
    rc = mal_decoder_decode_ushort(mal_decoder, cursor, &element_holder->value.ushort_value);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_USHORT_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_ushort_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_ushort_list_decode_malbinary((mal_ushort_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_SHORT_FORM)
  {
    element_holder->value.composite_value = mal_updateheader_new();
    if (element_holder->value.composite_value == NULL) return -1;
    rc = mal_updateheader_decode_malbinary((mal_updateheader_t *)element_holder->value.composite_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATEHEADER_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updateheader_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updateheader_list_decode_malbinary((mal_updateheader_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_SHORT_FORM)
  {
    rc = mal_decoder_decode_small_enum(mal_decoder, cursor, &enumerated_value);
    if (rc < 0)
      return rc;
    element_holder->value.enumerated_value = (mal_updatetype_t) enumerated_value;
  }
  else if (element_holder->short_form == MAL_UPDATETYPE_LIST_SHORT_FORM)
  {
    element_holder->value.list_value = mal_updatetype_list_new(0);
    if (element_holder->value.list_value == NULL) return -1;
    rc = mal_updatetype_list_decode_malbinary((mal_updatetype_list_t *)element_holder->value.list_value, mal_decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
    return -1;
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
