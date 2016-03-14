#ifndef __INVOKE_APP_H_INCLUDED__
#define __INVOKE_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malzmq.h"
#include "testarea.h"
#include "malactor.h"

#define INVOKE_APP_VERSION_MAJOR 1
#define INVOKE_APP_VERSION_MINOR 0
#define INVOKE_APP_VERSION_PATCH 0

#define INVOKE_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define INVOKE_APP_VERSION \
		INVOKE_APP_MAKE_VERSION(INVOKE_APP_VERSION_MAJOR, INVOKE_APP_VERSION_MINOR, INVOKE_APP_VERSION_PATCH)

typedef struct _invoke_app_myprovider_t invoke_app_myprovider_t;
typedef struct _invoke_app_myconsumer_t invoke_app_myconsumer_t;

void invoke_app_test(bool verbose);

// Public API classes
#include "invoke_app_myconsumer.h"
#include "invoke_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
