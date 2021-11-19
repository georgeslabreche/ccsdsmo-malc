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

/* remove carriage return and new line, if any */
//std_out[strcspn(std_out, "\r\n")] = 0;


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

int
shell_proxy_execute_command (char *command, char *std_out)
{
    /* file pointer */
    FILE *fp;

    /* use popen to read output from command */
    fp = popen(command, "r");

    /* error check */
    if (!fp)
    {
        return -1;
    }

    /* read stdout line into char buffer */
    char line[128];
    int offset = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        strcpy(std_out + offset, line);
        offset = offset + strlen(line);
    }

    /* error check */
    if (ferror(fp))
    {
        fclose(fp);
        return -1;
    }

    /* cleanup */
    fclose(fp);

    /* success */
    return 0;
}


//  --------------------------------------------------------------------------
//  Get Linux uptime in seconds

int
shell_proxy_get_uptime (shell_proxy_t *self_p, char *std_out)
{
    /* response code */
    int res;
    
    /* execute command */
    res = shell_proxy_execute_command("awk '{print int($1)}' /proc/uptime", std_out);

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get free memory

int
shell_proxy_get_free_memory (shell_proxy_t *self_p, char *std_out)
{
    /* response code */
    int res;
    
    /* execute command */
    res = shell_proxy_execute_command("free", std_out);

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get free CPU

int
shell_proxy_get_free_cpu (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}

//  --------------------------------------------------------------------------
//  Get disk usage

int
shell_proxy_get_disk_usage (shell_proxy_t *self_p, char *std_out)
{
    /* response code */
    int res;
    
    /* execute command */
    res = shell_proxy_execute_command("df -m | head -n2", std_out);

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
//  Get OOM counter

int
shell_proxy_get_oom_counter (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}

//  --------------------------------------------------------------------------
//  Get file count toGround

int
shell_proxy_get_file_count_toGround (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}

//  --------------------------------------------------------------------------
//  Get file count toGroundLP

int
shell_proxy_get_file_count_toGroundLP (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}

//  --------------------------------------------------------------------------
// Get FPGA image loaded

int
shell_proxy_get_fpga_image_loaded (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}

//  --------------------------------------------------------------------------
// Get core counter

int
shell_proxy_get_core_counter (shell_proxy_t *self_p, char *std_out)
{
    /* response code */
    int res;
    
    /* execute command */
    res = shell_proxy_execute_command("cat /proc/cpuinfo | grep processor | wc -l", std_out);

    /* return response code */
    return res;
}

//  --------------------------------------------------------------------------
// Get rescue shell status

int
shell_proxy_get_rescue_shell_status (shell_proxy_t *self_p, char *std_out)
{
    return 0;
}