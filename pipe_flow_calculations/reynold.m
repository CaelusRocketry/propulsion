function [ Reynold ] = reynold( rho,v,d,mu )
%[Re]=reynold(rho,v,d,mu)
%  input all variables in SI units.
%rho:density
%v:velocity
%d:diameter
%mu:viscosity
Reynold=rho*d*v/mu;
end

