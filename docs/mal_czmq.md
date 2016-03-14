Transport MAL/CZMQ
==================

Cette section décrit l'implémentation du transport `malzmq` sur l'API CZMQ. Il ne s'agit donc pas d'une description en terme de protocole (comme doit le faire le livre CCSDS MALZMQ) mais en terme d'API.

Le format d'encodage du header MAL est donné en annexe ###La même description doit être donnée par le livre MALZMQ.

Un message MAL est transporté dans une unique trame ZMQ (zframe).

Les sections suivantes décrivent l'implémentation du module MAL/CZMQ :

  -	Configuration du header MALZMQ
  -	Constructeur d'un contexte MALZMQ
  -	Démarrage
  -	Réception d'un message MAL
  -	Implémentation des fonctions virtuelles imposées par l'API MAL

Header MALZMQ
-------------

Une classe est définie pour gérer les spécificités du format de header MALZMQ (voir annexe 14.3) :

  -	Numéro de version du mapping MALZMQ.
  -	Catalogue de mapping.
  -	Flags de présence des champs de header MALZMQ optionnels.
  -	Valeur des champs non présents.


###	Constructeur

```c
malzmq_header_t *malzmq_header_new(
  malzmq_mapping_directory_t *mapping_directory,
  bool priority_flag, mal_uinteger_t priority,
  bool timestamp_flag, mal_identifier_t *network_zone,
  mal_identifier_t *session_name, mal_identifier_list_t *domain,
  mal_blob_t *authentication_id);
```

Paramètres :

  - `mapping_directory` : catalogue de mapping à utiliser pour l'encodage (cf ###), peut être NULL.
  - `priority_flag` : flag de présence du champ Priority dans le header MALZMQ.
  - `priority` : valeur du champ Priority s'il n'est pas présent dans le header MALZMQ.
  - `timestamp_flag` : flag de présence du champ Timestamp dans le header MALZMQ.
  - `network_zone` : valeur du champ Network Zone s'il n'est pas présent dans le header MALZMQ. Si NULL alors le champ Network Zone est présent dans le header MALZMQ.
  - `session_name` : idem pour le champ Session Name.
  - `domain` : idem pour le champ Domain.
  - `authentication_id` : idem pour le champ Authentication Id.

###	Paramètres de configuration

Certains champs du header MAL peuvent être toujours identiques pour une application. Les transférer lors de chaque appel serait redondant, et on peut donc optimiser les performances en les omettant du header MALZMQ. Ces champs sont les suivants : `PRIORITY`, `NETWORK_ZONE`, `SESSION_NAME`, `DOMAIN`, `AUTHENTICATION_ID`. La présence de ces champs dans le header MALZMQ, ainsi que leur éventuelle valeur globale, est définie dans le constructeur du header MALZMQ.

Un autre champ du header MAL, `TIMESTAMP`, peut également être omis du header MALZMQ. Cette éventuelle omission est également définie dans le constructeur du header MALZMQ. Il n'y a pas de valeur de remplacement définie pour ce champ.

Il va de soit que ces différents paramètres de configuration doivent être fournis de manière identique à toutes les entités communiquantes de l'application.

###	Catalogue de mapping

Le header du message MAL contient de nombreux champs dont la taille peut être importante : des URIs, des chaînes de caractère, etc. Afin d'optimiser les performances les messages échangés entre les instances de MAL/CZMQ transportent des champs encodés dans des types scalaires de taille moindre.

Afin de maintenir la compatibilité avec le MAL les champs des messages MAL/CZMQ ainsi encodés sont systématiquement transformés en leur équivalent MAL lors de leur accès par l'utilisateur de l'API MAL. Pour ce faire la correspondance des informations doit être maintenue tant coté consumer, que coté provider via un catalogue.

L'objet de cette section est de décrire l'API d'accès à ce catalogue et son usage.

#### Principes

Le catalogue de mapping conserve une correspondance entre des chaînes de caractères et des valeurs numériques. La valeur numérique est appelée `MDK` pour Mapping Directory Key.

Le catalogue permet de retrouver le MDK d'une chaîne côté encodage, et de retrouver la chaîne d'un MDK côté décodage.

