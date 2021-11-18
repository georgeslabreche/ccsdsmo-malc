/*  =========================================================================
    shell_proxy - class description

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    shell_proxy -
@discuss
@end
*/

#include "sepp_tm_classes.h"

//  Structure of our class

struct _shell_proxy_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new shell_proxy

shell_proxy_t *
shell_proxy_new (void)
{
    shell_proxy_t *self = (shell_proxy_t *) zmalloc (sizeof (shell_proxy_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the shell_proxy

void
shell_proxy_destroy (shell_proxy_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        shell_proxy_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Get Linux uptime in seconds

int
shell_proxy_get_uptime (shell_proxy_t *self_p, char *stdout)
{
    /* file pointer */
    FILE *fp;

    /* command contains the command string (a character array) */
    char *command = "awk '{print int($1)}' /proc/uptime";

    /* use popen to read output from command */
    fp = popen(command, "r");

    /* error check */
    if (!fp)
    {
        return -1;
    }

    /* read stdout line into char buffer */
    fgets(stdout, sizeof(stdout), fp);

    /* error check */
    if (feof(fp) || ferror(fp))
    {
        return -1;
    }

    /* remove carriage return and new line, if any */
    stdout[strcspn(stdout, "\r\n")] = 0;
    
    /* cleanup */
    fclose(fp);

    /* success */
    return 0;
}

