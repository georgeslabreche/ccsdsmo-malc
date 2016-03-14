#include "czmq.h"
#include "zmq.h"

#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

int id = 0;

static void *
client_task(void *args) {
  zctx_t *ctx = zctx_new();
  assert(ctx);
  void *client = zsocket_new(ctx, ZMQ_DEALER);
  assert(client);

  //char identity [10];
  //sprintf (identity, "%d", id);
  //zsockopt_set_identity (client, identity);
  int zc = zsocket_connect(client, "tcp://localhost:5555");
  assert(zc == 0);

  /* Create a ZMQ_SUB socket */
  //void *client = zmq_socket (ctx, ZMQ_DEALER);
  //assert (client);
  /* Connect it to the host server001, port 5555 using a TCP transport */
  //int rc = zmq_connect (client, "tcp://localhost:5555");
  //assert (rc == 0);
  zmq_pollitem_t items[] = { { client, 0, ZMQ_POLLIN, 0 } };
  int request_nbr = 0;
  while (true) {
    //  Tick once per second, pulling in arriving messages
    int centitick;
    for (centitick = 0; centitick < 100; centitick++) {
      zmq_poll(items, 1, 1);
      if (items[0].revents & ZMQ_POLLIN) {
        zmsg_t *msg = zmsg_recv(client);
        //char * string = zmsg_popstr(msg);
        //printf("msg = %s\n", string);
        zmsg_destroy(&msg);
        break;
      }
    }
    id += 1;
    char data[10];
    sprintf(data, "msg nb %d", ++request_nbr);
    zmsg_t *msg = zmsg_new();
    zmsg_addstr(msg, data);
    zmsg_send(&msg, client);
  }
  zctx_destroy(&ctx);
  return NULL;
}

/*
static void *
client_task1(void *args) {
  zctx_t *ctx = zctx_new();
  void *dealer = zsocket_new(ctx, ZMQ_DEALER);
  zsocket_connect(dealer, "tcp://localhost:5555");
  zmsg_t *msg = zmsg_new();
  zmsg_addstr(msg, "mon message.");
  zmsg_send(&msg, dealer);
  msg = zmsg_recv(dealer);
  if (msg != NULL) {
    while (zmsg_size(msg) > 0) {
      char *s = zmsg_popstr(msg);
      printf("receive = %s\n", s);
      free(s);
    }
    zmsg_destroy(&msg);
  } else {
    printf("failed\n");
  }
  zsocket_destroy(ctx, dealer);
  zctx_destroy(&ctx);
  return 0;
}
*/

float diffTime(struct timeval t0, struct timeval t1) {
  return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void async_cli_test(bool verbose) {
  printf("async_cli: \n");
  if (verbose)
    printf("\n");

  struct timeval tv0;
  struct timeval tv1;
  float elapsed;
  gettimeofday(&tv0, 0);

  //  @selftest
  zthread_new(client_task, NULL);
  //zthread_new (client_task, NULL);
  zclock_sleep(10 * 1000);    //  Run for 10 seconds then quit
  printf("\ntotal iterations = %d\n", id);

  gettimeofday(&tv1, 0);
  elapsed = diffTime(tv0, tv1);
  printf("Time (ms) : %10.2f\n", elapsed);

  printf("debit : %10.0f m/s\n", id*1000/elapsed);

  if (verbose)
    printf("test end !!!! \n");

  //  @end
  printf("OK\n");
}

//  The main thread simply starts several clients and a server, and then
//  waits for the server to finish.

int main(void) {
  async_cli_test(false);
  return 0;
}
