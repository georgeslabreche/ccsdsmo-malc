/*  =========================================================================
    file_encoding - class description

    The MIT License (MIT)
    Copyright (c) 2016 CNES
    =========================================================================
*/

#ifndef FILE_ENCODING_H_INCLUDED
#define FILE_ENCODING_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new file_encoding
ENCODING_EXPORT file_encoding_t *
    file_encoding_new (void);

//  Destroy the file_encoding
ENCODING_EXPORT void
    file_encoding_destroy (file_encoding_t **self_p);

//  Self test of this class
ENCODING_EXPORT void
    file_encoding_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
