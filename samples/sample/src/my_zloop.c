#include "../include/my_zloop.h"


void *server_loop(void *args) {
  printf("=> server_loop\n");

  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) args;
  assert(zloop_ctx);

  zloop_ctx->loop = zloop_new ();
  assert(zloop_ctx->loop);
  zloop_set_verbose(zloop_ctx->loop, zloop_ctx->verbose);

  // create map
  zloop_ctx->map = zhash_new ();

  // Frontend socket talks to clients over TCP
  zloop_ctx->ctx = zctx_new();
  zloop_ctx->frontend = (zsock_t *) zsocket_new(zloop_ctx->ctx, ZMQ_ROUTER);
  assert(zloop_ctx->frontend);
  int rc = zsocket_bind(zloop_ctx->frontend, zloop_ctx->router_url);
  assert(rc);

  // Register our socket handlers with reactor
  zmq_pollitem_t poller = { 0, 0, ZMQ_POLLIN };
  poller.socket = zloop_ctx->frontend;
  rc = zloop_poller (zloop_ctx->loop, &poller, socket_event, zloop_ctx);
  assert(rc == 0);

  // Create socket from.zactor and connect over inproc
  zloop_ctx->from_actor = (zsock_t *) zsocket_new(zloop_ctx->ctx, ZMQ_ROUTER);
  zsocket_bind(zloop_ctx->from_actor, zloop_ctx->zloop_reply_url);
  assert(zloop_ctx->from_actor);
  // Register our handlers with reactor
  poller.socket = zloop_ctx->from_actor;
  rc = zloop_poller (zloop_ctx->loop, &poller, handler_event, zloop_ctx);
  assert(rc == 0);


  // Run reactor until process interrupted
  zloop_start (zloop_ctx->loop);

  printf("server_loop: ============ destroy\n");

  zloop_destroy(&zloop_ctx->loop);
  assert(zloop_ctx->loop == NULL);
  zsock_destroy(&zloop_ctx->from_actor);
  //zsock_destroy(&zloop_ctx->to_actor);
  zsock_destroy(&zloop_ctx->frontend);
  zhash_destroy (&zloop_ctx->map);
  assert(zloop_ctx->map == NULL);
  free(zloop_ctx);

  printf("<= server_loop\n");
  return zloop_ctx;
}

int socket_event (zloop_t *loop, zmq_pollitem_t *poller, void *args) {
  printf("=> socket_event\n");

  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) args;
  assert(zloop_ctx);

  zmsg_t *msg = zmsg_recv(poller->socket);
  zmsg_dump(msg);

  zframe_t *identity = zmsg_pop(msg);
  zframe_t *content = zmsg_pop(msg);
  assert(content);
  zframe_t *target = zmsg_pop(msg);
  zmsg_destroy(&msg);
  if (target == NULL) {
    //char *string = zframe_strdup(content);
    //printf("msg = %s\n", string);
    send_to_actors(zloop_ctx, identity, content);

  } else {
    char *to = zframe_strdup(target);
    send_to_actor(zloop_ctx, to, identity, content);
    zframe_destroy(&target);
  }
  zframe_destroy(&identity);
  zframe_destroy(&content);

  printf("<= socket_event\n");
  return 0;
}

void send_to_actor(zloop_ctx_t *zloop_ctx, char *actor_name, zframe_t *identity, zframe_t *content) {
  printf("=>send_to_actor: actor_name = %s\n", actor_name);
  void *item = zhash_lookup(zloop_ctx->map, actor_name);
  if (item == NULL) {
    return;
  }
  zsock_t *to_actor = (zsock_t *) item;
  int ret = zframe_send(&identity, to_actor, ZFRAME_REUSE + ZFRAME_MORE);
  printf("send identity = %d to %s\n", ret, actor_name);
  ret = zframe_send(&content, to_actor, ZFRAME_REUSE);
  printf("send message = %d to %s\n", ret, actor_name);
  printf("<=send_to_actor\n");
}

