# INSA_TP_CommandeTempsReel_MCC

Auteurs : 
- Romain DELPOUX (Romain.Delpoux at insa-lyon.fr), INSA de Lyon, Laboratoire Ampere UMR CNRS 5005.
- Lubin KERHUEL (Lubin.Kerhuel at microchip.com), Microchip Technology Inc.

## Introduction
Ce projet détaille la modélisation et la commande d'un moteur à courant continu 
pour des applications temps réel sur cible microntroleurs Microchip dsPIC.  
![fig:MotorPravalux]


Etapes avec l'outil de prototypage rapide Matlab-Simulink:

1. (En) [MCLV V2 board setup with Simulink for DC motor][Hardware_setup]
1. (En) [Data recording, Simulation and Validation][DataLog_And_Simulation]
1. (En) [Control Loop design][Control_Loop]


[Hardware_setup]: ./Experimentations/01_Hardware_setup/ "Simulink Model, picgui script to visualise data"
[DataLog_And_Simulation]: ./Experimentations/05_Log_Model_And_Simulation/ "Log data and reuse in simulation"
[Control_Loop]: ./Experimentations/10_Control_Loop/ "Control loop"


[fig:MotorPravalux]: ./Experimentations/05_Log_Model_And_Simulation/MotorPravalux.png "Motor Pravalux"
