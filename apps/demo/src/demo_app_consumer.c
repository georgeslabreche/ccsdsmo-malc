/*  =========================================================================
    demo_app_consumer - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_app_consumer -
@discuss
@end
*/

#include "demo_classes.h"

//  Structure of our class

// state
struct _demo_app_consumer_t {
    mal_uri_t *provider_uri;
    mal_blob_t *authentication_id;
    mal_qoslevel_t qoslevel;
    mal_uinteger_t priority;
    mal_identifier_list_t *domain;
    mal_identifier_t *network_zone;
    mal_sessiontype_t session;
    mal_identifier_t *session_name;
    mal_encoder_t *encoder;
    mal_decoder_t *decoder;
};

// Consumer actor
mal_actor_t *consumer_actor = NULL;

//  --------------------------------------------------------------------------
//  Create a new demo_app_consumer

demo_app_consumer_t *
demo_app_consumer_new (mal_uri_t *provider_uri,
    mal_blob_t *authentication_id, mal_qoslevel_t qoslevel,
    mal_uinteger_t priority, mal_identifier_list_t *domain,
    mal_identifier_t *network_zone, mal_sessiontype_t session,
    mal_identifier_t *session_name,
    mal_encoder_t *encoder, mal_decoder_t *decoder)
{
    demo_app_consumer_t *self = (demo_app_consumer_t *) zmalloc (sizeof (demo_app_consumer_t));
    assert (self);

    //  Initialize class properties here
    self->provider_uri = provider_uri;
    self->authentication_id = authentication_id;
    self->qoslevel = qoslevel;
    self->priority = priority;
    self->domain = domain;
    self->network_zone = network_zone;
    self->session = session;
    self->session_name = session_name;
    self->encoder = encoder;
    self->decoder = decoder;

    return self;
}


//  --------------------------------------------------------------------------
//  Create the consumer
int demo_app_consumer_actor_create(
    bool verbose,
    mal_ctx_t *mal_ctx,
    mal_uri_t *provider_uri,
    mal_encoder_t *encoder,
    mal_decoder_t *decoder)
{

    int rc = 0;

    printf(" * demo_app_create_consumer: \n");

    mal_blob_t *authentication_id = mal_blob_new(0);
    mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
    mal_uinteger_t priority = 4;
    mal_identifier_list_t *domain = mal_identifier_list_new(0);
    mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
    mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
    mal_identifier_t *session_name = mal_identifier_new("LIVE");

    demo_app_consumer_t *consumer = demo_app_consumer_new(provider_uri,
        authentication_id, qoslevel, priority, domain, network_zone, session,
        session_name, encoder, decoder);

    mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "demo_app/consumer");
    printf("demo_app: consumer URI: %s\n", consumer_uri);

    consumer_actor = mal_actor_new(
        mal_ctx,
        consumer_uri, consumer,
        demo_app_consumer_initialize, demo_app_consumer_finalize);

    return rc;
}

//  --------------------------------------------------------------------------
//  Initialize
int demo_app_consumer_initialize(void *self, mal_actor_t *mal_actor)
{
    printf("demo_app_consumer_initialize()\n");

    // The response code
    int rc = 0;

    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        SOFTWAREMANAGEMENT_AREA_NUMBER,
        SOFTWAREMANAGEMENT_AREA_VERSION,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_SERVICE_NUMBER,
        SOFTWAREMANAGEMENT_APPSLAUNCHER_LISTAPP_OPERATION_NUMBER,
        demo_app_consumer_request_response);

    demo_app_consumer_t *consumer = (demo_app_consumer_t *) self;

    // Initiate a request interaction
    mal_uri_t *provider_uri = consumer->provider_uri;
    printf("demo_app_consumer: provider URI: %s\n", provider_uri);

    // Build appNames and category parameters

    // The appNames field contains a list of application names
    mal_identifier_list_t *appNames = mal_identifier_list_new(1);
    mal_identifier_t **appNames_content = mal_identifier_list_get_content(appNames);
    appNames_content[0] = mal_identifier_new("*");

    // The category field contains the category identifier to filter on
    mal_identifier_t *category = mal_identifier_new("*");

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(consumer->encoder);

    // Add encoding length for the parameters
    
    printf("demo_app_consumer: encoding_length_0 for appNames\n");
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_0(
        consumer->encoder, appNames, cursor);

    if (rc < 0)
    {
        return rc;
    }

    printf("demo_app_consumer: encoding_length_1 for category\n");
    rc = softwaremanagement_appslauncher_listapp_request_add_encoding_length_1(
        consumer->encoder, category, cursor);
    if (rc < 0)
    {
        return rc;
    }

    // Build the MAL Message that will contain the parameters
    printf("demo_app_consumer: new MAL message\n");
        mal_message_t *message = mal_message_new(consumer->authentication_id,
        consumer->qoslevel, consumer->priority, consumer->domain,
        consumer->network_zone, consumer->session, consumer->session_name,
        mal_encoder_cursor_get_length(consumer->encoder, cursor));

    // Initialize the MAL encoder cursor
    mal_encoder_cursor_init(
        consumer->encoder, cursor,
        mal_message_get_body(message),
        mal_encoder_cursor_get_length(consumer->encoder, cursor),
        mal_message_get_body_offset(message));

    // Encode the appNames parameter
    printf("demo_app_consumer: encode 0 for appNames\n");
    rc = softwaremanagement_appslauncher_listapp_request_encode_0(
        cursor, consumer->encoder, appNames);
    mal_encoder_cursor_assert(consumer->encoder, cursor);

    if (rc < 0)
    {
        return rc;
    }

    // Encode the category parameter
    printf("demo_app_consumer: encode 1 for category\n");
    rc = softwaremanagement_appslauncher_listapp_request_encode_1(
        cursor, consumer->encoder, category);
    mal_encoder_cursor_assert(consumer->encoder, cursor);

    if (rc < 0)
    {
        return rc;
    }

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(consumer->encoder, cursor);

    // Send the request message
    printf("demo_app_consumer: listapp request message\n");
    rc = softwaremanagement_appslauncher_listapp_request(
        mal_actor_get_mal_endpoint(mal_actor), message, provider_uri);

    if (rc < 0)
    {
        return rc;
    }
    
    // Destroy parameters
    mal_identifier_list_destroy(&appNames);
    mal_identifier_destroy(&category);

    return rc;
}

