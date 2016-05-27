Simple example of MAL application
=================================

This section shows the MAL C API concepts through the programming of a very simple application that
runs in a unique process.

Different blocks of code are distinguished:
  -	The code corresponding to the components of the application. In this example, two components are created.
  To simplify the application, each component is limited to a single role: "provider" or "consumer" service.
  A very simple test service is defined in a service area called "TestArea" (see section 14.1).
  -	The initialization code and application launch.

The code of components depends only on MAL C API and APIs generated from the definition of TestArea.

The initialization code and application launch ('main' function) depends on the MAL C API but also on the
transport API 'malzmq'.

This example uses the execution of actors CZMQ model.

Only the non generated code is presented in the following sections.

"consumer" component
--------------------

Include MAL C API definition and API service (generated code):

	#include "mal.h"
	#include "testarea.h"

### Constructor

In this example, all the parameters needed to operate the consumer are given when it was created:

  - The consumer's end-point.
  - The provider's URI (to which the consumer connects).
  - The parameters of the header of MAL message, such as the authentication ID, etc.
  - The identifier of the encoding format.
  - Encoding settings (untyped to avoid dependence 'malbinary').

Declaration:

```c
	simple_app_myconsumer_t *simple_app_myconsumer_new(
	  mal_endpoint_t *endpoint,
	  mal_uri_t *provider_uri,
	  mal_blob_t *authentication_id,
	  mal_qoslevel_t qoslevel,
	  mal_uinteger_t priority,
	  mal_identifier_list_t *domain,
	  mal_identifier_t *network_zone,
	  mal_sessiontype_t session,
	  mal_identifier_t *session_name,
	  int encoding_format_code,
	  void *encoder, void *decoder);
```

### Implementation

In this example a CZMQ actor related to the consumer component initiates a MAL interaction on startup.
The signature must conform to the `main` virtual function of the actor as defined in CZMQ API:

```c
	void simple_app_myconsumer_run(zsock_t *pipe, void *self) {
```

The self parameter is cast to get the state of the actor (the "consumer" object):

```c
	simple_app_myconsumer_t *consumer = (simple_app_myconsumer_t *) self;
```

The provider URI is retrieved from the state of the consumer:

```c
	mal_uri_t *uri_to = consumer->provider_uri;
```

A C data structure `TestComposite` is instantiated:

```c
	testarea_testservice_testcomposite_t *testcomposite =
	  testarea_testservice_testcomposite_new();
```

A MAL string is allocated from the static string "hello world":

```c
	mal_string_t *str = mal_string_new("hello world");
```

The `stringField` field is assigned:

```c
	testarea_testservice_testcomposite_set_stringfield(testcomposite, str);
```

From this point the `TestComposite` structure is responsible for the release of the MAL string str.
Conversely the use of this string is only possible as long as the structure was not released.

The `intField` field may be null. It is therefore necessary to set the presence flag for this field
to true, then assign the value of the field (10):

```c
	testarea_testservice_testcomposite_intfield_set_present(
	  testcomposite,
	  true);
	testarea_testservice_testcomposite_set_intfield(testcomposite, 10);
```

A data structure corresponding to a MAL string list is instantiated and initialized:

```c
	mal_string_list_t *string_list = mal_string_list_new(2);
	mal_string_t **string_list_content =
	  mal_string_list_get_content(string_list);
	string_list_content[0] = mal_string_new("list-element-1");
	string_list_content[1] = mal_string_new("list-element-2");
```

In order to test the polymorphisme, a `TestFinalCompositeA` structure is instantiated.
This structure inherits from `TestAbstractComposite`:

```c
	testarea_testservice_testfinalcompositea_t *testfinalcompositea =
	  testarea_testservice_testfinalcompositea_new();
	testarea_testservice_testfinalcompositea_set_intfield(
	  testfinalcompositea, 20);
	testarea_testservice_testfinalcompositea_set_intfield2(
	  testfinalcompositea, 30);
```

