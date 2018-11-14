# Control loop design



## Control design

Two Proportional Integral (PI) feedback loop are used. The inner PI feedback for current control ; The outer PI feedback for speed control.

The script xxx compute the P and I control gains for each loop.

### Benefits from control loops:

The current control loop provides an inner robustness to power supply variation.  
The speed control loop improve the system dynamics (settling time will be shorter) and will compensate for load variation.

While the speed control loop also compensate for power supply variation, The current control loop compensate for it before any impact of the power supply variation is detectable on the motor speed. 

## Simulation

### without current modulation (from BEMF)
 
 Characteristics, prediction of model efficiency
 
### with current modulation (closer to real system)

Simulation results are slightly degraded, but still working. However the command (voltage applied to the motor) is agitated. Current variation are likely to get even higher and trig the protection mode (fault) which will inevitably degrade the system response. Another possible problem with this noisy command is the current variation requested to the power supply which might get above its capabilities. 

Filtering out the current modulation is difficult: 
- The current modulation frequency is within the same magnitude as the mechanicl system dynamics.
- The current modulation frequency is lower than the electrical system dynamics. 

or
- Low pass filtering the command would slow down the system dynamic. 
- Low pass filtering the current feedback signal would cut off all the dynamics of  the electrical system we want to control.

We use an internal model

### Floating point to Fixed point conversion

Simulation was done using floating point which is convenient to design algorithms.  
The algorithm is converted and simulated using fixed point datatypes.

## Experimentation

With fixed point controller, we just copy the controller and generate code for it.

One push button process

### Results:



<!---  math test not working on GitHub: $\sqrt(2) + \frac{1}{2^5}$
comment  -->

[fig:Model_Hardware_Test_withSampleTime]: ./Fig/Model_Hardware_Test_withSampleTime.png "Simulink Model Model_Hardware_Test_withSampleTime.slx from this repository set-up the dsPIC 33EP256MC506 PIM daughter board used on a MCLV v2 microchip motor control board. Two PWM signals drives a DC motor. One QEI peripheral provides position and speed from an optical encoder. 3 ADC channels provides board potentiometer position and current measurement from two shunt resistors. Peripheral QEI and ADC output values are sent through the UART to the microchip picgui interface for visualisation and data logging."
[fig:DataVisu]: ./Fig/DataVisu.png "picgui, custom script and figure that present in real-time potentiometer, motor speed and current measured"

[MainProjectPage]: ./../../readme.md 

[blockset]: https://www.microchip.com/SimulinkBlocks "Blockset for dsPIC and PIC32 (free)"
[MPLABX]: https://www.microchip.com/MPLABX "Microchip developpment environment (free)"
[XC16]: https://www.microchip.com/XC16 "Microchip Compiler (free with -O1 optimisation)"