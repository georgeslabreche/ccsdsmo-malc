Modèle d'exécution Acteur / Handler
===================================

L'acteur MAL utilise l'API MAL/C et en particulier les notions de **poller**, de **end-point** et de **handler**. Il repose sur la notion d'acteur CZMQ.

Acteur
------
Un acteur est en charge de l'exécution d'un ensemble de handlers d'interactions correspondant aux interactions d'un end-point donné. L'API permet l'ajout et la suppression dynamique de handlers. Afin d'éviter les problèmes liés au parallélisme, l'enregistrement et la suppression d'un handler ne peut s'effectuer que depuis l'acteur lui-même.
Un Handler ne peut être exécuté que par un unique acteur.

Un acteur réagit aux messages MAL indépendamment de tout rôle dans l'interaction. Lors de la réception d'un message il recherche le handler correspondant dans la liste des handlers  enregistrés. En cas de succès il active cet handler en appelant la fonction correspondant au message reçu, dans le cas contraire le message est détruit.

La durée de vie d'une interaction dépasse celle d'une réaction de l'acteur.

Seul l'acteur qui a reçu le message initiant une interaction peut répondre à cette interaction.

Un acteur possède les caractéristiques suivantes :

  -	Il correspond à un unique end-point, en conséquence :
      - Il ne peut utiliser qu'un unique transport (binding) pour recevoir et envoyer des messages MAL.
      - Il peut utiliser plusieurs formats d'encodage du corps de message MAL.
      - Il est identifié de manière unique par une URI MAL relative au contexte MAL et dont le format dépend du transport utilisé.
      - Il gère un compteur de 'Transaction Id' (champ du header MAL)
  -	Il possède un état.
  -	Il a un cycle de vie à 3 trois états :
      - Lors de sa création la fonction `initialize` est appelée avant de le lancement de la boucle de traitement des messages entrants.
      - La fonction `handle` est appelée par la boucle de réception des messages pour rechercher le handler correspondant au message reçu et l'activer.
      - Lors de son arrêt la fonction `finalize` est appelée avant sa destruction.
  -	Les fonctions `initialize` et `finalize` sont personnalisables par l'utilisateur.
  -	Il est exécuté de manière mono-threadée.
  -	Son état n'est modifiable qu'au travers des réactions des Handlers.
  -	Son état n'est pas transmissible à un autre acteur.

Si un mode d'exécution multi-threadé est nécessaire, par exemple pour effectuer un traitement coûteux en CPU, alors le Handler doit déléguer l'exécution de ce traitement à différents acteurs. Le traitement est donc exécuté en parallèle, et la charge associée est partagée entre ces acteurs.

L'acteur définit un end-point spécifique correspondant au socket d'écoute de l'acteur C/ZMQ sous-jacent, il utilise la notion de poller MAL pour écouter simultanément le end-point utilisateur et ce end-point interne. Ce end-point interne permet la réception de commandes envoyées à l'acteur, par la fontion `mal_actor_send_command`.

API Actor MAL
-------------

### Constructeur

Crée une instance d'acteur identifiée par une URI MAL. La création d'un acteur entraîne la création d'un end-point correspondant à l'URI MAL de cet acteur, et d'un routeur pour la gestion des handlers de cet acteur. L'état de ce routeur est l'état de l'acteur.

Un compteur de `Transaction Id` est géré.

Déclaration :

```c
mal_actor_t *mal_actor_new(
  mal_ctx_t *mal_ctx,
  mal_uri_t *uri,
  void *state,
  mal_actor_initialize_fn *initialize,
  mal_actor_finalize_fn *finalize);
```

Paramètres :

  - `mal_ctx` : contexte MAL
  - `uri` : URI MAL identifiant l'acteur MAL
  - `state` : état de l'acteur; non typé pour permettre le polymorphisme
  - `initialize` : fonction d'initialisation de l'acteur
  - `finalize` : fonction de terminaison de l'acteur

### Fonction virtuelle d'initialisation de l'acteur MAL

Déclaration :

```c
typedef int mal_actor_initialize_fn(void *self, mal_ctx_t *mal_ctx,
  mal_actor_t *mal_actor);
```

Paramètres :

  - `self` : état de l'acteur
  - `mal_ctx` : référence du contexte MAL
  - `mal_actor` : référence de l'acteur

