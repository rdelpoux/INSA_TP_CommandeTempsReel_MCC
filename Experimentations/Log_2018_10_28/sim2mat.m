load 2018_10_28_at_23h48_37s.mat

A = padr(Rtotal,2); % trig on 2nd column

t = 0:.00005:((length(A)-1)*.00005);

SimIn = [t ; A'];
save Sim_2018_10_28_at_23h48_37s SimIn;


