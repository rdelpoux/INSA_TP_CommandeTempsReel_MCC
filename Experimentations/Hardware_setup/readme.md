# MCLV2 dsPIC33EP256MC506 with externalOpAmp PIM. Simulink hardware setup model

With the MPLAB blockset from Microchip, setup peripheral blocks for the MCLV2 board to run a DC motor

## Getting Started

Open the model, click on build button to build and download the model on the MCLV2 target board.
![Model_Hardware_Test_withSampleTime.slx](.\Fig\Model_Hardware_Test_withSampleTime.png)

### Prerequisites

Matlab,Simulink, Embedded coder, Fixed point toolbox, MPLAB blocks for microchip targets.
UART Tx connection from MCLV2 board to the host PC.

## test

MCLV2 board powered, open the picgui interface (type picgui at matlab prompt), connect the UART connection with 115200, click start to visualize curves showing potentiometer, motor position and speed and current.

