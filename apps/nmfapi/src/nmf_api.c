/*  =========================================================================
    nmf_api - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api -
@discuss
@end
*/

#include "nmfapi_classes.h"

//  Structure of our class

struct _nmf_api_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new nmf_api

nmf_api_t *
nmf_api_new (void)
{
    nmf_api_t *self = (nmf_api_t *) zmalloc (sizeof (nmf_api_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the nmf_api

void
nmf_api_destroy (nmf_api_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        nmf_api_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Self test of this class

// If your selftest reads SCMed fixture data, please keep it in
// src/selftest-ro; if your test creates filesystem objects, please
// do so under src/selftest-rw.
// The following pattern is suggested for C selftest code:
//    char *filename = NULL;
//    filename = zsys_sprintf ("%s/%s", SELFTEST_DIR_RO, "mytemplate.file");
//    assert (filename);
//    ... use the "filename" for I/O ...
//    zstr_free (&filename);
// This way the same "filename" variable can be reused for many subtests.
#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
nmf_api_test (bool verbose)
{
    printf (" * nmf_api: ");

    //  @selftest
    //  Simple create/destroy test
    nmf_api_t *self = nmf_api_new ();
    assert (self);
    nmf_api_destroy (&self);
    //  @end
    printf ("OK\n");
}
