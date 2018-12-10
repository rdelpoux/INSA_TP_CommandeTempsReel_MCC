
%% parvalux DC motor
% Electrical parameters
R = 1.22; % in Ohm
L = 2.7e-3; % in H
Kphi = 0.061; % in V/(rad/s)

% Electrical dynamics :
K_e = 1/R;
tau_e = L/R;
Tr_e = 3*tau_e;

% Mechanical Parameters
J = 2.20e-4; % in kgm^2
F = 0.0001; % in Nm/(rad/s);
C0 = 0.0; % in Nm


% Mechanical dynamics :
K_m = Kphi/F;
tau_m = J/F;
Tr_m = 3*tau_m;
%% Physical limits
Vdc = 24; % in V
Vmax = Vdc;
Vmin = -Vdc;

Inom = 4.3; % in A
Imax = Inom;
Imin = -Inom;

Omnom = 350; % in rad/s
Ommax = Omnom;
Ommin = -Omnom;


%% Control synthesis

%%% Electrical control
% Desired polynomial equation
%  1         2 zeta
% ---- p^2+ ------- p + 1
% wn^2        wn
% Overshoot 5%, Trcl x wncl = 3
zetacle = 0.7;
Trcle = Tr_e/3;
wncle = 3/Trcle;
Elec_desired_poles = roots([1/wncle^2 2*zetacle/wncle 1]);

%%% Electrical state feedback
Ae = [
        -R/L 0;
        -1 0;
    ];

Be = [
        1/L;
        0;
    ];

Ke = place(Ae,Be,Elec_desired_poles)

eig(Ae-Be*Ke)
%% Mechanical control
% Desired polynomial equation
%  1         2 zeta
% ---- p^2+ ------- p + 1
% wn^2        wn
% overshoot 5%, Trbf x wnbf = 3
zetaclm = 0.7;
Trclm = Tr_m/20;
wnclm = 3/Trclm;
Desired_mecha_pole = roots([1/wnclm^2 2*zetaclm/wnclm 1]);
% Mechanical state feedback
Am = [
        -F/J 0;
        -1 0;
    ];

Bm = [
        Kphi/J;
        0;
    ];


Km = place(Am,Bm,Desired_mecha_pole);

%% Simulation
% Simulation parameters
Ts = 0.5e-4; % in s
TsMeca = 0.002;%Ts; % in s
Tf = 10; % in s



