%% Tank Pressure Sample Calculation
% Testing calculations when trying to decipher Huzel & Huang
% Gabriel Witkop & Sophia Troshynski, 05 October, 2019

%% Preprocessing
clc; clear; close all;
%% Pressure vs Temperature, Isentropic Expansion
gamma = 1.40; % Ratio of specific heats of helium gas
R = 55.165; % Gas constant for helium in ft-lbf/ft-R
%R = (1544/4); % Gas constant for helium in J/kg-K
%pipeDiam = 0.5/39.37; % 0.5 inches, divide by 39.37 for meters
%pipeLen = 8; % 8 meters
%pipeVolume = pi*(pipeDiam/2)^2 * pipeLen;
pipeVolume = 5.15353; % ft^3
%pipeVolume = 0.4; % m^3
minTemp = 214.238; % minimum temperature deg R
maxTemp = 536.4; % maximum temperature
%minTemp = 191; % minimum temperature
%maxTemp = 500; % maximum temperature
bulkTemp = (minTemp+maxTemp)/2;
%bulkTemp = 346;
disp("bulk temperature:");
disp(bulkTemp);
pressurePostExpulsion = 11137634.9512; % pa
%pressurePostExpulsion = 23760; % pa
maxTankPressure = 31026351.714723; 
%maxTankPressure = 31026351.714723; 
%maxTankPressure = 4500; 
pipePressure = 2758000;
%pipePressure = 400;
volPropExpelled = 0.353147; % ft^3
%volPropExpelled = 119; % m^3
compressibilityFactor = 1;
pressurantWeight = (pressurePostExpulsion * volPropExpelled * compressibilityFactor)/(R*bulkTemp);
residPipeWeight = (pressurePostExpulsion * pipeVolume * compressibilityFactor/(R*bulkTemp));
totalPressurantVolume = (pressurantWeight + residPipeWeight)/(((maxTankPressure)/(R*maxTemp))-((pipePressure)/(R*minTemp)));

disp(pressurantWeight);
disp(residPipeWeight);
disp(totalPressurantVolume);