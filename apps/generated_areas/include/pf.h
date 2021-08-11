#ifndef __PF_H_INCLUDED__
#define __PF_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mal.h"
#include "malbinary.h"
#include "malsplitbinary.h"

int pf_malbinary_add_mal_element_encoding_length(mal_encoder_t * encoder, mal_element_holder_t * element_holder, void * cursor);
int pf_malbinary_encode_mal_element(mal_encoder_t * encoder, void * cursor, mal_element_holder_t * element_holder);
int pf_malbinary_decode_mal_element(mal_decoder_t * decoder, void * cursor, mal_element_holder_t * element_holder);

// standard area identifiers
#define PF_AREA_NUMBER 105
#define PF_AREA_VERSION 2

// generated code for composite PF:_:VectorF3D
#ifndef PF_VECTORF3D_T_DEFINED
#define PF_VECTORF3D_T_DEFINED

typedef struct _pf_vectorf3d_t pf_vectorf3d_t;

#endif // PF_VECTORF3D_T_DEFINED

// short form for composite type PF:_:VectorF3D
#define PF_VECTORF3D_SHORT_FORM 0x69000002000001L
#ifndef PF_VECTORF3D_LIST_T_DEFINED
#define PF_VECTORF3D_LIST_T_DEFINED

typedef struct _pf_vectorf3d_list_t pf_vectorf3d_list_t;

#endif // PF_VECTORF3D_LIST_T_DEFINED

// short form for list of composite type PF:_:VectorF3D
#define PF_VECTORF3D_LIST_SHORT_FORM 0x69000002ffffffL

// generated code for composite PF:_:VectorD3D
#ifndef PF_VECTORD3D_T_DEFINED
#define PF_VECTORD3D_T_DEFINED

typedef struct _pf_vectord3d_t pf_vectord3d_t;

#endif // PF_VECTORD3D_T_DEFINED

// short form for composite type PF:_:VectorD3D
#define PF_VECTORD3D_SHORT_FORM 0x69000002000002L
#ifndef PF_VECTORD3D_LIST_T_DEFINED
#define PF_VECTORD3D_LIST_T_DEFINED

typedef struct _pf_vectord3d_list_t pf_vectord3d_list_t;

#endif // PF_VECTORD3D_LIST_T_DEFINED

// short form for list of composite type PF:_:VectorD3D
#define PF_VECTORD3D_LIST_SHORT_FORM 0x69000002fffffeL

// standard service identifiers
#define PF_CAMERA_SERVICE_NUMBER 1

// generated code for composite PF:Camera:Picture
#ifndef PF_CAMERA_PICTURE_T_DEFINED
#define PF_CAMERA_PICTURE_T_DEFINED

typedef struct _pf_camera_picture_t pf_camera_picture_t;

#endif // PF_CAMERA_PICTURE_T_DEFINED

// short form for composite type PF:Camera:Picture
#define PF_CAMERA_PICTURE_SHORT_FORM 0x69000102000001L
#ifndef PF_CAMERA_PICTURE_LIST_T_DEFINED
#define PF_CAMERA_PICTURE_LIST_T_DEFINED

typedef struct _pf_camera_picture_list_t pf_camera_picture_list_t;

#endif // PF_CAMERA_PICTURE_LIST_T_DEFINED

// short form for list of composite type PF:Camera:Picture
#define PF_CAMERA_PICTURE_LIST_SHORT_FORM 0x69000102ffffffL

// generated code for composite PF:Camera:PixelResolution
#ifndef PF_CAMERA_PIXELRESOLUTION_T_DEFINED
#define PF_CAMERA_PIXELRESOLUTION_T_DEFINED

typedef struct _pf_camera_pixelresolution_t pf_camera_pixelresolution_t;

#endif // PF_CAMERA_PIXELRESOLUTION_T_DEFINED

// short form for composite type PF:Camera:PixelResolution
#define PF_CAMERA_PIXELRESOLUTION_SHORT_FORM 0x69000102000002L
#ifndef PF_CAMERA_PIXELRESOLUTION_LIST_T_DEFINED
#define PF_CAMERA_PIXELRESOLUTION_LIST_T_DEFINED

typedef struct _pf_camera_pixelresolution_list_t pf_camera_pixelresolution_list_t;

#endif // PF_CAMERA_PIXELRESOLUTION_LIST_T_DEFINED

// short form for list of composite type PF:Camera:PixelResolution
#define PF_CAMERA_PIXELRESOLUTION_LIST_SHORT_FORM 0x69000102fffffeL

// generated code for enumeration pf_camera_pictureformat
typedef enum {
  PF_CAMERA_PICTUREFORMAT_RAW,
  PF_CAMERA_PICTUREFORMAT_RGB24,
  PF_CAMERA_PICTUREFORMAT_BMP,
  PF_CAMERA_PICTUREFORMAT_PNG,
  PF_CAMERA_PICTUREFORMAT_JPG
} pf_camera_pictureformat_t;

// short form for enumeration type pf_camera_pictureformat
#define PF_CAMERA_PICTUREFORMAT_SHORT_FORM 0x69000102000003L
#ifndef PF_CAMERA_PICTUREFORMAT_LIST_T_DEFINED
#define PF_CAMERA_PICTUREFORMAT_LIST_T_DEFINED

typedef struct _pf_camera_pictureformat_list_t pf_camera_pictureformat_list_t;

#endif // PF_CAMERA_PICTUREFORMAT_LIST_T_DEFINED

// short form for list of enumeration type pf_camera_pictureformat
#define PF_CAMERA_PICTUREFORMAT_LIST_SHORT_FORM 0x69000102fffffdL

// generated code for composite PF:Camera:CameraSettings
#ifndef PF_CAMERA_CAMERASETTINGS_T_DEFINED
#define PF_CAMERA_CAMERASETTINGS_T_DEFINED

typedef struct _pf_camera_camerasettings_t pf_camera_camerasettings_t;

#endif // PF_CAMERA_CAMERASETTINGS_T_DEFINED

// short form for composite type PF:Camera:CameraSettings
#define PF_CAMERA_CAMERASETTINGS_SHORT_FORM 0x69000102000004L
#ifndef PF_CAMERA_CAMERASETTINGS_LIST_T_DEFINED
#define PF_CAMERA_CAMERASETTINGS_LIST_T_DEFINED

typedef struct _pf_camera_camerasettings_list_t pf_camera_camerasettings_list_t;

#endif // PF_CAMERA_CAMERASETTINGS_LIST_T_DEFINED

// short form for list of composite type PF:Camera:CameraSettings
#define PF_CAMERA_CAMERASETTINGS_LIST_SHORT_FORM 0x69000102fffffcL

// standard service identifiers
#define PF_GPS_SERVICE_NUMBER 2

// generated code for composite PF:GPS:Position
#ifndef PF_GPS_POSITION_T_DEFINED
#define PF_GPS_POSITION_T_DEFINED

typedef struct _pf_gps_position_t pf_gps_position_t;

#endif // PF_GPS_POSITION_T_DEFINED

// short form for composite type PF:GPS:Position
#define PF_GPS_POSITION_SHORT_FORM 0x69000202000001L
#ifndef PF_GPS_POSITION_LIST_T_DEFINED
#define PF_GPS_POSITION_LIST_T_DEFINED

typedef struct _pf_gps_position_list_t pf_gps_position_list_t;

#endif // PF_GPS_POSITION_LIST_T_DEFINED

// short form for list of composite type PF:GPS:Position
#define PF_GPS_POSITION_LIST_SHORT_FORM 0x69000202ffffffL

// generated code for composite PF:GPS:SatelliteInfo
#ifndef PF_GPS_SATELLITEINFO_T_DEFINED
#define PF_GPS_SATELLITEINFO_T_DEFINED

typedef struct _pf_gps_satelliteinfo_t pf_gps_satelliteinfo_t;

#endif // PF_GPS_SATELLITEINFO_T_DEFINED

