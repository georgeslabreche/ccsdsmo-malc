#ifndef __SIMPLE_APP_H_INCLUDED__
#define __SIMPLE_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malzmq.h"
#include "testarea.h"

#define SIMPLE_APP_VERSION_MAJOR 1
#define SIMPLE_APP_VERSION_MINOR 0
#define SIMPLE_APP_VERSION_PATCH 0

#define SIMPLE_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define SIMPLE_APP_VERSION \
    SIMPLE_APP_MAKE_VERSION(SIMPLE_APP_VERSION_MAJOR, SIMPLE_APP_VERSION_MINOR, SIMPLE_APP_VERSION_PATCH)

typedef struct _simple_app_myprovider_t simple_app_myprovider_t;
typedef struct _simple_app_myconsumer_t simple_app_myconsumer_t;

void simple_app_test(bool verbose);

// Public API classes
#include "simple_app_myconsumer.h"
#include "simple_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
