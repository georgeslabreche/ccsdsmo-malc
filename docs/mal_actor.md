Actor / Handler Execution Model
===============================


The MAL actor uses the MAL C API and in particular the notions of **poller**, **end-point** and **handler**. It is based on the notion of CZMQ actor.

MAL Actor
---------
An actor is in charge of the execution of a set of interaction handlers corresponding to the interactions of a given end-point. The API allows the dynamic addition and removal of handlers. To avoid problems related to parallelism, registering and deleting a handler can be made only from the actor himself.
A handler can only be performed by an unique actor.

An actor reacts to MAL messages independently of any role in the interaction. When receiving a message it searches for the corresponding handler in the list of registered handlers. If successful, it activates the handler by calling the function corresponding to the received message, otherwise the message is destroyed.

The lifetime of an interaction exceeds the reaction of the actor.

Only the actor who received the message initiating an interaction can answer to this interaction.

An actor has the following features:

  -	It corresponds to a single a single endpoint, therefore:
    -	It can only use a single transport (binding) to receive and send MAL messages.
    -	It can use multiple encoding formats for the MAL message body.
    -	It is uniquely identified by a MAL URI relative to the MAL context, the format of this URI depends on the transport used.
    -	It handles a counter of `Transaction Id` (field of MAL header)
  -	It owns a state.
  -	Its life cycle has three states:
    -	When created the `initialize` function is called before the launch of processing loop that handles incoming message.
    -	When receiving a message the processing loop calls the `handle` function to search the handler corresponding to the received message and then activate it.
    -	When stopped the `finalize` function is called before the actor destruction.
  -	The `initialize` and `finalize` functions are customizable by the user.
  -	It runs in single-threaded way.
  -	Its state can be changed only through the handlers reactions.
  -	Its state can not be transmitted to another actor.

If a multithreaded execution mode is needed, for example to perform a costly CPU processing, then the handler must delegate the execution of this task to different actors. The processing is then performed in parallel, and the associated load is shared between all these actors.

Each actor defines a specific endpoint corresponding to the listen socket of the underlying C/ZMQ actor, it uses the concept of poller to simultaneously listen to the user end-point and this internal end-point. The internal end-point allows to receive commands sent to the actor by the `mal_actor_send_command` function.

MAL Actor API
-------------

### Constructor

Create an actor instance identified by a MAL URI. Creating an actor will create the end-point corresponding to the MAL URI of this actor, and the router needed to manage handlers of this actor. The state of this router is the state of the actor.

A `Transaction Id` counter is created.

Declaration:

```c
mal_actor_t *mal_actor_new(
  mal_ctx_t *mal_ctx,
  mal_uri_t *uri,
  void *state,
  mal_actor_initialize_fn *initialize,
  mal_actor_finalize_fn *finalize);
```

Parameters:

  - `mal_ctx` : MAL context
  - `uri` : MAL URI that identify this actor
  - `state` : actor state; untyped to allow polymorphism
  - `initialize` : initialization function
  - `finalize` : finalization function

### Virtual initialization function of the MAL actor

Declaration:

```c
typedef int mal_actor_initialize_fn(void *self, mal_ctx_t *mal_ctx, mal_actor_t *mal_actor);
```

Parameters:

  - `self` : actor state
  - `mal_ctx` : MAL context pointer
  - `mal_actor` : MAL actor pointer

Result:

  - Error code

### Virtual finalisation function of the MAL actor

Declaration:

```c
typedef int mal_handler_finalize_fn(void *self, mal_ctx_t *mal_ctx, mal_actor_t *mal_actor);
```

Parameters:

  - `self` : actor state
  - `mal_ctx` : MAL context pointer
  - `mal_actor` : MAL actor pointer

Result:

  - Error code

### Sending a MAL message

MAL messages are sent through the actor's integrated endpoint (see interface defined in 7.4.2). The actor's interface defines a function to find the corresponding end-point:

```c
mal_endpoint_t *mal_actor_get_mal_endpoint(mal_actor_t *self);
```

### Handlers registration

The registration of the handlers is done through the actor's integrated router (see interface defined in 7.6.3).
The actor's interface defines a function to find the corresponding router:

```c
mal_routing_t *mal_actor_get_router(mal_actor_t *self);
```

### Sending a command to the MAL actor

Sending commands to the an actor via its internal endpoint can be done through the following function:

```c
int mal_actor_send_command(mal_actor_t *to, char *cmd);
```

The parameters of this function are the recipient actor and the string containing the command.
For example, to request the termination of an actor:

```c
mal_actor_send_command(actor, "$TERM");
```

### Destructor

Deletes the actor and free its state.

```c
void mal_actor_destroy(mal_actor_t **self_p);
```

Simple example of a MAL application
-----------------------------------

In this example we use the code already introduced in the tutorial but we use the library of actors described in this chapter.
Most of the code is identical and we only detail the aspects specifically related to the use of MAL actors framework.

### Consumer component

During the creation of the consumer component we also create a MAL actor for managing this component:

```c
send_app_myconsumer_t *consumer = send_app_myconsumer_new(
  provider_uri,
  authentication_id, qoslevel, priority, domain, network_zone, session,
  session_name, MALBINARY_FORMAT_CODE, encoder, decoder);
```

```c
mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "send_app/myconsumer");
mal_actor_t *consumer_actor = mal_actor_new(
  mal_ctx,
  consumer_uri, consumer,
  send_app_myconsumer_initialize, send_app_myconsumer_finalize);
```

The initialization and termination functions are provided to the actor during its creation.
The initialization function allows us to initiate the SEND interaction to the provider. This code corresponds
to the code the run method described in section 4.1.2.

### Provider component

During the creation of the provider component we also create a MAL actor for managing this component:

```c
send_app_myprovider_t *provider =
  send_app_myprovider_new(MALBINARY_FORMAT_CODE, encoder, decoder);
```

```c
mal_actor_t *provider_actor = mal_actor_new(
  mal_ctx,
  provider_uri, provider,
  send_app_myprovider_initialize, send_app_myprovider_finalize);
```

The initialization and termination functions are provided to the actor during its creation.
The initialization function allow to record the handlers of the provider.
The message reception is now handled automatically by the MAL actor:

  -	When a MAL message is received on the endpoint corresponding to the provider's URI the registered handler is automatically executed.
  -	Otherwise the message is destroyed.

### Run the application

Consumer and provider components are now actors, they do not require explicit creation of a ZMQ an actor to run:

```c
send_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
send_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);
```

The launch of the application code is identical:

  -	creation of the MAL context,
  -	creation of encoder and decoder components,
  -	instantiation of the MALZMQ transport,
  -	starting the MAL context.
