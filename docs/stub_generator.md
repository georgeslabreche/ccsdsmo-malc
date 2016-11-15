Stubs code generation
=====================

Generated code is produced for a dedicated mission which uses a set of service Areas. All areas must be generated at the same time, in a single run of the generator.

The C statement 'calloc' (initializes allocated bytes with 0) is used to allocate the structures and pointers arrays. It guarantees that the destructor will not free memory through false pointers when the initialization has not completed properly.

Zproject
--------
A single Zproject is created for the generation run. It is called 'generated_areas'.

### Include file (.h)

The created file `generated_areas.h` includes the main `<area>.h` files for all the generated areas.

Area
----
A new 'zproject' class is created for each Area. It is named as the area name in lower case: `<area>`

### Include file (.h)

A file `<area>.h` is defined for each area.

#### Header

```c
#ifndef __<AREA>_H_INCLUDED__
#define __<AREA>_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

Declare the dependency on the MAL Area:

```c
#include "mal.h"
```

For each required Area:

```c
#include "<required area>.h"
```

#### Constants

Definition of area specific constants:

```c
#define <AREA>_AREA_NUMBER <area number>
#define <AREA>_AREA_VERSION <version>
```

For each service:

```c
#define <AREA>_<SERVICE>_SERVICE_NUMBER <service number>
```

For each service operation:

```c
#define <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER <operation number>
```

For each error raised by an operation:

```c
#define <AREA>_<SERVICE>_<OPERATION>_<ERROR>_ERROR_NUMBER <error number>
```

#### Types

For each Enumeration type:

```c
typedef enum {
  <AREA>_[<SERVICE>_]<ENUMERATION>_<ENUMERATED NAME>,
} <area>_[<service>_]<enumeration>_t;
```

For each Composite type:

```c
typedef struct _<area>_[<service>_]<composite>_t
  <area>_[<service>_]<composite>_t;
```

For each data type defined above (Enumeration, Composite):

```c
typedef struct _<area>_[<service>_]<type>_list_t
  <area>_[<service>_]<type>_list_t;
```

For each data type, define the numerical identifier 'short form' (typed as 'long') according to the definition in section 5.2.3 of the MAL/SPP book:

```c
#define <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM <short form>
#define <AREA>_[<SERVICE>_]<TYPE>_LIST_SHORT_FORM <short form>
```

#### Operations

For each service operation, except when the IP is Publish/Subscribe, the following functions are defined:

  -	a function sending a message to initiate the interaction (first step);
  -	a function sending a message for each result step of the interaction (second and following steps).

Interaction initiation (except Publish/Subscribe)

```c
int <area>_<service>_<operation>_<first stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_uri_t *provider_uri);
```

Interaction result (except Publish/Subscribe)

```c
int <area>_<service>_<operation>_<result stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message, mal_message_t *result_message,
  bool is_error_message);
```

For each service operation when the IP is Publish/Subscribe, functions are defined for the following interaction steps: register, publishRegister, publish, deregister, publishDeregister.

Subscription (Publish/Subscribe)

```c
int <area>_<service>_<operation>_register(
  mal_ctx_t *mal_ctx, mal_endpoint_t *endpoint, mal_message_t *message,
  mal_uri_t *broker_uri);
```

Declaration of publish (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_register(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

Publish (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri,
  long initial_publish_register_tid);
```

Unsubscription (Publish/Subscribe)

```c
int <area>_<service>_<operation>_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

Stop of publish (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

#### Encoding functions

For each message of an interaction step, the following functions are defined:

  -	for each element of a message body (identified by its index), and for each type in case of polymorphism (cf 9.4.1):
  	- a function to get the size required to encode the data
  	- a function to encode the data
  -	for each element of a message body (identified by its index and its declared type):
  	- a function to decode the data

The operations with IP Publish/Subscribe are handled in a special way. The three en/decoding functions are only generated for a single fictional interaction step, the update step, which matches the two steps publish and notify. The parameters types of those interaction steps are defined in the operation specification as a publishNotify message. Moreover the actual parameters types used in the functions, and in the en/decoding functions, are lists of the types declared in the specification.

The en/decoding functions related to the error messages follow the general schema with the following specificities:

  -	the name of the functions does not include an index,
  -	the name of the encoding functions always includes the type suffix <_qftype>,
  -	the decoding function follows the rule of decoding with polymorphism of Element.

##### Computing the encoding length

In case of polymorphism of Attribute:

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, bool presence_flag,
  unsigned char attribute_tag, union mal_attribute_t element,
  void *cursor);
```

