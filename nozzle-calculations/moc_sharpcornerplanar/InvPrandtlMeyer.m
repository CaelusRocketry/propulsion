%% Based on Hall, I. M. "Inversion of the prandtl-meyer relation." Aeronautical Journal 79 (1975): 417.
function Mach=InvPrandtlMeyer(v)
v=v*pi/180;
A=1.3604;
B=0.0962;
C=-0.5127;
D=-0.6722;
E=-0.3278;
v_0=0.5*pi*(sqrt(6)-1);
y=(v/v_0)^(2/3);
Mach=(1 + A*y + B*y^2 + C*y^3)/(1 + D*y + E*y^2);
end