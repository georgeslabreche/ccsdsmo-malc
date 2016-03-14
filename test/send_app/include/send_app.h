#ifndef __SEND_APP_H_INCLUDED__
#define __SEND_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "malzmq.h"
#include "testarea.h"
#include "malactor.h"

#define SEND_APP_VERSION_MAJOR 1
#define SEND_APP_VERSION_MINOR 0
#define SEND_APP_VERSION_PATCH 0

#define SEND_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define SEND_APP_VERSION \
    SEND_APP_MAKE_VERSION(SEND_APP_VERSION_MAJOR, SEND_APP_VERSION_MINOR, SEND_APP_VERSION_PATCH)

typedef struct _send_app_myprovider_t send_app_myprovider_t;
typedef struct _send_app_myconsumer_t send_app_myconsumer_t;

void send_app_test(bool verbose);

// Public API classes
#include "../../send_app/include/send_app_myconsumer.h"
#include "../../send_app/include/send_app_myprovider.h"

#ifdef __cplusplus
}
#endif

#endif
