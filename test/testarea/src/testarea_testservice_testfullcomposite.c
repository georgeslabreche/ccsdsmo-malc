#include "testarea.h"


// structure definition for composite testarea_testservice_testfullcomposite
struct _testarea_testservice_testfullcomposite_t {
  mal_boolean_t boolfield;
  bool intfield_is_present;
  mal_integer_t intfield;
  mal_string_t * stringfield;
  mal_blob_t * blobfield;
  testarea_testenumeration_t enumfield;
  testarea_testservice_testcomposite_t * compfield;
  mal_boolean_list_t * boollistfield;
  mal_integer_list_t * intlistfield;
  mal_string_list_t * stringlistfield;
  mal_blob_list_t * bloblistfield;
  testarea_testenumeration_list_t * enumlistfield;
  testarea_testservice_testcomposite_list_t * complistfield;
  unsigned char attributefield_attribute_tag;
  union mal_attribute_t attributefield;
};

// fields accessors for composite testarea_testservice_testfullcomposite
mal_boolean_t testarea_testservice_testfullcomposite_get_boolfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->boolfield;
}
void testarea_testservice_testfullcomposite_set_boolfield(testarea_testservice_testfullcomposite_t * self, mal_boolean_t boolfield)
{
  self->boolfield = boolfield;
}
bool testarea_testservice_testfullcomposite_intfield_is_present(testarea_testservice_testfullcomposite_t * self)
{
  return self->intfield_is_present;
}
void testarea_testservice_testfullcomposite_intfield_set_present(testarea_testservice_testfullcomposite_t * self, bool is_present)
{
  self->intfield_is_present = is_present;
}
mal_integer_t testarea_testservice_testfullcomposite_get_intfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->intfield;
}
void testarea_testservice_testfullcomposite_set_intfield(testarea_testservice_testfullcomposite_t * self, mal_integer_t intfield)
{
  self->intfield = intfield;
}
mal_string_t * testarea_testservice_testfullcomposite_get_stringfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->stringfield;
}
void testarea_testservice_testfullcomposite_set_stringfield(testarea_testservice_testfullcomposite_t * self, mal_string_t * stringfield)
{
  self->stringfield = stringfield;
}
mal_blob_t * testarea_testservice_testfullcomposite_get_blobfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->blobfield;
}
void testarea_testservice_testfullcomposite_set_blobfield(testarea_testservice_testfullcomposite_t * self, mal_blob_t * blobfield)
{
  self->blobfield = blobfield;
}
testarea_testenumeration_t testarea_testservice_testfullcomposite_get_enumfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->enumfield;
}
void testarea_testservice_testfullcomposite_set_enumfield(testarea_testservice_testfullcomposite_t * self, testarea_testenumeration_t enumfield)
{
  self->enumfield = enumfield;
}
testarea_testservice_testcomposite_t * testarea_testservice_testfullcomposite_get_compfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->compfield;
}
void testarea_testservice_testfullcomposite_set_compfield(testarea_testservice_testfullcomposite_t * self, testarea_testservice_testcomposite_t * compfield)
{
  self->compfield = compfield;
}
mal_boolean_list_t * testarea_testservice_testfullcomposite_get_boollistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->boollistfield;
}
void testarea_testservice_testfullcomposite_set_boollistfield(testarea_testservice_testfullcomposite_t * self, mal_boolean_list_t * boollistfield)
{
  self->boollistfield = boollistfield;
}
mal_integer_list_t * testarea_testservice_testfullcomposite_get_intlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->intlistfield;
}
void testarea_testservice_testfullcomposite_set_intlistfield(testarea_testservice_testfullcomposite_t * self, mal_integer_list_t * intlistfield)
{
  self->intlistfield = intlistfield;
}
mal_string_list_t * testarea_testservice_testfullcomposite_get_stringlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->stringlistfield;
}
void testarea_testservice_testfullcomposite_set_stringlistfield(testarea_testservice_testfullcomposite_t * self, mal_string_list_t * stringlistfield)
{
  self->stringlistfield = stringlistfield;
}
mal_blob_list_t * testarea_testservice_testfullcomposite_get_bloblistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->bloblistfield;
}
void testarea_testservice_testfullcomposite_set_bloblistfield(testarea_testservice_testfullcomposite_t * self, mal_blob_list_t * bloblistfield)
{
  self->bloblistfield = bloblistfield;
}
testarea_testenumeration_list_t * testarea_testservice_testfullcomposite_get_enumlistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->enumlistfield;
}
void testarea_testservice_testfullcomposite_set_enumlistfield(testarea_testservice_testfullcomposite_t * self, testarea_testenumeration_list_t * enumlistfield)
{
  self->enumlistfield = enumlistfield;
}
testarea_testservice_testcomposite_list_t * testarea_testservice_testfullcomposite_get_complistfield(testarea_testservice_testfullcomposite_t * self)
{
  return self->complistfield;
}
void testarea_testservice_testfullcomposite_set_complistfield(testarea_testservice_testfullcomposite_t * self, testarea_testservice_testcomposite_list_t * complistfield)
{
  self->complistfield = complistfield;
}
unsigned char testarea_testservice_testfullcomposite_attributefield_get_attribute_tag(testarea_testservice_testfullcomposite_t * self)
{
  return self->attributefield_attribute_tag;
}
void testarea_testservice_testfullcomposite_attributefield_set_attribute_tag(testarea_testservice_testfullcomposite_t * self, unsigned char attribute_tag)
{
  self->attributefield_attribute_tag = attribute_tag;
}

