API MAL en C et transport MAL/CZMQ
==================================


Introduction
============

L'API C représente tous les concepts MAL, en particulier les patterns d'interaction, le format de message MAL et le modèle de données.
L'objectif principal de l'API C est d'offrir une version simplifiée des fonctions de l'API MAL en Java. La complexité inhérente au standard MAL doit être conservée. Cependant, plusieurs aspects complexes de l'API MAL en Java peuvent être simplifiés ou abandonnés, soit parce qu'ils ne sont pas indispensables, soit parce qu'ils sont liés à des choix de conception différents (par exemple l'approche orientée appel de procédure, RPC), soit parce qu'ils peuvent être améliorés (par exemple la liaison forte entre transport et encodage).

Les éléments de complexité suivants sont inhérents au standard MAL. Ils doivent être conservés :

  -	Séparation des fonctions de transport, d'encodage et de contrôle d'accès : multiples APIs et fonctions abstraites
  -	Patterns d'interaction complexes : *Invoke*, *Progress*, *Publish-Subscribe*
  -	Polymorphisme d'élément MAL, limité au dernier élément d'un corps de message
  -	Polymorphisme d'Attribut MAL
  -	Héritage de structure

Polymorphisme d'élément MAL
---------------------------

Le livre MAL autorise l'utilisation du polymorphisme d'élément à condition qu'il ne soit appliqué qu'au dernier élément d'un corps de message. Ce dernier élément peut être déclaré avec les types suivants :

  -	`MAL::Element`
  -	un type `Composite` abstrait
  -	une liste d'éléments de type `MAL::Element`
  -	une liste d'éléments de type `Composite` abstrait
  -	une liste d'éléments de type `MAL::Attribute`

Les types listés ci-dessus sont réservés au polymorphisme du dernier élément d'un corps de message. Ils ne peuvent pas être utilisés pour un champ de Composite.

Les listes d'éléments de type abstrait (`Composite`, `MAL::Element` ou `MAL::Attribute`) ne peuvent pas être instanciées : il n'y a pas de structure de liste pouvant contenir des éléments de type abstrait (et donc des éléments de plusieurs types conformes à ce type abstrait). Par exemple :

  -	`List<MAL::Element>`, `List<MAL::Attribute>` ne peuvent pas être instanciées
  -	`List<MAL::UpdateHeader>`, `List<MAL::Boolean>` peuvent être instanciées

En conséquence, une structure liste contient nécessairement des éléments de même type et de type non abstrait.

Polymorphisme d'Attribut MAL
----------------------------
Le livre MAL autorise l'utilisation du polymorphisme d'attribut pour le dernier élément d'un corps de message et pour les champs de Composite.
Le polymorphisme d'Attribut consiste à déclarer un élément ou un champ avec le type MAL::Attribute.

Concepts
========

La plupart des concepts de l'API MAL en C sont imposés par la spécification MAL : message MAL, champs de header, types de données. Cependant, la spécification MAL ne définit pas certains concepts qui sont propres à l'implémentation de la spécification. Cette section présente uniquement ces concepts.

End-Point
---------

Le end-point MAL est l'entité qui permet d'émettre et de recevoir des messages MAL. Chaque end-point est associé à une unique URI de service MAL, l'API MAL permet la création et la suppression dynamique de end-point.

Seul le end-point qui a reçu le message initiant une interaction peut répondre à cette interaction.

Un end-point possède les caractéristiques suivantes :

  -	Il ne peut utiliser qu'un unique transport (binding) pour recevoir et envoyer des messages MAL.
  -	Il peut utiliser plusieurs formats d'encodage du corps de message MAL.
  -	Il est identifié de manière unique par une URI MAL relative au contexte MAL et dont le format dépend du transport utilisé.
  -	Il doit être exécuté de manière mono-threadée.
  -	Il gère un compteur de `Transaction Id` (champ du header MAL).

Poller
------

Le poller MAL est une entité qui permet d'attendre l'arrivée d'un message sur de multiples end-points. L'API MAL permet la création et la suppression dynamique de pollers, l'ajout et la suppression de end-point au poller.

Un poller possède les caractéristiques suivantes :

  -	L'ensemble des end-points d'un poller doivent dépendre d'un même contexte MAL et donc d'un unique transport (binding).
  -	Il doit être exécuté de manière mono-threadée.

L'usage du poller MAL n'est pas obligatoire, il est utile dans différents cas :

  -	Gestion de multiples end-points au travers d'un flot d'exécution unique,
  -	Réception non bloquante de messages.

Handler et Routage
------------------

Ces concepts sont offerts afin de faciliter la distribution des messages MAL reçus aux fonctions de traitement, leur utilisation est optionnelle.

Un Handler est un traitant d'interaction MAL, il s'exécute de manière asynchrone quand il est notifié de l'arrivée d'un message MAL et envoie en retour zéro, un ou plusieurs messages MAL, soit pour initier de nouvelles interactions (rôle du consumer), soit pour répondre à l'interaction en cours (rôle du provider).

