MAL/ZMQ Transport
=================

This section describes the implementation of MAL binding to ZMTP transport on CZMQ API.
It is not a description as protocol terms (see the *Mission Operations - MAL binding to ZMTP* CCSDS book) but as API.

The encoding format of the MAL header is given in the *Mission Operations - MAL binding to ZMTP* CCSDS book.

Currently a MAL message is transmit in a single ZMQ frame (zframe).

The following sections describe the implementation of the MAL / CZMQ module:

	-  MALZMQ header configuration.
	-  MALZMQ context constructor.
	-  Boot.
	-  MAL message reception.
	-  Implementation of virtual functions needed by the MAL API.

MALZMQ Header
-------------

A class is defined to handle the specificities of MALZMQ header format:

	-  MALZMQ version number.
	-  Mapping directory.
	-  Presence flags for optional MALZMQ header fields.
	-  Value of non-present fields.

###	Constructor

```c
malzmq_header_t *malzmq_header_new(
  malzmq_mapping_directory_t *mapping_directory,
  bool priority_flag, mal_uinteger_t priority,
  bool timestamp_flag, mal_identifier_t *network_zone,
  mal_identifier_t *session_name, mal_identifier_list_t *domain,
  mal_blob_t *authentication_id);
```

Parameters

	-  `mapping_directory`: Mapping directory to use by encoding, may be null.
	-  `priority_flag`: Boolean indicating the presence of the *Priority* field in the MALZMQ header.
	-  `priority`: Value of the *Priority* field if it is not present in the MALZMQ header.
	-  `timestamp_flag`: Boolean indicating the presence of the *TimeStamp* field in the MALZMQ header.
	-  `network_zone`: Value of the *Network Zone* field if it is not present in the MALZMQ header.
        If NULL the *Network Zone* field should be present in the MALZMQ header.
	-  `session_name`: Value of the *Session Name* field if it is not present in the MALZMQ header.
        If NULL the *Session Name* field should be present in the MALZMQ header.
	-  `domain`: Value of the *Domain* field if it is not present in the MALZMQ header.
        If NULL the *Domain* field should be present in the MALZMQ header.
	-  `authentication_id`: Value of the *Authentication Id* field if it is not present in the MALZMQ header.
        If NULL the *Authentication Id* field should be present in the MALZMQ header.

###	Configuration parameters

Some MAL header fields can be always identical for a given application.
Transmit their values with each call would be redundant, and thus we can optimize performance by
omitting them in the MALZMQ header. These fields are: `PRIORITY`, `NETWORK_ZONE`, `SESSION_NAME`,
`DOMAIN`, `AUTHENTICATION_ID`. The presence of these fields in the header MALZMQ and their potential
overall value is defined in the MALZMQ header constructor.

Another field of the MAL header, `TIMESTAMP`, can also be omitted in the header MALZMQ. This possible
omission is also defined in the MALZMQ header constructor. There is no replacement value defined for this
field.

It goes without saying that these configuration parameters must be provided in an identical manner to all
entities of the application.

### Internal broker

The MALZMQ transport allow to use the multicast capabilities od ZMQ to implement an internal broker.
If needed the user shall call the malzmq_header_enable_internal_broker function with true parameter to
indicate this choice.

```c
void malzmq_header_enable_internal_broker(malzmq_header_t *self, bool internal_broker);
```

By default this mechanism is off and an external broker shall be used.

###	Mapping directory

The MAL message header contains several fields whose size can be important: URIs, strings, etc.
To optimize the performance messages exchanged between instances of MAL/CZMQ can contain fields encoded
in smaller scalar types.

To maintain compatibility with the MAL, these encoded fields are systematically converted into their MAL
equivalent when accessed by the user of the MAL API. To allow this transformation, informations must be
maintained in a directory on both sides (consumer and provider).

The purpose of this section is to describe the corresponding API and its use.

#### Principles

The mapping directiry maintains a mapping between strings and numeric values. The numerical value is called
`MDK` for *Mapping Key Directory*.

The directory allows to find the MDK corresponding to a given string during encoding, and to find the string
corresponding to a  MDK during decoding.

It is not under the responsibility of the MAL/CZMQ to provide a consistent directory to each side of the
interaction. This responsibility relies to the application. The simplest way to achieve this is to provide
a static catalog to all components during the installation of the the application. However, nothing prevents
an application to provide a more dynamic implementation of the directory.

#### Encoding

The encoding of a string under his MDK form is optional, to handle the case where there is no MDK in the
directory for the string to be encoded. This is why the mapping described in 14.3 refers to a type `Optional MDK`.

