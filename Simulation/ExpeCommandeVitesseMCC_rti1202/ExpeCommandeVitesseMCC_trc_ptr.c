/***************************************************************************

   Source file ExpeCommandeVitesseMCC_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 7.8 (02-May-2017)
   Fri Sep 21 10:40:34 2018

   Copyright 2018, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "ExpeCommandeVitesseMCC_trc_ptr.h"
#include "ExpeCommandeVitesseMCC.h"
#include "ExpeCommandeVitesseMCC_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_ExpeCommandeVitesseMCC_real_T_0 = NULL;
volatile boolean_T *p_0_ExpeCommandeVitesseMCC_boolean_T_1 = NULL;
volatile real_T *p_1_ExpeCommandeVitesseMCC_real_T_0 = NULL;
volatile boolean_T *p_1_ExpeCommandeVitesseMCC_boolean_T_1 = NULL;
volatile real_T *p_2_ExpeCommandeVitesseMCC_real_T_0 = NULL;
volatile int8_T *p_2_ExpeCommandeVitesseMCC_int8_T_1 = NULL;
volatile real_T *p_3_ExpeCommandeVitesseMCC_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_ExpeCommandeVitesseMCC_real_T_0 =
    &ExpeCommandeVitesseMCC_B.RateTransition3;
  p_0_ExpeCommandeVitesseMCC_boolean_T_1 =
    &ExpeCommandeVitesseMCC_B.RelationalOperator;
  p_1_ExpeCommandeVitesseMCC_real_T_0 = &ExpeCommandeVitesseMCC_P.Cg[0];
  p_1_ExpeCommandeVitesseMCC_boolean_T_1 = &ExpeCommandeVitesseMCC_P.va1_Value;
  p_2_ExpeCommandeVitesseMCC_real_T_0 =
    &ExpeCommandeVitesseMCC_DW.RateTransition3_Buffer0;
  p_2_ExpeCommandeVitesseMCC_int8_T_1 =
    &ExpeCommandeVitesseMCC_DW.RateTransition3_write_buf;
  p_3_ExpeCommandeVitesseMCC_real_T_0 =
    &ExpeCommandeVitesseMCC_X.TransferFcn1_CSTATE;
}

void ExpeCommandeVitesseMCC_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
