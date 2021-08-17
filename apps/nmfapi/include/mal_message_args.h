/*  =========================================================================
    mal_message_args - A container for mal message arguments.

    The MIT License (MIT)
    =========================================================================
*/

#ifndef MAL_MESSAGE_ARGS_H_INCLUDED
#define MAL_MESSAGE_ARGS_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/mal_message_args.api" to make changes.
//  @interface
//  This API is a draft, and may change without notice.
#ifdef NMFAPI_BUILD_DRAFT_API
#define MAL_MESSAGE_ARGS_NETWORK_ZONE "Network Zone"  // the network zone.
#define MAL_MESSAGE_ARGS_SESSION_NAME_LIVE "LIVE"  // the LIVE session name.

//  *** Draft method, for development use, may change without warning ***
//  Instanciate mal message argument.
NMFAPI_EXPORT mal_message_args_t *
    mal_message_args_new (void);

//  *** Draft method, for development use, may change without warning ***
//  The destructor.
NMFAPI_EXPORT void
    mal_message_args_destroy (mal_message_args_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Get the authentication id
NMFAPI_EXPORT mal_blob_t *
    mal_message_args_get_authentication_id (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the qoslevel
NMFAPI_EXPORT mal_qoslevel_t
    mal_message_args_get_qoslevel (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the priority
NMFAPI_EXPORT mal_uinteger_t
    mal_message_args_get_priority (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the domain
NMFAPI_EXPORT mal_identifier_list_t *
    mal_message_args_get_domain (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the network zone
NMFAPI_EXPORT mal_identifier_t *
    mal_message_args_get_network_zone (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the session
NMFAPI_EXPORT mal_sessiontype_t
    mal_message_args_get_session (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the session name
NMFAPI_EXPORT mal_identifier_t *
    mal_message_args_get_session_name (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the encoder
NMFAPI_EXPORT mal_encoder_t *
    mal_message_args_get_encoder (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Get the decoder
NMFAPI_EXPORT mal_decoder_t *
    mal_message_args_get_decoder (mal_message_args_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
NMFAPI_EXPORT void
    mal_message_args_test (bool verbose);

#endif // NMFAPI_BUILD_DRAFT_API
//  @end

#ifdef __cplusplus
}
#endif

#endif
