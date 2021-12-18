/*  =========================================================================
    sepp_tm_utils - a utils class

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SEPP_TM_UTILS_H_INCLUDED
#define SEPP_TM_UTILS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/* path of the file containing the directory service uri */
#define DIRECTORY_SERVICE_URI_FILEPATH          "/home/nmf/supervisor/centralDirectoryService.uri"
#define DIRECTORY_SERVICE_URI_MAX_CHAR                                                         100

//  Init free mem struct members
SEPP_TM_EXPORT void
    sepp_tm_utils_init_struct_free_memory (sepp_tm_free_memory_t *sepp_tm_free_memory);

//  Init free cpu struct members
SEPP_TM_EXPORT void
    sepp_tm_utils_init_struct_free_cpu (sepp_tm_free_cpu_t *sepp_tm_free_cpu);

//  Init disk usage struct members
SEPP_TM_EXPORT void
    sepp_tm_utils_init_struct_disk_usage (sepp_tm_disk_usage_t *sepp_tm_disk_usage);

//  Get index of the nth char occurence in a given string
SEPP_TM_EXPORT int
    sepp_tm_utils_get_index_of_nth_char_occurence (char *str, char c, int n);

//  Init the provider host and port
SEPP_TM_EXPORT int
    sepp_tm_utils_init_provider_host_and_port (char *host, char *port);


//  @end

#ifdef __cplusplus
}
#endif

#endif
