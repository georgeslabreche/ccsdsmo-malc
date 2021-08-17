/*  =========================================================================
    nmf_api_main - A test main program

    The MIT License (MIT)
    =========================================================================
*/

/*
@header
    nmf_api_main - A test main program
@discuss
@end
*/

#include "nmfapi_classes.h"

int main (int argc, char *argv [])
{
    mc_parameter_service_t *param_service = mc_parameter_service_new ("192.168.132.16", "1024", "1025");
    //mc_parameter_service_get_value (param_service, NULL);

    //mc_parameter_service_list_definition (param_service, "*");
    mc_parameter_service_get_value (param_service, 1);
    mc_parameter_service_destroy (&param_service);
    
    return 0;
}
