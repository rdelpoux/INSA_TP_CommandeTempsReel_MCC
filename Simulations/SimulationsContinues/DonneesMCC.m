%% MCC pravalux
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
%% Limites physiques (un seul bras, vitesse courant positif)
Vdc = 24; % en V
Vmax = Vdc;
Vmin = -Vdc;

Inom = 5; % en A
Imax = Inom;
Imin = -Inom;

Omnom = 350; % en rad/s
Ommax = Omnom;
Ommin = -Omnom;


%% Synthese de commande

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

Kelec = -place(Ae,Be,Pole_elec_desiree)


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
sim('SimulationContinueClampingMCC')

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