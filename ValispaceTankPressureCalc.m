%% Preprocessing 
clc; close all;
%% Simple Tank Pressure Calculation
% Using two isentropic expansion formulas
% https://www.grc.nasa.gov/www/k-12/airplane/compexp.html
finalPressure = 1.6e06; % Final pressure inside tank
waterVolume = 4.567; % Liters
initVolume = linspace(waterVolume, 100-waterVolume, numPoints);
totalVolume = initVolume+waterVolume;
initTemp = 298; % Kevlin, room temperature
gamma = 1.40; % Ratio of specific heats of nitrogen gas
p1 = getInitPressure(p2, v1, v2, gamma);
t1 = initTemp;
t2 = getFinalTemp(t1, p1, p2, gamma);
initPressures = p1/1e06;
finalTemps = t2;

disp(finalTemps)
%% Functions
function finalTemp = getFinalTemp(temp_1, pressure_1, pressure_2, gamma)
    finalTemp = temp_1*(pressure_2/pressure_1)^((gamma-1)/gamma);
end
function initPressure = getInitPressure(pressure_2, volume_1, volume_2, k)
    initPressure = (pressure_2)/(volume_1/volume_2)^k;
end