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
#define MC_AREA_VERSION 1

// generated code for enumeration mc_severity
typedef enum {
  MC_SEVERITY_INFORMATIONAL,
  MC_SEVERITY_WARNING,
  MC_SEVERITY_ALARM,
  MC_SEVERITY_SEVERE,
  MC_SEVERITY_CRITICAL
} mc_severity_t;

// short form for enumeration type mc_severity
#define MC_SEVERITY_SHORT_FORM 0x4000001000006L
#ifndef MC_SEVERITY_LIST_T_DEFINED
#define MC_SEVERITY_LIST_T_DEFINED

typedef struct _mc_severity_list_t mc_severity_list_t;

#endif // MC_SEVERITY_LIST_T_DEFINED

// short form for list of enumeration type mc_severity
#define MC_SEVERITY_LIST_SHORT_FORM 0x4000001fffffaL

// generated code for composite MC:_:ArgumentDefinitionDetails
#ifndef MC_ARGUMENTDEFINITIONDETAILS_T_DEFINED
#define MC_ARGUMENTDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_argumentdefinitiondetails_t mc_argumentdefinitiondetails_t;

#endif // MC_ARGUMENTDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:_:ArgumentDefinitionDetails
#define MC_ARGUMENTDEFINITIONDETAILS_SHORT_FORM 0x4000001000001L
#ifndef MC_ARGUMENTDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_ARGUMENTDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_argumentdefinitiondetails_list_t mc_argumentdefinitiondetails_list_t;

#endif // MC_ARGUMENTDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:_:ArgumentDefinitionDetails
#define MC_ARGUMENTDEFINITIONDETAILS_LIST_SHORT_FORM 0x4000001ffffffL

// generated code for composite MC:_:AttributeValue
#ifndef MC_ATTRIBUTEVALUE_T_DEFINED
#define MC_ATTRIBUTEVALUE_T_DEFINED

typedef struct _mc_attributevalue_t mc_attributevalue_t;

#endif // MC_ATTRIBUTEVALUE_T_DEFINED

// short form for composite type MC:_:AttributeValue
#define MC_ATTRIBUTEVALUE_SHORT_FORM 0x4000001000002L
#ifndef MC_ATTRIBUTEVALUE_LIST_T_DEFINED
#define MC_ATTRIBUTEVALUE_LIST_T_DEFINED

typedef struct _mc_attributevalue_list_t mc_attributevalue_list_t;

#endif // MC_ATTRIBUTEVALUE_LIST_T_DEFINED

// short form for list of composite type MC:_:AttributeValue
#define MC_ATTRIBUTEVALUE_LIST_SHORT_FORM 0x4000001fffffeL

// generated code for composite MC:_:ConditionalConversion
#ifndef MC_CONDITIONALCONVERSION_T_DEFINED
#define MC_CONDITIONALCONVERSION_T_DEFINED

typedef struct _mc_conditionalconversion_t mc_conditionalconversion_t;

#endif // MC_CONDITIONALCONVERSION_T_DEFINED

// short form for composite type MC:_:ConditionalConversion
#define MC_CONDITIONALCONVERSION_SHORT_FORM 0x4000001000003L
#ifndef MC_CONDITIONALCONVERSION_LIST_T_DEFINED
#define MC_CONDITIONALCONVERSION_LIST_T_DEFINED

typedef struct _mc_conditionalconversion_list_t mc_conditionalconversion_list_t;

#endif // MC_CONDITIONALCONVERSION_LIST_T_DEFINED

// short form for list of composite type MC:_:ConditionalConversion
#define MC_CONDITIONALCONVERSION_LIST_SHORT_FORM 0x4000001fffffdL

// generated code for composite MC:_:ParameterExpression
#ifndef MC_PARAMETEREXPRESSION_T_DEFINED
#define MC_PARAMETEREXPRESSION_T_DEFINED

typedef struct _mc_parameterexpression_t mc_parameterexpression_t;

#endif // MC_PARAMETEREXPRESSION_T_DEFINED

// short form for composite type MC:_:ParameterExpression
#define MC_PARAMETEREXPRESSION_SHORT_FORM 0x4000001000004L
#ifndef MC_PARAMETEREXPRESSION_LIST_T_DEFINED
#define MC_PARAMETEREXPRESSION_LIST_T_DEFINED

typedef struct _mc_parameterexpression_list_t mc_parameterexpression_list_t;

#endif // MC_PARAMETEREXPRESSION_LIST_T_DEFINED

// short form for list of composite type MC:_:ParameterExpression
#define MC_PARAMETEREXPRESSION_LIST_SHORT_FORM 0x4000001fffffcL

// generated code for composite MC:_:ObjectInstancePair
#ifndef MC_OBJECTINSTANCEPAIR_T_DEFINED
#define MC_OBJECTINSTANCEPAIR_T_DEFINED

typedef struct _mc_objectinstancepair_t mc_objectinstancepair_t;

#endif // MC_OBJECTINSTANCEPAIR_T_DEFINED

// short form for composite type MC:_:ObjectInstancePair
#define MC_OBJECTINSTANCEPAIR_SHORT_FORM 0x4000001000007L
#ifndef MC_OBJECTINSTANCEPAIR_LIST_T_DEFINED
#define MC_OBJECTINSTANCEPAIR_LIST_T_DEFINED

typedef struct _mc_objectinstancepair_list_t mc_objectinstancepair_list_t;

#endif // MC_OBJECTINSTANCEPAIR_LIST_T_DEFINED

// short form for list of composite type MC:_:ObjectInstancePair
#define MC_OBJECTINSTANCEPAIR_LIST_SHORT_FORM 0x4000001fffff9L

// standard service identifiers
#define MC_ACTION_SERVICE_NUMBER 1

// generated code for enumeration mc_action_actioncategory
typedef enum {
  MC_ACTION_ACTIONCATEGORY_DEFAULT,
  MC_ACTION_ACTIONCATEGORY_HIPRIORITY,
  MC_ACTION_ACTIONCATEGORY_CRITICAL
} mc_action_actioncategory_t;

// short form for enumeration type mc_action_actioncategory
#define MC_ACTION_ACTIONCATEGORY_SHORT_FORM 0x4000101000004L
#ifndef MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED
#define MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED

typedef struct _mc_action_actioncategory_list_t mc_action_actioncategory_list_t;

#endif // MC_ACTION_ACTIONCATEGORY_LIST_T_DEFINED

// short form for list of enumeration type mc_action_actioncategory
#define MC_ACTION_ACTIONCATEGORY_LIST_SHORT_FORM 0x4000101fffffcL

// generated code for composite MC:Action:ActionDefinitionDetails
#ifndef MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED
#define MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_action_actiondefinitiondetails_t mc_action_actiondefinitiondetails_t;

#endif // MC_ACTION_ACTIONDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:Action:ActionDefinitionDetails
#define MC_ACTION_ACTIONDEFINITIONDETAILS_SHORT_FORM 0x4000101000001L
#ifndef MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_action_actiondefinitiondetails_list_t mc_action_actiondefinitiondetails_list_t;

#endif // MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionDefinitionDetails
#define MC_ACTION_ACTIONDEFINITIONDETAILS_LIST_SHORT_FORM 0x4000101ffffffL

// generated code for composite MC:Action:ActionInstanceDetails
#ifndef MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED
#define MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED

typedef struct _mc_action_actioninstancedetails_t mc_action_actioninstancedetails_t;

#endif // MC_ACTION_ACTIONINSTANCEDETAILS_T_DEFINED

// short form for composite type MC:Action:ActionInstanceDetails
#define MC_ACTION_ACTIONINSTANCEDETAILS_SHORT_FORM 0x4000101000002L
#ifndef MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED
#define MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED

typedef struct _mc_action_actioninstancedetails_list_t mc_action_actioninstancedetails_list_t;

#endif // MC_ACTION_ACTIONINSTANCEDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionInstanceDetails
#define MC_ACTION_ACTIONINSTANCEDETAILS_LIST_SHORT_FORM 0x4000101fffffeL

// generated code for composite MC:Action:ActionCreationRequest
#ifndef MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED
#define MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED

typedef struct _mc_action_actioncreationrequest_t mc_action_actioncreationrequest_t;

#endif // MC_ACTION_ACTIONCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Action:ActionCreationRequest
#define MC_ACTION_ACTIONCREATIONREQUEST_SHORT_FORM 0x4000101000003L
#ifndef MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED
#define MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_action_actioncreationrequest_list_t mc_action_actioncreationrequest_list_t;

#endif // MC_ACTION_ACTIONCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Action:ActionCreationRequest
#define MC_ACTION_ACTIONCREATIONREQUEST_LIST_SHORT_FORM 0x4000101fffffdL

// standard service identifiers
#define MC_PARAMETER_SERVICE_NUMBER 2

// generated code for enumeration mc_parameter_validitystate
typedef enum {
  MC_PARAMETER_VALIDITYSTATE_VALID,
  MC_PARAMETER_VALIDITYSTATE_EXPIRED,
  MC_PARAMETER_VALIDITYSTATE_INVALID_RAW,
  MC_PARAMETER_VALIDITYSTATE_INVALID_CONVERSION,
  MC_PARAMETER_VALIDITYSTATE_UNVERIFIED,
  MC_PARAMETER_VALIDITYSTATE_INVALID
} mc_parameter_validitystate_t;

// short form for enumeration type mc_parameter_validitystate
#define MC_PARAMETER_VALIDITYSTATE_SHORT_FORM 0x4000201000004L
#ifndef MC_PARAMETER_VALIDITYSTATE_LIST_T_DEFINED
#define MC_PARAMETER_VALIDITYSTATE_LIST_T_DEFINED

typedef struct _mc_parameter_validitystate_list_t mc_parameter_validitystate_list_t;

#endif // MC_PARAMETER_VALIDITYSTATE_LIST_T_DEFINED

// short form for list of enumeration type mc_parameter_validitystate
#define MC_PARAMETER_VALIDITYSTATE_LIST_SHORT_FORM 0x4000201fffffcL

// generated code for composite MC:Parameter:ParameterDefinitionDetails
#ifndef MC_PARAMETER_PARAMETERDEFINITIONDETAILS_T_DEFINED
#define MC_PARAMETER_PARAMETERDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_parameter_parameterdefinitiondetails_t mc_parameter_parameterdefinitiondetails_t;

#endif // MC_PARAMETER_PARAMETERDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:Parameter:ParameterDefinitionDetails
#define MC_PARAMETER_PARAMETERDEFINITIONDETAILS_SHORT_FORM 0x4000201000001L
#ifndef MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_parameter_parameterdefinitiondetails_list_t mc_parameter_parameterdefinitiondetails_list_t;

#endif // MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterDefinitionDetails
#define MC_PARAMETER_PARAMETERDEFINITIONDETAILS_LIST_SHORT_FORM 0x4000201ffffffL

// generated code for composite MC:Parameter:ParameterValue
#ifndef MC_PARAMETER_PARAMETERVALUE_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUE_T_DEFINED

typedef struct _mc_parameter_parametervalue_t mc_parameter_parametervalue_t;

#endif // MC_PARAMETER_PARAMETERVALUE_T_DEFINED

// short form for composite type MC:Parameter:ParameterValue
#define MC_PARAMETER_PARAMETERVALUE_SHORT_FORM 0x4000201000002L
#ifndef MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED

