%% Donnees TP Temps Reel


%% Initilisation 
% Fonctions de base
clc
clear all

%% Initisation de l'expérimentation
%Frequence de PWM
FPWM = 20e3; % en Hz
TPWM = 1/FPWM; % en s
PWMmax = 3199;
% Temps mort
Tm = 0.5e-6; % en s
% Periode d'echantillonnage
Ts = 1e-4;


%% Paramètres Banc
Vdc = 24;
Lignes = 250*4;


%% Filtre vitesse
b = [0.0155    0.0155];
a = [1.0000   -0.9691];
