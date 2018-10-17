/*
 * ExpeCommandeVitesseMCC_data.c
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

#include "ExpeCommandeVitesseMCC.h"
#include "ExpeCommandeVitesseMCC_private.h"

/* Block parameters (auto storage) */
P_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_P = {
  /*  Variable: Cg
   * Referenced by: '<S41>/Gain2'
   */
  { 0.0, 1.0 },
  0.00080476900149031058,              /* Variable: Fg
                                        * Referenced by: '<S40>/Gain1'
                                        */

  /*  Variable: Gg
   * Referenced by: '<S40>/Gain'
   */
  { -1.1868636363636362, -0.060249552906110289 },

  /*  Variable: Ggi
   * Referenced by:
   *   '<S41>/Gain'
   *   '<S41>/Gain1'
   */
  { -1.1353181818181819, -0.057968032786885254, -0.015363771846633241 },
  3.903999999999999,                   /* Variable: KPi
                                        * Referenced by:
                                        *   '<S12>/Gain'
                                        *   '<S13>/Gain'
                                        */
  0.044262295081967204,                /* Variable: KPw
                                        * Referenced by:
                                        *   '<S15>/Gain'
                                        *   '<S16>/Gain2'
                                        */

  /*  Variable: Kelec
   * Referenced by:
   *   '<S14>/Gain1'
   *   '<S14>/Gain2'
   */
  { 3.903999999999983, -4961.3333333329119 },

  /*  Variable: Kmeca
   * Referenced by:
   *   '<S17>/Gain1'
   *   '<S17>/Gain2'
   */
  { 0.044262295081967183, -0.29806259314455885 },
  0.00078688524590163919,              /* Variable: TIi
                                        * Referenced by:
                                        *   '<S12>/Gain1'
                                        *   '<S13>/Gain1'
                                        */
  0.14850000000000002,                 /* Variable: TIw
                                        * Referenced by:
                                        *   '<S15>/Gain1'
                                        *   '<S16>/Gain1'
                                        */
  5.0E-5,                              /* Variable: TPWM
                                        * Referenced by: '<S20>/tpwm'
                                        */
  24.0,                                /* Variable: Vdc
                                        * Referenced by: '<Root>/Gain'
                                        */
  250.0,                               /* Mask Parameter: MoteurMicroLabBox_Precisioncode
                                        * Referenced by:
                                        *   '<S21>/Gain'
                                        *   '<S21>/Gain2'
                                        */
  3.3394,                              /* Mask Parameter: MoteurMicroLabBox_gain_ia
                                        * Referenced by:
                                        *   '<S30>/Gain_iaL'
                                        *   '<S31>/Gain_iaL'
                                        */
  3.3339,                              /* Mask Parameter: MoteurMicroLabBox_gain_ib
                                        * Referenced by:
                                        *   '<S30>/Gain_ibL'
                                        *   '<S31>/Gain_ibL'
                                        */
  3.3333,                              /* Mask Parameter: MoteurMicroLabBox_gain_ic
                                        * Referenced by:
                                        *   '<S30>/Gain_icL'
                                        *   '<S31>/Gain_icL'
                                        */
  0.0412,                              /* Mask Parameter: MoteurMicroLabBox_offset_ia
                                        * Referenced by:
                                        *   '<S30>/Constant1'
                                        *   '<S31>/Constant1'
                                        */
  0.0252,                              /* Mask Parameter: MoteurMicroLabBox_offset_ib
                                        * Referenced by:
                                        *   '<S30>/Constant2'
                                        *   '<S31>/Constant2'
                                        */
  0.0011,                              /* Mask Parameter: MoteurMicroLabBox_offset_ic
                                        * Referenced by:
                                        *   '<S30>/Constant6'
                                        *   '<S31>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  0.0,                                 /* Computed Parameter: adca1_Y0
                                        * Referenced by: '<S32>/adca1 '
                                        */
  0.0,                                 /* Computed Parameter: adcb1_Y0
                                        * Referenced by: '<S32>/adcb1'
                                        */
  0.0,                                 /* Computed Parameter: adcc3_Y0
                                        * Referenced by: '<S32>/adcc3'
                                        */
  0.0,                                 /* Computed Parameter: adca11_Y0
                                        * Referenced by: '<S32>/adca1 1'
                                        */
  0.0,                                 /* Computed Parameter: adcb2_Y0
                                        * Referenced by: '<S32>/adcb2'
                                        */
  0.0,                                 /* Computed Parameter: adcc1_Y0
                                        * Referenced by: '<S32>/adcc1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/CommandeCourant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/omref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S31>/Gain3'
                                        */
  -50.0,                               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S21>/Transfer Fcn1'
                                        */
  50.0,                                /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S21>/Transfer Fcn1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/CommandeVitesse'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/vref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/iref'
                                        */
  0.0,                                 /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S4>/Merge'
                                        */
  0.0,                                 /* Computed Parameter: Merge_InitialOutput_b
                                        * Referenced by: '<Root>/Merge'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Rate Transition5'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S30>/Gain3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S30>/Gain1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S30>/Gain2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S31>/Gain1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S31>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/pos1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/init enc'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S6>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  0.9,                                 /* Expression: 0.9
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  1,                                   /* Computed Parameter: va1_Value
                                        * Referenced by: '<S21>/va1'
                                        */
  1,                                   /* Computed Parameter: va2_Value
                                        * Referenced by: '<S21>/va2'
                                        */
  0                                    /* Computed Parameter: dSpace_muC_Value
                                        * Referenced by: '<Root>/dSpace_muC'
                                        */
};
