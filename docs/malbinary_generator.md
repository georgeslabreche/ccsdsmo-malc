Génération du code d'encodage 'malbinary'
=========================================

Ce code est partagé par les fonctions d'encodage générées par Area et par Composite (voir sections 10.1.2 et 10.2.2).

Calcul de la taille encodée
---------------------------

Les paramètres suivants doivent être transmis par le code appelant :

  -	<element> : élément MAL à encoder en fonction de son type
  -	presence_flag : champ de présence si l'élément n'est pas de type pointeur
  -	attribute_tag : identifiant du type d'Attribut en cas de polymorphisme d'Attribut
  -	malbinary_encoder : configuration de l'encodeur
  -	encoding_length : résultat du calcul

### Champ optionnel

Ajout de la taille du champ de présence :

```c
(*encoding_length) += MALBINARY_PRESENCE_FLAG_SIZE;
```

Si le champ est de type pointeur :

```c
if (<element> != NULL) {
```

Sinon, test du champ de présence :

```c
if (presence_flag) {
```

Ajout de la taille de l'élément encodé. Voir section 11.1.2.

```c
}
```

### Champ non optionnel

#### Polymorphisme

En cas de polymorphisme d'Attribut :
```c
(*encoding_length) += MALBINARY_ATTRIBUTE_TAG_SIZE;
```

En cas de polymorphisme d'élément :
```c
(*encoding_length) += MALBINARY_SHORT_FORM_SIZE;
```


#### Valeur de l'élément

Si le type déclaré est `MAL::Attribute` :

```c
rc = malbinary_encoder_add_attribute_encoding_length(malbinary_encoder,
  <attribute_tag>, <element>, encoding_length);
```

Si le type de l'élément est un Attribut :

```c
rc = malbinary_encoder_add_<attribute>_encoding_length(malbinary_encoder,
  <element>, encoding_length);
```

Si l'élément est de type Composite :

```c
rc = <area>_[<service>_]<composite>_add_encoding_length_malbinary(
  <element>, malbinary_encoder, encoding_length);
```

Si l'élément est de type liste:

```c
rc = <area>_[<service>_]<type>_list_add_encoding_length_malbinary(
  <element>, malbinary_encoder, encoding_length);
```

Si l'élément est de type Enumeration :

  -	Si la taille de l'énumération est inférieure à 2^8 :

```c
(*encoding_length) += MALBINARY_SMALL_ENUM_SIZE;
```

  -	Si la taille de l'énumération est inférieure à 2^16 :
```c
(*encoding_length) += MALBINARY_MEDIUM_ENUM_SIZE;
```

  -	Si la taille de l'énumération est inférieure à 2^32 :
```c
(*encoding_length) += MALBINARY_LARGE_ENUM_SIZE;
```
Test du code d'erreur :
```c
if (rc < 0) return rc;
```

Encodage
--------

Les paramètres suivants doivent être transmis par le code appelant :

  -	`<element>` : élément MAL à encoder en fonction de son type
  -	`presence_flag` : champ de présence si l'élément n'est pas de type pointeur
  -	`attribute_tag` : identifiant du type d'Attribut en cas de polymorphisme d'Attribut
  -	`malbinary_encoder` : configuration de l'encodeur MALBinary
  -	`bytes` : tableau d'octets où les éléments MAL sont encodés
  -	`offset` : index de début de l'encodage

### Champ optionnel

Encodage du champ de présence :

```c
rc = malbinary_encoder_encode_presence_flag(malbinary_encoder,
  bytes, offset, <presence_flag>);
if (rc < 0) return rc;
```

Test du champ de présence :
```c
if (<presence_flag>) {
```

Encodage de l'élément. Voir section 11.2.2.
```c
}
```

### Champ non optionnel

#### Polymorphisme

En cas de polymorphisme d'Attribut, encodage du tag d'attribut (voir section 5.2.2 du livre MAL/SPP) :

```c
rc = malbinary_encoder_encode_attribute_tag(malbinary_encoder,
  bytes, offset, <attribute_tag>);
```

En cas de polymorphisme d'élément :

```c
rc = malbinary_encoder_encode_short_form(malbinary_encoder,
  bytes, offset, <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM);
```

Test du code d'erreur :

```c
if (rc < 0) return rc;
```

#### Valeur de l'élément

Si le type déclaré est `MAL::Attribute` :

```c
rc = malbinary_encoder_encode_attribute(malbinary_encoder,
  bytes, offset, <attribute_tag>, <element>);
```

Si le type de l'élément est un Attribut :

```c
rc = malbinary_encoder_encode_<attribute>(malbinary_encoder,
  bytes, offset, <element>);
```

Si l'élément est de type Composite:
```c
rc = <area>_[<service>_]<composite>_encode_malbinary(
  <element>, malbinary_encoder, bytes, offset);
```

