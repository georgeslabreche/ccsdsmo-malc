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

    if(res == 0)
    {
        printf("uptime: %s\n", uptime);
    }

    /* TODO: fetch free CPU */

    /* fetch free memory */
    struct sepp_tm_free_memory_t *sepp_tm_free_memory;
    sepp_tm_free_memory = (struct sepp_tm_free_memory_t*)malloc(sizeof(struct sepp_tm_free_memory_t));

    res = shell_proxy_get_free_memory(sepp_tm_free_memory);

    printf("TOTAL FREE MEME %s", sepp_tm_free_memory->total);

    free(sepp_tm_free_memory);

    /* fetch disk usage */
    //res = shell_proxy_get_disk_usage(output);

    return 0;
}
