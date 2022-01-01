/*  =========================================================================
    common_directory_lookupprovider_consumer - The request consumer for the lookupProvider operation

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    common_directory_lookupprovider_consumer - The request consumer for the lookupProvider operation
@discuss
@end
*/

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

//  The class logger
clog_logger_t common_directory_lookupprovider_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
common_directory_lookupprovider_consumer_set_log_level (int level)
{
    common_directory_lookupprovider_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _common_directory_lookupprovider_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_actor_t *actor;
    common_directory_servicefilter_t *service_filter;
    common_directory_providersummary_list_t *response_provider_summary_list;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t common_directory_lookupprovider_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions

int
common_directory_lookupprovider_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
common_directory_lookupprovider_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
common_directory_lookupprovider_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new common_directory_lookupprovider_consumer

common_directory_lookupprovider_consumer_t *
common_directory_lookupprovider_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_new()\n");

    common_directory_lookupprovider_consumer_t *self = 
        (common_directory_lookupprovider_consumer_t *) zmalloc (sizeof (common_directory_lookupprovider_consumer_t));
    assert (self);
    
    // Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the common_directory_lookupprovider_consumer

void
common_directory_lookupprovider_consumer_destroy (common_directory_lookupprovider_consumer_t **self_p)
{
    // Log debug
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        common_directory_lookupprovider_consumer_t *self = *self_p;
        //  Free class properties here

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
common_directory_lookupprovider_consumer_mutex_lock (common_directory_lookupprovider_consumer_t *self)
{
    pthread_mutex_lock(&common_directory_lookupprovider_consumer_mutex);
}

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
common_directory_lookupprovider_consumer_mutex_unlock (common_directory_lookupprovider_consumer_t *self)
{
    pthread_mutex_unlock(&common_directory_lookupprovider_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
common_directory_lookupprovider_consumer_actor_init (common_directory_lookupprovider_consumer_t *self)
{
    // Create the consumer URI
    mal_uri_t *consumer_uri = mal_ctx_create_uri(self->mal_ctx, COMMON_DIRECTORY_LOOKUPPROVIDER_CONSUMER_URI);

    // Create the MAL actor
    self->actor = mal_actor_new(self->mal_ctx, consumer_uri, self,
        common_directory_lookupprovider_consumer_initialize, common_directory_lookupprovider_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

//  Get the service filter MAL message field
common_directory_servicefilter_t *
common_directory_lookupprovider_consumer_get_field_service_filter (
    common_directory_lookupprovider_consumer_t *self)
{
    return self->service_filter;
}

//  Set the service filter MAL message field
void
common_directory_lookupprovider_consumer_set_field_service_filter (
    common_directory_lookupprovider_consumer_t *self, common_directory_servicefilter_t *service_filter)
{
    self->service_filter = service_filter;
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for the provider summary
common_directory_providersummary_list_t *
common_directory_lookupprovider_consumer_get_response_provider_summary_list (
    common_directory_lookupprovider_consumer_t *self)
{
    return self->response_provider_summary_list;
}

//  Get error code from processing the response
int
common_directory_lookupprovider_consumer_get_response_error_code (common_directory_lookupprovider_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization function
int
common_directory_lookupprovider_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_initialize()\n");

    // Cast self to consumer type
    common_directory_lookupprovider_consumer_t *consumer = (common_directory_lookupprovider_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    // The mutex will be unlocked at the end of the finalize function
    common_directory_lookupprovider_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    // Register the consumer request handler
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        COMMON_AREA_NUMBER,
        COMMON_AREA_VERSION,
        COMMON_DIRECTORY_SERVICE_NUMBER,
        COMMON_DIRECTORY_LOOKUPPROVIDER_OPERATION_NUMBER,
        common_directory_lookupprovider_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error and return error code
        clog_error(common_directory_lookupprovider_consumer_logger,
            "common_directory_lookupprovider_consumer_initialize: error register consumer request handler\n");

        // Return the error code
        return rc;
    }

    // Get the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the filter field
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_initialize: encoding_length_0 for filter\n");

    rc = common_directory_lookupprovider_request_add_encoding_length_0(encoder, consumer->service_filter, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(common_directory_lookupprovider_consumer_logger,
            "common_directory_lookupprovider_consumer_initialize: error encoding_length_0 for filter\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Return the error code
        return rc;
    }

    // Build the MAL Message that will contain the filter field
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_initialize: new MAL message\n");

    mal_message_t *message = nmfapi_util_create_mal_message(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the filter field
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_initialize: encode_0 for filter\n");

    rc = common_directory_lookupprovider_request_encode_0(cursor, encoder, consumer->service_filter);
    mal_encoder_cursor_assert(encoder, cursor);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(common_directory_lookupprovider_consumer_logger,
            "common_directory_lookupprovider_consumer_initialize: error encode_0 for filter\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Return the error code
        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    clog_debug(common_directory_lookupprovider_consumer_logger,
        "common_directory_lookupprovider_consumer_initialize: send lookupProvider request message\n");

    rc = common_directory_lookupprovider_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    // Error check
    if (rc < 0)
    {
        // Log error
        clog_error(common_directory_lookupprovider_consumer_logger,
            "common_directory_lookupprovider_consumer_initialize: error sending lookupProvider request message\n");

        // Terminate the actor thread or else z_poller will wait indefinitely
        // This will trigger the finalize function
        mal_actor_term(mal_actor);
    }

    // Return the return code
    return rc;
}


//  The consumer finalization function
int
common_directory_lookupprovider_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(common_directory_lookupprovider_consumer_logger, 
        "common_directory_lookupprovider_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    common_directory_lookupprovider_consumer_t *consumer = (common_directory_lookupprovider_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);
   
    // Unlock the mutex
    common_directory_lookupprovider_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The consumer response function
int
common_directory_lookupprovider_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // Log debug
    clog_debug(common_directory_lookupprovider_consumer_logger, 
        "common_directory_lookupprovider_consumer_response()\n");

    // Cast consumer type
    common_directory_lookupprovider_consumer_t *consumer = (common_directory_lookupprovider_consumer_t *) self;

    // Initialize the response error code to no error
    consumer->response_error_code = 0;

    // Get the MAL message decoder
    mal_decoder_t *decoder = malbinary_decoder_new(false);

    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    // Log the offset
    clog_debug(common_directory_lookupprovider_consumer_logger, 
        "common_directory_lookupprovider_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // Check if received error message
    if(mal_message_is_error_message(message))
    {
        // Log error
        clog_error(common_directory_lookupprovider_consumer_logger,
            "mc_parameter_listdefinition_consumer_response: received error message for lookupProvider request\n");

        // Set error code to error value
        consumer->response_error_code = -1;
    }
    else
    {
        // Decode the response
        clog_debug(common_directory_lookupprovider_consumer_logger, 
            "common_directory_lookupprovider_consumer_response: decode_0 for matchingProviders\n");

        consumer->response_error_code = common_directory_lookupprovider_request_response_decode_0(cursor, decoder, &consumer->response_provider_summary_list);
        mal_decoder_cursor_assert(decoder, cursor);

        // Error check
        if(consumer->response_error_code != 0)
        {
            // Log error
            clog_error(common_directory_lookupprovider_consumer_logger,
                "common_directory_lookupprovider_consumer_response: error decode_0 for matchingProviders\n");

            // Destroy response object if it has been set
            if(consumer->response_provider_summary_list)
            {
                common_directory_providersummary_list_destroy(&consumer->response_provider_summary_list);
            }
        }

        // Cleanup
        clog_debug(common_directory_lookupprovider_consumer_logger,
            "common_directory_lookupprovider_consumer_response: cleanup\n");
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

    // Return the return code
    return consumer->response_error_code;
}