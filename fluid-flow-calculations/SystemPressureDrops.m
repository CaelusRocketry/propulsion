%% Preprocessing
clc;
gravity = 9.8; % m/sec^2

%% Propellant Properties
dynamicViscosityE = 0.0016; % kPa*sec
massFlowRateE = 0.12; % kg/sec
densityE = 789; % kg/m^3
volumetricFlowRateE = massFlowRateE/densityE; % m^3/sec
kinematicViscosityE = dynamicViscosityE/densityE; %

dynamicViscosityN = 0.0117; % kPa*sec
massFlowRateN = 0.48; % kg/sec
densityN = 772.25; % kg/m^3
volumetricFlowRateN = massFlowRateN/densityN; % L/sec
kinematicViscosityN = dynamicViscosityN/densityN; %

%% Pipe Parameters
pipeDiameter = 0.00635; % meters
pipeRoughness = 0.015; %micrometers - stainless steel
pipeRoughness = pipeRoughness .* 1000;
pipeLength = 5;                                 % meters

%% Calculations
% ethanolPressDrop = straightPipeDrop(dynamicViscosityEthanol, pipeLength, volumetricFlowRateEthanol, densityEthanol, pipeDiameter, gravity);

ethanolPressDrop = darcyWeisbach(pipeDiameter, pipeRoughness, volumetricFlowRateE, kinematicViscosityE, densityE, pipeLength, gravity);
nitrousOxidePressDrop = darcyWeisbach(pipeDiameter, pipeRoughness, volumetricFlowRateN, kinematicViscosityN, densityN, pipeLength, gravity);
disp(ethanolPressDrop);
disp(nitrousOxidePressDrop);

%% Functions
function pressureDrop = straightPipeDrop(dynamicViscosity, pipeLength, volumetricFlowRate, fluidDensity, pipeDiameter, gravity)
   pressureDrop =  (128*dynamicViscosity*pipeLength*volumetricFlowRate)/(pi*fluidDensity*gravity*(pipeDiameter)^4);
end

function deltaP = darcyWeisbach(diam, rough, Q, kvisc, density, len, g)
    V = Q/(pi*(diam/2)^2); % average velocity
    re = V*diam/kvisc; % Reynolds number
    ed = rough/diam; % relative roughness
    ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
    hf = ff*len*(V^2)/(diam*2*g); % head loss
    deltaP = (density*g*hf)/(1e06); % pressure drop in MPa
end
