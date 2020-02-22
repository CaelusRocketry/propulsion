%% Isentropic Expansion
% Jason Chen, 22 February, 2020
clc; clear all; close all;
initTemp = 298; % Kevlin, room temperature
gamma = 1.40; % Ratio of specific heats of nitrogen gas
totalTankVolume = 11.564;  % L
propellantInitVolume = 1.762;  % L
initPressurantVolume = totalTankVolume - propellantInitVolume;
finalPressure = 3.035e06;  % Pa
initPressure = getInitPressure(finalPressure, initPressurantVolume, totalTankVolume, gamma);
finalTemp = getFinalTemp(initTemp, initPressurantVolume, totalTankVolume, gamma);
disp("Initial Pressurant Pressure (MPa): " + initPressure/1e06);
disp("Final Tank Temperature (K): " + finalTemp);
%% Functions
function finalTemp = getFinalTemp(temp_1, pressure_1, pressure_2, gamma)
    finalTemp = temp_1*(pressure_2/pressure_1)^((gamma-1)/gamma);
end
function initPressure = getInitPressure(pressure_2, volume_1, volume_2, k)
    initPressure = (pressure_2)/(volume_1/volume_2)^k;
end