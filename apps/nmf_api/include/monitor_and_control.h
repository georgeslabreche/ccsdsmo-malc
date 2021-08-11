/*  =========================================================================
    monitor_and_control - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef MONITOR_AND_CONTROL_H_INCLUDED
#define MONITOR_AND_CONTROL_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new monitor_and_control
NMF_API_EXPORT monitor_and_control_t *
    monitor_and_control_new (void);

//  Destroy the monitor_and_control
NMF_API_EXPORT void
    monitor_and_control_destroy (monitor_and_control_t **self_p);

//  Self test of this class
NMF_API_EXPORT void
    monitor_and_control_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
