APIs d'encodage
===============

Les APIs d'encodage sont définies de manière spécifique à un format d'encodage. Aucune fonction virtuelle n'est imposée par l'API C. Seuls des patterns de fonction sont proposés. Ces patterns sont le plus générique possible mais ils ne sont pas forcément applicables à tous les formats d'encodage. D'autres patterns de fonction peuvent être définis selon les besoins.

Les fonctions d'encodage générées pour chaque structure de donnée appellent directement les fonctions spécifiques d'encodage. Donc le générateur de stub doit connaître les fonctions spécifiques d'encodage offertes par chaque module d'encodage.

Le code applicatif ne dépend pas des APIs spécifiques d'encodage, sauf dans le cas où l'application a besoin d'encoder ou de décoder des données de manière explicite.

Le nom donné en C au format d'encodage défini dans le livre MAL/SPP est : malbinary.

Ce nom est une chaîne de caractères utilisée pour le nommage des APIs.

Définitions
-----------

```c
	<format>.h
```

Un code identifie de manière unique le format d'encodage doit être défini.

```c
	#define <FORMAT>_FORMAT_CODE <unique number>
```

Données à encoder
-----------------

Les données à encoder sont :

  -	les attributs MAL (dont les types C sont définis en section 5)
  -	le type d'union `mal_attribute_t`
  -	des données spécifiques à certains format ; par exemple : le flag de présence d'un champ, la taille de liste, la valeur d'un énuméré.

Il n'y a pas de fonction d'encodage d'énumérations car seul le code généré (stubs) a la connaissance de la taille des énumérés qui détermine le format d'encodage (dans le cas du format `malbinary`).

Il n'y a pas non plus de fonction d'encodage de liste car l'encodage des éléments de la liste est spécifique à leur type. Donc le code d'encodage d'une liste doit être généré dans les stubs.

L'encodage/décodage d'un code d'erreur est réalisé avec les fonctions d'encodage du type `MAL Uinteger`.

Pour chaque type de donnée à encoder, trois fonctions sont définies :

  -	une fonction permettant de calculer la taille requise par l'encodage de la donnée ; cette fonction prend en paramètre une taille initiale (la taille d'encodage en cours de calcul) et ajoute la taille de la donnée ;
  -	une fonction d'encodage de la donnée ;
  -	une fonction de décodage de la donnée.

Encodeur
--------

```c
	<format>_encoder.h
```

### Calcul de la taille d'encodage

Fonction d'ajout de la taille d'encodage à une valeur initiale.

Déclaration :

  - Si la donnée n'est pas de type pointeur (Attributs non pointeurs ou données spécifiques) :

```c
	int <format>_encoder_add_<data>_encoding_length(
	 <format>_encoder_t *self, mal_<data type>_t to_encode,
	 unsigned int *encoding_length);
```
  
  - Si la donnée est de type pointeur (Attributs pointeurs ou données spécifiques) :