typedef struct _mc_parameter_parametervalue_list_t mc_parameter_parametervalue_list_t;

#endif // MC_PARAMETER_PARAMETERVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterValue
#define MC_PARAMETER_PARAMETERVALUE_LIST_SHORT_FORM 0x4000201fffffeL

// generated code for composite MC:Parameter:ParameterConversion
#ifndef MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED
#define MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED

typedef struct _mc_parameter_parameterconversion_t mc_parameter_parameterconversion_t;

#endif // MC_PARAMETER_PARAMETERCONVERSION_T_DEFINED

// short form for composite type MC:Parameter:ParameterConversion
#define MC_PARAMETER_PARAMETERCONVERSION_SHORT_FORM 0x4000201000003L
#ifndef MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED

typedef struct _mc_parameter_parameterconversion_list_t mc_parameter_parameterconversion_list_t;

#endif // MC_PARAMETER_PARAMETERCONVERSION_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterConversion
#define MC_PARAMETER_PARAMETERCONVERSION_LIST_SHORT_FORM 0x4000201fffffdL

// generated code for composite MC:Parameter:ParameterCreationRequest
#ifndef MC_PARAMETER_PARAMETERCREATIONREQUEST_T_DEFINED
#define MC_PARAMETER_PARAMETERCREATIONREQUEST_T_DEFINED

typedef struct _mc_parameter_parametercreationrequest_t mc_parameter_parametercreationrequest_t;

#endif // MC_PARAMETER_PARAMETERCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Parameter:ParameterCreationRequest
#define MC_PARAMETER_PARAMETERCREATIONREQUEST_SHORT_FORM 0x4000201000005L
#ifndef MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_parameter_parametercreationrequest_list_t mc_parameter_parametercreationrequest_list_t;

#endif // MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterCreationRequest
#define MC_PARAMETER_PARAMETERCREATIONREQUEST_LIST_SHORT_FORM 0x4000201fffffbL

// generated code for composite MC:Parameter:ParameterRawValue
#ifndef MC_PARAMETER_PARAMETERRAWVALUE_T_DEFINED
#define MC_PARAMETER_PARAMETERRAWVALUE_T_DEFINED

typedef struct _mc_parameter_parameterrawvalue_t mc_parameter_parameterrawvalue_t;

#endif // MC_PARAMETER_PARAMETERRAWVALUE_T_DEFINED

// short form for composite type MC:Parameter:ParameterRawValue
#define MC_PARAMETER_PARAMETERRAWVALUE_SHORT_FORM 0x4000201000006L
#ifndef MC_PARAMETER_PARAMETERRAWVALUE_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERRAWVALUE_LIST_T_DEFINED

typedef struct _mc_parameter_parameterrawvalue_list_t mc_parameter_parameterrawvalue_list_t;

#endif // MC_PARAMETER_PARAMETERRAWVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterRawValue
#define MC_PARAMETER_PARAMETERRAWVALUE_LIST_SHORT_FORM 0x4000201fffffaL

// generated code for composite MC:Parameter:ParameterValueDetails
#ifndef MC_PARAMETER_PARAMETERVALUEDETAILS_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUEDETAILS_T_DEFINED

typedef struct _mc_parameter_parametervaluedetails_t mc_parameter_parametervaluedetails_t;

#endif // MC_PARAMETER_PARAMETERVALUEDETAILS_T_DEFINED

// short form for composite type MC:Parameter:ParameterValueDetails
#define MC_PARAMETER_PARAMETERVALUEDETAILS_SHORT_FORM 0x4000201000007L
#ifndef MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_T_DEFINED
#define MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_T_DEFINED

typedef struct _mc_parameter_parametervaluedetails_list_t mc_parameter_parametervaluedetails_list_t;

#endif // MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Parameter:ParameterValueDetails
#define MC_PARAMETER_PARAMETERVALUEDETAILS_LIST_SHORT_FORM 0x4000201fffff9L

// standard service identifiers
#define MC_ALERT_SERVICE_NUMBER 3

// generated code for composite MC:Alert:AlertDefinitionDetails
#ifndef MC_ALERT_ALERTDEFINITIONDETAILS_T_DEFINED
#define MC_ALERT_ALERTDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_alert_alertdefinitiondetails_t mc_alert_alertdefinitiondetails_t;

#endif // MC_ALERT_ALERTDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:Alert:AlertDefinitionDetails
#define MC_ALERT_ALERTDEFINITIONDETAILS_SHORT_FORM 0x4000301000001L
#ifndef MC_ALERT_ALERTDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_ALERT_ALERTDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_alert_alertdefinitiondetails_list_t mc_alert_alertdefinitiondetails_list_t;

#endif // MC_ALERT_ALERTDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Alert:AlertDefinitionDetails
#define MC_ALERT_ALERTDEFINITIONDETAILS_LIST_SHORT_FORM 0x4000301ffffffL

// generated code for composite MC:Alert:AlertEventDetails
#ifndef MC_ALERT_ALERTEVENTDETAILS_T_DEFINED
#define MC_ALERT_ALERTEVENTDETAILS_T_DEFINED

typedef struct _mc_alert_alerteventdetails_t mc_alert_alerteventdetails_t;

#endif // MC_ALERT_ALERTEVENTDETAILS_T_DEFINED

// short form for composite type MC:Alert:AlertEventDetails
#define MC_ALERT_ALERTEVENTDETAILS_SHORT_FORM 0x4000301000002L
#ifndef MC_ALERT_ALERTEVENTDETAILS_LIST_T_DEFINED
#define MC_ALERT_ALERTEVENTDETAILS_LIST_T_DEFINED

typedef struct _mc_alert_alerteventdetails_list_t mc_alert_alerteventdetails_list_t;

#endif // MC_ALERT_ALERTEVENTDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Alert:AlertEventDetails
#define MC_ALERT_ALERTEVENTDETAILS_LIST_SHORT_FORM 0x4000301fffffeL

// generated code for composite MC:Alert:AlertCreationRequest
#ifndef MC_ALERT_ALERTCREATIONREQUEST_T_DEFINED
#define MC_ALERT_ALERTCREATIONREQUEST_T_DEFINED

typedef struct _mc_alert_alertcreationrequest_t mc_alert_alertcreationrequest_t;

#endif // MC_ALERT_ALERTCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Alert:AlertCreationRequest
#define MC_ALERT_ALERTCREATIONREQUEST_SHORT_FORM 0x4000301000003L
#ifndef MC_ALERT_ALERTCREATIONREQUEST_LIST_T_DEFINED
#define MC_ALERT_ALERTCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_alert_alertcreationrequest_list_t mc_alert_alertcreationrequest_list_t;

#endif // MC_ALERT_ALERTCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Alert:AlertCreationRequest
#define MC_ALERT_ALERTCREATIONREQUEST_LIST_SHORT_FORM 0x4000301fffffdL

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
#define MC_CHECK_CHECKSTATE_SHORT_FORM 0x4000401000006L
#ifndef MC_CHECK_CHECKSTATE_LIST_T_DEFINED
#define MC_CHECK_CHECKSTATE_LIST_T_DEFINED

typedef struct _mc_check_checkstate_list_t mc_check_checkstate_list_t;

#endif // MC_CHECK_CHECKSTATE_LIST_T_DEFINED

// short form for list of enumeration type mc_check_checkstate
#define MC_CHECK_CHECKSTATE_LIST_SHORT_FORM 0x4000401fffffaL

// generated code for composite MC:Check:CheckLinkDetails
#ifndef MC_CHECK_CHECKLINKDETAILS_T_DEFINED
#define MC_CHECK_CHECKLINKDETAILS_T_DEFINED

typedef struct _mc_check_checklinkdetails_t mc_check_checklinkdetails_t;

#endif // MC_CHECK_CHECKLINKDETAILS_T_DEFINED

// short form for composite type MC:Check:CheckLinkDetails
#define MC_CHECK_CHECKLINKDETAILS_SHORT_FORM 0x4000401000001L
#ifndef MC_CHECK_CHECKLINKDETAILS_LIST_T_DEFINED
#define MC_CHECK_CHECKLINKDETAILS_LIST_T_DEFINED

typedef struct _mc_check_checklinkdetails_list_t mc_check_checklinkdetails_list_t;

#endif // MC_CHECK_CHECKLINKDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckLinkDetails
#define MC_CHECK_CHECKLINKDETAILS_LIST_SHORT_FORM 0x4000401ffffffL

// generated code for composite MC:Check:CheckResult
#ifndef MC_CHECK_CHECKRESULT_T_DEFINED
#define MC_CHECK_CHECKRESULT_T_DEFINED

typedef struct _mc_check_checkresult_t mc_check_checkresult_t;

#endif // MC_CHECK_CHECKRESULT_T_DEFINED

// short form for composite type MC:Check:CheckResult
#define MC_CHECK_CHECKRESULT_SHORT_FORM 0x4000401000002L
#ifndef MC_CHECK_CHECKRESULT_LIST_T_DEFINED
#define MC_CHECK_CHECKRESULT_LIST_T_DEFINED

typedef struct _mc_check_checkresult_list_t mc_check_checkresult_list_t;

#endif // MC_CHECK_CHECKRESULT_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckResult
#define MC_CHECK_CHECKRESULT_LIST_SHORT_FORM 0x4000401fffffeL

// generated code for composite MC:Check:CheckLinkSummary
#ifndef MC_CHECK_CHECKLINKSUMMARY_T_DEFINED
#define MC_CHECK_CHECKLINKSUMMARY_T_DEFINED

typedef struct _mc_check_checklinksummary_t mc_check_checklinksummary_t;

#endif // MC_CHECK_CHECKLINKSUMMARY_T_DEFINED

// short form for composite type MC:Check:CheckLinkSummary
#define MC_CHECK_CHECKLINKSUMMARY_SHORT_FORM 0x4000401000003L
#ifndef MC_CHECK_CHECKLINKSUMMARY_LIST_T_DEFINED
#define MC_CHECK_CHECKLINKSUMMARY_LIST_T_DEFINED

typedef struct _mc_check_checklinksummary_list_t mc_check_checklinksummary_list_t;

#endif // MC_CHECK_CHECKLINKSUMMARY_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckLinkSummary
#define MC_CHECK_CHECKLINKSUMMARY_LIST_SHORT_FORM 0x4000401fffffdL

// generated code for composite MC:Check:CheckResultSummary
#ifndef MC_CHECK_CHECKRESULTSUMMARY_T_DEFINED
#define MC_CHECK_CHECKRESULTSUMMARY_T_DEFINED

typedef struct _mc_check_checkresultsummary_t mc_check_checkresultsummary_t;

#endif // MC_CHECK_CHECKRESULTSUMMARY_T_DEFINED

// short form for composite type MC:Check:CheckResultSummary
#define MC_CHECK_CHECKRESULTSUMMARY_SHORT_FORM 0x4000401000004L
#ifndef MC_CHECK_CHECKRESULTSUMMARY_LIST_T_DEFINED
#define MC_CHECK_CHECKRESULTSUMMARY_LIST_T_DEFINED

typedef struct _mc_check_checkresultsummary_list_t mc_check_checkresultsummary_list_t;