The size of encoded message body is calculated using generated functions for each element of the message body.
A cursor depending of the encoding is created and initialized, this cursor corresponds to a pointer in the encoding
structures and datas. It is used during message size calculation, encoding and decoding.

```c
  malbinary_cursor_t cursor;
  malbinary_cursor_reset(&cursor);
```

Calculation of the encoding size of the first element (index '0' for the initiation of the `send` stage of
the `testSend` operation):

```c
	unsigned int body_length = 0;
	rc = testarea_testservice_testsend_send_add_encoding_length_0(
	  consumer->encoding_format_code,
	  consumer->encoder, testcomposite, &cursor);
```

Calculation of the encoding size of the second element (index '1'):

```c
	rc = testarea_testservice_testsend_send_add_encoding_length_1(
	  consumer->encoding_format_code,
	  consumer->encoder, string_list, &cursor);
```

Calculation of the encoding size of the third element (index '2') with polymorphism:

```c
	rc = testarea_testservice_testsend_send_add_encoding_length_2_testarea_
	testservice_testfinalcompositea(
	  consumer->encoding_format_code,
	  consumer->encoder, testfinalcompositea, &cursor);
```

Creating a MAL message with the following parameters:

  - MAL header fields contained in the statement of Handler.
  - The encoding size of the MAL message body retrieved from the encoding cursor.

```c
	mal_message_t *message = mal_message_new(uri_to,
	  consumer->authentication_id,
	  consumer->qoslevel, consumer->priority, consumer->domain,
	  consumer->network_zone, consumer->session, consumer->session_name,
	  malbinary_cursor_get_body_length(&cursor));
```

Encoding of the first element (index '0'):

```c
	unsigned int Declaration: = mal_message_get_body_offset(message);
	char *bytes = mal_message_get_body(message);
	rc = testarea_testservice_testsend_send_encode_0(
	  consumer->encoding_format_code, &cursor,
	  consumer->encoder, testcomposite);
```

Encoding of the second (index '1'):

```c
	rc = testarea_testservice_testsend_send_encode_1(
	  consumer->encoding_format_code, &cursor,
	  consumer->encoder, string_list);
```

Encoding of the third element (index '3'):

```c
	rc = testarea_testservice_testsend_send_encode_2_testarea_testservice_
	testfinalcompositea(
	  consumer->encoding_format_code, cursor,
	  consumer->encoder, testfinalcompositea);
```

Sending of MAL message (initiation of stage `send` of `testSend` operation):

```c
	rc = testarea_testservice_testsend_send(
	  consumer->endpoint,
	  message,
	  consumer->provider_uri);
```

Releasing of allocated structures:

```c
	testarea_testservice_testcomposite_destroy(&testcomposite);
	mal_string_list_destroy(&string_list);
	testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
```

"provider" component
--------------------

Include MAL C API definition and API service (generated code):

```c
	#include "mal.h"
	#include "testarea.h"
```

### Constructor

In this example, all the parameters needed to operate the provider are given when it was created:

  - The provider's end-point.
  - The identifier of the encoding format.
  - Encoding settings (untyped to avoid dependence 'malbinary').

Declaration:

```c
	simple_app_myprovider_t simple_app_myprovider_new(
	  mal_endpoint_t *endpoint,
	  int encoding_format_code,
	  void *encoder, void *decoder);
```

### Implementation

In this example a CZMQ actor related to the provider registers an interaction handler on startup.
The signature must conform to the `main` virtual function of the actor as defined in CZMQ API:

```c
  void simple_app_myprovider_run(zsock_t *pipe, void *self) {
```

To facilitate the messages routing a MAL router is created:

```c
	mal_routing_t *router = mal_routing_new(self->endpoint, self);
```

Then a handler corresponding to the provider role of a `send` interaction must be registered
dynamically with the router:

