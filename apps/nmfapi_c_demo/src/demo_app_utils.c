/*  =========================================================================
    demo_app_utils - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_app_utils - A dummy class to workaround a bug (see comments in project.xml for details)
@discuss
@end
*/

#include "nmfapi_c_demo_classes.h"

//  Structure of our class

struct _demo_app_utils_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new demo_app_utils

demo_app_utils_t *
demo_app_utils_new (void)
{
    demo_app_utils_t *self = (demo_app_utils_t *) zmalloc (sizeof (demo_app_utils_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the demo_app_utils

void
demo_app_utils_destroy (demo_app_utils_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        demo_app_utils_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

