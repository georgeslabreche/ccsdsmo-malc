/*  =========================================================================
    nmf_api_util - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api_util -
@discuss
@end
*/

#include "nmfapi_classes.h"

mal_uri_t *
nmfapi_util_create_uri(const char* protocol, char *hostname, char *port, char *id)
{
    // Calculate length of URI
    size_t uri_length = strlen(protocol);

    if (hostname) 
    {
        uri_length += strlen(hostname);
    }
  
    if (port)
    {
        // +1 for the ":" between the hostname and the port
        uri_length += strlen(port) + 1; 
    }

    if (id) 
    {
        // +1 for the "/" between the port and the id
        uri_length += strlen(id) + 1;
    }

    // Crate string variable for URI
    char *uri = (char *) malloc(uri_length + 1);
  
    // Need to set the final '\0' before using strcat
    uri[0] = '\0';
  
    // Build the URI string
    if (uri) 
    {
        strcat(uri, MALTCP_URI);
        if (hostname) 
        {
            strcat(uri, hostname);
        }
        if (port) 
        {
            strcat(uri, ":");
            strcat(uri, port);
        }
        if (id)
        {
            strcat(uri, "/");
            strcat(uri, id);
        }
    }

    return uri;
}


mal_message_t *
nmfapi_util_create_mal_message_request(mal_encoder_t *encoder, void *cursor)
{
    mal_blob_t *authentication_id = mal_blob_new(0);
    mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
    mal_uinteger_t priority = 4;
    mal_identifier_list_t *domain = mal_identifier_list_new(0);
    mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
    mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
    mal_identifier_t *session_name = mal_identifier_new("LIVE");
    

    mal_message_t *message = mal_message_new(authentication_id, qoslevel,
        priority, domain, network_zone, session, session_name,
        mal_encoder_cursor_get_length(encoder, cursor));

    return message;
}

