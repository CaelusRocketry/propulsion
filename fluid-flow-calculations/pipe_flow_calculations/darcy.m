function [f]=darcy(Re,r)
%Darcy-Weisbach friction factor Calculator
%[f]=darcy(Re,r)
%Re must be 
%r must be postive value
if Re>2300
a=2/log(10);
b=r/3.7;
d=Re*log(10)/5.02;
s=b*d+log(d);
q=s^(s/(s+1));
g=b*d+log(d/q);
z=log(q/g);
dla=z*g/(g+1);
dcf=dla*(1+((z/2)/((g+1)^2+((z/3)*(2*g-1)))));
f=(1/(a*(log(d/q)+dcf)))^2;
end
end