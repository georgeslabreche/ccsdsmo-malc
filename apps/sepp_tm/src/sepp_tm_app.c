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
#define STDOUT_BUFFER_SIZE              1024
char std_out[STDOUT_BUFFER_SIZE];

void process_shell_stdout(char *id, int res, char *std_out)
{
    if(res != 0)
    {
        printf("Failed to fetch %s.\n", id);
    }
    else
    {
        /* print command output */
        printf("%s:\n %s\n", id, std_out);
    }
}

//  --------------------------------------------------------------------------
//  The main program

int main (int argc, char *argv [])
{
    /* response code */
    int res;

    /* shell proxy object to execute shell commands and read their outputs */
    shell_proxy_t *shell_proxy = shell_proxy_new();

    /* fetch Linux uptime */
    res = shell_proxy_get_uptime(shell_proxy, std_out);

    /* process output */
    process_shell_stdout("uptime", res, std_out);


    /* fetch free memory */
    res = shell_proxy_get_free_memory(shell_proxy, std_out);

    /* process output */
    process_shell_stdout("free memory", res, std_out);


    /* TODO: fetch free CPU */


    /* fetch disk usage */
    res = shell_proxy_get_disk_usage(shell_proxy, std_out);

    /* process output */
    process_shell_stdout("disk usage", res, std_out);


    /* destroy the shell project object */
    shell_proxy_destroy(&shell_proxy);

    return 0;
}
