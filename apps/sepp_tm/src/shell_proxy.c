/*  =========================================================================
    shell_proxy - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    shell_proxy -
@discuss
@end
*/

#include "sepp_tm_classes.h"


void shell_proxy_process_stdout (char *id, int res, char *std_out)
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
//  Get Linux uptime in seconds

int
shell_proxy_get_uptime (char *uptime)
{
    /* response code */
    int res;

    /* fetch Linux uptime */
    res = shell_cmd_dispatcher_get_uptime(uptime);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    uptime[strcspn(uptime, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get free memory

int
shell_proxy_get_free_memory (char *std_out)
{
    int res;

    /* fetch free memory */
    res = shell_cmd_dispatcher_get_free_memory(std_out);

    /* process output */
    shell_proxy_process_stdout("free memory", res, std_out);

    return res;
}

//  --------------------------------------------------------------------------
//  Get free CPU

int
shell_proxy_get_free_cpu (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
//  Get disk usage

int
shell_proxy_get_disk_usage (char *std_out)
{
    int res;

    res = shell_cmd_dispatcher_get_disk_usage(std_out);

    /* process output */
    shell_proxy_process_stdout("disk usage", res, std_out);

    return res;
}

//  --------------------------------------------------------------------------
//  Get OOM counter

int
shell_proxy_get_oom_counter (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
//  Get file count toGround

int
shell_proxy_get_file_count_toGround (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
//  Get file count toGroundLP

int
shell_proxy_get_file_count_toGroundLP (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
// Get FPGA image loaded

int
shell_proxy_get_fpga_image_loaded (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
// Get core counter

int
shell_proxy_get_core_counter (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
// Get rescue shell status

int
shell_proxy_get_rescue_shell_status (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge

int
shell_proxy_get_spp_bridge (char *std_out)
{
    /* execute command */
    return 0;
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge (packetstore)

int
shell_proxy_get_spp_bridge_packetstore (char *std_out)
{
    /* execute command */
    return 0;
}