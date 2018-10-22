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
 * File: TPMCC_MCLV2_dsPIC33EP256MC506_V0_1.c
 *
 * Code generated for Simulink model 'TPMCC_MCLV2_dsPIC33EP256MC506_V0_1'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Oct 22 11:17:48 2018
 */

#include "TPMCC_MCLV2_dsPIC33EP256MC506_V0_1.h"
#include "TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_private.h"

/* Block signals and states (auto storage) */
DW_TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_T TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW;

/* Real-time model */
RT_MODEL_TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_T
  TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_M_;
RT_MODEL_TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_T *const
  TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_M = &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_M_;

/* Model step function for TID0 */
void TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  /* S-Function (MCHP_QEI): '<S3>/QEI1' */
  TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1CH1 = POS1CNTL;/* POS1CNTH is not taken into account (16 bits output) */
  TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1CH2 = VEL1CNT;/* Velocity Counter (Register is Reset when read) */
}

/* Model step function for TID1 */
void TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_Compare_b;
  uint16_T rtb_Sum;
  int16_T tmp;

  /* Saturate: '<S16>/Saturation1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  if (reference > 24) {
    tmp = 24;
  } else if (reference < -24) {
    tmp = -24;
  } else {
    tmp = reference;
  }

  /* End of Saturate: '<S16>/Saturation1' */

  /* Gain: '<S18>/Gain' incorporates:
   *  Bias: '<S18>/Bias'
   *  Gain: '<S18>/Gain1'
   */
  rtb_Sum = (uint16_T)(((int16_T)(21845L * tmp >> 6) + 8192) * 3199L >> 14);

  /* Saturate: '<S16>/Saturation' */
  if (rtb_Sum < 32U) {
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation = 32U;
  } else {
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Sum = 3199U - rtb_Sum;

  /* Saturate: '<S16>/Saturation2' */
  if (rtb_Sum < 32U) {
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation2 = 32U;
  } else {
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation2 = rtb_Sum;
  }

  /* End of Saturate: '<S16>/Saturation2' */
  /* S-Function (MCHP_UART_Rx): '<S1>/UART Rx' */

  /* MCHP_UART_Rx Block for UARTRef 1: <S1>/UART Rx/Outputs */
  {
    unsigned int n = 0;

    {
      int_T i1;
      uint8_T *y0 = &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1Rx_m[0] ;
      for (i1 = 0; i1 < 100 ; i1++) {
        if (U1STAbits.URXDA == 1) {
          y0[i1] = (uint8_T) U1RXREG;  /* Use only the 8 low bytes or RxReg */
          n += 1;
        } else {
          if (U1STAbits.OERR )
            U1STAbits.OERR = 0;        /* Clear UART Rx Overload Error */
          break;
        }
      }

      y0[i1] = 0;                      /* add one trailing 0, Watch out, last value is erased if the output vector is 'full'. */
    }

    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1Rx = n;/* Number of char received */
  }

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Compare_b = (TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1Rx > 0U);

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATDbits.LATD5 = rtb_Compare_b;

  /* Outputs for Enabled SubSystem: '<S1>/Terminal Interface Management' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_Compare_b) {
    /* S-Function (MCHP_C_function_Call): '<S6>/Add every bytes received to the buffer' */
    TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o1 =
      addToBuffer(
                  &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o2
                  [0]
                  , &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1Rx_m[0]
                  , TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.U1Rx
                  );

    /* Outputs for Enabled SubSystem: '<S6>/Clear current line - "ESC" pressed' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    /* RelationalOperator: '<S12>/Compare' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if ((TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o1
         == 2) > 0) {
      /* Outputs for Atomic SubSystem: '<S7>/Clear current line' */

      /* S-Function (MCHP_C_function_Call): '<S15>/C Function Call2' incorporates:
       *  Constant: '<S15>/Constant1'
       */
      sprintf(
              &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.CFunctionCall2[0]
              , TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_ConstP.Constant1_Value
              );

      /* S-Function (MCHP_UART_Tx): '<S15>/UART Tx1' */
      /* MCHP_UART_Tx Block for UARTRef 1: <S15>/UART Tx1/Outputs */
      {
        uint_T Tmp;
        Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
        Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

        {
          uint_T i1 = 0;
          register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
          uint8_T *u0 = &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.CFunctionCall2[0]
            ;
          if (Tmp >= 100) {
            Tmp = 100 ;
          }

          while (i1 < Tmp) {
            if (u0[i1] == 0)
              break;                   /* Stop on first 0 */
            MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
            LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
            i1= i1 + 1;
          }

          MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
        }

        {
          register uint_T LocalHead;
          _U1TXIE = 0;                 /* Disable Interrupt portecting against possible concurrent access */
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
          while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
          {
            U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
            LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
          }

          MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
          if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
          {
            _U1TXIE = 1;               /* Enable Interrupt */
          }
        }
      }

      /* End of Outputs for SubSystem: '<S7>/Clear current line' */
    }

    /* End of RelationalOperator: '<S12>/Compare' */
    /* End of Outputs for SubSystem: '<S6>/Clear current line - "ESC" pressed' */

    /* S-Function (MCHP_C_function_Call): '<S6>/Print the current content of the output buffer' incorporates:
     *  Constant: '<S6>/FormatString '
     */
    sprintf(
            &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Printthecurrentcontentoftheoutputbuffer
            [0]
            , TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_ConstP.FormatString_Value
            ,
            &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o2
            [0]
            );

    /* S-Function (MCHP_UART_Tx): '<S6>/UART Tx' */
    /* MCHP_UART_Tx Block for UARTRef 1: <S6>/UART Tx/Outputs */
    {
      uint_T Tmp;
      Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
      Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

      {
        uint_T i1 = 0;
        register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
        uint8_T *u0 =
          &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Printthecurrentcontentoftheoutputbuffer
          [0] ;
        if (Tmp >= 100) {
          Tmp = 100 ;
        }

        while (i1 < Tmp) {
          if (u0[i1] == 0)
            break;                     /* Stop on first 0 */
          MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
          LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
          i1= i1 + 1;
        }

        MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
      }

      {
        register uint_T LocalHead;
        _U1TXIE = 0;                   /* Disable Interrupt portecting against possible concurrent access */
        _U1TXIF = 0;                   /* Clear Interrupt Flag */
        LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
        while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
        {
          U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
          LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
        }

        MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
        if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
        {
          _U1TXIE = 1;                 /* Enable Interrupt */
        }
      }
    }

    /* S-Function (MCHP_UART_Tx): '<S6>/UART Tx2' incorporates:
     *  Constant: '<S6>/cr lf'
     */
    /* MCHP_UART_Tx Block for UARTRef 1: <S6>/UART Tx2/Outputs */
    {
      uint_T Tmp;
      Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
      Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

      {
        uint_T i1 = 0;
        register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
        uint8_T *u0 = TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_ConstP.pooled4 ;
        if (Tmp >= 2) {
          Tmp = 2 ;
        }

        while (i1 < Tmp) {
          if (u0[i1] == 0)
            break;                     /* Stop on first 0 */
          MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
          LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
          i1= i1 + 1;
        }

        MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
      }

      {
        register uint_T LocalHead;
        _U1TXIE = 0;                   /* Disable Interrupt portecting against possible concurrent access */
        _U1TXIF = 0;                   /* Clear Interrupt Flag */
        LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
        while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
        {
          U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
          LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
        }

        MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
        if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
        {
          _U1TXIE = 1;                 /* Enable Interrupt */
        }
      }
    }

    /* Outputs for Enabled SubSystem: '<S6>/Print help - "help" command' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     */
    if ((TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o1
         == 12) > 0) {
      /* S-Function (MCHP_C_function_Call): '<S13>/Help C Function Call' */
      printHelp(
                &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.HelpCFunctionCall[0]
                );

      /* S-Function (MCHP_UART_Tx): '<S13>/UART Tx2' */
      /* MCHP_UART_Tx Block for UARTRef 1: <S13>/UART Tx2/Outputs */
      {
        uint_T Tmp;
        Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
        Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

        {
          uint_T i1 = 0;
          register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
          uint8_T *u0 =
            &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.HelpCFunctionCall[0] ;
          if (Tmp >= 5000) {
            Tmp = 5000 ;
          }

          while (i1 < Tmp) {
            if (u0[i1] == 0)
              break;                   /* Stop on first 0 */
            MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
            LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
            i1= i1 + 1;
          }

          MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
        }

        {
          register uint_T LocalHead;
          _U1TXIE = 0;                 /* Disable Interrupt portecting against possible concurrent access */
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
          while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
          {
            U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
            LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
          }

          MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
          if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
          {
            _U1TXIE = 1;               /* Enable Interrupt */
          }
        }
      }
    }

    /* End of RelationalOperator: '<S11>/Compare' */
    /* End of Outputs for SubSystem: '<S6>/Print help - "help" command' */

    /* Outputs for Enabled SubSystem: '<S6>/Print ref - "ref" command' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    /* RelationalOperator: '<S10>/Compare' incorporates:
     *  Constant: '<S10>/Constant'
     */
    if ((TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o1
         == 16) > 0) {
      /* S-Function (MCHP_C_function_Call): '<S14>/Print the current content of the output buffer' incorporates:
       *  Constant: '<S14>/Reference_FormatString'
       */
      sprintf(
              &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Printthecurrentcontentoftheoutputbuffer_g
              [0]
              ,
              TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_ConstP.Reference_FormatString_Value
              );

      /* S-Function (MCHP_UART_Tx): '<S14>/UART Tx' */
      /* MCHP_UART_Tx Block for UARTRef 1: <S14>/UART Tx/Outputs */
      {
        uint_T Tmp;
        Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
        Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

        {
          uint_T i1 = 0;
          register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
          uint8_T *u0 =
            &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Printthecurrentcontentoftheoutputbuffer_g
            [0] ;
          if (Tmp >= 100) {
            Tmp = 100 ;
          }

          while (i1 < Tmp) {
            if (u0[i1] == 0)
              break;                   /* Stop on first 0 */
            MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
            LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
            i1= i1 + 1;
          }

          MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
        }

        {
          register uint_T LocalHead;
          _U1TXIE = 0;                 /* Disable Interrupt portecting against possible concurrent access */
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
          while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
          {
            U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
            LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
          }

          MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
          if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
          {
            _U1TXIE = 1;               /* Enable Interrupt */
          }
        }
      }

      /* S-Function (MCHP_UART_Tx): '<S14>/UART Tx2' incorporates:
       *  Constant: '<S14>/cr lf'
       */
      /* MCHP_UART_Tx Block for UARTRef 1: <S14>/UART Tx2/Outputs */
      {
        uint_T Tmp;
        Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
        Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

        {
          uint_T i1 = 0;
          register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
          uint8_T *u0 = TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_ConstP.pooled4 ;
          if (Tmp >= 2) {
            Tmp = 2 ;
          }

          while (i1 < Tmp) {
            if (u0[i1] == 0)
              break;                   /* Stop on first 0 */
            MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
            LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
            i1= i1 + 1;
          }

          MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
        }

        {
          register uint_T LocalHead;
          _U1TXIE = 0;                 /* Disable Interrupt portecting against possible concurrent access */
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
          while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
          {
            U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
            LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
          }

          MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
          if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
          {
            _U1TXIE = 1;               /* Enable Interrupt */
          }
        }
      }
    }

    /* End of RelationalOperator: '<S10>/Compare' */
    /* End of Outputs for SubSystem: '<S6>/Print ref - "ref" command' */

    /* Outputs for Enabled SubSystem: '<S6>/Clear terminal - "clear" command' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    /* RelationalOperator: '<S9>/Compare' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if ((TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Addeverybytesreceivedtothebuffer_o1
         == 11) > 0) {
      /* SignalConversion: '<S8>/TmpSignal ConversionAtUART Tx1 Send allInport1' incorporates:
       *  Constant: '<S8>/termination'
       */
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [0] = 27U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [1] = 91U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [2] = 50U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [3] = 74U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [4] = 27U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [5] = 91U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [6] = 72U;
      TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
        [7] = 0U;

      /* S-Function (MCHP_UART_Tx): '<S8>/UART Tx1 Send all' */
      /* MCHP_UART_Tx Block for UARTRef 1: <S8>/UART Tx1 Send all/Outputs */
      {
        uint_T Tmp;
        Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
        Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */

        {
          uint_T i1 = 0;
          register uint_T LocalTail = MCHP_UART1_Tx.tail;/* Tail is a volatile variable. Use local variable to speed-up execution */
          uint8_T *u0 =
            &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.TmpSignalConversionAtUARTTx1SendallInport1
            [0] ;
          if (Tmp >= 8) {
            Tmp = 8 ;
          }

          while (i1 < Tmp) {
            MCHP_UART1_Tx.buffer[LocalTail] = u0[i1];
            LocalTail = (LocalTail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
            i1= i1 + 1;
          }

          MCHP_UART1_Tx.tail = LocalTail;/* Push back volatile variable */
        }

        {
          register uint_T LocalHead;
          _U1TXIE = 0;                 /* Disable Interrupt portecting against possible concurrent access */
          _U1TXIF = 0;                 /* Clear Interrupt Flag */
          LocalHead = MCHP_UART1_Tx.head;/* Head is a volatile variable. Use local variable to speed-up execution */
          while ((0U == U1STAbits.UTXBF) && (MCHP_UART1_Tx.tail != LocalHead) )/* while UxTXREG buffer is not full */
          {
            U1TXREG = MCHP_UART1_Tx.buffer[LocalHead];
            LocalHead = (LocalHead + 1) & (Tx_BUFF_SIZE_Uart1-1);
          }

          MCHP_UART1_Tx.head = LocalHead;/* Push back volatile variable */
          if (MCHP_UART1_Tx.tail != LocalHead)/* If remaining values to send present in the circular buffer */
          {
            _U1TXIE = 1;               /* Enable Interrupt */
          }
        }
      }
    }

    /* End of RelationalOperator: '<S9>/Compare' */
    /* End of Outputs for SubSystem: '<S6>/Clear terminal - "clear" command' */
  }

  /* End of Outputs for SubSystem: '<S1>/Terminal Interface Management' */

  /* Update for S-Function (MCHP_PWM_HighSpeed): '<S16>/PWM High Speed' */
  PDC1 = TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation;/* duty cycle for Channel 1 */
  PDC2 = TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW.Saturation2;/* duty cycle for Channel 2 */
}

