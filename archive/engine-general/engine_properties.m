%% General Parameters Characterization
% Ethanol (75%), H20(25%), GOX
% Jason Chen, Project Caelus, 16 December, 2019

clc; close all;
%% Purdue's Parameters
g = 9.806; % m/s
lbsm2kg = 0.453592;
lbsf2n = 4.448;
mdot = 4.1; % lbsf/s
mdot = mdot*lbsm2kg;
thrust = 1124.045; % lbsf
thrust = thrust*lbsf2n;
v = thrust/mdot;
isp = v/g;
burn_time = 8.1; % sec
glow = 120*lbsm2kg;
dry_weight = glow - burn_time*mdot;
t = table(thrust, v, isp, dry_weight);
disp(t);
