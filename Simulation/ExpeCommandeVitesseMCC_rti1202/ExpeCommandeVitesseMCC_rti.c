/*********************** dSPACE target specific file *************************

   Include file ExpeCommandeVitesseMCC_rti.c:

   Definition of functions and variables for the system I/O and for
   the hardware and software interrupts used.

   RTI1202 7.8 (02-May-2017)
   Fri Sep 21 10:40:34 2018

   Copyright 2018, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

#if !(defined(__RTI_SIMENGINE__) || defined(RTIMP_FRAME))
# error This file may be included only by the RTI(-MP) simulation engine.
#endif

/* Include the model header file. */
#include "ExpeCommandeVitesseMCC.h"
#include "ExpeCommandeVitesseMCC_private.h"

/* Defines for block output and parameter structure existence */
#define RTI_rtB_STRUCTURE_EXISTS       1
#define RTI_rtP_STRUCTURE_EXISTS       1
#define RTB_STRUCTURE_NAME             ExpeCommandeVitesseMCC_B
#define RTP_STRUCTURE_NAME             ExpeCommandeVitesseMCC_P

/* dSPACE generated includes for header files */
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#ifndef dsRtmGetNumSampleTimes
# define dsRtmGetNumSampleTimes(rtm)   3
#endif

#ifndef dsRtmGetTPtr
# define dsRtmGetTPtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef dsRtmSetTaskTime
# define dsRtmSetTaskTime(rtm, sti, val) (dsRtmGetTPtr((rtm))[sti] = (val))
#endif

/****** Definitions: task functions for timer tasks *********************/

