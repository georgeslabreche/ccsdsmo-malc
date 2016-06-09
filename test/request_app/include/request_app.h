#ifndef __REQUEST_APP_H_INCLUDED__
#define __REQUEST_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"
#include "malzmq.h"
#include "maltcp.h"
#include "testarea.h"
#include "malactor.h"

#define REQUEST_APP_VERSION_MAJOR 1
#define REQUEST_APP_VERSION_MINOR 0
#define REQUEST_APP_VERSION_PATCH 0

#define REQUEST_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define REQUEST_APP_VERSION \
		REQUEST_APP_MAKE_VERSION(REQUEST_APP_VERSION_MAJOR, REQUEST_APP_VERSION_MINOR, REQUEST_APP_VERSION_PATCH)

typedef struct _request_app_myprovider_t request_app_myprovider_t;
typedef struct _request_app_myconsumer_t request_app_myconsumer_t;

void request_app_test(bool verbose);

// Public API classes
#include "request_app_myconsumer.h"
#include "request_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
