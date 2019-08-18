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
tankVolumes = [25 50 75 100]; % Liters
pressureDrops = zeros(numPoints, size(tankVolumes,2));
t1 = 298; % Initial temperature, Kelvin
% pressureDrops = [tankVolumes; pressureDrops]; 
for n=1:size(tankVolumes)
    tankVol = tankVolumes(1);
    for i=1:numPoints
        p1 = initPressure(1);
        p2 = finalPressure;
        t2 = getFinalTemp(t1, p1, p2, gamma);
        temp = (t1+t2)/2; % Bulk temperature at expulsion end
        mass = (p1*tankVol*1)/(R*temp); % Required pressurant mass
        
    end
end
figure;
%% Functions
function deltaP = getPressureDrop()
    deltaP = 1;
end

function finalTemp = getFinalTemp(temp_1, pressure_1, pressure_2, gamma)
    finalTemp = temp_1*(pressure_2/pressure_1)^((gamma-1)/gamma);
end
