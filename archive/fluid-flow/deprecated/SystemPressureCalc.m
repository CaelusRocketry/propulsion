%% Timed-Based System Pressure Drop
% Jason Chen, 22 February, 2020
clc; clear all; close all;
%% Initial Constants
dt = 0.01; % sec
tp0 = 3.8235e06; % Initial tank pressure, Pa
tpf = 3.035e06; % Final tank pressure, Pa
burntime = 10; % sec
rho = 0.789; % Ethanol density, kg/L
pipeDP = 0.1e06; % Pipe pressure drops (no MPV), Pa
mpvCV = 0.2; % MPV flow coefficient, dimensionless
