MAL C API and MAL/CZMQ transport
================================


Introduction
============

This C API represents all MAL concepts, especially the interaction patterns, the MAL message format and the data model. The main goal of this API is to offer a simplified version of the Java MAL API functions. The inherent complexity of MAL standard must be maintained. However, more complex aspects of the Java MAL API can be simplified or abandoned, either because they are not essential, either because they are related to different designs choice (eg Remote Procedure Call oriented approach), or because they can be improved (eg the high dependence between transport and encoding).

The following elements of complexity are inherent to the MAL standard, they must be kept:

  - Separation of transport functions, encoding and access control: multiple APIs and abstract functions
  - Complex interaction patterns: *Invoke*, *Progress*, *Publish-Subscribe*
  - Polymorphism of MAL component, limited to the last element of a message body
  - Polymorphism of MAL attribute
  - Inheritance of structure

Polymorphism of MAL element
---------------------------
The MAL specification allows the use of polymorphism for MAL `Element` if it is applied at the last item of a message body. It can be used with the following types:

  -	`MAL::Element`
  -	an abstract `Composite`
  -	a list of `MAL::Element` items
  -	a list of abstract `Composite` items
  -	a list of `MAL::Attribute` items

The types listed above are reserved for polymorphism of the last item of a message body. They can not be used for a composite field.

The lists of abstract type items (`Composite`, `MAL::Element` or `MAL::Attribute`) can not be instantiated: there is no structure of list that may contain items of abstract type (and thus items of several types conform to this abstract type). For example :

  -	`List<MAL::Element>`, `List<MAL::Attribute>` cannot be instantiated
  -	`List<MAL::UpdateHeader>`, `List<MAL::Boolean>` can be instantiated

Accordingly, a list structure only contain elements of the same type and none of abstract type.

Polymorphism of MAL Attribute
-----------------------------
The MAL specification allows the use of polymorphism for MAL `Attribute` it it is applied to the last item of a message body and for `Composite` field.
The `Attribute` polymorphism consist to declare an element or field with the type `MAL::Attribute`.

Concepts
========

Most concepts of MAL C API are imposed by the MAL specification: MAL message, header fields, data types. However, the MAL specification does not define some concepts that are specific to the implementation of this specification. This section presents only those concepts.

End-Point
---------
The MAL End-Point is the entity that allows to send and receive MAL messages. Each end-point is related to a single URI of MAL service, the MAL C API enables the dynamic creation and removal of end-points.

Only the end-point which received the message initiating an interaction can answer to this interaction.

An end-point has the following features:

  -	It can only use a unique transport (binding) to receive and send MAL messages.
  -	It can use multiple encoding formats for the MAL message body.
  -	It is uniquely identified by a MAL URI relative to the MAL context, the URI format depends on the transport used.
  -	It must be run in single-threaded way.
  -	It manages a `Transaction Id` counter (MAL header field).

Poller
------
The MAL Poller is an entity that allows to await the arrival of a message across multiple end-points. The MAL C API enables the dynamic creation and deletion of pollers, adding and removing end-point to the poller.

A Poller has the following features:

  -	All the end-points of a poller must depend on a single MAL context and thus a single transport (binding).
  -	It must be run in single-threaded way.

The use of MAL Poller is not mandatory, it is useful in different cases:

  -	management of multiple end-points through a single execution flow,
  -	non-blocking message reception.

Handler and routing
-------------------
These concepts are provided in order to facilitate the distribution of MAL messages received for processing functions, their use is optional.

A MAL Handler is an interaction processor, it runs asynchronously when it is notified of an incoming MAL message, and in return it sends zero, one or more MAL messages, either to initiate new interactions (consumer role) or to reply to the current interaction (provider role).

Each handler has an interface that depends on its role (provider, consumer, etc.) and interaction in which it operates (send, submit, etc.). For example for a Progress interaction:

  -	The provider handler must provide the function: `on_progress`
  -	The consumer handler must provide the functions: `on_ack`, `on_update` and `on_response`.

Each of these functions is called with the following parameters:

  -	a pointer to the Router state (cf 7.6),
  -	a pointer to the MAL Context (cf 7.2),
  -	a pointer to the MAL End-Point (cf 7.4),
  -	and a pointer to the MAL message (cf 7.3).

The MAL C API provides a helper class (mal-routing) that simplifies the management of handlers for a particular end-point. This class allows to register the handlers corresponding to expected interactions, and then upon receipt of a message by the end-point to activate the corresponding handler to process the message.

The routers have a state shared by all the handlers they manage.

MAL Broker
----------
In our implementation of MAC/CZMQ transport the Publish/Subscribe is partially supported by the MAC/CZMQ transport through the ZMQ PUB/SUB sockets. In order to respect the semantics of MAL Publish/Subscribe pattern it is however necessary to implement a Broker component to manage subscriptions and message filtering.

To comply with the functioning of ZMQ, this broker component will be located Consumer side. Currently it operates as a special Handler (section 2.3) that the user can change or replace.

URI Transformation
------------------
ZMQ can use multiple underlying protocols to communicate. For example point-to-point communications may pass through TCP between different machines process, IPC between processes on the same machine or internal mechanisms within the same process. Similarly, the Publish/Subscribe pattern can be implemented through TCP, PGM or EPGM.

MAL/ZMQ transport uses various communication streams according interactions, in our prototype each MAL context is listening on 2 different sockets:

  - A `DEALER` socket for point-to-point communications,
  - A `SUB` socket for multicats communications.

To ensure the transformation of the MAL URI of a service in the ZMQ URI needed to achieve an interaction we have chosen to outsource this transformation through upcalls (section 12.2.1). This provides a greater freedom of configuration to the user.

Pointer attributes
------------------
Pointer attributes are MAL attributes whose representation in C is a pointer type: `MAL::Blob`, `MAL::Identifier`, `MAL::String` and `MAL::URI`.

For these attributes the `NULL` value (null pointer) is allowed. For other attributes, the null value is represented by an additional boolean field called "presence flag".

Overview of the MAL C API
=========================

The MAL C API consists of several APIs:

  -	**MAL attribute API** : The MAL attributes are extracted from the MAL API to avoid a circular dependency bween MAL API (which depends on the encoding APIs) and encoding APIs (which depends of MAL attributes).
  -	**Encoding APIs** : Encoding APIs are specifically defined for each encoding format.
  -	**MAL API** : The MAL API allows the use of MAL level concepts.
  - **Area APIs** (generated) : The MAL API contains the Area API generated from the definition of the MAL Area.
  -	**Transport APIs** : which manages the mapping of MAL concepts to the underlying concepts of transport chosen.
  -	**Extraction API for configuration paramters**.

Most concepts are each represented by a class that conforms to the zproject Class model:

  -	an opaque structure (only the type is visible and not the content) declared in the main header file of the API (`<api>.h`)
  -	an include file: `<classname>.h`
  -	a source file: `<classname>.c`

Class names are lowercase, with '\_' separator, and prefixed by the API name. For example, the concept of end-point, defined in the API MAL, is represented by a class named: `mal_endpoint`.

The names of the classes representing data types are prefixed by the names of their Area and their service (if available). For example, the type `MAL::Blob` (defined in the area MAL without intermediate Service) is named: `mal_blob`.

Other conventions are conform to the zproject *Class* model.


