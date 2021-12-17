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
//  init free mem struct members

void
init_struct_free_memory (sepp_tm_free_memory_t *sepp_tm_free_memory)
{
    memset(sepp_tm_free_memory->total, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->used, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->free, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->shared, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->buffers, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->cached, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->used_minus_bufferscache, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->free_plus_bufferscache, 0, FREE_MEMORY_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  init free cpu struct members

void
init_struct_free_cpu (sepp_tm_free_cpu_t *sepp_tm_free_cpu)
{
    memset(sepp_tm_free_cpu->usr, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->sys, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->nic, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->idle, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->io, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->irq, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->sirq, 0, FREE_CPU_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  init disk usage struct members

void
init_struct_disk_usage (sepp_tm_disk_usage_t *sepp_tm_disk_usage)
{
    memset(sepp_tm_disk_usage->size, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->used, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->available, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->available_percentage, 0, DISK_USAGE_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  the main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;


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
    init_struct_free_cpu(sepp_tm_free_cpu);

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
    init_struct_free_memory(sepp_tm_free_memory);

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
    init_struct_disk_usage(sepp_tm_disk_usage);

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

    free(sepp_tm_free_memory);
    free(sepp_tm_free_cpu);
    free(sepp_tm_disk_usage);

    return 0;
}
