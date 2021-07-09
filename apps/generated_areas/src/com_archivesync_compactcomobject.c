#include "com.h"


// structure definition for composite com_archivesync_compactcomobject
struct _com_archivesync_compactcomobject_t {
  bool f_network_is_present;
  mal_uinteger_t f_network;
  bool f_provideruri_is_present;
  mal_uinteger_t f_provideruri;
  mal_long_t f_objecttype;
  bool f_sourcelinkdomainid_is_present;
  mal_uinteger_t f_sourcelinkdomainid;
  bool f_sourcelinkobjecttype_is_present;
  mal_long_t f_sourcelinkobjecttype;
  bool f_sourcelinkobjid_is_present;
  mal_long_t f_sourcelinkobjid;
  bool f_relatedlink_is_present;
  mal_long_t f_relatedlink;
  mal_blob_t * f_objectbody;
  mal_long_t f_objid;
  mal_finetime_t f_timestamp;
};

// fields accessors for composite com_archivesync_compactcomobject
bool com_archivesync_compactcomobject_network_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_network_is_present;
}
void com_archivesync_compactcomobject_network_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_network_is_present = is_present;
}
mal_uinteger_t com_archivesync_compactcomobject_get_network(com_archivesync_compactcomobject_t * self)
{
  return self->f_network;
}
void com_archivesync_compactcomobject_set_network(com_archivesync_compactcomobject_t * self, mal_uinteger_t f_network)
{
  self->f_network = f_network;
}
bool com_archivesync_compactcomobject_provideruri_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_provideruri_is_present;
}
void com_archivesync_compactcomobject_provideruri_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_provideruri_is_present = is_present;
}
mal_uinteger_t com_archivesync_compactcomobject_get_provideruri(com_archivesync_compactcomobject_t * self)
{
  return self->f_provideruri;
}
void com_archivesync_compactcomobject_set_provideruri(com_archivesync_compactcomobject_t * self, mal_uinteger_t f_provideruri)
{
  self->f_provideruri = f_provideruri;
}
mal_long_t com_archivesync_compactcomobject_get_objecttype(com_archivesync_compactcomobject_t * self)
{
  return self->f_objecttype;
}
void com_archivesync_compactcomobject_set_objecttype(com_archivesync_compactcomobject_t * self, mal_long_t f_objecttype)
{
  self->f_objecttype = f_objecttype;
}
bool com_archivesync_compactcomobject_sourcelinkdomainid_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkdomainid_is_present;
}
void com_archivesync_compactcomobject_sourcelinkdomainid_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_sourcelinkdomainid_is_present = is_present;
}
mal_uinteger_t com_archivesync_compactcomobject_get_sourcelinkdomainid(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkdomainid;
}
void com_archivesync_compactcomobject_set_sourcelinkdomainid(com_archivesync_compactcomobject_t * self, mal_uinteger_t f_sourcelinkdomainid)
{
  self->f_sourcelinkdomainid = f_sourcelinkdomainid;
}
bool com_archivesync_compactcomobject_sourcelinkobjecttype_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkobjecttype_is_present;
}
void com_archivesync_compactcomobject_sourcelinkobjecttype_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_sourcelinkobjecttype_is_present = is_present;
}
mal_long_t com_archivesync_compactcomobject_get_sourcelinkobjecttype(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkobjecttype;
}
void com_archivesync_compactcomobject_set_sourcelinkobjecttype(com_archivesync_compactcomobject_t * self, mal_long_t f_sourcelinkobjecttype)
{
  self->f_sourcelinkobjecttype = f_sourcelinkobjecttype;
}
bool com_archivesync_compactcomobject_sourcelinkobjid_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkobjid_is_present;
}
void com_archivesync_compactcomobject_sourcelinkobjid_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_sourcelinkobjid_is_present = is_present;
}
mal_long_t com_archivesync_compactcomobject_get_sourcelinkobjid(com_archivesync_compactcomobject_t * self)
{
  return self->f_sourcelinkobjid;
}
void com_archivesync_compactcomobject_set_sourcelinkobjid(com_archivesync_compactcomobject_t * self, mal_long_t f_sourcelinkobjid)
{
  self->f_sourcelinkobjid = f_sourcelinkobjid;
}
bool com_archivesync_compactcomobject_relatedlink_is_present(com_archivesync_compactcomobject_t * self)
{
  return self->f_relatedlink_is_present;
}
void com_archivesync_compactcomobject_relatedlink_set_present(com_archivesync_compactcomobject_t * self, bool is_present)
{
  self->f_relatedlink_is_present = is_present;
}
mal_long_t com_archivesync_compactcomobject_get_relatedlink(com_archivesync_compactcomobject_t * self)
{
  return self->f_relatedlink;
}
void com_archivesync_compactcomobject_set_relatedlink(com_archivesync_compactcomobject_t * self, mal_long_t f_relatedlink)
{
  self->f_relatedlink = f_relatedlink;
}
mal_blob_t * com_archivesync_compactcomobject_get_objectbody(com_archivesync_compactcomobject_t * self)
{
  return self->f_objectbody;
}
void com_archivesync_compactcomobject_set_objectbody(com_archivesync_compactcomobject_t * self, mal_blob_t * f_objectbody)
{
  self->f_objectbody = f_objectbody;
}
mal_long_t com_archivesync_compactcomobject_get_objid(com_archivesync_compactcomobject_t * self)
{
  return self->f_objid;
}
void com_archivesync_compactcomobject_set_objid(com_archivesync_compactcomobject_t * self, mal_long_t f_objid)
{
  self->f_objid = f_objid;
}
mal_finetime_t com_archivesync_compactcomobject_get_timestamp(com_archivesync_compactcomobject_t * self)
{
  return self->f_timestamp;
}
void com_archivesync_compactcomobject_set_timestamp(com_archivesync_compactcomobject_t * self, mal_finetime_t f_timestamp)
{
  self->f_timestamp = f_timestamp;
}

