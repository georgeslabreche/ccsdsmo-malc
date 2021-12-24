/*  =========================================================================
    nmf_api_util - A utils class for convenience

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api_util -
@discuss
@end
*/

#include "nmfapi_c_classes.h"

mal_uri_t *
nmfapi_util_create_uri(const char* protocol, const char *hostname, const char *port, const char *id)
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
nmfapi_util_create_mal_message(mal_encoder_t *encoder, void *cursor)
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


int
nmfapi_util_init_maltcp_ctx(char *hostname, char *port, mal_ctx_t **mal_ctx)
{
    // Create context
    *mal_ctx = mal_ctx_new();

    // Create mal tcp header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = NULL;
    maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);
    
    // Create the consumer listening socket: bind to server with the consumer port number
    maltcp_ctx_t *maltcp_ctx = NULL;
    maltcp_ctx = maltcp_ctx_new(*mal_ctx, hostname, port, maltcp_header, false);

    // Check consumer context
    if (!maltcp_ctx)
    {
        // Return error code in case of error
        return -1;
    }

    // Return no-error code
    return 0;
}


int
nmfapi_util_init_mal_attribute(char *raw_value, unsigned char tag, union mal_attribute_t *attribute)
{
    // Set the attribute value according to the given tag
    switch(tag)
    {
        case MAL_IDENTIFIER_ATTRIBUTE_TAG:
            attribute->identifier_value = mal_identifier_new(raw_value);
            break;

        case MAL_STRING_ATTRIBUTE_TAG:
            attribute->string_value = mal_string_new(raw_value);
            break;

        case MAL_URI_ATTRIBUTE_TAG:
            attribute->uri_value = mal_uri_new(raw_value);
            break;

        case MAL_BOOLEAN_ATTRIBUTE_TAG:
            // type: bool
            if( strcmp(raw_value, "true") == 0 ||
                strcmp(raw_value, "True") == 0 ||
                strcmp(raw_value, "TRUE") == 0 ||
                strcmp(raw_value, "t") == 0 ||
                strcmp(raw_value, "T") == 0 ||
                strcmp(raw_value, "1") == 0)
            {
                attribute->boolean_value = true;
            }
            else
            {
                attribute->boolean_value = false;
            }
            break;

        case MAL_FLOAT_ATTRIBUTE_TAG:
            // type: float
            attribute->float_value = atof(raw_value);
            break;

        case MAL_DOUBLE_ATTRIBUTE_TAG:
            // type: double
            attribute->double_value = strtod(raw_value, NULL);
            break;

        case MAL_OCTET_ATTRIBUTE_TAG:
            // type: char

            // Error checking, expecting single character
            if(strlen(raw_value) == 1)
            {
                attribute->octet_value = raw_value[0];
            }
            else
            {
                return -1;
            }

            break;

        case MAL_UOCTET_ATTRIBUTE_TAG:
            // type: unsigned char

            // Error checking, expecting single character
            if(strlen(raw_value) == 1)
            {
                attribute->uoctet_value = raw_value[0];
            }
            else
            {
                return -1;
            }

            break;

        case MAL_SHORT_ATTRIBUTE_TAG:
            // type: short
            // FIXME: No error checking when using atoi
            attribute->short_value = atoi(raw_value);
            break;

        case MAL_USHORT_ATTRIBUTE_TAG:
            // type: unsigned short
            // FIXME: No error checking when using atoi
            attribute->ushort_value = atoi(raw_value);
            break;

        case MAL_INTEGER_ATTRIBUTE_TAG:
            // type: int
            attribute->integer_value = atoi(raw_value);
            break;

        case MAL_UINTEGER_ATTRIBUTE_TAG:
            // type: unsigned int
            attribute->uinteger_value = strtoul(raw_value, 0L, 10);
            break;

        case MAL_LONG_ATTRIBUTE_TAG:
            // type: long
            attribute->long_value = strtol(raw_value, 0L, 10);
            break;

        case MAL_ULONG_ATTRIBUTE_TAG:
            // type: unsigned long
            attribute->ulong_value = strtoul(raw_value, 0L, 10);
            break;

        case MAL_TIME_ATTRIBUTE_TAG:
            // type: unsigned long
            attribute->time_value = strtoul(raw_value, 0L, 10);
            break;

        case MAL_FINETIME_ATTRIBUTE_TAG:
            // type: unsigned long
            attribute->finetime_value = strtoul(raw_value, 0L, 10);
            break;

        case MAL_DURATION_ATTRIBUTE_TAG:
            // type: double
            attribute->duration_value = strtod(raw_value, NULL);
            break;

        default:
            // Unsupported tag
            // Not supporting Blob tag for attribute value of type mal_blot_t struct
            return -1;
    }

    return 0;
}