void send_to_actors(zloop_ctx_t *zloop_ctx, zframe_t *identity, zframe_t *content) {
   printf("=>send_to_actors: map.size = %zu\n", zhash_size (zloop_ctx->map));
   zsock_t *to_actor;
   void *item = zhash_next(zloop_ctx->map);
   while (item != NULL) {
     printf("send_to_actors: item = %p\n", item);
     to_actor = (zsock_t *) item;
     int ret = zframe_send(&identity, to_actor, ZFRAME_REUSE + ZFRAME_MORE);
     printf("send identity = %d\n", ret);
     ret = zframe_send(&content, to_actor, ZFRAME_REUSE);
     printf("send message = %d\n", ret);
     // next item
     item = zhash_next(zloop_ctx->map);
   };
   printf("<=send_to_actors\n");
}

void receive_from_actor(zmsg_t *msg, char *actor_name, zloop_ctx_t *zloop_ctx) {
  // receive the identity
  zframe_t *identity = zmsg_pop(msg);
  assert(identity);
  // receive the content
  zframe_t *content = zmsg_pop(msg);
  assert(content);
  char* new_msg;

  printf("from_actor msg = %s\n", zframe_strdup(content));

  asprintf(&new_msg, "%s(%s) : %s", "FROM_ACTOR ", actor_name, zframe_strdup(content));
  content = zframe_new(new_msg, strlen(new_msg));

  int rc = zframe_send(&identity, zloop_ctx->frontend, ZFRAME_REUSE + ZFRAME_MORE);
  assert(rc == 0);
  rc = zframe_send(&content, zloop_ctx->frontend, ZFRAME_REUSE);
  assert(rc == 0);

  zframe_destroy(&identity);
  zframe_destroy(&content);
  free(new_msg);
}

int handler_event(zloop_t *loop, zmq_pollitem_t *poller, void *args) {
  printf("=>zloop.handler_event\n");

  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) args;
  assert(zloop_ctx);

  zmsg_t *msg = zmsg_recv(poller->socket);

  // receive the actor name
  zframe_t *name = zmsg_pop(msg);
  assert(name);
  char *actor_name = zframe_strdup(name);
  // receive the command : ex ZLOOP_ADD_ACTOR or ZLOOP_REPLY
  zframe_t *cmd = zmsg_pop(msg);
  assert(cmd);
  char *command = zframe_strdup(cmd);

  if (strcmp(command, ZLOOP_ADD_ACTOR) == 0) {
    // receive the actor url
    zframe_t *actor_url = zmsg_pop(msg);
    assert(actor_url);
    char *url = zframe_strdup(actor_url);
    if (poller->socket == zloop_ctx->from_actor) {
      printf("from_actor actor_url = %s\n", url);
    }
    // Look for non-existent items
    void *item = (void *) zhash_lookup (zloop_ctx->map, actor_name);
    if (item == NULL) {
      // Create socket to the new actor and connect over inproc
      zsock_t *zsock_new_actor = zsock_new_push(url);
      assert(zsock_new_actor);
      int rc = zhash_insert (zloop_ctx->map, actor_name, zsock_new_actor);
      assert (rc == 0);
    }
    free(url);

  } else if (strcmp(command, ZLOOP_REPLY) == 0) {
    if (poller->socket == zloop_ctx->from_actor) {
      // call the receive function
      receive_from_actor(msg, actor_name, zloop_ctx);
    }
  }

  free(command);
  zmsg_destroy(&msg);
  zframe_destroy(&cmd);
  zframe_destroy(&name);
  printf("<=zloop.handler_event\n");
  return 0;
}

void *my_zloop_new() {
  printf("=>my_zloop_new\n");
  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) zmalloc (sizeof (zloop_ctx_t));
  zloop_ctx->router_url = "tcp://*:5555";
  //zloop_ctx->push_inproc_url = "inproc://zactor.A";
  zloop_ctx->zloop_reply_url = "tcp://*:5557";
  zloop_ctx->verbose = true;
  void * s_loop = server_loop(zloop_ctx);
  assert(s_loop);
  printf("<=my_zloop_new\n");
  return s_loop;
}

void *my_zloop_ctx_new(void *args) {
  printf("=>my_zloop_new %p\n", (void *) args);

  assert(args);
  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) args;

  void * s_loop = server_loop(zloop_ctx);
  assert(s_loop);
  printf("<=my_zloop_new\n");
  return s_loop;
}

void my_zloop_test(bool verbose) {
  /*
  printf("my_zloop_test: \n");
  if (verbose)
    printf("\n");

  zthread_new(my_zloop_new, NULL);

  //  @end
  printf("OK\n");
  */
}


