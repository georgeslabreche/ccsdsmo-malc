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

/* */
#include "malactor.h"

struct _mal_actor_t {
  zsock_t *pipe;
  mal_endpoint_t *actor_endpoint;

  mal_poller_t *poller;
  mal_endpoint_t *endpoint;
  mal_routing_t *router;

  mal_actor_initialize_fn *initialize;
  mal_actor_finalize_fn *finalize;

  void *actor;

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

void mal_actor_destroy(mal_ctx_t *mal_ctx, mal_actor_t **self_p) {
  if (*self_p) {
    mal_actor_t *self = *self_p;

    zactor_destroy((zactor_t **) &self->actor);

    mal_poller_destroy(&self->poller);
    mal_endpoint_destroy(&self->endpoint);
    mal_routing_destroy(&self->router);
    mal_endpoint_destroy(&self->actor_endpoint);

    free(self);
    *self_p = NULL;
  }
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
  mal_actor_t *actor_data = (mal_actor_t *) args;

    clog_debug(mal_logger, "mal_actor_run()\n");

  actor_data->pipe = pipe;
  actor_data->actor_endpoint = mal_actor_endpoint_create(mal_actor_get_mal_ctx(actor_data), pipe);
  mal_poller_add_endpoint(actor_data->poller, actor_data->actor_endpoint);

  //  Signal successful initialization
  zsock_signal(pipe, 0);

  if (actor_data && actor_data->initialize) {
    clog_debug(mal_logger, "mal_actor_run: initialize..\n");
    actor_data->initialize(mal_routing_get_state(actor_data->router), actor_data);
  }

  while (!actor_data->terminated) {

    clog_debug(mal_logger, "mal_actor_run: mal_poller_wait...\n");

    mal_endpoint_t *which;
    rc = mal_poller_wait(actor_data->poller, &which, -1);
    if (rc) {
      clog_fatal(mal_logger, "mal_actor_run: poller returns error %d\n", rc);
      break;
    }

    if (which) {
      clog_debug(mal_logger, "mal_actor_run: mal_poller_wait, receives on %s\n", mal_endpoint_get_uri(which));

      if (which == actor_data->actor_endpoint) {
        clog_debug(mal_logger, "mal_actor_run: actor_endpoint activated...\n");
        mal_actor_handle_pipe(actor_data);
        //    } else if (zpoller_terminated(actor_data->poller)) {
        //
        //      if (actor_data->verbose)
        //        clog_debug(mal_logger, "mal_actor_run: zpoller_terminated.\n");
        //
        //      break;          //  Interrupted
      } else {
        clog_debug(mal_logger, "mal_actor_run: receiving message...\n");

        bool message_delivered = false;
        mal_message_t *mal_message = NULL;
        rc = mal_endpoint_recv_message(actor_data->endpoint, &mal_message);

        if ((rc == 0) && mal_message) {
          if (mal_routing_handle(actor_data->router, mal_message) == 0)
            message_delivered = true;
        }

        clog_debug(mal_logger, "mal_actor_run: message_delivered=%d\n", message_delivered);

        if (!message_delivered) {
          clog_warning(mal_logger, "mal_actor_run: destroy undelivered MAL message\n");

          mal_message_destroy(&mal_message, mal_endpoint_get_mal_ctx(actor_data->endpoint));
        }
      }
    } else {
      clog_error(mal_logger, "mal_actor_run: poller returns null end-point\n");
    }
  }

  if (actor_data && actor_data->finalize) {
    clog_debug(mal_logger, "mal_actor_run: finalize..\n");

    actor_data->finalize(mal_routing_get_state(actor_data->router), actor_data);
  }

  // destroy the actor resources
  mal_poller_destroy(&actor_data->poller);
  mal_endpoint_destroy(&actor_data->endpoint);
  mal_routing_destroy(&actor_data->router);
  mal_endpoint_destroy(&actor_data->actor_endpoint);

	// Try to self-destroy in order to better clean ZMQ resources.
  clog_debug(mal_logger, "mal_actor_run: end.\n");
  zactor_destroy((zactor_t **) &actor_data->actor);
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