#endif // MC_CHECK_CHECKRESULTSUMMARY_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckResultSummary
#define MC_CHECK_CHECKRESULTSUMMARY_LIST_SHORT_FORM 0x4000401fffffcL

// generated code for composite MC:Check:CheckResultFilter
#ifndef MC_CHECK_CHECKRESULTFILTER_T_DEFINED
#define MC_CHECK_CHECKRESULTFILTER_T_DEFINED

typedef struct _mc_check_checkresultfilter_t mc_check_checkresultfilter_t;

#endif // MC_CHECK_CHECKRESULTFILTER_T_DEFINED

// short form for composite type MC:Check:CheckResultFilter
#define MC_CHECK_CHECKRESULTFILTER_SHORT_FORM 0x4000401000005L
#ifndef MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED
#define MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED

typedef struct _mc_check_checkresultfilter_list_t mc_check_checkresultfilter_list_t;

#endif // MC_CHECK_CHECKRESULTFILTER_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckResultFilter
#define MC_CHECK_CHECKRESULTFILTER_LIST_SHORT_FORM 0x4000401fffffbL

// generated code for composite MC:Check:ReferenceValue
#ifndef MC_CHECK_REFERENCEVALUE_T_DEFINED
#define MC_CHECK_REFERENCEVALUE_T_DEFINED

typedef struct _mc_check_referencevalue_t mc_check_referencevalue_t;

#endif // MC_CHECK_REFERENCEVALUE_T_DEFINED

// short form for composite type MC:Check:ReferenceValue
#define MC_CHECK_REFERENCEVALUE_SHORT_FORM 0x4000401000007L
#ifndef MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED
#define MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED

typedef struct _mc_check_referencevalue_list_t mc_check_referencevalue_list_t;

#endif // MC_CHECK_REFERENCEVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Check:ReferenceValue
#define MC_CHECK_REFERENCEVALUE_LIST_SHORT_FORM 0x4000401fffff9L

// generated code for composite MC:Check:ConstantCheckDefinition
#ifndef MC_CHECK_CONSTANTCHECKDEFINITION_T_DEFINED
#define MC_CHECK_CONSTANTCHECKDEFINITION_T_DEFINED

typedef struct _mc_check_constantcheckdefinition_t mc_check_constantcheckdefinition_t;

#endif // MC_CHECK_CONSTANTCHECKDEFINITION_T_DEFINED

// short form for composite type MC:Check:ConstantCheckDefinition
#define MC_CHECK_CONSTANTCHECKDEFINITION_SHORT_FORM 0x4000401000008L
#ifndef MC_CHECK_CONSTANTCHECKDEFINITION_LIST_T_DEFINED
#define MC_CHECK_CONSTANTCHECKDEFINITION_LIST_T_DEFINED

typedef struct _mc_check_constantcheckdefinition_list_t mc_check_constantcheckdefinition_list_t;

#endif // MC_CHECK_CONSTANTCHECKDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Check:ConstantCheckDefinition
#define MC_CHECK_CONSTANTCHECKDEFINITION_LIST_SHORT_FORM 0x4000401fffff8L

// generated code for composite MC:Check:ReferenceCheckDefinition
#ifndef MC_CHECK_REFERENCECHECKDEFINITION_T_DEFINED
#define MC_CHECK_REFERENCECHECKDEFINITION_T_DEFINED

typedef struct _mc_check_referencecheckdefinition_t mc_check_referencecheckdefinition_t;

#endif // MC_CHECK_REFERENCECHECKDEFINITION_T_DEFINED

// short form for composite type MC:Check:ReferenceCheckDefinition
#define MC_CHECK_REFERENCECHECKDEFINITION_SHORT_FORM 0x4000401000009L
#ifndef MC_CHECK_REFERENCECHECKDEFINITION_LIST_T_DEFINED
#define MC_CHECK_REFERENCECHECKDEFINITION_LIST_T_DEFINED

typedef struct _mc_check_referencecheckdefinition_list_t mc_check_referencecheckdefinition_list_t;

#endif // MC_CHECK_REFERENCECHECKDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Check:ReferenceCheckDefinition
#define MC_CHECK_REFERENCECHECKDEFINITION_LIST_SHORT_FORM 0x4000401fffff7L

// generated code for composite MC:Check:DeltaCheckDefinition
#ifndef MC_CHECK_DELTACHECKDEFINITION_T_DEFINED
#define MC_CHECK_DELTACHECKDEFINITION_T_DEFINED

typedef struct _mc_check_deltacheckdefinition_t mc_check_deltacheckdefinition_t;

#endif // MC_CHECK_DELTACHECKDEFINITION_T_DEFINED

// short form for composite type MC:Check:DeltaCheckDefinition
#define MC_CHECK_DELTACHECKDEFINITION_SHORT_FORM 0x400040100000aL
#ifndef MC_CHECK_DELTACHECKDEFINITION_LIST_T_DEFINED
#define MC_CHECK_DELTACHECKDEFINITION_LIST_T_DEFINED

typedef struct _mc_check_deltacheckdefinition_list_t mc_check_deltacheckdefinition_list_t;

#endif // MC_CHECK_DELTACHECKDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Check:DeltaCheckDefinition
#define MC_CHECK_DELTACHECKDEFINITION_LIST_SHORT_FORM 0x4000401fffff6L

// generated code for composite MC:Check:LimitCheckDefinition
#ifndef MC_CHECK_LIMITCHECKDEFINITION_T_DEFINED
#define MC_CHECK_LIMITCHECKDEFINITION_T_DEFINED

typedef struct _mc_check_limitcheckdefinition_t mc_check_limitcheckdefinition_t;

#endif // MC_CHECK_LIMITCHECKDEFINITION_T_DEFINED

// short form for composite type MC:Check:LimitCheckDefinition
#define MC_CHECK_LIMITCHECKDEFINITION_SHORT_FORM 0x400040100000bL
#ifndef MC_CHECK_LIMITCHECKDEFINITION_LIST_T_DEFINED
#define MC_CHECK_LIMITCHECKDEFINITION_LIST_T_DEFINED

typedef struct _mc_check_limitcheckdefinition_list_t mc_check_limitcheckdefinition_list_t;

#endif // MC_CHECK_LIMITCHECKDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Check:LimitCheckDefinition
#define MC_CHECK_LIMITCHECKDEFINITION_LIST_SHORT_FORM 0x4000401fffff5L

// generated code for composite MC:Check:CompoundCheckDefinition
#ifndef MC_CHECK_COMPOUNDCHECKDEFINITION_T_DEFINED
#define MC_CHECK_COMPOUNDCHECKDEFINITION_T_DEFINED

typedef struct _mc_check_compoundcheckdefinition_t mc_check_compoundcheckdefinition_t;

#endif // MC_CHECK_COMPOUNDCHECKDEFINITION_T_DEFINED

// short form for composite type MC:Check:CompoundCheckDefinition
#define MC_CHECK_COMPOUNDCHECKDEFINITION_SHORT_FORM 0x400040100000cL
#ifndef MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_T_DEFINED
#define MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_T_DEFINED

typedef struct _mc_check_compoundcheckdefinition_list_t mc_check_compoundcheckdefinition_list_t;

#endif // MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_T_DEFINED

// short form for list of composite type MC:Check:CompoundCheckDefinition
#define MC_CHECK_COMPOUNDCHECKDEFINITION_LIST_SHORT_FORM 0x4000401fffff4L

// generated code for composite MC:Check:CheckTypedInstance
#ifndef MC_CHECK_CHECKTYPEDINSTANCE_T_DEFINED
#define MC_CHECK_CHECKTYPEDINSTANCE_T_DEFINED

typedef struct _mc_check_checktypedinstance_t mc_check_checktypedinstance_t;

#endif // MC_CHECK_CHECKTYPEDINSTANCE_T_DEFINED

// short form for composite type MC:Check:CheckTypedInstance
#define MC_CHECK_CHECKTYPEDINSTANCE_SHORT_FORM 0x400040100000dL
#ifndef MC_CHECK_CHECKTYPEDINSTANCE_LIST_T_DEFINED
#define MC_CHECK_CHECKTYPEDINSTANCE_LIST_T_DEFINED

typedef struct _mc_check_checktypedinstance_list_t mc_check_checktypedinstance_list_t;

#endif // MC_CHECK_CHECKTYPEDINSTANCE_LIST_T_DEFINED

// short form for list of composite type MC:Check:CheckTypedInstance
#define MC_CHECK_CHECKTYPEDINSTANCE_LIST_SHORT_FORM 0x4000401fffff3L

// standard service identifiers
#define MC_STATISTIC_SERVICE_NUMBER 5

// generated code for composite MC:Statistic:StatisticFunctionDetails
#ifndef MC_STATISTIC_STATISTICFUNCTIONDETAILS_T_DEFINED
#define MC_STATISTIC_STATISTICFUNCTIONDETAILS_T_DEFINED

typedef struct _mc_statistic_statisticfunctiondetails_t mc_statistic_statisticfunctiondetails_t;

#endif // MC_STATISTIC_STATISTICFUNCTIONDETAILS_T_DEFINED

// short form for composite type MC:Statistic:StatisticFunctionDetails
#define MC_STATISTIC_STATISTICFUNCTIONDETAILS_SHORT_FORM 0x4000501000001L
#ifndef MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_T_DEFINED

typedef struct _mc_statistic_statisticfunctiondetails_list_t mc_statistic_statisticfunctiondetails_list_t;

#endif // MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticFunctionDetails
#define MC_STATISTIC_STATISTICFUNCTIONDETAILS_LIST_SHORT_FORM 0x4000501ffffffL

// generated code for composite MC:Statistic:StatisticLinkDetails
#ifndef MC_STATISTIC_STATISTICLINKDETAILS_T_DEFINED
#define MC_STATISTIC_STATISTICLINKDETAILS_T_DEFINED

typedef struct _mc_statistic_statisticlinkdetails_t mc_statistic_statisticlinkdetails_t;

#endif // MC_STATISTIC_STATISTICLINKDETAILS_T_DEFINED

// short form for composite type MC:Statistic:StatisticLinkDetails
#define MC_STATISTIC_STATISTICLINKDETAILS_SHORT_FORM 0x4000501000002L
#ifndef MC_STATISTIC_STATISTICLINKDETAILS_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICLINKDETAILS_LIST_T_DEFINED

typedef struct _mc_statistic_statisticlinkdetails_list_t mc_statistic_statisticlinkdetails_list_t;

#endif // MC_STATISTIC_STATISTICLINKDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticLinkDetails
#define MC_STATISTIC_STATISTICLINKDETAILS_LIST_SHORT_FORM 0x4000501fffffeL

// generated code for composite MC:Statistic:StatisticValue
#ifndef MC_STATISTIC_STATISTICVALUE_T_DEFINED
#define MC_STATISTIC_STATISTICVALUE_T_DEFINED

typedef struct _mc_statistic_statisticvalue_t mc_statistic_statisticvalue_t;

#endif // MC_STATISTIC_STATISTICVALUE_T_DEFINED

// short form for composite type MC:Statistic:StatisticValue
#define MC_STATISTIC_STATISTICVALUE_SHORT_FORM 0x4000501000003L
#ifndef MC_STATISTIC_STATISTICVALUE_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICVALUE_LIST_T_DEFINED

