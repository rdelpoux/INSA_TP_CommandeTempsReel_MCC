/*
 * ExpeCommandeVitesseMCC.c
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

#include "ExpeCommandeVitesseMCC_trc_ptr.h"
#include "ExpeCommandeVitesseMCC.h"
#include "ExpeCommandeVitesseMCC_private.h"

/* Block signals (auto storage) */
B_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_B;

/* Continuous states */
X_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_X;

/* Block states (auto storage) */
DW_ExpeCommandeVitesseMCC_T ExpeCommandeVitesseMCC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ExpeCommandeVitesseMC_T ExpeCommandeVitesseMCC_PrevZCX;

/* Real-time model */
RT_MODEL_ExpeCommandeVitesseM_T ExpeCommandeVitesseMCC_M_;
RT_MODEL_ExpeCommandeVitesseM_T *const ExpeCommandeVitesseMCC_M =
  &ExpeCommandeVitesseMCC_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ExpeCommandeVitesseMCC_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for function-call system: '<S28>/Triggered Subsystem' */
void ExpeCom_TriggeredSubsystem_Init(void)
{
  /* SystemInitialize for Outport: '<S32>/adca1 ' */
  ExpeCommandeVitesseMCC_B.SFunction1 = ExpeCommandeVitesseMCC_P.adca1_Y0;

  /* SystemInitialize for Outport: '<S32>/adcb1' */
  ExpeCommandeVitesseMCC_B.SFunction1_b = ExpeCommandeVitesseMCC_P.adcb1_Y0;

  /* SystemInitialize for Outport: '<S32>/adcc3' */
  ExpeCommandeVitesseMCC_B.SFunction1_a = ExpeCommandeVitesseMCC_P.adcc3_Y0;

  /* SystemInitialize for Outport: '<S32>/adca1 1' */
  ExpeCommandeVitesseMCC_B.SFunction1_f = ExpeCommandeVitesseMCC_P.adca11_Y0;

  /* SystemInitialize for Outport: '<S32>/adcb2' */
  ExpeCommandeVitesseMCC_B.SFunction1_k = ExpeCommandeVitesseMCC_P.adcb2_Y0;

  /* SystemInitialize for Outport: '<S32>/adcc1' */
  ExpeCommandeVitesseMCC_B.SFunction1_kc = ExpeCommandeVitesseMCC_P.adcc1_Y0;
}

/* Output and update for function-call system: '<S28>/Triggered Subsystem' */
void ExpeCommande_TriggeredSubsystem(void)
{
  /* user code (Output function Body for TID2) */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 Group:ADC */
  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_18 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_18);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_18);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_19 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_19);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_19);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_20 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_20);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_20);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_21 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_21);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_21);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_22 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_22);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_22);

  /* fire burst- or conversion trigger for analog input channel. Called by ADC C1 block pRTIAdcC1AnalogIn_Ch_23 */
  AdcCl1AnalogIn_setConversSwTrigger(pRTIAdcC1AnalogIn_Ch_23);
  AdcCl1AnalogIn_write(pRTIAdcC1AnalogIn_Ch_23);

  /* S-Function (rti_commonblock): '<S34>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 18 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_18, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_18);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_18, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1);
  }

  /* S-Function (rti_commonblock): '<S35>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 19 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_19, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_19);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_19, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1_b);
  }

  /* S-Function (rti_commonblock): '<S36>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 20 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_20, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_20);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_20, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1_a);
  }

  /* S-Function (rti_commonblock): '<S33>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 21 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_21, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_21);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_21, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1_f);
  }

  /* S-Function (rti_commonblock): '<S37>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 22 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_22, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_22);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_22, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1_k);
  }

  /* S-Function (rti_commonblock): '<S38>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 23 --- */
  {
    UInt32 readStateFlag[] = { 1 };

    /* define variable required for adc cl1 realtime functions */
    UInt32 IsNew = 0;

    /* wait until conversion result is available */
    while (IsNew == 0) {
      AdcCl1AnalogIn_isDataReady(pRTIAdcC1AnalogIn_Ch_23, &IsNew);
    }

    /* read conversion result from hardware */
    AdcCl1AnalogIn_read(pRTIAdcC1AnalogIn_Ch_23);

    /* retrieve conversion result */
    AdcCl1AnalogIn_getSingleValue(pRTIAdcC1AnalogIn_Ch_23, readStateFlag,
      (real_T*) &ExpeCommandeVitesseMCC_B.SFunction1_kc);
  }
}