// default constructor
testarea_testservice_testfullcomposite_t * testarea_testservice_testfullcomposite_new(void)
{
  testarea_testservice_testfullcomposite_t *self = (testarea_testservice_testfullcomposite_t *) calloc(1, sizeof(testarea_testservice_testfullcomposite_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int testarea_testservice_testfullcomposite_add_encoding_length_malbinary(testarea_testservice_testfullcomposite_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_boolean_encoding_length(encoder, self->boolfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->intfield_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->intfield_is_present)
  {
    rc = mal_encoder_add_integer_encoding_length(encoder, self->intfield, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->stringfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->stringfield != NULL))
  {
    rc = mal_encoder_add_string_encoding_length(encoder, self->stringfield, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_blob_encoding_length(encoder, self->blobfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_small_enum_encoding_length(encoder, self->enumfield, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->compfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->compfield != NULL))
  {
    rc = testarea_testservice_testcomposite_add_encoding_length_malbinary(self->compfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->boollistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->boollistfield != NULL))
  {
    rc = mal_boolean_list_add_encoding_length_malbinary(self->boollistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_integer_list_add_encoding_length_malbinary(self->intlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_string_list_add_encoding_length_malbinary(self->stringlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->bloblistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->bloblistfield != NULL))
  {
    rc = mal_blob_list_add_encoding_length_malbinary(self->bloblistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->enumlistfield != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->enumlistfield != NULL))
  {
    rc = testarea_testenumeration_list_add_encoding_length_malbinary(self->enumlistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = testarea_testservice_testcomposite_list_add_encoding_length_malbinary(self->complistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_tag_encoding_length(encoder, self->attributefield_attribute_tag, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_attribute_encoding_length(encoder, self->attributefield_attribute_tag, self->attributefield, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfullcomposite_encode_malbinary(testarea_testservice_testfullcomposite_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_encoder_encode_boolean(encoder, cursor, self->boolfield);
  if (rc < 0)
    return rc;
  presence_flag = self->intfield_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_integer(encoder, cursor, self->intfield);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->stringfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_string(encoder, cursor, self->stringfield);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_blob(encoder, cursor, self->blobfield);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_small_enum(encoder, cursor, self->enumfield);
  if (rc < 0)
    return rc;
  presence_flag = (self->compfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = testarea_testservice_testcomposite_encode_malbinary(self->compfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->boollistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_boolean_list_encode_malbinary(self->boollistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_integer_list_encode_malbinary(self->intlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_string_list_encode_malbinary(self->stringlistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  presence_flag = (self->bloblistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_blob_list_encode_malbinary(self->bloblistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->enumlistfield != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = testarea_testenumeration_list_encode_malbinary(self->enumlistfield, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  rc = testarea_testservice_testcomposite_list_encode_malbinary(self->complistfield, encoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute_tag(encoder, cursor, self->attributefield_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_attribute(encoder, cursor, self->attributefield_attribute_tag, self->attributefield);
  if (rc < 0)
    return rc;
  return rc;
}
int testarea_testservice_testfullcomposite_decode_malbinary(testarea_testservice_testfullcomposite_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  int enumerated_value;
  rc = mal_decoder_decode_boolean(decoder, cursor, &self->boolfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_integer(decoder, cursor, &self->intfield);
    if (rc < 0)
      return rc;
  }
  self->intfield_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_string(decoder, cursor, &self->stringfield);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->stringfield = NULL;
  }
  rc = mal_decoder_decode_blob(decoder, cursor, &self->blobfield);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_small_enum(decoder, cursor, &enumerated_value);
  if (rc < 0)
    return rc;
  self->enumfield = (testarea_testenumeration_t) enumerated_value;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->compfield = testarea_testservice_testcomposite_new();
    if (self->compfield == NULL) return -1;
    rc = testarea_testservice_testcomposite_decode_malbinary(self->compfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->compfield = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->boollistfield = mal_boolean_list_new(0);
    if (self->boollistfield == NULL) return -1;
    rc = mal_boolean_list_decode_malbinary(self->boollistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->boollistfield = NULL;
  }
  self->intlistfield = mal_integer_list_new(0);
  if (self->intlistfield == NULL) return -1;
  rc = mal_integer_list_decode_malbinary(self->intlistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  self->stringlistfield = mal_string_list_new(0);
  if (self->stringlistfield == NULL) return -1;
  rc = mal_string_list_decode_malbinary(self->stringlistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->bloblistfield = mal_blob_list_new(0);
    if (self->bloblistfield == NULL) return -1;
    rc = mal_blob_list_decode_malbinary(self->bloblistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->bloblistfield = NULL;
  }
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->enumlistfield = testarea_testenumeration_list_new(0);
    if (self->enumlistfield == NULL) return -1;
    rc = testarea_testenumeration_list_decode_malbinary(self->enumlistfield, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->enumlistfield = NULL;
  }
  self->complistfield = testarea_testservice_testcomposite_list_new(0);
  if (self->complistfield == NULL) return -1;
  rc = testarea_testservice_testcomposite_list_decode_malbinary(self->complistfield, decoder, cursor);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute_tag(decoder, cursor, &self->attributefield_attribute_tag);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_attribute(decoder, cursor, self->attributefield_attribute_tag, self->attributefield);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void testarea_testservice_testfullcomposite_destroy(testarea_testservice_testfullcomposite_t ** self_p)
{
  if ((*self_p)->stringfield != NULL)
  {
    mal_string_destroy(& (*self_p)->stringfield);
  }
  if ((*self_p)->blobfield != NULL)
  {
    mal_blob_destroy(& (*self_p)->blobfield);
  }
  if ((*self_p)->compfield != NULL)
  {
    testarea_testservice_testcomposite_destroy(& (*self_p)->compfield);
  }
  if ((*self_p)->boollistfield != NULL)
  {
    mal_boolean_list_destroy(& (*self_p)->boollistfield);
  }
  if ((*self_p)->intlistfield != NULL)
  {
    mal_integer_list_destroy(& (*self_p)->intlistfield);
  }
  if ((*self_p)->stringlistfield != NULL)
  {
    mal_string_list_destroy(& (*self_p)->stringlistfield);
  }
  if ((*self_p)->bloblistfield != NULL)
  {
    mal_blob_list_destroy(& (*self_p)->bloblistfield);
  }
  if ((*self_p)->enumlistfield != NULL)
  {
    testarea_testenumeration_list_destroy(& (*self_p)->enumlistfield);
  }
  if ((*self_p)->complistfield != NULL)
  {
    testarea_testservice_testcomposite_list_destroy(& (*self_p)->complistfield);
  }
  mal_attribute_destroy(&(*self_p)->attributefield, (*self_p)->attributefield_attribute_tag);
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void testarea_testservice_testfullcomposite_test(bool verbose)
{
  printf(" * TestArea:TestService:TestFullComposite: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
