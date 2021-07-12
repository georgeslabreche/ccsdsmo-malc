#ifndef __MC_H_INCLUDED__
#define __MC_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int mc_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int mc_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int mc_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define MC_AREA_NUMBER 4
#define MC_AREA_VERSION 129

// generated code for enumeration mc_severity
typedef enum {
  MC_SEVERITY_INFORMATIONAL,
  MC_SEVERITY_WARNING,
  MC_SEVERITY_ALARM,
  MC_SEVERITY_SEVERE,
  MC_SEVERITY_CRITICAL
} mc_severity_t;

// short form for enumeration type mc_severity
#define MC_SEVERITY_SHORT_FORM 0xffffffff81000006L
#ifndef MC_SEVERITY_LIST_T_DEFINED
#define MC_SEVERITY_LIST_T_DEFINED

typedef struct _mc_severity_list_t mc_severity_list_t;

#endif // MC_SEVERITY_LIST_T_DEFINED

// short form for list of enumeration type mc_severity
#define MC_SEVERITY_LIST_SHORT_FORM 0xffffffff81fffffaL

// generated code for composite MC:_:ArgumentDefinition
#ifndef MC_ARGUMENTDEFINITION_T_DEFINED
#define MC_ARGUMENTDEFINITION_T_DEFINED

typedef struct _mc_argumentdefinition_t mc_argumentdefinition_t;

#endif // MC_ARGUMENTDEFINITION_T_DEFINED

// short form for composite type MC:_:ArgumentDefinition
#define MC_ARGUMENTDEFINITION_SHORT_FORM 0xffffffff81000001L
#ifndef MC_ARGUMENTDEFINITION_LIST_T_DEFINED
#define MC_ARGUMENTDEFINITION_LIST_T_DEFINED

typedef struct _mc_argumentdefinition_list_t mc_argumentdefinition_list_t;

#endif // MC_ARGUMENTDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:_:ArgumentDefinition
#define MC_ARGUMENTDEFINITION_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:_:ArgumentValue
#ifndef MC_ARGUMENTVALUE_T_DEFINED
#define MC_ARGUMENTVALUE_T_DEFINED

typedef struct _mc_argumentvalue_t mc_argumentvalue_t;

#endif // MC_ARGUMENTVALUE_T_DEFINED

// short form for composite type MC:_:ArgumentValue
#define MC_ARGUMENTVALUE_SHORT_FORM 0xffffffff81000002L
#ifndef MC_ARGUMENTVALUE_LIST_T_DEFINED
#define MC_ARGUMENTVALUE_LIST_T_DEFINED

typedef struct _mc_argumentvalue_list_t mc_argumentvalue_list_t;

#endif // MC_ARGUMENTVALUE_LIST_T_DEFINED

// short form for list of composite type MC:_:ArgumentValue
#define MC_ARGUMENTVALUE_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite MC:_:ConditionalReference
#ifndef MC_CONDITIONALREFERENCE_T_DEFINED
#define MC_CONDITIONALREFERENCE_T_DEFINED

typedef struct _mc_conditionalreference_t mc_conditionalreference_t;

#endif // MC_CONDITIONALREFERENCE_T_DEFINED

// short form for composite type MC:_:ConditionalReference
#define MC_CONDITIONALREFERENCE_SHORT_FORM 0xffffffff81000003L
#ifndef MC_CONDITIONALREFERENCE_LIST_T_DEFINED
#define MC_CONDITIONALREFERENCE_LIST_T_DEFINED

typedef struct _mc_conditionalreference_list_t mc_conditionalreference_list_t;

#endif // MC_CONDITIONALREFERENCE_LIST_T_DEFINED

// short form for list of composite type MC:_:ConditionalReference
#define MC_CONDITIONALREFERENCE_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite MC:_:ParameterExpression
#ifndef MC_PARAMETEREXPRESSION_T_DEFINED
#define MC_PARAMETEREXPRESSION_T_DEFINED

typedef struct _mc_parameterexpression_t mc_parameterexpression_t;

#endif // MC_PARAMETEREXPRESSION_T_DEFINED

// short form for composite type MC:_:ParameterExpression
#define MC_PARAMETEREXPRESSION_SHORT_FORM 0xffffffff81000004L
#ifndef MC_PARAMETEREXPRESSION_LIST_T_DEFINED
#define MC_PARAMETEREXPRESSION_LIST_T_DEFINED

typedef struct _mc_parameterexpression_list_t mc_parameterexpression_list_t;

#endif // MC_PARAMETEREXPRESSION_LIST_T_DEFINED

// short form for list of composite type MC:_:ParameterExpression
#define MC_PARAMETEREXPRESSION_LIST_SHORT_FORM 0xffffffff81fffffcL

// generated code for composite MC:_:AttributeValue
#ifndef MC_ATTRIBUTEVALUE_T_DEFINED
#define MC_ATTRIBUTEVALUE_T_DEFINED

typedef struct _mc_attributevalue_t mc_attributevalue_t;

#endif // MC_ATTRIBUTEVALUE_T_DEFINED

// short form for composite type MC:_:AttributeValue
#define MC_ATTRIBUTEVALUE_SHORT_FORM 0xffffffff81000007L
#ifndef MC_ATTRIBUTEVALUE_LIST_T_DEFINED
#define MC_ATTRIBUTEVALUE_LIST_T_DEFINED

typedef struct _mc_attributevalue_list_t mc_attributevalue_list_t;

#endif // MC_ATTRIBUTEVALUE_LIST_T_DEFINED

// short form for list of composite type MC:_:AttributeValue
#define MC_ATTRIBUTEVALUE_LIST_SHORT_FORM 0xffffffff81fffff9L

