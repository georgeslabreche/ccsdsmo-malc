#include "mal.h"

struct _mal_entitykey_t {
  mal_identifier_t *firstsubkey;
  bool secondsubkey_is_present;
  mal_long_t secondsubkey;
  bool thirdsubkey_is_present;
  mal_long_t thirdsubkey;
  bool fourthsubkey_is_present;
  mal_long_t fourthsubkey;
};

mal_entitykey_t *mal_entitykey_new(void) {
  mal_entitykey_t *self = (mal_entitykey_t *) malloc(sizeof(mal_entitykey_t));
  if (!self)
    return NULL;
  return self;
}

void mal_entitykey_destroy(mal_entitykey_t **self_p) {
  if (*self_p) {
    mal_entitykey_t *self = *self_p;
    mal_identifier_destroy(&(self->firstsubkey));
    free(self);
    *self_p = NULL;
  }
}

int mal_entitykey_add_encoding_length_malbinary(mal_entitykey_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  if (self == NULL) {
    rc = -1;
    return rc;
  }

  // Field 'firstsubkey' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
  if (self->firstsubkey != NULL) {
    rc = malbinary_encoder_add_string_encoding_length(encoder, self->firstsubkey, cursor);
    if (rc < 0)
      return rc;
  }

  // Field 'secondsubkey' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
  if (rc < 0)
    return rc;
  if (self->secondsubkey_is_present) {
    rc = malbinary_encoder_add_long_encoding_length(encoder, self->secondsubkey, cursor);
    if (rc < 0)
      return rc;
  }

  // Field 'thirdsubkey' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
  if (rc < 0)
    return rc;
  if (self->thirdsubkey_is_present) {
    rc = malbinary_encoder_add_long_encoding_length(encoder, self->thirdsubkey, cursor);
    if (rc < 0)
      return rc;
  }

  // Field 'fourthsubkey' (canBeNull='true')
  rc = malbinary_encoder_add_presence_flag_encoding_length(encoder, cursor);
  if (rc < 0)
    return rc;
  if (self->fourthsubkey_is_present) {
    rc = malbinary_encoder_add_long_encoding_length(encoder, self->fourthsubkey, cursor);
    if (rc < 0)
      return rc;
  }

  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entitykey_encode_malbinary(mal_entitykey_t *self,
    mal_encoder_t *encoder, void *cursor) {
  int rc = 0;

  bool is_present = (self->firstsubkey != NULL);
  rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
      is_present);
  if (is_present) {
    rc = malbinary_encoder_encode_identifier(encoder, cursor,
        self->firstsubkey);
    if (rc < 0)
      return rc;
  }

  rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
      self->secondsubkey_is_present);
  if (rc < 0)
    return rc;
  if (self->secondsubkey_is_present) {
    rc = malbinary_encoder_encode_long(encoder, cursor,
        self->secondsubkey);
  }

  rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
      self->thirdsubkey_is_present);
  if (rc < 0)
    return rc;
  if (self->thirdsubkey_is_present) {
    rc = malbinary_encoder_encode_long(encoder, cursor,
        self->thirdsubkey);
  }

  rc = malbinary_encoder_encode_presence_flag(encoder, cursor,
      self->fourthsubkey_is_present);
  if (rc < 0)
    return rc;
  if (self->fourthsubkey_is_present) {
    rc = malbinary_encoder_encode_long(encoder, cursor,
        self->fourthsubkey);
  }

  return rc;
}

// 'binary' refers to the "binary encoding" specified in MAL/SPP BB
int mal_entitykey_decode_malbinary(mal_entitykey_t *self,
    mal_decoder_t *decoder, void *cursor) {
  int rc = 0;
  rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
      &(self->secondsubkey_is_present));
  if (rc < 0)
    return rc;
  if (self->secondsubkey_is_present) {
    rc = malbinary_decoder_decode_identifier(decoder, cursor,
        &(self->firstsubkey));
    if (rc < 0)
      return rc;
  }

  rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
      &(self->secondsubkey_is_present));
  if (rc < 0)
    return rc;
  if (self->secondsubkey_is_present) {
    rc = malbinary_decoder_decode_long(decoder, cursor,
        &(self->secondsubkey));
  }

  rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
      &(self->thirdsubkey_is_present));
  if (rc < 0)
    return rc;
  if (self->thirdsubkey_is_present) {
    rc = malbinary_decoder_decode_long(decoder, cursor,
        &(self->thirdsubkey));
  }

  rc = malbinary_decoder_decode_presence_flag(decoder, cursor,
      &(self->fourthsubkey_is_present));
  if (rc < 0)
    return rc;
  if (self->fourthsubkey_is_present) {
    rc = malbinary_decoder_decode_long(decoder, cursor,
        &(self->fourthsubkey));
  }
  return rc;
}

mal_identifier_t *mal_entitykey_get_firstsubkey(mal_entitykey_t *self) {
  return self->firstsubkey;
}

void mal_entitykey_set_firstsubkey(mal_entitykey_t *self,
    mal_identifier_t *firstsubkey) {
  self->firstsubkey = firstsubkey;
}

mal_long_t mal_entitykey_secondsubkey_is_present(mal_entitykey_t *self) {
  return self->secondsubkey;
}

void mal_entitykey_secondsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present) {
  self->secondsubkey_is_present = is_present;
}

mal_long_t mal_entitykey_get_secondsubkey(mal_entitykey_t *self) {
  return self->secondsubkey;
}

void mal_entitykey_set_secondsubkey(mal_entitykey_t *self,
    mal_long_t secondsubkey) {
  self->secondsubkey = secondsubkey;
}

mal_long_t mal_entitykey_thirdsubkey_is_present(mal_entitykey_t *self) {
  return self->thirdsubkey;
}

void mal_entitykey_thirdsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present) {
  self->thirdsubkey_is_present = is_present;
}

mal_long_t mal_entitykey_get_thirdsubkey(mal_entitykey_t *self) {
  return self->thirdsubkey;
}

void mal_entitykey_set_thirdsubkey(mal_entitykey_t *self,
    mal_long_t thirdsubkey) {
  self->thirdsubkey = thirdsubkey;
}

mal_long_t mal_entitykey_fourthsubkey_is_present(mal_entitykey_t *self) {
  return self->fourthsubkey;
}

void mal_entitykey_fourthsubkey_set_present(mal_entitykey_t *self,
    mal_long_t is_present) {
  self->fourthsubkey_is_present = is_present;
}

mal_long_t mal_entitykey_get_fourthsubkey(mal_entitykey_t *self) {
  return self->fourthsubkey;
}

void mal_entitykey_set_fourthsubkey(mal_entitykey_t *self,
    mal_long_t fourthsubkey) {
  self->fourthsubkey = fourthsubkey;
}

void mal_entitykey_test(bool verbose) {
  printf(" * mal_entitykey: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

