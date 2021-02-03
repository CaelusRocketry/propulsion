%% Preprocessing
clc;
gravity = 9.8; % m/sec^2

%% Propellant Properties
dynamicViscosityE = 0.0016; % kPa*sec
massFlowRateE = 0.12; % kg/sec
densityE = 789; % kg/m^3
volumetricFlowRateE = massFlowRateE/densityE; % m^3/sec
kinematicViscosityE = dynamicViscosityE/densityE; %
specificGravityE = 0.79;

dynamicViscosityN = 0.0117; % kPa*sec
massFlowRateN = 0.48; % kg/sec
densityN = 772.25; % kg/m^3
volumetricFlowRateN = massFlowRateN/densityN; % L/sec
kinematicViscosityN = dynamicViscosityN/densityN; %
specificGravityN = 1.555;

%% Plumbing Part Properties
solenoidValveCV = 0.06;
checkValveCV = 1.2;

%% Pipe Parameters
pipeDiameter = 0.00635; % meters
pipeRoughness = 0.015; %micrometers - stainless steel
pipeRoughness = pipeRoughness .* 1000;
pipeLength = 5;                                 % meters

%% Calculations

disp(cvPressDrop(specificGravityE, volumetricFlowRateE, 1))

ethanolSolenoidValvePressureDrop = cvPressDrop(specificGravityE, volumetricFlowRateE, solenoidValveCV);
disp(ethanolSolenoidValvePressureDrop);

ethanolStraightPipePressureDrop = darcyWeisbach(pipeDiameter, pipeRoughness, volumetricFlowRateE, kinematicViscosityE, densityE, pipeLength, gravity);
disp(ethanolStraightPipePressureDrop);

ethanolCheckValvePressureDrop = cvPressDrop(specificGravityE, volumetricFlowRateE, checkValveCV);
disp(ethanolCheckValvePressureDrop);

nitrousOxideSolenoidValvePressureDrop = cvPressDrop(specificGravityN, volumetricFlowRateN, solenoidValveCV);
disp(nitrousOxideSolenoidValvePressureDrop);

nitrousOxideStraightPipePressDrop = darcyWeisbach(pipeDiameter, pipeRoughness, volumetricFlowRateN, kinematicViscosityN, densityN, pipeLength, gravity);
disp(nitrousOxideStraightPipePressDrop);

nitrousOxideCheckValvePressureDrop = cvPressDrop(specificGravityN, volumetricFlowRateN, checkValveCV);
disp(nitrousOxideCheckValvePressureDrop);


%% Functions
function deltaP = darcyWeisbach(diam, rough, Q, kvisc, density, len, g)
    V = Q/(pi*(diam/2)^2); % average velocity
    re = V*diam/kvisc; % Reynolds number
    ed = rough/diam; % relative roughness
    ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
    hf = ff*len*(V^2)/(diam*2*g); % head loss
    deltaP = (density*g*hf)/(1e06); % pressure drop in MPa
    deltaP = deltaP .* 145.038; % pressure drop in PSI
end

function deltaP = cvPressDrop(specificGravity, volumetricFlowRate, flowCoefficient)
    volumetricFlowRate = volumetricFlowRate .* 1000 .* 15.850372483753;
    deltaP = ((volumetricFlowRate * (specificGravity ^ 0.5))/flowCoefficient)^2;
    deltaP = deltaP .* 145.038; % pressure drop in PSI
end