// short form for composite type PF:GPS:SatelliteInfo
#define PF_GPS_SATELLITEINFO_SHORT_FORM 0x69000202000002L
#ifndef PF_GPS_SATELLITEINFO_LIST_T_DEFINED
#define PF_GPS_SATELLITEINFO_LIST_T_DEFINED

typedef struct _pf_gps_satelliteinfo_list_t pf_gps_satelliteinfo_list_t;

#endif // PF_GPS_SATELLITEINFO_LIST_T_DEFINED

// short form for list of composite type PF:GPS:SatelliteInfo
#define PF_GPS_SATELLITEINFO_LIST_SHORT_FORM 0x69000202fffffeL

// generated code for composite PF:GPS:PositionExtraDetails
#ifndef PF_GPS_POSITIONEXTRADETAILS_T_DEFINED
#define PF_GPS_POSITIONEXTRADETAILS_T_DEFINED

typedef struct _pf_gps_positionextradetails_t pf_gps_positionextradetails_t;

#endif // PF_GPS_POSITIONEXTRADETAILS_T_DEFINED

// short form for composite type PF:GPS:PositionExtraDetails
#define PF_GPS_POSITIONEXTRADETAILS_SHORT_FORM 0x69000202000004L
#ifndef PF_GPS_POSITIONEXTRADETAILS_LIST_T_DEFINED
#define PF_GPS_POSITIONEXTRADETAILS_LIST_T_DEFINED

typedef struct _pf_gps_positionextradetails_list_t pf_gps_positionextradetails_list_t;

#endif // PF_GPS_POSITIONEXTRADETAILS_LIST_T_DEFINED

// short form for list of composite type PF:GPS:PositionExtraDetails
#define PF_GPS_POSITIONEXTRADETAILS_LIST_SHORT_FORM 0x69000202fffffcL

// generated code for composite PF:GPS:NearbyPositionDefinition
#ifndef PF_GPS_NEARBYPOSITIONDEFINITION_T_DEFINED
#define PF_GPS_NEARBYPOSITIONDEFINITION_T_DEFINED

typedef struct _pf_gps_nearbypositiondefinition_t pf_gps_nearbypositiondefinition_t;

#endif // PF_GPS_NEARBYPOSITIONDEFINITION_T_DEFINED

// short form for composite type PF:GPS:NearbyPositionDefinition
#define PF_GPS_NEARBYPOSITIONDEFINITION_SHORT_FORM 0x6900020200001aL
#ifndef PF_GPS_NEARBYPOSITIONDEFINITION_LIST_T_DEFINED
#define PF_GPS_NEARBYPOSITIONDEFINITION_LIST_T_DEFINED

typedef struct _pf_gps_nearbypositiondefinition_list_t pf_gps_nearbypositiondefinition_list_t;

#endif // PF_GPS_NEARBYPOSITIONDEFINITION_LIST_T_DEFINED

// short form for list of composite type PF:GPS:NearbyPositionDefinition
#define PF_GPS_NEARBYPOSITIONDEFINITION_LIST_SHORT_FORM 0x69000202ffffe6L

// generated code for composite PF:GPS:TwoLineElementSet
#ifndef PF_GPS_TWOLINEELEMENTSET_T_DEFINED
#define PF_GPS_TWOLINEELEMENTSET_T_DEFINED

typedef struct _pf_gps_twolineelementset_t pf_gps_twolineelementset_t;

#endif // PF_GPS_TWOLINEELEMENTSET_T_DEFINED

// short form for composite type PF:GPS:TwoLineElementSet
#define PF_GPS_TWOLINEELEMENTSET_SHORT_FORM 0x69000202000005L
#ifndef PF_GPS_TWOLINEELEMENTSET_LIST_T_DEFINED
#define PF_GPS_TWOLINEELEMENTSET_LIST_T_DEFINED

typedef struct _pf_gps_twolineelementset_list_t pf_gps_twolineelementset_list_t;

#endif // PF_GPS_TWOLINEELEMENTSET_LIST_T_DEFINED

// short form for list of composite type PF:GPS:TwoLineElementSet
#define PF_GPS_TWOLINEELEMENTSET_LIST_SHORT_FORM 0x69000202fffffbL

// standard service identifiers
#define PF_AUTONOMOUSADCS_SERVICE_NUMBER 3

// generated code for composite PF:AutonomousADCS:Quaternion
#ifndef PF_AUTONOMOUSADCS_QUATERNION_T_DEFINED
#define PF_AUTONOMOUSADCS_QUATERNION_T_DEFINED

typedef struct _pf_autonomousadcs_quaternion_t pf_autonomousadcs_quaternion_t;

#endif // PF_AUTONOMOUSADCS_QUATERNION_T_DEFINED

// short form for composite type PF:AutonomousADCS:Quaternion
#define PF_AUTONOMOUSADCS_QUATERNION_SHORT_FORM 0x69000302000001L
#ifndef PF_AUTONOMOUSADCS_QUATERNION_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_QUATERNION_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_quaternion_list_t pf_autonomousadcs_quaternion_list_t;

#endif // PF_AUTONOMOUSADCS_QUATERNION_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:Quaternion
#define PF_AUTONOMOUSADCS_QUATERNION_LIST_SHORT_FORM 0x69000302ffffffL

// generated code for composite PF:AutonomousADCS:AttitudeModeBDot
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodebdot_t pf_autonomousadcs_attitudemodebdot_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeBDot
#define PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_SHORT_FORM 0x69000302000003L
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodebdot_list_t pf_autonomousadcs_attitudemodebdot_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeBDot
#define PF_AUTONOMOUSADCS_ATTITUDEMODEBDOT_LIST_SHORT_FORM 0x69000302fffffdL

// generated code for composite PF:AutonomousADCS:AttitudeModeSingleSpinning
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodesinglespinning_t pf_autonomousadcs_attitudemodesinglespinning_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeSingleSpinning
#define PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_SHORT_FORM 0x69000302000004L
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodesinglespinning_list_t pf_autonomousadcs_attitudemodesinglespinning_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeSingleSpinning
#define PF_AUTONOMOUSADCS_ATTITUDEMODESINGLESPINNING_LIST_SHORT_FORM 0x69000302fffffcL

// generated code for composite PF:AutonomousADCS:AttitudeModeSunPointing
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodesunpointing_t pf_autonomousadcs_attitudemodesunpointing_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeSunPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_SHORT_FORM 0x69000302000005L
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodesunpointing_list_t pf_autonomousadcs_attitudemodesunpointing_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeSunPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODESUNPOINTING_LIST_SHORT_FORM 0x69000302fffffbL

// generated code for composite PF:AutonomousADCS:AttitudeModeTargetTracking
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodetargettracking_t pf_autonomousadcs_attitudemodetargettracking_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeTargetTracking
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_SHORT_FORM 0x69000302000006L
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodetargettracking_list_t pf_autonomousadcs_attitudemodetargettracking_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeTargetTracking
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKING_LIST_SHORT_FORM 0x69000302fffffaL

// generated code for composite PF:AutonomousADCS:AttitudeModeTargetTrackingLinear
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodetargettrackinglinear_t pf_autonomousadcs_attitudemodetargettrackinglinear_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeTargetTrackingLinear
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_SHORT_FORM 0x6900030200000cL
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodetargettrackinglinear_list_t pf_autonomousadcs_attitudemodetargettrackinglinear_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeTargetTrackingLinear
#define PF_AUTONOMOUSADCS_ATTITUDEMODETARGETTRACKINGLINEAR_LIST_SHORT_FORM 0x69000302fffff4L

// generated code for composite PF:AutonomousADCS:AttitudeModeNadirPointing
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodenadirpointing_t pf_autonomousadcs_attitudemodenadirpointing_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeNadirPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_SHORT_FORM 0x69000302000007L
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodenadirpointing_list_t pf_autonomousadcs_attitudemodenadirpointing_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeNadirPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODENADIRPOINTING_LIST_SHORT_FORM 0x69000302fffff9L

