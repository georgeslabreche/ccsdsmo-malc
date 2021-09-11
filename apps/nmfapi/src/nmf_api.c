/*  =========================================================================
    nmf_api - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api -
@discuss
@end
*/

#include "nmfapi_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t nmf_api_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
nmf_api_set_log_level (int level)
{
    nmf_api_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _nmf_api_t {
    common_directory_service_t *common_directory_service;
    sm_appslauncher_service_t *sm_appslauncher_service;
    mc_parameter_service_t *mc_parameter_service;
};


//  --------------------------------------------------------------------------
//  Create a new nmf_api

nmf_api_t *
nmf_api_new (char *hostname, char *provider_port, char *consumer_port)
{
    nmf_api_t *self = (nmf_api_t *) zmalloc (sizeof (nmf_api_t));
    assert (self);
    
    // Initialize class properties here

    // Initialize COMMON services
    self->common_directory_service = common_directory_service_new(hostname, provider_port, consumer_port);

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

        // Destroy COMMON services
        common_directory_service_destroy(&self->common_directory_service);

        // Destroy SOFTWARE MANAGEMENT services
        sm_appslauncher_service_destroy(&self->sm_appslauncher_service);

        // Destroy MONITOR & CONTROL services
        mc_parameter_service_destroy(&self->mc_parameter_service);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
// Service getters

//  Get the Common Directory service
common_directory_service_t *
nmf_api_get_common_directory_service (nmf_api_t *self)
{
    return self->common_directory_service;
}

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

#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
nmf_api_test (bool verbose)
{
    printf (" * nmf_api: ");
    //  @end
    printf ("OK\n");
}
