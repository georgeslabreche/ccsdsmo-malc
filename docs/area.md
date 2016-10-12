APIs d'area
===========

Les noms de type (de donnée) ou d'opération sont toujours préfixés par les nom d'area et de service où est déclaré le type ou l'opération. Deux notations sont utilisées pour spécifier ce format de nommage. La première consiste à inclure systématiquement les noms d'Area et de service, le nom de service n'existant pas pour les types définis dans des Areas (il est donc entre crochets pour les types) :

```c
<area>_[<service>_]<type>
<area>_<service>_<operation>
```

La seconde notation n'indique que le nom de type ou d'opération avec le préfix `qf` signifiant « qualified » c'est-à-dire incluant les noms d'Area et de service. Cette notation est plus compacte :

```c
<qftype>
<qfop>
```

Définition de constantes
------------------------

```c
#define <AREA>_AREA_NUMBER <area number>
#define <AREA>_AREA_VERSION <version>
```

Pour chaque service :

```c
#define <AREA>_<SERVICE>_SERVICE_NUMBER <service number>
```

Pour chaque opération de service :
```c
#define <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER <operation number>
```

Pour chaque erreur levée par une opération :
```c
#define <AREA>_<SERVICE>_<OPERATION>_<ERROR>_ERROR_NUMBER <error number>
```

Pour chaque type de donnée :
```c
#define <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM <short form>
#define <AREA>_[<SERVICE>_]<TYPE>_LIST_SHORT_FORM <short form>
```

Définition des types
--------------------


###	Enumeration

La valeur d'un énuméré est sa valeur ordinale, qui est égale à 0 pour le premier énuméré et qui est incrémentée de 1 pour chaque énuméré dans l'ordre de leur déclaration.

```c
typedef enum {
  <AREA>_[<SERVICE>_]<ENUMERATION>_<ENUMERATED NAME>,
} <area>_[<service>_]<enumeration>_t;
```

La valeur numérique de l'énuméré (spécifiée par la définition du service) est résolue au travers d'un tableau d'entiers déclaré statiquement. Ce tableau contient la valeur numérique pour chaque énuméré dans l'ordre de leur déclaration.

```c
int <AREA>_[<SERVICE>_]<ENUMERATION>_NUMERIC_VALUES[] = {
  <numeric value>,
}
```

###	Composite

```c
typedef struct _<area>_[<service>_]<composite>_t
  <area>_[<service>_]<composite>_t;
```

###	Listes

Pour chaque Composite :

```c
typedef struct _<area>_[<service>_]<composite>_list_t
    <area>_[<service>_]<composite>_list_t;
```

Pour chaque Enumeration :

```c
typedef struct _<area>_[<service>_]<enumeration>_list_t
    <area>_[<service>_]<enumeration>_list_t;
```

Envoi de message
----------------


###	Opération non Publish/Subscribe

Pour chaque opération, excepté si le pattern d'interaction est Publish/Subscribe, les fonctions d'envoi de message listées dans le tableau ci-dessous doivent être définies. 

L'étape et le rôle de l'application MAL appelant la fonction sont spécifiés pour chaque fonction.

Fonction | Etape | Rôle
---------|-------|-----
Initiation d'interaction | send, submit, request, invoke, progress | Consumer
Résultat d'interaction | submit_ack, request_response invoke_ack, invoke_response, progress_ack, progress_update, progress_response|Provider

Déclarations :

```c
int <area>_<service>_<operation>_<first stage>(
  mal_endpoint_t *endpoint, mal_message_t *init_message,
  mal_uri_t *provider_uri);

int <area>_<service>_<operation>_<result stage>(
  mal_endpoint_t *endpoint, mal_message_t *init_message,
  mal_message_t *result_message, bool is_error_message);
```

Paramètres :

        -	`endpoint` : le end-point qui envoie le message
        -	`init_message` : le message qui initie l'interaction (première étape)
        -	`provider_uri` : l'URI du provider de service
        -	`result_message` : le message résultat du traitement de l'interaction (seconde étape et suivantes)
        -	`is_error_message` : flag indiquant si le message renvoie une erreur

