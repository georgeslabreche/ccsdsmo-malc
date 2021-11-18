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

//  Destroy the shell_proxy
SEPP_TM_EXPORT int
    shell_proxy_get_uptime (shell_proxy_t *self_p, char *stdout);

//  @end

#ifdef __cplusplus
}
#endif

#endif