The principle of `Optional MDK` encoding is derived from the String `MAL Binary` encoding. This encoding
consists normally in the encoding of the string length (typed `UInteger`), followed by the encoding of the characters
themselves. The `Optional MDK` encoding converts the 32 bit length field in an Integer value to separately exploit
the sign and the absolute value. The sign describes the nature of the field represented by the absolute value,
a *MDK* if the sign is negative, or length if the sign is positive. In the second case the characters are encoded after
the length field as in `MAL Binary` encoding.

An encoded string in its MDK form therefore requires only 4 bytes, representing the negative value of the MDK.
If it is not encoded in its MDK form a chain complies with its `MAL Binary` encoding form.

The special case of a zero value for the initial Integer corresponds to the `MAL Binary` encoding of an empty
string. Consequently an MDK must be strictly positive.

#### API

The directory mapping, typed `malzmq_mapping_directory_t`, is provided as a functions table.

```c
typedef struct _malzmq_mapping_directory_t malzmq_mapping_directory_t;
struct _malzmq_mapping_directory_t {
  malzmq_md_get_key_fn *get_key_fn;
  malzmq_md_get_string_fn *get_string_fn;
  malzmq_md_put_string_fn *put_string_fn;
};
```

Fields:

	- `get_key_fn`: Gets the MDK of a string if it exists in the directory.
	- `get_string_fn`: Gets the string corresponding to an MDK.
	- `put_string_fn`: Adds a string in the directory and return the corresponding MDK.

Below the detailed interface of these functions.

```c
typedef int malzmq_md_get_key_fn(char *string, unsigned int *key);
```

Parameters

        - `string`: String to search for a possible key correspondence. Should not be null.
        - `key`: return value of the matching MDK for the string, if it exists.

Result:

        - 0: execution valid, the return key can be used.
        - <0: error code, the key parameter is undefined.

```c
typedef int malzmq_md_get_string_fn(unsigned int key, char **string);
```

Parameters

        - `key`: MDK to search for a possible string correspondence.
        - `string`: return value of the matching string for the MDK, if it exists.
         This string is allocated and should be released by free or various specific functions (mal_string_destroy, etc).

Result:

        - 0: execution valid, the return string can be used.
        - <0: error code, the string parameter is undefined.

```c
typedef int malzmq_md_put_string_fn(char *string, unsigned int *key);
```

Parameters

        - `string`: string for which we want to create a matching key, should not be null.
         The directory must not retain the string beyond this call to allow the caller to release it if necessary.
        - `key`: return value of the matching MDK for the string. Must be strictly positive and strictly less
        than 231. A distinctive value is created if and only if an existing MDK does not exist for this string
        in the directory.

Result:

        - 0: execution valid, the return key can be used.
        - <0: error code, the string is not registered in the directory and the key parameter is undefined.

Note:

The directory functions only work on strings (char *), because the different target types `mal_string_t`,
`mal_uri_t` and `mal_identifier_t`, are themselves defined as `char*`. Otherwise, the catalog should 
provide distinct functions for each of these types.

####	Usage

The directory is currently used only for the following header fields: *URI from*, *URI to*, *Network Zone*,
*Session Name* and *Domain*.

Using explicitly the directory for selected fields of the body is also possible, but it would break the current
compliance to the MAL binary encoding format of the body.

MALZMQ context constructor
--------------------------

```c
malzmq_ctx_t *malzmq_ctx_new(
  mal_ctx_t *mal_ctx,
  malzmq_mapping_uri_t *mapping_uri,
  char *hostname, char *port, malzmq_header_t *malzmq_header,
  malbinary_encoder_t *encoder, malbinary_decoder_t *decoder,
  bool verbose);
```

Parameters

        - `mal_ctx`: MAL context.
        - `mapping_uri`: Processing fonctions to transform MAL URI in ZMQ URI. If this mapping is null, the
        default URI mapping functions are used.
        - `hostname`: IP address used to listen incoming connections.
        - `port`: port used to listen incoming connections.
        - `malzmq_header`: Flags and optional fields. The configuration of the MALZMQ header is global to the
        MALZMQ context.
        - `encoder`: Encoding context used to encode the MAL headers.
        - `decoder`: Decoding context used to decode the MAL headers.
        - `verbose`: Flag allowing to enable/disable the logging traces.

The constructor performs the following actions:
  
        - Creating a ZMQ ROUTER socket for accepting connections initiated by other remote MALZMQ
        contexts: `SOCKET_MAL_ROUTER`. The ZMQ URI used is built from `hostname` and `port` parameters,
        and the URI mapping functions.
        - Creating a ZMQ SUB socket for accepting messages published by other remote MALZMQ contexts: 
        `SOCKET_MAL_SUB`. The ZMQ URI used is built from `hostname` and `port` parameters, and the URI
        mapping functions.
        - Creating an `inproc` ZMQ ROUTER socket for communicating with the services registered in the
        context: `SOCKET_Z_ROUTER`.
        - Creating a `zloop` to handle the message routing between the external MALZMQ contexts
        and the internal services.

