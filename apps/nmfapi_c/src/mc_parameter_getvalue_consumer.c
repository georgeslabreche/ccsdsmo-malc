/*  =========================================================================
    mc_parameter_getvalue_consumer - The request consumer for the getValue operation.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_getvalue_consumer - The request consumer for the getValue operation
    The getValue operation returns the latest received value for a requested parameter
@discuss
@end
*/

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

//  The class logger
clog_logger_t mc_parameter_getvalue_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
mc_parameter_getvalue_consumer_set_log_level (int level)
{
    mc_parameter_getvalue_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _mc_parameter_getvalue_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_uri_t *consumer_uri;
    mal_actor_t *actor;
    int64_t *param_inst_id_list;
    unsigned int param_inst_id_list_size;
    union mal_attribute_t *response_mal_attribute_list;
    unsigned char *response_mal_attribute_tag_list;
    unsigned int response_element_count;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t mc_parameter_getvalue_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions

int
mc_parameter_getvalue_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_getvalue_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_getvalue_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_getvalue_consumer

mc_parameter_getvalue_consumer_t *
mc_parameter_getvalue_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_new()\n");

    mc_parameter_getvalue_consumer_t *self = (mc_parameter_getvalue_consumer_t *) zmalloc (sizeof (mc_parameter_getvalue_consumer_t));
    assert (self);
    
    // Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;
    self->consumer_uri = mal_ctx_create_uri(mal_ctx, MC_PARAMETER_GETVALUE_CONSUMER_URI);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_getvalue_consumer

void
mc_parameter_getvalue_consumer_destroy (mc_parameter_getvalue_consumer_t **self_p)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        mc_parameter_getvalue_consumer_t *self = *self_p;

        //  Free class properties here

        // We do not invoke the clear response variables function here (i.e. mc_parameter_getvalue_consumer_response_clear)
        // This is because we still want those variables to be available to the client even after the 
        // mc_parameter_service's mc_parameter_service_get_values function is done executing.
        // The reponse variables will be cleared when invoking mc_parameter_service's destructor.

        // Destroy the consumer URI
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
//  Clear the response variables

void
mc_parameter_getvalue_consumer_response_clear (mc_parameter_getvalue_consumer_t *self)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_response_clear()\n");

    if (self)
    {
        if (self->response_element_count > 0)
        {
            // Reset element count to zero
            self->response_element_count = 0;

            // Clear MAL attributes
            free(self->response_mal_attribute_list);
            self->response_mal_attribute_list = NULL;

            // Clear MAL attributes tags
            free(self->response_mal_attribute_tag_list);
            self->response_mal_attribute_tag_list = NULL;
        }
    }
}


