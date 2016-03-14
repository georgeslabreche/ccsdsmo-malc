Génération du code des stubs
============================

Le code généré est produit pour une mission donnée utilisant un ensemble d'Areas de service.

L'instruction 'calloc' (initialise à '0' les octets alloués) est utilisée pour allouer des structures ou des tableaux de pointeurs afin d'éviter, en cas d'initialisation incomplète, que le destructeur ne libère de la mémoire au travers de faux pointeurs.

Area
----
Un nouveau projet de type 'zproject' est créé pour chaque Area. Il porte le nom de l'Area en carcatères minuscules : `<area>`

### Fichier include (.h)

Un fichier `<area>.h` est défini pour chaque area.

#### Entête

```c
#ifndef __<AREA>_H_INCLUDED__
#define __<AREA>_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

Déclaration de la dépendance avec l'Area MAL :

```c
#include "mal.h"
```

Pour chaque Area requise :

```c
#include "<required area>.h"
```

#### Constantes

Définition des constantes suivantes :

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

#### Types

Pour chaque type Enumeration :

```c
typedef enum {
  <AREA>_[<SERVICE>_]<ENUMERATION>_<ENUMERATED NAME>,
} <area>_[<service>_]<enumeration>_t;
```

Pour chaque Composite :

```c
typedef struct _<area>_[<service>_]<composite>_t
  <area>_[<service>_]<composite>_t;
```

Pour chaque type de donnée défini précédemment (Enumeration, Composite) :

```c
typedef struct _<area>_[<service>_]<type>_list_t
  <area>_[<service>_]<type>_list_t;
```

Pour chaque type de donnée, calcul de l'identifiant entier 'short form' (typé 'long') comme défini en section 5.2.3 du livre MAL/SPP :

```c
#define <AREA>_[<SERVICE>_]<TYPE>_SHORT_FORM <short form>
#define <AREA>_[<SERVICE>_]<TYPE>_LIST_SHORT_FORM <short form>
```

#### Opérations

Pour chaque opération de service, excepté si le pattern d'interaction est Publish/Subscribe, les fonctions suivantes sont définies :

  -	une fonction d'envoi de message pour l'initiation d'une interaction (première étape) ;
  -	une fonction d'envoi de message pour chaque étape de résultat d'une interaction (seconde étape et suivantes).

Initiation d'interaction (excepté Publish/Subscribe)

```c
int <area>_<service>_<operation>_<first stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_uri_t *provider_uri);
```

Résultat d'interaction (excepté Publish/Subscribe)

```c
int <area>_<service>_<operation>_<result stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message, mal_message_t *result_message,
  bool is_error_message);
```

Pour chaque opération de service dont le pattern d'interaction est Publish/Subscribe, des fonctions sont définies pour les étapes suivantes de l'interaction : register, publishRegister, publish, deregister, publishDeregister.

Abonnement (Publish/Subscribe)

```c
int <area>_<service>_<operation>_register(
  mal_ctx_t *mal_ctx, mal_endpoint_t *endpoint, mal_message_t *message,
  mal_uri_t *broker_uri);
```

Déclaration de publication (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_register(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

Publication (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri,
  long initial_publish_register_tid);
```

Désabonnement (Publish/Subscribe)

```c
int <area>_<service>_<operation>_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

Arrêt de publication (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri);
```

### Fonctions d'encodage

Pour chaque message d'étape d'interaction de chaque opération de service, les fonctions suivantes sont définies :

  -	pour chaque élément de corps de message (identifié par son index), et pour chaque type en cas de polymorphisme (voir 9.4.1) :
  -	une fonction de calcul de taille d'encodage
  -	une fonction d'encodage
  -	pour chaque élément de corps de message (identifié par son index et son type déclaré) :
    - une fonction de décodage

Les opérations dont le pattern d'interaction est Publish/Subscribe sont traitées de manière particulière. Les trois fonctions d'encodage ne sont générées que pour une seule étape d'interaction fictive, l'étape update, qui correspond aux deux étapes publish et notify, et dont les types de paramètres sont définis dans la spécification de l'opération sous la forme d'un message publishNotify. De plus les paramètres effectivement utilisés dans les fonctions d'encodage sont des listes du type déclaré dans la spécification.