Else the type of the element is known (even in case of polymorphism):

  -	If the element is a non pointer Attribute or an enumerated value:
```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, bool presence_flag,
  <qftype>_t element, void *cursor);
```
  -	If the element is a pointer Attribute, a Composite or a list:
```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, <qftype>_[list_]t *element,
  void *cursor);
```

If the operation is Pub/Sub, the function is generated for the type list of the type declared in the specification:
```c
int <qfop>_update_add_encoding_length[_<index>][_<qftype>_list](
  mal_encoder_t *encoder,
    <qftype>_list_t *element,
    void *cursor);
```

##### Encoding

In case of polymorphism of Attribute:

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  bool presence_flag, unsigned char attribute_tag,
  union mal_attribute_t element);
```

Else the type of the element is known (even in case of polymorphism):

  -	If the element is a non pointer Attribute or an enumerated value:

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  bool presence_flag, <qftype>_t element);
```
  
  -	If the element is a pointer Attribute, a Composite or a list:
```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  <qftype>_[list_]t *element);
```

If the operation is Pub/Sub, the function is generated for the type list of the type declared in the specification:

```c
int <qfop>_update_encode[_<index>][_<qftype>_list](
  void *cursor, mal_encoder_t *encoder,
  <qftype>_list_t *element);
```

##### Decoding

In case of polymorphism of Attribute:

```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  bool *presence_flag_res, unsigned char *attribute_tag_res,
  union mal_attribute_t *element_res);
```

In case of polymorphism of Element, including if the operation is PubSub (stage = update), and/or for an error message:

```c
int <qfop>_<stage|error>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  mal_element_holder_t *element_holder);
```

If the element type is known:

  -	If the element is a non pointer Attribute or an enumerated value:
```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  bool *presence_flag_res, <qftype>_t *element_res);
```

  -	If the element is a pointer Attribute, a Composite or a list:
```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  <qftype>_[list_]t **element_res);
```

If the operation is Pub/Sub, the function is generated for the type list of the type declared in the specification, except in case of polymorphism where the standard case of polymorphism of Element is reused.

```c
int <qfop>_update_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  <qftype>_list_t **element_res);
```

#### End of file

A test function:
```c
void <area>_test(bool verbose);
```

For each Composite structure:

```c
#include "<area>_[<service>_]<composite>.h"
```

For each list of Composite:

```c
#include "<area>_[<service>_]<composite>_list.h"
```

For each list of enumrated values:

```c
#include "<area>_[<service>_]<enumeration>_list.h"
```

end of file:
```c
#ifdef __cplusplus
}
#endif

#endif
```

### Source file (.c)

```c
#include "<area>.h"
```

For each enumeration:

```c
int <AREA>_[<SERVICE>_]<ENUMERATION>_NUMERIC_VALUES[] = {
  <numeric value>,
}
```

#### Interaction initiation (except Publish/Subscribe)

```c
int <area>_<service>_<operation>_<first stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_uri_t *provider_uri) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(init_message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_<IP>,
    MAL_IP_STAGE_<STAGE>);
```

Send the message:

```c
  rc = mal_endpoint_init_operation(
    endpoint, init_message, provider_uri, true);
  return rc;
}
```

#### Interaction result (except Publish/Subscribe)

```c
int <area>_<service>_<operation>_<result stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_message_t *result_message,
  bool is_error_message) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(result_message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_<IP>,
    MAL_IP_STAGE_<STAGE>);
```

Send the message:

```c
  rc = mal_endpoint_return_operation(
    endpoint, init_message, result_message, is_error_message);
  return rc;
}
```

#### Subscription (Publish/Subscribe)

```c
int <area>_<service>_<operation>_register(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_REGISTER);
```

