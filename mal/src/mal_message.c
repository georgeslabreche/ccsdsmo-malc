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

struct _mal_message_t {
  mal_uri_t *uri_from;
  mal_blob_t *authentication_id;
  mal_uri_t *uri_to;
  mal_uoctet_t encoding_id;
  mal_time_t timestamp;
  mal_qoslevel_t qoslevel;
  mal_uinteger_t priority;
  mal_identifier_list_t *domain;
  mal_identifier_t *network_zone;
  mal_sessiontype_t session;
  mal_identifier_t *session_name;
  mal_interactiontype_t interaction_type;
  mal_uoctet_t interaction_stage;
  mal_long_t transaction_id;
  mal_ushort_t service_area;
  mal_ushort_t service;
  mal_ushort_t operation;
  mal_uoctet_t area_version;
  mal_boolean_t is_error_message;
  // flags stating whether destroy frees the header fields or not
  bool free_uri_from;
  bool free_authentication_id;
  bool free_uri_to;
  bool free_domain;
  bool free_network_zone;
  bool free_session_name;
  // TODO: currently assumes that the body is not segmented
  unsigned int body_offset;
  unsigned int body_length;
  char *body;
  // Owner of the body (e.g. a ZMQ frame), may be NULL
  void *body_owner;
};

clog_logger_t logger = CLOG_WARN_LEVEL;

mal_message_t *mal_message_new_void(void) {
  mal_message_t *self = (mal_message_t *) calloc(1, sizeof(mal_message_t));
  if (!self)
    return NULL;
  return self;
}

mal_message_t *mal_message_new(mal_blob_t *authentication_id,
    mal_qoslevel_t qoslevel, mal_uinteger_t priority,
    mal_identifier_list_t *domain, mal_identifier_t *network_zone,
    mal_sessiontype_t session, mal_identifier_t *session_name,
    unsigned int body_length) {
  mal_message_t *self = mal_message_new_void();

  self->authentication_id = authentication_id;
  self->qoslevel = qoslevel;
  self->priority = priority;
  self->domain = domain;
  self->network_zone = network_zone;
  self->session = session;
  self->session_name = session_name;

  // Destroy does not free the header fields
  self->free_uri_from = false;
  self->free_authentication_id = false;
  self->free_uri_to = false;
  self->free_domain = false;
  self->free_network_zone = false;
  self->free_session_name = false;

  self->body_owner = NULL;

  self->body_offset = 0;
  self->body_length = body_length;
  if (self->body_length > 0)
    self->body = (char *) calloc(1, body_length);
  else
    self->body = NULL;

  self->timestamp = 0L;

  return self;
}

void mal_message_destroy(mal_message_t **self_p, mal_ctx_t *mal_ctx) {
  if (self_p && *self_p) {
    mal_message_t *self = *self_p;

    if (self->free_uri_to) {
      mal_uri_destroy(&self->uri_to);
    }

    if (self->free_authentication_id) {
      mal_blob_destroy(&self->authentication_id);
    }

    if (self->free_uri_from) {
      mal_uri_destroy(&self->uri_from);
    }

    if (self->free_domain) {
      mal_identifier_list_destroy(&self->domain);
    }

    if (self->free_network_zone) {
      mal_identifier_destroy(&self->network_zone);
    }

    if (self->free_session_name) {
      mal_identifier_destroy(&self->session_name);
    }

    // If there is no body owner, free directly the body
    if (self->body_owner == NULL) {
      if (self->body_length > 0)
        free(self->body - self->body_offset);
    } else {
      mal_ctx_destroy_message(mal_ctx, self);
    }

    free(self);

    *self_p = NULL;
  }
}

mal_uoctet_t mal_message_get_encoding_id(mal_message_t *self) {
  return self->encoding_id;
}

void mal_message_set_encoding_id(mal_message_t *self,
    mal_uoctet_t encoding_id) {
  self->encoding_id = encoding_id;
}

mal_ushort_t mal_message_get_service_area(mal_message_t *self) {
  return self->service_area;
}

void mal_message_set_service_area(mal_message_t *self,
    mal_ushort_t service_area) {
  self->service_area = service_area;
}

mal_uoctet_t mal_message_get_area_version(mal_message_t *self) {
  return self->area_version;
}

void mal_message_set_area_version(mal_message_t *self,
    mal_uoctet_t area_version) {
  self->area_version = area_version;
}

