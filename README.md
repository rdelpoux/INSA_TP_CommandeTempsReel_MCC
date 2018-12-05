# Lab : Real Time DC motor control

## Authors : 
- Romain DELPOUX (Romain.Delpoux at insa-lyon.fr), Assistant Professor, INSA de Lyon, Laboratoire Ampere UMR CNRS 5005.
- Lubin KERHUEL (Lubin.Kerhuel at microchip.com), Software Engineer, Microchip Technology Inc.

## Introduction
This project is offered to the 5th year students in the [electrical engineering departement][GE] of [INSA Lyon][INSA] for the [CCSA][CCSA] option. This project details the steps for the real time implementation of a velocity DC motor control on Microchip dsPIC microcontroller target. The programming environment for this project is the rapid protoype Matlab/Simulink toolbox [MPLAB Device Blocks for Simulink][SimulinkMicrochip].

![fig:MotorPravalux] 

The project details the following points 
1. Getting started with the programming environment and harware setup until the openl-loop control of the DC motor which means : 
	- Two PWM signals to control the motor DC voltage through a H bridge structure using MOSFET.
	- Two ADC channels providing the respectively the board potentiometer positon to impose a reference and the current measurement from a shunt resistor. 
	- QEI peripheral to provide shaft position and speed
	- UART connection to the computer for the data analysis. 
1. Modelling and simulation of the DC motor.
	- A recall on the motor modelling and a basic simulation model of the motor is given. 
1. Control synthesis and simulation
	- 

Ce projet détaille la modélisation et la commande d'un moteur à courant continu 
pour des applications temps réel sur cible microntroleurs Microchip dsPIC.  



Etapes avec l'outil de prototypage rapide Matlab-Simulink:

1. (En) [MCLV V2 board setup with Simulink for DC motor][Hardware_setup]
1. (En) [Data recording, Simulation and Validation][DataLog_And_Simulation]
1. (En) [Control Loop design][Control_Loop]









[GE]: http://ge.insa-lyon.fr
[INSA]: http://www.insa-lyon.fr
[CCSA]: http://ge-option5a.insa-lyon.fr/content/ccsa-commande-de-convertisseurs-et-de-systemes-dactionnement
[SimulinkMicrochip]:https://www.microchip.com/DevelopmentTools/ProductDetails/sw007023#utm_source=MicroSolutions&utm_medium=Link&utm_term=FY16Q4&utm_content=DevTools&utm_campaign=Article
[Hardware_setup]: ./Experimentations/01_Hardware_setup/ "Simulink Model, picgui script to visualise data"
[DataLog_And_Simulation]: ./Experimentations/05_Log_Model_And_Simulation/ "Log data and reuse in simulation"
[Control_Loop]: ./Experimentations/10_Control_Loop/ "Control loop"


[fig:MotorPravalux]: ./Experimentations/05_Log_Model_And_Simulation/MotorPravalux.png "Motor Pravalux"
