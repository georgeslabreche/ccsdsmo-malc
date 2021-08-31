/*  =========================================================================
    sm_appslauncher_service - The Apps Launcher service provides the ability to monitor
    the execution, run, stop, kill and list applications software on-board of a spacecraft

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sm_appslauncher_service - The Apps Launcher service provides the ability to monitor
    the execution, run, stop, kill and listapplications software on-board of a spacecraft
@discuss
@end
*/
#include <string.h>
#include "nmfapi_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t sm_appslauncher_service_logger = CLOG_DEBUG_LEVEL;

void
sm_appslauncher_service_set_log_level (int level)
{
    sm_appslauncher_service_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _sm_appslauncher_service_t {
    char *hostname;
    char *provider_port;
    char *consumer_port;
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
};

// The consumers
sm_appslauncher_list_app_consumer_t *list_app_consumer;


//  --------------------------------------------------------------------------
//  Create a new sm_appslauncher_service

sm_appslauncher_service_t *
sm_appslauncher_service_new (char *hostname, char *provider_port, char *consumer_port)
{
    sm_appslauncher_service_t *self = (sm_appslauncher_service_t *) zmalloc (sizeof (sm_appslauncher_service_t));
    assert (self);

    // Initialize class properties here
    self->hostname = hostname;
    self->provider_port = provider_port;
    self->consumer_port = consumer_port;

    // Create provider URI
    char *provider_id = "nanosat-mo-supervisor-AppsLauncher";
    self->provider_uri = nmfapi_util_create_uri(MALTCP_URI, hostname, provider_port, provider_id);
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_new: provider URI: %s\n", self->provider_uri);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the sm_appslauncher_service

void
sm_appslauncher_service_destroy (sm_appslauncher_service_t **self_p)
{
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_destroy()\n");

    assert (self_p);
    if (*self_p) {
        sm_appslauncher_service_t *self = *self_p;

        // Free class properties here

        // Destroy the listApp consumer
        if(list_app_consumer) // FIXME: will response be cleared because consumer gets destroyed in sm_appslauncher_service_list_app?
        {
            // Clear the response variables
            sm_appslauncher_list_app_consumer_response_clear(list_app_consumer);

            // Destroy the consumer
            sm_appslauncher_list_app_consumer_destroy(&list_app_consumer);
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
//  Private functions

//  Create the consumer context
void
sm_appslauncher_service_consumer_ctx_create (sm_appslauncher_service_t *self)
{
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_consumer_ctx_create()\n");

    if(!self->mal_ctx)
    {
        // Create context
        self->mal_ctx = mal_ctx_new();
    
        // Create mal tcp header: all the MAL header fields are passed
        maltcp_header_t *maltcp_header = NULL;
        maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);
        
        // Create the consumer listening socket: bind to server with the consumer port number
        void *ctx_consumer = NULL;
        ctx_consumer = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

        // Check consumer context
        if (!ctx_consumer) exit(EXIT_FAILURE);
    }
}



//  --------------------------------------------------------------------------
//  The listApp operation allows a consumer to request the object instance identifiers of the Apps objects
//  and running status for an app name or for a certain app category

int
sm_appslauncher_service_list_app (sm_appslauncher_service_t *self, char **app_name_list, size_t app_name_list_size, char *category,
    long **response_apps_inst_id_list, bool **response_apps_inst_running_list, size_t *response_element_count)
{
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_list_app()\n");

    // The return code
    int rc;

    // Create the consumer context / listening socket
    sm_appslauncher_service_consumer_ctx_create(self);

    // Create the listApp consumer
    list_app_consumer = sm_appslauncher_list_app_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the app names MAL message field
    sm_appslauncher_list_app_consumer_set_field_app_name_list(list_app_consumer, app_name_list);

    // Set the app names sie MAL message field
    sm_appslauncher_list_app_consumer_set_field_app_name_list_size(list_app_consumer, app_name_list_size);

    // Set the category MAL message field
    sm_appslauncher_list_app_consumer_set_field_category(list_app_consumer, category);

    // Initialize the consumer actor
    sm_appslauncher_list_app_consumer_actor_init(list_app_consumer);

    // Start
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request response callback function has finished executing
    // We do this so that the response variables can be set and return synchronously
    sm_appslauncher_list_app_consumer_mutex_lock(list_app_consumer);

    // Set the response pointers
    *response_apps_inst_id_list = sm_appslauncher_list_app_consumer_get_response_apps_inst_id_list(list_app_consumer);
    *response_apps_inst_running_list = sm_appslauncher_list_app_consumer_get_response_apps_inst_running_list(list_app_consumer);
    *response_element_count = sm_appslauncher_list_app_consumer_get_response_element_count(list_app_consumer);

    // Set the return code as the error code of the consumer response
    rc = sm_appslauncher_list_app_consumer_get_response_error_code(list_app_consumer);

    // Unlock the consumer mutex
    sm_appslauncher_list_app_consumer_mutex_unlock(list_app_consumer);

    // Destroy the listApp consumer
    sm_appslauncher_list_app_consumer_destroy(&list_app_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}