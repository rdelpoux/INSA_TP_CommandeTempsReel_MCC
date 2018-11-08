function sim2mat()
% Convert Picgui Logs files from model MCLV2_dsPIC33EP256MC506_externalOpAmp_DataLog
% into input file to feed simulink model

Fnames = {...  
            '2018_10_28_at_23h48_37s',...   %% Steps 
            '2018_11_07_at_18h40_54s',...   %% Chirp
            };

Flag = 0;
for iF = Fnames
    FileIn = [iF{1} '.mat'];
    FileOut = ['Sim_' iF{1} '.mat'];
    if ~exist(FileOut,'file')        
        Flag = 1;
        disp(['Load ' iF{1} '.mat']);
        load([iF{1} '.mat']);
    
        % 1st column is the PWM motor cmd (normalized in [-1 1], datatype in model is sfix16 en15) 
        %       sampled every 50us
        % 2nd column is Current measurement (A) with format: datatype in model is fixdt(1,16,4.4/32768,0) 
        %       sampled every 50us
        % where 4.4/32768 is the LSB representation        
        %       3rd column is the raw speed measurement from QEI peripehral. sampled every 2ms

        A = padr(Rtotal,2); % trig on 2nd column all data are rewriten at 50us rate. 3rd column is sampled and hold.
        t = 0:.00005:((length(A)-1)*.00005);    % time vector for sim reference
        SimIn = [t ; A'];   % simulink file input format: first line is time, others lines are values

        disp(['  Save Sim_' iF{1} '.mat']);
        save(['Sim_' iF{1}],'SimIn');
    end
end

if Flag == 0
    disp('sim2mat conversion: Nothing to do');
end




