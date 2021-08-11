/*  =========================================================================
    monitor_and_control - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    monitor_and_control -
@discuss
@end
*/

#include "nmf_api_classes.h"

//  Structure of our class

struct _monitor_and_control_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new monitor_and_control

monitor_and_control_t *
monitor_and_control_new (void)
{
    monitor_and_control_t *self = (monitor_and_control_t *) zmalloc (sizeof (monitor_and_control_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the monitor_and_control

void
monitor_and_control_destroy (monitor_and_control_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        monitor_and_control_t *self = *self_p;
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
monitor_and_control_test (bool verbose)
{
    printf (" * monitor_and_control: ");

    //  @selftest
    //  Simple create/destroy test
    monitor_and_control_t *self = monitor_and_control_new ();
    assert (self);
    monitor_and_control_destroy (&self);
    //  @end
    printf ("OK\n");
}
