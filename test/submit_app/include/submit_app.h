#ifndef __SUBMIT_APP_H_INCLUDED__
#define __SUBMIT_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malzmq.h"
#include "testarea.h"
#include "malactor.h"

#define SUBMIT_APP_VERSION_MAJOR 1
#define SUBMIT_APP_VERSION_MINOR 0
#define SUBMIT_APP_VERSION_PATCH 0

#define SUBMIT_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define SUBMIT_APP_VERSION \
		SUBMIT_APP_MAKE_VERSION(SUBMIT_APP_VERSION_MAJOR, SUBMIT_APP_VERSION_MINOR, SUBMIT_APP_VERSION_PATCH)

typedef struct _submit_app_myprovider_t submit_app_myprovider_t;
typedef struct _submit_app_myconsumer_t submit_app_myconsumer_t;

void submit_app_test(bool verbose);

// Public API classes
#include "submit_app_myconsumer.h"
#include "submit_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
