%% Preprocessing
clc; clear; close all;
%% Pressure vs Temperature, Isentropic Expansion
gamma = 1.40; % Ratio of specific heats of nitrogen gas
R = 296.6; % Gas constant for nitrogen in J/kg-K
pipeDiam = 0.5/39.37; % 0.5 inches, divide by 39.37 for meters
pipeLen = 8; % 8 meters
pipeVolume = pi*(pipeDiam/2)^2 * pipeLen;
numPoints = 100;
totalTime = 10; % 10 seconds 
finalPressure = 1.6e06; % Final pressure inside tank
initPressure = linspace(2e06, 1e07, numPoints);
initResPressure = 1.5e05;
tankVolumes = [50 100 150 200]; % Liters
totalVolumes = zeros(numPoints, size(tankVolumes,2));
totalMasses = zeros(numPoints, size(tankVolumes,2));
t1 = 298; % Initial temperature, Kelvin
maxTemp = 373.15; % Boiling point of water
% pressureDrops = [tankVolumes; pressureDrops]; 
for n=1:size(tankVolumes,2)
    tankVol = tankVolumes(n);
    for i=1:numPoints
        p1 = initPressure(i);
        p2 = finalPressure;
        p3 = initResPressure;
        t2 = getFinalTemp(t1, p1, p2, gamma);
        tempAvg = (t1+t2)/2; % Bulk temperature at expulsion end
        massTank = (p1*tankVol*1)/(R*tempAvg); % Required pressurant mass
        massRes = (p1*pipeVolume*1)/(R*tempAvg); % Residual pressurant mass
        % Pressurant volume and mass given lower ambient-temperature limit:
        % Stored-gas requirement = Propellant tank requirement + residual 
        % in tank requirement + residual in other componenets requirement
        minTemp = min(t1, t2);
        maxTemp = max(t1, t2);
        totalVol = (massTank+massRes)/((p1/(R*maxTemp))-(p3/(R*minTemp)));
        totalMass = (p1*totalVol*1.02)/(R*maxTemp); %  +2 percent reserve
        totalVolTank = (R*maxTemp*totalMass)/(p1*1);
        totalVolumes(i,n) = totalVolTank;
        totalMasses(i,n) = totalMass;
    end
end
%% Plotting
figure;
% figure('Position', [50 50 1080 720]);
% subplot(2,1,1);
for n=1:size(tankVolumes,2)
    plot(initPressure, totalVolumes(:,n)', 'DisplayName', ...
        int2str(tankVolumes(1,n)));
    hold on;
end
hold off;
legend;
title('Total Pressurant Volume vs Initial Pressures');
xlabel('Initial Pressure, Pa');
ylabel('Total Pressurant Volume, L');
figure;
% subplot(2,1,2);
for n=1:size(tankVolumes,2)
    plot(initPressure, totalMasses(:,n)', 'DisplayName', ...
        int2str(tankVolumes(1,n)));
    hold on;
end
hold off;
legend;
title('Total Pressurant Mass vs Initial Pressures');
xlabel('Initial Pressure, Pa');
ylabel('Total Pressurant Mass, kg');
%% Functions
function finalTemp = getFinalTemp(temp_1, pressure_1, pressure_2, gamma)
    finalTemp = temp_1*(pressure_2/pressure_1)^((gamma-1)/gamma);
end
