/*  =========================================================================
    nmf_api - The gateway API initializes the service objects and implements service accessors

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api - The gateway API initializes the service objects and implements service accessors
@discuss
@end
*/

#include "nmfapi_c_classes.h"

//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t nmf_api_logger = CLOG_ERROR_LEVEL;

//  Set the log level for this class
void
nmf_api_set_log_level (int level)
{
    nmf_api_logger = level;
}

//  Set the log level globally (for all classes of the nmf_api)
void
nmf_api_set_global_log_level (int level)
{
    // Gateway API
    nmf_api_set_log_level(level);

    // MAL
    mal_set_log_level(level);

    // MAL TCP
    maltcp_set_log_level(level);

    // Common service (DRAFT)
    //common_directory_service_set_log_level(level);
    //common_directory_lookupprovider_consumer_set_log_level(level);

    // AppsLauncher service
    sm_appslauncher_service_set_log_level(level);
    sm_appslauncher_listapp_consumer_set_log_level(level);

    // Parameter service
    mc_parameter_service_set_log_level(level);
    mc_parameter_listdefinition_consumer_set_log_level(level);
    mc_parameter_getvalue_consumer_set_log_level(level);
    mc_parameter_setvalue_consumer_set_log_level(level);
    mc_parameter_addparameter_consumer_set_log_level(level);
    mc_parameter_removeparameter_consumer_set_log_level(level);
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _nmf_api_t {
    //common_directory_service_t *common_directory_service; /* DRAFT */
    sm_appslauncher_service_t *sm_appslauncher_service;
    mc_parameter_service_t *mc_parameter_service;
};


//  --------------------------------------------------------------------------
//  Create a new nmf_api

nmf_api_t *
nmf_api_new (char *hostname, char *provider_port, char *consumer_port)
{
    // Return code
    int rc;

    // If the port is not available then increment its number until an available one is found;
    rc = nmfapi_util_set_available_port(hostname, consumer_port);

    if(rc != 0)
    {
        return NULL;
    }

    // Creat class object
    nmf_api_t *self = (nmf_api_t *) zmalloc (sizeof (nmf_api_t));
    assert (self);
    
    // Initialize class properties here

    // Initialize COMMON services (DRAFT)
    //self->common_directory_service = common_directory_service_new(hostname, provider_port, consumer_port);

    // Initialize SOFTWARE MANAGEMENT services
    self->sm_appslauncher_service = sm_appslauncher_service_new(hostname, provider_port, consumer_port);

    // Initialize MONITOR & CONTROL services
    self->mc_parameter_service = mc_parameter_service_new(hostname, provider_port, consumer_port);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the nmf_api

void
nmf_api_destroy (nmf_api_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        nmf_api_t *self = *self_p;
        
        //  Free class properties here

        // Destroy the COMMON DIRECTORY service (DRAFT)
        //common_directory_service_destroy(&self->common_directory_service);

        // Destroy SOFTWARE MANAGEMENT APPS LAUNCHER service
        sm_appslauncher_service_destroy(&self->sm_appslauncher_service);

        // Destroy MONITOR & CONTROL PARAMETER service
        mc_parameter_service_destroy(&self->mc_parameter_service);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
// Service getters

//  Get the Common Directory service (DRAFT)
/**
common_directory_service_t *
nmf_api_get_common_directory_service (nmf_api_t *self)
{
    return self->common_directory_service;
}
*/

//  Get the AppsLauncher service
sm_appslauncher_service_t *
nmf_api_get_sm_appslauncher_service (nmf_api_t *self)
{
    return self->sm_appslauncher_service;
}

//  Get the Parameter service
mc_parameter_service_t *
nmf_api_get_mc_parameter_service (nmf_api_t *self)
{
    return self->mc_parameter_service;
}

//  --------------------------------------------------------------------------
//  Self test of this class

// If your selftest reads SCMed fixture data, please keep it in
// src/selftest-ro; if your test creates filesystem objects, please
// do so under src/selftest-rw.
// The following pattern is suggested for C selftest code:
//    char *filename = NULL;
//    filename = zsys_sprintf ("%s/%s", SELFTEST_DIR_RO, "mytemplate.file");
//    assert (filename);
//    ... use the "filename" for I/O ...
//    zstr_free (&filename);
// This way the same "filename" variable can be reused for many subtests.
#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
nmf_api_test (bool verbose)
{
    printf (" * nmf_api: ");
    printf ("OK\n");
}
