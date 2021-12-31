
# NMF API
The [NMF](https://nanosat-mo-framework.github.io/) API is a library that uses the MAL C API and is built for the [OPS-SAT spacecraft](https://opssat1.esoc.esa.int/).

## 1. Background

## 2. Extending
This API does not implement all of the spacecraft's NMF capability sets. This section provides a narrative that describes how the Monitor and Control (M&C) Parameter Service's *addParameter* operation was implemented. The description serves as a reference on how the API can be extended with additional capability sets. This feature's [pull request](https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/pull/78) is a good reference on how to update this project to support other NMF Service operations.
### 2.1 Consumer API
Create the **mc_parameter_addparameter_consumer.api** file in the api directory to describe the *addParameter* consumer class:
```bash
touch mc_parameter_addparameter_consumer.api
```
#### 2.1.1 Common consumer methods
Common consumer class methods to define:
- **constructor**: Instanciate a consumer object for the *addParameter* operation.
- **deconstructor**: The destructor.
- **response_clear**: Clear the response variables.
- **mutex_lock**: Lock the mutex used to force a synchronous response despite the request being an asynchronous operation.
- **mutex_unlock**: Unlock the mutex used to force a synchronous response despite the request being an asynchronous operation.
- **actor_init**:  Create and initialize the actor.
- **get_response_error_code**: Get error code from processing the response.

#### 2.1.2 Consumer methods specific to addParameter
Consumer class request parameters and response objects as well as their getter and setter accessor methods are determined by studying [the operation's specification in the M&C's Parameter Service definition XML file](https://github.com/tanagraspace/CCSDS_MO_StubGenerator/blob/46b0be7bfe5340b6a2b608c6dc14319fa095d340/specs/xml/area004-v001-Monitor-and-Control.xml#L587-L617):
- **paramDefDetails**: The field shall hold the name and the *ParameterDefinitionDetails* to be added.
- **newObjInstIds**: The response shall contain the list of object instance identifiers for the *ParameterIdentity* and new *ParameterDefinition* objects.

The *paramDefDetails* is the operation's request MAL message field while *newObjInstIds* is the request's MAL response object. Studying the generated code in the [generated_areas project](https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/tree/opssat/apps/generated_areas) also helps to determine the MAL message request and response objects that need to be initialized and handled. Code pertaining to the *addParameter* operation can be found in the *mc.c* file by searching for the *addparameter* keyword.

##### 2.1.2.1 Request parameters
Looking at the generated encoding method, i.e. `mc_parameter_addparameter_request_encode_0,`, reveals that the operation's request expects a MAL message made out of a single parameter: a pointer to an `mc_parameter_parametercreationrequest_list_t` struct. Setting this request parameter can be approached in one of two ways:

1. The client is responsible for instanciating and initializing the structs specific to the operation in question.
2. The API implements levels of abstractions so that the client only needs to worry about setting primitive data types. The required structs are created and initialized behind the scene.

Option 2 is the favored approach in case `mc_parameter_parametercreationrequest_list_t` doesn't consists of a lot of parameters or nested structs. A quick dive into the **generated_areas** code reveals the following hiearachy of structs to consider:

The `mc_parameter_parametercreationrequest_list_t` struct is defined in *mc_parameter_parametercreationrequest_list.c*:
```c
struct _mc_parameter_parametercreationrequest_list_t {
  unsigned int element_count;
  mc_parameter_parametercreationrequest_t ** content;
};
```

The `mc_parameter_parametercreationrequest_t` struct is defined in *mc_parameter_parametercreationrequest.c*:
```c
// structure definition for composite mc_parameter_parametercreationrequest
struct _mc_parameter_parametercreationrequest_t {
  mal_identifier_t * f_name;
  mc_parameter_parameterdefinitiondetails_t * f_paramdefdetails;
};
```

The `mc_parameter_parameterdefinitiondetails_t` struct is defined in *mc_parameter_parameterdefinitiondetails.c*:
```c
// structure definition for composite mc_parameter_parameterdefinitiondetails
struct _mc_parameter_parameterdefinitiondetails_t {
  mal_string_t * f_description;
  mal_octet_t f_rawtype;
  mal_string_t * f_rawunit;
  mal_boolean_t f_generationenabled;
  mal_duration_t f_reportinterval;
  mc_parameterexpression_t * f_validityexpression;
  mc_parameter_parameterconversion_t * f_conversion;
};

```

The `mc_parameterexpression_t` struct is defined in *mc_parameterexpression.c*:
```c
// structure definition for composite mc_parameterexpression
struct _mc_parameterexpression_t {
  com_objectkey_t * f_parameterid;
  com_archive_expressionoperator_t f_operator;
  mal_boolean_t f_useconverted;
  bool f_value_is_present;
  unsigned char f_value_attribute_tag;
  union mal_attribute_t f_value;
};
```

The `mc_parameter_parameterconversion_t` struct is defined in *mc_parameter_parameterconversion.c*:
```c
// structure definition for composite mc_parameter_parameterconversion
struct _mc_parameter_parameterconversion_t {
  mal_octet_t f_convertedtype;
  mal_string_t * f_convertedunit;
  mc_conditionalconversion_list_t * f_conditionalconversions;
};
```

The `mc_conditionalconversion_list_t` struct is defined in *mc_conditionalconversion_list.c*:
```c
struct _mc_conditionalconversion_list_t {
  unsigned int element_count;
  mc_conditionalconversion_t ** content;
};
```

The `mc_conditionalconversion_t` struct is defined in *mc_conditionalconversion.c*:
```c
// structure definition for composite mc_conditionalconversion
struct _mc_conditionalconversion_t {
  mc_parameterexpression_t * f_condition;
  com_objectkey_t * f_conversionid;
};
```

Examining the NMF Supervisor's source code helps figuring out which of the above struct members are expected for the *addParameter* request to succeed (GitLab references as of December 29, 2021):
- The [addParameter](https://gitlab.com/esa/NMF/nanosat-mo-framework/-/blob/16c7ea674ca6368f3135d3bee9966d57a0fa2807/core/mo-services-impl/ccsds-mc-impl/src/main/java/esa/mo/mc/impl/provider/ParameterProviderServiceImpl.java#L475-551) method in the [ParameterProviderServiceImpl](https://nanosat-mo-framework.readthedocs.io/en/latest/javadoc/esa/mo/mc/impl/provider/ParameterProviderServiceImpl.html) class.
- The [addMultiple](https://gitlab.com/esa/NMF/nanosat-mo-framework/-/blob/16c7ea674ca6368f3135d3bee9966d57a0fa2807/core/mo-services-impl/ccsds-mc-impl/src/main/java/esa/mo/mc/impl/provider/ParameterManager.java#L556-692) method in the [ParameterManager](https://nanosat-mo-framework.readthedocs.io/en/latest/javadoc/esa/mo/mc/impl/provider/ParameterManager.html) class.
- The [store](https://gitlab.com/esa/NMF/nanosat-mo-framework/-/blob/16c7ea674ca6368f3135d3bee9966d57a0fa2807/core/mo-services-impl/ccsds-com-impl/src/main/java/esa/mo/com/impl/provider/ArchiveProviderServiceImpl.java#L519-611) method in the [ArchiveProviderServiceImpl](https://nanosat-mo-framework.readthedocs.io/en/latest/javadoc/esa/mo/com/impl/provider/ArchiveProviderServiceImpl.html) class.
- The ParameterDefinitionDetails class.

The request parameters can be reduced to setting the following struct members:

1. The size of the list: the `element_count` member of the `_mc_parameter_parametercreationrequest_list_t` struct.
2. The parameter names to add: the `f_name` member of the `_mc_parameter_parametercreationrequest_t` struct.
3. The descriptions for each parameter to add: the `f_description` member of the `_mc_parameter_parameterdefinitiondetails_t` struct.
4. The raw types for each parameter to add: the `f_rawtype` member of the `_mc_parameter_parameterdefinitiondetails_t` struct. Holds the attribute short form part of the raw type of the parameter, e.g., for a MAL::String parameter it shall hold 15.
5. The raw units for each parameter to add: the `f_rawunit` member of the `_mc_parameter_parameterdefinitiondetails_t` struct.
6. The generation enabled flag for each parameter to add: the `f_generationenabled` member of the `_mc_parameter_parameterdefinitiondetails_t` struct.
7. The report interval for each parameter to add: the `f_reportinterval` member of the `_mc_parameter_parameterdefinitiondetails_t` struct.

This results in defining the following accessors in the *mc_parameter_addparameter_consumer.api* definition file:

1. `get_field_param_list_size` and `set_field_param_list_size` for the number of parameters to create (size_t).
2. `get_field_param_name_list` and `set_field_param_name_list` for the names of the parameters (string list).
3. `get_field_param_description_list` and `set_field_param_description_list` for the descriptions of the parameters (string list).
4. `get_field_param_raw_type_list` and `set_field_param_raw_type_list` for the data types of the parameters (char list).
5. `get_field_param_raw_unit_list` and `set_field_param_raw_unit_list` for the raw units of the parameters (string list).
6. `get_field_param_generation_enabled_list` and `set_field_param_generation_enabled_list` for the raw units of the parameters (boolean list).
7. `get_field_param_report_interval_list` and `set_field_param_report_interval_list` for the raw units of the parameters (double list).

Given primitive data type values for these *addParameter* request parameters, the API will create and initialize the `mc_parameter_parametercreationrequest_list_t` struct that will then be encoded as the *addParameter* MAL request message. NULL is set for the remaining struct members:
- `f_validityexpression`: Expression that determines this parameter's validity state. Can be NULL if no validity check is required or validity is calculated by implementation-specific mechanisms.
- `f_conversion`: If present then parameter has a converted type.

This results in the following structure for the *addParameter* consumer class:

```c
//  --------------------------------------------------------------------------
//  Structure of the addParameter consumer class

struct _mc_parameter_addparameter_consumer_t {
    mal_ctx_t *mal_ctx;
    mal_uri_t *provider_uri;
    mal_actor_t *actor;
    char **param_name_list;
    char **param_description_list;
    unsigned char *param_raw_type_list;
    char **param_raw_unit_list;
    bool *param_generation_enabled_list;
    double *param_report_interval_list;
    size_t param_list_size;
    long *response_param_identity_id_list;
    long *response_param_definition_id_list;
    size_t response_element_count;
    int response_error_code;
};
```

##### 2.1.2.2 Response objects
Looking at the generated decoding method, i.e. `mc_parameter_addparameter_request_decode_0,`, reveals that the operation's MAL response message is decoded as a `mc_objectinstancepair_list_t` struct (defined in *mc_objectinstancepair_list.c*):

```c
struct _mc_objectinstancepair_list_t {
  unsigned int element_count;
  mc_objectinstancepair_t ** content;
};
```

The `mc_objectinstancepair_t` struct is defined in *mc_objectinstancepair.c*:

```c
// structure definition for composite mc_objectinstancepair
struct _mc_objectinstancepair_t {
  mal_long_t f_objidentityinstanceid;
  mal_long_t f_objdefinstanceid;
};

```

The getters defined in the *mc_parameter_addparameter_consumer.api* for this reponse are `get_response_param_identity_id_list` and `get_response_param_definition_id_list`.

### 2.2 Service API
Clients do not interact with the consumer classes but instead with one of the service classes. The *addParameter* operation is part of the M&C Parameter Service implemented in *mc_parameter_service.c*. The *addParameter* operation is included in this service by defining and implementing the `add_parameter_list` and `add_parameter` methods in the *mc_parameter_service.api* and *mc_parameter_service.c* files, respectively.

### 2.3 Code generation
The `mc_parameter_service` service class exists so only the `mc_parameter_addparameter_consumer` consumer class needs to be added to the *project.xml*:

```xml
<class name = "mc_parameter_addparameter_consumer" selftest = "0" state = "stable">
    The consumer class for the addParameter operation
</class>
```

Code for the *addParameter* opration can now be generated:
```bash
gsl project.xml
```

What executing the GSL command does:
- Creates the consumer class header file: *mc_parameter_addparameter_consumer.h*.
- Creates the consumer class c file: *mc_parameter_addparameter_consumer.c*.
- Updates *mc_parameter_service.h* with `add_parameter_list` and `add_parameter` method definitions (*mc_parameter_service.h* already existed).
- Regenerates *nmfapi_c_library.h* with typedef, define, and include pertaining to the *addParameter* consumer class.

What's left to do:
- Implement methods in *mc_parameter_addparameter_consumer.c* (defined in *mc_parameter_addparameter_consumer.api* and *mc_parameter_addparameter_consumer.h*).
- Implement the `add_parameter_list` and `add_parameter` methods in *mc_parameter_service.c* (defned in *mc_parameter_service.api* and *mc_parameter_service.h*).

### 2.4 Code to implement
The following logic needs to be implemented:

1. mc_parameter_service.c:
    - Include a global variable for the `mc_parameter_addparameter_consumer` consumer.
    - Implement `add_parameter_list`.
    - Implement `add_parameter` (it invokes `add_parameter_list` with a parameter list of size 1).
2. mc_parameter_addparameter_consumer.c:
    - Include a global variable for the mutex object.
    - Implement private functions for the consumer's initialization, finalization, and response handling.
    - Implement logger object and log level setter method: `mc_parameter_addparameter_consumer_set_log_level`.
    - Implement all methods defined in *mc_parameter_addparameter_consumer.h*.
4. nmfapi_c.h:
    - Define the consumer log level setter: `mc_parameter_addparameter_consumer_set_log_level`.
3. nmf_api.c:
    - Invoke the `mc_parameter_addparameter_consumer_set_log_level` from the `nmf_api_set_global_log_level` method.

In case a new service was implemented then logic pertaining to the service's initialization and destruction would have been included in *nmf_api.c* as well as accessor methods for the new service. However, in this case, *mc_parameter_service.c* already existed and only required that the `add_parameter_list` and `add_parameter` methods be implemented.

### 2.5 Build
Implementing the *addParameter* operation involved creating new files and modifying existing ones:

```bash
$ git status
On branch issue_37_addParameter
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)
        new file:   api/mc_parameter_addparameter_consumer.api
        modified:   api/mc_parameter_service.api
        new file:   include/mc_parameter_addparameter_consumer.h
        modified:   include/mc_parameter_service.h
        modified:   include/nmfapi_c.h
        modified:   include/nmfapi_c_library.h
        modified:   project.xml
        new file:   src/mc_parameter_addparameter_consumer.c
        modified:   src/mc_parameter_service.c
        modified:   src/nmf_api.c
```

Build the project:
```bash
./genmake
```


### 2.6 Demo app
Create a demo executable binary in the [**nmfapi_c_demo**](https://github.com/tanagraspace/ccsdsmo-malc-sepp-apps/tree/opssat/apps/nmfapi_c_demo) project. Define the main class in the *project.xml*:

```xml
<main name = "demo_addparameter">Demo the addParameter interaction provided by the Monitor and Control Parameter Service</main>
```

Generate the template code for the main class:
```
gsl project.xml
```

Implement the demo app, build, and run:
```
./genmake
./src/demo_addparameter -?
```
