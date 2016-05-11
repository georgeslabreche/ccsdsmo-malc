MAL Attribute API
=================

The MAL Attribute API defines the *C* types used to represent the MAL attributes.

Boolean type
------------

Definition of type `MAL::Boolean`:

```c
	typedef bool mal_boolean_t;
```

Integer types
-------------

Definition of types `MAL::Octet`, `MAL::UOctet`, `MAL::Short`, `MAL::UShort`, `MAL::Integer`, `MAL::UInteger`, `MAL::Long`, `MAL::ULong`:

```c
	typedef char mal_octet_t;
	typedef unsigned char mal_uoctet_t;
	typedef short mal_short_t;
	typedef unsigned short mal_ushort_t;
	typedef int mal_integer_t;
	typedef unsigned int mal_uinteger_t;
	typedef long mal_long_t;
	typedef unsigned long mal_ulong_t;
```

Floating point types
--------------------

Definition of types `MAL::Float`, `MAL::Double`.

```c
	typedef float mal_float_t;
	typedef double mal_double_t;
```

Dates
-----

Definition of types `MAL::Time`, `MAL::FineTime`:

```c
	typedef unsigned long mal_time_t;
	typedef unsigned long mal_finetime_t;
```

Duration
--------

Definition of type `MAL::Duration`:

```c
	typedef float mal_duration_t;
```

Character types
---------------

The `char` type is used to represent strings. If the characters are not in the ASCII format
(MAL specifies Unicode), then a character may be represented by several bytes. In this case,
the *C* functions dealing ASCII strings are no longer usable.

Definition of types `MAL::String`, `MAL::Identifier`, `MAL::URI`:

```c
	typedef char mal_string_t;
	typedef char mal_identifier_t;
	typedef char mal_uri_t;
```

### Constructor


Dynamically allocates a new string from an existing string. 
This function should be called when a MAL string is built from a statically defined chain.

```c
	mal_<attribute>_t *mal_<attribute>_new(char *char_content);
```

### String length (ASCII)

Returns the number of characters (encoded on 1 byte) in the string before the final null character (`\0`).

```c
	size_t mal_<attribute>_get_char_count(mal_<attribute>_t *self)
```

### String copy

When the same string must be used in two different fields of the same MAL structure or in two different MAL structures (composite, list), then it is necessary to duplicate the MAL string. Do never assign the same MAL string to different fields.

```c
	mal_<attribute>_t *attribute2 = mal_<attribute>_new(attribute1);
```

### Destructeur

Deletes the string.

```c
	mal_<attribute>_destroy(mal_<attribute>_t **self_p);
```

Blob
----

A class is defined for the type Blob in order to keep the size of the corresponding byte array (not accessible in C).

### Constructeur

Declaration:

```c
	mal_blob_t *mal_blob_new(unsigned int length);
```

Parameter:

  -	`length`: Number of bytes in the Blob.

### Getters

Two functions are defined to access the fields of Blob:

```c
	char *mal_blob_get_content(mal_blob_t *self);
	unsigned int mal_blob_get_length(mal_blob_t *self);
```

### Destructeur

Deletes the Blob and its content.

```c
	void mal_blob_destroy(mal_blob_t **self_p);
```

MAL Attribute polymorphism
--------------------------

To handle the case of MAL Attribute polymorphism, a class is defined with the following elements:

  -	tags that identify the real type of the attribute,
  -	a *C* union allowing the manipulation of the value of the attribute according to the associated tag,
  -	a destructor.

### Attribute union

A *C* union `mal_attribute_t` is defined to allow the MAL attribute polymorphism.

```c
	union mal_attribute_t {
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
	};
```

### Attribute tags


These identifiers are transmitted in case of *MAL Attribute* polymorphism.

```c
	#define MAL_BLOB_ATTRIBUTE_TAG 0
	#define MAL_BOOLEAN_ATTRIBUTE_TAG 1
	#define MAL_DURATION_ATTRIBUTE_TAG 2
	#define MAL_FLOAT_ATTRIBUTE_TAG 3
	#define MAL_DOUBLE_ATTRIBUTE_TAG 4
	#define MAL_IDENTIFIER_ATTRIBUTE_TAG 5
	#define MAL_OCTET_ATTRIBUTE_TAG 6
	#define MAL_UOCTET_ATTRIBUTE_TAG 7
	#define MAL_SHORT_ATTRIBUTE_TAG 8
	#define MAL_USHORT_ATTRIBUTE_TAG 9
	#define MAL_INTEGER_ATTRIBUTE_TAG 10
	#define MAL_UINTEGER_ATTRIBUTE_TAG 11
	#define MAL_LONG_ATTRIBUTE_TAG 12
	#define MAL_ULONG_ATTRIBUTE_TAG 13
	#define MAL_STRING_ATTRIBUTE_TAG 14
	#define MAL_TIME_ATTRIBUTE_TAG 15
	#define MAL_FINETIME_ATTRIBUTE_TAG 16
	#define MAL_URI_ATTRIBUTE_TAG 17
```

### Destructor

Deletes the union content.
Do not destroy the union itself which is not an allocated structure.

```c
	void mal_attribute_destroy(union mal_attribute_t *self_p,
	    unsigned char attribute_tag);
```

Attribute short forms
---------------------

These identifiers are transmitted in case of *MAL Element* polymorphism.

```c
	#define MAL_BLOB_SHORT_FORM 0x1000001000001L
	#define MAL_BOOLEAN_SHORT_FORM 0x1000001000002L
	#define MAL_DURATION_SHORT_FORM 0x1000001000003L
	#define MAL_FLOAT_SHORT_FORM 0x1000001000004L
	#define MAL_DOUBLE_SHORT_FORM 0x1000001000005L
	#define MAL_IDENTIFIER_SHORT_FORM 0x1000001000006L
	#define MAL_OCTET_SHORT_FORM 0x1000001000007L
	#define MAL_UOCTET_SHORT_FORM 0x1000001000008L
	#define MAL_SHORT_SHORT_FORM 0x1000001000009L
	#define MAL_USHORT_SHORT_FORM 0x100000100000AL
	#define MAL_INTEGER_SHORT_FORM 0x100000100000BL
	#define MAL_UINTEGER_SHORT_FORM 0x100000100000CL
	#define MAL_LONG_SHORT_FORM 0x100000100000DL
	#define MAL_ULONG_SHORT_FORM 0x100000100000EL
	#define MAL_STRING_SHORT_FORM 0x100000100000FL
	#define MAL_TIME_SHORT_FORM 0x10000010000010L
	#define MAL_FINETIME_SHORT_FORM 0x10000010000011L
	#define MAL_URI_SHORT_FORM 0x10000010000012L
```