typedef struct _mc_statistic_statisticvalue_list_t mc_statistic_statisticvalue_list_t;

#endif // MC_STATISTIC_STATISTICVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticValue
#define MC_STATISTIC_STATISTICVALUE_LIST_SHORT_FORM 0x4000501fffffdL

// generated code for composite MC:Statistic:StatisticCreationRequest
#ifndef MC_STATISTIC_STATISTICCREATIONREQUEST_T_DEFINED
#define MC_STATISTIC_STATISTICCREATIONREQUEST_T_DEFINED

typedef struct _mc_statistic_statisticcreationrequest_t mc_statistic_statisticcreationrequest_t;

#endif // MC_STATISTIC_STATISTICCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Statistic:StatisticCreationRequest
#define MC_STATISTIC_STATISTICCREATIONREQUEST_SHORT_FORM 0x4000501000004L
#ifndef MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_statistic_statisticcreationrequest_list_t mc_statistic_statisticcreationrequest_list_t;

#endif // MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticCreationRequest
#define MC_STATISTIC_STATISTICCREATIONREQUEST_LIST_SHORT_FORM 0x4000501fffffcL

// generated code for composite MC:Statistic:StatisticLinkSummary
#ifndef MC_STATISTIC_STATISTICLINKSUMMARY_T_DEFINED
#define MC_STATISTIC_STATISTICLINKSUMMARY_T_DEFINED

typedef struct _mc_statistic_statisticlinksummary_t mc_statistic_statisticlinksummary_t;

#endif // MC_STATISTIC_STATISTICLINKSUMMARY_T_DEFINED

// short form for composite type MC:Statistic:StatisticLinkSummary
#define MC_STATISTIC_STATISTICLINKSUMMARY_SHORT_FORM 0x4000501000005L
#ifndef MC_STATISTIC_STATISTICLINKSUMMARY_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICLINKSUMMARY_LIST_T_DEFINED

typedef struct _mc_statistic_statisticlinksummary_list_t mc_statistic_statisticlinksummary_list_t;

#endif // MC_STATISTIC_STATISTICLINKSUMMARY_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticLinkSummary
#define MC_STATISTIC_STATISTICLINKSUMMARY_LIST_SHORT_FORM 0x4000501fffffbL

// generated code for composite MC:Statistic:StatisticEvaluationReport
#ifndef MC_STATISTIC_STATISTICEVALUATIONREPORT_T_DEFINED
#define MC_STATISTIC_STATISTICEVALUATIONREPORT_T_DEFINED

typedef struct _mc_statistic_statisticevaluationreport_t mc_statistic_statisticevaluationreport_t;

#endif // MC_STATISTIC_STATISTICEVALUATIONREPORT_T_DEFINED

// short form for composite type MC:Statistic:StatisticEvaluationReport
#define MC_STATISTIC_STATISTICEVALUATIONREPORT_SHORT_FORM 0x4000501000006L
#ifndef MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_T_DEFINED
#define MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_T_DEFINED

typedef struct _mc_statistic_statisticevaluationreport_list_t mc_statistic_statisticevaluationreport_list_t;

#endif // MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_T_DEFINED

// short form for list of composite type MC:Statistic:StatisticEvaluationReport
#define MC_STATISTIC_STATISTICEVALUATIONREPORT_LIST_SHORT_FORM 0x4000501fffffaL

// standard service identifiers
#define MC_AGGREGATION_SERVICE_NUMBER 6

// generated code for enumeration mc_aggregation_aggregationcategory
typedef enum {
  MC_AGGREGATION_AGGREGATIONCATEGORY_GENERAL,
  MC_AGGREGATION_AGGREGATIONCATEGORY_DIAGNOSTIC
} mc_aggregation_aggregationcategory_t;

// short form for enumeration type mc_aggregation_aggregationcategory
#define MC_AGGREGATION_AGGREGATIONCATEGORY_SHORT_FORM 0x4000601000007L
#ifndef MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationcategory_list_t mc_aggregation_aggregationcategory_list_t;

#endif // MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_aggregationcategory
#define MC_AGGREGATION_AGGREGATIONCATEGORY_LIST_SHORT_FORM 0x4000601fffff9L

// generated code for enumeration mc_aggregation_thresholdtype
typedef enum {
  MC_AGGREGATION_THRESHOLDTYPE_PERCENTAGE,
  MC_AGGREGATION_THRESHOLDTYPE_DELTA
} mc_aggregation_thresholdtype_t;

// short form for enumeration type mc_aggregation_thresholdtype
#define MC_AGGREGATION_THRESHOLDTYPE_SHORT_FORM 0x4000601000008L
#ifndef MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED
#define MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED

typedef struct _mc_aggregation_thresholdtype_list_t mc_aggregation_thresholdtype_list_t;

#endif // MC_AGGREGATION_THRESHOLDTYPE_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_thresholdtype
#define MC_AGGREGATION_THRESHOLDTYPE_LIST_SHORT_FORM 0x4000601fffff8L

// generated code for enumeration mc_aggregation_generationmode
typedef enum {
  MC_AGGREGATION_GENERATIONMODE_ADHOC,
  MC_AGGREGATION_GENERATIONMODE_PERIODIC,
  MC_AGGREGATION_GENERATIONMODE_FILTERED_TIMEOUT
} mc_aggregation_generationmode_t;

// short form for enumeration type mc_aggregation_generationmode
#define MC_AGGREGATION_GENERATIONMODE_SHORT_FORM 0x4000601000009L
#ifndef MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED
#define MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED

typedef struct _mc_aggregation_generationmode_list_t mc_aggregation_generationmode_list_t;

#endif // MC_AGGREGATION_GENERATIONMODE_LIST_T_DEFINED

// short form for list of enumeration type mc_aggregation_generationmode
#define MC_AGGREGATION_GENERATIONMODE_LIST_SHORT_FORM 0x4000601fffff7L

// generated code for composite MC:Aggregation:AggregationDefinitionDetails
#ifndef MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_T_DEFINED

typedef struct _mc_aggregation_aggregationdefinitiondetails_t mc_aggregation_aggregationdefinitiondetails_t;

#endif // MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_T_DEFINED

// short form for composite type MC:Aggregation:AggregationDefinitionDetails
#define MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_SHORT_FORM 0x4000601000001L
#ifndef MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationdefinitiondetails_list_t mc_aggregation_aggregationdefinitiondetails_list_t;

#endif // MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationDefinitionDetails
#define MC_AGGREGATION_AGGREGATIONDEFINITIONDETAILS_LIST_SHORT_FORM 0x4000601ffffffL

// generated code for composite MC:Aggregation:AggregationParameterSet
#ifndef MC_AGGREGATION_AGGREGATIONPARAMETERSET_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONPARAMETERSET_T_DEFINED

typedef struct _mc_aggregation_aggregationparameterset_t mc_aggregation_aggregationparameterset_t;

#endif // MC_AGGREGATION_AGGREGATIONPARAMETERSET_T_DEFINED

// short form for composite type MC:Aggregation:AggregationParameterSet
#define MC_AGGREGATION_AGGREGATIONPARAMETERSET_SHORT_FORM 0x4000601000002L
#ifndef MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationparameterset_list_t mc_aggregation_aggregationparameterset_list_t;

#endif // MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationParameterSet
#define MC_AGGREGATION_AGGREGATIONPARAMETERSET_LIST_SHORT_FORM 0x4000601fffffeL

// generated code for composite MC:Aggregation:AggregationValue
#ifndef MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED

typedef struct _mc_aggregation_aggregationvalue_t mc_aggregation_aggregationvalue_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUE_T_DEFINED

// short form for composite type MC:Aggregation:AggregationValue
#define MC_AGGREGATION_AGGREGATIONVALUE_SHORT_FORM 0x4000601000003L
#ifndef MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationvalue_list_t mc_aggregation_aggregationvalue_list_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationValue
#define MC_AGGREGATION_AGGREGATIONVALUE_LIST_SHORT_FORM 0x4000601fffffdL

// generated code for composite MC:Aggregation:AggregationSetValue
#ifndef MC_AGGREGATION_AGGREGATIONSETVALUE_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONSETVALUE_T_DEFINED

typedef struct _mc_aggregation_aggregationsetvalue_t mc_aggregation_aggregationsetvalue_t;

#endif // MC_AGGREGATION_AGGREGATIONSETVALUE_T_DEFINED

// short form for composite type MC:Aggregation:AggregationSetValue
#define MC_AGGREGATION_AGGREGATIONSETVALUE_SHORT_FORM 0x4000601000004L
#ifndef MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationsetvalue_list_t mc_aggregation_aggregationsetvalue_list_t;

#endif // MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationSetValue
#define MC_AGGREGATION_AGGREGATIONSETVALUE_LIST_SHORT_FORM 0x4000601fffffcL

// generated code for composite MC:Aggregation:AggregationParameterValue
#ifndef MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_T_DEFINED

typedef struct _mc_aggregation_aggregationparametervalue_t mc_aggregation_aggregationparametervalue_t;

#endif // MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_T_DEFINED

// short form for composite type MC:Aggregation:AggregationParameterValue
#define MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_SHORT_FORM 0x4000601000005L
#ifndef MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationparametervalue_list_t mc_aggregation_aggregationparametervalue_list_t;

#endif // MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationParameterValue
#define MC_AGGREGATION_AGGREGATIONPARAMETERVALUE_LIST_SHORT_FORM 0x4000601fffffbL

// generated code for composite MC:Aggregation:ThresholdFilter
#ifndef MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED
#define MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED

typedef struct _mc_aggregation_thresholdfilter_t mc_aggregation_thresholdfilter_t;

#endif // MC_AGGREGATION_THRESHOLDFILTER_T_DEFINED

// short form for composite type MC:Aggregation:ThresholdFilter
#define MC_AGGREGATION_THRESHOLDFILTER_SHORT_FORM 0x4000601000006L
#ifndef MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED
#define MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED

typedef struct _mc_aggregation_thresholdfilter_list_t mc_aggregation_thresholdfilter_list_t;

#endif // MC_AGGREGATION_THRESHOLDFILTER_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:ThresholdFilter
#define MC_AGGREGATION_THRESHOLDFILTER_LIST_SHORT_FORM 0x4000601fffffaL

// generated code for composite MC:Aggregation:AggregationCreationRequest
#ifndef MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_T_DEFINED

typedef struct _mc_aggregation_aggregationcreationrequest_t mc_aggregation_aggregationcreationrequest_t;

#endif // MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_T_DEFINED

// short form for composite type MC:Aggregation:AggregationCreationRequest
#define MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_SHORT_FORM 0x400060100000aL
#ifndef MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationcreationrequest_list_t mc_aggregation_aggregationcreationrequest_list_t;

#endif // MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationCreationRequest
#define MC_AGGREGATION_AGGREGATIONCREATIONREQUEST_LIST_SHORT_FORM 0x4000601fffff6L

// generated code for composite MC:Aggregation:AggregationValueDetails
#ifndef MC_AGGREGATION_AGGREGATIONVALUEDETAILS_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUEDETAILS_T_DEFINED

typedef struct _mc_aggregation_aggregationvaluedetails_t mc_aggregation_aggregationvaluedetails_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUEDETAILS_T_DEFINED

