Exemple simple d'application MAL
================================

Cette section met en pratique les concepts de l'API MAL en C en programmant une application MAL très simple qui s'exécute dans une unique fonction 'main'.

Deux types de code sont distingués :

  -	le code des composants constituant l'application. Dans cet exemple, deux composants sont créés. Pour simplifier l'application, chaque composant est limité à un seul rôle : « provider » ou « consumer » de service. Un service de test très simple est défini dans une area de service nommée « TestArea » (voir section 14.1).
  -	le code de lancement de l'application

Le code des composants ne dépend que de l'API MAL et de l'API générée à partir de la définition de TestArea.

Le code de lancement de l'application (fonction 'main') dépend de l'API MAL et également de l'API de transport 'malzmq'.

Cet exemple utilise le modèle d'exécution des acteurs CZMQ.

Seul le code non généré est présenté dans les sections suivantes.

Composant « consumer »
----------------------

Dépendances avec l'API MAL et l'API du service (code généré) :

	#include "mal.h"
	#include "testarea.h"

### Constructeur

Dans cet exemple de code, tous les paramètres nécessaires au fonctionnement du consumer sont  donnés lors de sa création :

  -	le end-point du consumer
  -	l'URI du provider (auquel le consumer s'adresse)
  -	les paramètres de l'entête de message MAL, par exemple l'identifiant d'authentification
  -	l'identifiant du format d'encodage
  -	les contextes d'encodage (non typés pour éviter la dépendance avec 'malbinary')

Déclaration :

```c
	simple_app_myconsumer_t *simple_app_myconsumer_new(
	  mal_endpoint_t *endpoint,
	  mal_uri_t *provider_uri,
	  mal_blob_t *authentication_id,
	  mal_qoslevel_t qoslevel,
	  mal_uinteger_t priority,
	  mal_identifier_list_t *domain,
	  mal_identifier_t *network_zone,
	  mal_sessiontype_t session,
	  mal_identifier_t *session_name,
	  int encoding_format_code,
	  void *encoder, void *decoder);
```

### Implémentation

Dans cet exemple un acteur CZMQ lié au composant « consumer » initie une interaction MAL lors de son démarrage. La signature doit être conforme à la fonction virtuelle de l'acteur définie dans l'API CZMQ :

```c
	void simple_app_myconsumer_run(zsock_t *pipe, void *self) {
```

La référence `self` est castée pour obtenir l'état de l'acteur (le « consumer »):

```c
	simple_app_myconsumer_t *consumer = (simple_app_myconsumer_t *) self;
```

L'URI du provider est récupérée à partir de l'état du consumer :

```c
	mal_uri_t *uri_to = consumer->provider_uri;
```

Une structure de donnée `TestComposite` est instanciée :

```c
	testarea_testservice_testcomposite_t *testcomposite =
	  testarea_testservice_testcomposite_new();
```

Allocation d'une String MAL à partir de la chaîne statique « hello world » :

```c
	mal_string_t *str = mal_string_new("hello world");
```

Affectation du champ `stringField` :

```c
	testarea_testservice_testcomposite_set_stringfield(testcomposite, str);
```

A partir de ce point la structure testcomposite est responsable de la libération de la String str. Réciproquement l'usage de la String n'est possible que tant que la structure n'a pas été libérée.

Le champ `intField` peut être nul. Il est donc nécessaire d'affecter le flag de présence pour ce champ (à la valeur `true`), puis d'affecter la valeur du champ (`10`) :

```c
	testarea_testservice_testcomposite_intfield_set_present(
	  testcomposite,
	  true);
	testarea_testservice_testcomposite_set_intfield(testcomposite, 10);
```

Une structure de donnée `List<MAL::String>` est instanciée :

```c
	mal_string_list_t *string_list = mal_string_list_new(2);
	mal_string_t **string_list_content =
	  mal_string_list_get_content(string_list);
	string_list_content[0] = mal_string_new("list-element-1");
	string_list_content[1] = mal_string_new("list-element-2");
```

Pour tester le polymorphisme, une structure `TestFinalCompositeA` est instanciée (elle hérite de `TestAbstractComposite`) :

