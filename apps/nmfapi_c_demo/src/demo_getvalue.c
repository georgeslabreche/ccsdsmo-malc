/*  =========================================================================
    demo_getvalue - Demo the getValue interaction

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_getvalue - Demo the getValue interaction
@discuss
@end
*/

#include "nmfapi_c_demo_classes.h"

#define MAX_PARAM_LIST_SIZE            20

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
            printf("demo_getvalue [options] ...");
            printf("\n  --host   / -h        hostname");
            printf("\n  --pport  / -p        provider port");
            printf("\n  --cport  / -c        consumer port");
            printf("\n  --pnames / -n        comma separated list of param names (max %d)", MAX_PARAM_LIST_SIZE);
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
        if (streq (argv [argn], "--pnames")
        ||  streq (argv [argn], "-n"))
            argv_index_pname = ++argn;
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
    if (argv_index_host < 0 || argv_index_pport < 0 || argv_index_cport < 0 || argv_index_pname < 0)
    {
        printf("Expected --host, --pport, --cport, and --pnames options\n");
        return 1;
    }

    /* parse param names */
    char* param_names = argv[argv_index_pname];
    char* param_name_list[MAX_PARAM_LIST_SIZE];
    const char delimiter = ',';
    size_t param_name_list_size = 0;

    char* start = param_names;
    char* end = NULL;

    while ((end = strchr(start, delimiter)) != NULL || *start)
    {
        size_t length = (end ? (size_t)(end - start) : strlen(start));
        if (param_name_list_size >= MAX_PARAM_LIST_SIZE)
        {
            printf("Too many parameter names listed in --pnames, max is %d\n", MAX_PARAM_LIST_SIZE);
            return 1;
        }

        /* allocate memory for the new string, plus null-terminator */
        param_name_list[param_name_list_size] = malloc(length + 1);
        if (param_name_list[param_name_list_size] == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        /* copy the substring into the new allocation */
        strncpy(param_name_list[param_name_list_size], start, length);
        param_name_list[param_name_list_size][length] = '\0';
        param_name_list_size++;

        /* exit if no more delimiters are found */
        if (!end)
        {
            break;
        }

        /* move past the delimiter */
        start = end + 1;
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
    // listDefinition interaction to fetch parameter ids

    /* verbosity */
    printf("\nTriggering the listDefinition interaction to fetch parameter ids\n\n");

    /* the response error code */
    int rc;

    /* get pointer to the Parameter service */
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    /* response variable for param inst and def ids as well as element count */
    long *response_param_inst_id_list;
    long *response_param_def_id_list;
    size_t response_param_inst_id_list_size;

    /* send the listDefinition request with the response variable pointers */
    rc = mc_parameter_service_list_definition(parameter_service, param_name_list, param_name_list_size,
        &response_param_inst_id_list, &response_param_def_id_list, &response_param_inst_id_list_size);

    /* error check */
    if(rc < 0)
    {
        /* print error message */
        printf("Error requesting list definition\n");

        /* return the error code */
        return rc;
    }

    /* size check */
    if(param_name_list_size != response_param_inst_id_list_size)
    {
        /* print error message */
        printf("Did not fetch the expected number of parameter definitions: Expected %lu but was %lu\n", param_name_list_size, response_param_inst_id_list_size);

        /* return the error code */
        return rc;
    }

    /* print parameter Ids */
    for(size_t i = 0; i < param_name_list_size; i++)
    {
        printf("\t- Parameter %s has identity id %ld and definition id %ld\n",
            param_name_list[i], response_param_inst_id_list[i], response_param_def_id_list[i]);
    }


    // --------------------------------------------------------------------------
    // getValue interaction to fetch parameter values

    /* verbosity */
    printf("\nTriggering the getValue interaction to fetch parameter values\n");

    /* response variable pointers and element  */
    union mal_attribute_t *response_mal_attribute_list;
    unsigned char *response_mal_attributes_tag_list;
    size_t response_mal_attributes_count;

    /** 
     * trigger getValue interactions but in a way that incrementally tries aggregations with increasing number of parameters
     * what this means is that if 3 parameter names were given, e.g. paramA, paramB, and paramC, then 3 getValue interactions will be triggered: 
     * 
     *      a) getValue with 1 parameter: paramA
     *      b) getValue with 2 parameters: paramA and paramB
     *      c) getValue with 3 parameters: paramA, paramB, and paramC
     * 
     * we do this to test if aggregation building breaks past a certain threshold.
     */
    for(size_t param_inst_ids_size = 1; param_inst_ids_size <= response_param_inst_id_list_size; param_inst_ids_size++)
    {
        /* verbosity */
        printf("\nFetching values for %ld parameters:\n", param_inst_ids_size);

        /* Send the getValue request with the response variable pointers */
        rc = mc_parameter_service_get_value_list(parameter_service, response_param_inst_id_list, param_inst_ids_size,
            &response_mal_attribute_list, &response_mal_attributes_tag_list, &response_mal_attributes_count);

        /* error check */
        if(rc < 0)
        {
            /* print error message */
            printf("Error requesting parameter values\n");

            /* return the error code */
            return rc;
        }

        /* size check */
        if(param_inst_ids_size != response_mal_attributes_count)
        {
            /* print error message */
            printf("Did not fetch the expected number of parameter values: Expected %lu but was %lu\n", param_inst_ids_size, response_mal_attributes_count);

            /* return the error code */
            return rc;
        }

        /* variables used to store and print responses */
        long param_id;
        long param_def_id;
        char tag;
        union mal_attribute_t attr;

        /* print values for fetched parameters */
        for(size_t i = 0; i < response_mal_attributes_count; i++)
        {
            // Set the fetched attribute variables
            param_id = response_param_inst_id_list[i];
            param_def_id = response_param_def_id_list[i];
            tag = response_mal_attributes_tag_list[i];
            attr = response_mal_attribute_list[i];

            printf("\t- ");

            /* fetch the parameter value based on the parameter type indicated by the attribute tag */
            switch(tag)
            {
                case MAL_IDENTIFIER_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is an Identifier: %s\n", param_name_list[i], param_id, param_def_id, attr.identifier_value);
                    break;

                case MAL_STRING_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a String: %s\n", param_name_list[i], param_id, param_def_id, attr.string_value);
                    break;

                case MAL_URI_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a URI: %s\n", param_name_list[i], param_id, param_def_id, attr.uri_value);
                    break;

                case MAL_BOOLEAN_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Boolean: %d\n", param_name_list[i], param_id, param_def_id, attr.boolean_value);
                    break;

                case MAL_FLOAT_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Float: %f\n", param_name_list[i], param_id, param_def_id, attr.float_value);
                    break;

                case MAL_DOUBLE_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Double: %f\n", param_name_list[i], param_id, param_def_id, attr.double_value);
                    break;

                case MAL_OCTET_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Octet: %c\n", param_name_list[i], param_id, param_def_id, attr.octet_value);
                    break;

                case MAL_UOCTET_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UOctet: %u\n", param_name_list[i], param_id, param_def_id, attr.uoctet_value);
                    break;

                case MAL_SHORT_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Short: %hd\n", param_name_list[i], param_id, param_def_id, attr.short_value);
                    break;

                case MAL_USHORT_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UShort: %hu\n", param_name_list[i], param_id, param_def_id, attr.ushort_value);
                    break;

                case MAL_INTEGER_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Integer: %d\n", param_name_list[i], param_id, param_def_id, attr.integer_value);
                    break;

                case MAL_UINTEGER_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a UInteger: %u\n", param_name_list[i], param_id, param_def_id, attr.uinteger_value);
                    break;

                case MAL_LONG_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a Long: %ld\n", param_name_list[i], param_id, param_def_id, attr.long_value);
                    break;

                case MAL_ULONG_ATTRIBUTE_TAG:
                    printf("Parameter %s has instance identity id %ld, definition id %ld, and is a ULong: %lu\n", param_name_list[i], param_id, param_def_id, attr.ulong_value);
                    break;

                default:
                    /* not handling Blob, Time, and Finetime */
                    printf("Parameter %s has instance identity id %ld, definition id %ld, with unsupported attribute tag %d\n", param_name_list[i], param_id, param_def_id, tag);
            }

            /**
             * IMPORTANT: don't forget to destroy the MAL attribute object
             * calling the destructor is only required for objects that are of type String
             * string objects are attributes of type: Blob, Identifier, String, and URI
             * here we just call the destructor everytime, no harm done.
             */
            mal_attribute_destroy(&attr, tag);
        }
    }

    /* deallocate memory */
    free(response_param_inst_id_list);
    response_param_inst_id_list = NULL;

    /* deallocate memory */
    free(response_param_def_id_list);
    response_param_def_id_list = NULL;

    /* deallocate memory */
    free(response_mal_attribute_list);
    response_mal_attribute_list = NULL;

    /* deallocate memory */
    free(response_mal_attributes_tag_list);
    response_mal_attributes_tag_list = NULL;

    /* deallocate memory */
    for (size_t i = 0; i < param_name_list_size; i++)
    {
        free(param_name_list[i]);
    }

    // --------------------------------------------------------------------------
    // destroy

    /* destoying the API gateway object also destroys all service objects */
    nmf_api_destroy(&nmf_api);

    /* end of program */
    return 0;
}