// short form for composite type MC:Aggregation:AggregationValueDetails
#define MC_AGGREGATION_AGGREGATIONVALUEDETAILS_SHORT_FORM 0x400060100000bL
#ifndef MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_T_DEFINED
#define MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_T_DEFINED

typedef struct _mc_aggregation_aggregationvaluedetails_list_t mc_aggregation_aggregationvaluedetails_list_t;

#endif // MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Aggregation:AggregationValueDetails
#define MC_AGGREGATION_AGGREGATIONVALUEDETAILS_LIST_SHORT_FORM 0x4000601fffff5L

// standard service identifiers
#define MC_CONVERSION_SERVICE_NUMBER 7

// generated code for composite MC:Conversion:DiscreteConversionDetails
#ifndef MC_CONVERSION_DISCRETECONVERSIONDETAILS_T_DEFINED
#define MC_CONVERSION_DISCRETECONVERSIONDETAILS_T_DEFINED

typedef struct _mc_conversion_discreteconversiondetails_t mc_conversion_discreteconversiondetails_t;

#endif // MC_CONVERSION_DISCRETECONVERSIONDETAILS_T_DEFINED

// short form for composite type MC:Conversion:DiscreteConversionDetails
#define MC_CONVERSION_DISCRETECONVERSIONDETAILS_SHORT_FORM 0x4000701000001L
#ifndef MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_T_DEFINED
#define MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_T_DEFINED

typedef struct _mc_conversion_discreteconversiondetails_list_t mc_conversion_discreteconversiondetails_list_t;

#endif // MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Conversion:DiscreteConversionDetails
#define MC_CONVERSION_DISCRETECONVERSIONDETAILS_LIST_SHORT_FORM 0x4000701ffffffL

// generated code for composite MC:Conversion:LineConversionDetails
#ifndef MC_CONVERSION_LINECONVERSIONDETAILS_T_DEFINED
#define MC_CONVERSION_LINECONVERSIONDETAILS_T_DEFINED

typedef struct _mc_conversion_lineconversiondetails_t mc_conversion_lineconversiondetails_t;

#endif // MC_CONVERSION_LINECONVERSIONDETAILS_T_DEFINED

// short form for composite type MC:Conversion:LineConversionDetails
#define MC_CONVERSION_LINECONVERSIONDETAILS_SHORT_FORM 0x4000701000002L
#ifndef MC_CONVERSION_LINECONVERSIONDETAILS_LIST_T_DEFINED
#define MC_CONVERSION_LINECONVERSIONDETAILS_LIST_T_DEFINED

typedef struct _mc_conversion_lineconversiondetails_list_t mc_conversion_lineconversiondetails_list_t;

#endif // MC_CONVERSION_LINECONVERSIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Conversion:LineConversionDetails
#define MC_CONVERSION_LINECONVERSIONDETAILS_LIST_SHORT_FORM 0x4000701fffffeL

// generated code for composite MC:Conversion:PolyConversionDetails
#ifndef MC_CONVERSION_POLYCONVERSIONDETAILS_T_DEFINED
#define MC_CONVERSION_POLYCONVERSIONDETAILS_T_DEFINED

typedef struct _mc_conversion_polyconversiondetails_t mc_conversion_polyconversiondetails_t;

#endif // MC_CONVERSION_POLYCONVERSIONDETAILS_T_DEFINED

// short form for composite type MC:Conversion:PolyConversionDetails
#define MC_CONVERSION_POLYCONVERSIONDETAILS_SHORT_FORM 0x4000701000003L
#ifndef MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_T_DEFINED
#define MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_T_DEFINED

typedef struct _mc_conversion_polyconversiondetails_list_t mc_conversion_polyconversiondetails_list_t;

#endif // MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Conversion:PolyConversionDetails
#define MC_CONVERSION_POLYCONVERSIONDETAILS_LIST_SHORT_FORM 0x4000701fffffdL

// generated code for composite MC:Conversion:RangeConversionDetails
#ifndef MC_CONVERSION_RANGECONVERSIONDETAILS_T_DEFINED
#define MC_CONVERSION_RANGECONVERSIONDETAILS_T_DEFINED

typedef struct _mc_conversion_rangeconversiondetails_t mc_conversion_rangeconversiondetails_t;

#endif // MC_CONVERSION_RANGECONVERSIONDETAILS_T_DEFINED

// short form for composite type MC:Conversion:RangeConversionDetails
#define MC_CONVERSION_RANGECONVERSIONDETAILS_SHORT_FORM 0x4000701000004L
#ifndef MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_T_DEFINED
#define MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_T_DEFINED

typedef struct _mc_conversion_rangeconversiondetails_list_t mc_conversion_rangeconversiondetails_list_t;

#endif // MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Conversion:RangeConversionDetails
#define MC_CONVERSION_RANGECONVERSIONDETAILS_LIST_SHORT_FORM 0x4000701fffffcL

// standard service identifiers
#define MC_GROUP_SERVICE_NUMBER 8

// generated code for composite MC:Group:GroupDetails
#ifndef MC_GROUP_GROUPDETAILS_T_DEFINED
#define MC_GROUP_GROUPDETAILS_T_DEFINED

typedef struct _mc_group_groupdetails_t mc_group_groupdetails_t;

#endif // MC_GROUP_GROUPDETAILS_T_DEFINED

// short form for composite type MC:Group:GroupDetails
#define MC_GROUP_GROUPDETAILS_SHORT_FORM 0x4000801000001L
#ifndef MC_GROUP_GROUPDETAILS_LIST_T_DEFINED
#define MC_GROUP_GROUPDETAILS_LIST_T_DEFINED

typedef struct _mc_group_groupdetails_list_t mc_group_groupdetails_list_t;

#endif // MC_GROUP_GROUPDETAILS_LIST_T_DEFINED

// short form for list of composite type MC:Group:GroupDetails
#define MC_GROUP_GROUPDETAILS_LIST_SHORT_FORM 0x4000801ffffffL

// include required areas definitions
#include "com.h"
#include "common.h"
#include "pf.h"
#include "softwaremanagement.h"

// generated code for composite MC:_:ArgumentDefinitionDetails

// generated code for composite MC:_:AttributeValue

// generated code for composite MC:_:ConditionalConversion

// generated code for composite MC:_:ParameterExpression

// generated code for composite MC:_:ObjectInstancePair

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

// generated code for operation mc_action_precheckaction
#define MC_ACTION_PRECHECKACTION_OPERATION_NUMBER 2
int mc_action_precheckaction_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_precheckaction_request_add_encoding_length_0(mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element, void * cursor);
int mc_action_precheckaction_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_action_actioninstancedetails_t * element);
int mc_action_precheckaction_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_action_actioninstancedetails_t ** element_res);
int mc_action_precheckaction_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_precheckaction_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_precheckaction_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_precheckaction_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_action_precheckaction_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_action_precheckaction_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_action_precheckaction_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_precheckaction_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_precheckaction_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_precheckaction_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_precheckaction_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_action_listdefinition
#define MC_ACTION_LISTDEFINITION_OPERATION_NUMBER 3
int mc_action_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_action_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_action_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_action_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_action_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_action_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_action_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_listdefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_listdefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_listdefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_action_addaction
#define MC_ACTION_ADDACTION_OPERATION_NUMBER 4
int mc_action_addaction_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_addaction_request_add_encoding_length_0(mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element, void * cursor);
int mc_action_addaction_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_action_actioncreationrequest_list_t * element);
int mc_action_addaction_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_action_actioncreationrequest_list_t ** element_res);
int mc_action_addaction_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_addaction_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_addaction_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_addaction_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_action_addaction_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_action_addaction_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_action_addaction_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_addaction_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_addaction_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_addaction_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_addaction_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_action_updatedefinition
#define MC_ACTION_UPDATEDEFINITION_OPERATION_NUMBER 5
int mc_action_updatedefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_updatedefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_action_updatedefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_action_updatedefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_action_updatedefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_updatedefinition_request_add_encoding_length_1(mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element, void * cursor);
int mc_action_updatedefinition_request_encode_1(void * cursor, mal_encoder_t * encoder, mc_action_actiondefinitiondetails_list_t * element);
int mc_action_updatedefinition_request_decode_1(void * cursor, mal_decoder_t * decoder, mc_action_actiondefinitiondetails_list_t ** element_res);
int mc_action_updatedefinition_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_updatedefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_action_updatedefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_updatedefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_action_updatedefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_action_updatedefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_action_updatedefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_updatedefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_action_removeaction
#define MC_ACTION_REMOVEACTION_OPERATION_NUMBER 6
int mc_action_removeaction_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_action_removeaction_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_action_removeaction_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_action_removeaction_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_action_removeaction_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_action_removeaction_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_action_removeaction_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_action_removeaction_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_action_removeaction_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_action_removeaction_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_action_removeaction_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Parameter:ParameterDefinitionDetails

// generated code for composite MC:Parameter:ParameterValue

// generated code for composite MC:Parameter:ParameterConversion

// generated code for composite MC:Parameter:ParameterCreationRequest

// generated code for composite MC:Parameter:ParameterRawValue

// generated code for composite MC:Parameter:ParameterValueDetails