/* Model output function */
void ExpeCommandeVitesseMCC_output(void)
{
  boolean_T didZcEventOccur;
  int8_T rtAction;
  ZCEventType zcEvent;
  real_T Bias;
  real_T y;
  real_T u2;
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    /* set solver stop time */
    if (!(ExpeCommandeVitesseMCC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ExpeCommandeVitesseMCC_M->solverInfo,
                            ((ExpeCommandeVitesseMCC_M->Timing.clockTickH0 + 1) *
        ExpeCommandeVitesseMCC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ExpeCommandeVitesseMCC_M->solverInfo,
                            ((ExpeCommandeVitesseMCC_M->Timing.clockTick0 + 1) *
        ExpeCommandeVitesseMCC_M->Timing.stepSize0 +
        ExpeCommandeVitesseMCC_M->Timing.clockTickH0 *
        ExpeCommandeVitesseMCC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ExpeCommandeVitesseMCC_M)) {
    ExpeCommandeVitesseMCC_M->Timing.t[0] = rtsiGetT
      (&ExpeCommandeVitesseMCC_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    /* S-Function (rti_commonblock): '<S29>/S-Function1' */

    /* This comment workarounds a code generation problem */

    /* End of Outputs for S-Function (rti_commonblock): '<S29>/S-Function1' */

    /* RateTransition: '<S28>/Rate Transition3' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition3_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition3 =
        ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition3 =
        ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition3' */

    /* Gain: '<S31>/Gain3' */
    ExpeCommandeVitesseMCC_B.Gain3 = ExpeCommandeVitesseMCC_P.Gain3_Gain *
      ExpeCommandeVitesseMCC_B.RateTransition3;

    /* Sum: '<S31>/Add1' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    ExpeCommandeVitesseMCC_B.Add1 = ExpeCommandeVitesseMCC_B.Gain3 +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ia;

    /* Gain: '<S31>/Gain_iaL' */
    ExpeCommandeVitesseMCC_B.Gain_iaL =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ia *
      ExpeCommandeVitesseMCC_B.Add1;

    /* Memory: '<S10>/Memory' */
    ExpeCommandeVitesseMCC_B.Memory =
      ExpeCommandeVitesseMCC_DW.Memory_PreviousInput;

    /* RelationalOperator: '<S10>/Relational Operator' incorporates:
     *  Constant: '<S2>/CommandeCourant'
     */
    ExpeCommandeVitesseMCC_B.RelationalOperator =
      (ExpeCommandeVitesseMCC_P.CommandeCourant_Value !=
       ExpeCommandeVitesseMCC_B.Memory);

    /* Memory: '<S11>/Memory' */
    ExpeCommandeVitesseMCC_B.Memory_g =
      ExpeCommandeVitesseMCC_DW.Memory_PreviousInput_k;

    /* RelationalOperator: '<S11>/Relational Operator' incorporates:
     *  Constant: '<S2>/CommandeVitesse'
     */
    ExpeCommandeVitesseMCC_B.RelationalOperator_d =
      (ExpeCommandeVitesseMCC_P.CommandeVitesse_Value !=
       ExpeCommandeVitesseMCC_B.Memory_g);

    /* Logic: '<S2>/Logical Operator' */
    ExpeCommandeVitesseMCC_B.LogicalOperator =
      (ExpeCommandeVitesseMCC_B.RelationalOperator ||
       ExpeCommandeVitesseMCC_B.RelationalOperator_d);
  }

  /* TransferFcn: '<S21>/Transfer Fcn1' */
  ExpeCommandeVitesseMCC_B.TransferFcn1 = 0.0;
  ExpeCommandeVitesseMCC_B.TransferFcn1 +=
    ExpeCommandeVitesseMCC_P.TransferFcn1_C *
    ExpeCommandeVitesseMCC_X.TransferFcn1_CSTATE;

  /* SwitchCase: '<S2>/Switch Case2' incorporates:
   *  Constant: '<Root>/iref'
   *  Constant: '<S2>/CommandeVitesse'
   *  Inport: '<S18>/irefconst'
   */
  rtAction = -1;
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    Bias = ExpeCommandeVitesseMCC_P.CommandeVitesse_Value;
    if (Bias < 0.0) {
      Bias = ceil(Bias);
    } else {
      Bias = floor(Bias);
    }

    if (rtIsNaN(Bias) || rtIsInf(Bias)) {
      Bias = 0.0;
    } else {
      Bias = fmod(Bias, 4.294967296E+9);
    }

    switch (Bias < 0.0 ? -(int32_T)(uint32_T)-Bias : (int32_T)(uint32_T)Bias) {
     case 0:
      rtAction = 0;
      break;

     case 1:
      rtAction = 1;
      break;

     case 2:
      rtAction = 2;
      break;

     case 3:
      rtAction = 3;
      break;
    }

    ExpeCommandeVitesseMCC_DW.SwitchCase2_ActiveSubsystem = rtAction;
  } else {
    rtAction = ExpeCommandeVitesseMCC_DW.SwitchCase2_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S4>/PI1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      ExpeCommandeVitesseMCC_B.Merge = ExpeCommandeVitesseMCC_P.iref_Value;
    }

    /* End of Outputs for SubSystem: '<S4>/PI1' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/PI' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Sum: '<S15>/Sum1' incorporates:
     *  Constant: '<Root>/omref'
     */
    ExpeCommandeVitesseMCC_B.Sum1_c = ExpeCommandeVitesseMCC_P.omref_Value -
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* Integrator: '<S15>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_c
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_c =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE_o =
          ExpeCommandeVitesseMCC_P.Integrator_IC_c;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator_e =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE_o;

    /* End of Integrator: '<S15>/Integrator' */

    /* Gain: '<S15>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.TIw;
    Bias = 1.0 / Bias;
    ExpeCommandeVitesseMCC_B.Gain1_e = Bias *
      ExpeCommandeVitesseMCC_B.Integrator_e;

    /* Sum: '<S15>/Sum' */
    ExpeCommandeVitesseMCC_B.Sum_b = ExpeCommandeVitesseMCC_B.Sum1_c +
      ExpeCommandeVitesseMCC_B.Gain1_e;

    /* Gain: '<S15>/Gain' */
    ExpeCommandeVitesseMCC_B.Merge = ExpeCommandeVitesseMCC_P.KPw *
      ExpeCommandeVitesseMCC_B.Sum_b;

    /* End of Outputs for SubSystem: '<S4>/PI' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S4>/PI Mod' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Integrator: '<S16>/Integrator1' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator1_Reset_ZCE
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator1_Reset_ZCE =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator1_CSTATE =
          ExpeCommandeVitesseMCC_P.Integrator1_IC;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator1 =
      ExpeCommandeVitesseMCC_X.Integrator1_CSTATE;

    /* End of Integrator: '<S16>/Integrator1' */

    /* Gain: '<S16>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.TIw;
    Bias = 1.0 / Bias;
    ExpeCommandeVitesseMCC_B.Gain1_fp = Bias *
      ExpeCommandeVitesseMCC_B.Integrator1;

    /* Sum: '<S16>/Sum' */
    ExpeCommandeVitesseMCC_B.Sum = ExpeCommandeVitesseMCC_B.Gain1_fp -
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* Gain: '<S16>/Gain2' */
    ExpeCommandeVitesseMCC_B.Merge = ExpeCommandeVitesseMCC_P.KPw *
      ExpeCommandeVitesseMCC_B.Sum;

    /* Sum: '<S16>/Sum1' incorporates:
     *  Constant: '<Root>/omref'
     */
    ExpeCommandeVitesseMCC_B.Sum1_a = ExpeCommandeVitesseMCC_P.omref_Value -
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* End of Outputs for SubSystem: '<S4>/PI Mod' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S4>/PI Mod1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Integrator: '<S17>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE !=
                          POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE =
          ExpeCommandeVitesseMCC_P.Integrator_IC_n;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE;

    /* End of Integrator: '<S17>/Integrator' */

    /* Gain: '<S17>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.Kmeca[1];
    ExpeCommandeVitesseMCC_B.Gain1_f = Bias *
      ExpeCommandeVitesseMCC_B.Integrator;

    /* Gain: '<S17>/Gain2' */
    Bias = ExpeCommandeVitesseMCC_P.Kmeca[0];
    ExpeCommandeVitesseMCC_B.Gain2_j = Bias *
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* Sum: '<S17>/Sum' */
    ExpeCommandeVitesseMCC_B.Merge = (0.0 - ExpeCommandeVitesseMCC_B.Gain1_f) -
      ExpeCommandeVitesseMCC_B.Gain2_j;

    /* Sum: '<S17>/Sum1' incorporates:
     *  Constant: '<Root>/omref'
     */
    ExpeCommandeVitesseMCC_B.Sum1 = ExpeCommandeVitesseMCC_P.omref_Value -
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* End of Outputs for SubSystem: '<S4>/PI Mod1' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case2' */

  /* SwitchCase: '<S2>/Switch Case1' incorporates:
   *  Constant: '<Root>/vref'
   *  Constant: '<S2>/CommandeCourant'
   *  Inport: '<S9>/vref'
   */
  rtAction = -1;
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    Bias = ExpeCommandeVitesseMCC_P.CommandeCourant_Value;
    if (Bias < 0.0) {
      Bias = ceil(Bias);
    } else {
      Bias = floor(Bias);
    }

    if (rtIsNaN(Bias) || rtIsInf(Bias)) {
      Bias = 0.0;
    } else {
      Bias = fmod(Bias, 4.294967296E+9);
    }

    switch (Bias < 0.0 ? -(int32_T)(uint32_T)-Bias : (int32_T)(uint32_T)Bias) {
     case 0:
      rtAction = 0;
      break;

     case 1:
      rtAction = 1;
      break;

     case 2:
      rtAction = 2;
      break;

     case 3:
      rtAction = 3;
      break;

     case 4:
      rtAction = 4;
      break;

     case 5:
      rtAction = 5;
      break;
    }

    ExpeCommandeVitesseMCC_DW.SwitchCase1_ActiveSubsystem = rtAction;
  } else {
    rtAction = ExpeCommandeVitesseMCC_DW.SwitchCase1_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/BO' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      ExpeCommandeVitesseMCC_B.Merge_j = ExpeCommandeVitesseMCC_P.vref_Value;
    }

    /* End of Outputs for SubSystem: '<S1>/BO' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/PI' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Sum: '<S12>/Sum1' */
    ExpeCommandeVitesseMCC_B.Sum1_j = ExpeCommandeVitesseMCC_B.Merge -
      ExpeCommandeVitesseMCC_B.Gain_iaL;

    /* Integrator: '<S12>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_i
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_i =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE_l =
          ExpeCommandeVitesseMCC_P.Integrator_IC;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator_eb =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE_l;

    /* End of Integrator: '<S12>/Integrator' */

    /* Gain: '<S12>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.TIi;
    Bias = 1.0 / Bias;
    ExpeCommandeVitesseMCC_B.Gain1_b = Bias *
      ExpeCommandeVitesseMCC_B.Integrator_eb;

    /* Sum: '<S12>/Sum' */
    ExpeCommandeVitesseMCC_B.Sum_c = ExpeCommandeVitesseMCC_B.Sum1_j +
      ExpeCommandeVitesseMCC_B.Gain1_b;

    /* Gain: '<S12>/Gain' */
    ExpeCommandeVitesseMCC_B.Merge_j = ExpeCommandeVitesseMCC_P.KPi *
      ExpeCommandeVitesseMCC_B.Sum_c;

    /* End of Outputs for SubSystem: '<S3>/PI' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/PI Mod' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* Integrator: '<S13>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_a
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_a =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE_e =
          ExpeCommandeVitesseMCC_P.Integrator_IC_g;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator_m3 =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE_e;

    /* End of Integrator: '<S13>/Integrator' */

    /* Gain: '<S13>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.TIi;
    Bias = 1.0 / Bias;
    ExpeCommandeVitesseMCC_B.Gain1_as = Bias *
      ExpeCommandeVitesseMCC_B.Integrator_m3;

    /* Sum: '<S13>/Sum' */
    ExpeCommandeVitesseMCC_B.Sum_m = ExpeCommandeVitesseMCC_B.Gain1_as -
      ExpeCommandeVitesseMCC_B.Gain_iaL;

    /* Gain: '<S13>/Gain' */
    ExpeCommandeVitesseMCC_B.Merge_j = ExpeCommandeVitesseMCC_P.KPi *
      ExpeCommandeVitesseMCC_B.Sum_m;

    /* Sum: '<S13>/Sum1' */
    ExpeCommandeVitesseMCC_B.Sum1_e = ExpeCommandeVitesseMCC_B.Merge -
      ExpeCommandeVitesseMCC_B.Gain_iaL;

    /* End of Outputs for SubSystem: '<S3>/PI Mod' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/PI Mod1' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Integrator: '<S14>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_n
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_n =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE_d =
          ExpeCommandeVitesseMCC_P.Integrator_IC_e;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator_m =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE_d;

    /* End of Integrator: '<S14>/Integrator' */

    /* Gain: '<S14>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.Kelec[1];
    ExpeCommandeVitesseMCC_B.Gain1_h = Bias *
      ExpeCommandeVitesseMCC_B.Integrator_m;

    /* Gain: '<S14>/Gain2' */
    Bias = ExpeCommandeVitesseMCC_P.Kelec[0];
    ExpeCommandeVitesseMCC_B.Gain2_e = Bias * ExpeCommandeVitesseMCC_B.Gain_iaL;

    /* Sum: '<S14>/Sum' */
    ExpeCommandeVitesseMCC_B.Merge_j = (0.0 - ExpeCommandeVitesseMCC_B.Gain1_h)
      - ExpeCommandeVitesseMCC_B.Gain2_e;

    /* Sum: '<S14>/Sum1' */
    ExpeCommandeVitesseMCC_B.Sum1_cq = ExpeCommandeVitesseMCC_B.Merge -
      ExpeCommandeVitesseMCC_B.Gain_iaL;

    /* End of Outputs for SubSystem: '<S3>/PI Mod1' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S7>/ReTotal' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    /* SignalConversion: '<S40>/TmpSignal ConversionAtGainInport1' */
    ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInpo_e[0] =
      ExpeCommandeVitesseMCC_B.Gain_iaL;
    ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInpo_e[1] =
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* Gain: '<S40>/Gain' */
    Bias = ExpeCommandeVitesseMCC_P.Gg[0] *
      ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInpo_e[0];
    Bias += ExpeCommandeVitesseMCC_P.Gg[1] *
      ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInpo_e[1];
    ExpeCommandeVitesseMCC_B.Gain_n = Bias;
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      /* Gain: '<S40>/Gain1' incorporates:
       *  Constant: '<Root>/omref'
       */
      ExpeCommandeVitesseMCC_B.Gain1_g = ExpeCommandeVitesseMCC_P.Fg *
        ExpeCommandeVitesseMCC_P.omref_Value;
    }

    /* Sum: '<S40>/Sum' */
    ExpeCommandeVitesseMCC_B.Merge_j = ExpeCommandeVitesseMCC_B.Gain1_g -
      ExpeCommandeVitesseMCC_B.Gain_n;

    /* End of Outputs for SubSystem: '<S7>/ReTotal' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S7>/ReTotal1' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    /* SignalConversion: '<S41>/TmpSignal ConversionAtGainInport1' */
    ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[0] =
      ExpeCommandeVitesseMCC_B.Gain_iaL;
    ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[1] =
      ExpeCommandeVitesseMCC_B.TransferFcn1;

    /* Gain: '<S41>/Gain' */
    y = ExpeCommandeVitesseMCC_P.Ggi[(int32_T)1.0 - 1];
    Bias = y * ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[0];
    y = ExpeCommandeVitesseMCC_P.Ggi[(int32_T)2.0 - 1];
    Bias += y * ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[1];
    ExpeCommandeVitesseMCC_B.Gain_d = Bias;

    /* Integrator: '<S41>/Integrator' */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      didZcEventOccur = (ExpeCommandeVitesseMCC_B.LogicalOperator &&
                         (ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_p
                          != POS_ZCSIG));
      ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_p =
        ExpeCommandeVitesseMCC_B.LogicalOperator;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ExpeCommandeVitesseMCC_X.Integrator_CSTATE_n =
          ExpeCommandeVitesseMCC_P.Integrator_IC_b;
      }
    }

    ExpeCommandeVitesseMCC_B.Integrator_k =
      ExpeCommandeVitesseMCC_X.Integrator_CSTATE_n;

    /* End of Integrator: '<S41>/Integrator' */

    /* Gain: '<S41>/Gain1' */
    Bias = ExpeCommandeVitesseMCC_P.Ggi[2];
    ExpeCommandeVitesseMCC_B.Gain1_a = Bias *
      ExpeCommandeVitesseMCC_B.Integrator_k;

    /* Gain: '<S41>/Gain2' */
    Bias = ExpeCommandeVitesseMCC_P.Cg[0] *
      ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[0];
    Bias += ExpeCommandeVitesseMCC_P.Cg[1] *
      ExpeCommandeVitesseMCC_B.TmpSignalConversionAtGainInport[1];
    ExpeCommandeVitesseMCC_B.Gain2_h = Bias;

    /* Sum: '<S41>/Sum' */
    ExpeCommandeVitesseMCC_B.Merge_j = (0.0 - ExpeCommandeVitesseMCC_B.Gain1_a)
      - ExpeCommandeVitesseMCC_B.Gain_d;

    /* Sum: '<S41>/Sum1' incorporates:
     *  Constant: '<Root>/omref'
     */
    ExpeCommandeVitesseMCC_B.Sum1_i = ExpeCommandeVitesseMCC_P.omref_Value -
      ExpeCommandeVitesseMCC_B.Gain2_h;

    /* End of Outputs for SubSystem: '<S7>/ReTotal1' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case1' */

  /* Gain: '<Root>/Gain' */
  Bias = ExpeCommandeVitesseMCC_P.Vdc;
  Bias = 1.0 / Bias;
  ExpeCommandeVitesseMCC_B.Gain = Bias * ExpeCommandeVitesseMCC_B.Merge_j;

  /* RateTransition: '<S28>/Rate Transition' */
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    switch (ExpeCommandeVitesseMCC_DW.RateTransition_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition =
        ExpeCommandeVitesseMCC_DW.RateTransition_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition =
        ExpeCommandeVitesseMCC_DW.RateTransition_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition_read_buf = -1;

    /* RateTransition: '<S28>/Rate Transition1' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition1_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition1 =
        ExpeCommandeVitesseMCC_DW.RateTransition1_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition1 =
        ExpeCommandeVitesseMCC_DW.RateTransition1_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition1' */

    /* RateTransition: '<S28>/Rate Transition2' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition2_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition2 =
        ExpeCommandeVitesseMCC_DW.RateTransition2_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition2 =
        ExpeCommandeVitesseMCC_DW.RateTransition2_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition2' */

    /* RateTransition: '<S28>/Rate Transition4' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition4_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition4 =
        ExpeCommandeVitesseMCC_DW.RateTransition4_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition4 =
        ExpeCommandeVitesseMCC_DW.RateTransition4_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition4' */

    /* RateTransition: '<S28>/Rate Transition5' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf =
        ExpeCommandeVitesseMCC_DW.RateTransition5_last_buf_wr;
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf != 0) {
      ExpeCommandeVitesseMCC_B.RateTransition5 =
        ExpeCommandeVitesseMCC_DW.RateTransition5_Buffer1;
    } else {
      ExpeCommandeVitesseMCC_B.RateTransition5 =
        ExpeCommandeVitesseMCC_DW.RateTransition5_Buffer0;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition5' */

    /* Gain: '<S30>/Gain3' */
    ExpeCommandeVitesseMCC_B.Gain3_n = ExpeCommandeVitesseMCC_P.Gain3_Gain_a *
      ExpeCommandeVitesseMCC_B.RateTransition;

    /* Sum: '<S30>/Add1' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    ExpeCommandeVitesseMCC_B.Add1_g = ExpeCommandeVitesseMCC_B.Gain3_n +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ia;

    /* Gain: '<S30>/Gain_iaL' */
    ExpeCommandeVitesseMCC_B.Gain_iaL_o =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ia *
      ExpeCommandeVitesseMCC_B.Add1_g;

    /* Gain: '<S30>/Gain1' */
    ExpeCommandeVitesseMCC_B.Gain1 = ExpeCommandeVitesseMCC_P.Gain1_Gain *
      ExpeCommandeVitesseMCC_B.RateTransition1;

    /* Sum: '<S30>/Add2' incorporates:
     *  Constant: '<S30>/Constant2'
     */
    ExpeCommandeVitesseMCC_B.Add2 = ExpeCommandeVitesseMCC_B.Gain1 +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ib;

    /* Gain: '<S30>/Gain_ibL' */
    ExpeCommandeVitesseMCC_B.Gain_ibL =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ib *
      ExpeCommandeVitesseMCC_B.Add2;

    /* Gain: '<S30>/Gain2' */
    ExpeCommandeVitesseMCC_B.Gain2 = ExpeCommandeVitesseMCC_P.Gain2_Gain *
      ExpeCommandeVitesseMCC_B.RateTransition2;

    /* Sum: '<S30>/Add6' incorporates:
     *  Constant: '<S30>/Constant6'
     */
    ExpeCommandeVitesseMCC_B.Add6 = ExpeCommandeVitesseMCC_B.Gain2 +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ic;

    /* Gain: '<S30>/Gain_icL' */
    ExpeCommandeVitesseMCC_B.Gain_icL =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ic *
      ExpeCommandeVitesseMCC_B.Add6;

    /* Gain: '<S31>/Gain1' */
    ExpeCommandeVitesseMCC_B.Gain1_n = ExpeCommandeVitesseMCC_P.Gain1_Gain_o *
      ExpeCommandeVitesseMCC_B.RateTransition4;

    /* Sum: '<S31>/Add2' incorporates:
     *  Constant: '<S31>/Constant2'
     */
    ExpeCommandeVitesseMCC_B.Add2_o = ExpeCommandeVitesseMCC_B.Gain1_n +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ib;

    /* Gain: '<S31>/Gain_ibL' */
    ExpeCommandeVitesseMCC_B.Gain_ibL_d =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ib *
      ExpeCommandeVitesseMCC_B.Add2_o;

    /* Gain: '<S31>/Gain2' */
    ExpeCommandeVitesseMCC_B.Gain2_f = ExpeCommandeVitesseMCC_P.Gain2_Gain_l *
      ExpeCommandeVitesseMCC_B.RateTransition5;

    /* Sum: '<S31>/Add6' incorporates:
     *  Constant: '<S31>/Constant6'
     */
    ExpeCommandeVitesseMCC_B.Add6_a = ExpeCommandeVitesseMCC_B.Gain2_f +
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_offset_ic;

    /* Gain: '<S31>/Gain_icL' */
    ExpeCommandeVitesseMCC_B.Gain_icL_p =
      ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_gain_ic *
      ExpeCommandeVitesseMCC_B.Add6_a;

    /* S-Function (rti_commonblock): '<S25>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S21>/Gain' */
    Bias = ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_Precisioncode;
    Bias = 6.2831853071795862 / Bias;
    ExpeCommandeVitesseMCC_B.Gain_h = Bias *
      ExpeCommandeVitesseMCC_B.SFunction1_o1;

    /* Gain: '<S21>/Gain2' */
    Bias = ExpeCommandeVitesseMCC_P.MoteurMicroLabBox_Precisioncode;
    Bias = 6.2831853071795862 / Bias;
    ExpeCommandeVitesseMCC_B.Gain2_o = Bias *
      ExpeCommandeVitesseMCC_B.SFunction1_o2;

    /* Outputs for Triggered SubSystem: '<S21>/EMC_ENCODER_POS_SET_BL2' incorporates:
     *  TriggerPort: '<S26>/Trigger'
     */
    if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &ExpeCommandeVitesseMCC_PrevZCX.EMC_ENCODER_POS_SET_BL2_Trig_ZC,
                         (ExpeCommandeVitesseMCC_P.initenc_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S26>/S-Function1' incorporates:
         *  Constant: '<S21>/pos1'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_POS_SET_BL2 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl1EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1,
               (Float64)(ExpeCommandeVitesseMCC_P.pos1_Value * 1)
               );

            /* Set positions state for the selected incremental Encoder to VALID */
            DioCl1EncoderIn_setEncPosValidity
              (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1,
               DIO_ENC_POSITION_VALID
               );

            /* Writes settings for the incremental Encoder */
            DioCl1EncoderIn_write(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S21>/EMC_ENCODER_POS_SET_BL2' */

    /* S-Function (rti_commonblock): '<S23>/S-Function1' incorporates:
     *  Constant: '<Root>/init enc'
     *  Constant: '<S21>/va1'
     */
    /* This comment workarounds a code generation problem */

    /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL1 --- */
    /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 4 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 4-4 on port 2 */
      outputData = ( ( ( (UInt32)ExpeCommandeVitesseMCC_P.va1_Value) << (4 - 1))
                    | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_4, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_4);
    }

    /* S-Function (rti_commonblock): '<S24>/S-Function1' incorporates:
     *  Constant: '<S21>/va2'
     */
    /* This comment workarounds a code generation problem */

    /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL2 --- */
    /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 4 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 4-4 on port 1 */
      outputData = ( ( ( (UInt32)ExpeCommandeVitesseMCC_P.va2_Value) << (4 - 1))
                    | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_4, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_4);
    }
  }

  /* End of RateTransition: '<S28>/Rate Transition' */

  /* Saturate: '<Root>/Saturation' */
  Bias = ExpeCommandeVitesseMCC_B.Gain;
  y = ExpeCommandeVitesseMCC_P.Saturation_LowerSat;
  u2 = ExpeCommandeVitesseMCC_P.Saturation_UpperSat;
  if (Bias > u2) {
    ExpeCommandeVitesseMCC_B.Saturation = u2;
  } else if (Bias < y) {
    ExpeCommandeVitesseMCC_B.Saturation = y;
  } else {
    ExpeCommandeVitesseMCC_B.Saturation = Bias;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    /* S-Function (rti_commonblock): '<S39>/S-Function1' incorporates:
     *  Constant: '<S20>/tpwm'
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     */
    /* This comment workarounds a code generation problem */

    /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM/EMC_MC_PWM_BL1 --- */
    /* --- [RTIEMC, MCPWM] - Port: 3 - Channel: 1 --- */
    {
      /* write Period for the MCPWM output channels 1-6 on port 3 */
      DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_3_Ch_1, (real_T)
        ExpeCommandeVitesseMCC_P.TPWM);

      {
        dsfloat tempBuf[6];
        tempBuf[0] = (dsfloat) ExpeCommandeVitesseMCC_P.Constant_Value[0];
        tempBuf[1] = (dsfloat) ExpeCommandeVitesseMCC_P.Constant_Value[1];
        tempBuf[2] = (dsfloat) ExpeCommandeVitesseMCC_P.Constant_Value[2];
        tempBuf[3] = (dsfloat) ExpeCommandeVitesseMCC_B.Saturation;
        tempBuf[4] = (dsfloat) ExpeCommandeVitesseMCC_P.Constant1_Value;
        tempBuf[5] = (dsfloat) ExpeCommandeVitesseMCC_P.Constant1_Value;

        /* write DutyCycle for the MCPWM output channels 1-6 on port 3 */
        DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_3_Ch_1, tempBuf);
      }

      DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_3_Ch_1);
    }

    /* S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
     *  Constant: '<Root>/dSpace_muC'
     */
    /* This comment workarounds a code generation problem */

    /* --- ExpeCommandeVitesseMCC/DIO_CLASS1_BIT_OUT_BL1 --- */
    /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 16 --- */
    {
      /* define variables required for BitOut realtime functions */
      UInt32 outputData = 0;

      /* write output state value to digital output channel 16-16 on port 1 */
      outputData = ( ( ( (UInt32)ExpeCommandeVitesseMCC_P.dSpace_muC_Value) <<
                      (16 - 1)) | outputData);
      DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_16, outputData);
      DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_16);
    }
  }
}

