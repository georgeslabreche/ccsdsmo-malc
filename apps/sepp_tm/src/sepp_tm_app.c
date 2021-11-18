/*  =========================================================================
    sepp_tm_app - SEPP TM

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    sepp_tm_app - SEPP TM
@discuss
@end
*/

#include "sepp_tm_classes.h"

int main (int argc, char *argv [])
{
    bool verbose = false;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-h")) {
            puts ("sepp_tm_app [options] ...");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --help / -h            this information");
            return 0;
        }
        else
        if (streq (argv [argn], "--verbose")
        ||  streq (argv [argn], "-v"))
            verbose = true;
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    //  Insert main code here
    if (verbose)
        zsys_info ("sepp_tm_app - SEPP TM");
    return 0;
}
