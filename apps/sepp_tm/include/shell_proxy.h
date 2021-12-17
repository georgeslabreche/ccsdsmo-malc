/*  =========================================================================
    shell_proxy - triggers bash command execution and parses stdout

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

// Get FPGA image loaded
SEPP_TM_EXPORT int
    shell_proxy_get_fpga_image_loaded (char *image_id);

//  Get OOM counter
SEPP_TM_EXPORT int
    shell_proxy_get_oom_counter (char *oom_counter);

//  Get file count toGround
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGround (char *toGound_count);

//  Get file count toGroundLP
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGroundLP (char *toGroundLP_count);

// Get core counter
SEPP_TM_EXPORT int
    shell_proxy_get_core_counter (char *core_counter);

// Get rescue shell status
SEPP_TM_EXPORT int
    shell_proxy_get_rescue_shell_status (char *status);

// Get status of the CAN bridge
SEPP_TM_EXPORT int
    shell_proxy_get_spp_bridge (char *spp_bridge);

// Get status of the CAN bridge (packetstore)
SEPP_TM_EXPORT int
    shell_proxy_get_spp_bridge_packetstore (char *spp_brdige);

//  @end

#ifdef __cplusplus
}
#endif

#endif
