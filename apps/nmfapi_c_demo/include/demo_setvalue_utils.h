/*  =========================================================================
    demo_setvalue_utils - A utils class for the setValue demo app

    The MIT License (MIT)
    =========================================================================
*/

#ifndef DEMO_SETVALUE_UTILS_H_INCLUDED
#define DEMO_SETVALUE_UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For close function
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifdef __cplusplus
extern "C" {
#endif

/* path of the file containing the directory service uri */
#define DIRECTORY_SERVICE_URI_FILEPATH          "/home/nmf/supervisor/centralDirectoryService.uri"
#define DIRECTORY_SERVICE_URI_MAX_CHAR                                                         100


//  @interface
//  Create a new demo_setvalue_utils
NMFAPI_C_DEMO_EXPORT demo_setvalue_utils_t *
    demo_setvalue_utils_new (void);

//  Destroy the demo_setvalue_utils
NMFAPI_C_DEMO_EXPORT void
    demo_setvalue_utils_destroy (demo_setvalue_utils_t **self_p);

// Check if port is available
NMFAPI_C_DEMO_EXPORT bool
    demo_setvalue_utils_is_port_available(int port);

//  Get index of the nth char occurence in a given string
NMFAPI_C_DEMO_EXPORT int
    demo_setvalue_utils_get_index_of_nth_char_occurence (char *str, char c, int n);

//  Init the provider host and port
NMFAPI_C_DEMO_EXPORT int
    demo_setvalue_utils_init_provider_host_and_port (char *host, char *port);

//  @end

#ifdef __cplusplus
}
#endif

#endif
