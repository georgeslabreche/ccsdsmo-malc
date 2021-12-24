/*  =========================================================================
    sm_appslauncher_listapp_consumer - The request consumer for the listApp operation

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sm_appslauncher_listapp_consumer - The request consumer for the listApp operation
@discuss
@end
*/

#include <pthread.h>
#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t sm_appslauncher_listapp_consumer_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
sm_appslauncher_listapp_consumer_set_log_level (int level)
{
    sm_appslauncher_listapp_consumer_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _sm_appslauncher_listapp_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_actor_t *actor;
    char **app_name_list;
    size_t app_name_list_size;
    char *category;
    long *response_apps_inst_id_list;
    bool *response_apps_inst_running_list;
    size_t response_element_count;
    int response_error_code;
};


//  --------------------------------------------------------------------------
//  Mutex

pthread_mutex_t sm_appslauncher_listapp_consumer_mutex;


//  --------------------------------------------------------------------------
//  Declare private functions

int
sm_appslauncher_listapp_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
sm_appslauncher_listapp_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
sm_appslauncher_listapp_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new sm_appslauncher_listapp_consumer

sm_appslauncher_listapp_consumer_t *
sm_appslauncher_listapp_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_new()\n");

    sm_appslauncher_listapp_consumer_t *self = (sm_appslauncher_listapp_consumer_t *) zmalloc (sizeof (sm_appslauncher_listapp_consumer_t));
    assert (self);
    
    //  Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the sm_appslauncher_listapp_consumer

