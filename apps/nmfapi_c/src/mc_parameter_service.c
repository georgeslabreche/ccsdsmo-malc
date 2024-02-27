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

#include "nmfapi_c_classes.h"


//  --------------------------------------------------------------------------
//  Logging

// The class logger
clog_logger_t mc_parameter_service_logger = CLOG_ERROR_LEVEL;

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
    mal_uri_t *provider_uri;
    mal_ctx_t *mal_ctx;
};

// The consumers
mc_parameter_getvalue_consumer_t *getvalue_consumer;
mc_parameter_setvalue_consumer_t *setvalue_consumer;
mc_parameter_listdefinition_consumer_t *listdefinition_consumer;
mc_parameter_addparameter_consumer_t *addparameter_consumer;
mc_parameter_removeparameter_consumer_t *removeparameter_consumer;

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

        //  --------------------------------------------------------------------------
        //  Destroy the consumers

        // Destroy the listDefinition consumer
        if(listdefinition_consumer)
        {
            // Clear the response variables
            mc_parameter_listdefinition_consumer_response_clear(listdefinition_consumer);

            // Destroy the consumer
            mc_parameter_listdefinition_consumer_destroy(&listdefinition_consumer);
        }

        // Destroy the getValue consumer
        if(getvalue_consumer)
        {
            // Clear the response variables
            mc_parameter_getvalue_consumer_response_clear(getvalue_consumer);

            // Destroy the consumer
            mc_parameter_getvalue_consumer_destroy(&getvalue_consumer);
        }

        // Destroy the setValue consumer
        if(setvalue_consumer)
        {
            // Destroy the consumer
            mc_parameter_setvalue_consumer_destroy(&setvalue_consumer);
        }

        // Destroy the addParameter consumer
        if(addparameter_consumer)
        {
            // Clear the response variables
            mc_parameter_addparameter_consumer_response_clear(addparameter_consumer);

            // Destroy the consumer
            mc_parameter_addparameter_consumer_destroy(&addparameter_consumer);
        }
        
        // Destroy the removeParameter consumer
        if(removeparameter_consumer)
        {
            // Destroy the consumer
            mc_parameter_removeparameter_consumer_destroy(&removeparameter_consumer);
        }


        //  --------------------------------------------------------------------------
        //  Free class properties here

        // Destroy the provider URI
        if(self->provider_uri)
        {
            mal_uri_destroy(&self->provider_uri);
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

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the getValue consumer
    listdefinition_consumer = mc_parameter_listdefinition_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field.
    mc_parameter_listdefinition_consumer_set_field_param_name_list(listdefinition_consumer, param_name_list);

    // Set the param size MAL message field.
    mc_parameter_listdefinition_consumer_set_field_param_name_list_size(listdefinition_consumer, param_name_list_size);

    // Create and initialize the consumer actor
    mc_parameter_listdefinition_consumer_actor_init(listdefinition_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_listdefinition_consumer_mutex_lock(listdefinition_consumer);

    // Set the response pointers
    *response_identity_id_list = mc_parameter_listdefinition_consumer_get_response_identity_id_list(listdefinition_consumer);
    *response_definition_id_list = mc_parameter_listdefinition_consumer_get_response_definition_id_list(listdefinition_consumer);
    *response_element_count = mc_parameter_listdefinition_consumer_get_response_element_count(listdefinition_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_listdefinition_consumer_get_response_error_code(listdefinition_consumer);

    // Unlock the consumer mutex
    mc_parameter_listdefinition_consumer_mutex_unlock(listdefinition_consumer);

    // Destroy the listDefinition consumer
    mc_parameter_listdefinition_consumer_destroy(&listdefinition_consumer);

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

    // Create list with single element
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

    // Deallocate memory
    free(response_identity_id_list);
    response_identity_id_list = NULL;

    // Deallocate memory
    free(response_definition_id_list);
    response_definition_id_list = NULL;

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

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the getValue consumer
    getvalue_consumer = mc_parameter_getvalue_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field
    mc_parameter_getvalue_consumer_set_field_param_inst_id_list(getvalue_consumer, param_inst_id_list);

    // Set the param size MAL message field
    mc_parameter_getvalue_consumer_set_field_param_inst_id_list_size(getvalue_consumer, param_inst_id_list_size);

    // Create and initialize the consumer actor
    mc_parameter_getvalue_consumer_actor_init(getvalue_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_getvalue_consumer_mutex_lock(getvalue_consumer);

    // Set the response pointers
    *response_mal_attribute_list = mc_parameter_getvalue_consumer_get_response_mal_attribute_list(getvalue_consumer);
    *response_mal_attribute_tag_list = mc_parameter_getvalue_consumer_get_response_mal_attribute_tag_list(getvalue_consumer);
    *response_element_count = mc_parameter_getvalue_consumer_get_response_element_count(getvalue_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_getvalue_consumer_get_response_error_code(getvalue_consumer);

    // Unlock the consumer mutex
    mc_parameter_getvalue_consumer_mutex_unlock(getvalue_consumer);

    // Destroy the getValue consumer
    mc_parameter_getvalue_consumer_destroy(&getvalue_consumer);

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
        clog_error(mc_parameter_service_logger, "mc_parameter_service_get_value: error requesting getValue\n");

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

    // Deallocate memory
    if(response_mal_attribute_list)
    {
        free(response_mal_attribute_list);
        response_mal_attribute_list = NULL;
    }

    // Deallocate memory
    if(response_mal_attribute_tag_list)
    {
        free(response_mal_attribute_tag_list);
        response_mal_attribute_tag_list = NULL;
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

        // Call the MAL attribute destructor in case erroneously fetched a String object
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

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the setValue consumer
    setvalue_consumer = mc_parameter_setvalue_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the MAL message param fields
    mc_parameter_setvalue_consumer_set_field_param_inst_id_list(setvalue_consumer, param_inst_id_list);
    mc_parameter_setvalue_consumer_set_field_param_tag_list(setvalue_consumer, param_tag_list);
    mc_parameter_setvalue_consumer_set_field_param_value_list(setvalue_consumer, param_value_list);
    mc_parameter_setvalue_consumer_set_field_param_list_size(setvalue_consumer, param_list_size);

     // Create and initialize the consumer actor
    mc_parameter_setvalue_consumer_actor_init(setvalue_consumer);

    // Start the submit response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_setvalue_consumer_mutex_lock(setvalue_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_setvalue_consumer_get_response_error_code(setvalue_consumer);

    // Unlock the consumer mutex
    mc_parameter_setvalue_consumer_mutex_unlock(setvalue_consumer);

    // Destroy the setValue consumer
    mc_parameter_setvalue_consumer_destroy(&setvalue_consumer);

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


//  --------------------------------------------------------------------------
//  The addParameter operation allows a consumer to define one or more parameters that do not currently exist

int
mc_parameter_service_add_parameter_list (mc_parameter_service_t *self,
    char **param_name_list, char **param_description_list, unsigned char *param_raw_type_list,
    char **param_raw_unit_list, bool *param_generation_enabled_list, double *param_report_interval_list, size_t param_list_size,
    long **response_param_identity_id_list, long **response_param_definition_id_list, size_t *response_element_count)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_add_parameter_list()\n");

    // The return code
    int rc;

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);
    
    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the addParameter consumer
    addparameter_consumer = mc_parameter_addparameter_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field
    mc_parameter_addparameter_consumer_set_field_param_name_list(addparameter_consumer, param_name_list);

    // Set the param descriptions MAL message field
    mc_parameter_addparameter_consumer_set_field_param_description_list(addparameter_consumer, param_description_list);

    // Set the param raw types MAL message field
    mc_parameter_addparameter_consumer_set_field_param_raw_type_list(addparameter_consumer, param_raw_type_list);

    // Set the param raw units MAL message field
    mc_parameter_addparameter_consumer_set_field_param_raw_unit_list(addparameter_consumer, param_raw_unit_list);

    // Set the param generation enabled MAL message field
    mc_parameter_addparameter_consumer_set_field_param_generation_enabled_list(addparameter_consumer, param_generation_enabled_list);

    // Set the param report interval MAL message field
    mc_parameter_addparameter_consumer_set_field_param_report_interval_list(addparameter_consumer, param_report_interval_list);

    // Set the param list size MAL message field
    mc_parameter_addparameter_consumer_set_field_param_list_size(addparameter_consumer, param_list_size);

    // Create and initialize the consumer actor
    mc_parameter_addparameter_consumer_actor_init(addparameter_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_addparameter_consumer_mutex_lock(addparameter_consumer);

    // Set the response pointers
    *response_param_identity_id_list = mc_parameter_addparameter_consumer_get_response_param_identity_id_list(addparameter_consumer);
    *response_param_definition_id_list = mc_parameter_addparameter_consumer_get_response_param_definition_id_list(addparameter_consumer);
    *response_element_count = mc_parameter_addparameter_consumer_get_response_element_count(addparameter_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_addparameter_consumer_get_response_error_code(addparameter_consumer);

    // Unlock the consumer mutex
    mc_parameter_addparameter_consumer_mutex_unlock(addparameter_consumer);

    // Destroy the addParameter consumer
    mc_parameter_addparameter_consumer_destroy(&addparameter_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}

//  The addParameter operation for a single parameter
int
mc_parameter_service_add_parameter (mc_parameter_service_t *self,
    char *param_name, char *param_description, unsigned char param_raw_type,
    char *param_raw_unit, bool param_generation_enabled, double param_report_interval,
    long *response_param_identity_id, long *response_param_definition_id)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_add_parameter()\n");

    // The return code
    int rc;

    // Create param name list with single element
    char *param_name_list[] = {param_name};

    // Create param description list with single element
    char *param_description_list[] = {param_description};

    // Create param raw type list with single element
    unsigned char param_raw_type_list[] = {param_raw_type};

    // Create param raw unit list with single element
    char *param_raw_unit_list[] = {param_raw_unit};

    // Create param generation_enabled list with single element
    bool param_generation_enabled_list[] = {param_generation_enabled};

    // Create param report interval list with single element
    double param_report_interval_list[] = {param_report_interval};

    // The response pointers and element count variable
    long *response_param_identity_id_list;
    long *response_param_definition_id_list;
    size_t response_element_count;

    // Invoke the addParameter function
    rc = mc_parameter_service_add_parameter_list(self,
        param_name_list,
        param_description == NULL ? NULL : param_description_list,
        param_raw_type_list,
        param_raw_unit == NULL ? NULL : param_raw_unit_list,
        param_generation_enabled_list,
        param_report_interval_list,
        1,
        &response_param_identity_id_list, &response_param_definition_id_list, &response_element_count);

    // Error check
    if (rc < 0)
    {
        // Log the error
        clog_error(mc_parameter_service_logger, "mc_parameter_service_add_parameter: error requesting addParameter\n");

        // Return error code
        return rc;
    }

    // Check that element count is as expected
    if(response_element_count == 1)
    {
        *response_param_identity_id = response_param_identity_id_list[0];
        *response_param_definition_id = response_param_definition_id_list[0];
    }
    else
    {
        // Log the error
        clog_error(mc_parameter_service_logger, 
            "mc_parameter_service_add_parameter: retrieved unexpected element count, expected %d but was %d\n",
            1, response_element_count);

        // Set the return code to an error value
        rc = -1;
    }

    // Deallocate memory
    free(response_param_identity_id_list);
    response_param_identity_id_list = NULL;

    // Deallocate memory
    free(response_param_definition_id_list);
    response_param_definition_id_list = NULL;

    // Return the return code
    return rc;
}


//  --------------------------------------------------------------------------
//  The removeParameter operation allows a consumer to remove one or more parameters from the list of parameters supported by the parameter provider

int
mc_parameter_service_remove_parameter_list (mc_parameter_service_t *self, long *param_identity_id_list, size_t param_identity_id_list_size)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_remove_parameter_list()\n");

    // The return code
    int rc;

    // Create the MAL context
    self->mal_ctx = mal_ctx_new();

    // Create MAL TCP header: all the MAL header fields are passed
    maltcp_header_t *maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);
    
    // Initialize the consumer context / listening socket
    // Create the consumer listening socket: bind to server with the consumer port number
    void *maltcp_ctx = maltcp_ctx_new(self->mal_ctx, self->hostname, self->consumer_port, maltcp_header, false);

    // Create the removeParameter consumer
    removeparameter_consumer = mc_parameter_removeparameter_consumer_new(self->mal_ctx, self->provider_uri);

    // Set the param names MAL message field
    mc_parameter_removeparameter_consumer_set_field_param_identity_id_list(removeparameter_consumer, param_identity_id_list);

    // Set the param size MAL message field
    mc_parameter_removeparameter_consumer_set_field_param_identity_id_list_size(removeparameter_consumer, param_identity_id_list_size);

    // Create and initialize the consumer actor
    mc_parameter_removeparameter_consumer_actor_init(removeparameter_consumer);

    // Start the request response listener
    mal_ctx_start(self->mal_ctx);

    // Lock the consumer mutex which has already been locked at the beginning of this function
    // The initial mutex lock will only be released after the request finalize function has finished executing
    // We do this so that the response variables can be set and return synchronously
    mc_parameter_removeparameter_consumer_mutex_lock(removeparameter_consumer);

    // Set the return code as the error code of the consumer response
    rc = mc_parameter_removeparameter_consumer_get_response_error_code(removeparameter_consumer);

    // Unlock the consumer mutex
    mc_parameter_removeparameter_consumer_mutex_unlock(removeparameter_consumer);

    // Destroy the removeParameter consumer
    mc_parameter_removeparameter_consumer_destroy(&removeparameter_consumer);

    // Destroy the consumer context / listening socket
    mal_ctx_destroy(&self->mal_ctx);

    // Return the return code
    return rc;
}

//  The removeParameter operation allows a consumer to remove one or more parameters from the list of parameters supported by the parameter provider
int
mc_parameter_service_remove_parameter (mc_parameter_service_t *self, long param_identity_id)
{
    // Log debug
    clog_debug(mc_parameter_service_logger, "mc_parameter_service_remove_parameter()\n");

    // The return code
    int rc;

    // Create param identity id list with single element
    long param_identity_id_list[] = {param_identity_id};

    // Invoke the removeParameter function
    rc = mc_parameter_service_remove_parameter_list (self, param_identity_id_list, 1);

    // Return the return code
    return rc;
}