```c
	testarea_testservice_testfinalcompositea_t *testfinalcompositea =
	  testarea_testservice_testfinalcompositea_new();
	testarea_testservice_testfinalcompositea_set_intfield(
	  testfinalcompositea, 20);
	testarea_testservice_testfinalcompositea_set_intfield2(
	  testfinalcompositea, 30);
```

La taille du corps de message encodé est calculée en faisant appel à une fonction générée pour chaque élément du corps de message.

Calcul de la taille d'encodage du premier élément (index '0' pour l'initiation de l'étape `send` de l'opération `testSend`) :

```c
	unsigned int body_length = 0;
	rc = testarea_testservice_testsend_send_add_encoding_length_0(
	  consumer->encoding_format_code,
	  consumer->encoder, testcomposite, &body_length);
```

Calcul de la taille d'encodage du deuxième élément (index '1') :

```c
	rc = testarea_testservice_testsend_send_add_encoding_length_1(
	  consumer->encoding_format_code,
	  consumer->encoder, string_list, &body_length);
```

Calcul de la taille d'encodage du troisième élément (index '2'), avec polymorphisme :

```c
	rc = testarea_testservice_testsend_send_add_encoding_length_2_testarea_
	testservice_testfinalcompositea(
	  consumer->encoding_format_code,
	  consumer->encoder, testfinalcompositea, &body_length);
```

Création d'un message MAL, avec passage en paramètre :

  -	des champs de header MAL contenus dans l'état du Handler
  -	de la taille d'encodage du corps de message : `body_length`

```c
	mal_message_t *message = mal_message_new(uri_to,
	  consumer->authentication_id,
	  consumer->qoslevel, consumer->priority, consumer->domain,
	  consumer->network_zone, consumer->session, consumer->session_name,
	  body_length);
```

Encodage du premier élément (index '0') :

```c
	unsigned int offset = mal_message_get_body_offset(message);
	char *bytes = mal_message_get_body(message);
	rc = testarea_testservice_testsend_send_encode_0(
	  consumer->encoding_format_code, bytes, &offset,
	  consumer->encoder, testcomposite);
```

Encodage du deuxième élément (index '1') :

```c
	rc = testarea_testservice_testsend_send_encode_1(
	  consumer->encoding_format_code, bytes, &offset,
	  consumer->encoder, string_list);
```

Encodage du troisième élément (index '2') :

```c
	rc = testarea_testservice_testsend_send_encode_2_testarea_testservice_
	testfinalcompositea(
	  consumer->encoding_format_code, bytes, &offset,
	  consumer->encoder, testfinalcompositea);
```

Envoi du message (initiation de l'étape `send` de l'opération `testSend`) :

```c
	rc = testarea_testservice_testsend_send(
	  consumer->endpoint,
	  message,
	  consumer->provider_uri);
```

Destruction des données allouées :

```c
	testarea_testservice_testcomposite_destroy(&testcomposite);
	mal_string_list_destroy(&string_list);
	testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);
```

Composant « provider »
----------------------

Dépendances avec l'API MAL et l'API du service (code généré) :

	#include "mal.h"
	#include "testarea.h"

### Constructeur

Dans cet exemple de code, tous les paramètres nécessaires au fonctionnement du provider sont  donnés lors de sa création :

  -	le end-point MAL du provider
  -	l'identifiant du format d'encodage
  -	les contextes d'encodage (non typés pour éviter la dépendance avec 'malbinary')

Déclaration :

	simple_app_myprovider_t simple_app_myprovider_new(
	  mal_endpoint_t *endpoint,
	  int encoding_format_code,
	  void *encoder, void *decoder);

### Implémentation

