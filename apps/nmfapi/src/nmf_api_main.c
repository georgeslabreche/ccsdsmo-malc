/*  =========================================================================
    nmf_api_main - A test main program

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api_main - A test main program
@discuss
@end
*/

#include "nmfapi_classes.h"

int main (int argc, char *argv [])
{
    char *host_sepp = "192.168.132.16";
    char *host_local = "192.168.0.119";

    // APPS LAUNCHER SERVICE
    sm_appslauncher_service_t *appslauncher_service = sm_appslauncher_service_new(host_local, 1024, 1025);

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
