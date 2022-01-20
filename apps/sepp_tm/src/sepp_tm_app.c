/*  =========================================================================
    sepp_tm_app - SEPP TM

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sepp_tm_app - SEPP TM
@discuss
@end
*/

#include "sepp_tm_classes.h"

//  --------------------------------------------------------------------------
//  Constants

#define ARRAY_SIZE_HOST                                20
#define ARRAY_SIZE_PPORT                                5
#define ARRAY_SIZE_CPORT                                5
#define DEFAULT_POLLING_FREQUENCY                      20 /* seconds */

//  --------------------------------------------------------------------------
//  SEPP datapool parameter names

#define PARAM_NAME_UPTIME                       "SEPTM001"      /* uptime */
#define PARAM_NAME_MEM_TOTAL                    "SEPTM002"      /* memory total */
#define PARAM_NAME_MEM_USED                     "SEPTM003"      /* memory used */
#define PARAM_NAME_MEM_FREE                     "SEPTM004"      /* memory free */
#define PARAM_NAME_MEM_SHARED                   "SEPTM005"      /* memory shared */
#define PARAM_NAME_MEM_BUFFERS                  "SEPTM006"      /* memory buffers */
#define PARAM_NAME_MEM_CACHED                   "SEPTM007"      /* memory cached */
#define PARAM_NAME_MEM_USED_MINUS_BC            "SEPTM008"      /* memory used minus buffers/cache */
#define PARAM_NAME_MEM_FREE_PLUS_BC             "SEPTM009"      /* memory free plus buffers/cache */
#define PARAM_NAME_CPU_USR                      "SEPTM010"      /* cpu use percentage from usr */
#define PARAM_NAME_CPU_SYS                      "SEPTM011"      /* cpu use percentage from sys */
#define PARAM_NAME_CPU_NIC                      "SEPTM012"      /* cpu use percentage from nic */
#define PARAM_NAME_CPU_IDLE                     "SEPTM013"      /* cpu use percentage from idle */
#define PARAM_NAME_CPU_IO                       "SEPTM014"      /* cpu use percentage from io */
#define PARAM_NAME_CPU_IRQ                      "SEPTM015"      /* cpu use percentage from irq */
#define PARAM_NAME_CPU_SIRQ                     "SEPTM016"      /* cpu use percentage from sirq */
#define PARAM_NAME_DISK_SIZE                    "SEPTM017"      /* disk size */
#define PARAM_NAME_DISK_USED                    "SEPTM018"      /* disk used */
#define PARAM_NAME_DISK_AVAILABLE               "SEPTM019"      /* disk available */
#define PARAM_NAME_DISK_AVAILABLE_PERCENTAGE    "SEPTM020"      /* disk available percentage */
#define PARAM_NAME_FPGA_LOADED                  "SEPTM021"      /* fpga image loaded */
#define PARAM_NAME_OOM_COUNT                    "SEPTM022"      /* out of memory counter */
#define PARAM_NAME_TOGROUND_FILE_COUNT          "SEPTM023"      /* toGround folder file counter */
#define PARAM_NAME_TOGROUNDLP_FILE_COUNT        "SEPTM024"      /* toGroundLP folder file counter  */
#define PARAM_NAME_CORE_COUNT                   "SEPTM025"      /* number of cores */
#define PARAM_NAME_RESCUE_SHELL_STATUS          "SEPTM026"      /* rescue shell status */
#define PARAM_NAME_APPS_RUNNING_COUNT           "SEPTM027"      /* number of apps running */
#define PARAM_NAME_CAN_SPP_BRIDGE_STATUS        "SEPTM028"      /* can spp bridge status */
#define PARAM_NAME_CAN_SPP_BRIDGE_PS_STATUS     "SEPTM029"      /* can spp bridge (packetstore) status */


//  --------------------------------------------------------------------------
//  Declare global variables

// The Gateway API object to access all services
nmf_api_t *nmf_api;

