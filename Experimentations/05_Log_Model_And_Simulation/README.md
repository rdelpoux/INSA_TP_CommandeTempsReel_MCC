# Working with recorded data


## Record data from the motor

record data with UART. use multirate data logging to save bandwidth.
Voltage input and current are logged at 20Khz (50us). Speed from quadrature encoder is logged at 500Hz (2ms).

Script to
- re-sample and hold all data at 20Khz
- save mat file format for direct use in Simulink (from file block)
values are stored as a matrix where the first line is the sample time-stamp, and each added line is one new mux output insimulink.



## Validate / Improve modelisation of the motor using recorded data

With logged data, we feed the motor model with the same voltage input, and compare its output with values from the log. See model file xxx.

In our case, the motor parameters from the constructor fit well with the simulation, however the friction had to be tuned. More important, current recorded shows a high current modulation which is inherent to DC motor construction. The model of the motor was modified to simulate as accurately as possible this modulation.

See end result on model xxx.

## Use recorded data in a feedforward simulation

The log of the current shows current modulation. This sinusoidal modulation frequency reflect the shaft rotation frequency.

The model xxx is a sensorless reconstruction of the motor speed which use the current ripple modulation to resolve the speed of the motor. The recorded current were used as input for the speed estimator simulated. The reconstructed speed is compared against the recorded optical encoder speed.

The same model allows selecting current generated from the simulated motor model. The simulated motor model current ripple simulation can be used by the newly created motor speed algorithm.



<!---  math test not working on GitHub: $\sqrt(2) + \frac{1}{2^5}$
comment  -->

[fig:Model_Hardware_Test_withSampleTime]: ./Fig/Model_Hardware_Test_withSampleTime.png "Simulink Model Model_Hardware_Test_withSampleTime.slx from this repository set-up the dsPIC 33EP256MC506 PIM daughter board used on a MCLV v2 microchip motor control board. Two PWM signals drives a DC motor. One QEI peripheral provides position and speed from an optical encoder. 3 ADC channels provides board potentiometer position and current measurement from two shunt resistors. Peripheral QEI and ADC output values are sent through the UART to the microchip picgui interface for visualisation and data logging."
[fig:DataVisu]: ./Fig/DataVisu.png "picgui, custom script and figure that present in real-time potentiometer, motor speed and current measured"

[MainProjectPage]: ./../../readme.md 

[blockset]: https://www.microchip.com/SimulinkBlocks "Blockset for dsPIC and PIC32 (free)"
[MPLABX]: https://www.microchip.com/MPLABX "Microchip developpment environment (free)"
[XC16]: https://www.microchip.com/XC16 "Microchip Compiler (free with -O1 optimisation)"