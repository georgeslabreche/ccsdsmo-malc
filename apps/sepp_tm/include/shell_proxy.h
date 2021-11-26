/*  =========================================================================
    shell_proxy - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SHELL_PROXY_H_INCLUDED
#define SHELL_PROXY_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  Get Linux uptime (in seconds)
SEPP_TM_EXPORT int
    shell_proxy_get_uptime (char *uptime);

//  Get free memory
SEPP_TM_EXPORT int
    shell_proxy_get_free_memory (sepp_tm_free_memory_t *sepp_tm_free_memory);

//  Get free CPU
SEPP_TM_EXPORT int
    shell_proxy_get_free_cpu (sepp_tm_free_cpu_t *sepp_tm_free_cpu);

//  Get disk usage
SEPP_TM_EXPORT int
    shell_proxy_get_disk_usage (sepp_tm_disk_usage_t *sepp_tm_disk_usage);

//  Get OOM counter
SEPP_TM_EXPORT int
    shell_proxy_get_oom_counter (char *output);

//  Get file count toGround
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGround (char *output);

//  Get file count toGroundLP
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGroundLP (char *output);

// Get FPGA image loaded
SEPP_TM_EXPORT int
    shell_proxy_get_fpga_image_loaded (char *output);

// Get core counter
SEPP_TM_EXPORT int
    shell_proxy_get_core_counter (char *output);

// Get rescue shell status
SEPP_TM_EXPORT int
    shell_proxy_get_rescue_shell_status (char *output);

// Get status of the CAN bridge
SEPP_TM_EXPORT int
    shell_proxy_get_spp_bridge (char *output);

// Get status of the CAN bridge (packetstore)
SEPP_TM_EXPORT int
    shell_proxy_get_spp_bridge_packetstore (char *output);

//  @end

#ifdef __cplusplus
}
#endif

#endif