/* Model update function */
void ExpeCommandeVitesseMCC_update(void)
{
  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    /* Update for Memory: '<S10>/Memory' incorporates:
     *  Constant: '<S2>/CommandeCourant'
     */
    ExpeCommandeVitesseMCC_DW.Memory_PreviousInput =
      ExpeCommandeVitesseMCC_P.CommandeCourant_Value;

    /* Update for Memory: '<S11>/Memory' incorporates:
     *  Constant: '<S2>/CommandeVitesse'
     */
    ExpeCommandeVitesseMCC_DW.Memory_PreviousInput_k =
      ExpeCommandeVitesseMCC_P.CommandeVitesse_Value;
  }

  if (rtmIsMajorTimeStep(ExpeCommandeVitesseMCC_M)) {
    rt_ertODEUpdateContinuousStates(&ExpeCommandeVitesseMCC_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ExpeCommandeVitesseMCC_M->Timing.clockTick0)) {
    ++ExpeCommandeVitesseMCC_M->Timing.clockTickH0;
  }

  ExpeCommandeVitesseMCC_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ExpeCommandeVitesseMCC_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    ExpeCommandeVitesseMCC_M->Timing.clockTick1++;
    if (!ExpeCommandeVitesseMCC_M->Timing.clockTick1) {
      ExpeCommandeVitesseMCC_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void ExpeCommandeVitesseMCC_derivatives(void)
{
  XDot_ExpeCommandeVitesseMCC_T *_rtXdot;
  _rtXdot = ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs);

  /* Derivatives for TransferFcn: '<S21>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += ExpeCommandeVitesseMCC_P.TransferFcn1_A *
    ExpeCommandeVitesseMCC_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += ExpeCommandeVitesseMCC_B.Gain2_o;

  /* Derivatives for SwitchCase: '<S2>/Switch Case2' */
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE_o = 0.0;
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator1_CSTATE = 0.0;
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE = 0.0;
  switch (ExpeCommandeVitesseMCC_DW.SwitchCase2_ActiveSubsystem) {
   case 0:
    break;

   case 1:
    /* Derivatives for IfAction SubSystem: '<S4>/PI' incorporates:
     *  Derivatives for ActionPort: '<S15>/Action Port'
     */
    /* Derivatives for Integrator: '<S15>/Integrator' */
    _rtXdot->Integrator_CSTATE_o = ExpeCommandeVitesseMCC_B.Sum1_c;

    /* End of Derivatives for SubSystem: '<S4>/PI' */
    break;

   case 2:
    /* Derivatives for IfAction SubSystem: '<S4>/PI Mod' incorporates:
     *  Derivatives for ActionPort: '<S16>/Action Port'
     */
    /* Derivatives for Integrator: '<S16>/Integrator1' */
    _rtXdot->Integrator1_CSTATE = ExpeCommandeVitesseMCC_B.Sum1_a;

    /* End of Derivatives for SubSystem: '<S4>/PI Mod' */
    break;

   case 3:
    /* Derivatives for IfAction SubSystem: '<S4>/PI Mod1' incorporates:
     *  Derivatives for ActionPort: '<S17>/Action Port'
     */
    /* Derivatives for Integrator: '<S17>/Integrator' */
    _rtXdot->Integrator_CSTATE = ExpeCommandeVitesseMCC_B.Sum1;

    /* End of Derivatives for SubSystem: '<S4>/PI Mod1' */
    break;
  }

  /* End of Derivatives for SwitchCase: '<S2>/Switch Case2' */

  /* Derivatives for SwitchCase: '<S2>/Switch Case1' */
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE_l = 0.0;
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE_e = 0.0;
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE_d = 0.0;
  ((XDot_ExpeCommandeVitesseMCC_T *) ExpeCommandeVitesseMCC_M->derivs)
    ->Integrator_CSTATE_n = 0.0;
  switch (ExpeCommandeVitesseMCC_DW.SwitchCase1_ActiveSubsystem) {
   case 0:
   case 4:
    break;

   case 1:
    /* Derivatives for IfAction SubSystem: '<S3>/PI' incorporates:
     *  Derivatives for ActionPort: '<S12>/Action Port'
     */
    /* Derivatives for Integrator: '<S12>/Integrator' */
    _rtXdot->Integrator_CSTATE_l = ExpeCommandeVitesseMCC_B.Sum1_j;

    /* End of Derivatives for SubSystem: '<S3>/PI' */
    break;

   case 2:
    /* Derivatives for IfAction SubSystem: '<S3>/PI Mod' incorporates:
     *  Derivatives for ActionPort: '<S13>/Action Port'
     */
    /* Derivatives for Integrator: '<S13>/Integrator' */
    _rtXdot->Integrator_CSTATE_e = ExpeCommandeVitesseMCC_B.Sum1_e;

    /* End of Derivatives for SubSystem: '<S3>/PI Mod' */
    break;

   case 3:
    /* Derivatives for IfAction SubSystem: '<S3>/PI Mod1' incorporates:
     *  Derivatives for ActionPort: '<S14>/Action Port'
     */
    /* Derivatives for Integrator: '<S14>/Integrator' */
    _rtXdot->Integrator_CSTATE_d = ExpeCommandeVitesseMCC_B.Sum1_cq;

    /* End of Derivatives for SubSystem: '<S3>/PI Mod1' */
    break;

   case 5:
    /* Derivatives for IfAction SubSystem: '<S7>/ReTotal1' incorporates:
     *  Derivatives for ActionPort: '<S41>/Action Port'
     */
    /* Derivatives for Integrator: '<S41>/Integrator' */
    _rtXdot->Integrator_CSTATE_n = ExpeCommandeVitesseMCC_B.Sum1_i;

    /* End of Derivatives for SubSystem: '<S7>/ReTotal1' */
    break;
  }

  /* End of Derivatives for SwitchCase: '<S2>/Switch Case1' */
}