//  --------------------------------------------------------------------------
//  Init the NMF Service Provider API

int
init_nmf_api(char *arg_host, char *arg_pport, char *arg_cport)
{
    /* Fetch the default host and port values by reading the centralDirectoryService.uri file */

    /* char array for provider host and port */
    char phost[ARRAY_SIZE_HOST] = {0};
    char pport[ARRAY_SIZE_PPORT] = {0};

    /* char array for consumer port */
    char cport[ARRAY_SIZE_CPORT] = {0};

    /* set provider host and port */
    sepp_tm_utils_init_provider_host_and_port(phost, pport);

    /* set consumer port as an increment of the provider port */
    int cport_int;
    sscanf(pport, "%d", &cport_int);
    cport_int++;

    /* cast consumer port to string */
    sprintf(cport, "%d", cport_int);

    /* Default to values that were given via command arguments (overwrite values read from the centralDirectoryService.uri file) */
    if(strlen(arg_host) != 0)
    {
        strcpy(phost, arg_host);
    }

    if(strlen(arg_pport) != 0)
    {
        strcpy(pport, arg_pport);
    }

    if(strlen(arg_cport) != 0)
    {
        strcpy(cport, arg_cport);
    }

    /* initialize the Gateway API object to access NMF services */
    nmf_api = nmf_api_new(phost, pport, cport);

    // Check for error
    if(nmf_api == NULL)
    {
        return 1;
    }

    /* success */
    return 0;
}


//  --------------------------------------------------------------------------
//  Get parameter ids from NMF Supervisor

int
get_nmf_param_ids(char *param_name, long *param_identity_id, long *param_definition_id)
{
    /* the response error code */
    int rc;

    /* get pointer to the Parameter service */
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    /* send the listDefinition request for a single parameter */
    rc = mc_parameter_service_get_definition(parameter_service, param_name, param_identity_id, param_definition_id);

    /* error Checking */
    if(rc != 0)
    {
        /* return error code */
        return rc;
    }

    /* success */
    return 0;
}


//  --------------------------------------------------------------------------
//  Set parameter value in NMF Supervisor

int
set_nmf_param(char *param_name, unsigned char param_tag, char *param_value)
{
    /* response code */
    int rc;

     /* get pointer to the Parameter service */
    mc_parameter_service_t *parameter_service = nmf_api_get_mc_parameter_service(nmf_api);

    /* param ids */
    long param_identity_id;
    long param_definition_id;

    /* get param ids */
    rc = get_nmf_param_ids(param_name, &param_identity_id, &param_definition_id);

    /* create param in case of error when fetching param ids */

    /** 
     * TODO: should explicitely check for error code/message confirming that the
     * parameter does not exist instead of assuming that this is the root of the
     * error. there's always the possibility that an error is due to something else.
     * 
     * error mal message response decoding is not yet implementd in the NMF MAL C API.
     * https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/issues/33
     */
    if(rc != 0)
    {
        printf("create param %s\n", param_name);

        /* send the addParameter request with the response variable pointers */
        rc = mc_parameter_service_add_parameter(parameter_service,
            param_name, NULL, param_tag, NULL, false, 0,
            &param_identity_id, &param_definition_id);

        /* check for param creation error */
        if(rc != 0)
        {
            /* if error then print message and exit function with an error code */
            printf("error creating param %s\n", param_name);

            /* return the error code */
            return rc;
        }
    }

    /* set param value via the parameter service */
    if(rc == 0)
    {
        rc = mc_parameter_service_set_value(parameter_service, param_identity_id, param_tag, param_value);

        /* check for param setValue error */
        if(rc != 0)
        {
            /* if error then print message and exit function with an error code */
            printf("error setting param %s\n", param_name);

            /* return the error code */
            return rc;
        }
    }

    /* success */
    return rc;
}


//  --------------------------------------------------------------------------
//  Get number of apps running

