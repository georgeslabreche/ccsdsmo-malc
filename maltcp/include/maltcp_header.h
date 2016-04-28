#ifndef __MALTCP_HEADER_H_INCLUDED__
#define __MALTCP_HEADER_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

typedef int maltcp_md_get_key_fn(char *string, unsigned int *key);
typedef int maltcp_md_get_string_fn(unsigned int key, char **string);
typedef int maltcp_md_put_string_fn(char *string, unsigned int *key);
typedef struct _maltcp_mapping_directory_t maltcp_mapping_directory_t;
struct _maltcp_mapping_directory_t {
  maltcp_md_get_key_fn *get_key_fn;
  maltcp_md_get_string_fn *get_string_fn;
  maltcp_md_put_string_fn *put_string_fn;
};

maltcp_header_t *maltcp_header_new(maltcp_mapping_directory_t *mapping_directory,
	bool priority_flag, mal_uinteger_t priority,
    bool timestamp_flag, mal_identifier_t *network_zone,
    mal_identifier_t *session_name, mal_identifier_list_t *domain,
    mal_blob_t *authentication_id);

unsigned char maltcp_header_get_version(maltcp_header_t *self);

void maltcp_header_set_version(maltcp_header_t *self, unsigned char version);

maltcp_mapping_directory_t *maltcp_header_get_mapping_directory(maltcp_header_t *self);

void maltcp_header_set_mapping_directory(maltcp_header_t *self,
	maltcp_mapping_directory_t *mapping_directory);

bool maltcp_header_get_priority_flag(maltcp_header_t *self);

void maltcp_header_set_priority_flag(maltcp_header_t *self, bool priority_flag);

bool maltcp_header_get_timestamp_flag(maltcp_header_t *self);

void maltcp_header_set_timestamp_flag(maltcp_header_t *self,
    bool timestamp_flag);

bool maltcp_header_get_network_zone_flag(maltcp_header_t *self);

void maltcp_header_set_network_zone_flag(maltcp_header_t *self,
    bool network_zone_flag);

bool maltcp_header_get_session_name_flag(maltcp_header_t *self);

void maltcp_header_set_session_name_flag(maltcp_header_t *self,
    bool session_name_flag);

bool maltcp_header_get_domain_flag(maltcp_header_t *self);

void maltcp_header_set_domain_flag(maltcp_header_t *self, bool domain_flag);

bool maltcp_header_get_authentication_id_flag(maltcp_header_t *self);

void maltcp_header_set_authentication_id_flag(maltcp_header_t *self,
    bool authentication_id_flag);

mal_blob_t *maltcp_header_get_authentication_id(maltcp_header_t *self);

void maltcp_header_set_authentication_id(maltcp_header_t *self,
    mal_blob_t *authentication_id);

mal_uinteger_t maltcp_header_get_priority(maltcp_header_t *self);

void maltcp_header_set_priority(maltcp_header_t *self, mal_uinteger_t priority);

mal_identifier_list_t *maltcp_header_get_domain(maltcp_header_t *self);

void maltcp_header_set_domain(maltcp_header_t *self,
    mal_identifier_list_t *domain);

mal_identifier_t *maltcp_header_get_network_zone(maltcp_header_t *self);

void maltcp_header_set_network_zone(maltcp_header_t *self,
    mal_identifier_t *network_zone);

mal_identifier_t *maltcp_header_get_session_name(maltcp_header_t *self);

void maltcp_header_set_session_name(maltcp_header_t *self,
    mal_identifier_t *session_name);

void maltcp_header_test(bool verbose);

#ifdef __cplusplus
}
#endif

#endif
