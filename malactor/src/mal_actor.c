/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2018 CNES
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

/* */
#include "malactor.h"

static int active_count = 0;

int mal_actor_active_count() {
  return active_count;
}

struct _mal_actor_t {
  zsock_t *pipe;
  mal_endpoint_t *actor_endpoint;

  mal_poller_t *poller;
  mal_endpoint_t *endpoint;
  mal_routing_t *router;

  mal_actor_initialize_fn *initialize;
  mal_actor_finalize_fn *finalize;

  void *actor;

  bool running;
  bool terminated;            //  Did caller ask us to quit?
};

static void mal_actor_run(zsock_t *pipe, void *args);

// BE CAREFUL: This structure should be identical to the malzmq_endpoint_data_t
// structure defined in malzmq_ctx.c
typedef struct {
  void *malzmq_ctx;
  mal_endpoint_t *mal_endpoint;
  void *socket;
  void *padding;
} actor_endpoint_data_t;

mal_endpoint_t *mal_actor_endpoint_create(
    mal_ctx_t *mal_ctx,
    zsock_t *pipe) {
  actor_endpoint_data_t *actor_endpoint_data = (actor_endpoint_data_t *) malloc(sizeof(actor_endpoint_data_t));
  actor_endpoint_data->malzmq_ctx = mal_ctx_get_binding(mal_ctx);
  actor_endpoint_data->socket = pipe;
  actor_endpoint_data->padding = NULL;

  mal_endpoint_t *actor_endpoint = mal_endpoint_actor(mal_ctx, actor_endpoint_data);

  actor_endpoint_data->mal_endpoint = actor_endpoint;

  return actor_endpoint;
}

mal_actor_t *mal_actor_new(
    mal_ctx_t *mal_ctx,
    mal_uri_t *uri,
    void *state,
    mal_actor_initialize_fn *initialize,
    mal_actor_finalize_fn *finalize) {
  mal_actor_t *self = (mal_actor_t *) malloc(sizeof(mal_actor_t));
  if (!self)
    return NULL;

  self->poller = mal_poller_new(mal_ctx);
  self->endpoint = mal_endpoint_new(mal_ctx, uri);
  mal_poller_add_endpoint(self->poller, self->endpoint);
  self->router = mal_routing_new(self->endpoint, state);
  self->initialize = initialize;
  self->finalize = finalize;
  self->running = false;
  self->terminated = false;

  self->actor = zactor_new(mal_actor_run, self);

  return self;
}

//void *malzmq_ctx_create_actor(void *malzmq_ctx, mal_actor_t *mal_actor) {
//  malzmq_ctx_t *self = (malzmq_ctx_t *) malzmq_ctx;
//
//  if (self->verbose)
//    clog_debug(mal_logger, "malzmq_ctx_create_actor()\n");
//
//  malzmq_actor_data_t *actor_data = (malzmq_actor_data_t *) zmalloc(sizeof(malzmq_actor_data_t));
//  assert(actor_data);
//
//  //  ... initialize your own state including any other
//  //  sockets, which you can add to the poller:
//  actor_data->mal_ctx = self->mal_ctx;
//  actor_data->malzmq_ctx = self;
//  actor_data->mal_actor = mal_actor;
//  actor_data->remote_socket_table = zhash_new();
//  actor_data->verbose = self->verbose;
//  actor_data->terminated = false;
//
//  mal_actor_set_actor_data(mal_actor, actor_data);
//
//  zactor_t *zactor = zactor_new(mal_actor_run, actor_data);
//
//  return zactor;
//}

void mal_actor_term(mal_actor_t *actor) {
  mal_actor_send_command(actor, "$TERM");
}

void mal_actor_destroy(mal_ctx_t *mal_ctx, mal_actor_t **self_p) {
  clog_debug(mal_logger, "mal_actor_destroy..\n");
  if (self_p && *self_p) {
    mal_actor_t *self = *self_p;

    mal_poller_destroy(&self->poller);
    mal_endpoint_destroy(&self->endpoint);
    mal_routing_destroy(&self->router);
// Note: The internal endoint is destroyed during the actor termination.
//    mal_endpoint_destroy(&self->actor_endpoint);

    zactor_destroy((zactor_t **) &self->actor);
    
    clog_debug(mal_logger, "mal_actor_destroy..destroyed\n");

    free(self);
    *self_p = NULL;
  }
}

void *mal_actor_get_state(mal_actor_t *self) {
  return mal_routing_get_state(self->router);
}

mal_ctx_t *mal_actor_get_mal_ctx(mal_actor_t *self) {
  return mal_endpoint_get_mal_ctx(self->endpoint);
}

mal_endpoint_t *mal_actor_get_mal_endpoint(mal_actor_t *self) {
  return self->endpoint;
}

mal_routing_t *mal_actor_get_router(mal_actor_t *self) {
  return self->router;
}

mal_uri_t *mal_actor_get_uri(mal_actor_t *self) {
  return mal_endpoint_get_uri(self->endpoint);
}

