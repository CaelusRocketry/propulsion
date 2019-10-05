%% System Pressure Loss Calculation with Valispace Integration
% Valispace integration of pipePressureLossCalc.m
% Ron Nachum, 05 October, 2019

% Valispace Login
ValispaceInit("https://caelus.valispace.com","RonNachum","Valispace2019")

% Pull all Valis for faster access or access via name
ValispacePull()


%% Main
diam = ValispaceGetValue("Pipe.Diameter"); % in
rough = ValispaceGetValue("Pipe.Roughness"); % m
rough = rough*(10^-6); % µm

% Parameters
mdot = ValispaceGetValue("Fluid.MassFlowRate"); % kg/s
density = ValispaceGetValue("Fluid.Density"); % kg/m^3
dvisc = ValispaceGetValue("Fluid.DynamicViscosity"); % dynamic viscosity, kg/m*s
kvisc = dvisc/density; % kinematic viscosity, m^2/s
len = ValispaceGetValue("Pipe.Length"); % m
g = 9.81; % m/s^2
Q = mdot/density; % volumetric flow rate, m^3/s
diam = diam/39.37; % convert inches to meters

%Calculations
V = Q/(pi*(diam/2)^2); % average velocity
re = V*diam/kvisc; % Reynolds number
ed = rough/diam; % relative roughness
ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
hf = ff*len*(V^2)/(diam*2*g); % head loss
deltaP = (density*g*hf)/(1e06); % pressure drop in MPa

%Display
disp('Diameter')
disp(diameter)
disp('Roughness')
disp(rough)
disp('Pressure Drop')
disp(deltaP)
ValispacePushValue("Pipe.PressureDrop", deltaP)
