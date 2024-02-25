/*  =========================================================================
    demo_app - Demo App

    The MO MAL interactions in this demo program are written for ESA's OPS-SAT
    spacecraft: https://opssat1.esoc.esa.int/

    This app can run on OPS-SAT-like environment with the NMF Supervisor Simulator:
    https://nanosat-mo-framework.readthedocs.io/en/latest/index.html


    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_app - Demo App
@discuss
@end
*/


#include "nmfapi_c_demo_classes.h"


//  --------------------------------------------------------------------------
//  Declare the demonstration functions

//  Demonstrate the lookupProvider request interaction
//  FIXME: Does not work
//         See Issue #29: https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/29
//int
//demo_directory_service_lookup_provider();

//  Demonstrate the listApp operation request interaction
int
demo_appslauncher_service_list_app();

//  Demonstrate the listDefinition operation with one parameter per request interaction
int
demo_parameter_service_get_definition();

//  Demonstrate the listDefinition operation with multiple parameters in a single request interaction
//  Demonstrate the getValue operation with multiple parameters in a single request interaction
int
demo_parameter_service_get_value_list();

//  Demonstrate the getValue operation with one parameter per request interaction
int
demo_parameter_service_get_value();

//  Demonstrate the setValue operation with one parameter per submit interaction
int
demo_parameter_service_set_value();


//  --------------------------------------------------------------------------
//  Declare global variables

// The Gateway API object to access all services
nmf_api_t *nmf_api;


//  --------------------------------------------------------------------------
//  The main program function for this demonstration app

int main (int argc, char *argv [])
{
    // Get provider host and port from command arguments.
    int argv_index_host = -1;
    int argv_index_pport = -1;
    int argv_index_cport = -1;
    int argv_index_log = -1;

    // Only log errors by default
    int log_level = CLOG_ERROR_LEVEL;


    // --------------------------------------------------------------------------
    // Parse the command arguments

    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-?")) {
            puts ("demo_app [options] ...");
            puts ("  --host  / -h        hostname");
            puts ("  --pport / -p        provider port");
            puts ("  --cport / -c        consumer port");
            puts ("  --debug / -d        enable debug logging");
            puts ("  --help  / -?        this information");
            return 0;
        }
        else
        if (streq (argv [argn], "--host")
        ||  streq (argv [argn], "-h"))
            argv_index_host = ++argn;
        else
        if (streq (argv [argn], "--pport")
        ||  streq (argv [argn], "-p"))
            argv_index_pport = ++argn;
        else
        if (streq (argv [argn], "--cport")
        ||  streq (argv [argn], "-c"))
            argv_index_cport = ++argn;
        else
        if (streq (argv [argn], "--debug")
        ||  streq (argv [argn], "-d"))
            log_level = CLOG_DEBUG_LEVEL;
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }

    // Check if hostname and port numbers were set
    if (argv_index_host < 0 || argv_index_pport < 0 || argv_index_cport < 0)
    {
        printf ("Expected --host, --pport, and --cport options\n");
        return 1;
    }


    // --------------------------------------------------------------------------
    // Set the log levels

    nmf_api_set_global_log_level(log_level);


    // --------------------------------------------------------------------------
    // Initialize the Gateway API object to access NMF services

    nmf_api = nmf_api_new(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Check for error
    if(nmf_api == NULL)
    {
        printf ("Error initializing the API.\n");
        return 1;
    }


    // --------------------------------------------------------------------------
    // Invoke the demonstration functions
    
    // FIXME: Demonstrate the lookupProvider operation
    //        See Issue #29: https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/29
    // demo_directory_service_lookup_provider();

    // Demonstrate the listApp operation
    demo_appslauncher_service_list_app();
    
    // Demonstrate the listDefinition operation with one parameter per request interaction
    demo_parameter_service_get_definition();

    // Demonstrate the listDefinition operation with multiple parameters in a single request interaction
    // Demonstrate the getValue operation with multiple parameters in a single request interaction
    
    demo_parameter_service_get_value_list();

    // Demonstrate the getValue operation with one parameter per request interaction
    demo_parameter_service_get_value();

    // Demonstrate the setValue operation with one parameter per submit interaction
    demo_parameter_service_set_value();


    // --------------------------------------------------------------------------
    // Destroy

    // Destoying the API gateway object also destroys all service objects
    nmf_api_destroy(&nmf_api);


    // --------------------------------------------------------------------------
    // Demonstration completed

    printf("\n\nDemonstration completed.\n\n");

    // End demo
    return 0;
}

