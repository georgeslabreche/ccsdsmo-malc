/*  =========================================================================
    shell_stdout_parser - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    shell_stdout_parser -
@discuss
@end
*/

#include "sepp_tm_classes.h"

//  Structure of our class

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
shell_stdout_parser_test (bool verbose)
{
    printf (" * shell_stdout_parser: ");

    char *cpu_usage = "CPU:   1\% usr   4\% sys   0\% nic  94\% idle   0\% io   0\% irq   0\% sirq";
    // TODO: test cpu usage parsing
    
    printf ("OK\n");
}
