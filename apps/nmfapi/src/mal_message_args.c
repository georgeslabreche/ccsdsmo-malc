/*  =========================================================================
    mal_message_args - A container for mal message arguments.

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    mal_message_args - A container for mal message arguments.
@discuss
@end
*/

#include "nmfapi_classes.h"

//  Structure of our class

struct _mal_message_args_t {
    mal_blob_t *authentication_id;
    mal_qoslevel_t qoslevel;
    mal_uinteger_t priority;
    mal_identifier_list_t *domain;
    mal_identifier_t *network_zone;
    mal_sessiontype_t session;
    mal_identifier_t *session_name;
    mal_encoder_t *encoder;
    mal_decoder_t *decoder;
};


//  --------------------------------------------------------------------------
//  Create a new mal_message_args

mal_message_args_t *
mal_message_args_new (void)
{
    mal_message_args_t *self = (mal_message_args_t *) zmalloc (sizeof (mal_message_args_t));
    assert (self);
    //  Initialize class properties here

    self->authentication_id = mal_blob_new(0);
    self->qoslevel = MAL_QOSLEVEL_ASSURED;
    self->priority = 4;
    self->domain = mal_identifier_list_new(0);
    self->network_zone = mal_identifier_new(MAL_MESSAGE_ARGS_NETWORK_ZONE);
    self->session = MAL_SESSIONTYPE_LIVE;
    self->session_name = mal_identifier_new(MAL_MESSAGE_ARGS_SESSION_NAME_LIVE);
    self->encoder = malbinary_encoder_new(false);
    self->decoder = malbinary_decoder_new(false);

    return self;
}

mal_blob_t *
mal_message_args_get_authentication_id (mal_message_args_t *self)
{
    return self->authentication_id;
}

mal_qoslevel_t
mal_message_args_get_qoslevel (mal_message_args_t *self)
{
    return self->qoslevel;
}

mal_uinteger_t
mal_message_args_get_priority (mal_message_args_t *self)
{
    return self->priority;
}

mal_identifier_list_t *
mal_message_args_get_domain (mal_message_args_t *self)
{
    return self->domain;
}

mal_identifier_t *
mal_message_args_get_network_zone (mal_message_args_t *self)
{
    return self->network_zone;
}


mal_sessiontype_t
mal_message_args_get_session (mal_message_args_t *self)
{
    return self->session;
}


mal_identifier_t *
mal_message_args_get_session_name (mal_message_args_t *self)
{
    return self->session_name;
}

mal_encoder_t *
mal_message_args_get_encoder (mal_message_args_t *self)
{
    return self->encoder;
}


mal_decoder_t *
mal_message_args_get_decoder (mal_message_args_t *self)
{
    return self->decoder;
}


//  --------------------------------------------------------------------------
//  Destroy the mal_message_args

void
mal_message_args_destroy (mal_message_args_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        mal_message_args_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Self test of this class

// If your selftest reads SCMed fixture data, please keep it in
// src/selftest-ro; if your test creates filesystem objects, please
// do so under src/selftest-rw.
// The following pattern is suggested for C selftest code:
//    char *filename = NULL;
//    filename = zsys_sprintf ("%s/%s", SELFTEST_DIR_RO, "mytemplate.file");
//    assert (filename);
//    ... use the "filename" for I/O ...
//    zstr_free (&filename);
// This way the same "filename" variable can be reused for many subtests.
#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
mal_message_args_test (bool verbose)
{
    printf (" * mal_message_args: ");

    //  @selftest
    //  Simple create/destroy test
    mal_message_args_t *self = mal_message_args_new ();
    assert (self);
    mal_message_args_destroy (&self);
    //  @end
    printf ("OK\n");
}
