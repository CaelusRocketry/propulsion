ValispaceInit("https://caelus.valispace.com","RonNachum","Valispace2019")
ValispacePull()

%% Define Constants
CubicFeetToInches = 1728;
CubicInchesToLiters = 0.0163871;
AtmosphericPressure = 14.696; %psi
NCompressibilityFactor = 1.054; %at 3000 psi, nitrogen
OCompressibilityFactor = 0.947; %at 3000 psi, oxygen
%% Tank Parameters
ServicePressure = ValispaceGetValue("Propellant_Tanks.ServicePressure"); %psi
IdealCapacity = ValispaceGetValue("Propellant_Tanks.IdealCapacity"); %cubic feet

%% Calculation
WaterVolume = (CubicFeetToInches * AtmosphericPressure * NCompressibilityFactor * IdealCapacity) / ServicePressure; %cubic inches

%% Conversion
WaterVolume = WaterVolume * CubicInchesToLiters; %liters

%% Printing
disp(WaterVolume);