//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_getvalue_consumer_mutex_lock (mc_parameter_getvalue_consumer_t *self)
{
    pthread_mutex_lock(&mc_parameter_getvalue_consumer_mutex);
}

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_getvalue_consumer_mutex_unlock (mc_parameter_getvalue_consumer_t *self)
{
    pthread_mutex_unlock(&mc_parameter_getvalue_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
mc_parameter_getvalue_consumer_actor_init (mc_parameter_getvalue_consumer_t *self)
{
    // Create the MAL actor
    self->actor = mal_actor_new(self->mal_ctx, self->consumer_uri, self,
        mc_parameter_getvalue_consumer_initialize, mc_parameter_getvalue_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

int64_t *
mc_parameter_getvalue_consumer_get_field_param_inst_id_list (mc_parameter_getvalue_consumer_t *self)
{
    return self->param_inst_id_list;
}

void
mc_parameter_getvalue_consumer_set_field_param_inst_id_list (mc_parameter_getvalue_consumer_t *self, int64_t *param_inst_id_list)
{
    self->param_inst_id_list = param_inst_id_list;
}

unsigned int
mc_parameter_getvalue_consumer_get_field_param_inst_id_list_size (mc_parameter_getvalue_consumer_t *self)
{
    return self->param_inst_id_list_size;
}

void
mc_parameter_getvalue_consumer_set_field_param_inst_id_list_size (mc_parameter_getvalue_consumer_t *self, unsigned int param_inst_id_list_size)
{
    self->param_inst_id_list_size = param_inst_id_list_size;
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for the mal attributes
union mal_attribute_t *
mc_parameter_getvalue_consumer_get_response_mal_attribute_list (mc_parameter_getvalue_consumer_t *self)
{
    return self->response_mal_attribute_list;
}

//  Get response variable for the mal attributes tags
unsigned char *
mc_parameter_getvalue_consumer_get_response_mal_attribute_tag_list (mc_parameter_getvalue_consumer_t *self)
{
    return self->response_mal_attribute_tag_list;
}

//  Get response variable for number of MAL attributes
unsigned int
mc_parameter_getvalue_consumer_get_response_element_count (mc_parameter_getvalue_consumer_t *self)
{
    return self->response_element_count;
}

//  Get error code from processing the response
int
mc_parameter_getvalue_consumer_get_response_error_code (mc_parameter_getvalue_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization function
int
mc_parameter_getvalue_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_initialize()\n");

    // Cast self to consumer type
    mc_parameter_getvalue_consumer_t *consumer = (mc_parameter_getvalue_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    // The mutex will be unlocked at the end of the finalize function
    mc_parameter_getvalue_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    // Register the consumer request handler
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        MC_AREA_NUMBER,
        MC_AREA_VERSION,
        MC_PARAMETER_SERVICE_NUMBER,
        MC_PARAMETER_GETVALUE_OPERATION_NUMBER,
        mc_parameter_getvalue_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error and return error code
        clog_error(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_initialize: error register consumer request handler\n");

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);

        // Return the error code
        return rc;
    }

    // Get number of parameters requested
    unsigned int param_inst_id_list_size = mc_parameter_getvalue_consumer_get_field_param_inst_id_list_size(consumer);

    // Build the paramInstIds request field
    mal_long_list_t *param_inst_id_list = mal_long_list_new(param_inst_id_list_size);
    mal_long_t *content = mal_long_list_get_content(param_inst_id_list);
    bool *presence_flag = mal_long_list_get_presence_flags(param_inst_id_list);

    // Construct the message content
    for(unsigned int i = 0; i < param_inst_id_list_size; i++)
    {
        content[i] = (mal_long_t)consumer->param_inst_id_list[i];
        presence_flag[i] = true;
    }

    // Get the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the field
    clog_debug(mc_parameter_getvalue_consumer_logger,
        "mc_parameter_getvalue_consumer_initialize: encoding_length_0 for paramInstIds\n");

    rc = mc_parameter_getvalue_request_add_encoding_length_0(encoder, param_inst_id_list, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_initialize: error encoding_length_0 for paramInstIds\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the MAL encoder
        free(encoder);

        // Destroy the field
        mal_long_list_destroy(&param_inst_id_list);

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);

        // Return the error code
        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(mc_parameter_getvalue_consumer_logger,
        "mc_parameter_getvalue_consumer_initialize: new MAL message\n");

    // The MAL Message object will be destroyed in the consumer's destructor
    mal_message_t *message = nmfapi_util_create_mal_message(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the paramInstIds field
    clog_debug(mc_parameter_getvalue_consumer_logger,
        "mc_parameter_getvalue_consumer_initialize: encode_0 for paramInstIds\n");

    rc = mc_parameter_getvalue_request_encode_0(cursor, encoder, param_inst_id_list);

    // Assert MAL encoder cursor
    mal_encoder_cursor_assert(encoder, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_initialize: error encode_0 for paramInstIds\n");

        // Destroy the field
        mal_long_list_destroy(&param_inst_id_list);

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
    clog_debug(mc_parameter_getvalue_consumer_logger,
        "mc_parameter_getvalue_consumer_initialize: send getValue request message\n");

    rc = mc_parameter_getvalue_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    // Destroy the field
    mal_long_list_destroy(&param_inst_id_list);

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
        clog_error(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_initialize: error sending getValue request message\n");

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);
    }

    // Return the return code
    return rc;
}


//  The consumer finalization function
int
mc_parameter_getvalue_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    mc_parameter_getvalue_consumer_t *consumer = (mc_parameter_getvalue_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);
   
    // Unlock the mutex
    mc_parameter_getvalue_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The consumer response function
int
mc_parameter_getvalue_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // Log debug
    clog_debug(mc_parameter_getvalue_consumer_logger, "mc_parameter_getvalue_consumer_response()\n");

    // The response fields
    mc_parameter_parametervaluedetails_t **content;
    mc_parameter_parametervaluedetails_list_t *param_value_details;

    // Cast consumer type
    mc_parameter_getvalue_consumer_t *consumer = (mc_parameter_getvalue_consumer_t *) self;

    // Initialize the response error code to no error
    consumer->response_error_code = 0;

    // Get the MAL message decoder
    mal_decoder_t *decoder = malbinary_decoder_new(false);

    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    // Log the offset
    clog_debug(mc_parameter_getvalue_consumer_logger, 
        "mc_parameter_getvalue_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // Check if received error message
    if(mal_message_is_error_message(message))
    {
        // Log error
        clog_error(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_response: received error message for getValue request\n");

        // Set error code to error value
        consumer->response_error_code = -1;
    }
    else
    {

        // Decode the response
        clog_debug(mc_parameter_getvalue_consumer_logger, 
            "mc_parameter_getvalue_consumer_response: decode_0 for paramValDetails\n");
        
        consumer->response_error_code = mc_parameter_getvalue_request_response_decode_0(cursor, decoder, &param_value_details);
        
        // Assert decoder cursor
        mal_decoder_cursor_assert(decoder, cursor);

        // Check for errors
        if(consumer->response_error_code != 0)
        {
            // Log error
            clog_error(mc_parameter_getvalue_consumer_logger,
                "mc_parameter_getvalue_consumer_response: error decode_0 for paramValDetails\n");
        }
        else // No error, allocate memory for response lists
        {
            // Get element count
            consumer->response_element_count = mc_parameter_parametervaluedetails_list_get_element_count(param_value_details);

            // Allocate memory for the MAL attributes response
            consumer->response_mal_attribute_list = (union mal_attribute_t *) calloc(consumer->response_element_count, sizeof(union mal_attribute_t));
            if (!consumer->response_mal_attribute_list && (consumer->response_element_count > 0))
            {
                // Log error
                clog_error(mc_parameter_getvalue_consumer_logger,
                    "mc_parameter_getvalue_consumer_response: memory allocation error for response mal attributes\n");

                // Destroy consumer's response MAL attributes
                mc_parameter_getvalue_consumer_response_clear(consumer);

                // Set and return the error code
                consumer->response_error_code = -1;
            }

            // Allocate memory for the MAL attributes tags response
            consumer->response_mal_attribute_tag_list = (unsigned char *) calloc(consumer->response_element_count, sizeof(unsigned char));
            if (!consumer->response_mal_attribute_tag_list && (consumer->response_element_count > 0))
            {
                // Log error
                clog_error(mc_parameter_getvalue_consumer_logger,
                    "mc_parameter_getvalue_consumer_response: memory allocation error for response mal attributes tags\n");

                // Destroy consumer's response MAL attributes and MAL attributes tags
                mc_parameter_getvalue_consumer_response_clear(consumer);

                // Set and return the error code
                consumer->response_error_code = -1;
            }
        }

        // Set response variables if no errors so far
        if(consumer->response_error_code == 0)
        {
            // Get content of the response
            content = mc_parameter_parametervaluedetails_list_get_content(param_value_details);

            // Fetch and set response variables
            for (unsigned int i = 0; i < consumer->response_element_count; i++)
            {
                if (content[i] != NULL)
                {
                    // Get the response parameter value object
                    // Note that param_value will be destroyed later when invoking mc_parameter_parametervaluedetails_destroy()
                    // The mc_parameter_parametervaluedetails_destroy function will invoke mc_parameter_parametervalue_destroy()
                    mal_long_t param_id = mc_parameter_parametervaluedetails_get_paramid(content[i]);
                    mc_parameter_parametervalue_t *param_value = mc_parameter_parametervaluedetails_get_value(content[i]);

                    // Get response tag and attribute values
                    unsigned char tag = mc_parameter_parametervalue_rawvalue_get_attribute_tag(param_value);
                    union mal_attribute_t attr = mc_parameter_parametervalue_get_rawvalue(param_value);

                    // Set the response tag to the respons tag buffer
                    consumer->response_mal_attribute_tag_list[i] = tag;

                    // After exiting this for loop the mc_parameter_parametervaluedetails_destroy() destructor function will be invoked
                    // This will destroy char pointer attributes, i.e. attributes of type Blob, Identifier, String, and URI
                    // Whenever we encounter these attribute types we make sure to create new objects so that their values can persist
                    // elsewhere in memory after calling the mc_parameter_parametervaluedetails_destroy() destructor function
                    // WARNING: The client is responsible for destroying these objects
                    if(tag == MAL_BLOB_ATTRIBUTE_TAG)
                    {
                        consumer->response_mal_attribute_list[i].blob_value = mal_blob_create(
                            mal_blob_get_content(attr.blob_value), mal_blob_get_length(attr.blob_value));
                    }
                    else if(tag == MAL_IDENTIFIER_ATTRIBUTE_TAG)
                    {
                        consumer->response_mal_attribute_list[i].identifier_value = mal_identifier_new(attr.identifier_value);
                    }
                    else if(tag == MAL_STRING_ATTRIBUTE_TAG)
                    {
                        consumer->response_mal_attribute_list[i].string_value = mal_string_new(attr.string_value);
                    }
                    else if(tag == MAL_URI_ATTRIBUTE_TAG)
                    {
                        consumer->response_mal_attribute_list[i].uri_value = mal_uri_new(attr.uri_value);
                    }
                    else
                    {
                        consumer->response_mal_attribute_list[i] = attr;
                    }
                }
                else
                {
                    // Log error and exit function with error code
                    clog_error(mc_parameter_getvalue_consumer_logger,
                        "mc_parameter_getvalue_consumer_response: encountered null content\n");
                        
                    consumer->response_error_code = -1;
                    break;
                }
            }
        }

        // Cleanup
        clog_debug(mc_parameter_getvalue_consumer_logger,
            "mc_parameter_getvalue_consumer_response: cleanup\n");

        // Destroy fields
        if(param_value_details)
        {
            mc_parameter_parametervaluedetails_list_destroy(&param_value_details);
        }
    }

    // Destroy the MAL decoder cursor
    mal_decoder_cursor_destroy(decoder, cursor);

    // Destroy the MAL binary decoder
    free(decoder);
    
    // Destroy MAL message
    mal_message_destroy(&message, mal_ctx);
    
    // Terminating the actor thread will trigger the finalize function
    mal_actor_term(consumer->actor);

    // Return the return code
    return consumer->response_error_code;
}