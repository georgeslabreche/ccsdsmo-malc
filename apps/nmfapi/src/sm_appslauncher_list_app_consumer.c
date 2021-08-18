/*  =========================================================================
    sm_appslauncher_list_app_consumer - The request consumer for the listApp operation

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sm_appslauncher_list_app_consumer - The request consumer for the listApp operation
@discuss
@end
*/

#include <pthread.h>
#include "nmfapi_classes.h"

// Mutex
pthread_mutex_t sm_appslauncher_list_app_consumer_mutex;

// The class logger
clog_logger_t sm_appslauncher_list_app_consumer_logger = CLOG_DEBUG_LEVEL;

// Structure of our class
struct _sm_appslauncher_list_app_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_message_args_t *mal_message_args;   // TODO: Move to mal_util?
    mal_actor_t *actor;                     // The consumer actor
    char **app_names;
    size_t app_names_size;
    char *category;
    long response_apps_inst_ids[SM_APPSLAUNCHER_LIST_APP_CONSUMER_MAX_APPS_COUNT];      // Response variable for application instance ids
    bool response_apps_running[SM_APPSLAUNCHER_LIST_APP_CONSUMER_MAX_APPS_COUNT];       // Response variable for application run states
    size_t response_apps_count;                                                         // Response variable for number of applications
};

//  --------------------------------------------------------------------------
//  Declare private functions

int
sm_appslauncher_list_app_consumer_initialize (void *self, mal_actor_t *mal_actor);

int
sm_appslauncher_list_app_consumer_finalize (void *self, mal_actor_t *mal_actor);

int
sm_appslauncher_list_app_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message);


//  --------------------------------------------------------------------------
//  Create a new sm_appslauncher_list_app_consumer