mal_ushort_t mal_message_get_service(mal_message_t *self) {
  return self->service;
}

void mal_message_set_service(mal_message_t *self, mal_ushort_t service) {
  self->service = service;
}

mal_ushort_t mal_message_get_operation(mal_message_t *self) {
  return self->operation;
}

void mal_message_set_operation(mal_message_t *self, mal_ushort_t operation) {
  self->operation = operation;
}

mal_blob_t *mal_message_get_authentication_id(mal_message_t *self) {
  return self->authentication_id;
}

void mal_message_set_authentication_id(mal_message_t *self,
    mal_blob_t *authentication_id) {
  self->authentication_id = authentication_id;
}

mal_uinteger_t mal_message_get_priority(mal_message_t *self) {
  return self->priority;
}

void mal_message_set_priority(mal_message_t *self, mal_uinteger_t priority) {
  self->priority = priority;
}

mal_identifier_list_t *mal_message_get_domain(mal_message_t *self) {
  return self->domain;
}

void mal_message_set_domain(mal_message_t *self, mal_identifier_list_t *domain) {
  self->domain = domain;
}

mal_identifier_t *mal_message_get_network_zone(mal_message_t *self) {
  return self->network_zone;
}

void mal_message_set_network_zone(mal_message_t *self,
    mal_identifier_t *network_zone) {
  self->network_zone = network_zone;
}

mal_identifier_t *mal_message_get_session_name(mal_message_t *self) {
  return self->session_name;
}

void mal_message_set_session_name(mal_message_t *self,
    mal_identifier_t *session_name) {
  self->session_name = session_name;
}

void *mal_message_get_body_owner(mal_message_t *self) {
  return self->body_owner;
}

void mal_message_set_body_owner(mal_message_t *self, void *body_owner) {
  self->body_owner = body_owner;
}

void mal_message_init(mal_message_t *self, mal_ushort_t service_area,
    mal_uoctet_t area_version, mal_ushort_t service, mal_ushort_t operation,
    mal_interactiontype_t interaction_type, mal_uoctet_t interaction_stage) {
  self->service_area = service_area;
  self->area_version = area_version;
  self->service = service;
  self->operation = operation;
  self->interaction_type = interaction_type;
  self->interaction_stage = interaction_stage;
}

mal_uri_t *mal_message_get_uri_from(mal_message_t *self) {
  return self->uri_from;
}

void mal_message_set_uri_from(mal_message_t *self, mal_uri_t *uri_from) {
  self->uri_from = uri_from;
}

mal_uri_t * mal_message_get_uri_to(mal_message_t *self) {
  return self->uri_to;
}

void mal_message_set_uri_to(mal_message_t *self, mal_uri_t *uri_to) {
  self->uri_to = uri_to;
}

long mal_message_get_transaction_id(mal_message_t *self) {
  return self->transaction_id;
}

void mal_message_set_transaction_id(mal_message_t *self, long transaction_id) {
  self->transaction_id = transaction_id;
}

mal_interactiontype_t mal_message_get_interaction_type(mal_message_t *self) {
  return self->interaction_type;
}

void mal_message_set_interaction_type(mal_message_t *self,
    mal_interactiontype_t interaction_type) {
  self->interaction_type = interaction_type;
}

mal_uoctet_t mal_message_get_interaction_stage(mal_message_t *self) {
  return self->interaction_stage;
}

void mal_message_set_interaction_stage(mal_message_t *self,
    mal_uoctet_t interaction_stage) {
  self->interaction_stage = interaction_stage;
}

bool mal_message_is_error_message(mal_message_t *self) {
  return self->is_error_message;
}

void mal_message_set_is_error_message(mal_message_t *self,
bool is_error_message) {
  self->is_error_message = is_error_message;
}

mal_qoslevel_t mal_message_get_qoslevel(mal_message_t *self) {
  return self->qoslevel;
}

void mal_message_set_qoslevel(mal_message_t *self, mal_qoslevel_t qoslevel) {
  self->qoslevel = qoslevel;
}

mal_sessiontype_t mal_message_get_session(mal_message_t *self) {
  return self->session;
}

void mal_message_set_session(mal_message_t *self, mal_sessiontype_t session) {
  self->session = session;
}

mal_time_t mal_message_get_timestamp(mal_message_t *self) {
  return self->timestamp;
}

