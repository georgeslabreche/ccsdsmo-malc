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

//  --------------------------------------------------------------------------
//  Parse stdout of free memory shell command

int
shell_stdout_parser_parse_free_memory (char *std_out, sepp_tm_free_memory_t *sepp_tm_free_memory)
{
    /* param values in the stdout string will by copied character by character so keep track of an offset index */
    int offset = 0;

    /* flag indicating if are procesing a param value within the stdout string */
    bool is_processing_param = false;

    /* index of the parameter being parsed */
    /* use this to determine which struct member to set */
    int param_index = 0;

    /* flag to indicate that all desired param values have been extracted from the stdout string */
    /* at wich point we can exit the char by char stdout string parsing loop */
    bool done = false;

    /* read the command's stdout string character by character and extra param values */
    for(int i = 0; i < strlen(std_out) && !done; i++)
    {
        /* extract char from the stdout string if the char is a digit */
        if(isdigit(std_out[i]))
        {
            /* set the flag to indicate that we are processing a digit char that is part of a param value */
            is_processing_param = true;

            /* set the approprtiate struct member depending on the tracked param index */
            switch(param_index)
            {
                case 0:
                    memcpy(sepp_tm_free_memory->total + offset, std_out + i, sizeof(char));
                    break;

                case 1:
                    memcpy(sepp_tm_free_memory->used + offset, std_out + i, sizeof(char));
                    break;

                case 2:
                    memcpy(sepp_tm_free_memory->free + offset, std_out + i, sizeof(char));
                    break;

                case 3:
                    memcpy(sepp_tm_free_memory->shared + offset, std_out + i, sizeof(char));
                    break;

                case 4:
                    memcpy(sepp_tm_free_memory->buffers + offset, std_out + i, sizeof(char));
                    break;

                case 5:
                    memcpy(sepp_tm_free_memory->cached + offset, std_out + i, sizeof(char));
                    break;

                case 6:
                    memcpy(sepp_tm_free_memory->used_minus_bufferscache + offset, std_out + i, sizeof(char));
                    break;

                case 7:
                    memcpy(sepp_tm_free_memory->free_plus_bufferscache + offset, std_out + i, sizeof(char));
                    break;

                default:
                    done = true;
            }
            
            /* update the offset */
            offset++;
        }
        else
        {
            /* increment the param index in preparation of the next series of digit values */
            if(is_processing_param)
            {
                param_index++;
            }

            /* reset flag and offset in preparation of the next series of digit values */
            is_processing_param = false;
            offset = 0;
        }
    }

    return 0;
}


//  --------------------------------------------------------------------------
//  Parse stdout of free cpu shell command

int
shell_stdout_parser_parse_free_cpu (char *std_out, sepp_tm_free_cpu_t *sepp_tm_free_cpu)
{
    /* param values in the stdout string will by copied character by character so keep track of an offset index */
    int offset = 0;

    /* flag indicating if are procesing a param value within the stdout string */
    bool is_processing_param = false;

    /* index of the parameter being parsed */
    /* use this to determine which struct member to set */
    int param_index = 0;

    /* flag to indicate that all desired param values have been extracted from the stdout string */
    /* at wich point we can exit the char by char stdout string parsing loop */
    bool done = false;

    /* read the command's stdout string character by character and extra param values */
    for(int i = 0; i < strlen(std_out) && !done; i++)
    {
        /* extract char from the stdout string if the char is a digit */
        if(isdigit(std_out[i]))
        {
            /* set the flag to indicate that we are processing a digit char that is part of a param value */
            is_processing_param = true;

            /* set the approprtiate struct member depending on the tracked param index */
            switch(param_index)
            {
                case 0:
                    memcpy(sepp_tm_free_cpu->usr + offset, std_out + i, sizeof(char));
                    break;

                case 1:
                    memcpy(sepp_tm_free_cpu->sys + offset, std_out + i, sizeof(char));
                    break;

                case 2:
                    memcpy(sepp_tm_free_cpu->nic + offset, std_out + i, sizeof(char));
                    break;

                case 3:
                    memcpy(sepp_tm_free_cpu->idle + offset, std_out + i, sizeof(char));
                    break;

                case 4:
                    memcpy(sepp_tm_free_cpu->io + offset, std_out + i, sizeof(char));
                    break;

                case 5:
                    memcpy(sepp_tm_free_cpu->irq + offset, std_out + i, sizeof(char));
                    break;

                case 6:
                    memcpy(sepp_tm_free_cpu->sirq + offset, std_out + i, sizeof(char));
                    break;

                default:
                    done = true;
            }
            
            /* update the offset */
            offset++;
        }
        else
        {
            /* increment the param index in preparation of the next series of digit values */
            if(is_processing_param)
            {
                param_index++;
            }

            /* reset flag and offset in preparation of the next series of digit values */
            is_processing_param = false;
            offset = 0;
        }
    }

    return 0;
}