Si l'élément est de type liste:
```c
rc = <area>_[<service>_]<type>_list_encode_malbinary(
  <element>, malbinary_encoder, encoding_length);
```

Si l'élément est de type Enumeration :

  -	Si la taille de l'énumération est inférieure à 2^8 :

```c
rc = malbinary_encoder_encode_small_enum(malbinary_encoder, bytes,
  offset, <element>);
```

  -	Si la taille de l'énumération est inférieure à 2^16 :

```c
rc = malbinary_encoder_encode_medium_enum(malbinary_encoder, bytes,
  offset, <element>);
```

  -	Si la taille de l'énumération est inférieure à 2^32 :

```c
rc = malbinary_encoder_encode_large_enum(malbinary_encoder, bytes,
  offset, <element>);
```

Test du code d'erreur :

```c
if (rc < 0) return rc;
```

Décodage
--------

Les paramètres suivants doivent être transmis par le code appelant :

  -	`presence_flag` : champ de présence décodé
  -	`malbinary_decoder` : configuration de l'encodeur MALBinary
  -	`bytes` : tableau d'octets où les éléments MAL sont encodés
  -	`offset` : index de début du décodage

### Champ optionnel

Décodage du champ de présence :

```c
rc = malbinary_decoder_decode_presence_flag(malbinary_decoder,
  bytes, offset, &presence_flag);
if (rc < 0) return rc;
if (presence_flag) {
```

Décodage de l'élément. Voir section 11.3.2.

```c
}
```

Si le champ est de type pointeur :

```c
else {
  <element> = NULL;

}
```

### Champ non optionnel

#### Polymorphisme d'Attribut

En cas de polymorphisme d'Attribut, décodage du tag d'Attribut :
```c
<unsigned char attribute_tag;>
```

```c
rc = malbinary_decoder_decode_attribute_tag(malbinary_decoder,
  bytes, offset, &<attribute_tag>);
```

Test du code d'erreur :

```c
if (rc < 0) return rc;
```

Décodage de l'attribut :

```c
rc = malbinary_decoder_decode_attribute(malbinary_decoder,
    bytes, offset, attribute_tag , &<element>);
```

#### Polymorphisme d'élément

En cas de polymorphisme d'élément, décodage du `short form` :

```c
rc = malbinary_decoder_decode_short_form(malbinary_decoder,
  bytes, offset, &element_holder->short_form);
```

Test du code d'erreur :

```c
if (rc < 0) return rc;
```

Pour chaque valeur de 'short_form' qui correspond à un type conforme au type abstrait :

```c
if (element_holder->short_form == <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM) {
```

Décodage d'un élément du type spécifié. Voir section 11.3.2.3. L'élément est décodé directement dans la structure :

  -	Si le type de l'élément est un Attribut :

```c
      &element_holder->value.<attribute>_value
```

  -	Si l'élément est de type Composite :

```c
      &element_holder->value.composite_value
```

  -	Si l'élément est de type liste :

```c
      &element_holder->value.list_value
```

  -	Si l'élément est de type Enumeration :

```c
      &element_holder->value.enumerated_value
```

```c
}[ else ]
```

#### Valeur de l'élément

Si le type de l'élément est un Attribut :

```c
rc = malbinary_decoder_decode_<attribute>(malbinary_decoder,
  bytes, offset, &<element>);
```

Si l'élément est de type Composite :

```c
<element> = <area>_[<service>_]<composite>_new();
if (<element> == NULL) return -1;
rc = <area>_[<service>_]<composite>_decode_malbinary(
  <element>, malbinary_decoder, bytes, offset);
```

Si l'élément est de type liste :

```c
<element> = <area>_[<service>_]<type>_list_new(0);
if (<element> == NULL) return -1;
rc = <area>_[<service>_]<type>_list_decode_malbinary(
  <element>, malbinary_decoder, bytes, offset);
```

Si l'élément est de type Enumeration :

```c
int enumerated_value;
```

  -	Si la taille de l'énumération est inférieure ou égale à 2^8 :

```c
rc = malbinary_decoder_decode_small_enum(malbinary_decoder,
  bytes, offset, &enumerated_value);
```

  -	Si la taille de l'énumération est inférieure ou égale à 2^16 :

```c
rc = malbinary_decoder_decode_medium_enum(malbinary_decoder,
  bytes, offset, &enumerated_value);
```

  -	Si la taille de l'énumération est inférieure ou égale à 2^32 :

```c
rc = malbinary_decoder_decode_large_enum(malbinary_decoder,
  bytes, offset, &enumerated_value);
```

Affectation de l'élément décodé :
```c
<element> = (<area>_[<service>_]<enum>_t) enumerated_value;
```

Test du code d'erreur :
```c
if (rc < 0) return rc;
```
