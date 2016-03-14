#include "czmq.h"
#include "zmq.h"


#ifndef ZLOOP_CTX_T_DEFINED
struct _zloop_ctx_t {
    zctx_t *ctx;                //  Context wrapper
    char *router_url;
    char *zloop_reply_url;
    zhash_t *map;             //  Key-value store
    zloop_t *loop;              //  zloop reactor
    zsock_t *frontend;
    zsock_t *from_actor;
    bool verbose;
};
typedef struct _zloop_ctx_t zloop_ctx_t;
#define ZLOOP_CTX_T_DEFINED
// zloop reply
#define ZLOOP_REPLY "reply"
#define ZLOOP_ADD_ACTOR "add_actor"
#endif


void *server_loop(void *args);
int socket_event (zloop_t *loop, zmq_pollitem_t *socket, void *args);
int handler_event (zloop_t *loop, zmq_pollitem_t *socket, void *args);
void *my_zloop_ctx_new(void *zloop_ctx);
void *my_zloop_new();
void my_zloop_test(bool verbose);
void send_to_actors(zloop_ctx_t *zloop_ctx, zframe_t *identity, zframe_t *content);
void send_to_actor(zloop_ctx_t *zloop_ctx, char *actor_name, zframe_t *identity, zframe_t *content);
void receive_from_actor(zmsg_t *msg, char *actor_name, zloop_ctx_t *zloop_ctx);