Résultat : 

code d'erreur

###	Opération Publish/Subscribe

Pour chaque opération dont le pattern d'interaction est Publish/Subscribe, les fonctions d'envoi de message listées dans le tableau ci-dessous doivent être définies. 

L'étape Pub/Sub et le rôle de l'application MAL appelant la fonction sont spécifiés pour chaque fonction. Aucune fonction n'est générée pour le rôle Broker car un Broker est un composant générique qui ne dépend pas d'Area particulière (excepté l'Area MAL).

Fonction | Etape Pub/Sub | Rôle
---------|---------------|--------
Abonnement | Register | Subscriber
Déclaration de publication | Publish Register | Publisher
Publication | Publish | Publisher
Désabonnement | Deregister | Subscriber
Arrêt de publication | Publish Deregister | Publisher

Déclarations :

```c
int <area>_<service>_<operation>_register(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri);

int <area>_<service>_<operation>_publish_register(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri);

int <area>_<service>_<operation>_publish(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri,
  long initial_publish_register_tid);

int <area>_<service>_<operation>_deregister(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri);

int <area>_<service>_<operation>_publish_deregister(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri);
```

Paramètres :

        -	`endpoint` : Le end-point qui envoie le message
        -	`message` : le message relatif à l'étape Pub/Sub
        -	`broker_uri` : l'URI du broker
        -	`initial_publish_register_tid` : identifiant de transaction du premier message Publish Register envoyé

Résultat : 

code d'erreur

Encodage
--------

Ces fonctions sont définies pour chaque opération, chaque élément de corps de message et chaque erreur retournée par l'opération. Les éléments sont identifiés par leur index dans le corps de message comme spécifié par la définition MAL (XML) du service.

En Pub/Sub, l'index des éléments commence à 0 avec la première liste d'Update. Les éléments précédents comme par exemple l'Identifier (message Notify) ou l'UpdateHeaderList (messages Publish et Notify) ne sont pas comptés.

Les messages d'erreur n'ont au plus qu'un seul élément (identifié par le champ extraInformation). Il n'y a donc pas d'index.

###	Polymorphisme du dernier élément de corps de message

Si l'élément est le dernier du corps de message :

        -	Si le type déclaré est MAL::Attribute, alors l'élément est transmis avec le type de l'union 'mal_attribute_t'.
        -	Si le type déclaré est MAL::Element, un composite abstrait, ou une liste d'un type abstrait (y compris MAL::Attribute), alors une fonction doit être définie pour chaque type final conforme au type abstrait. Le nom du type (qftype) est ajouté au nom de la fonction après un séparateur '_' :

```c
<nom de la fonction d encodage>_<qftype>(<paramètres>);
```

Les fonctions d'encodage du message d'erreur suivront également la même convention de nommage, que le type du champ extraInformation soit polymorphique ou non. Cela permet de distinguer les fonctions des éventuelles erreurs multiples.

###	Calcul de la taille d'encodage d'un élément de corps de message

Fonction d'ajout de la taille d'encodage à une valeur initiale.

Déclaration :

        -	Si l'opération n'est pas Pub/Sub :

        -	En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, bool presence_flag,
  unsigned char attribute_tag, union mal_attribute_t element,
  unsigned int *encoding_length);
```

        -	Sinon, le type de l'élément est connu (même en cas de polymorphisme) :
        -	Si l’élément est un Attribut non pointeur, ou un énuméré :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, bool presence_flag,
  <qftype>_t element, unsigned int *encoding_length);
```

        -	Si l’élément est un Attribut pointeur, un Composite ou une liste :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, <qftype>_[list_]t *element,
  unsigned int *encoding_length);
```

        -	Si l'opération est Pub/Sub :
```c
int <qfop>_update_add_encoding_length[_<index>][_<qftype>_list](
    int encoding_format_code, void * encoder,
    <qftype>_list_t *element,
    unsigned int *encoding_length);
