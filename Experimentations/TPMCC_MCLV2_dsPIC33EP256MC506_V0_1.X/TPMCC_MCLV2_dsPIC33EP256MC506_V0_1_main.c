/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * -------------------------------------------------------------------
 * MPLAB 16-Bit Device Blocks for Simulink v3.38.
 *
 *   Product Page:  http://www.microchip.com/SimulinkBlocks
 *           Forum: http://www.microchip.com/forums/f192.aspx
 *           Wiki:  http://microchip.wikidot.com/simulink:start
 * -------------------------------------------------------------------
 * File: TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_main.c
 *
 * Code generated for Simulink model 'TPMCC_MCLV2_dsPIC33EP256MC506_V0_1'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Oct 22 11:17:48 2018
 */

#define MCHP_isMainFile
#include "TPMCC_MCLV2_dsPIC33EP256MC506_V0_1.h"
#include "TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_private.h"

/* Microchip Global Variables */
/* Set Fuses Options */

#pragma config FNOSC = PRI, PWMLOCK = OFF
#pragma config POSCMD = XT, FCKSM = CSECMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile Overrun;

    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile event;

    static int_T taskCounter[2] = { 0, 0 };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    if (taskCounter[1] == 0) {         /* task dropped on overload */
      event.Flags1 = 1U;
    }

    /* Update task internal counters */
    taskCounter[1]++;
    if (taskCounter[1] == 100) {
      taskCounter[1]= 0;
    }

    /* Step the model for base rate */
    /* Start profiling task 0 */
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_step0();

    /* Get model outputs here */

    /* Stop profiling task 0 */
    if (_T1IF ) {
      _T1IF = 0;                       /* Skip next task0 when Overloaded */
    }

    /* Re-Enable Interrupt. IPL value is 2 at this point */
    _IPL0 = 1;                         /* Re-Enable Scheduler re-entrant interrupt. Lower IPL from 2 to 1 */
    _IPL1 = 0;

    /* Step the model for any subrate */
    /* Handle Task 1 */
    if (Overrun.Flags1) {
      return;                          /* Priority to higher rate steps interrupted */
    }

    if (event.Flags1) {
      Overrun.Flags1 = 1;

      /* Start profiling task 1 */
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_step1();

      /* Get model outputs here */
      ;                                /* Execute task tid 1 */

      /* Stop profiling task 1 */
      event.Flags1 = 0U;
      Overrun.Flags1 = 0U;
    }

    /* Disable Interrupt. IPL value is 1 at this point */
    _IPL1 = 1;                         /* Disable Scheduler Interrupts. Rise IPL from 1 to 2 */
    _IPL0 = 0;
  }
}

int main()
{
  /* Initialize model */
  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    __asm__ volatile("nop\n"
                     "nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 222.0;                      /* configure Oscillator PLL : PLLDIV */
  CLKDIV = 0x05;                       /* configure Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  /* Configure Remappables Pins */
  RPINR14 = 0x3618;
  RPINR18 = 0x35;
  RPOR7 = 0x0100;

  /* Configure Digitals I/O directions */
  TRISD = 0xFFDF;
  TRISF = 0xFFFD;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_initialize();

  /* Configure Timers */
  /* --- TIMER 1 --- This timer is enabled at end of configuration functions. */
  T1CON = 0;                           /* Stop Timer 1 and resets control register */
  _T1IP = 2;                           /* Set timer Interrupt Priority */
  _T1IF = 0;                           /* Reset pending Interrupt */
  _T1IE = 1;                           /* Enable Timer Interrupt. */
  PR1 = 0x18FF;                        /* Period */

  /* Enable Time-step */
  PTCON = 0x8000;                      /* Enable PWM peripheral */
  TMR1 = 0x18FE;
  T1CONbits.TON = 1;                   /* Start timer 1. Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) ;
}                                      /* end of main() */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
