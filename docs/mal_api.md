MAL API
=======

MAL API allows the use of MAL-level concepts:

  - concepts defined by the MAL specification (Blue Book).
  - specific concepts to the C API, defined in section 2.

The MAL API contains the Area API generated from the definition of the MAL Area.

Definition
----------

```c
mal.h
```

### Virtual function to create an URI

Function to be provided by a MAL binding to create a URI.

Declaration:

```c
typedef mal_uri_t *mal_binding_ctx_create_uri_fn(
  void *mal_binding_ctx,
  char *id);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings. 
  - `id`: unique identifier to include in the created URI.

Result: 

  - Created URI.

### Virtual function to create an end-point

Function to be provided by a MAL binding to create an end-point.

Declaration:

```c
typedef void *mal_binding_ctx_create_endpoint_fn(
  void *mal_binding_ctx,
  mal_endpoint_t *mal_endpoint);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_endpoint`: MAL end-point corresponding to the physical transport end-point to create.

Result:

  - The pointer to the physical end-point created (untyped to allow the use of multiple bindings, for example ZMQ socket).

### Virtual function to delete an end-point

Function to be provided by a MAL binding to destroy an end-point.

Declaration:

```c
typedef void mal_binding_ctx_destroy_endpoint_fn(
  void *mal_binding_ctx,
  void **endpoint_p);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `endpoint_p`: the end-point to delete.

### Virtual function to create a poller

Function to be provided by a MAL binding to create a poller.

Declaration:

```c
typedef void *mal_binding_ctx_create_poller_fn(
  void *mal_binding_ctx,
  mal_poller_t *mal_poller);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_poller`: the MAL poller corresponding to the physical transport poller to create.

Result: 

  - The pointer to the physical poller created (untyped to allow the use of multiple bindings, for example ZMQ zpoller).

### Virtual function to destroy a poller

Function to be provided by a MAL binding to destroy a poller.

Declaration:

```c
typedef void mal_binding_ctx_destroy_poller_fn(
  void *mal_binding_ctx,
  void **poller_p);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `poller_p`: poller to destroy.

### Virtual function to add (resp. remove) an end-point to a poller

Functions to be provided by a MAL binding to add or remove an end-point to a poller.

Declaration:

```c
typedef int mal_binding_ctx_poller_add_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

