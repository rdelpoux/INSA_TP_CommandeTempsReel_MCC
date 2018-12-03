# Hardware Configuration

## Board

### Pinout of the MCLV-V2 with the PIM dsPIC33EP256MC506 with External Op-Amp

The pinout for the MCLV V2 board with the dsPIC33EP256MC506 PIM for Interlnal Op Amp configuration is described in its [Information Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33EP256MC506%20Internal%20Op%20Amp%20PIM%20Infosheet%20Rev%20B.pdf).

The table below provide important pinout information.


| MCLV-V2 Board  |   dsPIC33EP256MC506 (Ext-Op-Amp) |
|:---:|:---:|
| LED1        |   RD6 
| LED2        |   RD5 
||
| SW1         |   RG6
| SW2         |   RC7
||
| UART_Rx     |   RC5
| UART_Tx     |   RF1
||
| PWM1 (L/H)  |   RB15 - RB14
| PWM2 (L/H)  |   RB13 - RB12
| PWM3 (L/H)  |   RB11 - RB10
| MC_FAULT    |   RB4  (FLT32)
||
| HALLA / QEA |   RA8
| HALLB / QEB |   RC6
| HALLC / INDX  |   RF0
| HOME        |   RC10
||
| Pot         |   RE13  (AN13)
| VBUS        |   RA12  (AN10)
| Ia          |   RB2   (C2IN1+)
| Ib          |   RC2   (C3IN1+)
| Ibus / Vbus   |   RB7   (AN14) 
||
| PGC (debug) |   RB6 (PGC2)
| PGD (debug) |   RB5 (PGD2)


### Analog inputs scaling

#### Currents measurements:

All Shunt resistances are **0.025 Ohms**. 

Two shunts measures Ia and Ib on PWM1 and PWM2 (low side). The third shunt measure Ibus which is the current sum of the three PWM (low side) currents.

Op-Amps (Internal or External) with a **gain of 15** boost low voltage measured to higher voltage converted by the dsPIC ADC for signals Ia, Ib and Ibus. (see [fig4 from DS52062B](./Fig/Internal_OpAmp_DS52062B_Fig4.png))

$V_{ADC} = 0.025*15*I_{shunt}$

For the ADC configured for 10 bits right aligned conversion, the raw output represents:

$ADC_{out} = 0.025*15 * \frac{1024}{3.3} * I_{shunt} = 116.36 * I_{shunt}$

The maximum measurable current is +-4.4 A which provides values within [-512 512] range. 

#### Voltage measurement:

A divider with a **gain of 1/15** reduce board DC+ input voltage to a lower voltage (Vbus) to fit within the [0 3.3V] range. 

$V_{BUS} = \frac{1}{15} * DC+$

The DC input range not saturating the ADC input is +- 24.75V.


## Peripheral block for Simulink

Two Push Button **S1** and **S2** states are read using one or two Digital Input blocks. Input voltage is inverted:bBoolean output is 0 when button is pushed ; 1 otherwise.

The two LEDs D1 and D2 are on when their respective pin is set to 1.
- **LED D1** is set using a Digital Output block. It is made to blink at 5Hz proving the program is running on the board. 
- **LED D2** is used as a Busy Flag which is set in the Master block. It provides the MCU load. A scope could be used to visualize the load.

The UART Config block configure the baudrate and the pins Rx-Tx pins. Bauds as high as 2Mb can be used by connecting directly an FTDI cable on the JP4-Rx and JP5-Tx Jumpers. The board Serial connector is limited to 460Kb.

The PWM block configure the PWM1 and PWM2 channels  as center aligned signals, with a fixed Period of 50us, and a dead time of 1us. The FLT32 Fault acrive low fault input force the PWMH to 0, and the PWML to 1 on both channels with automatic recovering when fault signal is released. Duty cycle is set as a block input. The Duty cycle input must be scaled using the variable PWM1max available in the matlab workspace. PWM1max value correspond to the **Max Period** set in the block. The Initial ADC Trigger set at 0 (middle of the center aligned PWM signal) provide an option in the ADC block to get triggered synchronously to the PWM signal.

The Op-Amp 2 is configured using the *Comparator - OpAmps - Volt Ref* block.

The ADC is set for 10 bits conversion which allows parallele sampling on up to 4 input channels. Result is set to be signed and left aligned. Channels AN13 (Potentiometer) and OA2 (Ia) are converted. 
The ADC is triggered by the PWM trigger signal. End of the ADC conversion will trigger the simulink base time step. Thus the time step period is equal to the PWM period ! **User must ensure that the fixed step period in the Simulink Configuration match with the PWM period**.

QEI block decode signal from the quadrature encoder sensor which contains 1000 lines. The position output must roll-over at value 999. Position and speed changes are likely not to change in 50us. The QEI block is likely to execute at a lower rate (40 time slower here at 2ms) than the base time step. 

