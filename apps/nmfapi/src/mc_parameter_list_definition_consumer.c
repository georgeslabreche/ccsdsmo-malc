/*  =========================================================================
    mc_parameter_list_definition_consumer - The request consumer for the listDefinition operation.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_list_definition_consumer - The request consumer for the listDefinition operation.
@discuss
@end
*/

#include "nmfapi_classes.h"

//  Structure of our class

struct _mc_parameter_list_definition_consumer_t {
    mal_uri_t *provider_uri;
    mal_message_args_t *mal_message_args; // TODO: Move to mal_util?
    mal_actor_t *consumer_actor; // The consumer actor
    char **param_names;
    size_t param_size;
};

//  --------------------------------------------------------------------------
//  Create a new mc_parameter_list_definition_consumer

mc_parameter_list_definition_consumer_t *
mc_parameter_list_definition_consumer_new (mal_uri_t *provider_uri)
{
    mc_parameter_list_definition_consumer_t *self = (mc_parameter_list_definition_consumer_t *) zmalloc (sizeof (mc_parameter_list_definition_consumer_t));
    assert (self);

    //  Initialize class properties here
    self->provider_uri = provider_uri;
    self->mal_message_args = mal_message_args_new();

    return self;
}

//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_list_definition_consumer

void
mc_parameter_list_definition_consumer_destroy (mc_parameter_list_definition_consumer_t **self_p, mal_ctx_t *mal_ctx)
{
    assert (self_p);
    if (*self_p) {
        mc_parameter_list_definition_consumer_t *self = *self_p;
        
        //  Free class properties here

        // Destroy mal message args
        mal_message_args_destroy(&self->mal_message_args);

        // Destroy consumer actor (if it was created)
        if(self->consumer_actor)
        {
            mal_actor_join(self->consumer_actor);
            mal_actor_destroy(mal_ctx, &self->consumer_actor);
        }

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

char **
mc_parameter_list_definition_consumer_get_field_param_names (mc_parameter_list_definition_consumer_t *self)
{
    return self->param_names;
}

void
mc_parameter_list_definition_consumer_set_field_param_names (mc_parameter_list_definition_consumer_t *self, char **param_names)
{
    self->param_names = param_names;
}

size_t
mc_parameter_list_definition_consumer_get_field_param_size (mc_parameter_list_definition_consumer_t *self)
{
    return self->param_size;
}

void
mc_parameter_list_definition_consumer_set_field_param_size (mc_parameter_list_definition_consumer_t *self, size_t param_size)
{
    self->param_size = param_size;
}

int
mc_parameter_list_definition_consumer_response (void *self, mal_ctx_t *mal_ctx,
    mal_endpoint_t *mal_endpoint, mal_message_t *message)
{
    printf("mc_parameter_list_definition_consumer_response\n");

    // The response code
    int rc = 0;

    // Cast to consumer type
    mc_parameter_list_definition_consumer_t *consumer = (mc_parameter_list_definition_consumer_t *) self;

    // Get the MAL message decoder
    mal_decoder_t *decoder = mal_message_args_get_decoder(consumer->mal_message_args);

    void *cursor = mal_decoder_new_cursor(decoder,
        mal_message_get_body(message),
        mal_message_get_body_offset(message) + mal_message_get_body_length(message),
        mal_message_get_body_offset(message));

    printf("mc_parameter_list_definition_consumer_response: offset=%d\n", mal_message_get_body_offset(message));

    // Decode the response field
    // The response shall contain a list of matching ParameterIdentity and ParameterDefinition object instance identifier pairs
    // The returned list shall maintain the same order as the submitted list unless the wildcard value was included in the request
    printf("mc_parameter_list_definition_consumer_response: decode objInstIds\n");

    mc_objectinstancepair_list_t *object_instance_pair_list;
    rc = mc_parameter_listdefinition_request_response_decode_0(cursor, decoder, &object_instance_pair_list);
    mal_decoder_cursor_assert(decoder, cursor);

    if (rc < 0)
    {
        // Destroy
        mal_decoder_cursor_destroy(decoder, cursor);
        mc_objectinstancepair_list_destroy(&object_instance_pair_list);
        mal_message_destroy(&message, mal_ctx);

        // Cleanup
        mal_actor_term(consumer->consumer_actor);

        return rc;
    }

    printf("mc_parameter_list_definition_consumer_response: get objInstIds content\n");
    mc_objectinstancepair_t **content = mc_objectinstancepair_list_get_content(object_instance_pair_list);

    mal_long_t obj_identity_instance_id;
    mal_long_t obj_def_instance_id;
    for (int i = 0; i < mc_objectinstancepair_list_get_element_count(object_instance_pair_list); i++)
    {
        obj_identity_instance_id = mc_objectinstancepair_get_objidentityinstanceid(content[i]);
        obj_def_instance_id = mc_objectinstancepair_get_objdefinstanceid(content[i]);

        printf("(%ld, %ld), \n", obj_identity_instance_id, obj_def_instance_id);
    }

    return rc;
}

int
mc_parameter_list_definition_consumer_initialize (void *self, mal_actor_t *mal_actor)
{
    // Initiate a request interaction
    printf("mc_parameter_list_definition_consumer_initialize()\n");

    // The response code
    int rc = 0;

    // Register the consumer request handler
    rc = mal_routing_register_consumer_request_handler(
        mal_actor_get_router(mal_actor),
        MC_AREA_NUMBER,
        MC_AREA_VERSION,
        MC_PARAMETER_SERVICE_NUMBER,
        MC_PARAMETER_LISTDEFINITION_OPERATION_NUMBER,
        mc_parameter_list_definition_consumer_response);

    mc_parameter_list_definition_consumer_t *consumer = (mc_parameter_list_definition_consumer_t *) self;
    printf("mc_parameter_list_definition_consumer: provider URI: %s\n", consumer->provider_uri);


    // Build the request field
    mal_identifier_list_t *param_name_mal_id_list = mal_identifier_list_new(consumer->param_size);
    mal_identifier_t **param_names_content = mal_identifier_list_get_content(param_name_mal_id_list);

    for(int i = 0; i < consumer->param_size; i++)
    {
        param_names_content[i] = mal_identifier_new(consumer->param_names[i]);
    }

    // Get the encoder
    mal_encoder_t *encoder = mal_message_args_get_encoder(consumer->mal_message_args);

    // Create a cursor
    void *cursor = mal_encoder_new_cursor(encoder);

    // Add encoding length for the field
    printf("mc_parameter_list_definition_consumer: encoding_length_0 for paramNames\n");
    rc = mc_parameter_listdefinition_request_add_encoding_length_0(encoder, param_name_mal_id_list, cursor);

    if (rc < 0)
    {
        // Destroy the MAL encoder cursor
        mal_encoder_cursor_destroy(encoder, cursor);

        // Desstroy the field
        mal_identifier_list_destroy(&param_name_mal_id_list);

        return rc;
    }

    // Build the MAL Message that will contain the field
    printf("mc_parameter_list_definition_consumer: new MAL message\n");
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

    // Encode the request field
    printf("mc_parameter_list_definition_consumer: encode 0 for paramNames\n");
    rc = mc_parameter_listdefinition_request_encode_0(
        cursor, encoder, param_name_mal_id_list);
    
    // Assert cursor
    mal_encoder_cursor_assert(encoder, cursor);

    // Destroy the MAL encoder cursor
    mal_encoder_cursor_destroy(encoder, cursor);

    // Send the request message
    mc_parameter_getvalue_request(
        mal_actor_get_mal_endpoint(mal_actor), message, consumer->provider_uri);

    // Destroy the field
    mal_identifier_list_destroy(&param_name_mal_id_list);

    return rc;
}

int
mc_parameter_list_definition_consumer_finalize (void *self, mal_actor_t *mal_actor)
{
    // The response code
    int rc = 0;

    mal_ctx_t* mal_ctx = mal_actor_get_mal_ctx(mal_actor);
    mal_ctx_stop(mal_ctx);

    return rc;
}


void
mc_parameter_list_definition_consumer_actor_create (mc_parameter_list_definition_consumer_t *self, mal_ctx_t *mal_ctx)
{
    mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, MC_PARAMETER_LIST_DEFINITION_CONSUMER_URI);

    self->consumer_actor = mal_actor_new(
        mal_ctx, consumer_uri, self,
        mc_parameter_list_definition_consumer_initialize, mc_parameter_list_definition_consumer_finalize);
}


//  --------------------------------------------------------------------------
//  Self test of this class

#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
mc_parameter_list_definition_consumer_test (bool verbose)
{
    printf (" * mc_parameter_list_definition_consumer: ");
    printf ("OK\n");
}
