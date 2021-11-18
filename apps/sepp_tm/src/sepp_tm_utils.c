/*  =========================================================================
    sepp_tm_utils - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sepp_tm_utils -
@discuss
@end
*/

#include "sepp_tm_classes.h"

//  Structure of our class

struct _sepp_tm_utils_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new sepp_tm_utils

sepp_tm_utils_t *
sepp_tm_utils_new (void)
{
    sepp_tm_utils_t *self = (sepp_tm_utils_t *) zmalloc (sizeof (sepp_tm_utils_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the sepp_tm_utils

void
sepp_tm_utils_destroy (sepp_tm_utils_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        sepp_tm_utils_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

