#include "com.h"


// structure definition for composite com_archivesync_domainizedcomobjects
struct _com_archivesync_domainizedcomobjects_t {
  bool f_domain_is_present;
  mal_uinteger_t f_domain;
  com_archivesync_compactcomobject_list_t * f_compactcomobjects;
};

// fields accessors for composite com_archivesync_domainizedcomobjects
bool com_archivesync_domainizedcomobjects_domain_is_present(com_archivesync_domainizedcomobjects_t * self)
{
  return self->f_domain_is_present;
}
void com_archivesync_domainizedcomobjects_domain_set_present(com_archivesync_domainizedcomobjects_t * self, bool is_present)
{
  self->f_domain_is_present = is_present;
}
mal_uinteger_t com_archivesync_domainizedcomobjects_get_domain(com_archivesync_domainizedcomobjects_t * self)
{
  return self->f_domain;
}
void com_archivesync_domainizedcomobjects_set_domain(com_archivesync_domainizedcomobjects_t * self, mal_uinteger_t f_domain)
{
  self->f_domain = f_domain;
}
com_archivesync_compactcomobject_list_t * com_archivesync_domainizedcomobjects_get_compactcomobjects(com_archivesync_domainizedcomobjects_t * self)
{
  return self->f_compactcomobjects;
}
void com_archivesync_domainizedcomobjects_set_compactcomobjects(com_archivesync_domainizedcomobjects_t * self, com_archivesync_compactcomobject_list_t * f_compactcomobjects)
{
  self->f_compactcomobjects = f_compactcomobjects;
}

// default constructor
com_archivesync_domainizedcomobjects_t * com_archivesync_domainizedcomobjects_new(void)
{
  com_archivesync_domainizedcomobjects_t *self = (com_archivesync_domainizedcomobjects_t *) calloc(1, sizeof(com_archivesync_domainizedcomobjects_t));
  if (!self)
    return NULL;
  return self;
}

// encoding functions related to transport malbinary
int com_archivesync_domainizedcomobjects_add_encoding_length_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, self->f_domain_is_present, cursor);
  if (rc < 0)
    return rc;
  if (self->f_domain_is_present)
  {
    rc = mal_encoder_add_uinteger_encoding_length(encoder, self->f_domain, cursor);
    if (rc < 0)
      return rc;
  }
  rc = mal_encoder_add_presence_flag_encoding_length(encoder, (self->f_compactcomobjects != NULL), cursor);
  if (rc < 0)
    return rc;
  if ((self->f_compactcomobjects != NULL))
  {
    rc = com_archivesync_compactcomobject_list_add_encoding_length_malbinary(self->f_compactcomobjects, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_domainizedcomobjects_encode_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_encoder_t * encoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  presence_flag = self->f_domain_is_present;
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_encoder_encode_uinteger(encoder, cursor, self->f_domain);
    if (rc < 0)
      return rc;
  }
  presence_flag = (self->f_compactcomobjects != NULL);
  rc = mal_encoder_encode_presence_flag(encoder, cursor, presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = com_archivesync_compactcomobject_list_encode_malbinary(self->f_compactcomobjects, encoder, cursor);
    if (rc < 0)
      return rc;
  }
  return rc;
}
int com_archivesync_domainizedcomobjects_decode_malbinary(com_archivesync_domainizedcomobjects_t * self, mal_decoder_t * decoder, void * cursor)
{
  int rc = 0;
  bool presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    rc = mal_decoder_decode_uinteger(decoder, cursor, &self->f_domain);
    if (rc < 0)
      return rc;
  }
  self->f_domain_is_present = presence_flag;
  rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
  if (rc < 0)
    return rc;
  if (presence_flag)
  {
    self->f_compactcomobjects = com_archivesync_compactcomobject_list_new(0);
    if (self->f_compactcomobjects == NULL) return -1;
    rc = com_archivesync_compactcomobject_list_decode_malbinary(self->f_compactcomobjects, decoder, cursor);
    if (rc < 0)
      return rc;
  }
  else
  {
    self->f_compactcomobjects = NULL;
  }
  return rc;
}

// destructor
void com_archivesync_domainizedcomobjects_destroy(com_archivesync_domainizedcomobjects_t ** self_p)
{
  if ((*self_p)->f_compactcomobjects != NULL)
  {
    com_archivesync_compactcomobject_list_destroy(& (*self_p)->f_compactcomobjects);
  }
  free(*self_p);
  (*self_p) = NULL;
}

// test function
void com_archivesync_domainizedcomobjects_test(bool verbose)
{
  printf(" * COM:ArchiveSync:DomainizedCOMObjects: ");
  if (verbose)
    printf("\n");
  printf("OK\n");
}
