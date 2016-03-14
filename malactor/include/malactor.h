/*
 */

#ifndef MALACTOR_INCLUDE_MALACTOR_H_
#define MALACTOR_INCLUDE_MALACTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mal.h"
#include "malzmq.h"

//  MAL/ACTOR API version macros for compile-time API detection

#define MALACTOR_VERSION_MAJOR 1
#define MALACTOR_VERSION_MINOR 0
#define MALACTOR_VERSION_PATCH 0

#define MALACTOR_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MALACTOR_VERSION \
    MALACTOR_MAKE_VERSION(MALACTOR_VERSION_MAJOR, MALACTOR_VERSION_MINOR, MALACTOR_VERSION_PATCH)

typedef struct _mal_actor_t mal_actor_t;

void malactor_test(bool verbose);

//  Public API classes
#include "mal_actor.h"

#ifdef __cplusplus
}
#endif

#endif /* MALACTOR_INCLUDE_MALACTOR_H_ */
