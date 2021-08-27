/*  =========================================================================
    mc_parameter_get_value_consumer - The request consumer for the getValue operation.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_get_value_consumer - The request consumer for the getValue operation.
@discuss
@end
*/

#include "nmfapi_classes.h"


//  --------------------------------------------------------------------------
//  Logging

//  The class logger
clog_logger_t mc_parameter_get_value_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
mc_parameter_get_value_consumer_set_log_level (int level)
{
    mc_parameter_get_value_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _mc_parameter_get_value_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_actor_t *actor;
    long *param_inst_ids;
    size_t param_inst_ids_size;
    union mal_attribute_t *response_mal_attributes;
    unsigned char *response_mal_attributes_tags;
    size_t response_mal_attributes_count;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t mc_parameter_get_value_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions

int
mc_parameter_get_value_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_get_value_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
mc_parameter_get_value_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_get_value_consumer

mc_parameter_get_value_consumer_t *
mc_parameter_get_value_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_new()\n");

    mc_parameter_get_value_consumer_t *self = (mc_parameter_get_value_consumer_t *) zmalloc (sizeof (mc_parameter_get_value_consumer_t));
    assert (self);
    
    //  Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_get_value_consumer

void
mc_parameter_get_value_consumer_destroy (mc_parameter_get_value_consumer_t **self_p)
{
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        mc_parameter_get_value_consumer_t *self = *self_p;

        //  Free class properties here

        // Clear response variables
        mc_parameter_get_value_consumer_response_clear(self);

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
mc_parameter_get_value_consumer_response_clear (mc_parameter_get_value_consumer_t *self)
{
    // Log debug
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response_clear()\n");

    if (self)
    {
        if (self->response_mal_attributes_count > 0)
        {
            // Reset attributes count to zero
            self->response_mal_attributes_count = 0;

            // Clear MAL attributes
            free(self->response_mal_attributes);
            self->response_mal_attributes = NULL;

            // Clear MAL attributes tags
            free(self->response_mal_attributes_tags);
            self->response_mal_attributes_tags = NULL;
        }
    }
}

//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_get_value_consumer_mutex_lock (mc_parameter_get_value_consumer_t *self)
{
    pthread_mutex_lock(&mc_parameter_get_value_consumer_mutex);
}


//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
mc_parameter_get_value_consumer_mutex_unlock (mc_parameter_get_value_consumer_t *self)
{
    pthread_mutex_unlock(&mc_parameter_get_value_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
mc_parameter_get_value_consumer_actor_init (mc_parameter_get_value_consumer_t *self)
{
    mal_uri_t *consumer_uri = mal_ctx_create_uri(self->mal_ctx, MC_PARAMETER_GET_VALUE_CONSUMER_URI);
    self->actor = mal_actor_new(self->mal_ctx, consumer_uri, self,
        mc_parameter_get_value_consumer_initialize, mc_parameter_get_value_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

long *
mc_parameter_get_value_consumer_get_field_param_inst_ids (mc_parameter_get_value_consumer_t *self)
{
    return self->param_inst_ids;
}

void
mc_parameter_get_value_consumer_set_field_param_inst_ids (mc_parameter_get_value_consumer_t *self, long *param_inst_ids)
{
    self->param_inst_ids = param_inst_ids;
}

size_t
mc_parameter_get_value_consumer_get_field_param_inst_ids_size (mc_parameter_get_value_consumer_t *self)
{
    return self->param_inst_ids_size;
}

void
mc_parameter_get_value_consumer_set_field_param_inst_ids_size (mc_parameter_get_value_consumer_t *self, size_t param_inst_ids_size)
{
    self->param_inst_ids_size = param_inst_ids_size;
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for the mal attributes
union mal_attribute_t *
mc_parameter_get_value_consumer_get_response_mal_attributes (mc_parameter_get_value_consumer_t *self)
{
    return self->response_mal_attributes;
}

//  Get response variable for the mal attributes tags
unsigned char *
mc_parameter_get_value_consumer_get_response_mal_attributes_tags (mc_parameter_get_value_consumer_t *self)
{
    return self->response_mal_attributes_tags;
}

//  Get response variable for number of MAL attributes
size_t
mc_parameter_get_value_consumer_get_response_mal_attributes_count (mc_parameter_get_value_consumer_t *self)
{
    return self->response_mal_attributes_count;
}

//  Get error code from processing the response
int
mc_parameter_get_value_consumer_get_response_error_code (mc_parameter_get_value_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization function
int
mc_parameter_get_value_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_initialize()\n");

    // Cast self to consumer type
    mc_parameter_get_value_consumer_t *consumer = (mc_parameter_get_value_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    // The mutex will be unlocked at the end of the finalize function
    mc_parameter_get_value_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        MC_AREA_NUMBER,
        MC_AREA_VERSION,
        MC_PARAMETER_SERVICE_NUMBER,
        MC_PARAMETER_GETVALUE_OPERATION_NUMBER,
        mc_parameter_get_value_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error and return error code
        clog_error(mc_parameter_get_value_consumer_logger,
            "mc_parameter_get_value_consumer_initialize: error register consumer request handler\n");

        // Return the error code
        return rc;
    }

    // Get number of parameters requested
    size_t param_inst_ids_size = mc_parameter_get_value_consumer_get_field_param_inst_ids_size(consumer);

    // Build the paramInstIds request field
    mal_long_list_t *param_inst_ids = mal_long_list_new(param_inst_ids_size);
    mal_long_t *content = mal_long_list_get_content(param_inst_ids);
    bool *presence_flag = mal_long_list_get_presence_flags(param_inst_ids);

    // Construct the message content
    for(size_t i = 0; i < param_inst_ids_size; i++)
    {
        content[i] = (mal_long_t)consumer->param_inst_ids[i];
        presence_flag[i] = true;
    }

    // Get the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the field
    clog_debug(mc_parameter_get_value_consumer_logger,
        "mc_parameter_get_value_consumer_initialize: encoding_length_0 for paramInstIds\n");

    rc = mc_parameter_getvalue_request_add_encoding_length_0(encoder, param_inst_ids, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger,
            "mc_parameter_get_value_consumer_initialize: error encoding_length_0 paramInstIds\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the field
        mal_long_list_destroy(&param_inst_ids);

        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(mc_parameter_get_value_consumer_logger,
        "mc_parameter_get_value_consumer_initialize: new MAL message\n");

    mal_message_t *message = nmfapi_util_create_mal_message_request(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the paramInstIds field
    clog_debug(mc_parameter_get_value_consumer_logger,
        "mc_parameter_get_value_consumer_initialize: encode_0 for paramInstIds\n");

    rc = mc_parameter_getvalue_request_encode_0(cursor, encoder, param_inst_ids);
    mal_encoder_cursor_assert(encoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger,
            "mc_parameter_get_value_consumer_initialize: error encode_0 paramInstIds\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the field
        mal_long_list_destroy(&param_inst_ids);

        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    clog_debug(mc_parameter_get_value_consumer_logger,
        "mc_parameter_get_value_consumer_initialize: send getValue request message\n");

    rc = mc_parameter_getvalue_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    clog_debug(mc_parameter_get_value_consumer_logger,
        "mc_parameter_get_value_consumer_initialize: sent getValue request message, %d\n", rc);

    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger,
            "mc_parameter_get_value_consumer_initialize: error getValue request\n");
    }

    // Destroy the field
    mal_long_list_destroy(&param_inst_ids);

    // Return the return code
    return rc;
}


//  The consumer finalization function
int
mc_parameter_get_value_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    mc_parameter_get_value_consumer_t *consumer = (mc_parameter_get_value_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);
   
    // Unlock the mutex
    mc_parameter_get_value_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The consumer response function
int
mc_parameter_get_value_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // Log debug
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    mc_parameter_get_value_consumer_t *consumer = (mc_parameter_get_value_consumer_t *) self;

    // Get the MAL message decoder
    mal_decoder_t *decoder = malbinary_decoder_new(false);

    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    // Log the offset
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // Decode the response
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: decode_0 paramValDetails\n");
    mc_parameter_parametervaluedetails_list_t *param_value_details;
    rc = mc_parameter_getvalue_request_response_decode_0(cursor, decoder, &param_value_details);
    mal_decoder_cursor_assert(decoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: error decode_0 paramValDetails\n");

        // Destroy
        mal_decoder_cursor_destroy(decoder, cursor);
        mc_parameter_parametervaluedetails_list_destroy(&param_value_details);
        mal_message_destroy(&message, mal_ctx);

        // Cleanup
        mal_actor_term(consumer->actor);

        // Set and return the error code
        consumer->response_error_code = rc;
        return rc;
    }

    // Destroy the MAL decoder cursor
    mal_decoder_cursor_destroy(decoder, cursor);

    // Get content of the response
    mc_parameter_parametervaluedetails_t **content = mc_parameter_parametervaluedetails_list_get_content(param_value_details);

    // Get element count
    size_t element_count = mc_parameter_parametervaluedetails_list_get_element_count(param_value_details);

    // Set response variable for element count
    consumer->response_mal_attributes_count = element_count;

    // Allocate memory for the MAL attributes response
    consumer->response_mal_attributes = (union mal_attribute_t *) calloc(consumer->response_mal_attributes_count, sizeof(union mal_attribute_t));
    if (!consumer->response_mal_attributes && (consumer->response_mal_attributes_count > 0))
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: memory allocation error for response mal attributes\n");

        // Destroy consumer's response MAL attributes
        mc_parameter_get_value_consumer_response_clear(consumer);

        // Destroy the content object
        mc_parameter_parametervaluedetails_destroy(content);

        // Set and return the error code
        consumer->response_error_code = -1;
        return consumer->response_error_code;
    }

    // Allocate memory for the MAL attributes tags response
    consumer->response_mal_attributes_tags = (unsigned char *) calloc(consumer->response_mal_attributes_count, sizeof(unsigned char));
    if (!consumer->response_mal_attributes_tags && (consumer->response_mal_attributes_count > 0))
    {
        // Log error
        clog_error(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: memory allocation error for response mal attributes tags\n");

        // Destroy consumer's response MAL attributes and MAL attributes tags
        mc_parameter_get_value_consumer_response_clear(consumer);

        // Destroy the content object
        mc_parameter_parametervaluedetails_destroy(content);

        // Set and return the error code
        consumer->response_error_code = -1;
        return consumer->response_error_code;
    }

    // Fetch and set response variables
    for (size_t i = 0; i < consumer->response_mal_attributes_count; i++)
    {
        if (content[i] != NULL)
        {
            // Get the response parameter value object
            mal_long_t param_id = mc_parameter_parametervaluedetails_get_paramid(content[i]);
            mc_parameter_parametervalue_t *param_value = mc_parameter_parametervaluedetails_get_value(content[i]);

            // Get response tag and attribute values
            unsigned char tag = mc_parameter_parametervalue_rawvalue_get_attribute_tag(param_value);
            union mal_attribute_t attr = mc_parameter_parametervalue_get_rawvalue(param_value);

            // Set the response tag to the respons tag buffer
            consumer->response_mal_attributes_tags[i] = tag;

            // After exiting this for loop the mc_parameter_parametervaluedetails_destroy() destructor function will be invoked
            // This will destroy char pointer attributes, i.e. attributes of type Blob, Identifier, String, and URI
            // Whenever we encounter these attribute types we make sure to create new objects so that their values can persist
            // elsewhere in memory after calling the mc_parameter_parametervaluedetails_destroy() destructor function
            // WARNING: The client is responsible for destroying these objects
            if(tag == MAL_BLOB_ATTRIBUTE_TAG)
            {
                consumer->response_mal_attributes[i].blob_value = mal_blob_create(
                    mal_blob_get_content(attr.blob_value), mal_blob_get_length(attr.blob_value));
            }
            else if(tag == MAL_IDENTIFIER_ATTRIBUTE_TAG)
            {
                consumer->response_mal_attributes[i].identifier_value = mal_identifier_new(attr.identifier_value);
            }
            else if(tag == MAL_STRING_ATTRIBUTE_TAG)
            {
                consumer->response_mal_attributes[i].string_value = mal_string_new(attr.string_value);
            }
            else if(tag == MAL_URI_ATTRIBUTE_TAG)
            {
                consumer->response_mal_attributes[i].uri_value = mal_uri_new(attr.uri_value);
            }
            else
            {
                consumer->response_mal_attributes[i] = attr;
            }
        }
        else
        {
            // Log error and exit function with error code
            clog_error(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: encountered null content\n");
            rc = -1;
            break;
        }
    }

    // Set the error code
    consumer->response_error_code = rc;

    // Cleanup
    clog_debug(mc_parameter_get_value_consumer_logger, "mc_parameter_get_value_consumer_response: cleanup\n");

    // Only destroy the mc_parameter_parametervaluedetails_t object if it was initialized
    if(content)
    {
        // This will also destroy f_value object of type mc_parameter_parametervalue_t
        mc_parameter_parametervaluedetails_destroy(content);
    }

    // Destroy fields
    mc_parameter_parametervaluedetails_list_destroy(&param_value_details);

    // Destroy MAL message
    mal_message_destroy(&message, mal_ctx);

    // Terminating the actor thread will trigger the finalize function
    mal_actor_term(consumer->actor);

    // Return the return code
    return rc;
}