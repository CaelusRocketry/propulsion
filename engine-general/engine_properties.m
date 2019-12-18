%% General Parameters Characterization
% Ethanol (75%), H20(25%), GOX
% Jason Chen, Project Caelus, 16 December, 2019

clc; close all;
%% Purdue's Parameters
g = 9.806; % m/s
lbs2kg = 0.453592;
mdot = 4.1; % lbsf/s
mdot = mdot*lbs2kg;
thrust = 1124.045; % lbsf
v = thrust/mdot;
isp = v/g;
