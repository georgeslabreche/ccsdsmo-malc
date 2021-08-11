/*  =========================================================================
    demo_app - Demo App Main

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    demo_app - Demo App Main
@discuss
@end
*/

#include "demo_classes.h"


//  --------------------------------------------------------------------------
//  The main function
int main (int argc, char *argv [])
{
    // Get provider host and port from command arguments.
    int argv_index_host = -1;
    int argv_index_port = -1;

    // split encoding flag
    bool split = false;

    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-?")) {
            puts ("demo_app [options] ...");
            puts ("  --host / -h         provider host");
            puts ("  --port / -p         provider port");
            puts ("  --split / -s        split encoding");
            puts ("  --help / -?         this information");
            return 0;
        }
        else
        if (streq (argv [argn], "--host")
        ||  streq (argv [argn], "-h"))
            argv_index_host = ++argn;
        else
        if (streq (argv [argn], "--port")
        ||  streq (argv [argn], "-p"))
            argv_index_port = ++argn;
        else
        if (streq (argv [argn], "--split")
        ||  streq (argv [argn], "-s"))
            split = true;
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }

    // Check if host and port were set.
    if (argv_index_host < 0 || argv_index_port < 0)
    {
        printf ("Expected --host and --port options\n");
        return 1;
    }

    mal_ctx_t *mal_ctx = mal_ctx_new();
    void *ctx = NULL;

    // All the MAL header fields are passed
    maltcp_header_t *maltcp_header = NULL;

    // Verbosity
    printf("demo_app: attempt connection to %s:%s\n", argv[argv_index_host], argv[argv_index_port]);

    // Create mal tcp header
    maltcp_header = maltcp_header_new(true, 0, true, NULL, NULL, NULL, NULL);

    // Connection: bind to server with set port number
    ctx = maltcp_ctx_new(
        mal_ctx,
        argv[argv_index_host], argv[argv_index_port],
        maltcp_header,
        true);

    // Change the logging level of maltcp encoding
    maltcp_ctx_set_encoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);
    maltcp_ctx_set_decoder_log_level((maltcp_ctx_t *) ctx, CLOG_WARN_LEVEL);

    if (!ctx) exit(EXIT_FAILURE);

    mal_uri_t *provider_uri = mal_ctx_create_uri(mal_ctx, "nanosat-mo-supervisor-AppsLauncher");
    printf("demo_app: provider URI: %s\n", provider_uri);

    // MAL encoder and decoder
    mal_encoder_t *encoder;
    mal_decoder_t *decoder;
    
    if (split)
    {
        encoder = malsplitbinary_encoder_new();
        decoder = malsplitbinary_decoder_new();
    } 
    else 
    {
        encoder = malbinary_encoder_new(false);
        decoder = malbinary_decoder_new(false);
    }

    // Create the consumer
    // This is the starting point to:
    //  1. create a new actor
    //  2. initialize the MAL request message
    //  3. encode and send the MAL request message
    //  4. Wait for the response callback function to be triggered
    //  5. Decode the MAL response message and print parameters
    demo_app_consumer_actor_create(false, mal_ctx, provider_uri, encoder, decoder);

    // Start
    mal_ctx_start(mal_ctx);
  
    // Verbosity
    printf("Stopped.\n");

    // Destroy the consumer actor
    demo_app_consumer_t *consumer = NULL;
    demo_app_consumer_destroy(&consumer, mal_ctx);

    // Destroy the context
    mal_ctx_destroy(&mal_ctx);

    // Verbosity
    printf("Destroyed.\n");

    return 0;
}