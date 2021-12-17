/*  =========================================================================
    sepp_tm_types - structs to contain fetched values

    The MIT License (MIT)
    =========================================================================
*/

#ifndef SEPP_TM_TYPES_H_INCLUDED
#define SEPP_TM_TYPES_H_INCLUDED

#define FREE_MEMORY_ARRAY_SIZE                  10
#define FREE_CPU_ARRAY_SIZE                      4
#define DISK_USAGE_ARRAY_SIZE                    8

/* struct to store values parsed out of the free memory command stdout */
struct sepp_tm_free_memory_t
{
    char total[FREE_MEMORY_ARRAY_SIZE];
    char used[FREE_MEMORY_ARRAY_SIZE];
    char free[FREE_MEMORY_ARRAY_SIZE];
    char shared[FREE_MEMORY_ARRAY_SIZE];
    char buffers[FREE_MEMORY_ARRAY_SIZE];
    char cached[FREE_MEMORY_ARRAY_SIZE];
    char used_minus_bufferscache[FREE_MEMORY_ARRAY_SIZE];
    char free_plus_bufferscache[FREE_MEMORY_ARRAY_SIZE];
};
typedef struct sepp_tm_free_memory_t sepp_tm_free_memory_t;

/* struct to store values parsed out of the free cpu command stdout */
struct sepp_tm_free_cpu_t
{
    char usr[FREE_CPU_ARRAY_SIZE];
    char sys[FREE_CPU_ARRAY_SIZE];
    char nic[FREE_CPU_ARRAY_SIZE];
    char idle[FREE_CPU_ARRAY_SIZE];
    char io[FREE_CPU_ARRAY_SIZE];
    char irq[FREE_CPU_ARRAY_SIZE];
    char sirq[FREE_CPU_ARRAY_SIZE];
};
typedef struct sepp_tm_free_cpu_t sepp_tm_free_cpu_t;

/* struct to store values parsed out of the disk usage command stdout */
struct sepp_tm_disk_usage_t
{
    char size[DISK_USAGE_ARRAY_SIZE];
    char used[DISK_USAGE_ARRAY_SIZE];
    char available[DISK_USAGE_ARRAY_SIZE];
    char available_percentage[DISK_USAGE_ARRAY_SIZE];
};
typedef struct sepp_tm_disk_usage_t sepp_tm_disk_usage_t;

#endif