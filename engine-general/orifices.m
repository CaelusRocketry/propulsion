%%overall parameters
drop = (1.5*10^6 *0.25); % pressure drop over injector 
angle = 60; % angle of impingement 

%oxidizer calcs
n = 14; % number of ox orifices 
mtoto = 0.5552; % total ox mass flow rate in kg/s
cd = 0.9; % coeff of discharge for ox
rhoo = 772.25; % density of oxidizer in kg/m^3
disp('diameter of oxidizer orifice in m:');
format long g % make decimal longer
disp(2*(sqrt(mtoto/(n*cd*pi*(sqrt(2*rhoo*drop)))))); %display the diameter in m
diamo = (2*(sqrt(mtoto/(n*cd*pi*(sqrt(2*rhoo*drop)))))); % diam of ox orifice in m
jet5o = 5*diamo; %jet length for oxidizer using l/d ratio of 5
jet6o = 6*diamo;%jet length for oxidizer using l/d ratio of 6
jet7o = 7*diamo; %jet length for oxidizer using l/d ratio of 7
jetlengo = 0.01; % round number chosen from jet options above in m
btwno = (jetlengo * 2 * sind(60)); %distance between oxidizer orifices 
disp('distance between the ox orifices in m');
disp (btwno);

%fuel calcs
nf = 8; % number of fuel orifices 
mtotf = 0.1388; % total mass flow rate in kg/s
cdf = 0.9; % coeff of discharge 
rhof = 789; % density of oxidizer in kg/m^3
disp('diameter of fuel orifice in m:');
format long g
disp(2*(sqrt(mtotf/(nf*cdf*pi*(sqrt(2*rhof*drop)))))); %display the diameter
diamf = (2*(sqrt(mtotf/(nf*cdf*pi*(sqrt(2*rhof*drop))))));
jet5f = 5*diamf; %jet length for oxidizer using l/d ratio of 5
jet6f = 6*diamf; %jet length for oxidizer using l/d ratio of 6
jet7f = 7*diamf; %jet length for oxidizer using l/d ratio of 7
jetlengf = jet5f; % since no round number, chose smallest one
btwnf = (jetlengf * 2 * sind(60)); %distance between oxidizer orifices 
disp('distance between the ox orifices in m');
disp (btwnf);