// generated code for operation mc_parameter_monitorvalue
#define MC_PARAMETER_MONITORVALUE_OPERATION_NUMBER 1
int mc_parameter_monitorvalue_update_add_encoding_length_0(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int mc_parameter_monitorvalue_update_encode_0(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int mc_parameter_monitorvalue_update_decode_0(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int mc_parameter_monitorvalue_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_monitorvalue_update_add_encoding_length_1(mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element, void * cursor);
int mc_parameter_monitorvalue_update_encode_1(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervalue_list_t * element);
int mc_parameter_monitorvalue_update_decode_1(void * cursor, mal_decoder_t * decoder, mc_parameter_parametervalue_list_t ** element_res);
int mc_parameter_monitorvalue_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_monitorvalue_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_parameter_monitorvalue_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_parameter_monitorvalue_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_parameter_monitorvalue_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int mc_parameter_monitorvalue_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_parameter_monitorvalue_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_parameter_monitorvalue_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation mc_parameter_getvalue
#define MC_PARAMETER_GETVALUE_OPERATION_NUMBER 2
int mc_parameter_getvalue_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_getvalue_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_parameter_getvalue_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_parameter_getvalue_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_parameter_getvalue_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_getvalue_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_getvalue_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_getvalue_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element, void * cursor);
int mc_parameter_getvalue_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_parameter_parametervaluedetails_list_t * element);
int mc_parameter_getvalue_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_parameter_parametervaluedetails_list_t ** element_res);
int mc_parameter_getvalue_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_getvalue_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_getvalue_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_getvalue_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_getvalue_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_setvalue
#define MC_PARAMETER_SETVALUE_OPERATION_NUMBER 3
int mc_parameter_setvalue_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_setvalue_submit_add_encoding_length_0(mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element, void * cursor);
int mc_parameter_setvalue_submit_encode_0(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterrawvalue_list_t * element);
int mc_parameter_setvalue_submit_decode_0(void * cursor, mal_decoder_t * decoder, mc_parameter_parameterrawvalue_list_t ** element_res);
int mc_parameter_setvalue_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_setvalue_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_setvalue_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_setvalue_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_parameter_setvalue_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_setvalue_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_setvalue_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_enablegeneration
#define MC_PARAMETER_ENABLEGENERATION_OPERATION_NUMBER 4
int mc_parameter_enablegeneration_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_enablegeneration_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_parameter_enablegeneration_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_parameter_enablegeneration_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_parameter_enablegeneration_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_enablegeneration_request_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_parameter_enablegeneration_request_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_parameter_enablegeneration_request_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_parameter_enablegeneration_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_enablegeneration_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_parameter_enablegeneration_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_enablegeneration_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_parameter_enablegeneration_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_parameter_enablegeneration_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_parameter_enablegeneration_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_enablegeneration_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_enablegeneration_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_enablegeneration_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_enablegeneration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_listdefinition
#define MC_PARAMETER_LISTDEFINITION_OPERATION_NUMBER 5
int mc_parameter_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_parameter_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_parameter_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_parameter_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_parameter_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_parameter_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_parameter_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_listdefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_listdefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_listdefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_addparameter
#define MC_PARAMETER_ADDPARAMETER_OPERATION_NUMBER 6
int mc_parameter_addparameter_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_addparameter_request_add_encoding_length_0(mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element, void * cursor);
int mc_parameter_addparameter_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_parameter_parametercreationrequest_list_t * element);
int mc_parameter_addparameter_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_parameter_parametercreationrequest_list_t ** element_res);
int mc_parameter_addparameter_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_addparameter_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_addparameter_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_addparameter_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_parameter_addparameter_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_parameter_addparameter_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_parameter_addparameter_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_addparameter_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_addparameter_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_addparameter_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_addparameter_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_updatedefinition
#define MC_PARAMETER_UPDATEDEFINITION_OPERATION_NUMBER 7
int mc_parameter_updatedefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_updatedefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_parameter_updatedefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_parameter_updatedefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_parameter_updatedefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_updatedefinition_request_add_encoding_length_1(mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element, void * cursor);
int mc_parameter_updatedefinition_request_encode_1(void * cursor, mal_encoder_t * encoder, mc_parameter_parameterdefinitiondetails_list_t * element);
int mc_parameter_updatedefinition_request_decode_1(void * cursor, mal_decoder_t * decoder, mc_parameter_parameterdefinitiondetails_list_t ** element_res);
int mc_parameter_updatedefinition_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_updatedefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_parameter_updatedefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_updatedefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_parameter_updatedefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_parameter_updatedefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_parameter_updatedefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_updatedefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_parameter_removeparameter
#define MC_PARAMETER_REMOVEPARAMETER_OPERATION_NUMBER 8
int mc_parameter_removeparameter_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_parameter_removeparameter_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_parameter_removeparameter_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_parameter_removeparameter_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_parameter_removeparameter_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_parameter_removeparameter_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_parameter_removeparameter_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_parameter_removeparameter_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_parameter_removeparameter_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_parameter_removeparameter_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_parameter_removeparameter_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Alert:AlertDefinitionDetails

// generated code for composite MC:Alert:AlertEventDetails

// generated code for composite MC:Alert:AlertCreationRequest

// generated code for operation mc_alert_enablegeneration
#define MC_ALERT_ENABLEGENERATION_OPERATION_NUMBER 1
int mc_alert_enablegeneration_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_enablegeneration_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_alert_enablegeneration_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_alert_enablegeneration_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_alert_enablegeneration_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_enablegeneration_request_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_alert_enablegeneration_request_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_alert_enablegeneration_request_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_alert_enablegeneration_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_enablegeneration_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_alert_enablegeneration_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_enablegeneration_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_alert_enablegeneration_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_alert_enablegeneration_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_alert_enablegeneration_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_enablegeneration_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_enablegeneration_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_enablegeneration_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_enablegeneration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_alert_listdefinition
#define MC_ALERT_LISTDEFINITION_OPERATION_NUMBER 2
int mc_alert_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_alert_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_alert_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_alert_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_alert_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_alert_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_alert_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_listdefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_listdefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_listdefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_alert_addalert
#define MC_ALERT_ADDALERT_OPERATION_NUMBER 3
int mc_alert_addalert_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_addalert_request_add_encoding_length_0(mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element, void * cursor);
int mc_alert_addalert_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_alert_alertcreationrequest_list_t * element);
int mc_alert_addalert_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_alert_alertcreationrequest_list_t ** element_res);
int mc_alert_addalert_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_addalert_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_addalert_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_addalert_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_alert_addalert_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_alert_addalert_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_alert_addalert_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_addalert_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_addalert_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_addalert_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_addalert_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_alert_updatedefinition
#define MC_ALERT_UPDATEDEFINITION_OPERATION_NUMBER 4
int mc_alert_updatedefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_updatedefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_alert_updatedefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_alert_updatedefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_alert_updatedefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_updatedefinition_request_add_encoding_length_1(mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element, void * cursor);
int mc_alert_updatedefinition_request_encode_1(void * cursor, mal_encoder_t * encoder, mc_alert_alertdefinitiondetails_list_t * element);
int mc_alert_updatedefinition_request_decode_1(void * cursor, mal_decoder_t * decoder, mc_alert_alertdefinitiondetails_list_t ** element_res);
int mc_alert_updatedefinition_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_updatedefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_alert_updatedefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_updatedefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_alert_updatedefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_alert_updatedefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_alert_updatedefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_updatedefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_alert_removealert
#define MC_ALERT_REMOVEALERT_OPERATION_NUMBER 5
int mc_alert_removealert_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_alert_removealert_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_alert_removealert_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_alert_removealert_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_alert_removealert_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_alert_removealert_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_alert_removealert_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_alert_removealert_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_alert_removealert_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_alert_removealert_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_alert_removealert_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Check:CheckLinkDetails

// generated code for composite MC:Check:CheckResult

// generated code for composite MC:Check:CheckLinkSummary

// generated code for composite MC:Check:CheckResultSummary

// generated code for composite MC:Check:CheckResultFilter

// generated code for composite MC:Check:ReferenceValue

// generated code for composite MC:Check:ConstantCheckDefinition

// generated code for composite MC:Check:ReferenceCheckDefinition

// generated code for composite MC:Check:DeltaCheckDefinition

// generated code for composite MC:Check:LimitCheckDefinition

// generated code for composite MC:Check:CompoundCheckDefinition

// generated code for composite MC:Check:CheckTypedInstance

// generated code for operation mc_check_getcurrenttransitionlist
#define MC_CHECK_GETCURRENTTRANSITIONLIST_OPERATION_NUMBER 1
int mc_check_getcurrenttransitionlist_progress(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_getcurrenttransitionlist_progress_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checkresultfilter_t * element, void * cursor);
int mc_check_getcurrenttransitionlist_progress_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checkresultfilter_t * element);
int mc_check_getcurrenttransitionlist_progress_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checkresultfilter_t ** element_res);
int mc_check_getcurrenttransitionlist_progress_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getcurrenttransitionlist_progress_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_getcurrenttransitionlist_progress_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getcurrenttransitionlist_progress_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_getcurrenttransitionlist_progress_update(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getcurrenttransitionlist_progress_update_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int mc_check_getcurrenttransitionlist_progress_update_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int mc_check_getcurrenttransitionlist_progress_update_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checkresultsummary_list_t ** element_res);
int mc_check_getcurrenttransitionlist_progress_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getcurrenttransitionlist_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_getcurrenttransitionlist_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getcurrenttransitionlist_progress_response_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int mc_check_getcurrenttransitionlist_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int mc_check_getcurrenttransitionlist_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checkresultsummary_list_t ** element_res);
int mc_check_getcurrenttransitionlist_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getcurrenttransitionlist_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_getcurrenttransitionlist_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_getcurrenttransitionlist_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_getcurrenttransitionlist_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

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
int mc_check_getsummaryreport_progress_update_add_encoding_length_1(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int mc_check_getsummaryreport_progress_update_encode_1(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int mc_check_getsummaryreport_progress_update_decode_1(void * cursor, mal_decoder_t * decoder, mc_check_checkresultsummary_list_t ** element_res);
int mc_check_getsummaryreport_progress_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_update_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_getsummaryreport_progress_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getsummaryreport_progress_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_long_t element, void * cursor);
int mc_check_getsummaryreport_progress_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_long_t element);
int mc_check_getsummaryreport_progress_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_long_t * element_res);
int mc_check_getsummaryreport_progress_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_response_add_encoding_length_1(mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element, void * cursor);
int mc_check_getsummaryreport_progress_response_encode_1(void * cursor, mal_encoder_t * encoder, mc_check_checkresultsummary_list_t * element);
int mc_check_getsummaryreport_progress_response_decode_1(void * cursor, mal_decoder_t * decoder, mc_check_checkresultsummary_list_t ** element_res);
int mc_check_getsummaryreport_progress_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getsummaryreport_progress_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_getsummaryreport_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_getsummaryreport_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_getsummaryreport_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_enableservice
#define MC_CHECK_ENABLESERVICE_OPERATION_NUMBER 3
int mc_check_enableservice_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_enableservice_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_check_enableservice_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_check_enableservice_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_check_enableservice_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_enableservice_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_enableservice_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_enableservice_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation mc_check_getservicestatus
#define MC_CHECK_GETSERVICESTATUS_OPERATION_NUMBER 4
int mc_check_getservicestatus_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_getservicestatus_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_getservicestatus_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_getservicestatus_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_check_getservicestatus_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_check_getservicestatus_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_check_getservicestatus_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_getservicestatus_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation mc_check_enablecheck
#define MC_CHECK_ENABLECHECK_OPERATION_NUMBER 5
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

