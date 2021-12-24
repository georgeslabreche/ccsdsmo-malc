/*  =========================================================================
    mc_parameter_listdefinition_consumer - The request consumer for the listDefinition operation.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_listdefinition_consumer - The request consumer for the listDefinition operation.
@discuss
@end
*/

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

//  The class logger
clog_logger_t mc_parameter_listdefinition_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
mc_parameter_listdefinition_consumer_set_log_level (int level)
{
    mc_parameter_listdefinition_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _mc_parameter_listdefinition_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_actor_t *actor;
    char **param_name_list;
    size_t param_name_list_size;
    long *response_identity_id_list;
    long *response_definition_id_list;
    size_t response_element_count;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t mc_parameter_listdefinition_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions

int
mc_parameter_listdefinition_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_listdefinition_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_listdefinition_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_listdefinition_consumer

mc_parameter_listdefinition_consumer_t *
mc_parameter_listdefinition_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_new()\n");

    mc_parameter_listdefinition_consumer_t *self = (mc_parameter_listdefinition_consumer_t *) zmalloc (sizeof (mc_parameter_listdefinition_consumer_t));
    assert (self);

    //  Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_listdefinition_consumer

void
mc_parameter_listdefinition_consumer_destroy (mc_parameter_listdefinition_consumer_t **self_p)
{
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        mc_parameter_listdefinition_consumer_t *self = *self_p;
        
        //  Free class properties here

        // We do not invoke the clear response variables function here (i.e. mc_parameter_listdefinition_consumer_response_clear)
        // This is because we still want those variables to be available to the client even after the 
        // mc_parameter_service's mc_parameter_service_get_values function is done executing.
        // The reponse variables will be cleared when invoking mc_parameter_service's destructor.

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
//  Clear the response variables

void
mc_parameter_listdefinition_consumer_response_clear (mc_parameter_listdefinition_consumer_t *self)
{
    // Log debug
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_response_clear()\n");

    if (self)
    {
        if (self->response_element_count > 0)
        {
            // Reset element count to zero
            self->response_element_count = 0;

            // Clear identity ids
            free(self->response_identity_id_list);
            self->response_identity_id_list = NULL;

            // Clear definition ids
            free(self->response_definition_id_list);
            self->response_definition_id_list = NULL;
        }
    }
}


//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_listdefinition_consumer_mutex_lock (mc_parameter_listdefinition_consumer_t *self)
{
    pthread_mutex_lock(&mc_parameter_listdefinition_consumer_mutex);
}

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_listdefinition_consumer_mutex_unlock (mc_parameter_listdefinition_consumer_t *self)
{
    pthread_mutex_unlock(&mc_parameter_listdefinition_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
mc_parameter_listdefinition_consumer_actor_init (mc_parameter_listdefinition_consumer_t *self)
{
    mal_uri_t *consumer_uri = mal_ctx_create_uri(self->mal_ctx, MC_PARAMETER_LISTDEFINITION_CONSUMER_URI);
    self->actor = mal_actor_new(self->mal_ctx, consumer_uri, self,
        mc_parameter_listdefinition_consumer_initialize, mc_parameter_listdefinition_consumer_finalize);
}

//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

char **
mc_parameter_listdefinition_consumer_get_field_param_name_list (mc_parameter_listdefinition_consumer_t *self)
{
    return self->param_name_list;
}

void
mc_parameter_listdefinition_consumer_set_field_param_name_list (mc_parameter_listdefinition_consumer_t *self, char **param_name_list)
{
    self->param_name_list = param_name_list;
}

size_t
mc_parameter_listdefinition_consumer_get_field_param_name_list_size (mc_parameter_listdefinition_consumer_t *self)
{
    return self->param_name_list_size;
}

void
mc_parameter_listdefinition_consumer_set_field_param_name_list_size (mc_parameter_listdefinition_consumer_t *self, size_t param_name_list_size)
{
    self->param_name_list_size = param_name_list_size;
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for the identity ids
long *
mc_parameter_listdefinition_consumer_get_response_identity_id_list (mc_parameter_listdefinition_consumer_t *self)
{
    return self->response_identity_id_list;
}

//  Get response variable for the definition ids
long *
mc_parameter_listdefinition_consumer_get_response_definition_id_list (mc_parameter_listdefinition_consumer_t *self)
{
    return self->response_definition_id_list;
}

//  Get response variable for number elements
size_t
mc_parameter_listdefinition_consumer_get_response_element_count (mc_parameter_listdefinition_consumer_t *self)
{
    return self->response_element_count;
}

//  Get error code from processing the response
int
mc_parameter_listdefinition_consumer_get_response_error_code (mc_parameter_listdefinition_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization function
int
mc_parameter_listdefinition_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_initialize()\n");

    // Cast self to consumer type
    mc_parameter_listdefinition_consumer_t *consumer = (mc_parameter_listdefinition_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    // The mutex will be unlocked at the end of the finalize function
    mc_parameter_listdefinition_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    // Register the consumer request handler
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        MC_AREA_NUMBER,
        MC_AREA_VERSION,
        MC_PARAMETER_SERVICE_NUMBER,
        MC_PARAMETER_LISTDEFINITION_OPERATION_NUMBER,
        mc_parameter_listdefinition_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error and return error code
        clog_error(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_initialize: error register consumer request handler\n");

        // Return the error code
        return rc;
    }

    // Build the request field
    mal_identifier_list_t *param_name_mal_id_list = mal_identifier_list_new(consumer->param_name_list_size);
    mal_identifier_t **content = mal_identifier_list_get_content(param_name_mal_id_list);

    // Construct the message content
    for(size_t i = 0; i < consumer->param_name_list_size; i++)
    {
        content[i] = mal_identifier_new(consumer->param_name_list[i]);
    }

    // Get the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the field
    clog_debug(mc_parameter_listdefinition_consumer_logger,
        "mc_parameter_listdefinition_consumer_initialize: encoding_length_0 for paramNames\n");

    rc = mc_parameter_listdefinition_request_add_encoding_length_0(encoder, param_name_mal_id_list, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_initialize: error encoding_length_0 for paramNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the field
        mal_identifier_list_destroy(&param_name_mal_id_list);

        // Return the error code
        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(mc_parameter_listdefinition_consumer_logger,
        "mc_parameter_listdefinition_consumer_initialize: new MAL message\n");

    mal_message_t *message = nmfapi_util_create_mal_message(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the request field
    clog_debug(mc_parameter_listdefinition_consumer_logger,
        "mc_parameter_listdefinition_consumer_initialize: encode_0 for paramNames\n");

    rc = mc_parameter_listdefinition_request_encode_0(cursor, encoder, param_name_mal_id_list);
    mal_encoder_cursor_assert(encoder, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_initialize: error encode_0 for paramNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the field
        mal_identifier_list_destroy(&param_name_mal_id_list);

        // Return the error code
        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    clog_debug(mc_parameter_listdefinition_consumer_logger,
        "mc_parameter_listdefinition_consumer_initialize: send getValue request message\n");

    rc = mc_parameter_listdefinition_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_initialize: error sending listDefinition request message\n");
    }

    // Destroy the field
    mal_identifier_list_destroy(&param_name_mal_id_list);

    // Return the return code
    return rc;
}


//  The consumer finalization function
int
mc_parameter_listdefinition_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    mc_parameter_listdefinition_consumer_t *consumer = (mc_parameter_listdefinition_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);
   
    // Unlock the mutex
    mc_parameter_listdefinition_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The consumer response function
int
mc_parameter_listdefinition_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // Log debug
    clog_debug(mc_parameter_listdefinition_consumer_logger, "mc_parameter_listdefinition_consumer_response()\n");

    // Cast consumer type
    mc_parameter_listdefinition_consumer_t *consumer = (mc_parameter_listdefinition_consumer_t *) self;

    // Initialize the response error code to no error
    consumer->response_error_code = 0;

    // Get the MAL message decoder
    mal_decoder_t *decoder = malbinary_decoder_new(false);

    // Get the MAL cursor
    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));


    // Check if received error message
    if(mal_message_is_error_message(message))
    {
        // Log error
        clog_error(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_response: received error message for listDefinition request\n");

        // Set error code to error value
        consumer->response_error_code = -1;
    }
    else
    {
        // The response fields
        mc_objectinstancepair_t **content;
        mc_objectinstancepair_list_t *object_instance_pair_list;
        
        // Log the offset
        clog_debug(mc_parameter_listdefinition_consumer_logger, 
            "mc_parameter_listdefinition_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

        // Decode the response
        clog_debug(mc_parameter_listdefinition_consumer_logger, 
            "mc_parameter_listdefinition_consumer_response: decode_0 for objInstIds\n");
        
        consumer->response_error_code = mc_parameter_listdefinition_request_response_decode_0(cursor, decoder, &object_instance_pair_list);
        mal_decoder_cursor_assert(decoder, cursor);

        // Check for errors
        if (consumer->response_error_code != 0)
        {
            // Log error
            clog_error(mc_parameter_listdefinition_consumer_logger,
                "mc_parameter_listdefinition_consumer_response: error decode_0 for objInstIds\n");
        }
        else // No error, allocate memory for response lists
        {
            // Set response variable for element count
            consumer->response_element_count = mc_objectinstancepair_list_get_element_count(object_instance_pair_list);

            // Allocate memory for the identity ids response
            consumer->response_identity_id_list = (long *) calloc(consumer->response_element_count, sizeof(long));
            if (!consumer->response_identity_id_list && (consumer->response_element_count > 0))
            {
                // Log error
                clog_error(mc_parameter_listdefinition_consumer_logger,
                    "mc_parameter_listdefinition_consumer_response: memory allocation error for response identity ids\n");

                // Destroy consumer's response MAL attributes
                mc_parameter_listdefinition_consumer_response_clear(consumer);

                // Set and return the error code
                consumer->response_error_code = -1;
            }

            // Allocate memory for the definition ids response
            consumer->response_definition_id_list = (long *) calloc(consumer->response_element_count, sizeof(long));
            if (!consumer->response_definition_id_list && (consumer->response_element_count > 0))
            {
                // Log error
                clog_error(mc_parameter_listdefinition_consumer_logger,
                    "mc_parameter_listdefinition_consumer_response: memory allocation error for response definition ids\n");

                // Destroy consumer's response MAL attributes
                mc_parameter_listdefinition_consumer_response_clear(consumer);

                // Set and return the error code
                consumer->response_error_code = -1;
            }

        }

        // Set response variables if no errors so far
        if(consumer->response_error_code == 0)
        {
            // Get content of the response
            content = mc_objectinstancepair_list_get_content(object_instance_pair_list);

            // Set response variables
            for (size_t i = 0; i < consumer->response_element_count; i++)
            {
                consumer->response_identity_id_list[i] = mc_objectinstancepair_get_objidentityinstanceid(content[i]);
                consumer->response_definition_id_list[i] = mc_objectinstancepair_get_objdefinstanceid(content[i]);
            }
        }

        // Cleanup
        clog_debug(mc_parameter_listdefinition_consumer_logger,
            "mc_parameter_listdefinition_consumer_response: cleanup\n");

        // Only destroy the mc_objectinstancepair object if it was initialized
        if(content)
        {
            mc_objectinstancepair_destroy(content);
        }

        // Destroy fields
        if(object_instance_pair_list)
        {
            mc_objectinstancepair_list_destroy(&object_instance_pair_list);
        }
    }

    // Destroy the MAL decoder cursor
    mal_decoder_cursor_destroy(decoder, cursor);

    // Destroy MAL message
    if(message)
    {
        mal_message_destroy(&message, mal_ctx);
    }

    // Terminating the actor thread will trigger the finalize function
    mal_actor_term(consumer->actor);

    // Return error code
    return consumer->response_error_code;
}