int
get_apps_running_count(int *apps_running_count)
{
    /* the return code */
    int rc = 0;

    /* get pointer to the AppsLauncher service */
    sm_appslauncher_service_t *appslauncher_service = nmf_api_get_sm_appslauncher_service(nmf_api);

    /* request parameters */
    char *app_name_list[] = {"*"};
    char *category = "*";

    /* calculate size of app_name_list array */
    size_t app_name_list_size = sizeof(app_name_list) / sizeof(app_name_list[0]);
    
    /* request response variables */
    long *response_apps_inst_id_list;
    bool *response_apps_inst_running_list;
    size_t response_element_count;

    /* send the listApp request with the response variable pointers */
    rc = sm_appslauncher_service_list_app(appslauncher_service, app_name_list, app_name_list_size, category,
        &response_apps_inst_id_list, &response_apps_inst_running_list, &response_element_count);

    /* an error occured, return the error code */
    if(rc < 0)
    {
        return rc;
    }

    /* each response element corresponds to an app  */
    for(size_t i = 0; i < response_element_count; i++)
    {
        /* increment a counter if the app is running */
        if(response_apps_inst_running_list[i] == 1)
        {
            /* use parenthesis because ++ has equal precedence with the * and the associativity is right-to-left */
            (*apps_running_count)++;
        }
    }

    /* return the error code */
    /* reaching this point means there were no errors */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for the number of apps running

int
set_nmf_param_apps_running_count()
{
    /* response code */
    int rc;

    /* fetch apps running */
    int apps_running_count = 0;
    rc = get_apps_running_count(&apps_running_count);
    
    /* error check */
    if(rc != 0)
    {
        printf("error fetching number of apps running\n");
    }
    else
    {
        /* cast int to string because the setValue operation expects a string */
        char apps_running_count_str[3] = {0};
        sprintf(apps_running_count_str, "%d", apps_running_count);

        /* print fetched value */
        printf("apps running: %s\n", apps_running_count_str);

        /* set the param value via the parameter service */
        rc = set_nmf_param(PARAM_NAME_APPS_RUNNING_COUNT, MAL_UOCTET_ATTRIBUTE_TAG, apps_running_count_str);
    }

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for SEPP uptime

int
set_nmf_param_uptime()
{
    /* response code */
    int rc;

    /* fetch uptime */
    char uptime[10] = {0};
    rc = shell_proxy_get_uptime(uptime);

    if(rc != 0)
    {
        printf("error fetching uptime\n");
    }
    else
    {
        /* print fetched value */
        printf("uptime: %s\n", uptime);

        /* set the param value via the parameter service */
        rc = set_nmf_param(PARAM_NAME_UPTIME, MAL_UINTEGER_ATTRIBUTE_TAG, uptime);
    }

    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for free memory

int
set_nmf_param_free_mem()
{
    /* response code */
    int rc;

    /* free memory struct */
    struct sepp_tm_free_memory_t *sepp_tm_free_memory;
    sepp_tm_free_memory = (struct sepp_tm_free_memory_t*)malloc(sizeof(struct sepp_tm_free_memory_t));

    /* init the struct char array members */
    sepp_tm_utils_init_struct_free_memory(sepp_tm_free_memory);

    /* fetch free memory */
    rc = shell_proxy_get_free_memory(sepp_tm_free_memory);

    if(rc != 0)
    {
        printf("error fetching free memory\n");
    }
    else
    {
        /* print fetched values */
        printf("mem\n");
        printf("\ttotal: %s\n", sepp_tm_free_memory->total);
        printf("\tused: %s\n", sepp_tm_free_memory->used);
        printf("\tfree: %s\n", sepp_tm_free_memory->free);
        printf("\tshared: %s\n", sepp_tm_free_memory->shared);
        printf("\tbuffers: %s\n", sepp_tm_free_memory->buffers);
        printf("\tcached: %s\n", sepp_tm_free_memory->cached);
        printf("\tbuffers/cache used: %s\n", sepp_tm_free_memory->used_minus_bufferscache);
        printf("\tbuffers/cache free: %s\n", sepp_tm_free_memory->free_plus_bufferscache);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_MEM_TOTAL, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->total);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_USED, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->used);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_FREE, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->free);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_SHARED, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->shared);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_BUFFERS, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->buffers);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_CACHED, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->cached);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_USED_MINUS_BC, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->used_minus_bufferscache);
        rc = rc || set_nmf_param(PARAM_NAME_MEM_FREE_PLUS_BC, MAL_UINTEGER_ATTRIBUTE_TAG, sepp_tm_free_memory->free_plus_bufferscache);
    }

    /* destroy the struct */
    free(sepp_tm_free_memory);

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for free cpu