// generated code for operation mc_check_triggercheck
#define MC_CHECK_TRIGGERCHECK_OPERATION_NUMBER 6
int mc_check_triggercheck_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_triggercheck_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_triggercheck_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_triggercheck_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_triggercheck_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_triggercheck_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_triggercheck_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_triggercheck_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_triggercheck_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_triggercheck_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_triggercheck_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_triggercheck_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_triggercheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_triggercheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_triggercheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_listdefinition
#define MC_CHECK_LISTDEFINITION_OPERATION_NUMBER 7
int mc_check_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_check_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_check_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_check_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element, void * cursor);
int mc_check_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checktypedinstance_list_t * element);
int mc_check_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checktypedinstance_list_t ** element_res);
int mc_check_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_listdefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_listdefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_listdefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_listchecklinks
#define MC_CHECK_LISTCHECKLINKS_OPERATION_NUMBER 8
int mc_check_listchecklinks_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_listchecklinks_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_listchecklinks_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_listchecklinks_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_listchecklinks_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listchecklinks_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_listchecklinks_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_listchecklinks_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element, void * cursor);
int mc_check_listchecklinks_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checklinksummary_list_t * element);
int mc_check_listchecklinks_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checklinksummary_list_t ** element_res);
int mc_check_listchecklinks_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_listchecklinks_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_listchecklinks_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_listchecklinks_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_listchecklinks_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_addcheck
#define MC_CHECK_ADDCHECK_OPERATION_NUMBER 9
int mc_check_addcheck_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_addcheck_request_add_encoding_length_0(mal_encoder_t * encoder, mal_string_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_list_t * element);
int mc_check_addcheck_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_list_t ** element_res);
int mc_check_addcheck_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addcheck_request_add_encoding_length_1_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_1_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int mc_check_addcheck_request_add_encoding_length_1_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_1_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int mc_check_addcheck_request_add_encoding_length_1_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_1_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int mc_check_addcheck_request_add_encoding_length_1_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_1_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int mc_check_addcheck_request_add_encoding_length_1_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int mc_check_addcheck_request_encode_1_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int mc_check_addcheck_request_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int mc_check_addcheck_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int mc_check_addcheck_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addcheck_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_addcheck_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_addcheck_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_check_addcheck_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_check_addcheck_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_check_addcheck_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addcheck_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_addcheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_addcheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_addcheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_updatedefinition
#define MC_CHECK_UPDATEDEFINITION_OPERATION_NUMBER 10
int mc_check_updatedefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_updatedefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_updatedefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_updatedefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_updatedefinition_request_add_encoding_length_1_mc_check_compoundcheckdefinition_list(mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1_mc_check_compoundcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_compoundcheckdefinition_list_t * element);
int mc_check_updatedefinition_request_add_encoding_length_1_mc_check_constantcheckdefinition_list(mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1_mc_check_constantcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_constantcheckdefinition_list_t * element);
int mc_check_updatedefinition_request_add_encoding_length_1_mc_check_deltacheckdefinition_list(mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1_mc_check_deltacheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_deltacheckdefinition_list_t * element);
int mc_check_updatedefinition_request_add_encoding_length_1_mc_check_limitcheckdefinition_list(mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1_mc_check_limitcheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_limitcheckdefinition_list_t * element);
int mc_check_updatedefinition_request_add_encoding_length_1_mc_check_referencecheckdefinition_list(mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1_mc_check_referencecheckdefinition_list(void * cursor, mal_encoder_t * encoder, mc_check_referencecheckdefinition_list_t * element);
int mc_check_updatedefinition_request_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int mc_check_updatedefinition_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int mc_check_updatedefinition_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_updatedefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_updatedefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_updatedefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_updatedefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_updatedefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_updatedefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_updatedefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_removecheck
#define MC_CHECK_REMOVECHECK_OPERATION_NUMBER 11
int mc_check_removecheck_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_removecheck_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_removecheck_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_removecheck_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_removecheck_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_removecheck_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_removecheck_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_removecheck_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_removecheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_removecheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_removecheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_addparametercheck
#define MC_CHECK_ADDPARAMETERCHECK_OPERATION_NUMBER 12
int mc_check_addparametercheck_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_addparametercheck_request_add_encoding_length_0(mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element, void * cursor);
int mc_check_addparametercheck_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_check_checklinkdetails_list_t * element);
int mc_check_addparametercheck_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_check_checklinkdetails_list_t ** element_res);
int mc_check_addparametercheck_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_add_encoding_length_1(mal_encoder_t * encoder, com_objectdetails_list_t * element, void * cursor);
int mc_check_addparametercheck_request_encode_1(void * cursor, mal_encoder_t * encoder, com_objectdetails_list_t * element);
int mc_check_addparametercheck_request_decode_1(void * cursor, mal_decoder_t * decoder, com_objectdetails_list_t ** element_res);
int mc_check_addparametercheck_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_check_addparametercheck_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_addparametercheck_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_check_addparametercheck_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_check_addparametercheck_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_check_addparametercheck_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_addparametercheck_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_addparametercheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_addparametercheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_addparametercheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_check_removeparametercheck
#define MC_CHECK_REMOVEPARAMETERCHECK_OPERATION_NUMBER 13
int mc_check_removeparametercheck_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_check_removeparametercheck_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_check_removeparametercheck_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_check_removeparametercheck_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_check_removeparametercheck_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_check_removeparametercheck_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_check_removeparametercheck_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_check_removeparametercheck_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_check_removeparametercheck_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_check_removeparametercheck_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_check_removeparametercheck_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Statistic:StatisticFunctionDetails

// generated code for composite MC:Statistic:StatisticLinkDetails

// generated code for composite MC:Statistic:StatisticValue

// generated code for composite MC:Statistic:StatisticCreationRequest

// generated code for composite MC:Statistic:StatisticLinkSummary

// generated code for composite MC:Statistic:StatisticEvaluationReport

// generated code for operation mc_statistic_getstatistics
#define MC_STATISTIC_GETSTATISTICS_OPERATION_NUMBER 1
int mc_statistic_getstatistics_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_getstatistics_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_getstatistics_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_getstatistics_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_getstatistics_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_getstatistics_request_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_getstatistics_request_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_getstatistics_request_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_getstatistics_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_getstatistics_request_add_encoding_length_2(mal_encoder_t * encoder, com_objectkey_list_t * element, void * cursor);
int mc_statistic_getstatistics_request_encode_2(void * cursor, mal_encoder_t * encoder, com_objectkey_list_t * element);
int mc_statistic_getstatistics_request_decode_2(void * cursor, mal_decoder_t * decoder, com_objectkey_list_t ** element_res);
int mc_statistic_getstatistics_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_getstatistics_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int mc_statistic_getstatistics_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_getstatistics_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int mc_statistic_getstatistics_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int mc_statistic_getstatistics_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticevaluationreport_list_t ** element_res);
int mc_statistic_getstatistics_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_getstatistics_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_getstatistics_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_getstatistics_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_getstatistics_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_resetevaluation
#define MC_STATISTIC_RESETEVALUATION_OPERATION_NUMBER 2
int mc_statistic_resetevaluation_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_resetevaluation_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_resetevaluation_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_resetevaluation_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_resetevaluation_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_resetevaluation_request_add_encoding_length_1(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_resetevaluation_request_encode_1(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_resetevaluation_request_decode_1(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_resetevaluation_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_resetevaluation_request_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_resetevaluation_request_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_resetevaluation_request_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_resetevaluation_request_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_resetevaluation_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int mc_statistic_resetevaluation_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_resetevaluation_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element, void * cursor);
int mc_statistic_resetevaluation_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticevaluationreport_list_t * element);
int mc_statistic_resetevaluation_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticevaluationreport_list_t ** element_res);
int mc_statistic_resetevaluation_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_resetevaluation_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_resetevaluation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_resetevaluation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_resetevaluation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_monitorstatistics
#define MC_STATISTIC_MONITORSTATISTICS_OPERATION_NUMBER 3
int mc_statistic_monitorstatistics_update_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_monitorstatistics_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_monitorstatistics_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_monitorstatistics_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_monitorstatistics_update_add_encoding_length_1(mal_encoder_t * encoder, com_objectid_list_t * element, void * cursor);
int mc_statistic_monitorstatistics_update_encode_1(void * cursor, mal_encoder_t * encoder, com_objectid_list_t * element);
int mc_statistic_monitorstatistics_update_decode_1(void * cursor, mal_decoder_t * decoder, com_objectid_list_t ** element_res);
int mc_statistic_monitorstatistics_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_monitorstatistics_update_add_encoding_length_2(mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element, void * cursor);
int mc_statistic_monitorstatistics_update_encode_2(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticvalue_list_t * element);
int mc_statistic_monitorstatistics_update_decode_2(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticvalue_list_t ** element_res);
int mc_statistic_monitorstatistics_update_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_monitorstatistics_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_statistic_monitorstatistics_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_statistic_monitorstatistics_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_statistic_monitorstatistics_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int mc_statistic_monitorstatistics_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int mc_statistic_monitorstatistics_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int mc_statistic_monitorstatistics_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation mc_statistic_enableservice
#define MC_STATISTIC_ENABLESERVICE_OPERATION_NUMBER 4
int mc_statistic_enableservice_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_enableservice_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_enableservice_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_enableservice_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_enableservice_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_enableservice_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_enableservice_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_enableservice_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);

// generated code for operation mc_statistic_getservicestatus
#define MC_STATISTIC_GETSERVICESTATUS_OPERATION_NUMBER 5
int mc_statistic_getservicestatus_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_getservicestatus_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_statistic_getservicestatus_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_getservicestatus_request_response_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_getservicestatus_request_response_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_getservicestatus_request_response_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_getservicestatus_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_getservicestatus_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation mc_statistic_enablereporting
#define MC_STATISTIC_ENABLEREPORTING_OPERATION_NUMBER 6
int mc_statistic_enablereporting_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_enablereporting_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_statistic_enablereporting_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_statistic_enablereporting_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_statistic_enablereporting_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_enablereporting_submit_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_statistic_enablereporting_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_statistic_enablereporting_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_statistic_enablereporting_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_enablereporting_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_statistic_enablereporting_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_enablereporting_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_statistic_enablereporting_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_enablereporting_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_enablereporting_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_listparameterevaluations
#define MC_STATISTIC_LISTPARAMETEREVALUATIONS_OPERATION_NUMBER 7
int mc_statistic_listparameterevaluations_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_listparameterevaluations_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_listparameterevaluations_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_listparameterevaluations_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_listparameterevaluations_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_listparameterevaluations_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_listparameterevaluations_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_listparameterevaluations_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element, void * cursor);
int mc_statistic_listparameterevaluations_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinksummary_list_t * element);
int mc_statistic_listparameterevaluations_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticlinksummary_list_t ** element_res);
int mc_statistic_listparameterevaluations_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_listparameterevaluations_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_listparameterevaluations_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_listparameterevaluations_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_listparameterevaluations_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_addparameterevaluation
#define MC_STATISTIC_ADDPARAMETEREVALUATION_OPERATION_NUMBER 8
int mc_statistic_addparameterevaluation_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_addparameterevaluation_request_add_encoding_length_0(mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element, void * cursor);
int mc_statistic_addparameterevaluation_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticcreationrequest_list_t * element);
int mc_statistic_addparameterevaluation_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticcreationrequest_list_t ** element_res);
int mc_statistic_addparameterevaluation_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_addparameterevaluation_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_addparameterevaluation_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_addparameterevaluation_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_statistic_addparameterevaluation_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_statistic_addparameterevaluation_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_statistic_addparameterevaluation_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_addparameterevaluation_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_addparameterevaluation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_addparameterevaluation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_addparameterevaluation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_updateparameterevaluation
#define MC_STATISTIC_UPDATEPARAMETEREVALUATION_OPERATION_NUMBER 9
int mc_statistic_updateparameterevaluation_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_updateparameterevaluation_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_updateparameterevaluation_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_updateparameterevaluation_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_updateparameterevaluation_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_updateparameterevaluation_request_add_encoding_length_1(mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element, void * cursor);
int mc_statistic_updateparameterevaluation_request_encode_1(void * cursor, mal_encoder_t * encoder, mc_statistic_statisticlinkdetails_list_t * element);
int mc_statistic_updateparameterevaluation_request_decode_1(void * cursor, mal_decoder_t * decoder, mc_statistic_statisticlinkdetails_list_t ** element_res);
int mc_statistic_updateparameterevaluation_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_updateparameterevaluation_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_statistic_updateparameterevaluation_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_updateparameterevaluation_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_updateparameterevaluation_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_updateparameterevaluation_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_updateparameterevaluation_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_updateparameterevaluation_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_updateparameterevaluation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_updateparameterevaluation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_updateparameterevaluation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_statistic_removeparameterevaluation
#define MC_STATISTIC_REMOVEPARAMETEREVALUATION_OPERATION_NUMBER 10
int mc_statistic_removeparameterevaluation_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_statistic_removeparameterevaluation_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_statistic_removeparameterevaluation_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_statistic_removeparameterevaluation_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_statistic_removeparameterevaluation_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_statistic_removeparameterevaluation_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_statistic_removeparameterevaluation_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_statistic_removeparameterevaluation_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_statistic_removeparameterevaluation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_statistic_removeparameterevaluation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_statistic_removeparameterevaluation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Aggregation:AggregationDefinitionDetails