/* Model initialize function */
void TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *) &TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_DW, 0,
                sizeof(DW_TPMCC_MCLV2_dsPIC33EP256MC506_V0_1_T));

  /* Start for S-Function (MCHP_PWM_HighSpeed): '<S16>/PWM High Speed' */

  /* Set PWM Period on Primary Time Base */
  PHASE1 = 3199;                       /* periode for channel 1 */
  PHASE2 = 3199;                       /* periode for channel 2 */
  PDC1 = 1599;
  PDC2 = 31999;
  ALTDTR1 = 63;
  ALTDTR2 = 63;
  IOCON1 = 0xC000;
  IOCON2 = 0xC000;
  IOCON3 = 0x00;
  FCLCON1 = 0x03;
  FCLCON2 = 0x03;
  PTPER = 6399;
  SEVTCMP = 6398;
  PWMCON1 = 0x0204;
  PWMCON2 = 0x0204;
  PTCON2 = 0x00;                       /* PWM Clock Divider Selection */

  /* Start for S-Function (MCHP_QEI): '<S3>/QEI1' */

  /* Initialize QEI 1 Peripheral */
  QEI1LECH = 0x00;                     /* Lower bound (High)*/
  QEI1LECL = 0x00;                     /* Lower bound (Low)*/
  QEI1GECH = 0x00;                     /* Upper bound (High)*/
  QEI1GECL = 0x03E7;                   /* Upper bound (Low)*/
  QEI1IOC = 0x00;
  QEI1CON = 0x9800;

  /* Start for S-Function (MCHP_Master): '<S2>/Microchip Master' */

  /* S-Function "Microchip MASTER" initialization Block: <S2>/Microchip Master */

  /* Start for S-Function (MCHP_UART_Config): '<S2>/UART Configuration1' */

  /* MCHP_UART_Config Block for UART 1: <S2>/UART Configuration1/Initialize */
  /* Initialisation sequence for UART 1 */
  {
    const uint8_T InitSequence[11] = { 73, 110, 105, 116, 32, 100, 111, 110, 101,
      10, 13 };

    U1BRG = 0x8A;                      /* Baud rate: 115200 (-0.08%) */
    U1MODE = 0x8008;
    U1STA = 0x8400;
    __delay32(1667);                   /* Wait for 1667 cycles */

    {
      uint_T i1;
      for (i1 = 0; i1 < 11 ; i1++) {
        while (U1STAbits.UTXBF == 1) ; /* Wait for one empty space within buffer UART */
        U1TXREG = InitSequence[i1];
      }
    }

    while (U1STAbits.TRMT == 0) ;      /* Wait for all value to be sent */
    U1MODE = 0;                        /* Then switch off UART */
  }

  U1BRG = 0x8A;                        /* Baud rate: 115200 (-0.08%) */
  U1MODE = 0x8008;
  U1STA = 0x8400;

  /* Configure UART1 Tx Interruption */
  MCHP_UART1_Tx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Tx.tail = 0;
  _U1TXIP = 6;                         /*  Tx Interrupt priority set to 6 */
  _U1TXIF = 0;                         /*  */
  _U1TXIE = 1;                         /* Enable Interrupt */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
