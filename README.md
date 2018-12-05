# Lab : Real Time DC motor control

## Authors : 
- Romain DELPOUX (Romain.Delpoux at insa-lyon.fr), Assistant Professor, INSA de Lyon, Laboratoire Ampere UMR CNRS 5005.
- Lubin KERHUEL (Lubin.Kerhuel at microchip.com), Software Engineer, Microchip Technology Inc.

## Introduction
This project is offered to the 5th year students in the [electrical engineering departement][GE] of [INSA Lyon][INSA] for the [CCSA][CCSA] option. This project details the steps for the real time implementation of a velocity DC motor control on Microchip dsPIC microcontroller target. The programming environment for this project is Matlab/Simulink, using the toolbox [MPLAB Device Blocks for Simulink][SimulinkMicrochip]

![fig:MotorPravalux] 

The project details the following points 
1. 

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