Les fonctions d'encodage liées aux messages d'erreur suivent le schéma général avec les particularités suivantes :

  -	le nom des fonctions ne comprend pas d'index,
  -	le nom des fonctions d'encodage comprend systématiquement le suffixe de type <_qftype>,
  -	la fonction de décodage suit le modèle de décodage avec polymorphisme d'Element.

#### Calcul de taille d'encodage

En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, bool presence_flag,
  unsigned char attribute_tag, union mal_attribute_t element,
  unsigned int *encoding_length);
```

Sinon, le type de l'élément est connu (même en cas de polymorphisme) :

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

Si l'opération est Pub/Sub, la fonction est générée pour le type liste du type déclaré dans la spécification :
```c
int <qfop>_update_add_encoding_length[_<index>][_<qftype>_list](
    int encoding_format_code, void * encoder,
    <qftype>_list_t *element,
    unsigned int *encoding_length);
```

#### Encodage

En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, bool presence_flag, unsigned char attribute_tag,
  union mal_attribute_t element);
```

Sinon, le type de l'élément est connu (même en cas de polymorphisme) :

  -	Si l’élément est un Attribut non pointeur ou un énuméré :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, bool presence_flag, <qftype>_t element);
```
  
  -	Si l’élément est un Attribut pointeur, un Composite, ou une liste :
```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, <qftype>_[list_]t *element);
```

Si l'opération est Pub/Sub, la fonction est générée pour le type liste du type déclaré dans la spécification :

```c
int <qfop>_update_encode[_<index>][_<qftype>_list](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, <qftype>_list_t *element);
```

#### Décodage

En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, bool *presence_flag_res,
  unsigned char *attribute_tag_res, union mal_attribute_t *element_res);
```

En cas de polymorphisme d'élément, y compris si l'opération est PubSub (stage = update), et/ou pour un message d'erreur :

```c
int <qfop>_<stage|error>_decode[_<index>](
  int encoding_format_code,
  char *bytes, unsigned int *offset, void *decoder,
  mal_element_holder_t *element_holder);
```

Si le type de l'élément est connu :

  -	Si l’élément est un Attribut non pointeur ou un énuméré :
```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, bool *presence_flag_res, <qftype>_t *element_res);
```

  -	Si l’élément est un Attribut pointeur, un Composite ou une liste :
```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, <qftype>_[list_]t **element_res);
```

Si l'opération est Pub/Sub, la fonction est générée pour le type liste du type déclaré dans la spécification, excepté en cas de polymorphisme où le cas standard de polymorphisme d'élément est repris.

```c
int <qfop>_update_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, <qftype>_list_t **element_res);
```

#### Fin du fichier

Une fonction de test :
```c
void <area>_test(bool verbose);
```

Pour chaque structure Composite :

```c
#include "<area>_[<service>_]<composite>.h"
```

Pour chaque liste de Composite :

```c
#include "<area>_[<service>_]<composite>_list.h"
```

Pour chaque liste d'énuméré:

```c
#include "<area>_[<service>_]<enumeration>_list.h"
```

Fin du ficher :
```c
#ifdef __cplusplus
}
#endif

#endif
```

###	Fichier source (.c)

```c
#include "<area>.h"
```

Pour chaque énumération :

```c
int <AREA>_[<SERVICE>_]<ENUMERATION>_NUMERIC_VALUES[] = {
  <numeric value>,
}
```

#### Initiation d'interaction (excepté Publish/Subscribe)

```c
int <area>_<service>_<operation>_<first stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_uri_t *provider_uri) {
  int rc = 0;
```

Affectation des champs liés à l'opération appelée :

```c
  mal_message_init(init_message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_<IP>,
    MAL_IP_STAGE_<STAGE>);
```

Envoi du message :

```c
  rc = mal_endpoint_init_operation(
    endpoint, init_message, provider_uri, true);
  return rc;
}
```

#### Résultat d'interaction (excepté Publish/Subscribe)

```c
int <area>_<service>_<operation>_<result stage>(
  mal_endpoint_t *endpoint,
  mal_message_t *init_message,
  mal_message_t *result_message,
  bool is_error_message) {
  int rc = 0;
```

Affectation des champs liés à l'opération :

```c
  mal_message_init(result_message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_<IP>,
    MAL_IP_STAGE_<STAGE>);
```

Envoi du message :

```c
  rc = mal_endpoint_return_operation(
    endpoint, init_message, result_message, is_error_message);
  return rc;
}
```

