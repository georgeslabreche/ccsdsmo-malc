/*  =========================================================================
    mc_parameter_service - The parameter service allows the user to subscribe to parameter value report and optionally be able to set new values.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_service - The parameter service allows the user to subscribe to parameter value report and optionally be able to set new values.
@discuss
@end
*/

#include "nmf_api_classes.h"

//  Structure of our class

struct _mc_parameter_service_t {
    int filler;     //  Declare class properties here
};

mal_ctx_t *mal_ctx;
mc_parameter_get_value_consumer_t *consumer;


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_service

mc_parameter_service_t *
mc_parameter_service_new (const char *provider_host, const char *provider_port, const char *consumer_port)
{
    mc_parameter_service_t *self = (mc_parameter_service_t *) zmalloc (sizeof (mc_parameter_service_t));
    assert (self);
    //  Initialize class properties here

    // Create mal context
    mal_ctx = mal_ctx_new();

    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = NULL;

    // Create mal tcp header
    maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    void *ctx = NULL;

    // Connection: bind to server with set port number
    // Listening socket.
    ctx = maltcp_ctx_new(
        mal_ctx,
        "192.168.0.118", "1025",
        maltcp_header,
        true);

    if (!ctx) exit(EXIT_FAILURE);

    //mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "nanosat-mo-supervisor-Parameter");
    mal_uri_t *provider_uri = "maltcp://192.168.132.16:1024/nanosat-mo-supervisor-Parameter";
    printf("demo_app: provider URI: %s\n", provider_uri);

    // Create the consumer
    consumer = mc_parameter_get_value_consumer_new(provider_uri);

    return self;
}

void
mc_parameter_service_get_value (mc_parameter_service_t *self, long *param_inst_ids)
{

    // Create the consumer actor with callback functions that:
    //  1. initialize the MAL request message
    //  2. encode and send the MAL request message
    //  3. Decode the MAL response message and print parameters
    mc_parameter_get_value_consumer_actor_create (consumer, mal_ctx);

    // Start
    mal_ctx_start(mal_ctx);
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_service

void
mc_parameter_service_destroy (mc_parameter_service_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        mc_parameter_service_t *self = *self_p;
        //  Free class properties here

        // Destroy the consumer
        mc_parameter_get_value_consumer_destroy (&consumer, mal_ctx);

        // Destroy the context
        mal_ctx_destroy(&mal_ctx);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
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
mc_parameter_service_test (bool verbose)
{
    printf (" * mc_parameter_service: ");

    //  @selftest
    //  Simple create/destroy test
    //mc_parameter_service_t *self = mc_parameter_service_new ("192.168.132.16", "1024", "192.168.0.118");
    //assert (self);
    //mc_parameter_service_destroy (&self);
    //  @end
    printf ("OK\n");
}
