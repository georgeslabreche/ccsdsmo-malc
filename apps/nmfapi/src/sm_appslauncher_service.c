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

#include "nmfapi_classes.h"

// Mutex
pthread_mutex_t request_mutex;

// The class logger
clog_logger_t sm_appslauncher_service_logger = CLOG_DEBUG_LEVEL;

// Structure of our class
struct _sm_appslauncher_service_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
};

// The consumers
sm_appslauncher_list_app_consumer_t *list_app_consumer;

//  --------------------------------------------------------------------------
//  Create a new sm_appslauncher_service

sm_appslauncher_service_t *
sm_appslauncher_service_new (char *host, char *provider_port, char *consumer_port)
{
    sm_appslauncher_service_t *self = (sm_appslauncher_service_t *) zmalloc (sizeof (sm_appslauncher_service_t));
    assert (self);

    // Initialize class properties here

    // Create mal context
    self->mal_ctx = mal_ctx_new();

    // Create mal tcp header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = NULL;
    maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Create the provider URI
    void *ctx_provider = NULL;
    ctx_provider = maltcp_ctx_new(self->mal_ctx, host, provider_port, maltcp_header, false);
    self->provider_uri = mal_ctx_create_uri(self->mal_ctx, "nanosat-mo-supervisor-AppsLauncher");
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_new: provider URI: %s\n", self->provider_uri);
    
    // Create the listening socket connection: bind to server with set port number
    void *ctx_consumer = NULL;
    ctx_consumer = maltcp_ctx_new(self->mal_ctx, host, consumer_port, maltcp_header, false);

    if (!ctx_provider || !ctx_consumer) exit(EXIT_FAILURE);

    // Create the consumers
    list_app_consumer = sm_appslauncher_list_app_consumer_new(self->mal_ctx, self->provider_uri);

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

        // Destroy the consumers
        sm_appslauncher_list_app_consumer_destroy (&list_app_consumer);

        // Destroy the context
        mal_ctx_destroy(&self->mal_ctx);

        // Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Getters and Setters

void
sm_appslauncher_service_set_log_level (sm_appslauncher_service_t *self, int level)
{
    sm_appslauncher_service_logger = level;
}


//  --------------------------------------------------------------------------
//  The listApp operation allows a consumer to request the object instance identifiers of the Apps objects
//  and running status for an app name or for a certain app category

void
sm_appslauncher_service_list_app (sm_appslauncher_service_t *self, char **app_names, size_t app_names_size, char *category,
    long **response_apps_inst_ids, bool **response_apps_running, size_t *response_apps_count)
{
    clog_debug(sm_appslauncher_service_logger, "sm_appslauncher_service_list_app()\n");

    // Make sure that the listApp consumer has been initialized
    assert(list_app_consumer);

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    sm_appslauncher_list_app_consumer_lock_mutex(list_app_consumer);

    // Set the app names MAL message field
    sm_appslauncher_list_app_consumer_set_field_app_names(list_app_consumer, app_names);

    // Set the app names sie MAL message field
    sm_appslauncher_list_app_consumer_set_field_app_names_size(list_app_consumer, app_names_size);

    // Set the category MAL message field
    sm_appslauncher_list_app_consumer_set_field_category(list_app_consumer, category);

    // Initialize the consumer actor
    sm_appslauncher_list_app_consumer_actor_init(list_app_consumer);

    // Start
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request response callback function has finished executing
    // We do this so that the response variables can be set and return synchronously
    sm_appslauncher_list_app_consumer_lock_mutex(list_app_consumer);

    // Set the response pointers
    *response_apps_inst_ids = sm_appslauncher_list_app_consumer_get_response_apps_inst_ids(list_app_consumer);
    *response_apps_running = sm_appslauncher_list_app_consumer_get_response_apps_running(list_app_consumer);
    *response_apps_count = sm_appslauncher_list_app_consumer_get_response_apps_count(list_app_consumer);

    // Unlock the consumer mutex
    sm_appslauncher_list_app_consumer_unlock_mutex(list_app_consumer);
}