/* Model initialize function */
void ExpeCommandeVitesseMCC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ExpeCommandeVitesseMCC_M, 0,
                sizeof(RT_MODEL_ExpeCommandeVitesseM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
                          &ExpeCommandeVitesseMCC_M->Timing.simTimeStep);
    rtsiSetTPtr(&ExpeCommandeVitesseMCC_M->solverInfo, &rtmGetTPtr
                (ExpeCommandeVitesseMCC_M));
    rtsiSetStepSizePtr(&ExpeCommandeVitesseMCC_M->solverInfo,
                       &ExpeCommandeVitesseMCC_M->Timing.stepSize0);
    rtsiSetdXPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
                 &ExpeCommandeVitesseMCC_M->derivs);
    rtsiSetContStatesPtr(&ExpeCommandeVitesseMCC_M->solverInfo, (real_T **)
                         &ExpeCommandeVitesseMCC_M->contStates);
    rtsiSetNumContStatesPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
      &ExpeCommandeVitesseMCC_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
      &ExpeCommandeVitesseMCC_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
      &ExpeCommandeVitesseMCC_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
      &ExpeCommandeVitesseMCC_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
                          (&rtmGetErrorStatus(ExpeCommandeVitesseMCC_M)));
    rtsiSetRTModelPtr(&ExpeCommandeVitesseMCC_M->solverInfo,
                      ExpeCommandeVitesseMCC_M);
  }

  rtsiSetSimTimeStep(&ExpeCommandeVitesseMCC_M->solverInfo, MAJOR_TIME_STEP);
  ExpeCommandeVitesseMCC_M->intgData.f[0] = ExpeCommandeVitesseMCC_M->odeF[0];
  ExpeCommandeVitesseMCC_M->contStates = ((X_ExpeCommandeVitesseMCC_T *)
    &ExpeCommandeVitesseMCC_X);
  rtsiSetSolverData(&ExpeCommandeVitesseMCC_M->solverInfo, (void *)
                    &ExpeCommandeVitesseMCC_M->intgData);
  rtsiSetSolverName(&ExpeCommandeVitesseMCC_M->solverInfo,"ode1");
  rtmSetTPtr(ExpeCommandeVitesseMCC_M, &ExpeCommandeVitesseMCC_M->Timing.tArray
             [0]);
  ExpeCommandeVitesseMCC_M->Timing.stepSize0 = 0.0001;

  /* block I/O */
  (void) memset(((void *) &ExpeCommandeVitesseMCC_B), 0,
                sizeof(B_ExpeCommandeVitesseMCC_T));

  /* states (continuous) */
  {
    (void) memset((void *)&ExpeCommandeVitesseMCC_X, 0,
                  sizeof(X_ExpeCommandeVitesseMCC_T));
  }

  /* states (dwork) */
  (void) memset((void *)&ExpeCommandeVitesseMCC_DW, 0,
                sizeof(DW_ExpeCommandeVitesseMCC_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    ExpeCommandeVitesseMCC_rti_init_trc_pointers();
  }

  /* Start for RateTransition: '<S28>/Rate Transition3' */
  ExpeCommandeVitesseMCC_B.RateTransition3 =
    ExpeCommandeVitesseMCC_P.RateTransition3_X0;

  /* Start for SwitchCase: '<S2>/Switch Case2' */
  ExpeCommandeVitesseMCC_DW.SwitchCase2_ActiveSubsystem = -1;

  /* Start for SwitchCase: '<S2>/Switch Case1' */
  ExpeCommandeVitesseMCC_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for RateTransition: '<S28>/Rate Transition' */
  ExpeCommandeVitesseMCC_B.RateTransition =
    ExpeCommandeVitesseMCC_P.RateTransition_X0;

  /* Start for RateTransition: '<S28>/Rate Transition1' */
  ExpeCommandeVitesseMCC_B.RateTransition1 =
    ExpeCommandeVitesseMCC_P.RateTransition1_X0;

  /* Start for RateTransition: '<S28>/Rate Transition2' */
  ExpeCommandeVitesseMCC_B.RateTransition2 =
    ExpeCommandeVitesseMCC_P.RateTransition2_X0;

  /* Start for RateTransition: '<S28>/Rate Transition4' */
  ExpeCommandeVitesseMCC_B.RateTransition4 =
    ExpeCommandeVitesseMCC_P.RateTransition4_X0;

  /* Start for RateTransition: '<S28>/Rate Transition5' */
  ExpeCommandeVitesseMCC_B.RateTransition5 =
    ExpeCommandeVitesseMCC_P.RateTransition5_X0;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ExpeCommandeVitesseMCC_PrevZCX.EMC_ENCODER_POS_SET_BL2_Trig_ZC =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition3' */
  ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition3_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf = -1;

  /* InitializeConditions for TransferFcn: '<S21>/Transfer Fcn1' */
  ExpeCommandeVitesseMCC_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  ExpeCommandeVitesseMCC_DW.Memory_PreviousInput =
    ExpeCommandeVitesseMCC_P.Memory_X0;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  ExpeCommandeVitesseMCC_DW.Memory_PreviousInput_k =
    ExpeCommandeVitesseMCC_P.Memory_X0_n;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition' */
  ExpeCommandeVitesseMCC_DW.RateTransition_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition_read_buf = -1;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition1' */
  ExpeCommandeVitesseMCC_DW.RateTransition1_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition1_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf = -1;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition2' */
  ExpeCommandeVitesseMCC_DW.RateTransition2_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition2_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf = -1;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition4' */
  ExpeCommandeVitesseMCC_DW.RateTransition4_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition4_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf = -1;

  /* InitializeConditions for RateTransition: '<S28>/Rate Transition5' */
  ExpeCommandeVitesseMCC_DW.RateTransition5_Buffer0 =
    ExpeCommandeVitesseMCC_P.RateTransition5_X0;
  ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf = -1;
  ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf = -1;

  /* SystemInitialize for S-Function (rti_commonblock): '<S29>/S-Function1' incorporates:
   *  SystemInitialize for SubSystem: '<S28>/Triggered Subsystem'
   */
  ExpeCom_TriggeredSubsystem_Init();

  /* End of SystemInitialize for S-Function (rti_commonblock): '<S29>/S-Function1' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/PI' */
  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE_o =
    ExpeCommandeVitesseMCC_P.Integrator_IC_c;

  /* End of SystemInitialize for SubSystem: '<S4>/PI' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/PI Mod' */
  /* InitializeConditions for Integrator: '<S16>/Integrator1' */
  ExpeCommandeVitesseMCC_X.Integrator1_CSTATE =
    ExpeCommandeVitesseMCC_P.Integrator1_IC;

  /* End of SystemInitialize for SubSystem: '<S4>/PI Mod' */

  /* SystemInitialize for IfAction SubSystem: '<S4>/PI Mod1' */
  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE =
    ExpeCommandeVitesseMCC_P.Integrator_IC_n;

  /* End of SystemInitialize for SubSystem: '<S4>/PI Mod1' */

  /* SystemInitialize for Merge: '<S4>/Merge' */
  ExpeCommandeVitesseMCC_B.Merge = ExpeCommandeVitesseMCC_P.Merge_InitialOutput;

  /* SystemInitialize for IfAction SubSystem: '<S3>/PI' */
  /* InitializeConditions for Integrator: '<S12>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE_l =
    ExpeCommandeVitesseMCC_P.Integrator_IC;

  /* End of SystemInitialize for SubSystem: '<S3>/PI' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/PI Mod' */
  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE_e =
    ExpeCommandeVitesseMCC_P.Integrator_IC_g;

  /* End of SystemInitialize for SubSystem: '<S3>/PI Mod' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/PI Mod1' */
  /* InitializeConditions for Integrator: '<S14>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE_d =
    ExpeCommandeVitesseMCC_P.Integrator_IC_e;

  /* End of SystemInitialize for SubSystem: '<S3>/PI Mod1' */

  /* SystemInitialize for IfAction SubSystem: '<S7>/ReTotal1' */
  /* InitializeConditions for Integrator: '<S41>/Integrator' */
  ExpeCommandeVitesseMCC_X.Integrator_CSTATE_n =
    ExpeCommandeVitesseMCC_P.Integrator_IC_b;

  /* End of SystemInitialize for SubSystem: '<S7>/ReTotal1' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  ExpeCommandeVitesseMCC_B.Merge_j =
    ExpeCommandeVitesseMCC_P.Merge_InitialOutput_b;
}

/* Model terminate function */
void ExpeCommandeVitesseMCC_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S25>/S-Function1' */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl1EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);
  }

  /* Terminate for Triggered SubSystem: '<S21>/EMC_ENCODER_POS_SET_BL2' */

  /* Terminate for S-Function (rti_commonblock): '<S26>/S-Function1' incorporates:
   *  Constant: '<S21>/pos1'
   */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_POS_SET_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl1EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl1EncoderIn_write(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<S21>/EMC_ENCODER_POS_SET_BL2' */

  /* Terminate for S-Function (rti_commonblock): '<S23>/S-Function1' incorporates:
   *  Constant: '<S21>/va1'
   */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 4 --- */

  /* disable digital output channel 4-4 on port 2 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_2_Ch_4,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_4);

  /* Terminate for S-Function (rti_commonblock): '<S24>/S-Function1' incorporates:
   *  Constant: '<S21>/va2'
   */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 4 --- */

  /* disable digital output channel 4-4 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_4,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_4);

  /* Terminate for S-Function (rti_commonblock): '<S39>/S-Function1' incorporates:
   *  Constant: '<S20>/tpwm'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 3 - Channel: 1 --- */
  {
    /* disable output channels 1-6 on port 3 (set to high-impedance), when the simulation terminates */
    DioCl1MultiPwmOut_setOutputHighZ(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      DIO_CLASS1_HIGH_Z_ON);

    /* write data to related digital output channels */
    DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_3_Ch_1);
  }

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/dSpace_muC'
   */

  /* --- ExpeCommandeVitesseMCC/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 16 --- */

  /* disable digital output channel 16-16 on port 1 *
   * (set to high-impedance), when the simulation terminates       */
  DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_16,
    DIO_CLASS1_HIGH_Z_ON);
  DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_16);
}
