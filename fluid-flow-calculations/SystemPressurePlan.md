# System Pressure Calculation Plan
Since using pressure blowdown system, end goal is to compute mdot and tank pressure as a function of time.

1) Find the DP across injector, let's say 25% for now.
    - Initial nominal chamber pressure of 1.5 MPa, so 1.875 MPa at fuel manifold
2) Assuming nominal mass flow rate at around 0.694 kg/s, around 0.139 kg/s for ethanol
    - 1 L/s = 15.850 GPM, 1 PSI = 6894.76 Pa
    - Using density (.789 kg/L), Q (volumetric flow rate) is around 0.176 L/s (2.790 GPM)
    - MPV Cv of around 0.2, using equation (uses gallons per minute and PSI, SPG = 0.789 kg/L), pressure drop across MPV is around 153.5 PSI (1058345.2445 Pa, ~= 1.06 MPa)
    - Adding this to DP at manifold, need around 2.935 MPa before the MPV
3) According to P&ID, MPV is the only thing constricting flow, along with adapters and bends
    - Assuming pipe roughness of 0.01 mm (10 microns) and cross-section change adapters with half angles of around 45 degrees
    
The following is the pressure drop of the 0.5" > 0.25" adapter:

Flow medium:	Water 20 °C / liquid
Volume flow::	0.176 l/s
Weight density:	998.206 kg/m³
Dynamic Viscosity:	1001.61 10-6 kg/ms
Element of pipe:	Gradual contraction
Dimensions of element:	Diameter of pipe D1: .5 in.
Diameter of pipe D2: .25 in.
Angle w in degree: 45
Velocity of flow:	1.39 m/s
Reynolds number:	17585
Velocity of flow 2:	5.56 m/s
Reynolds number 2:	35170
Flow:	turbulent
Absolute roughness:	0.01 mm
Pipe friction number:	0.03
Pressure drop:	28.07 mbar, ~= 0.03 bar = 2807 Pa

The following is the pressure drop of the 0.25" > 0.5" pressure adapter:

Flow medium:	Water 20 °C / liquid
Volume flow::	0.176 m³/h
Weight density:	998.206 kg/m³
Dynamic Viscosity:	1001.61 10-6 kg/ms
Element of pipe:	Gradual enlargement
Dimensions of element:	Diameter of pipe D1: .25 in.
Diameter of pipe D2: .5 in.
Angle w in degree: 45
Velocity of flow:	1.54 m/s
Reynolds number:	9769
Velocity of flow 2:	0.39 m/s
Reynolds number 2:	4885
Flow:	turbulent
Absolute roughness:	0.01 mm
Pipe friction number:	0.03
Pressure drop:	7.4 mbar, ~= 0.01 bar = 740 Pa

For pressure drop due to bends:

Flow medium:	Water 20 °C / liquid
Volume flow::	0.176 m³/h
Weight density:	998.206 kg/m³
Dynamic Viscosity:	1001.61 10-6 kg/ms
Element of pipe:	Circular bend
Dimensions of element:	Diameter of pipe D: .5 in.
Radius R: 1 in.
Angle w in degree: 45
Velocity of flow:	0.39 m/s
Reynolds number:	4885
Velocity of flow 2:	-
Reynolds number 2:	-
Flow:	turbulent
Absolute roughness:	0.01 mm
Pipe friction number:	0.04
Pressure drop:	0.35 mbar

With assuming around 10 bends, total DP due to bends = 3.5 mbar = 350 Pa

For pressure drop due to length (25 ft):

Flow medium:	Water 20 °C / liquid
Volume flow::	0.176 m³/h
Weight density:	998.206 kg/m³
Dynamic Viscosity:	1001.61 10-6 kg/ms
Element of pipe:	circular
Dimensions of element:	Diameter of pipe D: .5 in.
Length of pipe L: 25 ft.
Velocity of flow:	0.39 m/s
Reynolds number:	4885
Velocity of flow 2:	-
Reynolds number 2:	-
Flow:	turbulent
Absolute roughness:	0.01 mm
Pipe friction number:	0.04
Pressure drop:	17.17 mbar, ~= 0.02 bar = 1717 Pa

Total DP due to straight, bends, adapters: 2807 Pa + 740 Pa + 350 Pa + 1717 Pa = 5614 Pa = 0.005614 MPa

4) For a conservative estimate and assuming adpaters are rougher & more sudden and that elbows are more sudden, DP due to piping (aside from MPV) is around 0.1 MPa. This compensates for tank entrance effects and adapter from 1" to 0.5". Total final tank pressure required is therefore 2.935 MPa + 0.1 MPa = 3.035 MPa
    - Assuming isentropic expansion in the propellant tank and a base volume of 11.564 L, 10 second burn time = 1.39 kg ethanol = 1.762 L of ethanol = 9.802 L of ullage gas, initial tank pressure must be: 3.8253 MPa
5) For calculating the thrust curve (and tank pressure as a function of time):
    a) Choose a dt (maybe 0.01 seconds)
    b) Use dt and initial mdot to find change in mass, use constant density to find change in volume in the tank, use change in volume in the tank and isentropic expansion to find new pressure inside the tank
    c) Using initial chamber pressure to 