//  --------------------------------------------------------------------------
//  Parse stdout of disk usage shell command

int
shell_stdout_parser_parse_disk_usage (char *std_out, sepp_tm_disk_usage_t *sepp_tm_disk_usage)
{
    /* param values in the stdout string will by copied character by character so keep track of an offset index */
    int offset = 0;

    /* flag indicating if are procesing a param value within the stdout string */
    bool is_processing_param = false;

    /* index of the parameter being parsed */
    /* use this to determine which struct member to set */
    int param_index = 0;

    /* flag to indicate that all desired param values have been extracted from the stdout string */
    /* at wich point we can exit the char by char stdout string parsing loop */
    bool done = false;

    /* read the command's stdout string character by character and extra param values */
    for(int i = 0; i < strlen(std_out) && !done; i++)
    {
        /* extract char from the stdout string if the char is a digit */
        /* ignore digit if it's part of the "1M-blocks" stdout substring */
        if(isdigit(std_out[i]) && std_out[i+1] != 'M')
        {
            /* set the flag to indicate that we are processing a digit char that is part of a param value */
            is_processing_param = true;

            /* set the approprtiate struct member depending on the tracked param index */
            switch(param_index)
            {
                case 0:
                    memcpy(sepp_tm_disk_usage->size + offset, std_out + i, sizeof(char));
                    break;

                case 1:
                    memcpy(sepp_tm_disk_usage->used + offset, std_out + i, sizeof(char));
                    break;

                case 2:
                    memcpy(sepp_tm_disk_usage->available + offset, std_out + i, sizeof(char));
                    break;

                case 3:
                    memcpy(sepp_tm_disk_usage->available_percentage + offset, std_out + i, sizeof(char));
                    break;

                default:
                    done = true;
            }
            
            /* update the offset */
            offset++;
        }
        else
        {
            /* increment the param index in preparation of the next series of digit values */
            if(is_processing_param)
            {
                param_index++;
            }

            /* reset flag and offset in preparation of the next series of digit values */
            is_processing_param = false;
            offset = 0;
        }
    }

    return 0;
}

//  --------------------------------------------------------------------------
//  Parse stdout of fpga image loaded command

int
shell_stdout_parser_parse_fpga_image_loaded (char *std_out, char *image_id)
{
    /* remove new line charcter from the stdout string */
    sepp_tm_utils_remove_unwanted_chars(std_out);

    /* return predefined value in case of error */
    if(strcmp(std_out, "Bus error (core dumped)") == 0)
    {
        strcpy(image_id, "0xffffffff");
    }
    else
    {
        /* copy to id */
        strcpy(image_id, std_out);
    }

    return 0;
}

//  --------------------------------------------------------------------------
//  Parse stdout of shell status command

