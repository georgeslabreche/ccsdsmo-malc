API MAL
=======

L'API MAL permet d'utiliser les concepts de niveau MAL :

  -	les concepts définis par la spécification MAL (Blue Book)
  -	les concepts propres à l'API C, définis en section 2

L'API MAL contient l'API d'Area générée à partir de la définition de l'Area MAL.

Définitions
-----------

```c
mal.h
```

### Fonction virtuelle de création d'URI

Déclaration :

```c
typedef mal_uri_t *mal_binding_ctx_create_uri_fn(
  void *mal_binding_ctx,
  char *id);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`id` : identifiant unique devant être inclus dans l'URI

Résultat : 

L'URI créée

### Fonction virtuelle de création d'un end-point

Déclaration :

```c
typedef void *mal_binding_ctx_create_endpoint_fn(
  void *mal_binding_ctx,
  mal_endpoint_t *mal_endpoint);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_endpoint` : le end-point MAL correspondant au end-point physique du transport

Résultat :

La référence du end-point physique créé (non typée pour éviter la dépendance avec les concepts physiques du transport, par exemple socket ZMQ).

### Fonction virtuelle de destruction d'un end-point

Déclaration :

```c
typedef void mal_binding_ctx_destroy_endpoint_fn(
  void *mal_binding_ctx,
  void **endpoint_p);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`endpoint_p` : le end-point à détruire

### Fonction virtuelle de création d'un poller MAL

Déclaration :

```c
typedef void *mal_binding_ctx_create_poller_fn(
  void *mal_binding_ctx,
  mal_poller_t *mal_poller);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_poller` : le poller MAL correspondant au poller physique du transport

Résultat : 

La référence du poller physique créé (non typée pour éviter la dépendance avec les concepts physiques du transport, par exemple zpoller ZMQ).

### Fonction virtuelle d'ajout / suppression d'un end-point à un poller

Déclaration :

```c
typedef int mal_binding_ctx_poller_add_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

typedef int mal_binding_ctx_poller_del_endpoint_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_poller` : le poller à utiliser
  -	`mal_endpoint` : le end-point à ajouter ou supprimer au poller

Résultat : 

Code d'erreur.

### Fonction virtuelle d'attente de message sur un poller MAL

Déclaration :

```c
typedef int mal_binding_ctx_poller_wait_fn(
    void *mal_binding_ctx,
    mal_poller_t *mal_poller,
    mal_endpoint_t **mal_endpoint,
    int timeout);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_poller` : le poller sur lequel attendre
  -	`mal_endpoint` : le end-point sur lequel un message est en attente de réception
  -	`timeout` : le temps d'attente maximum, éventuellement infini (-1)

Résultat : 

Code d'erreur.

### Fonction virtuelle de destruction d'un poller MAL

Déclaration :

```c
typedef void mal_binding_ctx_destroy_poller_fn(
  void *mal_binding_ctx,
  void **poller_p);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`poller_p` : le poller à détruire

### Fonction virtuelle d'envoi de message MAL

Cette fonction est appelée par la fonction `mal_ctx_send_message` (section 7.4.2).

Déclaration :

```c
typedef int mal_binding_ctx_send_message_fn(
    void *mal_binding_ctx,
    mal_endpoint_t *mal_endpoint,
    mal_message_t *message);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_endpoint` : le end-point qui envoie le message
  -	`message` : message MAL à envoyer

Résultat : 

code d'erreur

### Fonction virtuelle de réception de message MAL

Cette fonction est appelée par la fonction `mal_ctx_recv_message` (section 7.4.3).

Déclaration :

```c
typedef int mal_binding_ctx_recv_message_fn(
  void *mal_binding_ctx,
  mal_endpoint_t *mal_endpoint, mal_message_t **message);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`mal_endpoint` : le end-point qui reçoit le message
  -	`message` : message MAL reçu

Résultat : 

Code d'erreur

### Fonction virtuelle de destruction de message MAL

Permet au transport d'associer des ressources au message MAL (champ `body_owner`) et de les libérer lors de la destruction du message.

Déclaration :

```c
typedef int mal_binding_ctx_destroy_message_fn(void *mal_binding_ctx,
    mal_message_t *message);
```