// generated code for composite PF:AutonomousADCS:AttitudeModeVectorPointing
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodevectorpointing_t pf_autonomousadcs_attitudemodevectorpointing_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeModeVectorPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_SHORT_FORM 0x6900030200000cL
#ifndef PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudemodevectorpointing_list_t pf_autonomousadcs_attitudemodevectorpointing_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeModeVectorPointing
#define PF_AUTONOMOUSADCS_ATTITUDEMODEVECTORPOINTING_LIST_SHORT_FORM 0x69000302fffff4L

// generated code for composite PF:AutonomousADCS:WheelsSpeed
#ifndef PF_AUTONOMOUSADCS_WHEELSSPEED_T_DEFINED
#define PF_AUTONOMOUSADCS_WHEELSSPEED_T_DEFINED

typedef struct _pf_autonomousadcs_wheelsspeed_t pf_autonomousadcs_wheelsspeed_t;

#endif // PF_AUTONOMOUSADCS_WHEELSSPEED_T_DEFINED

// short form for composite type PF:AutonomousADCS:WheelsSpeed
#define PF_AUTONOMOUSADCS_WHEELSSPEED_SHORT_FORM 0x69000302000008L
#ifndef PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_wheelsspeed_list_t pf_autonomousadcs_wheelsspeed_list_t;

#endif // PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:WheelsSpeed
#define PF_AUTONOMOUSADCS_WHEELSSPEED_LIST_SHORT_FORM 0x69000302fffff8L

// generated code for composite PF:AutonomousADCS:ActuatorsTelemetry
#ifndef PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_T_DEFINED
#define PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_T_DEFINED

typedef struct _pf_autonomousadcs_actuatorstelemetry_t pf_autonomousadcs_actuatorstelemetry_t;

#endif // PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_T_DEFINED

// short form for composite type PF:AutonomousADCS:ActuatorsTelemetry
#define PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_SHORT_FORM 0x69000302000009L
#ifndef PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_actuatorstelemetry_list_t pf_autonomousadcs_actuatorstelemetry_list_t;

#endif // PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:ActuatorsTelemetry
#define PF_AUTONOMOUSADCS_ACTUATORSTELEMETRY_LIST_SHORT_FORM 0x69000302fffff7L

// generated code for composite PF:AutonomousADCS:AttitudeTelemetry
#ifndef PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_T_DEFINED

typedef struct _pf_autonomousadcs_attitudetelemetry_t pf_autonomousadcs_attitudetelemetry_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_T_DEFINED

// short form for composite type PF:AutonomousADCS:AttitudeTelemetry
#define PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_SHORT_FORM 0x6900030200000aL
#ifndef PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_attitudetelemetry_list_t pf_autonomousadcs_attitudetelemetry_list_t;

#endif // PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:AttitudeTelemetry
#define PF_AUTONOMOUSADCS_ATTITUDETELEMETRY_LIST_SHORT_FORM 0x69000302fffff6L

// generated code for enumeration pf_autonomousadcs_magnetorquersstate
typedef enum {
  PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_INACTIVE,
  PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_ACTIVE,
  PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_SUSPEND
} pf_autonomousadcs_magnetorquersstate_t;

// short form for enumeration type pf_autonomousadcs_magnetorquersstate
#define PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_SHORT_FORM 0x6900030200000bL
#ifndef PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_magnetorquersstate_list_t pf_autonomousadcs_magnetorquersstate_list_t;

#endif // PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_T_DEFINED

// short form for list of enumeration type pf_autonomousadcs_magnetorquersstate
#define PF_AUTONOMOUSADCS_MAGNETORQUERSSTATE_LIST_SHORT_FORM 0x69000302fffff5L

// generated code for enumeration pf_autonomousadcs_reactionwheelidentifier
typedef enum {
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_X,
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_Y,
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_Z,
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_U,
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_V,
  PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_WHEEL_W
} pf_autonomousadcs_reactionwheelidentifier_t;

// short form for enumeration type pf_autonomousadcs_reactionwheelidentifier
#define PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_SHORT_FORM 0x6900030200000cL
#ifndef PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_reactionwheelidentifier_list_t pf_autonomousadcs_reactionwheelidentifier_list_t;

#endif // PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_T_DEFINED

// short form for list of enumeration type pf_autonomousadcs_reactionwheelidentifier
#define PF_AUTONOMOUSADCS_REACTIONWHEELIDENTIFIER_LIST_SHORT_FORM 0x69000302fffff4L

// generated code for composite PF:AutonomousADCS:ReactionWheelParameters
#ifndef PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_T_DEFINED
#define PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_T_DEFINED

typedef struct _pf_autonomousadcs_reactionwheelparameters_t pf_autonomousadcs_reactionwheelparameters_t;

#endif // PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_T_DEFINED

// short form for composite type PF:AutonomousADCS:ReactionWheelParameters
#define PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_SHORT_FORM 0x6900030200000cL
#ifndef PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_T_DEFINED
#define PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_T_DEFINED

typedef struct _pf_autonomousadcs_reactionwheelparameters_list_t pf_autonomousadcs_reactionwheelparameters_list_t;

#endif // PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_T_DEFINED

// short form for list of composite type PF:AutonomousADCS:ReactionWheelParameters
#define PF_AUTONOMOUSADCS_REACTIONWHEELPARAMETERS_LIST_SHORT_FORM 0x69000302fffff4L

// standard service identifiers
#define PF_SOFTWAREDEFINEDRADIO_SERVICE_NUMBER 4

// generated code for composite PF:SoftwareDefinedRadio:SDRConfiguration
#ifndef PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_T_DEFINED
#define PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_T_DEFINED

typedef struct _pf_softwaredefinedradio_sdrconfiguration_t pf_softwaredefinedradio_sdrconfiguration_t;

#endif // PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_T_DEFINED

// short form for composite type PF:SoftwareDefinedRadio:SDRConfiguration
#define PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_SHORT_FORM 0x69000402000001L
#ifndef PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_T_DEFINED
#define PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_T_DEFINED

typedef struct _pf_softwaredefinedradio_sdrconfiguration_list_t pf_softwaredefinedradio_sdrconfiguration_list_t;

#endif // PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_T_DEFINED

// short form for list of composite type PF:SoftwareDefinedRadio:SDRConfiguration
#define PF_SOFTWAREDEFINEDRADIO_SDRCONFIGURATION_LIST_SHORT_FORM 0x69000402ffffffL

// generated code for composite PF:SoftwareDefinedRadio:IQComponents
#ifndef PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_T_DEFINED
#define PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_T_DEFINED

typedef struct _pf_softwaredefinedradio_iqcomponents_t pf_softwaredefinedradio_iqcomponents_t;

#endif // PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_T_DEFINED

// short form for composite type PF:SoftwareDefinedRadio:IQComponents
#define PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_SHORT_FORM 0x6900040200001bL
#ifndef PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_T_DEFINED
#define PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_T_DEFINED

typedef struct _pf_softwaredefinedradio_iqcomponents_list_t pf_softwaredefinedradio_iqcomponents_list_t;

#endif // PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_T_DEFINED

// short form for list of composite type PF:SoftwareDefinedRadio:IQComponents
#define PF_SOFTWAREDEFINEDRADIO_IQCOMPONENTS_LIST_SHORT_FORM 0x69000402ffffe5L

// standard service identifiers
#define PF_OPTICALDATARECEIVER_SERVICE_NUMBER 5

// standard service identifiers
#define PF_POWERCONTROL_SERVICE_NUMBER 7

// generated code for composite PF:PowerControl:Device
#ifndef PF_POWERCONTROL_DEVICE_T_DEFINED
#define PF_POWERCONTROL_DEVICE_T_DEFINED

typedef struct _pf_powercontrol_device_t pf_powercontrol_device_t;

#endif // PF_POWERCONTROL_DEVICE_T_DEFINED

// short form for composite type PF:PowerControl:Device
#define PF_POWERCONTROL_DEVICE_SHORT_FORM 0x69000702000011L
#ifndef PF_POWERCONTROL_DEVICE_LIST_T_DEFINED
#define PF_POWERCONTROL_DEVICE_LIST_T_DEFINED

