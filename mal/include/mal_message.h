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

#ifndef __MAL_MESSAGE_H_INCLUDED__
#define __MAL_MESSAGE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

// used for decoding
mal_message_t *mal_message_new_void(void);

mal_message_t *mal_message_new(mal_blob_t *authentication_id,
    mal_qoslevel_t qoslevel, mal_uinteger_t priority,
    mal_identifier_list_t *domain, mal_identifier_t *network_zone,
    mal_sessiontype_t session, mal_identifier_t *session_name,
    unsigned int body_length);

void mal_message_destroy(mal_message_t **self_p, mal_ctx_t *mal_ctx);

mal_uoctet_t mal_message_get_encoding_id(mal_message_t *self);

void mal_message_set_encoding_id(mal_message_t *self,
    mal_uoctet_t encoding_id);

mal_ushort_t mal_message_get_service_area(mal_message_t *self);

void mal_message_set_service_area(mal_message_t *self,
    mal_ushort_t service_area);

mal_uoctet_t mal_message_get_area_version(mal_message_t *self);

void mal_message_set_area_version(mal_message_t *self,
    mal_uoctet_t area_version);

mal_ushort_t mal_message_get_service(mal_message_t *self);

void mal_message_set_service(mal_message_t *self, mal_ushort_t service);

mal_ushort_t mal_message_get_operation(mal_message_t *self);

void mal_message_set_operation(mal_message_t *self, mal_ushort_t operation);

mal_interactiontype_t mal_message_get_interaction_type(mal_message_t *self);

void mal_message_set_interaction_type(mal_message_t *self,
    mal_interactiontype_t interaction_type);

mal_uoctet_t mal_message_get_interaction_stage(mal_message_t *self);

void mal_message_set_interaction_stage(mal_message_t *self,
    mal_uoctet_t interaction_stage);

bool mal_message_is_error_message(mal_message_t *self);

void mal_message_set_is_error_message(mal_message_t *self,
    bool is_error_message);

unsigned int mal_message_get_body_length(mal_message_t *self);

void mal_message_set_body_length(mal_message_t *self, unsigned int body_length);

unsigned int mal_message_get_body_offset(mal_message_t *self);

void mal_message_set_body_offset(mal_message_t *self, unsigned int body_offset);

char *mal_message_get_body(mal_message_t *self);

void mal_message_set_body(mal_message_t *self, char *body);

mal_blob_t *mal_message_get_authentication_id(mal_message_t *self);

void mal_message_set_authentication_id(mal_message_t *self,
    mal_blob_t *authentication_id);

mal_uinteger_t mal_message_get_priority(mal_message_t *self);

void mal_message_set_priority(mal_message_t *self, mal_uinteger_t priority);

mal_identifier_list_t *mal_message_get_domain(mal_message_t *self);

void mal_message_set_domain(mal_message_t *self, mal_identifier_list_t *domain);

mal_identifier_t *mal_message_get_network_zone(mal_message_t *self);

void mal_message_set_network_zone(mal_message_t *self,
    mal_identifier_t *network_zone);

mal_sessiontype_t mal_message_get_session(mal_message_t *self);

void mal_message_set_session(mal_message_t *self, mal_sessiontype_t session);

mal_identifier_t *mal_message_get_session_name(mal_message_t *self);

void mal_message_set_session_name(mal_message_t *self,
    mal_identifier_t *session_name);

void mal_message_init(mal_message_t *self, mal_ushort_t service_area,
    mal_uoctet_t area_version, mal_ushort_t service, mal_ushort_t operation,
    mal_interactiontype_t interaction_type, mal_uoctet_t interaction_stage);

mal_uri_t *mal_message_get_uri_from(mal_message_t *self);

void mal_message_set_uri_from(mal_message_t *self, mal_uri_t *uri_from);

mal_uri_t *mal_message_get_uri_to(mal_message_t *self);

void mal_message_set_uri_to(mal_message_t *self, mal_uri_t *uri_to);

long mal_message_get_transaction_id(mal_message_t *self);

void mal_message_set_transaction_id(mal_message_t *self, long transaction_id);

mal_time_t mal_message_get_timestamp(mal_message_t *self);

void mal_message_set_timestamp(mal_message_t *self, mal_time_t timestamp);

mal_qoslevel_t mal_message_get_qoslevel(mal_message_t *self);

void mal_message_set_qoslevel(mal_message_t *self, mal_qoslevel_t qoslevel);

bool mal_message_is_free_uri_from(mal_message_t *self);

void mal_message_set_free_uri_from(mal_message_t *self,
bool free_uri_from);

bool mal_message_is_free_authentication_id(mal_message_t *self);

void mal_message_set_free_authentication_id(mal_message_t *self,
bool free_authentication_id);

bool mal_message_is_free_uri_to(mal_message_t *self);

void mal_message_set_free_uri_to(mal_message_t *self,
bool free_uri_to);

bool mal_message_is_free_domain(mal_message_t *self);

void mal_message_set_free_domain(mal_message_t *self,
bool free_domain);

bool mal_message_is_free_network_zone(mal_message_t *self);

void mal_message_set_free_network_zone(mal_message_t *self,
bool free_network_zone);

bool mal_message_is_free_session_name(mal_message_t *self);

void mal_message_set_free_session_name(mal_message_t *self,
bool free_session_name);

void *mal_message_get_body_owner(mal_message_t *self);

void mal_message_set_body_owner(mal_message_t *self, void *body_owner);

int mal_message_add_encoding_length_malbinary(mal_message_t *self,
    mal_encoder_t *encoder, unsigned int *encoding_length);

int mal_message_encode_malbinary(mal_message_t *self,
    mal_encoder_t *encoder, char *bytes, unsigned int *offset);

int mal_message_decode_malbinary(mal_message_t *self,
    mal_decoder_t *decoder, char *bytes, unsigned int *offset,
    unsigned int length);

void mal_message_print(mal_message_t *self);

//  Self test of this class
void mal_message_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
