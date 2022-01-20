/*  =========================================================================
    nmf_api_util - a utils class for convenience

    The MIT License (MIT)
    =========================================================================
*/

#ifndef NMF_API_UTIL_H_INCLUDED
#define NMF_API_UTIL_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_PORT_INCREMENTS         100 // The maximum number of port number increments to find an available port


//  If the given port is not available then increment its number until an available one is found
int
nmfapi_util_set_available_port(char *hostname, char *port);

//  Create a URI string
mal_uri_t *
nmfapi_util_create_uri(const char* protocol, const char *hostname, const char *port, const char *id);

//  Create a mal message for a request transaction
mal_message_t *
nmfapi_util_create_mal_message(mal_encoder_t *encoder, void *cursor);

//  Destroy a MAL message
void
nmfapi_util_destroy_mal_message(mal_message_t *message, mal_ctx_t *mal_ctx);

//  Initialize a MAL Attribute given the raw value and attribute tag
int
nmfapi_util_init_mal_attribute(char *rawvalue, unsigned char tag, union mal_attribute_t *attribute);

#ifdef __cplusplus
}
#endif

#endif