int
shell_stdout_parser_parse_shell_status (char *std_out, char *status)
{
    /* remove new line charcter from the stdout string */
    sepp_tm_utils_remove_unwanted_chars(std_out);

    /* set number id for status */
    if(strcmp(std_out, "running") == 0)
    {
        strcpy(status, "0");
    }
    else if(strcmp(std_out, "maintenance") == 0)
    {
        strcpy(status, "1");
    }
    else if(strcmp(std_out, "degraded") == 0)
    {
        strcpy(status, "2");
    }
    else
    {
        strcpy(status, "3");
    }

    return 0;
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
shell_stdout_parser_test (bool verbose)
{
    printf(" * shell_stdout_parser:\n");


    //  --------------------------------------------------------------------------
    //  TEST: shell_stdout_parser_parse_free_memory

    printf("\tshell_stdout_parser_parse_free_memory: ");

    /* mock stdout */
    char *stdout_free_memory = \
        "             total       used       free     shared    buffers     cached\n" \
        "Mem:       1026800     198248     828552       1068       6952      71672\n" \
        "-/+ buffers/cache:     119624     907176\n" \
        "Swap:            0          0          0";

    /* free memory struct */
    struct sepp_tm_free_memory_t *sepp_tm_free_memory;
    sepp_tm_free_memory = (struct sepp_tm_free_memory_t*)malloc(sizeof(struct sepp_tm_free_memory_t));
    
    /* parse the free memory stdout and set the struct members */
    shell_stdout_parser_parse_free_memory(stdout_free_memory, sepp_tm_free_memory);
    
    /* assert that the free memory struct members have been set with the expected value */
    assert(strcmp(sepp_tm_free_memory->total, "1026800") == 0);
    assert(strcmp(sepp_tm_free_memory->used, "198248") == 0);
    assert(strcmp(sepp_tm_free_memory->free, "828552") == 0);
    assert(strcmp(sepp_tm_free_memory->shared, "1068") == 0);
    assert(strcmp(sepp_tm_free_memory->buffers, "6952") == 0);
    assert(strcmp(sepp_tm_free_memory->cached, "71672") == 0);
    assert(strcmp(sepp_tm_free_memory->used_minus_bufferscache, "119624") == 0);
    assert(strcmp(sepp_tm_free_memory->free_plus_bufferscache, "907176") == 0);

    /* test pass */
    printf("OK\n");


    //  --------------------------------------------------------------------------
    //  TEST: shell_stdout_parser_parse_free_cpu

    printf("\tshell_stdout_parser_parse_free_cpu: ");

    /* mock stdout */
    char *stdout_free_cpu = "CPU:   3\% usr   4\% sys   2\% nic  89\% idle   0\% io   0\% irq   1\% sirq";

    /* free spustruct */
    struct sepp_tm_free_cpu_t *sepp_tm_free_cpu;
    sepp_tm_free_cpu = (struct sepp_tm_free_cpu_t*)malloc(sizeof(struct sepp_tm_free_cpu_t));

    /* parse the free cpu stdout and set the struct members */
    shell_stdout_parser_parse_free_cpu(stdout_free_cpu, sepp_tm_free_cpu);

    /* assert that the free cpu struct members have been set with the expected value */
    assert(strcmp(sepp_tm_free_cpu->usr, "3") == 0);
    assert(strcmp(sepp_tm_free_cpu->sys, "4") == 0);
    assert(strcmp(sepp_tm_free_cpu->nic, "2") == 0);
    assert(strcmp(sepp_tm_free_cpu->idle, "89") == 0);
    assert(strcmp(sepp_tm_free_cpu->io, "0") == 0);
    assert(strcmp(sepp_tm_free_cpu->irq, "0") == 0);
    assert(strcmp(sepp_tm_free_cpu->sirq, "1") == 0);

    /* test pass */
    printf("OK\n");


    //  --------------------------------------------------------------------------
    //  TEST: shell_stdout_parser_parse_disk_usage

    printf("\tshell_stdout_parser_parse_disk_usage: ");

    /* mock stdout */
    char *stdout_disk_usage = \
        "Filesystem           1M-blocks      Used Available Use\% Mounted on\n" \
        "/dev/root                 3936      2300      1415  62\% /";

    /* disk usage struct */
    struct sepp_tm_disk_usage_t *sepp_tm_disk_usage;
    sepp_tm_disk_usage = (struct sepp_tm_disk_usage_t*)malloc(sizeof(struct sepp_tm_disk_usage_t));

    /* parse the disk usage stdout and set the struct members */
    shell_stdout_parser_parse_disk_usage(stdout_disk_usage, sepp_tm_disk_usage);

    /* assert that the disk_usage struct members have been set with the expected value */
    assert(strcmp(sepp_tm_disk_usage->size, "3936") == 0);
    assert(strcmp(sepp_tm_disk_usage->used, "2300") == 0);
    assert(strcmp(sepp_tm_disk_usage->available, "1415") == 0);
    assert(strcmp(sepp_tm_disk_usage->available_percentage, "62") == 0);

    /* test pass */
    printf("OK\n");


    //  --------------------------------------------------------------------------
    //  TEST: shell_stdout_parser_parse_fpga_image_loaded

    printf("\tshell_stdout_parser_parse_fpga_image_loaded: ");

    /* mock stdout */
    char *stdout_fpga_error = "Bus error (core dumped)";
    char *stdout_fpga_loaded = "0x10101010";

    /* parsed out hex id will be stored in this char array */
    char image_id[12] = {0};

    /* parse the fpga image loaded stdout and assert expected value */
    shell_stdout_parser_parse_fpga_image_loaded(stdout_fpga_error, image_id);

    assert(strcmp(image_id, "0xffffffff") == 0);

    shell_stdout_parser_parse_fpga_image_loaded(stdout_fpga_loaded, image_id);
    assert(strcmp(image_id, "0x10101010") == 0);

    /* test pass */
    printf("OK\n");


    //  --------------------------------------------------------------------------
    //  TEST: shell_stdout_parser_parse_shell_status

    printf("\tshell_stdout_parser_parse_shell_status: ");

    /* mock stdout */
    char *stdout_running = "running";
    char *stdout_maintenance = "maintenance";
    char *stdout_degraded = "degraded";
    char *stdout_other = "invalid";

    /* parsed out status will be stored in this char array */
    char status[1] = {0};
    
    /* parse the fpga image loaded stdout and assert expected value */
    shell_stdout_parser_parse_shell_status(stdout_running, status);
    assert(strcmp(status, "0") == 0);

    shell_stdout_parser_parse_shell_status(stdout_maintenance, status);
    assert(strcmp(status, "1") == 0);

    shell_stdout_parser_parse_shell_status(stdout_degraded, status);
    assert(strcmp(status, "2") == 0);

    shell_stdout_parser_parse_shell_status(stdout_other, status);
    assert(strcmp(status, "3") == 0);

    /* test pass */
    printf("OK\n");


    //  --------------------------------------------------------------------------
    //  cleanup
    
    free(sepp_tm_free_memory);
    free(sepp_tm_free_cpu);
    free(sepp_tm_disk_usage);
}