sm_appslauncher_list_app_consumer_t *
sm_appslauncher_list_app_consumer_new (mal_ctx_t *mal_ctx, mal_uri_t *provider_uri)
{
    // Log debug
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_new()\n");

    sm_appslauncher_list_app_consumer_t *self = (sm_appslauncher_list_app_consumer_t *) zmalloc (sizeof (sm_appslauncher_list_app_consumer_t));
    assert (self);
    
    //  Initialize class properties here
    self->mal_ctx = mal_ctx;
    self->provider_uri = provider_uri;
    self->mal_message_args = mal_message_args_new();

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the sm_appslauncher_list_app_consumer

void
sm_appslauncher_list_app_consumer_destroy (sm_appslauncher_list_app_consumer_t **self_p)
{
    // Log debug
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_destroy()\n");

    assert (self_p);
    if (*self_p) {
        sm_appslauncher_list_app_consumer_t *self = *self_p;
        //  Free class properties here

        // Destroy consumer actor
        mal_actor_join(self->actor);
        mal_actor_destroy(self->mal_ctx, &self->actor);

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Getters and Setters

//  Set the log level
void
sm_appslauncher_list_app_consumer_set_log_level (sm_appslauncher_list_app_consumer_t *self, int level)
{
    sm_appslauncher_list_app_consumer_logger = level;
}

//  Get the app names MAL message field
char **
sm_appslauncher_list_app_consumer_get_field_app_names (sm_appslauncher_list_app_consumer_t *self)
{
    return self->app_names;
}

//  Set the app names MAL message field
void
sm_appslauncher_list_app_consumer_set_field_app_names (sm_appslauncher_list_app_consumer_t *self, char **app_names)
{
    self->app_names = app_names;
}

//  Get the size of the app names MAL message field
size_t
sm_appslauncher_list_app_consumer_get_field_app_names_size (sm_appslauncher_list_app_consumer_t *self)
{
    return self->app_names_size;
}

//  Set the size of the app names MAL message field
void
sm_appslauncher_list_app_consumer_set_field_app_names_size (sm_appslauncher_list_app_consumer_t *self, size_t app_names_size)
{
    self->app_names_size = app_names_size;
}

//  Get the category MAL message field
char *
sm_appslauncher_list_app_consumer_get_field_category (sm_appslauncher_list_app_consumer_t *self)
{
    return self->category;
}

//  Set the category MAL message field
void
sm_appslauncher_list_app_consumer_set_field_category (sm_appslauncher_list_app_consumer_t *self, char *category)
{
    self->category = category;
}

//  --------------------------------------------------------------------------
//  Getters for response variables

//  Get response variable for appsInstIds
long *
sm_appslauncher_list_app_consumer_get_response_apps_inst_ids (sm_appslauncher_list_app_consumer_t *self)
{
    return self->response_apps_inst_ids;
}

//  Get response variable for running apps
bool *
sm_appslauncher_list_app_consumer_get_response_apps_running (sm_appslauncher_list_app_consumer_t *self)
{
    return self->response_apps_running;
}

//  Get response variable for number of apps
size_t
sm_appslauncher_list_app_consumer_get_response_apps_count (sm_appslauncher_list_app_consumer_t *self)
{
    return self->response_apps_count;
}

//  --------------------------------------------------------------------------
// Thread operation for mutex locking and unlocking

//  Lock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
sm_appslauncher_list_app_consumer_lock_mutex (sm_appslauncher_list_app_consumer_t *self)
{
    pthread_mutex_lock(&sm_appslauncher_list_app_consumer_mutex);
}

//  Unlock the mutex
//  A mutex is used to force a synchronous response despite the request being an asynchronous operation
void
sm_appslauncher_list_app_consumer_unlock_mutex (sm_appslauncher_list_app_consumer_t *self)
{
    pthread_mutex_unlock(&sm_appslauncher_list_app_consumer_mutex);
}

//  --------------------------------------------------------------------------
//  Initialize the consumer actor
void
sm_appslauncher_list_app_consumer_actor_init (sm_appslauncher_list_app_consumer_t *self)
{
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_actor_init()\n");

    // Consumer URI
    mal_uri_t *consumer_uri = mal_ctx_create_uri(self->mal_ctx, SM_APPSLAUNCHER_LIST_APP_CONSUMER_URI);

    // Create actor
    self->actor = mal_actor_new(
        self->mal_ctx, consumer_uri, self,
        sm_appslauncher_list_app_consumer_initialize, sm_appslauncher_list_app_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  The consumer initialization callback function

int
sm_appslauncher_list_app_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize()\n");

    // The response code
    int rc = 0;

    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: register consumer request handler\n");
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        SOFTWAREMANAGEMENT_AREA_NUMBER,
        SOFTWAREMANAGEMENT_AREA_VERSION,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER,
        sm_appslauncher_list_app_consumer_response);

    if(rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error register consumer request handler\n");

        return rc;
    }
    
    // Cast self to consumer type
    sm_appslauncher_list_app_consumer_t *consumer = (sm_appslauncher_list_app_consumer_t *) self;

    // Initiate a request interaction
    mal_uri_t *provider_uri = consumer->provider_uri;
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: provider URI: %s\n", provider_uri);

    // The appNames field contains a list of application names
    mal_identifier_list_t *app_names = mal_identifier_list_new(consumer->app_names_size);
    mal_identifier_t **content = mal_identifier_list_get_content(app_names);

    for(unsigned int i = 0; i < consumer->app_names_size; i++)
    {
        content[i] = mal_identifier_new(consumer->app_names[i]);
    }

    // The category field contains the category identifier to filter on
    mal_identifier_t *category = mal_identifier_new(consumer->category);

    // Get the encoder
    mal_encoder_t *encoder = mal_message_args_get_encoder(consumer->mal_message_args);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the appNames field
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: add_encoding_length_0 appNames\n");
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(
        encoder, app_names, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error add_encoding_length_0 appNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_names);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Add encoding length for the category field
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: add_encoding_length_1 category\n");
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(
        encoder, category, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error add_encoding_length_1 category\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_names);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Build the MAL Message that will contain the field
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: new MAL message\n");
    mal_message_t *message = mal_message_new(
        mal_message_args_get_authentication_id(consumer->mal_message_args),
        mal_message_args_get_qoslevel(consumer->mal_message_args),
        mal_message_args_get_priority(consumer->mal_message_args),
        mal_message_args_get_domain(consumer->mal_message_args),
        mal_message_args_get_network_zone(consumer->mal_message_args),
        mal_message_args_get_session(consumer->mal_message_args),
        mal_message_args_get_session_name(consumer->mal_message_args),
        mal_encoder_cursor_get_length(encoder, cursor));


    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the appNames parameter
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: encode_0 appNames\n");
    rc = softwaremanagement_appslauncher_listapp_request_encode_0(
        cursor, encoder, app_names);
    mal_encoder_cursor_assert(encoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error encode_0 appNames\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_names);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Encode the category parameter
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: encode_1 category\n");
    rc = softwaremanagement_appslauncher_listapp_request_encode_1(
        cursor, encoder, category);
    mal_encoder_cursor_assert(encoder, cursor);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error encode_1 category\n");

        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Destroy the fields
        mal_identifier_list_destroy(&app_names);
        mal_identifier_destroy(&category);

        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: listapp request message\n");
    rc = softwaremanagement_appslauncher_listapp_request(
        mal_actor_get_mal_endpoint(mal_actor), message, provider_uri);

    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_initialize: error listapp request\n");
    }

    // Destroy the fields
    mal_identifier_list_destroy(&app_names);
    mal_identifier_destroy(&category);

    return rc;
}

//  --------------------------------------------------------------------------
//  The consumer finalization callback function

int
sm_appslauncher_list_app_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // Log debug
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_finalize()\n");

    // The response code
    int rc = 0;

    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);

    return rc;
}