void
sm_appslauncher_listapp_consumer_destroy (sm_appslauncher_listapp_consumer_t **self_p)
{
    // Log debug
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        sm_appslauncher_listapp_consumer_t *self = *self_p;

        //  Free class properties here

        // We do not invoke the clear response variables function here (i.e. sm_appslauncher_listapp_consumer_response_clear)
        // This is because we still want those variables to be available to the client even after the 
        // sm_appslauncher_service's sm_appslauncher_listapp function is done executing.
        // The reponse variables will be cleared when invoking sm_appslauncher_service's destructor.

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
sm_appslauncher_listapp_consumer_response_clear (sm_appslauncher_listapp_consumer_t *self)
{
    // Log debug
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_response_clear()\n");

    if (self)
    {
        if (self->response_element_count > 0)
        {
            // Reset element count to zero
            self->response_element_count = 0;

            // Clear app inst id list
            free(self->response_apps_inst_id_list);
            self->response_apps_inst_id_list = NULL;

            // Clear app inst running list
            free(self->response_apps_inst_running_list);
            self->response_apps_inst_running_list = NULL;
        }
    }
}


//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
sm_appslauncher_listapp_consumer_mutex_lock (sm_appslauncher_listapp_consumer_t *self)
{
    pthread_mutex_lock(&sm_appslauncher_listapp_consumer_mutex);
}

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
sm_appslauncher_listapp_consumer_mutex_unlock (sm_appslauncher_listapp_consumer_t *self)
{
    pthread_mutex_unlock(&sm_appslauncher_listapp_consumer_mutex);
}


//  --------------------------------------------------------------------------
//  Create and initialize the actor

void
sm_appslauncher_listapp_consumer_actor_init (sm_appslauncher_listapp_consumer_t *self)
{
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_actor_init()\n");

    // Consumer URI
    mal_uri_t *consumer_uri = mal_ctx_create_uri(self->mal_ctx, SM_APPSLAUNCHER_LISTAPP_CONSUMER_URI);

    // Create actor
    self->actor = mal_actor_new(
        self->mal_ctx, consumer_uri, self,
        sm_appslauncher_listapp_consumer_initialize, sm_appslauncher_listapp_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Getters and Setters for the class variables

//  Get the app names MAL message field
char **
sm_appslauncher_listapp_consumer_get_field_app_name_list (sm_appslauncher_listapp_consumer_t *self)
{
    return self->app_name_list;
}

//  Set the app names MAL message field
void
sm_appslauncher_listapp_consumer_set_field_app_name_list (sm_appslauncher_listapp_consumer_t *self, char **app_name_list)
{
    self->app_name_list = app_name_list;
}

//  Get the size of the app names MAL message field
size_t
sm_appslauncher_listapp_consumer_get_field_app_name_list_size (sm_appslauncher_listapp_consumer_t *self)
{
    return self->app_name_list_size;
}

//  Set the size of the app names MAL message field
void
sm_appslauncher_listapp_consumer_set_field_app_name_list_size (sm_appslauncher_listapp_consumer_t *self, size_t app_name_list_size)
{
    self->app_name_list_size = app_name_list_size;
}

//  Get the category MAL message field
char *
sm_appslauncher_listapp_consumer_get_field_category (sm_appslauncher_listapp_consumer_t *self)
{
    return self->category;
}

//  Set the category MAL message field
void
sm_appslauncher_listapp_consumer_set_field_category (sm_appslauncher_listapp_consumer_t *self, char *category)
{
    self->category = category;
}


//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for appsInstIds
long *
sm_appslauncher_listapp_consumer_get_response_apps_inst_id_list (sm_appslauncher_listapp_consumer_t *self)
{
    return self->response_apps_inst_id_list;
}

//  Get response variable for running apps
bool *
sm_appslauncher_listapp_consumer_get_response_apps_inst_running_list (sm_appslauncher_listapp_consumer_t *self)
{
    return self->response_apps_inst_running_list;
}

//  Get response variable for number of apps
size_t
sm_appslauncher_listapp_consumer_get_response_element_count (sm_appslauncher_listapp_consumer_t *self)
{
    return self->response_element_count;
}

//  Get error code from processing the response
int
sm_appslauncher_listapp_consumer_get_response_error_code (sm_appslauncher_listapp_consumer_t *self)
{
    return self->response_error_code;
}


//  --------------------------------------------------------------------------
//  Private functions

//  The consumer initialization callback function
int
sm_appslauncher_listapp_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_initialize()\n");

    // Cast self to consumer type
    sm_appslauncher_listapp_consumer_t *consumer = (sm_appslauncher_listapp_consumer_t *) self;

    // Lock the consumer mutex
    // Use this mutex mechanism to force an synchronous response on an asynchronous request response mechanism
    // The mutex will be unlocked at the end of the finalize function
    sm_appslauncher_listapp_consumer_mutex_lock(consumer);

    // The response code
    int rc = 0;

    // Register the consumer request handler
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        SOFTWAREMANAGEMENT_AREA_NUMBER,
        SOFTWAREMANAGEMENT_AREA_VERSION,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER,
        sm_appslauncher_listapp_consumer_response);

    // Check for error
    if(rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error register consumer request handler\n");

        return rc;
    }

    // The appNames field contains a list of application names
    mal_identifier_list_t *app_name_list = mal_identifier_list_new(consumer->app_name_list_size);
    mal_identifier_t **content = mal_identifier_list_get_content(app_name_list);

    for(size_t i = 0; i < consumer->app_name_list_size; i++)
    {
        content[i] = mal_identifier_new(consumer->app_name_list[i]);
    }

    // The category field contains the category identifier to filter on
    mal_identifier_t *category = mal_identifier_new(consumer->category);

    // Create the encoder
    mal_encoder_t *encoder = malbinary_encoder_new(false);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the appNames field
    clog_debug(sm_appslauncher_listapp_consumer_logger,
        "sm_appslauncher_listapp_consumer_initialize: add_encoding_length_0 appNames\n");

    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(encoder, app_name_list, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error add_encoding_length_0 appNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_name_list);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Add encoding length for the category field
    clog_debug(sm_appslauncher_listapp_consumer_logger,
        "sm_appslauncher_listapp_consumer_initialize: add_encoding_length_1 category\n");

    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(encoder, category, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error add_encoding_length_1 category\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_name_list);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(sm_appslauncher_listapp_consumer_logger,
        "sm_appslauncher_listapp_consumer_initialize: new MAL message\n");

    mal_message_t *message = nmfapi_util_create_mal_message(encoder, cursor);

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the appNames field
    clog_debug(sm_appslauncher_listapp_consumer_logger, 
        "sm_appslauncher_listapp_consumer_initialize: encode_0 appNames\n");

    rc = softwaremanagement_appslauncher_listapp_request_encode_0(cursor, encoder, app_name_list);
    mal_encoder_cursor_assert(encoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error encode_0 appNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_name_list);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Encode the category field
    clog_debug(sm_appslauncher_listapp_consumer_logger, 
        "sm_appslauncher_listapp_consumer_initialize: encode_1 category\n");

    rc = softwaremanagement_appslauncher_listapp_request_encode_1(
        cursor, encoder, category);
    mal_encoder_cursor_assert(encoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error encode_1 category\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_name_list);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    clog_debug(sm_appslauncher_listapp_consumer_logger, 
        "sm_appslauncher_listapp_consumer_initialize: send listApp request message\n");

    rc = softwaremanagement_appslauncher_listapp_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_initialize: error listapp request\n");
    }

    // Destroy the fields
    mal_identifier_list_destroy(&app_name_list);
    mal_identifier_destroy(&category);

    // Return the return code
    return rc;
}


