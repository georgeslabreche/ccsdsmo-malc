/*  =========================================================================
    mc_parameter_service - The parameter service allows the user to subscribe
    to parameter value report and optionally be able to set new values.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_parameter_service - The parameter service allows the user to subscribe to parameter value report
    and optionally be able to set new values.
@discuss
@end
*/

#include "nmfapi_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t mc_parameter_service_logger = CLOG_DEBUG_LEVEL;

//  Set the log level
void
mc_parameter_service_set_log_level (int level)
{
    mc_parameter_service_logger = level;
}


//  --------------------------------------------------------------------------
//  Structure of our class

struct _mc_parameter_service_t {
    char *hostname;
    char *provider_port;
    char *consumer_port;
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
};

// The consumers
mc_parameter_get_value_consumer_t *get_value_consumer;
mc_parameter_set_value_consumer_t *set_value_consumer;
mc_parameter_list_definition_consumer_t *list_definition_consumer;


//  --------------------------------------------------------------------------
//  Create a new mc_parameter_service

mc_parameter_service_t *
mc_parameter_service_new (char *hostname, char *provider_port, char *consumer_port)
{
    mc_parameter_service_t *self = (mc_parameter_service_t *) zmalloc (sizeof (mc_parameter_service_t));
    assert (self);

    // Initialize class properties here
    self->hostname = hostname;
    self->provider_port = provider_port;
    self->consumer_port = consumer_port;

    // Create provider URI
    char *provider_id = "nanosat-mo-supervisor-Parameter";
    self->provider_uri = nmfapi_util_create_uri(MALTCP_URI, hostname, provider_port, provider_id);
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_new: provider URI: %s\n", self->provider_uri);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_parameter_service

void
mc_parameter_service_destroy (mc_parameter_service_t **self_p)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_destroy()\n");

    assert (self_p);
    if (*self_p) {
        mc_parameter_service_t *self = *self_p;

        // Free class properties here

        // Destroy the listDefinition consumer
        if(list_definition_consumer) // FIXME: will response be cleared because consumer gets destroyed in mc_parameter_service_list_definition?
        {
            // Clear the response variables
            mc_parameter_list_definition_consumer_response_clear(list_definition_consumer);

            // Destroy the consumer
            mc_parameter_list_definition_consumer_destroy(&list_definition_consumer);
        }

        // Destroy the getValue consumer
        if(get_value_consumer) // FIXME: will response be cleared because consumer gets destroyed in mc_parameter_service_get_value_list?
        {
            // Clear the response variables
            mc_parameter_get_value_consumer_response_clear(get_value_consumer);

            // Destroy the consumer
            mc_parameter_get_value_consumer_destroy(&get_value_consumer);
        }

        // Destroy the getValue consumer
        if(set_value_consumer) // FIXME: will response be cleared because consumer gets destroyed in mc_parameter_service_get_value_list?
        {
            // Destroy the consumer
            mc_parameter_set_value_consumer_destroy(&set_value_consumer);
        }
        
        // Destroy the context
        if(self->mal_ctx)
        {
            mal_ctx_destroy(&self->mal_ctx);
        }
        
        // Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  The listDefinition operation allows a consumer to request the latest object instance identifiers
//  of the ParameterIdentity and ParameterDefinition objects for the supported parameters of the provider

int
mc_parameter_service_list_definition (mc_parameter_service_t *self, char **param_name_list, size_t param_name_list_size,
    long **response_identity_id_list, long **response_definition_id_list, size_t *response_element_count)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_list_definition()\n");

    // The return code
    int rc;

    // Initialize the consumer context / listening socket
    nmfapi_util_init_maltcp_ctx(self->hostname, self->consumer_port, &self->mal_ctx);

    // Create the getValue consumer
    list_definition_consumer = mc_parameter_list_definition_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field.
    mc_parameter_list_definition_consumer_set_field_param_name_list(list_definition_consumer, param_name_list);

    // Set the param size MAL message field.
    mc_parameter_list_definition_consumer_set_field_param_name_list_size(list_definition_consumer, param_name_list_size);

    // Create and initialize the consumer actor
    mc_parameter_list_definition_consumer_actor_init(list_definition_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_list_definition_consumer_mutex_lock(list_definition_consumer);

    // Set the response pointers
    *response_identity_id_list = mc_parameter_list_definition_consumer_get_response_identity_id_list(list_definition_consumer);
    *response_definition_id_list = mc_parameter_list_definition_consumer_get_response_definition_id_list(list_definition_consumer);
    *response_element_count = mc_parameter_list_definition_consumer_get_response_element_count(list_definition_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_list_definition_consumer_get_response_error_code(list_definition_consumer);

    // Unlock the consumer mutex
    mc_parameter_list_definition_consumer_mutex_unlock(list_definition_consumer);

    // Destroy the getValue consumer
    mc_parameter_list_definition_consumer_destroy(&list_definition_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The listDefinition operation allows a consumer to request the latest object instance identifiers
//  of the ParameterIdentity and ParameterDefinition objects for the supported parameters of the provider

int
mc_parameter_service_get_definition (mc_parameter_service_t *self, char *param_name, long *response_identity_id, long *response_definition_id)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_definition()\n");

    // The return code
    int rc;

    // Create long list with single element
    char *param_name_list[] = {param_name};

    // The response pointers and element count variable
    long *response_identity_id_list;
    long *response_definition_id_list;
    size_t response_element_count;

    // Invoke the list_definitions list
    rc = mc_parameter_service_list_definition (self, param_name_list, 1,
        &response_identity_id_list, &response_definition_id_list, &response_element_count);

    // error check
    if (rc < 0)
    {
        // Log the error
        clog_error(mc_parameter_service_logger, "mc_parameter_service_get_definition: error requesting listDefinition\n");

        // Return error code
        return rc;
    }

    // Check that element count is as expected
    if(response_element_count == 1)
    {
        *response_identity_id = response_identity_id_list[0];
        *response_definition_id = response_definition_id_list[0];
    }
    else
    {
        // Log the error
        clog_error(mc_parameter_service_logger, 
            "mc_parameter_service_get_definition: retrieved unexpected element count, expected %d but was %d\n",
            1, response_element_count);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The getValue operation functions return the latest received value for the requested parameters

int
mc_parameter_service_get_value_list (mc_parameter_service_t *self, long *param_inst_id_list, size_t param_inst_id_list_size,
    union mal_attribute_t **response_mal_attribute_list, unsigned char **response_mal_attribute_tag_list,
    size_t *response_element_count)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_list()\n");

    // The return code
    int rc;

    // Initialize the consumer context / listening socket
    nmfapi_util_init_maltcp_ctx(self->hostname, self->consumer_port, &self->mal_ctx);

    // Create the getValue consumer
    get_value_consumer = mc_parameter_get_value_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field
    mc_parameter_get_value_consumer_set_field_param_inst_id_list(get_value_consumer, param_inst_id_list);

    // Set the param size MAL message field
    mc_parameter_get_value_consumer_set_field_param_inst_id_list_size(get_value_consumer, param_inst_id_list_size);

    // Create and initialize the consumer actor
    mc_parameter_get_value_consumer_actor_init(get_value_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_get_value_consumer_mutex_lock(get_value_consumer);

    // Set the response pointers
    *response_mal_attribute_list = mc_parameter_get_value_consumer_get_response_mal_attribute_list(get_value_consumer);
    *response_mal_attribute_tag_list = mc_parameter_get_value_consumer_get_response_mal_attribute_tag_list(get_value_consumer);
    *response_element_count = mc_parameter_get_value_consumer_get_response_element_count(get_value_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_get_value_consumer_get_response_error_code(get_value_consumer);

    // Unlock the consumer mutex
    mc_parameter_get_value_consumer_mutex_unlock(get_value_consumer);

    // Destroy the getValue consumer
    mc_parameter_get_value_consumer_destroy(&get_value_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}

//  The getValue operation returns the latest received value for the requested parameters
int
mc_parameter_service_get_value (mc_parameter_service_t *self, long param_inst_id,
    union mal_attribute_t *response_mal_attribute, unsigned char *response_mal_attribute_tag)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value()\n");

    // The return code
    int rc = 0;

    // Create long list with single element
    long param_inst_id_list[] = {param_inst_id};

    // The response pointers and element count variable
    union mal_attribute_t *response_mal_attribute_list;
    unsigned char *response_mal_attribute_tag_list;
    size_t response_element_count;

    // Invoke the get_values function
    rc = mc_parameter_service_get_value_list(self, param_inst_id_list, 1,
        &response_mal_attribute_list, &response_mal_attribute_tag_list, &response_element_count);

    if (rc < 0)
    {
        // Log the error
        clog_error(mc_parameter_service_logger, "mc_parameter_service_get_value: error requestion getValue\n");

        // Return error code
        return rc;
    }

    // Check that element count is as expected
    if(response_element_count == 1)
    {
        *response_mal_attribute = response_mal_attribute_list[0];
        *response_mal_attribute_tag = *response_mal_attribute_tag_list;
    }
    else
    {
        // Log the error
        clog_error(mc_parameter_service_logger, 
            "mc_parameter_service_get_value: retrieved unexpected element count, expected %d but was %d\n",
            1, response_element_count);

        // If multiple attribute were returned: destroy them all
        // Unlikely to happen but implemented for good measure
        if(response_mal_attribute_list && response_mal_attribute_tag_list)
        {
            for(int i = 0; i < response_element_count; i++)
            {
                if(response_mal_attribute_tag_list[i])
                {
                    mal_attribute_destroy(&response_mal_attribute_list[i], response_mal_attribute_tag_list[i]);
                }
            }
        }

        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_blob (mc_parameter_service_t *self, long param_inst_id, char **content, size_t *content_length)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_blob()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_BLOB_ATTRIBUTE_TAG)
    {
        *content = mal_blob_get_content(response_mal_attribute.blob_value);
        *content_length = mal_blob_get_length(response_mal_attribute.blob_value);
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_blob: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_BLOB_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_boolean (mc_parameter_service_t *self, long param_inst_id, bool *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_boolean()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_BOOLEAN_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.boolean_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_boolean: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_BOOLEAN_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_duration (mc_parameter_service_t *self, long param_inst_id, double *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_duration()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_DURATION_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.duration_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_duration: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_DURATION_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_float (mc_parameter_service_t *self, long param_inst_id, float *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_float()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_FLOAT_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.float_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_float: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_FLOAT_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_double (mc_parameter_service_t *self, long param_inst_id, double *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_double()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_DOUBLE_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.double_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_double: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_DOUBLE_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_identifier (mc_parameter_service_t *self, long param_inst_id, char **value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_identifier()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_IDENTIFIER_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.identifier_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_identifier: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_IDENTIFIER_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_octet (mc_parameter_service_t *self, long param_inst_id, char *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_octet()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_OCTET_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.octet_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_octet: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_OCTET_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_uoctet (mc_parameter_service_t *self, long param_inst_id, unsigned char *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_uoctet()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_UOCTET_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.uoctet_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_uoctet: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_UOCTET_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_short (mc_parameter_service_t *self, long param_inst_id, short *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_short()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_SHORT_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.short_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_short: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_SHORT_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_ushort (mc_parameter_service_t *self, long param_inst_id, unsigned short *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_ushort()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_USHORT_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.ushort_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_ushort: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_USHORT_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_integer (mc_parameter_service_t *self, long param_inst_id, int *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_integer()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_INTEGER_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.integer_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_integer: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_INTEGER_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_uinteger (mc_parameter_service_t *self, long param_inst_id, unsigned int *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_uinteger()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_UINTEGER_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.uinteger_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_uinteger: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_UINTEGER_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_long (mc_parameter_service_t *self, long param_inst_id, long *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_long()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_LONG_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.long_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_long: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_LONG_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_ulong (mc_parameter_service_t *self, long param_inst_id, unsigned long *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_ulong()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_ULONG_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.ulong_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_ulong: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_ULONG_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_string (mc_parameter_service_t *self, long param_inst_id, char **value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_string()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);

    // Error check
    if(rc < 0)
    {
        // Destroy the string object if it has been created despite the error
        if(response_mal_attribute.string_value)
        {
            // Not using mal_attribute_destroy() here in case response_mal_attribute_tag wasn't set.
            mal_string_destroy(&response_mal_attribute.string_value);
        }

        // Return error code
        return rc;
    }

    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_STRING_ATTRIBUTE_TAG)
    {
        // Set the response value as a new string
        // Create a new string because the MAL attribute will be destroyed (as well as its string value)
        // WARNING: The client is responsible for destroying this new object
        *value = mal_string_new(response_mal_attribute.string_value);
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_string: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_STRING_ATTRIBUTE_TAG, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Destroy the mal attribute
    mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_time (mc_parameter_service_t *self, long param_inst_id, unsigned long *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_time()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_TIME_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.time_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_time: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_TIME_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_finetime (mc_parameter_service_t *self, long param_inst_id, unsigned long *value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_finetime()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_FINETIME_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.finetime_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_finetime: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_FINETIME_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}

int
mc_parameter_service_get_value_uri (mc_parameter_service_t *self, long param_inst_id, char **value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_get_value_uri()\n");

    // The return code
    int rc = 0;

    // The response variables
    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    // Execute the getValue request interaction
    rc = mc_parameter_service_get_value(self, param_inst_id, &response_mal_attribute, &response_mal_attribute_tag);
    
    // Error check
    if(rc < 0)
    {
        // Return error code
        return rc;
    }
    
    // Check that tag is expected value
    if(response_mal_attribute_tag == MAL_URI_ATTRIBUTE_TAG)
    {
        // Set the response value
        *value = response_mal_attribute.uri_value;
    }
    else
    {
        // Log error
        clog_error(mc_parameter_service_logger,
            "mc_parameter_service_get_value_uri: retrieved unexpected tag value, expected %d but was %d\n",
            MAL_URI_ATTRIBUTE_TAG, response_mal_attribute_tag);

        // Call the MAL attribute destructor in case the erroneously fetched a String object
        // String objects are attributes of type: Blob, Identifier, String, and URI
        mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);
        
        // Set the return code to an error value
        rc = -1;
    }

    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The setValue operation functions allows setting the raw value for one or more parameters

int
mc_parameter_service_set_value_list (mc_parameter_service_t *self, long *param_inst_id_list, unsigned char *param_tag_list, char **param_value_list, size_t param_list_size)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_set_value_list()\n");

    // The return code
    int rc = 0;

    // Initialize the consumer context / listening socket
    nmfapi_util_init_maltcp_ctx(self->hostname, self->consumer_port, &self->mal_ctx);

    // Create the setValue consumer
    set_value_consumer = mc_parameter_set_value_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the MAL message param fields
    mc_parameter_set_value_consumer_set_field_param_inst_id_list(set_value_consumer, param_inst_id_list);
    mc_parameter_set_value_consumer_set_field_param_tag_list(set_value_consumer, param_tag_list);
    mc_parameter_set_value_consumer_set_field_param_value_list(set_value_consumer, param_value_list);
    mc_parameter_set_value_consumer_set_field_param_list_size(set_value_consumer, param_list_size);

     // Create and initialize the consumer actor
    mc_parameter_set_value_consumer_actor_init(set_value_consumer);

    // Start the submit response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_set_value_consumer_mutex_lock(set_value_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_set_value_consumer_get_response_error_code(set_value_consumer);

    // Unlock the consumer mutex
    mc_parameter_set_value_consumer_mutex_unlock(set_value_consumer);

    // Destroy the setValue consumer
    mc_parameter_set_value_consumer_destroy(&set_value_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}

int
mc_parameter_service_set_value (mc_parameter_service_t *self, long param_inst_id, unsigned char param_tag, char *param_value)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_set_value()\n");

    // The return code
    int rc = 0;

    // Create param inst id long list with single element
    long param_inst_id_list[] = {param_inst_id};

    // Create param attribute tag string list with single element
    unsigned char param_tag_list[] = {param_tag};

    // Create param raw value string list with single element
    char *param_value_list[] = {param_value};

    // Invole the set value list function with list parameters that only have one element
    rc = mc_parameter_service_set_value_list(self, param_inst_id_list, param_tag_list, param_value_list, 1);

    // Return the return code
    return rc;
}

int
mc_parameter_service_set_value_blob (mc_parameter_service_t *self, long param_inst_id, char *param_content, size_t param_content_length)
{
    
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_set_value_blob()\n");

    // TODO: Implement
    clog_error(mc_parameter_service_logger, "mc_parameter_service_set_value_blob: Not yet implemented\n");

    // Return the return code
    return -1;
}
