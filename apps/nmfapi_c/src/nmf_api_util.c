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


//  --------------------------------------------------------------------------
//  Given a port number, checks if it's available
//  If the port is not available then increment its number until an available one is found

int
nmfapi_util_set_available_port(char *hostname, char *port)
{
    // The return code
    int rc = 0;

    // Cast consumer port to int type
    int port_int;
    sscanf(port, "%d", &port_int);
 
    // Define connection variables
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
 
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Error check
    if (sockfd < 0)
    {
        return -1;
    }
 
    // Get host
    server = gethostbyname(hostname);
 
    // Error check
    if (server == NULL)
    {
        return -1;
    }
 
    // Init server connection
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    
    // Keep track of number of attemps to find an availabel port number to avoid an infinite loop
    int attempts;

    // Loop to find available port
    // Keep increment the port number until an available one is found
    for(attempts = 0; attempts < MAX_PORT_INCREMENTS; attempts++)
    {
        serv_addr.sin_port = htons(port_int);
        
        // Check if connection can be made for the given port
        if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        {
            // If connection is successful then the current port was available
            // Cast the available consumer port to string
            sprintf(port, "%d", port_int);

            // Exit the loop and disconnect from the server to make the port available again
            break;
        } 
        else
        {
            // If connection failed then the port was not available
            // Increment the port number and check again
            port_int++;
        }
    }
 
    // Close the socket connection so that the port is made available again
    close(sockfd);

    // If the attempt counter passed the max number of attempts the we failed to find an available port
    if(attempts >= MAX_PORT_INCREMENTS)
    {
        return -1;
    }

    // Success
    return 0;
}


//  --------------------------------------------------------------------------
//  Create a URI
//  It's the invoker of this funtion to destroy the returned URI with mal_uri_destroy

mal_uri_t *
nmfapi_util_create_uri(const char* protocol, const char *hostname, const char *port, const char *id)
{
    // Calculate length of URI
    unsigned int uri_length = strlen(protocol);

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

    // Create string variable for URI
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

    // Return the URI
    return uri;
}


//  --------------------------------------------------------------------------
//  Create a MAL message

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

    // Return the MAL message
    return message;
}

//  --------------------------------------------------------------------------
//  Destroy a MAL message

void
nmfapi_util_destroy_mal_message(mal_message_t *message, mal_ctx_t *mal_ctx)
{
    /**
     * Invoking mal_message_destroy does not destroy the object's properties
     * unless they are flagged to be free, e.g.:
     * 
     *    if (self->free_domain)
     *    {
     *      mal_identifier_list_destroy(&self->domain);
     *    }
     * 
     * This util function makes sure that all the message object's property "free"
     * flags are set to True prior to destroying the message object.
     */

    // Destroy the message object's properties
    if(message)
    {
        // DO NOT destroy the provider URI
        // Those URI objects are created in the service class and thus must be deallocated there
        
        // DO NOT destroy the consumer URI
        // Those URI objects are created in the consumer class and thus must be deallocated there
        
        // All other properties are OK to free
        mal_message_set_free_network_zone(message, true);
        mal_message_set_free_session_name(message, true);
        mal_message_set_free_domain(message, true);
        mal_message_set_free_authentication_id(message, true);

        // And now we can destroy the message and its properties
        mal_message_destroy(&message, mal_ctx);
    }
}


//  --------------------------------------------------------------------------
//  Initialize a MAL attribute
//  FIXME: Mask casts portable: atof, strtod, atoi, strtol, and strtoul

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