```c
	rc = mal_routing_register_provider_send_handler(
	     router,
	     TESTAREA_AREA_NUMBER,
	     TESTAREA_AREA_VERSION,
	     TESTAREA_TESTSERVICE_SERVICE_NUMBER,
	     TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER,
	     simple_app_myprovider_testarea_testservice_testsend);
```

These calls are made in the initialization function of the actor. Finally the actor waits to receive
a message on the corresponding end-point:

```c
	mal_message_t *message = NULL;
	rc = mal_endpoint_recv_message(self->endpoint, &message);
```

Then the actor activates the corresponding handler through the router and destroy this message if it could
not be handled by any handler:

```c
	if (message != NULL) {
	  rc = mal_routing_handle(router, message);
	  if (rc != 0)
	    mal_message_destroy(
	      message,
	      mal_endpoint_get_mal_ctx(self->endpoint));
```

The handler can then react to the received MAL message MAL through the
`simple_app_myprovider_testarea_testservice_testsend` function whose signature must conform
to the virtual function defined in the MAL Handler API (see Section 7.6.1).
The dispatch code thus refers to a specific function in the processing of the operation 'testSend':

```c
	int simple_app_myprovider_testarea_testservice_testsend(
	  void *self,
	  mal_ctx_t *mal_ctx,
	  mal_endpoint_t *mal_endpoint,
	  mal_message_t *message) {
```

The 'self' parameter is cast to get the state of the router shared by all registered handlers (the "provider"):

```c
	  simple_app_myprovider_t *provider = (simple_app_myprovider_t *) self;
```

A cursor depending of the encoding is created then initialized, this cursor corresponds to a pointer in
data buffer and decoding structure. It is used during decoding.

```c
  malbinary_cursor_t cursor;
  malbinary_cursor_init(&cursor,
      mal_message_get_body(message),
      mal_message_get_body_offset(message) + mal_message_get_body_length(message),
      mal_message_get_body_offset(message));
```

Decoding the first element of the MAL message body:

```c
	  testarea_testservice_testcomposite_t *parameter_0 = NULL;
	  unsigned int offset = mal_message_get_body_offset(message);
	  char *bytes = mal_message_get_body(message);
	  rc = testarea_testservice_testsend_send_decode_0(
	    provider->encoding_format_code, &cursor,
	    provider->decoder, &parameter_0);
	  if (rc < 0) {
	    return rc;
	  }
```

Decoding the second element:

```c
	  mal_string_list_t *parameter_1;
	  rc = testarea_testservice_testsend_send_decode_1(
	    provider->encoding_format_code, &cursor,
	    provider->decoder, &parameter_1);
	  if (rc < 0) {
	    return rc;
	  }
```

Decoding the third (last) element (with polymorphism):

```c
	  mal_element_holder_t parameter_2;
	  rc = testarea_testservice_testsend_send_decode_2(
	    provider->encoding_format_code, &cursor,
	    provider->decoder, &parameter_2);
	  if (rc < 0) {
	    return rc;
	  }
```

The value of the decoded parameters can be zero.

The third parameter needs to test the value of the 'short_form' field before making the cast:

```c
	if (parameter_2.presence_flag && parameter_2.short_form ==
	    TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
	  testarea_testservice_testfinalcompositea_t *testfinalcompositea =
	    (testarea_testservice_testfinalcompositea_t *) parameter_2;
	  ...
```

Releasing the corresponding allocated structures:

```c
	  testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
```

Releasing the allocated structures for first and second parameters:

```c
	  testarea_testservice_testcomposite_destroy(&parameter_0);
	  mal_string_list_destroy(&parameter_1);
```

The message should then be destroyed:

```c
	mal_message_destroy(&message, mal_ctx);
```

Application launching:
----------------------

Include MAL/C and MALZMQ transport API definition:

```c
	#include "mal.h"
	#include "malzmq.h"
```

### Creating a MAL context

```c
	mal_ctx_t *mal_ctx = mal_ctx_new();
```