// generated code for composite MC:Aggregation:AggregationParameterSet

// generated code for composite MC:Aggregation:AggregationValue

// generated code for composite MC:Aggregation:AggregationSetValue

// generated code for composite MC:Aggregation:AggregationParameterValue

// generated code for composite MC:Aggregation:ThresholdFilter

// generated code for composite MC:Aggregation:AggregationCreationRequest

// generated code for composite MC:Aggregation:AggregationValueDetails

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
int mc_aggregation_getvalue_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element, void * cursor);
int mc_aggregation_getvalue_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationvaluedetails_list_t * element);
int mc_aggregation_getvalue_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationvaluedetails_list_t ** element_res);
int mc_aggregation_getvalue_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_getvalue_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_getvalue_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_getvalue_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_getvalue_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_enablegeneration
#define MC_AGGREGATION_ENABLEGENERATION_OPERATION_NUMBER 3
int mc_aggregation_enablegeneration_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_enablegeneration_request_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_aggregation_enablegeneration_request_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_aggregation_enablegeneration_request_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_aggregation_enablegeneration_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablegeneration_request_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_aggregation_enablegeneration_request_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_aggregation_enablegeneration_request_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_aggregation_enablegeneration_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablegeneration_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_enablegeneration_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_enablegeneration_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_enablegeneration_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_enablegeneration_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_enablegeneration_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablegeneration_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_enablegeneration_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_enablegeneration_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_enablegeneration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_enablefilter
#define MC_AGGREGATION_ENABLEFILTER_OPERATION_NUMBER 4
int mc_aggregation_enablefilter_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_enablefilter_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int mc_aggregation_enablefilter_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int mc_aggregation_enablefilter_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int mc_aggregation_enablefilter_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablefilter_submit_add_encoding_length_1(mal_encoder_t * encoder, com_instancebooleanpair_list_t * element, void * cursor);
int mc_aggregation_enablefilter_submit_encode_1(void * cursor, mal_encoder_t * encoder, com_instancebooleanpair_list_t * element);
int mc_aggregation_enablefilter_submit_decode_1(void * cursor, mal_decoder_t * decoder, com_instancebooleanpair_list_t ** element_res);
int mc_aggregation_enablefilter_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_enablefilter_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_enablefilter_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_enablefilter_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_aggregation_enablefilter_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_enablefilter_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_enablefilter_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_listdefinition
#define MC_AGGREGATION_LISTDEFINITION_OPERATION_NUMBER 5
int mc_aggregation_listdefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_listdefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int mc_aggregation_listdefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int mc_aggregation_listdefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int mc_aggregation_listdefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_listdefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_listdefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_listdefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_aggregation_listdefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_aggregation_listdefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_aggregation_listdefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_listdefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_listdefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_listdefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_listdefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_addaggregation
#define MC_AGGREGATION_ADDAGGREGATION_OPERATION_NUMBER 6
int mc_aggregation_addaggregation_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_addaggregation_request_add_encoding_length_0(mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element, void * cursor);
int mc_aggregation_addaggregation_request_encode_0(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationcreationrequest_list_t * element);
int mc_aggregation_addaggregation_request_decode_0(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationcreationrequest_list_t ** element_res);
int mc_aggregation_addaggregation_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_addaggregation_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_addaggregation_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_addaggregation_request_response_add_encoding_length_0(mal_encoder_t * encoder, mc_objectinstancepair_list_t * element, void * cursor);
int mc_aggregation_addaggregation_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mc_objectinstancepair_list_t * element);
int mc_aggregation_addaggregation_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mc_objectinstancepair_list_t ** element_res);
int mc_aggregation_addaggregation_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_addaggregation_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_addaggregation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_addaggregation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_addaggregation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_updatedefinition
#define MC_AGGREGATION_UPDATEDEFINITION_OPERATION_NUMBER 7
int mc_aggregation_updatedefinition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_updatedefinition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_updatedefinition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_updatedefinition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_updatedefinition_request_add_encoding_length_1(mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_request_encode_1(void * cursor, mal_encoder_t * encoder, mc_aggregation_aggregationdefinitiondetails_list_t * element);
int mc_aggregation_updatedefinition_request_decode_1(void * cursor, mal_decoder_t * decoder, mc_aggregation_aggregationdefinitiondetails_list_t ** element_res);
int mc_aggregation_updatedefinition_request_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_updatedefinition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int mc_aggregation_updatedefinition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_updatedefinition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_updatedefinition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_updatedefinition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_updatedefinition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_updatedefinition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_updatedefinition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_updatedefinition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation mc_aggregation_removeaggregation
#define MC_AGGREGATION_REMOVEAGGREGATION_OPERATION_NUMBER 8
int mc_aggregation_removeaggregation_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int mc_aggregation_removeaggregation_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int mc_aggregation_removeaggregation_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int mc_aggregation_removeaggregation_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int mc_aggregation_removeaggregation_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int mc_aggregation_removeaggregation_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int mc_aggregation_removeaggregation_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int mc_aggregation_removeaggregation_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int mc_aggregation_removeaggregation_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int mc_aggregation_removeaggregation_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int mc_aggregation_removeaggregation_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite MC:Conversion:DiscreteConversionDetails

// generated code for composite MC:Conversion:LineConversionDetails

// generated code for composite MC:Conversion:PolyConversionDetails

// generated code for composite MC:Conversion:RangeConversionDetails

// generated code for composite MC:Group:GroupDetails

// test function
void mc_test(bool verbose);

#include "mc_severity_list.h"
#include "mc_argumentdefinitiondetails.h"
#include "mc_argumentdefinitiondetails_list.h"
#include "mc_attributevalue.h"
#include "mc_attributevalue_list.h"
#include "mc_conditionalconversion.h"
#include "mc_conditionalconversion_list.h"
#include "mc_parameterexpression.h"
#include "mc_parameterexpression_list.h"
#include "mc_objectinstancepair.h"
#include "mc_objectinstancepair_list.h"
#include "mc_action_actioncategory_list.h"
#include "mc_action_actiondefinitiondetails.h"
#include "mc_action_actiondefinitiondetails_list.h"
#include "mc_action_actioninstancedetails.h"
#include "mc_action_actioninstancedetails_list.h"
#include "mc_action_actioncreationrequest.h"
#include "mc_action_actioncreationrequest_list.h"
#include "mc_parameter_validitystate_list.h"
#include "mc_parameter_parameterdefinitiondetails.h"
#include "mc_parameter_parameterdefinitiondetails_list.h"
#include "mc_parameter_parametervalue.h"
#include "mc_parameter_parametervalue_list.h"
#include "mc_parameter_parameterconversion.h"
#include "mc_parameter_parameterconversion_list.h"
#include "mc_parameter_parametercreationrequest.h"
#include "mc_parameter_parametercreationrequest_list.h"
#include "mc_parameter_parameterrawvalue.h"
#include "mc_parameter_parameterrawvalue_list.h"
#include "mc_parameter_parametervaluedetails.h"
#include "mc_parameter_parametervaluedetails_list.h"
#include "mc_alert_alertdefinitiondetails.h"
#include "mc_alert_alertdefinitiondetails_list.h"
#include "mc_alert_alerteventdetails.h"
#include "mc_alert_alerteventdetails_list.h"
#include "mc_alert_alertcreationrequest.h"
#include "mc_alert_alertcreationrequest_list.h"
#include "mc_check_checkstate_list.h"
#include "mc_check_checklinkdetails.h"
#include "mc_check_checklinkdetails_list.h"
#include "mc_check_checkresult.h"
#include "mc_check_checkresult_list.h"
#include "mc_check_checklinksummary.h"
#include "mc_check_checklinksummary_list.h"
#include "mc_check_checkresultsummary.h"
#include "mc_check_checkresultsummary_list.h"
#include "mc_check_checkresultfilter.h"
#include "mc_check_checkresultfilter_list.h"
#include "mc_check_referencevalue.h"
#include "mc_check_referencevalue_list.h"
#include "mc_check_constantcheckdefinition.h"
#include "mc_check_constantcheckdefinition_list.h"
#include "mc_check_referencecheckdefinition.h"
#include "mc_check_referencecheckdefinition_list.h"
#include "mc_check_deltacheckdefinition.h"
#include "mc_check_deltacheckdefinition_list.h"
#include "mc_check_limitcheckdefinition.h"
#include "mc_check_limitcheckdefinition_list.h"
#include "mc_check_compoundcheckdefinition.h"
#include "mc_check_compoundcheckdefinition_list.h"
#include "mc_check_checktypedinstance.h"
#include "mc_check_checktypedinstance_list.h"
#include "mc_statistic_statisticfunctiondetails.h"
#include "mc_statistic_statisticfunctiondetails_list.h"
#include "mc_statistic_statisticlinkdetails.h"
#include "mc_statistic_statisticlinkdetails_list.h"
#include "mc_statistic_statisticvalue.h"
#include "mc_statistic_statisticvalue_list.h"
#include "mc_statistic_statisticcreationrequest.h"
#include "mc_statistic_statisticcreationrequest_list.h"
#include "mc_statistic_statisticlinksummary.h"
#include "mc_statistic_statisticlinksummary_list.h"
#include "mc_statistic_statisticevaluationreport.h"
#include "mc_statistic_statisticevaluationreport_list.h"
#include "mc_aggregation_aggregationcategory_list.h"
#include "mc_aggregation_thresholdtype_list.h"
#include "mc_aggregation_generationmode_list.h"
#include "mc_aggregation_aggregationdefinitiondetails.h"
#include "mc_aggregation_aggregationdefinitiondetails_list.h"
#include "mc_aggregation_aggregationparameterset.h"
#include "mc_aggregation_aggregationparameterset_list.h"
#include "mc_aggregation_aggregationvalue.h"
#include "mc_aggregation_aggregationvalue_list.h"
#include "mc_aggregation_aggregationsetvalue.h"
#include "mc_aggregation_aggregationsetvalue_list.h"
#include "mc_aggregation_aggregationparametervalue.h"
#include "mc_aggregation_aggregationparametervalue_list.h"
#include "mc_aggregation_thresholdfilter.h"
#include "mc_aggregation_thresholdfilter_list.h"
#include "mc_aggregation_aggregationcreationrequest.h"
#include "mc_aggregation_aggregationcreationrequest_list.h"
#include "mc_aggregation_aggregationvaluedetails.h"
#include "mc_aggregation_aggregationvaluedetails_list.h"
#include "mc_conversion_discreteconversiondetails.h"
#include "mc_conversion_discreteconversiondetails_list.h"
#include "mc_conversion_lineconversiondetails.h"
#include "mc_conversion_lineconversiondetails_list.h"
#include "mc_conversion_polyconversiondetails.h"
#include "mc_conversion_polyconversiondetails_list.h"
#include "mc_conversion_rangeconversiondetails.h"
#include "mc_conversion_rangeconversiondetails_list.h"
#include "mc_group_groupdetails.h"
#include "mc_group_groupdetails_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __MC_H_INCLUDED__
