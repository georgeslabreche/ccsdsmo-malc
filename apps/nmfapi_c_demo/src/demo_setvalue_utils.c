/*  =========================================================================
    demo_setvalue_utils - A utils class for the setValue demo app

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_setvalue_utils - A utils class for the setValue demo app
@discuss
@end
*/

#include "nmfapi_c_demo_classes.h"

//  Structure of our class

struct _demo_setvalue_utils_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new demo_setvalue_utils

demo_setvalue_utils_t *
demo_setvalue_utils_new (void)
{
    demo_setvalue_utils_t *self = (demo_setvalue_utils_t *) zmalloc (sizeof (demo_setvalue_utils_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the demo_setvalue_utils

void
demo_setvalue_utils_destroy (demo_setvalue_utils_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        demo_setvalue_utils_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Check for port availability

bool
demo_setvalue_utils_is_port_available(int port)
{
    int sockfd;
    struct sockaddr_in addr;

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Could not create socket");
        return false;
    }

    /* zero out address structure */
    memset(&addr, 0, sizeof(addr));

    /* set address info */
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY); /* bind to any address */
    addr.sin_port = htons(port); /* convert port number to network byte order */

    /* attempt to bind */
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        /* bind failed, port is likely in use */
        close(sockfd);
        return false;
    }

    /* bind succeeded, port is available */
    close(sockfd);
    return true;
}


//  --------------------------------------------------------------------------
//  Get index of the nth char occurence in a given string
int
demo_setvalue_utils_get_index_of_nth_char_occurence (char *str, char c, int n)
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
//  Init the provider host and port
int
demo_setvalue_utils_init_provider_host_and_port (char *host, char *port)
{
    /* the file stream */
    FILE *fs;

    /* the directory service uri fetched from the file */
    char uri[DIRECTORY_SERVICE_URI_MAX_CHAR] = {0};
    
    /* open the file */
    fs = fopen(DIRECTORY_SERVICE_URI_FILEPATH, "r");

    /* File could not be opened, return error */
    if (fs == NULL)
    {
        return -1;
    }

    /* read file */
    fgets(uri, DIRECTORY_SERVICE_URI_MAX_CHAR, fs);

    /* close the file */
    fclose(fs);

    /* get required index to fetch host and port substrings from uri */
    int uri_index_start = demo_setvalue_utils_get_index_of_nth_char_occurence(uri, '/', 2);
    int uri_index_end = demo_setvalue_utils_get_index_of_nth_char_occurence(uri, ':', 2);
    int port_index_stop = demo_setvalue_utils_get_index_of_nth_char_occurence(uri, '/', 3);

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