Paramètres :

  -	`mal_binding_ctx` : contexte du transport (binding) utilisé par la couche MAL ; non typé pour permettre à la couche MAL d'utiliser plusieurs transports
  -	`message` : message MAL à détruire

Résultat : 

Code d'erreur

Contexte MAL
------------

```c
mal_ctx.h
```

### Constructeur

Déclaration :

```c
mal_ctx_t *mal_ctx_new(void);
```

Résultat : 

Le contexte MAL créé

### Création d'URI

Déclaration :

```c
mal_uri_t *mal_ctx_create_uri(mal_ctx_t *self, char *id);
```

Paramètres :

  -	`self` : contexte MAL
  -	`id` : identifiant unique devant être inclus dans l'URI

Résultat : 

L'URI créée

### Création d'un poller

Déclaration :

```c
void *mal_ctx_create_poller(
  mal_ctx_t *self,
  mal_poller_t *poller);
```

Paramètres :

  -	`self`  : contexte MAL
  -	`poller` : le poller MAL correspondant au poller physique créé

Résultat : 

	La référence du poller physique créé (non typée pour éviter la dépendance avec les concepts physiques du transport, par exemple zpoller ZMQ).

### Création d'un end-point

Déclaration :

```c
void *mal_ctx_create_endpoint(
  mal_ctx_t *self,
  mal_endpoint_t *endpoint);
```

Paramètres :

  -	`self` : contexte MAL
  -	`endpoint` : le end-point MAL correspondant au end-point physique créé

Résultat : 

La référence du end-point physique créé (non typée pour éviter la dépendance avec les concepts physiques du transport, par exemple socket ZMQ).

### Envoi de message MAL

Cette fonction est appelée par les fonctions d'envoi de message MAL des end-points (section 7.4.2). Elle appelle la fonction virtuelle d'envoi de message offerte par le transport (section 7.1.8).

L'usage de cette fonction est limitée aux end-point MAL.

Déclaration :

```c
int mal_ctx_send_message(
  mal_ctx_t *self,
  mal_endpoint_t *mal_endpoint,
  mal_message_t *message);
```

Paramètres :

  -	`self` : contexte MAL
  -	`mal_endpoint` : end-point qui envoie le message
  -	`message` : message MAL à envoyer

Résultat : 

Code d'erreur

### Réception de message MAL

Cette fonction est appelée par les fonctions de réception de messages MAL des end-points (section 7.4.3). Elle appelle la fonction virtuelle de réception de messages offerte par le transport (section 7.1.9).

L'usage de cette fonction est limitée aux end-point MAL.

Déclaration :

```c
int mal_ctx_recv_message(
  mal_ctx_t *self,
  mal_endpoint_t *mal_endpoint,
  mal_message_t **message);
```

Paramètres :

  -	`self` : contexte MAL
  -	`mal_endpoint` : end-point qui recoit le message
  -	`message` : message MAL à envoyer

Résultat : 

Code d'erreur

### Destructeur

Détruit le contexte MAL.

```c
	void mal_ctx_destroy(mal_ctx_t **self_p);
```

Paramètres :
  
  -	`self_p` : pointeur vers le contexte MAL à détruire

Message MAL
-----------

### Constructeur

Alloue la mémoire nécessaire pour le corps de message.

Déclaration :

```c
mal_message_t *mal_message_new(
  mal_blob_t *authentication_id,
  mal_qoslevel_t qoslevel, mal_uinteger_t priority, mal_list_t *domain,
  mal_identifier_t *network_zone, mal_sessiontype_t session,
  mal_identifier_t *session_name, unsigned int body_length);
```

Paramètres :

  -	Champs du header MAL
  -	Taille du corps de message en octets

### Initialisation

Initialisation des champs propres à l'opération et à l'étape d'interaction :

Déclaration :

```c
void mal_message_init(mal_message_t *self, mal_ushort_t service_area,
  mal_uoctet_t area_version, mal_ushort_t service,
  mal_ushort_t operation,
  mal_interactiontype_t interaction_type,
  mal_uoctet_t interaction_stage);
```

