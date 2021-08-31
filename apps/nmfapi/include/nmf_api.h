/*  =========================================================================
    nmf_api - class description

    The MIT License (MIT)
    =========================================================================
*/

#ifndef NMF_API_H_INCLUDED
#define NMF_API_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new nmf_api
NMFAPI_EXPORT nmf_api_t *
    nmf_api_new (void);

//  Destroy the nmf_api
NMFAPI_EXPORT void
    nmf_api_destroy (nmf_api_t **self_p);

//  Self test of this class
NMFAPI_EXPORT void
    nmf_api_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