```c
	int <format>_encoder_add_<data>_encoding_length(
	 <format>_encoder_t *self, mal_<data type>_t *to_encode,
	 unsigned int *encoding_length);
```

  - Pour le type MAL::Attribute (polymorphisme d'Attribut) :

```c
	int <format>_encoder_add_attribute_encoding_length(
	 <format>_encoder_t *self, unsigned char attribute_tag,
	  union mal_attribute_t to_encode, unsigned int *encoding_length);
```

Paramètres :

  -	`self` : le contexte d'encodage
  -	`attribute_tag` : l'identifiant du type d'Attribut (en cas de polymorphisme d'Attribut)
  -	`to_encode` : la donnée à encoder
  -	`encoding_length` : valeur initiale et résultat de la fonction d'ajout

Résultat : 

Code d'erreur

### Encodage

Déclaration :

  - Si la donnée n'est pas de type pointeur (Attributs non pointeurs ou données spécifiques) :

```c
	int <format>_encoder_encode_<data>(<format>_encoder_t *self,
	  void *cursor, mal_<data type>_t to_encode);
```

  - Si la donnée est de type pointeur (Attributs pointeurs ou données spécifiques) :

```c
	int <format>_encoder_encode_<data>(<format>_encoder_t *self,
	  void *cursor, mal_<data type>_t *to_encode);
```

  - Pour le type `MAL::Attribute` (polymorphisme d'Attribut) :

```c
	int <format>_encoder_encode_attribute(
	  <format>_encoder_t *self, void *cursor,
	  unsigned char attribute_tag, mal_attribute_t to_encode);
```

Paramètres :

  -	`self` : le contexte d'encodage
  -	`cursor` : un index virtuel dans les structures d'encodage
  -	`attribute_tag` : l'identifiant du type d'Attribut (en cas de polymorphisme d'Attribut)
  -	`to_encode` : la donnée à encoder

Résultat : 

Code d'erreur

Décodeur
--------

```c
	<format>_decoder.h
```

Pour chaque type de donnée à décoder, une fonction de décodage est définie.

Déclaration :

  - Si la donnée n'est pas de type pointeur (Attributs non pointeurs ou données spécifiques) :

```c
	int <format>_decoder_decode_<data>(<format>_decoder_t *self,
	  void *cursor, mal_<data type>_t *result);
```

  - Si la donnée est de type pointeur (Attributs pointeurs ou données spécifiques) :

```c
	int <format>_decoder_decode_<data>(<format>_decoder_t *self,
	  void *cursor, mal_<data type>_t **result);
```

  - Pour le type `MAL::Attribute` (polymorphisme d'Attribut) :

```c
	int <format>_decoder_decode_attribute(
	  <format>_decoder_t *self, void *cursor,
	  unsigned char attribute_tag, mal_attribute_t *result);
```

Paramètres :
  
  -	`self` : le contexte de décodage
  -	`cursor` : un index virtuel dans les structures de d�codage
  -	`result` : la donnée décodée

Résultat : 

Code d'erreur

Format **malbinary**
--------------------

### Données spécifiques


| Donnée	      | Type	        | Description                                                                                |
|-----------------|-----------------|--------------------------------------------------------------------------------------------|
| `presence_flag` | `bool`          | Champ de présence d'un élément pouvant être nul. `TRUE` si le champ est présent (valeur non nulle), `FALSE` si le champ est absent (valeur nulle). |
| `list_size`     | `unsigned int`  | Champ donnant la taille d'une liste MAL                                                    |
| `small_enum`    | `int`	        | Champ donnant la valeur d'un élément d'une petite énumération (taille inférieure à 2^8)    |
| `medium_enum`   | `int`	        | Champ donnant la valeur d'un élément d'une  moyenne énumération (taille inférieure à 2^16) |
| `large_enum`    | `int`           | Champ donnant la valeur d'un élément d'une grande énumération (taille inférieure à 2^32)   |
| `short_form`    | `long`          | Identifiant de type constitué des numéros d'Area, de Service, de version d'Area et de type. Défini en section 4.1.2 du livre MAL. Cet identifiant est encodé en cas de polymorphisme d'élément. |
| `attribute_tag` | `unsigned char` | Identifiant d'attribut : `short form` de l'attribut moins 1 (voir section 5.2.2 du livre MAL/SPP) |

### Constantes

Ces constantes donnent la taille d'encodage de certaines données : `presence_flag`, `attribute_tag`, `short_form`, `small_enum`, `medium_enum`, `large_enum`.

```c
	#define MALBINARY_PRESENCE_FLAG_SIZE 1
	#define MALBINARY_ATTRIBUTE_TAG_SIZE 1
	#define MALBINARY_SHORT_FORM_SIZE 8
	#define MALBINARY_SMALL_ENUM_SIZE 1
	#define MALBINARY_MEDIUM_ENUM_SIZE 2
	#define MALBINARY_LARGE_ENUM_SIZE 4
```