// default constructor
com_archivesync_compactcomobject_t * com_archivesync_compactcomobject_new(void)
{
  com_archivesync_compactcomobject_t *self = (com_archivesync_compactcomobject_t *) calloc(1, sizeof(com_archivesync_compactcomobject_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archivesync_compactcomobject_add_encoding_length_malbinary(com_archivesync_compactcomobject_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_network_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_network_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_network, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_provideruri_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_provideruri_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_provideruri, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_objecttype, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_sourcelinkdomainid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_sourcelinkdomainid_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_sourcelinkdomainid, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_sourcelinkobjecttype_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_sourcelinkobjecttype_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_sourcelinkobjecttype, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_sourcelinkobjid_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_sourcelinkobjid_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_sourcelinkobjid, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_relatedlink_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_relatedlink_is_present)
  {
    rc = mal_encoder_add_long_encoding_length(encoder, self->f_relatedlink, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_objectbody != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_objectbody != NULL))
  {
    rc = mal_encoder_add_blob_encoding_length(encoder, self->f_objectbody, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_long_encoding_length(encoder, self->f_objid, cursor);
  if (rc < 0)
    return rc;
  rc = mal_encoder_add_finetime_encoding_length(encoder, self->f_timestamp, cursor);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archivesync_compactcomobject_encode_malbinary(com_archivesync_compactcomobject_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_network_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_network);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_provideruri_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_provideruri);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_long(encoder, cursor, self->f_objecttype);
  if (rc < 0)
    return rc;
  presence_flag = self->f_sourcelinkdomainid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_sourcelinkdomainid);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_sourcelinkobjecttype_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_sourcelinkobjecttype);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_sourcelinkobjid_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_sourcelinkobjid);
    if (rc < 0)
      return rc;
  }
  presence_flag = self->f_relatedlink_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_long(encoder, cursor, self->f_relatedlink);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_objectbody != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_blob(encoder, cursor, self->f_objectbody);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_encode_long(encoder, cursor, self->f_objid);
  if (rc < 0)
    return rc;
  rc = mal_encoder_encode_finetime(encoder, cursor, self->f_timestamp);
  if (rc < 0)
    return rc;
  return rc;
}
int com_archivesync_compactcomobject_decode_malbinary(com_archivesync_compactcomobject_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_network);
    if (rc < 0)
      return rc;
  }
  self->f_network_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_provideruri);
    if (rc < 0)
      return rc;
  }
  self->f_provideruri_is_present = presence_flag;
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_objecttype);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_sourcelinkdomainid);
    if (rc < 0)
      return rc;
  }
  self->f_sourcelinkdomainid_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_sourcelinkobjecttype);
    if (rc < 0)
      return rc;
  }
  self->f_sourcelinkobjecttype_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_sourcelinkobjid);
    if (rc < 0)
      return rc;
  }
  self->f_sourcelinkobjid_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_long(decoder, cursor, &self->f_relatedlink);
    if (rc < 0)
      return rc;
  }
  self->f_relatedlink_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_blob(decoder, cursor, &self->f_objectbody);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_objectbody = NULL;
  }
  rc = mal_decoder_decode_long(decoder, cursor, &self->f_objid);
  if (rc < 0)
    return rc;
  rc = mal_decoder_decode_finetime(decoder, cursor, &self->f_timestamp);
  if (rc < 0)
    return rc;
  return rc;
}

// destructor
void com_archivesync_compactcomobject_destroy(com_archivesync_compactcomobject_t ** self_p)
{
  if ((*self_p)->f_objectbody != NULL)
  {
    mal_blob_destroy(& (*self_p)->f_objectbody);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archivesync_compactcomobject_test(bool verbose)
{
  printf(" * COM:ArchiveSync:CompactCOMObject: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
