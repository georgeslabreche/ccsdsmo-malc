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

#include "nmfapi_classes.h"

//  Structure of our class

struct _mc_parameter_service_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
};

mc_parameter_get_value_consumer_t *get_value_consumer;
mc_parameter_list_definition_consumer_t *list_definition_consumer;


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_service

mc_parameter_service_t *
mc_parameter_service_new (const char *provider_host, const char *provider_port, const char *consumer_port)
{
    mc_parameter_service_t *self = (mc_parameter_service_t *) zmalloc (sizeof (mc_parameter_service_t));
    assert (self);
    //  Initialize class properties here

    // Create mal context
    self->mal_ctx = mal_ctx_new();

    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = NULL;

    // Create mal tcp header
    maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    void *ctx = NULL;

    // Connection: bind to server with set port number
    // Listening socket.
    ctx = maltcp_ctx_new(
        self->mal_ctx,
        //"192.168.132.16", "1025", // SEPP
        "192.168.0.119", "1025", // LOCAL DEV
        maltcp_header,
        true);

    if (!ctx) exit(EXIT_FAILURE);

    //mal_uri_t *provider_uri = mal_ctx_create_uri(self->mal_ctx, "nanosat-mo-supervisor-Parameter");
    // SEPP
    //self->provider_uri = "maltcp://192.168.132.16:1024/nanosat-mo-supervisor-Parameter";
    
    // LOCAL DEV
    self->provider_uri = "maltcp://192.168.0.119:1024/nanosat-mo-supervisor-Parameter";
    printf("demo_app: provider URI: %s\n", self->provider_uri);

    // Create the consumers
    get_value_consumer = mc_parameter_get_value_consumer_new(self->mal_ctx, self->provider_uri);
    list_definition_consumer = mc_parameter_list_definition_consumer_new(self->provider_uri);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_service

void
mc_parameter_service_destroy (mc_parameter_service_t **self_p)
{
    printf("mc_parameter_service_destroy\n");

    assert (self_p);
    if (*self_p) {
        mc_parameter_service_t *self = *self_p;
        //  Free class properties here

        // Destroy the consumers
        mc_parameter_get_value_consumer_destroy (&get_value_consumer);
        mc_parameter_list_definition_consumer_destroy(&list_definition_consumer, self->mal_ctx);

        // Destroy the context
        mal_ctx_destroy(&self->mal_ctx);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

void
mc_parameter_service_get_values (mc_parameter_service_t *self, long *param_inst_ids, size_t param_inst_size)
{
    // Make sure that the getValue consumer has been initialized
    assert(get_value_consumer);

    // Set the param names MAL message field.
    mc_parameter_get_value_consumer_set_field_param_inst_ids(get_value_consumer, param_inst_ids);

    // Set the param size MAL message field.
    mc_parameter_get_value_consumer_set_field_param_inst_size(get_value_consumer, param_inst_size);

    // Start
    mal_ctx_start(self->mal_ctx);
}

void
mc_parameter_service_get_value (mc_parameter_service_t *self, long param_inst_id)
{
    long param_inst_ids[1];
    param_inst_ids[0] = param_inst_id;
    mc_parameter_service_get_values(self, param_inst_ids, 1);

    // Start
    mal_ctx_start(self->mal_ctx);
}

void
mc_parameter_service_list_definitions (mc_parameter_service_t *self, char **param_names, size_t param_size)
{
    // Make sure that the listDefinition consumer has been initialized
    assert(list_definition_consumer);

    // Set the param names MAL message field.
    mc_parameter_list_definition_consumer_set_field_param_names(list_definition_consumer, param_names);

    // Set the param size MAL message field.
    mc_parameter_list_definition_consumer_set_field_param_size(list_definition_consumer, param_size);

    // Create the consumer actor that registers callback functions
    // TODO: move to constructor?
    mc_parameter_list_definition_consumer_actor_create(list_definition_consumer, self->mal_ctx);

    // Start the request interaction;
    mal_ctx_start(self->mal_ctx);
}

void
mc_parameter_service_list_definition (mc_parameter_service_t *self, char *param_name)
{
    char *param_names[] = {param_name};
    mc_parameter_service_list_definitions(self, param_names, 1);
}


//  --------------------------------------------------------------------------
//  Self test of this class

#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
mc_parameter_service_test (bool verbose)
{
    printf (" * mc_parameter_service: ");
    printf ("OK\n");
}