###	URI mapping functions

Associated with each service (and MAL URI) there may be two ZMTP URIs corresponding to different
communication modes, one URI for point-to-point channel and another used for multicast channel.
The mapping between the MAL URI of a service and the ZMTP URIs is ensured by 4 configuration functions
provided by the user:

        - ‘get_local_p2p_ztmp_uri’ takes in parameter the MAL URI of the service and
        returns the ZMTP URI needed to bind the ZMQ ROUTER listening socket corresponding
        to the MAL context. This ZMQ socket will be used to receive messages during
        point-to-point interactions. For example calling this function with
        `malzmtp://host:port/service` MAL URI returns `tcp://*:port` ZMTP URI.
        - ‘get_local_mcast_ztmp_uri’ takes in parameter the MAL URI of the service and returns
        the ZMQ URI to bind the ZMQ SUB listening socket corresponding to the MAL context.
        This socket will be used to receive messages during multicast interactions. If it returns
        NULL the multicast channel is not used by the ZMTP transport. For example calling this
        function with `malzmtp://host:port/service` MAL URI returns `tcp://host:(port+1)` or
        `pgm://itf;mcast_addr:(port+1)` ZMTP URI.
        - ‘get_remote_ptp_zmtp_uri’ accepts in parameters the MAL header fields ‘URI To’ of a
        message and returns the ZMTP URI of the remote socket to send the message through the
        point-to-point channel. It needs a ZMQ DEALER socket connected to this URI. For example
        calling this function with `malztp://host1:port1/service` MAL URI returns `tcp://host1:port1`
        ZMTP URI.
        - ‘get_remote_mcast_zmtp_uri’ accepts in parameters the MAL header fields ‘URI To’ of
        the message and returns the ZMTP URI of the remote socket to send the message through
        the multicast channel. It needs PUB ZMTP socket connected to this URI. If it returns NULL
        the multicast channel is not used by the ZMTP transport. For example calling this function
        with `malztp://host1:port1/service` MAL URI returns `tcp://*:(port1+1)` or
        `epgm://itf;mcast_addr:(port+1)` ZMTP URI.

Functions for mapping MAL URI to ZMQ URI are given to the MALZMQ context through the malzmq_mapping_uri_t structure. If this
parameter is null the default functions defined in the MALZMQ transport are used; these functions consider that TCP is used for
all interactions and the port used for Publish/Subscribe interaction is the service port +1.

```c
typedef mal_uri_t *malzmq_get_local_ptp_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_local_mcast_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_remote_ptp_zmtp_uri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_remote_mcast_zmtp_uri_fn(mal_uri_t *maluri);

typedef struct _malzmq_mapping_uri_t malzmq_mapping_uri_t;

struct _malzmq_mapping_uri_t {
  malzmq_get_local_ptp_zmtp_uri_fn *get_local_ptp_zmtp_uri;
  malzmq_get_local_mcast_zmtp_uri_fn *get_local_mcast_zmtp_uri;
  malzmq_get_remote_ptp_zmtp_uri_fn *get_remote_ptp_zmtp_uri;
  malzmq_get_remote_mcast_zmtp_uri_fn *get_remote_mcast_zmtp_uri;
};
```

###	Default mapping

The default mapping implemented in the POC for MALZMQ transport uses TCP communications for both Point-to-Point and
Publish/Subscribe:

        - `get_local_ptp_zmtp_uri`: for `malzmq://host:port/service` it returns `tcp://*:port`.
        - `get_local_mcast_zmtp_uri`: for `malzmq://host:port/service` it returns `tcp://*:port_ps`
        with `port_ps=port+1`.
        - `get_remote_ptp_zmtp_uri`: for `malzmq://host1:port1/service` it returns `tcp://host1:port1`.
        - `get_remote_mcast_zmtp_uri`: for `malzmq://host1:port1/service it returns `tcp://host1:port1_ps`
        with `port1_ps=port1+1`

Start-up
--------

The following function will start the MALZMQ context. This function starts the zloop and blocks as the
zloop did not complete.

```c
int malzmq_ctx_start(malzmq_ctx_t *self);
```

zloop behavior
--------------

