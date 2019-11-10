//
// Primary and Secondary School License - for use in teaching and meeting
// course requirements at primary and secondary schools only.  Not for
// government, commercial, university, or other organizational use.
//
// File: sh_water_supply_system.h
//
// Code generated for Simulink model 'sh_water_supply_system'.
//
// Model version                  : 1.70
// Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
// C/C++ source code generated on : Sat Nov  9 18:33:49 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_sh_water_supply_system_h_
#define RTW_HEADER_sh_water_supply_system_h_
#include <string.h>
#include <cmath>
#ifndef sh_water_supply_system_COMMON_INCLUDES_
# define sh_water_supply_system_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "sh_water_supply_system_900c0b92_1_gateway.h"
#endif                               // sh_water_supply_system_COMMON_INCLUDES_

#include "rt_matrixlib.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Block signals and states (default storage) for system '<Root>'
typedef struct {
  real_T INPUT_2_1_1[4];               // '<S21>/INPUT_2_1_1'
  real_T INPUT_1_1_1[4];               // '<S21>/INPUT_1_1_1'
  real_T INPUT_4_1_1[4];               // '<S21>/INPUT_4_1_1'
  real_T INPUT_3_1_1[4];               // '<S21>/INPUT_3_1_1'
  real_T INPUT_6_1_1[4];               // '<S21>/INPUT_6_1_1'
  real_T INPUT_5_1_1[4];               // '<S21>/INPUT_5_1_1'
  real_T STATE_1[44];                  // '<S21>/STATE_1'
  real_T INPUT_2_1_1_Discrete[2];      // '<S21>/INPUT_2_1_1'
  real_T INPUT_1_1_1_Discrete[2];      // '<S21>/INPUT_1_1_1'
  real_T INPUT_4_1_1_Discrete[2];      // '<S21>/INPUT_4_1_1'
  real_T INPUT_3_1_1_Discrete[2];      // '<S21>/INPUT_3_1_1'
  real_T INPUT_6_1_1_Discrete[2];      // '<S21>/INPUT_6_1_1'
  real_T INPUT_5_1_1_Discrete[2];      // '<S21>/INPUT_5_1_1'
  real_T STATE_1_Discrete;             // '<S21>/STATE_1'
  real_T OUTPUT_1_0_Discrete;          // '<S21>/OUTPUT_1_0'
  void* STATE_1_Simulator;             // '<S21>/STATE_1'
  void* STATE_1_SimData;               // '<S21>/STATE_1'
  void* STATE_1_DiagMgr;               // '<S21>/STATE_1'
  void* STATE_1_ZcLogger;              // '<S21>/STATE_1'
  void* STATE_1_TsIndex;               // '<S21>/STATE_1'
  void* OUTPUT_1_0_Simulator;          // '<S21>/OUTPUT_1_0'
  void* OUTPUT_1_0_SimData;            // '<S21>/OUTPUT_1_0'
  void* OUTPUT_1_0_DiagMgr;            // '<S21>/OUTPUT_1_0'
  void* OUTPUT_1_0_ZcLogger;           // '<S21>/OUTPUT_1_0'
  void* OUTPUT_1_0_TsIndex;            // '<S21>/OUTPUT_1_0'
  int_T STATE_1_Modes;                 // '<S21>/STATE_1'
  int_T OUTPUT_1_0_Modes;              // '<S21>/OUTPUT_1_0'
  int32_T STATE_1_MASS_MATRIX_PR;      // '<S21>/STATE_1'
  boolean_T STATE_1_FirstOutput;       // '<S21>/STATE_1'
  boolean_T OUTPUT_1_0_FirstOutput;    // '<S21>/OUTPUT_1_0'
} DW;

// Continuous states (default storage)
typedef struct {
  real_T sh_water_supply_systemTank_Stat[44];// '<S21>/STATE_1'
} X;

// State derivatives (default storage)
typedef struct {
  real_T sh_water_supply_systemTank_Stat[44];// '<S21>/STATE_1'
} XDot;

// State disabled
typedef struct {
  boolean_T sh_water_supply_systemTank_Stat[44];// '<S21>/STATE_1'
} XDis;