// standard service identifiers
#define MC_ACTION_SERVICE_NUMBER 1

// generated code for composite MC:Action:ActionDefinitionDetails
#ifndef MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED
#define MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_action_actiondefinitiondetails_t mc_action_actiondefinitiondetails_t;

#endif // MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:Action:ActionDefinitionDetails
#define MC_ACTION_ACTIONDEFINITIONDETAILS_SHORT_FORM 0xffffffff81000001L
#ifndef MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_action_actiondefinitiondetails_list_t mc_action_actiondefinitiondetails_list_t;

#endif // MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionDefinitionDetails
#define MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:Action:ActionInstanceDetails
#ifndef MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED
#define MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED

typedef struct _mc_action_actioninstancedetails_t mc_action_actioninstancedetails_t;

#endif // MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED

// short form for composite type MC:Action:ActionInstanceDetails
#define MC_ACTION_ACTIONINSTANCEDETAILS_SHORT_FORM 0xffffffff81000002L
#ifndef MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED
#define MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED

typedef struct _mc_action_actioninstancedetails_list_t mc_action_actioninstancedetails_list_t;

#endif // MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionInstanceDetails
#define MC_ACTION_ACTIONINSTANCEDETAILS_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite MC:Action:ActionCreationRequest
#ifndef MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED
#define MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED

typedef struct _mc_action_actioncreationrequest_t mc_action_actioncreationrequest_t;

#endif // MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Action:ActionCreationRequest
#define MC_ACTION_ACTIONCREATIONREQUEST_SHORT_FORM 0xffffffff81000003L
#ifndef MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED
#define MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_action_actioncreationrequest_list_t mc_action_actioncreationrequest_list_t;

#endif // MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionCreationRequest
#define MC_ACTION_ACTIONCREATIONREQUEST_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for enumeration mc_action_actioncategory
typedef enum {
  MC_ACTION_ACTIONCATEGORY_DEFAULT,
  MC_ACTION_ACTIONCATEGORY_HIPRIORITY,
  MC_ACTION_ACTIONCATEGORY_CRITICAL
} mc_action_actioncategory_t;

// short form for enumeration type mc_action_actioncategory
#define MC_ACTION_ACTIONCATEGORY_SHORT_FORM 0xffffffff81000004L
#ifndef MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED
#define MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED

typedef struct _mc_action_actioncategory_list_t mc_action_actioncategory_list_t;

#endif // MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED

// short form for list of enumeration type mc_action_actioncategory
#define MC_ACTION_ACTIONCATEGORY_LIST_SHORT_FORM 0xffffffff81fffffcL

// standard service identifiers
#define MC_PARAMETER_SERVICE_NUMBER 2

// generated code for enumeration mc_parameter_validity
typedef enum {
  MC_PARAMETER_VALIDITY_INVALID,
  MC_PARAMETER_VALIDITY_VALID,
  MC_PARAMETER_VALIDITY_VALID_RAW_ONLY,
  MC_PARAMETER_VALIDITY_UNVERIFIED,
  MC_PARAMETER_VALIDITY_EXPIRED
} mc_parameter_validity_t;

// short form for enumeration type mc_parameter_validity
#define MC_PARAMETER_VALIDITY_SHORT_FORM 0xffffffff81000003L
#ifndef MC_PARAMETER_VALIDITY_LIST_T_DEFINED
#define MC_PARAMETER_VALIDITY_LIST_T_DEFINED

typedef struct _mc_parameter_validity_list_t mc_parameter_validity_list_t;

#endif // MC_PARAMETER_VALIDITY_LIST_T_DEFINED

// short form for list of enumeration type mc_parameter_validity
#define MC_PARAMETER_VALIDITY_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite MC:Parameter:ParameterDefinition
#ifndef MC_PARAMETER_PARAMETERDEFINITION_T_DEFINED
#define MC_PARAMETER_PARAMETERDEFINITION_T_DEFINED

typedef struct _mc_parameter_parameterdefinition_t mc_parameter_parameterdefinition_t;

#endif // MC_PARAMETER_PARAMETERDEFINITION_T_DEFINED

// short form for composite type MC:Parameter:ParameterDefinition
#define MC_PARAMETER_PARAMETERDEFINITION_SHORT_FORM 0xffffffff81000001L
#ifndef MC_PARAMETER_PARAMETERDEFINITION_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERDEFINITION_LIST_T_DEFINED

typedef struct _mc_parameter_parameterdefinition_list_t mc_parameter_parameterdefinition_list_t;

#endif // MC_PARAMETER_PARAMETERDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterDefinition
#define MC_PARAMETER_PARAMETERDEFINITION_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:Parameter:ParameterValue
#ifndef MC_PARAMETER_PARAMETERVALUE_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUE_T_DEFINED

typedef struct _mc_parameter_parametervalue_t mc_parameter_parametervalue_t;

#endif // MC_PARAMETER_PARAMETERVALUE_T_DEFINED

// short form for composite type MC:Parameter:ParameterValue
#define MC_PARAMETER_PARAMETERVALUE_SHORT_FORM 0xffffffff81000002L
#ifndef MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED

typedef struct _mc_parameter_parametervalue_list_t mc_parameter_parametervalue_list_t;

#endif // MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterValue
#define MC_PARAMETER_PARAMETERVALUE_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite MC:Parameter:ParameterConversion
#ifndef MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED
#define MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED

typedef struct _mc_parameter_parameterconversion_t mc_parameter_parameterconversion_t;

#endif // MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED

// short form for composite type MC:Parameter:ParameterConversion
#define MC_PARAMETER_PARAMETERCONVERSION_SHORT_FORM 0xffffffff81000004L
#ifndef MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED

