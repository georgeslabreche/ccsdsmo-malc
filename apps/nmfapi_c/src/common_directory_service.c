/*  =========================================================================
    common_directory_service - The Directory service allows service providers to publish information about which services
    they provide and consumersto discover service provider address and capability information

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    common_directory_service - The Directory service allows service providers to publish information about which services
    they provide and consumersto discover service provider address and capability information

    TODO: This Service class is not fully implemented
          See Issue #29: https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/29
@discuss
@end
*/

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t common_directory_service_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
common_directory_service_set_log_level (int level)
{
    common_directory_service_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _common_directory_service_t {
    char *hostname;
    char *provider_port;
    char *consumer_port;
    mal_uri_t *provider_uri;
    mal_ctx_t *mal_ctx;
};


// The consumers
common_directory_lookupprovider_consumer_t * lookup_provider_consumer;

//  --------------------------------------------------------------------------
//  Create a new common_directory_service

common_directory_service_t *
common_directory_service_new (char *hostname, char *provider_port, char *consumer_port)
{
    common_directory_service_t *self = (common_directory_service_t *) zmalloc (sizeof (common_directory_service_t));
    assert (self);

    // Initialize class properties here
    self->hostname = hostname;
    self->provider_port = provider_port;
    self->consumer_port = consumer_port;

    // Create provider URI
    char *provider_id = "nanosat-mo-supervisor-Directory";
    self->provider_uri = nmfapi_util_create_uri(MALTCP_URI, hostname, provider_port, provider_id);

    clog_debug(common_directory_service_logger, "common_directory_service_new: provider URI: %s\n", self->provider_uri);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the common_directory_service

void
common_directory_service_destroy (common_directory_service_t **self_p)
{
    // Log debug
    clog_debug(common_directory_service_logger, "common_directory_service_destroy()\n");

    assert (self_p);
    if (*self_p) {
        common_directory_service_t *self = *self_p;
        
        //  --------------------------------------------------------------------------
        //  Destroy the consumers

        // Destroy the lookupProvider consumer
        if(lookup_provider_consumer)
        {
            // Destroy the consumer
            common_directory_lookupprovider_consumer_destroy(&lookup_provider_consumer);
        }

        //  --------------------------------------------------------------------------
        //  Free class properties here

        // Destroy the provider URI
        if(self->provider_uri)
        {
            mal_uri_destroy(&self->provider_uri);
        }

        // Destroy the context
        if(self->mal_ctx)
        {
            mal_ctx_destroy(&self->mal_ctx);
        }

        // Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  The lookup operation allows a service consumer to query the directory service to return a list of
//  service providers that match the requested criteria. If no match is found, then an empty list is returned

int
common_directory_service_lookup_provider (common_directory_service_t *self,
    common_directory_servicefilter_t *service_filter,
    common_directory_providersummary_list_t *response_provider_summary_list)
{
    // Log debug
    clog_debug(common_directory_service_logger, "common_directory_service_lookup_provider()\n");

    // The return code
    int rc;

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the lookupProvider consumer
    lookup_provider_consumer = common_directory_lookupprovider_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the service_filter field
    common_directory_lookupprovider_consumer_set_field_service_filter(lookup_provider_consumer, service_filter);

    // Create and initialize the consumer actor
    common_directory_lookupprovider_consumer_actor_init(lookup_provider_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    common_directory_lookupprovider_consumer_mutex_lock(lookup_provider_consumer);

    // Set the response pointers
    response_provider_summary_list = common_directory_lookupprovider_consumer_get_response_provider_summary_list(lookup_provider_consumer);

    // Set the return code as the error code of the consumer response
    rc = common_directory_lookupprovider_consumer_get_response_error_code(lookup_provider_consumer);

    // Unlock the consumer mutex
    common_directory_lookupprovider_consumer_mutex_unlock(lookup_provider_consumer);

    // Destroy the lookupProvider consumer
    common_directory_lookupprovider_consumer_destroy(&lookup_provider_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The lookup operation allows a service consumer to query the directory service to return a list of
//  service providers that match the requested criteria. If no match is found, then an empty list is returned

int
common_directory_service_lookup_provider_all (common_directory_service_t *self,
    common_directory_providersummary_list_t *response_provider_summary_list)
{
    // Log debug
    clog_debug(common_directory_service_logger, "common_directory_service_lookup_provider_all()\n");

    // The return code
    int rc = 0;

    // Create the filter object
    // Want to fetch all providers so no filters will be set
    common_directory_servicefilter_t *service_filter = common_directory_servicefilter_new();

    // Set filter for servive provider id
    common_directory_servicefilter_set_serviceproviderid(service_filter, mal_identifier_new("*"));
    
    // Set filter for domains
    mal_identifier_list_t *domain_list = mal_identifier_list_new(1);
    mal_identifier_t **domain_list_content = mal_identifier_list_get_content(domain_list);
    domain_list_content[0] = mal_identifier_new("*");
    common_directory_servicefilter_set_domain(service_filter, domain_list);
    
    // Set filter for network
    common_directory_servicefilter_set_network(service_filter, mal_identifier_new("*"));

    // Set filter for session type
    common_directory_servicefilter_sessiontype_set_present(service_filter, false);
    common_directory_servicefilter_set_sessiontype(service_filter, MAL_SESSIONTYPE_LIVE);

    // Set filter for session name
    common_directory_servicefilter_set_sessionname(service_filter, mal_identifier_new("*"));

    // Set filter for service key
    common_servicekey_t *service_key = common_servicekey_new();
    common_servicekey_set_keyarea(service_key, 0);
    common_servicekey_set_keyservice(service_key, 0);
    common_servicekey_set_keyareaversion(service_key, 0);
    common_directory_servicefilter_set_servicekey(service_filter, service_key);

    // Set filter for required capability set
    common_directory_servicefilter_set_requiredcapabilitysets(service_filter, mal_ushort_list_new(0));

    // Send the lookupProvider request
    rc = common_directory_service_lookup_provider(self, service_filter, response_provider_summary_list);

    // Destroy the filter object and all of its fields
    if(service_filter)
    {
        common_directory_servicefilter_destroy(&service_filter);
    }
    
    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The lookup operation allows a service consumer to query the directory service to return a list of
//  service providers that match the requested criteria. If no match is found, then an empty list is returned

int
common_directory_service_lookup_provider_all_uri (common_directory_service_t *self,
    long **response_provider_id_list, char ***response_provider_uri_list, size_t *response_element_count)
{
    // Log debug
    clog_debug(common_directory_service_logger, "common_directory_service_lookup_provider_all_uri()\n");

    // The return code
    int rc = 0;

    // The response object
    common_directory_providersummary_list_t *response_provider_summary_list;

    // Send the lookupProvider request to fetch all providers
    rc = common_directory_service_lookup_provider_all(self, response_provider_summary_list);

    // TODO: Process the response object to extract and set provider id and url lists
    if(rc == 0)
    {   
        size_t element_count = common_directory_providersummary_list_get_element_count(response_provider_summary_list);
        common_directory_providersummary_t **content = common_directory_providersummary_list_get_content(response_provider_summary_list);

        for(size_t i = 0; i < element_count; i++)
        {
            // Get the provider id
            mal_identifier_t *provider_id = common_directory_providersummary_get_providerid(content[i]);
            
            // TODO: Set the response_provider_uri_list with the fetched provider id uris.
            //
            // TODO: Is provider_id what we need or do we need to dig deeper to get the service uri?
            //
            // If we need to get the service uri:
            // i.e. common_directory_providersummary_t 
            //  --> common_directory_providerdetails_t * f_providerdetails
            //      --> common_directory_addressdetails_list_t * f_provideraddresses
            //          --> common_directory_addressdetails_t ** content;
            //              --> mal_uri_t * f_serviceuri;
        }

    }

    // Destroy the response object
    if(response_provider_summary_list != NULL)
    {
        size_t element_count = common_directory_providersummary_list_get_element_count(response_provider_summary_list);

        if(element_count > 0)
        {
            common_directory_providersummary_list_destroy(&response_provider_summary_list);
        }
    }

    // Return the return code
    return rc;
}
