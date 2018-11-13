%% Declaration variables + synthesis of feedback controller

if ~exist('PWMmax')
	PWMmax = 3199;	% this value should be initialized by the PWM block itself
end

% sampling rate
	Ts = 50e-6; 		% 50us

%% Hardware parameters:
	Vmax = 24;		% Power supply is 24V
	Imax = 4.4;		% Max current measurement: 4.4Amps

% encoder:
	Lignes = 250*4;	% Quadrature Encoder resolution per rotation: 250 lines (*4)

% Motor:
	Wmax = 350; % rad/s:  Max rotational speed for the motor shaft

% DC motor pravalux
	%Parametre electriques
	R = 1.22; % en Ohm
	L = 2.7e-3; % en H
	Kphi = 0.061; % en V/(ras/s)

	% Dynamique electrique :
	K_e = 1/R;
	tau_e = L/R;
	Tr_e = 3*tau_e;

	%Parametre mecaniques
	J = 2.20e-4; % en kgm^2
	F = 0.0001; % en Nm/(rad/s);
	C0 = 0.0; % en Nm

	% Dynamique mecanique :
	K_m = Kphi/F;
	tau_m = J/F;
	Tr_m = 3*tau_m;



%% Command law: 
	% model require two set of parameters:
	% - Kelec for the inner current control loop and
	% - Kmeca for the outer speed control loop

	%% Boucle de courant
	% polynome caracteristique desiree
	%  1         2zeta
	% ---- p^2+ ------- p + 1
	% wn^2        wn
	% Depassement 5%, Trbf x wnbf = 3
	zetabfe = 0.7;
	Trbfe = Tr_e/3;
	wnbfe = 3/Trbfe;
	Pole_elec_desiree = roots([1/wnbfe^2 2*zetabfe/wnbfe 1]);
	%% Retour d'etat de la dynamique electrique
	Ae = [
	        -R/L 0;
	        -1 0;
	    ];

	Be = [
	        1/L;
	        0;
	    ];

	Kelec = -place(Ae,Be,Pole_elec_desiree);


	%% Boucle de vitesse
	% polynome caracteristique desiree
	%  1         2zeta
	% ---- p^2+ ------- p + 1
	% wn^2        wn
	% Depassement 5%, Trbf x wnbf = 3
	zetabfm = 0.7;
	Trbfm = Tr_m/20;
	wnbfm = 3/Trbfm;
	Pole_meca_desiree = roots([1/wnbfm^2 2*zetabfm/wnbfm 1]);

	%% Retour d'etat de la dynamique mecanique
	Am = [
	        -F/J 0;
	        -1 0;
	    ];

	Bm = [
	        Kphi/J;
	        0;
	    ];


	Kmeca = place(Am,Bm,Pole_meca_desiree);
	%eig(Am-Bm*Kmeca) % to check that eigen values are similar to the value targeted Pole_meca_desiree




% use filter designed using FDAtool (graphical interface)
% coefs are hard coded in blocks

%% if required, synthesis of a LP filter, for the 500Hz control loop:
if 0
    cutOff = 50;  % 50Hz
    [b,a] = butter(1,cutOff*2e-3*2);    % Filter at 50 Hz (normalized frequency: 1 is Fnyquist, 2e-3(s) (500Hz) is the sampling rate for the mechanical feedback loop)
    % figure(2); step(fct);
    % fct = tf(b,a,Ts);
    % figure(1); bode(fct);

	%% for the 20kHz control loop:    
    [b,a] = butter(1,cutOff*50e-6*2);    % Filter at 50 Hz (normalized frequency: 1 is Fnyquist)
    % fct = tf(b,a,Ts);
    % figure(1); bode(fct);
    % figure(2); step(fct);
end



