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
Vmin = 0;

Inom = 5; % en A
Imax = Inom;
Imin = 0;

Omnom = 350; % en rad/s
Ommax = Omnom;
Ommin = 0;


%% Synthèse de commande

%% Boucle de courant
% polynome caracteristique désiree
%  1         2zeta
% ---- p^2+ ------- p + 1
% wn^2        wn
% Depassement 5%, Trbf x wnbf = 3
zetabfe = 0.7;
Trbfe = Tr_e/3;
wnbfe = 3/Trbfe;

%% Synthèse Fonction de transfert
Pole_elec_desiree = roots([1/wnbfe^2 2*zetabfe/wnbfe 1]);
KPi = (2*zetabfe*wnbfe*tau_e-1)/K_e;
TIi = (2*zetabfe*wnbfe*tau_e-1)/(wnbfe^2*tau_e);

assert(isequal(round(Pole_elec_desiree,10), round(roots([TIi*tau_e/(KPi*K_e) TIi/(KPi*K_e)*(1+KPi*K_e) 1]),10)));

%% Retour d'état de la dynamique electrique
Ae = [
        -R/L 0;
        -1 0;
    ];

Be = [
        1/L;
        0;
    ];

Kelec = -place(Ae,Be,Pole_elec_desiree);
%assert(isnegative(real(eig(A-B*Kelec))))

%% Boucle de vitesse
% polynome caracteristique désiree
%  1         2zeta
% ---- p^2+ ------- p + 1
% wn^2        wn
% Depassement 5%, Trbf x wnbf = 3
zetabfm = 0.7;
Trbfm = Tr_m/20;
wnbfm = 3/Trbfm;

%% Synthèse Fonction de transfert
Pole_meca_desiree = roots([1/wnbfm^2 2*zetabfm/wnbfm 1]);
KPw = (2*zetabfm*wnbfm*tau_m-1)/K_m;
TIw = (2*zetabfm*wnbfm*tau_m-1)/(wnbfm^2*tau_m);

assert(isequal(round(Pole_meca_desiree,10), round(roots([TIw*tau_m/(KPw*K_m) TIw/(KPw*K_m)*(1+KPw*K_m) 1]),10)));

%% Retour d'état de la dynamique mecanique
Am = [
        -F/J 0;
        -1 0;
    ];

Bm = [
        Kphi/J;
        0;
    ];


Kmeca = place(Am,Bm,Pole_meca_desiree);
eig(Am-Bm*Kmeca)


%% Retour d'etat global
Ag = [
        -R/L -Kphi/L;
        Kphi/J -F/J;
    ];

Bg = [
        1/L;
        0;
    ];

Cg = [0 1];

Pole_global_desiree = roots([1/wnbfm^2 2*zetabfm/wnbfm 1]);

Gg=place(Ag,Bg,Pole_global_desiree);
% Préfiltre
Fg = -inv(Cg*inv(Ag-Bg*Gg)*Bg);

%% ==================
% Action intégrale sans préfiltre
% Modèle étendu

Agi = [Ag    [  0;
                0];
       0  1    0];
Bgi = [Bg;
        0];
Cgi = [Cg 0];
% pôle de l'intégrateur en boucle fermée n fois plus rapide que le plus
% rapide
n=3;

p3=n*real(min(Pole_global_desiree))
Ggi=acker(Agi,Bgi,[Pole_global_desiree;p3])
%% Simulation
% Commande :
% x0 : BO
% x1 : Asservissement de courant PI
% x2 : Asservissement de courant PI modifié
% x3 : asservissement de courant RE

% 0x : Pas de boucle de vitesse
% 1x : Asservissement de vitesse PI
% 2x : Asservissement de vitesse PImod
% 3x : Asservissement de vitesse RE

% x4 : asservissement système complet RE prefiltre
% x5 : asservissement système complet RE action intégrale

Commande = 5;


%% Charge
Cl = 0;

%% Paramètre de simulation

Ts = 1e-4; % en s
Tf = 10; % en s

sim('SimuMCC')

%%
figure(1)
subplot(3,1,1)
plot(v.Time,v.Data)
ylabel('Tension v (V)')
subplot(3,1,2)
plot(iref.Time,iref.data,'--',i.Time,i.Data)
legend('i_r_e_f','i','location','best')
ylabel('Courants i (A)')
subplot(3,1,3)
plot(omref.Time, omref.Data,'--',omega.Time,omega.Data)
legend('\omega_r_e_f','\omega','location','best')
ylabel('Vitesse \omega(rad/s)')
xlabel('Temps (s)')