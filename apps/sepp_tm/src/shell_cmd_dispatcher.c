/*  =========================================================================
    shell_cmd_dispatcher - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    shell_cmd_dispatcher -
@discuss
@end
*/

#include "sepp_tm_classes.h"


int
shell_cmd_dispatcher_execute_command (char *command, char *std_out)
{
    /* file pointer */
    FILE *fp;

    /* use popen to read output from command */
    fp = popen(command, "r");

    /* error check */
    if (!fp)
    {
        return -1;
    }

    /* read stdout line into char buffer */
    char line[128];
    int offset = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        strcpy(std_out + offset, line);
        offset = offset + strlen(line);
    }

    /* error check */
    if (ferror(fp))
    {
        fclose(fp);
        return -1;
    }

    /* cleanup */
    fclose(fp);

    /* success */
    return 0;
}


//  --------------------------------------------------------------------------
//  Get Linux uptime in seconds

int
shell_cmd_dispatcher_get_uptime (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("awk '{print int($1)}' /proc/uptime", std_out);
}

//  --------------------------------------------------------------------------
//  Get free memory

int
shell_cmd_dispatcher_get_free_memory (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("free", std_out);
}

//  --------------------------------------------------------------------------
//  Get free CPU

int
shell_cmd_dispatcher_get_free_cpu (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("top -n1 | head -n2 | tail -n1", std_out);
}

//  --------------------------------------------------------------------------
//  Get disk usage

int
shell_cmd_dispatcher_get_disk_usage (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("df -m | head -n2", std_out);
}

//  --------------------------------------------------------------------------
//  Get OOM counter

int
shell_cmd_dispatcher_get_oom_counter (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("dmesg | { grep -c 'Out of memory' || true; }", std_out);
}

//  --------------------------------------------------------------------------
//  Get file count toGround

int
shell_cmd_dispatcher_get_file_count_toGround (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("ls -F | grep -v /home/root/esoc-apps/fms/filestore/toGround | wc -l", std_out);
}

//  --------------------------------------------------------------------------
//  Get file count toGroundLP

int
shell_cmd_dispatcher_get_file_count_toGroundLP (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("ls -F | grep -v /home/root/esoc-apps/fms/filestore/toGroundLP | wc -l", std_out);
}

//  --------------------------------------------------------------------------
// Get FPGA image loaded

int
shell_cmd_dispatcher_get_fpga_image_loaded (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("devmem {}", std_out);
}

//  --------------------------------------------------------------------------
// Get core counter

int
shell_cmd_dispatcher_get_core_counter (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("cat /proc/cpuinfo | grep processor | wc -l", std_out);
}

//  --------------------------------------------------------------------------
// Get rescue shell status

int
shell_cmd_dispatcher_get_rescue_shell_status (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("systemctl status | head -n2 | tail -n1 | awk '{print $2}'", std_out);
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge

int
shell_cmd_dispatcher_get_spp_bridge (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("systemctl status spp_bridge", std_out);
}

//  --------------------------------------------------------------------------
// Get status of the CAN bridge (packetstore)

int
shell_cmd_dispatcher_get_spp_bridge_packetstore (char *std_out)
{
    /* execute command */
    return shell_cmd_dispatcher_execute_command("systemctl status spp_bridge_packetstore", std_out);
}