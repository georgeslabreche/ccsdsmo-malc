/*  =========================================================================
    demo_addparameter - Demo the Monitor and Control Service addParameter interaction

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_addparameter - Demo the addParameter interaction provided by the Monitor and Control Parameter Service
    TODO: Right now the Param provider implementation in NFM Superviser does not support storing or persisting values on its own
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
            printf("\n  --host  / -h        hostname");
            printf("\n  --pport / -p        provider port");
            printf("\n  --cport / -p        consumer port");
            printf("\n  --debug / -d        enable debug logging");
            printf("\n  --help  / -?        this information\n\n");
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
        else
        {
            printf("Unknown option: %s\n\n", argv[argn]);
            return 1;
        }
    }

    /* check if mandatory arguments were provided */
    if (argv_index_host < 0 || argv_index_pport < 0 || argv_index_cport < 0)
    {
        printf("Expected --host, --pport, and --cport options\n");
        return 1;
    }

    // --------------------------------------------------------------------------
    // set the log levels

    nmf_api_set_global_log_level(log_level);

    /* we expect an error when checking if a parameter already exists or not via a listDefinition request */
    /* make the listDefintion consumer logs less verbose in light of this (i.e don't display error logs) */
    mc_parameter_listdefinition_consumer_set_log_level(CLOG_FATAL_LEVEL);


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
    // it's the service that implements the addParameter operation

    /* the response error code */
    int rc;

    /* get pointer to the Parameter service */
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);


    // --------------------------------------------------------------------------
    // create a list of new parameters

    /* list of param names */
    char *param_name_list[] = {
        "NEWPAR01", /* MAL String */
        "NEWPAR02", /* MAL String */
        "NEWPAR03", /* MAL String */
        "NEWPAR04", /* MAL String */
        "NEWPAR05"  /* MAL String */
    };

    /* list of param raw types */
    unsigned char param_raw_type_list[] = {
        MAL_STRING_ATTRIBUTE_TAG, /* NEWPAR01 */
        MAL_STRING_ATTRIBUTE_TAG, /* NEWPAR02 */
        MAL_STRING_ATTRIBUTE_TAG, /* NEWPAR03 */
        MAL_STRING_ATTRIBUTE_TAG, /* NEWPAR04 */
        MAL_STRING_ATTRIBUTE_TAG  /* NEWPAR05 */
    };

    /* list of params ids assigned to the created parameters */
    long param_id_list[5] = {0};

    /* list of param values to set */
    char *param_values_list[] = {
        "Ground ",
        "Control, ",
        "adding ",
        "parameters ",
        "works!"
    };

    /* calculate list size */
    size_t param_list_size = sizeof(param_name_list) / sizeof(param_name_list[0]);

    /* response variables */
    long param_identity_id;
    long param_definition_id;


    // --------------------------------------------------------------------------
    // create parameters via the addParameter request

    printf("\naddParameter:\n=============\n\n");

    for(int i = 0; i < param_list_size; i++)
    {
        /* use the listDefinition operation to check if the parameter we want to create already exists */
        rc = mc_parameter_service_get_definition(parameter_service, param_name_list[i], &param_identity_id, &param_definition_id);

        /* if the parameter already exists then don't try to add it (it will trigger a DUPLICATE error) */
        /* instead, remove it and then add it (this serves to also test the removeParameter operation) */
        if(rc == 0)
        {
            /* keep track of the ids of the created params */
            param_id_list[i] = param_identity_id;

            /* verbosity */
            printf("The %s parameter already exists with instance identity id %ld and definition id %ld",
                param_name_list[i], param_identity_id, param_definition_id);

            /* remove parameter */
            rc = mc_parameter_service_remove_parameter(parameter_service, param_identity_id);

            if(rc == 0)
            {
                printf(": removed it\n");
            }
            else
            {
                printf("\nFailed to remove %s, using its existing definition\n", param_name_list[i]);
            }
        }
        else
        {
            /* parameter to add does not exist because listDefintion returned an error */
            /* this is what we want so reset the return code to non error value */
            rc = 0;

            /* also print a message stating that the logged listDefinition error is normal */
            printf("The above error message is expected (it means that the parameter does not already exist)\n");
        }

        if(rc == 0)
        {
            /* send the addParameter request with the response variable pointers */
            rc = mc_parameter_service_add_parameter(parameter_service,
                param_name_list[i], NULL, param_raw_type_list[i], NULL, false, 0,
                &param_identity_id, &param_definition_id);

            /* error check */
            if(rc < 0)
            {
                /* print error message */
                printf("Error adding %s\n", param_name_list[i]);
            }
            else
            {
                /* keep track of the ids of the created params */
                param_id_list[i] = param_identity_id;

                /* verbosity */
                printf("Added %s with instance identity id %ld and definition id %ld\n", param_name_list[i], param_identity_id, param_definition_id);
            }
        }

        /* for Terminal output clarity */
        printf("\n");
    }


    // --------------------------------------------------------------------------
    // set the parameter values for the created parameters
    // FIXME: Not currently working, see TODO in header comment.

    printf("\nsetValue:\n=========\n\n");

    for(int i = 0; i < param_list_size; i++)
    {
        /* verbosity */
        printf("Set %s value to '%s'\n", param_name_list[i], param_values_list[i]);

        /* trigger the setValue submit interaction */
        rc = mc_parameter_service_set_value(parameter_service, param_id_list[i], MAL_STRING_ATTRIBUTE_TAG, param_values_list[i]);

        /* check for error */
        if(rc != 0)
        {
            /* print error message */
            printf("Error setting value for %s\n", param_name_list[i]);
        }
    }


    // --------------------------------------------------------------------------
    // get the parameter values to validate that they were set as expected
    // FIXME: Not currently working, see TODO in header comment.

    printf("\ngetValue:\n=========\n\n");

    char *param_value;
    for(int i = 0; i < param_list_size; i++)
    {
        rc = mc_parameter_service_get_value_string(parameter_service, param_id_list[i], &param_value);

        /* check for error */
        if(rc != 0)
        {
            /* print error message */
            printf("Error getting value for %s\n", param_name_list[i]);
        }
        else
        {
            printf("%s", param_value);
        }
    }


    // --------------------------------------------------------------------------
    // destroy

    /* destoying the API gateway object also destroys all service objects */
    nmf_api_destroy(&nmf_api);

    /* end of program */
    return 0;
}
