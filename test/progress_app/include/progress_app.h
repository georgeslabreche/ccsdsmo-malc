#ifndef __PROGRESS_APP_H_INCLUDED__
#define __PROGRESS_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malzmq.h"
#include "testarea.h"
#include "malactor.h"

#define PROGRESS_APP_VERSION_MAJOR 1
#define PROGRESS_APP_VERSION_MINOR 0
#define PROGRESS_APP_VERSION_PATCH 0

#define PROGRESS_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define PROGRESS_APP_VERSION \
		PROGRESS_APP_MAKE_VERSION(PROGRESS_APP_VERSION_MAJOR, PROGRESS_APP_VERSION_MINOR, PROGRESS_APP_VERSION_PATCH)

typedef struct _progress_app_myprovider_t progress_app_myprovider_t;
typedef struct _progress_app_myconsumer_t progress_app_myconsumer_t;

void progress_app_test(bool verbose);

// Public API classes
#include "progress_app_myconsumer.h"
#include "progress_app_myprovider.h"

extern mal_actor_t *consumer_actor;
extern mal_actor_t *provider_actor;

#ifdef __cplusplus
}
#endif

#endif
