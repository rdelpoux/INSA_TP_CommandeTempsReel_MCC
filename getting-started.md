# Getting Started

## Getting Started

### Getting Started

#### Hardware requirements:

* [MCLV-V2](https://www.microchip.com/dsPICDEMMCLV-2DevelopmentBoard866) Motor Control Board
* [PIM dsPIC33EP256MC506](https://www.microchip.com/DevelopmentTools/ProductDetails/ma330031) with internal Op-Amp
* Programmer \([PICkit 4](https://www.microchip.com/pickit4), [ICD4](https://www.microchip.com/icd4), [Real-Ice](https://www.microchip.com/realice), [PICkit 3](https://www.microchip.com/pickit3), [ICD3](https://www.microchip.com/icd3), ...\)
* DC motor \([Pravalux Brushed DC Motor, 90 W, 24 V dc, 3000 rpm](https://uk.rs-online.com/web/p/dc-motors/0716200/)\)
* Cable to send data from the MCLV board \(Tx\) to the PC \(Rx\) \(like a [FTDI cable](https://www.ftdichip.com/Products/Cables/USBTTLSerial.htm)\)

#### Software requirements:

* Matlab/Simulink
  * Embedded coder \(Matlab Coder & Simulink Coder\)
  * Fixed point toolbox
* [MPLAB device blocks for Simulink](https://www.microchip.com/SimulinkBlocks)
* [MPLAB X IDE](https://www.microchip.com/MPLABX) development \(required to flash the binary from matlab\)
* [XC16](https://www.microchip.com/XC16) compiler

#### Hardware Configuration

**Pinout of the MCLV-V2 with the PIM dsPIC33EP256MC506 with External Op-Amp**

The pinout for the MCLV V2 board with the dsPIC33EP256MC506 PIM for Interlnal Op Amp configuration is described in its [Information Sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/dsPIC33EP256MC506%20Internal%20Op%20Amp%20PIM%20Infosheet%20Rev%20B.pdf).

The table below provide important pinout information.

| MCLV-V2 Board | dsPIC33EP256MC506 \(Ext-Op-Amp\) |
| :---: | :---: |
| LED1 | RD6 |
| LED2 | RD5 |
|  |  |
| SW1 | RG6 |
| SW2 | RC7 |
|  |  |
| UART\_Rx | RC5 |
| UART\_Tx | RF1 |
|  |  |
| PWM1 \(L/H\) | RB15 - RB14 |
| PWM2 \(L/H\) | RB13 - RB12 |
| PWM3 \(L/H\) | RB11 - RB10 |
| MC\_FAULT | RB4  \(FLT32\) |
|  |  |
| HALLA / QEA | RA8 |
| HALLB / QEB | RC6 |
| HALLC / INDX | RF0 |
| HOME | RC10 |
|  |  |
| Pot | RE13  \(AN13\) |
| VBUS | RA12  \(AN10\) |
| Ia | RB2   \(C2IN1+\) |
| Ib | RC2   \(C3IN1+\) |
| Ibus / Vbus | RB7   \(AN14\) |
|  |  |
| PGC \(debug\) | RB6 \(PGC2\) |
| PGD \(debug\) | RB5 \(PGD2\) |

**Analog inputs scaling**

**Currents measurements:**

All Shunt resistances are **0.025 Ohms**.

Two shunts measures Ia and Ib on PWM1 and PWM2 \(low side\). The third shunt measure Ibus which is the current sum of the three PWM \(low side\) currents.

Op-Amps \(Internal or External\) with a **gain of 15** boost low voltage measured to higher voltage converted by the dsPIC ADC for signals Ia, Ib and Ibus. \(see [fig4 from DS52062B](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/f4be492167956b5449ef4fb184332b885cf5780f/Figures/GettingStarted/Internal_OpAmp_DS52062B_Fig4.png)\)

$$V_{ADC} = 0.025*15*I_{shunt}$$

For the ADC configured for 10 bits right aligned conversion, the raw output represents:

$$ADC_{out} = 0.025*15 * \frac{1024}{3.3}* I_{shunt} = 116.36 * I_{shunt}$$

The maximum measurable current is +-4.4 A which provides values within \[-512 512\] range.

**Voltage measurement:**

A divider with a **gain of 1/15** reduce board DC+ input voltage to a lower voltage \(Vbus\) to fit within the \[0 3.3V\] range.

$$V_{BUS} = \frac{1}{15} * DC+$$

The DC input range not saturating the ADC input is +- 24.75V.

#### Peripheral block for Simulink

Two Push Button **S1** and **S2** states are read using one or two Digital Input blocks. Input voltage is inverted:bBoolean output is 0 when button is pushed ; 1 otherwise.

The two LEDs D1 and D2 are on when their respective pin is set to 1.

* **LED D1** is set using a Digital Output block. It is made to blink at 5Hz proving the program is running on the board. 
* **LED D2** is used as a Busy Flag which is set in the Master block. It provides the MCU load. A scope could be used to visualize the load.

The UART Config block configure the baudrate and the pins Rx-Tx pins. Bauds as high as 2Mb can be used by connecting directly an FTDI cable on the JP4-Rx and JP5-Tx Jumpers. The board Serial connector is limited to 460Kb.

The PWM block configure the PWM1 and PWM2 channels as center aligned signals, with a fixed Period of 50us, and a dead time of 1us. The FLT32 Fault acrive low fault input force the PWMH to 0, and the PWML to 1 on both channels with automatic recovering when fault signal is released. Duty cycle is set as a block input. The Duty cycle input must be scaled using the variable PWM1max available in the matlab workspace. PWM1max value correspond to the **Max Period** set in the block. The Initial ADC Trigger set at 0 \(middle of the center aligned PWM signal\) provide an option in the ADC block to get triggered synchronously to the PWM signal.

The Op-Amp 2 is configured using the _Comparator - OpAmps - Volt Ref_ block.

The ADC is set for 10 bits conversion which allows parallele sampling on up to 4 input channels. Result is set to be signed and left aligned. Channels AN13 \(Potentiometer\) and OA2 \(Ia\) are converted. The ADC is triggered by the PWM trigger signal. End of the ADC conversion will trigger the simulink base time step. Thus the time step period is equal to the PWM period ! **User must ensure that the fixed step period in the Simulink Configuration match with the PWM period**.

QEI block decode signal from the quadrature encoder sensor which contains 1000 lines. The position output must roll-over at value 999. Position and speed changes are likely not to change in 50us. The QEI block is likely to execute at a lower rate \(40 time slower here at 2ms\) than the base time step.

#### Generate code and compile:

The build icon on top right of Simulink model, \(see [fig](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/f4be492167956b5449ef4fb184332b885cf5780f/Figures/GettingStarted/Model_Hardware_Test_withSampleTime.png) above\) do: 1. generates c source code, 2. compiles c code and 3. flash the resulting binary to the MCLV targeted board.

> If programming the board fails \(not powered, not connected,...\), use the **Microchip -&gt; Flash** within the Simulink model menu.

#### Data Visualization with picgui:

Open the picgui interface \([fig](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/f4be492167956b5449ef4fb184332b885cf5780f/Figures/GettingStarted/DataVisu.png)\) \(type **picgui** at matlab prompt or double click on the **Interface Tx-Matlab block** in the model\)

1. Select host UART port and connect at 115200 bauds
2. Replace the default script within the picgui interface to a call the customized matlab script [DataVisu.m](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/f4be492167956b5449ef4fb184332b885cf5780f/DataVisu.m) \(see figure below\)
3. Push the **start** button to visualize runtime curves showing potentiometer, motor position, motor speed and current measured on shunt resistor _apabilities to customize visualization or perform further analysis on received data in real-time._

![fig: The picgui interface decode the incoming UART data stream and plot in real-time received values, here potentiometer, motor speed and current measured. Plots in figure are realized with a matlab script which is continuously refreshing the graphs using incoming data. This script can be modified providing all the matlab capabilities to customize visualization or perform further analysis on received data in real-time.](.gitbook/assets/datavisu.png)

## To do

1. Starting from the empty file to download [here](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/raw/f4be492167956b5449ef4fb184332b885cf5780f/LABMatlabFiles/02_GettingStarted/MCLV2_dsPIC33EP256MC506_base_R2017a.zip)

   , add the configuration blocks

   * Microchip Master
   * Compiler Options 
   * UART Configuration
   * Graphical Interface    
   * Port Info

2. Blink LED D1 at 5hz to verify the configuration
3. Configure the peripherals :
   * Two PWM signals to control the motor DC voltage through an H bridge structure using MOSFET.
   * Two ADC channels providing the respectively the board potentiometer position to impose a reference and the current measurement from a shunt resistor. 
   * QEI peripheral to provide shaft position and speed
   * UART connection to the computer for the data analysis.     
4. With the MCLV2 board powered and programmed, rotate the potentiometer to accelerate motor / reverse direction. **Setting the potentiometer at middle position \(off\) at power on to avoid current surge.**

The model should look like \([fig](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/f4be492167956b5449ef4fb184332b885cf5780f/Figures/GettingStarted/Model_Hardware_Test_withSampleTime.png)\)

![](.gitbook/assets/model_hardware_test_withsampletime%20%281%29.png)

[Solution](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/raw/master/LABMatlabFiles/02_GettingStarted/Correction/Correction2.zip)