// Mass Matrix (global)
typedef struct {
  int_T ir[4];
  int_T jc[45];
  real_T pr[4];
} MassMatrix;

#ifndef ODE14X_INTG
#define ODE14X_INTG

// ODE14X Integration Data
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[44];
  real_T odeF0[44];
  real_T odeX1START[44];
  real_T odeF1[44];
  real_T odeDELTA[44];
  real_T odeE[4*44];
  real_T odeFAC[44];
  real_T odeDFDX[44*44];
  real_T odeW[44*44];
  int_T odePIVOTS[44];
  real_T odeXTMP[44];
  real_T odeZTMP[44];
  real_T odeMASSMATRIX_M[4];
  ODE14X_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint16_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Continuous states (default storage)
extern X rtX;

// global MassMatrix
extern MassMatrix rtMassMatrix;

// Block signals and states (default storage)
extern DW rtDW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void sh_water_supply_system_initialize(void);
  extern void sh_water_supply_system_step(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Volume (m^3)' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'sh_water_supply_system'
//  '<S1>'   : 'sh_water_supply_system/Pump Station 1'
//  '<S2>'   : 'sh_water_supply_system/Pump Station 2'
//  '<S3>'   : 'sh_water_supply_system/Pump Station 3'
//  '<S4>'   : 'sh_water_supply_system/Solver Configuration'
//  '<S5>'   : 'sh_water_supply_system/Volume T1'
//  '<S6>'   : 'sh_water_supply_system/Volume T2'
//  '<S7>'   : 'sh_water_supply_system/Volume T3'
//  '<S8>'   : 'sh_water_supply_system/Volume T4'
//  '<S9>'   : 'sh_water_supply_system/Pump Station 1/Simulink-PS Converter'
//  '<S10>'  : 'sh_water_supply_system/Pump Station 1/Simulink-PS Converter1'
//  '<S11>'  : 'sh_water_supply_system/Pump Station 1/Simulink-PS Converter/EVAL_KEY'
//  '<S12>'  : 'sh_water_supply_system/Pump Station 1/Simulink-PS Converter1/EVAL_KEY'
//  '<S13>'  : 'sh_water_supply_system/Pump Station 2/Simulink-PS Converter'
//  '<S14>'  : 'sh_water_supply_system/Pump Station 2/Simulink-PS Converter1'
//  '<S15>'  : 'sh_water_supply_system/Pump Station 2/Simulink-PS Converter/EVAL_KEY'
//  '<S16>'  : 'sh_water_supply_system/Pump Station 2/Simulink-PS Converter1/EVAL_KEY'
//  '<S17>'  : 'sh_water_supply_system/Pump Station 3/Simulink-PS Converter'
//  '<S18>'  : 'sh_water_supply_system/Pump Station 3/Simulink-PS Converter1'
//  '<S19>'  : 'sh_water_supply_system/Pump Station 3/Simulink-PS Converter/EVAL_KEY'
//  '<S20>'  : 'sh_water_supply_system/Pump Station 3/Simulink-PS Converter1/EVAL_KEY'
//  '<S21>'  : 'sh_water_supply_system/Solver Configuration/EVAL_KEY'
//  '<S22>'  : 'sh_water_supply_system/Volume T1/PS-Simulink Converter1'
//  '<S23>'  : 'sh_water_supply_system/Volume T1/PS-Simulink Converter1/EVAL_KEY'
//  '<S24>'  : 'sh_water_supply_system/Volume T2/PS-Simulink Converter1'
//  '<S25>'  : 'sh_water_supply_system/Volume T2/PS-Simulink Converter1/EVAL_KEY'
//  '<S26>'  : 'sh_water_supply_system/Volume T3/PS-Simulink Converter1'
//  '<S27>'  : 'sh_water_supply_system/Volume T3/PS-Simulink Converter1/EVAL_KEY'
//  '<S28>'  : 'sh_water_supply_system/Volume T4/PS-Simulink Converter1'
//  '<S29>'  : 'sh_water_supply_system/Volume T4/PS-Simulink Converter1/EVAL_KEY'

#endif                                 // RTW_HEADER_sh_water_supply_system_h_

//
// File trailer for generated code.
//
// [EOF]
//
