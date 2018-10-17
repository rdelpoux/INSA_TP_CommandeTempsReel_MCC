/*********************** dSPACE target specific file *************************

   Header file ExpeCommandeVitesseMCC_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.8 (02-May-2017)
   Fri Sep 21 10:40:34 2018

   Copyright 2018, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_ExpeCommandeVitesseMCC_trc_ptr_h_
#define RTI_HEADER_ExpeCommandeVitesseMCC_trc_ptr_h_

/* Include the model header file. */
#include "ExpeCommandeVitesseMCC.h"
#include "ExpeCommandeVitesseMCC_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_ExpeCommandeVitesseMCC_real_T_0;
EXTERN_C volatile boolean_T *p_0_ExpeCommandeVitesseMCC_boolean_T_1;
EXTERN_C volatile real_T *p_1_ExpeCommandeVitesseMCC_real_T_0;
EXTERN_C volatile boolean_T *p_1_ExpeCommandeVitesseMCC_boolean_T_1;
EXTERN_C volatile real_T *p_2_ExpeCommandeVitesseMCC_real_T_0;
EXTERN_C volatile int8_T *p_2_ExpeCommandeVitesseMCC_int8_T_1;
EXTERN_C volatile real_T *p_3_ExpeCommandeVitesseMCC_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void ExpeCommandeVitesseMCC_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_ExpeCommandeVitesseMCC_trc_ptr_h_ */