The zloop listens (`SOCKET_MAL_ROUTER` and `SOCKET_MAL_SUB`) to the messages sent by remote MALZMQ
contexts. When ZMQ message is received, the following actions are performed:

        - Gets and destroy of the first frame containing the identity of the caller (currently, the ZMQ
        connections are only used in one direction, therefore the identity of the caller is not retained).
        - The next frame is not extracted (zmsg_pop) from the ZMQ message, but only read (zmsg_next)
        enabling to send this ZMQ message to the recipient endpoint.
        - Only the `URI To` field is decoded, this field identifies the inproc `DEALER` socket used by the
        recipient endpoint.
        - The ZMQ message is forwarded to the recipient endpoint through the inproc `SOCKET_ACTOR_ROUTER`.

Message receiving
-----------------

When a MAL endpoint asks for receiving a message, the MALZMQ transport listens on the corrsponding ZMQ DEALER socket
connected to the ZMQ ROUTER socket of the zloop.

When receiving a MAL message the following actions are performed:

        - The unique frame of the ZMQ message is extracted.
        - A `mal_message` structure is instanciated.
        - The MAL header fields are decoded using MAL Binary encoding. The optional unencoded fields are set 
        using the global MALZMQ configuration header.
        - The MAL message body is directly set from the ZMQ frame (`data` field of `zframe`) without copy. 
        Consequently, the ZMQ frame can only be destroyed at the time of the destruction of MAL message. The
         `body_owner` field of the message is affected with the MAL ZMQ frame.
        - The built message is returned to the caller, the destruction of the MAL message is the responsibility
        of the handler of this message.

Virtual function to build URI
-----------------------------

The URI format is:

```c
malzmq://<hostname>:<port>/<id>
```

The underlying transport protocol used by ZMQ is not specified in the URI. It is specified in the creation of MALZMQ context.

In some cases, the MALZMQ context could optimize communication using a more efficient transport protocol, for example:

        - `ipc`: if both consumer and provider are on the same host.
        - `inproc`: if both consumer and provider are in the same process. Be careful in this case to the 
        starting order as *inproc* does not ensure the temporal decoupling for ZMQ sockets.

This optimization is not currently implemented in the prototype.

Virtual function to create an endpoint
--------------------------------------

A MALZMQ endpoint is created and returned as an untyped pointer `void *`.

Specific MALZMQ endpoint datas are:

        - the MALZMQ context,
        - the corresponding MAL endpoint,
        - the listening inproc ZMQ DEALER socket used to receive forwarded messages from the zloop,
        - an hashtable containing the ZMQ sockets open to the remote MALZMQ contexts.

During the initialization of the endpoint, the following actions are performed:

        - creating a ZMQ DEALER socket,
        - registering this socket identity with the endpoint URI,
        - connection of this DEALER socket with the ROUTER socket handled by the zloop (ZLOOP_ENDPOINTS_SOCKET_URI)

Virtual function to send a message
----------------------------------

The message's MAL URI is converted into a ZMQ URI:

        - MAL URI format: `malzmq://<hostname>:<port>/<id>`
        - ZMQ URI format: `<protocole zmq>://<hostname>:<port>`

A ZMQ DEALER socket connected to this URI is searched in the hashtable owned by the endpoint. If the socket is not
found then a new one is created and registered in the table (the key is the ZMQ URI).

The MAL message is encoded and transmitted in a single frame ZMQ.

Virtual function to create a poller
-----------------------------------

A MALZMQ poller is created and returned as an untyped pointer `void *`.

Specific MALZMQ poller datas are:

        - the MALZMQ context,
        - the corresponding MAL poller,
        - the ZMQ zpoller listening on sockets of endpoints,
        - the list of endpoints associated to this poller.

During the initialization of the poller, the following actions are performed:

        - creation of a ZMQ zpoller,
        - creation ofn empty list of endpoints.


Virtual function to add an endpoint to a poller
-----------------------------------------------

This function adds to the poller the endpoint in parameter. The end-point is added to the list of
endpoints, the corresponding socket is added to the zpoller.

Virtual function to remove an endpoint to a poller
--------------------------------------------------

This function removes from the poller the endpoint in parameter. The end-point is removed from the
list of poller, the corresponding socket is removed from the zpoller.

Virtual function to wait a message on a poller
----------------------------------------------

This function waits to receive a message on the associated zpoller.

If a message arrives before the timeout expiration the corresponding endpoint is searched in the
list of endpoints and is returned in the corresponding parameter. If there is no matching endpoint
registered an error is returned.

Virtual function to delete a message
------------------------------------

This function checks if the `body_owner` message field MAL is set. In this case, it means that the
MAL message was created (decoded) from a ZMQ frame (`zframe`) and must be destroyed (`zframe_destroy`).
