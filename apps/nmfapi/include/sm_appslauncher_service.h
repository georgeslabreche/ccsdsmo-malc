/*  =========================================================================
    sm_appslauncher_service - The Apps Launcher service provides the ability to monitor
the execution, run, stop, kill and list applications software on-board of a spacecraft

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SM_APPSLAUNCHER_SERVICE_H_INCLUDED
#define SM_APPSLAUNCHER_SERVICE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/sm_appslauncher_service.api" to make changes.
//  @interface
//  This API is a draft, and may change without notice.
#ifdef NMFAPI_BUILD_DRAFT_API
//  *** Draft method, for development use, may change without warning ***
//  Instanciate a Apps Launcher service object
NMFAPI_EXPORT sm_appslauncher_service_t *
    sm_appslauncher_service_new (char *host, char *provider_port, char *consumer_port);

//  *** Draft method, for development use, may change without warning ***
//  The destructor
NMFAPI_EXPORT void
    sm_appslauncher_service_destroy (sm_appslauncher_service_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Set the log level
NMFAPI_EXPORT void
    sm_appslauncher_service_set_log_level (sm_appslauncher_service_t *self, int level);

//  *** Draft method, for development use, may change without warning ***
//  The listApp operation allows a consumer to request the object instance identifiers
//  of the Apps objects and running status for an app name or for a certain app category
NMFAPI_EXPORT void
    sm_appslauncher_service_list_app (sm_appslauncher_service_t *self, char **app_names, size_t app_names_size, char *category, long **response_apps_inst_ids, bool **response_apps_running, size_t *response_apps_count);

#endif // NMFAPI_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