typedef int mal_binding_ctx_poller_del_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_poller`: MAL poller to use.
  - `mal_endpoint`: MAL end-point to add (resp. remove) to the specified poller.

Result:

  - an error code.
  
### Virtual function for waiting a message on a poller

Function to be provided by a MAL binding to wait on a poller.

Declaration:

```c
typedef int mal_binding_ctx_poller_wait_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t **mal_endpoint,
    int timeout);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_poller`: MAL poller to use.
  - `mal_endpoint`: MAL end-point on which a message is pending.
  - `timeout`: the maximum waiting time, possibly infinite (-1).

Result:

  - an error code.

### Virtual function to send a message

Function to be provided by a MAL binding to send a message.
This function is called by `mal_ctx_send_message` (see section 7.4.2).

Declaration:

```c
typedef int mal_binding_ctx_send_message_fn(
    void *mal_binding_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_endpoint`: MAL end-point sending the message.
  - `message`: MAL message to send.

Result:

  - an error code.

### Virtual function to receive a message

Function to be provided by a MAL binding to receive a message.
This function is called by `mal_ctx_recv_message` (see section 7.4.3).

Declaration:

```c
typedef int mal_binding_ctx_recv_message_fn(
  void *mal_binding_ctx,
  mal_endpoint_t *mal_endpoint,
  mal_message_t **message);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `mal_endpoint`: MAL end-point receiving the message.
  - `message`: receiving message.

Result:

  - an error code.

### Virtual function to delete a MAL message

Function to be provided by a MAL binding to destroy a message.
Allows the transport to free resources (field `body_owner`) that it has associated with the message before its destruction.

Declaration:

```c
typedef int mal_binding_ctx_destroy_message_fn(
    void *mal_binding_ctx,
    mal_message_t *message);
```

Parameters:

  - `mal_binding_ctx`: transport context (binding) used by the MAL layer; untyped to allow the use of multiple bindings.
  - `message`: MAL message to delete.

Result:

  - an error code.

Contexte MAL
------------

```c
mal_ctx.h
```

### Constructor

Declaration:

```c
mal_ctx_t *mal_ctx_new(void);
```

Result: 

  - The created MAL context.

### URI creation

Declaration:

```c
mal_uri_t *mal_ctx_create_uri(mal_ctx_t *self, char *id);
```

Parameters:

  - `self`: MAL context.
  - `id`: unique identifier in the transport context.

Result: 

  - The created URI.

### Poller creation

Declaration:

```c
void *mal_ctx_create_poller(
  mal_ctx_t *self,
  mal_poller_t *poller);
```

Parameters:

  - `self`: MAL context.
  - `poller`: MAL poller corresponding to the new physical poller.

Result: 

  - A pointer to the created physical poller (untyped to avoid dependence with physical concepts of transport, for example a ZMQ zpoller).

### end-point creation

Declaration:

```c
void *mal_ctx_create_endpoint(
  mal_ctx_t *self,
  mal_endpoint_t *endpoint);
```

Parameters:

  - `self`: MAL context.
  - `endpoint`: MAL end-point corresponding to the new physical end-point.

Result: 

  - A pointer to the created physical end-point (untyped to avoid dependence with physical concepts of transport, for example a ZMQ socket).

### MAL message sending

This function is used by message sending functions of MAL end-points (section 7.4.2). It calls the message sending function offered by the underlying transport (section 7.1.8).

The use of this function is restricted to MAL end-point.

Declaration:

```c
int mal_ctx_send_message(
  mal_ctx_t *self,
  mal_endpoint_t *mal_endpoint,
  mal_message_t *message);
```

Parameters:

  - `self`: MAL context.
  - `mal_endpoint`: MAL end-point sending the message.
  - `message`: MAL message to send.

Result:

  - an error code.

### MAL message reception

This function is used by the message receiving functions of MAL end-points (section 7.4.3). It calls the message receiving function offered by underlying transport (7.1.9).

The use of this function is restricted to MAL end-point.

Declaration:

```c
int mal_ctx_recv_message(
  mal_ctx_t *self,
  mal_endpoint_t *mal_endpoint,
  mal_message_t **message);
```

Parameters:

  - `self`: MAL context.
  - `mal_endpoint`: MAL end-point receiving the message.
  - `message`: MAL message received.

Result:

  - an error code.

### Destructor

Deletes the MAL context.

```c
  void mal_ctx_destroy(mal_ctx_t **self_p);
```

Parameters:
  
  - `self_p`: Handle to the MAL context to delete.

MAL message
-----------

### Constructor

Allocate the memory chunk needed for the message body.

Declaration:

```c
mal_message_t *mal_message_new(
  mal_blob_t *authentication_id,
  mal_qoslevel_t qoslevel, mal_uinteger_t priority, mal_list_t *domain,
  mal_identifier_t *network_zone, mal_sessiontype_t session,
  mal_identifier_t *session_name, unsigned int body_length);
```

Parameters:

  - MAL header fields.
  - Message body size in bytes.

Result:

  - The new MAL message.
  
### Initialisation

Initialization of the header fields corresponding to the operation and interaction stage.

Declaration:

```c
void mal_message_init(mal_message_t *self, mal_ushort_t service_area,
  mal_uoctet_t area_version, mal_ushort_t service,
  mal_ushort_t operation,
  mal_interactiontype_t interaction_type,
  mal_uoctet_t interaction_stage);
```

Parameters:

  - `self`: a pointer to the MAL message to initialize.
  - MAL header fields.

### Destructor

Deletes the MAL message and the corresponding body.
Calls the virtual function provided by the transport API.
Declaration:

```c
void mal_message_destroy(mal_message_t **self_p, mal_ctx_t *mal_ctx);
```

Parameters:

  - `self`: an handle to the MAL message to destroy.
  - The MAL context needed to free associated resources in transport binding if needed.

### Getters et setters

The fields defined in the following table are accessible through getter and setter methods.

Champ | Type | Description
------|------|-----------------
`<mal header field>` | `<mal header field type>` | MAL header fields as described in the MAL blue book.
`free_<header field>` | `bool` | Flags indicating whether the corresponding MAL header fields of type pointer must be destroyed when the MAL message is deleted.
`body` | `char *` | Message Body encoded.
`body_offset` | `unsigned int` | Start offset of the message body.
`body_length` | `unsigned int` | Size of the message body.
`body_owner` | `void *` | Resource associated with the message by the transport. Should be released during the destruction of the message.

Presence flags apply to the following fields: `URI To`, `Authentication Id`, `URI From`, `Domain`, `Network Zone`, `Session Name`.
By default, the behavior is:

  - If the MAL message is created through the constructor then the flag is false. The MAL header fields are transmitted by the application when calling the constructor, so they do not have to be released.
  - If the MAL message is created by the transport during a reception and if the header fields have been decoded (not recovered from a configuration service) then the flag is true. The MAL header fields are owned by the message and should be destroyed with it.

End-Point MAL
-------------

Each endpoint should be handled by a single execution flow.

### Constructor

Create an endpoint instance identified by a MAL URI.
A `Transaction Id` counter is managed.

Declaration:

```c
mal_endpoint_t *mal_endpoint_new(mal_ctx_t *mal_ctx, mal_uri_t *uri);
```

Parameters:

  - `mal_ctx`: a pointer to the MAL context.
  - `uri`: MAL URI identifying the MAL endpoint.

The API provides two functions to retrieve the URL and context MAL corresponding to an end-point:

```c
mal_uri_t *mal_endpoint_get_uri(mal_endpoint_t *self);
mal_ctx_t *mal_endpoint_get_mal_ctx(mal_endpoint_t *self);
```

### MAL message sending

Two message sending functions are defined:

  - A funtion to initiate an interaction (first stage). This function sets the URI fields of the message: the destination URI of the message is set with the `uri_to` parameter, and the source URI of the message is set with the endpoint URI. If the `set_tid` flag is true then the `Transaction Id` field is set with the next value of the `TransactionId` counter handled by the endpoint. Otherwise the original value of the `Transaction Id` field is left unchanged.
  - A function for the next stages of the interaction. This function sets the URI fields of the message: the destination URI of the message is set with the `uri_from` field of the initiation message, and the source URI of the message is set with the endpoint URI. The `Transaction Id` field of the message is set with the `Transaction Id` field of the initiation message. The field `Is Error Message` is set with the value of the `is_error_message` parameter. counter.
  
The `mal_ctx_send_message` function (section 7.2.5) is called to send the MAL message.

Declaration:

```c
int mal_endpoint_init_operation(
  mal_endpoint_t *self,
  mal_message_t *message,
  mal_uri_t *uri_to,
  bool set_tid);

int mal_endpoint_return_operation(
  mal_endpoint_t *self,
  mal_message_t *init_message,
  mal_message_t *message,
  bool is_error_message);
```

Parameters:

  - `self`: A pointer to the MAL endpoint sending the message.
  - `message`: A pointer to the MAL message to send.
  - `init_message`: A pointer to the MAL message initiating the interaction.
  - `uri_to`: The MAL URI of the message recipient.
  - `set_tid`: Boolean indicating whether the field 'Transaction ID' of the message MAL should be affected or not.
  - `is_error_message`:  Boolean indicating whether the message returns an error

Result: 

Error code.

### MAL message reception

The `mal_endpoint_recv_message` function allows to receive a message on the end-point.
This function blocks until receiving a message. The destroying of the message is then the
responsability of the caller of `mal_endpoint_recv_message` function.

Declaration:

```c
int mal_endpoint_recv_message(
    mal_endpoint_t *self,
    mal_message_t **message);
```

Parameters:
 
  - `self`: A pointer to the MAL endpoint waiting for a message.
  - `message`: The message received.

Result: 

Error code.

### Destructor

Delete the endpoint.

Declaration:

```c
void mal_endpoint_destroy(mal_endpoint_t **self_p);
```

MAL Poller
----------

Each MAL poller should be handled by a single execution flow.

### Constructor

Create a poller instance identified by a MAL URI.

Declaration:

```c
  mal_poller_t *mal_poller_new(mal_ctx_t *mal_ctx);
```

Parameters:

  - `mal_ctx`: A pointer to the MAL context.

The API provides a function to retrieve the MAL context corresponding to the poller:

```c
mal_ctx_t *mal_poller_get_mal_ctx(mal_poller_t *self);
```

### Add / Remove MAL endpoint

Twos functions allow to add and remove a endpoint to the poller.

Declaration:

```c
int mal_poller_add_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *endpoint);

int mal_poller_del_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint);
```

Parameters:

  - `self`: A pointer to the MAL poller.
  - `endpoint`: A pointer to the MAL endpoint to add or remove.

Result:

Error code.

### Attente de message MAL

`mal_poller_wait` function allows to wait the reception of a MAL message on one of the endpoint handled by the poller.
This is a blocking function, it takes a time-out parameter.

Declaration:

```c
int mal_poller_wait(
    mal_poller_t *self,
    mal_endpoint_t **endpoint,
    int timeout);
```

Parameters:

  - `self`: A pointer to the poller waiting a MAL message.
  - `endpoint`: An handle to the endpoint which received a message.
  - `timeout`: The maximum waiting time, possibly infinite (-1).

Result:

Error code.

### Destructor


Deletes the MAL poller. The associated endpoint should be destroyed explicitly.

Declaration:

```c
  void mal_poller_destroy(mal_oller_t **self_p);
```

MAL Handler and routing
-----------------------
A handler is a logical structure composed of a set of MAL message processing functions.
This set of functions depends of its role (provider, consumer, etc.) and interaction in
which it operates (send, submit, etc.). Handlers run in the context of a routing structure
(i e, an object of the class `mal_routing`, or router).

The router is linked to the MAL endpoint: it allows to register the handlers corresponding
to different expected interactions, then on a message receipt it allows the activatation of
the corresponding handler to handle the message. The router shares its state with all its
handlers.

### Handler

Each message processing function of the handler has the same signature defined below.

  - the state of the router,
  - a pointer to the MAL context,
  - a pointer the MAL endpoint,
  - a pointer to the message to process.
  
The corresponding signature is.

Declaration:

```c
typedef int mal_routing_on_message_fn(
  void *self,
  mal_ctx_t *mal_ctx,
  mal_endpoint_t *mal_endpoint,
  mal_message_t *message);
```

Parameters:

  - `state`: The state of the router (untyped to allow polymorphism).
  - `mal_ctx`: A pointer to the MAL context.
  - `endpoint`: A pointer to the MAL endpoint.
  - `message`: A pointer to the message to process.

### Constructor

Create a router instance identified by the corresponding endpoint URI.
Normally only a single router must be associated with a given MAL endpoint.

Declaration:

```c
mal_routing_t *mal_routing_new(mal_endpoint_t *endpoint, void *state);
```

Parameters:

  - `endpoint`: A pointer to the MAL endpoint.
  - `state`: The state of the router (untyped to allow polymorphism).

### Handlers registering

The MAL router interface defines the set of functions for registering the interaction's handlers.
Each function takes as parameters a pointer to the router's state itself, the identification of the area, version, identity of service and operation. Depending on the role of the handler and the operation type, the interface includes pointers to the functions allowing to process the messages corresponding to the interaction.

L'interface defines a function to register an handler of *Send* interaction, and two functions to register the *provider* and *consumer* handlers of each interactions *Submit*, *Request*, *Invoke* et *Progress*:

```c
int mal_routing_register_provider_send_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_send);

int mal_routing_register_provider_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_submit);

int mal_routing_register_consumer_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack);

int mal_routing_register_provider_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_request);

int mal_routing_register_consumer_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_invoke);

int mal_routing_register_consumer_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_progress);

int mal_routing_register_consumer_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_update,
    mal_routing_on_message_fn *on_response);
```

L'interface also offers three functions to register *publisher*, *subscriber* and *broker* handlers for *Publish/Subscribe* interaction:

```c
int mal_routing_register_provider_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_publish_error,
    mal_routing_on_message_fn *on_publish_register_ack,
    mal_routing_on_message_fn *on_publish_deregister_ack);

int mal_routing_register_consumer_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_register_ack,
    mal_routing_on_message_fn *on_deregister_ack,
    mal_routing_on_message_fn *on_notify);

int mal_routing_register_broker_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_notify_error,
    mal_routing_on_message_fn *on_register,
    mal_routing_on_message_fn *on_deregister,
    mal_routing_on_message_fn *on_publish);
```

Finally, the interface also provides a function to deregister a *handler*:

```c
int mal_routing_remove_handler(
    mal_routing_t *mal_routing,
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation);
```

### Handlers execution

The *router* interface provides a function to activate the rigth handler when receiving a MAL message.
When called this function search the right handler in the list of registered handlers. If successful it
activates the handler by calling the function corresponding to the received message. The destroying of the
incoming message is then the responsability of this handler.

Declaration:

```c
int mal_routing_handle(mal_routing_t *self, mal_message_t *message);
```

Parameters:

  - `self`: A pointer to the *router*.
  - `message`: A pointer to the received message.

### Destructor

Deletes the *router* and its state.

```c
void mal_routing_destroy(mal_routing_t **self_p);
```

Element union
-------------

A `mal_element_t`  union is defined to allow the polymorphism of *Element*.

```c
union mal_element_t {
  mal_blob_t *blob_value;
  mal_boolean_t boolean_value;
  mal_double_t double_value;
  mal_float_t float_value;
  mal_octet_t octet_value;
  mal_uoctet_t uoctet_value;
  mal_short_t short_value;
  mal_ushort_t ushort_value;
  mal_integer_t integer_value;
  mal_uinteger_t uinteger_value;
  mal_long_t long_value;
  mal_ulong_t ulong_value;
  mal_string_t *string_value;
  mal_identifier_t *identifier_value;
  mal_uri_t *uri_value;
  mal_time_t time_value;
  mal_finetime_t finetime_value;
  mal_duration_t duration_value;
  int enumerated_value;
  void *composite_value;
  void *list_value;
};
```

Element holder
--------------

This structure allows to manage the decoding in case of element polymorphism.

### Constructor

Declaration:

```c
mal_element_holder_t *mal_element_holder_new(void);
```

### Getters et setters

Declaration:

```c
bool mal_element_holder_get_presence_flag(mal_element_holder_t *self);

void mal_element_holder_set_presence_flag(mal_element_holder_t *self,
  bool presence_flag);

long mal_element_holder_get_short_form(mal_element_holder_t *self);

void mal_element_holder_set_short_form(mal_element_holder_t *self,
  long short_form);

union mal_element_t mal_element_holder_get_value(
  mal_element_holder_t *self);

void mal_element_holder_set_value(mal_element_holder_t *self,
  union mal_element_t value);
```

### Destructor

This destructor frees only space allocated for the structure itself, not the union elements.

Declaration:

```c
void mal_element_holder_destroy(mal_element_holder_t **self_p);
```

List of non-pointer attribute
-----------------------------

Data structures defined to represent lists of *attribute* types which are not represented by a *C* pointer
(see section 2.6). These lists are specific to each type of non-pointer *Attribute*.
For each list, two tables are defined:

  - `presence_flags`: Table of presence flags for each of the items in the list.
  - `content`: Table containing the values of each item of the list; if an item is null, its value in the
  table can be assigned with any value.

The size of `presence_flags` and `content` tables should be the same.

### Constructor

Declaration:

```c
mal_<attribute>_list_t *mal_<attribute>_list_new(
  unsigned int element_count);
```

Parameters:

  - `element_count`: Number of items in the list.

### Getter

Getter functions are defined to access the fields:

```c
unsigned int mal_<attribute>_list_get_element_count(
  mal_<attribute>_list_t *self);

bool *mal_<attribute>_list_get_presence_flags(
  mal_<attribute>_list_t *self);

mal_<attribute>_t *mal_<attribute>_list_get_content(
  mal_<attribute>_list_t *self);
```

### Destructor

Deletes the list and its contents (`presence_flags` and `content` tables).

Declaration:

```c
void mal_<attribute>_list_destroy(mal_<attribute>_list_t **self_p);
```

List of pointer attribute
-------------------------

Data structures defined to represent lists of *attribute* types which are represented by a *C* pointer
(see section 2.6).

### Constructor

Declaration:

```c
mal_<attribute>_list_t *mal_<attribute>_list_new(
  unsigned int element_count);
```

Parameters:

  - `element_count`: Number of items in the list.

### Getters

Getter functions are defined to access the fields:

```c
unsigned int mal_<attribute>_list_get_element_count(
  mal_<attribute>_list_t *self);

mal_<attribute>_t **mal_<attribute>_list_get_content(
  mal_<attribute>_list_t *self);
```

### Destructor

Deletes the list, its contents (pointers table) and the list items.

Declaration:

```c
void mal_<attribute>_list_destroy(mal_<attribute>_list_t **self_p);
```

List of Composite
-----------------
Cf section 9.6.

List of Enumerated
------------------
Cf section 9.7.

Interaction stage
-----------------

A constant is defined for each stage of each interaction:

```c
#define MAL_IP_STAGE_SEND 1
#define MAL_IP_STAGE_SUBMIT 1
#define MAL_IP_STAGE_SUBMIT_ACK 2
#define MAL_IP_STAGE_REQUEST 1
#define MAL_IP_STAGE_REQUEST_RESPONSE 2
#define MAL_IP_STAGE_INVOKE 1
#define MAL_IP_STAGE_INVOKE_ACK 2
#define MAL_IP_STAGE_INVOKE_RESPONSE 3
#define MAL_IP_STAGE_PROGRESS 1
#define MAL_IP_STAGE_PROGRESS_ACK 2
#define MAL_IP_STAGE_PROGRESS_UPDATE 3
#define MAL_IP_STAGE_PROGRESS_RESPONSE 4
#define MAL_IP_STAGE_PUBSUB_REGISTER 1
#define MAL_IP_STAGE_PUBSUB_REGISTER_ACK 2
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER 3
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK 4
#define MAL_IP_STAGE_PUBSUB_PUBLISH 5
#define MAL_IP_STAGE_PUBSUB_NOTIFY 6
#define MAL_IP_STAGE_PUBSUB_DEREGISTER 7
#define MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK 8
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER 9
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK 10
```