int
set_nmf_param_free_cpu()
{
    /* response code */
    int rc;

    /* free CPU struct */
    struct sepp_tm_free_cpu_t *sepp_tm_free_cpu;
    sepp_tm_free_cpu = (struct sepp_tm_free_cpu_t*)malloc(sizeof(struct sepp_tm_free_cpu_t));
    
    /* init the struct char array members */
    sepp_tm_utils_init_struct_free_cpu(sepp_tm_free_cpu);

    /* fetch free CPU */
    rc = shell_proxy_get_free_cpu(sepp_tm_free_cpu);

    if(rc != 0)
    {
        printf("error fetching free CPU\n");
    }
    else
    {
        /* print fetched values */
        printf("cpu\n");
        printf("\tusr: %s\n", sepp_tm_free_cpu->usr);
        printf("\tsys: %s\n", sepp_tm_free_cpu->sys);
        printf("\tnic: %s\n", sepp_tm_free_cpu->nic);
        printf("\tidle: %s\n", sepp_tm_free_cpu->idle);
        printf("\tio: %s\n", sepp_tm_free_cpu->io);
        printf("\tirq: %s\n", sepp_tm_free_cpu->irq);
        printf("\tsirq: %s\n", sepp_tm_free_cpu->sirq);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_CPU_USR, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->usr);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_SYS, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->sys);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_NIC, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->nic);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_IDLE, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->idle);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_IO, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->io);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_IRQ, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->irq);
        rc = rc || set_nmf_param(PARAM_NAME_CPU_SIRQ, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_free_cpu->sirq);
    }

    /* destroy the struct */
    free(sepp_tm_free_cpu);

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for disk usage

int
set_nmf_param_disk_usage()
{
    /* response code */
    int rc;

    /* disk usage struct */
    struct sepp_tm_disk_usage_t *sepp_tm_disk_usage;
    sepp_tm_disk_usage = (struct sepp_tm_disk_usage_t*)malloc(sizeof(struct sepp_tm_disk_usage_t));

    /* init the struct char array members */
    sepp_tm_utils_init_struct_disk_usage(sepp_tm_disk_usage);

    /* fetch disk usage */
    rc = shell_proxy_get_disk_usage(sepp_tm_disk_usage);

    if(rc != 0)
    {
        printf("error fetching disk usage\n");
    }
    else
    {
        /* print fetched values */
        printf("disk\n");
        printf("\tsize: %s\n", sepp_tm_disk_usage->size);
        printf("\tused: %s\n", sepp_tm_disk_usage->used);
        printf("\tavailable: %s\n", sepp_tm_disk_usage->available);
        printf("\tavailable_percentage: %s\n", sepp_tm_disk_usage->available_percentage);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_DISK_SIZE, MAL_USHORT_ATTRIBUTE_TAG, sepp_tm_disk_usage->size);
        rc = rc || set_nmf_param(PARAM_NAME_DISK_USED, MAL_USHORT_ATTRIBUTE_TAG, sepp_tm_disk_usage->used);
        rc = rc || set_nmf_param(PARAM_NAME_DISK_AVAILABLE, MAL_USHORT_ATTRIBUTE_TAG, sepp_tm_disk_usage->available);
        rc = rc || set_nmf_param(PARAM_NAME_DISK_AVAILABLE_PERCENTAGE, MAL_UOCTET_ATTRIBUTE_TAG, sepp_tm_disk_usage->available_percentage);
    }

    /* destroy the struct */
    free(sepp_tm_disk_usage);

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for loaded fpga image

