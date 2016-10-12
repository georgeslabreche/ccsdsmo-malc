encoding APIs
=============

Based on our experience of the MalBinary and MalSplitBinary formats, we propose a generic encoding API for all encoding formats.
If it is not suitable to a particular encoding format, it is still possible to define format specific functions. For that reason the generated encoding functions may use code specific to the encoding format.

The user code does not depend on specific encoding APIs, except when the application needs to encode or decode data explicitely.

The encoding functions generated for each data structure may call either the generic encoding functions or possible format specific functions. The stub generator knows the specificities of each format. It may call the format specific functions, or produce format specific code.

The C name for the encoding format defined in the MAL/SPP book is: `malbinary`.
The C name for the encoding format defined in the MAL/TCP book is: `malsplitbinary`.
Those names are strings used in the naming of the APIs.

Definitions
-----------

```c
	<format>.h
```

A code is defined to uniquely identify the encoding format.

```c
	#define <FORMAT>_FORMAT_CODE <unique number>
```

Data to encode
--------------

The data to encode are:

  -	MAL attributes (whose C types are defined in section 5)
  -	union type `mal_attribute_t`
  -	format specific data; for example : the presence flag for a nullable field, the size of a list, the value of an enumerated value.

Encoding and decoding an error code is performed with the encoding functions for the `MAL Uinteger` type.

For each data type to encode, three functions are defined:

  -	a function to get the size required to encode the data; it accepts the current state of the computed size as input parameter, adds the size of the data, and return the updated size value; the generic API allows for complex size computation, such as the one defined in the split binary encoding;
  -	a function to encode the data in a preallocated buffer;
  -	a function to decode the data.

Encoder
-------

```c
	mal_encoder.h
```

### Computing the encoding length

The function adds the encoding length to an initial value given as a parameter.
The length parameter is generalized as a cursor to manage on various encoding formats.
The generic mal_encoder_* functions are mapped to specific \<format>\_encoder_* functions declared in the \<format>\_encoder.h file.

Prototype:

  - If the data type is not a pointer (non pointer Attributes or specific data):

```c
	int mal_encoder_add_<data>_encoding_length(
	  mal_encoder_t *self, mal_<data type>_t to_encode, void *cursor);
```
  
  - If the data type is a pointer (pointer Attributes or specific data):

```c
	int mal_encoder_add_<data>_encoding_length(
	  mal_encoder_t *self, mal_<data type>_t *to_encode, void *cursor);
```

  - For the type `MAL::Attribute` (polymorphism of Attribute):

```c
	int mal_encoder_add_attribute_encoding_length(
	  <format>_encoder_t *self, unsigned char attribute_tag,
	  union mal_attribute_t to_encode, void *cursor);
```

Parameters:

  -	`self` : the encoding context
  -	`attribute_tag` : the identifier of the Attribute type (with polymorphism of Attribute)
  -	`to_encode` : the data to encode
  -	`cursor` : initial and updated value of the encoding length

Result: 

Error code

### Encoding

The function encodes the data in a buffer and at an index defined by the generic cursor parameter.
The generic mal_encoder_* functions are mapped to specific \<format>\_encoder_* functions declared in the \<format>\_encoder.h file.
The specific functions cast the generic cursor into a \<format>\_cursor_t pointer.

Prototype:

  - If the data type is not a pointer (non pointer Attributes or specific data):

```c
	int mal_encoder_encode_<data>(mal_encoder_t *self,
	  void *cursor, mal_<data type>_t to_encode);
```

  - If the data type is a pointer (pointer Attributes or specific data):

```c
	int mal_encoder_encode_<data>(mal_encoder_t *self,
	  void *cursor, mal_<data type>_t *to_encode);
```

  - For the type `MAL::Attribute` (polymorphism of Attribute):

```c
	int mal_encoder_encode_attribute(
	  mal_encoder_t *self, void *cursor,
	  unsigned char attribute_tag, mal_attribute_t to_encode);
```

Parameters:

  -	`self` : the encoding context
  -	`cursor` : a virtual index in the encoding structures
  -	`attribute_tag` : the identifier of the Attribute type (with polymorphism of Attribute)
  -	`to_encode` : the data to encode

Result: 

Error code

Decoder
-------

```c
	mal_decoder.h
```

A decoding function is defined for each type to decode
The generic mal_decoder_* functions are mapped to specific \<format>\_decoder_* functions declared in the \<format>\_decoder.h file.

Prototype:

  - If the data type is not a pointer (non pointer Attributes or specific data):

```c
	int mal_decoder_decode_<data>(mal_decoder_t *self,
	  void *cursor, mal_<data type>_t *result);
```

  - If the data type is a pointer (pointer Attributes or specific data):

```c
	int mal_decoder_decode_<data>(mal_decoder_t *self,
	  void *cursor, mal_<data type>_t **result);
```

  - For the type `MAL::Attribute` (polymorphism of Attribute):

```c
	int mal_decoder_decode_attribute(
	  mal_decoder_t *self, void *cursor,
	  unsigned char attribute_tag, mal_attribute_t *result);
```

Parameters:

  -	`self` : the encoding context
  -	`cursor` : a virtual index in the encoding structures
  -	`attribute_tag` : the identifier of the Attribute type (with polymorphism of Attribute)
  -	`result` : the decoded data

Result: 

Error code

Format **malbinary** and **malsplitbinary**
-------------------------------------------

Both formats require similar specific data. They have been declared in the generic encoding API.

### Specific data


| Data            | Type            | Description                                                                                |
|-----------------|-----------------|--------------------------------------------------------------------------------------------|
| `presence_flag` | `bool`          | Field used for a Nullable element. `TRUE` when the field is defined (non null value), `FALSE` when it is not (null value). |
| `list_size`      | `unsigned int` | Field defining the size of a MAL list                                                    |
| `small_enum`     | `int`	        | Field used for an enumerated value of a small enumeration type (size lower than 2^8)    |
| `medium_enum`   | `int`	        | Field used for an enumerated value of a medium enumeration type (size lower than 2^16) |
| `large_enum`    | `int`           | Field used for an enumerated value of a large enumeration type (size lower than 2^32)   |
| `short_form`    | `long`          | Type identifier defined in section 4.1.2 of the MAL book. It is used in case of general polymorphism. |
| `attribute_tag` | `unsigned char` | Attribute type identifier: `short form` of the Attribute minus 1 (cf section 5.2.2 of the MAL/SPP book) |

