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


#include "demo_classes.h"


//  --------------------------------------------------------------------------
//  Declare the demonstration functions

//  Demonstrate the lookupProvider operation
int
demo_directory_service_lookup_provider(char *hostname, char *provider_port, char *consumer_port);

//  Demonstrate the listApp operation
int
demo_appslauncher_service_list_app(char *hostname, char *provider_port, char *consumer_port);

//  Demonstrate the listDefinition operation with multiple parameters in a single request
int
demo_parameter_service_list_definition(char *hostname, char *provider_port, char *consumer_port);

//  Demonstrate the listDefinition operation with one parameter per request
int
demo_parameter_service_get_definition(char *hostname, char *provider_port, char *consumer_port);

//  Demonstrate the getValue operation with multiple parameters in a single request
int
demo_parameter_service_get_values(char *hostname, char *provider_port, char *consumer_port);

//  Demonstrate the getValue operation with one parameter per request
int
demo_parameter_service_get_value(char *hostname, char *provider_port, char *consumer_port);


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
            puts ("  --cport / -p        consumer port");
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

    // MAL TCP log level
    maltcp_set_log_level(log_level);

    // FIXME: Common service log level
    //common_directory_service_set_log_level(log_level);
    //common_directory_lookup_provider_consumer_set_log_level(log_level);

    // AppsLauncher service log level
    sm_appslauncher_service_set_log_level(log_level);
    sm_appslauncher_list_app_consumer_set_log_level(log_level);

    // Parameter service log levels
    mc_parameter_service_set_log_level(log_level);
    mc_parameter_list_definition_consumer_set_log_level(log_level);
    mc_parameter_get_value_consumer_set_log_level(log_level);


    // --------------------------------------------------------------------------
    // Invoke the demonstration functions
    
    // FIXME: Demonstrate the lookupProvider operation
    //        See: https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/29
    // demo_directory_service_lookup_provider(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Demonstrate the listApp operation
    demo_appslauncher_service_list_app(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Demonstrate the listDefinition operation with multiple parameters in a single request
    demo_parameter_service_list_definition(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Demonstrate the listDefinition operation with one parameter per request
    demo_parameter_service_get_definition(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Demonstrate the getValue operation with multiple parameters in a single request
    demo_parameter_service_get_values(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Demonstrate the getValue operation with one parameter per request
    demo_parameter_service_get_value(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // --------------------------------------------------------------------------
    // Demonstration completed

    printf("\n\nDemonstration completed.\n\n");

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the lookupProvider operation
int
demo_directory_service_lookup_provider(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the lookupProvider operation:\n\n");

    // Create the Directory service
    common_directory_service_t *directory_service = common_directory_service_new(hostname, provider_port, consumer_port);

    // Request response variables
    long *response_provider_id_list;
    char **response_provider_uri_list;
    size_t response_element_count;

    // Send the lookupProvider request with the response variable pointers
    common_directory_service_lookup_provider_all_uri (directory_service,
        &response_provider_id_list, &response_provider_uri_list, &response_element_count);

    // Destroy the service
    common_directory_service_destroy(&directory_service);

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the listApp operation

int
demo_appslauncher_service_list_app(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the listApp operation:\n\n");

    // Create the AppsLauncher service
    sm_appslauncher_service_t *appslauncher_service = sm_appslauncher_service_new(hostname, provider_port, consumer_port);

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

    // Destroy the service
    sm_appslauncher_service_destroy(&appslauncher_service);

    // TODO: Destroy the response variables?

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the listDefinition operation with multiple parameters in a single request

int
demo_parameter_service_list_definition(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the listDefinition operation with multiple parameters in a single request:\n\n");

    // The response error code
    int rc;

    // Create the Parameter service
    mc_parameter_service_t *parameter_service = mc_parameter_service_new(hostname, provider_port, consumer_port);

    // Build the param names request field
    char *param_name_list[] = {
        "OSVersion",            // Version of the OS            1
        "attitudeQuatA",        // Quaternion                   3
        "attitudeQuatB",        // Quaternion                   4
        "attitudeQuatC",        // Quaternion                   5
        "attitudeQuatD",        // Quaternion                   6
        "CADC0884",             // I_PD1_THETA                891
        "CADC0886",             // I_PD2_THETA                893
        "CADC0888",             // I_PD3_THETA                895
        "CADC0890",             // I_PD4_THETA                897
        "CADC0892",             // I_PD5_THETA                899
        "CADC0894"              // I_PD6_THETA                901
    };

    // Calculate size of array
    size_t param_name_list_size = sizeof(param_name_list) / sizeof(param_name_list[0]);

    // Response variable pointers and element count
    long *response_identity_id_list;
    long *response_definition_id_list;
    size_t response_element_count;

    // Send the listDefinition request with the response variable pointers
    rc = mc_parameter_service_list_definition(parameter_service, param_name_list, param_name_list_size,
        &response_identity_id_list, &response_definition_id_list, &response_element_count);

    // Error check
    if(rc < 0)
    {
        // Print error message
        printf("Error requesting list definition\n");

        // Destroy the service
        mc_parameter_service_destroy(&parameter_service);

        // Return the error code
        return rc;
    }

    // Print values for fetched parameters
    for(size_t i = 0; i < response_element_count; i++)
    {
        printf("Param %s has identity id %ld and definition id %ld\n",
            param_name_list[i], response_identity_id_list[i], response_definition_id_list[i]);
    }

    // Destroy the service
    mc_parameter_service_destroy(&parameter_service);

    // TODO: Destroy the response variables?

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the listDefinition operation with one parameter per request

int
demo_parameter_service_get_definition(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the listDefinition operation with one parameter per request:\n\n");

    // The response error code
    int rc;

    // Create the Parameter service
    mc_parameter_service_t *parameter_service = mc_parameter_service_new(hostname, provider_port, consumer_port);

    // A list of parameter names, each will be requested individually instead of in bulk as in demo_parameter_service_list_definition
    char *param_name_list[] = {
        "OSVersion",            // Version of the OS            1
        "attitudeQuatA",        // Quaternion                   3
        "attitudeQuatB",        // Quaternion                   4
        "attitudeQuatC",        // Quaternion                   5
        "attitudeQuatD",        // Quaternion                   6
        "CADC0884",             // I_PD1_THETA                891
        "CADC0886",             // I_PD2_THETA                893
        "CADC0888",             // I_PD3_THETA                895
        "CADC0890",             // I_PD4_THETA                897
        "CADC0892",             // I_PD5_THETA                899
        "CADC0894"              // I_PD6_THETA                901
    };

    // Calculate size of array
    size_t param_name_list_size = sizeof(param_name_list) / sizeof(param_name_list[0]);

    // Response variable pointers and element count
    long response_identity_id;
    long response_definition_id;

    for(size_t i = 0; i < param_name_list_size; i++)
    {
        // Send the listDefinition request for a single parameter
        rc = mc_parameter_service_get_definition(parameter_service, param_name_list[i], &response_identity_id, &response_definition_id);

        // Error Checking
        if(rc != 0)
        {
            printf("Error requesting list definition for param %s: \n", param_name_list[i]);
        }
        else // No errors
        {
            // Print response result
            printf("Param %s has identity id %ld and definition id %ld\n",
                param_name_list[i], response_identity_id, response_definition_id);
        }
    }

    // Destroy the service
    mc_parameter_service_destroy(&parameter_service);

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the getValue operation with multiple parameters in a single request

int
demo_parameter_service_get_values(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the getValue operation with multiple parameters in a single request:\n\n");

    // The response error code
    int rc;

    // Create the Parameter service
    mc_parameter_service_t *parameter_service = mc_parameter_service_new(hostname, provider_port, consumer_port);

    // Request parameters
    long param_inst_ids[] = {
        1,      // OSVersion             Version of the OS          String
        3,      // attitudeQuatA         Quaternion                 Float
        4,      // attitudeQuatB         Quaternion                 Float
        5,      // attitudeQuatC         Quaternion                 Float
        6,      // attitudeQuatD         Quaternion                 Float
        891,    // CADC0884              I_PD1_THETA                Float
        892,    // CADC0885              I_PD1_VAL_FLAG             Boolean
        1064,   // PACK1057              PACKET_STORE_USED_SIZE     UIntger
        1101,   // TM_C1094              TM_CHANNEL_VALUE           UOctet
        1164,   // BUSS1157              CONFIG_SEPP                UShort
        8604    // EPS9830l              PDU1_VCC_LMIN              Short
    };

    // Calculate size of array
    size_t param_inst_ids_size = sizeof(param_inst_ids) / sizeof(param_inst_ids[0]);

    // Response variable pointers and element count
    union mal_attribute_t *response_mal_attributes;
    unsigned char *response_mal_attributes_tags;
    size_t response_mal_attributes_count;

    // Send the getValue request with the response variable pointers
    rc = mc_parameter_service_get_values(parameter_service, param_inst_ids, param_inst_ids_size,
        &response_mal_attributes, &response_mal_attributes_tags, &response_mal_attributes_count);

    // Error check
    if(rc < 0)
    {
        // Print error message
        printf("Error requesting parameter values\n");

        // Destroy the service
        mc_parameter_service_destroy(&parameter_service);

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
        param_id = param_inst_ids[i];
        tag = response_mal_attributes_tags[i];
        attr = response_mal_attributes[i];

        // Fetch the parameter value based on the parameter type indicated by the attribute tag
        switch(tag)
        {
            case MAL_IDENTIFIER_ATTRIBUTE_TAG:
                printf("Param #%ld is an Identifier: %s\n", param_id, attr.identifier_value);
                break;

            case MAL_STRING_ATTRIBUTE_TAG:
                printf("Param #%ld is a String: %s\n", param_id, attr.string_value);
                break;

            case MAL_URI_ATTRIBUTE_TAG:
                printf("Param #%ld is a URI: %s\n", param_id, attr.uri_value);
                break;

            case MAL_BOOLEAN_ATTRIBUTE_TAG:
                printf("Param #%ld is a Boolean: %d\n", param_id, attr.boolean_value);
                break;

            case MAL_FLOAT_ATTRIBUTE_TAG:
                printf("Param #%ld is a Float: %f\n", param_id, attr.float_value);
                break;

            case MAL_DOUBLE_ATTRIBUTE_TAG:
                printf("Param #%ld is a Double: %f\n", param_id, attr.double_value);
                break;

            case MAL_OCTET_ATTRIBUTE_TAG:
                printf("Param #%ld is a Octet: %c\n", param_id, attr.octet_value);
                break;

            case MAL_UOCTET_ATTRIBUTE_TAG:
                printf("Param #%ld is a UOctet: %u\n", param_id, attr.uoctet_value);
                break;

            case MAL_SHORT_ATTRIBUTE_TAG:
                printf("Param #%ld is a Short: %hd\n", param_id, attr.short_value);
                break;

            case MAL_USHORT_ATTRIBUTE_TAG:
                printf("Param #%ld is a UShort: %hu\n", param_id, attr.ushort_value);
                break;

            case MAL_INTEGER_ATTRIBUTE_TAG:
                printf("Param #%ld is a Integer: %d\n", param_id, attr.integer_value);
                break;

            case MAL_UINTEGER_ATTRIBUTE_TAG:
                printf("Param #%ld is a UInteger: %u\n", param_id, attr.uinteger_value);
                break;

            case MAL_LONG_ATTRIBUTE_TAG:
                printf("Param #%ld is a Long: %ld\n", param_id, attr.long_value);
                break;

            case MAL_ULONG_ATTRIBUTE_TAG:
                printf("Param #%ld is a ULong: %lu\n", param_id, attr.ulong_value);
                break;

            default:
                // Not handling Blob, Time, and Finetime
                printf("Param #%ld has unsupportred attribute tag %d\n", param_id, tag);
        }

        // IMPORTANT: Don't forget to destroy the MAL attribute object
        // Calling the destructor is only required for objects that are of type String
        // String objects are attributes of type: Blob, Identifier, String, and URI
        // Here we just call the destructor everytime, no harm done.
        mal_attribute_destroy(&attr, tag);
    }

    // Destroy the service
    mc_parameter_service_destroy(&parameter_service);

    // TODO: Destroy the response variables?

    return 0;
}


//  --------------------------------------------------------------------------
//  Demonstrate the getValue operation with one parameter per request

int
demo_parameter_service_get_value(char *hostname, char *provider_port, char *consumer_port)
{
    // Verbosity
    printf("\n\nDemonstrate the getValue operation with one parameter per request:\n\n");

    // The response error code
    int rc;

    // --------------------------------------------------------------------------
    // Create the Parameter service

    mc_parameter_service_t *parameter_service = mc_parameter_service_new(hostname, provider_port, consumer_port);


    // --------------------------------------------------------------------------
    // Get the OS version parameter via mc_parameter_service_get_value()

    // The response variables
    union mal_attribute_t response_mal_attribute_os_version;
    unsigned char response_mal_attribute_tag_os_version;

    // Send the getValue requests with the response variable pointers
    rc = mc_parameter_service_get_value(parameter_service, 1, &response_mal_attribute_os_version, &response_mal_attribute_tag_os_version);
    
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

    // Send the getValue requests with the string pointer to be set
    rc = mc_parameter_service_get_value_string(parameter_service, 1, &os_version);

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
    float q1, q2, q3, q4;
    rc = mc_parameter_service_get_value_float(parameter_service, 3, &q1);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, 4, &q2);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, 5, &q3);
    rc = rc || mc_parameter_service_get_value_float(parameter_service, 6, &q4);

    if(rc != 0)
    {
        printf("Error requesting parameter: Quaterions\n");
    }
    else
    {
        // Print the quaternion float values
        printf("Quaternions (q1, q2, q3, q4) = (%f, %f, %f, %f)\n", q1, q2, q3, q4);
    }


    // --------------------------------------------------------------------------
    // Destroy the service

    mc_parameter_service_destroy(&parameter_service);

    // TODO: Destroy the response variables?

    return 0;
}