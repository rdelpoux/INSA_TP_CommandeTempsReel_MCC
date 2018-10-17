/*
 * ExpeCommandeVitesseMCC.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ExpeCommandeVitesseMCC".
 *
 * Model version              : 1.40
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Fri Sep 21 10:40:34 2018
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ExpeCommandeVitesseMCC_h_
#define RTW_HEADER_ExpeCommandeVitesseMCC_h_
#include <math.h>
#include <string.h>
#ifndef ExpeCommandeVitesseMCC_COMMON_INCLUDES_
# define ExpeCommandeVitesseMCC_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ExpeCommandeVitesseMCC_COMMON_INCLUDES_ */

#include "ExpeCommandeVitesseMCC_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

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

/* Block signals (auto storage) */
typedef struct {
  real_T RateTransition3;              /* '<S28>/Rate Transition3' */
  real_T Gain3;                        /* '<S31>/Gain3' */
  real_T Add1;                         /* '<S31>/Add1' */
  real_T Gain_iaL;                     /* '<S31>/Gain_iaL' */
  real_T TransferFcn1;                 /* '<S21>/Transfer Fcn1' */
  real_T Memory;                       /* '<S10>/Memory' */
  real_T Memory_g;                     /* '<S11>/Memory' */
  real_T Merge;                        /* '<S4>/Merge' */
  real_T Merge_j;                      /* '<Root>/Merge' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T RateTransition;               /* '<S28>/Rate Transition' */
  real_T RateTransition1;              /* '<S28>/Rate Transition1' */
  real_T RateTransition2;              /* '<S28>/Rate Transition2' */
  real_T RateTransition4;              /* '<S28>/Rate Transition4' */
  real_T RateTransition5;              /* '<S28>/Rate Transition5' */
  real_T Gain3_n;                      /* '<S30>/Gain3' */
  real_T Add1_g;                       /* '<S30>/Add1' */
  real_T Gain_iaL_o;                   /* '<S30>/Gain_iaL' */
  real_T Gain1;                        /* '<S30>/Gain1' */
  real_T Add2;                         /* '<S30>/Add2' */
  real_T Gain_ibL;                     /* '<S30>/Gain_ibL' */
  real_T Gain2;                        /* '<S30>/Gain2' */
  real_T Add6;                         /* '<S30>/Add6' */
  real_T Gain_icL;                     /* '<S30>/Gain_icL' */
  real_T Gain1_n;                      /* '<S31>/Gain1' */
  real_T Add2_o;                       /* '<S31>/Add2' */
  real_T Gain_ibL_d;                   /* '<S31>/Gain_ibL' */
  real_T Gain2_f;                      /* '<S31>/Gain2' */
  real_T Add6_a;                       /* '<S31>/Add6' */
  real_T Gain_icL_p;                   /* '<S31>/Gain_icL' */
  real_T SFunction1_o1;                /* '<S25>/S-Function1' */
  real_T SFunction1_o2;                /* '<S25>/S-Function1' */
  real_T Gain_h;                       /* '<S21>/Gain' */
  real_T Gain2_o;                      /* '<S21>/Gain2' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T SFunction1;                   /* '<S34>/S-Function1' */
  real_T SFunction1_b;                 /* '<S35>/S-Function1' */
  real_T SFunction1_a;                 /* '<S36>/S-Function1' */
  real_T SFunction1_f;                 /* '<S33>/S-Function1' */
  real_T SFunction1_k;                 /* '<S37>/S-Function1' */
  real_T SFunction1_kc;                /* '<S38>/S-Function1' */
  real_T Integrator;                   /* '<S17>/Integrator' */
  real_T Gain1_f;                      /* '<S17>/Gain1' */
  real_T Gain2_j;                      /* '<S17>/Gain2' */
  real_T Sum1;                         /* '<S17>/Sum1' */
  real_T Integrator1;                  /* '<S16>/Integrator1' */
  real_T Gain1_fp;                     /* '<S16>/Gain1' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T Sum1_a;                       /* '<S16>/Sum1' */
  real_T Sum1_c;                       /* '<S15>/Sum1' */
  real_T Integrator_e;                 /* '<S15>/Integrator' */
  real_T Gain1_e;                      /* '<S15>/Gain1' */
  real_T Sum_b;                        /* '<S15>/Sum' */
  real_T TmpSignalConversionAtGainInport[2];
  real_T Gain_d;                       /* '<S41>/Gain' */
  real_T Integrator_k;                 /* '<S41>/Integrator' */
  real_T Gain1_a;                      /* '<S41>/Gain1' */
  real_T Gain2_h;                      /* '<S41>/Gain2' */
  real_T Sum1_i;                       /* '<S41>/Sum1' */
  real_T TmpSignalConversionAtGainInpo_e[2];
  real_T Gain_n;                       /* '<S40>/Gain' */
  real_T Gain1_g;                      /* '<S40>/Gain1' */
  real_T Integrator_m;                 /* '<S14>/Integrator' */
  real_T Gain1_h;                      /* '<S14>/Gain1' */
  real_T Gain2_e;                      /* '<S14>/Gain2' */
  real_T Sum1_cq;                      /* '<S14>/Sum1' */
  real_T Integrator_m3;                /* '<S13>/Integrator' */
  real_T Gain1_as;                     /* '<S13>/Gain1' */
  real_T Sum_m;                        /* '<S13>/Sum' */
  real_T Sum1_e;                       /* '<S13>/Sum1' */
  real_T Sum1_j;                       /* '<S12>/Sum1' */
  real_T Integrator_eb;                /* '<S12>/Integrator' */
  real_T Gain1_b;                      /* '<S12>/Gain1' */
  real_T Sum_c;                        /* '<S12>/Sum' */
  boolean_T RelationalOperator;        /* '<S10>/Relational Operator' */
  boolean_T RelationalOperator_d;      /* '<S11>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S2>/Logical Operator' */
} B_ExpeCommandeVitesseMCC_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  volatile real_T RateTransition3_Buffer0;/* '<S28>/Rate Transition3' */
  volatile real_T RateTransition3_Buffer1;/* '<S28>/Rate Transition3' */
  real_T Memory_PreviousInput;         /* '<S10>/Memory' */
  real_T Memory_PreviousInput_k;       /* '<S11>/Memory' */
  volatile real_T RateTransition_Buffer0;/* '<S28>/Rate Transition' */
  volatile real_T RateTransition_Buffer1;/* '<S28>/Rate Transition' */
  volatile real_T RateTransition1_Buffer0;/* '<S28>/Rate Transition1' */
  volatile real_T RateTransition1_Buffer1;/* '<S28>/Rate Transition1' */
  volatile real_T RateTransition2_Buffer0;/* '<S28>/Rate Transition2' */
  volatile real_T RateTransition2_Buffer1;/* '<S28>/Rate Transition2' */
  volatile real_T RateTransition4_Buffer0;/* '<S28>/Rate Transition4' */
  volatile real_T RateTransition4_Buffer1;/* '<S28>/Rate Transition4' */
  volatile real_T RateTransition5_Buffer0;/* '<S28>/Rate Transition5' */
  volatile real_T RateTransition5_Buffer1;/* '<S28>/Rate Transition5' */
  volatile int8_T RateTransition3_write_buf;/* '<S28>/Rate Transition3' */
  volatile int8_T RateTransition3_read_buf;/* '<S28>/Rate Transition3' */
  volatile int8_T RateTransition3_last_buf_wr;/* '<S28>/Rate Transition3' */
  int8_T SwitchCase2_ActiveSubsystem;  /* '<S2>/Switch Case2' */
  int8_T SwitchCase1_ActiveSubsystem;  /* '<S2>/Switch Case1' */
  volatile int8_T RateTransition_write_buf;/* '<S28>/Rate Transition' */
  volatile int8_T RateTransition_read_buf;/* '<S28>/Rate Transition' */
  volatile int8_T RateTransition_last_buf_wr;/* '<S28>/Rate Transition' */
  volatile int8_T RateTransition1_write_buf;/* '<S28>/Rate Transition1' */
  volatile int8_T RateTransition1_read_buf;/* '<S28>/Rate Transition1' */
  volatile int8_T RateTransition1_last_buf_wr;/* '<S28>/Rate Transition1' */
  volatile int8_T RateTransition2_write_buf;/* '<S28>/Rate Transition2' */
  volatile int8_T RateTransition2_read_buf;/* '<S28>/Rate Transition2' */
  volatile int8_T RateTransition2_last_buf_wr;/* '<S28>/Rate Transition2' */
  volatile int8_T RateTransition4_write_buf;/* '<S28>/Rate Transition4' */
  volatile int8_T RateTransition4_read_buf;/* '<S28>/Rate Transition4' */
  volatile int8_T RateTransition4_last_buf_wr;/* '<S28>/Rate Transition4' */
  volatile int8_T RateTransition5_write_buf;/* '<S28>/Rate Transition5' */
  volatile int8_T RateTransition5_read_buf;/* '<S28>/Rate Transition5' */
  volatile int8_T RateTransition5_last_buf_wr;/* '<S28>/Rate Transition5' */
} DW_ExpeCommandeVitesseMCC_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S21>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S17>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S16>/Integrator1' */
  real_T Integrator_CSTATE_o;          /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S41>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S14>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S12>/Integrator' */
} X_ExpeCommandeVitesseMCC_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S21>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S17>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S16>/Integrator1' */
  real_T Integrator_CSTATE_o;          /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S41>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S14>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S12>/Integrator' */
} XDot_ExpeCommandeVitesseMCC_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S21>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S17>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S16>/Integrator1' */
  boolean_T Integrator_CSTATE_o;       /* '<S15>/Integrator' */
  boolean_T Integrator_CSTATE_n;       /* '<S41>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S14>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S13>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S12>/Integrator' */
} XDis_ExpeCommandeVitesseMCC_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState EMC_ENCODER_POS_SET_BL2_Trig_ZC;/* '<S21>/EMC_ENCODER_POS_SET_BL2' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S17>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S16>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE_c;   /* '<S15>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S41>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S14>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_a;   /* '<S13>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S12>/Integrator' */
} PrevZCX_ExpeCommandeVitesseMC_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_ExpeCommandeVitesseMCC_T_ {
  real_T Cg[2];                        /* Variable: Cg
                                        * Referenced by: '<S41>/Gain2'
                                        */
  real_T Fg;                           /* Variable: Fg
                                        * Referenced by: '<S40>/Gain1'
                                        */
  real_T Gg[2];                        /* Variable: Gg
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Ggi[3];                       /* Variable: Ggi
                                        * Referenced by:
                                        *   '<S41>/Gain'
                                        *   '<S41>/Gain1'
                                        */
  real_T KPi;                          /* Variable: KPi
                                        * Referenced by:
                                        *   '<S12>/Gain'
                                        *   '<S13>/Gain'
                                        */
  real_T KPw;                          /* Variable: KPw
                                        * Referenced by:
                                        *   '<S15>/Gain'
                                        *   '<S16>/Gain2'
                                        */
  real_T Kelec[2];                     /* Variable: Kelec
                                        * Referenced by:
                                        *   '<S14>/Gain1'
                                        *   '<S14>/Gain2'
                                        */
  real_T Kmeca[2];                     /* Variable: Kmeca
                                        * Referenced by:
                                        *   '<S17>/Gain1'
                                        *   '<S17>/Gain2'
                                        */
  real_T TIi;                          /* Variable: TIi
                                        * Referenced by:
                                        *   '<S12>/Gain1'
                                        *   '<S13>/Gain1'
                                        */
  real_T TIw;                          /* Variable: TIw
                                        * Referenced by:
                                        *   '<S15>/Gain1'
                                        *   '<S16>/Gain1'
                                        */
  real_T TPWM;                         /* Variable: TPWM
                                        * Referenced by: '<S20>/tpwm'
                                        */
  real_T Vdc;                          /* Variable: Vdc
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T MoteurMicroLabBox_Precisioncode;/* Mask Parameter: MoteurMicroLabBox_Precisioncode
                                          * Referenced by:
                                          *   '<S21>/Gain'
                                          *   '<S21>/Gain2'
                                          */
  real_T MoteurMicroLabBox_gain_ia;    /* Mask Parameter: MoteurMicroLabBox_gain_ia
                                        * Referenced by:
                                        *   '<S30>/Gain_iaL'
                                        *   '<S31>/Gain_iaL'
                                        */
  real_T MoteurMicroLabBox_gain_ib;    /* Mask Parameter: MoteurMicroLabBox_gain_ib
                                        * Referenced by:
                                        *   '<S30>/Gain_ibL'
                                        *   '<S31>/Gain_ibL'
                                        */
  real_T MoteurMicroLabBox_gain_ic;    /* Mask Parameter: MoteurMicroLabBox_gain_ic
                                        * Referenced by:
                                        *   '<S30>/Gain_icL'
                                        *   '<S31>/Gain_icL'
                                        */
  real_T MoteurMicroLabBox_offset_ia;  /* Mask Parameter: MoteurMicroLabBox_offset_ia
                                        * Referenced by:
                                        *   '<S30>/Constant1'
                                        *   '<S31>/Constant1'
                                        */
  real_T MoteurMicroLabBox_offset_ib;  /* Mask Parameter: MoteurMicroLabBox_offset_ib
                                        * Referenced by:
                                        *   '<S30>/Constant2'
                                        *   '<S31>/Constant2'
                                        */
  real_T MoteurMicroLabBox_offset_ic;  /* Mask Parameter: MoteurMicroLabBox_offset_ic
                                        * Referenced by:
                                        *   '<S30>/Constant6'
                                        *   '<S31>/Constant6'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T Integrator_IC_b;              /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S16>/Integrator1'
                                        */
  real_T Integrator_IC_n;              /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  real_T adca1_Y0;                     /* Computed Parameter: adca1_Y0
                                        * Referenced by: '<S32>/adca1 '
                                        */
  real_T adcb1_Y0;                     /* Computed Parameter: adcb1_Y0
                                        * Referenced by: '<S32>/adcb1'
                                        */
  real_T adcc3_Y0;                     /* Computed Parameter: adcc3_Y0
                                        * Referenced by: '<S32>/adcc3'
                                        */
  real_T adca11_Y0;                    /* Computed Parameter: adca11_Y0
                                        * Referenced by: '<S32>/adca1 1'
                                        */
  real_T adcb2_Y0;                     /* Computed Parameter: adcb2_Y0
                                        * Referenced by: '<S32>/adcb2'
                                        */
  real_T adcc1_Y0;                     /* Computed Parameter: adcc1_Y0
                                        * Referenced by: '<S32>/adcc1'
                                        */
  real_T CommandeCourant_Value;        /* Expression: 0
                                        * Referenced by: '<S2>/CommandeCourant'
                                        */
  real_T omref_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/omref'
                                        */
  real_T RateTransition3_X0;           /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 10
                                        * Referenced by: '<S31>/Gain3'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S21>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S21>/Transfer Fcn1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  real_T CommandeVitesse_Value;        /* Expression: 0
                                        * Referenced by: '<S2>/CommandeVitesse'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  real_T vref_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/vref'
                                        */
  real_T iref_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/iref'
                                        */
  real_T Merge_InitialOutput;          /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S4>/Merge'
                                        */
  real_T Merge_InitialOutput_b;        /* Computed Parameter: Merge_InitialOutput_b
                                        * Referenced by: '<Root>/Merge'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition1'
                                        */
  real_T RateTransition2_X0;           /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition2'
                                        */
  real_T RateTransition4_X0;           /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition4'
                                        */
  real_T RateTransition5_X0;           /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition5'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 10
                                        * Referenced by: '<S30>/Gain3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 10
                                        * Referenced by: '<S30>/Gain2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 10
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 10
                                        * Referenced by: '<S31>/Gain2'
                                        */
  real_T pos1_Value;                   /* Expression: 0
                                        * Referenced by: '<S21>/pos1'
                                        */
  real_T initenc_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/init enc'
                                        */
  real_T Constant_Value[3];            /* Expression: [0;0;0]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.9
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  boolean_T va1_Value;                 /* Computed Parameter: va1_Value
                                        * Referenced by: '<S21>/va1'
                                        */
  boolean_T va2_Value;                 /* Computed Parameter: va2_Value
                                        * Referenced by: '<S21>/va2'
                                        */
  boolean_T dSpace_muC_Value;          /* Computed Parameter: dSpace_muC_Value
                                        * Referenced by: '<Root>/dSpace_muC'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ExpeCommandeVitesseMC_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ExpeCommandeVitesseMCC_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeF[1][8];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_P;

/* Block signals (auto storage) */
extern B_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_B;

/* Continuous states (auto storage) */
extern X_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_X;

/* Block states (auto storage) */
extern DW_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_ExpeCommandeVitesseMC_T ExpeCommandeVitesseMCC_PrevZCX;

/* Model entry point functions */
extern void ExpeCommandeVitesseMCC_initialize(void);
extern void ExpeCommandeVitesseMCC_output(void);
extern void ExpeCommandeVitesseMCC_update(void);
extern void ExpeCommandeVitesseMCC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ExpeCommandeVitesseM_T *const ExpeCommandeVitesseMCC_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ExpeCommandeVitesseMCC'
 * '<S1>'   : 'ExpeCommandeVitesseMCC/Boucle ouverte'
 * '<S2>'   : 'ExpeCommandeVitesseMCC/Choix de la commande'
 * '<S3>'   : 'ExpeCommandeVitesseMCC/Commande Courant'
 * '<S4>'   : 'ExpeCommandeVitesseMCC/Commande Vitesse'
 * '<S5>'   : 'ExpeCommandeVitesseMCC/DIO_CLASS1_BIT_OUT_BL1'
 * '<S6>'   : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox'
 * '<S7>'   : 'ExpeCommandeVitesseMCC/RE global'
 * '<S8>'   : 'ExpeCommandeVitesseMCC/RTI Data'
 * '<S9>'   : 'ExpeCommandeVitesseMCC/Boucle ouverte/BO'
 * '<S10>'  : 'ExpeCommandeVitesseMCC/Choix de la commande/Initint'
 * '<S11>'  : 'ExpeCommandeVitesseMCC/Choix de la commande/Initint1'
 * '<S12>'  : 'ExpeCommandeVitesseMCC/Commande Courant/PI'
 * '<S13>'  : 'ExpeCommandeVitesseMCC/Commande Courant/PI Mod'
 * '<S14>'  : 'ExpeCommandeVitesseMCC/Commande Courant/PI Mod1'
 * '<S15>'  : 'ExpeCommandeVitesseMCC/Commande Vitesse/PI'
 * '<S16>'  : 'ExpeCommandeVitesseMCC/Commande Vitesse/PI Mod'
 * '<S17>'  : 'ExpeCommandeVitesseMCC/Commande Vitesse/PI Mod1'
 * '<S18>'  : 'ExpeCommandeVitesseMCC/Commande Vitesse/PI1'
 * '<S19>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1'
 * '<S20>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM'
 * '<S21>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures'
 * '<S22>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants'
 * '<S23>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL1'
 * '<S24>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL2'
 * '<S25>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_BL2'
 * '<S26>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_POS_SET_BL2'
 * '<S27>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/DIO_CLASS1_HWINT_BL1'
 * '<S28>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc'
 * '<S29>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/DIO_CLASS1_HWINT_BL1/Common Hardware Interrupt Interface'
 * '<S30>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/ShuntCalibration'
 * '<S31>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/ShuntCalibration1'
 * '<S32>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem'
 * '<S33>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL1'
 * '<S34>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL2'
 * '<S35>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL3'
 * '<S36>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL4'
 * '<S37>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL5'
 * '<S38>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL6'
 * '<S39>'  : 'ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM/EMC_MC_PWM_BL1'
 * '<S40>'  : 'ExpeCommandeVitesseMCC/RE global/ReTotal'
 * '<S41>'  : 'ExpeCommandeVitesseMCC/RE global/ReTotal1'
 * '<S42>'  : 'ExpeCommandeVitesseMCC/RTI Data/RTI Data Store'
 * '<S43>'  : 'ExpeCommandeVitesseMCC/RTI Data/RTI Data Store/RTI Data Store'
 * '<S44>'  : 'ExpeCommandeVitesseMCC/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_ExpeCommandeVitesseMCC_h_ */
