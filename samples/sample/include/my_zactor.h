#include "czmq.h"
#include "zmq.h"

#ifndef ACTOR_CTX_T_DEFINED
struct _actor_ctx_t {
  char *name;
  zsock_t *pipe;  //  Actor command pipe
  zpoller_t *poller;  //  Socket poller
  zsock_t *inproc;
  zsock_t *zloop_reply;
  //handle_A_fn *handle;
  zactor_t *zactor;
  char *zloop_reply_url;
  int zloop_reply_type;
  char *pull_inproc_url;
  bool terminated;
  bool verbose;
};
typedef struct _actor_ctx_t actor_ctx_t;
#define ACTOR_CTX_T_DEFINED
#endif

void zactor_handle_pipe (actor_ctx_t *actor_ctx);
void zactor_handle_socket (actor_ctx_t *actor_ctx);
void zactor_run(zsock_t *pipe, void *args);
void write_pipe(zactor_t *zactor, char *data);
void ack(zsock_t *socket, zframe_t *identity, zframe_t *content);
void init_zloop_reply(actor_ctx_t *actor_ctx);
void *my_zactor_ctx_new(void *actor_ctx);
void *my_zactor_new();
void my_zactor_test(bool verbose);
void add_actor_to_zloop(actor_ctx_t *actor_ctx);
