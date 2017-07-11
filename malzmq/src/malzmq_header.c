/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2017 CNES
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

#include "malzmq.h"

struct _malzmq_header_t {
  unsigned char version;
  malzmq_mapping_directory_t *mapping_directory;
  bool internal_broker;
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

malzmq_header_t *malzmq_header_new(malzmq_mapping_directory_t *mapping_directory,
    bool priority_flag, mal_uinteger_t priority,
    bool timestamp_flag, mal_identifier_t *network_zone,
    mal_identifier_t *session_name, mal_identifier_list_t *domain,
    mal_blob_t *authentication_id) {
  malzmq_header_t *self = (malzmq_header_t *) malloc(sizeof(malzmq_header_t));
  if (!self)
    return NULL;

  self->version = MALZMQ_PROTOCOL_VERSION;

  self->internal_broker = false;

  self->mapping_directory = mapping_directory;

  self->priority_flag = priority_flag;
  self->priority = priority;

  self->timestamp_flag = timestamp_flag;

  if (network_zone == NULL) {
    self->network_zone_flag = true;
  } else {
    self->network_zone_flag = false;
    self->network_zone = network_zone;
  }

  if (session_name == NULL) {
    self->session_name_flag = true;
  } else {
    self->session_name_flag = false;
    self->session_name = session_name;
  }

  if (domain == NULL) {
    self->domain_flag = true;
  } else {
    self->domain_flag = false;
    self->domain = domain;
  }

  if (authentication_id == NULL) {
    self->authentication_id_flag = true;
  } else {
    self->authentication_id_flag = false;
    self->authentication_id = authentication_id;
  }

  return self;
}

unsigned char malzmq_header_get_version(malzmq_header_t *self) {
  return self->version;
}

void malzmq_header_set_version(malzmq_header_t *self, unsigned char version) {
  self->version = version;
}


bool malzmq_header_is_internal_broker(malzmq_header_t *self) {
  return self->internal_broker;
}

void malzmq_header_enable_internal_broker(malzmq_header_t *self, bool internal_broker) {
  self->internal_broker = internal_broker;
}

malzmq_mapping_directory_t *malzmq_header_get_mapping_directory(malzmq_header_t *self) {
  return self->mapping_directory;
}

void malzmq_header_set_mapping_directory(malzmq_header_t *self, malzmq_mapping_directory_t *mapping_directory) {
  self->mapping_directory = mapping_directory;
}

bool malzmq_header_get_priority_flag(malzmq_header_t *self) {
  return self->priority_flag;
}

void malzmq_header_set_priority_flag(malzmq_header_t *self,
bool priority_flag) {
  self->priority_flag = priority_flag;
}

bool malzmq_header_get_timestamp_flag(malzmq_header_t *self) {
  return self->timestamp_flag;
}

void malzmq_header_set_timestamp_flag(malzmq_header_t *self,
bool timestamp_flag) {
  self->timestamp_flag = timestamp_flag;
}

bool malzmq_header_get_network_zone_flag(malzmq_header_t *self) {
  return self->network_zone_flag;
}

void malzmq_header_set_network_zone_flag(malzmq_header_t *self,
bool network_zone_flag) {
  self->network_zone_flag = network_zone_flag;
}

bool malzmq_header_get_session_name_flag(malzmq_header_t *self) {
  return self->session_name_flag;
}

void malzmq_header_set_session_name_flag(malzmq_header_t *self,
bool session_name_flag) {
  self->session_name_flag = session_name_flag;
}

bool malzmq_header_get_domain_flag(malzmq_header_t *self) {
  return self->domain_flag;
}

void malzmq_header_set_domain_flag(malzmq_header_t *self,
bool domain_flag) {
  self->domain_flag = domain_flag;
}

bool malzmq_header_get_authentication_id_flag(malzmq_header_t *self) {
  return self->authentication_id_flag;
}

void malzmq_header_set_authentication_id_flag(malzmq_header_t *self,
bool authentication_id_flag) {
  self->authentication_id_flag = authentication_id_flag;
}

mal_blob_t *malzmq_header_get_authentication_id(malzmq_header_t *self) {
  return self->authentication_id;
}

void malzmq_header_set_authentication_id(malzmq_header_t *self,
    mal_blob_t *authentication_id) {
  self->authentication_id = authentication_id;
}

mal_uinteger_t malzmq_header_get_priority(malzmq_header_t *self) {
  return self->priority;
}

void malzmq_header_set_priority(malzmq_header_t *self, mal_uinteger_t priority) {
  self->priority = priority;
}

mal_identifier_list_t *malzmq_header_get_domain(malzmq_header_t *self) {
  return self->domain;
}

void malzmq_header_set_domain(malzmq_header_t *self, mal_identifier_list_t *domain) {
  self->domain = domain;
}

mal_identifier_t *malzmq_header_get_network_zone(malzmq_header_t *self) {
  return self->network_zone;
}

void malzmq_header_set_network_zone(malzmq_header_t *self,
    mal_identifier_t *network_zone) {
  self->network_zone = network_zone;
}

mal_identifier_t *malzmq_header_get_session_name(malzmq_header_t *self) {
  return self->session_name;
}

void malzmq_header_set_session_name(malzmq_header_t *self,
    mal_identifier_t *session_name) {
  self->session_name = session_name;
}

//  --------------------------------------------------------------------------
//  Selftest

void malzmq_header_test(bool verbose) {
  printf(" * malzmq header: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}

