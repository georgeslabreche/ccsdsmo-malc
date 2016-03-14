#include "../include/my_zactor.h"
#include "../include/my_zloop.h"

void s_actor_ctx_destroy(actor_ctx_t **actor_ctx_p) {
  printf("=>s_actor_ctx_destroy\n");
  assert(actor_ctx_p);
  if (*actor_ctx_p) {
    actor_ctx_t *actor_ctx = *actor_ctx_p;
    //  ... destroy your own state here
    zsock_destroy (&actor_ctx->inproc);
    zsock_destroy (&actor_ctx->pipe);
    free(actor_ctx);
    *actor_ctx_p = NULL;
  }
  printf("<=s_actor_ctx_destroy\n");
}

void zactor_run(zsock_t *pipe, void *args) {
  printf("=>zactor_run\n");
  actor_ctx_t *actor_ctx = (actor_ctx_t *) args;
  actor_ctx->pipe = pipe;
  // create the poller for the pipe
  actor_ctx->poller = zpoller_new (actor_ctx->pipe, NULL);
  assert(actor_ctx->poller);
  // add the socket inproc to the poller
  int ret = zpoller_add(actor_ctx->poller, actor_ctx->inproc);
  assert(ret == 0);
  printf("zactor_run: poller OK.\n");

  // Signal successful initialization
  zsock_signal(actor_ctx->pipe, 0);

  while (!actor_ctx->terminated) {
    printf("zactor_run: while...\n");
    zsock_t *which = (zsock_t *) zpoller_wait (actor_ctx->poller, -1);
    assert(which);
    //printf("zactor_run: which = %p\n", (void *)which);
    //printf("zactor_run: pipe = %p\n", (void *)actor_ctx->pipe);
    //printf("zactor_run: inproc = %p\n",(void *)actor_ctx->inproc);
    if (which == actor_ctx->pipe)
      zactor_handle_pipe (actor_ctx);
    else if (which == actor_ctx->inproc)
      zactor_handle_socket (actor_ctx);
    else {
      if (zpoller_terminated (actor_ctx->poller))
        break; //  Interrupted
      actor_ctx->terminated = true;//NTA tmp
    }
  }

  s_actor_ctx_destroy(&actor_ctx);
  printf("<=zactor_run\n");
}

void zactor_handle_pipe (actor_ctx_t *actor_ctx) {
  printf("=>zactor_handle_pipe\n");
  // Get the whole message off the pipe in one go
  zmsg_t *request = zmsg_recv(actor_ctx->pipe);
  zmsg_dump(request);

  if (!request) {
    printf("zactor_handle_pipe request = NULL. Interrupt! \n");
    return;  //  Interrupted
  }

  char *message = zmsg_popstr(request);
  printf("zactor_handle_pipe: request msg = %s\n", message);
  zstr_free(&message);
  //actor_ctx->handle(request, NULL);

  zmsg_destroy(&request);
  printf("<=zactor_handle_pipe\n");
}

void zactor_handle_socket (actor_ctx_t *actor_ctx) {
  printf("=>zactor_handle_socket %s\n", actor_ctx->name);

  zmsg_t *msg = zmsg_recv(actor_ctx->inproc);
  zmsg_dump(msg);

  zframe_t *identity = zmsg_pop(msg);
  zframe_t *content = zmsg_pop(msg);
  assert(content);

  char *string = zframe_strdup(content);
  printf("msg = %s\n", string);

  // for test
  write_pipe(actor_ctx->zactor, "TEST PIPE DATA...");

  if (actor_ctx->zloop_reply == NULL) {
    init_zloop_reply(actor_ctx);
  }
  ack(actor_ctx->zloop_reply, identity, content);

  zmsg_destroy(&msg);
  zframe_destroy(&identity);
  zframe_destroy(&content);

  printf("<=zactor_handle_socket %s\n", actor_ctx->name);
}

