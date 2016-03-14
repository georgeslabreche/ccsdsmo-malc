#include "../include/sample.h"

void *client_task(void *args);

/**
 * Create one actor and one loop.
 * And call the client.
 *
 */
void sample_new() {
  // create the actor
  actor_ctx_t *actor_ctx = (actor_ctx_t *) zmalloc(sizeof(actor_ctx_t));
  assert(actor_ctx);
  actor_ctx->pull_inproc_url = "inproc://zactor.A";
  actor_ctx->zloop_reply_url = "tcp://localhost:5557";
  actor_ctx->zloop_reply_type = ZMQ_DEALER;

  // create the loop
  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) zmalloc(sizeof(zloop_ctx_t));
  assert(zloop_ctx);
  zloop_ctx->router_url = "tcp://*:5555";
  zloop_ctx->zloop_reply_url = "tcp://*:5557";
  zloop_ctx->verbose = true;


  zthread_new(my_zactor_new, actor_ctx);
  zthread_new(my_zloop_new, zloop_ctx);

  zclock_sleep(1000);
  printf("\n\n*********** ZActor and ZLoop started. *************\n\n");

  zclock_sleep(1000);
  printf("\n\n*********** start client 1 *************\n");
  zthread_new(client_task, NULL);

  zclock_sleep(2 * 1000);    // Run for 2 seconds then quit
}

/**
 * Create the actor A, the actor B and one loop.
 * Call the client with no args => wait tow replies (from A and B).
 * Call the client with the B actor args => wait the reply from B.
 *
 */
void sample_new1() {
  // create the actor A
  actor_ctx_t *actor_ctx = (actor_ctx_t *) zmalloc(sizeof(actor_ctx_t));
  assert(actor_ctx);
  actor_ctx->name = "zactor.A";
  actor_ctx->pull_inproc_url = "inproc://zactor.A";
  actor_ctx->zloop_reply_url = "tcp://localhost:5557";
  actor_ctx->zloop_reply_type = ZMQ_DEALER;

  printf("\nnew actor : %s\n", actor_ctx->name);
  printf("new actor : actor_ctx %p\n", (void *) actor_ctx);
  // start ZACTOR A
  zthread_new(my_zactor_ctx_new, actor_ctx);
  printf("new actor : %s CREATED.\n", actor_ctx->name);

  // create the actor B
  actor_ctx_t *actor_ctx_b = (actor_ctx_t *) zmalloc(sizeof(actor_ctx_t));
  assert(actor_ctx_b);
  actor_ctx_b->name = "zactor.B";
  actor_ctx_b->pull_inproc_url = "inproc://zactor.B";
  actor_ctx_b->zloop_reply_url = "tcp://localhost:5557";
  actor_ctx_b->zloop_reply_type = ZMQ_DEALER;
  printf("\nnew actor : %s\n", actor_ctx_b->name);
  printf("new actor : actor_ctx_b %p\n", (void *) actor_ctx_b);
  // start ZACTOR B
  zthread_new(my_zactor_ctx_new, actor_ctx_b);
  printf("new actor : %s CREATED.\n", actor_ctx_b->name);

  // create the loop
  zloop_ctx_t *zloop_ctx = (zloop_ctx_t *) zmalloc(sizeof(zloop_ctx_t));
  assert(zloop_ctx);
  zloop_ctx->router_url = "tcp://*:5555";
  zloop_ctx->zloop_reply_url = "tcp://*:5557";
  zloop_ctx->verbose = true;
  // start the Zloop
  zthread_new(my_zloop_new, zloop_ctx);

  zclock_sleep(1000);
  printf("\n\n*********** ZActor and ZLoop started. *************\n\n");

  zclock_sleep(1000);
  printf("\n\n*********** start client 1 *************\n");
  zthread_new(client_task, NULL);

  zclock_sleep(1000);
  printf("\n\n*********** start client 2 *************\n");
  char *target = "zactor.B";
  zthread_new(client_task, target);

  zclock_sleep(2 * 1000);    // Run for 2 seconds then quit

  //TODO free...
}

/**
 * send one message "mon message",
 * to all actors if args = NULL, or to the actor if args = actor.
 * And receive the replies.
 *
 */
void *client_task(void *args) {
  char *target = NULL;
  if (args != NULL) {
    target = (char *) args;
  }
  zctx_t *ctx = zctx_new();
  void *dealer = zsocket_new(ctx, ZMQ_DEALER);
  zsocket_connect(dealer, "tcp://localhost:5555");
  char *m = "mon message";
  zmsg_t *msg = zmsg_new();
  zmsg_addstr(msg, m);
  if (target != NULL) {
    zmsg_addstr(msg, target);
    printf("++++++++++++++ CLIENT send = \"%s\" to %s actor.\n", m, target);
  } else {
    printf("++++++++++++++ CLIENT send = \"%s\" to all actors.\n", m);
  }
  zmsg_send(&msg, dealer);

  while (true) {
    msg = zmsg_recv(dealer);
    if (msg != NULL) {
      while (zmsg_size(msg) > 0) {
        char *s = zmsg_popstr(msg);
        printf("++++++++++++++ CLIENT receive = %s\n", s);
        free(s);
      }
      zmsg_destroy(&msg);
    } else {
      printf("failed\n");
    }
  }
  zsocket_destroy(ctx, dealer);
  zctx_destroy(&ctx);
  return 0;
}

void sample_test(bool verbose) {
  printf("sample_test: \n");
  if (verbose)
    printf("\n");

  //  @selftest
  sample_new1();

  if (verbose)
    printf("test end !!!! \n");

  //  @end
  printf("OK\n");
}
