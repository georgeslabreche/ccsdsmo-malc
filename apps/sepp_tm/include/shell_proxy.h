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

//  @interface
//  Create a new shell_proxy
SEPP_TM_EXPORT shell_proxy_t *
    shell_proxy_new (void);

//  Destroy the shell_proxy
SEPP_TM_EXPORT void
    shell_proxy_destroy (shell_proxy_t **self_p);

//  Get Linux uptime (in seconds)
SEPP_TM_EXPORT int
    shell_proxy_get_uptime (shell_proxy_t *self_p, char *std_out);

//  Get free memory
SEPP_TM_EXPORT int
    shell_proxy_get_free_memory (shell_proxy_t *self_p, char *std_out);

//  Get free CPU
SEPP_TM_EXPORT int
    shell_proxy_get_free_cpu (shell_proxy_t *self_p, char *std_out);

//  Get disk usage
SEPP_TM_EXPORT int
    shell_proxy_get_disk_usage (shell_proxy_t *self_p, char *std_out);

//  Get OOM counter
SEPP_TM_EXPORT int
    shell_proxy_get_oom_counter (shell_proxy_t *self_p, char *std_out);

//  Get file count toGround
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGround (shell_proxy_t *self_p, char *std_out);

//  Get file count toGroundLP
SEPP_TM_EXPORT int
    shell_proxy_get_file_count_toGroundLP (shell_proxy_t *self_p, char *std_out);

// Get FPGA image loaded
SEPP_TM_EXPORT int
    shell_proxy_get_fpga_image_loaded (shell_proxy_t *self_p, char *std_out);

// Get core counter
SEPP_TM_EXPORT int
    shell_proxy_get_core_counter (shell_proxy_t *self_p, char *std_out);

// Get rescue shell status
SEPP_TM_EXPORT int
    shell_proxy_get_rescue_shell_status (shell_proxy_t *self_p, char *std_out);

//  @end

#ifdef __cplusplus
}
#endif

#endif
