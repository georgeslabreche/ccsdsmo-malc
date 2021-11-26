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
//  The main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;


    //  --------------------------------------------------------------------------
    //  uptime

    /* fetch uptime */
    char uptime[16];
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
    }


    //  --------------------------------------------------------------------------
    //  disk usage

    /* disk usage struct */
    struct sepp_tm_disk_usage_t *sepp_tm_disk_usage;
    sepp_tm_disk_usage = (struct sepp_tm_disk_usage_t*)malloc(sizeof(struct sepp_tm_disk_usage_t));

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
    char image_id[12];
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
    char oom_counter[1024];
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

    /* fetch  */
    char toGround_count[1024];
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

    char toGroundLP_count[1024];
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

    char core_count[1];
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

    char shell_status[1];
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

    //  --------------------------------------------------------------------------
    //  CAN bridge status (packetstore)

    
    //  --------------------------------------------------------------------------
    //  cleanup

    free(sepp_tm_free_memory);
    free(sepp_tm_free_cpu);
    free(sepp_tm_disk_usage);

    return 0;
}