Paramètres :

  -	Champs du header MAL

### Destructeur

Détruit le message MAL et le contenu du corps de message.

Appelle la fonction virtuelle de destruction de message MAL offerte par le transport (voir 7.1.10).

Déclaration :

```c
void mal_message_destroy(mal_message_t **self_p, mal_ctx_t *mal_ctx);
```

Paramètres :

  -	Le message à détruire
  -	Le contexte MAL pour éventuellement libérer des ressources au niveau transport (binding) associées au message

### Getters et setters

Les champs définis dans le tableau suivant sont accessibles.

Champ | Type | Description
------|------|-----------------
`<mal header field>` | `<mal header field type>` | Les champs de header MAL sont décrits dans le livre MAL
`free_<header field>` | `bool` | Flags indiquant si les champs de header MAL qui sont de type pointeur doivent être détruits (destroy) lorsque le message MAL est détruit.
`body` | `char *` | Corps du message encodé
`body_offset` | `unsigned int` | Index de début du corps du message
`body_length` | `unsigned int` | Taille du corps de message
`body_owner` | `void *` | Ressource associée au message par le transport et devant être libérée lors de la destruction du message

Les flags de présence s'appliquent aux champs suivants : `URI To`, `Authentication Id`, `URI From`, `Domain`, `Network Zone`, `Session Name`.
Par défaut, le comportement est le suivant :

  -	si le message MAL a été créé par le constructeur alors le flag est faux : les champs du header sont transmis lors de l'appel au constructeur, ils n'ont donc pas à être libérés
  -	si le message MAL a été créé lors d'un décodage et si les champs de header ont été décodés (non récupérés d'un service de configuration) alors le flag est vrai : les champs du header appartiennent au message et doivent être détruits avec lui


End-Point MAL
-------------

Un end-point ne doit être manipulé que par un unique flot d'exécution.

### Constructeur

Crée une instance de end-point identifiée par une URI MAL. Un compteur de `Transaction Id` est géré.

Déclaration :

```c
mal_endpoint_t *mal_endpoint_new(mal_ctx_t *mal_ctx, mal_uri_t *uri);
```

Paramètres :

  -	`mal_ctx` : contexte MAL
  -	`uri` : URI MAL identifiant le end-point MAL

L'API offre deux fonctions permettant de retrouver l'URI et le contexte MAL correspondant au end-point :

```c
mal_uri_t *mal_endpoint_get_uri(mal_endpoint_t *self);
mal_ctx_t *mal_endpoint_get_mal_ctx(mal_endpoint_t *self);
```

### Envoi de message MAL

Deux fonctions d'envoi de message sont définies :

  -	une fonction pour l'initiation d'une interaction (première étape). Cette fonction affecte les champs d'URI (l'URI de destination est affectée avec le paramètre `uri_to` et l'URI source est l'URI du end-point). Si le flag `set_tid` est égal à True, alors le champ `Transaction Id` est affecté avec la prochaine valeur du compteur de 'Transaction Id' géré par le end-point MAL. Sinon, la valeur du champ `Transaction Id` du message fourni n'est pas modifiée.
  -	une fonction pour les étapes de résultat d'une interaction (seconde étape et suivantes). Cette fonction affecte les champs d'URI (`URI To` est affectée avec la valeur du champ `URI From` du message d'initiation, et `URI From` est l'URI du end-point). Le champ `Transaction Id` est affecté avec la valeur du champ `Transaction Id` du message d'initiation. Le champ `Is Error Message` est affecté avec la valeur passée par le paramètre `is_error_message`.

La fonction `mal_ctx_send_message` (section 7.2.5) est appelée pour envoyer le message MAL.

Déclaration :

```c
int mal_endpoint_init_operation(
  mal_endpoint_t *self,
  mal_message_t *message,
  mal_uri_t *uri_to,
  bool set_tid);

int mal_endpoint_return_operation(
  mal_endpoint_t *self,
  mal_message_t *init_message,
  mal_message_t *message,
  bool is_error_message);
```

