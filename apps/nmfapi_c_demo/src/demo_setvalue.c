/*  =========================================================================
    demo_setvalue - Demo the setValue interaction provided by the Monitor and Control Parameter Service

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_setvalue - Demo the setValue interaction provided by the Monitor and Control Parameter Service
@discuss
@end
*/

#include "nmfapi_c_demo_classes.h"

//  --------------------------------------------------------------------------
//  Declare global variables

/* the Gateway API object to access all services */
nmf_api_t *nmf_api;

int main (int argc, char *argv [])
{
    /* get provider host and port from command arguments */
    int argv_index_host = -1;
    int argv_index_pport = -1;
    int argv_index_cport = -1;
    int argv_index_pname = -1;
    int argv_index_pvalue = -1;
    int argv_index_ptype = -1;
    int argv_index_log = -1;

    /* only log errors by default */
    int log_level = CLOG_ERROR_LEVEL;

    // --------------------------------------------------------------------------
    // parse the command arguments

    int argn;
    for (argn = 1; argn < argc; argn++)
    {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-?"))
        {
            printf("demo_setvalue [options] ...");
            printf("\n  --host   / -h        hostname");
            printf("\n  --pport  / -p        provider port");
            printf("\n  --cport  / -c        consumer port");
            printf("\n  --pname  / -n        parameter name");
            printf("\n  --pvalue / -v        parameter value");
            printf("\n  --ptype  / -t        parameter type");
            printf("\n                        %d - Blob", MAL_BLOB_ATTRIBUTE_TAG);
            printf("\n                        %d - Boolean", MAL_BOOLEAN_ATTRIBUTE_TAG);
            printf("\n                        %d - Duration", MAL_DURATION_ATTRIBUTE_TAG);
            printf("\n                        %d - Float", MAL_FLOAT_ATTRIBUTE_TAG);
            printf("\n                        %d - Double", MAL_DOUBLE_ATTRIBUTE_TAG);
            printf("\n                        %d - Identifier", MAL_IDENTIFIER_ATTRIBUTE_TAG);
            printf("\n                        %d - Octet", MAL_OCTET_ATTRIBUTE_TAG);
            printf("\n                        %d - UOctet", MAL_UOCTET_ATTRIBUTE_TAG);
            printf("\n                        %d - Short", MAL_SHORT_ATTRIBUTE_TAG);
            printf("\n                        %d - UShort", MAL_USHORT_ATTRIBUTE_TAG);
            printf("\n                        %d - Intege", MAL_INTEGER_ATTRIBUTE_TAG);
            printf("\n                        %d - UInteger", MAL_UINTEGER_ATTRIBUTE_TAG);
            printf("\n                        %d - Long", MAL_LONG_ATTRIBUTE_TAG);
            printf("\n                        %d - ULong", MAL_ULONG_ATTRIBUTE_TAG);
            printf("\n                        %d - String", MAL_STRING_ATTRIBUTE_TAG);
            printf("\n                        %d - Time", MAL_TIME_ATTRIBUTE_TAG);
            printf("\n                        %d - Finetime", MAL_FINETIME_ATTRIBUTE_TAG);
            printf("\n                        %d - URI", MAL_URI_ATTRIBUTE_TAG);
            printf("\n  --debug  / -d        enable debug logging");
            printf("\n  --help   / -?        this information\n\n");
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
        if (streq (argv [argn], "--pname")
        ||  streq (argv [argn], "-n"))
            argv_index_pname = ++argn;
        else
        if (streq (argv [argn], "--pvalue")
        ||  streq (argv [argn], "-v"))
            argv_index_pvalue = ++argn;
        else
        if (streq (argv [argn], "--ptype")
        ||  streq (argv [argn], "-t"))
            argv_index_ptype = ++argn;
        else
        if (streq (argv [argn], "--debug")
        ||  streq (argv [argn], "-d"))
            log_level = CLOG_DEBUG_LEVEL;
        else
        {
            printf("Unknown option: %s\n\n", argv[argn]);
            return 1;
        }
    }

    /* check if mandatory arguments were provided */
    if (argv_index_host < 0 || argv_index_pport < 0 || argv_index_cport < 0 || argv_index_pname < 0 || argv_index_pvalue < 0 || argv_index_ptype < 0)
    {
        printf("Expected --host, --pport, --cport, --pname, --pvalue, and --ptype options\n");
        return 1;
    }

    /* parse param name and value */
    char *param_name = argv[argv_index_pname];
    char *param_value = argv[argv_index_pvalue];

    /* convert the param type argument to an integer first, then cast to unsigned char */
    /* default value of 255 means it has not been set*/
    unsigned char param_type = 255;

    int type = atoi(argv[argv_index_ptype]);
    if (type >= 0 && type <= 255) { /* ensure it's within the valid range for unsigned char */
        param_type = (unsigned char)type;
    } else {
        printf("Invalid parameter type: %s\n", argv[argv_index_ptype]);
        return 1;
    }


    // --------------------------------------------------------------------------
    // set the log levels

    nmf_api_set_global_log_level(log_level);

    // --------------------------------------------------------------------------
    // initialize the Gateway API object to access NMF services

    nmf_api = nmf_api_new(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Check for error
    if(nmf_api == NULL)
    {
        printf ("Error initializing the API.\n");
        return 1;
    }


    // --------------------------------------------------------------------------
    // get a pointer to the Monitor and Control Parameter Service
    // it's the service that implements the setValue operation

    /* the response error code */
    int rc;

    /* get pointer to the Parameter service */
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    /* response variable for param inst and def ids */
    long param_identity_id;
    long param_definition_id;

    /* get parameter definition via the listDefinition request with the response variable pointers */
    printf("THE PARAM NAME: %s\n", param_name);
    rc = mc_parameter_service_get_definition(parameter_service, param_name, &param_identity_id, &param_definition_id);

    /* error check */
    if(rc < 0)
    {
        /* print error message */
        printf("Error requesting list definition\n");

        /* return the error code */
        return rc;
    }


    // --------------------------------------------------------------------------
    // set the parameter value for the given parameter

    /* verbosity */
    printf("Setting value %s of type %d to parameter %s with id: %ld\n", param_value, param_type, param_name, param_identity_id);

    /* trigger the setValue submit interaction */
    rc = mc_parameter_service_set_value(parameter_service, param_identity_id, param_type, param_value);

    /* check for error */
    if(rc != 0)
    {
        /* print error message */
        printf("Error setting value for %s\n", param_name);

        /* return the error code */
        return rc;
    }


    // --------------------------------------------------------------------------
    // get the parameter value that was just set
    // we do this to verify that it was indeed set to the given value

    union mal_attribute_t response_mal_attribute;
    unsigned char response_mal_attribute_tag;

    rc = mc_parameter_service_get_value(parameter_service, param_identity_id, &response_mal_attribute, &response_mal_attribute_tag);

    /* error check */
    if(rc < 0)
    {
        /* print error message */
        printf("Error getting value for %s\n", param_name);

        /* return the error code */
        return rc;
    }

    /* fetch the parameter value based on the parameter type indicated by the attribute tag */
    switch(response_mal_attribute_tag)
    {
        case MAL_IDENTIFIER_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is an Identifier: %s\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.identifier_value);
            break;

        case MAL_STRING_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a String: %s\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.string_value);
            break;

        case MAL_URI_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a URI: %s\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.uri_value);
            break;

        case MAL_BOOLEAN_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Boolean: %d\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.boolean_value);
            break;

        case MAL_FLOAT_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Float: %f\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.float_value);
            break;

        case MAL_DOUBLE_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Double: %f\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.double_value);
            break;

        case MAL_OCTET_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Octet: %c\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.octet_value);
            break;

        case MAL_UOCTET_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UOctet: %u\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.uoctet_value);
            break;

        case MAL_SHORT_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Short: %hd\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.short_value);
            break;

        case MAL_USHORT_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UShort: %hu\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.ushort_value);
            break;

        case MAL_INTEGER_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Integer: %d\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.integer_value);
            break;

        case MAL_UINTEGER_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UInteger: %u\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.uinteger_value);
            break;

        case MAL_LONG_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Long: %ld\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.long_value);
            break;

        case MAL_ULONG_ATTRIBUTE_TAG:
            printf("Parameter %s has instance identity id %ld, definition id %ld, and is a ULong: %lu\n", param_name, param_identity_id, param_definition_id, response_mal_attribute.ulong_value);
            break;

        default:
            /* not handling Blob, Time, and Finetime */
            printf("Parameter %s has instance identity id %ld, definition id %ld, with unsupported attribute tag %d\n", param_name, param_identity_id, param_definition_id, response_mal_attribute_tag);
    }

    /**
    * IMPORTANT: don't forget to destroy the MAL attribute object
    * calling the destructor is only required for objects that are of type String
    * string objects are attributes of type: Blob, Identifier, String, and URI
    * here we just call the destructor everytime, no harm done.
    */
    mal_attribute_destroy(&response_mal_attribute, response_mal_attribute_tag);


    // --------------------------------------------------------------------------
    // destroy

    /* destoying the API gateway object also destroys all service objects */
    nmf_api_destroy(&nmf_api);


    // --------------------------------------------------------------------------
    // end of program
    return 0;
}
