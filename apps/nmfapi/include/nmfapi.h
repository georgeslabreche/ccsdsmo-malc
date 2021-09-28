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
common_directory_lookupprovider_consumer_set_log_level (int level);


//  --------------------------------------------------------------------------
//  Declare the AppsLauncher service log level setters

void
sm_appslauncher_service_set_log_level (int level);

void
sm_appslauncher_listapp_consumer_set_log_level (int level);


//  --------------------------------------------------------------------------
//  Declare the Parameter service log level setters

void
mc_parameter_service_set_log_level (int level);

void
mc_parameter_getvalue_consumer_set_log_level (int level);

void
mc_parameter_setvalue_consumer_set_log_level (int level);

void
mc_parameter_listdefinition_consumer_set_log_level (int level);

#endif
