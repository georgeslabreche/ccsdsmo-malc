Transport API
=============

Transport APIs are defined in the context of a specific binding, for example MALZMQ.
These APIs are not directly used by the final user of the MAL API, these APIs are used by
the MAL/C itself to perform all actions related to the tranport. 

Several virtual functions are defined by the MAL layer, such as the message sending function (section 7.1.8).
Thus, the application code can send messages without dependence to specific transport API.

The code of the various services (consumer, provider) does not depend on the transport API. It only uses the MAL API.
The binding identifier corresponding to the MALZMQ transport is `malzmq`. This identifier is a string used for naming APIs.

Binding Context
---------------

```c
<binding>_ctx.h
```

### Constructor

Declaration:

```c
<binding>_ctx_t *<binding>_ctx_new(mal_ctx_t *mal_ctx);
```

Parameters:

  - `mal_ctx`: MAL context using the created transport.

Result:

  - pointer to the created transport.

### URI creation

This function must conform to the virtual function defined by the MAL API to create a URI (see 7.1.1).

Declaration:

```c
mal_uri_t *<binding>_ctx_create_uri(void *self, char *id);
```

Parameters:

  - `self`: pointer to the transport component.
  - `id`: unique identifier in the transport context.

Result:

  - the created URI

### End-point creation

This function must conform to the virtual function defined by the MAL API to create an end-point (see 7.1.2).

Declaration:

```c
void *<binding>_ctx_create_endpoint(
  void *self,
  mal_endpoint_t *endpoint);
```

Parameters:

  - `self`: pointer to the transport component.
  - `mal_endpoint`: MAL end-point corresponding to the physical transport end-point.

Result:

  - a pointer to the created end-point.

### MAL message sending

This function must conform to the virtual function defined by the MAL API to send a MAL message (see 7.1.8).

Declaration:

```c
int <binding>_ctx_send_message(void *self,
  mal_endpoint_t *mal_endpoint, mal_message_t *message);
```

Parameters:

  - `self`: pointer to the transport component.
  - `mal_endpoint`: MAL end-point sending the message.
  - `message`: MAL message to send.

Result:

  - an error code.
  
### MAL message deletion

This function must conform to the virtual function defined by the MAL API to delete a MAL message (see 7.1.10).

Declaration:

```c
int <binding>_ctx_destroy_message(void *self, mal_message_t *message);
```

Parameters:

  - `self`: pointer to the transport component.
  - `message`: MAL message to delete.

Result:

  - an error code.


### End-point deletion

This function must conform to the virtual function defined by the MAL API to delete an end-point (see 7.1.3).

Declaration:

```c
void <binding>_ctx_destroy_endpoint(void *self, void **endpoint_p);
```

Parameters:

  - `self`: pointer to the transport component.
  - `mal_endpoint`: handle to the MAL end-point to delete.

Result:

  - an error code.


### Poller creation

This function must conform to the virtual function defined by the MAL API to create a MAL poller (see 7.1.4).

Declaration:

```c
void *<binding>_ctx_create_poller(
  void *self,
  mal_poller_t *poller);
```

Parameters:

  - `self`: pointer to the transport component.
  - `mal_poller`: MAL poller corresponding to the physical transport poller.

Result:

  -- pointer to the created poller.

### End-point adding / removing to the poller

Theses functions must conform to the virtual functions defined by the MAL API to add and remove an end-point to a poller (see 7.1.5).

Declaration:

```c
int malzmq_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

int malzmq_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);
```

Parameters:

  - `self`: pointer to the transport component.
  - `mal_poller`: MAL poller corresponding to the physical transport poller.
  - `mal_endpoint`: MAL end-point to add / remove to the specified poller.

Result:

  - an error code.


### Message waiting trough the poller

This function must conform to the virtual function defined by the MAL API allowing to wait a MAL message through a poller's end-point (see 7.1.6).

Declaration:

```c
int malzmq_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t **mal_endpoint,
    int timeout);
```

Parameters:

  - `self` : pointer to the transport component.
  - `mal_poller` : MAL poller corresponding to the physical transport poller.
  - `mal_endpoint` : MAL end-point that expect a message.
  - `timeout` : the maximum waiting time, possibly unlimited (-1)

Result:

  - an error code.

### Poller deletion

This function must conform to the virtual function defined by the MAL API to delete a poller (see 7.1.7).

Declaration:

```c
void <binding>_ctx_destroy_poller(void *self, void **poller_p);
```

### Destructor

Delete the transport context.

Declaration:

```c
void <binding>_ctx_destroy(<binding>_ctx_t **self_p);
```
