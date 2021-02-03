%% Preprocessing
clc;

%% Calculation Parameters
gravitationalConstant = 9.8;            % m/s^2
massFlowRate = linspace(0.2, 2, 19);    %kg/sec
specificImpulse = 250;                  % sec

%% Calculation
formatSpec = "Mass flow rate: %.1f kg/sec\tThrust %.1f N\n";
for i=1:length(massFlowRate)
    thrust = gravitationalConstant * specificImpulse * massFlowRate(i);
    fprintf(formatSpec, massFlowRate(i), thrust);
end