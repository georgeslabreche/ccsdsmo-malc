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

/* buffer for shell command stdout */
#define STDOUT_BUFFER_SIZE              1024
char std_out[STDOUT_BUFFER_SIZE];


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
shell_proxy_get_free_memory (sepp_tm_free_memory_t *sepp_tm_free_memory)
{
    int res;

    /* fetch free memory */
    res = shell_cmd_dispatcher_get_free_memory(std_out);

    /* parse output */
    res = res || shell_stdout_parser_parse_free_memory(std_out, sepp_tm_free_memory);

    return res;
}

//  --------------------------------------------------------------------------
//  Get free CPU

int
shell_proxy_get_free_cpu (sepp_tm_free_cpu_t *sepp_tm_free_cpu)
{
    int res;

    /* fetch free cpu */
    res = shell_cmd_dispatcher_get_free_cpu(std_out);

    /* parse output */
    res = res || shell_stdout_parser_parse_free_cpu(std_out, sepp_tm_free_cpu);

    return res;
}

//  --------------------------------------------------------------------------
//  Get disk usage

int
shell_proxy_get_disk_usage (sepp_tm_disk_usage_t *sepp_tm_disk_usage)
{
    int res;

    /* fetch disk usage */
    res = shell_cmd_dispatcher_get_disk_usage(std_out);

    /* parse stdout */
    res = res || shell_stdout_parser_parse_disk_usage(std_out, sepp_tm_disk_usage);
 
    return res;
}

//  --------------------------------------------------------------------------
// Get FPGA image loaded

int
shell_proxy_get_fpga_image_loaded (char *image_id)
{
    int res;

    /* fetch id of loaded fpga image */
    res = shell_cmd_dispatcher_get_fpga_image_loaded(std_out);

    /* parse stdout */
    res = res || shell_stdout_parser_parse_fpga_image_loaded(std_out, image_id);

    return res;
}

//  --------------------------------------------------------------------------
//  Get OOM counter

int
shell_proxy_get_oom_counter (char *oom_counter)
{
    /* fetch oom counter */
    int res = shell_cmd_dispatcher_get_oom_counter(oom_counter);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    oom_counter[strcspn(oom_counter, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get file count toGround

int
shell_proxy_get_file_count_toGround (char *toGound_count)
{
    /* fetch toGround file counter */
    int res = shell_cmd_dispatcher_get_file_count_toGround(toGound_count);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    toGound_count[strcspn(toGound_count, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get file count toGroundLP

int
shell_proxy_get_file_count_toGroundLP (char *toGroundLP_count)
{
    /* fetch toGroundLP file counter */
    int res = shell_cmd_dispatcher_get_file_count_toGroundLP(toGroundLP_count);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    toGroundLP_count[strcspn(toGroundLP_count, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
// Get core counter

int
shell_proxy_get_core_counter (char *core_counter)
{
    /* fetch oom counter */
    int res = shell_cmd_dispatcher_get_core_counter(core_counter);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    core_counter[strcspn(core_counter, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
// Get rescue shell status

int
shell_proxy_get_rescue_shell_status (char *status)
{
    /* fetch rescue shell status */
    int res = shell_cmd_dispatcher_get_rescue_shell_status(std_out);

    /* parse stdout */
    res = res || shell_stdout_parser_parse_shell_status(std_out, status);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    status[strcspn(status, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge

int
shell_proxy_get_spp_bridge (char *spp_bridge)
{
    /* fetch CAN bridge status */
    int res = shell_cmd_dispatcher_get_spp_bridge(spp_bridge);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    spp_bridge[strcspn(spp_bridge, "\r\n")] = 0;

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge (packetstore)

int
shell_proxy_get_spp_bridge_packetstore (char *spp_bridge)
{
    /* fetch CAN bridge status (packetstore) */
    int res = shell_cmd_dispatcher_get_spp_bridge_packetstore(spp_bridge);

    /* error check */
    if(res != 0)
    {
        /* return error code */
        return res;
    }

    /* remove carriage return and new line, if any */
    spp_bridge[strcspn(spp_bridge, "\r\n")] = 0;

    /* return response code */
    return res;
}