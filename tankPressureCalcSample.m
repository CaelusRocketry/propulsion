%% Preprocessing
clc; clear; close all;
%% Pressure vs Temperature, Isentropic Expansion
gamma = 1.40; % Ratio of specific heats of nitrogen gas
R = 125.037809103; % Gas constant for nitrogen in J/kg-K
%pipeDiam = 0.5/39.37; % 0.5 inches, divide by 39.37 for meters
%pipeLen = 8; % 8 meters
%pipeVolume = pi*(pipeDiam/2)^2 * pipeLen;
pipeVolume = 0.0113267;
minTemp = 106.111; %minimum temperature
maxTemp = 277.778; %maximum temperature
bulkTemp = (minTemp*maxTemp)/2;
maxTankPressure = 11137634.9512;
maxTankPressure2 = 31026000;
pipePressure = 2758000;
volPropExpelled = 3.3697;
compressibilityFactor = 1;
pressurantWeight = (maxTankPressure * volPropExpelled * compressibilityFactor)/(R*bulkTemp);
residPipeWeight = (maxTankPressure * pipeVolume * compressibilityFactor/(R*bulkTemp));
totalPressurantVolume = (pressurantWeight + residPipeWeight)/(((maxTankPressure2)/((1544/4)*maxTemp))-((pipePressure)/((1544/4)*minTemp)));

disp(pressurantWeight);
disp(residPipeWeight);
disp(totalPressurantVolume);