/*  =========================================================================
    mc_get_value - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef MC_GET_VALUE_H_INCLUDED
#define MC_GET_VALUE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new mc_get_value
MC_API_EXPORT mc_get_value_t *
    mc_get_value_new (void);

//  Destroy the mc_get_value
MC_API_EXPORT void
    mc_get_value_destroy (mc_get_value_t **self_p);

//  Self test of this class
MC_API_EXPORT void
    mc_get_value_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