Chaque handler possède une interface dépendant de son rôle (provider, consumer, etc.) et de l'interaction dans laquelle il intervient (send, submit, etc.). Par exemple pour une interaction Progress :

  -	Le handler du provider doit offrir la fonction : `on_progress`
  -	Le handler du consumer doit offrir les fonctions : `on_ack`, `on_update` et `on_response`.

Chacune de ces fonctions est appelée avec les paramètres suivants :

  -	un pointeur sur l'état du router (cf 7.6),
  -	un pointeur sur le contexte MAL (cf 7.2),
  -	un pointeur sur le end-point MAL (cf 7.4),
  -	et un pointeur sur le message MAL (cf 7.3).

L'API MAL offre une classe helper (mal_routing) qui simplifie la gestion des Handlers d'un end-point donné, cette classe mal_routing permet d'enregistrer les handlers correspondants aux différentes interactions attendues, puis lors de la réception d'un message par le end-point d'activer le handler correspondant pour qu'il traite le message.

Les routeurs possèdent un état partagé par l'ensemble des handlers qu'ils gèrent.

MAL Broker
----------

Dans notre implantation du transport ZMQ le Publish/Subscribe est partiellement supporté par le transport ZMQ au travers des sockets PUB/SUB de ZMQ. Afin de respecter la sémantique du pattern Publish/Subscribe du MAL il est cependant nécessaire d'implanter un composant Broker gérant les souscriptions et le filtrage des messages.

Afin de respecter le mode de fonctionnement de ZMQ ce composant Broker sera localisé coté Consumer. Actuellement il est implanté sous la forme d'un Handler (section 2.3) particulier que l'utilisateur de l'API peut modifier.

Transformation d'URI
--------------------

ZMQ peut utiliser de multiples protocoles sous-jacents pour communiquer. Par exemple des communications point-à-point peuvent passer par TCP entre des processus de machines différentes, des IPC entre processus de la même machine ou des mécanismes internes dans un même processus. De même, le Publish/Subscribe peut être mis en œuvre au travers de TCP, PGM ou EPGM.

Le transport MALZMQ utilise différents flots de communication selon les interactions, dans notre prototype chaque contexte MAL écoute sur 2 sockets différents :

  - Un socket `DEALER` pour les communications point-à-point
  - Un socket `SUB` pour les communications multicast.

Afin d'assurer la transformation de l'URI MAL d'un service en URI ZMQ nécessaire à la réalisation d'une interaction et afin d'offrir à l'utilisateur une grande liberté de configuration nous avons choisi d'externaliser cette transformation au travers d'upcalls (section 12.2.1).

Attributs pointeurs
-------------------

Les attributs pointeurs sont les attributs MAL dont la représentation en C est un type pointeur : `MAL::Blob`, `MAL::Identifier`, `MAL::String` et `MAL::URI`.

Pour ces attributs, la valeur `NULL` (pointeur nul) est autorisée.

Pour les autres attributs (non pointeurs), la valeur nulle est représentée par un champ additionnel (de type booléen) appelé « flag de présence ».

Vue d'ensemble de l'API C
=========================

L'API C est constituée de plusieurs APIs :

  -	**API d'attribut MAL** : Les attributs MAL sont extraits de l'API MAL afin d'éviter une double-dépendance entre l'API MAL (qui dépend des APIs d'encodage) et les APIs d'encodage (qui dépendent des attributs MAL).
  -	**APIs d'encodage** : Les APIs d'encodage sont définies de manière spécifique à un format d'encodage.
  -	**API MAL** : L'API MAL permet l'utilisation des concepts de niveau MAL.
  - **APIs d'Area** (générées) : L'API MAL contient l'API d'Area générée à partir de la définition de l'Area MAL.
  -	**APIs de transport** : qui gère le mapping des concepts MAL sur les concepts sous-jacents du transport choisi.
  -	**API d'extraction de paramètres de configuration**.

La plupart des concepts sont représentés chacun par une classe conforme au modèle Class de zproject :

  -	une structure opaque (seul le type est visible, pas le contenu) déclarée dans le header principal de l'API (`<api>.h`)
  -	un fichier « include » : `<nom de classe>.h`
  -	un fichier « source » : `<nom de classe>.c`

Les noms de classe sont en caractères minuscules, avec séparateur '_', et sont préfixés du nom de l'API. Par exemple, le concept de end-point, défini dans l'API MAL, est représenté par une classe nommée : `mal_endpoint`.

Les noms des classes représentant des types de données sont préfixés des noms de leur Area et leur Service (si existant). Par exemple le type MAL::Blob (défini dans l'area MAL, sans Service intermédiaire) est nommé : `mal_blob`.

Les autres conventions sont propres au modèle *CLASS*.


