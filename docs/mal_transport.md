APIs de transport
=================

Les APIs de transport sont définies de manière spécifique à un « binding », par exemple MALZMQ.

Plusieurs fonctions virtuelles sont imposées par la couche MAL, par exemple la fonction d'envoi de message (section 7.1.8). Ainsi, le code applicatif peut envoyer un message sans dépendre de l'API spécifique du transport utilisé.

Le code des services (consumer, provider) ne dépend pas de l'API de transport. Il utilise seulement l'API MAL.
Le nom donné en C au transport (binding) MALZMQ est : `malzmq`
Ce nom est une chaîne de caractères utilisée pour le nommage des APIs.

Contexte de Binding
-------------------

```c
<binding>_ctx.h
```

### Constructeur

Déclaration :

```c
<binding>_ctx_t *<binding>_ctx_new(mal_ctx_t *mal_ctx);
```

Paramètre :

  -	`mal_ctx` : le context MAL utilisant le transport créé

Résultat :

le transport créé

### Création d'une URI

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour créer une URI  (voir 7.1.1).

Déclaration :

```c
mal_uri_t *<binding>_ctx_create_uri(void *self, char *id);
```

Paramètre :

  -	`self` : la référence du module de transport
  -	`id` : identifiant unique dans le contexte MALZMQ

Résultat :

l'URI créée

### Création de end-point

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour créer un end-point  (voir 7.1.2).

Déclaration :

```c
void *<binding>_ctx_create_endpoint(
  void *self,
  mal_endpoint_t *endpoint);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`mal_endpoint` : end-point MAL correspondant au end-point physique du transport

Retour :

La référence du end-point créé par le transport

### Envoi de message MAL

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour envoyer un message MAL (voir 7.1.8).

Déclaration :

```c
int <binding>_ctx_send_message(void *self,
  mal_endpoint_t *mal_endpoint, mal_message_t *message);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`mal_endpoint` : le end-point qui envoie le message
  -	`message` : message MAL à envoyer

Résultat :

Code d'erreur

### Destruction de message MAL
Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour détruire un message MAL (voir 7.1.10).

Déclaration :

```c
int <binding>_ctx_destroy_message(void *self, mal_message_t *message);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`message` : message MAL à détruire

Résultat :

Code d'erreur

### Destruction de end-point

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour détruire un end-point (voir 7.1.3).

Déclaration :

```c
void <binding>_ctx_destroy_endpoint(void *self, void **endpoint_p);
```

### Création de poller

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour créer un end-point  (voir 7.1.4).

Déclaration :

```c
void *<binding>_ctx_create_poller(
  void *self,
  mal_poller_t *poller);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`mal_poller` : poller MAL correspondant au poller physique du transport

Retour :

La référence du poller créé par le transport

### Ajout / Suppression de end-point au poller

Ces fonctions doivent être conformes aux fonctions virtuelles définies par l'API MAL pour ajouter ou supprimer un end-point du poller (voir 7.1.5).

Déclaration :

```c
int malzmq_ctx_poller_add_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);

int malzmq_ctx_poller_del_endpoint(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t *mal_endpoint);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`mal_poller` : poller MAL correspondant au poller physique du transport
  -	`mal_endpoint` : end-point MAL à ajouter ou supprimer du poller

Retour : 

Code d'erreur

### Attente de message sur le poller

Ces fonctions doivent être conformes aux fonctions virtuelles définies par l'API MAL pour attendre la réception d'un message sur un des end-points du poller (voir 7.1.6).

Déclaration :

```c
int malzmq_ctx_poller_wait(
    void *self,
    mal_poller_t *mal_poller,
    mal_endpoint_t **mal_endpoint,
    int timeout);
```

Paramètres :

  -	`self` : la référence du module de transport
  -	`mal_poller` : poller MAL correspondant au poller physique du transport
  -	`mal_endpoint` : le end-point sur lequel un message est en attente de réception
  -	`timeout` : le temps d'attente maximum, éventuellement infini (-1)

Retour : 

Code d'erreur

### Destruction du poller

Cette fonction doit être conforme à la fonction virtuelle définie par l'API MAL pour détruire un poller (voir 7.1.7).

Déclaration :

```c
void <binding>_ctx_destroy_poller(void *self, void **poller_p);
```

### Destructeur

Détruit le contexte MALZMQ.

```c
void <binding>_ctx_destroy(<binding>_ctx_t **self_p);
```