void mal_message_set_timestamp(mal_message_t *self, mal_time_t timestamp) {
  self->timestamp = timestamp;
}

bool mal_message_is_free_uri_from(mal_message_t *self) {
  return self->free_uri_from;
}

void mal_message_set_free_uri_from(mal_message_t *self,
bool free_uri_from) {
  self->free_uri_from = free_uri_from;
}

bool mal_message_is_free_authentication_id(mal_message_t *self) {
  return self->free_authentication_id;
}

void mal_message_set_free_authentication_id(mal_message_t *self,
bool free_authentication_id) {
  self->free_authentication_id = free_authentication_id;
}

bool mal_message_is_free_uri_to(mal_message_t *self) {
  return self->free_uri_to;
}

void mal_message_set_free_uri_to(mal_message_t *self,
bool free_uri_to) {
  self->free_uri_to = free_uri_to;
}

bool mal_message_is_free_domain(mal_message_t *self) {
  return self->free_domain;
}

void mal_message_set_free_domain(mal_message_t *self,
bool free_domain) {
  self->free_domain = free_domain;
}

bool mal_message_is_free_network_zone(mal_message_t *self) {
  return self->free_network_zone;
}

void mal_message_set_free_network_zone(mal_message_t *self,
bool free_network_zone) {
  self->free_network_zone = free_network_zone;
}

bool mal_message_is_free_session_name(mal_message_t *self) {
  return self->free_session_name;
}

void mal_message_set_free_session_name(mal_message_t *self,
bool free_session_name) {
  self->free_session_name = free_session_name;
}

char *mal_message_get_body(mal_message_t *self) {
  if (self->body_length <= 0)
    return NULL;
  return self->body;
}

void mal_message_set_body(mal_message_t *self, char *body) {
  self->body = body;
}

unsigned int mal_message_get_body_offset(mal_message_t *self) {
  return self->body_offset;
}

void mal_message_set_body_offset(mal_message_t *self, unsigned int body_offset) {
  self->body_offset = body_offset;
}

unsigned int mal_message_get_body_length(mal_message_t *self) {
  return self->body_length;
}

void mal_message_set_body_length(mal_message_t *self, unsigned int body_length) {
  self->body_length = body_length;
}

void mal_message_set_log_level(int level) {
  logger = level;
}

void mal_message_print(mal_message_t *self) {
  if (self) {
    clog_debug_no_header(logger, "mal_message(");
    if (self->uri_from)
      clog_debug_no_header(logger, "uri_from=%s", self->uri_from);
    clog_debug_no_header(logger, ",authentication_id=");
    if (self->authentication_id)
      mal_blob_print(self->authentication_id);
    if (self->uri_to)
      clog_debug_no_header(logger, ",uri_to=%s", self->uri_to);
    clog_debug_no_header(logger, ",timestamp=%lu", self->timestamp);
    clog_debug_no_header(logger, ",qoslevel=%d", self->qoslevel);
    clog_debug_no_header(logger, ",priority=%d", self->priority);
    clog_debug_no_header(logger, ",domain=");
    if (self->domain)
      mal_identifier_list_print(self->domain);
    if (self->network_zone)
      clog_debug_no_header(logger, ",network_zone=%s", self->network_zone);
    clog_debug_no_header(logger, ",session=%d", self->session);
    if (self->session_name)
      clog_debug_no_header(logger, ",session_name=%s", self->session_name);
    clog_debug_no_header(logger, ",interaction_type=%d", self->interaction_type);
    clog_debug_no_header(logger, ",interaction_stage=%d", self->interaction_stage);
    clog_debug_no_header(logger, ",transaction_id=%lu", self->transaction_id);
    clog_debug_no_header(logger, ",service_area=%d", self->service_area);
    clog_debug_no_header(logger, ",service=%d", self->service);
    clog_debug_no_header(logger, ",operation=%d", self->operation);
    clog_debug_no_header(logger, ",area_version=%d", self->area_version);
    clog_debug_no_header(logger, ",is_error_message=%d", self->is_error_message);
    clog_debug_no_header(logger, ",body_offset=%d", self->body_offset);
    clog_debug_no_header(logger, ",body_length=%d)", self->body_length);
  } else {
    clog_debug_no_header(logger, "NULL");
  }
}

void mal_message_test(bool verbose) {
  printf(" * mal_message: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