Paramètres :

  -	`self` : le end-point qui envoie le message
  -	`message` : message résultat de l'interaction (à envoyer)
  -	`init_message` : message qui a initié l'interaction
  -	`uri_to` : l'URI du destinataire du message
  -	`set_tid` : flag indiquant si le champ 'Transaction Id' du message MAL doit être affecté ou non
  -	`is_error_message` : flag indiquant si le message renvoie une erreur

Résultat : 

Code d'erreur

### Réception de message MAL

La fonction `mal_endpoint_recv_message` permet de recevoir un message sur le end-point, cette fonction est bloquante.

```c
int mal_endpoint_recv_message(
    mal_endpoint_t *self,
    mal_message_t **message);
```

Paramètres :
 
  -	`self` : le end-point qui envoie le message
  -	`message` : le message reçu

Résultat : 

Code d'erreur

### Destructeur

Détruit le end-point.

```c
void mal_endpoint_destroy(mal_endpoint_t **self_p);
```

Poller MAL
----------

Un poller ne doit être manipulé que par un unique flot d'exécution.

### Constructeur

Crée une instance de poller identifiée par une URI MAL.

Déclaration :

```c
	mal_poller_t *mal_poller_new(mal_ctx_t *mal_ctx);
```

Paramètres :

  -	`mal_ctx` : contexte MAL

L'API offre une fonction permettant de retrouver le contexte MAL correspondant au poller :

```c
mal_ctx_t *mal_endpoint_get_mal_ctx(mal_endpoint_t *self);
```

###Ajout/Suppression de end-point MAL

Deux fonctions permettent l'ajout et la suppression de end-point au poller.

Déclaration :

```c
int mal_poller_add_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *endpoint);

int mal_poller_del_endpoint(
    mal_poller_t *self,
    mal_endpoint_t *mal_endpoint);
```

Paramètres :

  -	`self` : le poller
  -	`endpoint` : le end-point à ajouter ou supprimer

Résultat :

Code d'erreur

### Attente de message MAL

La fonction mal_poller_wait permet d'attendre la réception d'un message sur l'un des end-points du poller. Cette fonction est bloquante prend en paramètre un time-out.

```c
int mal_poller_wait(
    mal_poller_t *self,
    mal_endpoint_t **endpoint,
    int timeout);
```

Paramètres :

  -	`self` : le poller en attente de message
  -	`endpoint` : le end-point sur lequel un message est arrivé
  -	`timeout` : le temps d'attente maximal, éventuellement infini (-1).

Résultat :

Code d'erreur

### Destructeur

Détruit le poller, les éventuels end-points rattachés doivent être détruits séparément.

```c
	void mal_poller_destroy(mal_oller_t **self_p);
```

Handler et routage
------------------
Un Handler est une structure logique constituée d'un ensemble de fonctions de traitements de messages MAL, cet ensemble de fonctions dépend de son rôle (provider, consumer, etc.) et de l'interaction dans laquelle il intervient (send, submit, etc.). Les handlers s'exécutent dans le cadre d'une structure de routage (i;e ; un objet de la classe mal_routing, ou routeur).

Le routeur est lié à un end-point MAL, il permet d'enregistrer les handlers correspondants aux différentes interactions attendues, puis lors de la réception d'un message par le end-point d'activer explicitement le handler correspondant pour qu'il traite le message. Le routeur possède un état partagé par l'ensemble des handlers qu'il gère.

### Handler

Chaque fonction de traitement de messages des handlers prend en paramètre l'état du routeur, la référence du contexte MAL, la référence du end-point et le message à traiter. La signature correspondante est définie ci-dessous.

```c
typedef int mal_routing_on_message_fn(
  void *self,
  mal_ctx_t *mal_ctx,
  mal_endpoint_t *mal_endpoint,
  mal_message_t *message);
```

Paramètres :

  -	`state` : état du routeur
  -	`mal_ctx` : contexte MAL
  -	`endpoint` : end-point MAL
  -	`state` : état de du routeur, non typé pour permettre le polymorphisme

### Constructeur

Crée une instance de routeur identifiée par l'URI du end-point correspondant. Normalement un unique routeur doit être associé à une end-point donné.

Déclaration :

```c
mal_routing_t *mal_routing_new(mal_endpoint_t *endpoint, void *state);
```

