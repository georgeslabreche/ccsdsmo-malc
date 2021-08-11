/*  =========================================================================
    mc_set_value - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef MC_SET_VALUE_H_INCLUDED
#define MC_SET_VALUE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new mc_set_value
MC_API_EXPORT mc_set_value_t *
    mc_set_value_new (void);

//  Destroy the mc_set_value
MC_API_EXPORT void
    mc_set_value_destroy (mc_set_value_t **self_p);

//  Self test of this class
MC_API_EXPORT void
    mc_set_value_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
