% 1) Valispace Login
ValispaceInit("https://caelus.valispace.com","RonNachum","Valispace2019")

% 2) optional: pull all Valis for faster access or access via name
ValispacePull()


%% Main
diameter = ValispaceGetValue("Pipe.Diameter"); % in
roughness = ValispaceGetValue("Pipe.Roughness"); % m
roughness = roughness*(10^-6); % µm
deltaP = getPressureDrop(diameter, roughness, 'diameter');
ValispacePushValue("Pipe.PressureDrop", deltaP)

disp('Diameter')
disp(diameter)
disp('Roughness')
disp(roughness)
disp('Pressure Drop')
disp(deltaP)
%% Functions
function deltaP = getPressureDrop(diam, rough, calc)
% Parameters
mdot = 0.9133; % kg/s
density = 786; % kg/m^3
dvisc = 0.00196; % dynamic viscosity, kg/m*s
kvisc = dvisc/density; % kinematic viscosity, m^2/s
len = 8; % m
g = 9.81; % m/s^2
Q = mdot/density; % volumetric flow rate, m^3/s
diam = diam/39.37; % convert inches to meters
if strcmp(calc, 'diameter') % solving for different diameters
    V = Q/(pi*(diam/2)^2); % average velocity
    re = V*diam/kvisc; % Reynolds number
    ed = rough/diam; % relative roughness
    ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
    hf = ff*len*(V^2)/(diam*2*g); % head loss
    deltaP = (density*g*hf)/(1e06); % pressure drop in MPa
    parameters = {'Diameter'; 'Average velocity (V)'; ...
        'Reynolds number (Re)'; 'Relative roughness (e/d)'; ...
        'Friction factor (f)'; 'Head loss (hf)'; ...
        'Pressure drop (delta P)'};
    Value = {diam; V; re; ed; ff; hf; deltaP};
    Unit = {'m'; 'm/s'; 'None'; 'None'; 'None'; 'm'; 'Pa'};
    example = table(Value, Unit, 'RowNames', parameters);
    disp(example);
elseif strcmp(calc, 'roughness') % solving for different roughnesses
    V = Q/(pi*(diam/2)^2); % average velocity
    re = V*diam/kvisc; % Reynolds number
    ed = rough/diam; % relative roughness
    ff = (1/(-1.8*log10((6.9/re)+(ed/3.7)^1.11)))^2; % friction factor
    hf = ff*len*(V^2)/(diam*2*g); % head loss
    deltaP = (density*g*hf)/(1e06); % pressure drop in MPa
else
    disp('Calculation type invalid.')
end
end
