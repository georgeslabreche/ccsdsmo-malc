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

    /* fetch uptime */
    char uptime[16];
    res = shell_proxy_get_uptime(uptime);

    if(res != 0)
    {
        printf("uptime fetch error");
    }
    else
    {
        printf("uptime: %s\n", uptime);
    }

    /* TODO: fetch free CPU */

    /* free memory struct */
    struct sepp_tm_free_memory_t *sepp_tm_free_memory;
    sepp_tm_free_memory = (struct sepp_tm_free_memory_t*)malloc(sizeof(struct sepp_tm_free_memory_t));

    /* fetch free memory */
    res = shell_proxy_get_free_memory(sepp_tm_free_memory);

    if(res != 0)
    {
        printf("free mem fetch error\n");
    }
    else
    {
        /* print fetched valued */
        printf("mem\n");
        printf("\ttotal: %s\n", sepp_tm_free_memory->total);
        printf("\tused: %s\n", sepp_tm_free_memory->used);
        printf("\tfree: %s\n", sepp_tm_free_memory->free);
        printf("\tshared: %s\n", sepp_tm_free_memory->shared);
    }
    

    /* disk usage struct */
    struct sepp_tm_disk_usage_t *sepp_tm_disk_usage;
    sepp_tm_disk_usage = (struct sepp_tm_disk_usage_t*)malloc(sizeof(struct sepp_tm_disk_usage_t));

    /* fetch disk usage */
    res = shell_proxy_get_disk_usage(sepp_tm_disk_usage);

    if(res != 0)
    {
        printf("disk usage fetch error\n");
    }
    else
    {
        /* print fetched valued */
        printf("disk\n");
        printf("\tsize: %s\n", sepp_tm_disk_usage->size);
        printf("\tused: %s\n", sepp_tm_disk_usage->used);
        printf("\tavailable: %s\n", sepp_tm_disk_usage->available);
        printf("\tavailable_percentage: %s\n", sepp_tm_disk_usage->available_percentage);
    }
    

    /* cleanup */
    free(sepp_tm_free_memory);
    free(sepp_tm_disk_usage);

    return 0;
}
