/*
 * ExpeCommandeVitesseMCC_private.h
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

#ifndef RTW_HEADER_ExpeCommandeVitesseMCC_private_h_
#define RTW_HEADER_ExpeCommandeVitesseMCC_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ExpeCommandeVitesseMCC.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_18;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_19;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_20;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_21;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_22;
extern AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_23;
extern DioCl1EncoderInSDrvObject *pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_2_Ch_4;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_4;
extern DioCl1MultiPwmOutSDrvObject *pRTIEmcMultiPwmOut_Port_3_Ch_1;
extern DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_16;
extern void ExpeCom_TriggeredSubsystem_Init(void);
extern void ExpeCommande_TriggeredSubsystem(void);

/* private model entry point functions */
extern void ExpeCommandeVitesseMCC_derivatives(void);

#endif                                 /* RTW_HEADER_ExpeCommandeVitesseMCC_private_h_ */