typedef struct _mc_parameter_parameterconversion_list_t mc_parameter_parameterconversion_list_t;

#endif // MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterConversion
#define MC_PARAMETER_PARAMETERCONVERSION_LIST_SHORT_FORM 0xffffffff81fffffcL

// standard service identifiers
#define MC_ALERT_SERVICE_NUMBER 3

// generated code for composite MC:Alert:AlertDefinition
#ifndef MC_ALERT_ALERTDEFINITION_T_DEFINED
#define MC_ALERT_ALERTDEFINITION_T_DEFINED

typedef struct _mc_alert_alertdefinition_t mc_alert_alertdefinition_t;

#endif // MC_ALERT_ALERTDEFINITION_T_DEFINED

// short form for composite type MC:Alert:AlertDefinition
#define MC_ALERT_ALERTDEFINITION_SHORT_FORM 0xffffffff81000001L
#ifndef MC_ALERT_ALERTDEFINITION_LIST_T_DEFINED
#define MC_ALERT_ALERTDEFINITION_LIST_T_DEFINED

typedef struct _mc_alert_alertdefinition_list_t mc_alert_alertdefinition_list_t;

#endif // MC_ALERT_ALERTDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Alert:AlertDefinition
#define MC_ALERT_ALERTDEFINITION_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:Alert:AlertEvent
#ifndef MC_ALERT_ALERTEVENT_T_DEFINED
#define MC_ALERT_ALERTEVENT_T_DEFINED

typedef struct _mc_alert_alertevent_t mc_alert_alertevent_t;

#endif // MC_ALERT_ALERTEVENT_T_DEFINED

// short form for composite type MC:Alert:AlertEvent
#define MC_ALERT_ALERTEVENT_SHORT_FORM 0xffffffff81000002L
#ifndef MC_ALERT_ALERTEVENT_LIST_T_DEFINED
#define MC_ALERT_ALERTEVENT_LIST_T_DEFINED

typedef struct _mc_alert_alertevent_list_t mc_alert_alertevent_list_t;

#endif // MC_ALERT_ALERTEVENT_LIST_T_DEFINED

// short form for list of composite type MC:Alert:AlertEvent
#define MC_ALERT_ALERTEVENT_LIST_SHORT_FORM 0xffffffff81fffffeL

// standard service identifiers
#define MC_CHECK_SERVICE_NUMBER 4

// generated code for enumeration mc_check_checkstate
typedef enum {
  MC_CHECK_CHECKSTATE_DISABLED,
  MC_CHECK_CHECKSTATE_UNCHECKED,
  MC_CHECK_CHECKSTATE_INVALID,
  MC_CHECK_CHECKSTATE_OK,
  MC_CHECK_CHECKSTATE_NOT_OK
} mc_check_checkstate_t;

// short form for enumeration type mc_check_checkstate
#define MC_CHECK_CHECKSTATE_SHORT_FORM 0xffffffff81000008L
#ifndef MC_CHECK_CHECKSTATE_LIST_T_DEFINED
#define MC_CHECK_CHECKSTATE_LIST_T_DEFINED

typedef struct _mc_check_checkstate_list_t mc_check_checkstate_list_t;

#endif // MC_CHECK_CHECKSTATE_LIST_T_DEFINED

// short form for list of enumeration type mc_check_checkstate
#define MC_CHECK_CHECKSTATE_LIST_SHORT_FORM 0xffffffff81fffff8L

// generated code for composite MC:Check:ConstantCheck
#ifndef MC_CHECK_CONSTANTCHECK_T_DEFINED
#define MC_CHECK_CONSTANTCHECK_T_DEFINED

typedef struct _mc_check_constantcheck_t mc_check_constantcheck_t;

#endif // MC_CHECK_CONSTANTCHECK_T_DEFINED

// short form for composite type MC:Check:ConstantCheck
#define MC_CHECK_CONSTANTCHECK_SHORT_FORM 0xffffffff81000001L
#ifndef MC_CHECK_CONSTANTCHECK_LIST_T_DEFINED
#define MC_CHECK_CONSTANTCHECK_LIST_T_DEFINED

typedef struct _mc_check_constantcheck_list_t mc_check_constantcheck_list_t;

#endif // MC_CHECK_CONSTANTCHECK_LIST_T_DEFINED

// short form for list of composite type MC:Check:ConstantCheck
#define MC_CHECK_CONSTANTCHECK_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:Check:ReferenceCheck
#ifndef MC_CHECK_REFERENCECHECK_T_DEFINED
#define MC_CHECK_REFERENCECHECK_T_DEFINED

typedef struct _mc_check_referencecheck_t mc_check_referencecheck_t;

#endif // MC_CHECK_REFERENCECHECK_T_DEFINED

// short form for composite type MC:Check:ReferenceCheck
#define MC_CHECK_REFERENCECHECK_SHORT_FORM 0xffffffff81000002L
#ifndef MC_CHECK_REFERENCECHECK_LIST_T_DEFINED
#define MC_CHECK_REFERENCECHECK_LIST_T_DEFINED

typedef struct _mc_check_referencecheck_list_t mc_check_referencecheck_list_t;

#endif // MC_CHECK_REFERENCECHECK_LIST_T_DEFINED

// short form for list of composite type MC:Check:ReferenceCheck
#define MC_CHECK_REFERENCECHECK_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite MC:Check:DeltaCheck
#ifndef MC_CHECK_DELTACHECK_T_DEFINED
#define MC_CHECK_DELTACHECK_T_DEFINED

typedef struct _mc_check_deltacheck_t mc_check_deltacheck_t;

#endif // MC_CHECK_DELTACHECK_T_DEFINED

