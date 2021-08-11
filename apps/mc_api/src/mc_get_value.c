/*  =========================================================================
    mc_get_value - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mc_get_value -
@discuss
@end
*/

#include "mc_api_classes.h"

//  Structure of our class

struct _mc_get_value_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new mc_get_value

mc_get_value_t *
mc_get_value_new (void)
{
    mc_get_value_t *self = (mc_get_value_t *) zmalloc (sizeof (mc_get_value_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the mc_get_value

void
mc_get_value_destroy (mc_get_value_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        mc_get_value_t *self = *self_p;
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
mc_get_value_test (bool verbose)
{
    printf (" * mc_get_value: ");

    //  @selftest
    //  Simple create/destroy test
    mc_get_value_t *self = mc_get_value_new ();
    assert (self);
    mc_get_value_destroy (&self);
    //  @end
    printf ("OK\n");
}
