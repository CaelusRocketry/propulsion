%% God help Huzel & Huang R.I.P @95 years old
% Simple tank pressure requirement calculation assuming isentropic flow
% Jason Chen, 05 October, 2019

%% Preprocessing 
clc; close all;
%% Simple Tank Pressure Calculation
% Using two isentropic expansion formulas
% https://www.grc.nasa.gov/www/k-12/airplane/compexp.html
numPoints = 100;
finalPressure = 1.6e06; % Final pressure inside tank
waterVolume = 4.567; % Liters
initVolume = linspace(waterVolume, 100-waterVolume, numPoints);
totalVolume = initVolume+waterVolume;
initTemp = 298; % Kevlin, room temperature
gamma = 1.40; % Ratio of specific heats of nitrogen gas
initPressures = zeros(1, numPoints);
finalTemps = zeros(1, numPoints);
for i=1:size(initVolume,2)
    v1 = initVolume(i);
    v2 = totalVolume(i);
    p2 = finalPressure;
    p1 = getInitPressure(p2, v1, v2, gamma);
    t1 = initTemp;
    t2 = getFinalTemp(t1, p1, p2, gamma);
    initPressures(i) = p1/1e06;
    finalTemps(i) = t2;
end    
figure;
plot(totalVolume, initPressures);
title('Total Tank Volume vs Required Initial Pressures (L)');
xlabel('Total Tank Volume (Pressurant Volume + 4.567), L');
ylabel('Required Initial Pressurant Pressure, MPa');

figure;
plot(totalVolume/28.317, initPressures);
title('Total Tank Volume vs Required Initial Pressures (ft^3)');
xlabel('Total Tank Volume (Pressurant Volume + 0.1613), ft^3');
ylabel('Required Initial Pressurant Pressure, MPa');


figure;
stem3(totalVolume, initPressures, finalTemps);
title('Total Tank Volume vs Initial Pressures vs Final Temperatures');
xlabel('Total Tank Volume, L');
ylabel('Initial Pressure, MPa');
zlabel('Final Temperature, K');
%% Functions
function finalTemp = getFinalTemp(temp_1, pressure_1, pressure_2, gamma)
    finalTemp = temp_1*(pressure_2/pressure_1)^((gamma-1)/gamma);
end
function initPressure = getInitPressure(pressure_2, volume_1, volume_2, k)
    initPressure = (pressure_2)/(volume_1/volume_2)^k;
end