// short form for composite type MC:Check:DeltaCheck
#define MC_CHECK_DELTACHECK_SHORT_FORM 0xffffffff81000003L
#ifndef MC_CHECK_DELTACHECK_LIST_T_DEFINED
#define MC_CHECK_DELTACHECK_LIST_T_DEFINED

typedef struct _mc_check_deltacheck_list_t mc_check_deltacheck_list_t;

#endif // MC_CHECK_DELTACHECK_LIST_T_DEFINED

// short form for list of composite type MC:Check:DeltaCheck
#define MC_CHECK_DELTACHECK_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite MC:Check:LimitCheck
#ifndef MC_CHECK_LIMITCHECK_T_DEFINED
#define MC_CHECK_LIMITCHECK_T_DEFINED

typedef struct _mc_check_limitcheck_t mc_check_limitcheck_t;

#endif // MC_CHECK_LIMITCHECK_T_DEFINED

// short form for composite type MC:Check:LimitCheck
#define MC_CHECK_LIMITCHECK_SHORT_FORM 0xffffffff81000004L
#ifndef MC_CHECK_LIMITCHECK_LIST_T_DEFINED
#define MC_CHECK_LIMITCHECK_LIST_T_DEFINED

typedef struct _mc_check_limitcheck_list_t mc_check_limitcheck_list_t;

#endif // MC_CHECK_LIMITCHECK_LIST_T_DEFINED

// short form for list of composite type MC:Check:LimitCheck
#define MC_CHECK_LIMITCHECK_LIST_SHORT_FORM 0xffffffff81fffffcL

// generated code for composite MC:Check:CheckLink
#ifndef MC_CHECK_CHECKLINK_T_DEFINED
#define MC_CHECK_CHECKLINK_T_DEFINED

typedef struct _mc_check_checklink_t mc_check_checklink_t;

#endif // MC_CHECK_CHECKLINK_T_DEFINED

// short form for composite type MC:Check:CheckLink
#define MC_CHECK_CHECKLINK_SHORT_FORM 0xffffffff81000005L
#ifndef MC_CHECK_CHECKLINK_LIST_T_DEFINED
#define MC_CHECK_CHECKLINK_LIST_T_DEFINED

typedef struct _mc_check_checklink_list_t mc_check_checklink_list_t;

#endif // MC_CHECK_CHECKLINK_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckLink
#define MC_CHECK_CHECKLINK_LIST_SHORT_FORM 0xffffffff81fffffbL

// generated code for composite MC:Check:CheckResult
#ifndef MC_CHECK_CHECKRESULT_T_DEFINED
#define MC_CHECK_CHECKRESULT_T_DEFINED

typedef struct _mc_check_checkresult_t mc_check_checkresult_t;

#endif // MC_CHECK_CHECKRESULT_T_DEFINED

// short form for composite type MC:Check:CheckResult
#define MC_CHECK_CHECKRESULT_SHORT_FORM 0xffffffff81000006L
#ifndef MC_CHECK_CHECKRESULT_LIST_T_DEFINED
#define MC_CHECK_CHECKRESULT_LIST_T_DEFINED

typedef struct _mc_check_checkresult_list_t mc_check_checkresult_list_t;

#endif // MC_CHECK_CHECKRESULT_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckResult
#define MC_CHECK_CHECKRESULT_LIST_SHORT_FORM 0xffffffff81fffffaL

// generated code for composite MC:Check:ReferenceValue
#ifndef MC_CHECK_REFERENCEVALUE_T_DEFINED
#define MC_CHECK_REFERENCEVALUE_T_DEFINED

typedef struct _mc_check_referencevalue_t mc_check_referencevalue_t;

#endif // MC_CHECK_REFERENCEVALUE_T_DEFINED

// short form for composite type MC:Check:ReferenceValue
#define MC_CHECK_REFERENCEVALUE_SHORT_FORM 0xffffffff81000007L
#ifndef MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED
#define MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED

typedef struct _mc_check_referencevalue_list_t mc_check_referencevalue_list_t;

#endif // MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Check:ReferenceValue
#define MC_CHECK_REFERENCEVALUE_LIST_SHORT_FORM 0xffffffff81fffff9L

// generated code for composite MC:Check:CheckResultFilter
#ifndef MC_CHECK_CHECKRESULTFILTER_T_DEFINED
#define MC_CHECK_CHECKRESULTFILTER_T_DEFINED

typedef struct _mc_check_checkresultfilter_t mc_check_checkresultfilter_t;

#endif // MC_CHECK_CHECKRESULTFILTER_T_DEFINED

// short form for composite type MC:Check:CheckResultFilter
#define MC_CHECK_CHECKRESULTFILTER_SHORT_FORM 0xffffffff81000009L
#ifndef MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED
#define MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED

typedef struct _mc_check_checkresultfilter_list_t mc_check_checkresultfilter_list_t;

#endif // MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckResultFilter
#define MC_CHECK_CHECKRESULTFILTER_LIST_SHORT_FORM 0xffffffff81fffff7L

// generated code for composite MC:Check:CheckSummary
#ifndef MC_CHECK_CHECKSUMMARY_T_DEFINED
#define MC_CHECK_CHECKSUMMARY_T_DEFINED

typedef struct _mc_check_checksummary_t mc_check_checksummary_t;

#endif // MC_CHECK_CHECKSUMMARY_T_DEFINED

// short form for composite type MC:Check:CheckSummary
#define MC_CHECK_CHECKSUMMARY_SHORT_FORM 0xffffffff8100000aL
#ifndef MC_CHECK_CHECKSUMMARY_LIST_T_DEFINED
#define MC_CHECK_CHECKSUMMARY_LIST_T_DEFINED