Résultat :

Code d'erreur

### Fonction virtuelle de terminaison de l'acteur MAL

Déclaration :

```c
typedef int mal_handler_finalize_fn(void *self, mal_ctx_t *mal_ctx,
  mal_actor_t *mal_actor);
```

Paramètres :

  - `self` : état de l'acteur
  - `mal_ctx` : référence du contexte MAL
  - `mal_actor` : référence de l'acteur

Résultat :

Code d'erreur

### Envoi de message MAL

L'envoi de messages MAL se fait au travers du end-point intégré à l'acteur (voir interface définie en 7.4.2). L'interface de l'acteur définit une fonction permettant de retrouver le end-point correspondant :

```c
mal_endpoint_t *mal_actor_get_mal_endpoint(mal_actor_t *self);
```

### Enregistrement des handlers

L'enregistrement des handlers de l'acteur se fait au travers du routeur intégré à l'acteur ( voir interface définie en 7.6.3). L'interface de l'acteur définit une fonction permettant de retrouver le routeur correspondant :

```c
mal_routing_t *mal_actor_get_router(mal_actor_t *self);
```

### Envoi de commandes à l'acteur MAL

L'envoi de commandes à l'acteur MAL au travers de son end-point interne peut s'effectuer au travers de la fonction :

```c
int mal_actor_send_command(mal_actor_t *to, char *cmd);
```

Cette fonction prend en paramètre l'acteur destinataire et la chaine de caractère contenant la commande. Par exemple :

```c
mal_actor_send_command(actor, "$TERM");
```

### Destructeur

Détruit l'acteur et son état.

```c
void mal_actor_destroy(mal_actor_t **self_p);
```

### Exemple simple d'application MAL

Dans cet exemple nous reprenons le code de l'exemple du chapitre 4 mais en utilisant la librairie d'acteurs présentée dans ce chapitre. Une part importante du code est identique et nous ne détaillerons que les aspects spécifiquement liés à l'usage du framework d'acteurs MAL.

### Composant consumer

Lors de la création du composant concumer on crée un acteur MAL pour sa gestion :

```c
send_app_myconsumer_t *consumer = send_app_myconsumer_new(
  provider_uri,
  authentication_id, qoslevel, priority, domain, network_zone, session,
  session_name, MALBINARY_FORMAT_CODE, encoder, decoder);
```

```c
mal_uri_t *consumer_uri = mal_ctx_create_uri(mal_ctx, "send_app/myconsumer");
mal_actor_t *consumer_actor = mal_actor_new(
  mal_ctx,
  consumer_uri, consumer,
  send_app_myconsumer_initialize, send_app_myconsumer_finalize);
```

Deux fonctions d'initialisation et de terminaison sont spécifiées à l'acteur, la fonction d'initialisation nous permet d'initier l'interaction SEND vers le provider. Ce code correspond au code la méthode run décrit en section 4.1.2.

### Composant Provider

Lors de la création du composant provider on crée un acteur MAL pour sa gestion :

```c
send_app_myprovider_t *provider =
  send_app_myprovider_new(MALBINARY_FORMAT_CODE, encoder, decoder);
```

```c
mal_actor_t *provider_actor = mal_actor_new(
  mal_ctx,
  provider_uri, provider,
  send_app_myprovider_initialize, send_app_myprovider_finalize);
```

Deux fonctions d'initialisation et de terminaison sont spécifiées à l'acteur, la fonction d'initialisation permettra entre autre d'enregistrer les handlers du provider. La réception de message est maintenant implicitement gérée par l'acteur MAL :

  -	Lors de la réception d'un message MAL sur le end-point correspondant à l'URI du provider le handler enregistrés en automatiquement exécuté.
  -	Dans le cas contraire le message est détruit.

### Lancement de l'application

Les composants consumer et provider sont maintenant des acteurs MAL, ils ne nécessitent donc plus la création explicite d'un acteur ZMQ pour les exécuter :

```c
send_app_create_provider(verbose, mal_ctx, provider_uri, encoder, decoder);
send_app_create_consumer(verbose, mal_ctx, provider_uri, encoder, decoder);
```

Le code de lancement de l'application est par ailleurs identique :

  -	création du contexte MAL,
  -	création des encoder et decoder,
  -	création du transport MALZMQ,
  -	démarrage du contexte MAL.