int mal_actor_send_command(mal_actor_t *to, char *cmd) {
  clog_debug(mal_logger, "mal_actor_send_command: [%p] %s\n", (void *) to, cmd);

  zstr_sendx (to->actor, cmd, NULL);
  return 0;
}

//  --------------------------------------------------------------------------
//  Handle a command from calling application
static int mal_actor_handle_pipe(mal_actor_t *self) {
    clog_debug(mal_logger, "mal_actor_handle_pipe\n");

  //  Get the whole message off the pipe in one go
  zmsg_t *request = zmsg_recv(self->pipe);
  if (!request)
    return -1;                  //  Interrupted

  char *command = zmsg_popstr(request);

  clog_debug(mal_logger, "mal_actor_handle_pipe: API command=\"%s\"\n", command);
  if (strncmp(command, "ECHO", 4) == 0) {
    clog_debug(mal_logger, "mal_actor_handle_pipe: %s\n", command);
  } else if (streq(command, "WAIT")) {
    //  An example of a command that the caller would wait for
    //  via a signal, so that the two threads synchronize
    zsock_signal(self->pipe, 0);
  } else if (streq(command, "$TERM")) {
    clog_debug(mal_logger, "mal_actor_handle_pipe: received $TERM\n");
    self->terminated = true;
  } else {
    clog_debug(mal_logger, "mal_actor_handle_pipe: invalid command: %s", command);
    assert(false);
  }

  zstr_free(&command);
  zmsg_destroy(&request);

  return 0;
}

static void mal_actor_run(zsock_t *pipe, void *args) {
  int rc = 0;
  mal_actor_t *self = (mal_actor_t *) args;

  clog_debug(mal_logger, "mal_actor_run()\n");

  self->pipe = pipe;
  self->actor_endpoint = mal_actor_endpoint_create(mal_actor_get_mal_ctx(self), pipe);
  mal_poller_add_endpoint(self->poller, self->actor_endpoint);

  //  Signal successful initialization
  zsock_signal(pipe, 0);

  self->running = true;
  active_count += 1;
  if (self && self->initialize) {
    clog_debug(mal_logger, "mal_actor_run: initialize..\n");
    self->initialize(mal_routing_get_state(self->router), self);
  }

  while (!self->terminated) {

    clog_debug(mal_logger, "mal_actor_run: mal_poller_wait...\n");

    mal_endpoint_t *which;
    rc = mal_poller_wait(self->poller, &which, -1);
    if (rc) {
      clog_fatal(mal_logger, "mal_actor_run: poller returns error %d\n", rc);
      break;
    }

    if (which) {
      clog_debug(mal_logger, "mal_actor_run: mal_poller_wait, receives on %s\n", mal_endpoint_get_uri(which));

      if (which == self->actor_endpoint) {
        clog_debug(mal_logger, "mal_actor_run: actor_endpoint activated...\n");
        mal_actor_handle_pipe(self);
        //    } else if (zpoller_terminated(actor_data->poller)) {
        //
        //      if (actor_data->verbose)
        //        clog_debug(mal_logger, "mal_actor_run: zpoller_terminated.\n");
        //
        //      break;          //  Interrupted
      } else {
        clog_debug(mal_logger, "mal_actor_run: receiving message...\n");

        mal_message_t *mal_message = NULL;
        rc = mal_endpoint_recv_message(self->endpoint, &mal_message);

        if ((rc == 0) && mal_message) {
          int ret = mal_routing_handle(self->router, mal_message);
          if ((ret != MAL_ROUTING_NO_HANDLER) && (ret != MAL_ROUTING_BAD_IP_STAGE) && (ret != MAL_ROUTING_UNKNOW_INTERACTION_TYPE)) {
            clog_debug(mal_logger, "mal_actor_run: message_delivered with success\n");
          } else {
            clog_warning(mal_logger, "mal_actor_run: destroy undelivered MAL message\n");
            mal_message_destroy(&mal_message, mal_endpoint_get_mal_ctx(self->endpoint));
          }
        }
      }
    } else {
      clog_error(mal_logger, "mal_actor_run: poller returns null end-point\n");
    }
  }

  if (self && self->finalize) {
    clog_debug(mal_logger, "mal_actor_run: finalize..\n");

    self->finalize(mal_routing_get_state(self->router), self);
  }

	// destroy the actor's internal endpoint
  mal_endpoint_destroy(&self->actor_endpoint);

  self->running = false;
  active_count -= 1;

  clog_debug(mal_logger, "mal_actor_run: end.\n");
}

bool mal_actor_alive(mal_actor_t *self) {
  return self->running;
}

void mal_actor_join(mal_actor_t *self) {
  while (self->running) {
    zclock_sleep(100);
  }
}

void mal_actor_test(bool verbose) {
  printf(" * mal_actor: ");
  if (verbose)
    printf("\n");

  //  @selftest
  // ...
  //  @end
  printf("OK\n");
}