Il n'est pas de la responsabilité du MAL/CZMQ de s'assurer de la cohérence du catalogue de chaque côté de l'interaction. Cette responsabilité revient à l'application. Le moyen le plus simple d'y parvenir est d'offrir un catalogue statique, fixé une fois pour toute à l'installation de l'application au niveau de tous les participants. Toutefois rien n'interdit à une application d'offrir une implantation plus dynamique du catalogue.

#### Encodage

L'encodage d'une chaîne sous sa forme MDK est optionnelle, afin de gérer le cas où il n'existe pas de MDK dans le catalogue correspondant à la chaîne à encoder. C'est pour cela que le mapping décrit en 14.3 fait référence à un type `Optional MDK`.

Le principe de l'encodage `Optional MDK` est dérivé de l'encodage MAL binary d'une chaîne de caractères. Cet encodage consiste normalement en l'encodage de la longueur de la chaîne, typée UInteger, suivi de l'encodage des caractères eux-mêmes. L'encodage `Optional MDK` transforme ce champ longueur de 32 bits en une valeur de type Integer, pour en exploiter séparément le signe et la valeur absolue. Le signe décrit la nature du champ représenté par la valeur absolue, à savoir un MDK si le signe est négatif, ou une longueur si le signe est positif. Dans le second cas les caractères de la chaîne sont encodés à la suite comme dans l'encodage MAL binary.

Une chaîne encodée sous sa forme MDK ne nécessite donc que 4 octets, représentant la valeur négative du MDK. Si elle n'est pas encodée sous sa forme MDK, une chaîne est conforme à son encodage MAL binary.

Le cas particulier d'une valeur nulle pour l'Integer initial correspond à l'encodage MAL binary, à savoir la chaîne vide. En conséquence un MDK doit être strictement positif.

#### API

Le catalogue de mapping, typé `malzmq_mapping_directory_t`, est fourni comme une table de fonctions.

```c
typedef struct _malzmq_mapping_directory_t malzmq_mapping_directory_t;
struct _malzmq_mapping_directory_t {
  malzmq_md_get_key_fn *get_key_fn;
  malzmq_md_get_string_fn *get_string_fn;
  malzmq_md_put_string_fn *put_string_fn;
};
```

Champs :

  - `get_key_fn` : renvoie le MDK d'une chaîne s'il existe dans le catalogue
  - `get_string_fn` : renvoie la chaîne correspondant à un MDK
  - `put_string_fn` : ajoute une chaîne au catalogue et renvoie le MDK correspondant.

Pour l'instant seules les deux premières fonctions sont utilisées par le MAL/CZMQ.

Voici le détail d'interface de chacune de ces fonctions.

```c
typedef int malzmq_md_get_key_fn(char *string, unsigned int *key);
```

Paramètres :

  - `string` : chaîne pour laquelle on recherche une éventuelle clef de correspondance. Ne doit pas être nulle.
  - `key` : valeur de retour du MDK correspondant à string, s'il existe.

Résultat :

  - 0 : exécution valide, valeur de retour key exploitable.
  - <0 : code d'erreur, valeur de retour key indéterminée.

```c
typedef int malzmq_md_get_string_fn(unsigned int key, char **string);
```

Paramètres :

  - `key` : MDK pour lequel on recherche une chaîne associée.
  - `string` : valeur de retour de la chaîne correspondant à key, si elle existe. Cette chaîne a été allouée et doit être libérée par free ou par les diverses fonctions spécifiques (mal_string_destroy, etc).

Résultat :

  - 0 : exécution valide, valeur de retour string exploitable.
  - <0 : code d'erreur, valeur de retour string indéterminée.

```c
typedef int malzmq_md_put_string_fn(char *string, unsigned int *key);
```

Paramètres :

  - `string` : chaîne pour laquelle on souhaite créer une clef de correspondance. Ne doit pas être nulle. Le catalogue ne doit pas conserver la chaîne telle quelle au delà de cet appel, afin de permettre à l'appelant de la libérer au besoin.
  - `key` : valeur de retour du MDK correspondant à string. Doit être strictement positive et strictement inférieure à 231. Cette valeur distinctive est créée si et seulement si il n'existait pas auparavant une autre valeur correspondante dans le catalogue.

