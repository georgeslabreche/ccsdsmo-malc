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

#include "maltcp.h"

struct _maltcp_header_t {
  unsigned char version;
  bool priority_flag;
  mal_uinteger_t priority;
  bool timestamp_flag;
  bool network_zone_flag;
  mal_identifier_t *network_zone;
  bool session_name_flag;
  mal_identifier_t *session_name;
  bool domain_flag;
  mal_identifier_list_t *domain;
  bool authentication_id_flag;
  mal_blob_t *authentication_id;
};

maltcp_header_t *maltcp_header_new(
	bool priority_flag, mal_uinteger_t priority,
    bool timestamp_flag, mal_identifier_t *network_zone,
    mal_identifier_t *session_name, mal_identifier_list_t *domain,
    mal_blob_t *authentication_id) {
  maltcp_header_t *self = (maltcp_header_t *) malloc(sizeof(maltcp_header_t));
  if (!self)
    return NULL;

  self->version = MALTCP_PROTOCOL_VERSION;

  self->priority_flag = priority_flag;
  if (self->priority_flag == false)
    self->priority = priority;  // User defined default value
  else
    self->priority = 0;         // MAL/TCP default value (see section 3.3.7.2-c)

  self->timestamp_flag = timestamp_flag;

  if (network_zone == NULL) {
    self->network_zone_flag = true;
    self->network_zone = "";            // MAL/TCP default value (see section 3.3.9.2-c)
  } else {
    self->network_zone_flag = false;
    self->network_zone = network_zone;  // User defined default value
  }

  if (session_name == NULL) {
    self->session_name_flag = true;
    self->session_name = "";            // MAL/TCP default value (see section 3.3.11.2-c)
  } else {
    self->session_name_flag = false;
    self->session_name = session_name;  // User defined default value
  }

  if (domain == NULL) {
    self->domain_flag = true;
    self->domain = mal_identifier_list_new(0);  // MAL/TCP default value (see section 3.3.8.2-c)
  } else {
    self->domain_flag = false;
    self->domain = domain;                      // User defined default value
  }

  if (authentication_id == NULL) {
    self->authentication_id_flag = true;
    self->authentication_id = mal_blob_new(0);    // MAL/TCP default value (see section 3.3.3.2-c)
  } else {
    self->authentication_id_flag = false;
    self->authentication_id = authentication_id;  // User defined default value
  }

  return self;
}

unsigned char maltcp_header_get_version(maltcp_header_t *self) {
  return self->version;
}

void maltcp_header_set_version(maltcp_header_t *self, unsigned char version) {
  self->version = version;
}

bool maltcp_header_get_priority_flag(maltcp_header_t *self) {
  return self->priority_flag;
}

void maltcp_header_set_priority_flag(maltcp_header_t *self,
bool priority_flag) {
  self->priority_flag = priority_flag;
}

bool maltcp_header_get_timestamp_flag(maltcp_header_t *self) {
  return self->timestamp_flag;
}

void maltcp_header_set_timestamp_flag(maltcp_header_t *self,
bool timestamp_flag) {
  self->timestamp_flag = timestamp_flag;
}

bool maltcp_header_get_network_zone_flag(maltcp_header_t *self) {
  return self->network_zone_flag;
}

void maltcp_header_set_network_zone_flag(maltcp_header_t *self,
bool network_zone_flag) {
  self->network_zone_flag = network_zone_flag;
}

bool maltcp_header_get_session_name_flag(maltcp_header_t *self) {
  return self->session_name_flag;
}

void maltcp_header_set_session_name_flag(maltcp_header_t *self,
bool session_name_flag) {
  self->session_name_flag = session_name_flag;
}

bool maltcp_header_get_domain_flag(maltcp_header_t *self) {
  return self->domain_flag;
}

void maltcp_header_set_domain_flag(maltcp_header_t *self,
bool domain_flag) {
  self->domain_flag = domain_flag;
}

bool maltcp_header_get_authentication_id_flag(maltcp_header_t *self) {
  return self->authentication_id_flag;
}

void maltcp_header_set_authentication_id_flag(maltcp_header_t *self,
bool authentication_id_flag) {
  self->authentication_id_flag = authentication_id_flag;
}

mal_blob_t *maltcp_header_get_authentication_id(maltcp_header_t *self) {
  return self->authentication_id;
}

void maltcp_header_set_authentication_id(maltcp_header_t *self,
    mal_blob_t *authentication_id) {
  self->authentication_id = authentication_id;
}

mal_uinteger_t maltcp_header_get_priority(maltcp_header_t *self) {
  return self->priority;
}

void maltcp_header_set_priority(maltcp_header_t *self, mal_uinteger_t priority) {
  self->priority = priority;
}

mal_identifier_list_t *maltcp_header_get_domain(maltcp_header_t *self) {
  return self->domain;
}

void maltcp_header_set_domain(maltcp_header_t *self, mal_identifier_list_t *domain) {
  self->domain = domain;
}

mal_identifier_t *maltcp_header_get_network_zone(maltcp_header_t *self) {
  return self->network_zone;
}

void maltcp_header_set_network_zone(maltcp_header_t *self,
    mal_identifier_t *network_zone) {
  self->network_zone = network_zone;
}

mal_identifier_t *maltcp_header_get_session_name(maltcp_header_t *self) {
  return self->session_name;
}

void maltcp_header_set_session_name(maltcp_header_t *self,
    mal_identifier_t *session_name) {
  self->session_name = session_name;
}

//  --------------------------------------------------------------------------
//  Selftest

void maltcp_header_test(bool verbose) {
  printf(" * maltcp header: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

