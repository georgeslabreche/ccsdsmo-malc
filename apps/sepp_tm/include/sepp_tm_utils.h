/*  =========================================================================
    sepp_tm_utils - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SEPP_TM_UTILS_H_INCLUDED
#define SEPP_TM_UTILS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new sepp_tm_utils
SEPP_TM_EXPORT sepp_tm_utils_t *
    sepp_tm_utils_new (void);

//  Destroy the sepp_tm_utils
SEPP_TM_EXPORT void
    sepp_tm_utils_destroy (sepp_tm_utils_t **self_p);


//  @end

#ifdef __cplusplus
}
#endif

#endif
