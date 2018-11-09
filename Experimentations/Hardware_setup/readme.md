Simulink model to target a dsPIC MCLV board running a DC motor
=================================================

The model contains blocks to configure **dsPIC peripheral** (PWM, ADC and QEI) to run a **DC motor** with the **MCLV-V2 board** equipped with the **dsPIC-33EP256MC506 PIM** (internal Op-Amp configuration).
Measurements are collected and sent to the computer to be visualized in real-time while the motor is running.

Getting Started
------------------------------

The model [MCLV2_dsPIC33EP256MC506_externalOpAmp_HardwareTest.mdl] ([fig][fig:Model_Hardware_Test_withSampleTime]) is not for simulation (peripheral blocks have no effects for simulation) but for code generation. 
Open the model and push the build button (top right, below the simulink windows menue bar).

![Simulink model to set-up the dsPIC 33EP256MC506 PIM daughter board used on a MCLV-v2 board. Two PWM signals drives a DC motor through a H mosfet structure. One QEI peripheral provides position and speed from an optical encoder. 2 ADC channels provides respectively the board potentiometer position and the current measurement from a shunt resistors. The optical encoder with the QEI Peripheral provides the shaft position and angular speed. Theses measurements are sent through the UART to computer. The picgui interface decode the incomming UART data stream and allows to plot values using a maltab script which is continuously refreshing the graphs.][fig:Model_Hardware_Test_withSampleTime]
*fig: Simulink model to set-up the dsPIC 33EP256MC506 PIM daughter board used on a MCLV-v2 board. Two PWM signals drives a DC motor through a H mosfet structure. One QEI peripheral provides position and speed from an optical encoder. 2 ADC channels provides respectively the board potentiometer position and the current measurement from a shunt resistors. Theses four measurements are sent through the UART to the computer.*

### Quick Start

The build button
1. generates c source code,
1. compiles c code and
1. flash the resulting binary to the MCLV targeted board.

### Hardware requirements

- [MCLV-V2] Motor Control Board
- [PIM dsPIC33EP256MC506] with external Op-Amp
- Programmer ([PICkit 4], [ICD4], [Real-Ice], [PICkit 3], [ICD3], ...)
- DC motor ([Pravalux Brushed DC Motor, 90 W, 24 V dc, 3000 rpm])
- Cable to send data from the MCLV board (Tx) to the PC (Rx) (like a [FTDI cable])

### Software requirements

- Matlab/Simulink
  - Embedded coder (Matlab Coder & Simulink Coder)
  - Fixed point toolbox
- [MPLAB device blocks for Simulink][blockset]
- [MPLAB X IDE][MPLABX] development (required to flash the binary from matlab)
- [XC16][XC16] compiler



Experiment
------------------------------

With the MCLV2 board powered and programmed, rotate the potentiometer to accelerate motor / reverse direction. (middle position is off).
**set the potentiometer in middle (off) position at power on.**

### Data Visualisation with picgui

open picgui interface ([fig][fig:DataVisu]) (>>**picgui** at matlab prompt or double click on the Interface Tx-Maltab block in the model)
- Select host UART port and connect at 115200 
- replace the script within the picgui interface to a call to the maltab script [DataVisu.m] (see figure below)
- push the picgui **start** button to visualize runtime curves showing potentiometer, motor position, motor speed and current measured on shunt resistors.

![The picgui interface decode the incomming UART data stream and plot in real-time received values, here potentiometer, motor speed and current measured. Plot are realized through a maltab script which is continuously refreshing the graphs using newly incomming data. This script can be modified at will providing all the matlab graphical capabilities to customize visualisaiton or perform further anlysis on received data.][fig:DataVisu]
*fig: The picgui interface decode the incomming UART data stream and plot in real-time received values, here potentiometer, motor speed and current measured. Plot are realized through a maltab script which is continuously refreshing the graphs using newly incomming data. This script can be modified at will providing all the matlab graphical capabilities to customize visualisaiton or perform further anlysis on received data in real-time.*

[Back to project presentation][MainProjectPage]


<!---  math test not working on GitHub: $\sqrt(2) + \frac{1}{2^5}$
comment  -->

[fig:Model_Hardware_Test_withSampleTime]: ./Fig/Model_Hardware_Test_withSampleTime.png "Simulink model to generate code for the MCLV-V2 board with a dsPIC PIM to run and log data from a DC motor."
[fig:DataVisu]: ./Fig/DataVisu.png "picgui, custom script and figure that present in real-time potentiometer, motor speed and current measured"

[MainProjectPage]: ./../../readme.md 

[blockset]: https://www.microchip.com/SimulinkBlocks "Blockset for dsPIC and PIC32"
[MPLABX]: https://www.microchip.com/MPLABX "Microchip developpment environment"
[XC16]: https://www.microchip.com/XC16 "Microchip Compiler for dsPIC familly"

[MCLV-V2]: https://www.microchip.com/dsPICDEMMCLV-2DevelopmentBoard866 "Motor Control Board"
[PIM dsPIC33EP256MC506]: https://www.microchip.com/DevelopmentTools/ProductDetails/ma330031 "Daughter board for MCLV motor control board"

[Real-Ice]: https://www.microchip.com/realice "Microchip programmer"
[ICD4]: https://www.microchip.com/icd4 "Microchip programmer" 
[ICD3]: https://www.microchip.com/icd3 "Microchip programmer"
[PICkit 4]: https://www.microchip.com/pickit4 "Microchip programmer"
[PICkit 3]: https://www.microchip.com/pickit3 "Microchip programmer"

[FTDI cable]: https://www.ftdichip.com/Products/Cables/USBTTLSerial.htm "USB TTL Serial Cables"
[Pravalux Brushed DC Motor, 90 W, 24 V dc, 3000 rpm]: https://uk.rs-online.com/web/p/dc-motors/0716200/ "Parvalux Brushed DC Motor, 90 W, 24 V dc, 3000 rpm, 7.93mm Shaft Diameter"

[MCLV2_dsPIC33EP256MC506_externalOpAmp_HardwareTest.mdl]: ./MCLV2_dsPIC33EP256MC506_externalOpAmp_HardwareTest.mdl
[DataVisu.m]: ./DataVisu.m