#if 0
//  --------------------------------------------------------------------------
//  Demonstrate the lookupProvider request interaction
//  FIXME: Does not work
//         See Issue #29: https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/29
int
demo_directory_service_lookup_provider()
{
    // Verbosity
    printf("\n\nDemonstrate the lookupProvider request interaction:\n\n");

    // Get pointer to the Directory service
    common_directory_service_t *directory_service = nmf_api_get_common_directory_service(nmf_api);

    // Request response variables
    long *response_provider_id_list;
    char **response_provider_uri_list;
    size_t response_element_count;

    // Send the lookupProvider request with the response variable pointers
    common_directory_service_lookup_provider_all_uri (directory_service,
        &response_provider_id_list, &response_provider_uri_list, &response_element_count);

    // End demo
    return 0;
}
#endif


//  --------------------------------------------------------------------------
//  Demonstrate the listApp requestion interaction

int
demo_appslauncher_service_list_app()
{
    // Verbosity
    printf("\n\nDemonstrate the listApp request interaction:\n\n");

    // Get pointer to the AppsLauncher service
    sm_appslauncher_service_t *appslauncher_service = nmf_api_get_sm_appslauncher_service(nmf_api);

    // Request parameters
    char *app_name_list[] = {"*"};
    char *category = "*";

    // Calculate size of app_name_list array
    size_t app_name_list_size = sizeof(app_name_list) / sizeof(app_name_list[0]);
    
    // Request response variables
    long *response_apps_inst_id_list;
    bool *response_apps_inst_running_list;
    size_t response_element_count;

    // Send the listApp request with the response variable pointers
    sm_appslauncher_service_list_app(appslauncher_service, app_name_list, app_name_list_size, category,
        &response_apps_inst_id_list, &response_apps_inst_running_list, &response_element_count);

    // Print the request's response variable values
    for(size_t i = 0; i < response_element_count; i++)
    {
        printf("App #%ld running status is %d\n", response_apps_inst_id_list[i], response_apps_inst_running_list[i]);
    }

    // Deallocate memory
    free(response_apps_inst_id_list);
    response_apps_inst_id_list = NULL;

    // Deallocate memory
    free(response_apps_inst_running_list);
    response_apps_inst_running_list = NULL;

    // End demo
    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the listDefinition operation with one parameter per request interaction

int
demo_parameter_service_get_definition()
{
    // Verbosity
    printf("\n\nDemonstrate the listDefinition operation with one parameter per request interaction:\n\n");

    // The response error code
    int rc;

    // Get pointer to the Parameter service
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    // A list of parameter names, each will be requested individually instead of in bulk as in demo_parameter_service_get_value_list
    char *param_name_list[] = {
        "OSVersion",            // Version of the OS
        "attitudeQuatA",        // Quaternion
        "attitudeQuatB",        // Quaternion
        "attitudeQuatC",        // Quaternion
        "attitudeQuatD",        // Quaternion
        "CADC0884",             // I_PD1_THETA
        "CADC0886",             // I_PD2_THETA
        "CADC0888",             // I_PD3_THETA
        "CADC0890",             // I_PD4_THETA
        "CADC0892",             // I_PD5_THETA
        "CADC0894"              // I_PD6_THETA
    };

    // Calculate size of array
    size_t param_name_list_size = sizeof(param_name_list) / sizeof(param_name_list[0]);

    // Response variable for parameter inst and def ids
    long response_identity_id;
    long response_definition_id;

    for(size_t i = 0; i < param_name_list_size; i++)
    {
        // Send the listDefinition request for a single parameter
        rc = mc_parameter_service_get_definition(parameter_service, param_name_list[i], &response_identity_id, &response_definition_id);

        // Error Checking
        if(rc != 0)
        {
            printf("Error requesting list definition for the %s parameter: \n", param_name_list[i]);
        }
        else // No errors
        {
            // Print response result
            printf("Parameter %s has identity id %ld and definition id %ld\n",
                param_name_list[i], response_identity_id, response_definition_id);
        }
    }

    // End demo
    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the listDefinition operation with multiple parameters in a single request interaction
//  Demonstrate the getValue operation with multiple parameters in a single request

int
demo_parameter_service_get_value_list()
{
    // Verbosity
    printf("\n\nDemonstrate: \
        \n - the listDefinition operation with multiple parameters in a single request interaction \
        \n - the getValue operation with multiple parameters in a single request interaction\n\n");

    // The response error code
    int rc;

    // Get pointer to the Parameter service
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    // Build the param names request field
    char *param_name_list[] = {
        "OSVersion",             // Version of the OS          String
        "attitudeQuatA",         // Quaternion                 Float
        "attitudeQuatB",         // Quaternion                 Float
        "attitudeQuatC",         // Quaternion                 Float
        "attitudeQuatD",         // Quaternion                 Float
        "CADC0884",              // I_PD1_THETA                Float
        "CADC0885",              // I_PD1_VAL_FLAG             Boolean
        "PACK1057",              // PACKET_STORE_USED_SIZE     UIntger
        "TM_C1094",              // TM_CHANNEL_VALUE           UOctet
        "BUSS1157",              // CONFIG_SEPP                UShort
        "EPS9830l",              // PDU1_VCC_LMIN              Short
    };

    // Calculate size of array
    size_t param_name_list_size = sizeof(param_name_list) / sizeof(param_name_list[0]);

    // Response variable for param inst and def ids as well as element count
    long *response_param_inst_id_list;
    long *response_param_def_id_list;
    size_t response_param_inst_id_list_size;

    // Send the listDefinition request with the response variable pointers
    rc = mc_parameter_service_list_definition(parameter_service, param_name_list, param_name_list_size,
        &response_param_inst_id_list, &response_param_def_id_list, &response_param_inst_id_list_size);

    // Error check
    if(rc < 0)
    {
        // Print error message
        printf("Error requesting list definition\n");

        // Return the error code
        return rc;
    }

    // Size check
    if(param_name_list_size != response_param_inst_id_list_size)
    {
        // Print error message
        printf("Did not fetch the expected number of parameter definitions: Expected %lu but was %lu\n", param_name_list_size, response_param_inst_id_list_size);

        // Return the error code
        return rc;
    }

    // Response variable pointers and element count
    union mal_attribute_t *response_mal_attribute_list;
    unsigned char *response_mal_attributes_tag_list;
    size_t response_mal_attributes_count;

    // Send the getValue request with the response variable pointers
    rc = mc_parameter_service_get_value_list(parameter_service, response_param_inst_id_list, response_param_inst_id_list_size,
        &response_mal_attribute_list, &response_mal_attributes_tag_list, &response_mal_attributes_count);

    // Error check
    if(rc < 0)
    {
        // Print error message
        printf("Error requesting parameter values\n");

        // Return the error code
        return rc;
    }

    // Size check
    if(response_param_inst_id_list_size != response_mal_attributes_count)
    {
        // Print error message
        printf("Did not fetch the expected number of parameter values: Expected %lu but was %lu\n", response_param_inst_id_list_size, response_mal_attributes_count);

        // Return the error code
        return rc;
    }

    // Variables used to store and print responses
    long param_id;
    char tag;
    union mal_attribute_t attr;

    // Print values for fetched parameters
    for(size_t i = 0; i < response_mal_attributes_count; i++)
    {
        // Set the fetched attribute variables
        param_id = response_param_inst_id_list[i];
        tag = response_mal_attributes_tag_list[i];
        attr = response_mal_attribute_list[i];

        // Fetch the parameter value based on the parameter type indicated by the attribute tag
        switch(tag)
        {
            case MAL_IDENTIFIER_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is an Identifier: %s\n", param_name_list[i], param_id, attr.identifier_value);
                break;

            case MAL_STRING_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a String: %s\n", param_name_list[i], param_id, attr.string_value);
                break;

            case MAL_URI_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a URI: %s\n", param_name_list[i], param_id, attr.uri_value);
                break;

            case MAL_BOOLEAN_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Boolean: %d\n", param_name_list[i], param_id, attr.boolean_value);
                break;

            case MAL_FLOAT_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Float: %f\n", param_name_list[i], param_id, attr.float_value);
                break;

            case MAL_DOUBLE_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Double: %f\n", param_name_list[i], param_id, attr.double_value);
                break;

            case MAL_OCTET_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Octet: %c\n", param_name_list[i], param_id, attr.octet_value);
                break;

            case MAL_UOCTET_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a UOctet: %u\n", param_name_list[i], param_id, attr.uoctet_value);
                break;

            case MAL_SHORT_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Short: %hd\n", param_name_list[i], param_id, attr.short_value);
                break;

            case MAL_USHORT_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a UShort: %hu\n", param_name_list[i], param_id, attr.ushort_value);
                break;

            case MAL_INTEGER_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Integer: %d\n", param_name_list[i], param_id, attr.integer_value);
                break;

            case MAL_UINTEGER_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a UInteger: %u\n", param_name_list[i], param_id, attr.uinteger_value);
                break;

            case MAL_LONG_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a Long: %ld\n", param_name_list[i], param_id, attr.long_value);
                break;

            case MAL_ULONG_ATTRIBUTE_TAG:
                printf("Parameter %s has id %ld and is a ULong: %lu\n", param_name_list[i], param_id, attr.ulong_value);
                break;

            default:
                // Not handling Blob, Time, and Finetime
                printf("Param %s has id %ld with unsupported attribute tag %d\n", param_name_list[i], param_id, tag);
        }

        // IMPORTANT: Don't forget to destroy the MAL attribute object
        // Calling the destructor is only required for objects that are of type String
        // String objects are attributes of type: Blob, Identifier, String, and URI
        // Here we just call the destructor everytime, no harm done.
        mal_attribute_destroy(&attr, tag);
    }


    // Deallocate memory
    free(response_param_inst_id_list);
    response_param_inst_id_list = NULL;

    // Deallocate memory
    free(response_param_def_id_list);
    response_param_def_id_list = NULL;

    // Deallocate memory
    free(response_mal_attribute_list);
    response_mal_attribute_list = NULL;

    // Deallocate memory
    free(response_mal_attributes_tag_list);
    response_mal_attributes_tag_list = NULL;

    // End demo
    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the getValue operation with one parameter per request interaction

int
demo_parameter_service_get_value()
{
    // Verbosity
    printf("\n\nDemonstrate the getValue operation with one parameter per request interaction:\n\n");

    // The response error code
    int rc;

    // Variables to store the parameter inst and def ids nedded to fetch parameter values
    long param_inst_id;
    long param_def_id;

    // --------------------------------------------------------------------------
    // Create the Parameter service

    // Get pointer to the parameter service
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    // --------------------------------------------------------------------------
    // Get the OS version parameter via mc_parameter_service_get_value()

    // The response variables
    union mal_attribute_t response_mal_attribute_os_version;
    unsigned char response_mal_attribute_tag_os_version;

    // Send the getValue requests with the response variable pointers
    rc = mc_parameter_service_get_definition(parameter_service, "OSVersion", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value(parameter_service, param_inst_id, &response_mal_attribute_os_version, &response_mal_attribute_tag_os_version);
    
    // Error check
    if(rc < 0)
    {
        printf("Error requesting parameter: OS Version\n");
    }
    else
    {
        // Print the fetched parameter
        printf("OS Version: %s\n", response_mal_attribute_os_version.string_value);
    }

    // IMPORTANT: Don't forget to destroy the MAL attribute object when requesting a string object
    // String objects are attributes of type: Blob, Identifier, String, and URI
    if(response_mal_attribute_os_version.string_value)
    {
        mal_attribute_destroy(&response_mal_attribute_os_version, response_mal_attribute_tag_os_version);
    }


    // --------------------------------------------------------------------------
    // Get the OS version parameter via mc_parameter_service_get_value_string()

    // Pointer to the string response variable
    char *os_version;

    // Send the getValue request with the string pointer to be set
    rc = mc_parameter_service_get_definition(parameter_service, "OSVersion", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value_string(parameter_service, param_inst_id, &os_version);

    // Error check
    if(rc < 0)
    {
        printf("Error requesting parameter: OS Version\n");
    }
    else
    {
        // Print the fetched parameter
        printf("OS Version: %s\n", os_version);
    }

    // IMPORTANT: Don't forget to destroy the string object
    if(os_version)
    {
        mal_string_destroy(&os_version);
    }


    // --------------------------------------------------------------------------
    // Get the quaternion parameters via mc_parameter_service_get_value_float()

    // Execute getValue interactions to fetch quaternion float values
    
    // Quaternion variables
    float q1, q2, q3, q4;
    
    
    // Send the listDefinition request for a single parameter
    rc = mc_parameter_service_get_definition(parameter_service, "attitudeQuatA", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, param_inst_id, &q1);

    rc = rc || mc_parameter_service_get_definition(parameter_service, "attitudeQuatB", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, param_inst_id, &q2);

    rc = rc || mc_parameter_service_get_definition(parameter_service, "attitudeQuatC", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, param_inst_id, &q3);

    rc = rc || mc_parameter_service_get_definition(parameter_service, "attitudeQuatD", &param_inst_id, &param_def_id);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, param_inst_id, &q4);

    if(rc != 0)
    {
        printf("Error requesting parameter: Quaterions\n");
    }
    else
    {
        // Print the quaternion float values
        printf("Quaternions (q1, q2, q3, q4) = (%f, %f, %f, %f)\n", q1, q2, q3, q4);
    }

    // End demo
    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the setValue operation with one parameter per submit interaction

int
demo_parameter_service_set_value()
{
    // Verbosity
    printf("\n\nDemonstrate the setValue operation with one parameter per submit interaction:\n\n");

    // The response error code
    int rc;

    // Get pointer to the Parameter service
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    // --------------------------------------------------------------------------
    // Demonstrate getting, setting, and then getting again

    // STEP 1: Get the parameter's definition based on the given parameter name

    // The param to set (it's of type double)
    char *param_name = "attitudeMonitoringInterval";

    // Get a random double value, between 0 and 2, to set as the new parameter value
    double random_value;
    srand (time(NULL));
    random_value = (double) rand() / RAND_MAX * 2.0;

    // Convert random double value to string
    char param_value_to_set[20];
    snprintf(param_value_to_set, 20, "%f", random_value);

    // Response variables for param inst and def ids
    long param_inst_id;
    long param_def_id;
    
    // Send the listDefinition request for a single parameter
    rc = mc_parameter_service_get_definition(parameter_service, param_name, &param_inst_id, &param_def_id);

    // Error Checking
    if(rc != 0)
    {
         // Print error mesage
        printf("Error requesting list definition for parameter %s: \n", param_name);

        // Return the error code
        return rc;
    }
    else // No errors
    {
        // Print response result
        printf("Parameter %s has identity id %ld and definition id %ld\n",
            param_name, param_inst_id, param_def_id);
    }

    // STEP 2: The getValue request interaction will fetch the param value

    // Pointer to the response variable (of type Double)
    double param_value;

    // Send the getValue request with the string pointer to be set
    rc = mc_parameter_service_get_value_duration(parameter_service, param_inst_id, &param_value);

    // Error check
    if(rc != 0)
    {
        // Print error message
        printf("Error requesting parameter %s\n", param_name);

        // Return the error code
        return rc;
    }
    else
    {
        // Print the fetched parameter
        printf("Value of parameter %s: %f\n", param_name, param_value);
    }

    // STEP 3: The setValue request interaction will set the OSVersion param value
    
    // Verbosity
    printf("Setting value of parameter %s from %f to %s\n", param_name, param_value, param_value_to_set);

    // Trigger the setValue submit interaction
    rc = mc_parameter_service_set_value(parameter_service, param_inst_id, MAL_DURATION_ATTRIBUTE_TAG, param_value_to_set);

    // Check for error
    if(rc != 0)
    {
        // Print error message
        printf("Error setting parameter %s\n", param_name);

        // Return the error code
        return rc;
    }

    // STEP 4: The getValue request interaction should fetch the new param value that was set
    if(rc == 0)
    {
        // Send the getValue request with the string pointer to be set
        rc = mc_parameter_service_get_value_duration(parameter_service, param_inst_id, &param_value);

        // Error check
        if(rc < 0)
        {
            printf("Error requesting parameter %s\n", param_name);

            // Return the error code
            return rc;
        }
        else
        {
            // Print the fetched parameter
            printf("New value of parameter %s: %f\n", param_name, param_value);
        }
    }

    // End demo
    return 0;
}