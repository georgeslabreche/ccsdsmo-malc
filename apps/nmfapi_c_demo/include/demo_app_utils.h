/*  =========================================================================
    demo_app_utils - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef DEMO_APP_UTILS_H_INCLUDED
#define DEMO_APP_UTILS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new demo_app_utils
NMFAPI_C_DEMO_EXPORT demo_app_utils_t *
    demo_app_utils_new (void);

//  Destroy the demo_app_utils
NMFAPI_C_DEMO_EXPORT void
    demo_app_utils_destroy (demo_app_utils_t **self_p);


//  @end

#ifdef __cplusplus
}
#endif

#endif