```

Paramètres :

        -	`encoding_format_code` : code du format d'encodage
        -	`encoder` : configuration du module d'encodage
        -	`presence_flag` : champ de présence, nécessaire si le type de l'élément n'est pas un pointeur
        -	`element` : élément à encoder
        -	`encoding_length` : valeur initiale et résultat de la fonction d'ajout

Résultat : 

code d'erreur

###	Encodage d'un élément de corps de message

Déclaration :

        -	Si l'opération n'est pas Pub/Sub :
        -	En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, void *cursor,
  void *encoder, bool presence_flag, unsigned char attribute_tag,
  union mal_attribute_t element);
```

        -	Sinon, le type de l'élément est connu (même en cas de polymorphisme) :
        -	Si l’élément est un Attribut non pointeur ou un énuméré :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, void *cursor,
  void *encoder, bool presence_flag, <qftype>_t element);
```

        -	Si l’élément est un Attribut pointeur, un Composite, ou une liste :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, void *cursor,
  void *encoder, <qftype>_[list_]t *element);
```

        -	Si l'opération est Pub/Sub :

```c
int <qfop>_update_encode[_<index>][_<qftype>_list](
    int encoding_format_code, void *cursor,
    void *encoder, <qftype>_list_t *element) {
```

Paramètres :

        -	`encoding_format_code` : code du format d'encodage
        -	`cursor` : un index virtuel du fromat d'encodage
        -	`encoder` : configuration du module d'encodage
        -	`presence_flag` : flag de présence à encoder
        -	`attribute_tag` : tag d'Attribut à encoder
        -	`element` : élément à encoder

###	Décodage d'un élément de corps de message

Déclaration :

        -	Si l'opération n'est pas Pub/Sub :
        -	En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, void *cursor,
  void *decoder, bool *presence_flag_res,
  unsigned char *attribute_tag_res, union mal_attribute_t *element_res);
```

        -	En cas de polymorphisme d'élément et/ou pour un message d'erreur :

```c
int <qfop>_<stage|error>_decode[_<index>](
  int encoding_format_code,
  void *cursor, void *decoder,
  mal_element_holder_t *element_holder);
```

        -	Si le type de l'élément est connu :
        -	Si l’élément est un Attribut non pointeur ou un énuméré :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, void *cursor,
  void *decoder, bool *presence_flag_res, <qftype>_t *element_res);
```
  
        -	Si l’élément est un Attribut pointeur, un Composite ou une liste :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, void *cursor,
  void *decoder, <qftype>_[list_]t **element_res);
```

        -	Si l'opération est Pub/Sub :
        -	En cas de polymorphisme d'élément :

```c
int <qfop>_update_decode[_<index>](int encoding_format_code,
  void *cursor, void *decoder,
  mal_element_holder_t *element_holder);
```

        -	Si le type de l'update est connu :

```c
int <qfop>_update_decode[_<index>](int encoding_format_code,
  void *cursor, void *decoder,
  <qftype>_list_t **element_res);
```

Paramètres :

        -	`encoding_format_code` : code du format d'encodage
        -	`cursor` : un index virtuel du format d'encodage
        -	`decoder` : configuration du module de décodage
        -	`presence_flag_res` : flag de présence décodé
        -	`attribute_tag_res` : tag d'Attribut décodé
        -	`element_res` : élément décodé
        -	`element_holder` : élément décodé

###	Allocation mémoire

Les primitives de décodage allouent de la mémoire pour certains paramètres (attributs pointeurs, composites, listes, et ce récursivement. Ces paramètres doivent en final être détruits par l'appel des fonctions destroy adaptées, qui assurent la libération récursive de la mémoire.

En cas de retour en erreur d'une fonction de décodage, il peut y avoir eu allocation partielle d'un ensemble d'éléments. Dans ce cas le paramètre partiellement décodé est retourné et doit également être détruit par l'appel à la fonction destroy.

La destruction de la mémoire allouée lors du décodage d'un élément polymorphique au travers d'une structure mal_holder_t est particulière. Le destructeur de la structure ne libérant pas le contenu, il faut retrouvé le type effectif de l'élément alloué et appeler le constructeur spécifique de l'élément.

Composite
---------

Une classe est générée pour chaque Composite.

###	Constructeur

```c
<area>_[<service>_]<composite>_t
  *<area>_[<service>_]<composite>_new(void);