int
set_nmf_param_fpga_loaded()
{
    /* response code */
    int rc;

    /* fetch */
    char image_id[32] = {0};
    rc = shell_proxy_get_fpga_image_loaded(image_id);

    if(rc != 0)
    {
        printf("error fetching fpga image id\n");
    }
    else
    {
        /* print fetched value */
        printf("fpga image loaded: %s\n", image_id);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_FPGA_LOADED, MAL_UINTEGER_ATTRIBUTE_TAG, image_id);
    }

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for out of memory count

int
set_nmf_param_oom_count()
{
    /* response code */
    int rc;

    /* fetch */
    char oom_counter[1] = {0};
    rc = shell_proxy_get_oom_counter(oom_counter);

    if(rc != 0)
    {
        printf("error fetching oom count\n");
    }
    else
    {
        /* print fetched value */
        printf("oom count: %s\n", oom_counter);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_OOM_COUNT, MAL_UINTEGER_ATTRIBUTE_TAG, oom_counter);
    }

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for toGround and toGroundLP file count

int
set_nmf_param_toGround_count()
{
    /* response code */
    int rc;
    int rc_set_param = -1;

    //  --------------------------------------------------------------------------
    //  toGround file counter

    /* fetch */
    char toGround_count[4] = {0};
    rc = shell_proxy_get_file_count_toGround(toGround_count);

    if(rc != 0)
    {
        printf("error fetching toGround file count\n");
    }
    else
    {
        /* print fetched value */
        printf("toGround file count: %s\n", toGround_count);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_TOGROUND_FILE_COUNT, MAL_USHORT_ATTRIBUTE_TAG, toGround_count);

        /* if this setValue fails then error response code will be -2 */
        if(rc != 0)
        {
            rc_set_param--;
        }
    }


    //  --------------------------------------------------------------------------
    //  toGroundLP file counter

    /* fetch */
    char toGroundLP_count[4] = {0};
    rc = shell_proxy_get_file_count_toGroundLP(toGroundLP_count);

    if(rc != 0)
    {
        printf("error fetching toGroundLP file count\n");
    }
    else
    {
        /* print fetched value */
        printf("toGroundLP file count: %s\n", toGroundLP_count);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_TOGROUNDLP_FILE_COUNT, MAL_USHORT_ATTRIBUTE_TAG, toGroundLP_count);

        /* if the previous setValue failed but this one didn't then the error code will be -2 */
        /* if the previous setValue didn't fail but this one did then the error code will be -2 */
        /* if the previous setValue AND this one failed then error code will be -3 */
        if(rc != 0)
        {
            rc_set_param--;
        }
    }

    /* If there's an error then return the error code*/
    if(rc != 0)
    {
        /* -1: error unrelated to setValue */
        /* -2: one of the two setValue returned an error (not both) */
        /* -3: both setValue returned errors */
        return rc_set_param;
    }
    
    /* no error */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for core count

int
set_nmf_param_core_count()
{
    /* response code */
    int rc;

    /* fetch */
    char core_count[1] = {0};
    rc = shell_proxy_get_core_counter(core_count);

    if(rc != 0)
    {
        printf("error fetching core count\n");
    }
    else
    {
        /* print fetched value */
        printf("core count: %s\n", core_count);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_CORE_COUNT, MAL_UOCTET_ATTRIBUTE_TAG, core_count);
    }

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for rescue shell status

int
set_nmf_param_rescue_shell_status()
{
    /* response code */
    int rc;

    /* fetch */
    char shell_status[1] = {0};
    rc = shell_proxy_get_rescue_shell_status(shell_status);

    if(rc != 0)
    {
        printf("error fetching rescue shell status\n");
    }
    else
    {
        /* print fetched value */
        printf("rescue shell status: %s\n", shell_status);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_RESCUE_SHELL_STATUS, MAL_UOCTET_ATTRIBUTE_TAG, shell_status);
    }

    /* return response code */
    return rc;
}


