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

/* buffer for shell command stdout */
#define OUTPUT_BUFFER_SIZE              1024
char output[OUTPUT_BUFFER_SIZE];


//  --------------------------------------------------------------------------
//  The main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;

    /* fetch uptime */
    res = shell_proxy_get_uptime(output);

    if(res == 0)
    {
        printf("uptime: %s\n", output);
    }

    /* TODO: fetch free CPU */

    /* fetch free memory */
    res = shell_proxy_get_free_memory(output);

    /* fetch disk usage */
    res = shell_proxy_get_disk_usage(output);

    return 0;
}