```

###	Getters et setters

L'affectation du flag de présence est réalisée de manière explicite par des fonctions `setter` dédiées. Le flag de présence ne doit pas être modifié implicitement par le `setter` de la valeur du champ.

Pour chaque champ, les fonctions 'setter' et 'getter' d'accès à la valeur du champ sont définies :

```c
<field type> <area>_[<service>_]<composite>_get_<field>(
    <area>_[<service>_]<composite>_t *self);
void <area>_[<service>_]<composite>_set_<field>(
    <area>_[<service>_]<composite>_t *self, <field type> <field>);
```

Si le champ n'est pas un pointeur (valeur NULL interdite), des fonctions 'setter' et 'getter' d'accès aux flags de présence sont ajoutées :

```c
bool <area>_[<service>_]<composite>_<field>_is_present(
    <area>_[<service>_]<composite>_t *self);
void <area>_[<service>_]<composite>_<field>_set_present(
    <area>_[<service>_]<composite>_t *self, bool is_present);
```

En cas de polymorphisme d'attribut, des fonctions 'setter' et 'getter' d'accès aux tags d'Attribut sont ajoutées :

```c
unsigned char <area>_[<service>_]<composite>_<field>_get_attribute_tag(
    <area>_[<service>_]<composite>_t *self);
void <area>_[<service>_]<composite>_<field>_set_attribute_tag(
    <area>_[<service>_]<composite>_t *self, unsigned char attribute_tag);
```

###	Destructeur

Détruit la structure et les structures contenues dedans (composites, listes, Attributs pointeurs).

```c
void <area>_[<service>_]<composite>_destroy(
    <area>_[<service>_]<composite>_t **self_p);
```

Listes de Composite
-------------------

Structures de liste générées pour chaque type Composite.

###	Constructeur

Déclaration :

```c
<area>_[<service>_]<composite>_list_t
  *<area>_[<service>_]<composite>_list_new(unsigned int element_count);
```

Paramètres :

        -	`element_count`

###	Getters

Des fonctions « getters » sont définies pour accéder aux champs :

```c
unsigned int <area>_[<service>_]<composite>_list_get_element_count(
  <area>_[<service>_]<composite>_list_t *self);
<area>_[<service>_]<composite>_t **<area>_[<service>_]<composite>_list_get_content(
  <area>_[<service>_]<composite>_list_t *self);
```

###	Destructeur

Détruit la liste, son contenu et les éléments de la liste.

```c
void <area>_[<service>_]<composite>_list_destroy(
    <area>_[<service>_]<composite>_list_t **self_p);
```

Listes d'énuméré
----------------

Structures de liste générées pour chaque type Enumeration.

###	Constructeur

Déclaration :

```c
<area>_[<service>_]<enum>_list_t
  *<area>_[<service>_]<enum>_list_new(unsigned int element_count);
```

Paramètres :

        -	`element_count`

###	Getters

Des fonctions « getters » sont définies pour accéder aux champs :

```c
unsigned int <area>_[<service>_]<enum>_list_get_element_count(
  <area>_[<service>_]<enum>_list_t *self);
bool *<area>_[<service>_]<enum>_list_get_presence_flags(
  <area>_[<service>_]<enum>_list_t *self);
<area>_[<service>_]<enum>_t *<area>_[<service>_]<enum>_list_get_content(
  <area>_[<service>_]<enum>_list_t *self);
```

###	Destructeur

Détruit la liste et son contenu.

```c
void <area>_[<service>_]<enum>_list_destroy(
    <area>_[<service>_]<enum>_list_t **self_p);
```