typedef struct _pf_powercontrol_device_list_t pf_powercontrol_device_list_t;

#endif // PF_POWERCONTROL_DEVICE_LIST_T_DEFINED

// short form for list of composite type PF:PowerControl:Device
#define PF_POWERCONTROL_DEVICE_LIST_SHORT_FORM 0x69000702ffffefL

// generated code for enumeration pf_powercontrol_devicetype
typedef enum {
  PF_POWERCONTROL_DEVICETYPE_ADCS,
  PF_POWERCONTROL_DEVICETYPE_OBC,
  PF_POWERCONTROL_DEVICETYPE_SBAND,
  PF_POWERCONTROL_DEVICETYPE_XBAND,
  PF_POWERCONTROL_DEVICETYPE_SDR,
  PF_POWERCONTROL_DEVICETYPE_OPTRX,
  PF_POWERCONTROL_DEVICETYPE_CAMERA,
  PF_POWERCONTROL_DEVICETYPE_OTHER
} pf_powercontrol_devicetype_t;

// short form for enumeration type pf_powercontrol_devicetype
#define PF_POWERCONTROL_DEVICETYPE_SHORT_FORM 0x69000702000003L
#ifndef PF_POWERCONTROL_DEVICETYPE_LIST_T_DEFINED
#define PF_POWERCONTROL_DEVICETYPE_LIST_T_DEFINED

typedef struct _pf_powercontrol_devicetype_list_t pf_powercontrol_devicetype_list_t;

#endif // PF_POWERCONTROL_DEVICETYPE_LIST_T_DEFINED

// short form for list of enumeration type pf_powercontrol_devicetype
#define PF_POWERCONTROL_DEVICETYPE_LIST_SHORT_FORM 0x69000702fffffdL

// include required areas definitions
#include "com.h"
#include "common.h"
#include "mc.h"
#include "softwaremanagement.h"

// generated code for composite PF:_:VectorF3D

// generated code for composite PF:_:VectorD3D

// generated code for composite PF:Camera:Picture

// generated code for composite PF:Camera:PixelResolution

// generated code for composite PF:Camera:CameraSettings

// generated code for operation pf_camera_picturesstream
#define PF_CAMERA_PICTURESSTREAM_OPERATION_NUMBER 1
int pf_camera_picturesstream_update_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_picture_list_t * element, void * cursor);
int pf_camera_picturesstream_update_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_picture_list_t * element);
int pf_camera_picturesstream_update_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_picture_list_t ** element_res);
int pf_camera_picturesstream_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_picturesstream_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_camera_picturesstream_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_camera_picturesstream_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_camera_picturesstream_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int pf_camera_picturesstream_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_camera_picturesstream_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_camera_picturesstream_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation pf_camera_enablestream
#define PF_CAMERA_ENABLESTREAM_OPERATION_NUMBER 2
int pf_camera_enablestream_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_camera_enablestream_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int pf_camera_enablestream_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int pf_camera_enablestream_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int pf_camera_enablestream_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_enablestream_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_camera_enablestream_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_camera_enablestream_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_camera_enablestream_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_enablestream_submit_add_encoding_length_2(mal_encoder_t * encoder, mal_identifier_t * element, void * cursor);
int pf_camera_enablestream_submit_encode_2(void * cursor, mal_encoder_t * encoder, mal_identifier_t * element);
int pf_camera_enablestream_submit_decode_2(void * cursor, mal_decoder_t * decoder, mal_identifier_t ** element_res);
int pf_camera_enablestream_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_enablestream_submit_add_encoding_length_3(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int pf_camera_enablestream_submit_encode_3(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int pf_camera_enablestream_submit_decode_3(void * cursor, mal_decoder_t * decoder, pf_camera_camerasettings_t ** element_res);
int pf_camera_enablestream_submit_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_enablestream_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int pf_camera_enablestream_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_enablestream_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_camera_enablestream_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_camera_enablestream_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_camera_enablestream_error_add_encoding_length_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int pf_camera_enablestream_error_encode_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int pf_camera_enablestream_error_add_encoding_length_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int pf_camera_enablestream_error_encode_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int pf_camera_enablestream_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_camera_previewpicture
#define PF_CAMERA_PREVIEWPICTURE_OPERATION_NUMBER 4
int pf_camera_previewpicture_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_camera_previewpicture_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_camera_previewpicture_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_previewpicture_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int pf_camera_previewpicture_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int pf_camera_previewpicture_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_picture_t ** element_res);
int pf_camera_previewpicture_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_previewpicture_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_camera_previewpicture_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_camera_takepicture
#define PF_CAMERA_TAKEPICTURE_OPERATION_NUMBER 5
int pf_camera_takepicture_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_camera_takepicture_invoke_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int pf_camera_takepicture_invoke_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int pf_camera_takepicture_invoke_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_camerasettings_t ** element_res);
int pf_camera_takepicture_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_takepicture_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_camera_takepicture_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_takepicture_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_camera_takepicture_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_takepicture_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int pf_camera_takepicture_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int pf_camera_takepicture_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_picture_t ** element_res);
int pf_camera_takepicture_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_takepicture_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_camera_takepicture_error_add_encoding_length_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int pf_camera_takepicture_error_encode_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int pf_camera_takepicture_error_add_encoding_length_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int pf_camera_takepicture_error_encode_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int pf_camera_takepicture_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_camera_takeautoexposedpicture
#define PF_CAMERA_TAKEAUTOEXPOSEDPICTURE_OPERATION_NUMBER 15
int pf_camera_takeautoexposedpicture_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_camera_takeautoexposedpicture_invoke_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_camerasettings_t * element, void * cursor);
int pf_camera_takeautoexposedpicture_invoke_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_camerasettings_t * element);
int pf_camera_takeautoexposedpicture_invoke_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_camerasettings_t ** element_res);
int pf_camera_takeautoexposedpicture_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_takeautoexposedpicture_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_camera_takeautoexposedpicture_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_takeautoexposedpicture_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_camera_takeautoexposedpicture_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_takeautoexposedpicture_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_picture_t * element, void * cursor);
int pf_camera_takeautoexposedpicture_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_picture_t * element);
int pf_camera_takeautoexposedpicture_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_picture_t ** element_res);
int pf_camera_takeautoexposedpicture_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_takeautoexposedpicture_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_camera_takeautoexposedpicture_error_add_encoding_length_pf_camera_pixelresolution_list(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int pf_camera_takeautoexposedpicture_error_encode_pf_camera_pixelresolution_list(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int pf_camera_takeautoexposedpicture_error_add_encoding_length_pf_camera_pictureformat_list(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int pf_camera_takeautoexposedpicture_error_encode_pf_camera_pictureformat_list(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int pf_camera_takeautoexposedpicture_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_camera_getproperties
#define PF_CAMERA_GETPROPERTIES_OPERATION_NUMBER 6
int pf_camera_getproperties_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_camera_getproperties_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_camera_getproperties_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_camera_getproperties_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element, void * cursor);
int pf_camera_getproperties_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_camera_pixelresolution_list_t * element);
int pf_camera_getproperties_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_camera_pixelresolution_list_t ** element_res);
int pf_camera_getproperties_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_getproperties_request_response_add_encoding_length_1(mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element, void * cursor);
int pf_camera_getproperties_request_response_encode_1(void * cursor, mal_encoder_t * encoder, pf_camera_pictureformat_list_t * element);
int pf_camera_getproperties_request_response_decode_1(void * cursor, mal_decoder_t * decoder, pf_camera_pictureformat_list_t ** element_res);
int pf_camera_getproperties_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_getproperties_request_response_add_encoding_length_2(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_camera_getproperties_request_response_encode_2(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_camera_getproperties_request_response_decode_2(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int pf_camera_getproperties_request_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_camera_getproperties_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);

// generated code for composite PF:GPS:Position

// generated code for composite PF:GPS:SatelliteInfo

// generated code for composite PF:GPS:PositionExtraDetails

// generated code for composite PF:GPS:NearbyPositionDefinition

// generated code for composite PF:GPS:TwoLineElementSet

// generated code for operation pf_gps_getnmeasentence
#define PF_GPS_GETNMEASENTENCE_OPERATION_NUMBER 1
int pf_gps_getnmeasentence_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getnmeasentence_invoke_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_gps_getnmeasentence_invoke_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_gps_getnmeasentence_invoke_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int pf_gps_getnmeasentence_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getnmeasentence_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_getnmeasentence_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getnmeasentence_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getnmeasentence_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getnmeasentence_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_gps_getnmeasentence_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_gps_getnmeasentence_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int pf_gps_getnmeasentence_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getnmeasentence_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_getnmeasentence_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_getlastknownposition
#define PF_GPS_GETLASTKNOWNPOSITION_OPERATION_NUMBER 2
int pf_gps_getlastknownposition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getlastknownposition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getlastknownposition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getlastknownposition_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int pf_gps_getlastknownposition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int pf_gps_getlastknownposition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_gps_position_t ** element_res);
int pf_gps_getlastknownposition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownposition_request_response_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_gps_getlastknownposition_request_response_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_gps_getlastknownposition_request_response_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_gps_getlastknownposition_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownposition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int pf_gps_getlastknownposition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_getposition
#define PF_GPS_GETPOSITION_OPERATION_NUMBER 3
int pf_gps_getposition_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getposition_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getposition_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getposition_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getposition_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getposition_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_gps_position_t * element, void * cursor);
int pf_gps_getposition_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_gps_position_t * element);
int pf_gps_getposition_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_gps_position_t ** element_res);
int pf_gps_getposition_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getposition_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_getposition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_getsatellitesinfo
#define PF_GPS_GETSATELLITESINFO_OPERATION_NUMBER 4
int pf_gps_getsatellitesinfo_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getsatellitesinfo_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getsatellitesinfo_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getsatellitesinfo_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getsatellitesinfo_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getsatellitesinfo_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element, void * cursor);
int pf_gps_getsatellitesinfo_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_gps_satelliteinfo_list_t * element);
int pf_gps_getsatellitesinfo_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_gps_satelliteinfo_list_t ** element_res);
int pf_gps_getsatellitesinfo_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getsatellitesinfo_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_getsatellitesinfo_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_listnearbyposition
#define PF_GPS_LISTNEARBYPOSITION_OPERATION_NUMBER 5
int pf_gps_listnearbyposition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_listnearbyposition_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int pf_gps_listnearbyposition_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int pf_gps_listnearbyposition_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int pf_gps_listnearbyposition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_listnearbyposition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_listnearbyposition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_listnearbyposition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int pf_gps_listnearbyposition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int pf_gps_listnearbyposition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int pf_gps_listnearbyposition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_listnearbyposition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);