//  --------------------------------------------------------------------------
//  The interaction's response callback function

int
sm_appslauncher_list_app_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response()\n");

    // The response code
    int rc = 0;

    // Cast self to consumer type
    sm_appslauncher_list_app_consumer_t *consumer = (sm_appslauncher_list_app_consumer_t *) self;

    // Get the MAL message decoder
    mal_decoder_t *decoder = mal_message_args_get_decoder(consumer->mal_message_args);

    // Create cursor
    void *cursor = mal_decoder_new_cursor(
        decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    // Log the offset
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // The appInstIds field contains a list of apps
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: decode_0 appInstIds\n");
    mal_long_list_t *apps_inst_ids;
    rc = softwaremanagement_appslauncher_listapp_request_response_decode_0(cursor, decoder, &apps_inst_ids);
    mal_decoder_cursor_assert(decoder, cursor);

    // Error check and handling
    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: error decode_0 appInstIds\n");

        // Destroy
        mal_decoder_cursor_destroy(decoder, cursor);
        mal_long_list_destroy(&apps_inst_ids);
        mal_message_destroy(&message, mal_ctx);

        // Cleanup
        mal_actor_term(consumer->actor);

        return rc;
    }
    
    // The running field contains a list of boolean values with the information about thte running status of requested apps
    // The returned lists shall maintain the same order as the submitted list unless the wildcard value was included in the appNames field request
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: decode_1 running\n");
    mal_boolean_list_t *running;
    rc = softwaremanagement_appslauncher_listapp_request_response_decode_1(cursor, decoder, &running);
    mal_decoder_cursor_assert(decoder, cursor);
    
    // Error check and handling
    if (rc < 0)
    {
        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: error decode_0 running\n");

        // Destroy
        mal_decoder_cursor_destroy(decoder, cursor);
        mal_boolean_list_destroy(&running);
        mal_message_destroy(&message, mal_ctx);

        // Cleanup
        mal_actor_term(consumer->actor);

        return rc;
    }

    // Destroy the MAL decoder cursor
    mal_decoder_cursor_destroy(decoder, cursor);

    // Check for element count equality
    size_t apps_inst_ids_count = mal_long_list_get_element_count(apps_inst_ids);
    size_t apps_running_count = mal_boolean_list_get_element_count(running);

    // Error check and handling
    if(apps_inst_ids_count != apps_running_count)
    {
        // Set error return code
        rc = -1;

        // Log error
        clog_error(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: error list sizes not equal\n");

        // Destroy
        mal_decoder_cursor_destroy(decoder, cursor);
        mal_boolean_list_destroy(&running);
        mal_message_destroy(&message, mal_ctx);

        // Cleanup
        mal_actor_term(consumer->actor);

        return rc;
    }

    // Set apps count
    consumer->response_apps_count = apps_inst_ids_count;

    // Set appInstIds values
    mal_long_t *apps_inst_ids_content = mal_long_list_get_content(apps_inst_ids);

    // The apps_inst_ids object is a mal_long_list_t that will be destroyed so we cannot point to its address
    // Copy the content into the dedicated class property
    for(int i = 0; i < consumer->response_apps_count; i++)
    {
        consumer->response_apps_inst_ids[i] = apps_inst_ids_content[i];
    }

    // Set apps running values
    mal_boolean_t *apps_running_content = mal_boolean_list_get_content(running);

    // The running object is a mal_boolean_list_t object that will be destroyed so we cannot point to its address
    // Copy the content into the dedicated class property
    for(int i = 0; i < consumer->response_apps_count; i++)
    {
        consumer->response_apps_running[i] = apps_running_content[i];
    }

    // Destroy and terminate
    clog_debug(sm_appslauncher_list_app_consumer_logger, "sm_appslauncher_list_app_consumer_response: destroy and terminate\n");

    // Destroy fields
    mal_long_list_destroy(&apps_inst_ids);
    mal_boolean_list_destroy(&running);

    // Destroy MAL message
    mal_message_destroy(&message, mal_ctx);
    
    // Terminate actor
    mal_actor_term(consumer->actor);

    // Release the mutex
    sm_appslauncher_list_app_consumer_unlock_mutex(consumer);

    return rc;
}

//  --------------------------------------------------------------------------
//  Self test of this class

#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
sm_appslauncher_list_app_consumer_test (bool verbose)
{
    printf (" * sm_appslauncher_list_app_consumer: ");
    printf ("OK\n");
}
