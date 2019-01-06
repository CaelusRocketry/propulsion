% Method of Characteristics for Minimum Length Supersonic Nozzle
% Created by Jason Chen, Project Caelus
% Thomas Jefferson High School for Science and Technology
% Developed on December 31st, 2018

% This program generates a minimum-length supersonic diverging nozzle 
% contour using the Method of Characteristics. Equations and methods are 
% derived from the von Karman Institute's 'Aerothermodynamics of High 
% Speed Flows, Lecture 5'. References in any comments throughout this code
% to equations or pages are based on the lecture's slideshow.

%% Inputs
F = input('Desired thrust: ');
P0 = input('Chamber pressure (Pa): ');
ALT = input('Altitude (m): ');
T0 = input('Combustion chamber temperature (K): ');
M = input('Gas molecular mass (kg/mol): ');
k = input('Ratio of specific heats (cp/cv): ');
n = input('Number of characteristics (>2) emanating from throat: ');
%% Exit Pressure
if (h >= 25000)  % Upper Stratosphere
    T = -131.21 + 0.00299 * h;
    P3 = (2.488 * ((T + 273.1) / 216.6)^(-11.388))/1000;
elseif (11000 < h) && (h < 25000)  % Lower Stratosphere
    T = -56.46;
    P3 = (22.65 * exp(1.73 - 0.000157 * h))/1000;
else % Troposphere
    T = 15.04 - 0.00649 * h;
    P3 = (101.29 * ((T + 273.1) / 288.08)^(5.256))/1000;
end
%% Isentropic Flow Relations
PR = P3/P0; % Pressure ratio
TR = PR^((k-1)/k); % Temperature ratio
R = (8314.3/M); % Gas constant
CTt = (2*k*R*T0)/(k-1); % Critical throat temperature (disputed equation?)
CTp = ((2/(k+1))^(k/(k-1)))*P0; % Critical throat pressure
CTv = sqrt((2*k*R*T0)/(k+1)); % Critical throat velocity
v2 = sqrt((CTt)*(1-TR)); % Exit velocity
mdot = F/v2; % Mass flow rate
T2 = T0*TR; % Exit temperature
a2 = sqrt(k*R*T2); % Exit speed of sound
Mnum2 = v2/a2; % Exit Mach number
At = (mdot*(sqrt(k*R*T0))) / (k*P0*(sqrt(((2/(k+1)) ^ ((k+1)/(k-1)))))); % Throat area
Rt = sqrt(At / pi); % Throat radius
%% Calculate Incident Expansion Waves
theta_max = rad2deg((1/2)*PMfunct(Mnum2, k));
%% Plot Incident Expansion Waves
x = linspace(-2*pi,2*pi);
y1 = sin(x);
y2 = cos(x);

figure
plot(x,y1,x,y2)
%% Prandtl-Meyer Function
function PMangle = PMfunct(gamma, mach)
sect1 = (gamma+1)/(gamma-1);
sect2 = (mach^2)-1;
PMangle = sqrt(sect1)*atan(sqrt(sect1*sect2)) - atan(sqrt(sect2));
end
%% Inverse Prandtl-Meyer Function
% Input is the Prandtl-Meyer angle, in radians
function mach = invPMfunct(v)
A = 1.3604;
B = 0.0962;
C = -0.5127;
D = -0.6722;
E = -0.3278;
v_0 = (pi/2)*(sqrt(6)-1);
y = (v/v_0)^(2/3);
mach = (1 + A*y + B*(y^2) + C*(y^3))/(1 + D*y + E*(y^2));
end
