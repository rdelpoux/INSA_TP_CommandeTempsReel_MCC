%% Getting started init

%% Experiment initialization
% PWM frequancy
FPWM = 20e3; % in Hz
TPWM = 1/FPWM; % in s
if ~exist('PWMmax')
	PWMmax = 3199;	% this value should be initialized by the PWM block itself
end

% Dead time
Tm = 0.5e-6; % in s
% Sampling period
Ts = TPWM;  % We synchronize model Time Stpe with PWM (see ADC peripheral settings). This is 5e-4(s);
Tsmeca = 0.002;
TsQEI = Tsmeca/5;   % QEI sampled 5 time faster than Tsmeca for filtering


%% Bench parameters Paramètres Banc
Vdc = 24;
Lignes = 500*4;


% use filter designed using FDAtool (graphical interface)
% coefs are set in block directly.

%% Filtre vitesse version de Lubin
if 0
    try
        LPF_vit_Fc = 50;  % 50Hz
        [b,a] = butter(1,LPF_vit_Fc*TsQEI*2);    % Filter at 50 Hz (normalized frequency: 1 is Fnyquist)
        % fct = tf(b,a,Ts);
        % figure(1); bode(fct);
        % figure(2); step(fct);
    catch % if control toolbox not available
        b = [0.2452    0.2452];
        a = [1.0000   -0.5095];
    end
end

%% Filtre vitesse version fonctionnelle pour le moment, a verifier
if 0
    try
        LPF_vit_Fc = 50;  % 50Hz
        [b,a] = butter(1,LPF_vit_Fc*Ts*2);    % Filter at 50 Hz (normalized frequency: 1 is Fnyquist)
        % fct = tf(b,a,Ts);
        % figure(1); bode(fct);
        % figure(2); step(fct);
    catch % if control toolbox not available
        b = [0.0155    0.0155];
        a = [1.0000   -0.9691];
    end
end