#### Abonnement (Publish/Subscribe)

```c
int <area>_<service>_<operation>_register(
  mal_endpoint_t *endpoint, mal_message_t *message, mal_uri_t *broker_uri) {
  int rc = 0;
```

Affectation des champs liés à l'opération :

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_REGISTER);
```

Envoi du message :

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Déclaration de publication (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish_register(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Affectation des champs liés à l'opération :

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER);
```

Envoi du message :

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Publication (Publish/Subscribe)

```c
int <area>_<service>_<operation>_publish(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri,
  long initial_publish_register_tid) {
  int rc = 0;
```

Affectation des champs liés à l'opération :

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH);
```

Affectation du `Transaction Id` :

```c
  mal_message_set_transaction_id(message, initial_publish_register_tid);
```

Envoi du message :

```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, false);
  return rc;
}
```

#### Désabonnement (Publish/Subscribe)

```c
int <area>_<service>_<operation>_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Affectation des champs liés à l'opération :

```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_DEREGISTER);
```

Envoi du message :
```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Arrêt de publication (Publish/Subscribe)
```c
int <area>_<service>_<operation>_publish_deregister(
  mal_endpoint_t *endpoint,
  mal_message_t *message,
  mal_uri_t *broker_uri) {
  int rc = 0;
```

Affectation des champs liés à l'opération :
```c
  mal_message_init(message, <AREA>_AREA_NUMBER,
    <AREA>_AREA_VERSION, <AREA>_<SERVICE>_SERVICE_NUMBER,
    <AREA>_<SERVICE>_<OPERATION>_OPERATION_NUMBER,
    MAL_INTERACTIONTYPE_PUBSUB,
    MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER);
```
Envoi du message :
```c
  rc = mal_endpoint_init_operation(endpoint, message, broker_uri, true);
  return rc;
}
```

#### Calcul de taille d'encodage

En cas de polymorphisme d'Attribut :
```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, bool presence_flag,
  unsigned char attribute_tag, union mal_attribute_t element,
  unsigned int *encoding_length) {
```

Sinon, le type de l'élément est connu (même en cas de polymorphisme) :

  -	Si l’élément est un Attribut non pointeur, ou un énuméré :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, bool presence_flag,
  <qftype>_t element, unsigned int *encoding_length) {
```

  -	Si l’élément est un Attribut pointeur, un Composite ou une liste :

```c
int <qfop>_<stage|error>_add_encoding_length[_<index>][_<qftype>](
  int encoding_format_code, void *encoder, <qftype>_[list_]t *element,
  unsigned int *encoding_length) {
```c

Initialisation du code d'erreur :

```c
  int rc = 0;
```

Test du type de l'encodage :

```c
  switch (encoding_format_code) {
```

Pour chaque format disponible :
```c
  case <FORMAT>_FORMAT_CODE: {
    <format>_encoder_t *<format>_encoder =
      (<format>_encoder_t *) encoder;
```

Calcul de la taille d'encodage d'un champ optionnel :
  -	Pour le format `malbinary`, voir section 11.1.1.
```c
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
```

#### Encodage

En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, bool presence_flag, unsigned char attribute_tag,
  union mal_attribute_t element) {
```

Sinon, le type de l'élément est connu (même en cas de polymorphisme) :
  -	Si l’élément est un Attribut non pointeur ou un énuméré :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, bool presence_flag, <qftype>_t element) {
```

  -	Si l’élément est un Attribut pointeur, un Composite, ou une liste :

```c
int <qfop>_<stage|error>_encode[_<index>][_<qftype>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *encoder, <qftype>_[list_]t *element) {
  presence_flag = (element != NULL);
```

Initialisation du code d'erreur :

```c
  int rc = 0;
```

Test du type de l'encodage :

```c
  switch (encoding_format_code) {
```

Pour chaque format disponible :

```c
  case <FORMAT>_FORMAT_CODE: {
    <format>_encoder_t *<format>_encoder =
      (<format>_encoder_t *) encoder;
```

Encodage d'un champ optionnel :

  -	Pour le format `malbinary`, voir section 11.2.2.
```c
    break;
  }
  default:
    rc = -1;
  }
  return rc;
}
```

#### Décodage

En cas de polymorphisme d'Attribut :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, bool *presence_flag_res,
  unsigned char *attribute_tag_res, union mal_attribute_t *element_res) {
```

En cas de polymorphisme d'élément et/ou pour un message d'erreur :

```c
int <qfop>_<stage|error>_decode[_<index>](
  int encoding_format_code,
  char *bytes, unsigned int *offset, void *decoder,
  mal_element_holder_t *element_holder) {
```

Si le type de l'élément est connu :

  -	Si l’élément est un Attribut non pointeur ou un énuméré :

```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes , unsigned int *offset,
  void *decoder, bool *presence_flag_res, <qftype>_t *element_res) {
```

  -	Si l’élément est un Attribut pointeur, un Composite ou une liste :
```c
int <qfop>_<stage>_decode[_<index>](
  int encoding_format_code, char *bytes, unsigned int *offset,
  void *decoder, <qftype>_[list_]t **element_res) {
```

Initialisation du code d'erreur :

```c
  int rc = 0;
```

Test du type de l'encodage :

```c
  switch (encoding_format_code) {
```

Pour chaque format disponible :

```c
  case <FORMAT>_FORMAT_CODE: {
    <format>_decoder_t *<format>_decoder =
      (<format>_encoder_t *) decoder;
      bool presence_flag;
```

Décodage d'un champ optionnel :

  -	Pour le format `malbinary`, voir section 11.3.1.
  -	Le décodage est réalisé directement dans la structure ou le pointeur résultat.
    - En cas de polymorphisme d'Attribut ou si l’élément est un Attribut non pointeur ou un énuméré : `(*presence_flag_res) = presence_flag;`
    - En cas de polymorphisme d'élément : `mal_element_holder_set_presence_flag(element_holder, presence_flag);`

Fin du décodage.
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

### Fichier include (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<COMPOSITE>_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<COMPOSITE>_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

Constructeur sans paramètre :

```c
<area>_[<service>_]<composite>_t
  *<area>_[<service>_]<composite>_new(void);
```

Pour chaque format d'encodage :

```c
int <area>_[<service>_]<composite>_add_encoding_length_<format>(
    <area>_[<service>_]<composite>_t *self, <format>_encoder_t *encoder,
    unsigned int *encoding_length);

int <area>_[<service>_]<composite>_encode_<format>(
    <area>_[<service>_]<composite>_t *self, <format>_encoder_t *encoder,
    char *bytes, unsigned int *offset);

int <area>_[<service>_]<composite>_decode_<format>(
    <area>_[<service>_]<composite>_t *self, <format>_decoder_t *decoder,
    char *bytes, unsigned int *offset);
```

Pour chaque champ du composite (y compris les champs hérités) :
```c
<field type> <area>_[<service>_]<composite>_get_<field>(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_set_<field>(
    <area>_[<service>_]<composite>_t *self, <field type> <field>);
```

Si le champ n'est pas un pointeur (valeur NULL interdite) :
```c
bool <area>_[<service>_]<composite>_<field>_is_present(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_<field>_set_present(
    <area>_[<service>_]<composite>_t *self, bool is_present);
```

En cas de polymorphisme d'Attribut :
```c
unsigned char <area>_[<service>_]<composite>_<field>_get_attribute_tag(
    <area>_[<service>_]<composite>_t *self);

void <area>_[<service>_]<composite>_<field>_set_attribute_tag(
    <area>_[<service>_]<composite>_t *self, unsigned char attribute_tag);
```

Destructeur :

```c
void <area>_[<service>_]<composite>_destroy(
    <area>_[<service>_]<composite>_t **self_p);
```

Fonction de test :

```c
void <area>_[<service>_]<composite>_test(bool verbose);
```

Fin du fichier :
```c
#ifdef __cplusplus
}
#endif

#endif
```

### Fichier source (.c)

```c
#include "<area>.h"
```

#### Définition de la structure

```c
struct _<area>_[<service>_]<composite>_t {
```

Pour chaque champ (y compris les champs hérités) :

  -	En cas de polymorphisme d'Attribut :
  -	Si le champ est optionnel (canBeNull = 'true') : `bool <field>_is_present`;
  -	Déclaration du champ :
```c
  unsigned char <field>_attribute_tag;
  union mal_attribute_t <field>;
```
  -	Si le champ est de type Attribut non pointeur, ou énuméré :
  -	Si le champ est optionnel (canBeNull = 'true') : `bool <field>_is_present;`
  -	Déclaration du champ : `<field type> <field>;`
  -	Sinon : `<field type> *<field>;`
Fin de la définition de la structure : `};`

#### Constructeur

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

#### Getters et setters

Pour chaque champ du composite (y compris les champs hérités) :

```c
<field type> <area>_[<service>_]<composite>_get_<field>(
    <area>_[<service>_]<composite>_t *self) {
  return self-><field>;
}
```

La fonction `setter` n'affecte que la valeur du champ. Le flag de présence ne doit pas être modifié.

```c
void <area>_[<service>_]<composite>_set_<field>(
    <area>_[<service>_]<composite>_t *self, <field type> <field>) {
  self-><field> = <field>;
}
```

Si le champ est optionnel (canBeNull = 'true') et si le champ n'est pas un pointeur :

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

En cas de polymorphisme d'Attribut :
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

#### Calcul de la taille encodée (`malbinary`)

```c
int <area>_[<service>_]<composite>_add_encoding_length_malbinary(
    <area>_[<service>_]<composite>_t *self,
    malbinary_encoder_t *malbinary_encoder,
    unsigned int *encoding_length) {
  int rc = 0;
```

Pour chaque champ (les champs hérités en premier) :

  -	Si le champ est optionnel, voir section 11.1.1.
  -	Sinon voir section 11.1.2.
```c
Fin de la fonction :
  return rc;
}
```

#### Encodage (`malbinary`)

```c
int <area>_[<service>_]<composite>_encode_malbinary(
    <area>_[<service>_]<composite>_t *self,
    malbinary_encoder_t *malbinary_encoder,
    char *bytes, unsigned int *offset) {
```

S'il existe au moins un champ optionnel :

```c
  bool presence_flag;
```

Pour chaque champ (les champs hérités en premier) :

  -	Si le champ est optionnel :
  -	Si le champ est de type Attribut non pointeur, ou énuméré : 
```c
presence_flag = self-><field>_is_present;
```
  -	Sinon : 
```c
presence_flag = (self-><field> != NULL);
```
  -	Voir section 11.2.1.
  -	Sinon voir section 11.2.2.

Fin de l'encodage :
```c
  return rc;
}
```

#### Décodage (`malbinary`)

```c
int <area>_[<service>_]<composite>_decode_malbinary(
    <area>_[<service>_]<composite>_t *self,
    malbinary_decoder_t *malbinary_decoder,
    char *bytes, unsigned int *offset) {
```

S'il existe au moins un champ optionnel : `bool presence_flag;`

Pour chaque champ (les champs hérités en premier) :

  -	Si le champ est optionnel, voir section 11.3.1.
  -	Sinon voir section 11.3.2.

Le décodage est réalisé directement dans la structure ou le pointeur résultat.
Si le champ est optionnel et de type Attribut abstrait, Attribut non pointeur, ou énuméré :

```c
    self-><field>_is_present = presence_flag;
```

Fin du décodage :

```c
  return rc;
}
```

#### Destructeur

Détruit la structure composite et les structures contenues dans les champs (composites, listes, chaînes de caractères, Blobs).

```c
void <area>_[<service>_]<composite>_destroy(
    <area>_[<service>_]<composite>_t **self_p) {
```

Pour chaque champ, y compris les champs hérités :

 - En cas de polymorphisme d'Attribut, si le champ est optionnel (canBeNull = 'true') :
```c
  if ((*self_p)-><field>_is_present)
```
 - En cas de polymorphisme d'Attribut, destruction du champ optionnel:
```c
  mal_attribute_destroy(&(*self_p)-><field>,
    (*self_p)-><field>_attribute_tag);
```
  -	Si le champ est de type Attribut pointeur :
```c
  if ((*self_p)-><field>!= NULL)
    mal_<attribute>_destroy(&(*self_p)-><field>);
```
  -	Si le champ est de type Composite :
```c
  if ((*self_p)-><field>!= NULL)
    <area>_[<service>_]<composite>_destroy(&(*self_p)-><field>);
```
  -	Si le champ est de type liste :
```c
  if ((*self_p)-><field>!= NULL)
    <area>_[<service>_]<type>_list_destroy(&(*self_p)-><field>);
```

Libération de la mémoire et effacement du pointeur :

```c
  free(*self_p);
  (*self_p) = NULL;
}
```

Listes de Composite
-------------------

### Fichier include (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<COMPOSITE>_LIST_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<COMPOSITE>_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

#### Constructeur :

```c
<area>_[<service>_]<composite>_list_t
  *<area>_[<service>_]<composite>_list_new(unsigned int element_count);
```

#### Getters :

```c
unsigned int <area>_[<service>_]<composite>_list_get_element_count(
  <area>_[<service>_]<composite>_list_t *self);

<area>_[<service>_]<composite>_t **mal_list_get_content(
  <area>_[<service>_]<composite>_list_t *self);
```

#### Pour chaque format d'encodage :

```c
int <area>_[<service>_]<composite>_list_add_encoding_length_<format>(
  <area>_[<service>_]<composite>_list_t *self,
  <format>_encoder_t *encoder, unsigned int *encoding_length);

int <area>_[<service>_]<composite>_list_encode_<format>(
  <area>_[<service>_]<composite>_list_t *self,
  <format>_encoder_t *encoder, char *bytes, unsigned int *offset);

int <area>_[<service>_]<composite>_list_decode_<format>(
  <area>_[<service>_]<composite>_t *self,
  <format>_decoder_t *decoder, char *bytes, unsigned int *offset);
```

#### Destructeur :

```c
void <area>_[<service>_]<composite>_list_destroy(
    <area>_[<service>_]<composite>_list_t **self_p);
```

#### Fonction de test :

```c
void <area>_[<service>_]<composite>_list_test(bool verbose);
```

#### Fin du fichier :

```c
#ifdef __cplusplus
}
#endif

#endif
```

### Fichier source (.c)

```c
#include "<area>.h"
```

#### Constructeur

Définition de la structure :

```c
struct _<area>_[<service>_]<composite>_list_t {
  unsigned int element_count;
  <area>_[<service>_]<composite>_t **content;
};
```

Constructeur :

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

#### Calcul de la taille d'encodage (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_add_encoding_length_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  malbinary_encoder_t *encoder, unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = self->element_count;
```

Encodage de la taille de la liste :

```c
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
```

Tous les éléments de la liste peuvent être nuls. Un champ de présence doit donc être ajouté pour chacun d'eux :

```c
  (*encoding_length) += list_size;
```

Encodage des éléments de la liste :

```c
  <area>_[<service>_]<composite>_t **content = self->content;
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element = content[i];
```

Calcul de la taille d'encodage d'un champ Composite optionnel : voir section 11.1.1.

```c
  }
  return rc;
}
```

#### Encodage (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_encode_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  <area>_[<service>_]<composite>_t *content = self->content;
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element = content[i];
```

Encodage d'un Composite optionnel : voir section 11.2.1.
```c
  }
  return rc;
}
```

#### Décodage (`malbinary`)

```c
int <area>_[<service>_]<composite>_list_decode_malbinary(
  <area>_[<service>_]<composite>_list_t *self,
  malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  <area>_[<service>_]<composite>_t **list_content =
    (<area>_[<service>_]<composite>_t **) calloc(
      sizeof(<area>_[<service>_]<composite>_t *) * list_size);
  for (int i = 0; i < list_size; i++) {
    <area>_[<service>_]<composite>_t *element;
```

Décodage d'un Composite optionnel : voir section 11.3.1.

```c
    list_content[i] = element;
  }
  self->element_count = list_size;
  self->content = list_content;
  return rc;
}
```

#### Destructeur

Détruit la liste, son contenu et les éléments de la liste.

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

Listes d'énuméré
----------------

### Fichier include (.h)

```c
#ifndef __<AREA>_[<SERVICE>_]<ENUMERATION>_LIST_H_INCLUDED__
#define __<AREA>_[<SERVICE>_]<ENUMERATION>_LIST_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif
```

#### Constructeur :

```c
<area>_[<service>_]<enumeration>_list_t
  *<area>_[<service>_]<enumeration>_list_new(
    unsigned int element_count);
```

#### Getters :

```c
unsigned int <area>_[<service>_]<enumeration>_list_get_element_count(
  <area>_[<service>_]<enumeration>_list_t *self);

bool *<area>_[<service>_]<enumeration>_list_get_presence_flags(
    <area>_[<service>_]<enumeration>_list_t *self);

<area>_[<service>_]<enumeration>_t *mal_list_get_content(
  <area>_[<service>_]<enumeration>_list_t *self);
```

#### Pour chaque format d'encodage :

```c
int <area>_[<service>_]<enumeration>_list_add_encoding_length_<format>(
  <area>_[<service>_]<enumeration>_list_t *self,
  <format>_encoder_t *encoder, unsigned int *encoding_length);

int <area>_[<service>_]<enumeration>_list_encode_<format>(
  <area>_[<service>_]<enumeration>_list_t *self,
  <format>_encoder_t *encoder, char *bytes, unsigned int *offset);

int <area>_[<service>_]<enumeration>_list_decode_<format>(
  <area>_[<service>_]<enumeration>_t *self,
  <format>_decoder_t *decoder, char *bytes, unsigned int *offset);
```

#### Destructeur :

```c
void <area>_[<service>_]<enumeration>_list_destroy(
    <area>_[<service>_]<enumeration>_list_t **self_p);
Fonction de test :
void <area>_[<service>_]<enumeration>_list_test(bool verbose);
```

##### Fin du fichier :

```c
#ifdef __cplusplus
}
#endif

#endif
```

### Fichier source (.c)

```c
#include "<area>.h"
```

#### Constructeur

Déclaration de la structure :

```c
struct _<area>_[<service>_]<enumeration>_list_t {
  unsigned int element_count;
  bool *presence_flags;
  <area>_[<service>_]<enumeration>_t *content;
};
```

Constructeur :

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

#### Calcul de la taille d'encodage (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_add_encoding_length_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  malbinary_encoder_t *encoder, unsigned int *encoding_length) {
  int rc = 0;
  unsigned int list_size = self->element_count;
```

Encodage de la taille de la liste :

```c
  malbinary_encoder_add_list_size_encoding_length(encoder, list_size,
      encoding_length);
```

Tous les éléments de la liste peuvent être nuls. Un champ de présence doit donc être ajouté pour chacun d'eux :

```c
  (*encoding_length) += list_size * MALBINARY_PRESENCE_FLAG_SIZE;
```

Encodage des éléments de la liste :

```c
  bool *presence_flags = self->presence_flags;
  <area>_[<service>_]<enumeration>_t *content = self->content;
  for (int i = 0; i < list_size; i++) {
    bool presence_flag = presence_flags[i];
    <area>_[<service>_]<enumeration>_t element = content[i];
```

Calcul de la taille d'encodage d'un champ énuméré optionnel : voir section 11.1.1.
```c
  }
  return rc;
}
```

#### Encodage (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_encode_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  malbinary_encoder_t *encoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size = self->element_count;
  malbinary_encoder_encode_list_size(encoder, bytes, offset, list_size);
  <area>_[<service>_]<enumeration>_t *content = self->content;
  for (int i = 0; i < list_size; i++) {
    bool presence_flag = presence_flags[i];
    <area>_[<service>_]<enumeration>_t *element = content[i];
```

Encodage d'un énuméré optionnel : voir section 11.2.1.
```c
  }
  return rc;
}
```

#### Décodage (`malbinary`)

```c
int <area>_[<service>_]<enumeration>_list_decode_malbinary(
  <area>_[<service>_]<enumeration>_list_t *self,
  malbinary_decoder_t *decoder, char *bytes, unsigned int *offset) {
  int rc = 0;
  unsigned int list_size;
  malbinary_decoder_decode_list_size(decoder, bytes, offset, &list_size);
  bool *presence_flags = (bool *) malloc(sizeof(bool) * list_size);
  <area>_[<service>_]<enumeration>_t *list_content =
    <area>_[<service>_]<enumeration>_t *list_content =
    (<area>_[<service>_]<enumeration>_t *) malloc(
      sizeof(<area>_[<service>_]<enumeration>_t) * list_size);
  for (int i = 0; i < list_size; i++) {
    bool presence_flag;
    int element;
```

Décodage d'un énuméré optionnel : voir section 11.3.1.
```c
    presence_flags[i] = presence_flag;
    list_content[i] = (<area>_[<service>_]<enumeration>_t) element;
  }
  self->element_count = list_size;
  self-> presence_flags = presence_flags;
  self->content = list_content;
  return rc;
}
```

#### Destructeur

Détruit la liste et son contenu (tableau).

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