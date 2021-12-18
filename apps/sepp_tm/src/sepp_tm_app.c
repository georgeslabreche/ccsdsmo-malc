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
//  Declare global variables

// The Gateway API object to access all services
nmf_api_t *nmf_api;


//  --------------------------------------------------------------------------
//  Declare global variables
int
fetch_apps_running_count(int *apps_running_count)
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
            *apps_running_count++;
        }
    }

    /* return the error code */
    /* reaching this point means there were no errors */
    return rc;
}


//  --------------------------------------------------------------------------
//  The main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;

    /* init log level for the NMF API */
    sepp_tm_utils_init_nmfapi_log_level(CLOG_ERROR_LEVEL);

    //  --------------------------------------------------------------------------
    //  Init the NMF Service Provider API

    /* char array for provider host and port */
    char host[20] = {0};
    char port[5] = {0};

    /* set provider host and port */
    sepp_tm_utils_init_provider_host_and_port(host, port);

    /* initialize the Gateway API object to access NMF services */
    nmf_api = nmf_api_new(host, port, "1025");


    //  --------------------------------------------------------------------------
    //  apps running

    /* fetch apps running */
    int apps_running_count = 0;
    res = fetch_apps_running_count(&apps_running_count);
    
    if(res != 0)
    {
        printf("error fetching number of apps running\n");
    }
    else
    {
        /* print fetched value */
        printf("apps running: %d\n", apps_running_count);
    }

    //  --------------------------------------------------------------------------
    //  uptime

    /* fetch uptime */
    char uptime[16] = {0};
    res = shell_proxy_get_uptime(uptime);

    if(res != 0)
    {
        printf("error fetching uptime\n");
    }
    else
    {
        /* print fetched value */
        printf("uptime: %s\n", uptime);
    }


    //  --------------------------------------------------------------------------
    //  free CPU

    /* free CPU struct */
    struct sepp_tm_free_cpu_t *sepp_tm_free_cpu;
    sepp_tm_free_cpu = (struct sepp_tm_free_cpu_t*)malloc(sizeof(struct sepp_tm_free_cpu_t));
    
    /* init the struct char array members */
    sepp_tm_utils_init_struct_free_cpu(sepp_tm_free_cpu);

    /* fetch free CPU */
    res = shell_proxy_get_free_cpu(sepp_tm_free_cpu);

    if(res != 0)
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
    }


    //  --------------------------------------------------------------------------
    //  free memory

    /* free memory struct */
    struct sepp_tm_free_memory_t *sepp_tm_free_memory;
    sepp_tm_free_memory = (struct sepp_tm_free_memory_t*)malloc(sizeof(struct sepp_tm_free_memory_t));

    /* init the struct char array members */
    sepp_tm_utils_init_struct_free_memory(sepp_tm_free_memory);

    /* fetch free memory */
    res = shell_proxy_get_free_memory(sepp_tm_free_memory);

    if(res != 0)
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
    }


    //  --------------------------------------------------------------------------
    //  disk usage

    /* disk usage struct */
    struct sepp_tm_disk_usage_t *sepp_tm_disk_usage;
    sepp_tm_disk_usage = (struct sepp_tm_disk_usage_t*)malloc(sizeof(struct sepp_tm_disk_usage_t));

    /* init the struct char array members */
    sepp_tm_utils_init_struct_disk_usage(sepp_tm_disk_usage);

    /* fetch disk usage */
    res = shell_proxy_get_disk_usage(sepp_tm_disk_usage);

    if(res != 0)
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
    }


    //  --------------------------------------------------------------------------
    //  fpga image loaded

    /* fetch id of loaded fpga image */
    char image_id[12] = {0};
    res = shell_proxy_get_fpga_image_loaded(image_id);

    if(res != 0)
    {
        printf("error fetching fpga image id\n");
    }
    else
    {
        /* print fetched value */
        printf("fpga image loaded: %s\n", image_id);
    }


    //  --------------------------------------------------------------------------
    //  out of memory counter

    /* fetch oom counter */
    char oom_counter[1] = {0};
    res = shell_proxy_get_oom_counter(oom_counter);

    if(res != 0)
    {
        printf("error fetching oom count\n");
    }
    else
    {
        /* print fetched value */
        printf("oom count: %s\n", oom_counter);
    }


    //  --------------------------------------------------------------------------
    //  toGround file counter

    /* fetch */
    char toGround_count[4] = {0};
    res = shell_proxy_get_file_count_toGround(toGround_count);

    if(res != 0)
    {
        printf("error fetching toGround file count\n");
    }
    else
    {
        /* print fetched value */
        printf("toGround file count: %s\n", toGround_count);
    }


    //  --------------------------------------------------------------------------
    //  toGroundLP file counter

    /* fetch */
    char toGroundLP_count[4] = {0};
    res = shell_proxy_get_file_count_toGroundLP(toGroundLP_count);

    if(res != 0)
    {
        printf("error fetching toGroundLP file count\n");
    }
    else
    {
        /* print fetched value */
        printf("toGroundLP file count: %s\n", toGroundLP_count);
    }

    //  --------------------------------------------------------------------------
    //  core counter

    /* fetch */
    char core_count[1] = {0};
    res = shell_proxy_get_core_counter(core_count);

    if(res != 0)
    {
        printf("error fetching core count\n");
    }
    else
    {
        /* print fetched value */
        printf("core count: %s\n", core_count);
    }

    //  --------------------------------------------------------------------------
    //  rescue shell status

    /* fetch */
    char shell_status[1] = {0};
    res = shell_proxy_get_rescue_shell_status(shell_status);

    if(res != 0)
    {
        printf("error fetching rescue shell status\n");
    }
    else
    {
        /* print fetched value */
        printf("rescue shell status: %s\n", shell_status);
    }


    //  --------------------------------------------------------------------------
    //  CAN bridge status

    /* fetch */
    char spp_bridge[1] = {0};
    res = shell_cmd_dispatcher_get_spp_bridge(spp_bridge);

    if(res != 0)
    {
        printf("error fetching rescue spp bridge\n");
    }
    else
    {
        /* print fetched value */
        printf("spp bridge status: %s\n", spp_bridge);
    }


    //  --------------------------------------------------------------------------
    //  CAN bridge status (packetstore)

    /* fetch */
    char spp_bridge_ps[1] = {0};
    res = shell_cmd_dispatcher_get_spp_bridge_packetstore(spp_bridge_ps);

    if(res != 0)
    {
        printf("error fetching rescue spp bridge packetstore\n");
    }
    else
    {
        /* print fetched value */
        printf("spp bridge packetstore status: %s\n", spp_bridge_ps);
    }


    //  --------------------------------------------------------------------------
    //  cleanup

    // destroy the structs
    free(sepp_tm_free_memory);
    free(sepp_tm_free_cpu);
    free(sepp_tm_disk_usage);

    // destoy the API gateway object, also destroys all service objects
    nmf_api_destroy(&nmf_api);

    return 0;
}
