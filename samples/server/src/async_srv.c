#include "czmq.h"
#include "zmq.h"

static void server_worker(void *args, zctx_t *ctx, void *pipe);

void *server_task(void *args) {
  //  Frontend socket talks to clients over TCP
  zctx_t *ctx = zctx_new();
  void *frontend = zsocket_new(ctx, ZMQ_ROUTER);
  zsocket_bind(frontend, "tcp://*:5555");

  //  Backend socket talks to workers over inproc
  void *backend = zsocket_new(ctx, ZMQ_DEALER);
  zsocket_bind(backend, "inproc://backend");

  //  Launch pool of worker threads, precise number is not critical
  int thread_nbr;
  for (thread_nbr = 0; thread_nbr < 3; thread_nbr++)
    zthread_fork(ctx, server_worker, NULL);

  //  Connect backend to frontend via a proxy
  zmq_proxy(frontend, backend, NULL);

  zctx_destroy(&ctx);
  return NULL;
}

static void server_worker(void *args, zctx_t *ctx, void *pipe) {
  void *worker = zsocket_new(ctx, ZMQ_DEALER);
  zsocket_connect(worker, "inproc://backend");

  while (true) {
    //  The DEALER socket gives us the reply envelope and message
    zmsg_t *msg = zmsg_recv(worker);
    //zmsg_dump(msg);

    zframe_t *identity = zmsg_pop(msg);
    zframe_t *content = zmsg_pop(msg);
    assert(content);

    //char *string = zframe_strdup(content);
    //printf("msg = %s\n", string);

    zmsg_destroy(&msg);

    //  Sleep for some fraction of a second
    zframe_send(&identity, worker, ZFRAME_REUSE + ZFRAME_MORE);
    zframe_send(&content, worker, ZFRAME_REUSE);

    zframe_destroy(&identity);
    zframe_destroy(&content);
  }
}

void async_srv_test(bool verbose) {
  printf("async_srv: \n");
  if (verbose)
    printf("\n");

  //  @selftest
  zthread_new(server_task, NULL);
  zclock_sleep(15 * 1000);    //  Run for 15 seconds then quit

  if (verbose)
    printf("test end !!!! \n");

  //  @end
  printf("OK\n");
}

int main(void) {
  async_srv_test(false);
  return 0;
}