void init_zloop_reply(actor_ctx_t *actor_ctx) {
  printf("=>init_zloop_reply\n");
  zctx_t *ctx = zctx_new();
  actor_ctx->zloop_reply = (zsock_t *) zsocket_new(ctx, actor_ctx->zloop_reply_type);
  zsocket_set_identity(actor_ctx->zloop_reply, actor_ctx->name);
  zsocket_connect(actor_ctx->zloop_reply, actor_ctx->zloop_reply_url);
  assert(actor_ctx->zloop_reply);
  printf("<=init_zloop_reply\n");
}

void ack(zsock_t *socket, zframe_t *identity, zframe_t *content) {
  printf("=>ack()\n");
  zframe_t * cmd = zframe_new(ZLOOP_REPLY, strlen(ZLOOP_REPLY));
  zframe_send(&cmd, socket, ZFRAME_MORE + ZFRAME_REUSE);
  zframe_send(&identity, socket, ZFRAME_REUSE + ZFRAME_MORE);
  zframe_send(&content, socket, ZFRAME_REUSE);
  printf("<=ack()\n");
}

void write_pipe(zactor_t *zactor, char *data) {
  printf("=>write_pipe : data = %s\n", data);
  zstr_sendx(zactor, data, NULL);
  printf("<=write_pipe\n");
}

void add_actor_to_zloop(actor_ctx_t *actor_ctx) {
  printf("=>add_actor_to_zloop %s\n", actor_ctx->name);
  if (actor_ctx->zloop_reply == NULL) {
    init_zloop_reply(actor_ctx);
  }
  zframe_t * cmd = zframe_new(ZLOOP_ADD_ACTOR, strlen(ZLOOP_ADD_ACTOR));
  zframe_t * actor_url = zframe_new(actor_ctx->pull_inproc_url, strlen(actor_ctx->pull_inproc_url));
  zframe_send(&cmd, actor_ctx->zloop_reply, ZFRAME_MORE + ZFRAME_REUSE);
  zframe_send(&actor_url, actor_ctx->zloop_reply, ZFRAME_REUSE);
  printf("<=add_actor_to_zloop %s\n", actor_ctx->name);
}

// Creates a new actor
void *my_zactor_new() {
  printf("=>my_zactor_new\n");
  actor_ctx_t *actor_ctx = (actor_ctx_t *) zmalloc(sizeof(actor_ctx_t));
  assert(actor_ctx);

  actor_ctx->name = "zactor.A";
  actor_ctx->pull_inproc_url = "inproc://zactor.A";
  actor_ctx->zloop_reply_url = "tcp://localhost:5557";
  actor_ctx->zloop_reply_type = ZMQ_DEALER;

  zactor_t *my_zactor = (zactor_t *) my_zactor_ctx_new(actor_ctx);

  printf("<=my_zactor_new\n");
  return my_zactor;
}

// Creates a new actor
void *my_zactor_ctx_new(void *args) {
  printf("=>my_zactor_new %p\n", (void *) args);

  assert(args);
  actor_ctx_t *actor_ctx = (actor_ctx_t *) args;
  assert(actor_ctx->name);

  printf("my_zactor_new : actor_ctx->name = %s\n", actor_ctx->name);
  printf("my_zactor_new : actor_ctx->name = %s\n", actor_ctx->pull_inproc_url);

  //  ... initialize your own state including any other sockets
  zsock_t *inproc = zsock_new_pull(actor_ctx->pull_inproc_url);
  assert(inproc);
  printf("=== my_zactor_new: socket binded. %p\n", (void *)inproc);

  actor_ctx->inproc = inproc;

  zactor_t *my_zactor = zactor_new(zactor_run, actor_ctx);
  actor_ctx->zactor = my_zactor;

  // add this actor to the zloop
  add_actor_to_zloop(actor_ctx);

  printf("<=my_zactor_new : %s\n", actor_ctx->name);
  return my_zactor;
}

void my_zactor_test(bool verbose) {
  /*
  printf("my_zactor_test: \n");
  if (verbose)
    printf("\n");

  zthread_new(my_zactor_new, NULL);

  //  @end
  printf("OK\n");
  */
}

