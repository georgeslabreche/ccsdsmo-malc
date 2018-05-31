/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 CNES
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