typedef struct _mc_check_checksummary_list_t mc_check_checksummary_list_t;

#endif // MC_CHECK_CHECKSUMMARY_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckSummary
#define MC_CHECK_CHECKSUMMARY_LIST_SHORT_FORM 0xffffffff81fffff6L

// standard service identifiers
#define MC_AGGREGATION_SERVICE_NUMBER 6

// generated code for enumeration mc_aggregation_aggregationcategory
typedef enum {
  MC_AGGREGATION_AGGREGATIONCATEGORY_GENERAL,
  MC_AGGREGATION_AGGREGATIONCATEGORY_DIAGNOSTIC,
  MC_AGGREGATION_AGGREGATIONCATEGORY_GENCOMP,
  MC_AGGREGATION_AGGREGATIONCATEGORY_DIAGCOMP,
  MC_AGGREGATION_AGGREGATIONCATEGORY_ALWAYSUHF,
  MC_AGGREGATION_AGGREGATIONCATEGORY_PACKETSTORE,
  MC_AGGREGATION_AGGREGATIONCATEGORY_TEMPORARY,
  MC_AGGREGATION_AGGREGATIONCATEGORY_LIVESBAND,
  MC_AGGREGATION_AGGREGATIONCATEGORY_LIVEUHF,
  MC_AGGREGATION_AGGREGATIONCATEGORY_BEACON
} mc_aggregation_aggregationcategory_t;

// short form for enumeration type mc_aggregation_aggregationcategory
#define MC_AGGREGATION_AGGREGATIONCATEGORY_SHORT_FORM 0xffffffff81000005L
#ifndef MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationcategory_list_t mc_aggregation_aggregationcategory_list_t;

#endif // MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_aggregationcategory
#define MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_SHORT_FORM 0xffffffff81fffffbL

// generated code for enumeration mc_aggregation_thresholdtype
typedef enum {
  MC_AGGREGATION_THRESHOLDTYPE_PERCENTAGE,
  MC_AGGREGATION_THRESHOLDTYPE_DELTA
} mc_aggregation_thresholdtype_t;

// short form for enumeration type mc_aggregation_thresholdtype
#define MC_AGGREGATION_THRESHOLDTYPE_SHORT_FORM 0xffffffff81000006L
#ifndef MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED
#define MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED

typedef struct _mc_aggregation_thresholdtype_list_t mc_aggregation_thresholdtype_list_t;

#endif // MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_thresholdtype
#define MC_AGGREGATION_THRESHOLDTYPE_LIST_SHORT_FORM 0xffffffff81fffffaL

// generated code for enumeration mc_aggregation_generationmode
typedef enum {
  MC_AGGREGATION_GENERATIONMODE_ADHOC,
  MC_AGGREGATION_GENERATIONMODE_PERIODIC,
  MC_AGGREGATION_GENERATIONMODE_FILTERED_TIMEOUT
} mc_aggregation_generationmode_t;

// short form for enumeration type mc_aggregation_generationmode
#define MC_AGGREGATION_GENERATIONMODE_SHORT_FORM 0xffffffff81000007L
#ifndef MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED
#define MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED

typedef struct _mc_aggregation_generationmode_list_t mc_aggregation_generationmode_list_t;

#endif // MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_generationmode
#define MC_AGGREGATION_GENERATIONMODE_LIST_SHORT_FORM 0xffffffff81fffff9L

// generated code for composite MC:Aggregation:AggregationDefinition
#ifndef MC_AGGREGATION_AGGREGATIONDEFINITION_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONDEFINITION_T_DEFINED

typedef struct _mc_aggregation_aggregationdefinition_t mc_aggregation_aggregationdefinition_t;

#endif // MC_AGGREGATION_AGGREGATIONDEFINITION_T_DEFINED

// short form for composite type MC:Aggregation:AggregationDefinition
#define MC_AGGREGATION_AGGREGATIONDEFINITION_SHORT_FORM 0xffffffff81000001L
#ifndef MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationdefinition_list_t mc_aggregation_aggregationdefinition_list_t;

#endif // MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationDefinition
#define MC_AGGREGATION_AGGREGATIONDEFINITION_LIST_SHORT_FORM 0xffffffff81ffffffL

// generated code for composite MC:Aggregation:AggregationValue
#ifndef MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED

typedef struct _mc_aggregation_aggregationvalue_t mc_aggregation_aggregationvalue_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED

// short form for composite type MC:Aggregation:AggregationValue
#define MC_AGGREGATION_AGGREGATIONVALUE_SHORT_FORM 0xffffffff81000002L
#ifndef MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationvalue_list_t mc_aggregation_aggregationvalue_list_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationValue
#define MC_AGGREGATION_AGGREGATIONVALUE_LIST_SHORT_FORM 0xffffffff81fffffeL

// generated code for composite MC:Aggregation:AggregationReference
#ifndef MC_AGGREGATION_AGGREGATIONREFERENCE_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONREFERENCE_T_DEFINED

typedef struct _mc_aggregation_aggregationreference_t mc_aggregation_aggregationreference_t;

#endif // MC_AGGREGATION_AGGREGATIONREFERENCE_T_DEFINED

// short form for composite type MC:Aggregation:AggregationReference
#define MC_AGGREGATION_AGGREGATIONREFERENCE_SHORT_FORM 0xffffffff81000003L
#ifndef MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationreference_list_t mc_aggregation_aggregationreference_list_t;

#endif // MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationReference
#define MC_AGGREGATION_AGGREGATIONREFERENCE_LIST_SHORT_FORM 0xffffffff81fffffdL

// generated code for composite MC:Aggregation:ThresholdFilter
#ifndef MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED
#define MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED

typedef struct _mc_aggregation_thresholdfilter_t mc_aggregation_thresholdfilter_t;

#endif // MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED

// short form for composite type MC:Aggregation:ThresholdFilter
#define MC_AGGREGATION_THRESHOLDFILTER_SHORT_FORM 0xffffffff81000004L
#ifndef MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED
#define MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED

typedef struct _mc_aggregation_thresholdfilter_list_t mc_aggregation_thresholdfilter_list_t;

#endif // MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:ThresholdFilter
#define MC_AGGREGATION_THRESHOLDFILTER_LIST_SHORT_FORM 0xffffffff81fffffcL

// include required areas definitions
#include "com.h"
#include "opssat_pf.h"
#include "opssat_std.h"

// generated code for composite MC:_:ArgumentDefinition

// generated code for composite MC:_:ArgumentValue

// generated code for composite MC:_:ConditionalReference

// generated code for composite MC:_:ParameterExpression

// generated code for composite MC:_:AttributeValue

// generated code for composite MC:Action:ActionDefinitionDetails

// generated code for composite MC:Action:ActionInstanceDetails

// generated code for composite MC:Action:ActionCreationRequest

// generated code for operation mc_action_submitaction
#define MC_ACTION_SUBMITACTION_OPERATION_NUMBER 1
int mc_action_submitaction_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_submitaction_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int mc_action_submitaction_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int mc_action_submitaction_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int mc_action_submitaction_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_submitaction_submit_add_encoding_length_1(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int mc_action_submitaction_submit_encode_1(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int mc_action_submitaction_submit_decode_1(void * cursor, mal_decoder_t * decoder, mc_action_actioninstancedetails_t ** element_res);
int mc_action_submitaction_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_submitaction_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_action_submitaction_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_submitaction_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_action_submitaction_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_submitaction_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_submitaction_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Parameter:ParameterDefinition

// generated code for composite MC:Parameter:ParameterValue

// generated code for composite MC:Parameter:ParameterConversion

// generated code for composite MC:Alert:AlertDefinition

// generated code for composite MC:Alert:AlertEvent

// generated code for operation mc_alert_enablegeneration
#define MC_ALERT_ENABLEGENERATION_OPERATION_NUMBER 1
int mc_alert_enablegeneration_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_enablegeneration_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_alert_enablegeneration_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_alert_enablegeneration_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_alert_enablegeneration_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_enablegeneration_submit_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_alert_enablegeneration_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_alert_enablegeneration_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_alert_enablegeneration_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_enablegeneration_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_alert_enablegeneration_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_enablegeneration_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_alert_enablegeneration_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_enablegeneration_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_enablegeneration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Check:ConstantCheck

// generated code for composite MC:Check:ReferenceCheck

// generated code for composite MC:Check:DeltaCheck

// generated code for composite MC:Check:LimitCheck

// generated code for composite MC:Check:CheckLink

// generated code for composite MC:Check:CheckResult

// generated code for composite MC:Check:ReferenceValue

// generated code for composite MC:Check:CheckResultFilter

// generated code for composite MC:Check:CheckSummary

// generated code for operation mc_check_getsummaryreport
#define MC_CHECK_GETSUMMARYREPORT_OPERATION_NUMBER 2
int mc_check_getsummaryreport_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_getsummaryreport_progress_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_getsummaryreport_progress_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_getsummaryreport_progress_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_getsummaryreport_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_getsummaryreport_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getsummaryreport_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_getsummaryreport_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getsummaryreport_progress_update_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int mc_check_getsummaryreport_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int mc_check_getsummaryreport_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int mc_check_getsummaryreport_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_update_add_encoding_length_1(mal_encoder_t * encoder, mc_check_checksummary_list_t * element, void * cursor);
int mc_check_getsummaryreport_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, mc_check_checksummary_list_t * element);
int mc_check_getsummaryreport_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, mc_check_checksummary_list_t ** element_res);
int mc_check_getsummaryreport_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_getsummaryreport_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getsummaryreport_progress_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int mc_check_getsummaryreport_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int mc_check_getsummaryreport_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int mc_check_getsummaryreport_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_response_add_encoding_length_1(mal_encoder_t * encoder, mc_check_checksummary_list_t * element, void * cursor);
int mc_check_getsummaryreport_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, mc_check_checksummary_list_t * element);
int mc_check_getsummaryreport_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, mc_check_checksummary_list_t ** element_res);
int mc_check_getsummaryreport_progress_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_getsummaryreport_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_getsummaryreport_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_getsummaryreport_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_enablecheck
#define MC_CHECK_ENABLECHECK_OPERATION_NUMBER 4
int mc_check_enablecheck_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_enablecheck_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_check_enablecheck_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_check_enablecheck_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_check_enablecheck_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_enablecheck_submit_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_check_enablecheck_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_check_enablecheck_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_check_enablecheck_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_enablecheck_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_enablecheck_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_enablecheck_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_enablecheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_enablecheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_enablecheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_listdefinition
#define MC_CHECK_LISTDEFINITION_OPERATION_NUMBER 5
int mc_check_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_check_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_check_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_check_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation mc_check_adddefinition
#define MC_CHECK_ADDDEFINITION_OPERATION_NUMBER 6
int mc_check_adddefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_adddefinition_request_add_encoding_length_0_mc_check_constantcheck_list(mal_encoder_t * encoder, mc_check_constantcheck_list_t * element, void * cursor);
int mc_check_adddefinition_request_encode_0_mc_check_constantcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheck_list_t * element);
int mc_check_adddefinition_request_add_encoding_length_0_mc_check_deltacheck_list(mal_encoder_t * encoder, mc_check_deltacheck_list_t * element, void * cursor);
int mc_check_adddefinition_request_encode_0_mc_check_deltacheck_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheck_list_t * element);
int mc_check_adddefinition_request_add_encoding_length_0_mc_check_limitcheck_list(mal_encoder_t * encoder, mc_check_limitcheck_list_t * element, void * cursor);
int mc_check_adddefinition_request_encode_0_mc_check_limitcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheck_list_t * element);
int mc_check_adddefinition_request_add_encoding_length_0_mc_check_referencecheck_list(mal_encoder_t * encoder, mc_check_referencecheck_list_t * element, void * cursor);
int mc_check_adddefinition_request_encode_0_mc_check_referencecheck_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheck_list_t * element);
int mc_check_adddefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int mc_check_adddefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int mc_check_adddefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_adddefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_adddefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_adddefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_adddefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_adddefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_adddefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_adddefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_adddefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_adddefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_adddefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_updatedefinition
#define MC_CHECK_UPDATEDEFINITION_OPERATION_NUMBER 7
int mc_check_updatedefinition_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_updatedefinition_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_updatedefinition_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_updatedefinition_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_updatedefinition_submit_add_encoding_length_1_mc_check_constantcheck_list(mal_encoder_t * encoder, mc_check_constantcheck_list_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_1_mc_check_constantcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheck_list_t * element);
int mc_check_updatedefinition_submit_add_encoding_length_1_mc_check_deltacheck_list(mal_encoder_t * encoder, mc_check_deltacheck_list_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_1_mc_check_deltacheck_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheck_list_t * element);
int mc_check_updatedefinition_submit_add_encoding_length_1_mc_check_limitcheck_list(mal_encoder_t * encoder, mc_check_limitcheck_list_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_1_mc_check_limitcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheck_list_t * element);
int mc_check_updatedefinition_submit_add_encoding_length_1_mc_check_referencecheck_list(mal_encoder_t * encoder, mc_check_referencecheck_list_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_1_mc_check_referencecheck_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheck_list_t * element);
int mc_check_updatedefinition_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int mc_check_updatedefinition_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int mc_check_updatedefinition_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_updatedefinition_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_updatedefinition_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_updatedefinition_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_removedefinition
#define MC_CHECK_REMOVEDEFINITION_OPERATION_NUMBER 8
int mc_check_removedefinition_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_removedefinition_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_removedefinition_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_removedefinition_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_removedefinition_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_removedefinition_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_removedefinition_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_removedefinition_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_removedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_removedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_removedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_addparametercheck
#define MC_CHECK_ADDPARAMETERCHECK_OPERATION_NUMBER 9
int mc_check_addparametercheck_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_addparametercheck_request_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checklink_list_t * element, void * cursor);
int mc_check_addparametercheck_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checklink_list_t * element);
int mc_check_addparametercheck_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checklink_list_t ** element_res);
int mc_check_addparametercheck_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_add_encoding_length_1(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int mc_check_addparametercheck_request_encode_1(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int mc_check_addparametercheck_request_decode_1(void * cursor, mal_decoder_t * decoder, com_objectdetails_list_t ** element_res);
int mc_check_addparametercheck_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_addparametercheck_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_addparametercheck_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_addparametercheck_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_addparametercheck_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_addparametercheck_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation mc_check_removeparametercheck
#define MC_CHECK_REMOVEPARAMETERCHECK_OPERATION_NUMBER 10
int mc_check_removeparametercheck_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_removeparametercheck_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_removeparametercheck_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_removeparametercheck_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_removeparametercheck_submit_add_encoding_length_1_mc_check_constantcheck_list(mal_encoder_t * encoder, mc_check_constantcheck_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_1_mc_check_constantcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheck_list_t * element);
int mc_check_removeparametercheck_submit_add_encoding_length_1_mc_check_deltacheck_list(mal_encoder_t * encoder, mc_check_deltacheck_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_1_mc_check_deltacheck_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheck_list_t * element);
int mc_check_removeparametercheck_submit_add_encoding_length_1_mc_check_limitcheck_list(mal_encoder_t * encoder, mc_check_limitcheck_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_1_mc_check_limitcheck_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheck_list_t * element);
int mc_check_removeparametercheck_submit_add_encoding_length_1_mc_check_referencecheck_list(mal_encoder_t * encoder, mc_check_referencecheck_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_1_mc_check_referencecheck_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheck_list_t * element);
int mc_check_removeparametercheck_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int mc_check_removeparametercheck_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_removeparametercheck_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_removeparametercheck_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_removeparametercheck_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_removeparametercheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_removeparametercheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_removeparametercheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Aggregation:AggregationDefinition

// generated code for composite MC:Aggregation:AggregationValue

// generated code for composite MC:Aggregation:AggregationReference

// generated code for composite MC:Aggregation:ThresholdFilter

// generated code for operation mc_aggregation_monitorvalue
#define MC_AGGREGATION_MONITORVALUE_OPERATION_NUMBER 1
int mc_aggregation_monitorvalue_update_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int mc_aggregation_monitorvalue_update_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int mc_aggregation_monitorvalue_update_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int mc_aggregation_monitorvalue_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_monitorvalue_update_add_encoding_length_1(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int mc_aggregation_monitorvalue_update_encode_1(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int mc_aggregation_monitorvalue_update_decode_1(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationvalue_list_t ** element_res);
int mc_aggregation_monitorvalue_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_monitorvalue_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_aggregation_monitorvalue_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_aggregation_monitorvalue_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_aggregation_monitorvalue_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int mc_aggregation_monitorvalue_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_aggregation_monitorvalue_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_aggregation_monitorvalue_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation mc_aggregation_getvalue
#define MC_AGGREGATION_GETVALUE_OPERATION_NUMBER 2
int mc_aggregation_getvalue_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_getvalue_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_getvalue_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_getvalue_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_getvalue_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_getvalue_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_getvalue_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_getvalue_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_getvalue_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_getvalue_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_getvalue_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_getvalue_request_response_add_encoding_length_1(mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element, void * cursor);
int mc_aggregation_getvalue_request_response_encode_1(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvalue_list_t * element);
int mc_aggregation_getvalue_request_response_decode_1(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationvalue_list_t ** element_res);
int mc_aggregation_getvalue_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_getvalue_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_getvalue_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_getvalue_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_getvalue_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_enablegeneration
#define MC_AGGREGATION_ENABLEGENERATION_OPERATION_NUMBER 3
int mc_aggregation_enablegeneration_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_enablegeneration_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_aggregation_enablegeneration_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_aggregation_enablegeneration_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_aggregation_enablegeneration_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablegeneration_submit_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_aggregation_enablegeneration_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_aggregation_enablegeneration_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_aggregation_enablegeneration_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablegeneration_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_enablegeneration_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_enablegeneration_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_aggregation_enablegeneration_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_enablegeneration_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_enablegeneration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_listdefinition
#define MC_AGGREGATION_LISTDEFINITION_OPERATION_NUMBER 5
int mc_aggregation_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_aggregation_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_aggregation_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_aggregation_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation mc_aggregation_adddefinition
#define MC_AGGREGATION_ADDDEFINITION_OPERATION_NUMBER 6
int mc_aggregation_adddefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_adddefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element, void * cursor);
int mc_aggregation_adddefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element);
int mc_aggregation_adddefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationdefinition_list_t ** element_res);
int mc_aggregation_adddefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_adddefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_adddefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_adddefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_adddefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_adddefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_adddefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_adddefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_adddefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_adddefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_adddefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_updatedefinition
#define MC_AGGREGATION_UPDATEDEFINITION_OPERATION_NUMBER 7
int mc_aggregation_updatedefinition_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_updatedefinition_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_updatedefinition_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_updatedefinition_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_updatedefinition_submit_add_encoding_length_1(mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_submit_encode_1(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinition_list_t * element);
int mc_aggregation_updatedefinition_submit_decode_1(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationdefinition_list_t ** element_res);
int mc_aggregation_updatedefinition_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_updatedefinition_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_updatedefinition_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_updatedefinition_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_aggregation_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_removedefinition
#define MC_AGGREGATION_REMOVEDEFINITION_OPERATION_NUMBER 8
int mc_aggregation_removedefinition_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_removedefinition_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_removedefinition_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_removedefinition_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_removedefinition_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_removedefinition_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_removedefinition_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_removedefinition_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_aggregation_removedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_removedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_removedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// test function
void mc_test(bool verbose);

#include "mc_severity_list.h"
#include "mc_argumentdefinition.h"
#include "mc_argumentdefinition_list.h"
#include "mc_argumentvalue.h"
#include "mc_argumentvalue_list.h"
#include "mc_conditionalreference.h"
#include "mc_conditionalreference_list.h"
#include "mc_parameterexpression.h"
#include "mc_parameterexpression_list.h"
#include "mc_attributevalue.h"
#include "mc_attributevalue_list.h"
#include "mc_action_actiondefinitiondetails.h"
#include "mc_action_actiondefinitiondetails_list.h"
#include "mc_action_actioninstancedetails.h"
#include "mc_action_actioninstancedetails_list.h"
#include "mc_action_actioncreationrequest.h"
#include "mc_action_actioncreationrequest_list.h"
#include "mc_action_actioncategory_list.h"
#include "mc_parameter_validity_list.h"
#include "mc_parameter_parameterdefinition.h"
#include "mc_parameter_parameterdefinition_list.h"
#include "mc_parameter_parametervalue.h"
#include "mc_parameter_parametervalue_list.h"
#include "mc_parameter_parameterconversion.h"
#include "mc_parameter_parameterconversion_list.h"
#include "mc_alert_alertdefinition.h"
#include "mc_alert_alertdefinition_list.h"
#include "mc_alert_alertevent.h"
#include "mc_alert_alertevent_list.h"
#include "mc_check_checkstate_list.h"
#include "mc_check_constantcheck.h"
#include "mc_check_constantcheck_list.h"
#include "mc_check_referencecheck.h"
#include "mc_check_referencecheck_list.h"
#include "mc_check_deltacheck.h"
#include "mc_check_deltacheck_list.h"
#include "mc_check_limitcheck.h"
#include "mc_check_limitcheck_list.h"
#include "mc_check_checklink.h"
#include "mc_check_checklink_list.h"
#include "mc_check_checkresult.h"
#include "mc_check_checkresult_list.h"
#include "mc_check_referencevalue.h"
#include "mc_check_referencevalue_list.h"
#include "mc_check_checkresultfilter.h"
#include "mc_check_checkresultfilter_list.h"
#include "mc_check_checksummary.h"
#include "mc_check_checksummary_list.h"
#include "mc_aggregation_aggregationcategory_list.h"
#include "mc_aggregation_thresholdtype_list.h"
#include "mc_aggregation_generationmode_list.h"
#include "mc_aggregation_aggregationdefinition.h"
#include "mc_aggregation_aggregationdefinition_list.h"
#include "mc_aggregation_aggregationvalue.h"
#include "mc_aggregation_aggregationvalue_list.h"
#include "mc_aggregation_aggregationreference.h"
#include "mc_aggregation_aggregationreference_list.h"
#include "mc_aggregation_thresholdfilter.h"
#include "mc_aggregation_thresholdfilter_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_H_INCLUDED__