Dans cet exemple un acteur CZMQ est lié au composant « provider » et enregistre un handler  lors de son démarrage. La signature doit être conforme à la fonction virtuelle de l'acteur définie dans l'API CZMQ :

	void simple_app_myprovider_run(zsock_t *pipe, void *self) {

Afin de faciliter la distribution des messages un routeur est créé :

	mal_routing_t *router = mal_routing_new(self->endpoint, self);

Puis pour permettre son fonctionnement un handler correspondant au rôle provider de l'interaction Send doit être dynamiquement enregistré au près de l'acteur :

	rc = mal_routing_register_provider_send_handler(
	     router,
	     TESTAREA_AREA_NUMBER,
	     TESTAREA_AREA_VERSION,
	     TESTAREA_TESTSERVICE_SERVICE_NUMBER,
	     TESTAREA_TESTSERVICE_TESTSEND_OPERATION_NUMBER,
	     simple_app_myprovider_testarea_testservice_testsend);

Ces appels sont réalisés dans la fonction d'initialisation de l'acteur.
Enfin l'acteur se met en attente de réception d'un message sur le end-point :

	mal_message_t *message = NULL;
	rc = mal_endpoint_recv_message(self->endpoint, &message);

Puis il demande l'activation du handler correspondant au travers du routeur et détruit ce message si il n'a pu être traité par aucun handler :

	if (message != NULL) {
	  rc = mal_routing_handle(router, message);
	  if (rc != 0)
	    mal_message_destroy(
	      message,
	      mal_endpoint_get_mal_ctx(self->endpoint));

Le handler peut alors réagir à la réception du message MAL correspondant via la fonction correspondante dont la signature doit être conforme à la fonction virtuelle de Handler définie dans l'API MAL (voir section 7.6.1). Le code de dispatch renvoie donc vers une fonction spécifique au traitement de l'opération 'testSend'. :

	int simple_app_myprovider_testarea_testservice_testsend(
	  void *self,
	  mal_ctx_t *mal_ctx,
	  mal_endpoint_t *mal_endpoint,
	  mal_message_t *message) {

La référence 'self' est castée pour obtenir l'état du router commun à tous les handlers enregistrés (le « provider »):

	  simple_app_myprovider_t *provider = (simple_app_myprovider_t *) self;

Décodage du premier élément du corps de message :

	  testarea_testservice_testcomposite_t *parameter_0 = NULL;
	  unsigned int offset = mal_message_get_body_offset(message);
	  char *bytes = mal_message_get_body(message);
	  rc = testarea_testservice_testsend_send_decode_0(
	    provider->encoding_format_code, bytes, &offset,
	    provider->decoder, &parameter_0);
	  if (rc < 0) {
	    // destruction des paramètres décodés (voir plus bas)
	    return rc;
	  }

Décodage du deuxième élément du corps de message :

	  mal_string_list_t *parameter_1;
	  rc = testarea_testservice_testsend_send_decode_1(
	    provider->encoding_format_code, bytes, &offset,
	    provider->decoder, &parameter_1);
	  if (rc < 0) {
	    // destruction des paramètres décodés (voir plus bas)
	    return rc;
	  }

Décodage du troisième élément du corps de message (avec polymorphisme) :

	  mal_element_holder_t parameter_2;
	  rc = testarea_testservice_testsend_send_decode_2(
	    provider->encoding_format_code, bytes, &offset,
	    provider->decoder, &parameter_2);
	  if (rc < 0) {
	    // destruction des paramètres décodés (voir plus bas)
	    return rc;
	  }

La valeur des paramètres décodés peut être nulle.

Le troisième paramètre nécessite de tester la valeur du 'short_form' avant de faire le cast :

	if (parameter_2.presence_flag && parameter_2.short_form ==
	    TESTAREA_TESTSERVICE_TESTFINALCOMPOSITEA_SHORT_FORM) {
	  testarea_testservice_testfinalcompositea_t *testfinalcompositea =
	    (testarea_testservice_testfinalcompositea_t *) parameter_2;
	  ...

Destruction de la donnée :

	  testarea_testservice_testfinalcompositea_destroy(&testfinalcompositea);

Fin du traitement du troisième paramètre :

	}

Enfin, les premier et deuxième paramètres sont détruits :

	  testarea_testservice_testcomposite_destroy(&parameter_0);
	  mal_string_list_destroy(&parameter_1);

Le message est également détruit :

	mal_message_destroy(&message, mal_ctx);

Lancement de l'application
--------------------------

Les dépendances nécessaires sont :

  -	l'API MAL
  -	l'API du transport MALZMQ

	#include "mal.h"
	#include "malzmq.h"

### Création d'un contexte MAL :

	mal_ctx_t *mal_ctx = mal_ctx_new();

Les contextes d'encodage et de décodage sont créés pour le format 'malbinary'. Le format 'varint' n'est pas utilisé et le flag 'verbose' est activé :

	malbinary_encoder_t *encoder = malbinary_encoder_new(false, true);
	malbinary_decoder_t *decoder = malbinary_decoder_new(false, true);

Configuration du catalogue de mapping (cf 12.1.3) et des flags de présence (cf 12.1.2) dans le header MALZMQ : dans l'exemple il n'y a pas de catalogue et tous les champs optionnels sont présents (encodés) dans le header.

	malzmq_header_t *malzmq_header = malzmq_header_new(NULL, true, 0, true, NULL,
	  NULL, NULL, NULL);

Un contexte de transport MALZMQ est créé à partir du contexte MAL. Une fonction de mapping d'URI est fournie (cf 12.2). Dans l'exemple on utilise la fonction par défaut. L'adresse et le port d'écoute de connexions entrantes sont 'localhost' et 5555.

	malzmq_ctx_t *malzmq_ctx = malzmq_ctx_new(
	  mal_ctx, NULL,
	  "localhost", "5555",
	  malzmq_header,
	  encoder, decoder,
	  true);

### Création du provider
Allocation d'une URI MALZMQ. Un nom unique (dans le contexte MALZMQ) est passé en paramètre.

	mal_uri_t *provider_uri =
	  mal_ctx_create_uri(mal_ctx, "simple_app/myprovider");

Création du end-point du provider avec les paramètres suivants :

  -	la référence du contexte MAL,
  -	l'URI du provider allouée précédemment.

	mal_endpoint_t *provider_endpoint = mal_endpoint_new(mal_ctx, provider_uri);

Instanciation du provider avec la référence du end-point correspondant et les paramètres liés à l'encodage :

	simple_app_myprovider_t *provider = simple_app_myprovider_new(
	  provider_endpoint,
	  MALBINARY_FORMAT_CODE,
	  encoder, decoder);

L'enregistrement du handler de l'opération sera effectuée dans la fonction run de l'acteur CZMQ (voir section 4.2.2).

### Création du consumer

Allocation d'une URI MALZMQ. Un nom unique (dans le contexte MALZMQ) est passé en paramètre.

	mal_uri_t *consumer_uri =
	  mal_ctx_create_uri(mal_ctx, "simple_app/myconsumer");

Création du end-point du consumer avec les paramètres suivants :

  -	la référence du contexte MAL,
  -	l'URI du consumer allouée précédemment.

	mal_endpoint_t *consumer_endpoint = mal_endpoint_new(mal_ctx, consumer_uri);

L'instanciation du consumer nécessite de déterminer certains paramètres du Header de message MAL :

	mal_blob_t *authentication_id = mal_blob_new(0);
	mal_qoslevel_t qoslevel = MAL_QOSLEVEL_ASSURED;
	mal_uinteger_t priority = 4;
	mal_identifier_list_t *domain = mal_identifier_list_new(0);
	mal_identifier_t *network_zone = mal_identifier_new("Network Zone");
	mal_sessiontype_t session = MAL_SESSIONTYPE_LIVE;
	mal_identifier_t *session_name = mal_identifier_new("LIVE");

	simple_app_myconsumer_t *consumer =
	simple_app_myconsumer_new(provider_uri,
	  authentication_id, qoslevel, priority, domain, network_zone, session,
	  session_name, MALBINARY_FORMAT_CODE, encoder, decoder);

Les mêmes contextes d'encodage et de décodage que ceux du provider sont utilisés par le consumer.

L'opération Send ne nécessitant pas de handler coté consumer il n'y aura pas d'enregistrement de handler pour ce consumer.

### Lancement et fin de l'application

Création du provider et de l'acteur ZMQ correspondant :

	provider = simple_app_create_provider(
	  verbose,
	  mal_ctx, provider_uri,
	  encoder, decoder);
	zactor_t *provider_actor = zactor_new(simple_app_myprovider_run, provider);

Création du consumer et de l'acteur ZMQ correspondant :

	consumer = simple_app_create_consumer(
	  verbose,
	  mal_ctx, provider_uri,
	  encoder, decoder);
	zactor_t *consumer_actor = zactor_new(simple_app_myconsumer_run, consumer);

Démarrage du contexte MALZMQ (appel bloquant jusqu'à l'interruption du contexte) :

	  malzmq_ctx_start(malzmq_ctx);

Destruction des contextes MAL et MALZMQ :

	  mal_ctx_destroy(&mal_ctx);
	  malzmq_ctx_destroy(&malzmq_ctx);
