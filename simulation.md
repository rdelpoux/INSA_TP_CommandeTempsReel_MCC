# Simulation

## Simulation

1. Download the simulation files [here](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/raw/master/LABMatlabFiles/01_Simulation/Simulation.zip) \([fig](https://github.com/rdelpoux/INSA_TP_CommandeTempsReel_MCC/tree/5e795288653c112fc4be57abb2be40275d964f8c/Figures/Simulation/FigureSimu.png)\). These files propose the simulation of the control law proposed section [DC motor modeling and control loop design](https://rtdc.ctrl-elec.fr/control-loop-design).

![Double precision simulation](.gitbook/assets/figuresimu.png)

1. For the realtime application the controlleur needs to be sampled. The inner electrical control loop will be sampled à 20kHz \(PWM frequency\). The outer mechanical control loop will be sampled at 500Hz. For this purpose, use the Sampling block commented in the simulation. Apply the sampled control to the downloaded model and compare with the continous control.
2. The DSpic support 16bits fixed point variables. The control needs to be converted to use 16bits fixed point variable only. Here use the quantization block. Compare the this control with the two previous one.

## Comparison between model and simulation

Here the objective is to compare the difference between the modeling and

![Model vs Logs](.gitbook/assets/modelvslog.png)

