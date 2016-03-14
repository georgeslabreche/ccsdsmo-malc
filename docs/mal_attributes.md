API d'Attributs MAL
===================

L'API d'Attributs MAL définit les types C utilisés pour représenter les Attributs MAL.

Type booléen
------------

Définition du type `MAL::Boolean` :

```c
	typedef bool mal_boolean_t;
```

Types numériques entiers
------------------------

Définition des types `MAL::Octet`, `MAL::UOctet`, `MAL::Short`, `MAL::UShort`, `MAL::Integer`, `MAL::UInteger`, `MAL::Long`, `MAL::ULong` :

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

Types numériques flotants
-------------------------

Définition des types `MAL::Float`, `MAL::Double`.

```c
	typedef float mal_float_t;
	typedef double mal_double_t;
```

Dates
-----

Définition des types `MAL::Time`, `MAL::FineTime` :

```c
	typedef unsigned long mal_time_t;
	typedef unsigned long mal_finetime_t;
```

Durée
-----

Définition du type `MAL::Duration` :

```c
	typedef float mal_duration_t;
```

Types chaîne de caractères
--------------------------

Le type `char` est utilisé pour représenter les chaînes de caractères. Si les caractères n'appartiennent pas au format ASCII (MAL spécifie le format Unicode), alors un même caractère peut être représenté par plusieurs octets . Dans ce cas, les fonctions C traitant les chaînes ASCII ne sont plus applicables.

Définition des types `MAL::String`, `MAL::Identifier`, `MAL::URI` :

```c
	typedef char mal_string_t;
	typedef char mal_identifier_t;
	typedef char mal_uri_t;
```

### Constructeur

Alloue dynamiquement une nouvelle chaîne de caractères à partir d'une chaîne existante. Cette fonction doit être appelée quand une chaîne MAL est construite à partir d'une chaîne définie statiquement.

```c
	mal_<attribute>_t *mal_<attribute>_new(char *char_content);
```

### Nombre de caractères (ASCII)

Retourne le nombre de caractères (encodés sur 1 octet) dans la chaîne, avant le caractère nul final (`\0`).

```c
	size_t mal_<attribute>_get_char_count(mal_<attribute>_t *self)
```

### Copie

Lorsqu'une même chaîne de caractères doit être affectée à deux champs distincts d'une même structure MAL ou de deux structures MAL distinctes (composite, liste), alors il est nécessaire de dupliquer la chaîne MAL. Il ne faut pas affecter la même chaîne MAL aux deux champs.

```c
	mal_<attribute>_t *attribute2 = mal_<attribute>_new(attribute1);
```

### Destructeur

Détruit la chaîne de caractères.

```c
	mal_<attribute>_destroy(mal_<attribute>_t **self_p);
```

Blob
----

Une classe est définie pour le type Blob afin de conserver la taille du tableau d'octets (non accessible en C).

### Constructeur

Déclaration :

```c
	mal_blob_t *mal_blob_new(unsigned int length);
```

Paramètres :

  -	`length` : nombre d'octets dans le Blob

### Getters

Des fonctions sont définies pour accéder aux champs de Blob :

```c
	char *mal_blob_get_content(mal_blob_t *self);
	unsigned int mal_blob_get_length(mal_blob_t *self);
```

### Destructeur

Détruit le Blob et son contenu.

```c
	void mal_blob_destroy(mal_blob_t **self_p);
```

Polymorphisme d'Attribut
------------------------

Pour gérer le cas du polymorphisme d'Attribut MAL, on définit une classe avec les éléments suivants :

  -	des tags qui permettent d'identifier le type concret de l'attribut,
  -	un type C union qui permet de manipuler la valeur de l'attribut typée en fonction du tag associé,
  -	un destructeur.

### Union des Attributs

Une union `mal_attribute_t` est définie pour permettre le polymorphisme d'Attribut.

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

### Tags d'Attribut

Ces identifiants sont transmis en cas de polymorphisme d'Attribut.

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

### Destructeur

Détruit le contenu de l'union. Ne détruit pas l'union elle-même qui n'est pas une structure allouée.

```c
	void mal_attribute_destroy(union mal_attribute_t *self_p,
	    unsigned char attribute_tag);
```

Short forms d'Attribut
----------------------

Ces identifiants sont transmis en cas de polymorphisme d'élément MAL.

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