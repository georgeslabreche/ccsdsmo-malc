MAL/TCP Transport
=================

This section describes the implementation of MAL binding to ZMTP transport on CZMQ API.
It is not a description as protocol terms (see the *Mission Operations - MAL binding to TCP/IP and Split-Binary enncoding*
CCSDS book) but as API.

The encoding format of the MAL header is given in the *Mission Operations - MAL binding to TCP/IP and Split-Binary enncoding*
CCSDS book.

A MAL message is transmit in a continous flow of bytes on a TCP connection.

The following sections describe the implementation of the MAL/TCP module:

	-  MALTCP header configuration.
	-  MALTCP context constructor.
	-  Boot.
	-  MAL message reception.
	-  Implementation of virtual functions needed by the MAL API.

MALTCP Header
-------------

A class is defined to handle the specificities of MALTCP header format:

	-  MALTCP version number.
	-  Presence flags for optional MALTCP header fields.
	-  Value of non-present fields.

###	Constructor

```c
maltcp_header_t *maltcp_header_new(
  bool priority_flag, mal_uinteger_t priority,
  bool timestamp_flag, mal_identifier_t *network_zone,
  mal_identifier_t *session_name, mal_identifier_list_t *domain,
  mal_blob_t *authentication_id);
```

Parameters

	-  `priority_flag`: Boolean indicating the presence of the *Priority* field in the MALTCP header.
	-  `priority`: Value of the *Priority* field if it is not present in the MALTCP header.
	-  `timestamp_flag`: Boolean indicating the presence of the *TimeStamp* field in the MALTCP header.
	-  `network_zone`: Value of the *Network Zone* field if it is not present in the MALTCP header.
        If NULL the *Network Zone* field should be present in the MALTCP header.
	-  `session_name`: Value of the *Session Name* field if it is not present in the MALTCP header.
        If NULL the *Session Name* field should be present in the MALTCP header.
	-  `domain`: Value of the *Domain* field if it is not present in the MALTCP header.
        If NULL the *Domain* field should be present in the MALTCP header.
	-  `authentication_id`: Value of the *Authentication Id* field if it is not present in the MALTCP header.
        If NULL the *Authentication Id* field should be present in the MALTCP header.

###	Configuration parameters

Some MAL header fields can be always identical for a given application.
Transmit their values with each call would be redundant, and thus we can optimize performance by
omitting them in the MALTCP header. These fields are: `PRIORITY`, `NETWORK_ZONE`, `SESSION_NAME`,
`DOMAIN`, `AUTHENTICATION_ID`. The presence of these fields in the header MALTCP and their potential
overall value is defined in the MALTCP header constructor.

Another field of the MAL header, `TIMESTAMP`, can also be omitted in the header MALTCP. This possible
omission is also defined in the MALTCP header constructor. There is no replacement value defined for this
field.

It goes without saying that these configuration parameters must be provided in an identical manner to all
entities of the application.

MALTCP context constructor
--------------------------

```c
maltcp_ctx_t *maltcp_ctx_new(
  mal_ctx_t *mal_ctx,
  char *hostname, char *port,
  maltcp_header_t *maltcp_header,
  bool verbose);
```

Parameters

        - `mal_ctx`: MAL context.
        - `hostname`: IP address used to listen incoming connections.
        - `port`: port used to listen incoming connections.
        - `maltcp_header`: Flags and optional fields. The configuration of the MALTCP header is global to the
        MALTCP context.
        - `verbose`: Flag allowing to enable/disable the logging traces.

The constructor performs the following actions:
  
        - Creating a TCP listen socket for accepting connections initiated by other remote MALTCP
        contexts. The listen socket is bound to an address corresponding to `hostname` and `port`
        parameters.
        - Creating an `inproc` ZMQ ROUTER socket for communicating with the services registered in the
        context: `SOCKET_Z_ROUTER`.
        - Creating a `zloop` to handle the message routing between the external MALTCP contexts
        and the internal services.

Start-up
--------

The following function will start the MALTCP context. This function starts the zloop and blocks as the
zloop did not complete.

```c
int maltcp_ctx_start(maltcp_ctx_t *self);
```

zloop behavior
--------------

The zloop listens for TCP connections and messages from remote MALTCP contexts.
When a TCP connection is initiated, the following actions are performed (see maltcp_ctx_socket_accept handler):

        - The connection is accepted and the resulting socket is added to the poller list
        of the zloop.

When a message is received, the following actions are performed (see maltcp_ctx_socket_receive):

        - Get the hostname and port information from the TCP/IP layer.
        - Read the fixed length part of the header (23 bytes, up to the length field).
        - Fully read the message.
        - Extract the destination URI and forward the message to the recipient endpoint. The peer URI is
        also sent in order to complete the from URI if necessary.
        - The message is forwarded to the recipient endpoint through the inproc `SOCKET_ACTOR_ROUTER`.

Message receiving (End-Point)
-----------------------------

When a MAL endpoint asks for receiving a message, the MALTCP transport listens on the corrsponding ZMQ DEALER socket
connected to the ZMQ ROUTER socket of the zloop (see maltcp_ctx_recv_message handler).

When receiving a MAL message the following actions are performed:

        - The first frame of the ZMQ message is extracted, it contains the peer URI of the MAL message.
        - The second frame of the ZMQ message is extracted, it contains the MAL message.
        - A `mal_message` structure is instanciated.
        - The MAL header fields are decoded using MAL Binary encoding.
        - The MAL message body is directly set from the ZMQ frame (`data` field of `zframe`) without copy. 
        Consequently, the ZMQ frame can only be destroyed at the time of the destruction of MAL message. The
         `body_owner` field of the message is affected with the MAL ZMQ frame.
        - The built message is returned to the caller, the destruction of the MAL message is the responsibility
        of the handler of this message.

Virtual function to build URI
-----------------------------

The URI format is:

```c
maltcp://<hostname>:<port>/<id>
```

Virtual function to create an endpoint
--------------------------------------

A MALTCP endpoint is created and returned as an untyped pointer `void *`.

Specific MALTCP endpoint datas are:

        - the MALTCP context,
        - the corresponding MAL endpoint,
        - the listening inproc ZMQ DEALER socket used to receive forwarded messages from the zloop.

During the initialization of the endpoint, the following actions are performed:

        - creating a ZMQ DEALER socket,
        - registering this socket identity with the endpoint URI,
        - connection of this DEALER socket with the ROUTER socket handled by the zloop (ZLOOP_ENDPOINTS_SOCKET_URI)

Virtual function to send a message
----------------------------------

A TCP/IP socket connected to the destination URI is searched in the hashtable owned by the MALTCP context. If the socket is not
found then a new one is created and registered in the table (the key is the destination base URI).

The MAL message is encoded and transmitted on the corresponding TCP connection.

Virtual function to create a poller
-----------------------------------

A MALTCP poller is created and returned as an untyped pointer `void *`.

Specific MALTCP poller datas are:

        - the MALTCP context,
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