Résultat :

  - 0 : exécution valide, valeur de retour key exploitable.
  - <0 : code d'erreur, chaîne non enregistrée dans le catalogue et valeur de retour key indéterminée.

Note :

les fonctions du catalogue ne travaillent que sur des chaînes (char*), car les différents types cibles `mal_string_t`, `mal_uri_t` et `mal_identifier_t`, ne sont eux-mêmes que des `char*`. Si ce n'était pas le cas, il faudrait que le catalogue fournisse des fonctions distinctes pour chacun de ces types.

####	Usage

Le catalogue n'est pour l'instant utilisé que pour les champs du header suivants : *URI from*, *URI to*, *Network Zone*, *Session Name*, *Domain*.

L'utilisation du catalogue pour des champs choisis du body est envisageable, mais casserait la conformité actuelle de l'encodage du body au format MAL binary.

Constructeur du contexte MALZMQ
-------------------------------

```c
malzmq_ctx_t *malzmq_ctx_new(
  mal_ctx_t *mal_ctx,
  malzmq_mapping_uri_t *mapping_uri,
  char *hostname, char *port, malzmq_header_t *malzmq_header,
  malbinary_encoder_t *encoder, malbinary_decoder_t *decoder,
  bool verbose);
```

Paramètres :

  - `mal_ctx` : le contexte MAL.
  - `mapping_uri` : fonctions de transformation de l'URI MAL d'un service en URI ZMQ. Ce mapping peut-être NULL, dans ce cas les fonctions de transformation d'URI par défaut de l'implantation sont utilisées (voir section ###).
  - `hostname` : addresse IP utilisée pour accepter les connexions entrantes.
  - `port` : port utilisé pour accepter les connexions entrantes.
  - `malzmq_header` : flags et champs optionnels. La configuration du header MALZMQ est globale au contexte MALZMQ.
  - `encoder` : contexte d'encodage utilisé pour encoder les headers MAL.
  - `decoder` : contexte de décodage utilisé pour décoder les headers MAL.
  - `verbose` : flag d'activation des traces.

Le constructeur effectue les actions suivantes :
  
  - Création d'une socket ZMQ de type ROUTER permettant d'accepter les connexions ouvertes par d'autres contextes MALZMQ distants : `SOCKET_MAL_ROUTER`. L'URI ZMQ utilisée par le bind est déterminée à partir des paramètres `hostname` et `port` et des fonctions de transformation d'URI passées en paramètre.
  - Création d'une socket ZMQ de type SUB permettant la réception des messages diffusés par les autres contextes MALZMQ : `SOCKET_MAL_SUB`. L'URI ZMQ utilisée par le bind est déterminée à partir des paramètres `hostname` et `port` et des fonctions de transformation d'URI passées en paramètre.
  - Création d'une socket ZMQ de protocole `inproc` et de type ROUTER permettant de communiquer avec les acteurs MALZMQ du contexte :  `SOCKET_Z_ROUTER`.
  -	Une `zloop` est créée pour gérer les deux sockets `ROUTER`.

###	Fonctions de transformation d'URI

La transformation des URI MAL en URI ZMQ est assurée par 3 fonctions :

  - La première get_p2p_zmquri prend en paramètre l'URI MAL d'un service et retourne l'URI ZMQ de bind du socket DEALER d'écoute du contexte MAL correspondant. Par exemple : `malzmq://host:port/service → tcp://*:port`
  - La seconde get_ps_zmquri prend en paramètre l'URI MAL d'un service et retourne l'URI ZMQ sur laquelle connecter le socket SUB d'écoute du contexte MAL correspondant. Par exemple : `malzmq://host:port/service → tcp://host:(port+1) ou pgm://itf;mcast_addr:(port+1)`
  - La dernière `get_zmquri_to` prend en paramètre un message MAL à émettre et retourne l'URI ZMQ correspondante en fonction de l'étape de l'interaction et de l'URI MAL du destinataire. Si l'URI du destinataire est `malzmq://host1:port1/service` :
◦	MAL_INTERACTIONTYPE_INVOKE, MAL_IP_STAGE_INVOKE
▪	tcp://host1:port1
◦	MAL_INTERACTIONTYPE_PUBSUB, MAL_IP_STAGE_PUBSUB_PUBLISH
▪	tcp://*:(port1+1) ou epgm://itf;mcast_addr:(port+1)

Les fonctions permettant la transformation des URI MAL en URI ZMQ sont passées au contexte MALZMQ au travers d'une structure malzmq_mapping_uri_t. Si ce paramètre est nul les fonctions définies par défaut dans le transport MALZMQ sont utilisées ; ces fonctions considèrent que le transport utilisé est TCP pour toutes les interactions et que le port utilisé pour le Publish / Subscribe est le port du service incrémenté de 1 (cf section ###).

```c
typedef mal_uri_t *malzmq_get_p2p_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_get_ps_zmquri_fn(mal_uri_t *maluri);
typedef mal_uri_t *malzmq_getzmquri_to_fn(mal_message_t *message);

typedef struct _malzmq_mapping_uri_t malzmq_mapping_uri_t;

struct _malzmq_mapping_uri_t {
  malzmq_get_p2p_zmquri_fn *get_p2p_zmquri_fn;
  malzmq_get_ps_zmquri_fn *get_ps_zmquri_fn;
  malzmq_getzmquri_to_fn *getzmquri_to_fn;
};
```

###	Mapping par défaut

Le mapping par défaut du transport MAL/CZMQ implanté dans le POC utilise le protocole TCP tant pour les communications Point-to-Point que Publish/Subscribe :

  -	malzmq_get_p2p_zmquri_fn
◦	malzmq://host:port/service → tcp://*:port
  -	typedef int malzmq_get_ps_zmquri_fn
◦	malzmq://host:port/service → tcp://host:port_ps, où port_ps=port+1
  -	typedef int malzmq_getzmquri_to_fn
◦	Si les champs interaction_type et interaction_stage du message passé en paramètre sont MAL_INTERACTIONTYPE_PUBSUB et MAL_IP_STAGE_PUBSUB_PUBLISH :
▪	malzmq://host1:port1/service → tcp://host1:port1_ps, où port1_ps=port1+1
◦	Dans tous les autres cas :
▪	malzmq://host1:port1/service → tcp://host1:port1

Démarrage
---------

La fonction suivante permet de démarrer le contexte MALZMQ. Cette fonction démarre la zloop et bloque tant que la zloop ne s'est pas terminée.

```c
int malzmq_ctx_start(malzmq_ctx_t *self);
```

Comportement de la zloop
------------------------

La zloop est en écoute (`SOCKET_MAL_ROUTER` et `SOCKET_MAL_SUB`) des messages émis par les acteurs MALZMQ distants. Lorsqu'un message ZMQ est reçu, les actions suivantes sont effectuées :

  -	Extraction et destruction de la première trame contenant l'identité de l'appelant. En effet, actuellement, les connexions ZMQ sont utilisées seulement à sens unique, en conséquence l'identité de l'appelant n'est pas conservée.
  -	La trame suivante n'est pas extraite (`zmsg_pop`) du message ZMQ mais seulement lue (`zmsg_next`) afin de permettre la réutilisation du message ZMQ pour l'envoyer à l'acteur destinataire.
  -	Seul le champ `URI To` est décodé. Ce champ donne l'identité de la socket `DEALER` utilisée par l'acteur destinataire.
  -	Le message ZMQ reçu est renvoyé à l'acteur destinataire au travers de `SOCKET_ACTOR_ROUTER`.

Réception d'un message par un end-point MALZMQ
----------------------------------------------

Lors de la demande de réception d'un message par un end-point MAL, le transport MALZMQ se met en écoute sur le socket connecté au socket router de la zloop.

A la réception d'un message MAL :

  -	La première et unique trame du message ZMQ est extraite.
  -	Une structure `mal_message` est instanciée.
  -	Les champs du header MAL sont décodés. Les champs optionnels non encodés du header MAL sont affectés à partir de la configuration du header MALZMQ qui est globale au contexte MALZMQ.
  -	Le corps du message est directement affecté à partir de la trame ZMQ (`data` de `zframe`) sans copie. En conséquence, la trame ZMQ ne peut être détruite qu'au moment de la destruction du message MAL (voir section 12.13). Le champ `body_owner` du message MAL est affecté avec la trame ZMQ.
  -	Le message MAL est retourné à l'appelant, la destruction du message MAL est à la responsabilité du traitant de ce message.

Fonction virtuelle de création d'URI
------------------------------------

Le format d'URI est le suivant :

```c
malzmq://<hostname>:<port>/<id>
```

Le protocole de transport utilisé par ZMQ n'est pas spécifié dans l'URI. Il est spécifié à la création du contexte MALZMQ.

Dans certains cas, le contexte MALZMQ pourrait optimiser la communication en utilisant un protocole de transport plus efficace, par exemple :

  - `ipc` : si le consumer et le provider sont sur la même machine (même 'hostname')
  - `inproc` : si le consumer et le provider sont dans le même processus (attention dans ce cas à l'ordre de démarrage car 'inproc' n'assure pas le découplage temporel des sockets ZMQ)

Cette optimisation n'est pour l'instant pas implémentée.

Fonction virtuelle de création de end-point
-------------------------------------------

Un end-point MALZMQ est créé et retourné comme résultat (en pointeur non typé `void *`).

Les données spécifiques au end-point MALZMQ sont :

  -	le contexte MALZMQ,
  -	le end-point MAL passé en paramètre de la fonction,
  -	la socket de réception des messages MAL routés par la zloop,
  -	une table de hash contenant les sockets ZMQ ouvertes vers des contextes MALZMQ distants.

Lors de l'initialisation du end-point, les actions suivantes sont effectuées :

  -	création d'une socket ZMQ de type DEALER
  -	affectation de l'identité de cette socket avec l'URI du end-point
  -	connexion de cette socket avec la socket router gérée par la zloop 

(ZLOOP_ENDPOINTS_SOCKET_URI)

Fonction virtuelle d'envoi de message
-------------------------------------
L'URI MAL destinataire du message est transformée en URI ZMQ :

  - Format d'URI MAL : `malzmq://<hostname>:<port>/<id>`
  - Format d'URI ZMQ : `<protocole zmq>://<hostname>:<port>`

Une socket de type DEALER connectée à cette URI est recherchée dans une table de hash appartenant à l'acteur (structure `malzmq_actor_data`). Si la socket n'est pas trouvée alors elle est créée et enregistrée dans la table (la clé étant l'URI ZMQ).

Le message MAL est encodé et transmis dans une unique trame ZMQ.

Fonction virtuelle de création de poller
----------------------------------------

Un poller MALZMQ est créé et retourné comme résultat (en pointeur non typé `void *`).

Les données spécifiques au poller MALZMQ sont :

  -	le contexte MALZMQ,
  -	le poller MAL passé en paramètre de la fonction,
  -	le zpoller permettant l'attente sur les sockets des end-points..
  -	la liste des end-points liés à ce poller

Lors de l'initialisation du poller, les actions suivantes sont effectuées :

  -	création d'un zpoller 
  -	création d'une liste vide de end-points


Fonction virtuelle d'ajout d'un end-point
-----------------------------------------

Cette fonction ajoute le end-point passé en paramètre au poller. Le end-point est ajouté à la liste du poller, le socket correspondant est ajouté au zpoller du poller.

Fonction virtuelle de suppression d'un end-point
------------------------------------------------

Cette fonction supprime le  end-point passé en paramètre du poller. Le end-point est supprimé de la liste du poller, le socket correspondant est supprimé du zpoller du poller.

Fonction virtuelle d'attente de message sur un poller
-----------------------------------------------------

Cette fonction se met en attente de réception d'un message sur le zpoller associé.

Si un message arrive avant l'expiration du timeout le end-point correspondant est recherché dans la liste des end-points et est retourné dans le paramètre correspondant. Si aucun end-point enregistré ne correspond une erreur est retournée.

Fonction virtuelle de destruction de message
--------------------------------------------

Cette fonction vérifie si le champ `body_owner` du message MAL est affecté.

Si c'est le cas, alors cela signifie que le message MAL a été créé (décodé) à partir d'une trame ZMQ (`zframe`) qui doit donc être détruite (`zframe_destroy`).