Paramètres :

  -	`endpoint` : end-point MAL
  -	`state` : état de du routeur, non typé pour permettre le polymorphisme

### Enregistrement des handlers

L'API du routeur MAL définit l'ensemble des fonctions permettant l'enregistrement des handlers d'interaction. Chacune de ces fonctions prend en paramètre le pointeur vers le routeur lui-même, l'identification de l'area, sa version, l’identité du service et de l'opération. En fonction du rôle du handler et du type de l'opération l'interface comprend des pointeurs vers les fonctions de traitement des messages correspondants de l'interaction.

L'API définit une fonction pour enregistrer un provider d'interaction Send, et deux fonctions permettant d'enregistrer les handlers de consumer et provider de chacune des interactions *Submit*, *Request*, *Invoke* et *Progress*;

```c
int mal_routing_register_provider_send_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_send);

int mal_routing_register_provider_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_submit);

int mal_routing_register_consumer_submit_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack);

int mal_routing_register_provider_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_request);

int mal_routing_register_consumer_request_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_invoke);

int mal_routing_register_consumer_invoke_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_response);

int mal_routing_register_provider_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_progress);

int mal_routing_register_consumer_progress_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_ack,
    mal_routing_on_message_fn *on_update,
    mal_routing_on_message_fn *on_response);
```

L'API offre en outre 3 fonctions permettant d'enregistrer un handler de publisher, de subscriber et de broker pour une interaction *PubSub* :

```c
int mal_routing_register_provider_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_publish_error,
    mal_routing_on_message_fn *on_publish_register_ack,
    mal_routing_on_message_fn *on_publish_deregister_ack);

int mal_routing_register_consumer_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_register_ack,
    mal_routing_on_message_fn *on_deregister_ack,
    mal_routing_on_message_fn *on_notify);

int mal_routing_register_broker_pubsub_handler(
    mal_routing_t *mal_routing,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation,
    mal_routing_on_message_fn *on_notify_error,
    mal_routing_on_message_fn *on_register,
    mal_routing_on_message_fn *on_deregister,
    mal_routing_on_message_fn *on_publish);
```

L'API offre aussi une fonction permettant de désenregistrer un Handler :

```c
int mal_routing_remove_handler(
    mal_routing_t *mal_routing,
    handler_type_t type,
    mal_ushort_t area, mal_uoctet_t area_version,
    mal_ushort_t service, mal_ushort_t operation);
```

### Exécution des handlers

Le routeur offre une fonction permettant d'activer un handler donné en fonction du message MAL reçu. Lorsqu'elle est appelée cette fonction recherche le handler correspondant dans la liste des handlers  enregistrés. En cas de succès elle active cet handler en appelant la fonction correspondant au message reçu.

```c
int mal_routing_handle(mal_routing_t *self, mal_message_t *message);
```

Paramètres :

  -	`self` : le routeur
  -	`message` : le message reçu

### Destructeur

Détruit le routeur et son état.

```c
void mal_routing_destroy(mal_routing_t **self_p);
```

Union des éléments
------------------

Une union `mal_element_t` est définie pour permettre le polymorphisme d'élément.

```c
union mal_element_t {
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
  int enumerated_value;
  void *composite_value;
  void *list_value;
};
```

Holder d'élément
----------------

Cette structure permet de gérer le décodage en cas de polymorphisme d'élément.

### Constructeur

Déclaration :

```c
mal_element_holder_t *mal_element_holder_new(void);
```

### Getters et setters

```c
bool mal_element_holder_get_presence_flag(mal_element_holder_t *self);

void mal_element_holder_set_presence_flag(mal_element_holder_t *self,
  bool presence_flag);

long mal_element_holder_get_short_form(mal_element_holder_t *self);

void mal_element_holder_set_short_form(mal_element_holder_t *self,
  long short_form);

union mal_element_t mal_element_holder_get_value(
  mal_element_holder_t *self);

void mal_element_holder_set_value(mal_element_holder_t *self,
  union mal_element_t value);
```

### Destructeur

```c
void mal_element_holder_destroy(mal_element_holder_t **self_p);
```

