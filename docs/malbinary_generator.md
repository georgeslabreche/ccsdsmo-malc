'malbinary' encoding code generation
====================================

This code is used for both Area and Composite encoding functions (cf sections 10.1.2 and 10.2.2).

Computing the encoding length
-----------------------------

The following parameters are provided by the calling code:

  -	<_element_>: MAL element to encode depending on its type
  -	presence_flag: presence flag when the element is not of a pointer type
  -	attribute_tag: identifier of the Attribute type in case of polymorphism of Attribute
  -	short_form: identifier of the type in case of polymorphism of Element
  -	encoder: configuration of the encoder, which should have been created as a malbinary encoder
  -	cursor: a virtual index in the encoding structures, holds the result of the encoding length computation

### Non mandatory field

Add the size of the presence flag:

```c
mal_encoder_add_presence_flag_encoding_length(encoder, presence_flag, cursor);
```

If the field is of a pointer type:

```c
if (<element> != NULL) {
```

Else test the presence flag:

```c
if (presence_flag) {
```

Add the size of the encoded element. Cf section 11.1.2.

```c
}
```

### Mandatory field

#### Polymorphism

In case of polymorphisme of Attribute:

```c
mal_encoder_add_attribute_tag_encoding_length(encoder, attribute_tag, cursor);
```

In case of polymorphisme of Element:

```c
mal_encoder_add_short_form_encoding_length(encoder, short_form, cursor);
```


#### Element value

If the declared type is `MAL::Attribute`:

```c
rc = mal_encoder_add_attribute_encoding_length(encoder,
  attribute_tag, <element>, cursor);
```

If the element type is an Attribute:

```c
rc = mal_encoder_add_<attribute>_encoding_length(encoder, <element>, cursor);
```

If the element type is a Composite:

```c
rc = <area>_[<service>_]<composite>_add_encoding_length_malbinary(
  <element>, encoder, cursor);
```

If the element type is a list:

```c
rc = <area>_[<service>_]<type>_list_add_encoding_length_malbinary(
  <element>, encoder, cursor);
```

If the element type is an Enumeration:

  -	If the enumeration size is lower than 2^8:

```c
	rc = mal_encoder_add_small_enum_encoding_length(encoder, <element>, cursor);
```

  -	If the enumeration size is lower than 2^16:
  
```c
	rc = mal_encoder_add_medium_enum_encoding_length(encoder, <element>, cursor);
```

  -	If the enumeration size is lower than 2^32:

```c
	rc = mal_encoder_add_large_enum_encoding_length(encoder, <element>, cursor);
```
Test the error code:
```c
if (rc < 0) return rc;
```

Encoding
--------

The following parameters are provided by the calling code:

  -	<_element_>: MAL element to encode depending on its type
  -	presence_flag: presence flag when the element is not of a pointer type
  -	attribute_tag: identifier of the Attribute type in case of polymorphism of Attribute
  -	short_form: identifier of the type in case of polymorphism of Element
  -	encoder: configuration of the encoder, which should have been created as a malbinary encoder
  -	cursor: a virtual index in the encoding structures, holds the result of the encoding length computation

### Non mandatory field

Encoding the presence flag:

```c
rc = mal_encoder_encode_presence_flag(encoder, cursor, <presence_flag>);
if (rc < 0) return rc;
```

Test the presence flag:
```c
if (<presence_flag>) {
```

Encoding the element. Cf section 11.2.2.
```c
}
```

### Mandatory field

#### Polymorphism

In case of polymorphism of Attribute, encoding the attribute tag (cf section 5.2.2 of the MAL/SPP book):

```c
rc = mal_encoder_encode_attribute_tag(encoder, cursor, <attribute_tag>);
```

In case of polymorphism of Element:

```c
rc = mal_encoder_encode_short_form(encoder,
  cursor, <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM);
```

Test the error code:

```c
if (rc < 0) return rc;
```

#### Element value

If the declared type is `MAL::Attribute`:

```c
rc = mal_encoder_encode_attribute(encoder,
  cursor, <attribute_tag>, <element>);
```

If the element type is an Attribute:

```c
rc = mal_encoder_encode_<attribute>(encoder,
  cursor, <element>);
```

