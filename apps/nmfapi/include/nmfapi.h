/*  =========================================================================
    nmfapi - NMF Service API

    The MIT License (MIT)
    =========================================================================
*/

#ifndef NMFAPI_H_H_INCLUDED
#define NMFAPI_H_H_INCLUDED

//  Include the project library file
#include "nmfapi_library.h"


//  --------------------------------------------------------------------------
//  Declare the NMF Gateway API log level setter
void
nmf_api_set_log_level (int level);


//  --------------------------------------------------------------------------
//  Declare the Directory service log level setters

void
common_directory_service_set_log_level (int level);

void
common_directory_lookup_provider_consumer_set_log_level (int level);


//  --------------------------------------------------------------------------
//  Declare the AppsLauncher service log level setters

void
sm_appslauncher_service_set_log_level (int level);

void
sm_appslauncher_list_app_consumer_set_log_level (int level);


//  --------------------------------------------------------------------------
//  Declare the Parameter service log level setters

void
mc_parameter_service_set_log_level (int level);

void
mc_parameter_get_value_consumer_set_log_level (int level);

void
mc_parameter_set_value_consumer_set_log_level (int level);

void
mc_parameter_list_definition_consumer_set_log_level (int level);

#endif