Ce destructeur ne libère que l'espace alloué pour la structure elle-même, mais pas les éléments de l'union.

Listes d'Attribut non pointeur
------------------------------

Structures de donnée définies pour représenter les listes des types d'Attribut qui ne sont pas représentés par un type C pointeur (voir section 2.6).
Ces listes sont spécifiques à chaque type d'Attribut non pointeur.
Pour chaque liste, deux tableaux sont définis :

  -	`presence_flags` : tableau des flags de présence pour chacun des éléments de la liste
  -	`content` : tableau contenant les valeurs des éléments de la liste ; si un élément est nul, sa valeur dans le tableau doit être affectée avec n'importe quelle valeur.

La taille des tableaux `presence_flags` et `content` doit être la même.

### Constructeur

Déclaration :

```c
mal_<attribute>_list_t *mal_<attribute>_list_new(
  unsigned int element_count);
```

Paramètres :

  -	`element_count` : nombre d'éléments dans la liste

### Getter

Des fonctions « getters » sont définies pour accéder aux champs :

```c
unsigned int mal_<attribute>_list_get_element_count(
  mal_<attribute>_list_t *self);

bool *mal_<attribute>_list_get_presence_flags(
  mal_<attribute>_list_t *self);

mal_<attribute>_t *mal_<attribute>_list_get_content(
  mal_<attribute>_list_t *self);
```

### Destructeur

Détruit la liste et son contenu (tableau des flags de présence et tableau des valeurs).

```c
void mal_<attribute>_list_destroy(mal_<attribute>_list_t **self_p);
```

Listes d'Attribut pointeur
--------------------------

Structures de donnée définies pour représenter les listes des types d'Attribut qui sont représentés par un type C pointeur (voir section 2.6).

### Constructeur

Déclaration :

```c
mal_<attribute>_list_t *mal_<attribute>_list_new(
  unsigned int element_count);
```

Paramètres :

  -	`element_count` : nombre d'éléments dans la liste

### Getters
Des fonctions « getters » sont définies pour accéder aux champs :

```c
unsigned int mal_<attribute>_list_get_element_count(
  mal_<attribute>_list_t *self);

mal_<attribute>_t **mal_<attribute>_list_get_content(
  mal_<attribute>_list_t *self);
```

### Destructeur

Détruit la liste, son contenu (tableau de pointeurs) et les éléments de la liste.

```c
void mal_<attribute>_list_destroy(mal_<attribute>_list_t **self_p);
```

Listes de Composite
-------------------
Voir section 9.6.

Listes d'énuméré
----------------
Voir section 9.7.

Etapes d'interaction
--------------------

Une constante est définie pour chaque étape d'interaction :

```c
#define MAL_IP_STAGE_SEND 1
#define MAL_IP_STAGE_SUBMIT 1
#define MAL_IP_STAGE_SUBMIT_ACK 2
#define MAL_IP_STAGE_REQUEST 1
#define MAL_IP_STAGE_REQUEST_RESPONSE 2
#define MAL_IP_STAGE_INVOKE 1
#define MAL_IP_STAGE_INVOKE_ACK 2
#define MAL_IP_STAGE_INVOKE_RESPONSE 3
#define MAL_IP_STAGE_PROGRESS 1
#define MAL_IP_STAGE_PROGRESS_ACK 2
#define MAL_IP_STAGE_PROGRESS_UPDATE 3
#define MAL_IP_STAGE_PROGRESS_RESPONSE 4
#define MAL_IP_STAGE_PUBSUB_REGISTER 1
#define MAL_IP_STAGE_PUBSUB_REGISTER_ACK 2
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER 3
#define MAL_IP_STAGE_PUBSUB_PUBLISH_REGISTER_ACK 4
#define MAL_IP_STAGE_PUBSUB_PUBLISH 5
#define MAL_IP_STAGE_PUBSUB_NOTIFY 6
#define MAL_IP_STAGE_PUBSUB_DEREGISTER 7
#define MAL_IP_STAGE_PUBSUB_DEREGISTER_ACK 8
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER 9
#define MAL_IP_STAGE_PUBSUB_PUBLISH_DEREGISTER_ACK 10
```