Send the message:

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Declaration of publish (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_register(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER);
```

Send the message:

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Publish (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri,
  long initial_publish_register_tid) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH);
```

Set the `Transaction Id`:

```c
  mal_message_set_transaction_id(message, initial_publish_register_tid);
```

Send the message:

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, false);
  return rc;
}
```

#### Unsubscription (Publish/Subscribe)

```c
int <area>_<service>_<operation>_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Set the fields related to the called operation:

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_DEREGISTER);
```

Send the message:
```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Stop of publish (Publish/Subscribe)
```c
int <area>_<service>_<operation>_publish_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Set the fields related to the called operation:
```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER);
```

Send the message:
```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Computing the encoding length

In case of polymorphism of Attribute:
```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, bool presence_flag,
  unsigned char attribute_tag, union mal_attribute_t element,
  void *cursor) {
```

Else the type of the element is known (even in case of polymorphism):

  -	If the element is a non pointer Attribute or an enumerated value:

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, bool presence_flag,
  <qftype>_t element, void *cursor) {
```

  -	If the element is a pointer Attribute, a Composite or a list:

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  mal_encoder_t *encoder, <qftype>_[list_]t *element,
  void *cursor) {
```c

Initialize the error code:

```c
  int rc = 0;
```

Test the encoding format allowing for format specific encoding:

```c
  switch (encoder->encoding_format_code) {
```

For each available format:
```c
  case <FORMAT>_FORMAT_CODE: {
```

Compute the encoding length of an optional field:
  -	For the encoding format `malbinary`, cf section 11.1.1.
```c
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
```

#### Encoding

In case of polymorphism of Attribute:

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  bool presence_flag, unsigned char attribute_tag,
  union mal_attribute_t element) {
```

Else the type of the element is known (even in case of polymorphism):

  -	If the element is a non pointer Attribute or an enumerated value:

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  bool presence_flag, <qftype>_t element) {
```

  -	If the element is a pointer Attribute, a Composite or a list:

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  void *cursor, mal_encoder_t *encoder,
  <qftype>_[list_]t *element) {
  bool presence_flag = (element != NULL);
```

Initialize the error code:

```c
  int rc = 0;
```

Test the encoding format allowing for format specific encoding:

```c
  switch (encoder->encoding_format_code) {
```

For each available format:

```c
  case <FORMAT>_FORMAT_CODE: {
```

Encode an optional field:

  -	For the encoding format `malbinary`, cf section 11.2.2.
```c
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
```

#### Decoding

In case of polymorphism of Attribute:

```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  bool *presence_flag_res, unsigned char *attribute_tag_res,
  union mal_attribute_t *element_res) {
```

In case of polymorphism of Element and/or for an error message:

```c
int <qfop>_<stage|error>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  mal_element_holder_t *element_holder) {
```

If the element type is known:

  -	If the element is a non pointer Attribute or an enumerated value:

```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  bool *presence_flag_res, <qftype>_t *element_res) {
```

  -	If the element is a pointer Attribute, a Composite or a list:
```c
int <qfop>_<stage>_decode[_<index>](
  void *cursor, mal_decoder_t *decoder,
  <qftype>_[list_]t **element_res) {
```

Initialize the error code:

```c
  int rc = 0;
```

Test the decoding format allowing for format specific decoding:

```c
  switch (decoder->encoding_format_code) {
```

For each available format:

```c
  case <FORMAT>_FORMAT_CODE: {
      bool presence_flag;
```

Decode an optional field:

  -	For the encoding format `malbinary`, cf section 11.3.1.
  - Data are decoded directly into the result structure or pointer.

In case of polymorphism of Attribute or if the element is a non pointer Attribute or an enumerated value:

```c
    (*presence_flag_res) = presence_flag;
```

In case of polymorphism of Element:

```c
    mal_element_holder_set_presence_flag(element_holder, presence_flag);
```

End of decoding.
```c
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
```

Composite
---------

### Include file (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<COMPOSITE>_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<COMPOSITE>_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

Empty constructor:

```c
<area>_[<service>_]<composite>_t
  *<area>_[<service>_]<composite>_new(void);
```

For each encoding format:

```c
int <area>_[<service>_]<composite>_add_encoding_length_<format>(
    <area>_[<service>_]<composite>_t *self, mal_encoder_t *encoder,
    void *cursor);

int <area>_[<service>_]<composite>_encode_<format>(
    <area>_[<service>_]<composite>_t *self, mal_encoder_t *encoder,
    void *cursor);

int <area>_[<service>_]<composite>_decode_<format>(
    <area>_[<service>_]<composite>_t *self, mal_decoder_t *decoder,
    void *cursor);
```

For each field in the composite (including nherited fields):
```c
<field type> <area>_[<service>_]<composite>_get_<field>(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_set_<field>(
    <area>_[<service>_]<composite>_t *self, <field type> <field>);
```

If the field is not a pointer (cannot store a NULL value):
```c
bool <area>_[<service>_]<composite>_<field>_is_present(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_<field>_set_present(
    <area>_[<service>_]<composite>_t *self, bool is_present);
```

In case of polymorphism of Attribute:
```c
unsigned char <area>_[<service>_]<composite>_<field>_get_attribute_tag(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_<field>_set_attribute_tag(
    <area>_[<service>_]<composite>_t *self, unsigned char attribute_tag);
```

Destructor:

```c
void <area>_[<service>_]<composite>_destroy(
    <area>_[<service>_]<composite>_t **self_p);
```

Test function:

```c
void <area>_[<service>_]<composite>_test(bool verbose);
```

End of file:
```c
#ifdef __cplusplus
}
#endif

#endif
```

### Source file (.c)

```c
#include "<area>.h"
```

#### Define the structure

```c
struct _<area>_[<service>_]<composite>_t {
```

For each field (including inherited fields):

  -	In case of polymorphism of Attribute:
	- If the field is not mandatory (canBeNull = 'true'):
	
		```c
		bool <field>_is_present;
		```
        
	- Declare the field:
	
		```c
		unsigned char <field>_attribute_tag;
		union mal_attribute_t <field>;
		```
        
  -	If the element is a non pointer Attribute or an enumerated value:
  	- If the field is not mandatory (canBeNull = 'true'):
	
		```c
		bool <field>_is_present;
		```
        
	- Declare the field:
	
		```c
		<field type> \<field>;
		```
        
  -	Else:
	
	```c
	<field type> *\<field>;
	```
        
End the structure definition*:
	
```c
};
```

#### Constructor

```c
<area>_[<service>_]<composite>_t
  *<area>_[<service>_]<composite>_new(void) {
  <area>_[<service>_]<composite>_t *self =
      (<area>_[<service>_]<composite>_t *) calloc(
          1, sizeof(<area>_[<service>_]<composite>_t));
  if (!self)
    return NULL;
  return self;
}
```

#### Getters and setters

For each field (including inherited fields):

```c
<field type> <area>_[<service>_]<composite>_get_<field>(
    <area>_[<service>_]<composite>_t *self) {
  return self-><field>;
}
```

The `setter` function only changes the field value. It shall leave the presence flag unchanged.

```c
void <area>_[<service>_]<composite>_set_<field>(
    <area>_[<service>_]<composite>_t *self, <field type> <field>) {
  self-><field> = <field>;
}
```

If the field is not mandatory (canBeNull = 'true') and if the field is not a pointer:

```c
bool <area>_[<service>_]<composite>_<field>_is_present(
    <area>_[<service>_]<composite>_t *self) {
  return self-><field>_is_present;
}

void <area>_[<service>_]<composite>_<field>_set_present(
    <area>_[<service>_]<composite>_t *self, bool is_present) {
  self-><field>_is_present = is_present;
}
```

In case of polymorphism of Attribute:
```c
unsigned char <area>_[<service>_]<composite>_<field>_get_attribute_tag(
    <area>_[<service>_]<composite>_t *self) {
  return self-><field>_attribute_tag;
}

void <area>_[<service>_]<composite>_<field>_set_attribute_tag(
  <area>_[<service>_]<composite>_t *self,
  unsigned char attribute_tag) {
  self-><field>_attribute_tag = attribute_tag;
}
```

#### Computing the encoding length (`malbinary`)

```c
int <area>_[<service>_]<composite>_add_encoding_length_malbinary(
    <area>_[<service>_]<composite>_t *self, mal_encoder_t *mal_encoder,
    void *cursor) {
  int rc = 0;
```

For each field (inherited fields first):

  -	If the field is not mandatory, cf section 11.1.1.
  -	Else cf section 11.1.2.

End of function:
```c
  return rc;
}
```

#### Encoding (`malbinary`)

```c
int <area>_[<service>_]<composite>_encode_malbinary(
    <area>_[<service>_]<composite>_t *self, mal_encoder_t *mal_encoder,
    void *cursor) {
```

If there is at least one non mandatory field:

```c
  bool presence_flag;
```

For each field (inherited fields first):

  -	If the field is not mandatory:
	  -	If the field is a non pointer Attribute or an enumerated value: 
		```c
		presence_flag = self-><field>_is_present;
		```
	  -	Else: 
		```c
		presence_flag = (self-><field> != NULL);
		```
	  -	Cf section 11.2.1.
  -	Else cf section 11.2.2.

End of encoding:
```c
  return rc;
}
```

#### Decoding (`malbinary`)

```c
int <area>_[<service>_]<composite>_decode_malbinary(
    <area>_[<service>_]<composite>_t *self, mal_decoder_t *mal_decoder,
    void *cursor) {
```

If there is at least one non mandatory field:
```c
  bool presence_flag;
```

For each field (inherited fields first):

  -	If the field is not mandatory, cf section 11.3.1.
  -	Else cf section 11.3.2.

Data are decoded directly into the result structure or pointer.

If the field is not mandatory and is typed as an abstract Attribute, a non pointer Attribute or an enumerated value:

```c
    self-><field>_is_present = presence_flag;
```

End of decoding:

```c
  return rc;
}
```

#### Destructor

Frees the composite structure and the structures embedded in the composite fields (composites, lists, Strings, Blobs).

```c
void <area>_[<service>_]<composite>_destroy(
    <area>_[<service>_]<composite>_t **self_p) {
```

For each field, including inherited fields:

 - In case of polymorphism of Attribute:
 	- if the field is not mandatory (canBeNull = 'true'):
		```c
		if ((*self_p)-><field>_is_present)
		```
 	- free the field:
		```c
		mal_attribute_destroy(&(*self_p)-><field>,
		  (*self_p)-><field>_attribute_tag);
		```
  -	If the field is a pointer Attribute:
	```c
	if ((*self_p)-><field>!= NULL)
	  mal_<attribute>_destroy(&(*self_p)-><field>);
	```
  -	If the field is a Composite:
	```c
	if ((*self_p)-><field>!= NULL)
	  <area>_[<service>_]<composite>_destroy(&(*self_p)-><field>);
	```
  -	If the field is a list:
	```c
	if ((*self_p)-><field>!= NULL)
	  <area>_[<service>_]<type>_list_destroy(&(*self_p)-><field>);
	```

Free the memory and reset the pointer:

```c
  free(*self_p);
  (*self_p) = NULL;
}
```

Lists of Composite
-------------------

### Include file (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<COMPOSITE>_LIST_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<COMPOSITE>_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

#### Constructor:

```c
<area>_[<service>_]<composite>_list_t
  *<area>_[<service>_]<composite>_list_new(unsigned int element_count);
```

#### Getters:

```c
unsigned int <area>_[<service>_]<composite>_list_get_element_count(
  <area>_[<service>_]<composite>_list_t *self);

<area>_[<service>_]<composite>_t **mal_list_get_content(
  <area>_[<service>_]<composite>_list_t *self);
```

#### For each encoding format:

```c
int <area>_[<service>_]<composite>_list_add_encoding_length_<format>(
  <area>_[<service>_]<composite>_list_t *self,
  mal_encoder_t *encoder, void *cursor);

int <area>_[<service>_]<composite>_list_encode_<format>(
  <area>_[<service>_]<composite>_list_t *self,
  mal_encoder_t *encoder, void *cursor);

int <area>_[<service>_]<composite>_list_decode_<format>(
  <area>_[<service>_]<composite>_t *self,
  mal_decoder_t *decoder, void *cursor);
```

#### Destructor:

```c
void <area>_[<service>_]<composite>_list_destroy(
    <area>_[<service>_]<composite>_list_t **self_p);
```

#### Test function:

```c
void <area>_[<service>_]<composite>_list_test(bool verbose);
```

#### End of file :

```c
#ifdef __cplusplus
}
#endif

#endif
```

### Source file (.c)

```c
#include "<area>.h"
```

#### Constructor

Structure definition:

```c
struct _<area>_[<service>_]<composite>_list_t {
  unsigned int element_count;
  <area>_[<service>_]<composite>_t **content;
};
```

Constructor:

```c
<area>_[<service>_]<composite>_list_t
  *<area>_[<service>_]<composite>_list_new(unsigned int element_count) {
  <area>_[<service>_]<composite>_list_t *self =
    (<area>_[<service>_]<composite>_list_t *) calloc(1,
      sizeof(<area>_[<service>_]<composite>_list_t));
  if (!self) return NULL;
  self->element_count = element_count;
  self->content = (<area>_[<service>_]<composite>_t **) calloc(
      element_count, sizeof(<area>_[<service>_]<composite>_t *));
  return self;
}
```

#### Getters

```c
unsigned int <area>_[<service>_]<composite>_list_get_element_count(
  <area>_[<service>_]<composite>_list_t *self) {
  return self->element_count;
}

<area>_[<service>_]<composite>_t **
  <area>_[<service>_]<composite>_list_get_content(
    <area>_[<service>_]<composite>_list_t *self) {
  return self->content;
}
```

#### Computing the encoding length (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_add_encoding_length_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
```

Encoding the list size:

```c
  mal_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
```

Encoding the list elements:

```c
  <area>_[<service>_]<composite>_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element = content[i];
```

All the elements of the list may be null. A presence flag is encoded for each of them:

```c
    bool presence_flag = (element != NULL);
    mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
```

Compute the encoding length of a non mandatory composite field: cf section 11.1.1.

```c
  }
  return rc;
}
```

#### Encoding (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_encode_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0) return rc;
  <area>_[<service>_]<composite>_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element = content[i];
```

Encoding a non mandatory Composite : cf section 11.2.1.

```c
  }
  return rc;
}
```

#### Decoding (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_decode_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  mal_decoder_t *decoder, void *cursor) {
  int rc = 0;
  int rc = mal_decoder_decode_list_size(decoder, cursor, &self->element_count);
  if (rc < 0) return rc;
  if (self->element_count == 0) {
    self->content = NULL;
    return 0;
  }
  self->content = (<area>_[<service>_]<composite>_t **) calloc(
      sizeof(<area>_[<service>_]<composite>_t *) * self->element_count);
  if (self->content == NULL)
    return -1;
  for (int i = 0; i < self->element_count; i++) {
```

Decoding a non mandatory Composite: cf section 11.3.1.

Data are decoded directly into the result structure or pointer (i.e. `self->content[i]`).

```c
  }
  return rc;
}
```

#### Destructor

Frees the list, its content, and the list elements.

```c
void <area>_[<service>_]<composite>_list_destroy(
    <area>_[<service>_]<composite>_list_t **self_p) {
  if ((*self_p)->element_count > 0) {
    for (int i = 0; i < (*self_p)->element_count; i++) {
      if ((*self_p)->content[i] != NULL)
        <area>_[<service>_]<composite>_destroy(&(*self_p)->content[i]);
    }
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}
```

Lists of enumerated values
--------------------------

### Include file (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<ENUMERATION>_LIST_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<ENUMERATION>_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

#### Constructor:

```c
<area>_[<service>_]<enumeration>_list_t
  *<area>_[<service>_]<enumeration>_list_new(
    unsigned int element_count);
```

#### Getters:

```c
unsigned int <area>_[<service>_]<enumeration>_list_get_element_count(
  <area>_[<service>_]<enumeration>_list_t *self);

bool *<area>_[<service>_]<enumeration>_list_get_presence_flags(
    <area>_[<service>_]<enumeration>_list_t *self);

<area>_[<service>_]<enumeration>_t *mal_list_get_content(
  <area>_[<service>_]<enumeration>_list_t *self);
```

#### For each encoding format:

```c
int <area>_[<service>_]<enumeration>_list_add_encoding_length_<format>(
  <area>_[<service>_]<enumeration>_list_t *self,
  mal_encoder_t *encoder, void *cursor);

int <area>_[<service>_]<enumeration>_list_encode_<format>(
  <area>_[<service>_]<enumeration>_list_t *self,
  mal_encoder_t *encoder, void *cursor);

int <area>_[<service>_]<enumeration>_list_decode_<format>(
  <area>_[<service>_]<enumeration>_t *self,
  <format>_decoder_t *decoder, void *cursor);
```

#### Destructor:

```c
void <area>_[<service>_]<enumeration>_list_destroy(
    <area>_[<service>_]<enumeration>_list_t **self_p);
Fonction de test :
void <area>_[<service>_]<enumeration>_list_test(bool verbose);
```

##### End of file:

```c
#ifdef __cplusplus
}
#endif

#endif
```

### Source file (.c)

```c
#include "<area>.h"
```

#### Constructor

Declare the structure:

```c
struct _<area>_[<service>_]<enumeration>_list_t {
  unsigned int element_count;
  bool *presence_flags;
  <area>_[<service>_]<enumeration>_t *content;
};
```

Constructor:

```c
<area>_[<service>_]<enumeration>_list_t
  *<area>_[<service>_]<enumeration>_list_new(
    unsigned int element_count) {
  <area>_[<service>_]<enumeration>_list_t *self =
    (<area>_[<service>_]<enumeration>_list_t *) calloc(1,
      sizeof(<area>_[<service>_]<enumeration>_list_t));
  if (!self) return NULL;
  self->element_count = element_count;
  if (element_count == 0) return self;
  self->presence_flags = (bool *) calloc(element_count, sizeof(bool));
  if (!self->presence_flags) {
    free(self);
    return NULL;
  }
  self->content = (<area>_[<service>_]<enumeration>_t *) calloc(
      element_count, sizeof(<area>_[<service>_]<enumeration>_t));
  if (!self->content) {
    free(self->presence_flags);
    free(self);
    return NULL;
  }
  return self;
}
```

#### Getters

```c
unsigned int <area>_[<service>_]<enumeration>_list_get_element_count(
  <area>_[<service>_]<enumeration>_list_t *self) {
  return self->element_count;
}

bool *<area>_[<service>_]<enumeration>_list_get_presence_flags(
  <area>_[<service>_]<enumeration>_list_t *self) {
  return self->presence_flags;
}

<area>_[<service>_]<enumeration>_t
  *<area>_[<service>_]<enumeration>_list_get_content(
  <area>_[<service>_]<enumeration>_list_t *self) {
  return self->content;
}
```

#### Computing the encoding length (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_add_encoding_length_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
```

Encoding the list size:

```c
  mal_encoder_add_list_size_encoding_length(encoder, list_size, cursor);
```

Encoding the list elements:

```c
  <area>_[<service>_]<composite>_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element = content[i];
```

All the elements of the list may be null. A presence flag is encoded for each of them:

```c
    bool presence_flag = self->presence_flags[i];
    mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
```

Compute the encoding length of a non mandatory enumeration field: cf section 11.1.1.

```c
  }
  return rc;
}
```

#### Encoding (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_encode_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  mal_encoder_t *encoder, void *cursor) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  rc = mal_encoder_encode_list_size(encoder, cursor, list_size);
  if (rc < 0) return rc;
  for (int i = 0; i < list_size; i++) {
    bool presence_flag = self->presence_flags[i];
    <area>_[<service>_]<enumeration>_t element = self->content[i];
```

Encoding a non mandatory enumerated value: cf section 11.2.1.

```c
  }
  return rc;
}
```

#### Decoding (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_decode_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  mal_decoder_t *decoder, void *cursor) {
  int rc = 0;
  rc = mal_decoder_decode_list_size(decoder, cursor, &self->element_count);
  if (rc < 0) return rc;
  if (self->element_count == 0) {
    self->presence_flags = NULL;
    self->content = NULL;
    return 0;
  }
  self->presence_flags = (bool *) calloc(self->element_count, sizeof(bool));
  if (self->presence_flags == NULL)
    return -1;
  self->content = (<area>_[<service>_]<enumeration>_t *) calloc(self->element_count, sizeof(<area>_[<service>_]<enumeration>_t));
  if (self->content == NULL) {
    free(self->presence_flags);
    return -1;
  }
  for (int i = 0; i < self->element_count; i++) {
```

Decoding a non mandatory enumerated value: cf section 11.3.1.

Data are decoded directly into the result structure or pointer (i.e. `self->presence_flags[i]` and `self->content[i]`).

```c
  }
  return rc;
}
```

#### Destructor

Free the list and its content.

```c
void <area>_[<service>_]<enum>_list_destroy(
    <area>_[<service>_]<enum>_list_t **self_p) {
  if ((*self_p)->element_count > 0) {
    free((*self_p)->presence_flags);
    free((*self_p)->content);
  }
  free (*self_p);
  (*self_p) = NULL;
}
```