//  --------------------------------------------------------------------------
//  Finalize
int demo_app_consumer_finalize(void *self, mal_actor_t *mal_actor)
{
    // The response code
    int rc = 0;

    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);

    return rc;
}

//  --------------------------------------------------------------------------
//  Request response
int demo_app_consumer_request_response(
    void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    // The response code
    int rc = 0;

    demo_app_consumer_t *consumer = (demo_app_consumer_t *) self;

    // Get response parameter from response MAL message.

    void *cursor = mal_decoder_new_cursor(
        consumer->decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    printf("demo_app_provider: offset=%d\n", mal_message_get_body_offset(message));

    // The appInstIds field contains a list of apps.
    mal_long_list_t *appInstIds;
    printf("demo_app_provider: decode appInstIds\n");
    rc = softwaremanagement_appslauncher_listapp_request_response_decode_0(cursor, consumer->decoder, &appInstIds);
    mal_decoder_cursor_assert(consumer->decoder, cursor);

    if (rc < 0)
    {
        return rc;
    }
    
    // The running field contains a list of boolean values with the information about thte running status of requested apps.
    // The returned lists shall maintain the same order as the submitted list unless the wildcard value was included in the appNames field request.
    mal_boolean_list_t *running;
    printf("demo_app_provider: decode running\n");
    rc = softwaremanagement_appslauncher_listapp_request_response_decode_1(cursor, consumer->decoder, &running);
    mal_decoder_cursor_assert(consumer->decoder, cursor);
    
    if (rc < 0)
    {
        return rc;
    }

    // Destroy the MAL decoder cursor
    mal_decoder_cursor_destroy(consumer->decoder, cursor);

    // Print appInstIds values
    printf("appInstIds=");
    mal_long_t* appInstIds_content = mal_long_list_get_content(appInstIds);
    for (int i = 0; i <  mal_long_list_get_element_count(appInstIds); i++)
    {
        printf("%ld, ", appInstIds_content[i]);
    }
    printf("\n");

    printf("destroy appInstIds\n");
    mal_long_list_destroy(&appInstIds);

    // Print running values
    printf("running=");
    mal_boolean_t* running_content = mal_boolean_list_get_content(running);
    for (int i = 0; i <  mal_boolean_list_get_element_count(running); i++)
    {
        printf("%d, ", running_content[i]);
    }

    printf("\n");

    printf("destroy running\n");
    mal_boolean_list_destroy(&running);

    printf("destroy MAL result message\n");
    mal_message_destroy(&message, mal_ctx);

    printf("Consumer done.\n");

    mal_actor_term(consumer_actor);

    return rc;
}

//  --------------------------------------------------------------------------
//  Destroy the demo_app_consumer
void
demo_app_consumer_destroy (demo_app_consumer_t **self_p, mal_ctx_t *mal_ctx)
{
    if (*self_p)
    {
        demo_app_consumer_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }

    if (consumer_actor)
    {
        mal_actor_join(consumer_actor);
        mal_actor_destroy(mal_ctx, &consumer_actor);
    }
}