//  --------------------------------------------------------------------------
//  Set NMF param value for spp bridge status

int
set_nmf_param_can_spp_bridge_status()
{
    /* response code */
    int rc;
    int rc_set_param = -1;

    //  --------------------------------------------------------------------------
    //  CAN bridge status

    /* fetch */
    char spp_bridge[1] = {0};
    rc = shell_cmd_dispatcher_get_spp_bridge(spp_bridge);

    if(rc != 0)
    {
        printf("error fetching rescue spp bridge\n");
    }
    else
    {
        /* print fetched value */
        printf("spp bridge status: %s\n", spp_bridge);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_CAN_SPP_BRIDGE_STATUS, MAL_UINTEGER_ATTRIBUTE_TAG, spp_bridge);

        /* if this setValue fails then error response code will be -2 */
        if(rc != 0)
        {
            rc_set_param--;
        }
        
    }


    //  --------------------------------------------------------------------------
    //  CAN bridge status (packetstore)

    /* fetch */
    char spp_bridge_ps[1] = {0};
    rc = shell_cmd_dispatcher_get_spp_bridge_packetstore(spp_bridge_ps);

    if(rc != 0)
    {
        printf("error fetching rescue spp bridge packetstore\n");
    }
    else
    {
        /* print fetched value */
        printf("spp bridge packetstore status: %s\n", spp_bridge_ps);

        /* set the param values via the parameter service */
        rc = set_nmf_param(PARAM_NAME_CAN_SPP_BRIDGE_PS_STATUS, MAL_UINTEGER_ATTRIBUTE_TAG, spp_bridge_ps);
        
        /* if the previous setValue failed but this one didn't then the error code will be -2 */
        /* if the previous setValue didn't fail but this one did then the error code will be -2 */
        /* if the previous setValue AND this one failed then error code will be -3 */
        if(rc != 0)
        {
            rc_set_param--;
        }
    }

    /* If there's an error then return the error code*/
    if(rc != 0)
    {
        /* -1: error unrelated to setValue */
        /* -2: one of the two setValue returned an error (not both) */
        /* -3: both setValue returned errors */
        return rc_set_param;
    }
    
    /* no error */
    return rc;
}


//  --------------------------------------------------------------------------
//  Fetch SEPP environment data and set them as telemetry data in the NMF datapool param values

void set_nmf_param_all()
{
    /* number of apps running */
    set_nmf_param_apps_running_count();

    /* uptime */
    set_nmf_param_uptime();

    /* free memory */
    set_nmf_param_free_mem();

    /* free CPU */
    set_nmf_param_free_cpu();

    /* disk usage */
    set_nmf_param_disk_usage();

    /* fpga image loaded */
    set_nmf_param_fpga_loaded();

    /* out of memory counter */
    set_nmf_param_oom_count();

    /* toGround and toGroundLP counter */
    set_nmf_param_toGround_count();

    /* core counter */
    set_nmf_param_core_count();

    /* rescue shell status */
    set_nmf_param_rescue_shell_status();

    /* CAN bridge status */
    set_nmf_param_can_spp_bridge_status();
}


//  --------------------------------------------------------------------------
//  Parse main program arguments (all arguments are optional)

