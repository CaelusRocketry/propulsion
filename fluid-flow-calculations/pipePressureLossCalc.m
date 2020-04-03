%% System Piping Pressure Loss Calculation
% Calculates pressure loss, Reynolds number, friction facts, head loss, and
% pressure drops across the system given pipe and fluid attributes
% Jason Chen, 05 October, 2019

%% Preprocessing
clc; clear; close all;
disp(getPressureDrop(0.25, 0.015, 1, 'diameter'));

%% Main
numPoints = 100;
figure('Position', [50 50 1080 720]);
subplot(2,2,1);
diameter = linspace(0.25, 1.0, numPoints); % inches
roughness = 1.5e-06; % m
deltaP = getPressureDrop(diameter, roughness, numPoints, 'diameter');
plot(diameter, deltaP);
% subtitle = sprintf('Assuming pipe roughness of %d in', roughness*39.37);
title('Pipe Diameter vs Pressure Loss (Imperial)');
xlabel('Pipe Diameter (in)');
ylabel('Pressure Drop (MPa)');

subplot(2,2,2);
diameter = diameter.*(2.54); % x-axis now measured in cm
plot(diameter, deltaP);
title('Pipe Diameter vs Pressure Loss (SI)');
xlabel('Pipe Diameter (cm)');
ylabel('Pressure Drop (MPa)');

subplot(2,2,4);
diameter = 0.25; % inches
roughness = linspace(0.1e-06, 0.5e-06, numPoints);
mmRoughness = roughness.*(1e03); % roughness in milimeters
deltaP = getPressureDrop(diameter, roughness, numPoints, 'roughness');
plot(mmRoughness, deltaP);
title('Pipe Roughness vs Pressure Loss (SI)');
xlabel('Average Roughness (mm)');
ylabel('Pressure Drop (MPa)');

subplot(2,2,3);
roughness = roughness.*(39.37); % x-axis now measured in inches
plot(roughness, deltaP);
% subtitle = sprintf('Assuming pipe diameter of %d in', diameter);
title('Pipe Roughness vs Pressure Loss (Imperial)');
xlabel('Average Roughness (in)');
ylabel('Pressure Drop (MPa)');
%% Functions
function deltaP = getPressureDrop(diam, rough, n, calc)
deltaP = zeros(1,100);
% Parameters
mdot = 0.694; % kg/s
density = 789; % kg/m^3
dvisc = 0.001232; % dynamic viscosity, kg/m*s
kvisc = dvisc/density; % kinematic viscosity, m^2/s
len = 2; % m
g = 9.81; % m/s^2
Q = mdot/density; % volumetric flow rate, m^3/s
diam = diam/39.37; % convert inches to meters
numPoints = n;
if strcmp(calc, 'diameter') % solving for different diameters
    for i=1:numPoints
        V = Q/(pi*(diam(i)/2)^2); % average velocity
        re = V*diam(i)/kvisc; % Reynolds number
        ed = rough/diam(i); % relative roughness
        ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
        hf = ff*len*(V^2)/(diam(i)*2*g); % head loss
        deltaP(i) = (density*g*hf)/(1e06); % pressure drop in MPa
        if i==1
           parameters = {'Diameter'; 'Average velocity (V)'; ...
               'Reynolds number (Re)'; 'Relative roughness (e/d)'; ...
               'Friction factor (f)'; 'Head loss (hf)'; ...
               'Pressure drop (delta P)'};
           Value = {diam(i); V; re; ed; ff; hf; deltaP(i)};
           Unit = {'m'; 'm/s'; 'None'; 'None'; 'None'; 'm'; 'MPa'};
           example = table(Value, Unit, 'RowNames', parameters);
           fprintf('Example calculation for i=%d: \n', i);
           disp(example);
        end
    end
elseif strcmp(calc, 'roughness') % solving for different roughnesses
    V = Q/(pi*(diam/2)^2); % average velocity
    re = V*diam/kvisc; % Reynolds number
    for i=1:numPoints
        ed = rough(i)/diam; % relative roughness
        ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
        hf = ff*len*(V^2)/(diam*2*g); % head loss
        deltaP(i) = (density*g*hf)/(1e06); % pressure drop in MPa
    end
else
    disp('Calculation type invalid.')
end
end
