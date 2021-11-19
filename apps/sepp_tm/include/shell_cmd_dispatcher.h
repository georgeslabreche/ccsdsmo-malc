/*  =========================================================================
    shell_cmd_dispatcher - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SHELL_CMD_DISPATCHER_H_INCLUDED
#define SHELL_CMD_DISPATCHER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  Get Linux uptime (in seconds)
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_uptime (char *std_out);

//  Get free memory
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_free_memory (char *std_out);

//  Get free CPU
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_free_cpu (char *std_out);

//  Get disk usage
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_disk_usage (char *std_out);

//  Get OOM counter
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_oom_counter (char *std_out);

//  Get file count toGround
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_file_count_toGround (char *std_out);

//  Get file count toGroundLP
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_file_count_toGroundLP (char *std_out);

// Get FPGA image loaded
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_fpga_image_loaded (char *std_out);

// Get core counter
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_core_counter (char *std_out);

// Get rescue shell status
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_rescue_shell_status (char *std_out);

// Get status of the CAN bridge
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_spp_bridge (char *std_out);

// Get status of the CAN bridge (packetstore)
SEPP_TM_EXPORT int
    shell_cmd_dispatcher_get_spp_bridge_packetstore (char *std_out);

//  @end

#ifdef __cplusplus
}
#endif

#endif
