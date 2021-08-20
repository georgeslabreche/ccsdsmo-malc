/*  =========================================================================
    nmf_api_util - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef NMF_API_UTIL_H_INCLUDED
#define NMF_API_UTIL_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

// Create a URI string
mal_uri_t *nmfapi_util_create_uri(const char* protocol, char *hostname, char *port, char *id);

// Create a mal message for a request transaction
mal_message_t *nmfapi_util_create_mal_message_request(mal_encoder_t *encoder, void *cursor);

#ifdef __cplusplus
}
#endif

#endif