//  The consumer finalization callback function
int
sm_appslauncher_listapp_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_finalize()\n");

    // The response code
    int rc = 0;

    // Cast consumer type
    sm_appslauncher_listapp_consumer_t *consumer = (sm_appslauncher_listapp_consumer_t *) self;

    // Stop the listening socket
    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);

    // Unlock the mutex
    sm_appslauncher_listapp_consumer_mutex_unlock(consumer);

    // Return the return code
    return rc;
}


//  The interaction's response callback function
int
sm_appslauncher_listapp_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_response()\n");

    // The response variables
    mal_long_list_t *apps_inst_id_list;
    mal_boolean_list_t *apps_inst_running_list;
    size_t apps_inst_id_list_count;
    size_t apps_inst_running_list_count;

    // Cast self to consumer type
    sm_appslauncher_listapp_consumer_t *consumer = (sm_appslauncher_listapp_consumer_t *) self;

    // Initialize the response error code to no error
    consumer->response_error_code = 0;

    // Create the MAL message decoder
    mal_decoder_t *decoder = malbinary_decoder_new(false);

    // Create cursor
    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    // Log the offset
    clog_debug(sm_appslauncher_listapp_consumer_logger,
        "sm_appslauncher_listapp_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // Check if received error message
    if(mal_message_is_error_message(message))
    {
        // Log error
        clog_error(sm_appslauncher_listapp_consumer_logger,
            "sm_appslauncher_listapp_consumer_response: received error message for listApp request\n");

        // Set error code to error value
        consumer->response_error_code = -1;
    }
    else
    {

        // The appInstIds field contains a list of apps
        clog_debug(sm_appslauncher_listapp_consumer_logger, 
            "sm_appslauncher_listapp_consumer_response: decode_0 for appInstIds\n");
        
        consumer->response_error_code = softwaremanagement_appslauncher_listapp_request_response_decode_0(cursor, decoder, &apps_inst_id_list);
        mal_decoder_cursor_assert(decoder, cursor);

        // Error check and handling
        if (consumer->response_error_code != 0)
        {
            // Log error
            clog_error(sm_appslauncher_listapp_consumer_logger,
                "sm_appslauncher_listapp_consumer_response: error decode_0 for appInstIds\n");

            // Set and return the error code
            consumer->response_error_code = -1;
        }
        else // No error, get list size
        {
            apps_inst_id_list_count = mal_long_list_get_element_count(apps_inst_id_list);
        }

        // Error check
        if (consumer->response_error_code == 0)
        {
            // The running field contains a list of boolean values with the information about thte running status of requested apps
            clog_debug(sm_appslauncher_listapp_consumer_logger,
                "sm_appslauncher_listapp_consumer_response: decode_1 for running\n");
            
            consumer->response_error_code = softwaremanagement_appslauncher_listapp_request_response_decode_1(cursor, decoder, &apps_inst_running_list);
            mal_decoder_cursor_assert(decoder, cursor);

            // Error check and handling
            if (consumer->response_error_code != 0)
            {
                // Log error
                clog_error(sm_appslauncher_listapp_consumer_logger,
                    "sm_appslauncher_listapp_consumer_response: error decode_1 for running\n");

                // Set and return the error code
                consumer->response_error_code = -1;
            }
            else // No error, get list size
            {
                apps_inst_running_list_count = mal_boolean_list_get_element_count(apps_inst_running_list);
            }
        }

        // Error check
        if(consumer->response_error_code == 0)
        {
            // Check for response element count equality
            if(apps_inst_id_list_count != apps_inst_running_list_count)
            {
                // Log error
                clog_error(sm_appslauncher_listapp_consumer_logger,
                    "sm_appslauncher_listapp_consumer_response: error response list sizes not equal: %d != %d\n",
                    apps_inst_id_list_count, apps_inst_running_list_count);

                // Set and return the error code
                consumer->response_error_code = -1;
            }
            else
            {
                // Allocate memory for the apps inst id list response
                consumer->response_apps_inst_id_list = (long *) calloc(apps_inst_id_list_count, sizeof(long));

                // Error check
                if (!consumer->response_apps_inst_id_list && (apps_inst_id_list_count > 0))
                {
                    // Log error
                    clog_error(sm_appslauncher_listapp_consumer_logger,
                        "sm_appslauncher_listapp_consumer_response: memory allocation error for response apps inst id list\n");

                    // Destroy consumer's response MAL attributes
                    sm_appslauncher_listapp_consumer_response_clear(consumer);

                    // Set and return the error code
                    consumer->response_error_code = -1;
                }
                else
                {
                    // Allocate memory for the apps inst running list response
                    consumer->response_apps_inst_running_list = (bool *) calloc(apps_inst_running_list_count, sizeof(bool));

                    // Error check
                    if (!consumer->response_apps_inst_running_list && (apps_inst_running_list_count > 0))
                    {
                        // Log error
                        clog_error(sm_appslauncher_listapp_consumer_logger,
                            "sm_appslauncher_listapp_consumer_response: memory allocation error for response apps inst running list\n");

                        // Destroy consumer's response MAL attributes
                        sm_appslauncher_listapp_consumer_response_clear(consumer);

                        // Set and return the error code
                        consumer->response_error_code = -1;
                    }
                }
            }
        }

        // Error check
        if(consumer->response_error_code == 0)
        {
            // Set response element count
            consumer->response_element_count = apps_inst_id_list_count;

            // Set appInstIds values
            mal_long_t *apps_inst_id_list_content = mal_long_list_get_content(apps_inst_id_list);

            // The apps_inst_id_list object is a mal_long_list_t that will be destroyed so we cannot point to its address
            // Copy the content into the dedicated class property
            for(size_t i = 0; i < consumer->response_element_count; i++)
            {
                consumer->response_apps_inst_id_list[i] = apps_inst_id_list_content[i];
            }

            // Set apps running values
            mal_boolean_t *apps_running_content = mal_boolean_list_get_content(apps_inst_running_list);

            // The apps_inst_running_list object is a mal_boolean_list_t object that will be destroyed so we cannot point to its address
            // Copy the content into the dedicated class property
            for(size_t i = 0; i < consumer->response_element_count; i++)
            {
                consumer->response_apps_inst_running_list[i] = apps_running_content[i];
            }
        }


        // Destroy and terminate
        clog_debug(sm_appslauncher_listapp_consumer_logger, "sm_appslauncher_listapp_consumer_response: cleanup\n");

        // Destroy fields
        if(apps_inst_id_list)
        {
            mal_long_list_destroy(&apps_inst_id_list);
        }
        
        if(apps_inst_running_list)
        {
            mal_boolean_list_destroy(&apps_inst_running_list);
        }

    }

    // Destroy the MAL decoder cursor
    if(cursor)
    {
        mal_decoder_cursor_destroy(decoder, cursor);
    }
    
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