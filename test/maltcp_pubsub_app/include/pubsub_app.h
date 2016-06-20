#ifndef __PUBSUB_APP_H_INCLUDED__
#define __PUBSUB_APP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malbinary.h"
#include "maltcp.h"
#include "testarea.h"
#include "malactor.h"

#define PUBSUB_APP_VERSION_MAJOR 1
#define PUBSUB_APP_VERSION_MINOR 0
#define PUBSUB_APP_VERSION_PATCH 0

#define PUBSUB_APP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define PUBSUB_APP_VERSION \
    PUBSUB_APP_MAKE_VERSION(PUBSUB_APP_VERSION_MAJOR, PUBSUB_APP_VERSION_MINOR, PUBSUB_APP_VERSION_PATCH)

typedef struct _pubsub_app_mypublisher_t pubsub_app_mypublisher_t;
typedef struct _pubsub_app_mysubscriber_t pubsub_app_mysubscriber_t;
typedef struct _pubsub_app_broker_t pubsub_app_broker_t;
typedef struct _pubsub_subscriber_t pubsub_subscriber_t;

void pubsub_app_test(bool verbose);

// Public API classes
#include "pubsub_app_mysubscriber.h"
#include "pubsub_app_mypublisher.h"
#include "pubsub_app_broker.h"

extern mal_actor_t *consumer_actor;
extern mal_actor_t *provider_actor;
extern mal_actor_t *broker_actor;

#ifdef __cplusplus
}
#endif

#endif