int parse_args (int argc, char *argv [], char *host, char *pport, char *cport, int *iter, uint *sleep, int *log_level)
{
    /* get provider host and port from command arguments */
    int argv_index_host = -1;
    int argv_index_pport = -1;
    int argv_index_cport = -1;
    int argv_index_iter = -1;
    int argv_index_sleep = -1;
    int argv_index_log = -1;

    /* only log errors by default */
    *log_level = CLOG_ERROR_LEVEL;

    // --------------------------------------------------------------------------
    // parse the command arguments (all arguments are optional)

    int argn;
    for (argn = 1; argn < argc; argn++)
    {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-?"))
        {
            printf("sepp_tm_app [options] ...");
            printf("\n  --host  / -h        hostname");
            printf("\n  --pport / -p        provider port");
            printf("\n  --cport / -p        consumer port");
            printf("\n  --iter  / -i        number of iterations");
            printf("\n  --sleep / -s        sleep time between iterations (in seconds)");
            printf("\n  --debug / -d        enable debug logging");
            printf("\n  --help  / -?        this information\n\n");
            
            /* program exit code */
            return 1;
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
        if (streq (argv [argn], "--iter")
        ||  streq (argv [argn], "-i"))
            argv_index_iter = ++argn;
        else
        if (streq (argv [argn], "--sleep")
        ||  streq (argv [argn], "-s"))
            argv_index_sleep = ++argn;
        else
        if (streq (argv [argn], "--debug")
        ||  streq (argv [argn], "-d"))
            *log_level = CLOG_DEBUG_LEVEL;
        else
        {
            /* print error message */
            printf("Unknown option: %s\n\n", argv[argn]);

            /* program exit code */
            return 1;
        }
    }

    /* set values for options that have been set via command arguments */
    /* default values for host and ports are read from the centralDirectoryService.uri file  */

    /* set the provider host */
    if(argv_index_host != -1)
    {
        strcpy(host, argv[argv_index_host]);
    }

    /* set the provider port */
    if(argv_index_pport != -1)
    {
        strcpy(pport, argv[argv_index_pport]);
    }

    /* set the consumer port */
    if(argv_index_cport != -1)
    {
        strcpy(cport, argv[argv_index_cport]);
    }

    /* set the number of iterations */
    *iter = argv_index_iter == -1 ? -1 : atoi(argv[argv_index_iter]);

    /* set the sleep time in between iterations */
    *sleep = argv_index_sleep == -1 ? DEFAULT_POLLING_FREQUENCY : (uint)atoi(argv[argv_index_sleep]);
    
    /* parse success */
    return 0;
}


//  --------------------------------------------------------------------------
//  The main program

int main (int argc, char *argv [])
{
    /* return code to check for errors or program exit codes */
    int rc = 0;

    /* optional program arguments */
    char host[ARRAY_SIZE_HOST] = {0};
    char pport[ARRAY_SIZE_PPORT] = {0};
    char cport[ARRAY_SIZE_CPORT] = {0};
    int iter;
    uint iter_sleep;
    int log_level;

    /* parse the given program arguments */
    rc = parse_args(argc, argv, host, pport, cport, &iter, &iter_sleep, &log_level);

    /* check for error code or program exit code */
    if (rc != 0)
    {
        /* exit program */
        return rc;
    }

    /* init log level */
    nmf_api_set_global_log_level(log_level);

    /* init the NMF Service Provider API */
    rc = init_nmf_api(host, pport, cport);

    /* check for error code or program exit code */
    if (rc != 0)
    {
        /* exit program */
        return rc;
    }

    /* program loop counter */
    uint loop_counter = 0;

    /* enter the program loop */
    while(1)
    {
        /* exit the program if the stop experiment file exists in the app's folder */
        /* this file is created when invoking the stop experiment bash script */
        if(access(".stop", F_OK) == 0)
        {
            break;
        }

        /* fetch SEPP environment data and set them as telemetry data in the NMF datapool param values */
        set_nmf_param_all();

        /* break out of the program loop when the target iteration number has been reached */
        /* if no target iteration number was specified as a prgram argument then the program loop is infinite */
        if(iter != -1)
        {
            /* increment loop counter */
            loop_counter++;

            /* break out of the loop is passed a given threshold */
            if(loop_counter >= iter)
            {
                break;
            }
        }

        /* wait before executing next iteration */
        sleep(iter_sleep);
    }

    /* destoy the API gateway object, also destroys all service objects */
    nmf_api_destroy(&nmf_api);

    /* end of program */
    return rc;
}