The encoding and decoding contexts are created for the 'malbinary' format. The 'varint' format is not 
used and the 'verbose' flag is enabled:

```c
	malbinary_encoder_t *encoder = malbinary_encoder_new(false, true);
	malbinary_decoder_t *decoder = malbinary_decoder_new(false, true);
```

Configuring the mapping catalog (see 12.1.3) and the presence of flags (see 12.1.2) in the MALZMQ header.
In this example we do not use a catalog and all optional fields are present (and encoded) in the MAL header.

```c
	malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL,
	  NULL, NULL, NULL);
```

A MALZMQ context is created from the MAL context, an URI mapping function can beprovided (see 12.2). In this
example we use the default function. The IP address and listening port for incoming connections are 'localhost'
and 5555.

```c
	malzmq_ctx_t *malzmq_ctx = malzmq_ctx_new(
	  mal_ctx, NULL,
	  "localhost", "5555",
	  malzmq_header,
	  encoder, decoder,
	  true);
```

### Provider creation

Creating a MALZMQ URI. A unique name (in the MALZMQ context) is given in parameter.

```c
	mal_uri_t *provider_uri =
	  mal_ctx_create_uri(mal_ctx, "simple_app/myprovider");
```

Creating the provider's endpoint with the following parameters:

  - The pointer to the MAL context.
  - The provider's URI previously allocated.

```c
	mal_endpoint_t *provider_endpoint = mal_endpoint_new(mal_ctx, provider_uri);
```

Instantiating the provider with the pointer to the corresponding endpoint and the related encoding parameters:

```c
	simple_app_myprovider_t *provider = simple_app_myprovider_new(
	  provider_endpoint,
	  MALBINARY_FORMAT_CODE,
	  encoder, decoder);
```

The operation handler will be registered later in the run function of the CZMQ actor (see Section 4.2.2).

### Consumer creation

Creating a MALZMQ URI. A unique name (in the MALZMQ context) is given in parameter.

```c
	mal_uri_t *consumer_uri =
	  mal_ctx_create_uri(mal_ctx, "simple_app/myconsumer");
```


Creating the consumer's endpoint with the following parameters:

  - The pointer to the MAL context.
  - The consumer's URI previously allocated.

```c
	mal_endpoint_t *consumer_endpoint = mal_endpoint_new(mal_ctx, consumer_uri);
```

The instantiation of the consumer requires some more MAL message header settings:

```c
	mal_blob_t *authentication_id = mal_blob_new(0);
	mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
	mal_uinteger_t priority = 4;
	mal_identifier_list_t *domain = mal_identifier_list_new(0);
	mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
	mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
	mal_identifier_t *session_name = mal_identifier_new("LIVE");

	simple_app_myconsumer_t *consumer =
	simple_app_myconsumer_new(provider_uri,
	  authentication_id, qoslevel, priority, domain, network_zone, session,
	  session_name, MALBINARY_FORMAT_CODE, encoder, decoder);
```

The encoding and decoding contexts used are those used by the provider.
Consumer side the Send operation requires no handler, so there will be no handler registration
for this consumer.

### Application launching and termination

Creating the provider and the corresponding ZMQ actor:

```c
  provider = simple_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
  zactor_t *provider_actor = zactor_new(simple_app_myprovider_run, provider);
```

Creating the consumer and the corresponding ZMQ actor:

```c
  consumer = simple_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);
  zactor_t *consumer_actor = zactor_new(simple_app_myconsumer_run, consumer);
```

Starting the MALZMQ transport (this call blocks until termination of the context):

```c
	  malzmq_ctx_start(malzmq_ctx);
```

Deletion of provider and consumer actors:

```c
  zactor_destroy(&provider_actor);
  zactor_destroy(&consumer_actor);
```

Deletion of MAL and MALZMQ contexts:

```c
	  mal_ctx_destroy(&mal_ctx);
	  malzmq_ctx_destroy(&malzmq_ctx);
```
