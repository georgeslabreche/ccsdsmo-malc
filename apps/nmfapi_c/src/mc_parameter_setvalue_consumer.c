/*  =========================================================================
    mc_parameter_setvalue_consumer - The submit consumer for the setValue operation
    The setValue operation allows a consumer to set the raw value for one or more parameters

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_setvalue_consumer - The submit consumer for the setValue operation
    The setValue operation allows a consumer to set the raw value for one or more parameters
@discuss
@end
*/

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

//  The class logger
clog_logger_t mc_parameter_setvalue_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
mc_parameter_setvalue_consumer_set_log_level (int level)
{
    mc_parameter_setvalue_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _mc_parameter_setvalue_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_uri_t *consumer_uri;
    mal_actor_t *actor;
    long *param_inst_id_list;
    unsigned char *param_tag_list;
    char **param_value_list;
    size_t param_list_size;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t mc_parameter_setvalue_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions


int
mc_parameter_setvalue_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_setvalue_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_setvalue_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_setvalue_consumer

mc_parameter_setvalue_consumer_t *
mc_parameter_setvalue_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(mc_parameter_setvalue_consumer_logger, "mc_parameter_setvalue_consumer_new()\n");

    mc_parameter_setvalue_consumer_t *self = (mc_parameter_setvalue_consumer_t *) zmalloc (sizeof (mc_parameter_setvalue_consumer_t));
    assert (self);

    // Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;
    self->consumer_uri = mal_ctx_create_uri(self->mal_ctx, MC_PARAMETER_SETVALUE_CONSUMER_URI);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_setvalue_consumer

void
mc_parameter_setvalue_consumer_destroy (mc_parameter_setvalue_consumer_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        mc_parameter_setvalue_consumer_t *self = *self_p;
        //  Free class properties here

        // Destroy the conusmer URI
        mal_uri_destroy(&self->consumer_uri);

        // Make sure the actor thread object is terminated before destroying it
        mal_actor_join(self->actor);

        // Destroy the actor object
        mal_actor_destroy(self->mal_ctx, &self->actor);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_setvalue_consumer_mutex_lock (mc_parameter_setvalue_consumer_t *self)
{
    pthread_mutex_lock(&mc_parameter_setvalue_consumer_mutex);
}


//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_setvalue_consumer_mutex_unlock (mc_parameter_setvalue_consumer_t *self)
{
    pthread_mutex_unlock(&mc_parameter_setvalue_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
mc_parameter_setvalue_consumer_actor_init (mc_parameter_setvalue_consumer_t *self)
{
    // Create the MAL actor
    self->actor = mal_actor_new(self->mal_ctx, self->consumer_uri, self,
        mc_parameter_setvalue_consumer_initialize, mc_parameter_setvalue_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get error code from processing the response
int
mc_parameter_setvalue_consumer_get_response_error_code (mc_parameter_setvalue_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

long *
mc_parameter_setvalue_consumer_get_field_param_inst_id_list (mc_parameter_setvalue_consumer_t *self)
{
    return self->param_inst_id_list;
}

void
mc_parameter_setvalue_consumer_set_field_param_inst_id_list (mc_parameter_setvalue_consumer_t *self, long *param_inst_id_list)
{
    self->param_inst_id_list = param_inst_id_list;
}

unsigned char*
mc_parameter_setvalue_consumer_get_field_param_tag_list (mc_parameter_setvalue_consumer_t *self)
{
    return self->param_tag_list;
}

void
mc_parameter_setvalue_consumer_set_field_param_tag_list (mc_parameter_setvalue_consumer_t *self, unsigned char *param_tag_list)
{
    self->param_tag_list = param_tag_list;
}

char **
mc_parameter_setvalue_consumer_get_field_param_value_list (mc_parameter_setvalue_consumer_t *self)
{
    return self->param_value_list;
}

void
mc_parameter_setvalue_consumer_set_field_param_value_list (mc_parameter_setvalue_consumer_t *self, char **param_value_list)
{
    self->param_value_list = param_value_list;
}

size_t
mc_parameter_setvalue_consumer_get_field_param_list_size (mc_parameter_setvalue_consumer_t *self)
{
    return self->param_list_size;
}

void
mc_parameter_setvalue_consumer_set_field_param_list_size (mc_parameter_setvalue_consumer_t *self, size_t param_list_size)
{
    self->param_list_size = param_list_size;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization function
int
mc_parameter_setvalue_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_setvalue_consumer_logger, "mc_parameter_setvalue_consumer_initialize()\n");

    // Cast self to consumer type
    mc_parameter_setvalue_consumer_t *consumer = (mc_parameter_setvalue_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous submit response mechanism
    // The mutex will be unlocked at the end of the finalize function
    mc_parameter_setvalue_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    // Register the consumer submit handler
    rc = mal_routing_register_consumer_submit_handler(
        mal_actor_get_router(mal_actor),
        MC_AREA_NUMBER,
        MC_AREA_VERSION,
        MC_PARAMETER_SERVICE_NUMBER,
        MC_PARAMETER_SETVALUE_OPERATION_NUMBER,
        mc_parameter_setvalue_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error and return error code
        clog_error(mc_parameter_setvalue_consumer_logger,
            "mc_parameter_setvalue_consumer_initialize: error register consumer submit handler\n");

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);

        // Return the error code
        return rc;
    }

    // Get the number of params to set
    size_t param_list_size = mc_parameter_setvalue_consumer_get_field_param_list_size(consumer);

    // Build the submit ParameterRawValue list field
    mc_parameter_parameterrawvalue_list_t *param_raw_value_list = mc_parameter_parameterrawvalue_list_new(param_list_size);
    mc_parameter_parameterrawvalue_t **content = mc_parameter_parameterrawvalue_list_get_content(param_raw_value_list);

    // Track if mal_attribute is being initialized without error
    int mal_attribute_init_error_code;

    // Construct the message content
    for(size_t i = 0; i < param_list_size; i++)
    {
        union mal_attribute_t attribute;
        mal_attribute_init_error_code = nmfapi_util_init_mal_attribute(consumer->param_value_list[i], consumer->param_tag_list[i], &attribute);

        // Error check
        if(mal_attribute_init_error_code == 0)
        {
            // No error: create param raw value object
            content[i] = mc_parameter_parameterrawvalue_new();

            // Set the param presence flag, inst id, attribute tag, and raw value attribute
            mc_parameter_parameterrawvalue_rawvalue_set_present(content[i], true);
            mc_parameter_parameterrawvalue_set_paraminstid(content[i], consumer->param_inst_id_list[i]);
            mc_parameter_parameterrawvalue_rawvalue_set_attribute_tag(content[i], consumer->param_tag_list[i]);
            mc_parameter_parameterrawvalue_set_rawvalue(content[i], attribute);
        }
        else
        {
            clog_debug(mc_parameter_setvalue_consumer_logger,
                "mc_parameter_setvalue_consumer_initialize: Error initializing mal attribute: %d\n", mal_attribute_init_error_code);
                
            // In case of error, set presence flag to false and log error
            mc_parameter_parameterrawvalue_rawvalue_set_present(content[i], false);

            // Log error
            clog_error(mc_parameter_setvalue_consumer_logger,
                "mc_parameter_setvalue_consumer_initialize: error creating raw value mal attribute, skipping parameter value '%s' with attribute tag %s\n",
                consumer->param_value_list[i], consumer->param_tag_list[i]);
        }
    }

    // Get the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the field
    clog_debug(mc_parameter_setvalue_consumer_logger,
        "mc_parameter_setvalue_consumer_initialize: encoding_length_0 for ParameterRawValue list\n");

    rc = mc_parameter_setvalue_submit_add_encoding_length_0(encoder, param_raw_value_list, cursor);

     // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_setvalue_consumer_logger,
            "mc_parameter_setvalue_consumer_initialize: error encoding_length_0 for ParameterRawValue list\n");

        // Destroy the field
        mc_parameter_parameterrawvalue_list_destroy(&param_raw_value_list);

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the MAL encoder
        free(encoder);

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);

        // Return the error code
        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(mc_parameter_setvalue_consumer_logger,
        "mc_parameter_setvalue_consumer_initialize: new MAL message\n");

    // The MAL Message object will be destroyed in the consumer's destructor
    mal_message_t *message = nmfapi_util_create_mal_message(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the ParameterRawValue list field
    clog_debug(mc_parameter_setvalue_consumer_logger,
        "mc_parameter_setvalue_consumer_initialize: encode_0 for ParameterRawValue list\n");

    rc = mc_parameter_setvalue_submit_encode_0(cursor, encoder, param_raw_value_list);

    // Assert the MAL encoder cursor
    mal_encoder_cursor_assert(encoder, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_setvalue_consumer_logger,
            "mc_parameter_setvalue_consumer_initialize: error encode_0 for ParameterRawValue list\n");

        // Destroy the field
        mc_parameter_parameterrawvalue_list_destroy(&param_raw_value_list);

        // Destroy the MAL message
        nmfapi_util_destroy_mal_message(message, consumer->mal_ctx);

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the MAL encoder
        free(encoder);

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);

        // Return the error code
        return rc;
    }

    // Send the request message
    clog_debug(mc_parameter_setvalue_consumer_logger,
        "mc_parameter_setvalue_consumer_initialize: send setValue submit message\n");

    rc = mc_parameter_setvalue_submit(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    // Destroy the field
    mc_parameter_parameterrawvalue_list_destroy(&param_raw_value_list);

    // Destroy the MAL message
    nmfapi_util_destroy_mal_message(message, consumer->mal_ctx);

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Destroy the MAL encoder
    free(encoder);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_setvalue_consumer_logger,
            "mc_parameter_setvalue_consumer_initialize: error sending setValue submit message\n");

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);
    }

    // Return the return code
    return rc;

}

//  The consumer finalization function
int
mc_parameter_setvalue_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_setvalue_consumer_logger, "mc_parameter_setvalue_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    mc_parameter_setvalue_consumer_t *consumer = (mc_parameter_setvalue_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);
   
    // Unlock the mutex
    mc_parameter_setvalue_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The consumer submit acknowledgement function
int
mc_parameter_setvalue_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // Log debug
    clog_debug(mc_parameter_setvalue_consumer_logger, "mc_parameter_setvalue_consumer_response()\n");

    // Cast consumer type
    mc_parameter_setvalue_consumer_t *consumer = (mc_parameter_setvalue_consumer_t *) self;

    // Initialize the response error code to no error
    consumer->response_error_code = 0;

    // Check if received error message
    if(mal_message_is_error_message(message))
    {
        // Log error
        clog_error(mc_parameter_setvalue_consumer_logger,
            "mc_parameter_setvalue_consumer_response: received error message for setValue submit\n");

        // Set error code to error value
        consumer->response_error_code = -1;
    }

    // Cleanup
    clog_debug(mc_parameter_setvalue_consumer_logger,
        "mc_parameter_setvalue_consumer_response: cleanup\n");

    // Destroy MAL message
    if(message)
    {
        mal_message_destroy(&message, mal_ctx);
    }

    // Terminating the actor thread will trigger the finalize function
    mal_actor_term(consumer->actor);

    // Return the return code
    return consumer->response_error_code;
}