// generated code for operation pf_gps_addnearbyposition
#define PF_GPS_ADDNEARBYPOSITION_OPERATION_NUMBER 6
int pf_gps_addnearbyposition_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_addnearbyposition_request_add_encoding_length_0(mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element, void * cursor);
int pf_gps_addnearbyposition_request_encode_0(void * cursor, mal_encoder_t * encoder, pf_gps_nearbypositiondefinition_list_t * element);
int pf_gps_addnearbyposition_request_decode_0(void * cursor, mal_decoder_t * decoder, pf_gps_nearbypositiondefinition_list_t ** element_res);
int pf_gps_addnearbyposition_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_addnearbyposition_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_addnearbyposition_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_addnearbyposition_request_response_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int pf_gps_addnearbyposition_request_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int pf_gps_addnearbyposition_request_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int pf_gps_addnearbyposition_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_addnearbyposition_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_addnearbyposition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int pf_gps_addnearbyposition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int pf_gps_addnearbyposition_error_add_encoding_length_mal_uinteger(mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element, void * cursor);
int pf_gps_addnearbyposition_error_encode_mal_uinteger(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_uinteger_t element);
int pf_gps_addnearbyposition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_removenearbyposition
#define PF_GPS_REMOVENEARBYPOSITION_OPERATION_NUMBER 7
int pf_gps_removenearbyposition_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_removenearbyposition_submit_add_encoding_length_0(mal_encoder_t * encoder, mal_long_list_t * element, void * cursor);
int pf_gps_removenearbyposition_submit_encode_0(void * cursor, mal_encoder_t * encoder, mal_long_list_t * element);
int pf_gps_removenearbyposition_submit_decode_0(void * cursor, mal_decoder_t * decoder, mal_long_list_t ** element_res);
int pf_gps_removenearbyposition_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_removenearbyposition_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_removenearbyposition_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_removenearbyposition_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_removenearbyposition_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int pf_gps_removenearbyposition_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int pf_gps_removenearbyposition_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_nearbyposition
#define PF_GPS_NEARBYPOSITION_OPERATION_NUMBER 8
int pf_gps_nearbyposition_update_add_encoding_length_0(mal_encoder_t * encoder, mal_boolean_list_t * element, void * cursor);
int pf_gps_nearbyposition_update_encode_0(void * cursor, mal_encoder_t * encoder, mal_boolean_list_t * element);
int pf_gps_nearbyposition_update_decode_0(void * cursor, mal_decoder_t * decoder, mal_boolean_list_t ** element_res);
int pf_gps_nearbyposition_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_nearbyposition_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_gps_nearbyposition_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_gps_nearbyposition_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_gps_nearbyposition_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int pf_gps_nearbyposition_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_gps_nearbyposition_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_gps_nearbyposition_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation pf_gps_getbestxyzsentence
#define PF_GPS_GETBESTXYZSENTENCE_OPERATION_NUMBER 9
int pf_gps_getbestxyzsentence_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getbestxyzsentence_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getbestxyzsentence_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getbestxyzsentence_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getbestxyzsentence_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getbestxyzsentence_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_gps_getbestxyzsentence_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_gps_getbestxyzsentence_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int pf_gps_getbestxyzsentence_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getbestxyzsentence_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_getbestxyzsentence_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_gettimeasentence
#define PF_GPS_GETTIMEASENTENCE_OPERATION_NUMBER 10
int pf_gps_gettimeasentence_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_gettimeasentence_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_gettimeasentence_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_gettimeasentence_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_gettimeasentence_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_gettimeasentence_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_gps_gettimeasentence_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_gps_gettimeasentence_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_string_t ** element_res);
int pf_gps_gettimeasentence_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_gettimeasentence_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_gettimeasentence_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_getlastknownpositionandvelocity
#define PF_GPS_GETLASTKNOWNPOSITIONANDVELOCITY_OPERATION_NUMBER 11
int pf_gps_getlastknownpositionandvelocity_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getlastknownpositionandvelocity_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getlastknownpositionandvelocity_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getlastknownpositionandvelocity_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int pf_gps_getlastknownpositionandvelocity_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_vectord3d_t ** element_res);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownpositionandvelocity_request_response_add_encoding_length_1(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int pf_gps_getlastknownpositionandvelocity_request_response_encode_1(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_1(void * cursor, mal_decoder_t * decoder, pf_vectorf3d_t ** element_res);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownpositionandvelocity_request_response_add_encoding_length_2(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int pf_gps_getlastknownpositionandvelocity_request_response_encode_2(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_2(void * cursor, mal_decoder_t * decoder, pf_vectord3d_t ** element_res);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownpositionandvelocity_request_response_add_encoding_length_3(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int pf_gps_getlastknownpositionandvelocity_request_response_encode_3(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_3(void * cursor, mal_decoder_t * decoder, pf_vectorf3d_t ** element_res);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownpositionandvelocity_request_response_add_encoding_length_4(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_gps_getlastknownpositionandvelocity_request_response_encode_4(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_4(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_gps_getlastknownpositionandvelocity_request_response_decode_4_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getlastknownpositionandvelocity_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3, mal_element_holder_t * arg4);
int pf_gps_getlastknownpositionandvelocity_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_getpositionandvelocity
#define PF_GPS_GETPOSITIONANDVELOCITY_OPERATION_NUMBER 12
int pf_gps_getpositionandvelocity_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_getpositionandvelocity_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getpositionandvelocity_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getpositionandvelocity_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_getpositionandvelocity_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_getpositionandvelocity_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int pf_gps_getpositionandvelocity_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int pf_gps_getpositionandvelocity_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_vectord3d_t ** element_res);
int pf_gps_getpositionandvelocity_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getpositionandvelocity_invoke_response_add_encoding_length_1(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int pf_gps_getpositionandvelocity_invoke_response_encode_1(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int pf_gps_getpositionandvelocity_invoke_response_decode_1(void * cursor, mal_decoder_t * decoder, pf_vectorf3d_t ** element_res);
int pf_gps_getpositionandvelocity_invoke_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getpositionandvelocity_invoke_response_add_encoding_length_2(mal_encoder_t * encoder, pf_vectord3d_t * element, void * cursor);
int pf_gps_getpositionandvelocity_invoke_response_encode_2(void * cursor, mal_encoder_t * encoder, pf_vectord3d_t * element);
int pf_gps_getpositionandvelocity_invoke_response_decode_2(void * cursor, mal_decoder_t * decoder, pf_vectord3d_t ** element_res);
int pf_gps_getpositionandvelocity_invoke_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getpositionandvelocity_invoke_response_add_encoding_length_3(mal_encoder_t * encoder, pf_vectorf3d_t * element, void * cursor);
int pf_gps_getpositionandvelocity_invoke_response_encode_3(void * cursor, mal_encoder_t * encoder, pf_vectorf3d_t * element);
int pf_gps_getpositionandvelocity_invoke_response_decode_3(void * cursor, mal_decoder_t * decoder, pf_vectorf3d_t ** element_res);
int pf_gps_getpositionandvelocity_invoke_response_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_getpositionandvelocity_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3);
int pf_gps_getpositionandvelocity_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_gps_gettle
#define PF_GPS_GETTLE_OPERATION_NUMBER 13
int pf_gps_gettle_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_gps_gettle_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_gettle_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_gettle_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_gps_gettle_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_gps_gettle_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, pf_gps_twolineelementset_t * element, void * cursor);
int pf_gps_gettle_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_gps_twolineelementset_t * element);
int pf_gps_gettle_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_gps_twolineelementset_t ** element_res);
int pf_gps_gettle_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_gps_gettle_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_gps_gettle_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite PF:AutonomousADCS:Quaternion

// generated code for composite PF:AutonomousADCS:AttitudeModeBDot

// generated code for composite PF:AutonomousADCS:AttitudeModeSingleSpinning

// generated code for composite PF:AutonomousADCS:AttitudeModeSunPointing

// generated code for composite PF:AutonomousADCS:AttitudeModeTargetTracking

// generated code for composite PF:AutonomousADCS:AttitudeModeTargetTrackingLinear

// generated code for composite PF:AutonomousADCS:AttitudeModeNadirPointing

// generated code for composite PF:AutonomousADCS:AttitudeModeVectorPointing

// generated code for composite PF:AutonomousADCS:WheelsSpeed

// generated code for composite PF:AutonomousADCS:ActuatorsTelemetry

// generated code for composite PF:AutonomousADCS:AttitudeTelemetry

// generated code for composite PF:AutonomousADCS:ReactionWheelParameters

// generated code for operation pf_autonomousadcs_monitorattitude
#define PF_AUTONOMOUSADCS_MONITORATTITUDE_OPERATION_NUMBER 1
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_0(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_0(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_list_t * element);
int pf_autonomousadcs_monitorattitude_update_decode_0(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_attitudetelemetry_list_t ** element_res);
int pf_autonomousadcs_monitorattitude_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_1(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_1(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_list_t * element);
int pf_autonomousadcs_monitorattitude_update_decode_1(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_actuatorstelemetry_list_t ** element_res);
int pf_autonomousadcs_monitorattitude_update_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_2(mal_encoder_t * encoder, mal_duration_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_2(void * cursor, mal_encoder_t * encoder, mal_duration_list_t * element);
int pf_autonomousadcs_monitorattitude_update_decode_2(void * cursor, mal_decoder_t * decoder, mal_duration_list_t ** element_res);
int pf_autonomousadcs_monitorattitude_update_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodebdot_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodebdot_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodenadirpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodenadirpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesinglespinning_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodesinglespinning_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodesunpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodesunpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettracking_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodetargettracking_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodetargettrackinglinear_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3_pf_autonomousadcs_attitudemodevectorpointing_list(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3_pf_autonomousadcs_attitudemodevectorpointing_list(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_list_t * element);
int pf_autonomousadcs_monitorattitude_update_add_encoding_length_3(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int pf_autonomousadcs_monitorattitude_update_encode_3(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int pf_autonomousadcs_monitorattitude_update_decode_3(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_monitorattitude_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_autonomousadcs_monitorattitude_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_autonomousadcs_monitorattitude_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_autonomousadcs_monitorattitude_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int pf_autonomousadcs_monitorattitude_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_autonomousadcs_monitorattitude_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_autonomousadcs_monitorattitude_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation pf_autonomousadcs_enablemonitoring
#define PF_AUTONOMOUSADCS_ENABLEMONITORING_OPERATION_NUMBER 2
int pf_autonomousadcs_enablemonitoring_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_enablemonitoring_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int pf_autonomousadcs_enablemonitoring_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int pf_autonomousadcs_enablemonitoring_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int pf_autonomousadcs_enablemonitoring_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_enablemonitoring_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_enablemonitoring_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_enablemonitoring_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_autonomousadcs_enablemonitoring_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_enablemonitoring_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int pf_autonomousadcs_enablemonitoring_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_enablemonitoring_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_enablemonitoring_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_enablemonitoring_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_enablemonitoring_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_getstatus
#define PF_AUTONOMOUSADCS_GETSTATUS_OPERATION_NUMBER 3
int pf_autonomousadcs_getstatus_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_getstatus_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_getstatus_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudetelemetry_t * element);
int pf_autonomousadcs_getstatus_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_attitudetelemetry_t ** element_res);
int pf_autonomousadcs_getstatus_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_1(mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_1(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_actuatorstelemetry_t * element);
int pf_autonomousadcs_getstatus_request_response_decode_1(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_actuatorstelemetry_t ** element_res);
int pf_autonomousadcs_getstatus_request_response_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_getstatus_request_response_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_autonomousadcs_getstatus_request_response_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int pf_autonomousadcs_getstatus_request_response_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int pf_autonomousadcs_getstatus_request_response_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_4(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_4(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_getstatus_request_response_decode_4(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_autonomousadcs_getstatus_request_response_decode_4_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int pf_autonomousadcs_getstatus_request_response_add_encoding_length_5(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int pf_autonomousadcs_getstatus_request_response_encode_5(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int pf_autonomousadcs_getstatus_request_response_decode_5(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getstatus_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3, mal_element_holder_t * arg4, mal_element_holder_t * arg5);
int pf_autonomousadcs_getstatus_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_setdesiredattitude
#define PF_AUTONOMOUSADCS_SETDESIREDATTITUDE_OPERATION_NUMBER 4
int pf_autonomousadcs_setdesiredattitude_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_setdesiredattitude_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_autonomousadcs_setdesiredattitude_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodebdot(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodebdot(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodebdot_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodenadirpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodenadirpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodenadirpointing_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodesinglespinning(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodesinglespinning(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesinglespinning_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodesunpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodesunpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodesunpointing_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettracking(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodetargettracking(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettracking_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodetargettrackinglinear(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodetargettrackinglinear(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodetargettrackinglinear_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1_pf_autonomousadcs_attitudemodevectorpointing(mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1_pf_autonomousadcs_attitudemodevectorpointing(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_attitudemodevectorpointing_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_add_encoding_length_1(mal_encoder_t * encoder, mal_element_holder_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_submit_encode_1(void * cursor, mal_encoder_t * encoder, mal_element_holder_t * element);
int pf_autonomousadcs_setdesiredattitude_submit_decode_1(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setdesiredattitude_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int pf_autonomousadcs_setdesiredattitude_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_setdesiredattitude_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_setdesiredattitude_error_add_encoding_length_mal_string(mal_encoder_t * encoder, mal_string_t * element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_error_encode_mal_string(void * cursor, mal_encoder_t * encoder, mal_string_t * element);
int pf_autonomousadcs_setdesiredattitude_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_autonomousadcs_setdesiredattitude_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_autonomousadcs_setdesiredattitude_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_setreactionwheelspeed
#define PF_AUTONOMOUSADCS_SETREACTIONWHEELSPEED_OPERATION_NUMBER 20
int pf_autonomousadcs_setreactionwheelspeed_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_setreactionwheelspeed_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element, void * cursor);
int pf_autonomousadcs_setreactionwheelspeed_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, pf_autonomousadcs_reactionwheelidentifier_t element);
int pf_autonomousadcs_setreactionwheelspeed_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, pf_autonomousadcs_reactionwheelidentifier_t * element_res);
int pf_autonomousadcs_setreactionwheelspeed_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setreactionwheelspeed_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setreactionwheelspeed_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setreactionwheelspeed_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setreactionwheelspeed_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setreactionwheelspeed_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1);
int pf_autonomousadcs_setreactionwheelspeed_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_setreactionwheelspeed_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_setreactionwheelspeed_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_setallreactionwheelspeeds
#define PF_AUTONOMOUSADCS_SETALLREACTIONWHEELSPEEDS_OPERATION_NUMBER 21
int pf_autonomousadcs_setallreactionwheelspeeds_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_3(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_3(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_3(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_3_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_4(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_4(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_4(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_4_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_add_encoding_length_5(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_encode_5(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_5(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_decode_5_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2, mal_element_holder_t * arg3, mal_element_holder_t * arg4, mal_element_holder_t * arg5);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_setallreactionwheelspeeds_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_setallreactionwheelspeeds_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_setallreactionwheelparameters
#define PF_AUTONOMOUSADCS_SETALLREACTIONWHEELPARAMETERS_OPERATION_NUMBER 22
int pf_autonomousadcs_setallreactionwheelparameters_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_setallreactionwheelparameters_submit_add_encoding_length_0(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int pf_autonomousadcs_setallreactionwheelparameters_submit_encode_0(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int pf_autonomousadcs_setallreactionwheelparameters_submit_decode_0(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_reactionwheelparameters_t ** element_res);
int pf_autonomousadcs_setallreactionwheelparameters_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallreactionwheelparameters_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_autonomousadcs_setallreactionwheelparameters_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_setallreactionwheelparameters_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_setallreactionwheelparameters_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_setallmagnetorquersdipolemoments
#define PF_AUTONOMOUSADCS_SETALLMAGNETORQUERSDIPOLEMOMENTS_OPERATION_NUMBER 23
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_add_encoding_length_1(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_encode_1(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_1(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_float_t element, void * cursor);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_float_t element);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_float_t * element_res);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_setallmagnetorquersdipolemoments_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_autonomousadcs_getallreactionwheelparameters
#define PF_AUTONOMOUSADCS_GETALLREACTIONWHEELPARAMETERS_OPERATION_NUMBER 24
int pf_autonomousadcs_getallreactionwheelparameters_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_autonomousadcs_getallreactionwheelparameters_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_autonomousadcs_getallreactionwheelparameters_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_autonomousadcs_getallreactionwheelparameters_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element, void * cursor);
int pf_autonomousadcs_getallreactionwheelparameters_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_autonomousadcs_reactionwheelparameters_t * element);
int pf_autonomousadcs_getallreactionwheelparameters_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_autonomousadcs_reactionwheelparameters_t ** element_res);
int pf_autonomousadcs_getallreactionwheelparameters_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_autonomousadcs_getallreactionwheelparameters_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_autonomousadcs_getallreactionwheelparameters_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite PF:SoftwareDefinedRadio:SDRConfiguration

// generated code for composite PF:SoftwareDefinedRadio:IQComponents

// generated code for operation pf_softwaredefinedradio_streamradio
#define PF_SOFTWAREDEFINEDRADIO_STREAMRADIO_OPERATION_NUMBER 1
int pf_softwaredefinedradio_streamradio_update_add_encoding_length_0(mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element, void * cursor);
int pf_softwaredefinedradio_streamradio_update_encode_0(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_iqcomponents_list_t * element);
int pf_softwaredefinedradio_streamradio_update_decode_0(void * cursor, mal_decoder_t * decoder, pf_softwaredefinedradio_iqcomponents_list_t ** element_res);
int pf_softwaredefinedradio_streamradio_update_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_softwaredefinedradio_streamradio_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_softwaredefinedradio_streamradio_register_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_softwaredefinedradio_streamradio_publish_register(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_softwaredefinedradio_streamradio_publish(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri, long initial_publish_register_tid);
int pf_softwaredefinedradio_streamradio_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);
int pf_softwaredefinedradio_streamradio_deregister_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * broker_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg);
int pf_softwaredefinedradio_streamradio_publish_deregister(mal_endpoint_t * endpoint, mal_message_t * message, mal_uri_t * broker_uri);

// generated code for operation pf_softwaredefinedradio_enablesdr
#define PF_SOFTWAREDEFINEDRADIO_ENABLESDR_OPERATION_NUMBER 2
int pf_softwaredefinedradio_enablesdr_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_softwaredefinedradio_enablesdr_submit_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element, void * cursor);
int pf_softwaredefinedradio_enablesdr_submit_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_boolean_t element);
int pf_softwaredefinedradio_enablesdr_submit_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_boolean_t * element_res);
int pf_softwaredefinedradio_enablesdr_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_softwaredefinedradio_enablesdr_submit_add_encoding_length_1(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int pf_softwaredefinedradio_enablesdr_submit_encode_1(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int pf_softwaredefinedradio_enablesdr_submit_decode_1(void * cursor, mal_decoder_t * decoder, pf_softwaredefinedradio_sdrconfiguration_t ** element_res);
int pf_softwaredefinedradio_enablesdr_submit_decode_1_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_softwaredefinedradio_enablesdr_submit_add_encoding_length_2(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_softwaredefinedradio_enablesdr_submit_encode_2(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_softwaredefinedradio_enablesdr_submit_decode_2(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_softwaredefinedradio_enablesdr_submit_decode_2_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_softwaredefinedradio_enablesdr_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0, mal_element_holder_t * arg1, mal_element_holder_t * arg2);
int pf_softwaredefinedradio_enablesdr_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_softwaredefinedradio_enablesdr_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_softwaredefinedradio_enablesdr_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_softwaredefinedradio_updateconfiguration
#define PF_SOFTWAREDEFINEDRADIO_UPDATECONFIGURATION_OPERATION_NUMBER 3
int pf_softwaredefinedradio_updateconfiguration_submit(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_softwaredefinedradio_updateconfiguration_submit_add_encoding_length_0(mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element, void * cursor);
int pf_softwaredefinedradio_updateconfiguration_submit_encode_0(void * cursor, mal_encoder_t * encoder, pf_softwaredefinedradio_sdrconfiguration_t * element);
int pf_softwaredefinedradio_updateconfiguration_submit_decode_0(void * cursor, mal_decoder_t * decoder, pf_softwaredefinedradio_sdrconfiguration_t ** element_res);
int pf_softwaredefinedradio_updateconfiguration_submit_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_softwaredefinedradio_updateconfiguration_submit_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_softwaredefinedradio_updateconfiguration_submit_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_softwaredefinedradio_updateconfiguration_submit_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_softwaredefinedradio_updateconfiguration_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_opticaldatareceiver_recordsamples
#define PF_OPTICALDATARECEIVER_RECORDSAMPLES_OPERATION_NUMBER 1
int pf_opticaldatareceiver_recordsamples_invoke(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_opticaldatareceiver_recordsamples_invoke_add_encoding_length_0(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_opticaldatareceiver_recordsamples_invoke_encode_0(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_opticaldatareceiver_recordsamples_invoke_decode_0(void * cursor, mal_decoder_t * decoder, bool * presence_flag_res, mal_duration_t * element_res);
int pf_opticaldatareceiver_recordsamples_invoke_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_opticaldatareceiver_recordsamples_invoke_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_opticaldatareceiver_recordsamples_invoke_ack(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_opticaldatareceiver_recordsamples_invoke_ack_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_opticaldatareceiver_recordsamples_invoke_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_opticaldatareceiver_recordsamples_invoke_response_add_encoding_length_0(mal_encoder_t * encoder, mal_blob_t * element, void * cursor);
int pf_opticaldatareceiver_recordsamples_invoke_response_encode_0(void * cursor, mal_encoder_t * encoder, mal_blob_t * element);
int pf_opticaldatareceiver_recordsamples_invoke_response_decode_0(void * cursor, mal_decoder_t * decoder, mal_blob_t ** element_res);
int pf_opticaldatareceiver_recordsamples_invoke_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_opticaldatareceiver_recordsamples_invoke_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_opticaldatareceiver_recordsamples_error_add_encoding_length_mal_duration(mal_encoder_t * encoder, bool presence_flag, mal_duration_t element, void * cursor);
int pf_opticaldatareceiver_recordsamples_error_encode_mal_duration(void * cursor, mal_encoder_t * encoder, bool presence_flag, mal_duration_t element);
int pf_opticaldatareceiver_recordsamples_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for composite PF:PowerControl:Device

// generated code for operation pf_powercontrol_listdevices
#define PF_POWERCONTROL_LISTDEVICES_OPERATION_NUMBER 1
int pf_powercontrol_listdevices_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_powercontrol_listdevices_request_add_encoding_length_0(mal_encoder_t * encoder, mal_identifier_list_t * element, void * cursor);
int pf_powercontrol_listdevices_request_encode_0(void * cursor, mal_encoder_t * encoder, mal_identifier_list_t * element);
int pf_powercontrol_listdevices_request_decode_0(void * cursor, mal_decoder_t * decoder, mal_identifier_list_t ** element_res);
int pf_powercontrol_listdevices_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_powercontrol_listdevices_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_powercontrol_listdevices_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_powercontrol_listdevices_request_response_add_encoding_length_0(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int pf_powercontrol_listdevices_request_response_encode_0(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int pf_powercontrol_listdevices_request_response_decode_0(void * cursor, mal_decoder_t * decoder, pf_powercontrol_device_list_t ** element_res);
int pf_powercontrol_listdevices_request_response_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_powercontrol_listdevices_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_powercontrol_listdevices_error_add_encoding_length_mal_uinteger_list(mal_encoder_t * encoder, mal_uinteger_list_t * element, void * cursor);
int pf_powercontrol_listdevices_error_encode_mal_uinteger_list(void * cursor, mal_encoder_t * encoder, mal_uinteger_list_t * element);
int pf_powercontrol_listdevices_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// generated code for operation pf_powercontrol_enabledevices
#define PF_POWERCONTROL_ENABLEDEVICES_OPERATION_NUMBER 2
int pf_powercontrol_enabledevices_request(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_uri_t * provider_uri);
int pf_powercontrol_enabledevices_request_add_encoding_length_0(mal_encoder_t * encoder, pf_powercontrol_device_list_t * element, void * cursor);
int pf_powercontrol_enabledevices_request_encode_0(void * cursor, mal_encoder_t * encoder, pf_powercontrol_device_list_t * element);
int pf_powercontrol_enabledevices_request_decode_0(void * cursor, mal_decoder_t * decoder, pf_powercontrol_device_list_t ** element_res);
int pf_powercontrol_enabledevices_request_decode_0_mal_element(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);
int pf_powercontrol_enabledevices_request_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_uri_t * provider_uri, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name, mal_element_holder_t * arg0);
int pf_powercontrol_enabledevices_request_response(mal_endpoint_t * endpoint, mal_message_t * init_message, mal_message_t * result_message, bool is_error_message);
int pf_powercontrol_enabledevices_request_response_full(mal_encoder_t * encoder, mal_endpoint_t * endpoint, mal_message_t * result_message, bool is_error_message, mal_blob_t * authentication_id, mal_qoslevel_t  qoslevel, mal_uinteger_t  priority, mal_identifier_list_t * domain, mal_identifier_t * network_zone, mal_sessiontype_t  session, mal_identifier_t * session_name);
int pf_powercontrol_enabledevices_error_decode(void * cursor, mal_decoder_t * decoder, mal_element_holder_t * element_holder);

// test function
void pf_test(bool verbose);

#include "pf_vectorf3d.h"
#include "pf_vectorf3d_list.h"
#include "pf_vectord3d.h"
#include "pf_vectord3d_list.h"
#include "pf_camera_picture.h"
#include "pf_camera_picture_list.h"
#include "pf_camera_pixelresolution.h"
#include "pf_camera_pixelresolution_list.h"
#include "pf_camera_pictureformat_list.h"
#include "pf_camera_camerasettings.h"
#include "pf_camera_camerasettings_list.h"
#include "pf_gps_position.h"
#include "pf_gps_position_list.h"
#include "pf_gps_satelliteinfo.h"
#include "pf_gps_satelliteinfo_list.h"
#include "pf_gps_positionextradetails.h"
#include "pf_gps_positionextradetails_list.h"
#include "pf_gps_nearbypositiondefinition.h"
#include "pf_gps_nearbypositiondefinition_list.h"
#include "pf_gps_twolineelementset.h"
#include "pf_gps_twolineelementset_list.h"
#include "pf_autonomousadcs_quaternion.h"
#include "pf_autonomousadcs_quaternion_list.h"
#include "pf_autonomousadcs_attitudemodebdot.h"
#include "pf_autonomousadcs_attitudemodebdot_list.h"
#include "pf_autonomousadcs_attitudemodesinglespinning.h"
#include "pf_autonomousadcs_attitudemodesinglespinning_list.h"
#include "pf_autonomousadcs_attitudemodesunpointing.h"
#include "pf_autonomousadcs_attitudemodesunpointing_list.h"
#include "pf_autonomousadcs_attitudemodetargettracking.h"
#include "pf_autonomousadcs_attitudemodetargettracking_list.h"
#include "pf_autonomousadcs_attitudemodetargettrackinglinear.h"
#include "pf_autonomousadcs_attitudemodetargettrackinglinear_list.h"
#include "pf_autonomousadcs_attitudemodenadirpointing.h"
#include "pf_autonomousadcs_attitudemodenadirpointing_list.h"
#include "pf_autonomousadcs_attitudemodevectorpointing.h"
#include "pf_autonomousadcs_attitudemodevectorpointing_list.h"
#include "pf_autonomousadcs_wheelsspeed.h"
#include "pf_autonomousadcs_wheelsspeed_list.h"
#include "pf_autonomousadcs_actuatorstelemetry.h"
#include "pf_autonomousadcs_actuatorstelemetry_list.h"
#include "pf_autonomousadcs_attitudetelemetry.h"
#include "pf_autonomousadcs_attitudetelemetry_list.h"
#include "pf_autonomousadcs_magnetorquersstate_list.h"
#include "pf_autonomousadcs_reactionwheelidentifier_list.h"
#include "pf_autonomousadcs_reactionwheelparameters.h"
#include "pf_autonomousadcs_reactionwheelparameters_list.h"
#include "pf_softwaredefinedradio_sdrconfiguration.h"
#include "pf_softwaredefinedradio_sdrconfiguration_list.h"
#include "pf_softwaredefinedradio_iqcomponents.h"
#include "pf_softwaredefinedradio_iqcomponents_list.h"
#include "pf_powercontrol_device.h"
#include "pf_powercontrol_device_list.h"
#include "pf_powercontrol_devicetype_list.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __PF_H_INCLUDED__
