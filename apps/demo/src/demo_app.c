/*  =========================================================================
    demo_app - Demo App

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

int main (int argc, char *argv [])
{
    // Get provider host and port from command arguments.
    int argv_index_host = -1;
    int argv_index_pport = -1;
    int argv_index_cport = -1;

    // Process command arguments
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-?")) {
            puts ("demo_app [options] ...");
            puts ("  --host  / -h        host");
            puts ("  --pport / -p        provider port");
            puts ("  --cport / -p        consumer port");
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
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }

    // Check if host and port were set.
    if (argv_index_host < 0 || argv_index_pport < 0 || argv_index_cport < 0)
    {
        printf ("Expected --host, --pport, and --cport options\n");
        return 1;
    }

    // APPS LAUNCHER SERVICE
    sm_appslauncher_service_t *appslauncher_service = sm_appslauncher_service_new(argv[argv_index_host], argv[argv_index_pport], argv[argv_index_cport]);

    // Request parameters
    char *app_names[] = {"*"};
    char *category = "*";
    
    // Request response variables
    long *response_apps_ids;
    bool *response_apps_running;
    size_t response_apps_count;

    // Send the listApp request and set the response variable pointers
    sm_appslauncher_service_list_app(appslauncher_service, app_names, 1, category,
        &response_apps_ids, &response_apps_running, &response_apps_count);

    // Print the request's response variable values
    for(size_t i = 0; i < response_apps_count; i++)
    {
        printf("App #%ld running status is %d\n", response_apps_ids[i], response_apps_running[i]);
    }

    // Destroy the service
    sm_appslauncher_service_destroy(&appslauncher_service);

    return 0;
}