/* Timer Task 1. (Base rate). */
static void rti_TIMERA(rtk_p_task_control_block task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  baseRateService(task);

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/****** Definitions: task functions for HW interrupts *******************/

/* HW Interrupt: <S27>/Common Hardware Interrupt Interface */
static void rti_120XDIOCL1MCPWM_BEGIN_OF_PERIODP3Ch1(rtk_p_task_control_block
  task)
{
  /* Task entry code BEGIN */
  /* -- None. -- */
  /* Task entry code END */

  /* Task code. */
  {
    /* S-Function (rti_commonblock): '<S29>/S-Function1' */
    ExpeCommande_TriggeredSubsystem();

    /* End of Outputs for S-Function (rti_commonblock): '<S29>/S-Function1' */

    /* RateTransition: '<S28>/Rate Transition3' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition3_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition3_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1_f;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1_f;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition3_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition3' */

    /* RateTransition: '<S28>/Rate Transition' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition' */

    /* RateTransition: '<S28>/Rate Transition1' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition1_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition1_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition1_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1_b;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition1_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1_b;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition1_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition1_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition1' */

    /* RateTransition: '<S28>/Rate Transition2' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition2_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition2_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition2_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1_a;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition2_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1_a;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition2_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition2_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition2' */

    /* RateTransition: '<S28>/Rate Transition4' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition4_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition4_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition4_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1_k;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition4_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1_k;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition4_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition4_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition4' */

    /* RateTransition: '<S28>/Rate Transition5' */
    switch (ExpeCommandeVitesseMCC_DW.RateTransition5_read_buf) {
     case 0:
      ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf = 1;
      break;

     case 1:
      ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf = 0;
      break;

     default:
      ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf = (int8_T)
        (ExpeCommandeVitesseMCC_DW.RateTransition5_last_buf_wr == 0);
      break;
    }

    if (ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf != 0) {
      ExpeCommandeVitesseMCC_DW.RateTransition5_Buffer1 =
        ExpeCommandeVitesseMCC_B.SFunction1_kc;
    } else {
      ExpeCommandeVitesseMCC_DW.RateTransition5_Buffer0 =
        ExpeCommandeVitesseMCC_B.SFunction1_kc;
    }

    ExpeCommandeVitesseMCC_DW.RateTransition5_last_buf_wr =
      ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf;
    ExpeCommandeVitesseMCC_DW.RateTransition5_write_buf = -1;

    /* End of RateTransition: '<S28>/Rate Transition5' */
  }

  /* Task exit code BEGIN */
  /* -- None. -- */
  /* Task exit code END */
}

/* ===== Declarations of RTI blocks ======================================== */
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_18;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_19;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_20;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_21;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_22;
AdcCl1AnalogInSDrvObject *pRTIAdcC1AnalogIn_Ch_23;
DioCl1EncoderInSDrvObject *pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_2_Ch_4;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_4;
DioCl1MultiPwmOutSDrvObject *pRTIEmcMultiPwmOut_Port_3_Ch_1;
DioCl1DigOutSDrvObject *pRTIDioC1DigOut_Port_1_Ch_16;

/* ===== Definition of interface functions for simulation engine =========== */
#if GRTINTERFACE == 1
#ifdef MULTITASKING
# define dsIsSampleHit(RTM,sti)        rtmGetSampleHitPtr(RTM)[sti]
#else
# define dsIsSampleHit(RTM,sti)        rtmIsSampleHit(RTM,sti,0)
#endif

#else
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

# define dsIsSampleHit(RTM,sti)        rtmStepTask(RTM, sti)
#endif

#undef __INLINE
#if defined(_INLINE)
# define __INLINE                      static inline
#else
# define __INLINE                      static
#endif

/*Define additional variables*/
static time_T dsTFinal = -1.0;

#define dsGetTFinal(rtm)               (dsTFinal)

static time_T dsStepSize = 0.0001;

# define dsGetStepSize(rtm)            (dsStepSize)

static void rti_mdl_initialize_host_services(void)
{
  DsDaq_Init(0, 32, 1);
}

static void rti_mdl_initialize_io_boards(void)
{
  /* Registering of RTI products and modules at VCM */
  {
    vcm_module_register(VCM_MID_RTI1202, (void *) 0,
                        VCM_TXT_RTI1202, 7, 8, 0,
                        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);

    {
      vcm_module_descriptor_type* msg_mod_ptr;
      msg_mod_ptr = vcm_module_register(VCM_MID_MATLAB, (void *) 0,
        VCM_TXT_MATLAB, 9, 2, 0,
        VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_SIMULINK, msg_mod_ptr,
                          VCM_TXT_SIMULINK, 8, 9, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
      vcm_module_register(VCM_MID_RTW, msg_mod_ptr,
                          VCM_TXT_RTW, 8, 12, 0,
                          VCM_VERSION_RELEASE, 0, 0, 0, VCM_CTRL_NO_ST);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 */
  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 18 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_18 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_18,
      ADC_CLASS1_CHANNEL_18);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_18 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_18,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_18,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 19 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_19 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_19,
      ADC_CLASS1_CHANNEL_19);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_19 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_19,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_19,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 20 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_20 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_20,
      ADC_CLASS1_CHANNEL_20);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_20 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_20,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_20,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 21 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_21 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_21,
      ADC_CLASS1_CHANNEL_21);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_21 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_21,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_21,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 22 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_22 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_22,
      ADC_CLASS1_CHANNEL_22);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_22 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_22,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_22,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 23 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Init ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_23 */
    ioErrorCode = AdcCl1AnalogIn_create(&pRTIAdcC1AnalogIn_Ch_23,
      ADC_CLASS1_CHANNEL_23);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Set parameters for ADC CL1 AnalogIn driver object pRTIAdcC1AnalogIn_Ch_23 */
    ioErrorCode = AdcCl1AnalogIn_setConversionMode(pRTIAdcC1AnalogIn_Ch_23,
      ADC_CLASS1_SINGLE_CONV_MODE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_setConversTrigger(pRTIAdcC1AnalogIn_Ch_23,
      ADC_CLASS1_TRIGGER_SW);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 */

  /* dSPACE I/O Board DS120XSTDADCC1 #0 Unit:ADCC1 Group:ADC */
  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL2 --- */
  /* --- [RTI120X, ADC C1] - Channel: 18 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_18 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_18);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_18);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL3 --- */
  /* --- [RTI120X, ADC C1] - Channel: 19 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_19 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_19);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_19);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL4 --- */
  /* --- [RTI120X, ADC C1] - Channel: 20 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_20 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_20);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_20);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL1 --- */
  /* --- [RTI120X, ADC C1] - Channel: 21 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_21 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_21);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_21);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL5 --- */
  /* --- [RTI120X, ADC C1] - Channel: 22 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_22 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_22);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_22);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/Courants/iabc/Triggered Subsystem/ADC_CLASS1_BL6 --- */
  /* --- [RTI120X, ADC C1] - Channel: 23 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* Apply- and Start-Fcn for pRTIAdcC1AnalogIn_Ch_23 */
    ioErrorCode = AdcCl1AnalogIn_apply(pRTIAdcC1AnalogIn_Ch_23);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = AdcCl1AnalogIn_start(pRTIAdcC1AnalogIn_Ch_23);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Create EMC Encoder driver object pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1 */
    ioErrorRetValue = DioCl1EncoderIn_create
      (&pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, DIO_CLASS1_PORT_1,
       DIO_CLASS1_CHANNEL_1, DIO_ENC_INSTANCE_1, DIO_ENC_IUSAGE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* -- Position measurement enabled -- */

    /* Sets number of encoder lines for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setEncoderLines
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, (UInt32) 250.0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets minimum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setMinPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets maximum position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setMaxPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, (Float64) 249.75);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Sets index signal usage mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setIndexMode
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, (Float64)
       DIO_ENC_IMODE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* no user specific minimum encoder velocity used */

    /* Sets gated mode for the selected incremental Encoder */
    ioErrorRetValue = DioCl1EncoderIn_setGatedMode
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, DIO_ENC_GMODE_DISABLED);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorRetValue = DioCl1EncoderIn_setMeasurementInterval
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, 1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Apply all parameter settings. Finalize the construction of the Encoder Obj driver object */
    ioErrorRetValue = DioCl1EncoderIn_apply
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_2_Ch_4 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_2_Ch_4,
      DIO_CLASS1_PORT_2, DIO_CLASS1_MASK_CH_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_2_Ch_4,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 4-4 on port 2 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_4,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_2_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_2_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_4 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_4,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_4,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 4-4 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_4,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 3 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for McPwm initial functions */
    Float64 initValArray[6];

    /* Init EMC MultiPwmOut driver object pRTIEmcMultiPwmOut_Port_3_Ch_1 */
    ioErrorCode = DioCl1MultiPwmOut_create(&pRTIEmcMultiPwmOut_Port_3_Ch_1,
      DIO_CLASS1_PORT_3, DIO_CLASS1_CHANNEL_1, 6);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setInvertingMode
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, DIO_CLASS1_INVERTED);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setSignalVoltage
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setAlignmentMode
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, DIO_PWM_ALIGNMENT_CENTER);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setUpdateMode(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      DIO_PWM_ANY_UPDATE);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setRisingEdgeDelay
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, (Float64) 5.0E-7);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setInterruptMode
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, DIO_CLASS1_INT_BEGIN_PERIOD|
       DIO_CLASS1_INT_MID_PERIOD);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setEventDelay(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      (Float64) 2.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setEventDownsample
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, (UInt32) 1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      (Float64) 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    initValArray[0] = 0.5;
    initValArray[1] = 0.5;
    initValArray[2] = 0.5;
    initValArray[3] = 0.5;
    initValArray[4] = 0.5;
    initValArray[5] = 0.5;
    ioErrorCode = DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      initValArray);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_apply(pRTIEmcMultiPwmOut_Port_3_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_start(pRTIEmcMultiPwmOut_Port_3_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;

    /* Init DIO CL1 DigOut driver object pRTIDioC1DigOut_Port_1_Ch_16 */
    ioErrorCode = DioCl1DigOut_create(&pRTIDioC1DigOut_Port_1_Ch_16,
      DIO_CLASS1_PORT_1, DIO_CLASS1_MASK_CH_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_setSignalVoltage(pRTIDioC1DigOut_Port_1_Ch_16,
      DIO_CLASS1_SIGNAL_5_0_V);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 16-16 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_16,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_apply(pRTIDioC1DigOut_Port_1_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_start(pRTIDioC1DigOut_Port_1_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }
}

/* Function rti_mdl_slave_load() is empty */
#define rti_mdl_slave_load()

/* Function rti_mdl_rtk_initialize() is empty */
#define rti_mdl_rtk_initialize()

static void rti_mdl_initialize_io_units(void)
{
  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorRetValue = IOLIB_NO_ERROR;

    /* Resets start (initial) position for the selected incremental Encoder (in lines) */
    ioErrorRetValue = DioCl1EncoderIn_setEncPosition
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1, (Float64) 0);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* Activate Encoder signals read */
    ioErrorRetValue = DioCl1EncoderIn_start
      (pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);
    if (ioErrorRetValue > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 2 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_2_Ch_4,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 4-4 on port 2 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_2_Ch_4,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_2_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/DIO_CLASS1_BIT_OUT_BL2 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 4 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_4,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (4 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 4-4 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_4,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_4);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/PWM/EMC_MC_PWM_BL1 --- */
  /* --- [RTIEMC, MCPWM] - Port: 3 - Channel: 1 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for McPwm initial functions */
    Float64 initValArray[6];

    /* enable output channels 1-6 on port 3 (always disable state of high-impedance) during initialization */
    ioErrorCode = DioCl1MultiPwmOut_setOutputHighZ
      (pRTIEmcMultiPwmOut_Port_3_Ch_1, DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    /* write initial values of MCPWM Period and DutyCycle for output channel 1-6 on port 3 */
    ioErrorCode = DioCl1MultiPwmOut_setPeriod(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      (Float64) 5.0E-5);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    initValArray[0] = 0.5;
    initValArray[1] = 0.5;
    initValArray[2] = 0.5;
    initValArray[3] = 0.5;
    initValArray[4] = 0.5;
    initValArray[5] = 0.5;
    ioErrorCode = DioCl1MultiPwmOut_setDutyCycle(pRTIEmcMultiPwmOut_Port_3_Ch_1,
      initValArray);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1MultiPwmOut_write(pRTIEmcMultiPwmOut_Port_3_Ch_1);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }

  /* --- ExpeCommandeVitesseMCC/DIO_CLASS1_BIT_OUT_BL1 --- */
  /* --- [RTI120X, BITOUT] - Port: 1 - Channel: 16 --- */
  {
    /* define a variable for IO error handling */
    UInt32 ioErrorCode = IOLIB_NO_ERROR;

    /* define variables required for BitOut initial functions */
    UInt32 outputDataInit = 0;
    ioErrorCode = DioCl1DigOut_setChMaskOutHighZ(pRTIDioC1DigOut_Port_1_Ch_16,
      DIO_CLASS1_HIGH_Z_OFF);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    outputDataInit = ( ( ( (UInt32)0) << (16 - 1)) | outputDataInit);

    /* write initialization value to digital output channel 16-16 on port 1 */
    ioErrorCode = DioCl1DigOut_setChMaskOutData(pRTIDioC1DigOut_Port_1_Ch_16,
      outputDataInit);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }

    ioErrorCode = DioCl1DigOut_write(pRTIDioC1DigOut_Port_1_Ch_16);
    if (ioErrorCode > IOLIB_NO_ERROR) {
      RTLIB_EXIT(1);
    }
  }
}

/* Function rti_mdl_acknowledge_interrupts() is empty */
#define rti_mdl_acknowledge_interrupts()

/* Function rti_mdl_timetables_register() is empty */
#define rti_mdl_timetables_register()

/* Function rti_mdl_timesync_simstate() is empty */
#define rti_mdl_timesync_simstate()

/* Function rti_mdl_timesync_baserate() is empty */
#define rti_mdl_timesync_baserate()

static void rti_mdl_background(void)
{
  /* DsDaq background call */
  DsDaq_Background(0);
}

__INLINE void rti_mdl_sample_input(void)
{
  /* Calls for base sample time: [0.0001, 0] */

  /* --- ExpeCommandeVitesseMCC/Moteur MicroLabBox/Moteur 1/mesures/EMC_ENCODER_BL2 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 1 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* define variables required for encoder sensor realtime functions */
    Float64 positionOrAngle= 0.0, speedOrAngVelocity= 0.0;
    UInt32 isIndexRaised= 0;

    /* Reads complete input data from selected encoder input channels (update data from hardware) */
    DioCl1EncoderIn_read(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1);

    /* Gets encoder position (line) */
    DioCl1EncoderIn_getEncPosition(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1,
      &positionOrAngle);

    /* Gets encoder speed (lines/second) */
    DioCl1EncoderIn_getEncVelocity(pRTIEmcEncoder_Unit_1_DioCl_1_Port_1_Ch1,
      &speedOrAngVelocity);
    ExpeCommandeVitesseMCC_B.SFunction1_o1 = (real_T) positionOrAngle;
    ExpeCommandeVitesseMCC_B.SFunction1_o2 = (real_T) speedOrAngVelocity;
  }
}

static void rti_mdl_daq_service()
{
  /* dSPACE Host Service */
  DsDaq_Service(0, 0, 1, (DsDaqSTimestampStruct *)
                rtk_current_task_absolute_time_ptr_get());
}

#undef __INLINE

/****** [EOF] ****************************************************************/