If the element type is a Composite:
```c
rc = <area>_[<service>_]<composite>_encode_malbinary(
  <element>, encoder, cursor);
```

If the element type is a list:
```c
rc = <area>_[<service>_]<type>_list_encode_malbinary(
  <element>, encoder, cursor);
```

If the element type is an Enumeration:

  -	If the enumeration size is lower than 2^8:

```c
	rc = mal_encoder_encode_small_enum(encoder, cursor, <element>);
```

  -	If the enumeration size is lower than 2^16:

```c
	rc = mal_encoder_encode_medium_enum(encoder, cursor, <element>);
```

  -	If the enumeration size is lower than 2^32:

```c
	rc = mal_encoder_encode_large_enum(encoder, cursor, <element>);
```

Test the error code:

```c
if (rc < 0) return rc;
```

Decoding
--------

The following parameters are provided by the calling code:

  -	presence_flag: presence flag when the element is not of a pointer type
  -	decoder: configuration of the decoder, which should have been created as a malbinary decoder
  -	cursor: a virtual index in the encoding structures

### Non mandatory field

Decoding the presence flag:

```c
rc = mal_decoder_decode_presence_flag(decoder, cursor, &presence_flag);
if (rc < 0) return rc;
if (presence_flag) {
```

Decoding the element. Cf section 11.3.2.

```c
}
```

If the field is of a pointer type:

```c
else {
  <element> = NULL;
}
```

### Mandatory field

#### Polymorphism of Attribute

In case of polymorphism of Attribute, decoding the Attribute tag:
```c
<unsigned char attribute_tag;>
```

```c
rc = mal_decoder_decode_attribute_tag(decoder,
  cursor, &<attribute_tag>);
```

Test the error code:

```c
if (rc < 0) return rc;
```

Decoding the attribute:

```c
rc = mal_decoder_decode_attribute(decoder,
    cursor, attribute_tag , &<element>);
```

#### Polymorphism of Element

In case of polymorphism of Element, decoding the `short form`:

```c
rc = mal_decoder_decode_short_form(decoder,
  cursor, &element_holder->short_form);
```

Test the error code:

```c
if (rc < 0) return rc;
```

For each possible value of 'short_form' corresponding to a concrete type conforming to the abstract type:

```c
if (element_holder->short_form == <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM) {
```

Decoding an element of the specified type. Cf section 11.3.2.3.
The element is decoded directly in the structure:

  -	If the element type is an Attribute:

```c
	&element_holder->value.<attribute>_value
```

  -	If the element type is a Composite:

```c
      &element_holder->value.composite_value
```

  -	If the element type is a list:

```c
      &element_holder->value.list_value
```

  -	If the element type is an Enumeration:

```c
      &element_holder->value.enumerated_value
```

```c
}[ else ]
```

#### Element value

If the element type is an Attribute:

```c
rc = mal_decoder_decode_<attribute>(decoder,
  cursor, &<element>);
```

If the element type is a Composite:

```c
<element> = <area>_[<service>_]<composite>_new();
if (<element> == NULL) return -1;
rc = <area>_[<service>_]<composite>_decode_malbinary(
  <element>, decoder, cursor);
```

If the element type is a list:

```c
<element> = <area>_[<service>_]<type>_list_new(0);
if (<element> == NULL) return -1;
rc = <area>_[<service>_]<type>_list_decode_malbinary(
  <element>, decoder, cursor);
```

If the element type is an Enumeration :

```c
int enumerated_value;
```

  -	If the enumeration size is lower than 2^8:

```c
	rc = mal_decoder_decode_small_enum(decoder,
  cursor, &enumerated_value);
```

  -	If the enumeration size is lower than 2^16:

```c
	rc = mal_decoder_decode_medium_enum(decoder,
  cursor, &enumerated_value);
```

  -	If the enumeration size is lower than 2^32:

```c
	rc = mal_decoder_decode_large_enum(decoder,
  cursor, &enumerated_value);
```

Setting the decoded value:
```c
<element> = (<area>_[<service>_]<enum>_t) enumerated_value;
```

Test the error code:
```c
if (rc < 0) return rc;
```
