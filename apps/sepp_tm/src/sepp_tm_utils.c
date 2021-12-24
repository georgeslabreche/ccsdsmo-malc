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


//  --------------------------------------------------------------------------
//  Init free mem struct members

void
sepp_tm_utils_init_struct_free_memory (sepp_tm_free_memory_t *sepp_tm_free_memory)
{
    memset(sepp_tm_free_memory->total, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->used, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->free, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->shared, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->buffers, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->cached, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->used_minus_bufferscache, 0, FREE_MEMORY_ARRAY_SIZE);
    memset(sepp_tm_free_memory->free_plus_bufferscache, 0, FREE_MEMORY_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  Init free cpu struct members

void
sepp_tm_utils_init_struct_free_cpu (sepp_tm_free_cpu_t *sepp_tm_free_cpu)
{
    memset(sepp_tm_free_cpu->usr, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->sys, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->nic, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->idle, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->io, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->irq, 0, FREE_CPU_ARRAY_SIZE);
    memset(sepp_tm_free_cpu->sirq, 0, FREE_CPU_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  Init disk usage struct members

void
sepp_tm_utils_init_struct_disk_usage (sepp_tm_disk_usage_t *sepp_tm_disk_usage)
{
    memset(sepp_tm_disk_usage->size, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->used, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->available, 0, DISK_USAGE_ARRAY_SIZE);
    memset(sepp_tm_disk_usage->available_percentage, 0, DISK_USAGE_ARRAY_SIZE);
}


//  --------------------------------------------------------------------------
//  Remove unwanted chars

void
sepp_tm_utils_remove_unwanted_chars (char *str)
{
    /* remove carriage return characters if they exist */
    if(strstr(str, "\r"))
    {
        str[strcspn(str, "\r")] = 0;
    }

    /* remove new line characters if they exist */
    if(strstr(str, "\n"))
    {
        str[strcspn(str, "\n")] = 0;
    }
}

//  --------------------------------------------------------------------------
//  Get index of the nth char occurence in a given string

int
sepp_tm_utils_get_index_of_nth_char_occurence(char *str, char c, int n)
{
    int index = -1;
    int occurence = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        /* increment index as we iterate the string char by char */
        index++;

        /* check if char at current index is equad to char we are looking for */
        if(str[i] == c)
        {
            /* if it is then increment the char occurence counter */
            occurence++;

            /* check if we reached the nth occurance */
            if(occurence == n)
            {
                /* nth occurence of the c char was found */
                /* return the index of the nth occurence of the char */
                return index;
            }
        }
    }

    /* nth occurence of the c char was not found */
    return -1;
}


//  --------------------------------------------------------------------------
//  Init provider host and port

int
sepp_tm_utils_init_provider_host_and_port (char *host, char *port)
{
    /* the file stream */
    FILE *fs;

    /* the directory service uri fetched from the file */
    char uri[DIRECTORY_SERVICE_URI_MAX_CHAR] = {0};
    
    /* open the file */
    fs = fopen(DIRECTORY_SERVICE_URI_FILEPATH, "r");

    /* read file */
    fgets(uri, DIRECTORY_SERVICE_URI_MAX_CHAR, fs);

    /* close the file */
    fclose(fs);

    /* get required index to fetch host and port substrings from uri */
    int uri_index_start = sepp_tm_utils_get_index_of_nth_char_occurence(uri, '/', 2);
    int uri_index_end = sepp_tm_utils_get_index_of_nth_char_occurence(uri, ':', 2);
    int port_index_stop = sepp_tm_utils_get_index_of_nth_char_occurence(uri, '/', 3);

    /* check for errors */
    if(uri_index_start == -1 || uri_index_end == -1 || port_index_stop == -1)
    {
        return -1;
    }

    /* extract host and port from uri and set their values to their respective char array */
    memcpy(host, &uri[uri_index_start + 1], uri_index_end - uri_index_start - 1);
    memcpy(port, &uri[uri_index_end + 1], port_index_stop - uri_index_end - 1);

    /* return no error response code */
    return 0;
}