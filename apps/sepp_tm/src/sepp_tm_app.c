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
#define SHELL_STDOUT_BUFFER_SIZE              500
char shell_outbuf[SHELL_STDOUT_BUFFER_SIZE];

//  --------------------------------------------------------------------------
//  The main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;

    /* shell proxy object to execute shell commands and read their outputs */
    shell_proxy_t *shell_proxy = shell_proxy_new();

    /* fetch uptime */
    res = shell_proxy_get_uptime(shell_proxy, shell_outbuf);

    if(res != 0)
    {
        printf("Failed to fetch uptime.\n");
    }
    else
    {
        /* write line to stdout */
        printf("Uptime: %s\n", shell_outbuf);
    }

    /* destroy the shell project object */
    shell_proxy_destroy(&shell_proxy);

    return 0;
}
