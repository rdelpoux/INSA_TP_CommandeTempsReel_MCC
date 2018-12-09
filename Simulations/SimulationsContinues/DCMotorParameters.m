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

Inom = 5; % in A
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

%%% Retour d'etat de la dynamique electrique
Ae = [
        -R/L 0;
        -1 0;
    ];

Be = [
        1/L;
        0;
    ];

Kelec = place(Ae,Be,Elec_desired_poles)

eig(Ae-Be*Kelec)
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

%% Simulation
% Consigne
omref = 200;


% Charge
Cl = .0;

% Parametres de simulation
Ts = 1e-4; % en s
Tf = 10; % en s



%sim('SimulationContinueMCC')
sim('SimulationContinueMCC')

%%
figure(1)
subplot(3,1,1)
plot(v_o.Time,v_o.Data)
ylabel('Tension v (V)')
subplot(3,1,2)
plot(iref_o.Time,iref_o.data,'--',i_o.Time,i_o.Data)
legend('i_r_e_f','i','location','best')
ylabel('Courants i (A)')
subplot(3,1,3)
plot(omref_o.Time, omref_o.Data,'--',omega_o.Time,omega_o.Data)
legend('\omega_r_e_f','\omega','location','best')
ylabel('Vitesse \omega (rad/s)')
xlabel('Temps (s)')